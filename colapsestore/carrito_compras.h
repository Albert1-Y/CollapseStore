#pragma once

#include <iostream>
#include <fstream>
//#include"carrito_compras.h"
#include"tarjeta_visa.h"
#include"arrays_objetos.h"
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
		void productos_carritod(ifstream & productos_carritoh, arrays_objetos& _arrays_productos);
		void agregarProducto(productos &_producto1);
		void verProductos();
		void cancelarCompra(tarjeta_visa& tarjeta_1);
};
