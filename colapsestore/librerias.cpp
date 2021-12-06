#include"librerias.h"
#include"arrays_usuarios.h"
#include <fstream> //convertir cadenas a float
#include <string>
#include <iostream>
#include<cstdlib>

using namespace std;

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
    int cantidad = {};

    inventario.open("inventario.txt", ios::in);
    if (inventario.is_open())
    {
        inventario >> cantidad;
        inventario.close();
    }
    return cantidad;
}


int contador_usuario()
{
    ifstream inventario;
 
    int contador=0;
    inventario.open("usuario.txt", ios::in);
    if (inventario.is_open())
    {
        
        inventario >> contador;
        
        
        inventario.close();
    }
    return contador;
}

  
int menu_inicial()
{
    system("cls");
    int x;
    cout << "----------Bienvenido a Collapse Store-------------" << endl;
    cout << "--------------For Gamers by Gamers----------------" << endl;
    cout << "-----------------Oficial Retail-------------------" << endl;
    cout << "1. Iniciar sesion" << endl;
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
    cout << "------------Estas en el modo Adminstrador-------------" << endl;
    
    cout << "1. Agregar productos" << endl;
    cout << "2. Ver productos" << endl;
    cout << "3. Ingresar elemento repetido " << endl;
    cout << "4. Eliminar del inventario " << endl;
    cout << "5. elimiminar unidades del producto" << endl;
    cout << "6. Lista de clientes" << endl;
    cout << "7. Lista de administradores" << endl;
    cout << "8. Salir" << endl;
    cin >> x;
    return x;
}


void adminMetodos(arrays_objetos & producto , administrador & admin,arrays_objetos &productos1  , ifstream &lec)
{   
    
   
    int opcionAdmin = 0;
    //int n;
    arrays_usuarios usuarios;
    usuarios.ser_incia_array(lec);
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
            admin.ingresando_elementos_repetidos(productos1);
            break;
        case 4:
            admin.eliminar_inventario(productos1);
            break;
        case 5:
            admin.elimina_unidadees_producto(productos1);
            break;
        case 6:
            usuarios.imprime_usuario();
            system("pause");
            break;
        case 7:
            usuarios.imprime_admin();
            system("pause");
            break;
        case 8:
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


void clienteMetodos(cliente &clienteM, arrays_objetos& producto1, ifstream& Lec, ofstream& EXP,tarjeta_visa &tarjeta_1)
{   
    
    int opcionCliente = 0;

    do
    {   
        opcionCliente = menuCliente();
        switch (opcionCliente)
        
        {
            case 1: 
            
                clienteM.ver_productos(producto1);
                system("pause");
                break;
            case 2: 
                //ver categorias
                break;
            case 3:
                if (clienteM.carrito.contador_productos != 0)
                {
                    clienteM.carrito.verProductos();

                    menu_hacer_pago(tarjeta_1, clienteM.carrito,clienteM);
                    
 
                    system("pause");
                }
                break;
            default:
                
                if (opcionCliente != 4) {
                    cout << "\nPor favor seleccione una opción valida";
                }
                
                break;
        }
    } while (opcionCliente != 4);

}




void crea_cuenta_cliente(cliente & cliente_1)
{
    ofstream inventario;
    
    inventario.open("auxi_inventario.txt", ios::out | ios::app);
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

    cliente_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono,tipo_usuario);
    inventario << nombre << " " << documentoIdentidad << " " << correo << " " << contrasena << " " << id << " " << direccion << " " << telefono << " " << tipo_usuario <<" "<<0<< "\n";
}


void inciar_sesion(ifstream& inventario,cliente &cliente_1,administrador & administrador_1)
{
    int contador;
    string nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario;
    string auxiID, auxcontrasena;
    int cantidad_productos_comprados;
    double sueldo_administrador;
    inventario.open("usuario.txt", ios::in);
    if (inventario.is_open())
    {
        cout << "---- INICIAR SESION-----\n\n";
        cout << "Ingrese su ID: ";
        cin.ignore();
        getline(cin, auxiID);
        cout << "Ingrese su contraseña: ";
        getline(cin, auxcontrasena);
        inventario >> contador;
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
           
            if (tipo_usuario == "CLIENTE")
                inventario >> cantidad_productos_comprados;
            else
                inventario >> sueldo_administrador;

            cout << id << "\n";
            
            

            if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "CLIENTE")
            {
                
                cout<<"lograste entrar como cliente \n";
                
                cliente_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono, tipo_usuario);
                cliente_1.setCliente(cantidad_productos_comprados);
                inventario.close();
                system("pause");
                return;
                
            }
            else if (auxiID == id && auxcontrasena == contrasena && tipo_usuario == "ADMINISTRADOR") {
                cout << "lograste entrar como admin\n";
                
                administrador_1.setUsuario(nombre, documentoIdentidad, correo, contrasena, id, direccion, telefono,tipo_usuario);
                administrador_1.setadmin(sueldo_administrador);
                      
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
    cout << "\n***DATO INCORRECTO***";
    system("pause");
}


