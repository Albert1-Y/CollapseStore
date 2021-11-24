#include "productos.h"
#include"cliente.h"
#include"usuario.h"
#include <string>
#include "administrador.h"

string nosepara(string dato);
string separa(string dato);

bool verifica_numero(string numero);


int contdor_productos(ifstream& inventario);


int contador_usuario(ifstream& inventario);


int menu();

int menuAdministrador();

void adminMetodos(productos*& producto, cliente*& cliente1, administrador admin, arrays_objetos& productos1, int tamano_users);

int menuCliente();

void clienteMetodos(cliente clienteM, productos*& producto, ifstream& Lec, ofstream& EXP);

void modificar_arrays(productos*& producto, int nuevo_tamaño, ifstream& inventario);

void crea_cuenta_cliente(/*cliente*& clase_cliente,*/ ofstream& inventario);

void inciar_sesion(ifstream& inventario, cliente& cliente_1, administrador& administrador_1);

void imprime_user_objeto(cliente*& cliente_1, int tamano);