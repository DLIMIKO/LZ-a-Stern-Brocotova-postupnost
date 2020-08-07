//
// Created by Matúš Nečas on 21/07/2020.
//

#include "linearny_zoznam.h"
#include <iostream>

/**
 * Názov funkcie: "vloz prvok na koniec"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * @param x hodnota prvku, kt. vkladáme
 *
 * Popis:
 * Funkcia sa najprv pozrie, či je daný zoznam prázdny:
 * --> Ak je zoznam prázdny, nastaví sa prvý a posledný prvok tohto zoznamu na hodnotu nového prvku
 *     a smerník "dalsi" na nullptr.
 * --> Ak už zoznam obsahuje nejaké prvky, tak sa smerník posledného prvku nastaví na nový prvok
 *     a následne sa nový prvok určí ako posledný prvok v zozname.
 */


void LZ::vloz_prvok_na_koniec(TZoznam &z, int x)
{
    auto *novy= new TPrvok; // vytvoríme pomocný smerník, kt. reprezentuje prvok, kt. pridávame

    novy->data=x;
    novy->dalsi= nullptr;

    if (z.prvy== nullptr)  //ak je zoznam prázdny ...
    {
        z.prvy=novy;
    }
    else //ak už LZ obsahuje zoznam nejaké prvky ...
    {
        z.posledny->dalsi=novy;
    }
    z.posledny=novy;
}

/**
 * Názov funkcie: "vloz prvok na zaciatok"
 *
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * @param x hodnota prvku, kt. vkladáme
 *
 * Popis:
 *
 * Funkcia sa najprv pozrie, či je daný zoznam prázdny:
 * --> Ak je zoznam prázdny, nastavia sa prvý a posledný prvok tohto zoznamu na hodnotu prvku, ktorú vkladáme
 *     a ich smerníky na nullptr.
 * --> Ak už zoznam obsahuje nejaké prvky, tak sa smerník nového prvku nastaví na prvý prvok
 *     a následne sa nový prvok určí ako prvý prvok.
 */

void LZ::vloz_prvok_na_zaciatok(TZoznam &z, int x)
{
    auto *novy=new TPrvok; // vytvoríme pomocný smerník, kt. reprezentuje prvok, kt. pridávame

    novy->data=x;
    novy->dalsi=nullptr;

    if (z.prvy== nullptr) //ak je zoznam prázdny ...
    {
        z.posledny=novy;
    }
    else //ak už LZ obsahuje nejaké prvky ...
    {
        novy->dalsi=z.prvy;
    }
    z.prvy=novy;

}

/**
 * Názov funkcie: "vloz prvok do zoznamu"
 *
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * @param x hodnota prvku, kt. vkladáme
 *
 * Popis:
 *
 * Funkcia sa najprv pozrie, či je daný zoznam prázdny:
 * --> Ak je zoznam prázdny, nastavia sa prvý a posledný prvok tohto zoznamu na hodnotu prvku, ktorú vkladáme
 *     a ich smerníky na nullptr.
 * --> Ak už zoznam obsahuje nejaké prvky, funkcia rozlišuje 3 rôzne situácie:
 *      1.) hodnota x je menšia ako hodnota prvého prvku:
 *           --> smerník nového prvku sa nastaví na prvý prvok a následne sa nový prvok určí ako 1. prvok
 *      2.) hodnota x je väčšia ako hodnota posledného prvku:
 *           --> smerník posledného prvku sa nastaví na nový prvok a následne sa nový prvok určí ako posledný prvok
 *      3.) hodnota x je z intervalu (prvy->data, posledny->data):
 *          -->funkcia si vytvorí dva pomocné smerníky p1, p2 a precháza zoznam, až nájde také dva prvky, že:
 *              p1->data<x && p2->data>x, potom presmeruje smerník p1 na nový prvok a smerník nového prvku na p2
 */

void LZ::vloz_do_zoznamu(TZoznam &z, int x)
{
    auto *novy=new TPrvok; // vytvoríme pomocný smerník, kt. reprezentuje prvok, kt. pridávame
    novy->data=x;
    novy->dalsi= nullptr;

    if (z.prvy== nullptr) //ak je zoznam prázdny
    {
        z.prvy=novy;
        z.posledny=novy;
    }
    else
    {
        if (x<z.prvy->data) //ak je x<prvy prvok ...
        {
            novy->dalsi=z.prvy;
            z.prvy=novy;
        }
        else if (x>z.posledny->data) //ak je x>poslaedny prvok ...
        {
            z.posledny->dalsi=novy;
            z.posledny=novy;
        }
        else // ak je x z intrvalu  (prvy prvok, posledny prvok) ...
        {
            TPrvok *p1=z.prvy;
            TPrvok *p2=z.prvy->dalsi;
            while (p2->data < x)
            {
                p1=p2;
                p2=p2->dalsi;
            }
            p1->dalsi=novy;
            novy->dalsi=p2;
        }
    }
}

