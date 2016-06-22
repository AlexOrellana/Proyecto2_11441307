
#include "luchadores.h"
#include "tirador.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Tirador::Tirador(int vida,int fuerza_base,int money,string nombre,int tiros):Luchadores(vida,fuerza_base,money,nombre),tiros(tiros){

}
Tirador::~Tirador(){

}
int Tirador::ataquar(int numero){

}
void Tirador::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Tirador::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Tirador::toString(){
	stringstream ss;
	ss << "Tirador"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre<<" "<<"tiros="<<tiros;
	return ss.str();
}
int Tirador::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	return vida;
}
void Tirador::Cambiar_nombre(string name){
	nombre = name;
}
int Tirador::GetMoney(){
	return money;
}
void Tirador::WinMoney(){
	int win=10;
	money +=10;
}