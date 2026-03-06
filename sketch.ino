const int latchPin = 10; //ST_CP
const int clockPin = 12; //SH_CP
const int dataPin = 11; //DS

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for( int i = 0; i < 8; i++)
  {
    byte value = 1 << i;
    
    sendToShift(value);

    delay(150);
  }

  for (int i = 6; i > 0; i--)
  {
    byte value = 1 << i;
    
    sendToShift(value);

    delay(150);
  }

}

void sendToShift(byte data)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}
