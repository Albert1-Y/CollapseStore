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
 
    int escoge_producto;
    for (int i = 0; i < producto.tamano_producto; i++)
    {   
        
        cout << i + 1 << " ";
        cout << producto.arrays_productos[i].marca << " ";
        cout << producto.arrays_productos[i].nombre << " ";
        cout << "$. "<< producto.arrays_productos[i].precio << " \n";
        
    }
    cout << "\ndigite el numero del producto: ";
    cin >> escoge_producto;
    if (escoge_producto > 0 && escoge_producto <= producto.tamano_producto) {
        carrito.agregarProducto(producto.arrays_productos[escoge_producto-1]);
    }
    else
        cout << "no existe el producto";
    }


