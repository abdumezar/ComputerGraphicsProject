#ifndef FINALPROJECTCOMPUTERGRAPHICS_ADDPROGMENUS_H
#define FINALPROJECTCOMPUTERGRAPHICS_ADDPROGMENUS_H

#include "MyUtilities.h"
HMENU FileMenu = CreatePopupMenu(),
        ColorMenu     = CreatePopupMenu(),
        LineMenu      = CreatePopupMenu(),
        CircleMenu    = CreatePopupMenu(),
        CircleFiling  = CreatePopupMenu(),
        RectangleMenu = CreatePopupMenu(),
        EllipseMenu   = CreatePopupMenu(),
        ConvexMenu    = CreatePopupMenu(),
        FloodFillMenu = CreatePopupMenu(),
        FillingRect   = CreatePopupMenu(),
        FillingSqr    = CreatePopupMenu(),
        CurveMenu     = CreatePopupMenu();

void AddFileMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 1, "Save");
    AppendMenu(subMenu, MF_STRING, 2, "Load");
    AppendMenu(subMenu, MF_SEPARATOR, -1, "");
    AppendMenu(subMenu, MF_STRING, 3, "Clear");
    AppendMenu(subMenu, MF_SEPARATOR, -1, "");
    AppendMenu(subMenu, MF_STRING, 0, "Exit");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "File");
}

void AddColorMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 4, "Choose Color ..");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Color");
}

void AddLineMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 8, "Line DDA");
    AppendMenu(subMenu, MF_STRING, 9, "Line MidPoint");
    AppendMenu(subMenu, MF_STRING, 10, "Line Parametric");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Line");
}

void AddCircleMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 11, "Circle Direct");
    AppendMenu(subMenu, MF_STRING, 12, "Circle Polar");
    AppendMenu(subMenu, MF_STRING, 13, "Circle Iterative Polar");
    AppendMenu(subMenu, MF_STRING, 14, "Circle MidPoint");
    AppendMenu(subMenu, MF_STRING, 15, "Circle modified MidPoint");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Circle");
}

void AddFillingCircleMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 16, "Filing With Lines");
    AppendMenu(subMenu, MF_STRING, 17, "Filing With Circles");
    AppendMenu(subMenu, MF_SEPARATOR, -1, "");
    AppendMenu(subMenu, MF_STRING, 18, "Quarter 1");
    AppendMenu(subMenu, MF_STRING, 19, "Quarter 2");
    AppendMenu(subMenu, MF_STRING, 20, "Quarter 3");
    AppendMenu(subMenu, MF_STRING, 21, "Quarter 4");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Filing Circle");
}

void AddEllipseMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 22, "Ellipse Direct Cartesian");
    AppendMenu(subMenu, MF_STRING, 23, "Ellipse Polar");
    AppendMenu(subMenu, MF_STRING, 24, "Ellipse Iterative Polar");
    AppendMenu(subMenu, MF_STRING, 25, "Ellipse MidPoint");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Ellipse");
}

void AddRectangleMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 26, "Draw Square");
    AppendMenu(subMenu, MF_STRING, 27, "Draw Rectangle");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Rectangle");
}

void AddConvexMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 28, "Convex Filling");
    AppendMenu(subMenu, MF_STRING, 29, "Non-Convex Filling");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Convex");
}

void AddFloodFillMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 30, "FloodFill Recursive");
    AppendMenu(subMenu, MF_STRING, 31, "FloodFill Non-Recursive");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "FloodFill");
}

void AddRectClipMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 32, "Point Clipping");
    AppendMenu(subMenu, MF_STRING, 33, "Line Clipping");
    AppendMenu(subMenu, MF_STRING, 34, "Polygon Clipping");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Rectangle Clipping");
}

void AddSqrClipMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 35, "Point Clipping");
    AppendMenu(subMenu, MF_STRING, 36, "Line Clipping");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Square Clipping");
}

void AddCurveMenu(HMENU MainMenu, HMENU subMenu){
    AppendMenu(subMenu, MF_STRING, 37, "Filling Square Hermite Vertical");
    AppendMenu(subMenu, MF_STRING, 38, "Filling Rectangle Bezier Horizontal");
    AppendMenu(subMenu, MF_STRING, 39, "Spline");
    AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)subMenu, "Curve");
}

HMENU hMenu = CreateMenu();

void LoadMenus(HWND hwnd){
    AddFileMenu(hMenu, FileMenu);
    AddColorMenu(hMenu, ColorMenu);
    AddLineMenu(hMenu, LineMenu);
    AddCircleMenu(hMenu, CircleMenu);
    AddFillingCircleMenu(hMenu, CircleFiling);
    AddRectangleMenu(hMenu, RectangleMenu);
    AddEllipseMenu(hMenu, EllipseMenu);
    AddConvexMenu(hMenu, ConvexMenu);
    AddFloodFillMenu(hMenu,FloodFillMenu);
    AddRectClipMenu(hMenu, FillingRect);
    AddSqrClipMenu(hMenu, FillingSqr);
    AddCurveMenu(hMenu, CurveMenu);
    SetMenu(hwnd, hMenu);
}

#endif
