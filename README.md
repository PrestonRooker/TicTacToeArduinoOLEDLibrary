# TicTacToeArduinoOLEDLibrary

This is a library for use with Arduino IDE that provides methods with which to draw the art for a simple TicTacToe game using an SSD1306 128x64 OLED Display such as this onehttps://www.amazon.com/IZOKEE-Display-SSD1306-Raspberry-White-IIC/dp/B076PDVFQD. 

This project was created for UCLA IEEE Open Project Space in 2021.

## Usage
Start by creating a TicTacToeDisplay object with either
`TicTacToeDisplay display;`
Or you can use `TicTackToeDisplay display(width, height, &Wire, reset_pin);` if the default parameters don't work.

From here you have to call `display.begin(switchvcc,i2caddress)` or just `display.begin()` for default parameters of SSD1306_SWITCHCAPVCC and 0x3c. It is common that you might have to use an i2caddress other than 0x3c based on the OLED you have. You can search online to find i2c scanners like https://learn.adafruit.com/scanning-i2c-addresses/arduino to find your address if you are having trouble.

For functions which require you to choose a square, the squares numbers of the tictactoe board are indexed 0 to 8 like this:

>   0 | 1 | 2<br>
>\---------<br>
>   3 | 4 | 5<br>
>\---------<br>
>   6 | 7 | 8

From here you can use all of the functions to draw out your tic tac toe game. Here is a list of the availabe functions:

`display.drawBoard();` draws an empty tictactoe board  
`display.drawX(int squareNum);` draws an x in designated square  
`display.drawO(int squareNum);` draws an o in designated square  
`drawVictoryLine(int firstSquareNum, int secondSquareNum);` draws a line across board from first number to last number to indicate victory  
`drawSmallText(String text);` writes out a string of small text, 88 chars max  
`drawLargeText(String text);` writes out a string of large text, 20 chars max  
 `selectSquare(int squareNum);` marks the corners of a square to show its selected  
 `deselectSquare(int squareNum);` erases the selection markings in a square  
 `clearSquare(int squareNum);` erases and entire square, removing any X, O, or selection marks that were there  
 `clearScreen();` clears the entire screen  
 `flashScreen();` rapidly inverts the color of the screen to make the screen flash, a good way to show the games over ;)  
