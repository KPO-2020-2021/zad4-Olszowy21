#include "../tests/doctest/doctest.h"
#include "cuboid.hpp"


TEST_CASE("Test konstruktorów bezparametrycznych")
{
    Cuboid macierz = Cuboid();

    Cuboid test;

    test[0] = Vector<double, SIZE>(2, 3, 3);
    test[1] = Vector<double, SIZE>(22, 3, 3);
    test[2] = Vector<double, SIZE>(2, 18, 3);
    test[3] = Vector<double, SIZE>(22, 18, 3);
    test[4] = Vector<double, SIZE>(2, 18, 28);
    test[5] = Vector<double, SIZE>(22, 18, 28);
    test[6] = Vector<double, SIZE>(2, 3, 28);
    test[7] = Vector<double, SIZE>(22, 3, 28);

    CHECK(macierz == test);
}

TEST_CASE("Test konstruktorów parametrycznych")
{

    Vector<double, SIZE> uno;





    Cuboid macierz = Cuboid();

    Cuboid test;

    test[0] = Vector<double, SIZE>(2, 3, 3);
    test[1] = Vector<double, SIZE>(22, 3, 3);
    test[2] = Vector<double, SIZE>(2, 18, 3);
    test[3] = Vector<double, SIZE>(22, 18, 3);
    test[4] = Vector<double, SIZE>(2, 18, 28);
    test[5] = Vector<double, SIZE>(22, 18, 28);
    test[6] = Vector<double, SIZE>(2, 3, 28);
    test[7] = Vector<double, SIZE>(22, 3, 28);

    CHECK(macierz == test);
}