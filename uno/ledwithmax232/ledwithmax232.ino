#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int green = 13;

// LEDs status
int greenstatus = 0;

void setup() {
      pinMode(green, OUTPUT);
      // initialize serial communication:
      mySerial.begin(9600);
              }

void loop() {
  //mySerial.println("Hello, world?");
  if (mySerial.available() > 0)
  {
    int inByte = mySerial.read();
    switch (inByte)
    {
      case 'g':
      case 'v':
        if (greenstatus == 0)
        {
          digitalWrite(green, HIGH);
          mySerial.println("Green LED is ON");
          greenstatus = 1;
          break;
        }
        else
        {
          digitalWrite(green, LOW);
          mySerial.println("Green LED is OFF");
          greenstatus = 0;
          break;
        }
     
      default:
        // turn all the LEDs off:
      digitalWrite(green, LOW);
      greenstatus = 0;
      mySerial.println("All LEDs are OFF");
       }
     }
    }
