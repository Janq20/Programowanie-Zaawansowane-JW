#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

/**
 * @brief Struktura reprezentujaca pojedynczy element listy dwukierunkowej.
 */
struct Wezel {
    int dane;           ///< Przechowuje wartosc elementu
    Wezel* nastepny;    ///< Wskaznik na kolejny element
    Wezel* poprzedni;   ///< Wskaznik na poprzedni element

    /**
     * @brief Konstruktor inicjalizujacy wezel.
     * @param wartosc wartosc przypisana do wezla
     */
    Wezel(int wartosc) : dane(wartosc), nastepny(nullptr), poprzedni(nullptr) {}
};

/**
 * @brief Klasa reprezentujaca liste dwukierunkowa.
 */
class ListaDwukierunkowa {
private:
    Wezel* glowa;   ///< Wskaznik na pierwszy element listy
    Wezel* ogon;    ///< Wskaznik na ostatni element listy

public:
    /**
     * @brief Konstruktor inicjujacy pusta liste.
     */
    ListaDwukierunkowa() : glowa(nullptr), ogon(nullptr) {}

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true jesli lista jest pusta, false w przeciwnym wypadku
     */
    bool isEmpty() {
        return glowa == nullptr;
    }

    /**
     * @brief Zwraca liczbe elementow w liscie.
     * @return liczba elementow typu int
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
     * @brief Dodaje nowy element na koniec listy.
     * @param wartosc wartosc do dodania
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
     * @brief Dodaje nowy element na poczatek listy.
     * @param wartosc wartosc do dodania
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
     * @brief Dodaje element pod wskazany indeks.
     * @param wartosc wartosc do dodania
     * @param indeks pozycja wstawienia (0 = poczatek listy)
     */
    void dodajPodIndeks(int wartosc, int indeks) {
        if (indeks <= 0) {
            dodajNaPoczatek(wartosc);
            return;
        }

        int licznik = 0;
        Wezel* temp = glowa;
        while (temp && licznik < indeks - 1) {
            temp = temp->nastepny;
            licznik++;
        }

        // jesli indeks poza zakresem lub lista pusta -> dodaj na koniec
        if (!temp || !temp->nastepny) {
            dodajNaKoniec(wartosc);
            return;
        }

        // wstawienie nowego wezla pomiedzy elementy
        Wezel* nowy = new Wezel(wartosc);
        nowy->nastepny = temp->nastepny;
        nowy->poprzedni = temp;
        temp->nastepny->poprzedni = nowy;
        temp->nastepny = nowy;
    }

    /**
     * @brief Wyswietla elementy listy od poczatku do konca.
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
     * @brief Wyswietla elementy listy od konca do poczatku.
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
     * @brief Destruktor zwalniajacy pamiec listy.
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
