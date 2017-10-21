#include <iostream>
#include <vector>
#include "cup.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct CupPair {//holds two volume values
	cup one, two;
	CupPair(cup one_, cup two_) : one(one_), two(two_) {};
};

struct Node {
	Node *parent;
	CupPair itself;
	Node(Node *parent_, CupPair itself_) : parent(parent_), itself(itself_) {};
};

int duplicate(CupPair, vector<Node>);

int main() {
	int c1_size, c2_size, target, steps = 0;
	vector<Node> queue;
	vector<Node> checked;//keeps track of set of volumes that have been tested
	cout << "Enter a size for the first cup in mL: ";
	cin >> c1_size;
	cout << "Enter a size for the second cup in mL: ";
	cin >> c2_size;
	cout << "Enter a target amount of mL: ";
	cin >> target;
	cup c1(c1_size);
	cup c2(c2_size);
	CupPair RootCupPair(c1, c2);
	Node root(nullptr, RootCupPair);
	queue.push_back(root);
	while (queue.size() > 0) {
		Node current_node = queue.front();//gets the next set of volumes from the queue
		if (current_node.itself.one.getVolume() != target && current_node.itself.two.getVolume() != target) {//if the cups don't have the target volume
			if (duplicate(current_node.itself, checked) == 1) {//if the set of volumes has not been checked
				for (int i = 0; i < 6; i++) {//apply the six actions(fill, empty, pour) to the current cup pair
					Node node_copy(&current_node, current_node.itself);
					//the current_node is a reference so that when current node is changed the parent node is also changed
					//everytime current_node changes the parent node changes
					switch (i) {
						case 0://empty cup1
							node_copy.itself.one.empty();
							break;
						case 1://empty cup2
							node_copy.itself.two.empty();
							break;
						case 2://pour cup1 to cup2
							node_copy.itself.one.pour(node_copy.itself.two);
							break;
						case 3://pour cup2 to cup1
							node_copy.itself.two.pour(node_copy.itself.one);
							break;
						case 4://fill cup1
							node_copy.itself.one.fill();
							break;
						case 5://fill cup2
							node_copy.itself.two.fill();
							break;
					}
					if (duplicate(current_node.itself, checked) == 1) {//if this newly created node has not been checked
						queue.push_back(node_copy);
					}
				}
				checked.push_back(current_node);//adds the volume to the checked list
			}
			else {//if the set of volumes has been checked
				
			}
		}
		else {//if at least one of the cups have the target volume
			cout << "The end is " << current_node.itself.one.getVolume() << " and " << current_node.itself.two.getVolume() << endl;
			break;
		}
		queue.erase(queue.begin());//removes it from the queue
	}
	Node last = queue.front();
	//TEST
	cout << last.itself.one.getVolume() << " and " << last.itself.two.getVolume() << endl;
	cout << (*last.parent).itself.one.getVolume() << " and " << (*last.parent).itself.two.getVolume() << endl;
	for (unsigned int i = 0; i < checked.size(); i++) {
		cout << "start" << endl;
		if (checked.at(i).parent != nullptr) {
			cout << "The parent is " << (*checked.at(i).parent).itself.one.getVolume() << " and " << (*checked.at(i).parent).itself.two.getVolume() << endl;
		}
		cout << "The child is "<< checked.at(i).itself.one.getVolume() << " and " << checked.at(i).itself.two.getVolume() << endl;
		cout << "end" << endl;
	}
	//TEST
	//while (last.parent != NULL) {
	//	last = *last.parent;
	//	cout << last.itself.one.getVolume() << " and " << last.itself.two.getVolume() << endl;
	//	steps++;
	//}
	cout << "The number of steps this process took was " << steps << "." << endl;
	cout << "Press any key to continue...";
	_getch();
	return 0;
}

int duplicate(CupPair a, vector<Node> list) {
	int k = 0;//variable used to determine if a set of volumes has been checked
	for (unsigned int i = 0; i < list.size(); i++) {//checks if the volume has been looked at already
		if (a.one.getVolume() == list.at(i).itself.one.getVolume() && a.two.getVolume() == list.at(i).itself.two.getVolume()) {
			k++;
			break;
		}
	}
	if (k == 0) return 1;//there are no duplicates
	else return 0;//there are duplciates
}