#pragma once

#include <iomanip>
#include <fstream>
#include "size.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#define MIN_DIFF 0.000001

class Matrix;

template<typename T, int SIZE>
class Vector{
    
    T size[SIZE];     //Tablica wektora

public:
    
// Konstruktory

    Vector();

    Vector(T [SIZE]);

    Vector(T x, T y );

// Metody

    Vector operator + (const Vector &tmp);

    Vector operator - (const Vector &tmp);

    Vector operator * (const T &tmp);

    Vector operator / (const T &tmp);

    Vector operator * (Matrix &tmp);

    bool operator == (const Vector &tmp) const;

    const T &operator [] (int index) const;

    T &operator [] (int index);

    Vector loadtofile(Vector &tmp);

    Vector display();
    
    void Load_vector(); 
};
