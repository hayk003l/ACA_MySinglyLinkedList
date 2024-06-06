#ifndef __LIST__
#define __LIST__
#include <iostream>
#include <stack>

namespace myStl {
    template <typename T>
    struct Node {
            T data;
            Node<T>* next;
    };
    
    template <typename T>
    class List {
    private:
        Node<T>* _head = nullptr;
    public:
        List() : _head(nullptr) {}
        ~List() {
            Node<T>* tmp = _head;
            while (tmp != nullptr) {
                Node<T>* ptr = tmp -> next;
                delete tmp;
                tmp = ptr;
            }
            
        }
    public:
        void push_front(const T& data) {
            Node<T>* temp = new Node<T>;
            temp->data = data;
            temp->next = _head;
            _head = temp;
        } 

        void pop_front() {
            Node<T>* tmp = _head;
            if (tmp != nullptr) {
                tmp = tmp -> next;
                delete _head;
                _head = tmp;
            }
            else {
                std::cout << "Error. You don't have elements to pop." << std::endl;
            }
        }

        void push_back(const T& data) {
            Node<T>* newNode = new Node<T>;
            newNode->data = data;
            newNode->next = nullptr;
            if(_head == nullptr) {
                _head = newNode;
            }
            else {
                Node<T>* temp = _head;
                Node<T>* prevTemp = nullptr;
                while (temp != nullptr) {
                    prevTemp = temp;
                    temp = temp -> next;
                }   
                prevTemp -> next = newNode;
            }
        }

        void pop_back() {
            Node<T>* tmp = _head;
            Node<T>* prevTmp = nullptr;
            while (tmp != nullptr) {
                prevTmp = tmp;
                tmp = tmp -> next;
            }
            delete prevTmp;
            
        }

        void insert(const T& data, const int& pos) {
            if (pos == 0) {
                push_front(data);
                return;
            }
            Node<T>* newNode = new Node<T>;
            newNode -> data = data;
            
            Node<T>* tmp = _head;
            int curr = 0;
            while (tmp != nullptr && curr < pos - 1) {
                tmp = tmp -> next;
                ++curr;
            }
            if (tmp == nullptr) {
                std::cout << "Error. Wrong position." << std::endl;
                delete newNode;
                return;
            }
            newNode->next = tmp -> next;
             tmp->next = newNode;
        }
        
        Node<T>* findLastNth(const int& n) {
            Node<T>* ptrOne = _head;
            Node<T>* ptrTwo = _head;

            for (int i = 0; i < n; ++i) {
                if (ptrOne == nullptr) {
                    return ptrOne;
                }
                ptrOne = ptrOne -> next;
            }

            while (ptrOne != nullptr) {
                ptrTwo = ptrTwo -> next;
                ptrOne = ptrOne -> next;
            }
            return ptrTwo;
        }

        void display() {
            Node<T>* tmp = _head;
            while (tmp != nullptr) {
                std::cout << tmp -> data << std::endl;
                tmp = tmp -> next;
            }
        }
        
        void swapList() {
            if (!_head) {
                return;
            }
            std::stack<T> stackCont;
            Node<T>* tmp = _head;
            while (tmp != nullptr) {
                stackCont.push(tmp -> data);
                tmp = tmp -> next;
            }
            tmp = _head;
            while (tmp != nullptr) {
                tmp -> data = stackCont.top();
                stackCont.pop();
                tmp = tmp -> next;
            }
        }

        bool detectLoop() {
            Node<T>* fastPtr = _head;
            Node<T>* slowPtr = _head;

            while(slowPtr != nullptr && fastPtr != nullptr && fastPtr -> next != nullptr) {
                slowPtr = slowPtr -> next;
                fastPtr = fastPtr -> next -> next;
                if (slowPtr == fastPtr) {
                    return false;
                }
            }
            return true;
        };
        void makeLoop() {
            Node<T>* tmp = _head;
            Node<T>* prevTemp = nullptr;
            while (tmp != nullptr) {
                prevTemp = tmp;
                tmp = tmp -> next;
            }
            prevTemp -> next = _head;
        }
    };
    
    template <typename T>
    void printNode(Node<T>* node) {
        std::cout << node -> data << std::endl;
    }

};

#endif // __LIST__