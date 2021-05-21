#include "../tests/doctest/doctest.h"
#include "cuboid.hpp"


TEST_CASE("Test konstruktorów bezparametrycznych")
{
    Cuboid Prostopadloscian = Cuboid();

    Cuboid test;

    test[0] = Vector<double, SIZE>(2, 3, 3);
    test[1] = Vector<double, SIZE>(22, 3, 3);
    test[2] = Vector<double, SIZE>(2, 18, 3);
    test[3] = Vector<double, SIZE>(22, 18, 3);
    test[4] = Vector<double, SIZE>(2, 18, 28);
    test[5] = Vector<double, SIZE>(22, 18, 28);
    test[6] = Vector<double, SIZE>(2, 3, 28);
    test[7] = Vector<double, SIZE>(22, 3, 28);

    CHECK(Prostopadloscian == test);
}

TEST_CASE("Test konstruktorów parametrycznych")
{

    

    Vector<double, SIZE> uno(2, 3, 3);
    Vector<double, SIZE> due(22, 3, 3);
    Vector<double, SIZE> rike(2, 18, 3);
    Vector<double, SIZE> faka(22, 18, 3);
    Vector<double, SIZE> maka(2, 18, 28);
    Vector<double, SIZE> paka(22, 18, 28);
    Vector<double, SIZE> fa(2, 3, 28);
    Vector<double, SIZE> fax2(22, 3, 28);

    Cuboid prostopadloscian = Cuboid();

    Cuboid test;

    test[0] = uno;
    test[1] = due;
    test[2] = rike;
    test[3] = faka;
    test[4] = maka;
    test[5] = paka;
    test[6] = fa;
    test[7] = fax2;

    CHECK(prostopadloscian == test);
}

TEST_CASE("Test translacji Prostopadloscianu")
{
    Vector<double, SIZE> wektor1(0, 5, 5);
    Vector<double, SIZE> wektor2(10, 5, 5);
    Vector<double, SIZE> wektor3(0, 20, 5);
    Vector<double, SIZE> wektor4(10, 20, 5);
    Vector<double, SIZE> wektor5(0, 20, 30);
    Vector<double, SIZE> wektor6(10, 20, 30);
    Vector<double, SIZE> wektor7(0, 5, 30);
    Vector<double, SIZE> wektor8(10, 5, 30);


    Cuboid Cuboid_test = Cuboid(wektor1, wektor2, wektor3, wektor4, wektor5, wektor6, wektor7, wektor8);
    Vector<double, SIZE> Przesuniecie_test(5, 5, 5);

    Cuboid_test.Kicking_Cuboid(Przesuniecie_test);

    Vector<double, SIZE> wynik_wektor1(5, 10, 10);
    Vector<double, SIZE> wynik_wektor2(15, 10, 10);
    Vector<double, SIZE> wynik_wektor3(5, 25, 10);
    Vector<double, SIZE> wynik_wektor4(15, 25, 10);
    Vector<double, SIZE> wynik_wektor5(5, 25, 35);
    Vector<double, SIZE> wynik_wektor6(15, 25, 35);
    Vector<double, SIZE> wynik_wektor7(5, 10, 35);
    Vector<double, SIZE> wynik_wektor8(15, 10, 35);

    Cuboid Cuboid_wynik = Cuboid(wynik_wektor1, wynik_wektor2, wynik_wektor3, wynik_wektor4, wynik_wektor5, wynik_wektor6, wynik_wektor7, wynik_wektor8);

    CHECK(Cuboid_test == Cuboid_wynik);
}


TEST_CASE("Test obrotu Prostopadloscianu ale o macierz jedynkową. Brakuje troszke czasu, wystarczyłoby zrobić konstruktory do zmiany axis i degrees ale ehh straszna sieczka jest z materiałem...")
{
    Vector<double, SIZE> wektor1(0, 5, 5);
    Vector<double, SIZE> wektor2(10, 5, 5);
    Vector<double, SIZE> wektor3(0, 20, 5);
    Vector<double, SIZE> wektor4(10, 20, 5);
    Vector<double, SIZE> wektor5(0, 20, 30);
    Vector<double, SIZE> wektor6(10, 20, 30);
    Vector<double, SIZE> wektor7(0, 5, 30);
    Vector<double, SIZE> wektor8(10, 5, 30);


    Cuboid Cuboid_test = Cuboid(wektor1, wektor2, wektor3, wektor4, wektor5, wektor6, wektor7, wektor8);
    Matrix<double, SIZE> Miotator;

    Cuboid_test.throwing_Cuboid(Miotator);

    Vector<double, SIZE> wynik_wektor1(0, 5, 5);
    Vector<double, SIZE> wynik_wektor2(10, 5, 5);
    Vector<double, SIZE> wynik_wektor3(0, 20, 5);
    Vector<double, SIZE> wynik_wektor4(10, 20, 5);
    Vector<double, SIZE> wynik_wektor5(0, 20, 30);
    Vector<double, SIZE> wynik_wektor6(10, 20, 30);
    Vector<double, SIZE> wynik_wektor7(0, 5, 30);
    Vector<double, SIZE> wynik_wektor8(10, 5, 30);

    Cuboid Cuboid_wynik(wynik_wektor1, wynik_wektor2, wynik_wektor3, wynik_wektor4, wynik_wektor5, wynik_wektor6, wynik_wektor7, wynik_wektor8);

    CHECK(Cuboid_test == Cuboid_wynik);
}

TEST_CASE("Test Operatora Porównywania z zbyt małym błędem")
{
    Cuboid prostopadloscian;
    Cuboid test;

    test[0] = Vector<double, SIZE>(2.00000001, 3.00000001, 3.00000001);
    test[1] = Vector<double, SIZE>(22.00000001, 3, 3);
    test[2] = Vector<double, SIZE>(2.00000001, 18.00000001, 3);
    test[3] = Vector<double, SIZE>(22.00000001, 18.00000001, 3.00000001);
    test[4] = Vector<double, SIZE>(2.00000001, 18, 28);
    test[5] = Vector<double, SIZE>(22.00000001, 18.00000001, 28);
    test[6] = Vector<double, SIZE>(2.00000001, 3, 28.00000001);
    test[7] = Vector<double, SIZE>(22.00000001, 3, 28.00000001);


    CHECK(prostopadloscian == test);
}

TEST_CASE("Test Operatora Porównywania ze zbyt dużym błędem")
{
    Cuboid prostopadloscian;
    Cuboid test;

    test[0] = Vector<double, SIZE>(2.000001, 3.000001, 3);
    test[1] = Vector<double, SIZE>(22.00000001, 3, 3);
    test[2] = Vector<double, SIZE>(2.000001, 18.00000001, 3);
    test[3] = Vector<double, SIZE>(22.000001, 18.000001, 3.000001);
    test[4] = Vector<double, SIZE>(2.000001, 18, 28);
    test[5] = Vector<double, SIZE>(22.000001, 18.00000001, 28);
    test[6] = Vector<double, SIZE>(2.000001, 3, 28.00000001);
    test[7] = Vector<double, SIZE>(22.000001, 3, 28.000001);


    CHECK(!(prostopadloscian == test));
}


TEST_CASE("Test operatora []")
{
    Cuboid prostopadloscian;
    std::ostringstream Strumien_out;

    Strumien_out << prostopadloscian.operator[](0);


    CHECK("[ 2 ] [ 3 ] [ 3 ] " == Strumien_out.str());
}