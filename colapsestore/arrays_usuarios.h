
#include"cliente.h"
#include"administrador.h"
#include"usuario.h"

class arrays_usuarios
{
	public:
		usuario ** arrays_usuario_c_a;
		int _contador_usuario;
	public:
		arrays_usuarios();
		~arrays_usuarios();
		void ser_incia_array(ifstream & usuario_txt);
		void imprime_usuario();
		void imprime_admin();
};



