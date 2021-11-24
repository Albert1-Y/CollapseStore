#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>

#include "cliente.h"
#include "librerias.h"
#include "usuario.h"
#include "productos.h"


using namespace std;


cliente::cliente()
{
    codigocliente = "";
}

void cliente::setCliente(string _codigocliente)/* :usuario(_nombre, _documentoIdentidad, _correo, _contrasena, _ID, _direccion, _telefono)*/
{
    codigocliente = _codigocliente;
}

/*
void cliente::crea_cliente(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _codigocliente)  : usuario(_nombre, _documentoIdentidad, _correo, _contrasena, _ID, _direccion, _telefono)
{
}

*/

void cliente::ver_productos(productos*& producto, ifstream& inventario)
{   system("cls");
    double nin;
    int numero_productos = contdor_productos(inventario);
    for (int i = 0; i < numero_productos; i++)
    {   
        nin = stod(producto[i].precio);
        cout << i + 1 << " ";
        cout << producto[i].marca << " ";
        cout << producto[i].nombre << " ";
        cout << "$. "<< nin << " \n";
        if (numero_productos > 10)
        {
            break;
        }
    }
    system("pause");
}


//----------------------------------------------------------

carritoCompra::carritoCompra()
{
    ID = "";
    saldo = "";
}


void carritoCompra::setcarritoCompra(string _ID, string _saldo)
{
    ID = _ID;
    saldo = _saldo;
}


