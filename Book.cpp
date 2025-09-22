#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() :bookTitle(nullptr), bookAuthor(nullptr), status(true) {}
Book::Book(const char* name, const char* author, bool st)
{
	bookTitle = new char[strlen(name) + 1];
	strcpy_s(bookTitle, strlen(name) + 1, name);

	bookAuthor = new char[strlen(author) + 1];
	strcpy_s(bookAuthor, strlen(author) + 1, author);

	status = st;
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
