OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Especie.o Cjt_Especies.o Cluster.o Cjt_Clusters.o
	g++ -o program.exe program.o Especie.o Cjt_Especies.o Cluster.o Cjt_Clusters.o

Especie.o: Especie.cc Especie.hh 
	g++ -c Especie.cc $(OPCIONS)

Cjt_Especies.o: Cjt_Especies.cc Cjt_Especies.hh Especie.hh
	g++ -c Cjt_Especies.cc $(OPCIONS) 

Cluster.o: Cluster.cc Cluster.hh Cjt_Especies.hh
	g++ -c Cluster.cc $(OPCIONS)

Cjt_Clusters.o: Cjt_Clusters.cc Cjt_Clusters.hh Cluster.hh
	g++ -c Cjt_Clusters.cc $(OPCIONS) 

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

practica.tar: program.cc
	tar -cvf practica.tar program.cc Especie.cc Especie.hh Cjt_Especies.cc Cjt_Especies.hh Cluster.cc Cluster.hh Cjt_Clusters.cc Cjt_Clusters.hh makefile

clean: 
	rm -f *.o
	rm -f *.exe