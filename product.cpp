#include "product.h"
#include <iostream>
using namespace std;
product::product()
{
	id = 0;
	price = 0;
	category = " ";
	brand = " ";
	
}

product::product(int id, int p, string cat, string bnd)
{
	this->id = id;
	price = p;
	category = cat;
	brand = bnd;
	
}

void product::take_productinfo()
{
	int weight, id, price, temp;
	string brand, cat;
	cout << "enter brand " << endl;
	cin >> brand;
	cout << "enter category " << endl;
	cin >> cat;
	cout << "enter id " << endl;
	cin >> id;
	cout << "enter price " << endl;
	cin >> price;
	setbrand(brand);
	setcategory(cat);
	setid(id);
	setprice(price);
}

