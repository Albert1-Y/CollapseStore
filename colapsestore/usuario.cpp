#include "usuario.h"


using namespace std;

usuario::usuario(){
	nombre = "";
	documentoIdentidad = "";
	correo = "";
	contrasena = "";
    ID = "";
	direccion = "";
    telefono = "";
}

void usuario::setUsuario(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono)
{
    nombre = _nombre;
    documentoIdentidad = _documentoIdentidad;
    correo = _correo;
    contrasena = _contrasena;
    ID = _ID;
    direccion = _direccion;
    telefono = _telefono;
}


