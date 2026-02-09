#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// --------------------------- Book Class ---------------------------
class Book {
private:
    int id;
    string title;
    string author;
    double price;
    bool isBorrowed;

public:
    Book(int id, string title, string author, double price) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->price = price;
        this->isBorrowed = false;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
    bool getStatus() const { return isBorrowed; }

    void borrowBook() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }

    void display() const {
        cout << "ID: " << id
            << " | Title: " << title
            << " | Author: " << author
            << " | Price: " << price
            << " | Status: " << (isBorrowed ? "Borrowed" : "Available")
            << endl;
    }
};

// --------------------------- Library Class ---------------------------
class Library {
private:
    vector<Book> books;
    bool isIdExists(int id) const {
        for (const auto& b : books) {
            if (b.getId() == id)
                return true;
        }
        return false;
    }

public:
    bool addBook(int id, const string& title, const string& author, double price) {
        if (isIdExists(id)) {
            cout << " Book ID already exists.\n";
            return false;
        }

        books.push_back(Book(id, title, author, price));
        cout << " Book added successfully!\n";
        return true;
    }



    void displayBooks() {
        cout << "\n--- All Books in Library ---\n";
        for (auto& b : books)
            b.display();
    }

    void searchBook(string title) {
        cout << "\n--- Search Results ---\n";
        bool found = false;
        for (auto& b : books) {
            if (b.getTitle() == title) {
                b.display();
                found = true;
            }
        }
        if (!found)
            cout << "No book found with title: " << title << endl;
    }

    void borrowBook(int id) {
        for (auto& b : books) {
            if (b.getId() == id) {
                if (!b.getStatus()) {
                    b.borrowBook();
                    cout << "Book borrowed successfully!\n";
                }
                else {
                    cout << "Book is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto& b : books) {
            if (b.getId() == id) {
                if (b.getStatus()) {
                    b.returnBook();
                    cout << "Book returned successfully!\n";
                }
                else {
                    cout << "Book was not borrowed.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void buyBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == id) {
                if (books[i].getStatus()) {
                    cout << "Cannot buy this book. It is currently borrowed.\n";
                    return;
                }

                cout << "\n===== Purchase Receipt =====\n";
                cout << "Book Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Price: " << books[i].getPrice() << " EGP\n";
                cout << "Thank you for your purchase!\n";

                books.erase(books.begin() + i);
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void checkAvailability(int id) {
        for (auto& b : books) {
            if (b.getId() == id) {
                cout << "\nBook Found:\n";
                b.display();

                if (b.getStatus())
                    cout << "Status:  Not Available (Borrowed)\n";
                else
                    cout << "Status:  Available\n";
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
   

};


