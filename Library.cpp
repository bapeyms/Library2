#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() :bookCount(0), bookAmount(2)
{
	bookArr = new Book * [bookAmount];
}
Library::~Library()
{
	for (int i = 0; i < bookCount; i++)
	{
		delete bookArr[i];
	}
	delete[] bookArr;
}

void Library::ShowAllBooks()
{
	for (int i = 0; i < bookCount; i++)
	{
		cout << "- Book #" << i + 1 << endl;
		cout << "Title: " << bookArr[i]->GetBookTitle() << endl;
		cout << "Author: " << bookArr[i]->GetBookAuthor() << endl;
		cout << "Status: " << bookArr[i]->GetBookStatus() << endl;
	}
	cout << endl;
}

void Library::AddBook(const char* title, const char* author, bool st)
{
    if (bookCount >= bookAmount)
    {
        int newAmount;
        if (bookAmount == 0)
        {
            newAmount = 2;
        }
        else
        {
            newAmount = 2 * bookAmount;
        }

        Book** newBookArr = new Book * [newAmount];
        for (int i = 0; i < bookCount; i++)
        {
            newBookArr[i] = bookArr[i];
        }
        delete[] bookArr;
        bookArr = newBookArr;
        bookAmount = newAmount;
    }

	bookArr[bookCount] = new Book(title, author, st);
	cout << "Book " << bookArr[bookCount]->GetBookTitle() << " has been added" << endl;
	cout << endl;
}
