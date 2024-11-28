// ROW 2-7 -> PORT 13 - 8 (PB5 - PB0)
// COLUMN 2-7 -> PORT (A5 - A0)

#define BUTTON PD6
#define SPST PD5
#define SPDT1 PD4
#define SPDT2 PD3

void clearMatrix() {
  PORTC = 0x00;
  PORTB = 0x00;
}

void LightLED(int x, int y) {
  switch (x) {
      case 0: PORTB = 0b00100000; break; // Row 0
      case 1: PORTB = 0b00010000; break; // Row 1
      case 2: PORTB = 0b00001000; break; // Row 2
      case 3: PORTB = 0b00000100; break; // Row 3
      case 4: PORTB = 0b00000010; break; // Row 4
      case 5: PORTB = 0b00000001; break; // Row 5
  }

  switch (y) {
      case 0: PORTC = 0b011111; break; // Column 0
      case 1: PORTC = 0b101111; break; // Column 1
      case 2: PORTC = 0b110111; break; // Column 2
      case 3: PORTC = 0b111011; break; // Column 3
      case 4: PORTC = 0b111101; break; // Column 4
      case 5: PORTC = 0b111110; break; // Column 5
  }
}

void animasiRem() {
  // Frame 1
    for(int i = 0; i < 300; i++) {
        LightLED(2, 2);
        _delay_us(100);

        LightLED(2, 3);
        _delay_us(100);

        LightLED(3, 2);
        _delay_us(100);

        LightLED(3, 3);
        _delay_us(100);
    }

  // Frame 2
    for(int i = 0; i < 300; i++) {
        LightLED(1, 1);
        _delay_us(100);

        LightLED(2, 2);
        _delay_us(100);

        LightLED(1, 4);
        _delay_us(100);

        LightLED(2, 3);
        _delay_us(100);

        LightLED(4, 1);
        _delay_us(100);

        LightLED(3, 2);
        _delay_us(100);

        LightLED(4, 4);
        _delay_us(100);

        LightLED(3, 3);
        _delay_us(100);
    }
    
    for(int i = 0; i < 300; i++) {
        // Frame 3
        LightLED(0, 0);
        _delay_us(100);

        LightLED(0, 5);
        _delay_us(100);

        LightLED(5, 0);
        _delay_us(100);

        LightLED(5, 5);
        _delay_us(100);

        LightLED(1, 1);
        _delay_us(100);

        LightLED(2, 2);
        _delay_us(100);

        LightLED(1, 4);
        _delay_us(100);

        LightLED(2, 3);
        _delay_us(100);

        LightLED(4, 1);
        _delay_us(100);

        LightLED(3, 2);
        _delay_us(100);

        LightLED(4, 4);
        _delay_us(100);

        LightLED(3, 3);
        _delay_us(100);

        LightLED(2,0);
        _delay_us(100);

        LightLED(3,0);
        _delay_us(100);

        LightLED(0,2);
        _delay_us(100);

        LightLED(0,3);
        _delay_us(100);

         LightLED(2,5);
        _delay_us(100);

        LightLED(3,5);
        _delay_us(100);

        LightLED(5,2);
        _delay_us(100);

        LightLED(5,3);
        _delay_us(100);
    }

    for(int i = 0; i < 300; i++) {
        // Frame 4
        LightLED(1, 1);
        _delay_us(100);

        LightLED(2, 2);
        _delay_us(100);

        LightLED(1, 4);
        _delay_us(100);

        LightLED(2, 3);
        _delay_us(100);

        LightLED(4, 1);
        _delay_us(100);

        LightLED(3, 2);
        _delay_us(100);

        LightLED(4, 4);
        _delay_us(100);

        LightLED(3, 3);
        _delay_us(100);
    }

     for(int i = 0; i < 300; i++) {
        // Frame 5
        LightLED(2, 2);
        _delay_us(100);

        LightLED(2, 3);
        _delay_us(100);

        LightLED(3, 2);
        _delay_us(100);

        LightLED(3, 3);
        _delay_us(100);
    }

     for(int i = 0; i < 300; i++) {
      //Frame 6
        clearMatrix();
        _delay_us(500);
    }
}

