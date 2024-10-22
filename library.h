//
// Created by velocitatem on 10/1/24.
//


#include <map>

#include "Items.h"
#include <vector>
#include <string>
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

void display_item(LibraryItem item);
class Library {
public:
    Library(string name);
    ~Library();
    void add_item(LibraryItem item);
    void remove_item(LibraryItem *item);
    LibraryItem* search_item(string query);
    LibraryItem* get_item_by_hash(size_t hash);
    bool checkout(LibraryItem *item);
    LibraryItem null_item;
private:
    map<size_t, LibraryItem> items;
    string name;

};

#endif //LIBRARY_H
