//
// Library for controlling Electronic Assembly eDIPTFT displays
//
//      Copyright (c) 2013 Stefan Gofferje. All rights reserved.
//
//      This library is free software; you can redistribute it and/or
//      modify it under the terms of the GNU Lesser General Public
//      License as published by the Free Software Foundation; either
//      version 2.1 of the License, or (at your option) any later
//      version.
//
//      This library is distributed in the hope that it will be
//      useful, but WITHOUT ANY WARRANTY; without even the implied
//      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//      PURPOSE.  See the GNU Lesser General Public License for more
//      details.
//
//      You should have received a copy of the GNU Lesser General
//      Public License along with this library; if not, write to the
//      Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
//      Boston, MA 02110-1301 USA
//

#ifndef EDIPTFT_h
#define EDIPTFT_h

#include <Arduino.h>

//Devices
#define EDIP128 1
#define EDIP160 1
#define EDIP240 1
#define EDIP320 2

//Set your device
#define DEVICE EDIP240
#define COORD_SIZE DEVICE  //Byte count for coordinates

#define EA_BLACK 1
#define EA_BLUE 2
#define EA_RED 3
#define EA_GREEN 4
#define EA_PURPLE 5
#define EA_CYAN 6
#define EA_YELLOW 7
#define EA_WHITE 8
#define EA_DARKGREY 9
#define EA_ORANGE 10
#define EA_LILA 11
#define EA_DARKPURPLE 12
#define EA_MINT 13
#define EA_GRASSGREEN 14
#define EA_LIGHTBLUE 15
#define EA_LIGHTGREY 16

// Fonts
#define EA_FONT8X8 0
#define EA_FONT4X6 1
#define EA_FONT6X8 2
#define EA_FONT7X12 3
#define EA_GENEVA10 4
#define EA_CHICAGO14 5
#define EA_SWISS30B 6
#define EA_BIGZIF57 7

#define NAK 0x15
#define ACK 0x06
#define ESC 0x1B

class EDIPTFT {
  public:
    EDIPTFT(boolean smallprotocol=true);
    void begin(long baud=115200);
    char readByte();
    char waitandreadByte();
    unsigned char datainBuffer();
    int readBuffer(char* data);
    void smallProtoSelect(char address);
    void smallProtoDeselect(char address);
    void sendData(char* data, char len);
    void clear();
    void invert();
    void setDisplayColor(char fg, char bg);
    void fillDisplayColor(char bg);
    void terminalOn(boolean on);
    void cursorOn(boolean on);
    void setCursor(char col, char row);
    void defineBargraph(char dir, char no, int x1, int y1, int x2, int y2, byte sv, byte ev, char type, char mst);
    void updateBargraph(char no, char val);
    void setBargraphColor(char no, char fg, char bg, char fr);
    void makeBargraphTouch(char no);
    void linkBargraphLight(char no);
    void deleteBargraph(char no,char n1);
    void defineInstrument(char no, int x1, int y1, char image, char angle, char sv, char ev);
    void updateInstrument(char no, char val);
    void redrawInstrument(char no);
    void deleteInstrument(char no, char n1, char n2);
    void setTextColor(char fg, char bg);
    void setTextFont(char font);
    void setTextAngle(char angle);
    void drawText(int x1, int y1, char justification,char* text);
    void setLineColor(char fg, char bg);
    void setLineThick(char x, char y);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawRect(int x1, int y1, int x2, int y2);
    void drawRectf(int x1, int y1, int x2, int y2, char color);
    void defineTouchKey(int x1, int y1, int x2, int y2, char down, char up, char* text);
    void defineTouchSwitch(int x1, int y1, int x2, int y2, char down, char up, char* text);
    void setTouchSwitch(char code,char value);
    void setTouchkeyColors(char n1, char n2, char n3, char s1, char s2, char s3);
    void setTouchkeyFont(char font);
    void setTouchkeyLabelColors(char nf,char sf);
    void setTouchGroup(char group);
    void removeTouchArea(char code,char n1);
  private:
    boolean _smallprotocol;
    unsigned char bytesAvailable();
    void waitBytesAvailable();
    void sendByte(char data);
    void sendSmall(char* data, char len);
    void sendSmallDC2(char* data, char len);
};
#endif
