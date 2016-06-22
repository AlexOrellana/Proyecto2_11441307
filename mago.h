#pragma once
#include "luchadores.h"
#include <string>
using std::string;

class Mago:public Luchadores{
	int magia;
  public:
	Mago(int,int,int,string,int=10);
	virtual ~Mago();
	int ataquar(int);
	void LevelUp(int);
	void UseMoney(int);
	string toString();
	int herir(int);
	void Cambiar_nombre(string);
	int GetMoney();
	void WinMoney();
	int GetVida();
	string GetNombre();
};