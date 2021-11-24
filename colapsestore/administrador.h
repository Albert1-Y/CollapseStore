#pragma once
#include "usuario.h"
#include"arrays_objetos.h"

class administrador :public usuario
{
public:
	string codigoAministrador;

public:
	administrador();
	void setadmin(string);
	void agregar_producto(arrays_objetos& arrays_producto);
	void ver_productos(arrays_objetos& arrays_producto);
	/*void modificar_inventario(arrays_objetos& arrays_producto);
	void eliminar_inventario(arrays_objetos& arrays_producto);*/
};

