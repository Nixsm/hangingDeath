#ifndef STATIC_LIST_TEMPLATE_H
#define STATIC_LIST_TEMPLATE_H

#define LIST_SIZE 100

#include <ostream>
#include <stdexcept>


namespace de{

    /*
     * Indexes are logical i.e. 1 is 1
     */
    template<class T> class List{
    public:
        bool isEmpty();
        bool isFull();
        
        unsigned int size();
        
        bool contains(T const& element);
        
        bool isValid(const unsigned int& index);
        
        T at(const unsigned int& index);
        
        unsigned int getIndex(T const& element);
        
        void insert(T const& element, const unsigned int index);
        
        void remove(T const& element);
        
        T operator[](const unsigned int& index);
        
        friend std::ostream& operator<<(std::ostream& os, const List<T>& list){
            for(auto i = 0; i < list._size; ++i){
                os << list._list[i] << " ";
            }
            
            return os;
        }
        
        List<T> operator=(const List<T>& other);
        
        static void sort(List<T>& list);
        
    private:
        unsigned int _size = 0;
        T _list[LIST_SIZE];
    };
    
}



#endif//STATIC_LIST_TEMPLATE_H
