#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("tstatura.txt");
class Magazin;
class Produs{
    char *denumire;
    int pret;
public:
    Produs(const Produs &prod)
    {
        ///constructor de copiere
        size_t len=strlen(prod.denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,prod.denumire);
        this->pret=prod.pret;
    }
    Produs(){
        denumire=nullptr;
        pret=0;}
    /*Produs(char *Denumire=NULL,int Pret=0){
        if(Denumire!=NULL)
        {this->denumire=new char[strlen(Denumire)];
            strcpy(denumire,Denumire);}
        else this->denumire=Denumire;
        this->pret=Pret;
    }*/

    Produs(const char* Denumire,int Pret)
    {
        ///constructor de initializare
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
        this->pret=Pret;
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
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
    }
    int getPret() const{
        return pret;
    }
    void setPret(int Pret){
        pret=Pret;
    }
    Produs& operator=(const Produs &rhs){
        ///operatorul  de atribuire
        if (this!=&rhs)
            setDenumire(rhs.denumire);
        this->pret=rhs.pret;
        return *this;
    }
    bool operator==(const  Produs &rhs) const{
        return strcmp(this->denumire,rhs.denumire) == 0 && this->pret==rhs.pret;
    }
    bool operator!=(const Produs &rhs) const {
        return !(rhs == *this);
    }
    friend std::ostream& operator<<(std::ostream &os , Produs p);
    friend std::istream& operator>>(std::istream &is , Produs &p);
    friend class Magazin;
};
ostream& operator<<(std::ostream &os , Produs p)
{
    if(!p.denumire){
        os<<"Not initialzed\n";
        return os;
    }
    os<<"Produs: denumire: "<<p.getDenumire()<<" pret: "<<p.getPret()<<"\n";
    return os;
}
istream& operator>>(std::istream &is , Produs &p)
{
    char buf[100];
    int x;
    is>>buf;
    p.setDenumire(buf);
    is>>x;
    p.setPret(x);
    return is;
}
class Magazin{
    char *denumire;
public:
    Produs p[100];
    Magazin(){
        denumire=nullptr;
    }
    Magazin(const char* Denumire){
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
    }
    Magazin(const Magazin &mag)
    {
        ///constructor de copiere
        size_t len=strlen(mag.denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,mag.denumire);

    }
    ~Magazin(){
        delete[] denumire;
    }
    Magazin& operator=(const Magazin &rhs){
        ///operatorul  de atribuire
        if (this!=&rhs)
            setDenumire(rhs.denumire);
        return *this;
    }
    char *getDenumire() const
    {
        return denumire;
    }
    void setDenumire(const char *Denumire)
    {
        size_t len=strlen(Denumire);
        this->denumire=new char[len+1];
        strcpy(denumire,Denumire);
    }
    friend std::ostream& operator<<(std::ostream &os , Magazin M);
    friend std::istream& operator>>(std::istream &is , Magazin &M);
};
ostream& operator<<(std::ostream &os , Magazin M)
{
    if(!M.denumire){
        os<<"Not initialzed\n";
        return os;
    }
    os<<M.getDenumire();
    return os;
}
istream& operator>>(std::istream &is , Magazin &M)
{
    char buf[100];
    is>>buf;
    M.setDenumire(buf);
    return is;
}
int main() {
    char buf[100];
    Magazin M;
    cout<<"Numele magazinului este ";
    fin>>buf;
    cout<<" si care contine un numar de ";
    int i,n;

    fin>>n;
    cout<<"produse . Acestea sunt :";
    for(i=1;i<=n;i++)
    {
        fin>>M.p[i];
        cout<<M.p[i];
    }

    return 0;
}
