#pragma once
class MergeSort {
public:
    MergeSort(); // Konstruktor
    MergeSort(int tab[], int size); // Konstruktor z tablic� wej�ciow�
    ~MergeSort(); // Destruktor

    void setTab(int tab[], int tabSize); // Funkcja ustawia warto�ci w tablicy.
    void sort(); // Funkcja rozpoczyna proces sortowania tablicy.
    void printTab(); // Funkcja wypisuje zawarto�� tablicy na ekran.
    int* getTab(); // Funkcja zwraca wska�nik do tablicy.
    int getSize(); // Funkcja zwraca rozmiar tablicy.

private:
    int* arr; // Wska�nik na dynamicznie alokowan� tablic�.
    int size;  // Rozmiar tablicy.
    void mergeSort(int* arr, int left, int right); // Funkcja rekurencyjnie dzieli tablic� na cz�ci i sortuje je.
    void merge(int* arr, int left, int mid, int right); // Funkcja scala dwie posortowane cz�ci tablicy w jedn�.
};

