#pragma once
#include "luchadores.h"
#include <string>
using std::string;

class Espadachin:public Luchadores{
	
  public:
	Espadachin(int,int,int,string);
	virtual ~Espadachin();
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