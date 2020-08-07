#include <iostream>
#include <iomanip>
#include "linearny_zoznam.h"

using namespace LZ;
using std::cout;
using std::endl;
using std::setw;


/**
 * Meno: Matúš Nečas (ID: MAP04)
 * Názov projektu: "Stern-Brocotová postupnosť a jej implementácia v jazyku c++ s využitím lineárneho zoznamu"
 *
 * Princíp fungovania:
 *
 * Stern-Brocotová postupnosť je zadefinovaná týmto rekurntným určením:
 * a(1)=1, a(2)=1,
 * a(2k+1) = a(k+1)+a(k)       // každý nepárny člen väčší ako 1
 * a(2k+2) = a(k+1)           // každý párny člen väčí ako 2
 * k je z N {1,2,3,4,5, ...}
 *
 * Využitie Stern-brokotovej postupnosti:
 *
 * Ak spravíme podiel všetkých a(n+1)/a(n), kde n je z N, dostaneme všetky kladné racionálne čísla,
 * ktoré sa budú v zozname vyskytovať práve raz. K týmto číslam stačí pridať 0 a čísla k nim opačné, a máme
 * celú množinu Q.
 *
 *
 * Zdroje:
 * --> lineárny zoznam: http://www.kiwiki.info/index.php/Lineárny_zoznam
 * --> Stern-Brocotova postupnosť: https://isibalo.com/matematika/posloupnosti-a-nekonecne-rady/stern-brocotova-posloupnost
 */

// implementácia v c++:

int main()
{
    int const MAX_ITER = 20; //počet kladných čísel množiny Q
    TZoznam cisla{}; //zoznam na ukladanie postupnosti

    vloz_prvok_na_koniec(cisla, 1); //vloženie člena a(1)=1
    vloz_prvok_na_koniec(cisla, 1); //vloženie člena a(2)=1


    TPrvok *AN=cisla.prvy; //smerník na n-tý člen postupnosti
    TPrvok *AN1=cisla.prvy->dalsi; //smerník na n+1 člen postupnosti

    //cyklus for, kt. pridáva členy do zoznamu, keďže v každom kroku pridá 2 prvky, je definovaný iba po hodnotu MAX_ITER/2
    //zároveň je tak ošetrený problém "idex_out_of_boundaries_error"
    for (int k=0;k<MAX_ITER/2;++k) {
        vloz_prvok_na_koniec(cisla, AN1->data + AN->data); //pridanie nepárneho člena postupnosti
        vloz_prvok_na_koniec(cisla, AN1->data); //pridanie párneho člena postupnosti

        //postun na ďalší prvok v zozname
        AN = AN->dalsi;
        AN1 = AN1->dalsi;
    }

   //pre výstup musíme reinicializovať smerníky AN a AN1 na prvý a druhý prvok v zozname:
    AN=cisla.prvy;
    AN1=cisla.prvy->dalsi;

    //Hlavička výstupu:
    cout<<endl<<"Prvých "<<2*MAX_ITER+1<<" členov množiny Q:"<<endl
       <<"Q+"<<setw(12)<<" Q-"<<setw(12)<<"Q0 = 0"<<endl;

    //Výpis členov AN1/AN pre Q+ a Q-
    for (int i=0;i<MAX_ITER;++i)
    {
        cout<<AN1->data<<"/"<<AN->data<<setw(10)
            <<"-"<<AN1->data<<"/"<<AN->data<<endl;
        AN=AN->dalsi;
        AN1=AN1->dalsi;
    }


//Uvolnenie pamäte
    zmaz_zoznam(cisla);
}


