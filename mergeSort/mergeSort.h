#pragma once
class MergeSort {
public:
    MergeSort(); // Konstruktor
    MergeSort(int tab[], int size); // Konstruktor z tablic¹ wejœciow¹
    ~MergeSort(); // Destruktor

    void setTab(int tab[], int tabSize); // Funkcja ustawia wartoœci w tablicy.
    void sort(); // Funkcja rozpoczyna proces sortowania tablicy.
    void printTab(); // Funkcja wypisuje zawartoœæ tablicy na ekran.
    int* getTab(); // Funkcja zwraca wskaŸnik do tablicy.
    int getSize(); // Funkcja zwraca rozmiar tablicy.

private:
    int* arr; // WskaŸnik na dynamicznie alokowan¹ tablicê.
    int size;  // Rozmiar tablicy.
    void mergeSort(int* arr, int left, int right); // Funkcja rekurencyjnie dzieli tablicê na czêœci i sortuje je.
    void merge(int* arr, int left, int mid, int right); // Funkcja scala dwie posortowane czêœci tablicy w jedn¹.
};

