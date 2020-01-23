#include "stdafx.h"

SC_MODULE(modul_sprzetowy)
{
	sc_in<sc_uint<8>> module_in;
	sc_out<sc_bv<7>> leds;

	void task5() {
		if (module_in.read() == 5)
		{
			cout << "Droga 1 pomaranczowe, czerwone" << endl;
			cout << "Droga 2 pomaranczowe" << endl;
			cout << "0 1 0 1 1 0" << endl;
			leds.write("1010110");
		}
	}

	SC_CTOR(modul_sprzetowy) {
		SC_METHOD(task5);
		sensitive << module_in;
	}
};