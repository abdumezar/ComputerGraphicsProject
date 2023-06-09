#include "MyComputerGraphicsProject.h"

LRESULT CALLBACK wndproc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;
    int x = LOWORD(lp);
    int y = HIWORD(lp);
    switch (m) {
        case WM_LBUTTONDOWN:
            if((shapeChoice >= 0 && shapeChoice <= 13) || menuChoice == 33 || menuChoice == 36){
                Clicks[counter].x = x;
                Clicks[counter].y = y;
                counter++;
            }
            break;
        case WM_LBUTTONUP:
            hdc = GetDC(hwnd);
            if(shapeChoice >= 0 && shapeChoice <= 13) {
                Clicks[counter].x = x;
                Clicks[counter].y = y;
                counter = 0;
                R = (int) CalcDistance(Clicks[0], Clicks[1]);
                switch(shapeChoice){
                    case 0:  DrawLineDDA(hdc, Line(Clicks[0], Clicks[1]), c);    break;
                    case 1:  DrawLineMidPoint(hdc,Line(Clicks[0], Clicks[1]),c); break;
                    case 2:  drawLineHermite(hdc,Clicks[0].x,Clicks[0].y,Clicks[1].x,Clicks[1].y,c); break;
                    case 3:  DrawCircleDirect(hdc,Clicks[0],R,c); break;
                    case 4:  DrawCirclePolorSimilarity(hdc,Clicks[0],R,c);    break;
                    case 5:  DrawCircleIterativePolar(hdc,Clicks[0],R,c);     break;
                    case 6:  DrawCircleBresenhamMidPoint(hdc,Clicks[0],R,c);  break;
                    case 7:  DrawCircleBresenhamImproveII(hdc,Clicks[0],R,c); break;
                    case 8:  DrawEllipseCart(hdc,Clicks[0],R,R/2, c);  break;
                    case 9:  DrawEllipsePolar(hdc,Clicks[0],R,R/2, c); break;
                    case 10: DrawEllipseIterativePolar(hdc,Clicks[0],R,R/2, c); break;
                    case 11: DrawEllipseMidPoint(hdc,Clicks[0],R,R/2,c);  break;
                    case 12: W.drawSquare(hdc, Clicks[0].y, Clicks[1].y, Clicks[0].x, Clicks[1].x, c);    break;
                    case 13: W.drawRectangle(hdc, Clicks[0].y, Clicks[1].y, Clicks[0].x, Clicks[1].x, c); break;
                    default: cout<<"will never execute";
                }
                ScreenData.SaveCurrentData(shapeChoice,Clicks,R,c, -1, fillingCircleMode, Q);
            }

            if(menuChoice >= 16 && menuChoice <= 21) {
                switch (fillingCircleMode) {
                    case 0: FillingCircleWithLines(hdc,Clicks[0],R,Q,1.57,c);   break;
                    case 1: FillingCircleWithCircles(hdc,Clicks[0],R,Q,1.57,c); break;
                    default: cout<<"will never execute";
                }
                ScreenData.SaveCurrentData(-1,Clicks,R,c, menuChoice, fillingCircleMode, Q);
            }

            else if(menuChoice == 28 || menuChoice == 29){
                Clicks[counter].x = x;
                Clicks[counter].y = y;
                counter++;
                if(counter == n){
                    switch (menuChoice) {
                        case 28: ConvexFilling(hdc,Clicks,n,c); break;
                        case 29: NonConvexFilling(hdc,Clicks,n,c); break;
                        default: cout<<"will never execute";
                    }
                    ScreenData.SaveCurrentData(-1,Clicks,n,c, menuChoice, -1, -1);
                    counter = 0;
                }

            }

            else if(menuChoice == 30 || menuChoice == 31){
                Clicks[0] = Point(x,y);
                switch (menuChoice) {
                    case 30: FloodFillRec(hdc,Clicks[0],RGB(64,64,64),c); break;
                    case 31: FloodFillNonRecQ(hdc,Clicks[0],RGB(64,64,64),c); break;
                    default: cout<<"will never execute";
                }
                ScreenData.SaveCurrentData(-1,Clicks,-1,c, menuChoice, -1, -1);
            }

            else if(menuChoice >= 32 && menuChoice <= 36 && menuChoice != 34){
                Clicks[counter].x = x;
                Clicks[counter].y = y;
                counter = 0;
                if(flag){
                    shapeChoice = -1;
                    counter = 0;
                    flag = false;
                }
                else{
                    switch (menuChoice) {
                    case 32: case 35:
                        if(PointClipping(Clicks[0], W)){
                            SetPixel(hdc,Clicks[0].x,Clicks[0].y,c);
                            ScreenData.SaveCurrentData(-1,Clicks,1,c, menuChoice, -1, -1);
                        }
                        break;
                    case 33: case 36:
                        L.S = Clicks[0];
                        L.E = Clicks[1];
                        if(LineClipping(L,W)){
                            DrawLineMidPoint(hdc,L,c);
                            Clicks[0] = L.S;
                            Clicks[1] = L.E;
                            ScreenData.SaveCurrentData(-1,Clicks,2,c, menuChoice, -1, -1);
                        }
                        break;
                    default: cout<<"will never execute";
                    }
                    counter = 0;
                }

            }

            else if(menuChoice == 34){
                if(flag){
                    shapeChoice = -1;
                    counter = 0;
                    flag = false;
                }else{
                    Clicks[counter].x = x;
                    Clicks[counter].y = y;
                    counter++;
                    if(counter == n){
                        ResPoly = PolyClip(Clicks, n, W);
                        ConvexFilling(hdc, ResPoly , c);

                        for(int i=0; i<ResPoly.size(); i++)
                            Clicks[i].x = ResPoly[i].x, Clicks[i].y = ResPoly[i].y;

                        ScreenData.SaveCurrentData(-1,Clicks,(int)ResPoly.size(),c, menuChoice, -1, -1);
                        counter = 0;
                    }
                }
            }

            else if(menuChoice >= 37 && menuChoice <= 39){
                if(flag){
                    shapeChoice = -1;
                    counter = 0;
                    flag = false;
                }
                else{
                    Vect[C2].x = x;
                    Vect[C2].y = y;
                    Clicks[C2].x = x;
                    Clicks[C2].y = y;
                    C2++;

                    if(C2 == 4) {
                        Clicks[4] = Point(W.Left, W.Top);
                        Clicks[5] = Point(W.Right, W.Bottom);
                        ScreenData.SaveCurrentData(-1,Clicks,4,c, menuChoice, -1, -1);

                        switch (menuChoice) {
                            case 37:
                                FillingHermite(hdc, Vect, W, c);
                                shapeChoice = 12;
                                flag = true;
                                break;
                            case 38:
                                FillingBezier(hdc,Clicks,4,W,c);
                                shapeChoice = 13;
                                flag = true;
                                break;
                            case 39:
                                DrawCardinalSpline(hdc, Vect, 4,0.005, c);
                                break;
                            default: cout<<"will never execute";
                        }

                        C2 = 0;
                        counter = 0;
                    }
                }
            }

            ReleaseDC(hwnd, hdc);
            break;
        case WM_COMMAND:
            hdc = GetDC(hwnd);
            menuChoice = LOWORD(wp);
            switch(menuChoice){
                case 0:
                    FileSettings::DeleteFile("temp.txt");
                    DestroyWindow(hwnd);
                    break;
                case 1: // File Menu -> Save Data
                    FileSettings::ClearData("Saved.txt");
                    ScreenData.SaveFromTemp("Saved.txt");
                    break;
                case 2: // File Menu -> Load Data
                    if(!ScreenData.LoadDataFromFile(hdc, "Saved.txt"))
                        cout<<"\nFailed to load file!\n";
                    break;
                case 3: // File Menu -> Clear Window
                    RECT rc;
                    GetClientRect(hwnd, &rc);
                    InvalidateRect(hwnd, &rc, TRUE);
                    system("cls");
                    FileSettings::ClearData("temp.txt");
                    break;
                case 4: // Color Menu -> Choose Color
                    CHOOSECOLOR chooseColor;
                    static COLORREF palette[16];
                    ZeroMemory(&chooseColor, sizeof(chooseColor));
                    chooseColor.lStructSize = sizeof(chooseColor);
                    chooseColor.hwndOwner = hwnd;
                    chooseColor.lpCustColors = (LPDWORD)palette;
                    chooseColor.rgbResult = c;
                    chooseColor.Flags = CC_FULLOPEN | CC_RGBINIT;

                    if (ChooseColor(&chooseColor) == TRUE)
                        c = chooseColor.rgbResult;

                    menuChoice = prevMenuChoice;
                    shapeChoice = prevShapeChoice;
                    break;
                case 8: // Shape Menu -> Line DDA
                    cout<<"Line DDA\n";
                    shapeChoice = 0;
                    break;
                case 9: // Shape Menu -> Line MidPoint
                    cout<<"Line MidPoint\n";
                    shapeChoice = 1;
                    break;
                case 10: // Shape Menu -> Line Parametric
                    cout<<"Line Parametric\n";
                    shapeChoice = 2;
                    break;
                case 11: // Shape Menu -> Circle Direct
                    cout<<"Circle Direct\n";
                    shapeChoice = 3;
                    break;
                case 12: // Shape Menu -> Circle Polar
                    cout<<"Circle Polar\n";
                    shapeChoice = 4;
                    break;
                case 13: // Shape Menu -> Circle Iterative Polar
                    cout<<"Circle Iterative Polar\n";
                    shapeChoice = 5;
                    break;
                case 14: // Shape Menu -> Circle MidPoint
                    cout<<"Circle MidPoint\n";
                    shapeChoice = 6;
                    break;
                case 15: // Shape Menu -> Circle modified MidPoint
                    cout<<"Circle modified MidPoint\n";
                    shapeChoice = 7;
                    break;
                case 16: // Filling Circle -> Filling with Lines
                    cout<<"Filling Circle with Lines\n";
                    shapeChoice = 7;
                    fillingCircleMode = 0;
                    break;
                case 17: // Filling Circle -> Filling with Circles
                    cout<<"Filling Circle with Circles\n";
                    shapeChoice = 7;
                    fillingCircleMode = 1;
                    break;
                case 18: case 19: case 20: case 21:
                    // Filling Circle -> Choose which quarter
                    switch(menuChoice){
                        case 18: Q = 4; break;
                        case 19: Q = 3; break;
                        case 20: Q = 2; break;
                        case 21: Q = 1; break;
                        default: cout<<"will never execute";
                    }
                    cout<< "Filling Q: "<< menuChoice - 17 <<" of circle\n";
                    shapeChoice = 7;
                    break;
                case 22:
                    // Ellipse -> Draw  Ellipse Direct Cartesian
                    cout<<"Drawing Ellipse Direct Cartesian\n";
                    shapeChoice = 8;
                    break;
                case 23:
                    // Ellipse -> Draw Ellipse Polar
                    cout<<"Drawing Ellipse Polar\n";
                    shapeChoice = 9;
                    break;
                case 24:
                    // Ellipse -> Draw Ellipse Iterative Polar
                    cout<<"Drawing Ellipse Iterative Polar\n";
                    shapeChoice = 10;
                    break;
                case 25:
                    // Ellipse -> Draw Ellipse MidPoint
                    cout<<"Drawing Ellipse MidPoint\n";
                    shapeChoice = 11;
                    break;
                case 26:
                    // Rectangle -> Draw Square
                    cout<<"Drawing Square based on its diagonal\n";
                    shapeChoice = 12;
                    break;
                case 27:
                    // Rectangle -> Draw Rectangle
                    cout<<"Drawing Rectangle\n";
                    shapeChoice = 13;
                    break;
                case 28:
                    // Convex -> Convex Filling
                    cout<<"Convex Filling\n";
                    shapeChoice = -1;
                    break;
                case 29:
                    // Convex -> Non-Convex Filling
                    cout<<"Non-Convex Filling\n";
                    Table.resize(3000);
                    shapeChoice = -1;
                    break;
                case 30:
                    // FloodFill -> FloodFill Recursive
                    cout<<"FloodFill Recursive\n";
                    Table.resize(3000);
                    shapeChoice = -1;
                    break;
                case 31:
                    // FloodFill -> FloodFill Non-Recursive
                    cout<<"FloodFill Non-Recursive\n";
                    Table.resize(3000);
                    shapeChoice = -1;
                    break;
                case 32:
                    // Rectangle Clipping -> Point
                    cout<<"Rectangle Clipping - Point\n";
                    flag = true;
                    shapeChoice = 13;
                    break;
                case 33:
                    // Rectangle Clipping -> Line
                    cout<<"Rectangle Clipping - Line\n";
                    flag = true;
                    shapeChoice = 13;
                    break;
                case 34:
                    // Rectangle Clipping -> Polygon
                    cout<<"Rectangle Clipping -> Polygon\n";
                    Table.resize(3000);
                    flag = true;
                    shapeChoice = 13;
                    break;
                case 35:
                    // Square Clipping -> Point
                    cout<<"Square Clipping -> Point\n";
                    flag = true;
                    shapeChoice = 12;
                    break;
                case 36:
                    // Square Clipping -> Line
                    cout<<"Square Clipping -> Line\n";
                    flag = true;
                    shapeChoice = 12;
                    break;
                case 37:
                    // Square Filling -> Hermite Vertical
                    cout<<"Square Filling -> Hermite Vertical\n";
                    flag = true;
                    shapeChoice = 12;
                    break;

                case 38:
                    // Rectangle Filling -> Bezier Horizontal
                    cout<<"Rectangle Filling -> Bezier Horizontal\n";
                    flag = true;
                    shapeChoice = 13;
                    break;
                case 39:
                    // Spline
                    cout<<"Spline\n";
                    shapeChoice = -1;
                    flag = false;
                    break;
                default: cout<<"will never execute";
            }
            ReleaseDC(hwnd, hdc);
            break;
        case WM_CREATE:
            LoadMenus(hwnd);
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            FileSettings::DeleteFile("temp.txt");
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, m, wp, lp);
    }
    prevMenuChoice = menuChoice;
    prevShapeChoice = shapeChoice;
    return 0;
}

int APIENTRY WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int csh) {
    WNDCLASS wc;
    wc.lpszClassName = TEXT("MyClass");
    wc.lpszMenuName = nullptr;
    wc.hCursor = LoadCursor(nullptr, IDC_CROSS);
    wc.hIcon = LoadIcon(nullptr, IDI_SHIELD);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = wndproc;
    wc.hInstance = h;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(TEXT("MyClass"), TEXT("Computer Graphics Project"), WS_OVERLAPPEDWINDOW, 60, 60, 1800, 900, nullptr, nullptr, h, nullptr);
    ShowWindow(hwnd, csh);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
