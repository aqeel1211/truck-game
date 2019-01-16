#include "truck.h"
#include <iostream>
#include <fstream>
#include "board.h"
using namespace std;
truck::truck():maximumcapacity (100)
{
	model = 0;
	power = 0;
	platenumber = " ";
}

truck::truck(int mdl, int maxcap, int pwr, string pnumber) :maximumcapacity(100)
{
	model = mdl;
	power = pwr;
	platenumber = pnumber;
}

void truck::readfromfile()
{
	ifstream ifile("trucks.dat", ios::in | ios::binary);
	while (!ifile.eof()) {

		ifile.read(reinterpret_cast<char *>(&model), sizeof(model));
		ifile.read(reinterpret_cast<char *>(&power), sizeof(power));
		ifile.read(/*reinterpret_cast*/(char *)(&maximumcapacity), sizeof(maximumcapacity));
		ifile.read(reinterpret_cast<char *>(&platenumber), sizeof(platenumber));
		//obj2.display();

	}
}

//void truck::spawn_truck(board &obj)
//{
//	cout << "in truck ";
//}

void truck::writetofile()
{
	ofstream ofile("trucks.dat", ios::binary);
	ofile.write(reinterpret_cast<const char *>(&model), sizeof(model));
	ofile.write(reinterpret_cast<const char *>(&power), sizeof(power));
	ofile.write(reinterpret_cast<const char *>(&maximumcapacity), sizeof(maximumcapacity));
	ofile.write(reinterpret_cast<const char *>(&platenumber), sizeof(platenumber));
	//ifstream ifile("cargo.dat", ios::in | ios::binary);
}
