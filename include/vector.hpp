#pragma once

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>

#include "size.hpp"
#include "vector.hpp"
#define MIN_DIFF 0.000001

template< typename T = double, int SIZE = 3 >
class Matrix;



template<typename T = double, unsigned int SIZE = 3>
class Vector{
    
    T size[SIZE];     //Tablica wektora

public:
    
// Konstruktory

    Vector();

    Vector(T [SIZE]);

    Vector(T x, T y );

// Metody

    Vector operator + (const Vector &tmp) const;

    Vector operator - (const Vector &tmp) const;

    Vector operator * (const T &tmp) const;

    Vector operator / (const T &tmp) const;

    Vector operator * (Matrix &tmp) const;

    Vector operator * (Vector tmp) const;

    bool operator == (const Vector &tmp) const;

    const T &operator [] (int index) const;

    T &operator [] (int index);

    Vector loadtofile(Vector &tmp);

    Vector display();
    
    void Load_vector(); 
};
    
template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &Strm, Vector<T, SIZE> const &Wek);


template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &Strm, Vector<T, SIZE> const &Wek)
{
    for(int i=0; i<SIZE; ++i) //Petla wyswietlajaca zawartosc wszystkich komorek danego obiektu
    {
        Strm << Wek.daj(i) << "  "; //Metoda zwracajaca atrybuty klasy 'Wektor'
    }
    return Strm;
}


template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T [SIZE]){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T x, T y ){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}



template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator - (const Vector &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator / (const T &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (const T &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T, unsigned int SIZE>
bool Vector<T, SIZE>::operator == (const Vector &tmp) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T, unsigned int SIZE>
const T &Vector<T, SIZE>::operator [] (int index) const{
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}


template <typename T, unsigned int SIZE>
T &Vector<T, SIZE>::operator [] (int index){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;
}

template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::loadtofile(Vector &tmp){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::display(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}

template <typename T, unsigned int SIZE>
void Vector<T, SIZE>::Load_vector(){
    static_assert(SIZE == 3, "Cross product does not defined");
    return *this;    
}