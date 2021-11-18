#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

#include "cliente.h"
#include "librerias.h"
#include "usuario.h"

using namespace std;

cliente::cliente()
{
    codigocliente = "";
}
void cliente::setCliente(string _codigocliente) {
    codigocliente = _codigocliente;
}

/*

void crea_cliente(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _codigocliente) : usuario(_nombre, _documentoIdentidad, _correo, _contrasena, _ID, _direccion, _telefono)
{
}

*/

carritoCompra::carritoCompra() {
    ID = "";
}

void carritoCompra::setcarritoCompra(string _ID)
{
    ID = _ID;
}