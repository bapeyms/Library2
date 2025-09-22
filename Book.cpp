#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() :bookTitle(nullptr), bookAuthor(nullptr), status(true), borrowedID(0) {}
Book::Book(const char* name, const char* author, bool st, int bor)
{
	bookTitle = new char[strlen(name) + 1];
	strcpy_s(bookTitle, strlen(name) + 1, name);

	bookAuthor = new char[strlen(author) + 1];
	strcpy_s(bookAuthor, strlen(author) + 1, author);

	status = st;
	borrowedID = bor;
}
Book::~Book()
{
	delete[] bookTitle;
	delete[] bookAuthor;
}

char* Book::GetBookTitle()
{
	return bookTitle;
}
char* Book::GetBookAuthor()
{
	return bookAuthor;
}
bool Book::GetBookStatus()
{
	return status;
}
int Book::GetBorrowedID()
{
	return borrowedID;
}

void Book::SetBookStatus(bool st)
{
	status = st;
}
void Book::SetBorrowedID(int bor)
{
	borrowedID = bor;
}


