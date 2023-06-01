#include <iostream>
#include <string>
#include <vector>
using namespace std;
class exceptie_pret:public std::exception{
public:
    exceptie_pret();
    const char* what() const noexcept override;
};
exceptie_pret::exceptie_pret()=default;
const char* exceptie_pret::what() const noexcept{
    return "Pretul trebuie sa fie pozitiv!\n";
}
class exceptie_bucati:public std::exception{
public:
    exceptie_bucati();
    const char* what() const noexcept override;
};
exceptie_bucati::exceptie_bucati() {}

const char *exceptie_bucati::what() const noexcept {
    return "Numarul de bucati nu poate fi negativ";
}
template<typename T>
class Id{
    static int id;
public:
    static int generareId();
};

template<typename T>
int Id<T>::id=0;

template<typename T>
int Id<T>::generareId() {
    return id++;
}

class Produs{
protected:
    string denumire;
    double pret;
    int nr_bucati;
public:
    Produs( const string &denumire, double pret,int nr_bucati);
    virtual void afisare() const=0;
    virtual Produs* clone() const=0;

    virtual ~Produs();

    friend ostream &operator<<(ostream &os, const Produs &produs);
};

Produs::Produs( const string &denumire, double pret,int nr_bucati) : denumire(denumire), pret(pret),nr_bucati(nr_bucati) {
    if(pret<0)
        throw exceptie_pret();
    if(nr_bucati<0)
        throw exceptie_bucati();
}

ostream &operator<<(ostream &os, const Produs &produs) {
    produs.afisare();
    return os;
}

Produs::~Produs() {

}

class Carti:public Produs{
    string autor,editura;
public:
    Carti( const string &denumire, double pret,int nr_bucati, const string &autor, const string &editura);

    void afisare() const override;
    Carti* clone() const override;

    friend ostream &operator<<(ostream &os, const Carti &carti);
};


void Carti::afisare() const{
    cout<<"Cartea: "<<denumire<<"\nAutor: "<<autor<<"\nEditura: "<<editura<<"\nNumarul de bucati: "<<nr_bucati<<"\n";
}

Carti *Carti::clone() const {
    return new Carti(*this);
}
Carti::Carti( const string &denumire, double pret,int nr_bucati, const string &autor, const string &editura) : Produs(denumire,pret,nr_bucati),
                                                                                                               autor(autor),
                                                                                                        editura(editura) {}

ostream &operator<<(ostream &os, const Carti &carti) {
    carti.afisare();
    return os;
}


class Alimente: public Produs{
    string categorie;
public:
    Alimente( const string &denumire, double pret,int nr_bucati, const string &categorie);
    void afisare() const override;
    Alimente* clone() const override;

    friend ostream &operator<<(ostream &os, const Alimente &alimente);
};

Alimente::Alimente( const string &denumire, double pret,int nr_bucati, const string &categorie) : Produs( denumire, pret,nr_bucati),
                                                                                           categorie(categorie) {}
void Alimente::afisare() const {
    cout<<"Aliment: "<<denumire<<"\nPret: "<<pret<<"\nCategorie: "<<categorie<<"\n";
}
Alimente *Alimente::clone() const {
    return new Alimente(*this);
}

ostream &operator<<(ostream &os, const Alimente &alimente) {
    alimente.afisare();
    return os;
}

class Inventar{
    vector<Produs*> produse;
    Inventar();
public:
    static Inventar& getI(){
        static Inventar i;
        return i;
    }
    void AddProdus(Produs* produs){
        produse.push_back(produs);
    }
    void AfisareProduse(){
        for(const auto &p:produse)
        {
            cout<<*p<<"\n";
        }
    }
};
class Customer{
    string nume;
    Customer(const string &nume);
public:
    static Customer& getInstance(const std::string& name);
    void afisare();
    string &getNume();
};
Customer::Customer(const std::string &nume):nume(nume) {}

Customer &Customer::getInstance(const std::string &name) {
    static Customer instance(name);
    return instance;
}

 string &Customer::getNume(){
    return nume;
}

void Customer::afisare() {
    cout<<"Nume: "<<nume<<"\n";
}
class Comanda{
    vector<Produs*> p;
    Customer& c;
    Comanda( Customer &c);
public:
    static Comanda& getInstance(Comanda& c);
    void addProdus(Produs* p);
    void afisare();

    const vector<Produs *> &getP() const;

    Customer &getC() const;
};

Comanda::Comanda( Customer &c) : c(c) {}

Comanda &Comanda::getInstance(Comanda &c) {
    static Comanda instance(c);
    return instance;
}

void Comanda::addProdus(Produs *pr) {
    p.push_back(pr);
}

void Comanda::afisare() {
    cout<<"Customer: "<<c.getNume()<<"\nProduse: "<<"\n";
    for (const auto& pr:p) {
        Carti* carti = dynamic_cast<Carti*>(pr);
        if (carti != nullptr) {
            carti->afisare();
        } else {
            Alimente* alimente = dynamic_cast<Alimente*>(pr);
            if (alimente != nullptr) {
                alimente->afisare();
            } else {
                cout << "Tipul produsului este necunoscut." << endl;
            }
        }
}}

Customer &Comanda::getC() const {
    return c;
}

const vector<Produs *> &Comanda::getP() const {
    return p;
}

template<typename T>
void afisareTotal(const Comanda& comanda) {
    Customer& customer = comanda.getC();
    cout<<"Customer: "<< customer.getNume()<< "\nProduse: "<<"\n";

    for (auto& pr : comanda.getP()) {
        try {
            T *produs = dynamic_cast<const T *>(pr);
            if (produs != nullptr) {
                produs->afisare();
                cout << "Total: " << produs->pret * produs->nr_bucati << endl;
            } else {
                cout << "Tipul produsului este necunoscut." << endl;
            }
        }catch(const exceptie_pret& pret){
            cout<<pret.what()<<endl;
        }
        catch(const exceptie_bucati& buc){
            cout<<buc.what()<<endl;
        }
    }
}
int main() {
    return 0;
}
