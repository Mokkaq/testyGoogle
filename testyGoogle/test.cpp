#include "pch.h"

#include "../MergeSort/MergeSort.h"
#include "../MergeSort/MergeSort.cpp"

#include <algorithm>
#include <cstdlib>

// Zachowuje tablic� niezmienion�, gdy ona jest ju� posortowana rosn�co
TEST(Sort, TabNiezmienionaRosnaco) {
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab();

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "Tablica zosta�a zmieniona przez algorytm na indeksie " << i;
	}
}


// Potrafi posortowa� tablic�, kt�ra jest posortowana w odwrotnej kolejno�ci
TEST(Sort, TabWOdwrotnejKolejnosci) {
	int tab[] = {9, 8, 7, 6, 5, 4, 11, 2, 1, 0};
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}

// Wy�wietlanie tablicy w celu sprawdzenia
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


// Poprawnie sortuje losow� tablic� liczb
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
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
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
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
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
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Obs�uguje pust� tablic� bez rzucania wyj�tkiem
TEST(Inicjalizuj, NieRzucaWyjatkiem) {
	int tab[] = { 0 };
	int size = sizeof(tab) / sizeof(tab[0]);

	ASSERT_NO_THROW(MergeSort arrayToSort(tab, size));
}


// Nie zmienia tablicy, kt�ra zawiera tylko jeden element
TEST(Sort, TabJednoelementowa) {
	int tab[] = { 42 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);
	int* tempArray = arrayToSort.getTab(); 

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablic� z duplikatami liczb
TEST(Sort, TabZDuplikatami) {
	int tab[] = { 4, 1, 4, 2, 1, 3, 4 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablice ujemn� z duplikatami
TEST(Sort, TabZUjemnymiDuplikatami) {
	int tab[] = { -5, -10, -5, -30, -5, -30, -4 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab));

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
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

	// Por�wnanie ka�dego elementu
	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje tablic� zawieraj�c� tylko dwa elementy w kolejno�ci rosn�cej
TEST(Sort, TabDwuelementowaRosnaca) {
	int tab[] = { 2, 1 };
	int size = sizeof(tab) / sizeof(tab[0]);

	MergeSort arrayToSort(tab, size);

	int* tempArray = arrayToSort.getTab();

	std::sort(std::begin(tab), std::end(tab)); // Sortowanie kontrolne

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje du�� tablic� zawieraj�c� ponad 100 element�w
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
		EXPECT_EQ(tab[i], tempArray[i]) << "B��d przy sortowaniu tablicy na indekse: " << i;
	}
}


// Poprawnie sortuje du�� tablic� zawieraj�c� ponad 100 element�w z liczbami ujemnymi, dodatnimi oraz duplikatami
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