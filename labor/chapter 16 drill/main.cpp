/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "../Graph.h"

int main()
{
	using namespace Graph_lib;
	
	Lines_window win{Point{100,100}, 1920, 1080, "Lines_window"};
	
	return gui_main();
}
