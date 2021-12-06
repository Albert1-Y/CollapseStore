#pragma once
#include "usuario.h"
#include"arrays_objetos.h"
using namespace std;

class administrador :public usuario
{
	public:
		double sueldo_administrador;

	public:
		administrador(string, string, string, string, string, string, string, string, double);
		administrador();
	
	
		void setadmin(double);
		void agregar_producto(arrays_objetos& arrays_producto);
		void ver_productos(arrays_objetos& arrays_producto);
		void ingresando_elementos_repetidos(arrays_objetos& arrays_producto);
		void eliminar_inventario(arrays_objetos& arrays_producto);
		void elimina_unidadees_producto(arrays_objetos& arrays_producto);
		void imprime();
};



