
#include "Cooperativa.h"

//TODO: Implementar corretamente o construtor e inicializacao da BST!
Cooperativa::Cooperativa():vinhos(Vinho("",0))
{}

bool Vinho::operator<(const Vinho &v1) const {
    if (ano > v1.getAno())
        return true;
    else if (ano == v1.getAno() && nome < v1.getNome())
        return true;
    return false;
}

void Cooperativa::addVinhos(const vector<Vinho> &vv) {
    for (const auto & it : vv) {
        vinhos.insert(it);
    }
}

list<string> Cooperativa::vinhosDisponiveis(int ano1, int ano2) {
    list<string> names;
    for (auto it = BSTItrIn<Vinho>(vinhos); !it.isAtEnd(); it.advance())
        if (it.retrieve().getAno() >= ano1 && it.retrieve().getAno() <= ano2)
            names.push_back(it.retrieve().getNome() + " " + to_string(it.retrieve().getAno()));
    if (names.empty())
        names.emplace_back("Indisponivel");
    else {
        names.sort();
        names.reverse();
    }
    return names;
}

int Cooperativa::delVinhoNome(string umVinho) {
    int count = 0;
    BST<Vinho> ar = vinhos;
    auto it = BSTItrIn<Vinho>(ar);
    while (!it.isAtEnd()) {
        if (it.retrieve().getNome() == umVinho) {
            Vinho a = it.retrieve();
            vinhos.remove(a);
            count++;
        }
        it.advance();
    }
    return count;
}

void Cooperativa::addVinicola(string umaVinicola) {
    for (auto it = vinicolas.begin(); it != vinicolas.end(); it++) {
        if (it->getNome() == umaVinicola) {
            Vinicola a = *it;
            vinicolas.erase(it);
            a.addVinho();
            vinicolas.insert(a);
            return;
        }
    }
    Vinicola a(umaVinicola);
    vinicolas.insert(a);
}

Vinicola Cooperativa::maisOpcoes() {
    Vinicola a("");
    for (const auto & vinicola : vinicolas) {
        if (a.getNome().empty())
            a = vinicola;
        else if (vinicola.getVinhos() > a.getVinhos())
            a = vinicola;
        else if (vinicola.getVinhos() == a.getVinhos() && vinicola.getNome() < vinicola.getNome())
            a = vinicola;
    }
    return a;
}

bool Enologo::operator<(const Enologo &e1) const {
    int count1 = 0, count2 = 0;
    for(const auto& elem: vinicolas){
        count1 += elem.getVinhos();
    }
    for(const auto& elem: e1.vinicolas){
        count2 += elem.getVinhos();
    }
    return count1 < count2;
}

void Cooperativa::addEnologoVinicola(string umEnologo, string umaVinicola) {
    priority_queue<Enologo> enologosTemp;
    bool added = false;
    while(!enologos.empty()){
        Enologo enologo = enologos.top();
        enologos.pop();
        if(enologo.getNome() == umEnologo){
            list<Vinicola>& vinicolass = enologo.getVinicolas();
            for(auto& elem: vinicolass){
                if(elem.getNome() == umaVinicola){
                    elem.addVinho();
                    added = true;
                }
            }if(!added) enologo.addVinicolaInexistente(Vinicola(umaVinicola));
            added = true;
        }
        enologosTemp.push(enologo);
    }
    if(!added){
        Enologo enologo(umEnologo);
        enologo.addVinicolaInexistente(Vinicola(umaVinicola));
        enologosTemp.push(enologo);
    }
    enologos = enologosTemp;
}

list<Vinicola> Cooperativa::vinicolasMelhoresNEnologos(int n) {
    list<Vinicola> a;
    priority_queue<Enologo> enologosTemp = enologos;
    while (!enologosTemp.empty() && n) {
        n--;
        Enologo enologo = enologosTemp.top();
        enologosTemp.pop();
        for (const auto &elem: enologo.getVinicolas()) {
            a.push_back(elem);
        }
    }
    return a;
}
