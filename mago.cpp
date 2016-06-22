
#include "luchadores.h"
#include "mago.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Mago::Mago(int vida,int fuerza_base,int money,string nombre,int magia):Luchadores(vida,fuerza_base,money,nombre),magia(magia){

}
Mago::~Mago(){

}
int Mago::ataquar(int numero){

}
void Mago::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Mago::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Mago::toString(){
	stringstream ss;
	ss << "Mago"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre<<" "<<"magia="<<magia;
	return ss.str();
}
int Mago::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	return vida;
}
void Mago::Cambiar_nombre(string name){
	nombre = name;
}
int Mago::GetMoney(){
	return money;
}
void Mago::WinMoney(){
	int win=10;
	money +=10;
}