bool verifica_tarjeta(tarjeta_visa&tarjeta_1){
    ifstream tarjeta_cuentas;
    string _saldo; 
    string _numeroTarjeta, _fechaVencimiento, _CVV;
    string auxfechaVencimiento,auxCVV, auxnumeroTarjeta;

    tarjeta_cuentas.open("tarjeta_cuentas.txt", ios::in);
    if (tarjeta_cuentas.is_open()){
        cout << "---- TARJETA DE CREDITO-----\n\n";
        cout << "Ingrese el numero de su tarjeta correcto: ";        
        cin.ignore();
        getline(cin, auxnumeroTarjeta);

        cout << "Ingrese la fecha de vencimiento de su tarjeta: ";
        cout << "Referencia: 03/04/2022: ";
        getline(cin, auxfechaVencimiento);

        cout << "Ingrese el codigo CVV de 3 digitos de su tarjeta: ";
        getline(cin, auxCVV);

        
        tarjeta_cuentas >>_numeroTarjeta;
        while (!tarjeta_cuentas.eof())
        {
            tarjeta_cuentas >> _fechaVencimiento;
            tarjeta_cuentas >> _CVV;
            tarjeta_cuentas >> _saldo;
            
            if (_numeroTarjeta==auxnumeroTarjeta && auxfechaVencimiento == _fechaVencimiento && auxCVV == _CVV){
                double com = stod(_saldo);
                cout<<"Datos comprobados de tarjeta\n";
                
                tarjeta_1.set_tarjeta_visa(_numeroTarjeta, _fechaVencimiento, _CVV, com);
                tarjeta_cuentas.close();
  
                return true;                
            }   
            tarjeta_cuentas >> _numeroTarjeta;
        }
        tarjeta_cuentas.close();
    }
    else
    {
        cout << "ERROR\n";
    }
    cout << "\n***DATOS INCORRECTOS DE TARJETA***";
    system("pause");
    return false;
}

void menu_hacer_pago(tarjeta_visa & tarjeta1, carrito_compras & carrito1,cliente & cliente1)
{
    int opcions;
    
    cout << "1. Desea comprar los productos? "<<"\n";
    cout << "2. Quitar elementos" << "\n";
    cout << "Opcion: ";
    cin >> opcions;
    if (opcions == 1)
    {
        bool verifica = false;
        system("cls");
        verifica = verifica_tarjeta(tarjeta1);
        if (verifica) {
            if (tarjeta1.saldo > carrito1.sumaTotal) {
                system("cls");
                carrito1.cancelarCompra(tarjeta1);
                cliente1.boleta();
                carrito1.~carrito_compras();
                

            }
            else {
                cout << "\nNo cuenta con saldo suficiente\n";
            }

        }
        else {
            cout << "\nNo se encontro de tarjeta\n";
        }
    }
    else if (opcions == 2)
    {   
        carrito1.verProductos();
        string elim;
        cout << "¿Que producto desea eliminar de su carrito? : " << "\n";
        cin >> elim;
        bool esNumero = verifica_numero(elim);
        if (esNumero == true)
        {
            int numero = stoi(elim);
            carrito1.eliminarProducto(numero);
        }
    }
    else
    {
        cout << "No existe esa opcion\n";
    }
}

//


void actulizar_inventario(arrays_objetos &producto1)
{

    ofstream inventario;
    inventario.open("auxi_inventario.txt", ios::out | ios::app);
    inventario << producto1.tamano_producto << "\n";

    for (int i = 0; i < producto1.tamano_producto; i++)
    {
        inventario << nosepara(producto1.arrays_productos[i].numeroSerie) << " " << nosepara(producto1.arrays_productos[i].nombre) << " " << nosepara(producto1.arrays_productos[i].marca) << " " << nosepara(producto1.arrays_productos[i].categoria) << " " << nosepara(producto1.arrays_productos[i].tipo) << " " << producto1.arrays_productos[i].precio << " " << producto1.arrays_productos[i].cantidad << "\n";
    }
    inventario.close();
    remove("inventario.txt");
    rename("auxi_inventario.txt", "inventario.txt");

}
