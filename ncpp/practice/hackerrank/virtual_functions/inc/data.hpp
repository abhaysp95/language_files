#pragma once

#include <string>
#include <cstring>
#define SIZE 6

class Person {
	private:
		std::string name_;
		int age_;
	public:
		Person();
		std::string getName() const;
		int getAge() const;
		void setName(std::string name);
		void setAge(int age);
		virtual void getdata();
		virtual void putdata() const;
};

class Professor: public Person {
	private:
		int publications_;
		int cur_id_;
	public:
		static int id;
		Professor();
		void getdata() override;
		void putdata() const override;
};

class Student: public Person {
	private:
		int* marks_;
		int cur_id_;
		int sum() const;
	public:
		static int id;
		Student();
		void getdata() override;
		void putdata() const override;
};