#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

/**
 * @brief Struktura reprezentująca pojedynczy element listy dwukierunkowej.
 */
struct Wezel {
    int dane;           ///< Przechowuje wartość elementu
    Wezel* nastepny;    ///< Wskaźnik na kolejny element
    Wezel* poprzedni;   ///< Wskaźnik na poprzedni element

    /**
     * @brief Konstruktor inicjalizujący węzeł.
     * @param wartosc wartość przypisana do węzła
     */
    Wezel(int wartosc) : dane(wartosc), nastepny(nullptr), poprzedni(nullptr) {}
};

/**
 * @brief Klasa iteratora listy dwukierunkowej.
 * Pozwala na iterowanie po elementach listy w przód i w tył.
 */
class Iterator {
private:
    Wezel* aktualny; ///< Wskaźnik na aktualny element

public:
    /**
     * @brief Konstruktor iteratora.
     * @param start wskaźnik na początkowy element listy
     */
    Iterator(Wezel* start) : aktualny(start) {}

    /**
     * @brief Sprawdza, czy istnieje następny element.
     * @return true jeśli istnieje, false w przeciwnym razie
     */
    bool maNastepny() {
        return aktualny && aktualny->nastepny;
    }

    /**
     * @brief Sprawdza, czy istnieje poprzedni element.
     * @return true jeśli istnieje, false w przeciwnym razie
     */
    bool maPoprzedni() {
        return aktualny && aktualny->poprzedni;
    }

    /**
     * @brief Przechodzi do następnego elementu.
     * @return iterator ustawiony na następny element
     */
    Iterator& nastepny() {
        if (aktualny) aktualny = aktualny->nastepny;
        return *this;
    }

    /**
     * @brief Przechodzi do poprzedniego elementu.
     * @return iterator ustawiony na poprzedni element
     */
    Iterator& poprzedni() {
        if (aktualny) aktualny = aktualny->poprzedni;
        return *this;
    }

    /**
     * @brief Zwraca wartość aktualnego elementu.
     * @return wartość typu int
     */
    int wartosc() const {
        return aktualny ? aktualny->dane : -1;
    }

    /**
     * @brief Sprawdza, czy iterator jest ważny.
     * @return true jeśli wskazuje na element, false jeśli nullptr
     */
    bool valid() const {
        return aktualny != nullptr;
    }
};

/**
 * @brief Klasa reprezentująca listę dwukierunkową.
 */
class ListaDwukierunkowa {
private:
    Wezel* glowa;   ///< Wskaźnik na pierwszy element listy
    Wezel* ogon;    ///< Wskaźnik na ostatni element listy

public:
    /**
     * @brief Konstruktor inicjujący pustą listę.
     */
    ListaDwukierunkowa() : glowa(nullptr), ogon(nullptr) {}

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true jeśli lista jest pusta, false w przeciwnym wypadku
     */
    bool isEmpty() {
        return glowa == nullptr;
    }

    /**
     * @brief Zwraca liczbę elementów w liście.
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
     * @brief Dodaje nowy element na koniec listy.
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
     * @brief Dodaje nowy element na początek listy.
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
     * @brief Dodaje element pod wskazany indeks.
     * @param wartosc wartość do dodania
     * @param indeks pozycja wstawienia (0 = początek listy)
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

        if (!temp || !temp->nastepny) {
            dodajNaKoniec(wartosc);
            return;
        }

        Wezel* nowy = new Wezel(wartosc);
        nowy->nastepny = temp->nastepny;
        nowy->poprzedni = temp;
        temp->nastepny->poprzedni = nowy;
        temp->nastepny = nowy;
    }

    /**
     * @brief Usuwa element z początku listy.
     */
    void usunZPoczatku() {
        if (!glowa) return;
        Wezel* temp = glowa;
        glowa = glowa->nastepny;
        if (glowa) glowa->poprzedni = nullptr;
        else ogon = nullptr;
        delete temp;
    }

    /**
     * @brief Usuwa element z końca listy.
     */
    void usunZKonca() {
        if (!ogon) return;
        Wezel* temp = ogon;
        ogon = ogon->poprzedni;
        if (ogon) ogon->nastepny = nullptr;
        else glowa = nullptr;
        delete temp;
    }

    /**
     * @brief Usuwa element pod wskazanym indeksem.
     * @param indeks indeks elementu do usunięcia (0 = początek)
     */
    void usunPodIndeks(int indeks) {
        if (!glowa || indeks < 0) return;

        if (indeks == 0) {
            usunZPoczatku();
            return;
        }

        int licznik = 0;
        Wezel* temp = glowa;
        while (temp && licznik < indeks) {
            temp = temp->nastepny;
            licznik++;
        }

        if (!temp) return; // poza zakresem

        if (temp == ogon) {
            usunZKonca();
            return;
        }

        temp->poprzedni->nastepny = temp->nastepny;
        temp->nastepny->poprzedni = temp->poprzedni;
        delete temp;
    }

    /**
     * @brief Czyści całą listę.
     */
    void czyscListe() {
        while (glowa) {
            usunZPoczatku();
        }
    }

    /**
     * @brief Zwraca iterator ustawiony na pierwszy element.
     * @return iterator wskazujący początek listy
     */
    Iterator begin() {
        return Iterator(glowa);
    }

    /**
     * @brief Zwraca iterator ustawiony na ostatni element.
     * @return iterator wskazujący koniec listy
     */
    Iterator end() {
        return Iterator(ogon);
    }

    /**
     * @brief Wyświetla elementy listy od początku do końca.
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
     * @brief Wyświetla elementy listy od końca do początku.
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
     * @brief Destruktor zwalniający pamięć listy.
     */
    ~ListaDwukierunkowa() {
        czyscListe();
        cout << "Pamiec zostala zwolniona." << endl;
    }
};

/**
 * @brief Klasa fabryki (Factory) do tworzenia list dwukierunkowych.
 */
class ListaFactory {
public:
    /**
     * @brief Tworzy nową listę dwukierunkową i zwraca wskaźnik do niej.
     * @return wskaźnik na nową instancję klasy ListaDwukierunkowa
     */
    static ListaDwukierunkowa* stworzListe() {
        return new ListaDwukierunkowa();
    }

    /**
     * @brief Usuwa wskazaną listę i zwalnia pamięć.
     * @param lista wskaźnik na listę do usunięcia
     */
    static void usunListe(ListaDwukierunkowa* lista) {
        delete lista;
    }
};

#endif
