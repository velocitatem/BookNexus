//
// Created by velocitatem on 10/1/24.
//

#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library() : name("") {}

Library::Library(string name) : name(name) {
    // deserialize from csv not obj
    ifstream file("../data/library.txt");
    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        string name, author;
        int pages, remaining;
        double price;
        size_t pos = 0;
        pos = line.find(",");
        name = line.substr(0, pos);
        line.erase(0, pos+1);
        pos = line.find(",");
        author = line.substr(0, pos);
        line.erase(0, pos+1);
        pos = line.find(",");
        pages = stoi(line.substr(0, pos));
        line.erase(0, pos+1);
        pos = line.find(",");
        price = stod(line.substr(0, pos));
        line.erase(0, pos+1);
        remaining = stoi(line);
        LibraryItem item(name, author, pages, price);
        item.set_remaining(remaining);
        this->items[item.hash()] = item;
    }
}

Library::~Library() {
    // serialize with plain text, save as a csv
    ofstream file("../data/library.txt");
    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    for (auto const& [key, val] : this->items) {
        LibraryItem item = val;
        file << item.get_name() << "," << item.get_author() << "," << item.get_pages_count() << "," << item.get_price() << "," << item.get_remaining() << endl;
    }
}
void Library::add_item(LibraryItem item) {
    if (items.count(item.hash())) { // check if we have it
        LibraryItem* try_find = this->get_item_by_hash(item.hash());
        try_find->set_remaining(try_find->get_remaining()+1); // increment if we found it
    }
    else {
        this->items[item.hash()] = item; // add new to library
    }
}
void Library::remove_item(LibraryItem *item) {
    this->items.erase(item->hash());
}

LibraryItem* Library::get_item_by_hash(size_t hash) {
    // I thought for a smaller size library a hash-functino might be
    // most efficient for easy access and low chance of duplicates
    if (this->items.count(hash)) { // we see if its in the keys
        map<size_t, LibraryItem>::iterator res = items.find(hash); // we find the key-val pair
        return res == items.end() ? &null_item : &res->second; // return item or null pointer
    }
    return &null_item; // just null
}

LibraryItem* Library::search_item(string name) {
    hash<string> hasher; // make a hasher obj
    return this->get_item_by_hash(hasher(name));
}

bool Library::checkout(LibraryItem *item) {
    if (item->get_remaining() == 0) {
        return false; // if we have none..
    }
    item->set_remaining(item->get_remaining()-1);
    return true;
}




void display_item(LibraryItem item) {
    cout << "📖 " << item.get_name() << " by " << item.get_author() << endl;
}




