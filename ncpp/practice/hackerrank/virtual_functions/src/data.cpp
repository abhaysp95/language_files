#include "../inc/data.hpp"
#include <iostream>

Person::Person() {
	this->name_ = "";
	this->age_ = 0;
}

std::string Person::getName() const { return this->name_; }
int Person::getAge() const { return this->age_; }
void Person::getdata() {
	std::string name;
	std::cin >> name;
	this->name_ = name.c_str();
}
void Person::putdata() const {
	std::cout << this->name_ << this->age_ << std::endl;
}

void Person::setName(std::string name) { this->name_ = name; }
void Person::setAge(int age) { this->age_ = age; }

int Professor::id = 0;
Professor::Professor() {
	this->publications_ = 0;
	this->cur_id_ = ++id;
}

void Professor::getdata() {
	std::string name;
	int age;
	std::cin >> name >> age >> this->publications_;
	this->setName(name.c_str());
	this->setAge(age);
}

void Professor::putdata() const {
	std::cout << this->getName() << " "
		<< this->getAge() << " "
		<< this->publications_ << " "
		<< this->cur_id_ << std::endl;
}

int Student::id = 0;
Student::Student() {
//#define SIZE 6
	this->marks_ = new int[SIZE];
	this->cur_id_ = ++id;
}

void Student::getdata() {
	std::string name;
	int age;
	std::cin >> name >> age;
	for (int i = 0; i < SIZE; ++i) {
		std::cin >> this->marks_[i];
	}
	this->setName(name.c_str());
	this->setAge(age);
}

int Student::sum() const {
	int sum{0};
	for (int i = 0; i < SIZE; ++i) {
		sum += this->marks_[i];
	}
	return sum;
}

void Student::putdata() const {
	std::cout << this->getName() << " "
		<< this->getAge() << " "
		<< this->sum() << " "
		<< this->cur_id_ << std::endl;;
}