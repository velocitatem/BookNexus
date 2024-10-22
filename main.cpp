#include <iostream>
#include "Items.h"
#include "library.h"

using namespace std;

void addItem(Library& library) {
    string title, author;
    int pages, copies;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter pages: ";
    cin >> pages;
    cout << "Enter number of copies: ";
    cin >> copies;
    Book book(title, author, pages, copies);
    library.add_item(book);
    cout << "Item added successfully.\n";
}

void removeItem(Library& library) {
    string title;
    cout << "Enter title of the item to remove: ";
    cin.ignore();
    getline(cin, title);
    LibraryItem *item = library.search_item(title);
    library.remove_item(item);
    cout << "Item removed successfully.\n";
}

void searchItem(Library& library) {
    string title;
    cout << "Enter search query ('Book by Author'): ";
    cin.ignore();
    getline(cin, title);
    LibraryItem* item = library.search_item(title);
    if (*item != library.null_item) {
        cout << "Item found: " << item->get_author() << ", " << item->get_pages_count() << " pages, " << item->get_remaining() << " copies remaining.\n";
    } else {
        cout << "Item not found.\n";
    }
}

void checkoutItem(Library& library) {
    string title;
    cout << "Enter title of the item to checkout: ";
    cin.ignore();
    getline(cin, title);
    LibraryItem* item = library.search_item(title);
    if (item) {
        if (library.checkout(item)) {
            cout << "Item checked out successfully.\n";
        } else {
            cout << "Item not available.\n";
        }
    } else {
        cout << "Item not found.\n";
    }
}

int main() {
    Library library("IE Library");

    while (true) {
        cout << "1. Add Item\n2. Remove Item\n3. Search Item\n4. Checkout\n5. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(library);
                break;
            case 2:
                removeItem(library);
                break;
            case 3:
                searchItem(library);
                break;
            case 4:
                checkoutItem(library);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}