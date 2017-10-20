#include <iostream>
#include <vector>
#include "cup.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int c1_size;
	int c2_size;
	std::vector<int> queue;
	cout << "Enter a size for the first cup in mL: ";
	cin >> c1_size;
	cout << "Enter a size for the second cup in mL: ";
	cin >> c2_size;
	cup c1(c1_size);
	cup c2(c2_size);
	cout << "The capcity of cup1 is " << c1.getCapacity() << "." << endl;
	cout << "The capcity of cup2 is " << c2.getCapacity() << "." << endl;
	cout << "The current volume of cup1 is " << c1.getVolume() << "." << endl;
	cout << "The current volume of cup2 is " << c2.getVolume() << "." << endl;
	c1.fill();
	cout << "The current volume of cup1 is " << c1.getVolume() << "." << endl;
	c1.pour(c2);
	cout << "The current volume of cup2 is " << c2.getVolume() << "." << endl;
	cout << "The current volume of cup1 is " << c1.getVolume() << "." << endl;
	cout << "Press any key to continue...";
	_getch();
	return 0;
}