#include <stdio.h>

// Define the structure for a book
typedef struct {
    int id;
    char bookgenre[50];
    char title[100];
} Book;

// Function to list books
void listBooks(Book books[], int length) {
    printf("\nID\tBook Genre\t\tBook Title\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%-4d\t%-20s\t%-40s\n", books[i].id, books[i].bookgenre, books[i].title);
    }
}

// Function to find a book by its ID
Book findBookById(Book books[], int length, int id) {
    for (int i = 0; i < length; i++) {
        if (books[i].id == id) {
            return books[i];
        }
    }
    
    Book emptyBook = {-1, "", ""}; // Return an empty book if not found
    return emptyBook;
}

int main(void) {
    printf("Welcome to Bookstore!\n");
    
    // Array of books
    Book books[10] = {
        {1, "Novel", "Crime and Punishment"},
        {2, "Novel", "The Oppressed"},
        {3, "Philosophy", "The Republic"},
        {4, "Biography", "Steve Jobs"},
        {5, "Biography", "Leonardo da Vinci"},
        {6, "Personal Development", "Versatile"},
        {7, "Philosophy", "The Apology of Socrates"},
        {8, "Personal Development", "Willpower Training"},
        {9, "Entrepreneurship", "Google"},
        {10, "Computer Science", "C Programming"}
    };
    
    int kitapid, choice;
    char onay;
    Book selectedBook;

    do {
        printf("\n1. Borrow a Book\n2. Return a Book\n3. Best Sellers\n4. List Books\n5. Exit\n \n Your Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid option. Please enter a number between 1 and 5.\n");
            // Clear invalid input
            while (getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                listBooks(books, 10);
                printf("Which book would you like to borrow? (Enter ID): ");
                if (scanf("%d", &kitapid) != 1) {
                    printf("Invalid ID. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                selectedBook = findBookById(books, 10, kitapid);
                if (selectedBook.id == -1) {
                    printf("No book found with the entered ID.\n");
                } else {
                    printf("\nSelected Book:\nID: %d\nGenre: %s\nTitle: %s\nDo you want to borrow this book? (Y/N): ",
                           selectedBook.id, selectedBook.bookgenre, selectedBook.title);
                    scanf(" %c", &onay); // Space character will consume the newline in buffer.
                    if(onay == 'Y' || onay == 'y') {
                        printf("Congratulations! You have borrowed '%s'.\n", selectedBook.title);
                    } else if(onay == 'N' || onay == 'n') {
                        printf("Book borrowing cancelled.\n");
                    } else {
                        printf("Invalid character. Please enter 'Y' or 'N'.\n");
                    }
                }
                break;
            case 2:
                printf("Which book would you like to return? (Enter ID): ");
                if (scanf("%d", &kitapid) != 1) {
                    printf("Invalid ID. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (kitapid > 0 && kitapid <= 10) {
                    selectedBook = findBookById(books, 10, kitapid);
                    if (selectedBook.id != -1) {
                        printf("Congratulations! You have returned '%s'.\n", selectedBook.title);
                    } else {
                        printf("No book found with the entered ID.\n");
                    }
                } else {
                    printf("Invalid ID. Please enter a valid book ID.\n");
                }
                break;

            case 3:
                listBooks(books, 5); // List top 5 books
                break;
            case 4:
                listBooks(books, 10); // List all books
                break;
            case 5:
                printf("Have healthy days, happy reading...\n");
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1 and 5.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}
