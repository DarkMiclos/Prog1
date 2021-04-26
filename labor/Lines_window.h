#include "GUI.h"

struct Lines_window : public Graph_lib::Window
{
	Lines_window(Graph_lib::Point xy, int w, int h, const string& title);
	Graph_lib::Open_polyline lines;
	bool wait_for_button();

 private:
	Graph_lib::Menu color_menu;
	Graph_lib::Menu style_menu;
 
	Graph_lib::Button next_button;
	Graph_lib::Button quit_button;
	Graph_lib::Button color_button;
	
	Graph_lib::In_box next_x;
	Graph_lib::In_box next_y;
	
	Graph_lib::Out_box xy_out;
	
	void next();
	void quit();
	
	void change(Graph_lib::Color c);
	void red_pressed();
	void blue_pressed();
	void black_pressed();

};
