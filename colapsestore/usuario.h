#pragma once

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class usuario{
	public:
		string nombre;
		string documentoIdentidad;
		string correo;
		string contrasena;
		string direccion;		

	public:
		usuario(string, string, string, string, string);
		
};

class administrador : public usuario{
	public:
		
		string codigoAministrador;

		administrador(string, string, string, string, string, string);

		void agregar_producto(ofstream &inventario);
		void ver_productos(ifstream& inventario);
		void modificar_inventario(ifstream &inventario);
		void eliminar_inventario(ifstream &inventario);		
};


