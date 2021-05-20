###############################################################################
###############		TOP MAKEFILE OF THE TOOL ##############################
# There is no need to change this file. In order to customise the tool ########
# change the file Makefile.inc in the current directory #######################
all:
	(cd src; make )

clean:
	(rm -f *~; cd src; make clean )
	(mkdir -p bin; ) 
	(rm -f bin/make_genprice )
	(rm -f bin/GenPrice )
###############################################################################
