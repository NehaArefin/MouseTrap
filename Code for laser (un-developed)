
#include <Servo.h> 
Servo myservo; 

int j = 0;
int t = 0;
const int triggeredLED = 7;
const int triggeredLED2 = 8;
const int RedLED = 4;        
const int GreenLED = 5;      
const int inputPin = A0;     
const int speakerPin = 12;  
const int armButton = 6;
const int button = 2; 

boolean reset = false; 
boolean isArmed = true;      
boolean isTriggered = false;
int buttonVal = 0;           
int prev_buttonVal = 0;     
int reading = 0;             
int threshold = 0;           


const int lowrange = 2000;   
const int highrange = 4000; 




void setup(){
  
  
  myservo.attach(9);
  
  pinMode(triggeredLED, OUTPUT);
  pinMode(triggeredLED2, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(armButton, INPUT);
  digitalWrite(triggeredLED, HIGH);
  delay(500);
  digitalWrite(triggeredLED, LOW);  

   calibrate();    //whats wrong with this now
   setArmedState();  
}

void loop(){

   int buttonVal = digitalRead(armButton);
 
   int ButtonVal = digitalRead(button);
 
  if ((buttonVal == HIGH) && (prev_buttonVal == LOW)){
    setArmedState();
    delay(500);
  }
  reading = analogRead(inputPin);


  if ((isArmed) && (reading < threshold)){
    isTriggered = true;  
  }

  if (isTriggered){
    pinMode(9, OUTPUT); //Allow the servo to move by making 9 an output 

     for (int i = lowrange; i <= highrange; i++)
    {
      tone (speakerPin, i, 250); 
    }
   
    for (int i = highrange; i >= lowrange; i--)
    {
      tone (speakerPin, i, 250);
    }

//////////////////////
if (j== 0){
  for(int pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);     
    j++;  
    t= 0;// waits 15ms for the servo to reach the position 
  }}
  /////////////////////
  
    digitalWrite(triggeredLED, HIGH);
    delay(50);
    digitalWrite(triggeredLED, LOW);
    delay (50);
    digitalWrite(triggeredLED2, HIGH);
    delay (50);
    digitalWrite(triggeredLED2, LOW);
    delay (50);
    

    }


     if (ButtonVal == HIGH){
      if ( t == 0){
     for(int pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } }
  t++;}




    
  delay(20);
  pinMode(9,INPUT); // set 9 to an input to turn servo off -- this stops the "servo buzz" 
}


void setArmedState(){

  if (isArmed){
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    isTriggered = false;
    isArmed = false;
    j=0;

    
    
  } else {
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, HIGH);
    tone(speakerPin, 220, 125);
    delay(200);
    tone(speakerPin, 196, 250);
    isArmed = true;
  } 
}

void calibrate(){

  int sample = 0;             
  int baseline = 0;            
  const int min_diff = 200; 
  const int sensitivity = 50;
  int success_count = 0;
  
  digitalWrite(RedLED, LOW);
  digitalWrite(GreenLED, LOW);

  for (int i=0; i<10; i++){
    sample += analogRead(inputPin);
    digitalWrite(GreenLED, HIGH);
    delay (50);
    digitalWrite(GreenLED, LOW);
    delay (50); 
  }

  do
  {
  sample = analogRead (inputPin);
    //sample = analogRead(inputPin);    

    if (sample > baseline + min_diff){
      success_count++;
      threshold += sample;

      digitalWrite(GreenLED, HIGH);
      delay (100);                    
      digitalWrite(GreenLED, LOW);
      delay (100);                    
    } else {
      success_count = 0;             
      threshold = 0;
    }

  } while (success_count < 3);

  threshold = (threshold/3) - sensitivity;

  tone(speakerPin, 196, 250);
  delay(200);
  tone(speakerPin, 220, 125);
}
