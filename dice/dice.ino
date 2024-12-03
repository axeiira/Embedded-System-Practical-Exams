#include <time.h>

#define BUTTON_PIN PC0

void LightDice(int d1, int d2) {
  switch (d1) {
      case 1: PORTB = 0b00000001; break; // Middle
      case 2: PORTB = 0b00000100; break; // Left-Diagonal
      case 3: PORTB = 0b00000011; break; // Right-Diagonal + Middle
      case 4: PORTB = 0b00000110; break; // Left & Right Diagonal
      case 5: PORTB = 0b00000111; break; // Left + Right (Diagonal) + Middle
      case 6: PORTB = 0b00001110; break; // LeftRight Daigonal + LeftRight Middle
  }

  switch (d2) {
      case 1: PORTD = 0b00010000; break; // Middle
      case 2: PORTD = 0b01000000; break; // Left-Diagonal
      case 3: PORTD = 0b10010000; break; // Right-Diagonal + Middle
      case 4: PORTD = 0b11000000; break; // Left & Right Diagonal
      case 5: PORTD = 0b11010000; break; // Left + Right (Diagonal) + Middle
      case 6: PORTD = 0b11100000; break; // LeftRight Daigonal + LeftRight Middle
  }
}

int main() {
  DDRB = 0xff; // Set PORTB as output
  DDRD = 0xff; // Set PORTD as output
  PORTC |= (1 << BUTTON_PIN); // Enable pull-up resistor on PC0

  srand(time(NULL)); // Seed the random number generator

  while (1) {
      if (!(PINC & (1 << BUTTON_PIN))) { // Check if button is pressed
          int d1 = rand() % 6 + 1; // Generate random number between 1 and 6
          int d2 = rand() % 6 + 1; // Generate random number between 1 and 6
          LightDice(d1, d2); // Call LightDice with random values
          _delay_ms(500); // Debounce delay
      }
  }
}