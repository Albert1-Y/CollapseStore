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
		string ID;
		string direccion;
		string telefono;

	public:
		usuario(string, string, string, string, string, string, string);
		usuario(string);
		//metodos:
		//void registrar_usuario();
		//void logear_usuario();	
};

class administrador : public usuario{
	public:	
		string codigoAministrador;

	public:
		administrador(string, string, string, string, string, string, string, string);

		void agregar_producto(ofstream &inventario);
		void ver_productos(ifstream& inventario);
		void modificar_inventario(ifstream &inventario);
		void eliminar_inventario(ifstream &inventario);
};


