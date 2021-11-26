#pragma once

#include <iostream>

using namespace std;

class tarjeta_visa
{
	public:
		double saldo;
		string numeroTarjeta;
		string fechaVencimiento;
		string CVV;

		tarjeta_visa();
		void set_tarjeta_visa(double _saldo, string _numeroTarjeta, string _fechaVencimiento, string _CVV);
		//void descontar(double totalCompra);
};

