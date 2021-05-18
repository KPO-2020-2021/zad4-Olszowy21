#pragma once

#include "matrix.hpp"

class Cuboid{

    Vector<double, SIZE> top[SIZE+5];

public:

// Konstruktory 

  Cuboid();

  Cuboid(Vector<double, SIZE> first, Vector<double, SIZE> second, Vector<double, SIZE> third, Vector<double, SIZE> fourth,
         Vector<double, SIZE> fifth, Vector<double, SIZE> sixth,  Vector<double, SIZE> seventh, Vector<double, SIZE> eigth );

// Metody

  void throwing_Cuboid(const Matrix<double, SIZE> &tmp);

  void length_of_the_sides();

  void Kicking_Cuboid(const Vector<double, SIZE> &tmp);

  void ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy);

  bool ZapisWspolrzednychDoPliku( const char *File_name);

  const Vector<double, SIZE> &operator [] (unsigned int index) const;

  Vector<double, SIZE> &operator [] (unsigned int index);

  bool operator == (const Cuboid &tmp) const;

};

std::ostream &operator << (std::ostream &out, Cuboid const &tmp);

template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &out, Vector<double, SIZE> const &tmp);

