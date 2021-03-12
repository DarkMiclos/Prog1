/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;
    Point tl {100,100};
	Simple_window win {tl, 600, 400, "My window"};
	Point origo{100, 100};
	Function s (one, -11, 11, origo, 400, 30, 30);
	Axis x {Axis::x, Point{20, 300}, 280, 12, "x"};
	Axis y {Axis::y, Point{20, 300}, 280, 12, "y"};
	x.set_color(Color::blue);
	Rectangle r {Point{200,200}, 100, 50};
	r.set_fill_color(Color::red);
	r.set_style(Line_style(Line_style::dash, 4));
	Text t {Point{200,200}, "Hollokepu"};
	t.set_color(Color::cyan);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	Circle c {Point{400,100}, 50};
	win.attach(c);
	win.attach(x);
	win.attach(y);
	win.attach(r);
	win.attach(s);
	win.attach(t);
	win.wait_for_button();

}
