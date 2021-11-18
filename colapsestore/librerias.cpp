#include "librerias.h"
#include "usuario.h"
#include "productos.h"
#include "cliente.h"

#include <string>
#include <iostream>

//
string nosepara(string dato) {
    string auxdato = "";
    int tamano = dato.length();
    for (int i = 0; i < tamano; i++) {
        if (dato[i] == ' ') {
            auxdato = auxdato + "-";
        }
        else {
            auxdato = auxdato + dato[i];
        }
    }
    return auxdato;

}
string separa(string dato) {
    string auxdato = "";
    int tamano = dato.length();
    for (int i = 0; i < tamano; i++) {
        if (dato[i] == '-') {
            auxdato = auxdato + " ";
        }
        else {
            auxdato = auxdato + dato[i];
        }
    }
    return auxdato;

}
void arreaglo_de_objetos(productos *&producto,ifstream &inventario)
{
    int m = 0;
    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;
    inventario.open("inventario.txt", ios::in);

    if (inventario.is_open())
    {
        inventario >> numeroSerie;
 
        while (!inventario.eof())
        {
            inventario >> nombre;
            nombre = separa(nombre);
            inventario >> marca;
            marca = separa(marca);
            inventario >> tipo;
            tipo = separa(tipo);
            inventario >> precio;
            producto[m].crear_objetos(nombre, marca, tipo, precio, numeroSerie);
            
            cout << "\n" << producto[m].numeroSerie;

            m= m + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }
}


int contdor_productos(ifstream &inventario)
{

    int n = 0;
    string numeroSerie;
    string nombre;
    string marca;
    string tipo;
    string precio;

    inventario.open("inventario.txt", ios::in);
    if (inventario.is_open())
    {
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> precio;
            n = n + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }
    return n;
}

  
int menu()
{
    system("cls");
    int x;
    cout << "----------Bienvenido a Collapse Store-------------" << endl;
    cout << "--------------For Gamers by Gamers----------------" << endl;
    cout << "-----------------Oficial Retail-------------------" << endl;
    cout << "1. Iniciar secion" << endl;
    cout << "2. Crear cuenta" << endl;
    cout << "3. Ingresar como invitado" << endl;
    cout << "4. Salir" << endl;
    cin >> x;
    return x;
}


int menuAdministrador()
{
    system("cls");
    int x;
    cout << "------------Esta en el modo Adminstrador-------------" << endl;
    //cout << "--------------For Gamers by Gamers----------------" << endl;
    //cout << "-----------------Oficial Retail-------------------" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Ver productos" << endl;
    cout << "3. Modificar inventario" << endl;
    cout << "4. Eliminar un producto" << endl;
    cout << "5. Ver clientes" << endl;
    cout << "6. Buscar clientes" << endl;
    cout << "7. Ver historial de compra de una cliente" << endl;
    cout << "8. Salir" << endl;
    cin >> x;
    return x;
}

void adminMetodos(administrador admin,ifstream &Lec,ofstream &EXP)
{
    int opcionAdmin;

    do
    {
        opcionAdmin = menuAdministrador();

        switch (opcionAdmin)
        {
        case 1:
            admin.agregar_producto(EXP);
            break;
        case 2:
            admin.ver_productos(Lec);
            break;
        case 3:
            admin.modificar_inventario(Lec);
            break;
        case 4:
            admin.eliminar_inventario(Lec);
                break;
        case 5:
            //Ver clientes
            break;
        case 6:
            //Buscar clientes
            break;
        case 7:
            //Ver historial de compra de una cliente
            break;
        default:
            cout << "Por favor seleccione una opción valida";
            break;
        }


    }
    while (opcionAdmin != 8);

}


void modificar_arrays(productos*& producto, int nuevo_tamaño, ifstream& inventario) {
    delete[] producto;
    producto = new productos[nuevo_tamaño];
    arreaglo_de_objetos(producto, inventario);
}


void imprime_objeto(productos*& producto, int nuevo_tamaño) {
    system("cls");
    for (int i = 0; i < nuevo_tamaño;i++) {
        cout<<"\n"<<producto[i].nombre;
    }
    cout << "\n";
    system("pause");
}


void crea_cuenta_cliente(/*cliente& cliente_1*/ ofstream& inventario) {
    string nombre, documentoIdentidad,correo,contrasena,id,direccion,telefono,tipo_usuario;
    tipo_usuario = "CLIENTE";
    cout << "Digite su nombre completo: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Diite su DNI:  ";
    getline(cin, documentoIdentidad);
    cout << "Digite su correo: ";
    getline(cin, correo);
    cout << "Digite su telefono: ";
    getline(cin, telefono);
    cout << "digite su departamento:";
    getline(cin, direccion);
    cout << "Digite un ID para inciar sesion: ";
    getline(cin, id);
    cout << "Digite una contraseña: ";
    getline(cin, contrasena);

    //cliente_1(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario);
    
    inventario.open("usuario.txt", ios::out | ios::app);

    inventario << nombre << " " << documentoIdentidad << " " << correo << " " << contrasena << " " << id << " "<< direccion <<" "<< telefono <<" "<< tipo_usuario << "\n";
   // cout<<clase_cliente[0].nombre;
    inventario.close();

}
void inciar_sesion(ifstream& inventario,cliente &cliente_1,administrador & administrador_1) {
    string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
    string auxiID,auxcontrasena;
    inventario.open("usuario.txt", ios::in);
    if (inventario.is_open())
    {
        cout << "---- INICIAR SESION-----\n\n";
        cout << "Ingrese su ID: ";
        cin.ignore();
        getline(cin, auxiID);
        cout << "Ingrese su contraseña: ";
        getline(cin, auxcontrasena);
        inventario >>nombre;
        while (!inventario.eof())
        {
            inventario >> documentoIdentidad;
            inventario >> correo;
            inventario >> contrasena;
            inventario >> id;
            inventario >> direccion;
            inventario >> telefono;
            inventario >> tipo_usuario;
            if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "CLIENTE") {
                cout<<"lograste entrar como cliente\n";
                inventario.close();
                cliente_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono);
                cliente_1.setCliente(tipo_usuario);
                system("pause");
                return;
            }
            else if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "ADMINISTRADOR") {
                cout << "lograste entrar como admin\n";
                inventario.close();
                administrador_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono);
                administrador_1.setadmin(tipo_usuario);
                system("pause");
                return;
            }

            inventario >> nombre;
        }
        inventario.close();
    }
    else
    {
        cout << "ERROR\n";
    }
    cout << "\n***DATO INCORRECTO***";
    system("pause");
}

