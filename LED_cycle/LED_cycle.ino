#define INTERRUPT_PIN PD2

volatile uint8_t state = 0;
volatile uint8_t buttonPressed = 0;

void setup() {
  DDRB = 0b00111111;
  PORTB = 0x00;
  
  DDRD &= ~(1 << INTERRUPT_PIN); // PD2 input
  PORTD |= (1 << INTERRUPT_PIN); // pull-up on PD2

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
  if (buttonPressed) {
    buttonPressed = 0;

    state = (state + 1) % 8;
    switch (state) {
      case 0: PORTB = 0x00; break; // All LEDs off
      case 1: PORTB = 0b00000111; break; // LRIGHT
      case 2: PORTB = 0b00111000; break; // LEFT
      case 3: PORTB = 0b00001100; break; // Middle
      case 4: PORTB = 0b00011010; break; // Ganjil
      case 5: PORTB = 0b00100101; break; // genap
      case 6: PORTB = 0b00110011; break; // middle mati
      case 7: PORTB = 0b00111111; break;   // All LEDs on
    }
  }
}

ISR(INT0_vect) {
  buttonPressed = 1; 
}

int main() {
  setup();
  while (1) {

  }
}
