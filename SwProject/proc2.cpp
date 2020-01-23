#include "stdafx.h"

SC_MODULE(proc2)
{
	sc_inout<sc_uint<8>> sw;
	sc_inout<sc_bv<7>> leds;
	
	void task3()
	{
		
		if (sw.read() == 3)
		{

			cout << "Droga 1 czerwone" << endl;
			cout << "Droga 2 zielone" << endl;
			cout << "0 0 1 1 0 0" << endl;
			leds.write("0001100");
		}
		
		
		//dorota.dariusz@gmail.com
	}

	SC_CTOR(proc2)
	{
		SC_METHOD(task3);
		sensitive << sw;
	}
};