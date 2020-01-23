#include "stdafx.h"
#include "modul_sprzetowy.cpp"
using namespace std;

SC_MODULE(proc1)
{
	sc_inout<sc_uint<8>> sw;
	sc_mutex mutex;
	sc_inout<sc_bv<7>> leds;
	//sc_in<sc_uint<2>> start;
	modul_sprzetowy modul;
	sc_signal<sc_uint<8>> module_out;
	sc_signal<sc_bv<7>> modul_leds_out;
	sc_uint<8> bufor;
	sc_uint<8> state;
	sc_uint<8> old_state;

	

	
	
	void write_sw()
	{

		while (1)
		{
			mutex.lock();
			old_state = sw.read();
			cout << "Podaj wartosc sw" << endl;
			cin >> bufor;
			system("CLS");
			if(bufor!=7)
			{
				sw.write(bufor);
			}
			
			
			mutex.unlock();
			wait(100, SC_NS);
			//wait();
			
		}	
		
	}
	
	void printMenu()
	{
		
		cout << endl;
		cout << endl;
		cout << "Sygnalizacja swietlna" << endl;
		cout << "1.droga 1 zielone\n2.droga 1 pomaranczowe\n3.droga 1 czerwone --- drugi procesor\n4.droga 2 zielone" << endl;
		cout << "5.droga 2 pomaranczowe --- modul sprzetowy\n6.droga 2 czerwone\n0.swiatla wylaczone\n7. wyjdz" << endl;
		cout << endl << endl;
	}

	void task1()
	{
		if (mutex.trylock() != -1)
		{
			if (sw.read() == 1)
			{

				cout << "Droga 1 zielone" << endl;
				cout << "Droga 2 czerwone" << endl;
				cout << "1 0 0 0 0 1" << endl;
				leds.write("0100001");

			}
			mutex.unlock();
		}
	}

	void task2()
	{
		if (mutex.trylock() != -1)
		{
			if (sw.read() == 2)
			{

				cout << "Droga 1 pomaranczowe" << endl;
				cout << "Droga 2 pomaranczowe, czerwone" << endl;
				cout << "1 1 0 0 1 0" << endl;
				leds.write("0110010");
			}
			mutex.unlock();
		}
	}

	void task4()
	{
		if (mutex.trylock() != -1)
		{
			if (sw.read() == 4)
			{

				cout << "Droga 1 czerwone" << endl;
				cout << "Droga 2 zielone" << endl;
				cout << "0 0 1 1 0 0" << endl;
				leds.write("1001100");
			}
			mutex.unlock();
		}
	}

	void task5() 
	{
		if (mutex.trylock() != -1)
		{
			if (sw.read() == 5)
			{
				
				module_out = 5;
				
			}
			else
			{
				module_out = 0;
			}
			mutex.unlock();
		}
		
	}

	void task6()
	{
		if (mutex.trylock() != -1)
		{
			if (sw.read() == 6)
			{
				cout << "Droga 1 zielone" << endl;
				cout << "Droga 2 czerwone" << endl;
				cout << "1 0 0 0 0 1" << endl;
				leds.write("1100001");
			}
			mutex.unlock();
		}
	}

	void task7()
	{
		if (mutex.trylock() != -1)
		{

			if (sw.read() == 0)
			{

				cout << "Droga 1 pomaranczowe" << endl;
				cout << "Droga 2 pomaranczowe" << endl;
				cout << "0 0 0 0 0 0" << endl;
				leds.write("0000000");
			}
			mutex.unlock();
		}
	}

	void task8()
	{
		if (mutex.trylock() != -1)
		{
			if ((sw.read() > 6) || (sw.read() < 0))
			{

				cout << "ERROR" << endl;
				cout << "ERROR" << endl;
				cout << "1 1 1 1 1 1" << endl;
				leds.write("1111111");
			}
			mutex.unlock();
		}
	}

	

	SC_CTOR(proc1) : modul("modul_sprzetowy")
	{
		modul.module_in(module_out);
		modul.leds(modul_leds_out);
		SC_THREAD(write_sw);
		sensitive << leds;
		sensitive << modul_leds_out;
		SC_METHOD(task1);
		sensitive << sw;
		SC_METHOD(task2);
		sensitive << sw;
		SC_METHOD(task4);
		sensitive << sw;
		SC_METHOD(task5);
		sensitive << sw;
		SC_METHOD(task6);
		sensitive << sw;
		SC_METHOD(task7);
		sensitive << sw;
		SC_METHOD(task8);
		sensitive << sw;
		system("CLS");
		printMenu();
	}
};