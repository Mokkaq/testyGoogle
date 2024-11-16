#include "MergeSort.h"
#include <iostream>

// Konstruktor domyślny inicjalizuje tablicę o rozmiarze 0.
MergeSort::MergeSort() {
    this->size = 0;
    this->arr = new int[this->size];
}

// Konstruktor kopiuje dane wejściowe, alokuje pamięć i rozpoczyna sortowanie.
MergeSort::MergeSort(int tab[], int size) {
    this->size = size;
    this->arr = new int[size];
    this->setTab(tab, this->size);
    this->sort();
}

// Destruktor zwalnia pamięć dynamicznie zaalokowaną dla tablicy.
MergeSort::~MergeSort() {
    delete[] arr;
}

// Funkcja kopiuje wartości z podanej tablicy do wewnętrznej tablicy obiektu.
void MergeSort::setTab(int tab[], int tabSize) {
    if (tabSize > size) return;
    for (int i = 0; i < tabSize; i++) {
        arr[i] = tab[i];
    }
}

// Funkcja inicjuje sortowanie tablicy metodą sortowania przez scalanie.
void MergeSort::sort() {
    if (size <= 1) return;
    mergeSort(arr, 0, size - 1);
}

// Funkcja wypisuje wszystkie elementy tablicy w jednej linii.
void MergeSort::printTab() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Funkcja zwraca wskaźnik do wewnętrznej tablicy obiektu.
int* MergeSort::getTab() {
    return this->arr;
}

// Funkcja zwraca rozmiar wewnętrznej tablicy obiektu.
int MergeSort::getSize() {
    return this->size;
}

// Rekurencyjna funkcja dzieli tablicę na części i scala je w posortowane fragmenty
void MergeSort::mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Rekurencyjne dzielenie tablicy na dwie połowy
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Scalanie posortowanych połówek
        merge(arr, left, mid, right);
    }
}

// Funkcja scala dwie posortowane części tablicy
void MergeSort::merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Dynamiczna alokacja pamięci dla tymczasowych tablic
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Kopiowanie danych do tymczasowych tablic
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
   
    // Scalanie tymczasowych tablic z powrotem do tablicy głównej arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów z lewej tablicy (jeśli są)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów z prawej tablicy (jeśli są)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Zwalnianie pamięci dynamicznie zaalokowanych tablic
    delete[] leftArr;
    delete[] rightArr;
}
