#include "cargotruck.h"
#include <iostream>

using namespace std;
cargo::cargo()
{
	size = 1;
	hparray = new heavyproduct[size];
	type = "flatbed";
}

cargo::cargo(int mdl, int maxcap, int pwr, string pnumber, int s,string t):truck(mdl,maxcap,pwr,pnumber)
{
	size = s;
	hparray = new heavyproduct[size];
	type = t;
}

void cargo::copy_products(heavyproduct  obj[])
{
	for (int i = 0; i < size; i++) {
		hparray[i] = obj[i];
	}
}

void cargo::load_products(heavyproduct obj[])
{
	hparray = new heavyproduct[size];

	if (getsize() <= getmaximumcapacity()) {
		for (int i = 0; i < getsize(); i++) {
			hparray[i] = obj[i];
		}
	}
}

void cargo::writetofile()
{
	truck::writetofile();
}

void cargo::readfromfile()
{
	truck::readfromfile();
}

void cargo::display()
{
	cout << "model " << getmodel() << endl;
	cout << "max cap " << getmaximumcapacity() << endl;
	cout << "power " << getpower() << endl;
	cout << "number " << getplatenumber() << endl;
}

bool cargo::operator<(cargo & obj)
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i < size; i++) {
		sum+=hparray[i].getweight();
	}
	for (int i = 0; i <obj.getsize(); i++) {
		sum1 += obj.hparray[i].getweight();
	}
	if (sum < sum1) {
		return true;
	}
	else {
		return false;
	}
}

bool cargo::operator==(cargo & obj)
{
	int sum = 0;
	int sum1 = 0;
	for (int i = 0; i < size; i++) {
		sum += hparray[i].getweight();
	}
	for (int i = 0; i <obj.getsize(); i++) {
		sum1 += obj.hparray[i].getweight();
	}
	if (sum == sum1) {
		return true;
	}
	else {
		return false;
	}
}

void cargo::operator[](heavyproduct & obj)
{
	for (int i = 0; i < size; i++) {
		if (hparray[i].getcategory() == obj.getcategory()) {
			cout << "*****product info ****" << endl;
			cout << "brand " << obj.getbrand() << endl;
			cout << "category " << obj.getcategory() << endl;
			cout << "id " << obj.getid() << endl;
			cout << "price " << obj.getprice() << endl;
			cout << "weight " << obj.getweight() << endl;
		}
	}
	
}

void cargo::operator()(heavyproduct & obj)
{
	for (int i = 0; i < size; i++) {
		if (hparray[i].getbrand() == obj.getbrand()) {
			cout << "*****product info ****" << endl;
			cout << "brand " << obj.getbrand() << endl;
			cout << "category " << obj.getcategory() << endl;
			cout << "id " << obj.getid() << endl;
			cout << "price " << obj.getprice() << endl;
			cout << "weight " << obj.getweight() << endl;
		}
	}
}

void cargo::remove_products(heavyproduct del)
{
	bool check = false;;
	for (int i = 0; i<size; i++){
		if ( hparray[i].getid() == del.getid()) {
			for (int j = i; j<(size - 1); j++){
				cout << "removing product" << endl;
				hparray[j] = hparray[j + 1];
			}
			check=true;
			setsize(size - 1);
			cout << "product removed " << endl;
			break;
		}
	}
	if (check == false){
		cout << "Product not found! " << endl;
	}
}

void cargo::spawn_truck(board &obj)

{
	/*int row =*/ obj.setcurrentrow((rand() % 36) + 0);
	/*int col = */obj.setcurrentcol((rand() % 51) + 0);
	int cargosign = 64;
	obj.place_truck(obj.getcurrentrow(), obj.getcurrentcol(), 43);
}

//void cargo::move_truck(board &obj)
//{
//	
//}

