#include "FastLED.h"

 
extern int spot[2]; //Creates ssepot that determines the current spot in the program
extern CRGB leds[25];
extern long blink;
extern int times;
extern int board[7][7];
extern int boxplacevalue[4];
extern int row;
extern int column;
extern int interval;
extern long randomNumber;
extern int box[4][2];


int inputchecker();
void dropauto();
void setshapes();
void move(int choice);
void printboxplacevalue();
void place(int y);
void calibrate();
void placelshape(int y);
void placebox(int y);
void updatebox();
void updatelshape();
void glitch();
void clearrow(int row1);
void droprow(int row1);
int whichrowfilled();
int whichrowfree();
void gameoverdisplay();
int isgameover();
void placeblock(int y);
void updateblock();
void rotate();
void updateline();
void setleds();
void printblock();
void printboard();
int isbottomfree();
int isbottomfilled();
int aresidesfilled(char d);
void printspot();
void showleds();
void changespot(int x, int y);
void placeline(int y);
void resetboard();//Sets all the coordinates of the board to a value of 0