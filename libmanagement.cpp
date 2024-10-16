#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void removeBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
        } else {
            for (const auto &book : books) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
                cout << ", Status: " << (book.isIssued ? "Issued" : "Available") << "\n";
            }
        }
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully.\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. View all Books\n";
        cout << "4. Issue a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string title, author;
            cout << "Enter book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        }
        case 2: {
            int id;
            cout << "Enter book ID to remove: ";
            cin >> id;
            library.removeBook(id);
            break;
        }
        case 3:
            library.viewBooks();
            break;
        case 4: {
            int id;
            cout << "Enter book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;
        }
        case 5: {
            int id;
            cout << "Enter book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;
        }
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
