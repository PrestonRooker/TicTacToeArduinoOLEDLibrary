/*
  TicTacToeDisplay.cpp - Library for displaying a tic tac toe board on SSD1306 128x64 OLED display
  Created by Preston J. Rooker, September 14, 2021.  
*/

#include "Arduino.h"
#include "TicTacToeDisplay.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

    const byte TicTacToeDisplay::squarePosX[9] = {68, 88, 108,  68, 88, 108,  68, 88, 108};
    const byte TicTacToeDisplay::squarePosY[9] = {4,  4,  4,    24, 24, 24,   44, 44, 44 };	

    TicTacToeDisplay::TicTacToeDisplay(uint8_t w, uint8_t h, TwoWire *twi, int8_t rst_pin)
    {
        m_display = Adafruit_SSD1306(w,h,twi,rst_pin);        
    }

    void TicTacToeDisplay::begin(uint8_t switchvcc,uint8_t i2caddr)
    {
        m_display.begin(switchvcc,i2caddr);
        m_display.clearDisplay();
        m_display.setTextColor(white);
        m_display.setTextSize(2);
    }

    void TicTacToeDisplay::displayBoard()
    {
        //display.clearDisplay();

        m_display.fillRect(64,0,64,64,black);

        //vertical lines
        m_display.fillRect(84,4,4,56,white);
        m_display.fillRect(104,4,4,56,white);

        //horizontal lines
        m_display.fillRect(68,20,56,4,white);
        m_display.fillRect(68,40,56,4,white);
        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::drawX(int squareNum)
    {
        m_display.setCursor(squarePosX[squareNum] + 3, squarePosY[squareNum] + 1);
        m_display.print("X");
        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::drawO(int squareNum)
    {
        m_display.setCursor(squarePosX[squareNum] + 3, squarePosY[squareNum] + 1);
        m_display.print("O");
        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::drawVictoryLine(int firstSquareNum, int secondSquareNum)
    {
        int x0;
        int y0;
        int x1;
        int y1;
        uint16_t color = SSD1306_WHITE;
        //void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
        if( (firstSquareNum == 0 && secondSquareNum == 8) || (firstSquareNum == 8 && secondSquareNum == 0)){
            x0 = 68;
            y0 = 4;
            x1 = 123;
            y1 = 59;
        }
        else if( (firstSquareNum == 2 && secondSquareNum == 6) || (firstSquareNum == 6 && secondSquareNum == 2)){
            x0 = 123;
            y0 = 4;
            x1 = 68;
            y1 = 59;
        }
        else if( (firstSquareNum == 0 && secondSquareNum == 6) || (firstSquareNum == 6 && secondSquareNum == 0)){
            x0 = 75;
            y0 = 4;
            x1 = 75;
            y1 = 59;
        }
        else if( (firstSquareNum == 1 && secondSquareNum == 7) || (firstSquareNum == 7 && secondSquareNum == 1)){
            x0 = 95;
            y0 = 4;
            x1 = 95;
            y1 = 59;
        }
        else if( (firstSquareNum == 2 && secondSquareNum == 8) || (firstSquareNum == 8 && secondSquareNum == 2)){
            x0 = 115;
            y0 = 4;
            x1 = 115;
            y1 = 59;
        }
        else if( (firstSquareNum == 0 && secondSquareNum == 2) || (firstSquareNum == 2 && secondSquareNum == 0)){
            x0 = 69;
            y0 = 12;
            x1 = 123;
            y1 = 12;
        }
        else if( (firstSquareNum == 3 && secondSquareNum == 5) || (firstSquareNum == 5 && secondSquareNum == 3)){
            x0 = 69;
            y0 = 32;
            x1 = 123;
            y1 = 32;
        }
        else if( (firstSquareNum == 6 && secondSquareNum == 8 ) || (firstSquareNum == 8 && secondSquareNum == 6)){
            x0 = 69;
            y0 = 52;
            x1 = 123;
            y1 = 52;
        }
        m_display.drawLine( x0, y0, x1, y1, color);
        m_display.drawLine( x0 + 1, y0, x1 + 1, y1, color);
        m_display.drawLine( x0 - 1, y0, x1 - 1, y1, color);
        m_display.drawLine( x0, y0 + 1, x1, y1 + 1, color);
        m_display.drawLine( x0, y0 - 1, x1, y1 - 1, color);
        m_display.display();
    }

    //can draw 11 characters horizontally
    //can draw 8  characters vertically
    void TicTacToeDisplay::drawSmallText(String text)
    {
        m_display.fillRect(0,0,64,32,black);
        m_display.setTextSize(1);
        m_display.setCursor(0,0);
        if(text.length() > 88){
            m_display.print(F("Too many\ncharacters!"));
            m_display.display();
            m_display.setTextSize(2);
            return;
        }
        for(int i = 0; i < text.length(); i++)
        {
            m_display.write(text.charAt(i));
            if((i+1)%11 == 0){
            m_display.write('\n');
            }
        }
        m_display.display();
        m_display.setTextSize(2);
    }

    //can draw 5 characters horizontally
    //can draw 4 characters vertically
    void TicTacToeDisplay::drawLargeText(String text)
    {
        m_display.fillRect(0,0,64,32,black);
        m_display.setTextSize(2);
        m_display.setCursor(0,0);
        if(text.length() > 20){
            m_display.print(F("Too\nmany\nchars\n!!!!!"));
            m_display.display();
            m_display.setTextSize(2);
            return;
        }
        for(int i = 0; i < text.length(); i++)
        {
            m_display.write(text.charAt(i));
            if((i+1)%5 == 0){
            m_display.write('\n');
            }
        }
        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::selectSquare(int squareNum)
    {
        int posX = squarePosX[squareNum];
        int posY = squarePosY[squareNum];

        m_display.drawRect(posX,posY,4,4,white);
        m_display.drawRect(posX + 12,posY,4,4,white);
        m_display.drawRect(posX,posY + 12,4,4,white);
        m_display.drawRect(posX + 12,posY + 12,4,4,white);

        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::deselectSquare(int squareNum)
    {
        int posX = squarePosX[squareNum];
        int posY = squarePosY[squareNum];
        
        m_display.fillRect(posX,posY,4,4,black);
        m_display.fillRect(posX + 12,posY,4,4,black);
        m_display.fillRect(posX,posY + 12,4,4,black);
        m_display.fillRect(posX + 12,posY + 12,4,4,black);
        
        m_display.display();
    }

    //  squareNum 0 - 8
    //
    //    0 | 1 | 2
    //    ---------
    //    3 | 4 | 5
    //    ---------
    //    6 | 7 | 8
    //
    void TicTacToeDisplay::clearSquare(int squareNum)
    {
        int posX = squarePosX[squareNum];
        int posY = squarePosY[squareNum];
        
        m_display.fillRect(posX,posY,16,16,black);
        
        m_display.display();
    }

    //Clears the entire screen
    void TicTacToeDisplay::clearScreen()
    {
        m_display.clearDisplay();
        m_display.display();
    }

    //Provided in case you really wanted to manually draw something, but if you want to do that
    //  I reccomend that you just use Adafruit_SSD1306 and Adafruit_GFX by themselves
    void TicTacToeDisplay::drawPixel(byte x, byte y)
    {
        m_display.drawPixel(x,y,white);
        m_display.display();
    }
    
    //Provided in case you really wanted to manually draw something, but if you want to do that
    //  I reccomend that you just use Adafruit_SSD1306 and Adafruit_GFX by themselves
    void TicTacToeDisplay::clearPixel(byte x, byte y)
    {
        m_display.drawPixel(x,y,black);
        m_display.display();
    }