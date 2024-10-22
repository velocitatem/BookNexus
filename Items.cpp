//
// Created by velocitatem on 10/1/24.
//

#include "Items.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <string>

using namespace std;

LibraryItem::LibraryItem(): name(""), author(""), pages_count(0), price(0), remaining(0) {}  // Default constructor

LibraryItem::LibraryItem(string name, string author, int pages_count, int price)
: name(name), author(author), pages_count(pages_count), price(price), remaining(1) {}

LibraryItem::~LibraryItem() {
    // all static variables
}


string LibraryItem::get_author() {
    return this->author;
}

string LibraryItem::get_name() {
    return this->name;
}

int LibraryItem::get_pages_count() {
    return this->pages_count;
}

int LibraryItem::get_price() {
    return this->price;
}

int LibraryItem::get_remaining() {
    return this->remaining;
}


void LibraryItem::set_remaining(int remaining) {
    this->remaining = remaining;
}


bool LibraryItem::operator==(const LibraryItem &B) const {
    return this->name == B.name && this->author == B.author && this->pages_count == B.pages_count && this->price == B.price;
}



size_t LibraryItem::hash() {
    string str = this->get_name() + " by " + this->get_author();
    std::hash<std::string> hash_fn;
    size_t hash_value = hash_fn(str);
    return hash_value;
}


Book::Book(string name, string author, int pages_count, int price)
        : LibraryItem(name, author, pages_count, price) {
    }

Magazine::Magazine(string name, string author, int pages_count, int price)
        : LibraryItem(name, author, pages_count, price) {
    };

