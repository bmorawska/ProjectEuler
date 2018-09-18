/*
 * Problem003
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <vector>

int main() {

    //Sito erastotenesa
    int rozmiarSita = 10000;
    long int liczbaDoRozkladu = 600851475143;
    bool *sito = new bool[rozmiarSita];
    bool czyZnalezionoWszystkieCzynniki = false;
    for (int pozycjaWSicie  = 0; pozycjaWSicie < rozmiarSita; pozycjaWSicie++) {
        sito[pozycjaWSicie] = true;         //Każda liczba w sicie jest początkowo uznawana za pierwszą.
    }
    std::vector<int> czynnikiPierwszeWektor;

    for(int czynnikPierwszy = 2; czynnikPierwszy < rozmiarSita; czynnikPierwszy++) {          //Zaczynamy od 2, bo 1 i 0 nie są liczbami pierwszymi, a popsułyby algorytm.
        if ((sito[czynnikPierwszy] == true) and (liczbaDoRozkladu % czynnikPierwszy == 0)) {
            czynnikiPierwszeWektor.push_back(czynnikPierwszy);
            liczbaDoRozkladu /= czynnikPierwszy;
            if (liczbaDoRozkladu == 1) {
                czyZnalezionoWszystkieCzynniki = true;
                break;
            }
            czynnikPierwszy--;                       //Możliwe jest, że ten sam czynnik wystąpi więcej niż raz, wtedy powtarzamy procedurę
            continue;
        }
        // Zgodnie z myślą sita Erastotenesa usuwamy wielokrotności naszego czynnika
        for(int j = czynnikPierwszy + 1; j < rozmiarSita; j++) {
            if ((sito[j] == true) and (j % czynnikPierwszy == 0)) {
                sito[j] = false;
            }
        }
    }

    //Wypisywanie zawartości wektora
    for (unsigned short s = 0; s < czynnikiPierwszeWektor.size(); s++) {
        std::cout << czynnikiPierwszeWektor[s] << " ";
    }
    if (czyZnalezionoWszystkieCzynniki) {
        std:: cout << "\nZnaleziono wszystkie czynniki." << std::endl;
    }
    else {
        std:: cout << "\nNie znaleziono wszystkich czynnikow. Zwieksz rozmiarSita." << std::endl;
    }

    std::cout << "\nNajwiekszy czynnik to: " << *(czynnikiPierwszeWektor.end() - 1) << std:: endl;


    //Zwalnianie pamięci i usuwanie danych.
    czynnikiPierwszeWektor.clear();
    delete []sito;

    return 0;
}

/*
 * The answer is 6857.
 */