#include "gtest/gtest.h"
#include "Iterator.h"

TEST(BinaryTree, Nullable) {
    Tree<int> tree;
    Iterator<int> *it = tree.iterator();
    string s = "";
    while (it->hasNext()) {
        s = s + to_string(it->next()->value);
    }
    ASSERT_EQ(s, "");
}

TEST(BinaryTree, OnlyRoot) {
    Tree<int> tree;
    tree.add(2);
    Iterator<int> *it = tree.iterator();
    string s = "";
    while (it->hasNext()) {
        s = s + to_string(it->next()->value);
    }
    ASSERT_EQ(s, "2");
}

TEST(BinaryTree, OneParentTwoChildren) {
    Tree<int> tree;
    tree.add(100);
    tree.add(90);
    tree.add(110);
    Iterator<int> *it = tree.iterator();

    string s = "";
    while (it->hasNext()) {
        s = s + to_string(it->next()->value);
    }
    ASSERT_EQ(s, "90100110");
}

TEST(BinaryTree, OnlyLeftBranch) {
    Tree<int> tree;
    tree.add(100);
    tree.add(90);
    tree.add(80);
    tree.add(60);
    Iterator<int> *it = tree.iterator();

    string s = "";
    while (it->hasNext()) {
        s = s + to_string(it->next()->value);
    }
    ASSERT_EQ(s, "608090100");
}