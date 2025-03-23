#include <iostream>
using namespace std;

class Media {
protected:
    string title;
    int publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string t, int pd, string id, string p) 
        : title(t), publicationDate(pd), uniqueID(id), publisher(p) {}

    virtual void displayInfo() {
        cout << endl << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " has been checked out." << endl;
    }

    void returnItem() {
        cout << title << " has been returned." << endl;
    }

    string getTitle() const { return title; }
    int getPublicationDate() const { return publicationDate; }
};

class Book : public Media {
    string author;
    long int ISBN;
    int numberOfPages;

public:
    Book(string t, int pd, string id, string p, string a, long int isbn, int num) 
        : Media(t, pd, id, p), author(a), ISBN(isbn), numberOfPages(num) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number Of Pages: " << numberOfPages << " pages" << endl;
    }

    long int getISBN() const { return ISBN; }
};

class DVD : public Media {
    string director;
    int duration;
    double rating;

public:
    DVD(string t, int pd, string id, string p, string d, int dur, double r) 
        : Media(t, pd, id, p), director(d), duration(dur), rating(r) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, int pd, string id, string p, string a, int num, string g) 
        : Media(t, pd, id, p), artist(a), numberOfTracks(num), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number Of Tracks: " << numberOfTracks << " tracks" << endl;
    }
};

class Magazine : public Media {
    string writer;
    int numberOfPages;

public:
    Magazine(string t, int pd, string id, string p, string w, int num) 
        : Media(t, pd, id, p), writer(w), numberOfPages(num) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Writer: " << writer << endl;
        cout << "Number of Pages: " << numberOfPages << " pages" << endl;
    }
};

void searchMedia(const string title) {
    cout << "Searching for media with title: " << title << endl;
}

void searchMedia(const long int ISBN) {
    cout << "Searching for books with ISBN: " << ISBN << endl;
}

void searchMedia(const int publicationDate) {
    cout << "Searching for media published in: " << publicationDate << endl;
}

int main() {
    Book book("1984", 1949, "B001", "Secker & Warburg", "George Orwell", 1234567890, 328);
    DVD dvd("Inception", 2010, "D001", "Warner Bros.", "Christopher Nolan", 148, 8.8);
    CD cd("Abbey Road", 1969, "C001", "Apple Records", "The Beatles", 17, "Rock");
    Magazine magazine("National Geographic", 2024, "M001", "National Geographic Society", "Jane Doe", 100);

    cout << endl << "Book Information" << endl;
    book.displayInfo();
    book.checkOut();
    book.returnItem();

    cout << endl << "DVD Information" << endl;
    dvd.displayInfo();
    dvd.checkOut();
    dvd.returnItem();

    cout << endl << "CD Information" << endl;
    cd.displayInfo();
    cd.checkOut();
    cd.returnItem();

    cout << endl << "Magazine Information" << endl;
    magazine.displayInfo();
    magazine.checkOut();
    magazine.returnItem();

    cout << endl;
    searchMedia(dvd.getTitle());
    searchMedia(book.getISBN());
    searchMedia(cd.getPublicationDate());
    return 0;
}
