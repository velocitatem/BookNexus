//
// Created by velocitatem on 10/1/24.
//
#include <string>
using namespace std;

#ifndef ITEMS_H
#define ITEMS_H

class LibraryItem {
public:
    LibraryItem();
    LibraryItem(string name, string author, int pages_count, int price);
    ~LibraryItem();
    string get_name();
    string get_author();
    int get_pages_count();
    int get_price();
    int get_remaining();
    void set_name(string name);
    void set_author(string author);
    void set_pages_count(int pages_count);
    void set_price(int price);
    void set_remaining(int remaining);
    size_t hash();
    bool operator==(const LibraryItem &B) const;


private:
    string name;
    string author;
    int pages_count;
    int remaining;
    int price;
};

class Book : public LibraryItem {
public:
    Book(string name, string author, int pages_count, int price);
};

class Magazine : public LibraryItem {
public:
    Magazine(string name, string author, int pages_count, int price);
};


#endif //ITEMS_H
