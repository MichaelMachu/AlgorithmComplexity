#include <iostream>

int main()
{
    // Priklady slozitosti - https://cs.wikipedia.org/wiki/Asymptotick%C3%A1_slo%C5%BEitost

    int n = 10; // Slozitost se odviji podle velikosti vstupu

    // Cyklus for probehne pouze n-krat - proto O(n)
    for (int i = 0; i < n; i++)
    {

    }

    // Pro kazdy jeden pruchod "i" se provedou vsechny mozne pruchody "j" na zaklade velikosti "n", jedna se tedy o slozitost n * n => O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

        }
    }

    // n * n * n => O(n^3) atd..
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

            }
        }
    }

    // Obecne se musime divat, co se v cyklu deje, kolikrat se provede dany pruchod
    /*
        Pokud mame napriklad serazene pole {1, 1, 2, 3, 4, 4, 5, 5, 5, 6}, a provedeme priklad ze cviceni na vypocet modu, tak
    */

    int i = 0, modeFrequency = 0, modeValue = 0;

    // O(nlogn)
    //std::qsort(elements, elementsLength, sizeof(int), compare);   // provedeme setrizeni

    int elementsLength = 10;
    int elements[] = { 1, 1, 2, 3, 4, 4, 5, 5, 5, 6 };      // zde je nase setrizene pole
    //int elements[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };      // zde si muzete vyzkouset zdanlive nejhorsi pripad

    int j = 1;

    // O(n)
    while (i <= elementsLength - 1)     // pro tenhle cyklus se zamerujeme na parametr elementsLength, ktery je nase "n" a udava slozitost, jak lze videt, tak tenhle cyklus se provede n-krat, takze minimalni slozitost bude O(n)
    {
        int runLength = 1;
        int runValue = elements[i];

        // zde vidime, jak jsme si rikali na cyklu, ze cyklus projde pouze tehdy, je-li:
        /*
            =>  i + runLength <= elementsLength - 1 <= prohledavani nasledujici delky od elementu "i" je mensi nez velikosti pole (nechceme, aby doslo k presahu)
            => elements[i + runLength] == runValue  <= a zaroven plati, ze nasledujici elementy v poli, na ktere se divam maji stejnou hodnotu, jako aktualni prvek (hledam spolecne prvky)

            V takovem pripade, pokud jsem splnil podminky, tak inkrementuji parametr runLength.

            Zde muzete videt, ze i kdybychom meli pole obrovske s nahodnymi daty, tak celkovy pocet shodnych hodnot v porovnani celkovou velikosti elementsLength bude velmi nizky, az v podstate zanedbatelny.
            Navic dojde i k preskoceni jiz prictenych hodnot viz nize.

            Mohl byste si ale rict, co kdyby data obsahovala pouze jednu hodnotu jako napriklad { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, pak by tenhle vnoreny cyklus musel projit n-krat?
            No, podivejte se na posledni radek v cyklu, ktery obsahuje i = i + runLength; zde se v podstate inkrementuje vnejsi cyklus na zaklade posunu o shodne hodnoty, ktere se nachazi vedle sebe,
            diky tomu pak dojde k preskoceni az na konec pole a cyklus skonci, takze sice vnitrni cyklus while probehne n-krat, ale vnejsi probehne pouze jednou, diky tomu pak opet zustava slozitost O(n).
        */
        while (i + runLength <= elementsLength - 1 && elements[i + runLength] == runValue) 
        {
            runLength = runLength + 1;

            // pridame parametr "j", abychom videli, kolikrat dojde k prubehu
            std::cout << j << ". pruchod" << std::endl;
            j++;
        }

        if (runLength > modeFrequency)
        {
            modeFrequency = runLength;
            modeValue = runValue;
        }
        i = i + runLength;
    }

    // Obecne plati, ze musite krokovat samotny algoritmus a divat se, co se na zaklade velikosti vstupu deje, dulezite jsou pro vas cykly a rekurze!! 
    // Obycejne ukladani do promenne jako X = 5 nema vyznam, to stejne i podminky, cykly a rekurze jsou to, co je pomale (opakujete prikazy nekolikrat)

    return 0;
}