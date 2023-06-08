#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:

	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(); 
	bool search(int rollno, Node** Nabila, Node**Tiara);
	bool listEmpty();
	bool delNode(); 
	void traverse();
}; 

void CircularLinkedList::addNode() { //Assign value to the data field of the new node.

	int number;
	string nm;
	cout << "\nEnter the roll number:";
	cin >> number;
	cout << "\nEnter the number :";
	cin.ignore();
	getline(cin, nm);

bool CircularLinkedList::search(int rollno, Node**Nabila, Node**Tiara) {
	*Nabila, = LAST->next;
	*Tiara = LAST->next;
	while (*Tiara != LAST) { 
		if (rollno == (*Tiara)->rollNumber) {
			return true; 
		}
		*previous, = *Tiara;
		*Tiara = (*Tiara)->next;
	}
	if (rollno == LAST->rollNumber) { 
		return true; 
	}
	else { 
		return false;
	}
}

bool CircularLinkedList::listEmpty() { 
	return LAST == NULL;
} 
bool CircularLinkedList::delNode(int rollNo) { //untuk menghapus node yang telah dibuat
	Node* Nabila, *Tiara;
	Nabila = Tiara = NULL;
	if (search(rollNo, &Nabila, &Tiara) == false)
		return false;

	if (Tiara->next != NULL)
		Tiara->next->prev = Nabila;
	if (Nabila != NULL)
		Nabila->next = Tiara->next;
	else
		START = Tiara->next;

	delete Tiara;
	return true;
}

void CircularLinkedList::traverse() { 
	if (listEmpty()) {

	cout << "\nList is empty\n";
}
 else { 
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl; 
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	} 
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
		cout << e.what() << endl;
		}																																																															   																																																																																																																															   
	 }
	 return 0;
 }