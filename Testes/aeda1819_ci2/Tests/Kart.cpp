#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"
#include <algorithm>

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}

vector<CKart> CGrupo::ordenaKarts()
{
    vector<CKart> vord;
    for(auto elem: pistasG){
        for(const auto& kart: elem.getFrotaActual()){
            vord.push_back(kart);
        }
    }
    sort(vord.begin(),vord.end(),[](CKart& kart1 , CKart& kart2){
        return kart1.getNumero() < kart2.getNumero();
    });
    return vord;

}

int CGrupo::numAvariados(int cilind)
{
    int counter = 0;
    for(auto elem: pistasG){
        for(auto kart: elem.getKartsAvariados())
            if( ((int) kart.getCilindrada()) == cilind)
                counter++;
    }
    return counter;
}

bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    for(auto& elem: frotaKartsPista){
        if(numeroKarts){
            if(!elem.getAvariado() && elem.getCilindrada() == cilind){
                kartsLinhaPartida.push(elem);
                numeroKarts--;
            }
        }
        if(!numeroKarts)
            return true;
    }
    return false;
}


int CPista::inicioCorrida()
{
    while (!kartsLinhaPartida.empty()){
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
    }
    return kartsEmProva.size();
}

