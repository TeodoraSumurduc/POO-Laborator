//
// Created by TEODORA on 24.04.2023.
//

#ifndef _LISTACUMPARATURI_H
#define _LISTACUMPARATURI_H
#include "Produs.h"
#include <memory>
#include <vector>

class ListaDepozit {
    static std::vector<std::shared_ptr<Produs>> lista;
    ListaDepozit();
public:
    static void AddProdus(const std::shared_ptr<Produs>& produs);

    static void PrintProduse();
    const int nrProduse();
};


#endif //_LISTACUMPARATURI_H
