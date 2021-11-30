
#include <fstream>
#include"administrador.h"
#include "tarjeta_visa.h"
#include "cliente.h"
string nosepara(string dato);
string separa(string dato);

bool verifica_numero(string numero);

int contdor_productos(ifstream& inventario);

int contador_usuario(ifstream& inventario);

bool verifica_tarjeta(tarjeta_visa &tarjeta_1);

int menu();

int menuAdministrador();

void adminMetodos(arrays_objetos & producto, administrador admin, arrays_objetos& productos1, int tamano_users);

int menuCliente();

void clienteMetodos(cliente clienteM, arrays_objetos& producto1, ifstream& Lec, ofstream& EXP, carrito_compras& carrito1, tarjeta_visa tarjeta_1);

void crea_cuenta_cliente(/*cliente*& clase_cliente,*/ ofstream& inventario);

void inciar_sesion(ifstream& inventario, cliente& cliente_1, administrador& administrador_1);


void imprime_user_objeto(cliente*& cliente_1, int tamano);
void hacer_pago(tarjeta_visa& tarjeta1, carrito_compras &carrito1);
