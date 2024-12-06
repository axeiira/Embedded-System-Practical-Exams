int main(){
  USART_Init();

  DDRB = 0xFF;
  PORTB |= (1 << PB4) | (1 << PB5);

  loop:
    if (!(PINB & (1 << PB4))){
      USART_Write("1\n");
    } else {
      USART_Write("0\n");
    }
    if (!(PINB & (1 << PB5))){
      USART_Write("3\n");
    } else {
      USART_Write("2\n");
    }
    _delay_ms(200);
  goto loop;
}

// int uart_putchar(char c, FILE *stream) {
void USART_Init() {
    // Initialize UART with baud rate 9600
    UBRR0H = 0;
    UBRR0L = 103;  // 9600 baud rate at 16MHz clock
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // Enable RX and TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}


void USART_Write(char *str) {
    while (*str) {
        while (!(UCSR0A & (1 << UDRE0)));  // Wait for the transmit buffer to be empty
        UDR0 = *str++;  // Send data and move to the next character
    }
}