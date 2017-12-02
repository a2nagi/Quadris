#include <iostream>
#include "graphicsdisplay.h"
#include "../model/Info.h"
#include "../model/Subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(Grid *g):g{g} {

  xw.drawString(200, 20, "Project Quadris", Xwindow::Blue);
  xw.drawString(100, 40, "Level:", Xwindow::Blue);
  xw.drawString(100, 60, "Score:", Xwindow::Blue);
  xw.drawString(100, 80, "Hi Score", Xwindow::Blue);
  xw.fillRectangle(0,150,500,500,Xwindow::Cyan);
}

void GraphicsDisplay::notify(Subject &whoNotified) {
  Info I = whoNotified.getInfo();
  int cellColSize = 500 / 11;
  int cellRowSize = 500 / 18;a

  switch(I.blockType) {
   case 'I':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Green);
      break;
   case 'J':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Black);
      break;
   case 'L':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Blue);
      break;
   case 'O':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Brown);
      break;
   case 'S':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Yellow);
      break;
   case 'Z':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Magenta);
      break;
   case 'T':
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Orange);
       break;
     default:
      xw.fillRectangle(I.col*cellColSize,150+I.row*cellRowSize,cellColSize,cellRowSize, Xwindow::Cyan);
  }
}
