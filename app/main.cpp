// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <fstream>
#include "exampleConfig.h"
#include "cuboid.hpp"
#include "matrix3d.hpp"
#include "vector3d.hpp"
#include "lacze_do_gnuplota.hh"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * 
 */


int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;

       std::string File_name = "../datasets/cuboid.dat";
       const char* WSK_FILE = File_name.c_str();
       std::ofstream FILE;
       Cuboid cuboid = Cuboid();
       Vector3D Przesuniecie = Vector3D();
       Matrix3D macierz;
       PzG::LaczeDoGNUPlota  Lacze;       // Ta zmienna jest potrzebna do wizualizacji
                                          // rysunku prostokata

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Ciagly,2);
       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       Lacze.DodajNazwePliku("../datasets/cuboid.dat",PzG::RR_Punktowy,2);
       //
       //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //
       Lacze.ZmienTrybRys(PzG::TR_3D);


       if (!cuboid.ZapisWspolrzednychDoPliku( WSK_FILE )) { return 1; }

  while(1){

       char x;

       std::cout<<"\nWybieram : ( m - menu ) > ";
       std::cin>>x;
       std::cout << std::endl;
       switch (x){
       case 'm':
              std::cout<<"\n\t**********************MENU***********************"<<std::endl;
              std::cout<<"\to - obrot bryly o zadana sekwencje katow"<<std::endl;
              std::cout<<"\tt - powtorzenie poprzedniego obrotu"<<std::endl;
              std::cout<<"\tr - wyswietlenie macierzy rotacji"<<std::endl;
              std::cout<<"\tp - przesuniecie prostopadloscianu o zadany wektor"<<std::endl;
              std::cout<<"\tw - wyswietlenie wspolrzednych wierzcholkow"<<std::endl;
              std::cout<<"\ts - sprawdzenie dlugosci przeciwleglych bokow"<<std::endl;
              std::cout<<"\tm - wyswietl menu"<<std::endl;
              std::cout<<"\tk - koniec dzialania programu"<<std::endl;
              std::cin.ignore(10000, '\n');
              break;
       case 'o':
       
              macierz = Matrix3D();
              macierz.set_degree_axis();
              
              int tmp;
              std::cout<<"Ile razy ma być powtorzona operacja obracania?"<<std::endl;
              std::cin >> tmp;

              for(; tmp > 0; --tmp){
                     macierz.obrotmacierzy(cuboid);
              }

              if (!cuboid.ZapisWspolrzednychDoPliku( WSK_FILE )) {
                     return 1;
              }

              Lacze.Rysuj();

              break;
       case 't':
              // NALEŻY SPRAWDZIĆ CZY W OGÓLE MACIERZ JEST WYPEŁNIONA
              cuboid.throwing_Cuboid(macierz);

              break;
       case 'r':

              std::cout << macierz;
              break;
       case 'p':
              Przesuniecie.Load_vector();
              cuboid.Kicking_Cuboid(Przesuniecie);
              if (!cuboid.ZapisWspolrzednychDoPliku( WSK_FILE )) {
                     return 1;
              }

              Lacze.Rysuj();
              std::cin.ignore(10000, '\n');

              break;
       case 'w':
              
              std::cout << cuboid;
              std::cin.ignore(10000, '\n');

              break;
       case 's':

              cuboid.length_of_the_sides();

              Lacze.Rysuj();
              std::cin.ignore(10000, '\n');

              break;
       case 'k':
              if (!cuboid.ZapisWspolrzednychDoPliku( WSK_FILE )) { return 1; }
              exit(1);
              break;
       default:
              std::cout<<" Niepoprawna operacja, symbol m to MENU"<<std::endl;
              break;
       }
  }
}
