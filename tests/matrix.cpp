#include "../tests/doctest/doctest.h"
#include "matrix.hpp"

// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

TEST_CASE("Test konstruktorów bezparametrycznych")
{
    Matrix<double, 3> macierz = Matrix<double, 3>();

    Matrix<double, 3> test;

    test(0, 0) = 1;
    test(0, 1) = 0;
    test(0, 2) = 0;
    test(1, 0) = 0;
    test(1, 1) = 1;
    test(1, 2) = 0;
    test(2, 0) = 0;
    test(2, 1) = 0;
    test(2, 2) = 1;

    CHECK(macierz == test);
}

TEST_CASE("Test konstruktorów parametrycznych")
{
    double tmp[SIZE][SIZE];
    tmp[0][0] = 1;
    tmp[0][1] = 2;
    tmp[0][2] = 3;
    tmp[1][0] = 4;
    tmp[1][1] = 1;
    tmp[1][2] = 2;
    tmp[2][0] = 3;
    tmp[2][1] = 4;
    tmp[2][2] = 4;

    Matrix<double, 3> macierz = Matrix<double, 3>(tmp);

    Matrix<double, 3> test;


    test(0, 0) = 1;
    test(0, 1) = 2;
    test(0, 2) = 3;
    test(1, 0) = 4;
    test(1, 1) = 1;
    test(1, 2) = 2;
    test(2, 0) = 3;
    test(2, 1) = 4;
    test(2, 2) = 4;

    CHECK(macierz == test);
}

TEST_CASE("Test przeciążenia mnożenia MACIERZ * WEKTOR")
{


    Matrix<double, 3> macierz;
    Vector<double, 3> wektor(1, 3, 1);
    Vector<double, 3> test;
    Vector<double, 3> Wynik(10, 3, 19);

    macierz(0, 0) = 1;
    macierz(0, 1) = 2;
    macierz(0, 2) = 3;
    macierz(1, 0) = 0;
    macierz(1, 1) = 1;
    macierz(1, 2) = 0;
    macierz(2, 0) = 3;
    macierz(2, 1) = 4;
    macierz(2, 2) = 4;

    test = macierz * wektor;

    CHECK(Wynik == test);
}

TEST_CASE("Test miotania osi x")
{

    int kat = 90;
    Matrix<double, 3> macierz;
    Matrix<double, 3> test;

    macierz(0, 0) = 1;
    macierz(0, 1) = 1;
    macierz(0, 2) = 1;
    macierz(1, 0) = 1;
    macierz(1, 1) = 1;
    macierz(1, 2) = 1;
    macierz(2, 0) = 1;
    macierz(2, 1) = 1;
    macierz(2, 2) = 1;

    macierz.obrot_x(kat);

    test(0, 0) = 0;
    test(0, 1) = -1;
    test(0, 2) = 0;
    test(1, 0) = 1;
    test(1, 1) = 0;
    test(1, 2) = 0;
    test(2, 0) = 0;
    test(2, 1) = 0;
    test(2, 2) = 1;

    CHECK(macierz == test);
}


TEST_CASE("Test operatora []")
{
    Matrix<double, 3> macierz = Matrix<double, 3>();
    std::ostringstream Strumien_out;

    Strumien_out << macierz.operator[](0);


    CHECK("1" == Strumien_out.str());
}

TEST_CASE("Test operatora ()")
{
    Matrix<double, 3> macierz = Matrix<double, 3>();
    std::ostringstream Strumien_out;

    Strumien_out << macierz(1, 1);

    CHECK("1" == Strumien_out.str());
}

