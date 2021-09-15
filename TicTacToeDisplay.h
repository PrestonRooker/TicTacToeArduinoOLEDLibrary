/*
  TicTacToeDisplay.h - Library for displaying a tic tac toe board on SSD1306 128x64 OLED display
  Created by Preston J. Rooker, September 14, 2021.  
*/
#ifndef TICTACTOEDISPLAY_H
#define TICTACTOEDISPLAY_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class TicTacToeDisplay
{
    public:
        TicTacToeDisplay(uint8_t w = 128, uint8_t h = 64, TwoWire *twi = &Wire, int8_t rst_pin = -1 );
        void begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0x3C);
        void displayBoard();
        void drawX(int squareNum);
        void drawO(int squareNum);
        void drawVictoryLine(int firstSquareNum, int secondSquareNum);
        void drawSmallText(String text);
        void drawLargeText(String text);
        void selectSquare(int squareNum);
        void deselectSquare(int squareNum);
        void clearSquare(int squareNum);
        void clearScreen();
        void drawPixel(byte x, byte y);
        void clearPixel(byte x, byte y);
    private:
        Adafruit_SSD1306 m_display;
        static const uint16_t white = SSD1306_WHITE;
        static const uint16_t black = SSD1306_BLACK;
        static const byte squarePosX[9];
        static const byte squarePosY[9]; 

};

#endif //TICTACTOEDISPLAY_H