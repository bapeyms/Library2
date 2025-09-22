#include <iostream>
#include "Book.h"
#include "Person.h"
#include "Library.h"
using namespace std;

enum Menu
{
	SHOW_ALL_BOOKS = 1,
	ADD_BOOK = 2,
	ADD_PERSON = 3,
	ISSUE_BOOK = 4,
	RETURN_BOOK = 5,
	FIND_BY_TITLE = 6,
	FIND_BY_AUTHOR = 7,
	FIND_MOST_FREQUENT = 8,
	EXIT = 0
};
int MenuChoice(int menuNumber)
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 0 || menuChoice > menuNumber)
	{
		cout << "Enter a number from 0 to " << menuNumber << "!" << endl;
		cout << "Number: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');
	}
	cout << endl;
	return menuChoice;
}

int main()
{
	cout << "-- LIBRARY --" << endl << endl;
	Library myLibrary;
	myLibrary.AddBook("Notes Of A Crocodole", "Qie Miaojin", true, 0);
	myLibrary.AddBook("Geungsi", "Sean Lam", true, 0);
	myLibrary.AddBook("Soul Mountain", "Gao Xingjian", true, 0);

	myLibrary.AddPerson("Kaiden Blackwood", 101, 0);
	myLibrary.AddPerson("Lyora Whitestone", 102, 0);

	while (true)
	{
		cout << "- LIBRARY MENU -" << endl;
		cout << "1. Show all books " << endl;
		cout << "2. Add a book" << endl;
		cout << "3. Add a person" << endl;
		cout << "4. Issue a book" << endl;
		cout << "5. Return a book" << endl;
		cout << "6. Find a book by the title" << endl;
		cout << "7. Find a book by the author" << endl;
		cout << "8. Find most frequent reader" << endl;
		cout << "0. Exit" << endl << endl;

		int menuNumber = 8;
		int menuChoice = MenuChoice(menuNumber);

		switch (menuChoice) {
		case SHOW_ALL_BOOKS: {
			cout << "- BOOKS' CATALOG -" << endl;
			myLibrary.ShowAllBooks();
			break;
		}
		case ADD_BOOK: {
			cout << "- BOOK ADDITION -" << endl;
			const int N = 256;
			char title[N];
			char author[N];
			bool st = true;
			int bor = 0;
			cout << "Enter title: ";
			cin.getline(title, N);
			cout << "Enter author: ";
			cin.getline(author, N);
			myLibrary.AddBook(title, author, st, bor);
			break;
		}
		case ADD_PERSON: {
			cout << "- PERSON ADDITION -" << endl;
			const int N = 256;
			char name[N];
			int id;
			int is = 0;
			cout << "Enter full name: ";
			cin.getline(name, N);
			cout << "Enter ID: ";
			cin >> id;
			cin.ignore(1000, '\n');
			myLibrary.AddPerson(name, id, is);
			break;
		}
		case ISSUE_BOOK: {
			cout << " - BOOK ISSUE -" << endl;
			myLibrary.IssueBook();
			break;
		}
		case RETURN_BOOK: {
			cout << " - BOOK RETURN -" << endl;
			myLibrary.ReturnBook();
			break;
		}
		case FIND_BY_TITLE: {
			cout << " - FIND BOOK BY TITLE -" << endl;
			const int N = 256;
			char title[N];
			cout << "Enter a title or a part of it: ";
			cin.getline(title, N);
			Book* foundBook = myLibrary.FindBookByTitle(title);
			if (foundBook != nullptr)
			{
				cout << "Book was found!" << endl;
				cout << "Title: " << foundBook->GetBookTitle() << endl;
				cout << "Author: " << foundBook->GetBookAuthor() << endl;
				if (foundBook->GetBookStatus())
				{
					cout << "Status: " << foundBook->GetBookStatus() << " (in stock)" << endl << endl;
				}
				else
				{
					cout << "Status: " << foundBook->GetBookStatus() << " (issued)" << endl << endl;
				}
			}
			else
			{
				cout << "Book was not found :(" << endl << endl;
			}
			break;
		}
		case FIND_BY_AUTHOR: {
			cout << " - FIND BOOK BY AUTHOR -" << endl;
			const int N = 256;
			char author[N];
			cout << "Enter an author or a part of it: ";
			cin.getline(author, N);
			Book* foundBook = myLibrary.FindBookByAuthor(author);
			if (foundBook != nullptr)
			{
				cout << "Book was found!" << endl;
				cout << "Title: " << foundBook->GetBookTitle() << endl;
				cout << "Author: " << foundBook->GetBookAuthor() << endl;
				if (foundBook->GetBookStatus())
				{
					cout << "Status: " << foundBook->GetBookStatus() << " (in stock)" << endl << endl;
				}
				else
				{
					cout << "Status: " << foundBook->GetBookStatus() << " (issued)" << endl << endl;
				}
			}
			else
			{
				cout << "Book was not found :(" << endl << endl;
			}
			break;
		}
		case FIND_MOST_FREQUENT: {
			cout << " - MOST FREQUENT READER -" << endl;
			myLibrary.MostFrPerson();
			break;
		}
		case EXIT: {
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
		}
	}
}