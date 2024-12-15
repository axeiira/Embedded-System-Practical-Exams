#define LED1_PIN PB2
#define LED2_PIN PB3

void USART_Init() {
    UBRR0H = 0;
    UBRR0L = 103;  // 9600 baud rate at 16 MHz clock
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // Enable RX and TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

char USART_Read() {
    while (!(UCSR0A & (1 << RXC0)));  // Wait for data to be received
    return UDR0;  // Return received data
}

void USART_Write(char c) {
    while (!(UCSR0A & (1 << UDRE0)));  // Wait for transmit buffer to be empty
    UDR0 = c;  // Send data
}

void processCommand(char *command) {
    if (strcmp(command, "1") == 0) {
        PORTB |= (1 << LED1_PIN);  // Turn LED 1 ON
    } else if (strcmp(command, "0") == 0) {
        PORTB &= ~(1 << LED1_PIN);  // Turn LED 1 OFF
    } else if (strcmp(command, "3") == 0) {
        PORTB |= (1 << LED2_PIN);  // Turn LED 2 ON
    } else if (strcmp(command, "2") == 0) {
        PORTB &= ~(1 << LED2_PIN);  // Turn LED 2 OFF
    }
}

int main(void) {
    USART_Init();
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN);  // Configure LED pins as outputs
    char commandBuffer[10];
    uint8_t commandIndex = 0;

    while (1) {
        char receivedChar = USART_Read();
        USART_Write(receivedChar);  // Echo back the received character for debugging

        if (receivedChar == '\n') {
            commandBuffer[commandIndex] = '\0';  // Add null-terminator
            processCommand(commandBuffer);
            commandIndex = 0;  // Reset buffer index
        } else if (receivedChar != '\r') {  // Ignore carriage return
            if (commandIndex < sizeof(commandBuffer) - 1) {
                commandBuffer[commandIndex++] = receivedChar;
            }
        }
    }
}
