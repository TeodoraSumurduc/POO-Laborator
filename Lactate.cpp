//
// Created by TEODORA on 23.04.2023.
//
#include "Lactate.h"
#include <iostream>
using namespace std;

Lactate::Lactate(const Lactate &l) : Produs(l.nume, l.nrBucati), procentGrasime(l.procentGrasime) {

}

Lactate &Lactate::operator=(const Lactate &d) {
    Produs::operator=(d);
    procentGrasime = d.procentGrasime;

    return *this;
}

ProductType Lactate::GetProdusType() const {
    return ProductType::Lactate;
}

int Lactate::getProcentGrasime() const {
    return procentGrasime;
}

void Lactate::setProcentGrasime(int procentGrasime) {
    Lactate::procentGrasime = procentGrasime;
}
std::ostream& operator<<(std::ostream &os ,const Lactate &l)
{

    os<<"Produs: nume: "<<l.nume<<".\nnrBucatiul: "<<l.nrBucati<<".\nProcentul de grasime: "<<l.procentGrasime<<".\n";
    return os;
}
std::istream& operator>>(std::istream &is , Lactate &l)
{
    string a;
    int x,y;
    is>>a;
    l.setNume(a);
    is>>x;
    l.setNrBucati(x);
    is>>y;
    l.setProcentGrasime(y);
    return is;
}

Lactate::Lactate(const string &nume, int nrBucati, int procentGrasime) : Produs(nume, nrBucati),
                                                                         procentGrasime(procentGrasime) {}





