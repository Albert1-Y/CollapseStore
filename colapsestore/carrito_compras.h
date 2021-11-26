#pragma once

#include <iostream>

#include "arrays_objetos.h"
#include "productos.h"

using namespace std;

class carrito_compras
{
	public:
		string ID;
		double sumaTotal;
		string direccion;
		productos* productos_carrito;
		int contador_productos;
		carrito_compras();
		void setcarritoCompra(string _ID, string _direccion);
		void agregarProducto(string _numeroSerie);
		void verProductos(arrays_objetos _arrays_productos);
		void cancelarCompra();
};
