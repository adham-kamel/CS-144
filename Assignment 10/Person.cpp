#include "Person.h"

void Person::procreate(Person* child) {
	children.push_back(child);
	child->parent = this;
}

void Person::print() const {
	if (this == nullptr) {
		return;
	}
	if (this->parent != nullptr) {
		cout << "+---";
	}
	if (this->spouse_name != "") {
		cout << this->name << " (" << this->spouse_name << ")";
	}
	else {
		cout << this->name;
	}
	cout << endl;
	for (int i = 0; i < this->children.size(); i++) {
		print_bar();
		cout << "|" << endl;
		print_bar();
		this->children[i]->print();
	}
}

void Person::print_bar() const {
	if (parent == nullptr) {
		return;
	}
	parent->print_bar();
	if (this == parent->children.back()) {
		cout << "   ";
	}
	else {
		cout << "|  ";
	}
}

Person::~Person() {
	if (this == nullptr) {
		return;
	}
	for (int i = 0; i < this->children.size(); i++) {
		delete this->children[i];
	}
	cout << "deleted " << this->name << endl;
}
