#include "Lines_window.h"

Lines_window::Lines_window(Graph_lib::Point xy, int w, int h, const string& title)
:
Graph_lib::Window(xy, w, h, title),
next_button(
	Graph_lib::Point(x_max() - 300, 0),
	150,
	40,
	"Next",
	[](Graph_lib::Address, Graph_lib::Address pw)
	{
		Graph_lib::reference_to<Lines_window>(pw).next();
	}),
quit_button(
	Graph_lib::Point(x_max() - 150, 0),
	150,
	40,
	"Quit",
	[](Graph_lib::Address, Graph_lib::Address pw)
	{
		Graph_lib::reference_to<Lines_window>(pw).quit();
	}),
next_x(
	Graph_lib::Point(300, 0),
	50,
	40,
	"next_x:"),
next_y(
	Graph_lib::Point(450, 0),
	50,
	40,
	"next_y:"),
xy_out(
	Graph_lib::Point(100, 0),
	100,
	40,
	"current x,y:"),
color_menu(
	Graph_lib::Point(x_max() - 70, 50),
	70,
	20,
	Graph_lib::Menu::vertical,
	"color")
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	color_menu.attach(
		new Graph_lib::Button(
			Graph_lib::Point(0, 0),
			0,
			0,
			"Red",
			[](Graph_lib::Address, Graph_lib::Address pw)
			{
				Graph_lib::reference_to<Lines_window>(pw).red_pressed();
			}));
	color_menu.attach(
		new Graph_lib::Button(
			Graph_lib::Point(0, 0),
			0,
			0,
			"Blue", 
			[](Graph_lib::Address, Graph_lib::Address pw)
			{
				Graph_lib::reference_to<Lines_window>(pw).blue_pressed();
			}));
	color_menu.attach(
		new Graph_lib::Button(
			Graph_lib::Point(0, 0),
			0,
			0,
			"Black", 
			[](Graph_lib::Address, Graph_lib::Address pw)
			{
				Graph_lib::reference_to<Lines_window>(pw).black_pressed();
			}));
	attach(color_menu);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	
	lines.add(Graph_lib::Point{x,y});
	
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	
	xy_out.put(ss.str());
	
	redraw();
}

void Lines_window::change(Graph_lib::Color c)
{
 lines.set_color(c);
 redraw();
}

void Lines_window::red_pressed()
{
	change(Graph_lib::Color::red);
}

void Lines_window::blue_pressed()
{
	change(Graph_lib::Color::blue);
}

void Lines_window::black_pressed()
{
	change(Graph_lib::Color::black);
}
