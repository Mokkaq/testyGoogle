#include <iostream>
#include "MergeSort.h"

int main() {
    int tab[] = { 67, 23, 11, 9, 43, 98, 2 }; // Tablica do posortowania
    int size = sizeof(tab) / sizeof(tab[0]); // Obliczenie liczby element�w w tablicy

    MergeSort arrayToSort(tab, size); // Utworzenie obiektu MergeSort i sortowanie tablicy

    std::cout << "Tablica przed sortowaniem: "; 
    std::cout << "Tablica po sortowaniu: ";

    arrayToSort.printTab(); // Wywo�anie metody, kt�ra wypisuje posortowan� tablic�

    return 0;
}
