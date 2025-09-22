#pragma once
class Book
{
	char* bookTitle;
	char* bookAuthor;
	bool status;
public:
	Book();
	Book(const char* name, const char* author, bool st);
	~Book();

	char* GetBookTitle();
	char* GetBookAuthor();
	bool GetBookStatus();
};

