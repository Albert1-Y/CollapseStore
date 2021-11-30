#pragma once
#include "usuario.h"
#include"arrays_objetos.h"
using namespace std;

class administrador :public usuario
{
public:
	string codigoAministrador;

public:
	administrador();
	void setadmin(string);
	void agregar_producto(arrays_objetos& arrays_producto);
	void ver_productos(arrays_objetos& arrays_producto);
	void ingreando_elementos_repetidos(arrays_objetos& arrays_producto);
	void eliminar_inventario(arrays_objetos& arrays_producto);
	void elimina_unidadees_producto(arrays_objetos& arrays_producto);
};

