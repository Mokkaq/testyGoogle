/**
 * @file main.cpp
 * @brief Program demonstruj�cy u�ycie klasy MergeSort do sortowania tablicy.
 *
 * Plik zawiera funkcj� `main`, kt�ra tworzy obiekt klasy MergeSort,
 * sortuje tablic� liczb ca�kowitych i wypisuje wynik na standardowe wyj�cie.
 */

#include <iostream>
#include "MergeSort.h"

 /**
  * @brief Funkcja g��wna programu.
  *
  * Funkcja g��wna demonstruje u�ycie klasy MergeSort do sortowania tablicy.
  * Tworzy tablic� liczb ca�kowitych, oblicza jej rozmiar, sortuje j� za pomoc�
  * algorytmu sortowania przez scalanie i wypisuje posortowan� tablic� na standardowe wyj�cie.
  *
  * @return Zwraca `0` w przypadku powodzenia dzia�ania programu.
  */
int main() {
    int tab[] = { 67, 23, 11, 9, 43, 98, 2 }; ///< Tablica do posortowania.
    int size = sizeof(tab) / sizeof(tab[0]); ///< Obliczenie liczby element�w w tablicy.

    MergeSort arrayToSort(tab, size); ///< Utworzenie obiektu MergeSort i sortowanie tablicy.

    std::cout << "Tablica po sortowaniu: ";
    arrayToSort.printTab(); ///< Wywo�anie metody, kt�ra wypisuje posortowan� tablic�.

    return 0;
}
