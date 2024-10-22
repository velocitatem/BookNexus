//
// Created by velocitatem on 10/22/24.
//

#include <iostream>
#include <gtest/gtest.h>

#include "library.h"

TEST(Library, AddItem) {
    Library library("Library");
    LibraryItem item("Book", "Author", 100, 10);
    library.add_item(item);
    LibraryItem* found = library.get_item_by_hash(item.hash());
    EXPECT_EQ(found->get_name(), "Book");
    EXPECT_EQ(found->get_author(), "Author");
    EXPECT_EQ(found->get_pages_count(), 100);
    EXPECT_EQ(found->get_price(), 10);
    EXPECT_EQ(found->get_remaining(), 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}