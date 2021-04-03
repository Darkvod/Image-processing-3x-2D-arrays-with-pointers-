#include <iostream>
#include <cmath>
using namespace std;

void wypiszTabliceChar(unsigned char *tablica)
{
    for(int i=0;i<90;i++)
    {
        if(i%6==0) cout << endl;
        cout << (int) *tablica << "\t";
        tablica++;
        if(i==29 || i==59)cout<<endl;
    }
}


void wypiszTabliceDouble(double *tablica)
{
    for(int i=0;i<90;i++)
    {
        if(i%6==0) cout << endl;
        cout << *tablica << "\t";
        tablica++;
        if(i==29 || i==59)cout<<endl;
    }
}


void wypelnienieTablicy(unsigned char *tab)
{
    for (int i=0;i<90;i++)
    {
        if(i<30) *tab=3;
        else if(i>=30 && i<60) *tab=5;
        else *tab=247;
        tab++;
    }
}

void logarytmArr(double *tab)
{
    for (int i=0;i<90;i++) {
        *tab = log2(*tab);
        tab++;
    }
}

void Normalizacja(double *tab)
{
    int min=0, max=255;
    double arr_max = 7.94837, arr_min = 1.58496;
    for (int i=0;i<90;i++)
    {
        *tab = (*tab - arr_min) / (arr_max - arr_min) * (max - min) + min;
        *tab = round(*tab);
        tab++;
    }
}

int main() {

    unsigned char *obraz = new unsigned char[3*5*6];
    double *obrazpom = new double[3*5*6];

    //wypelnienie liczbami
    wypelnienieTablicy(obraz);

    //wypis tablicy z char
    wypiszTabliceChar(obraz);

    cout<<endl<<endl<<endl<<"Tablica po logarytmowaniu:";

    //kopiowanie tablicy unsigned char -> double
    copy(obraz,obraz+90,obrazpom);

    //logarytmowanie
    logarytmArr(obrazpom);

    cout <<endl<<endl;
    //wypis przekopiowanej i pologarytmowanej tablicy
    wypiszTabliceDouble(obrazpom);

    //Normalizacja tablicy
    Normalizacja(obrazpom);

    //kopiowanie tablicy unsigned double -> char
    copy(obrazpom,obrazpom+90,obraz);

    cout <<endl<<endl<< "Tablica po normalizacji i zaokragleniu: " << endl;
    //wypis tablicy Obraz
    wypiszTabliceChar(obraz);

    return 0;
}
