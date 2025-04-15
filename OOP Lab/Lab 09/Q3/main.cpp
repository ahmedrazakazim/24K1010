#include <iostream>
#include <string>
#include "Book.h"


using namespace std;

int main() {
    Book myBook("The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");

    cout << "--- Library Book Record ---" << endl;
    cout << "Title:  " << myBook.getTitle() << endl;
    cout << "Author: " << myBook.getAuthor() << endl;
    cout << "ISBN:   " << myBook.getIsbn() << endl;

    return 0;
}
