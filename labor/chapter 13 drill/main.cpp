/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"

int main()
{
    using namespace Graph_lib;
    Point p {100,100};
    Simple_window win(p, 1000, 800, "Drill");
    Lines grid;
    for(int i = 100; i <= 800; i+=100)
    {
    	grid.add(Point(i,0),Point(i,800));
    	grid.add(Point(0,i),Point(800,i));
    }
    win.attach(grid);
    Vector_ref<Rectangle> r;
    for(int i = 0; i < 8; ++i)
    {
    	r.push_back(new Rectangle(Point(i*100, i*100), 100, 100));
    	r[r.size()-1].set_fill_color(Color::red);
    	win.attach(r[r.size()-1]);
    }
    win.wait_for_button();
    Image img1(Point(0,200), "ea.jpeg");
    Image img2(Point(0,400), "ea.jpeg");
    Image img3(Point(0,600), "ea.jpeg");
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.set_label("ex04");
    win.wait_for_button();
    Image bob(Point(0,0), "bob.jpeg");
    int newx = 0;
    int newy = 0;
    win.attach(bob);
    while(newx < 1000 && newy < 800)
    {
    	int x = randint(8);
    	int y = randint(8);
    	newx = 100 * x - bob.point(0).x;
    	newy = 100 * y - bob.point(0).y;
    	bob.move(newx,newy);
    	win.set_label("bob");
    	win.wait_for_button();
    }
    win.wait_for_button();
    
}
