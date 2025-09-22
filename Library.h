#pragma once
#include "Book.h"
#include "Person.h"
class Library
{
	Book** bookArr;
	int bookCount;
	int bookAmount;

	Person** personArr;
	int personCount;
	int personAmount;
public:
	Library();
	~Library();

	void ShowAllBooks();
	void AddBook(const char* title, const char* author, bool st, int bor);
	void AddPerson(const char* name, int id, int is);
	Book* FindBookByTitle(const char* title);
	Book* FindBookByAuthor(const char* author);
	void IssueBook();
	void ReturnBook();
	void MostFrPerson();

};

