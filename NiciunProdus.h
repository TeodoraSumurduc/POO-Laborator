//
// Created by TEODORA on 26.04.2023.
//

#ifndef _NICIUNPRODUS_H
#define _NICIUNPRODUS_H
#include <exception>

class NiciunProdus :public std::exception{
public:
    NiciunProdus();
    const char* what()const noexcept override;

};


#endif //_NICIUNPRODUS_H
