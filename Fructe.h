
#ifndef _FRUCTE_H
#define _FRUCTE_H
#include "Produs.h"
#include <string>


class Fructe : public Produs {
    std::string origine;
public:
    Fructe(std::string nume, int nrBucati, std::string origine);

    Fructe(const Fructe& f);

    Fructe& operator=(const Fructe& f);



    ProductType GetProdusType() const override;


    const std::string &getOrigine() const ;

    void setOrigine(const std::string &origine);

    friend std::ostream& operator<<(std::ostream &os ,const Fructe &f);
    friend std::istream& operator>>(std::istream &is , Fructe &f);

};

#endif
