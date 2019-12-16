CXXFLAGS += -std=c++17
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

ex: closet_main.o closet.o
	$(CXX) $(CXXFLAGS) -o closet closet_main.o closet.o $(GTKFLAGS)
	
closet_main.o: closet_main.cpp closet.h
	$(CXX) $(CXXFLAGS) -c closet_main.cpp $(GTKFLAGS)
	
closet.o: closet.h closet.cpp
	$(CXX) $(CXXFLAGS) -c closet.cpp $(GTKFLAGS)
	
cleanup:
	echo "Cleaning up object files and executable!"
	rm *.o
	rm closet