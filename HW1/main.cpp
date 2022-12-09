#include <iostream>
#include "BMP.h"
#include <cmath>


//-- remove at the end
using namespace std;


    BMP bmpNew(300,300,false);

 void midptellipse(int rx, int ry,
                  int x_center, int y_center)
{

    //-- Here is the variables we will use
    
    float dx;        //-- this is derivative of x
    float dy;        //-- this the derivative of y
    float d1;        //-- d1 variable
    float d2;        //-- d2 variable
    float x;         //-- x variable
    float y;         //-- y variable
    x = 0;
    y = ry;
 
    // Initial for region 1
    d1 = (ry * ry) - (rx * rx * ry) +
                     (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
 
    // For region 1
    while (dx < dy)
    {
 
        
         bmpNew.set_pixel(x+x_center, y+y_center, 255, 255, 255, 0);
        //bmpNew.set_pixel(-x+xc, y+yc, 255, 255, 255, 0);
        bmpNew.set_pixel(x+x_center, -y+y_center, 255, 255, 255, 0);
        //bmpNew.set_pixel(-x+xc, -y+yc, 255, 255, 255, 0);
        
 
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
 
    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
 
    // Plotting points of region 2
    while (y >= 0)
    {
 
        // Print points based on 4-way symmetry
        // cout << x + xc << " , " << y + yc << endl;
        // cout << -x + xc << " , " << y + yc << endl;
        // cout << x + xc << " , " << -y + yc << endl;
        // cout << -x + xc << " , " << -y + yc << endl;

        bmpNew.set_pixel(x+x_center, y+y_center, 255, 255, 255, 0);
        //bmpNew.set_pixel(-x+xc, y+yc, 255, 255, 255, 0);
        bmpNew.set_pixel(x+x_center, -y+y_center, 255, 255, 255, 0);
        //bmpNew.set_pixel(-x+xc, -y+yc, 255, 255, 255, 0);
 
        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}


int main() {


    bmpNew.fill_region(0, 0, 300, 300, 0, 0, 0, 0);
   

   midptellipse(120, 60, 150, 150);


    bmpNew.write("output.bmp");


}
