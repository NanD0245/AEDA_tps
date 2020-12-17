#ifndef SRC_VETERINARY_H_
#define SRC_VETERINARY_H_

#include <string>
using namespace std;

class Veterinary {
    string name;
    long codOrder;
public:
    /**
     * construtor da classe
     * @param nome nome do veterinário
     * @param cod código do veterinário
     */
    Veterinary(string nome, int cod);
    /**
     * função getName
     * @return retorna o nome do veterinario
     */
    string getName() const;
    /**
     * função getInfo
     * @return retorna o valor de todos os atributos do veterinário
     */
    string getInfo() const;
};


#endif /* SRC_VETERINARY_H_ */
