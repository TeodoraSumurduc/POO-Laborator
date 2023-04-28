#include "Produs.h"
#include "DepasireCantitateDorita.h"
#include "NiciunProdus.h"
#include <iostream>
#include <utility>
using namespace std;


const std::string &Produs::getNume() const {
    return nume;
}

void Produs::setNume(const std::string &nume) {
    Produs::nume = nume;
}

int Produs::getNrBucati() const {
    return nrBucati;
}

void Produs::setNrBucati(int nrBucati) {
    Produs::nrBucati = nrBucati;
}
std::ostream& operator<<(std::ostream &os ,const Produs &p)
{

    os<<"Produs: nume: "<<p.nume<<"\nnrBucatiul: "<<p.nrBucati<<"\n";
    return os;
}
std::istream& operator>>(std::istream &is , Produs &p)
{
    char buf[100];
    int x;
    is>>buf;
    p.setNume(buf);
    is>>x;
    p.setNrBucati(x);

    return is;
}


Produs::~Produs()= default;

Produs::Produs(string nume,int nrBucati) : nume(std::move(nume)),nrBucati(nrBucati) {
    if(nrBucati>100)
        throw DepasireCantitateDorita();
    else {
        if(nrBucati==0)
            throw NiciunProdus();
    }
}
