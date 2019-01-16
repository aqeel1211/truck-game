#include "coldproduct.h"
#include <iostream>
using namespace std;
coldproduct::coldproduct()
{
	temperature = 0;
	weight = 1;
}

coldproduct::coldproduct(int temp, int w, int id, int p, string cat, string bnd) :product(id, p, cat, bnd)
{
	temperature = temp;
	weight = w;
}

void coldproduct::take_productinfo()
{
	int temp,w;
	product::take_productinfo();
	cout << "enter temperature " << endl;
	cin >> temp;
	cout << "enter weight " << endl;
	cin >> w;
	settemperature(temp);
	setweight(w);
}
