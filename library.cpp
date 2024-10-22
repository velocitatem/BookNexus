//
// Created by velocitatem on 10/1/24.
//

#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library(string name) : name(name) {
    // TODO: read from file in binary
    // if file does not exist, create it

    fstream file;
    file.open("library.bin", ios::in | ios::binary);
    if (file.is_open()) {

        file.close();
    }
    else {
        file.open("library.bin", ios::out | ios::binary);

        file.close();
    }

}

Library::~Library() {
    // TODO: write to file
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




