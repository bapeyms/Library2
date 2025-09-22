#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() :fullName(nullptr), ID(0), issuedBooks(0) {}
Person::Person(const char* name, int id, int is)
{
	fullName = new char[strlen(name) + 1];
	strcpy_s(fullName, strlen(name) + 1, name);

	ID = id;
	issuedBooks = is;
}
Person::~Person()
{
	delete[] fullName;
}

char* Person::GetFullName()
{
	return fullName;
}
int Person::GetID()
{
	return ID;
}
int Person::GetIssuedBooks()
{
	return issuedBooks;
}

void Person::SetIssuedBooks(int is)
{
	issuedBooks = is;
}
