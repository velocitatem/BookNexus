#include <iostream>
#include "Items.h"
#include "library.h"

using namespace std;

int main() {
    Library library("IE Library");

    // example: Book book("Thinking", "Author", 500, 2);

    while
    (true)
    {

    printf("1. Add Item\n2. Remove Item\n3. Search Item\n4. Checkout\n5. Exit\n");
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            string name, author;
            int pages_count, price;
            printf("Enter name, author, pages_count, price\n");
            cin >> name >> author >> pages_count >> price;
            LibraryItem* item = new LibraryItem(name, author, pages_count, price);
            library.add_item(item);
            break;
        }
        case 2: {
            string name, author;
            int pages_count, price;
            printf("Enter name, author, pages_count, price\n");
            cin >> name >> author >> pages_count >> price;
            LibraryItem* item = new LibraryItem(name, author, pages_count, price);
            library.remove_item(item);
            break;
        }
        case 3: {
            string query;
            printf("Enter query\n");
            cin >> query;
            LibraryItem* item = library.search_item(query);
            display_item(*item);
            break;
        }
        case 4: {
            string name, author;
            int pages_count, price;
            printf("Enter name, author, pages_count, price\n");
            cin >> name >> author >> pages_count >> price;
            LibraryItem* item = new LibraryItem(name, author, pages_count, price);
            library.checkout(item);
            break;
        }
        case 5: {
            return 0;
        }
    }

    }
    ;



    return 0;
}
