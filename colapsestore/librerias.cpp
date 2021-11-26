#include "librerias.h"
#include "usuario.h"
#include "cliente.h"
#include "productos.h"

#include"arrays_objetos.h"
#include <string>
#include <iostream>


string nosepara(string dato)
{
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

string separa(string dato)
{
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


bool verifica_numero(string numero) {
	char compro[11] = { '0','1','2','3','4','5','6','7','8','9','.' };
	int n = 0;
	int no ;
	int num = numero.length();
	for (int j = 0; j < num; j++) {
		no = 0;
		if (numero[0] == '.') {
			return false;
		}
		for (int i = 0; i < 11; i++) {
			if (numero[j] != compro[i]) {
				no = no + 1;	
			}
		}
		if (numero[j] == '.') {
			n = n + 1;
		}
		if (no == 11 || n > 1) {
			
			return false;
		}
	}
	return true;
	
}


int contdor_productos(ifstream &inventario)
{

    int n = 0;
    string numeroSerie,nombre,marca,tipo,categoria, precio,cantidad;

    inventario.open("inventario.txt", ios::in);
    if (inventario.is_open())
    {
        inventario >> numeroSerie;

        while (!inventario.eof())
        {
            inventario >> nombre;
            inventario >> marca;
            inventario >> tipo;
            inventario >> categoria;
            inventario >> precio;
            inventario >> cantidad;
            n = n + 1;
            inventario >> numeroSerie;
        }
        inventario.close();
    }
    return n;
}


int contador_usuario(ifstream &inventario)
{
    int n = 0;
    string nombre, documentoIdentidad,correo,contrasena,id,direccion,telefono,tipo_usuario;

    inventario.open("usuario.txt", ios::in);
    if (inventario.is_open())
    {
        inventario >> nombre;

        while (!inventario.eof())
        {
            inventario >> documentoIdentidad;
            inventario >> correo,
            inventario >> contrasena;
            inventario >> id;
            inventario >> direccion;
            inventario >> telefono;
            inventario >> tipo_usuario;
            if (tipo_usuario=="CLIENTE") {
                n = n + 1;
            }
            
            inventario >>nombre ;
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
    
    cout << "1. Agregar productos" << endl;
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


void adminMetodos(productos*& producto , cliente*& cliente1, administrador admin,arrays_objetos &productos1  , int tamano_users)
{
    int opcionAdmin = 0;
    int n;
    do
    {
        opcionAdmin = menuAdministrador();

        switch (opcionAdmin)
        {
        case 1:
            admin.agregar_producto(productos1);
            
            break;
        case 2:
            admin.ver_productos(productos1);
            break;
        case 3:
            /*admin.modificar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(producto, n, Lec);*/
            break;
        case 4:
            /*admin.eliminar_inventario(Lec);
            n = contdor_productos(Lec);
            modificar_arrays(producto, n, Lec);*/
                break;
        case 5:
            //Ver clientes
            //areglos_de_usuarios(cliente1, Lec);
            imprime_user_objeto(cliente1, tamano_users);
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


int menuCliente()
{
    system("cls");
    int x;
    cout << "----------Bienvenido a Collapse Store-------------" << endl;
    cout << "--------------For Gamers by Gamers----------------" << endl;
    cout << "-----------------Oficial Retail-------------------" << endl;

    cout << "1. Ver productos recomendados" << endl;
    cout << "2. Ver Categorias" << endl;
    cout << "3. Ver carrito de Compras" << endl;
    cout << "4. Salir" << endl;
    cin >> x;
    return x;
}


void clienteMetodos(cliente clienteM, productos *& producto , ifstream& Lec, ofstream& EXP)
{   
    
    int opcionAdmin = 0;

    do
    {
        opcionAdmin = menuCliente();
        switch (opcionAdmin)
        {
        case 1: 
            clienteM.ver_productos(producto, Lec);
            break;
        case 2: 
            break;
        case 3: 
            break;
        default:
            cout << "Por favor seleccione una opción valida";
            break;
        }
    } while (opcionAdmin != 4);

}


void modificar_arrays(productos*& producto, int nuevo_tamaño, ifstream& inventario) {
    delete[] producto;
    producto = new productos[nuevo_tamaño];
    //arreaglo_de_objetos(producto, inventario);
}


void crea_cuenta_cliente(ofstream& inventario) {
    string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
    tipo_usuario = "CLIENTE";
    cout << "Digite su nombre completo: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Digite su DNI:  ";
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

    inventario << nombre << " " << documentoIdentidad << " " << correo << " " << contrasena << " " << id << " " << direccion << " " << telefono << " " << tipo_usuario << "\n";
    // cout<<clase_cliente[0].nombre;
    inventario.close();

}


void imprime_objeto(productos*& producto, int nuevo_tamaño) {
    system("cls");
    for (int i = 0; i < nuevo_tamaño;i++) {
        cout<<"\n"<<producto[i].nombre;
    }
    cout << "\n";
    system("pause");
}


void inciar_sesion(ifstream& inventario,cliente &cliente_1,administrador & administrador_1)
{
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
            if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "CLIENTE")
            {
                cout<<"lograste entrar como cliente\n";
                
                cliente_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono);
                cliente_1.setCliente(tipo_usuario);
                system("pause");
                inventario.close();
                return;
                
            }
            else if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "ADMINISTRADOR") {
                cout << "lograste entrar como admin\n";
           
                administrador_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono);
                administrador_1.setadmin(tipo_usuario);
                system("pause");
                inventario.close();
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


void imprime_user_objeto(cliente *& cliente_1,int tamano)
{
    system("cls");
    for(int i=0;i<tamano;i++){
        cout << cliente_1[i].nombre << "\n";
    }
    system("pause");
}

