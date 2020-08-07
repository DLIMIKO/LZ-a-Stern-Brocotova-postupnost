//
// Created by Matúš Nečas on 21/07/2020.
//

#ifndef LZOZNAM_LINEARNY_ZOZNAM_H
#define LZOZNAM_LINEARNY_ZOZNAM_H

/**
 * Lineárny zoznam, definíica a jeho vlastnosti:
 *
 * --> LZ je dynamická dátová štruktúra, obsahujúca jednu alebo viacero štruktúr (položiek),
 *     navzájom lineárne previazané odkazmi pomocou smerníkov a referencií.
 *
 * --> Každý prvok v zozname obsahuje určitú hodnotu (v našom prípade typ int) a smerník na iný prvok.
 *
 * --> typy zoznamov:
 *      1.) jednosmerný (každý prvok odkazuje na ďalší prvok, posledný na tzv. zarážku, v našom prípade nullptr)
 *      2.) obojstranný (každý prvok odkazuje na ďalší a predchádzajúci prvok, na začiatku aj na konci je zarážka)
 *      3.) kruhový (keď posledný prvok odkazuje na prvý)
 *
 *      Poznámka: My budeme v tomto projekte používať jednosmerný zoznam typu int.
 *
 * --> Vlastnosti:
 *      1.) LZ je pamäťovo nenáročná štruktúra
 *      2.) možno zoskupiť ľubovoľný počet prvkov, limitovaní sme iba pamäťovou kapacitou počítača (RAM)
 *      3.) dokáže ľahko meniť svoju veľkosť počas behu programu
 *      4.) prvky zoznamu, na rozdiel od polí, nie sú uložené vedľa seba, ale v pamäti sú alokované podľa toho,
 *          kde je práve dostatok miesta
 *      5.) všetky prvky (tak ako pri poli) musia byť rovnakého typu
 *
 */

namespace LZ
{
   /**
    * Štruktúra charakterizujúca daný prvok v zozname:
    *   int data = hodnota prvku typu int
    *   TPrvok *dalsi = smerník na ďalší prvok
    */

    struct TPrvok
    {
        int data;
        TPrvok *dalsi;
    };

    /**
     * Štruktúra charakterizujúca lineárny zoznam:
     *  TPrvok *prvy  = smerník na prvý prvok v zozname
     *  TPrvok *posledny = smerník na posledný prvok v zozname
     */

    struct TZoznam
    {
        TPrvok *prvy;
        TPrvok *posledny;
    };

    /**
     * Práca s LZ:
     * --> prvky prvy, posledny a dalsi su ukazovatele na TPrvok
     * --> časť štruktúry TPrvok data môže byť ľubovoľný dátový typ
     * --> ak je zoznam prázdny, tak smerníky prvy(TZoznam) a posledny(TZoznam) ukazujú na  nullptr (čiže nikam)
     * --> ak zoznam obsahuje práve 1 prvok, tak prvy(TZoznam) aj posledny(TZoznam) ukazujú na tento prvok a
     *     smerník dalsi(TPrvok) na nullptr
     * --> ak je v zozname >2 prvkov, tak:
     *      smernik prvy(TZoznam) ukazuje na prvý prvok v zozname
     *      smerník posledny(TZoznam) ukazuje na posledny prvok v zozname
     *      smernik dalsi(TPrvok) prvého prvku ukazuje na druhý prvok v zozname
     *      smernik dalsi(TPrvok) posledného prvku ukazuje na nullptr
     *
     */


   // Metódy pracujúce s LZ:

    void vloz_prvok_na_koniec(TZoznam &z, int x);       // metóda pridá prvok na koniec zoznamu
    void vloz_prvok_na_zaciatok(TZoznam &z, int x);     // metóda pridá prvok na začiatok zoznamu
    void vloz_do_zoznamu(TZoznam &z, int x);            // metóda vloží prvok do usporiadaného zoznamu
                                                        // (od najmenšieho po najväčší)

    TPrvok* hladaj_v_zozname(TZoznam z, int x);         // metóda vyhľadá prvok v zozname podľa jeho hodnoty
    bool je_prazdny(TZoznam z);                         // metóda, kt. určí, či je zoznam prázdny
    void vypis_zoznam(TZoznam z);                       // metóda vypíše zoznam

    void zmaz_prvy_prvok(TZoznam &z);                   // metóda zmaže prvý prvok
    void zmaz_posledny_prvok(TZoznam &z);               // metóda zmaže posledný prvok
    void zmaz_zoznam(TZoznam &z);                       // metóda zmaže celý zoznam

}

#endif //LZOZNAM_LINEARNY_ZOZNAM_H
