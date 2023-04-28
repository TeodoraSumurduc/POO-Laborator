#include <iostream>
#include <string>
#include "Produs.h"
#include "Lactate.h"
#include "bacanie.h"
#include "Legume.h"
#include "Fructe.h"
#include "ProductType.h"
#include "ListaDepozit.h"
#include "DepasireCantitateDorita.h"
#include "NiciunProdus.h"
#include "fstream"

using namespace std;
std::ifstream file(R"(C:\\Users\\TEODORA\\Desktop\\Anul I sem II\\POO\\Laborator\\Tema 2\\tastatura.txt)");
void meniu(){
    std::cout<<"Vreti sa introduceti in depozit produse de bacanie ?\nDaca raspunsul este da , apasati tasta 1:";
    int afirmare;
    file>>afirmare;
    std::cout<<afirmare;
    if(afirmare==1)
    {
        std::cout<<"Cate produse de bacanie vreti sa introduceti ?";
        int n1,nrBuc;
        std::string nume,animal;
        file>>n1;

        for(int i=1;i<=n1;i++)
        {
            std::cout<<"Introduceti denumirea : ";
            file>>nume;
            std::cout<<"Introduceti numarul de bucati : ";
            file>>nrBuc;
            std::cout<<"Introduceti animalul :";
            file>>animal;
            try{
                Produs *p=new Bacanie(nume, nrBuc,animal);

                Bacanie *b=dynamic_cast<Bacanie*>(p);
                auto x=std::make_shared<Bacanie>(b->getNume(),b->getNrBucati(),b->getAnimal());

                ListaDepozit::AddProdus(x);}
            catch(const DepasireCantitateDorita &d){
                std::cout<<d.what()<<"\n";
            }
            catch(const NiciunProdus &n){
                std::cout<<n.what()<<"\n";
            }
        }
    }
    std::cout<<"Vreti sa introduceti in depozit produse lactate?\nDaca raspunsul este da , apasati tasta 1:";
    file>>afirmare;
    if(afirmare==1)
    {
        std::cout<<"Cate produse lactate vreti sa introduceti ?";
        int n2,nrBuc;
        float procent;
        std::string nume;
        file>>n2;

        for(int i=1;i<=n2;i++)
        {
            std::cout<<"Introduceti denumirea : ";
            file>>nume;
            std::cout<<"Introduceti numarul de bucati : ";
            file>>nrBuc;
            std::cout<<"Procentul de grasime :";
            file>>procent;
            try{
                Produs *p=new Lactate(nume, nrBuc,procent);

                Lactate *b=dynamic_cast<Lactate*>(p);
                auto x=std::make_shared<Lactate>(b->getNume(),b->getNrBucati(),b->getProcentGrasime());

                ListaDepozit::AddProdus(x);}
            catch(const DepasireCantitateDorita &d){
                std::cout<<d.what()<<"\n";
            }
            catch(const NiciunProdus &n){
                std::cout<<n.what()<<"\n";
            }
        }
    }
    std::cout<<"Vreti sa introduceti in depozit produse legume?\nDaca raspunsul este da , apasati tasta 1:";
    file>>afirmare;
    if(afirmare==1)
    {
        std::cout<<"Cate produse legume vreti sa introduceti ?";
        int n3,nrBuc;
        std::string nume,origine;
        file>>n3;

        for(int i=1;i<=n3;i++)
        {
            std::cout<<"Introduceti denumirea : ";
            file>>nume;
            std::cout<<"Introduceti numarul de bucati : ";
            file>>nrBuc;
            std::cout<<"Introduceti originea:";
            file>>origine;
            try{
                Produs *p=new Legume(nume, nrBuc,origine);

                Legume *b=dynamic_cast<Legume*>(p);
                auto x=std::make_shared<Legume>(b->getNume(),b->getNrBucati(),b->getOrigine());

                ListaDepozit::AddProdus(x);}
            catch(const DepasireCantitateDorita &d){
                std::cout<<d.what()<<"\n";
            }
            catch(const NiciunProdus &n){
                std::cout<<n.what()<<"\n";
            }
        }
    }
    std::cout<<"Vreti sa introduceti in depozit produse fructe?\nDaca raspunsul este da , apasati tasta 1:";
    file>>afirmare;
    if(afirmare==1)
    {
        std::cout<<"Cate produse fructe vreti sa introduceti ?";
        int n4,nrBuc;
        std::string nume,origine;
        file>>n4;

        for(int i=1;i<=n4;i++)
        {
            std::cout<<"Introduceti denumirea : ";
            file>>nume;
            std::cout<<"Introduceti numarul de bucati : ";
            file>>nrBuc;
            std::cout<<"Introduceti originea:";
            file>>origine;
            try{
                Produs *p=new Fructe(nume, nrBuc,origine);

                Fructe *b=dynamic_cast<Fructe*>(p);
                auto x=std::make_shared<Fructe>(b->getNume(),b->getNrBucati(),b->getOrigine());

                ListaDepozit::AddProdus(x);}
            catch(const DepasireCantitateDorita &d){
                std::cout<<d.what()<<"\n";
            }
            catch(const NiciunProdus &n) {
                std::cout << n.what() << "\n";
            }
        }
    }
    ListaDepozit::PrintProduse();
}

int main() {
    meniu();

    return 0;
}

