/**
 * @file main.cpp
 * @brief Program demonstruj¹cy u¿ycie klasy MergeSort do sortowania tablicy.
 *
 * Plik zawiera funkcjê `main`, która tworzy obiekt klasy MergeSort,
 * sortuje tablicê liczb ca³kowitych i wypisuje wynik na standardowe wyjœcie.
 */

#include <iostream>
#include "MergeSort.h"

 /**
  * @brief Funkcja g³ówna programu.
  *
  * Funkcja g³ówna demonstruje u¿ycie klasy MergeSort do sortowania tablicy.
  * Tworzy tablicê liczb ca³kowitych, oblicza jej rozmiar, sortuje j¹ za pomoc¹
  * algorytmu sortowania przez scalanie i wypisuje posortowan¹ tablicê na standardowe wyjœcie.
  *
  * @return Zwraca `0` w przypadku powodzenia dzia³ania programu.
  */
int main() {
    int tab[] = { 67, 23, 11, 9, 43, 98, 2 }; ///< Tablica do posortowania.
    int size = sizeof(tab) / sizeof(tab[0]); ///< Obliczenie liczby elementów w tablicy.

    MergeSort arrayToSort(tab, size); ///< Utworzenie obiektu MergeSort i sortowanie tablicy.

    std::cout << "Tablica po sortowaniu: ";
    arrayToSort.printTab(); ///< Wywo³anie metody, która wypisuje posortowan¹ tablicê.

    return 0;
}
