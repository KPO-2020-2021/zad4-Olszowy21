#pragma once

#include "matrix.hpp"

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */

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

// std::ofstream &operator << (std::ofstream &out, Rectangle const &tmp);

std::ostream &operator << (std::ostream &out, Vector<double, SIZE> const &tmp);

std::ostream &operator << (std::ostream &out, Cuboid const &tmp){

    for(unsigned int i = 0; i < SIZE+5; ++i){
        out << i + 1 << " Wiechołek prostokąta - " << tmp.operator[](i) << std::endl;
    }
    return out;
}

Cuboid::Cuboid(){

    top[0] = Vector<double, SIZE>(2, 3, 3);
    top[1] = Vector<double, SIZE>(22, 3, 3);
    top[2] = Vector<double, SIZE>(2, 18, 3);
    top[3] = Vector<double, SIZE>(22, 18, 3);
    top[4] = Vector<double, SIZE>(2, 18, 28);
    top[5] = Vector<double, SIZE>(22, 18, 28);
    top[6] = Vector<double, SIZE>(2, 3, 28);
    top[7] = Vector<double, SIZE>(22, 3, 28);

}

Cuboid::Cuboid( Vector<double, SIZE> first, Vector<double, SIZE> second, Vector<double, SIZE> third, Vector<double, SIZE> fourth,
        Vector<double, SIZE> fifth, Vector<double, SIZE> sixth,  Vector<double, SIZE> seventh, Vector<double, SIZE> eigth ){
    
    top[0] = first;
    top[1] = second;
    top[2] = third;
    top[3] = fourth;
    top[4] = fifth;
    top[5] = sixth;
    top[6] = seventh;
    top[7] = eigth;

}


/*!
 * Realizuje porownanie dwoch prostokatow ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa prostokata sprawdzanego z prostokatem zawartym wewnatrz klasy
 * 
 * \retval true - gdy oba sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
bool Cuboid::operator == (const Cuboid &tmp) const{

    for(int i = 0; i < SIZE+5; ++i){
        if(!(this->top[i] == tmp.top[i])){
            return false;
        }
    }
    return true;
}


/*!
 * Metoda przesuwania punktow szczegolnych figury o zadany wektor.
 * \param[in] tmp - nazwa wektora która przysluzy się do przesuniecia punktow prostokata
 *                         
 */
void Cuboid::Kicking_Cuboid(const Vector<double, SIZE> &tmp){
    
    for(int i=0; i<SIZE+5; ++i){

        top[i] = top[i] + tmp;

    }
}

/*!
 * Metoda obracania punktow szczegolnych figury.
 * \param[in] tmp - nazwa macierzy która przysłuży się do obracania punktow prostokata
 *                         
 */
void Cuboid::throwing_Cuboid(const Matrix<double, SIZE> &tmp){
    
    for(unsigned int i=0; i<SIZE+5; ++i){

        top[i] = tmp * top[i];

    }
}



/*!
 * Zapis wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * 
 */
