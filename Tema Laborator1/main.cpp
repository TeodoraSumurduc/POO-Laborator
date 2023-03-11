#include <iostream>
#include <cstring>
using namespace std;

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

    Produs(char *Denumire=NULL,int Pret=10){
        if(Denumire!=NULL)
        {this->denumire=new char[strlen(Denumire)];
        strcpy(denumire,Denumire);}
        else this->denumire=Denumire;
    }

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
    friend std::ostream& operator<<(std::ostream &os , Produs &p);
    friend std::istream& operator>>(std::istream &is , Produs &p);

};
ostream& operator<<(std::ostream &os , Produs &p)
{
    if(!p.denumire){
        os<<"Not initialzed\n";
        return os;
    }
    os<<"Produs: denumire: "<<p.denumire<<" pret: "<<p.pret<<"\n";
    return os;
}
istream& operator>>(std::istream &is , Produs &p)
{
    char buf[100];
    is>>buf;
    p.setDenumire(buf);
    is>>p.pret;
    return is;
}

int main() {

    Produs p[100];
    int i,n;
    cout<<"n=";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
        cout<<p[i];
    }

    return 0;
}
