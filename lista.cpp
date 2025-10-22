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

    // Wyświetlenie listy od początku i od końca
    lista.wyswietlOdPoczatku();
    lista.wyswietlOdKonca();

    // Sprawdzenie liczby elementów
    cout << "Liczba elementow w liscie: " << lista.liczbaElementow() << endl;

    // Sprawdzenie, czy lista nadal jest pusta
    cout << "Czy lista jest pusta po dodaniu elementow? " << (lista.isEmpty() ? "TAK" : "NIE") << endl;

    cout << "=== Koniec testu ===" << endl;
    return 0;
}
