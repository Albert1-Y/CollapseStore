#include "carrito_compras.h"
#include <iostream>

using namespace std;

carrito_compras::carrito_compras()
{
    ID = "";
    sumaTotal = 0.0;
    direccion = "";
    productos_carrito = nullptr;
}

void carrito_compras::setcarritoCompra(string _ID, string _direccion)
{
    ID = _ID;
    direccion = _direccion; 
}

void carrito_compras::agregarProducto(string _numeroSerie)
{
    
}

void carrito_compras::verProductos(arrays_objetos _arrays_productos)
{

}

void carrito_compras::cancelarCompra()
{

}

