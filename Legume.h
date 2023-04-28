//
// Created by TEODORA on 23.04.2023.
//

#ifndef _LEGUME_H
#define _LEGUME_H

#include "Produs.h"
#include <string>

class Legume : public Produs {
    std::string origine;
public:
    Legume(std::string nume, int nrBucati, std::string origine);

    Legume(const Legume& l);

    Legume& operator=(const Legume& l);

    ProductType GetProdusType() const override;


    const std::string &getOrigine() const ;

    void setOrigine(const std::string &origine);

    friend std::ostream& operator<<(std::ostream &os ,const Legume &l);
    friend std::istream& operator>>(std::istream &is , Legume &l);

};
#endif 
