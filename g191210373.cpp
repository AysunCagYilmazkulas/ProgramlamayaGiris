/****************************************************************************
**
**				OGRENCİ ADI.........:	AYSUN CAG YILMAZKULAS
**				OGRENCİ NUMARASI....:	G191210373
**				DERS GRUBU..........:	B 
**
****************************************************************************/
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
char karakterler[5] = {'*', '#', '$', '+', '@'};

int rasgeleSahneGenisligi;
int rasgeleSahneYuksekligi;
char rasgeleaKarakter;

struct Sahne
{
    int sabitSahneGenisligi;
    int sabitSahneYuksekligi;
    char sabitKarakter;

    Sahne(int sonSahneGenlisligi, int sonSahneYuksekligi, char sonKarakter)
    {
        sabitSahneGenisligi = sonSahneGenlisligi;
        sabitSahneYuksekligi = sonSahneYuksekligi;
        sabitKarakter = sonKarakter;
    }
};
struct LSekli
{
    int x;
    int y;
    int boyut;
    char lKarakter;

    LSekli()
    {
        y = 3;
        x = rand() % 21 + 5;
        boyut = (rand() % 6 + 2) * 2;
        lKarakter = karakterler[rand() % 5];
    }
};
void koordinatAta(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sahneCiz(Sahne sahneOlustur)
{
    for (int i = 0; i < sahneOlustur.sabitSahneGenisligi; i++)
    {
        cout << sahneOlustur.sabitKarakter;
    }
    for (int i = 0; i < sahneOlustur.sabitSahneYuksekligi; i++)
    {
        koordinatAta(sahneOlustur.sabitSahneGenisligi - 1, i);
        cout << sahneOlustur.sabitKarakter << endl;
    }
    for (int i = 0; i < sahneOlustur.sabitSahneGenisligi; i++)
    {
        koordinatAta(sahneOlustur.sabitSahneGenisligi - i - 1, sahneOlustur.sabitSahneYuksekligi - 1);
        cout << sahneOlustur.sabitKarakter;
    }
    for (int i = 0; i < sahneOlustur.sabitSahneYuksekligi; i++)
    {
        koordinatAta(0, sahneOlustur.sabitSahneYuksekligi - 1 - i);
        cout << sahneOlustur.sabitKarakter << endl;
    }
}
void lSekliCiz(LSekli lSekliOlustur)
{
    koordinatAta(lSekliOlustur.x, lSekliOlustur.y);
    for (int i = 0; i < lSekliOlustur.boyut / 2; i++)
    {
        cout << lSekliOlustur.lKarakter;
    }
    for (int i = 0; i < lSekliOlustur.boyut / 2 + 1; i++)
    {
        koordinatAta(lSekliOlustur.x + lSekliOlustur.boyut / 2 - 1, lSekliOlustur.y + i);
        cout << lSekliOlustur.lKarakter;
    }
    for (int i = 0; i < lSekliOlustur.boyut / 2; i++)
    {
        koordinatAta(lSekliOlustur.x + lSekliOlustur.boyut / 2 + i - 1, lSekliOlustur.y + lSekliOlustur.boyut / 2);
        cout << lSekliOlustur.lKarakter;
    }
    for (int i = 0; i < lSekliOlustur.boyut / 2; i++)
    {
        koordinatAta(lSekliOlustur.x + lSekliOlustur.boyut - 1, lSekliOlustur.y + lSekliOlustur.boyut / 2 + i);
        cout << lSekliOlustur.lKarakter;
    }
    for (int i = 0; i < lSekliOlustur.boyut; i++)
    {
        koordinatAta(lSekliOlustur.x + lSekliOlustur.boyut - i - 1, lSekliOlustur.y + lSekliOlustur.boyut);
        cout << lSekliOlustur.lKarakter;
    }
    for (int i = 0; i < lSekliOlustur.boyut; i++)
    {
        koordinatAta(lSekliOlustur.x, lSekliOlustur.y + lSekliOlustur.boyut - 1 - i);
        cout << lSekliOlustur.lKarakter << endl;
    }
}

LSekli lSekliAsagiGotur(LSekli, Sahne a, int yukseklik)
{
    LSekli lSekliOlustur;

    for (lSekliOlustur.y = 1; lSekliOlustur.y < yukseklik - lSekliOlustur.boyut - 1; lSekliOlustur.y++)
    {
        Sleep(50);
        koordinatAta(lSekliOlustur.x, lSekliOlustur.y);
        system("cls");
        sahneCiz(a);
        Sleep(50);
        koordinatAta(lSekliOlustur.x, lSekliOlustur.y + 1);
        lSekliCiz(lSekliOlustur);
    }

    return lSekliOlustur;
}
void kursoruGizle()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
    srand(time(0));
    rasgeleSahneGenisligi = (rand() % 3 + 3) * 10;
    rasgeleSahneYuksekligi = rand() % 11 + 20;
    rasgeleaKarakter = karakterler[rand() % 5];

    Sahne sahneOlustur(rasgeleSahneGenisligi, rasgeleSahneYuksekligi, rasgeleaKarakter);

    LSekli lSekliOlustur;
    kursoruGizle();


    while (true)
    {
        system("cls");

        sahneCiz(sahneOlustur);

        lSekliAsagiGotur(lSekliOlustur, sahneOlustur, sahneOlustur.sabitSahneYuksekligi);

        Sleep(200);
    }

    return 0;
}