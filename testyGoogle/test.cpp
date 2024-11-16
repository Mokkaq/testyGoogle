#include "pch.h"

#include "../MergeSort/MergeSort.h"
#include "../MergeSort/MergeSort.cpp"

#include <algorithm>
#include <cstdlib>

// Zachowuje tablicê niezmienion¹, gdy ona jest ju¿ posortowana rosn¹co
TEST(Sort, TabNiezmienionaRosnaco) {
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab();

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "Tablica zosta³a zmieniona przez algorytm na indeksie " << i;
	}
}


// Potrafi posortowaæ tablicê, która jest posortowana w odwrotnej kolejnoœci
TEST(Sort, TabWOdwrotnejKolejnosci) {
	int tab[] = {9, 8, 7, 6, 5, 4, 11, 2, 1, 0};
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}

// Wyœwietlanie tablicy w celu sprawdzenia
	//std::cout << "Oczekiwana tablica: ";
	//for (int j = 0; j < size; j++) {
	//	std::cout << tab[j] << " ";
	//}
	//std::cout << "\nWynikowa tablica: ";
	//for (int j = 0; j < size; j++) {
	//	std::cout << tempArray[j] << " ";
	//}
	//std::cout << std::endl;
}


// Poprawnie sortuje losow¹ tablicê liczb
TEST(Sort,TabLosowychLiczb) {
	int size = 10;
	int tab[10];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		tab[i] = rand() % 20;
	}

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(Sort, TabLiczbyUjemne) {
	int tab[] = { -38, -27, -43, -3, -9, -82, -10 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(Sort, TabLiczbyUjemneIDodatnie) {
	int tab[] = { -38, 27, -43, 3, -9, 82, -10 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Obs³uguje pust¹ tablicê bez rzucania wyj¹tkiem
TEST(Inicjalizuj, NieRzucaWyjatkiem) {
	int tab[] = { 0 };
	int size = sizeof(tab) / sizeof(tab[0]);

	ASSERT_NO_THROW(MergeSort arrayToSort(tab, size));
}


// Nie zmienia tablicy, która zawiera tylko jeden element
TEST(Sort, TabJednoelementowa) {
	int tab[] = { 42 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab(); 

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablicê z duplikatami liczb
TEST(Sort, TabZDuplikatami) {
	int tab[] = { 4, 1, 4, 2, 1, 3, 4 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablice ujemn¹ z duplikatami
TEST(Sort, TabZUjemnymiDuplikatami) {
	int tab[] = { -5, -10, -5, -30, -5, -30, -4 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(Sort, TabUjemneDodatnieDuplikaty) {
	int tab[] = { 5, -3, 7, -3, 2, 0, 5, 7, -1, 5 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab(); // Tablica wynikowa

	// Sortowanie kontrolne (oczekiwany wynik)
	std::sort(std::begin(tab), std::end(tab));

	// Porównanie ka¿dego elementu
	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablicê zawieraj¹c¹ tylko dwa elementy w kolejnoœci rosn¹cej
TEST(Sort, TabDwuelementowaRosnaca) {
	int tab[] = { 2, 1 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab)); // Sortowanie kontrolne

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
TEST(Sort, TabStoElementow) {
	const int size = 150;
	int tab[size];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		tab[i] = rand() % 1000;
	}

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B³¹d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(Sort, TabOstateczna) {
	const int size = 200;
	int tab[size];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		tab[i] = (rand() % 200) - 100;
	}

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "Wartosc " << tab[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}