void Cuboid::ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy){
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[1][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[1][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[1][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[2][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[2][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[2][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[3][0]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[3][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[3][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[4][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[4][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[4][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[5][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[5][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[5][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[6][0]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[6][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[6][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[7][0]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[7][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[7][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][2] << std::endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] File_name - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * 
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Cuboid::ZapisWspolrzednychDoPliku( const char *File_name)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(File_name, std::ios::trunc);

  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << File_name << "\"" << std::endl
    << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia(StrmPlikowy);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/*!
 * Metoda sprawdzania dlugosci przeciwleglych bokow aktualnej figury
 * znajdujacej sie w klasie rectangle ( prostokata ).
 * \param[in] tmp - nazwa macierzy która przysłuży się do obracania punktow prostokata
 *  
 * \retval true - gdy boki prostokata sa rowne
 * \retval false - w przypadku przeciwnym.                       
 */
void Cuboid::length_of_the_sides(){
    double side1;   //                                  side7                 
                    //        top[7] ---> *------------------------------* <--- top[5]              ----|          
    double side2;   //                    |                              |                              |
                    //                   ||                             ||                              |  
    double side3;   //                  | | <--- side9                 | |                              | <--- side12 
                    //      side4 ---> |  |                side3 ---> |  |                              |
    double side4;   //                |   |           side5          |   |                              |
                    //       top[1] -|--> *-------------------------|----* <--- top[3]              ----|
    double side5;   //              |    |        side8            |    |                             
                    // top[8] ---> *----|-------------------------* <--|- top[6]                    ----|
    double side6;   //             |   | <--- side1               |   | <--- side2                      |
                    // side10 ---> |  |                           |  |                                  | <--- side11
    double side7;   //             | |                            | |                                   |
                    //             ||                             ||                                    |
    double side8;   // top[2] ---> *------------------------------* <--- top[4]                     ----|
                    //                          side6
    double side9;   //
                    //
    double side10;  //
                    //
    double side11;  //
                    //
    double side12;  //


    side1 = sqrt( pow( std::abs(top[2][0] - top[1][0]),2)  +  pow( std::abs(top[2][1] - top[1][1]),2) + pow( std::abs(top[2][2] - top[1][2]),2));

    side2 = sqrt( pow( std::abs(top[4][0] - top[3][0]),2)  +  pow( std::abs(top[4][1] - top[3][1]),2) + pow( std::abs(top[4][2] - top[3][2]),2));

    side3 = sqrt( pow( std::abs(top[6][0] - top[5][0]),2)  +  pow( std::abs(top[6][1] - top[5][1]),2) + pow( std::abs(top[6][2] - top[5][2]),2));

    side4 = sqrt( pow( std::abs(top[8][0] - top[7][0]),2)  +  pow( std::abs(top[8][1] - top[7][1]),2) + pow( std::abs(top[8][2] - top[7][2]),2));

    side5 = sqrt( pow( std::abs(top[3][0] - top[1][0]),2)  +  pow( std::abs(top[3][1] - top[1][1]),2) + pow( std::abs(top[3][2] - top[1][2]),2));

    side6 = sqrt( pow( std::abs(top[4][0] - top[2][0]),2)  +  pow( std::abs(top[4][1] - top[2][1]),2) + pow( std::abs(top[4][2] - top[2][2]),2));

    side7 = sqrt( pow( std::abs(top[7][0] - top[5][0]),2)  +  pow( std::abs(top[7][1] - top[5][1]),2) + pow( std::abs(top[7][2] - top[5][2]),2));

    side8 = sqrt( pow( std::abs(top[8][0] - top[6][0]),2)  +  pow( std::abs(top[8][1] - top[6][1]),2) + pow( std::abs(top[8][2] - top[6][2]),2));

    side9 = sqrt( pow( std::abs(top[7][0] - top[1][0]),2)  +  pow( std::abs(top[7][1] - top[1][1]),2) + pow( std::abs(top[7][2] - top[1][2]),2));

    side10 = sqrt( pow( std::abs(top[8][0] - top[2][0]),2)  +  pow( std::abs(top[8][1] - top[2][1]),2) + pow( std::abs(top[8][2] - top[2][2]),2));

    side11 = sqrt( pow( std::abs(top[6][0] - top[4][0]),2)  +  pow( std::abs(top[6][1] - top[4][1]),2) + pow( std::abs(top[6][2] - top[4][2]),2));

    side12 = sqrt( pow( std::abs(top[5][0] - top[3][0]),2)  +  pow( std::abs(top[5][1] - top[3][1]),2) + pow( std::abs(top[5][2] - top[3][2]),2));


    if((std::abs(side5 - side8) <= MIN_DIFF) && (std::abs(side6 - side7) <= MIN_DIFF)){
        std::cout <<" :)  Dluzsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side8 << std::endl;

        
    }
    else{
        std::cout <<" :/  Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side8 << std::endl;
    }

    if((std::abs(side1 - side3) <= MIN_DIFF) && (std::abs(side2 - side4) <= MIN_DIFF)){
        std::cout <<" :)  Krotsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side4 << std::endl;
    }
    else{
        std::cout <<" :/  Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side4 << std::endl;
    }

    if((std::abs(side9 - side11) <= MIN_DIFF) && (std::abs(side10 - side12) <= MIN_DIFF)){
        std::cout <<" :)  Poprzeczne przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }
    else{
        std::cout <<" :/  Poprzeczne przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }

}