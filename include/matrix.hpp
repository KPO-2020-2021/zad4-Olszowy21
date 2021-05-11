#pragma once


#include "size.hpp"
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <math.h>

template< typename T = double, int SIZE = 3 > 
class Matrix {

    T value[SIZE][SIZE];                  // Wartosci macierzy

public:

// Konstruktory

    Matrix(T tmp[SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                                  // Konstruktor klasy

// Metody

    // Vector operator * (Vector tmp) const;            // Operator mnożenia przez wektor

    // Vector operator * (Matrix &tmp) const;

    Matrix operator + (Matrix tmp);

    T  &operator () (unsigned int row, unsigned int column);
    
    const T &operator () (unsigned int row, unsigned int column) const;

    void obrotmacierzy(T kat);

    bool operator == (const Matrix tmp) const;

    const T &operator [] (unsigned int index) const;
    
    T &operator [] (unsigned int index);

};


template <typename T, int SIZE>
std::istream &operator >> (std::istream &in, Matrix<T, SIZE> &mat);

template <typename T, int SIZE>
std::ostream &operator << (std::ostream &out, Matrix<T, SIZE> const &mat);

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <typename T, int SIZE>
Matrix<T, SIZE>::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename T, int SIZE>
Matrix<T, SIZE>::Matrix(T tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

/*!
 * Realizuje obrot macierzy o zadany kat.
 * \param[in] kat - kat w stopniach jaki zostanie zmieniony w radiany a nastepnie
 *                      przysluzy do obrotu danych macierzy.
 * 
 */
template <typename T, int SIZE>
void Matrix<T, SIZE>::obrotmacierzy(T kat){
    
    T rad = kat * M_PI / 180;

    value[0][0] = cos(rad);
    value[0][1] = -sin(rad);
    value[1][0] = sin(rad);
    value[1][1] = cos(rad);
}

/*!
 * Realizuje porownanie dwoch macierzy ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa macierzy sprawdzanej z macierza zawarta wewnatrz klasy
 * 
 * \retval true - gdy obie sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
template <typename T, int SIZE>
bool Matrix<T, SIZE>::operator == (const Matrix<T, SIZE> tmp) const{
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(std::abs(this->value[i][j] - tmp.value[i][j]) > MIN_DIFF ){
                return false;
            }
        }
    }
    return true;
}

/*!
 * Przeciazenie operatora [] dla danych chronionych macierzy.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <typename T, int SIZE>
T &Matrix<T, SIZE>::operator [] (unsigned int index){
if ( index >= SIZE*2 ) {
        std::cerr << "Error: Macierz jest poza zasiegiem!" << std::endl;
} // lepiej byłoby rzucić wyjątkiem stdexcept

return value[index][index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych macierzy.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <typename T, int SIZE>
const T &Matrix<T, SIZE>::operator [] (unsigned int index) const{
    return value[index][index];
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
// template <typename T, int SIZE>
// Vector<T, SIZE> Matrix<T, SIZE>::operator * (Vector<T, SIZE> tmp) const{
//     Vector result;
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             result[i] += value[i][j] * tmp[j];
//         }
//     }
//     return result;
// }

// /******************************************************************************
//  |  Realizuje mnozenie macierzy przez wektor przez.                           |
//  |  Argumenty:                                                                |
//  |     this - pierwszy skladnik mnozenia (macierz).                           |
//  |     tmp - drugi skladnik mnozenia (wektor)                                 |
//  |  Zwraca:                                                                   |
//  |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
//  |      na parametr.                                                          |
// //  */
// template <typename T, int SIZE>
// Vector<T, SIZE> Matrix<T, SIZE>::operator * (const Vector<T, SIZE> &tmp){
//     Vector result;

//     for(int x = 0; x < SIZE; ++x){
//         for(int y = 0; y < SIZE; ++y){
//             result[x] += tmp[y] * this->value[y][x];
//         }
//     }
//     return result;
// }


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <typename T, int SIZE>
T &Matrix<T, SIZE>::operator () (unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <typename T, int SIZE>
const T &Matrix<T, SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cerr << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cerr << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <typename T, int SIZE>
Matrix<T, SIZE> Matrix<T, SIZE>::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <typename T, int SIZE>
std::istream &operator >> (std::istream &in, Matrix<T, SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> tmp(i, j);
        }
    }
    return in;
}


/*!
 * Przeciazenie operatora wypisywania na ekran.
 * \param[in] out - strumien wyjsciowy, z ktorego maja zostac wpisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Matrix z ktorej bedzie wypisywane
 *                     wspolrzedne na ekran.
 * 
 */
template <typename T, int SIZE>
std::ostream &operator << (std::ostream &out, const Matrix<T, SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << tmp(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
