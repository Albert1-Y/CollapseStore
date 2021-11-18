#include "usuario.h"
#include "librerias.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>


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


//----------------------Adminstrador--------------------------------------

administrador::administrador()
{
    codigoAministrador = "";
}

void administrador::setadmin(string _codigoAministrador)
{
    codigoAministrador = _codigoAministrador;
}


void administrador::agregar_producto(ofstream& inventario)
{
    string _nombre, _marca, _tipo, _precios;
    string _numeroserie;
	system("cls");
    cout << "Ingrese el numero de serie del producto: ";
    cin.ignore();
    getline(cin, _numeroserie);
    _numeroserie = nosepara(_numeroserie);
    cout << "Ingrese el nombre del producto: ";
    getline(cin, _nombre);
    _nombre = nosepara(_nombre);
    cout << "Ingrese la marca del producto: ";
    getline(cin, _marca);
    _marca = nosepara(_marca);
    cout << "Ingrese el tipo del producto: ";
    getline(cin, _tipo);
    _tipo=nosepara(_tipo);
    cout << "Ingrese el precio del producto: ";
    getline(cin, _precios);

	inventario.open("inventario.txt", ios::out | ios::app);

	inventario  << _numeroserie << " " << _nombre << " " << _marca << " " << _tipo << " " << _precios<<"\n";

	inventario.close();
}

void administrador::ver_productos(ifstream &inventario)
{
    
    string nombre, marca, tipo, precio, numeroSerie;    

    inventario.open("inventario.txt", ios::in);


    if (inventario.is_open())
    {

        cout << "------------------------------------------\n----------------Personas Registradas----------------\n------------------------------------------\n\n"; 

        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            
            cout << "------------------------------------------" << endl;
            cout << "Numero de Serie-------------: " << numeroSerie << endl;
            cout << "Nombre del producto---------: " << nombre << endl;
            cout << "Marca del producto----------: " << marca << endl;
            cout << "Tipo del producto-----------: " << tipo << endl;
            cout << "Precio del producto---------: " << precio << endl;
            cout << "------------------------------------------" << endl;
            
            inventario >> numeroSerie;
        }
        inventario.close();
    }
    else
    {
        cout << "ERROR\n";
    }

    system("pause");
}


void administrador::modificar_inventario(ifstream& inventario)
{
    system("cls");

    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    
    string aux_nombre;
    string aux_marca;
    string aux_tipo;
    string aux_precio;
   
    string auxNumeroSerie;

    inventario.open("inventario.txt", ios::in);

    ofstream aux("auxiliar_inventario.txt", ios::out | ios::app);

    if (inventario.is_open())
    {
        bool omg = false;
        cout << "Numero de serie:  ";
        cin >> auxNumeroSerie;
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;

            if (numeroSerie == auxNumeroSerie)
            {
                cout << "Digite el nuevo nombre del producto: ";
                cin >> aux_nombre;
                cout << "Digite la marca del proucto: ";
                cin >> aux_marca;
                cout << "Digite el tipo del proucto: ";
                cin >> aux_tipo;
                cout << "Digite el precio del proucto: ";
                cin >> aux_precio;

                aux << numeroSerie << " " << aux_nombre << " " << aux_marca << " " << aux_tipo << " " << aux_precio << "\n";
                omg = true;
            }
            else
            {
                aux << numeroSerie << " " << nombre << " " << marca << " " << tipo << " " << precio << "\n";
            }
            
            inventario >> numeroSerie;
        }
        inventario.close();
        aux.close();
        if (omg == false)
        {
            cout << "Dato no encontrado\n";
            Sleep(1500);
        }
    }
    else
    {
        cout << "ERROR\n";
        Sleep(1500);
    }
    remove("inventario.txt");
    rename("auxiliar_inventario.txt", "inventario.txt");
}

void administrador::eliminar_inventario(ifstream& inventario)
{
    system("cls");

    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;

    string aux_nombre;
    string aux_marca;
    string aux_tipo;
    string aux_precio;

    string auxNumeroSerie;

    inventario.open("inventario.txt", ios::in);

    ofstream aux("auxiliar_inventario.txt", ios::out | ios::app);

    if (inventario.is_open())
    {
        bool omg = false;
        cout << "Numero de serie: ";
        cin >> auxNumeroSerie;
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            if (numeroSerie == auxNumeroSerie)
            {
                cout << "Eliminado ok ";
                Sleep(1500);
                omg = true;
            }
            else
            {
                aux << numeroSerie << " " << nombre << " " << marca << " " << tipo << " " << precio << "\n";
            }
            inventario >> numeroSerie;
        }
        inventario.close();
        aux.close();
        if (omg == false)
        {
            cout << "Dato no encontrado\n";
            Sleep(1500);
        }
    }
    else
    {
        cout << "ERROR\n";
        Sleep(1500);
    }
    remove("inventario.txt");
    rename("auxiliar_inventario.txt", "inventario.txt");
}
