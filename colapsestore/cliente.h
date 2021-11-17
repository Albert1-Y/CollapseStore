#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include"usuario.h"


class cliente:public usuario
{
	public:
		string codigocliente;

	public:
		cliente();
		cliente(string, string, string, string, string, string, string, string);

	/*public:
		void crea_cliente(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _codigocliente);*/
		 
		//void historialCompra(ifstream& historial);
	// void carritoCompra(ofstream& historial);

};


class carritoCompra : public usuario
{	
	public:
		carritoCompra(string);

	//void	
};

