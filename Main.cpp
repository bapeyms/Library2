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
	myLibrary.AddBook("Notes Of A Crocodole", "Qie Miaojin", true);
	myLibrary.AddBook("Geungsi", "Sean Lam", true);
	myLibrary.AddBook("Soul Mountain", "Gao Xingjian", true);

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
		case SHOW_ALL_BOOKS:
			cout << "- BOOKS' CATALOG -" << endl;
			myLibrary.ShowAllBooks();
			break;
		case ADD_BOOK:
			cout << "- BOOK ADDITION -" << endl;
			cout << endl << endl;
			break;
		case ADD_PERSON:
			cout << "- PERSON ADDITION -" << endl;
			break;
		case ISSUE_BOOK:
			cout << " - BOOK ISSUE -" << endl;
			break;
		case RETURN_BOOK:
			cout << " - BOOK RETURN -" << endl;
			break;
		case FIND_BY_TITLE:
			cout << " - FIND BOOK BY TITLE -" << endl;
			break;
		case FIND_BY_AUTHOR:
			cout << " - FIND BOOK BY AUTHOR -" << endl;
			break;
		case FIND_MOST_FREQUENT:
			cout << " - MOST FREQUENT READER -" << endl;
			break;
		case EXIT:
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
	}
}