
all: bclient bserver lsclient lsserver dclient drandom dserver fclient fserver 
exes = bclient bserver lsclient lsserver dclient drandom dserver fclient fserver


bclient: bclient.c osheaders.h
	g++ bclient.c -o bclient

bserver: bserver.c osheaders.h
	g++ bserver.c -o bserver
	
lsclient: lsclient.c osheaders.h
	g++ lsclient.c -o lsclient

lsserver: lsserver.c osheaders.h
	g++ lsserver.c -o lsserver

dclient: dclient.c osheaders.h
	g++ dclient.c -o dclient
	
drandom: drandom.c osheaders.h
	g++ drandom.c -o drandom

dserver: dserver.c osheaders.h
	g++ dserver.c -o dserver
	
fclient: fclient.c osheaders.h
	g++ fclient.c -o fclient

fserver: fserver.c osheaders.h
	g++ fserver.c -o fserver	
	
clean:
	rm $(exes)
	
	