/**
 * Názov funkcie: "hľadaj_v_zozname"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * @param x hodnota prvku, kt. hľadáme
 * @return TPrvok alebo nullptr
 *
 * Popis:
 * Funkcia prechádza zoznam a hľadá v ňom prvok s hodnotou x, ak ho nájde, tak ho vráti, ak nie vráti nullptr.
 */

LZ::TPrvok* LZ::hladaj_v_zozname(TZoznam z, int x)
{
    TPrvok *p=z.prvy;

    while (p!= nullptr) //opakuje až kým nepríde na koniec zoznamu
    {
        if(p->data==x)
        {
            return p;
        }
        p=p->dalsi;
    }
    return nullptr;
}
/**
 * Názov: "je_prazdny"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * @return pravdivostná hodnota bool
 *
 * Popis: Funkcia sa pozerá na prvý prvok, a ak zistí, že sa rovná nullptr, vráti 1(True).
 */

bool LZ::je_prazdny(TZoznam z)
{
    return z.prvy == nullptr;
}
/**
 * Názov: "vypis_zoznam"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * Popis: funkcia vypíše zoznam pomocou objektu cout vo formáte: (hodnota1, hodnota2, ...).
 */

void LZ::vypis_zoznam(TZoznam z)
{
    if (je_prazdny(z)) return;

    else
    {
        TPrvok *p=z.prvy;
        while(p->dalsi!= nullptr)
        {
            std::cout<<p->data<<", ";
            p=p->dalsi;
        }
        std::cout<<p->data<<std::endl;
    }
}
/**
 * Názov: "zmaz_prvy_prvok"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * Popis: Funkcia si najprv vytvorí pomocný smerník, do kt ukazuje na prvý prvok, následne ako prvý prvok určí druhý prvok
 * a vymaže dáta, na ktoré smerník ukazuje. Ak je zoznam prázdny, funkcia neurobí nič.
 */
void LZ::zmaz_prvy_prvok(TZoznam &z)
{
    if (z.prvy == nullptr) return; //ak je zoznam prázdny ...
    TPrvok *p=z.prvy; // vytvoríme pomocný smerník, kt. reprezentuje prvok, kt. pridávame
    z.prvy=p->dalsi;
    delete p;
}
/**
 * Názov: "zmaz_posledny_prvok"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 * Popis: funkcia si najprv vytvorí pomocný smerník, kt. ukazuje na prvý prvok, následne môžu nastať 3 situácie:
 *        1.) zoznam je prázdny:
 *        --> funkcia neurobí nič
 *        2.) v zozname je práve jeden prvok:
 *        --> funkcia vymaže dáta, na ktoré ukazuje smerník a nastaví smerníky prvy a posledny na nullptr
 *        3.) v zozname je viac ako jeden prvok:
 *        --> funkcia prechádza zoznam až na predposledný prvok, reinicializuje sa pomocný smerník na posledný prvok,
 *             zmažú sa dáta, na ktoré ukazuje, nastaví sa na nullptr a určí sa ako posledný prvok
 *
 */

void LZ::zmaz_posledny_prvok(TZoznam &z)
{
    if (z.prvy == nullptr) return;
    TPrvok *p=z.prvy; // vytvoríme pomocný smerník, kt. reprezentuje prvok, kt. pridávame
    if (p->dalsi == nullptr)
    {
        delete p;
        z.prvy= nullptr;
        z.posledny= nullptr;
        return;
    }
    while (p->dalsi->dalsi == nullptr)
    {
        p=p->dalsi;
    }
    delete p->dalsi;
    p->dalsi= nullptr;
    z.posledny=p;

}
/**
 * Názov: "zmaz_zoznam"
 *
 * @param z lineárny zoznam, s kt. pracujeme
 *
 * Popis:
 * Funkcia maže zoznam, pokiaľ nie je prázdny, pomocou funkcie zmaz_prvy_prvok -- mazanie spredu.
 * (fungovalo by aj mazanie pomocou metódy "zamaz posledný prvok", ale tá má komplikovanejšiu implementáciu)
 *
 */
void LZ::zmaz_zoznam(TZoznam &z)
{
    while(!LZ::je_prazdny(z))
    {
        LZ::zmaz_prvy_prvok(z);
    }
}
