main: main.o luchadores.o mago.o melee.o priest.o tirador.o espadachin.o
	g++ main.o luchadores.o mago.o melee.o priest.o tirador.o espadachin.o -lncurses 
	
main.o:	main.cpp luchadores.h mago.h melee.h priest.h tirador.h espadachin.h
	g++ -c main.cpp 

luchadores.o:	luchadores.cpp luchadores.h
	g++ -c luchadores.cpp 

mago.o:	mago.cpp mago.h luchadores.h
	g++ -c mago.cpp

melee.o:	melee.cpp melee.h luchadores.h
	g++ -c melee.cpp

priest.o:	priest.cpp priest.h luchadores.h
	g++ -c priest.cpp

tirador.o:	tirador.cpp tirador.h luchadores.h
	g++ -c tirador.cpp

espadachin.o:	espadachin.cpp espadachin.h luchadores.h
	g++ -c espadachin.cpp