#pragma once

#include <iostream>
#include <fstream>
#include"librerias.h"
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
		~carrito_compras();

		void setcarritoCompra(string _ID, string _direccion);
		void productos_carritod(ifstream & productos_carritoh, arrays_objetos _arrays_productos);
		void agregarProducto(productos _producto);
		void verProductos(arrays_objetos _arrays_productos);
		void cancelarCompra(tarjeta_visa& tarjeta_1);
};
