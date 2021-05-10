#pragma once
#include "vector.hpp"

template<typename T, int SIZE>
Vector<T, SIZE>::Vector(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template<typename T, int SIZE>
Vector<T, SIZE>::Vector(T [SIZE]){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template<typename T, int SIZE>
Vector<T, SIZE>::Vector(T x, T y ){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}



template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator - (const Vector &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator / (const T &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template<typename T, int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (Matrix &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T,int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (const T &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T,int SIZE>
bool Vector<T, SIZE>::operator == (const Vector &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T,int SIZE>
const T &Vector<T, SIZE>::operator [] (int index) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}


template <typename T,int SIZE>
T &Vector<T, SIZE>::operator [] (int index){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T,int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::loadtofile(Vector &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template <typename T,int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::display(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template <typename T,int SIZE>
void Vector<T, SIZE>::Load_vector(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}