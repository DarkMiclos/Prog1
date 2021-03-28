/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    using namespace Graph_lib;
    const int xmax = 600;
    const int ymax = 600;
    
    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);
    Point p1(100,100);
    
    const int r_min = -10;
    const int r_max = 11;
    const int points = 400;
    
    Simple_window win(p1, xmax, ymax, "Function graphs");
    const int length = 400;
    const int scale = 20;
    
    Axis x(Axis::x, Point(100,x_orig), length, length/scale, "1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y, Point(x_orig,500), length, length/scale, "1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();
    
    Function s(one, r_min, r_max, orig, points, scale, scale);
    win.attach(s);
    win.wait_for_button();
    
    Function s2(slope, r_min, r_max, orig, points, scale, scale);
    win.attach(s2);
    win.wait_for_button();
    
    Text t(Point(100,y_orig+4*scale), "x/2");
    win.attach(t);
    win.wait_for_button();
    
    Function s3(square, r_min, r_max, orig, points, scale, scale);
    win.attach(s3);
    win.wait_for_button();
    
    Function s4(cos, r_min, r_max, orig, points, scale, scale);
    s4.set_color(Color::blue);
    win.attach(s4);
    win.wait_for_button();
    
    Function s5(sloping_cos, r_min, r_max, orig, points, scale, scale);
    win.attach(s5);
    win.wait_for_button();
    
    
    
}
