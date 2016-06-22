#pragma once
#include "luchadores.h"
#include <string>
using std::string;

class Priest:public Luchadores{
	
  public:
	Priest(int,int,int,string);
	virtual ~Priest();
	int ataquar(int);
	void LevelUp(int);
	void UseMoney(int);
	string toString();
	int herir(int);
	void Cambiar_nombre(string);
	int GetMoney();
	void WinMoney();
};