
#include "Books.h"
#include <iostream>
using namespace std;

Book::Book(int id, string title, string author, double price) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->price = price;
    this->isBorrowed = false;
}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
double Book::getPrice() const { return price; }
bool Book::getStatus() const { return isBorrowed; }

void Book::borrowBook() { isBorrowed = true; }
void Book::returnBook() { isBorrowed = false; }

void Book::display() const {
    cout << "ID: " << id
        << " | Title: " << title
        << " | Author: " << author
        << " | Price: " << price
        << " | Status: " << (isBorrowed ? "Borrowed" : "Available")
        << endl;
}
