#include <iostream>
#include <string>
#include "Book.h"


using namespace std;

int main() {
    Book b1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");

    cout << "--- Library Book Record ---" << endl;
    cout << "Title:  " << b1.getTitle() << endl;
    cout << "Author: " << b1.getAuthor() << endl;
    cout << "ISBN:   " << b1.getIsbn() << endl;

    return 0;
}
