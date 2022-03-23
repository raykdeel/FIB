OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11



program.exe: program.o 
	g++ -o program.exe program.o ConsultaBool_IO2.o coleccion.o album.o foto.o fecha.o $(OPCIONS)

program.o: program.cc coleccion.o
	g++ -c program.cc $(OPCIONS)
	
	
coleccion.o: coleccion.cc album.cc coleccion.hh ConsultaBool_IO2.o 
	g++ -c coleccion.cc album.cc $(OPCIONS)
	
ConsultaBool_IO2.o: ConsultaBool_IO2.cc ConsultaBool_IO.hh foto.o
	g++ -c ConsultaBool_IO2.cc ConsultaBool_IO.hh $(OPCIONS)	
	
foto.o: foto.cc foto.hh fecha.o
	g++ -c foto.cc $(OPCIONS)
	
fecha.o: fecha.cc fecha.hh
	g++ -c fecha.cc $(OPCIONS)
	
practica.tar: program.cc
	tar -cvf practica.tar program.cc coleccion.cc coleccion.hh album.cc ConsultaBool_IO2.cc ConsultaBool_IO.hh foto.cc foto.hh fecha.cc fecha.hh makefile html.zip

clear:
	rm -f *.o
	rm -f *.gch
	rm -f *.tar
