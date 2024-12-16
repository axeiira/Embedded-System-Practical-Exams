int main(void) {
    DDRB |= (1 << PB2) | (1 << PB3);

    // Set ADC (Analog-to-Digital Converter) configuration
    ADMUX = (1 << REFS0) | 5;  // AVcc reference voltage, ADC channel 5 (A5)
    ADCSRA = (1 << ADEN)       // Enable ADC
           | (1 << ADPS2)      // Set ADC prescaler to 16 (clock / 16)
           | (1 << ADPS1);     

    while (1) {
        // Start ADC conversion
        ADCSRA |= (1 << ADSC);
        // Wait for conversion to complete
        while (ADCSRA & (1 << ADSC));

        uint16_t x = ADC;

        if (x > 500) {
            PORTB |= (1 << PB2);
        } else {
            PORTB &= ~(1 << PB2);
        }

        if (x < 50 && x > 0) {
            PORTB |= (1 << PB3);
        } else {
            PORTB &= ~(1 << PB3);
        }
        _delay_ms(100);
    }

    return 0;
}
