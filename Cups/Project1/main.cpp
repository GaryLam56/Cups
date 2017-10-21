#include <iostream>
#include <vector>
#include "cup.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct CupPair {
	cup one, two;
	CupPair(cup one_, cup two_) : one(one_), two(two_) {};
};

int duplicate(CupPair, vector<CupPair>);

int main() {
	int c1_size, c2_size, target, steps = 0;
	vector<CupPair> queue;
	vector<CupPair> checked;//keeps track of set of volumes that have been tested
	cout << "Enter a size for the first cup in mL: ";
	cin >> c1_size;
	cout << "Enter a size for the second cup in mL: ";
	cin >> c2_size;
	cout << "Enter a target amount of mL: ";
	cin >> target;
	cup c1(c1_size);
	cup c2(c2_size);
	CupPair root(c1, c2);
	queue.push_back(root);
	while (queue.size() > 0) {
		CupPair node = queue.front();//gets the next set of volumes from the queue
		queue.erase(queue.begin());//removes it from the queue
		if (node.one.current_volume != target || node.two.current_volume != target) {//if the cups don't have the target volume
			if (duplicate(node, checked) == 1) {//if the set of volumes has not been checked
				for (int i = 0; i < 6; i++) {
					switch (i) {
						case 0:
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
					}
				}
				checked.push_back(node);//adds the volume to the checked list
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

int duplicate(CupPair a, vector<CupPair> list) {
	int k = 0;//variable used to determine if a set of volumes has been checked
	for (unsigned int i = 0; i < list.size(); i++) {//checks if the volume has been looked at already
		if (a.one.current_volume == list.at(i).one.current_volume && a.two.current_volume == list.at(i).two.current_volume) {
			k++;
			break;
		}
	}
	if (k == 0) return 1;//there are no duplicates
	else return 0;//there are duplciates
}