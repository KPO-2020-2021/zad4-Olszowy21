#pragma once

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cmath>
#include "size.hpp"
#include <math.h>
#include <string>
#include <sstream>

#define MIN_DIFF 0.0000001


template<typename T, unsigned int SIZE>
class Vector{
    
    T size[SIZE];     //Tablica wektora

public:
    
// Konstruktory

    Vector();

    Vector(T tmp[SIZE]);

    Vector(T x, T y, T z );

// Metody

    Vector operator + (const Vector &tmp);

    Vector operator - (const Vector &tmp);

    Vector operator * (const T &tmp);

    // Vector operator * (Vector tmp);

    bool operator == (const Vector &tmp) const;

    const T &operator [] (unsigned int index) const;

    T &operator [] (unsigned int index);
    
    void Load_vector(); 
};

template <typename T, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<T, SIZE> &tmp);

template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &out, Vector<T, SIZE> const &tmp);

template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &out, Vector<T, SIZE> const &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ] ";
    }
    return out;
}

template <typename T, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<T, SIZE> &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }

    return in;
}


template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(){
    for (unsigned int i = 0; i < SIZE; ++i){
        this->size[i] = T();
    }
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T tmp[SIZE]){
    for (unsigned int i = 0; i < SIZE; ++i) {
        this->size[i] = tmp[i];
    }   
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T x, T y, T z ){
    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;
}



template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator - (const Vector &tmp){
    Vector<T, SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= tmp[i];
    }
    return result;
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector &tmp){
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += tmp[i];
    }
    return result;
}

template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (const T &tmp){
    Vector<T, SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}

template <typename T, unsigned int SIZE>
bool Vector<T, SIZE>::operator == (const Vector &tmp) const{
    if((std::abs(this->size[0] - tmp.size[0]) <= MIN_DIFF ) && (std::abs(this->size[1] - tmp.size[1]) <= MIN_DIFF ) && (std::abs(this->size[2] - tmp.size[2]) <= MIN_DIFF )){
        return true;
    }
    return false;
}

template <typename T, unsigned int SIZE>
const T &Vector<T, SIZE>::operator [] (unsigned int index) const{
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


template <typename T, unsigned int SIZE>
T &Vector<T, SIZE>::operator [] (unsigned int index){
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


template <typename T, unsigned int SIZE>
void Vector<T, SIZE>::Load_vector(){

    T x,y,z;
    std::cout<<"Proszę podać wektor przesunięcia przykład: 10 2 3 <---> x y z"<<std::endl;
    std::cin>>x;
    std::cin>>y;
    std::cin>>z;

    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;
}   