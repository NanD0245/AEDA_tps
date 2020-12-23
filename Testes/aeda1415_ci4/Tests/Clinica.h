
#ifndef CLINICA_H_
#define CLINICA_H_

#include <string>
#include <list>
#include <sstream>
#include <tr1/unordered_set>
#include "BST.h"
#include <algorithm>


class Animal {
	string nome;
	string especie;
	int numConsultas;
public:
	Animal(string umNome, string umaEspecie, int numeroConsultas=0);
	string getNome() const;
	string getEspecie() const;
	int getNumConsultas() const;
	void incNumConsultas();
};

class Veterinario {
	string nome;
	list<string> meusAnimais;
public:
	Veterinario(string umNome);
	string getNome() const;
	list<string> getAnimais() const;
	void addAnimal(string umNomeAnimal);

	//TODO: A implementar (vide ficheiro CPP)
	bool operator<(const Veterinario& v1) const;
};

class Consulta {
	int hora, dia, mes;
	string nomeAnimal;
public:
	Consulta(int umaHora, int umDia, int umMes, string umNomeAnimal="");
	string getNomeAnimal() const;
	int getHora() const;
	int getDia() const;
	int getMes() const;

	//TODO: A implementar (vide ficheiro CPP)
	bool operator < (const Consulta &c2) const;
};

class ConsultasVet {
public:
	string nomeVeterinario;
	BST<Consulta> minhasConsultas;
	ConsultasVet(string umNomeVet);
	void addConsulta(const Consulta &c1);

};



struct hAnimal {
	int operator()(const Animal& a1) const{
		//TODO: Implementar a funcao de dispersao e substituir corretamente o valor do return!
		int v = 0;
		for (char i : a1.getNome())
		    v = 37*v + i;
		return v;
	}
	bool operator()(const Animal& a1, const Animal& a2) const {
		//TODO: Implementar a funcao de igualdade e substituir corretamente o valor do return!
		return a1.getNome() == a2.getNome();
	}
};

typedef tr1::unordered_set<Animal, hAnimal, hAnimal> hashAnimal;

class Clinica {
	list<ConsultasVet> consultasDisponiveis;
	hashAnimal animais;
	priority_queue<Veterinario> veterinarios;
public:
	Clinica();
	list<ConsultasVet> getConsultasDisponiveis() const;
	hashAnimal getAnimais() const;
	priority_queue<Veterinario> getVeterinarios() const;
	void addConsultasDisponiveisVet(const ConsultasVet &v1);
	void addAnimal(const Animal &a1);
	void addVeterinario(const Veterinario &v1);

	//TODO: a realizar de acordo com o solicitado nas respectivas al�neas!

	void addConsultas(const vector<Consulta> consultas1, string nomeVet) {
        for (ConsultasVet consulta: consultasDisponiveis) {
            if (consulta.nomeVeterinario == nomeVet) {
                for (const Consulta& cons : consultas1)
                    consulta.addConsulta(cons);
                return;
            }
        }
        ConsultasVet a(nomeVet);
        for (Consulta cons : consultas1)
            a.addConsulta(cons);
        consultasDisponiveis.push_front(a);
	}

	list<Consulta> veConsultasDisponiveis(int dia1, int dia2, int mesC, string nomeVet) const {
	    list<Consulta> a;
        for (ConsultasVet elem : consultasDisponiveis) {
            if (elem.nomeVeterinario == nomeVet)  {
                for (auto it = BSTItrIn<Consulta>(elem.minhasConsultas); !it.isAtEnd();it.advance()) {
                    if (it.retrieve().getMes() == mesC && it.retrieve().getDia() >= dia1 && it.retrieve().getDia() <= dia2)
                        a.push_back(it.retrieve());
                }
                return a;
            }
        }
	    return a;
	}

	bool marcaConsulta(int &horaC, int &diaC, int &mesC, string nomeAnimal, string nomeVet) {
        for (auto it = consultasDisponiveis.begin(); it != consultasDisponiveis.end(); it++) {
            if (it->nomeVeterinario == nomeVet) {
                auto consultas = BSTItrIn<Consulta>(it->minhasConsultas);
                while (!consultas.isAtEnd()) {
                    if (consultas.retrieve().getHora() >= horaC && consultas.retrieve().getDia() == diaC && consultas.retrieve().getMes() == mesC) {
                        horaC = consultas.retrieve().getHora();
                        it->minhasConsultas.remove(consultas.retrieve());
                        return true;
                    }
                    else if (consultas.retrieve().getDia() > diaC && consultas.retrieve().getMes() == mesC) {
                        horaC = consultas.retrieve().getHora();
                        diaC = consultas.retrieve().getDia();
                        it->minhasConsultas.remove(consultas.retrieve());
                        return true;
                    }
                    else if (consultas.retrieve().getMes() > mesC) {
                        horaC = consultas.retrieve().getHora();
                        diaC = consultas.retrieve().getDia();
                        mesC = consultas.retrieve().getMes();
                        it->minhasConsultas.remove(consultas.retrieve());
                        return true;
                    }
                    consultas.advance();
                }
            }
        }
        return false;
	}

	Animal fimConsulta(string umNomeAnimal, string umNomeEspecie) {
	    Animal a(umNomeAnimal,umNomeEspecie,1);
	    bool check = false;
	    for (auto it = animais.begin(); it != animais.end(); it++) {
	        if (it->getNome() == umNomeAnimal) {
	            a = *it;
	            animais.erase(it);
	            a.incNumConsultas();
	            animais.insert(a);
	            return a;
	        }
	    }
	    animais.insert(a);
	    return a;
	}

	int numAnimaisEspecie(string umNomeEspecie) const {
	    int count = 0;
	    for (Animal animal:animais){
	        if (animal.getEspecie() == umNomeEspecie)
	            count++;
	    }
	    return count;
	}

	Veterinario alocaVeterinario(string umNomeAnimal) {
	    Veterinario a = veterinarios.top();
	    veterinarios.pop();
	    a.addAnimal(umNomeAnimal);
	    veterinarios.push(a);
	    return a;
	}

	list<string> veterinariosMaisN(int n) const {
	    list<string> names;
        priority_queue<Veterinario> a = veterinarios;
	    while (!a.empty()) {
	        if (a.top().getAnimais().size() > n)
	            names.push_front(a.top().getNome());
	        a.pop();
	    }
	    /*vector<Veterinario> vets;
	    while (!a.empty()) {
	        if (a.top().getAnimais().size() > n)
	            vets.push_back(a.top());
	        a.pop();
	    }
        sort(vets.begin(), vets.end(),[](Veterinario a, Veterinario b){
            return a.getAnimais().size()>b.getAnimais().size();
        });
        for (Veterinario vet : vets)
            names.push_back(vet.getNome()); */
	    return names;
	}

};

#endif /* CLINICA_H_ */
