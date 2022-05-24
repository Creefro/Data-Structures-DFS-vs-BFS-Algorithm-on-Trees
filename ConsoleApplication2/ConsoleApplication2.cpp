// DataStructures Ödev 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "veri.h"
#include <chrono>

int main()
{
    int agacNo;
    int secim;
    std::string yontem;
    int deger;
    int* dizi = NULL;
    std::cout << "Arama yapacaginiz agaci seciniz (1,2,3):\n";
    std::cin >> agacNo;
    if (agacNo == 1) {
        dizi = dizi1;
    }
    else if (agacNo == 2) {
        dizi = dizi2;
    }
    else if (agacNo == 3) {
        dizi = dizi3;
    }
    else {
        std::cout << "Hatalý seçim\n";
    }
    std::cout << "\nAgac " << agacNo << " icin arama yontemini seciniz (DFS:1, BFS:2):\n";
    std::cin >> secim;
    if (secim == 1) {
        yontem = "DFS";
    }
    else if (secim == 2) {
        yontem = "BFS";
    }
    else
    {
        std::cout << "Hatalý seçim\n";
    }
    std::cout << "\nAgac " << agacNo << " uzerinde " << yontem << " ile arayacaginiz degeri giriniz:\n";
    std::cin >> deger;

    IkiliSiralamaAgaci* agac = new IkiliSiralamaAgaci;

    agac->agacKur(dizi);

    std::cout << "\nSONUC =>";

    auto begin = std::chrono::high_resolution_clock::now();
    if (yontem == "DFS") {
        if (DFS(agac->kok, deger))
        {
            std::cout << "VERI BULUNDU";
        }
        else {
            std::cout << "VERI BULUNAMADI";
        }
    }
    else {
        if (BFS(agac->kok, deger))
        {
            std::cout << "VERI BULUNDU";
        }
        else {
            std::cout << "VERI BULUNAMADI";
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "\nGECEN SURE =>  " << elapsed.count() << "  nano-saniye" << std::endl;

    agac->agacKapat();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
