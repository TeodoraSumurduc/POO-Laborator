//
// Created by TEODORA on 24.04.2023.
//
#include "ListaDepozit.h"
#include <iostream>
std::vector<std::shared_ptr<Produs>> ListaDepozit::lista;
ListaDepozit::ListaDepozit() = default;

void ListaDepozit::AddProdus(const std::shared_ptr<Produs>& produs) {
    lista.push_back(produs);
}
void ListaDepozit::PrintProduse() {
    for(auto &produs:ListaDepozit::lista)
    {
        std::cout<<*produs<<"\n";

    }
}
const int ListaDepozit::nrProduse() {
    int nr=0;
    for(auto &produs:ListaDepozit::lista)
        nr++;
    return nr;
}
