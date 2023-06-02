#ifndef DLLIST_H_
#define DLLIST_H_

template<class T>
class DLList {
    struct Node {
        T _x;
        Node *_next;
        Node *_prev;
        Node(T x) {
            _x = x;
            _next = _prev = nullptr;
        }
    };
    
	Node dummy;
	int _n;

protected:
    Node* getNode(int i);

    Node* addBefore(Node *w, T x);

    void removeNode(Node *w);

public:

    DLList();

    ~DLList();

    T get(int i);
    T set(int i, T x);

    void add(int i, T x);
    void add_to_end(T x);

    T remove(int i);
    T remove_from_front();
};

template<class T>
DLList<T>::DLList() { 
	_n = 0;
    dummy._x = T();
	dummy._prev = &dummy;
    dummy._next = &dummy;
}

template<class T>
DLList<T>::~DLList() {
	Node *u = dummy._next;
	while (u != &dummy) {
		Node *w = u;
		u = u->_next;
		delete w;
	}
}

template<class T>
DLList<T>::Node* DLList<T>::getNode(int i) {
    Node* p;
    if(i < _n/2) {
        p = dummy._next;
        int j = 0;
        while(j < i) {
            p = p->_next;
            j++;
        }
    } else {
        p = &dummy;
        int j = _n;
        while(j > i + 1) {
            p = p->_prev;
            j--;
        }
    }
    return p;
}

template<class T>
T DLList<T>::get(int i) { 
    Node* u = getNode(i);
    return u->_x;
}

template<class T>
T DLList<T>::set(int i, T x) {
    Node* u = getNode(i);
    T y = u->_x;
    u->_x = x;
    return y;
}

template<class T>
DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
    Node *u = new Node(x);
    u->_prev = w->_prev;
    u->_next = w;
    u->_next->_prev = u;
    u->_prev->_next = u;
    _n++;
    return u;
}

template<class T>
void DLList<T>::add(int i, T x) {
    if (_n == 0) {
        addBefore(&dummy, x);
    } else {
        Node* u = getNode(i);
        addBefore(u, x);
    }
}

template<class T>
void DLList<T>::removeNode(Node *w) {
    w->_prev->_next = w->_next;
    w->_next->_prev = w->_prev;
    delete w;
    _n--;
}

template<class T>
T DLList<T>::remove(int i) {
    Node* u = getNode(i);
    T x = u->_x;
    removeNode(u);
    return x;
}

template<class T>
void DLList<T>::add_to_end(T x) {
    addBefore(&dummy, x);
}

template<class T>
T DLList<T>::remove_from_front() {
    Node* u = dummy._next;
    T x = u->_x;
    removeNode(u);
    return x;
}

#endif /*DLLIST_H_*/