#include "productos.h"
#include"cliente.h"
#include"usuario.h"

#include <string>


void arreaglo_de_objetos(productos*& producto, ifstream& inventario);
int contdor_productos(ifstream& inventario);

int menu();
int menuAdministrador();
void adminMetodos(administrador admin, ifstream& Lec, ofstream& EXP);

void modificar_arrays(productos*& producto, int nuevo_tama�o, ifstream& inventario);
void imprime_objeto(productos*& producto, int nuevo_tama�o);

string nosepara(string dato);
string separa(string dato);

void crea_cuenta_cliente(/*cliente*& clase_cliente,*/ ofstream& inventario);
void inciar_sesion(ifstream& inventario, cliente& cliente_1, administrador& administrador_1);