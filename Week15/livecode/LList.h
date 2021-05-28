#include <iostream>

template <class T>
class LList {
    public:
        LList();
        LList(const LList&);
        LList& operator=(const LList&);
        ~LList();

    public:
        void push_back(const T& element);
        void print() const;

    private:
        struct Node {
            T data;
            Node* next;
        };
    Node* first;
    void copy(const LList& other);
    void erase(); 

    public:
        class Iterator {
            public:
                Iterator();
                Iterator(Node* _current);
                bool operator!=(const Iterator& other);
                T& operator*();
                void operator++();
            private:
                Node* current;
        };
    Iterator begin();
    Iterator end();
};

template <class T>
LList<T>::Iterator::Iterator() {
    current = nullptr;
}

template <class T>
LList<T>::Iterator::Iterator(Node* _current) {
    current = _current;
}

template <class T>
bool LList<T>::Iterator::operator!=(const Iterator& other) {
    return current != other.current;
}

template <class T>
T& LList<T>::Iterator::operator*() {
    return current->data;
}

template <class T>
void LList<T>::Iterator::operator++() {
    current = current->next;
}

template <class T>
typename LList<T>::Iterator LList<T>::begin() {
    return Iterator(first);
}

template <class T>
typename LList<T>::Iterator LList<T>::end() {
    return Iterator(nullptr);
}

template <class T>
void LList<T>::copy(const LList& other) {
    if(other.first == nullptr) {
        return;
    }

//  --------------------------------------------- //
// Първи начин
    // first = new Node{other.first->data, nullptr};
    // Node* crr_other = other.first;
    // Node* crr = first;

    // while(crr_other->next != nullptr) {
    //     crr->next = new Node{crr_other->next->data, nullptr};
    //     crr = crr->next;
    //     crr_other = crr_other->next;
    // }

//  --------------------------------------------- //
// Втори начин
    first = new Node{other.first->data, nullptr};
    Node* crr_other = other.first->next;

    while(crr_other != nullptr) {
        push_back(crr_other->data);
        crr_other = crr_other->next;
    } 
}

template <class T>
void LList<T>::erase() {
    while(first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    first = nullptr;
}

template <class T>
LList<T>::~LList() {
    this->erase();
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& other) {
    if(this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

template <class T>
LList<T>::LList(const LList& other) {
    this->copy(other);
}

template <class T>
LList<T>::LList() {
    first = nullptr;
}

template <class T>
void LList<T>::push_back(const T& element) {
    if (first == nullptr) {
        first = new Node{element, nullptr};
        return;
    }

    Node* crr = first;
    while(crr->next != nullptr) {
        crr = crr->next;
    }
    crr->next = new Node{element, nullptr};
}

template <class T>
void LList<T>::print() const {
    Node* crr = first;
    while(crr != nullptr) {
        std::cout << crr->data << " ";
        crr = crr->next;
    }
    std::cout << "\n";
}