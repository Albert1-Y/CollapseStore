#pragma once

#include "productos.h"
#include "cliente.h"
#include "usuario.h"

#include <fstream>

class arrays_objetos
{
	public:
		productos *arrays_productos;

		cliente *arrays_cliente;

		int tamano_producto;
		int tamano_cliente;

	public:
		//constructor y destructor
		arrays_objetos();
		~arrays_objetos();
		void set_crea_arrays_productos(ifstream & inventario);
		void set_crea_arrays_clientes(ifstream & inventario);
		void setarrays_perifericos(ifstream& inventario);
		void setarrays_componetes(ifstream& inventario);
		void setarrays_objetos(ifstream& inventario);
		void setarrays_usuario(ifstream& inventario);
};

