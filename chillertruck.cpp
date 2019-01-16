#include "chillertruck.h"
#include "coldproduct.h"

#include <iostream>
#include <fstream>
using namespace std;
chiller::chiller()
{
	size = 1;
	chillertemperature = 0;
	cparray = new coldproduct[size];
}

chiller::chiller(int ct, int s, int mdl, int maxcap, int pwr, string pnumber):truck(mdl, maxcap, pwr, pnumber)
{
	size = s;
	chillertemperature = ct;
	cparray = new coldproduct[size];
}

void chiller::copy_products(coldproduct obj[])
{
	for (int i = 0; i < size; i++) {
		cparray[i] = obj[i];
	}
}

void chiller::load_products(coldproduct obj[])
{
	/*cout << "enter number of products to be loaded " << endl;
	cin >> size;*/
	cparray = new coldproduct[size];

	for (int i = 0; i < getsize(); i++) {
		if (getsize() <= getmaximumcapacity() && obj[i].gettemperature() <= getchillertemperature()) {
			cparray[i] = obj[i];
		}
	}
}

void chiller::writetofile()
{
	truck::writetofile();
	ofstream ofile("trucks.dat", ios::out | ios::app, ios::binary);
	ofile.write(reinterpret_cast<const char *>(&chillertemperature), sizeof(chillertemperature));

}

void chiller::readfromfile()
{
	truck::readfromfile();
	ifstream ifile("trucks.dat", ios::in |ios::app| ios::binary);
	ifile.read(reinterpret_cast < char *>(&chillertemperature), sizeof(chillertemperature));
}

bool chiller::operator<(chiller & obj)
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i < size; i++) {
		sum += cparray[i].getweight();
	}
	for (int i = 0; i <obj.getsize(); i++) {
		sum1 += obj.cparray[i].getweight();
	}
	if (sum < sum1) {
		return true;
	}
	else {
		return false;
	}
}

bool chiller::operator==(chiller & obj)
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i < size; i++) {
		sum += cparray[i].getweight();
	}
	for (int i = 0; i <obj.getsize(); i++) {
		sum1 += obj.cparray[i].getweight();
	}
	if (sum == sum1) {
		cout << "equal weight " << endl;
		return true;
	}
	else {
		cout << "unequal weight " << endl;
		return false;
	}
}

void chiller::operator[](coldproduct &obj)
{
	for (int i = 0; i < size; i++) {
		if (cparray[i].getcategory() ==obj.getcategory()) {
			cout<<"*****product info ****"<<endl;
			cout << "brand " << obj.getbrand() << endl;
			cout << "category " << obj.getcategory() << endl;
			cout << "id " << obj.getid() << endl;
			cout << "price " << obj.getprice() << endl;
			cout << "temperature " << obj.gettemperature() << endl;
			cout << "weight " << obj.getweight() << endl;
		}
	}
}

void chiller::operator()(coldproduct & obj)
{
	for (int i = 0; i < size; i++) {
		if (cparray[i].getbrand() == obj.getbrand()) {
			cout << "*****product info ****" << endl;
			cout << "brand " << obj.getbrand() << endl;
			cout << "category " << obj.getcategory() << endl;
			cout << "id " << obj.getid() << endl;
			cout << "price " << obj.getprice() << endl;
			cout << "weight " << obj.getweight() << endl;
		}
	}
}

void chiller::remove_products(coldproduct del)
{
	bool check = false;;
	for (int i = 0; i<size; i++) {
		if (cparray[i].getid() == del.getid()) {
			for (int j = i; j<(size - 1); j++) {
				cout << "removing product" << endl;
				cparray[j] = cparray[j + 1];
			}
			check = true;
			setsize(size - 1);
			cout << "product removed " << endl;
			break;
		}
	}
	if (check == false) {
		cout << "Product not found! " << endl;
	}
}

void chiller::spawn_truck(board & obj)
{
	obj.setcurrentrow((rand() % 36) + 0);
	obj.setcurrentcol((rand() % 51) + 0); int chillersign = 35;
	obj.place_truck(obj.getcurrentrow(), obj.getcurrentcol(), chillersign);
}

//void chiller::move_truck(board &obj)
//{
//}
