
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "product.h"
#include "truck.h"
#include "cargotruck.h"
#include"heavyproduct.h"
#include "coldproduct.h"
#include "chillertruck.h"
#include "electriccargotruck.h"
#include"fuelcargotruck.h"
#include "board.h"
using namespace std;

void menu() {
	cout << "1.Create & Load Truck " << endl;
	cout << "2.Display Truck " << endl;
	cout << "3.Check if Truck is empty " << endl;
	cout << "4.Remove products from Truck " << endl;
	cout << "5.display products that belong to same category " << endl;
	cout << "6.display products that belong to same brand " << endl;
	cout << "7.Check if trucks are equal in terms of eight " << endl;
	cout << "8.copy products " << endl;
	cout << "9.start game " << endl;
	cout << "10.exit menu " << endl;
}
ostream & operator<<(ostream & output, heavyproduct & obj) {
	output << endl;
	output << "heavy product info " << endl;
	output << "brand " << obj.getbrand() << endl;
	output << "category " << obj.getcategory() << endl;
	output << "price " << obj.getprice() << endl;
	output << "id " << obj.getid() << endl;
	output << "weight " << obj.getweight() << endl;
	output << endl;
	return output;
}

ostream & operator<<(ostream & output, cargo & obj) {
	heavyproduct *p = obj.gethparray();
	output << "*****Cargo info*****" << endl;
	output << "plate number: " << obj.getplatenumber() << endl;
	output << "model : " << obj.getmodel() << endl;
	output << "max capacity " << obj.getmaximumcapacity() << endl;
	output << "power " << obj.getpower() << endl;
	output << "type : " << obj.gettype() << endl;
	for (int i = 0; i < obj.getsize(); i++) {
		output << p[i] << " ";
	}
	output << endl;
	return output;
}

ostream & operator<<(ostream & output, coldproduct & obj) {
	output << "cold product info " << endl;
	output << "brand " << obj.getbrand() << endl;
	output << "category " << obj.getcategory() << endl;
	output << "price " << obj.getprice() << endl;
	output << "id " << obj.getid() << endl;
	output << "weight " << obj.getweight() << endl;
	output << "temperature " << obj.gettemperature() << endl;
	output << endl;
	return output;
}

ostream & operator<<(ostream & output, chiller & obj) {
	coldproduct *p = obj.getcparray();
	output << "*****chiller info*****" << endl;
	output << "plate number: " << obj.getplatenumber() << endl;
	output << "model : " << obj.getmodel() << endl;
	output << "max capacity " << obj.getmaximumcapacity() << endl;
	output << "power " << obj.getpower() << endl;
	output << endl;
	for (int i = 0; i < obj.getsize(); i++) {
		output << p[i] << " ";
	}
	output << endl;
	return output;
}
ostream & operator<<(ostream & output, electriccargo & obj) {
	heavyproduct *p = obj.gethparray();
	output << "*****electric cargo info*****" << endl;
	output << "plate number: " << obj.getplatenumber() << endl;
	output << "model : " << obj.getmodel() << endl;
	output << "max capacity " << obj.getmaximumcapacity() << endl;
	output << "power " << obj.getpower() << endl;
	output << "type : " << obj.gettype() << endl;
	output << endl;
	for (int i = 0; i < obj.getsize(); i++) {
		output << p[i] << " ";
	}
	output << endl;
	return output;
}
ostream & operator<<(ostream & output, fuelcargo & obj) {
	heavyproduct *p = obj.gethparray();
	output << "*****fuel cargo info*****" << endl;
	output << "plate number: " << obj.getplatenumber() << endl;
	output << "model : " << obj.getmodel() << endl;
	output << "max capacity " << obj.getmaximumcapacity() << endl;
	output << "power " << obj.getpower() << endl;
	output << "type : " << obj.gettype() << endl;
	output << endl;
	for (int i = 0; i < obj.getsize(); i++) {
		output << p[i] << " ";
	}
	output << endl;
	return output;
}

