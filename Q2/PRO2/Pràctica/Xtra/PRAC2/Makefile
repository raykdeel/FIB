OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Sala.o Almacen.o Cjt_salas.o Cjt_productos.o
	g++ -o program.exe *.o 

Cjt_productos.o: Cjt_productos.cc Cjt_productos.hh 
	g++ -c Cjt_productos.cc $(OPCIONS) 

Sala.o: Sala.cc Sala.hh 
	g++ -c Sala.cc $(OPCIONS) 

Cjt_salas.o: Cjt_salas.cc Cjt_salas.hh Sala.hh
	g++ -c Cjt_salas.cc $(OPCIONS) 

Almacen.o: Almacen.cc Almacen.hh BinTree.hh
	g++ -c Almacen.cc $(OPCIONS) 

program.o: program.cc Sala.hh Cjt_productos.hh Cjt_salas.hh Almacen.hh BinTree.hh
	g++ -c program.cc $(OPCIONS) 

clean:
	rm *.o
	rm *.exe
