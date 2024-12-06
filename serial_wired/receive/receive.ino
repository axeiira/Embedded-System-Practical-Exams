#define LED1_PIN PD4
#define LED2_PIN PD5

void USART_Init() {
    UBRR0H = 0;
    UBRR0L = 103;  // 9600 baud rate at 16MHz clock
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // Enable RX and TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

char USART_Read() {
    while (!(UCSR0A & (1 << RXC0)));  // Wait for data to be received
    return UDR0;  // Get and return received data from the buffer
}

void processCommand(char *command) {
    if (strcmp(command, "1") == 0) {
        PORTD |= (1 << LED1_PIN);  // Turn LED 1 ON
    } else if (strcmp(command, "0") == 0) {
        PORTD &= ~(1 << LED1_PIN);  // Turn LED 1 OFF
    } else if (strcmp(command, "3") == 0) {
        PORTD |= (1 << LED2_PIN);  // Turn LED 2 ON
    } else if (strcmp(command, "2") == 0) {
        PORTD &= ~(1 << LED2_PIN);  // Turn LED 2 OFF
    }
}

int main(void) {
    char commandBuffer[10];
    uint8_t commandIndex = 0;

    USART_Init();
    DDRD |= (1 << LED1_PIN) | (1 << LED2_PIN);

    loop:
      char receivedChar = USART_Read();
      if (receivedChar == '\n') {
          commandBuffer[commandIndex] = '\0';  // Add null-terminator 
          processCommand(commandBuffer);
          commandIndex = 0;
      } else if (receivedChar != '\r') {  // Ignore carriage return
          if (commandIndex < sizeof(commandBuffer) - 1) {
              commandBuffer[commandIndex++] = receivedChar;  
          }
      }
      goto loop;
}