void animasiHazard(){
  // Frame 1
    for(int i = 0; i < 70; i++) {
      LightLED(1,1);
      _delay_us(100);
      LightLED(1,2);
      _delay_us(100);
      LightLED(1,3);
      _delay_us(100);
      LightLED(1,4);
      _delay_us(100);

      LightLED(2,1);
      _delay_us(100);
      LightLED(2,4);
      _delay_us(100);

      LightLED(3,1);
      _delay_us(100);
      LightLED(3,4);
      _delay_us(100);

      LightLED(4,1);
      _delay_us(100);
      LightLED(4,2);
      _delay_us(100);
      LightLED(4,3);
      _delay_us(100);
      LightLED(4,4);
      _delay_us(100);
    }

  // Frame 2
    for(int i = 0; i < 70; i++) {
      LightLED(0,0);
      _delay_us(100);
      LightLED(0,1);
      _delay_us(100);
      LightLED(0,2);
      _delay_us(100);
      LightLED(0,3);
      _delay_us(100);
      LightLED(0,4);
      _delay_us(100);
      LightLED(0,5);
      _delay_us(100);

      LightLED(1,0);
      _delay_us(100);
      LightLED(1,5);
      _delay_us(100);

      LightLED(2,0);
      _delay_us(100);
      LightLED(2,5);
      _delay_us(100);

      LightLED(3,0);
      _delay_us(100);
      LightLED(3,5);
      _delay_us(100);

      LightLED(4,0);
      _delay_us(100);
      LightLED(4,5);
      _delay_us(100);

      LightLED(5,0);
      _delay_us(100);
      LightLED(5,1);
      _delay_us(100);
      LightLED(5,2);
      _delay_us(100);
      LightLED(5,3);
      _delay_us(100);
      LightLED(5,4);
      _delay_us(100);
      LightLED(5,5);
      _delay_us(100);

      LightLED(2,2);
      _delay_us(100);
      LightLED(2,3);
      _delay_us(100);
      LightLED(3,2);
      _delay_us(100);
      LightLED(3,3);
      _delay_us(100);

    }
}

void animasiSenKanan(){
  // Frame 1
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 0);
    _delay_us(100);

    LightLED(1, 1);
    _delay_us(100);

    LightLED(2, 0);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 2);
    _delay_us(100);

    LightLED(4, 3);
    _delay_us(100);

    LightLED(5, 2);
    _delay_us(100);

    // Arrow - 3
    LightLED(0, 4);
    _delay_us(100);

    LightLED(1, 5);
    _delay_us(100);

    LightLED(2, 4);
    _delay_us(100);  
  }

  // Frame 2
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 1);
    _delay_us(100);

    LightLED(1, 2);
    _delay_us(100);

    LightLED(2, 1);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 3);
    _delay_us(100);

    LightLED(4, 4);
    _delay_us(100);

    LightLED(5, 3);
    _delay_us(100);

    // Arrow - 3
    LightLED(0, 5);
    _delay_us(100);

    LightLED(2, 5);
    _delay_us(100);  
  }

  // Frame 3
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 2);
    _delay_us(100);

    LightLED(1, 3);
    _delay_us(100);

    LightLED(2, 2);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 4);
    _delay_us(100);

    LightLED(4, 5);
    _delay_us(100);

    LightLED(5, 4);
    _delay_us(100);
  }

  // Frame 4
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 3);
    _delay_us(100);

    LightLED(1, 4);
    _delay_us(100);

    LightLED(2, 3);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 5);
    _delay_us(100);

    LightLED(5, 5);
    _delay_us(100);

    //Arrow - 3
    LightLED(1,0);
    _delay_us(100);
  }

  // Frame 5
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(0, 4);
    _delay_us(100);

    LightLED(1, 5);
    _delay_us(100);

    LightLED(2, 4);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 0);
    _delay_us(100);

    LightLED(1, 1);
    _delay_us(100);

    LightLED(2, 0);
    _delay_us(100);
  }

  // Frame 6
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(0, 5);
    _delay_us(100);

    LightLED(2, 5);
    _delay_us(100);

    //Arrow - 2
    LightLED(4,0);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 1);
    _delay_us(100);

    LightLED(1, 2);
    _delay_us(100);

    LightLED(2, 1);
    _delay_us(100);
  }

  // Frame 7
  for(int i = 0; i < 200; i++) {
    //Arrow - 2
    LightLED(3,0);
    _delay_us(100);
    LightLED(4,1);
    _delay_us(100);
    LightLED(5,0);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 2);
    _delay_us(100);

    LightLED(1, 3);
    _delay_us(100);

    LightLED(2, 2);
    _delay_us(100);
  }

  // Frame 8
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(1,0);
    _delay_us(100);

    //Arrow - 2
    LightLED(3,1);
    _delay_us(100);
    LightLED(4,2);
    _delay_us(100);
    LightLED(5,1);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 3);
    _delay_us(100);

    LightLED(1, 4);
    _delay_us(100);

    LightLED(2, 3);
    _delay_us(100);
  }
}

