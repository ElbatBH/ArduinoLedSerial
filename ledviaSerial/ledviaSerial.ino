#include <SoftwareSerial.h>

int green = 13;

// LEDs status
int greenstatus = 0;

void setup() {
      pinMode(green, OUTPUT);
      // initialize serial communication:
      Serial.begin(9600);
              }

void loop() {
  //mySerial.println("Hello, world?");
  if (Serial.available() > 0)
  {
    int inByte = Serial.read();
    switch (inByte)
    {
      case 'g':
      case 'v':
        if (greenstatus == 0)
        {
          digitalWrite(green, HIGH);
          Serial.println("Green LED is ON");
          greenstatus = 1;
          break;
        }
        else
        {
          digitalWrite(green, LOW);
          Serial.println("Green LED is OFF");
          greenstatus = 0;
          break;
        }
     
      default:
        // turn all the LEDs off:
      digitalWrite(green, LOW);
      greenstatus = 0;
      Serial.println("All LEDs are OFF");
       }
     }
    }
