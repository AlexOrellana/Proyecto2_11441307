#pragma once

#include <string>
using std::string;

class Luchadores{
  protected:
  	int vida;
	int fuerza_base;
	int money;
	string nombre;
  public:
	Luchadores(int=500,int=0,int=500,string="BOT");
	virtual ~Luchadores();
	virtual int ataquar(int)=0;
	virtual void LevelUp(int)=0;
	virtual void UseMoney(int)=0;
	virtual int GetMoney()=0;
	virtual void WinMoney()=0;
	virtual string toString()=0;
	virtual int herir(int)=0;
	virtual void Cambiar_nombre(string)=0;
};