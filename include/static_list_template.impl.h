//#ifndef STATIC_LIST_TEMPLATE_H
//#error Do not include this before static_list_template_h
//#endif

#include "include/static_list_template.h"

namespace de {
    template<class T> bool List<T>::isEmpty(){
        return !_size; // if _size is zero, the result of a not will return true
    }
    
    template<class T> bool List<T>::isFull(){
        return _size == LIST_SIZE;
    }
    
    template<class T> unsigned int List<T>::size(){
        return _size;
    }
    
    template<class T> bool List<T>::isValid(const unsigned int& index){
        return index - 1 < LIST_SIZE;
    }
    
    template<class T> T List<T>::at(const unsigned int& index){
        return _list[index - 1];
    }

    template<class T> unsigned int List<T>::getIndex(T const& element){
        for(auto i = 0; i < LIST_SIZE; ++i){
            if(element == _list[i])
                return i;
        }
    }
    
    template<class T> T List<T>::operator[](const unsigned int& index){
        return _list[index - 1];
    }

    template<class T> void List<T>::insert(T const& element, const unsigned int index){
        for(auto i = _size; i > index - 1; --i){
            _list[i] = _list[i - 1];
        }
        _list[index - 1] = element;
        ++_size;
    }

    template<class T> void List<T>::remove(T const& element){
        const unsigned int index = getIndex(element);

        for(auto i = index - 1; i < _size; ++i){
            _list[i] = _list[i + 1];
        }

        --_size;
    }

    template<class T> List<T> List<T>::operator=(const List<T>& other){
        List<T> newList(_size);
        for(auto i = 0; i < _size; ++i){
            newList.insert(_list[i], i);
        }

        return newList;
    }

    template<class T> void List<T>::sort(List<T>& list){
        for (auto j = 1; j < list._size; ++j){
            const T item = list._list[j];

            int i = j - 1;
            while (i > -1 && list._list[i] > item){
                list._list[i + 1] = list._list[i];
                --i;
            }

            list._list[i + 1] = item;
        }
    }

    
}
