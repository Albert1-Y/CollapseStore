#include "productos.h"
#include"cliente.h"
#include"usuario.h"
#include <string>


string nosepara(string dato);
string separa(string dato);

bool verifica_numero(string numero);

void arreaglo_de_objetos(productos*& producto, ifstream& inventario);

void areglos_de_usuarios(cliente*& cliente_1, ifstream& inventario);

int contdor_productos(ifstream& inventario);

int contdor_usuario(ifstream& inventario);

int menu();

int menuAdministrador();

void adminMetodos(cliente*& cliente1, administrador admin, ifstream& Lec, ofstream& EXP, int tamano_users);

int menuCliente();

void clienteMetodos(cliente clienteM, productos*& producto, ifstream& Lec, ofstream& EXP);

void modificar_arrays(productos*& producto, int nuevo_tamaño, ifstream& inventario);


void crea_cuenta_cliente(/*cliente*& clase_cliente,*/ ofstream& inventario);
void inciar_sesion(ifstream& inventario, cliente& cliente_1, administrador& administrador_1);
void imprime_user_objeto(cliente*& cliente_1, int tamano);