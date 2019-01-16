#include "electriccargotruck.h"
#include <fstream>
electriccargo::electriccargo()
{
	electricplates = 0;
}

electriccargo::electriccargo(int ep, int mdl, int maxcap, int pwr, string pnumber, int s,string t):cargo(mdl,maxcap,pwr,pnumber,s,t)
{
	electricplates = ep;
}

void electriccargo::load_products(heavyproduct obj[])
{
	cargo::load_products(obj);
}

bool electriccargo::operator<(electriccargo & obj)
{
	return cargo::operator<(obj);
}

bool electriccargo::operator==(electriccargo & obj)
{
	return cargo::operator==(obj);
}

void electriccargo::operator[](heavyproduct & obj)
{
	cargo::operator[](obj);
}

void electriccargo::operator()(heavyproduct & obj)
{
	cargo::operator()(obj);
}

void electriccargo::writetofile()
{
	truck::writetofile();
	ofstream ofile("trucks.dat", ios::out | ios::app, ios::binary);
	ofile.write(reinterpret_cast<const char *>(&electricplates), sizeof(electricplates));
	
}

void electriccargo::readfromfile()
{
	truck::readfromfile();
	ifstream ifile("trucks.dat", ios::in | ios::app | ios::binary);
	ifile.read(reinterpret_cast < char *>(&electricplates), sizeof(electricplates));
}

void electriccargo::spawn_truck(board &obj)
{
	obj.setcurrentrow((rand() % 36) + 0);
	obj.setcurrentcol((rand() % 51) + 0);
	int electriccargosign = 94;
	obj.place_truck(obj.getcurrentrow(), obj.getcurrentcol(), electriccargosign);

	
}

//void electriccargo::move_truck(board &obj)
//{
//}

void electriccargo::remove_products(heavyproduct del)
{
	cargo::remove_products(del);
}
