/*
  TicTacToeDisplayExample.ino - Example for how to use the TicTacToeDisplay library
  Created by Preston J. Rooker, January 2, 2022.  
*/

//Before you start, make sure that you have installed the Adafruit_GFX.h library and Adafruit_SSD1306.h libraries, as they are neccesary for TicTacToeDisplay library 

//Make sure to include the library :)
#include <TicTacToeDisplay.h>

//Start off by making a TicTacToeDisplay object
TicTacToeDisplay display; 


void setup() {
  
  /////////////////////////////////////////////////
  //////////////// SETUP FUNCTIONS ////////////////
  /////////////////////////////////////////////////
  
  //First, make sure you call the begin() function
  //if screen doesn't work from the start its likely because you forgot display.begin(), or because you are using too much memory
  display.begin();

  //You can start off by drawing the tictactoe board with drawBoard()
  display.drawBoard();
  delay(500); //you can always add delays between drawings with the delay(milliseconds) function



  /////////////////////////////////////////////////
  ////////////// Drawing X's and O's //////////////
  /////////////////////////////////////////////////


  //Now that we have our board, we can draw X's and O's
  //to draw an X or O, we have to choose the square to draw it in. The squares are indexed from 0 to 8
  //    0|1|2
  //    -----
  //    3|4|5
  //    -----
  //    6|7|8
  
  display.drawX(0); //this draws an X at square 0, which is the top left
  delay(500);
  display.drawO(4); //this draws an O at square 4, which is the middle
  delay(500);
  display.drawX(1); //this draws an X at square 1, which is the top center
  delay(500);
  display.drawO(6); //this draws an O at square 6, which is the bottom left
  delay(500);
  display.drawX(2); //this draws an X at square 2, which is the top right
  delay(500);

  
  /////////////////////////////////////////////////
  ////////////// Game Over Drawings ///////////////
  /////////////////////////////////////////////////

  //Now that our TicTacToe board has some X's and O's, lets draw a line through the top row to show that X has won
  //we can do this with drawVictoryLine(firstSquareNum,secondSquareNum), this draws a line starting at firstSquareNum and ending at secondSquareNum
  display.drawVictoryLine(0,2); //draws a victory line through the top row, starting at square 0 and ending at square 2
  delay(500);
  //To show that the game is over, lets flash the screen with flashScreen(), this rapidly inverts the colors of the screen to make it flash
  display.flashScreen();
  delay(500);

  
  /////////////////////////////////////////////////
  //////////////// Writing Text ///////////////////
  /////////////////////////////////////////////////

  //Now that the game is over, let's learn how to write text so that we can show who won
  //There are two sizes of text, small and large

  //lets start with small text, which is written with drawSmallText(stringMessage)
  //small text can have 88 characters max, with 11 characters per line horizontally, and 8 lines max vertically
  //lets use small text to congratulate player X
  display.drawSmallText("Congratulations Player X! You win!");
  delay(2000);
  //that doesn't look so good because of spacing, lets try again, this time spacing things out so there are 11 characters in each line
  display.drawSmallText("Congrats              Player X!             You Win!");
  delay(2000); 
  //that looks much better!

  //now lets try writing large text with drawLargeText(stringMessage)
  //large text can have 20 characters max with 5 characters per line horizontally, and 4 lines max vertically
  display.drawLargeText("Player X Wins!");
  delay(2000);
  //again because of spacing this doesn't look great, lets try again with shorter words and better spacing
  display.drawLargeText("  X       Wins!");
  delay(2000);
  //keep in mind that whenever you draw text, it automatically erases whatever text was there beforehand

  
  /////////////////////////////////////////////////
  //////////////// Clearing Functions /////////////
  /////////////////////////////////////////////////

  //if we want to clear an individual square, we can use clearSquare(squareNum)
  //this erases the square, removing any X's, O's, and selection marks
  display.clearSquare(6); //erases the bottom left square (in this case erasing the O that was there)
  delay(1000);

  //if we want to clear and erase the entire screen, we can use clearScreen()
  display.clearScreen();
  delay(1000);
  //you can always redraw the board with another call to drawBoard()
  display.drawBoard(); 
  delay(500);

  /////////////////////////////////////////////////
  /////////////// Selecting Functions /////////////
  /////////////////////////////////////////////////

  //if we want to mark a square as selected, we can use selectSquare(squareNum)
  //this colors in the corners of a square to show that it's selected
  //lets use a for loop to select each square on the board
  for(int i = 0; i<9; i++){
    display.selectSquare(i);
    delay(200);
  }

  //to deselect a square thats marked as selected, we can use deselectSquare(squareNum)
  //lets use a for loop to deselect each square on the board
  for(int i = 0; i<9; i++){
    display.deselectSquare(i);
    delay(200);
  }
  delay(4000);

  //Thanks for reading the example, hopefully this helps you code your own TicTacToe game!
  
}

void loop() {
  display.drawLargeText("     Thank");
  display.drawO(6);
  delay(600);
  display.drawLargeText("     You");
  display.drawX(0);
  delay(600);
  display.drawLargeText("     For");
  display.drawO(4);
  delay(600);
  display.drawLargeText("     Read-ing");
  display.drawX(1);
  delay(600);
  display.drawLargeText("     This");
  display.drawO(2);
  delay(600);
  display.drawLargeText("     Exam-ple");
  display.drawVictoryLine(2,6);
  delay(600);
  display.drawBoard();
}