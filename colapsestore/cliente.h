#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "usuario.h"
#include "carrito_compras.h"

using namespace std;

class cliente :public usuario
{
	public:
		int cantidad_productos_comprados;
		carrito_compras carrito;	
	public: 
		cliente(string, string, string, string, string, string, string, string, int);
		cliente();
		void setCliente(int);
		void imprime();
		void ver_productos(arrays_objetos& producto);
		void inicializarCarrito(arrays_objetos& producto);
		void agregar_producto_carrito(arrays_objetos& producto);
		void boleta();
};



