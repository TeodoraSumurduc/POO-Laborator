#include "bacanie.h"
#include "DepasireCantitateDorita.h"
#include "NiciunProdus.h"
#include <iostream>
using namespace std;

Bacanie::Bacanie(const string &nume, int nrBucati, const string &animal) : Produs(nume, nrBucati), animal(animal) {
}

Bacanie::Bacanie(const Bacanie &b) : Produs(b.nume, b.nrBucati), animal(b.animal) {

}

Bacanie &Bacanie::operator=(const Bacanie &b) {
    Produs::operator=(b);
    animal = b.animal;
    return *this;
}

ProductType Bacanie::GetProdusType() const {
    return ProductType::Bacanie;
}

const std::string &Bacanie::getAnimal() const {
    return animal;
}

void Bacanie::setAnimal(const std::string &a) {
    Bacanie::animal = a;
}
std::ostream& operator<<(std::ostream &os ,const Bacanie &b)
{

    os<<"Produs: nume: "<<b.nume<<".\nnrBucatiul: "<<b.nrBucati<<".\nProvenienta animal: "<<b.animal<<".\n";
    return os;
}
std::istream& operator>>(std::istream &is , Bacanie &b)
{
    string a,y;
    int x;
    is>>a;
    b.setNume(a);
    is>>x;
    b.setNrBucati(x);
    is>>y;
    b.setAnimal(y);
    return is;
}






