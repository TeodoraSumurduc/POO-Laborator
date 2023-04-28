#include "Fructe.h"
#include <iostream>
using namespace std;

Fructe::Fructe(std::string nume, int nrBucati, std::string origine )
        : Produs(nume, nrBucati) // apel ct clasa baza
        , origine(origine) // alte date
{}



Fructe::Fructe(const Fructe &f) : Produs(f.nume, f.nrBucati), origine(f.origine) {

}

Fructe &Fructe::operator=(const Fructe &f) {
    Produs::operator=(f);
    origine = f.origine;
    return *this;
}

ProductType Fructe::GetProdusType() const {
    return ProductType::Fructe;
}

const std::string &Fructe::getOrigine() const {
    return origine;
}

void Fructe::setOrigine(const std::string &origine) {
    Fructe::origine = origine;
}
std::ostream& operator<<(std::ostream &os ,const Fructe &f)
{

    os<<"Produs: nume: "<<f.nume<<".\nnrBucatiul: "<<f.nrBucati<<".\nProvenienta : "<<f.origine<<".\n";
    return os;
}
std::istream& operator>>(std::istream &is , Fructe &f)
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