#ifndef _PRODUS_H
#define _PRODUS_H
#include "ProductType.h"
#include <string>
#include <ostream>
class Produs {
protected:
    std::string nume;
    int nrBucati;
public:

    Produs(std::string nume, int nrBucati);

    Produs();

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    int getNrBucati() const;

    void setNrBucati(int nrBucati);



    friend std::ostream& operator<<(std::ostream &os ,const Produs &p);
    friend std::istream& operator>>(std::istream &is , Produs &p);

    virtual ProductType GetProdusType() const = 0;



    virtual ~Produs();
};

#endif
