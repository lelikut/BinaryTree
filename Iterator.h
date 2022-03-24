#ifndef BINARYTREE_ITERATOR_H
#define BINARYTREE_ITERATOR_H
#pragma once

#include "Tree.h"

template<typename T>
struct Iterator {

    Tree<T> *collection;
    Node<T> *current;

    Iterator(Tree<T> *collection) {
        this->collection = collection;
        this->current = fetchNext();
    }

    bool hasNext() {
        return current != nullptr;
    }

    Node<T> *next() {
        Node<T> *previous = current;
        this->current = fetchNext();
        return previous;
    }

private:

    Node<T> *findMin(Node<T> *currentNode) {
        if (!currentNode->left) return currentNode;

        return findMin(currentNode->left);
    }

    Node<T> *getNextParent(Node<T> *currentNode) {
        Node<T> *parent = currentNode->parent;

        if (parent) {
            if (parent->left == currentNode) {
                return parent;
            } else {
                return getNextParent(parent);
            }
        }

        return parent;
    }

    Node<T> *fetchNext() {
        if (this->current == nullptr) {
            return findMin(this->collection->root);
        }

        if (this->current->isLeaf()) {
            return getNextParent(this->current);
        }

        if (this->current->right) {
            return findMin(this->current->right);
        } else {
            return getNextParent(this->current);
        }
    }
};

#endif