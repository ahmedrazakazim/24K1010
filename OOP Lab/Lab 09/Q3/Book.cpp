#include "Book.h"
#include <string>

using namespace std;

Book::Book(const string& bookTitle, const string& bookAuthor, const string& bookIsbn)
    : title(bookTitle), author(bookAuthor), isbn(bookIsbn) {
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getIsbn() const {
    return isbn;
}
