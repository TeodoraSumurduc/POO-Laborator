#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("tastatura.txt");
class Magazin;
class Produs{
    char *denumire;
    int nrBucati,stoc;
public:
    Produs(const Produs &prod)
    {
        ///constructor de copiere
        size_t len=strlen(prod.denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,prod.denumire);
        this->nrBucati=prod.nrBucati;
        this->stoc=prod.stoc;
    }
    Produs(){
        denumire=nullptr;
        nrBucati=0;
        stoc=0;
    }
    Produs(const char* Denumire,int NrBucati,int Stoc)
    {
        ///constructor de initializare
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
        this->nrBucati=NrBucati;
        this->stoc=Stoc;
    }
    ~Produs(){
        delete[] denumire;

    }

    char *getDenumire() const
    {
        return denumire;
    }
    void setDenumire(const char *Denumire)
    {
        delete[] this->denumire;
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
    }
    int getNrBucati() const{
        return nrBucati;
    }
    void setNrBucati(int NrBucati){
        nrBucati=NrBucati;
    }
    int getStoc() const{
        return stoc;
    }
    void setStoc(int Stoc){
        stoc=Stoc;
    }
    Produs& operator=(const Produs &rhs){
        ///operatorul  de atribuire
        if (this!=&rhs)
            setDenumire(rhs.denumire);
        this->nrBucati=rhs.nrBucati;
        this->stoc=rhs.stoc;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os ,const Produs &p);
    friend std::istream& operator>>(std::istream &is , Produs &p);
    friend class Magazin;
};
bool operator==(const  Produs &lhs,const  Produs &rhs) {
    return strcmp(lhs.getDenumire(),rhs.getDenumire()) == 0 && lhs.getNrBucati()==rhs.getNrBucati() && lhs.getStoc()==rhs.getStoc();
}
bool operator!=(const  Produs &lhs,const  Produs &rhs) {
    return strcmp(lhs.getDenumire(),rhs.getDenumire()) != 0 || lhs.getNrBucati()!=rhs.getNrBucati() || lhs.getStoc()!=rhs.getStoc();
}
ostream& operator<<(std::ostream &os ,const Produs &p)
{
    if(!p.getDenumire()){
        os<<"Not initialzed\n";
        return os;
    }
    os<<"Produs: denumire: "<<p.getDenumire()<<"\nNumarul de bucati: "<<p.getNrBucati()<<"\nNumarul de produse ramase in stoc:"<<p.getStoc();
    return os;
}
istream& operator>>(std::istream &is , Produs &p)
{
    char buf[100];
    int x,y;
    is>>buf;
    p.setDenumire(buf);
    is>>x;
    p.setNrBucati(x);
    is>>y;
    p.setStoc(y);
    return is;
}
class Magazin{
    char *nume,*strada;
    int nrStrada;
public:
    Produs p[100];
    Magazin(){
        nume=nullptr;
        strada=nullptr;
        nrStrada=0;
    }
    Magazin(const Magazin &mag)
    {
        ///constructor de copiere
        size_t len1=strlen(mag.nume);
        this->nume=new char[len1+1];
        strcpy(nume,mag.nume);
        size_t len2=strlen(mag.strada);
        this->strada=new char[len2+1];
        strcpy(strada,mag.strada);
        this->nrStrada=mag.nrStrada;
    }
    ~Magazin(){
        delete[] nume;
        delete[] strada;

    }
    Magazin& operator=(const Magazin &rhs){
        ///operatorul  de atribuire
        if (this!=&rhs)
        {
            setNume(rhs.nume);
            setStrada(rhs.strada);
        }
        this->nrStrada=rhs.nrStrada;
        return *this;
    }
    char *getNume() const
    {
        return nume;
    }
    void setNume(const char *Nume)
    {
        delete[] this->nume;
        size_t len=strlen(Nume);
        this->nume=new char[len+1];
        strcpy(nume,Nume);
    }
    char *getStrada() const
    {
        return strada;
    }
    void setStrada(const char *Strada)
    {
        delete[] this->strada;
        size_t len=strlen(Strada);
        this->strada=new char[len+1];
        strcpy(strada,Strada);
    }
    int getNrStrada() const{
        return nrStrada;
    }
    void setNrStrada(int NrStrada){
        nrStrada=NrStrada;
    }
    friend std::ostream& operator<<(std::ostream &os ,const Magazin &M);
    friend std::istream& operator>>(std::istream &is , Magazin &M);
};
ostream& operator<<(std::ostream &os ,const Magazin &M)
{
    if(!M.getNume() && !M.getStrada()){
        os<<"Not initialzed\n";
        return os;
    }
    os<<"Numele magazinului este: "<<M.getNume()<<"\n Se afla pe strada: "<<M.getStrada()<<" numarul "<<M.getNrStrada();
    return os;
}
istream& operator>>(std::istream &is , Magazin &M)
{
    char buf[100],buf1[100];
    cout<<"Numele magazinului este ";
    is>>buf;
    M.setNume(buf);
    cout<<"Se afla pe strada: ";
    is>>buf1;
    M.setStrada(buf1);
    cout<<"Numarul: ";
    int x;
    is>>x;
    M.setNrStrada(x);
    return is;
}
int main() {
    Magazin M;
    fin>>M;
    cout<<"Lista mea de cumparaturi contine  ";
    int i,n;
    char buf[100],r[100];
    fin>>n;
    cout<<"produse . Acestea sunt : ";
    for(i=1;i<=n;i++)
    {
        fin>>M.p[i];
        if(M.p[i].getNrBucati()>M.p[i].getStoc())
        {
            cout<<"Numarul dumneavoastra de bucati este mai mare decat stocul produsului.";
            cout<<"\nVreti sa mai cumparati produsul ?";
            fin>>buf;
            if(strcmp(buf,"da")==0)
            {
                cout<<M.p[i]<<"\nPentru ca nu avem stoc suficient, veti achizitiona "<<M.p[i].getStoc()<<" bucati.";
                cout<<"Sunteti de acord ?";
                fin>>r;
                if(strcmp(r,"da")==0)
                    cout<<"Produsul dumneavoastra a fost adaugat in cos.";
            }

        }
        else{
            cout<<"Produsul dumneavoastra se afla in stoc.Acesta a fost adaugat in cos.\n";
            cout<<M.p[i];
        }
    }
    cout<<"\nMultumim ca ati cumparat de la noi !";

    return 0;
}
