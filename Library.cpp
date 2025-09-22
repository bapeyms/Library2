#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() :bookCount(0), bookAmount(3), personCount(0), personAmount(2)
{
	bookArr = new Book * [bookAmount];
    personArr = new Person * [personAmount];
}
Library::~Library()
{
	for (int i = 0; i < bookCount; i++)
	{
		delete bookArr[i];
	}
	delete[] bookArr;

    for (int i = 0; i < personCount; i++)
    {
        delete personArr[i];
    }
    delete[] personArr;
}

void Library::ShowAllBooks()
{
	for (int i = 0; i < bookCount; i++)
	{
		cout << "- Book #" << i + 1 << endl;
		cout << "Title: " << bookArr[i]->GetBookTitle() << endl;
		cout << "Author: " << bookArr[i]->GetBookAuthor() << endl;
        if (bookArr[i]->GetBookStatus())
        {
            cout << "Status: " << bookArr[i]->GetBookStatus() << " (in stock)" << endl;
        }
        else
        {
            cout << "Status: " << bookArr[i]->GetBookStatus() << " (issued)" << endl;
            cout << "Book holder: " << personArr[i]->GetFullName() << " (ID: "
                << personArr[i]->GetID() << ")" << endl;
        }
	}
	cout << endl;
}
void Library::AddBook(const char* title, const char* author, bool st, int bor)
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
        if (bookArr != nullptr)
        {
            delete[] bookArr;
        }
        bookArr = newBookArr;
        bookAmount = newAmount;
    }

    bookArr[bookCount] = new Book(title, author, st, bor);
    bookCount++;
}
void Library::AddPerson(const char* name, int id, int is)
{
    if (personCount >= personAmount)
    {
        int newAmount;
        if (personAmount == 0)
        {
            newAmount = 2;
        }
        else
        {
            newAmount = 2 * personAmount;
        }

        Person** newPersonArr = new Person * [newAmount];
        for (int i = 0; i < personCount; i++)
        {
            newPersonArr[i] = personArr[i];
        }
        if (personArr != nullptr)
        {
            delete[] personArr;
        }
        personArr = newPersonArr;
        personAmount = newAmount;
    }

	personArr[personCount] = new Person(name, id, is);
    personCount++;
}

Book* Library::FindBookByTitle(const char* title)
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (strstr(bookArr[i]->GetBookTitle(), title) != nullptr)
        {
            return bookArr[i];
        }
    }
    return nullptr;
}
Book* Library::FindBookByAuthor(const char* author)
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (strstr(bookArr[i]->GetBookAuthor(), author) != nullptr)
        {
            return bookArr[i];
        }
    }
    return nullptr;
}

void Library::IssueBook()
{
    const int N = 256;
    char title[N];
    int id;
    cout << "Enter a title or a part of it: ";
    cin.getline(title, N);
    cout << "Enter an ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    Book* bookToIssue = nullptr;
    for (int i = 0; i < bookCount; ++i) 
    {
        if (strstr(bookArr[i]->GetBookTitle(), title) != nullptr)
        {
            bookToIssue = bookArr[i];
            break;
        }
    }

    Person* person = nullptr;
    for (int i = 0; i < personCount; ++i) 
    {
        if (personArr[i]->GetID() == id) 
        {
            person = personArr[i];
            break;
        }
    }
    if (bookToIssue == nullptr)
    {
        cout << "Error! Book was not found" << endl;
    }
    else if (person == nullptr)
    {
        cout << "Error! Person was not found" << endl;
    }
    else if (!bookToIssue->GetBookStatus())
    {
        cout << "Error! This book has already issued :(" << endl;
    }
    else if (person->GetIssuedBooks() >= 3)
    {
        cout << "Error! The person already has three issued books!" << endl;
    }
    else {
        bookToIssue->SetBookStatus(false);
        bookToIssue->SetBorrowedID(person->GetID());
        person->SetIssuedBooks(person->GetIssuedBooks() + 1);
        cout << "Book '" << bookToIssue->GetBookTitle() << "' has been successfully issued to "
            << person->GetFullName() << endl << endl;
    }
}
void Library::ReturnBook()
{
    const int N = 256;
    char title[N];
    int id;
    cout << "Enter a title or a part of it: ";
    cin.getline(title, N);
    cout << "Enter an ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    Book* bookToReturn = nullptr;
    for (int i = 0; i < bookCount; ++i)
    {
        if (strstr(bookArr[i]->GetBookTitle(), title) != nullptr)
        {
            bookToReturn = bookArr[i];
            break;
        }
    }
    if (bookToReturn == nullptr)
    {
        cout << "Error! Book was not found" << endl;
    }
    else if (bookToReturn->GetBookStatus() == true)
    {
        cout << "Error! This book is not currently issued" << endl;
    }
    else if (bookToReturn->GetBorrowedID() != id)
    {
        cout << "Error! This book was not issued to this person" << endl;
    }
    else 
    {
        bookToReturn->SetBookStatus(true);
        bookToReturn->SetBorrowedID(0);
        for (int i = 0; i < personCount; ++i)
        {
            if (personArr[i]->GetID() == id)
            {
                personArr[i]->SetIssuedBooks(personArr[i]->GetIssuedBooks() - 1);
                break;
            }
        }
        cout << "Book '" << bookToReturn->GetBookTitle() 
            << "' has been successfully returned" << endl << endl;
    }
}

void Library::MostFrPerson()
{
    int maxBooks = 0;
    Person* mostFrequentPerson = nullptr;

    for (int i = 0; i < personCount; ++i) 
    {
        if (personArr[i]->GetIssuedBooks() > maxBooks)
        {
            maxBooks = personArr[i]->GetIssuedBooks();
            mostFrequentPerson = personArr[i];
        }
    }

    if (mostFrequentPerson != nullptr && maxBooks > 0)
    {
        cout << "The most frequent person: " << mostFrequentPerson->GetFullName() << endl;
        cout << "Issued number of books: " << mostFrequentPerson->GetIssuedBooks() << endl << endl;
    }
    else 
    {
        cout << "No books have been issued yet :(" << endl << endl;
    }
}




