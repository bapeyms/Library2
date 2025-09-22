#pragma once
class Book
{
	char* bookTitle;
	char* bookAuthor;
	bool status;
	int borrowedID;
public:
	Book();
	Book(const char* name, const char* author, bool st, int bor);
	~Book();

	char* GetBookTitle();
	char* GetBookAuthor();
	bool GetBookStatus();
	int GetBorrowedID();

	void SetBookStatus(bool st);
	void SetBorrowedID(int bor);
};

