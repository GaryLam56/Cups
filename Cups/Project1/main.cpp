#include <iostream>
#include <vector>
#include "cup.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct Volumes {
	int one, two;
	Volumes(int one_, int two_) : one(one_), two(two_) {};
};

int duplicate(Volumes, vector<Volumes>);

int main() {
	int c1_size, c2_size, target, steps = 0;
	vector<Volumes> queue;
	vector<Volumes> checked;//keeps track of set of volumes that have been tested
	cout << "Enter a size for the first cup in mL: ";
	cin >> c1_size;
	cout << "Enter a size for the second cup in mL: ";
	cin >> c2_size;
	cout << "Enter a target amount of mL: ";
	cin >> target;
	cup c1(c1_size);
	cup c2(c2_size);
	Volumes volume(0, 0);
	queue.push_back(volume);
	while (queue.size() > 0) {
		volume = queue.front();//gets the next set of volumes from the queue
		queue.erase(queue.begin());//removes it from the queue
		if (volume.one != target || volume.two != target) {//if the cups don't have the target volume
			if (duplicate(volume, checked) == 1) {//if the set of volumes has not been checked
				for (int i = 0; i < 6; i++) {
					Volumes x = volume;
					switch (i) {
						case 0:
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
					}
				}
				checked.push_back(volume);//adds the volume to the checked list
			}
			else {//if the set of volumes has been checked
				
			}
		}
		else {//if at least one of the cups have the target volume
			break;
		}
	}
	cout << "The number of steps this process took was " << steps << "." << endl;
	cout << "Press any key to continue...";
	_getch();
	return 0;
}

int duplicate(Volumes v, vector<Volumes> list) {
	int k = 0;//variable used to determine if a set of volumes has been checked
	for (unsigned int i = 0; i < list.size(); i++) {//checks if the volume has been looked at already
		if (v.one == list.at(i).one && v.two == list.at(i).two) {
			k++;
			break;
		}
	}
	if (k == 0) return 1;//there are no duplicates
	else return 0;//there are duplciates
}