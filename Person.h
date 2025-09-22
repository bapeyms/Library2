#pragma once
class Person
{
	char* fullName;
	int ID;
	int issuedBooks;
public:
	Person();
	Person(const char* name, int id, int is);
	~Person();

	char* GetFullName();
	int GetID();
	int GetIssuedBooks();

	void SetIssuedBooks(int is);
};

