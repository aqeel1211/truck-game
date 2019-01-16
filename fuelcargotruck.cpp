#include "fuelcargotruck.h"
#include <fstream>
fuelcargo::fuelcargo()
{
	fuel = 0;
}

fuelcargo::fuelcargo(int f, int mdl, int maxcap, int pwr, string pnumber, int s,string t):cargo(mdl,maxcap, pwr,pnumber,s,t)
{
	fuel = f;
}

void fuelcargo::load_products(heavyproduct obj[])
{
	cargo::load_products(obj);
}

bool fuelcargo::operator<(fuelcargo & obj)
{
	return cargo::operator<(obj);
}

bool fuelcargo::operator==(fuelcargo & obj)
{
	return cargo::operator==(obj);
}

void fuelcargo::operator[](heavyproduct & obj)
{
	cargo::operator[](obj);
}

void fuelcargo::operator()(heavyproduct & obj)
{
	cargo::operator()(obj);
}

void fuelcargo::remove_products(heavyproduct del)
{
	cargo::remove_products(del);
}

void fuelcargo::writetofile()
{
	truck::writetofile();
	ofstream ofile("trucks.dat", ios::out | ios::app, ios::binary);
	ofile.write(reinterpret_cast<const char *>(&fuel), sizeof(fuel));
}

void fuelcargo::readfromfile()
{
	truck::readfromfile();
	ifstream ifile("trucks.dat", ios::in | ios::app | ios::binary);
	ifile.read(reinterpret_cast < char *>(&fuel), sizeof(fuel));
}

void fuelcargo::spawn_truck(board &obj)
{
	obj.setcurrentrow((rand() % 36) + 0);
	obj.setcurrentcol((rand() % 51) + 0); 
	int fuelcargosign = 64;
	obj.place_truck(obj.getcurrentrow(), obj.getcurrentcol(), fuelcargosign);
}

//void fuelcargo::move_truck(board &obj)
//{
//}
