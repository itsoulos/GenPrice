####################################################################################################################
############### MAKEFILE FOR THE MINFINDER #########################################################################
OBJS = problem.o tolmin.o collection.o get_options_price.o genprice.o doublestack.o fparser.o population.o program.o rule.o symbol.o genpricemain.o grs.o rlsprogram.o

include ../Makefile.inc

all: $(OBJS)  make_genprice

grs.o: grs.cc
	$(CXX) grs.cc -I. -I../include -c

rlsprogram.o: rlsprogram.cc
	$(CXX) rlsprogram.cc -I. -I../include -c

genpricemain.o: genpricemain.cc
	$(CXX) genpricemain.cc -I. -I../include -c

genprice.o: genprice.cc
	$(CXX) genprice.cc -I. -I../include -c

problem.o: problem.cc
	$(CXX) problem.cc -I../include -c 

collection.o: collection.cc
	$(CXX) collection.cc -I../include -c 

tolmin.o: tolmin.cc
	$(CXX) tolmin.cc -I. -I../include -c 

get_options_price.o: get_options_price.cc
	$(CXX) get_options_price.cc -I. -I../include -c

doublestack.o: doublestack.cc
	$(CXX) doublestack.cc -I. -I../include -c

fparser.o: fparser.cc
	$(CXX) fparser.cc -I. -I../include -c

population.o: population.cc
	$(CXX) population.cc -I. -I../include -c

program.o: program.cc
	$(CXX) program.cc -I. -I../include -c

rule.o: rule.cc
	$(CXX) rule.cc -I. -I../include -c

symbol.o: symbol.cc
	$(CXX) symbol.cc -I. -I../include -c

make_genprice: make_genprice.cc
	$(CXX) make_genprice.cc -DCC=\"$(CC)\" -DCXX=\"$(CXX)\" -DF77=\"$(F77)\" -DF77FLAGS=\"$(F77FLAGS)\" -DROOTDIR=\"$(ROOTDIR)\" -o make_genprice
	mv make_genprice ../bin

clean:
	rm -f *~ *.o   make_genprice 
#######################################################################################################################
#######################################################################################################################
