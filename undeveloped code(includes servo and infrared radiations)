#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>



int getFingerprintIDez();

bool locked = true;

SoftwareSerial mySerial(11, 12);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int SolenoidPin = 2;

int LedPin = 3;



void setup()

{

pinMode(SolenoidPin, OUTPUT);

pinMode(LedPin, OUTPUT);

digitalWrite(LedPin, HIGH);

Serial.begin(9600);

finger.begin(57600);

}

void loop()

{

getFingerprintIDez();

}



int getFingerprintIDez() {

uint8_t p = finger.getImage();

if (p != FINGERPRINT_OK) return -1;



p = finger.image2Tz();

if (p != FINGERPRINT_OK) return -1;



p = finger.fingerFastSearch();

if (p != FINGERPRINT_OK) return -1;



if (locked == true) {

digitalWrite(SolenoidPin, HIGH);

for(pos = 0; pos < 180; pos += 1)  
  {                                  
    myservo.write(pos);              
    delay(15);                       
  } 
  for(pos = 180; pos>=1; pos-=1)     
  {                                
    myservo.write(pos);              
    delay(15);     
                  
  } 

//infrared radiations part
int analogPin = 3;     // Infrared Sensor (Right lead) connected to analog pin 3
                                    // outside leads to ground and +5V
int val = 0;                  // variable to store the value read

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  val = analogRead(analogPin);    // read the input pin
  Serial.println(val);                           // debug value
}
elseif


(locked = false)

delay(2000);



} else {

digitalWrite(SolenoidPin, LOW);

locked = true;

delay(2000);

}

return finger.fingerID;

}
