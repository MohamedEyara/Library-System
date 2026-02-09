#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include"Books.h"
using namespace std;



// --------------------------- Main Program ---------------------------
int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n===== Library System Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Buy Book\n";
        cout << "7. Check Availability\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8) break;

        int id;
        string title, author;
        double price;

       


        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Price: ";
            cin >> price;

            if (!lib.addBook(id, title, author, price)) {
                cout << "Try again with another ID.\n";
            }
            break;


        case 2:
            lib.displayBooks();
            break;

        case 3:
            cin.ignore();
            cout << "Enter Title to search: ";
            getline(cin, title);
            lib.searchBook(title);
            break;

        case 4:
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            lib.borrowBook(id);
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 6:
            cout << "Enter Book ID to buy: ";
            cin >> id;
            lib.buyBook(id);
            break;

        case 7:
            cout << "Enter Book ID to check availability: ";
            cin >> id;
            lib.checkAvailability(id);
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}