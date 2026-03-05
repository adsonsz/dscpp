#pragma once
#include <cstddef>

namespace ds {

template <typename T>
class doubly_linked_list {
protected:
    struct Node;
    struct Node {
        Node* previous;
        Node* next;
        T data;

        Node(Node* n, Node* p, const T& d) : previous(p), next(n), data(d) {}
    };

private:
    Node* _first;
    Node* _last;
    size_t _size;

public:
    doubly_linked_list() : _first(nullptr), _last(nullptr), _size(0) {}
    doubly_linked_list(const T& data) : _first(new Node(nullptr, nullptr, data)), _size(1) {}
    ~doubly_linked_list();

    // Element access
    inline const T& front() const { return _first->data; }
    inline const T& back() const { return _last->data; }

    // Capacity
    inline bool empty() const { return _first == nullptr; }
    inline size_t size() const { return _size; }

    // Modifiers
    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();
    void clear();
};

template <typename T>
doubly_linked_list<T>::~doubly_linked_list() {
    this->clear();
}

template <typename T>
void doubly_linked_list<T>::push_front(const T& data) {
    Node* new_first = new Node(nullptr, _first, data);
    _first = new_first;
    _size++;
}

template <typename T>
void doubly_linked_list<T>::push_back(const T& data) {
    Node* new_last = new Node(_last, nullptr, data);
    _last = new_last;
    _size++;
}

template <typename T>
void doubly_linked_list<T>::pop_front() {
    Node* new_first = _first->next;
    delete _first;
    _first = new_first;
    _size--;
}

template <typename T>
void doubly_linked_list<T>::pop_back() {
    Node* new_last = _last->previous;
    delete _last;
    _last = new_last;
    _size--;
}

template <typename T>
void doubly_linked_list<T>::clear() {
    // Delete
    Node* current = _first;
    while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }

    // Reinitialize
    _first = nullptr;
    _last = nullptr;
    _size = 0;
}

} // namespace ds

