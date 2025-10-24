#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    cout << "=== Test listy dwukierunkowej ===" << endl;

    ListaDwukierunkowa lista;

    // Sprawdzenie, czy lista jest pusta
    cout << "Czy lista jest pusta? " << (lista.isEmpty() ? "TAK" : "NIE") << endl;

    // Dodanie elementów na koniec listy
    lista.dodajNaKoniec(10);
    lista.dodajNaKoniec(20);
    lista.dodajNaKoniec(30);

    // Dodanie elementów na początek listy
    lista.dodajNaPoczatek(5);
    lista.dodajNaPoczatek(1);

    cout << "\nLista po dodaniu elementow na poczatek i koniec:" << endl;
    lista.wyswietlOdPoczatku();
    lista.wyswietlOdKonca();

    // Sprawdzenie liczby elementów
    cout << "Liczba elementow w liscie: " << lista.liczbaElementow() << endl;

    // Dodanie elementu pod wskazany indeks
    cout << "\nDodajemy element 99 pod indeks 2:" << endl;
    lista.dodajPodIndeks(99, 2);
    lista.wyswietlOdPoczatku();

    cout << "\nDodajemy element 77 pod indeks 0 (poczatek):" << endl;
    lista.dodajPodIndeks(77, 0);
    lista.wyswietlOdPoczatku();

    cout << "\nDodajemy element 88 pod indeks 100 (koniec):" << endl;
    lista.dodajPodIndeks(88, 100);
    lista.wyswietlOdPoczatku();

    // Sprawdzenie, czy lista nadal jest pusta
    cout << "\nCzy lista jest pusta po dodaniu elementow? " 
         << (lista.isEmpty() ? "TAK" : "NIE") << endl;

    cout << "Liczba elementow w liscie po wszystkich operacjach: " 
         << lista.liczbaElementow() << endl;

    cout << "=== Koniec testu ===" << endl;
    return 0;
}
