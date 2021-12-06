
#include <fstream>
#include"administrador.h"
#include "tarjeta_visa.h"
#include "cliente.h"


string nosepara(string dato);

string separa(string dato);

bool verifica_numero(string numero);

int contdor_productos(ifstream& inventario);

int contador_usuario();

bool verifica_tarjeta(tarjeta_visa &tarjeta_1);

int menu_inicial();

int menuAdministrador();

void adminMetodos(arrays_objetos & producto, administrador& admin, arrays_objetos& productos1,ifstream &lec);

int menuCliente();

void clienteMetodos(cliente& clienteM, arrays_objetos& producto1, ifstream& Lec, ofstream& EXP, tarjeta_visa & tarjeta_1);

void crea_cuenta_cliente(cliente & cliente_1);

void inciar_sesion(ifstream& inventario, cliente& cliente_1, administrador& administrador_1);

void menu_hacer_pago(tarjeta_visa& tarjeta1, carrito_compras &carrito1, cliente& cliente1);

void actulizar_inventario(arrays_objetos & producto1);