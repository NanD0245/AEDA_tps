#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : vagas(lot), lotacao(lot), numMaximoClientes(nMaxCli) {}

unsigned ParqueEstacionamento::getNumLugares() const {return lotacao; };

unsigned ParqueEstacionamento::getNumMaximoClientes() const {return numMaximoClientes; };

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
    for(size_t i=0;i < clientes.size(); i++) {
        if (clientes[i].nome == nome) {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
    if (posicaoCliente(nome) != -1)
        return false;
    if (clientes.size() == numMaximoClientes)
        return false;
    InfoCartao x;
    x.nome = nome;
    x.presente = 0;
    clientes.push_back(x);
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome) {
    int index = posicaoCliente(nome);
    if (index == -1)
        return false;
    else if (vagas == 0)
        return false;
    else if (clientes[index].presente)
        return false;
    else {
        vagas--;
        clientes[index].presente = true;
        return true;
    }
}

bool ParqueEstacionamento::retiraCliente(const string & nome) {
    int index = posicaoCliente(nome);
    if (clientes[index].presente)
        return false;
    clientes.erase(clientes.begin()+index);
    return true;
}

bool ParqueEstacionamento::sair(const string & nome) {
    int index = posicaoCliente(nome);
    if (index == -1)
        return false;
    if (!clientes[index].presente)
        return false;
    clientes[index].presente = false;
    vagas++;
    return true;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const {return lotacao-vagas; };

unsigned ParqueEstacionamento::getNumClientesAtuais() const {return clientes.size(); };