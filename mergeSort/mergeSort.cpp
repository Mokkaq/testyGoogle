/**
 * @file MergeSort.cpp
 * @brief Implementacja metod klasy MergeSort.
 *
 * Plik zawiera implementacje wszystkich metod klasy MergeSort, w tym konstruktorów,
 * destruktora, funkcji sortujących oraz funkcji pomocniczych.
 */

#include "MergeSort.h"
#include <iostream>

 /**
  * @brief Konstruktor domyślny klasy MergeSort.
  *
  * Tworzy pustą tablicę dynamiczną o rozmiarze 0. Alokuje pamięć dla tablicy
  * i inicjalizuje wskaźnik `arr` oraz zmienną `size`.
  */
MergeSort::MergeSort() {
    this->size = 0;
    this->arr = new int[this->size];
}

/**
 * @brief Konstruktor inicjalizujący klasę MergeSort z tablicą wejściową.
 *
 * Kopiuje dane z podanej tablicy wejściowej do wewnętrznej tablicy obiektu.
 * Następnie automatycznie uruchamia proces sortowania tablicy.
 *
 * @param tab Wskaźnik do tablicy wejściowej.
 * @param size Rozmiar tablicy wejściowej.
 */
MergeSort::MergeSort(int tab[], int size) {
    this->size = size;
    this->arr = new int[size];
    this->setTab(tab, this->size);
    this->sort();
}

/**
 * @brief Destruktor klasy MergeSort.
 *
 * Usuwa dynamicznie zaalokowaną pamięć dla tablicy `arr`, aby zapobiec wyciekowi pamięci.
 */
MergeSort::~MergeSort() {
    delete[] arr;
}

/**
 * @brief Kopiuje zawartość z podanej tablicy wejściowej do wewnętrznej tablicy obiektu.
 *
 * Funkcja kopiuje dane z tablicy `tab` do tablicy `arr` obiektu.
 * Kopiowanie jest ograniczone do rozmiaru wewnętrznej tablicy.
 *
 * @param tab Wskaźnik do tablicy wejściowej.
 * @param tabSize Rozmiar tablicy wejściowej.
 *
 * @note Jeśli `tabSize` przekracza rozmiar wewnętrznej tablicy, funkcja nie wykonuje operacji.
 */
void MergeSort::setTab(int tab[], int tabSize) {
    if (tabSize > size) return;
    for (int i = 0; i < tabSize; i++) {
        arr[i] = tab[i];
    }
}

/**
 * @brief Rozpoczyna sortowanie tablicy wewnętrznej.
 *
 * Implementacja korzysta z metody sortowania przez scalanie. Jeśli rozmiar
 * tablicy wynosi 0 lub 1, sortowanie nie jest wykonywane.
 */
void MergeSort::sort() {
    if (size <= 1) return;
    mergeSort(arr, 0, size - 1);
}

/**
 * @brief Wypisuje zawartość wewnętrznej tablicy obiektu na standardowe wyjście.
 *
 * Wszystkie elementy tablicy są wypisywane w jednej linii, oddzielone spacjami.
 */
void MergeSort::printTab() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Zwraca wskaźnik do wewnętrznej tablicy obiektu.
 *
 * @return Wskaźnik do tablicy `arr`.
 */
int* MergeSort::getTab() {
    return this->arr;
}

/**
 * @brief Zwraca rozmiar wewnętrznej tablicy obiektu.
 *
 * @return Liczba elementów w tablicy `arr`.
 */
int MergeSort::getSize() {
    return this->size;
}

/**
 * @brief Funkcja rekurencyjna sortująca fragment tablicy.
 *
 * Funkcja dzieli tablicę na mniejsze fragmenty, sortuje je rekurencyjnie,
 * a następnie scala w posortowany fragment.
 *
 * @param arr Wskaźnik do tablicy do posortowania.
 * @param left Indeks początkowy zakresu do posortowania.
 * @param right Indeks końcowy zakresu do posortowania.
 */
void MergeSort::mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);         ///< Sortowanie lewej połowy tablicy.
        mergeSort(arr, mid + 1, right);   ///< Sortowanie prawej połowy tablicy.

        merge(arr, left, mid, right);     ///< Scalanie posortowanych połówek.
    }
}

/**
 * @brief Scala dwa posortowane fragmenty tablicy w jeden.
 *
 * Funkcja wykorzystuje dwie pomocnicze dynamiczne tablice: `leftArr` i `rightArr`.
 * Elementy są kopiowane z oryginalnej tablicy do tych pomocniczych, a następnie
 * scalane w jeden posortowany fragment w tablicy głównej.
 *
 * @param arr Wskaźnik do tablicy głównej.
 * @param left Indeks początkowy lewej części tablicy.
 * @param mid Indeks końcowy lewej części i początkowy prawej części.
 * @param right Indeks końcowy prawej części tablicy.
 */
void MergeSort::merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1; ///< Liczba elementów w lewej części.
    int n2 = right - mid;    ///< Liczba elementów w prawej części.

    int* leftArr = new int[n1]; ///< Dynamicznie alokowana tablica dla lewej części.
    int* rightArr = new int[n2]; ///< Dynamicznie alokowana tablica dla prawej części.

    // Kopiowanie danych do tablic pomocniczych.
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; ///< Indeksy dla odpowiednich części.

    // Scalanie danych z tablic pomocniczych do tablicy głównej.
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów z lewej części, jeśli istnieją.
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów z prawej części, jeśli istnieją.
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr; ///< Zwolnienie pamięci po lewej tablicy pomocniczej.
    delete[] rightArr; ///< Zwolnienie pamięci po prawej tablicy pomocniczej.
}
