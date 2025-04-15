#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& bookTitle, const string& bookAuthor, const string& bookIsbn);

    string getTitle() const;
    string getAuthor() const;
    string getIsbn() const;
};

#endif
