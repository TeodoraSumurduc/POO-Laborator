#include "Legume.h"
#include <iostream>
using namespace std;

Legume::Legume(std::string nume, int nrBucati, std::string origine )
        : Produs(nume, nrBucati) // apel ct clasa baza
        , origine(origine) // alte date
{}


Legume::Legume(const Legume &f) : Produs(f.nume, f.nrBucati), origine(f.origine) {

}

Legume &Legume::operator=(const Legume &f) {
    Produs::operator=(f);
    origine = f.origine;
    return *this;
}

ProductType Legume::GetProdusType() const {
    return ProductType::Legume;
}

const std::string &Legume::getOrigine() const {
    return origine;
}

void Legume::setOrigine(const std::string &origine) {
    Legume::origine = origine;
}
std::ostream& operator<<(std::ostream &os ,const Legume &f)
{

    os<<"Produs: nume: "<<f.nume<<".\nnrBucatiul: "<<f.nrBucati<<".\nProvenienta : "<<f.origine<<".\n";
    return os;
}
std::istream& operator>>(std::istream &is , Legume &f)
{
    string a,y;
    int x;
    is>>a;
    f.setNume(a);
    is>>x;
    f.setNrBucati(x);
    is>>y;
    f.setOrigine(y);
    return is;
}