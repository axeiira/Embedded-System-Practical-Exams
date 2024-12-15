#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define IR_RECEIVER PD2  // Assuming IR receiver on INT0 (PD2)
#define LED1 PB3         // LED for higher frequency on PB3
#define LED2 PB2         // LED for lower frequency on PB2

#define BUFFER_SIZE 10   // Number of readings to average
#define FREQ_THRESHOLD_LOW 200   // Lower frequency threshold
#define FREQ_THRESHOLD_HIGH 250 // Higher frequency threshold

volatile unsigned long pulseStart = 0;
volatile unsigned long pulseDuration = 0;
volatile uint8_t signalDetected = 0;

// Circular buffer for frequency readings
unsigned long frequencyBuffer[BUFFER_SIZE];
uint8_t bufferIndex = 0;
uint8_t bufferFilled = 0;

// Initialize serial communication
void uart_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1<<TXEN0);
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

// Send a single character via UART
void uart_transmit(unsigned char data) {
    while (!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

// Send a string via UART
void uart_printstr(char* str) {
    while(*str) {
        uart_transmit(*str);
        str++;
    }
}

// Convert unsigned long to string for printing
void uart_printnum(unsigned long num) {
    char buffer[10];
    unsigned char i = 0;
    
    if (num == 0) {
        uart_transmit('0');
        uart_transmit('\n');
        return;
    }
    
    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }
    
    while (i > 0) {
        uart_transmit(buffer[--i]);
    }
    uart_transmit('\n');
}

// Calculate average frequency
unsigned long calculateAverageFrequency() {
    if (!bufferFilled && bufferIndex == 0) return 0;
    
    unsigned long sum = 0;
    uint8_t count = bufferFilled ? BUFFER_SIZE : bufferIndex;
    
    for (uint8_t i = 0; i < count; i++) {
        sum += frequencyBuffer[i];
    }
    
    return sum / count;
}

// Interrupt Service Routine for External Interrupt
ISR(INT0_vect) {
    unsigned long currentTime = micros();
    
    if (pulseStart != 0) {
        pulseDuration = currentTime - pulseStart;
    }
    
    pulseStart = currentTime;
}

// Microsecond timer initialization
void timer_init() {
    TCCR0A = (1 << WGM01) | (1 << WGM00);  // Fast PWM mode
    TCCR0B = (1 << CS01);  // Prescaler = 8
}

// Microsecond timer function
unsigned long micros() {
    static unsigned long timer_overflow_count = 0;
    static unsigned long last_tcnt = 0;
    
    unsigned long current_tcnt = TCNT0;
    
    if (current_tcnt < last_tcnt) {
        timer_overflow_count++;
    }
    
    last_tcnt = current_tcnt;
    
    return (timer_overflow_count * 256 + current_tcnt) * 8;
}

int main(void) {
    // Initialize ports
    DDRB |= (1 << LED1) | (1 << LED2);  // Set LED pins as output
    DDRD &= ~(1 << IR_RECEIVER);        // Set IR receiver pin as input
    
    // Initialize UART (16MHz clock, 9600 baud)
    uart_init(103);
    
    // Initialize timer
    timer_init();
    
    // Enable external interrupt on INT0 (PD2)
    EICRA |= (1 << ISC00);  // Any logical change triggers interrupt
    EIMSK |= (1 << INT0);   // Enable INT0
    
    // Enable global interrupts
    sei();
    
    unsigned long lastSignalTime = 0;
    
    while (1) {
      uart_printnum(pulseDuration);
        if (pulseDuration > 0) {
            // Calculate frequency from pulse duration
            unsigned long frequency = 1000000 / pulseDuration;
            
            // Store in circular buffer
            frequencyBuffer[bufferIndex] = frequency;
            bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
            
            // Mark buffer as filled if we've gone through a full cycle
            if (bufferIndex == 0) {
                bufferFilled = 1;
            }
            
            // Calculate and print average frequency
            unsigned long avgFrequency = calculateAverageFrequency();
            uart_printnum(avgFrequency);
            
            // More stable LED control based on average frequency
            if (avgFrequency >= FREQ_THRESHOLD_HIGH) {
                PORTB |= (1 << LED1);   // Higher frequency LED on
                PORTB &= ~(1 << LED2);  // Lower frequency LED off
            } else if (avgFrequency <= FREQ_THRESHOLD_LOW) {
                PORTB &= ~(1 << LED1);  // Higher frequency LED off
                PORTB |= (1 << LED2);   // Lower frequency LED on
            } else {
                // Intermediate frequency - both LEDs off
                PORTB &= ~((1 << LED1) | (1 << LED2));
            }
            
            signalDetected = 1;
            lastSignalTime = micros() / 1000;  // Convert to milliseconds
            pulseDuration = 0;
        }
        
        // Turn off LEDs if no signal is detected for a period
        if ((micros() / 1000 - lastSignalTime) > 100 && signalDetected) {
            PORTB &= ~((1 << LED1) | (1 << LED2));
            signalDetected = 0;
        }
    }
    
    return 0;
}