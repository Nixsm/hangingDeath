#ifndef DYNAMIC_LIST_TEMPLATE_IMPL_H
#define DYNAMIC_LIST_TEMPLATE_IMPL_H

#include "dynamic_list_template.h"

namespace de {
    template<class T> bool List<T>::isEmpty() const {
        return (_size == 0);
    }
    
    template<class T> unsigned int List<T>::size() const {
        return _size;
    }

    template<class T> bool List<T>::elementExists(const T& element) const {
        Node<T>* begin = _begin;
        
        while (Node<T>* node = begin) {
            if (node->value == element) {
                return true;
            }
            
            begin = node->next;
        }
        
        return false;
    }
    
    template<class T> bool List<T>::posExists(const unsigned int& index) const {
        return ((index >= 1) && (index <= _size));
    }
    
    template<class T> T List<T>::at(const unsigned int& index) const {
        Node<T>* begin = _begin;
        
        T returnValue;
        unsigned int cont = 1;
        while (Node<T>* node = begin) {
            if (cont == index) {
                returnValue = node->value;
                break;
            }
            cont++;
            begin = node->next;
        }
        return returnValue;
    }
    
    template<class T> unsigned int List<T>::getIndex(const T& element) const {
        Node<T>* begin = _begin;
        
        unsigned int cont = 1;
        while (Node<T>* node = begin) {
            if (node->value == element) {
                return cont;
            }
            cont++;
            
            begin = node->next;
        }
        
        return unsigned(-1);
    }
    
    template<class T> void List<T>::insert(const T& element, const unsigned int& index){
        
        Node<T>* begin = _begin; /* Copy the beginning pointer so we dont lost it*/
        unsigned int cont = 1; /* We want to find the next index after the @param index */
        Node<T>* next = nullptr;
        Node<T>* previous = nullptr;
        while ((next = begin)){
            /* Check if index is the index we want */
            if (cont++ == index) {
                break; /* We've found our insertion index */
                /* node should be holding */
            }
            
            begin = next->next;
            previous = next;
        }
        
        Node<T>* newNode = new Node<T>;
        newNode->value = element;
        newNode->next = nullptr;
        
        /* Check if we are not dealing with the first element */
        if (previous) {
            previous->next = newNode;
        }else{
            _begin = newNode;
        }
        newNode->next = next;
        
        _size++;
    }
    
    template<class T> void List<T>::remove(const unsigned int& index){
        Node<T>* begin = _begin;
        
        unsigned int cont = 1;
        Node<T>* iteration = nullptr;
        Node<T>* before = nullptr;
        while((iteration = begin)){
            if (cont++ == index) {
                break;
            }
            before = iteration;
            begin = iteration->next;
            
        }
        
        if (!before) { /* Our element is the first one */
            delete _begin;
            _begin = iteration->next;
        }else{
            Node<T>* toBeDeleted = before->next;
            Node<T>* toBeConnected = toBeDeleted->next;
            
            before->next = toBeConnected;
            
            delete toBeDeleted;
        }
        
        _size--;
    }
    
    
    template<class T> List<T>& List<T>::operator=(const List<T>& other){
        this->~List();
        
        Node<T>* begin = other._begin;
        unsigned int cont = 1;
        while (Node<T>* node = begin) {
            insert(node->value, cont++);
            
            begin = node->next;
        }
        
        return *this;
        
    }
    
    template<class T> void List<T>::reverse(){
        unsigned int listSize = _size;
        const unsigned int listSize2 = listSize/2;
                
        for(auto i = 1; i <= listSize2; ++i){
            const T temp = at(i);
            remove(i);
            
            const T temp2 = at(_size + 1 - i);
            
            remove(_size + 1 - i);
            insert(temp2, i);
            insert(temp, _size + 2 - i); // + 2 because we start at 1 and not zero
        }
    }
    
    template<class T> void List<T>::split(List<T>& out1, List<T>& out2, const T& needle) const {
        Node<T>* begin = _begin;
        
        const unsigned int needleIndex = getIndex(needle);
        
        unsigned int cont = 1;
        while (Node<T>* node = begin) {
            if (cont < needleIndex) {
                out1.insert(node->value, cont);
                cont++;
            }else if(cont == needleIndex){
                cont++;
            }else if(cont <= _size){
                out2.insert(node->value, cont - needleIndex);
                cont++;
            }
            
            begin = node->next;
        }
    }
    
    template<class T> void List<T>::insertOrdered(const T& value, const bool& reverse){
        Node<T>* begin = _begin;
        
        unsigned int cont = 1;
        
        while (Node<T>* node = begin) {
            if (value < node->value && !reverse) {
                break;
            }else if (value > node->value && reverse){
                break;
            }
            cont++;
            begin = node->next;
        }
                
        insert(value, cont);
    }
    
    template<class T> void List<T>::findOccurences(List<unsigned int>& out, const T& element) const {
        Node<T>* begin = _begin;
        
        unsigned int cont = 1;
        int i = 1;
        
        while (Node<T>* node = begin) {
            if (element == node->value) {
                out.insert(i, cont++);
            }
            i++;
            begin = node->next;
        }
    }
    
    template<class T> T& List<T>::operator[](const unsigned int& index){
        Node<T>* begin = _begin;
        
        unsigned int cont = 1;
                
        while (Node<T>* node = begin){
            if (cont++ == index){
                return node->value;
                break;
            }
            begin = node->next;
        }
    }

}

#endif//DYNAMIC_LIST_TEMPLATE_IMPL_H