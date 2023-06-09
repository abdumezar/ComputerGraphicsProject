cmake_minimum_required(VERSION 3.25)
project(FinalProjectComputerGraphics)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        FinalProjectComputerGraphics
        main.cpp
        Line.h
        MyUtilities.h
        Point.h
        Circle.h
        Data.h
        Rectangle.h
        AddProgMenus.h
        Ellipse.h
        ConvexFilling.h
        NonConvexFilling.h
        FloodFilling.h
        LineClipping.h
        HermiteCurve.h
        PolygonClipping.h
        BezierCurve.h
        MyComputerGraphicsProject.h
)
