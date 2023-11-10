#include "functions.h"
#include "MeOrion.h"
#include "FastLED.h"
int spot[2]; //Creates spot that determines the current spot in the program
CRGB leds[25];
long blink = -2000;
int times = 0;
long pause = 1000;
int board[7][7] = {
  {9,9,9,9,9,9,9},
  {9,0,0,0,0,0,9},
  {9,0,0,0,0,0,9},
  {9,0,0,0,0,0,9},
  {9,0,0,0,0,0,9},
  {9,0,0,0,0,0,9},
  {9,9,9,9,9,9,9}
 };
int boxplacevalue[4]= {
  1,1,
  0,1
 };
int row = 1;
int column = 3;
int interval = 500;
long randomNumber;
int box[4][2]={
  {spot[0],spot[1]},
  {spot[0],spot[1]+1},
  {spot[0]+1,spot[1]},
  {spot[0]+1,spot[1]+1}
 };












// End of Global Variables


void setup() 
{
  Serial.begin(9600);
  setleds();
  randomNumber = analogRead(A0);
  resetboard();
  // put your setup code here, to run once:
  printboard();
  randomNumber = random(1,7);
  setshapes();
}

void loop() {
  changespot(row,column);
  
  
  place(1);
  printboard();
  //printboxplacevalue();
  long currenttime = millis();
  while (millis() < currenttime + pause)
  {
    place(0);
    int input = inputchecker();
    if (input != 0)
    {
     place(0);
     Serial.print(input);
     move(input);
     changespot(row, column);
     place(1);
     printboard();
    }
  }
  place(0);
  dropauto();
}
