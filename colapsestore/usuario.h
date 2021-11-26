#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include"productos.h"

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
		usuario();
		void setUsuario(string, string, string, string, string, string, string);

		//metodos:
		//void registrar_usuario();
		//void logear_usuario();
};



