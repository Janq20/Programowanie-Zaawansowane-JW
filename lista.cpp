#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== TEST LISTY DWUKIERUNKOWEJ ===" << endl;

    // Tworzenie listy przez fabric
    ListaDwukierunkowa* lista = ListaFactory::stworzListe();
    cout << "Utworzono nowa liste przez fabryke." << endl;

    // Dodawanie elementów
    lista->dodajNaPoczatek(10);
    lista->dodajNaKoniec(20);
    lista->dodajNaKoniec(30);
    lista->dodajPodIndeks(15, 1);
    lista->dodajPodIndeks(25, 3);

    cout << "\nZawartosc listy (od poczatku):" << endl;
    lista->wyswietlOdPoczatku();

    cout << "\nZawartosc listy (od konca):" << endl;
    lista->wyswietlOdKonca();

    cout << "\nLiczba elementow: " << lista->liczbaElementow() << endl;

    // Test iteratora od początku
    cout << "\n=== Test iteratora od poczatku ===" << endl;
    Iterator it = lista->begin();
    while (it.valid()) {
        cout << it.wartosc() << " ";
        it.nastepny();
    }
    cout << endl;

    // Test iteratora od końca
    cout << "\n=== Test iteratora od konca ===" << endl;
    Iterator it2 = lista->end();
    while (it2.valid()) {
        cout << it2.wartosc() << " ";
        it2.poprzedni();
    }
    cout << endl;

    // Test usuwania elementów
    cout << "\nUsuwam element z poczatku i konca..." << endl;
    lista->usunZPoczatku();
    lista->usunZKonca();

    cout << "\nLista po usunieciu pierwszego i ostatniego elementu:" << endl;
    lista->wyswietlOdPoczatku();

    // Czyszczenie listy
    cout << "\nCzyszcze cala liste..." << endl;
    lista->czyscListe();
    lista->wyswietlOdPoczatku();

    cout << "\nCzy lista jest pusta? " << (lista->isEmpty() ? "Tak" : "Nie") << endl;

    // Zwolnienie pamięci przez fabrykę
    ListaFactory::usunListe(lista);
    cout << "\nZakonczono testy." << endl;

    return 0;
}
