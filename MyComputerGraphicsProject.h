#ifndef FINALPROJECTCOMPUTERGRAPHICS_MYCOMPUTERGRAPHICSPROJECT_H
#define FINALPROJECTCOMPUTERGRAPHICS_MYCOMPUTERGRAPHICSPROJECT_H

#include <iostream>
#include "Line.h"
#include "Circle.h"
#include "Data.h"
#include "Rectangle.h"
#include "AddProgMenus.h"
#include "Ellipse.h"
#include "ConvexFilling.h"
#include "NonConvexFilling.h"
#include "FloodFilling.h"
#include "LineClipping.h"
#include "HermiteCurve.h"
#include "PolygonClipping.h"
#include "BezierCurve.h"

// Global Variables

Point Clicks[20];
Line L;
Window W;
Vector2 Vect[4];
vector<Point> ResPoly;
FileSettings ScreenData("temp.txt");
int counter = 0, shapeChoice = 0, fillingCircleMode = 0, menuChoice = 0, Q = 4, R, C2 = 0, n = 5, prevMenuChoice = 0, prevShapeChoice = 0;
bool flag = true;
COLORREF c = RGB(0, 0, 0);

#endif
