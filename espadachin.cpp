
#include "luchadores.h"
#include "espadachin.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Espadachin::Espadachin(int vida,int fuerza_base,int money,string nombre):Luchadores(vida,fuerza_base,money,nombre){

}
Espadachin::~Espadachin(){

}
int Espadachin::ataquar(int numero){

}
void Espadachin::LevelUp(int numero){
	if (numero==1)
	{
		fuerza_base++;
	}else if (numero==2)
	{
		vida++;
	}
}
void Espadachin::UseMoney(int numero){
	int temp=money-numero;
	money=temp;
}
string Espadachin::toString(){
	stringstream ss;
	ss << "Espadachin"<<"----"<<"vida="<<vida<<" "<<"fuerza base="<<fuerza_base<<" "<<"dinero="<<money<<" "<<"nombre="<<nombre;
	return ss.str();
}
int Espadachin::herir(int dano){
	int nueva_vida=vida-dano;
	vida = nueva_vida;
	int vida;
}
void Espadachin::Cambiar_nombre(string name){
	nombre = name;
}
int Espadachin::GetMoney(){
	return money;
}
void Espadachin::WinMoney(){
	int win=10;
	money +=10;
}
