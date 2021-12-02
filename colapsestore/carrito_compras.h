#pragma once

#include <iostream>
#include <fstream>
#include"tarjeta_visa.h"
#include"arrays_objetos.h"
//#include"librerias.h"
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
		void productos_carritod(arrays_objetos& _arrays_productos);
		void agregarProducto(productos &_producto1);
		void eliminarProducto(int _producto_eliminar);
		void verProductos();
		void cancelarCompra(tarjeta_visa& tarjeta_1);
		
};
