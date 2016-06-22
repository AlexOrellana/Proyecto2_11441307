#pragma once
#include "luchadores.h"
#include <string>
using std::string;

class Tirador:public Luchadores{
	int tiros;
  public:
	Tirador(int,int,int,string,int=30);
	virtual ~Tirador();
	int ataquar(int);
	void LevelUp(int);
	void UseMoney(int);
	string toString();
	int herir(int);
	void Cambiar_nombre(string);
	int GetMoney();
	void WinMoney();
};