#include "../tests/doctest/doctest.h"
#include "vector.hpp"

TEST_CASE("Konstruktor bezparametryczny vectora")
{
    Vector<double, 3> xD = Vector<double, 3>();

    Vector<double, 3> test;

    test[0] = 0;
    test[1] = 0;
    test[2] = 0;

    CHECK(xD == test);
}

TEST_CASE("Konstruktor parametryczny vectora")
{
    Vector<double, 3> xD(3, 3.14, 666);

    Vector<double, 3> test;

    test[0] = 3;
    test[1] = 3.14;
    test[2] = 666;

    CHECK(xD == test);
}


TEST_CASE("Test Operatora Odejmowania")
{
    Vector<double, 3> wektor1(16, 32, 10);

    Vector<double, 3> wektor2(-10, 30, 5);

    Vector<double, 3> Wynik = wektor1 - wektor2;

    Vector<double, 3> test(26, 2, 5);


    CHECK(Wynik == test);
}

TEST_CASE("Test Operatora Dodawania")
{
    Vector<double, 3> wektor1(16.5, 32, 12);

    Vector<double, 3> wektor2(10.5, 30, 1);

    Vector<double, 3> Wynik = wektor1 + wektor2;

    Vector<double, 3> test(27, 62, 13);


    CHECK(Wynik == test);
}

TEST_CASE("Test Operatora Porównywania z zbyt małym błędem")
{
    Vector<double, 3> wektor1(1.0000001, 32.10030022, 0.00322223);

    Vector<double, 3> wektor2(1.0000002, 32.10030021, 0.00322223);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("Test Operatora Porównywania z zbyt dużym błędem")
{
    Vector<double, 3> wektor1(1.000031, 32.000023, 0322221);

    Vector<double, 3> wektor2(1.000035, 32.000025, 0322224);

    CHECK(!(wektor1 == wektor2));
}

TEST_CASE("Test Wyswietlania wektora") {
    
    Vector<double, 3> wektor1(2, 2, 3);

    std::ostringstream Strumien;

    Strumien << wektor1;
 
   CHECK(Strumien.str() == "[ 2 ] [ 2 ] [ 3 ] ");
}   



TEST_CASE("Test wczytywania wektora do strumienia")
{
    Vector<double, 3> wektor1;
    std::ostringstream Strumien_out;
    std::istringstream Strumien_in("-20 2.555 13 ");

    Strumien_in >> wektor1;

    Strumien_out << wektor1;

    CHECK("[ -20 ] [ 2.555 ] [ 13 ] " == Strumien_out.str());
}

TEST_CASE("Test operatora []")
{
    Vector<double, 3> wektor1(1, 1, 1);
    std::ostringstream Strumien_out;

    Strumien_out << wektor1.operator[](0);


    CHECK("1" == Strumien_out.str());
}
