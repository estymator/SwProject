// SwProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "proc1.cpp"
#include "proc2.cpp"
using namespace std;

//sd
int sc_main(int argc, char* argv[])
{
	cout << "Strssrt" << endl;
	sc_signal<sc_uint<8>, SC_MANY_WRITERS> switches;
	//sc_signal<sc_uint<8>, SC_MANY_WRITERS> modulSprzetowy;
	sc_signal<sc_bv<7>, SC_MANY_WRITERS> leds;
	



	
	
	proc1 p1("p1");
	p1.sw(switches);
	p1.leds(leds);
	


	proc2 p2("p2");
	p2.sw(switches);
	p2.leds(leds);
	sc_start();
	
	//keep terminal alive
	cout << "keep terminal alive" << endl;
	int a;
	cin >> a;
    return 0;
}

