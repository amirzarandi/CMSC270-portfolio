#include <iostream>

template<class T>
class  ArrayDeque {
    protected:
        int _n;
        T *_a; 
        int _j;
        int _size; 
        void resize();
    public:
         ArrayDeque(int n);

        ~ArrayDeque();

        T get(int i);
        T set(int i, T x);

        void add(int i, T x);
        
        T remove(int i);

        void display();        
};

template<class T>
ArrayDeque<T>::ArrayDeque(int size) {
    _a = new T[size];
    _size = size; 
    _n = 0;
    _j = 0;
}

template<class T>
ArrayDeque<T>::~ArrayDeque() {}

template<class T>
void ArrayDeque<T>::resize() {
    T * b = new T[max(1, 2*_n)];
    for (int i = 0; i < _n; i++) {
        b[i] = _a[i];
    }     
    _a = b;
    _size = max(1, 2*_n);
}

template<class T>
T ArrayDeque<T>::get(int i) {
    return _a[(_j + i) % _size];
}

template<class T>
T ArrayDeque<T>::set(int i, T x) {
    T y = _a[(_j + i) % _size];
    _a[(_j + i) % _size] = x;
    return y;
}

template<class T>
void ArrayDeque<T>::add(int i, T x) {
    if (_n == _size) {
        resize();
    }
    if (i < _n/2) {
        _j = (_j - 1 + _size)%_size;
        for (int k = 0; k < i; k++) {
            _a[(_j + k) % _size] = _a[(_j + k + 1) % _size];
        }
    } else {
        for (int k = _n; k > i ; k--) {
            _a[(_j + k) % _size] = _a[(_j + k -1) % _size];
        }
    }
    _a[(_j + i) % _size] = x;
    _n++;
}

template<class T>
T ArrayDeque<T>::remove(int i) {
    T x = _a[(_j + i) % _size];
    if (i < _n/2) {
        for (int k = i; k > 0; k--) {
            _a[(_j + k) % _size] = _a[(_j + k - 1) % _size];
        }
        _j = (_j + 1)%_size;
    } else {
        for (int k = i; k > _n-3; k--) {
            _a[(_j + k) % _size] = _a[(_j + k + 1) % _size];
        }
    }
    _n--;
    if (_size >= 3 * _n) {
        resize();
    }
    return x;
}

template<class T>
void ArrayDeque<T>::display() {
    std::cout << "[";
    for (int i = 0; i < _n; i++) {
        std::cout << " " << _a[i];
    }
    for (int j = _n; j < _size; j++) {
        std::cout << " -";
    }
    std::cout << " ]" << std::endl;
}
