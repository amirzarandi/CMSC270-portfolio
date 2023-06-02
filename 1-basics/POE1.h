#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>

template<class T>
class BST {
    struct Node {
        T _x;
        Node *_parent;
        Node *_left;
        Node *_right;
    };
    int _n;
    Node* _root;

public:
    // constructor
    BST();

    BST(T x);

    // destructor
    ~BST();

    // is x in the tree?
    bool isElement(T x);

    bool add(T x);

    T remove(T x);

    int size();
    
    void showNode(T x);

    void traverse();


private:
    Node* find_last(T x);
    bool add_child(Node* p, Node* u);
    void splice(Node* u);
    T remove_node(Node* u);
    void dfs_traverse(Node* r);
};

template<class T>
BST<T>::BST() {
    _n = 0;
    _root = nullptr;
}

template<class T>
BST<T>::BST(T x) {
    _n = 1;
    _root = new Node();
    _root->_x = x;
    _root->_parent = nullptr;
    _root->_left = nullptr;
    _root->_right = nullptr;
}

template<class T>
BST<T>::~BST() {}

template<class T>
bool BST<T>::isElement(T x) {
    Node* currentNode = _root;
    while (currentNode != nullptr) {
        if (x < currentNode->_x) {
            currentNode = currentNode->_left;
        } else if (x > currentNode->_x) {
            currentNode = currentNode->_right;
        } else {
            return true;
        }
    }
    return false;
}

template<class T>
bool BST<T>::add(T x) {
    Node* p = find_last(x);
    Node* newNode = new Node();
    newNode->_x = x;
    return add_child(p, newNode);
}

template<class T>
typename BST<T>::Node* BST<T>::find_last(T x) {
    Node* w = _root;
    Node* prev = nullptr;
    while (w != nullptr) {
        prev = w;
        if (x < w->_x) {
            w = w->_left;
        } else if (x > w->_x) {
            w = w->_right;
        } else {
            return w;
        }
    }
    return prev;
}

template<class T>
bool BST<T>::add_child(Node* p, Node* u) {
    if (p == nullptr) {
        _root = u;
    } else {
        if (u->_x < p->_x) {
            p->_left = u;
        } else if (u->_x > p->_x) {
            p->_right = u;
        } else {
            delete u; // u->_x is already in the tree
            return false;
        }
        u->_parent = p;
    }
    _n++;
    return true;
}

template<class T>
T BST<T>::remove(T x) {
    Node* u = find_last(x);
    T removedValue = remove_node(u);
    return removedValue;
}

template<class T>
void BST<T>::splice(Node* u) {
    Node* s = nullptr;
    Node* p = nullptr;
    if(u->_left != nullptr) {
        s = u->_left;
    } else {
        s = u->_right;
    }
    if (u == _root) {
        _root = s;
        p = nullptr;
    } else {
        p = u->_parent;
        if(p->_left == u) {
            p->_left = s;
        } else {
            p->_right = s;
        }
    }
    if(s == nullptr) {
        if (p != nullptr) {
            s->_parent = p;
        }
    }
    _n--;
}

template<class T>
T BST<T>::remove_node(Node* u) {
    T removedValue = u->_x;
    if (u->_left == nullptr || u->_right == nullptr) {
        splice(u);
    } else {
        Node* w = u->_right;
        while (w->_left != nullptr) {
            w = w->_left;
        }
        u->_x = w->_x;
        splice(w);
    }
    delete u;
    return removedValue;
}


template<class T>
int BST<T>::size() {
    return _n;
}

template<class T>
void BST<T>::showNode(T x) {
    Node* currentNode = find_last(x);
    if (currentNode != nullptr && currentNode->_x == x) {
        std::cout << "Node: " << x << std::endl;
        std::cout << "Parent: ";
        if (currentNode->_parent) {
            std::cout << currentNode->_parent->_x << std::endl;
        } else {
            std::cout << "NULL" << std::endl;
        }
        std::cout << "Left Child: ";
        if (currentNode->_left) {
            std::cout << currentNode->_left->_x << std::endl;
        } else {
            std::cout << "NULL" << std::endl;
        }
        std::cout << "Right Child: ";
        if (currentNode->_right) {
            std::cout << currentNode->_right->_x << std::endl;
        } else {
            std::cout << "NULL" << std::endl;
        }
    } else {
        std::cout << "Node not found in the tree." << std::endl;
    }
}

template<class T>
void BST<T>::traverse() {
    dfs_traverse(_root);
}

template<class T>
void BST<T>::dfs_traverse(Node* r) {
    if(r != nullptr) {
        showNode(r->_x);
        dfs_traverse(r->_left);
        dfs_traverse(r->_right);
    }
}

#endif /* BINARYSEARCHTREE_H_ */