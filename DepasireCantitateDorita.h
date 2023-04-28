//
// Created by TEODORA on 25.04.2023.
//

#ifndef _DEPASIRECANTITATEDORITA_H
#define _DEPASIRECANTITATEDORITA_H
#include <exception>

class DepasireCantitateDorita:public std::exception{
public:
    DepasireCantitateDorita();

    const char* what() const noexcept override;

};


#endif //_DEPASIRECANTITATEDORITA_H
