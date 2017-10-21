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

struct Node {
	CupPair parent;
	CupPair itself;
	Node(CupPair parent_, CupPair itself_) : parent(parent_), itself(itself_) {};
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
		if (node.one.getVolume() != target && node.two.getVolume() != target) {//if the cups don't have the target volume
			if (duplicate(node, checked) == 1) {//if the set of volumes has not been checked
				for (int i = 0; i < 6; i++) {//apply the six actions(fill, empty, pour) to the current cup pair
					CupPair node_copy = node;
					switch (i) {
						case 0://empty cup1
							node_copy.one.empty();
							break;
						case 1://empty cup2
							node_copy.two.empty();
							break;
						case 2://pour cup1 to cup2
							node_copy.one.pour(node_copy.two);
							break;
						case 3://pour cup2 to cup1
							node_copy.two.pour(node_copy.one);
							break;
						case 4://fill cup1
							node_copy.one.fill();
							break;
						case 5://fill cup2
							node_copy.two.fill();
							break;
					}
					if (duplicate(node_copy, checked) == 1) {//if this newly created node has not been checked
						//cout << node_copy.one.getVolume() << " and " << node_copy.two.getVolume() << endl;
						queue.push_back(node_copy);
					}
				}
				checked.push_back(node);//adds the volume to the checked list
			}
			else {//if the set of volumes has been checked
				
			}
		}
		else {//if at least one of the cups have the target volume
			cout << "The end is " << node.one.getVolume() << " and " << node.two.getVolume() << endl;
			break;
		}
		steps++;
	}
	cout << "The number of steps this process took was " << steps << "." << endl;
	cout << "Press any key to continue...";
	_getch();
	return 0;
}

int duplicate(CupPair a, vector<CupPair> list) {
	int k = 0;//variable used to determine if a set of volumes has been checked
	for (unsigned int i = 0; i < list.size(); i++) {//checks if the volume has been looked at already
		if (a.one.getVolume() == list.at(i).one.getVolume() && a.two.getVolume() == list.at(i).two.getVolume()) {
			k++;
			break;
		}
	}
	if (k == 0) return 1;//there are no duplicates
	else return 0;//there are duplciates
}