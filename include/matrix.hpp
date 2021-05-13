#pragma once


#include "size.hpp"
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <math.h>

template< typename T = double, int SIZE = 3 >
class Matrix {

    T value[SIZE][SIZE];                  // Wartosci macierzy

    char axis[30];

    int degrees[30];

public:

// Konstruktory klasy

    Matrix(T tmp[SIZE][SIZE]);

    Matrix();

// Metody

    Vector<double, SIZE> operator * (Vector<double, SIZE> tmp);

    Matrix operator + (Matrix tmp);

    T  &operator () (unsigned int row, unsigned int column);
    
    const T &operator () (unsigned int row, unsigned int column) const;

    void obrotmacierzy(T kat);

    void set_degree_axis();

    void obrot_x(T kat);

    void obrot_y(T kat);

    void obrot_z(T kat);

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
    for (int k = 0; k < 10; ++k) {
        axis[k] = ' ';
    }
    for (int l = 0; l < 10; ++l) {
        degrees[l] = 0;
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

template <typename T, int SIZE>
void set_degree_axis(){
    std::cout << "Proszę podać oś oraz kąt obrotu wokół niej w postaci >x 30< " << std::endl;
    for(int i = 0; i < 30; ++i){
        std::cin >> axis[i];
        std::cin >> degrees[i];
        char tmp = axis[i];
        switch(tmp)
        {
        case 'x':
            std::cout << "Wczytano do osi x " << std::endl;
            break;

        case 'y':
            std::cout << "Wczytano do osi y " << std::endl;
            break;

        case 'z':
            std::cout << "Wczytano do osi z " << std::endl;
            break;

        case '.':
            std::cout << "Skończono wczytywanie osi " << std::endl;
            degrees[i] = 0;
            i = 30;
            break;

        default:
            axis[i] = ' ';
            degrees[i] = 0;
            --i;
            std::cout << "Podano niepoprawną oś możliwe to: x, y, z " << std::endl;
            break;
        }
    }
}

template <typename T, int SIZE>
void obrot_x(T kat){
    T rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = cos(rad);
        value[0][1] = -sin(rad);
        value[0][2] = 0;
        value[1][0] = sin(rad);
        value[1][1] = cos(rad);
        value[1][2] = 0;
        value[2][0] = 0;
        value[2][1] = 0;
        value[2][2] = 1;
    }
    else{
        std::cout << "Do not except that yet" << std::endl;
    }
}


template <typename T, int SIZE>
void obrot_y(T kat){
    T rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = cos(rad);
        value[0][1] = 0;
        value[0][2] = sin(rad);
        value[1][0] = 0;
        value[1][1] = 1;
        value[1][2] = 0;
        value[2][0] = -sin(rad);
        value[2][1] = 0;
        value[2][2] = cos(rad);
    }
    else{
        std::cout << "Do not except that yet" << std::endl;
    }
}

template <typename T, int SIZE>
void obrot_z(T kat){
    T rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = 1;
        value[0][1] = 0;
        value[0][2] = 0;
        value[1][0] = 0;
        value[1][1] = cos(rad);
        value[1][2] = -sin(rad);
        value[2][0] = 0;
        value[2][1] = sin(rad);
        value[2][2] = cos(rad);
    }
    else{
        std::cout << "Do not except that yet" << std::endl;
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
    char tmp;
    int Kaciwo;
    for(int i=0; i < 30; ++i){
        tmp = axis[i];

        switch(tmp)
        {
        case 'x':
            Kaciwo = degrees[i];
            obrot_x(kaciwo);
            std::cout << "Zmlucono os x " << std::endl;
            break;

        case 'y':
            Kaciwo = degrees[i];
            obrot_y(kaciwo);
            std::cout << "Zmlucono os y " << std::endl;
            break;

        case 'z':
            Kaciwo = degrees[i];
            obrot_z(kaciwo);
            std::cout << "Zmlucono os z " << std::endl;
            break;

        case '.':
            std::cout << "Skończono mlucenie " << std::endl;
            i = 30;
            break;

        default:
            axis[i] = ' ';
            degrees[i] = 0;
            --i;
            std::cout << "UNEXCPECTED VIRUS OR MY PROGRAMMING " << std::endl;
            break;
        }
    }
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
 |     this - pierwszy skladnik mnozenia (macierz).                           |
 |     tmp - drugi skladnik mnozenia (wektor)                                 |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
//  */
template<typename T, int SIZE>
Vector<double, SIZE> Matrix<T, SIZE>::operator * (Vector<double, SIZE> tmp){
    Vector<double, SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

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
Matrix<T, SIZE> Matrix<T, SIZE>::operator + (Matrix<T, SIZE> tmp){
    Matrix<T, SIZE> result;
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
