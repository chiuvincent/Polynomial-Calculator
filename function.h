#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

using namespace std;

template <typename T>
T* allocate(int capacity){
    T* ar = new T[capacity];
    //fill empty spaces with 0
    T* walker = ar;
    for(int i=0; i<capacity; i++){
        *walker = 0;
        walker++;
    }
    return ar;
    //return new T[capacity];
}

template <typename T>
void copy_list(T* remix, T* original, int size){
    for(int i=0; i<size; i++){
        *remix = *original; //copies over
        remix++; //increments walker
        original++;
    }
}

template <typename T>
T* reallocate(T* ptr, int& size, int cap){
    T* ptr2 = allocate<T>(cap);
    copy_list(ptr2, ptr, size);
    delete[] ptr;//delete original pointer
    size = cap; //only useful for POLY project
    return ptr2;
}

//template <typename T>
//T* shift_right(T* ptr, int& size){
//    size++;
//    T* ptr2 = allocate<T>(size); //creates a new array of 1 size greater
//    *ptr2 = 0; //set first item to 0
//    T* walker = ptr2;
//    T* stay = ptr; //this gets delete later
//    for(int i=1; i<size; i++){ //shifts entire array right
//        walker++;
//        *walker = *ptr;
//        ptr++;
//    }
//    delete[] stay; //gets rid of original space
//    return ptr2;
//}

template <typename T>
void print_array(T* ptr, int size){
    for(int i=0; i<size; i++){
        cout<<" + "<<*ptr<<"x^"<<i;
        ptr++;
    }
}
#endif // FUNCTION_H
