#include "arrays_usuarios.h"
#include "librerias.h"
#include <fstream>
#include<iostream>

using namespace std;

arrays_usuarios::arrays_usuarios()
{
	_contador_usuario = 0;
	arrays_usuario_c_a = nullptr;
}

arrays_usuarios::~arrays_usuarios()
{
	if (arrays_usuario_c_a != nullptr)
	{
		for (int i = 0; i < _contador_usuario; i++) {
			delete arrays_usuario_c_a[i];
		}
		delete[] arrays_usuario_c_a;
	}
}
void arrays_usuarios::ser_incia_array(ifstream& usuario_txt)
{
	
	this-> _contador_usuario = contador_usuario();
	int contador;

	string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
	int cantidad_productos_comprados;
	double sueldo_administrador;
	int m = 0;
	
	arrays_usuario_c_a =new usuario*[_contador_usuario];
	usuario_txt.open("usuario.txt", ios::in);
	usuario_txt >> contador;
	usuario_txt >> nombre;
	while (!usuario_txt.eof())
	{
		usuario_txt >> documentoIdentidad;
		usuario_txt >> correo;
		usuario_txt >> contrasena;
		usuario_txt >> id;
		usuario_txt >> direccion;
		usuario_txt >> telefono;
		usuario_txt >> tipo_usuario;
		if (tipo_usuario == "CLIENTE")
		{	
			usuario_txt >> cantidad_productos_comprados;

			arrays_usuario_c_a[m]=new cliente(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario, cantidad_productos_comprados);
			
		}
		else if (tipo_usuario == "ADMINISTRADOR")
		{
			
			usuario_txt >> sueldo_administrador;

			arrays_usuario_c_a[m] = new administrador(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario, sueldo_administrador);

			
			
			
		}
		m++;
		usuario_txt >> nombre;
	}
	usuario_txt.close();
}


void  arrays_usuarios::imprime_usuario() {
	for (int i = 0; i < _contador_usuario; i++) {
		if (arrays_usuario_c_a[i]->tipo_usuario == "CLIENTE")
			arrays_usuario_c_a[i]->imprime();
	}
}
void arrays_usuarios::imprime_admin() {
	for (int i = 0; i < _contador_usuario; i++) {
		if (arrays_usuario_c_a[i]->tipo_usuario == "ADMINISTRADOR")
			arrays_usuario_c_a[i]->imprime();
	}
}
