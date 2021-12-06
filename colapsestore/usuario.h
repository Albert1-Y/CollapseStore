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
		string tipo_usuario;

	public:
		usuario(string, string, string, string, string, string, string, string);
		usuario();
		void setUsuario(string, string, string, string, string, string, string,string);
		virtual void imprime();
};



