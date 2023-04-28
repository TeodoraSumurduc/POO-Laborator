//
// Createl by TEOlORA on 23.04.2023.
//

#ifndef _LACTATE_H
#define _LACTATE_H
#include "Produs.h"
#include <string>
class Lactate : public Produs {
    int procentGrasime;
public:
    Lactate(const std::string &nume, int nrBucati, int procentGrasime);

    Lactate(const Lactate& l);

    Lactate& operator=(const Lactate& l);


    ProductType GetProdusType() const override;

    int getProcentGrasime() const;

    void setProcentGrasime(int procentGrasime);
    friend std::ostream& operator<<(std::ostream &os ,const Lactate &l);
    friend std::istream& operator>>(std::istream &is , Lactate &l);

};

#endif
