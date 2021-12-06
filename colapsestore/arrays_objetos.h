#pragma once
#include <fstream>
#include "productos.h"
#include <fstream>
#include <iostream>
//#include"cliente.h"
using namespace std;

class arrays_objetos
{	
	public:
		productos *arrays_productos;
		int tamano_producto;

	public:
		//constructor y destructor
		arrays_objetos();
		~arrays_objetos();
		void set_crea_arrays_productos(ifstream & inventario);
		void setarrays_objetos(ifstream& inventario);
		
};

