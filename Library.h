#pragma once
#include "Book.h"
class Library
{
	Book** bookArr;
	int bookCount;
	int bookAmount;
public:
	Library();
	~Library();

	void ShowAllBooks();
	void AddBook(const char* title, const char* author, bool st);

};

