#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

/**
 * @brief Struktura reprezentująca pojedynczy element listy.
 */
struct Wezel {
    int dane;           ///< Przechowuje wartość elementu
    Wezel* nastepny;    ///< Wskaźnik na kolejny element
    Wezel* poprzedni;   ///< Wskaźnik na poprzedni element

    /**
     * @brief Konstruktor inicjalizujący węzeł
     * @param wartosc wartość przypisana do węzła
     */
    Wezel(int wartosc) : dane(wartosc), nastepny(nullptr), poprzedni(nullptr) {}
};

/**
 * @brief Klasa reprezentująca listę dwukierunkową.
 */
class ListaDwukierunkowa {
private:
    Wezel* glowa;   ///< Wskaźnik na pierwszy element
    Wezel* ogon;    ///< Wskaźnik na ostatni element

public:
    /**
     * @brief Konstruktor inicjujący pustą listę
     */
    ListaDwukierunkowa() : glowa(nullptr), ogon(nullptr) {}

    /**
     * @brief Sprawdza, czy lista jest pusta
     * @return true jeśli lista jest pusta, false w przeciwnym wypadku
     */
    bool isEmpty() {
        return glowa == nullptr;
    }

    /**
     * @brief Zwraca liczbę elementów w liście
     * @return liczba elementów typu int
     */
    int liczbaElementow() {
        int licznik = 0;
        Wezel* temp = glowa;
        while (temp) {
            licznik++;
            temp = temp->nastepny;
        }
        return licznik;
    }

    /**
     * @brief Dodaje nowy element na koniec listy
     * @param wartosc wartość do dodania
     */
    void dodajNaKoniec(int wartosc) {
        Wezel* nowy = new Wezel(wartosc);
        if (!glowa) {
            glowa = ogon = nowy;
        } else {
            ogon->nastepny = nowy;
            nowy->poprzedni = ogon;
            ogon = nowy;
        }
    }

    /**
     * @brief Dodaje nowy element na początek listy
     * @param wartosc wartość do dodania
     */
    void dodajNaPoczatek(int wartosc) {
        Wezel* nowy = new Wezel(wartosc);
        if (!glowa) {
            glowa = ogon = nowy;
        } else {
            nowy->nastepny = glowa;
            glowa->poprzedni = nowy;
            glowa = nowy;
        }
    }

    /**
     * @brief Wyświetla elementy listy od początku do końca
     */
    void wyswietlOdPoczatku() {
        cout << "Lista od poczatku: ";
        Wezel* temp = glowa;
        while (temp) {
            cout << temp->dane << " ";
            temp = temp->nastepny;
        }
        cout << endl;
    }

    /**
     * @brief Wyświetla elementy listy od końca do początku
     */
    void wyswietlOdKonca() {
        cout << "Lista od konca: ";
        Wezel* temp = ogon;
        while (temp) {
            cout << temp->dane << " ";
            temp = temp->poprzedni;
        }
        cout << endl;
    }

    /**
     * @brief Destruktor zwalniający pamięć listy
     */
    ~ListaDwukierunkowa() {
        Wezel* aktualny = glowa;
        while (aktualny) {
            Wezel* nastepny = aktualny->nastepny;
            delete aktualny;
            aktualny = nastepny;
        }
        glowa = ogon = nullptr;
        cout << "Pamiec zostala zwolniona." << endl;
    }
};

#endif
