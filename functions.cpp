#include "functions.h"
//Game Logic

int whichrowfree()  //totally different just returns the row thats free for the current shape dropping //returns which row is free for that shape
{
  int whichrow = 0;
  if (boxplacevalue[2] != 0 && boxplacevalue[3] != 0)  //if the bottom line is XX
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i + 1][column] == 0 && board[i + 1][column + 1] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                                                      //
  if (boxplacevalue[2] == 0 && boxplacevalue[3] == 0 && boxplacevalue[0] != 0 && boxplacevalue[1] != 0)  //if the bottom line is XX
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i][column] == 0 && board[i][column + 1] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                             //                                                                                    /0
  if (boxplacevalue[2] != 0 && boxplacevalue[3] == 0 && boxplacevalue[1] == 0)  //if the bottom line is X0
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i + 1][column] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                             //                                                                                          0/
  if (boxplacevalue[3] != 0 && boxplacevalue[0] == 0 && boxplacevalue[2] == 0)  //if the bottom line is 0X
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i + 1][column + 1] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                             //                                                                                          X/
  if (boxplacevalue[3] != 0 && boxplacevalue[0] != 0 && boxplacevalue[2] == 0)  //if the bottom line is 0X
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i][column] == 0 && board[i + 1][column + 1] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                             //                                                                                          /X
  if (boxplacevalue[2] != 0 && boxplacevalue[1] != 0 && boxplacevalue[3] == 0)  //if the bottom line is X0
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i + 1][column] == 0 && board[i][column + 1] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }                                                                                                      //                                                                                                                 X0
  if (boxplacevalue[0] != 0 && boxplacevalue[1] == 0 && boxplacevalue[3] == 0 && boxplacevalue[2] == 0)  //if the bottom line is 00
  {
    for (int i = 1, s = 1; i < 6; i++) {
      if (board[i][column] == 0) {
        whichrow = i;

      } else {
        break;
      }
    }
    return whichrow;
  }
  return whichrow;
}
int isgameover()  //checks if squares have filled the top
{
  int r = 1;
  for (int c = 1; c < 6; c++) {
    if (board[r][c] != 0) {
      return 1;
    }
  }
  return 0;
}
int isbottomfilled() {
  if (boxplacevalue[2] != 0) {
    if (board[box[2][0] + 1][box[2][1]] != 0) {
      return 1;
    }
  }
  if (boxplacevalue[3] != 0) {
    if (board[box[3][0] + 1][box[3][1]] != 0) {
      return 1;
    }
  }
  if (boxplacevalue[0] != 0) {
    if (board[box[0][0] + 1][box[0][1]] != 0) {
      return 1;
    }
  }
  if (boxplacevalue[1] != 0) {
    if (board[box[1][0] + 1][box[1][1]] != 0) {
      return 1;
    }
  }
  return 0;
}
int aresidesfilled(char d) {
  if (d == 'r') {
    if (boxplacevalue[1] != 0 || boxplacevalue[3] != 0)  //if there is a right
    {
      //calculate normal
      if (boxplacevalue[3] != 0) {
        if (board[box[3][0]][box[3][1] + 1] != 0) {
          return 1;
        }
      }
      if (boxplacevalue[1] != 0) {
        if (board[box[1][0]][box[1][1] + 1] != 0) {
          return 1;
        }
      }

    } else {
      if (boxplacevalue[2] != 0) {
        if (board[box[2][0]][box[2][1] + 1] != 0) {
          return 1;
        }
      }
      if (boxplacevalue[0] != 0) {
        if (board[box[0][0]][box[0][1] + 1] != 0) {
          return 1;
        }
      }
    }
  }
  if (d == 'l') {
    if (boxplacevalue[0] != 0 || boxplacevalue[2] != 0)  //if there is a left
    {
      //calculate normal
      if (boxplacevalue[2] != 0) {
        if (board[box[2][0]][box[2][1] - 1] != 0) {
          return 1;
        }
      }
      if (boxplacevalue[0] != 0) {
        if (board[box[0][0]][box[0][1] - 1] != 0) {
          return 1;
        }
      }

    } else {
      if (boxplacevalue[3] != 0) {
        if (board[box[2][0]][box[2][1]] != 0) {
          return 1;
        }
      }
      if (boxplacevalue[1] != 0) {
        if (board[box[0][0]][box[0][1]] != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


//Game Board Movement Functions
void updatebox()  //Updates the coordinates of box based on Spot's Current Coordinate value in the 2d ARray
{
  // Use the same logic as lshape to update box
  box[0][0] = spot[0];      // x-axis of the first dot of the box
  box[0][1] = spot[1];      // y-axis of the first dot of the box
  box[1][0] = spot[0];      // x-axis of the second dot of the box (same as first dot)
  box[1][1] = spot[1] + 1;  // y-axis of the second dot of the box
  box[2][0] = spot[0] + 1;  // x-axis of the third dot of the box
  box[2][1] = spot[1];      // y-axis of the third dot of the box
  box[3][0] = spot[0] + 1;  // x-axis of the fourth dot of the box
  box[3][1] = spot[1] + 1;  // y-axis of the fourth dot of the box
}
void place(int y)  //Sets the value on the Game Board based on a 1 parameter or a 0 Parameter
{
  if (y != 0) {
    // If y is not equal to 0, place the values of box on the board
    if (boxplacevalue[0] != 0) {
      board[box[0][0]][box[0][1]] = boxplacevalue[0];  //if the array box place value has a 0 (It forms shape based on whats inside the box for example {1,1,0,0} would be a straight line accross) then it would skip over and not place that value on the "Board" 7*7 Array
    }
    if (boxplacevalue[1] != 0) {
      board[box[1][0]][box[1][1]] = boxplacevalue[1];
    }
    if (boxplacevalue[2] != 0) {
      board[box[2][0]][box[2][1]] = boxplacevalue[2];
    }
    if (boxplacevalue[3] != 0) {
      board[box[3][0]][box[3][1]] = boxplacevalue[3];
    }
  } else {
    // If y is equal to 0, places the values of box on the board
    if (boxplacevalue[0] != 0) {
      board[box[0][0]][box[0][1]] = 0;
    }
    if (boxplacevalue[1] != 0) {
      board[box[1][0]][box[1][1]] = 0;
    }
    if (boxplacevalue[2] != 0) {
      board[box[2][0]][box[2][1]] = 0;
    }
    if (boxplacevalue[3] != 0) {
      board[box[3][0]][box[3][1]] = 0;
    }
  }
}


void rotate() 
{
  int copy[4] = { boxplacevalue[0], boxplacevalue[1], boxplacevalue[2], boxplacevalue[3] };
  int checker[4] = {copy[2],copy[0],copy[3],copy[1]};
  if (boxplacevalue[0] == 1)
  {
    return;
  }
  if (copy[0] == 0 && checker[0]==1)
  {
    //Serial.print("This square 0 needs to be checked");
    if (board[box[0][0]][box[0][1]]!=0)
    { 
      return;
    }
  }
  if (copy[1] == 0 && checker[1]!=0)
  {
    //Serial.print("This square 1 needs to be checked");
    if (board[box[1][0]][box[1][1]]!=0)
    { 
      return;
    }
  }
  if (copy[2] == 0 && checker[2]!=0)
  {
    //Serial.print("This square 2 needs to be checked");
    if (board[box[2][0]][box[2][1]]!=0)
    { 
      return;
    }
  }
  if (copy[3] == 0 && checker[3]!=0)
  {
    //Serial.print("This square 3 needs to be checked");
    if (board[box[3][0]][box[3][1]]!=0)
    { 
      return;
    }
  }
  //Serial.print("Checked if statements");
  boxplacevalue[0] = copy[2];
  boxplacevalue[1] = copy[0];
  boxplacevalue[2] = copy[3];
  boxplacevalue[3] = copy[1];
  return;
}

void dropauto() {
  row++;
  if (isbottomfilled()) {
    place(1);
    row = 1;
    column = 3;
    randomNumber = random(1, 7);
    setshapes();
  }
  clearrow(whichrowfilled());  //checks if row is filled and acts accordingly
  if (isgameover())            //checks if its game over
  {
    resetboard();
    gameoverdisplay();
  }
}
//Game Board Functions
void move(int choice) {
  if (choice == 3)  //pause
  {
    glitch();  //pauses game
  }
  if (choice == 9 && !(aresidesfilled('r')))  //right
  {
    column++;
  }
  if (choice == 5 && !(isbottomfilled()))  //slow drop
  {
    row++;
  }
  if (choice == 6 && (whichrowfree() != 0))  //harddrop
  {
    row = whichrowfree();
  }
  if (choice == 1 && !(aresidesfilled('l')))  //left
  {
    column--;
  }
  if (choice == 8)  //rotate
  {
    rotate();
  }
  if (row > 5) {
    row = 5;
  }
  if (row < 0) {
    row = 1;
  }
  if (column > 5) {
    column = 5;
  }
  if (column < 0) {
    column = 0;
  }
}
void printboard()  //prints the current board.
{
  Serial.println("-----------");
  for (int r = 0; r < 7; r++) {
    Serial.print("[");
    for (int c = 0; c < 7; c++) {
      Serial.print(board[r][c]);
      if (c < 6) {
        Serial.print("|");
      }
    }
    Serial.println("]");
  }
  Serial.println("-----------");
  showleds();
}
int whichrowfilled()  //returns the value number for the most bottom filled row
{
  int whichrow;
  for (int r = 5; r > 0; r--) {
    for (int c = 1; c < 6; c++) {
      if (board[r][c] == 0)  //if one of the rows has a 0 then by logic that row is not filled. there is a hole so it stops right there, gives
      {                      //whichrowdata 0 and 1 both 0's and returns right there and then.
        whichrow = 0;
        break;
      }
      if (c == 5) {
        whichrow = r;
        return whichrow;
      }
    }
  }
  return whichrow;
}
void resetboard()  //Sets all the coordinates of the playable board to a value of 0
{
  for (int r = 1; r < 6; r++) {
    for (int c = 1; c < 6; c++) {
      board[r][c] = 0;
    }
  }
}
void changespot(int x, int y) {  //changes the spot based on the arguments you pass in, int x is essentially the row  and y is the column
  spot[0] = x;
  spot[1] = y;
  updatebox();
}
void droprow(int row1)  //Drops the entire boardby 1 row
{
  if (row1 == 1) {
    for (int c = 1; c < 6; c++) {
      board[row1][c] = 0;
    }
    return;
  }
  for (int c = 1; c < 6; c++) {
    board[row1][c] = board[row1 - 1][c];  //gives it the value above the box
  }
  droprow(row1 - 1);
  showleds();
}
void clearrow(int row1)  //clears the row and shows a little display
{
  //int row1 = 5
  if (row1 == 0) {
    return 1;
  }
  droprow(row1);
}  //clears the row1 and changes the 1's and 0's
void setshapes()  //Creates the shapes by assining numbers to the box values
{
  if (randomNumber == 1)  //Basic Block
  {
    boxplacevalue[0] = 1;
    boxplacevalue[1] = 0;
    boxplacevalue[2] = 0;
    boxplacevalue[3] = 0;
    return;
  }
  if (randomNumber == 2)  //line
  {
    boxplacevalue[0] = 2;
    boxplacevalue[1] = 2;
    boxplacevalue[2] = 0;
    boxplacevalue[3] = 0;
    return;
  }
  if (randomNumber == 3)  //reverse r hape
  {
    boxplacevalue[0] = 3;
    boxplacevalue[1] = 3;
    boxplacevalue[2] = 3;
    boxplacevalue[3] = 0;
    return;
  }
  if (randomNumber == 4)  //r Shape
  {
    boxplacevalue[0] = 4;
    boxplacevalue[1] = 4;
    boxplacevalue[2] = 0;
    boxplacevalue[3] = 4;
    return;
  }
  if (randomNumber == 5)  //right diagnol shape
  {
    boxplacevalue[0] = 5;
    boxplacevalue[1] = 0;
    boxplacevalue[2] = 0;
    boxplacevalue[3] = 5;
    return;
  }
  if (randomNumber == 6)  //left diagnol shape
  {
    boxplacevalue[0] = 0;
    boxplacevalue[1] = 6;
    boxplacevalue[2] = 6;
    boxplacevalue[3] = 0;
    return;
  }
}
void glitch()  //pauses the arduino
{
  Serial.print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  Serial.end();
  Serial.begin(9600);
  while (1) {
    if (Serial.available() != 0) {
      break;
    }
  }
}

int inputchecker()  //returns the value pressed
{
  if (Serial.available() != 0) {
    int choice = Serial.parseInt();
    //Serial.print(choice);
    return choice;
  } else {
    return 0;
  }
}
//Debugging Functions
void printspot()  //prints the current value of spot
{
  Serial.print("Board[");
  Serial.print(spot[0]);
  Serial.print("]");
  Serial.print("[");
  Serial.print(spot[1]);
  Serial.print("]");
  Serial.print(" = ");
  Serial.println(board[spot[0]][spot[1]]);
}
void printboxplacevalue() {
  Serial.println("");
  Serial.print(boxplacevalue[0]);
  Serial.println(boxplacevalue[1]);
  Serial.print(boxplacevalue[0]);
  Serial.println(boxplacevalue[1]);
}

//Led Board Functions
void showleds()  //shows the leds
{

  int l[5][5] = {
    { 0, 1, 2, 3, 4 },
    { 9, 8, 7, 6, 5 },
    { 10, 11, 12, 13, 14 },
    { 19, 18, 17, 16, 15 },
    { 20, 21, 22, 23, 24 }
  };
  for (int r = 1; r < 6; r++)  //r= row
  {
    for (int c = 1; c < 6; c++) {
      if (board[r][c] == 0)  //Black
      {
        leds[l[r - 1][c - 1]] = CRGB::Black;
      }
      if (board[r][c] == 1)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Red;
      }
      if (board[r][c] == 2)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Blue;
      }
      if (board[r][c] == 3)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Orange;
      }
      if (board[r][c] == 3)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Yellow;
      }
      if (board[r][c] == 4)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Pink;
      }
      if (board[r][c] == 5)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Purple;
      }
      if (board[r][c] == 6)  //red
      {
        leds[l[r - 1][c - 1]] = CRGB::Aquamarine;
      }
      if (board[r][c] == 7)  //celebration!!
      {
        leds[l[r - 1][c - 1]] = CRGB::Green;
      }
      if (board[r][c] == 7)  //celebration!!
      {
        leds[l[r - 1][c - 1]] = CRGB::MediumSpringGreen;
      }
    }
  }

  FastLED.show();

  //FastLED.addLeds<WS2811, 4, RGB>(sleds, 25).setCorrection(TypicalLEDStrip);
}
void gameoverdisplay()  //creates the game over display
{
  long timer = millis() + 2000;
  while (millis() < timer) {
    for (int i = 0; i < 25; i++) {
      if (i % 2 != 1) {
        leds[i] = CRGB::Red;
      } else {
        leds[i] = CRGB::Blue;
      }
      //sleds[i] = CRGB::Red;
    }
    FastLED.delay(200);
    for (int i = 0; i < 25; i++) {
      if (i % 2 != 1) {
        leds[i] = CRGB::Blue;
      } else {
        leds[i] = CRGB::Green;
      }
      //sleds[i] = CRGB::Orange;
    }
    FastLED.delay(200);
  }
}
void setleds() {
  Serial.begin(9600);
  FastLED.setBrightness(255);
  FastLED.addLeds<WS2811, 6, RGB>(leds, 25).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<WS2811, 4, RGB>(//sleds, 25).setCorrection(TypicalLEDStrip);
}
