#include "librerias.h"
#include"usuario.h"
#include "productos.h"
#include"cliente.h"
#include<string>


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
    cout << "----------bienvenido-------------" << endl;
    cout << "1. Registrar producto" << endl;
    cout << "2. Iniciar sesion" << endl;
    cout << "3. Crear cuenta" << endl;
    cout << "4. Modificar producto" << endl;
    cout << "5. Eliminar producto" << endl;
    cout << "6. Salir" << endl;
    cin >> x;
    return x;
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
    system("pause");}

void crea_cuenta_cliente(/*cliente& cliente_1*/ ofstream& inventario) {
    string nombre, documentoIdentidad,correo,contrasena,id,direccion,telefono,tipo_usuario;
    tipo_usuario = "CLIENTE";
    cout << "Digite su nombre competo: ";
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
    cout << "Digite una contrasena: ";
    getline(cin, contrasena);

    //cliente_1(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario);
    
    inventario.open("usuario.txt", ios::out | ios::app);

    inventario << nombre << " " << documentoIdentidad << " " << correo << " " << contrasena << " " << id << " "<< direccion <<" "<< telefono <<" "<< tipo_usuario << "\n";
   // cout<<clase_cliente[0].nombre;
    inventario.close();

}
void inciar_sesion(ifstream& inventario) {
    string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
    string auxiID,auxcontrasena;
    inventario.open("usuario.txt", ios::in);

    if (inventario.is_open())

    {
        cout << "---- INICIAR SESION-----\n\n";
        cout << "Ingrese su ID: ";
        cin.ignore();
        getline(cin, auxiID);
        cout << "Ingrese su contrase: ";
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
                system("pause");
                return;
            }
            else if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "ADMINISTRADOR") {
                cout << "lograste entrar como admin\n";
                inventario.close();
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

    system("pause");
}

