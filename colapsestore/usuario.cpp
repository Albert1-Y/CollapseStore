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
    tipo_usuario = "";
}


usuario::usuario(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _tipo_usuario)
{
    nombre = _nombre;
    documentoIdentidad = _documentoIdentidad;
    correo = _correo;
    contrasena = _contrasena;
    ID = _ID;
    direccion = _direccion;
    telefono = _telefono;
    tipo_usuario = _tipo_usuario;
}


void usuario::setUsuario(string _nombre, string _documentoIdentidad, string _correo, string _contrasena, string _ID, string _direccion, string _telefono, string _tipo_usuario)
{
    nombre = _nombre;
    documentoIdentidad = _documentoIdentidad;
    correo = _correo;
    contrasena = _contrasena;
    ID = _ID;
    direccion = _direccion;
    telefono = _telefono;
    tipo_usuario = _tipo_usuario;
}
void usuario::imprime() {
    cout << "-----------------------------------------------------\n";
    cout << "nombre: " << nombre<<" \n";
    cout << "DNI: " << documentoIdentidad << " \n";
    cout << "Direccion: " << direccion << " \n";
    cout << "correo: " << correo << " \n";
}

