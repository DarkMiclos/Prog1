/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl, 600, 400, "My window"};
	//Exercise 1
	win.set_label("exercise 1");
	Rectangle r { Point{50,50}, 100, 50};
	Polygon p;
	p.add( {200, 50} );
	p.add( {300, 50} );
	p.add( {300, 100} );
	p.add( {200, 100} );
	p.set_color(Color::red);
	r.set_color(Color::blue);
	win.attach(r);
	win.attach(p);
	win.wait_for_button();
	//Exercise 2
	Rectangle r2 { {50, 150}, 100, 30};
	Text t { {75,165}, "Howdy!"};
	win.attach(r2);
	win.attach(t);
	win.set_label("exercise 2");
	win.wait_for_button();
	//Exercise 3
	win.set_label("exercise 3");
	Open_polyline l;
	l.add(Point(350, 50));
	l.add(Point(350,100));
	l.add(Point(375,100));
	l.set_color(Color::red);
	Open_polyline m;
	m.add(Point(400,100));
	m.add(Point(400,50));
	m.add(Point(425,75));
	m.add(Point(450,50));
	m.add(Point(450,100));
	m.set_color(Color::blue);
	win.attach(l);
	win.attach(m);
	win.wait_for_button();
	//Exercise 4
	win.set_label("exercise 4");
	Vector_ref<Rectangle> v;
	int w = 50;
	for(int row = 0; row < 3; ++row)
	{
		for(int col = 0; col < 3; ++col)
		{
			v.push_back(new Rectangle(Point(50+w*col, 200+w*row), w, w));
			int i = v.size()-1;
			i % 2 == 0 ? v[i].set_fill_color(Color::white) : 	v[i].set_fill_color(Color::red);
			win.attach(v[i]);
		}
	}
		
	win.wait_for_button();
	//Exercise 5
	win.set_label("exercise 5");
	Rectangle r5(Point(500,50), x_max()*2/3, y_max() * 3 / 4);
	win.attach(r5);
	win.wait_for_button();
	//Exercise 6
	win.set_label("exercise 6");
	//First half is the 5th exercise
	Simple_window win2(tl, 2000, 1600, "Huge");
	win2.set_label("exercise 6");
	win2.wait_for_button();
	//Exercise 7
	win.set_label("exercise 7");
	Rectangle base(Point(250, 150), 100, 100);
	Polygon roof;
	roof.add(Point(250,150));
	roof.add(Point(350,150));
	roof.add(Point(300,100));
	Rectangle window(Point(265, 175), 25, 25);
	Rectangle window2(Point(265, 210), 25, 25);
	Rectangle door(Point(305, 180), 30, 65);
	Polygon chimney;
	chimney.add(Point(325, 140));
	chimney.add(Point(345, 140));
	chimney.add(Point(345, 110));
	chimney.add(Point(325, 110));
	win.attach(base);
	win.attach(roof);
	win.attach(window);
	win.attach(window2);
	win.attach(door);
	win.attach(chimney);
	win.wait_for_button();
	//Exercise 8
	win.set_label("exercise 8");
	Circle blue(Point(400, 150), 25);
	blue.set_color(Color::blue);
	Circle yellow(Point(425,175), 25);
	yellow.set_color(Color::yellow);
	Circle black(Point(450, 150), 25);
	black.set_color(Color::black);
	Circle green(Point(475,175), 25);
	green.set_color(Color::green);
	Circle red(Point(500,150), 25);
	red.set_color(Color::red);
	win.attach(blue);
	win.attach(yellow);
	win.attach(black);
	win.attach(green);
	win.attach(red);
	win.wait_for_button();
	//Exercise 9
	Image img(Point(50,50), "badge.jpg");
	Text txt(Point(100,100), "Badge");
	win.attach(img);
	win.attach(txt);
	win.set_label("exercise 9");
	win.wait_for_button();
	
}

