ROOTINC = $(shell root-config --cflags) -std=c++1y
ROOTLIB = $(shell root-config --libs)


OBJ = lumi_plot.o


all : lumi_plot

.SUFFIXES: .C .o

.C.o : 
	g++ $(ROOTINC) -c $<

lumi_plot : $(OBJ)
	g++  -o $@ $(OBJ) $(ROOTLIB) 

clean : 
	rm -rf *.o *~ lumi_plot thesis_lumi.pdf
