

#include <Keypad.h>
#include <Servo.h>


Servo servo_Motor; 
char* password = "123";
int position = 0;
int piezoPin = 11;
const int RedLED = 12;
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = /*{9,8,7,6};*/ {6,7,8,9};//Rows 0 to 3
byte colPins[numCols]=  /*{5,4,3,2};*/{2,3,4,5};//Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
#define ledpin 13
void setup()
{
  pinMode(ledpin,OUTPUT);
  pinMode(RedLED,OUTPUT);
  digitalWrite(ledpin, HIGH);
  digitalWrite(ledpin, LOW);
  
  servo_Motor.attach(10 );
  setLocked(true);
  Serial.begin(9600);
}

void loop()
{
  
char key = myKeypad.getKey();
if (key == 'a' || key == 'A')
{
 digitalWrite(RedLED, LOW);

}
 if (key == '*' || key == '#')
{
 digitalWrite(RedLED, HIGH);
position = 0;
setLocked(true);
}

if (key == password[position])
{
  
position ++;
}
if (position == 3)
{
  

setLocked(false);
}
 
//delay(100);
 Serial.println(key);
}

void setLocked(int locked)
{
if (locked)
{
  digitalWrite(ledpin, LOW);
  
  noTone(11);
  servo_Motor.write(11);
}
else
{
   digitalWrite(ledpin, HIGH);
   tone(piezoPin, 10000, 500);
   servo_Motor.write(90);
}
}
