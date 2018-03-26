#include <iostream>
#include "list.h"

using namespace std;
using std::cout;
using std::endl;

List::List() {
	first = nullptr;
}

List::~List() {
	Node* prev;
	Node* temp = first;
	while (temp != nullptr) {
		prev = temp;
		temp = temp ->next;
		delete prev;
	}
}

bool List::exists(int d) const {
	if (empty())
		return false;
	Node* temp = first;
	while (temp) {
		if (temp->value == d)
			return true;
		temp = temp->next;
	}
	return false;
}

int List::size() const {
	Node* temp = first;
	int size = 0;
	while (temp) {
		temp = temp->next;
		size++;
	}
	return size;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	Node* node = new Node(d, first);
	first = node;
}

void List::remove(int d, DeleteFlag df) {
	Node* temp = first;
	Node* prev = temp;
	bool should_remove = false;
	while (temp) {
		if (df == DeleteFlag::EQUAL && d == temp->value ) {
			should_remove = true;
			break;
		} else if (df == DeleteFlag::LESS && d > temp->value) {
			should_remove = true;
			break;
		} else if (df == DeleteFlag::GREATER && d < temp->value) {
			should_remove = true;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (should_remove) {
		if (temp == first) {
			first = temp->next;
		} else {
			prev->next = temp->next;
		}
		delete temp;
	}
}

void List::print() const {
	Node* temp = first;
	cout << endl;
	while (temp) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}
