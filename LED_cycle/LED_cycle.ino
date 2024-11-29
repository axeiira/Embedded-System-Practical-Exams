#define LED_MASK 0b00111111 // Mask for PB0 to PB5
#define INTERRUPT_PIN PD2

volatile uint8_t state = 0;
volatile uint8_t buttonPressed = 0;

void setup() {
  // Configure PB0 to PB5 as output
  DDRB |= LED_MASK;
  PORTB &= ~LED_MASK; // Turn off all LEDs initially

  // Configure PD2 as input with pull-up resistor
  DDRD &= ~(1 << INTERRUPT_PIN); // PD2 as input
  PORTD |= (1 << INTERRUPT_PIN); // Enable pull-up on PD2

  // Enable external interrupt on INT0 (PD2), falling edge
  EICRA |= (1 << ISC01);  // Falling edge triggers interrupt
  EIMSK |= (1 << INT0);   // Enable INT0

  // Configure Timer0 for debounce (CTC mode)
  TCCR0A |= (1 << WGM01); // CTC mode
  TCCR0B |= (1 << CS02) | (1 << CS00); // Prescaler 1024
  OCR0A = 156; // Compare match for ~10 ms at 16 MHz clock
  TIMSK0 |= (1 << OCIE0A); // Enable Timer0 compare interrupt

  sei(); // Enable global interrupts
}

ISR(TIMER0_COMPA_vect) {
  // Timer interrupt for debouncing
  if (buttonPressed) {
    buttonPressed = 0; // Clear button press flag

    // Cycle through LED states
    state = (state + 1) % 8;
    switch (state) {
      case 0: PORTB &= ~LED_MASK; break;          // All LEDs off
      case 1: PORTB = (PORTB & ~LED_MASK) | 0b00000001; break; // LED1
      case 2: PORTB = (PORTB & ~LED_MASK) | 0b00010010; break; // LED2 + LED4
      case 3: PORTB = (PORTB & ~LED_MASK) | 0b00010100; break; // LED3 + LED5
      case 4: PORTB = (PORTB & ~LED_MASK) | 0b00000111; break; // LED1 + LED2 + LED3
      case 5: PORTB = (PORTB & ~LED_MASK) | 0b00011100; break; // LED4 + LED5 + LED6
      case 6: PORTB = (PORTB & ~LED_MASK) | 0b00010101; break; // LED1 + LED3 + LED5
      case 7: PORTB = (PORTB & ~LED_MASK) | LED_MASK; break;   // All LEDs on
    }
  }
}

ISR(INT0_vect) {
  // External interrupt handler (PD2 button press)
  buttonPressed = 1; // Set flag for debounce handling
}

int main() {
  setup();
  while (1) {
    // Main loop can remain empty; logic is interrupt-driven
  }
}
