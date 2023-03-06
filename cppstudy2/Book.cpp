#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title; // 책의 제목
	char* isbn; // 국제표준도서번호
	int price; // 책의 정가
public:
	Book(const char* _title, const char* _isbn, int _price)
		:price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];

		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}
	Book(const Book& ref)
	{
		int titleLen = strlen(ref.title)+1;
		int isbnLen = strlen(ref.isbn)+1;

		title = new char[titleLen];
		isbn = new char[isbnLen];

		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		price = ref.price;
	}
	Book& operator=(const Book& ref)
	{
		delete[] title;
		delete[] isbn;

		int titleLen = strlen(ref.title) + 1;
		int isbnLen = strlen(ref.isbn) + 1;

		title = new char[titleLen];
		isbn = new char[isbnLen];

		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		price = ref.price;

		return *this;
	}

	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMKey; // 보안관련 키
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		:Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey)+1];
		
		strcpy(DRMKey, _DRMKey);
	}
	EBook(const EBook& ref)
		: Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;

		DRMKey = new char[strlen(ref.DRMKey)];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	void ShowEBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-0", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}