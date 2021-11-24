#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "productos.h"
#include "arrays_objetos.h"


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

		usuario();
		void setUsuario(string, string, string, string, string, string, string);

		//metodos:
		//void registrar_usuario();
		//void logear_usuario();
};



class administrador : public usuario{
	public:	
		string codigoAministrador;

	public:
		administrador();
		void setadmin(string);
		void agregar_producto(arrays_objetos &arrays_producto);
		void ver_productos(arrays_objetos& arrays_producto);
		/*void modificar_inventario(arrays_objetos& arrays_producto);
		void eliminar_inventario(arrays_objetos& arrays_producto);*/
};


