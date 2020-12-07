#include "fleet.h"
#include "vehicle.h"
#include <iostream>

int main() {
    Fleet f;
    Vehicle *v1 =new Car("Fiat",5,1997,"gasolina",1200);
    Vehicle *v2= new Truck("Ford",3,1999,"gasolina",1400,1000);
    Vehicle *v3=new Car("Renault",9,1997,"gasoleo",1300);
    Vehicle *v4=new Bicycle("XX",4,2002,"TodoTerreno");
    f.addVehicle(v1);
    f.addVehicle(v2);
    f.addVehicle(v3);
    f.addVehicle(v4);
    std::cout << f.numVehicles() << std::endl;
    return 0;
}
