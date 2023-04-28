//
// Created by TEODORA on 23.04.2023.
//

#ifndef BACANIE_H
#define BACANIE_H
#include "Produs.h"
#include <string>

class Bacanie : public Produs {
    std::string animal;
public:

    Bacanie(const std::string &nume, int nrBucati, const std::string &animal);

    Bacanie(const Bacanie& b);

    Bacanie& operator=(const Bacanie& b);



    ProductType GetProdusType() const override;


    const std::string &getAnimal() const ;

    void setAnimal(const std::string &animal);

    friend std::ostream& operator<<(std::ostream &os ,const Bacanie &b);
    friend std::istream& operator>>(std::istream &is , Bacanie &b);


};

#endif
