//Hamilton Nguyen 1000538439 

#include "closet.h"
#include <iostream>
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv);
	auto app1 = Gtk::Application::create(argc, argv);
	auto app2 = Gtk::Application::create(argc, argv);
	
	closet_window_1 a;
	app->run(a);
	
	closet_window_2 b;
	app1->run(b);
	
	closet_window_3 c;
	app2->run(c);
}