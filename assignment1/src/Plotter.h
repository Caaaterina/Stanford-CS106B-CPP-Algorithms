#include "Plotter.h"
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    double x = 0, y = 0;
    bool PenDown = false;
    PenStyle style;
    style.width = 1;
    style.color = "black";

    for (string line; getline(input, line);){
        istringstream parser(line);

        string command;
        parser >> command;

        for (char& ch: command){
            ch = tolower(ch);
        }

        if (command == "penup"){
            PenDown = false;
        }else if(command =="pendown"){
            PenDown = true;
        }else if(command == "moveabs"){
            double a, b;
            parser >> a;
            parser >> b;

            if (PenDown){
                drawLine(x, y, a, b, style);
                x = a;
                y = b;
            }else{
                x = a;
                y = b;
            }

        }else if(command == "moverel"){
            double dx, dy;
            parser >> dx;
            parser >> dy;
            double newX = x + dx;
            double newY = y + dy;

            if (PenDown){
                drawLine(x, y, newX, newY, style);
                x = newX;
                y = newY;
            }else{
                x = newX;
                y = newY;
            }
        }else if(command == "penwidth"){
            double width;
            parser >> width;
            style.width = width;
        }else if(command == "pencolor"){
            string color;
            parser >> color;
            style.color = color;
        }
    }
}


