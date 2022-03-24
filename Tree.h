#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
struct Iterator;

template<typename T>
struct Tree {

    Node<T> *root = nullptr;

    Node<T> *add(T value) {
        if (this->root == nullptr) {
            this->root = new Node<T>(value);
            return this->root;
        }

        Node<T> *searched = nullptr;
        Node<T> *current = root;

        while (searched == nullptr) {
            if (value >= current->value) {
                if (current->right == nullptr) {
                    current->right = new Node<T>(value);
                    current->right->parent = current;
                    searched = current;
                } else {
                    current = current->right;
                }
            } else {
                if (current->left == nullptr) {
                    current->left = new Node<T>(value);
                    current->left->parent = current;
                    searched = current;
                } else {
                    current = current->left;
                }
            }
        }

        current = searched;

        while (current != nullptr) {
            Node<T> *item = current;
            current = current->parent;
            balance(item);
        }

        return searched;
    }

    Node<T> *search(T data) {
        Node<T> *current = root;

        while (current != nullptr && current->value != data) {
            if (data > current->value) {
                current = current->right;
            } else if (data < current->value) {
                current = current->left;
            } else {
                return current;
            }
        }

        return current;
    }

    void print() {
        printNode(root);
        cout << endl;
    }

    Iterator<T> *iterator() {
        return new Iterator<T>(this);
    }

private:

    int heightOf(Node<T> *node) {
        return node == nullptr ? 0 : node->height;
    }

    void updateHeight(Node<T> *node) {
        unsigned int left = heightOf(node->left);
        unsigned int right = heightOf(node->right);
        node->height = left > right ? left + 1 : right + 1;
    }

    Node<T> *leftRotation(Node<T> *node) {
        Node<T> *item = node->right;

        if (node->isRoot()) {
            root = item;
        } else {
            if (node->parent->left == node) {
                node->parent->left = item;
            } else {
                node->parent->right = item;
            }
        }

        item->parent = node->parent;
        node->parent = item;
        if (item->left) item->left->parent = node;
        node->right = item->left;
        item->left = node;

        updateHeight(node);
        updateHeight(item);
        return item;
    }

    Node<T> *rightRotation(Node<T> *node) {
        Node<T> *item = node->left;

        if (node->isRoot()) {
            root = item;
        } else {
            if (node->parent->left == node) {
                node->parent->left = item;
            } else {
                node->parent->right = item;
            }
        }

        item->parent = node->parent;
        node->parent = item;
        if (item->right) item->right->parent = node;
        node->left = item->right;
        item->right = node;

        updateHeight(node);
        updateHeight(item);
        return item;
    }

    int balanceFactor(Node<T> *node) {
        return heightOf(node->right) - heightOf(node->left);
    }

    void balance(Node<T> *node) {
        updateHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node->right) < 0) node->right = rightRotation(node->right);
            leftRotation(node);
        }
        if (balanceFactor(node) == -2) {
            if (balanceFactor(node->left) > 0) node->left = leftRotation(node->left);
            rightRotation(node);
        }
    }

    void printNode(Node<T> *node) {
        if (node != nullptr) {
            printNode(node->left);
            cout << node->value << " ";
            printNode(node->right);
        }
    }

};


#endif