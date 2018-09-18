/*
 * Problem004
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <stdio.h>
int main() {

    int palindromInt = 0;
    char palindromChar[6];
    int najwiekszyPalindromInt = 0;

    int pierwszyCzynnik;
    int drugiCzynnik;

    const int najmniejszaLiczbaSzesciocyfrowa = 100000;

    //Każdy palidrom jest podzielny przez 11. Nie ma więc potrzeby sprawdzania każdej konfiguracji liczb.
    for (pierwszyCzynnik = 110; pierwszyCzynnik <= 990; pierwszyCzynnik = pierwszyCzynnik + 11)
    {
        for (drugiCzynnik = 100; drugiCzynnik <= 999; drugiCzynnik++)
        {
            palindromInt = pierwszyCzynnik * drugiCzynnik;
            //Wynik mnożenia dwóch liczb trzycyfrowych może mieć 5 albo 6 cyfr.
            //Po eksperymentalnym sprawdzeniu, że isnieje przynajmniej jeden palindom 6 cyfrowy, pomijamy sprawdzanie,
            //czy największy jest pięciocyfrowy.
            if(palindromInt >= najmniejszaLiczbaSzesciocyfrowa)
            {
                sprintf(palindromChar, "%d", palindromInt);
                if ((palindromChar[0] == palindromChar[5]) and
                    (palindromChar[1] == palindromChar[4]) and
                    (palindromChar[2] == palindromChar[3]) and
                    (palindromChar[0] != palindromChar[1]) and
                    (palindromChar[1] != palindromChar[2]) and
                    (palindromChar[0] != palindromChar[2]))
                {
                    if (najwiekszyPalindromInt < palindromInt)
                    {
                        najwiekszyPalindromInt = palindromInt;
                    }
                }
            }
        }
    }

    printf("Najwiekszy palindrom szesciocyfrowy to: %d", najwiekszyPalindromInt);

    return 0;
}

/*
 * The answer is 906609.
 */