#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "usuario.h"
#include"carrito_compras.h"
using namespace std;

class cliente :public usuario
{
	public:
		string codigocliente;
		
	public: 
		cliente();
		void setCliente(string);
		void ver_productos(arrays_objetos& producto, carrito_compras& carrito);

	/*public:
		void crea_cliente(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _codigocliente);*/
		 
		//void historialCompra(ifstream& historial);1
	// void carritoCompra(ofstream& historial);
};

