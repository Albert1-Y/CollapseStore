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
		void set_tarjeta_visa(string _numeroTarjeta, string _fechaVencimiento, string _CVV, double _saldo);
		void descontar(double _totalCompra);
};

