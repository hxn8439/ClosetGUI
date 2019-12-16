//Hamilton Nguyen 1000538439 

#include "closet.h"
#include <iostream>
#include <sstream>
#include <fstream>

closet_window_1::closet_window_1() : box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Submit")
{			
	set_size_request(400, 200);			
	set_title("Closet Question 1:");	
	
	add(box);	
	
	label.set_text("Hello Closet Cleaner! Enter Your Name:");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. Marko");	
	entry.select_region(0, entry.get_text_length());
	box.pack_start(entry);	

	label1.set_text("How many items do you want to sell (10 is max)?");	
	box.pack_start(label1);	
	entry1.set_max_length(4000);
	entry1.set_text("e.g. 3");	
	entry1.select_region(1, entry1.get_text_length());
	box.pack_start(entry1);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,&closet_window_1::send_value));		
	box.pack_start(button_send);	

	button_close.signal_clicked().connect(	sigc::mem_fun(*this, &closet_window_1::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
}	
	
closet_window_1::~closet_window_1()
{

}	

void	closet_window_1::send_value()	
{			
	name=entry.get_text();
	string convert= entry1.get_text();
	
	ofstream written("person.txt");
	if(written.is_open())
	{	
		written<<name+'\n';
		written<<convert+'\n';
	}	
	
	else
	cout<<"UNABLE TO OPEN person.TXT FILE"<<endl;	

	hide();	
}	
	
void closet_window_1::close_button()
{			
	exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

closet_window_2::closet_window_2()	: box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Submit")
{			
	
	ifstream file;
	string line;
	file.open("person.txt");
	
	int i = 0;
	while(getline(file,line))
	{
		stringstream linestream(line);
		getline(linestream, raw[i]);
		++i;
	}
	
	
	stringstream ss;
	ss<<raw[1];
	ss>>item;
	
	set_size_request(400, 200);			
	set_title("Closet Question 2:");	
	
	add(box);
	int increm = 0;

	for(i=0; i<item; i++)
	{	
		label[i].set_text("Enter item and price:");	
		box.pack_start(label[i]);	
		entry[i].set_max_length(4000);
		entry[i].set_text("For an example: belt 3.50");	
		entry[i].select_region(increm, entry[i].get_text_length());
		box.pack_start(entry[i]);	
		++increm;
	}
	
	button_send.signal_clicked().connect(sigc::mem_fun(*this,		
	&closet_window_2::send_value));		
	box.pack_start(button_send);	


	button_close.signal_clicked().connect(	sigc::mem_fun(*this,
	&closet_window_2::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
	file.close();
}	
	
closet_window_2::~closet_window_2()
{

}	
	
void closet_window_2::send_value()	
{	
	for(i = 0; i<item; i++)
	{	
		string	rawinput=entry[i].get_text();
		char p[rawinput.length()];
		int j;
		
		for (j =0; j< sizeof(p); j++)
		{
			p[j]=rawinput[j];
		}

		inputPTR =strtok(p, " ");
		stackpile.push_back(inputPTR);
		while(inputPTR != NULL)
		{
			inputPTR =strtok(NULL, " ");
			stackpile.push_back(inputPTR);
		}
		
		string input = stackpile[0];
		string input1 = stackpile[1];
		
		ofstream written("data.txt", ios::out | ios::app);
		if(written.is_open())
		{	
			written<<input<<endl;
			written<<input1<<endl;
		}	
		
		else
		cout<<"UNABLE TO OPEN data.txt FILE"<<endl;	
		
		stackpile.clear();
		hide();
	}
}	
	
void closet_window_2::close_button()
{			
	exit(0);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

closet_window_3::closet_window_3()	: box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Buy"), button_balance("Balance")
{			
	ifstream file1;
	string line1;
	file1.open("person.txt");
	
	int i = 0;
	while(getline(file1,line1))
	{
		stringstream linestream1(line1);
		getline(linestream1, raw[i]);
		++i;
	}
	name = raw[0];
	item = stoi(raw[1]);
	
	ifstream file;
	string line;
	file.open("data.txt");
	
	i = 0;
	
	while(getline(file,line))
	{
		stringstream linestream(line);
		getline(linestream, raw1[i]);
		++i;
	}
	
	item_name[0] = raw1[0];
	item_name[1] = raw1[2];
	item_name[2] = raw1[4];
	item_name[3] = raw1[6];
	item_name[4] = raw1[8];
	item_name[5] = raw1[10];
	item_name[6] = raw1[12];
	item_name[7] = raw1[14];
	item_name[8] = raw1[16];
	item_name[9] = raw1[18];
	
	stringstream ss; 
	ss<<raw1[1];
	ss>>item_price[0];
	
	stringstream as; 
	as<<raw1[3];
	as>>item_price[1];
	
	stringstream bs; 
	bs<<raw1[5];
	bs>>item_price[2];
	
	stringstream cs; 
	bs<<raw1[7];
	bs>>item_price[3];
	
	stringstream ds; 
	ds<<raw1[9];
	ds>>item_price[4];
	
	stringstream es; 
	es<<raw1[11];
	es>>item_price[5];
	
	stringstream fs; 
	fs<<raw1[13];
	fs>>item_price[6];
	
	stringstream gs; 
	gs<<raw1[15];
	gs>>item_price[7];
	
	stringstream hs; 
	hs<<raw1[17];
	hs>>item_price[8];
	
	stringstream is; 
	is<<raw1[19];
	is>>item_price[9];

/*
	cout<<raw1[1]<<endl;
	cout<<item_price[0]<<endl;
	cout<<raw1[3]<<endl;
	cout<<item_price[1]<<endl;
	cout<<raw1[5]<<endl;
	cout<<item_price[2]<<endl;
	cout<<raw1[7]<<endl;
	cout<<item_price[3]<<endl;
	cout<<item_name[0]<<endl;
	cout<<item_name[1]<<endl;
	cout<<item_name[2]<<endl;
	cout<<item_name[3]<<endl;
	
*/	
	set_size_request(400, 200);			
	set_title("Closet Welcome Screen");	
	
	add(box);
	
	label2.set_text("***************");	
	box.pack_start(label2);
	
	label1.set_text(name+"'s Closet!");	
	box.pack_start(label1);
	
	label3.set_text("***************");	
	box.pack_start(label3);
	
	label.set_text("Hello shopper! What item are you looking for?");	
	box.pack_start(label);	
	entry.set_max_length(4000);
	entry.set_text("e.g. shoes");	
	entry.select_region(0, entry.get_text_length());
	box.pack_start(entry);	
		
	
	button_send.signal_clicked().connect(sigc::mem_fun(*this,		
	&closet_window_3::send_value));		
	box.pack_start(button_send);	
	
	button_balance.signal_clicked().connect(sigc::mem_fun(*this,		
	&closet_window_3::balance_button));		
	box.pack_start(button_balance);
	
	button_close.signal_clicked().connect(	sigc::mem_fun(*this,
	&closet_window_3::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
	file.close();
}	
	
closet_window_3::~closet_window_3()
{

}	
	
void closet_window_3::send_value()	
{	
	string input=entry.get_text();
	balance = 0;
	
	for (int i=0; i<input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}
	
	int activate;
	for (i = 0; i<10 ; i++)
	{
		if(input == item_name[i])
		{
			ifstream file;
			string line;
			file.open("balance.txt");
	
			if(getline(file,line))
			{
				stringstream linestream(line);
				getline(linestream, baldata);
			}
			
			stringstream vs;
			vs << baldata;
			vs>>balance;
			balance = balance + item_price[i];
			ostringstream strs;
			strs << balance;
			string away;
			away = strs.str();
			
			ofstream written("balance.txt");
			
			if(written.is_open())
			{	
				written<<away<<endl;
				
			}
			
			ostringstream a;
			a << item_price[i];
			string pri;
			pri = a.str();

			Gtk::MessageDialog dialog (*this, "**TRANSACTION**",false,Gtk::MESSAGE_INFO);
			dialog.set_secondary_text("Thank you for buying a "+input+" at " +pri+" !");
			dialog.run();
			activate = 0;
			break;
		}
		
		
		activate =1;
	}	
	
	if (activate)
	{
		Gtk::MessageDialog dialog (*this, "**ALERT!!**",false,Gtk::MESSAGE_ERROR);
		dialog.set_secondary_text("SORRY! WE DON'T HAVE THAT");
		dialog.run();
	}	
}	
	
void closet_window_3::close_button()
{			
	
	ofstream ofs;
	ofs.open("person.txt", ofstream::out | ofstream::trunc);
	ofs.close();
	
	ofstream a;
	a.open("data.txt", ofstream::out | ofstream::trunc);
	a.close();
	
	ofstream b;
	b.open("balance.txt", ofstream::out | ofstream::trunc);
	b.close();
	
	exit(0);
}

void closet_window_3::balance_button()
{
	ifstream file1;
	string line1;
	file1.open("person.txt");
	
	int i = 0;
	while(getline(file1,line1))
	{
		stringstream linestream1(line1);
		getline(linestream1, raw[i]);
		++i;
	}
	name = raw[0];
	
	
	ifstream file;
	string line;
	file.open("balance.txt");
	
	if(getline(file,line))
	{
		stringstream linestream(line);
		getline(linestream, baldata);
	}
	
	Gtk::MessageDialog dialog (*this, "**BALANCE**",false,Gtk::MESSAGE_INFO);
	dialog.set_secondary_text("Hello "+name+" So far you have made $"+baldata);
	dialog.run();
}	