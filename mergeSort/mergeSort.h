/**
 * @file MergeSort.h
 * @brief Deklaracja klasy MergeSort.
 *
 * Klasa MergeSort implementuje algorytm sortowania przez scalanie
 * na dynamicznie alokowanych tablicach. Umo¿liwia sortowanie liczb
 * ca³kowitych oraz oferuje ró¿ne operacje na tablicach, takie jak
 * wypisywanie ich zawartoœci czy pobieranie wskaŸnika do tablicy.
 */

#pragma once

 /**
  * @class MergeSort
  * @brief Klasa implementuj¹ca algorytm sortowania przez scalanie.
  *
  * Klasa zarz¹dza dynamicznie alokowan¹ tablic¹, umo¿liwia jej sortowanie
  * metod¹ sortowania przez scalanie, wypisanie na ekran oraz modyfikacjê.
  */
class MergeSort {
public:
    /**
     * @brief Konstruktor domyœlny klasy MergeSort.
     *
     * Tworzy pust¹ tablicê o rozmiarze 0 i alokuje pamiêæ dla wskaŸnika `arr`.
     */
    MergeSort();
               
    /**
     * @brief Konstruktor inicjalizuj¹cy z tablic¹ wejœciow¹.
     *
     * Tworzy obiekt klasy MergeSort, kopiuje dane z podanej tablicy
     * do wewnêtrznej tablicy dynamicznej i sortuje j¹.
     *
     * @param tab WskaŸnik do tablicy wejœciowej.
     * @param size Rozmiar tablicy wejœciowej.
     */
    MergeSort(int tab[], int size);

    /**
     * @brief Destruktor klasy MergeSort.
     *
     * Zwalnia pamiêæ zaalokowan¹ dla dynamicznie alokowanej tablicy.
     */
    ~MergeSort();

    /**
     * @brief Ustawia zawartoœæ wewnêtrznej tablicy na podstawie podanej tablicy.
     *
     * Kopiuje dane z tablicy wejœciowej `tab` do wewnêtrznej tablicy `arr`.
     * Operacja jest ograniczona do rozmiaru wewnêtrznej tablicy.
     *
     * @param tab WskaŸnik do tablicy wejœciowej.
     * @param tabSize Rozmiar tablicy wejœciowej.
     * @note Jeœli rozmiar podanej tablicy przekracza rozmiar wewnêtrznej tablicy,
     *       operacja nie jest wykonywana.
     */
    void setTab(int tab[], int tabSize);

    /**
     * @brief Rozpoczyna proces sortowania tablicy.
     *
     * U¿ywa metody sortowania przez scalanie do posortowania wewnêtrznej tablicy `arr`.
     */
    void sort();

    /**
     * @brief Wypisuje zawartoœæ wewnêtrznej tablicy na ekran.
     *
     * Elementy s¹ wypisywane w jednej linii, oddzielone spacjami.
     */
    void printTab();

    /**
     * @brief Zwraca wskaŸnik do wewnêtrznej tablicy dynamicznej.
     *
     * @return WskaŸnik do dynamicznie zaalokowanej tablicy `arr`.
     */
    int* getTab();

    /**
     * @brief Zwraca rozmiar wewnêtrznej tablicy.
     *
     * @return Liczba elementów w dynamicznie zaalokowanej tablicy `arr`.
     */
    int getSize();

private:
    int* arr; ///< WskaŸnik do dynamicznie zaalokowanej tablicy.
    int size; ///< Liczba elementów w tablicy `arr`.

    /**
     * @brief Funkcja pomocnicza implementuj¹ca sortowanie przez scalanie.
     *
     * Rekurencyjnie dzieli tablicê na mniejsze czêœci, sortuje je i scala
     * w jeden posortowany fragment.
     *
     * @param arr WskaŸnik do tablicy do posortowania.
     * @param left Indeks pocz¹tkowy zakresu do posortowania.
     * @param right Indeks koñcowy zakresu do posortowania.
     */
    void mergeSort(int* arr, int left, int right);

    /**
     * @brief Funkcja pomocnicza scalaj¹ca dwa posortowane fragmenty tablicy.
     *
     * £¹czy dwa posortowane podzbiory tablicy w jeden posortowany fragment.
     * Dane s¹ kopiowane do tymczasowych tablic pomocniczych, a nastêpnie
     * scalane w oryginalnej tablicy `arr`.
     *
     * @param arr WskaŸnik do tablicy zawieraj¹cej dane.
     * @param left Indeks pocz¹tkowy lewej czêœci tablicy.
     * @param mid Indeks koñcowy lewej czêœci i pocz¹tkowy prawej czêœci.
     * @param right Indeks koñcowy prawej czêœci tablicy.
     */
    void merge(int* arr, int left, int mid, int right);
};
