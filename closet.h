#ifndef GTKMM_CLOSET_H
#define GTKMM_CLOSET_H

//Hamilton Nguyen 1000538439 

#include <gtkmm.h>
#include <vector>
#define MAKE 10
#define ELEPH 20

using namespace std;

class person
{
	protected:
	string name;
	int item;
	string raw[2];
	string raw1[ELEPH];
	int i;
	char* inputPTR;
	vector<char*>stackpile;
	double item_price[10];
	string item_name[10];
	double balance;
	string baldata;
	
};



class closet_window_1 : public	Gtk::Window, person	
{	
	
	public:

	closet_window_1();		
	virtual	~closet_window_1();	
	
	protected:			

	//signal	handlers
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box shape;
	Gtk::Label	label;
	Gtk::Label	label1;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Entry	entry1;
	Gtk::Button	button_close, button_send; 
};

class closet_window_2	: public Gtk::Window, person
{	
	char* inputPTR;
	
	public:

	closet_window_2();		
	virtual	~closet_window_2();	
		
	protected:			

	//signal	handlers	
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box weight;
	Gtk::Label	label[MAKE];
	Gtk::Box	box;
	Gtk::Entry	entry[MAKE];
	Gtk::Button	button_close, button_send;
};

class closet_window_3	: public Gtk::Window, person
{	
	char* inputPTR;
	
	public:

	closet_window_3();		
	virtual	~closet_window_3();	
		
	protected:			

	//signal	handlers	
	void send_value();
	void close_button();
	void balance_button();	
		
	//widgets
	Gtk::Box weight;
	Gtk::Label	label, label1, label2, label3;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Button	button_close, button_send, button_balance;
	
};		



#endif 