/**
 * @file MergeSort.h
 * @brief Deklaracja klasy MergeSort.
 *
 * Klasa MergeSort implementuje algorytm sortowania przez scalanie
 * na dynamicznie alokowanych tablicach. Umo�liwia sortowanie liczb
 * ca�kowitych oraz oferuje r�ne operacje na tablicach, takie jak
 * wypisywanie ich zawarto�ci czy pobieranie wska�nika do tablicy.
 */

#pragma once

 /**
  * @class MergeSort
  * @brief Klasa implementuj�ca algorytm sortowania przez scalanie.
  *
  * Klasa zarz�dza dynamicznie alokowan� tablic�, umo�liwia jej sortowanie
  * metod� sortowania przez scalanie, wypisanie na ekran oraz modyfikacj�.
  */
class MergeSort {
public:
    /**
     * @brief Konstruktor domy�lny klasy MergeSort.
     *
     * Tworzy pust� tablic� o rozmiarze 0 i alokuje pami�� dla wska�nika `arr`.
     */
    MergeSort();
               
    /**
     * @brief Konstruktor inicjalizuj�cy z tablic� wej�ciow�.
     *
     * Tworzy obiekt klasy MergeSort, kopiuje dane z podanej tablicy
     * do wewn�trznej tablicy dynamicznej i sortuje j�.
     *
     * @param tab Wska�nik do tablicy wej�ciowej.
     * @param size Rozmiar tablicy wej�ciowej.
     */
    MergeSort(int tab[], int size);

    /**
     * @brief Destruktor klasy MergeSort.
     *
     * Zwalnia pami�� zaalokowan� dla dynamicznie alokowanej tablicy.
     */
    ~MergeSort();

    /**
     * @brief Ustawia zawarto�� wewn�trznej tablicy na podstawie podanej tablicy.
     *
     * Kopiuje dane z tablicy wej�ciowej `tab` do wewn�trznej tablicy `arr`.
     * Operacja jest ograniczona do rozmiaru wewn�trznej tablicy.
     *
     * @param tab Wska�nik do tablicy wej�ciowej.
     * @param tabSize Rozmiar tablicy wej�ciowej.
     * @note Je�li rozmiar podanej tablicy przekracza rozmiar wewn�trznej tablicy,
     *       operacja nie jest wykonywana.
     */
    void setTab(int tab[], int tabSize);

    /**
     * @brief Rozpoczyna proces sortowania tablicy.
     *
     * U�ywa metody sortowania przez scalanie do posortowania wewn�trznej tablicy `arr`.
     */
    void sort();

    /**
     * @brief Wypisuje zawarto�� wewn�trznej tablicy na ekran.
     *
     * Elementy s� wypisywane w jednej linii, oddzielone spacjami.
     */
    void printTab();

    /**
     * @brief Zwraca wska�nik do wewn�trznej tablicy dynamicznej.
     *
     * @return Wska�nik do dynamicznie zaalokowanej tablicy `arr`.
     */
    int* getTab();

    /**
     * @brief Zwraca rozmiar wewn�trznej tablicy.
     *
     * @return Liczba element�w w dynamicznie zaalokowanej tablicy `arr`.
     */
    int getSize();

private:
    int* arr; ///< Wska�nik do dynamicznie zaalokowanej tablicy.
    int size; ///< Liczba element�w w tablicy `arr`.

    /**
     * @brief Funkcja pomocnicza implementuj�ca sortowanie przez scalanie.
     *
     * Rekurencyjnie dzieli tablic� na mniejsze cz�ci, sortuje je i scala
     * w jeden posortowany fragment.
     *
     * @param arr Wska�nik do tablicy do posortowania.
     * @param left Indeks pocz�tkowy zakresu do posortowania.
     * @param right Indeks ko�cowy zakresu do posortowania.
     */
    void mergeSort(int* arr, int left, int right);

    /**
     * @brief Funkcja pomocnicza scalaj�ca dwa posortowane fragmenty tablicy.
     *
     * ��czy dwa posortowane podzbiory tablicy w jeden posortowany fragment.
     * Dane s� kopiowane do tymczasowych tablic pomocniczych, a nast�pnie
     * scalane w oryginalnej tablicy `arr`.
     *
     * @param arr Wska�nik do tablicy zawieraj�cej dane.
     * @param left Indeks pocz�tkowy lewej cz�ci tablicy.
     * @param mid Indeks ko�cowy lewej cz�ci i pocz�tkowy prawej cz�ci.
     * @param right Indeks ko�cowy prawej cz�ci tablicy.
     */
    void merge(int* arr, int left, int mid, int right);
};
