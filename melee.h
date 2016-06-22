#pragma once
#include "luchadores.h"
#include <string>
using std::string;

class Melee:public Luchadores{
	
  public:
	Melee(int,int,int,string);
	virtual ~Melee();
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