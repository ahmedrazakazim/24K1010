#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[20];
    char author[20];
    int publicationYear;
    float price;
} Book;

void displayBooks(Book books[], int count)
{
    printf("\nAll Books in the Library:\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nTitle: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication Year: %d\n", books[i].publicationYear);
        printf("Price: %.2f\n", books[i].price);
    }
}

void searchBookByTitle(Book books[], int count, char title[])
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            printf("\nBook found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Price: %.2f\n", books[i].price);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nBook with title '%s' not found.\n", title);
    }
}

void searchBooksByAuthor(Book books[], int count, char author[])
{
    int found = 0;
    printf("\nBooks by %s:\n", author);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            printf("Title: %s\n", books[i].title);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Price: %.2f\n", books[i].price);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No books found by %s.\n", author);
    }
}

int main()
{
    Book library[999];
    int numBooks;
    
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);
    getchar();

    for (int i = 0; i < numBooks; i++)
    {
        printf("\nEnter details for book %d:\n", i + 1);

        printf("Title: ");
        fgets(library[i].title, sizeof(library[i].title), stdin);
        library[i].title[strcspn(library[i].title, "\n")] = 0;

        printf("Author: ");
        fgets(library[i].author, sizeof(library[i].author), stdin);
        library[i].author[strcspn(library[i].author, "\n")] = 0;

        printf("Publication Year: ");
        scanf("%d", &library[i].publicationYear);

        printf("Price: ");
        scanf("%f", &library[i].price);
        getchar();
    }

    displayBooks(library, numBooks);

    char title[100];
    printf("\nEnter the title to search for: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;
    searchBookByTitle(library, numBooks, title);

    char author[100];
    printf("\nEnter the author to list books by: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;
    searchBooksByAuthor(library, numBooks, author);

    return 0;
}