int main() {
	cargo user1;
	chiller user2;
	electriccargo user3;
	fuelcargo user4;
	heavyproduct *obj1 = new heavyproduct[10];
	cargo obj2(2011, 100, 5000, "abc-121", 2, "jumbo");
	obj2.writetofile();
	coldproduct *obj3 = new coldproduct[10];
	chiller obj4(100, 2, 2011, 100, 5000, "abc-121");
	obj4.writetofile();
	heavyproduct u(5, 999, 35, "water", "nestle");
	coldproduct w(100, 5, 999, 35, "water", "nestle");
	electriccargo obj5;
	obj5.writetofile();
	fuelcargo obj6;
	obj6.writetofile();
	board mainboard;
	cargo cargo1;
	cargo1.load_products(obj1);
	chiller chiller1;
	chiller1.load_products(obj3);

	/*electriccargo ec,ee;
	obj1 = ee.gethparray();
	obj1->setweight(5);
	ec.load_products(obj1);
	cout << ec << endl;
	if (ee == ec) {
		cout << "equal " << endl;
	}*/
	int choice;
	int emptycheck = 0;
	int emptycheck1 = 0;
	int emptycheck2 = 0;
	int emptycheck3 = 0;
	int user1emptycheck = 0;
	int user2emptycheck = 0;
	int user3emptycheck = 0;
	int user4emptycheck = 0;
	menu();
	cout << "enter choice " << endl;
	cin >> choice;
	while (choice != 10)
	{
		if (choice == 1) {
			system("cls");
			cout << "1.Create and load cargo " << endl;
			cout << "2.create and load chiller " << endl;
			cout << "3.create and load electric cargo " << endl;
			cout << "4.create and load fuel cargo " << endl;
			cout << "5.create and load user truck " << endl;

			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				int size, mdl, pr;
				string pn;
				cout << "enter model " << endl;
				cin >> mdl;
				cout << "enter plate number " << endl;
				cin >> pn;
				cout << "enter power" << endl;
				cin >> pr;
				obj2.setmodel(mdl);
				obj2.setplatenumber(pn);
				obj2.setpower(pr);
				cout << "enter number of products to load in cargo " << endl;
				cin >> size;
				obj2.setsize(size);

				obj2.writetofile();
				for (int i = 0; i < size; i++) {
					obj1[i].take_productinfo();
				}
				obj2.load_products(obj1);

				emptycheck++;
				//cout << obj2 << endl;
			}
			else if (choice == 2) {
				int size2;
				int temp, mdl, pr;
				string pn;
				cout << "enter model " << endl;
				cin >> mdl;
				cout << "enter plate number " << endl;
				cin >> pn;
				cout << "enter power" << endl;
				cin >> pr;
				cout << "enter chiller temperature " << endl;
				cin >> temp;
				obj4.setchillertemperature(temp);
				obj4.setmodel(mdl);
				obj4.setplatenumber(pn);
				obj4.setpower(pr);
				cout << "enter number of products to load in chiller " << endl;
				cin >> size2;
				obj4.setsize(size2);
				obj4.writetofile();

				/*coldproduct *obj3 = new coldproduct[10];
				chiller obj4(1, 2, 3, 4, 5, "na");*/
				for (int i = 0; i < size2; i++) {
					obj3[i].take_productinfo();
				}
				obj4.load_products(obj3);
				emptycheck1++;
			}
			else if (choice == 3) {
				int size2;
				int temp, mdl, pr, ep;
				string pn;
				cout << "enter model " << endl;
				cin >> mdl;
				cout << "enter plate number " << endl;
				cin >> pn;
				cout << "enter power" << endl;
				cin >> pr;
				cout << "enter number of electric plates " << endl;
				cin >> ep;
				obj5.setelectricplates(ep);
				obj5.setmodel(mdl);
				obj5.setplatenumber(pn);
				obj5.setpower(pr);
				cout << "enter number of products to load in elecetric cargo " << endl;
				cin >> size2;
				obj5.setsize(size2);
				obj5.writetofile();
				for (int i = 0; i < size2; i++) {
					obj1[i].take_productinfo();
				}
				obj5.load_products(obj1);
				emptycheck2++;
			}
			else if (choice == 4) {
				int size2;
				int temp, mdl, pr, fuel;
				string pn;
				cout << "enter model " << endl;
				cin >> mdl;
				cout << "enter plate number " << endl;
				cin >> pn;
				cout << "enter power" << endl;
				cin >> pr;
				cout << "enter fuel amount " << endl;
				cin >> fuel;
				obj6.setfuel(fuel);
				obj6.setmodel(mdl);
				obj6.setplatenumber(pn);
				obj6.setpower(pr);
				cout << "enter number of products to load in elecetric cargo " << endl;
				cin >> size2;
				obj6.setsize(size2);
				/*coldproduct *obj3 = new coldproduct[10];
				chiller obj4(1, 2, 3, 4, 5, "na");*/
				for (int i = 0; i < size2; i++) {
					obj1[i].take_productinfo();
				}
				obj6.load_products(obj1);
				emptycheck3++;
			}
			else if (choice == 5) {
				system("cls");

				cout << "1.Cargo " << endl;
				cout << "2.Chiller " << endl;
				cout << "3.Electric Cargo" << endl;
				cout << "4.Fuel Cargo" << endl;
				cout << "enter choice " << endl;
				cin >> choice;
				if (choice == 1) {
					int size, mdl, pr;
					string pn;
					cout << "enter model " << endl;
					cin >> mdl;
					cout << "enter plate number " << endl;
					cin >> pn;
					cout << "enter power" << endl;
					cin >> pr;
					user1.setmodel(mdl);
					user1.setplatenumber(pn);
					user1.setpower(pr);
					cout << "enter number of products to load in cargo " << endl;
					cin >> size;
					user1.setsize(size);
					user1.writetofile();

					for (int i = 0; i < size; i++) {
						obj1[i].take_productinfo();
					}
					user1.load_products(obj1);
					user1emptycheck++;

				}
				else if (choice == 2) {
					int size, mdl, pr, temp;
					string pn;
					cout << "enter model " << endl;
					cin >> mdl;
					cout << "enter plate number " << endl;
					cin >> pn;
					cout << "enter power" << endl;
					cin >> pr;
					cout << "enter temperature " << endl;
					cin >> temp;
					user2.setchillertemperature(temp);
					user2.setmodel(mdl);
					user2.setplatenumber(pn);
					user2.setpower(pr);
					cout << "enter number of products to load in cargo " << endl;
					cin >> size;
					user2.setsize(size);
					user2.writetofile();

					for (int i = 0; i < size; i++) {
						obj3[i].take_productinfo();
					}
					user2.load_products(obj3);
					user2emptycheck++;
				}
				else if (choice == 3) {
					int size2;
					int temp, mdl, pr, ep;
					string pn;
					cout << "enter model " << endl;
					cin >> mdl;
					cout << "enter plate number " << endl;
					cin >> pn;
					cout << "enter power" << endl;
					cin >> pr;
					cout << "enter number of electric plates " << endl;
					cin >> ep;
					user3.setelectricplates(ep);
					user3.setmodel(mdl);
					user3.setplatenumber(pn);
					user3.setpower(pr);
					cout << "enter number of products to load in electric cargo " << endl;
					cin >> size2;
					user3.setsize(size2);
					user3.writetofile();
					for (int i = 0; i < size2; i++) {
						obj1[i].take_productinfo();
					}
					user3.load_products(obj1);
					user3emptycheck++;
				}
				else if (choice == 4) {
					int size2;
					int temp, mdl, pr, fuel;
					string pn;
					cout << "enter model " << endl;
					cin >> mdl;
					cout << "enter plate number " << endl;
					cin >> pn;
					cout << "enter power" << endl;
					cin >> pr;
					cout << "enter fuel amount " << endl;
					cin >> fuel;
					user4.setfuel(fuel);
					user4.setmodel(mdl);
					user4.setplatenumber(pn);
					user4.setpower(pr);
					cout << "enter number of products to load in elecetric cargo " << endl;
					cin >> size2;
					user4.setsize(size2);
					/*coldproduct *obj3 = new coldproduct[10];
					chiller obj4(1, 2, 3, 4, 5, "na");*/
					for (int i = 0; i < size2; i++) {
						obj1[i].take_productinfo();
					}
					user4.load_products(obj1);
					user4emptycheck++;
				}
			}
		}
		else if (choice == 2) {
			system("cls");
			cout << "1.display cargo " << endl;
			cout << "2.dislpay chiller " << endl;
			cout << "3.display electric cargo " << endl;
			cout << "4.display fuel cargo " << endl;
			cout << "5.display user truck " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				cout << obj2 << endl;
			}
			else if (choice == 2) {
				cout << obj4 << endl;
			}
			else if (choice == 3) {
				cout << obj5 << endl;
			}
			else if (choice == 4) {
				cout << obj6 << endl;
			}
			else if (choice == 5) {
				system("cls");
				cout << "1.display user's cargo " << endl;
				cout << "2.dislpay user's chiller " << endl;
				cout << "3.display user's electric cargo " << endl;
				cout << "4.display user's fuel cargo " << endl;
				cout << "enter choice " << endl;
				cin >> choice;
				if (choice == 1) {
					cout << user1 << endl;
				}
				else if (choice == 2) {
					cout << user2 << endl;
				}
				else if (choice == 3) {
					cout << user3 << endl;
				}
				else if (choice == 4) {
					cout << user4 << endl;
				}
			}
		}

		else if (choice == 3) {
			system("cls");
			cout << "1.Check if cargo is empty " << endl;
			cout << "2.check if chiller is empty " << endl;
			cout << "3.check if electric cargo is empty " << endl;
			cout << "4.check if fuel cargo is empty " << endl;
			cout << "5.check if user's truck is empty " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				if (emptycheck > 0) {
					cout << "cargo is not empty " << endl;
				}
				else {
					cout << "cargo is empty " << endl;
				}
			}
			else if (choice == 2) {
				if (emptycheck1 > 0) {
					cout << "chiller is not empty " << endl;
				}
				else {
					cout << "chiller is empty " << endl;
				}
			}
			else if (choice == 3) {
				if (emptycheck2 > 0) {
					cout << "electric cargo is not empty " << endl;
				}
				else {
					cout << "electric cargo is empty " << endl;
				}
			}
			else if (choice == 4) {
				if (emptycheck3 > 0) {
					cout << "fuel cargo is not empty " << endl;
				}
				else {
					cout << "fuel cargo is empty " << endl;
				}
			}
			else if (choice == 5) {
				system("cls");
				cout << "1.Check if user's cargo is empty " << endl;
				cout << "2.check if user's chiller is empty " << endl;
				cout << "3.check if user's electric cargo is empty " << endl;
				cout << "4.check if user's fuel cargo is empty " << endl;
				cout << "enter choice " << endl;
				cin >> choice;
				if (choice == 1) {
					if (user1emptycheck > 0) {
						cout << "cargo is not empty " << endl;
					}
					else {
						cout << "cargo is empty " << endl;
					}
				}
				else if (choice == 2) {
					if (user2emptycheck > 0) {
						cout << "chiller is not empty " << endl;
					}
					else {
						cout << "chiller is empty " << endl;
					}
				}
				else if (choice == 3) {
					if (user3emptycheck > 0) {
						cout << "electric cargo is not empty " << endl;
					}
					else {
						cout << "electric cargo is empty " << endl;
					}
				}
				else if (choice == 4) {
					if (user4emptycheck > 0) {
						cout << "fuel cargo is not empty " << endl;
					}
					else {
						cout << "fuel cargo is empty " << endl;
					}
				}
			}
		}

		else if (choice == 4) {
			system("cls");

			cout << "1.Remove product from Cargo " << endl;
			cout << "2.Remove product from Chiller " << endl;
			cout << "3.Remove product from electric cargo " << endl;
			cout << "4.Remove product from fuel cargo " << endl;
			cout << "5.Remove product from user truck " << endl;
			cin >> choice;
			if (choice == 1) {
				int id;
				cout << "enter id of product to be removed " << endl;
				cin >> id;
				u.setid(id);
				obj2.remove_products(u);
			}
			else if (choice == 2) {
				int id;
				cout << "enter id of product to be removed " << endl;
				cin >> id;
				w.setid(id);
				obj4.remove_products(w);
			}

			else if (choice == 3) {
				int id;
				cout << "enter id of product to be removed " << endl;
				cin >> id;
				u.setid(id);
				obj5.remove_products(u);
			}

			else if (choice == 4) {
				int id;
				cout << "enter id of product to be removed " << endl;
				cin >> id;
				u.setid(id);
				obj6.remove_products(u);
			}
			else if (choice == 5) {
				system("cls");
				cout << "1.Remove product from user's Cargo " << endl;
				cout << "2.Remove product from user's Chiller " << endl;
				cout << "3.Remove product from user's electric cargo " << endl;
				cout << "4.Remove product from user's fuel cargo " << endl;
				cout << "enter choice " << endl;
				cin >> choice;
				if (choice == 1) {
					int id;
					cout << "enter id of product to be removed " << endl;
					cin >> id;
					u.setid(id);
					user1.remove_products(u);
				}
				else if (choice == 2) {
					int id;
					cout << "enter id of product to be removed " << endl;
					cin >> id;
					w.setid(id);
					user2.remove_products(w);
				}

				else if (choice == 3) {
					int id;
					cout << "enter id of product to be removed " << endl;
					cin >> id;
					u.setid(id);
					user3.remove_products(u);
				}
				else if (choice == 4) {
					int id;
					cout << "enter id of product to be removed " << endl;
					cin >> id;
					u.setid(id);
					user4.remove_products(u);
				}
			}
		}

		else if (choice == 5) {
			system("cls");
			cout << "1.display heavy products of cargo that belong to same category " << endl;
			cout << "2.display cold products of chiller that belong to same category " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				string cat;
				cout << "enter category " << endl;
				cin >> cat;
				u.setcategory(cat);
				obj2[u];
			}
			else if (choice == 2) {
				string cat;
				cout << "enter category " << endl;
				cin >> cat;
				w.setcategory(cat);
				obj4[w];
			}
		}
		else if (choice == 6) {
			system("cls");
			cout << "1.display products of cargo that belong to same brand " << endl;
			cout << "2.display products of chiller that belong to same brand " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				string bnd;
				cout << "enter brand " << endl;
				cin >> bnd;
				u.setbrand(bnd);
				obj2(u);
			}
			else if (choice == 2) {
				string bnd;
				cout << "enter brand " << endl;
				cin >> bnd;
				w.setcategory(bnd);
				obj4(w);
			}
		}
		else if (choice == 7) {
			system("cls");
			cout << "1.check if two cargos are equal in weight " << endl;
			cout << "2.check if two chillers are equal in weight " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			cout << "!!!" << endl;

			if (choice == 1) {
				obj2 == cargo1;
			}
			else if (choice == 2) {
				obj4 == chiller1;
			}
		}
		else if (choice == 8) {
			system("cls");
			cout << "1.copy heavy products " << endl;
			cout << "2.copy cold products " << endl;
			cout << "enter choice " << endl;
			cin >> choice;
			if (choice == 1) {
				obj2.copy_products(obj1);
			}
			else if (choice == 2) {
				obj4.copy_products(obj3);
			}
		}
		else if (choice == 9) {
			board obj;
			mainboard.spawn_alltrucks(mainboard);
			mainboard.display_board();
		}
		cout << endl;
		menu();
		cout << endl;
		cout << "enter choice " << endl;
		cin >> choice;
	}
	delete[] obj1;
	delete[] obj3;
	system("pause");
	return 0;
}