#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>

#include "cliente.h"
#include "librerias.h"


using namespace std;

cliente::cliente()
{
    codigocliente = "";
}


void cliente::setCliente(string _codigocliente) {
    codigocliente = _codigocliente;
}

void cliente::ver_productos(arrays_objetos& producto, carrito_compras& carrito)
{
    for (int i = 0; i < producto.tamano_producto; i++)
    {   
        cout << i + 1 << " ";
        cout << producto.arrays_productos[i].marca << " ";
        cout << producto.arrays_productos[i].nombre << " ";
        cout << "$. "<< producto.arrays_productos[i].precio << " \n";
    }
}

void cliente::agregar_producto_carrito(arrays_objetos& producto, carrito_compras& carrito)
{
    string escoge_producto;
    cout << "\nDigite el numero del producto: ";
    cin >> escoge_producto;

    bool esNumero = verifica_numero(escoge_producto);

    if (esNumero == true)
    {
        int numero = stoi(escoge_producto);
        if (numero > 0 && numero <= producto.tamano_producto)
        {
            carrito.agregarProducto(producto.arrays_productos[numero - 1]);
        }
        else
        {
            cout << "No existe el producto";
        }
    }
}
