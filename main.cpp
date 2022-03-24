#include <iostream>
#include "Iterator.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

    Tree<int> tree;

    tree.add(6);
    tree.add(4);
    tree.add(1);
    tree.add(5);
    tree.add(7);
    tree.add(3);
    tree.add(1);
    tree.add(0);
    tree.add(100);

    tree.print();

    Iterator<int> *it = tree.iterator();
    while (it->hasNext()) {
        cout << it->next()->value << " ";
    }

    return 0;
}
