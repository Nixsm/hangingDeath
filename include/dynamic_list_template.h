#ifndef DYNAMIC_LIST_TEMPLATE_H
#define DYNAMIC_LIST_TEMPLATE_H

#include <iostream>

namespace de {
    
    template<class T> struct Node{
        Node* next;
        T value;
    };
    
    template<class T> class List {
    public:
        List() {
            _begin = nullptr;
            _size = 0;
        }
        
        List(const List<T>& list)
        :_size(0), _begin(nullptr)
        {
            Node<T>* begin = list._begin;
            
            unsigned int cont = 1;
            while (Node<T>* node = begin) {
                insert(node->value, cont++);
                
                begin = node->next;
            }
        }
        ~List() {
            Node<T>* node;
            while (_begin != nullptr) {
                node = _begin;
                _begin = _begin->next;

                delete node;
            }
            
            _size = 0;
            
        };

        bool isEmpty() const;
        
        unsigned int size() const;
        
        bool elementExists(const T& element) const;
        
        bool posExists(const unsigned int& index) const;
        
        T at(const unsigned int& index) const;
        
        unsigned int getIndex(const T& element) const;
        
        void insert(const T& element, const unsigned int& index);
        
        void remove(const unsigned int& index);
        
        friend std::ostream& operator<<(std::ostream& os, const List<T>& list){
            Node<T>* begin = list._begin;
            
            while (Node<T>* node = begin) {
                os << node->value << " ";
                begin = node->next;
            }
            
            return os;
        }
        
        List<T>& operator=(const List<T>& other);
        
        void reverse();
        
        void split(List<T>& out1, List<T>& out2, const T& needle) const;
        
        void insertOrdered(const T& value, const bool& reverse = false);
        
        void findOccurences(List<unsigned int>& out, const T& element) const;
        
        T& operator[](const unsigned int& index);
        
    private:
        unsigned int _size = 0;
        Node<T>* _begin = nullptr;
    };
}


#endif//DYNAMIC_LIST_TEMPLATE_H