void animasiSenKiri(){
  // Frame 1
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 1);
    _delay_us(100);

    LightLED(1, 0);
    _delay_us(100);

    LightLED(2, 1);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 3);
    _delay_us(100);

    LightLED(4, 2);
    _delay_us(100);

    LightLED(5, 3);
    _delay_us(100);

    // Arrow - 3
    LightLED(0, 5);
    _delay_us(100);

    LightLED(1, 4);
    _delay_us(100);

    LightLED(2, 5);
    _delay_us(100);  
  }

  // Frame 2
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 0);
    _delay_us(100);

    LightLED(2, 0);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 2);
    _delay_us(100);

    LightLED(4, 1);
    _delay_us(100);

    LightLED(5, 2);
    _delay_us(100);

    // Arrow - 3
    LightLED(0, 4);
    _delay_us(100);

    LightLED(1, 3);
    _delay_us(100);

    LightLED(2,4);
    _delay_us(100);  
  }

  // Frame 3
  for(int i = 0; i < 200; i++) {
    // Arrow - 3
    LightLED(0, 3);
    _delay_us(100);

    LightLED(1, 2);
    _delay_us(100);

    LightLED(2, 3);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 1);
    _delay_us(100);

    LightLED(4, 0);
    _delay_us(100);

    LightLED(5, 1);
    _delay_us(100);
  }

  // Frame 4
  for(int i = 0; i < 200; i++) {
    // Arrow - 1
    LightLED(0, 2);
    _delay_us(100);

    LightLED(1, 1);
    _delay_us(100);

    LightLED(2, 2);
    _delay_us(100);

    // Arrow - 2
    LightLED(3, 0);
    _delay_us(100);

    LightLED(5, 0);
    _delay_us(100);

    //Arrow - 3
    LightLED(1,5);
    _delay_us(100);
  }

  // Frame 5
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(0, 1);
    _delay_us(100);

    LightLED(1, 0);
    _delay_us(100);

    LightLED(2, 1);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 5);
    _delay_us(100);

    LightLED(1, 4);
    _delay_us(100);

    LightLED(2, 5);
    _delay_us(100);
  }

  // Frame 6
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(0, 1);
    _delay_us(100);

    LightLED(2, 1);
    _delay_us(100);

    //Arrow - 2
    LightLED(4,5);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 4);
    _delay_us(100);

    LightLED(1, 3);
    _delay_us(100);

    LightLED(2, 4);
    _delay_us(100);
  }

  // Frame 7
  for(int i = 0; i < 200; i++) {
    //Arrow - 2
    LightLED(3,5);
    _delay_us(100);
    LightLED(4,4);
    _delay_us(100);
    LightLED(5,5);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 3);
    _delay_us(100);

    LightLED(1, 2);
    _delay_us(100);

    LightLED(2, 3);
    _delay_us(100);
  }

  // Frame 8
  for(int i = 0; i < 200; i++) {
    //Arrow - 1
    LightLED(1,5);
    _delay_us(100);

    //Arrow - 2
    LightLED(3,4);
    _delay_us(100);
    LightLED(4,3);
    _delay_us(100);
    LightLED(5,4);
    _delay_us(100);

    //Arrow - 3
    LightLED(0, 2);
    _delay_us(100);

    LightLED(1, 1);
    _delay_us(100);

    LightLED(2, 2);
    _delay_us(100);
  }
}

int main(){
  DDRB = 0xFF;
  DDRD = 0x00;
  DDRC = 0xFF;
  PORTC = 0x00;
  PORTD = (1 << BUTTON) | (1 << SPST) | (1 << SPDT1) | (1 << SPDT2);
  loop:
    //REM
    if(!(PIND & (1 << BUTTON))){
      animasiRem();
    }
    //HAZARD
    else if (!(PIND & (1 << SPST))) {
      animasiHazard();
    }
    //SEN-KANAN
    else if (!(PIND & (1 << SPDT1))) {
      animasiSenKanan();                                 
    }
    //SEN-KIRI
    else if (!(PIND & (1 << SPDT2))) {
      animasiSenKiri();                                 
    } 
    else{
      clearMatrix();
    }
    goto loop;
}