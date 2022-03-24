#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

template<typename T>
struct Node {

    T value;
    Node<T> *parent = nullptr;
    Node<T> *right = nullptr;
    Node<T> *left = nullptr;
    unsigned int height = 1;

    Node(T value) {
        this->value = value;
    }

    bool isLeaf() {
        return this->left == nullptr && this->right == nullptr;
    }

    bool isRoot() {
        return this->parent == nullptr;
    }

};


#endif //BINARYTREE_NODE_H
