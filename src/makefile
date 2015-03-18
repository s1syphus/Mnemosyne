OBJS = mnemosyne.o net.o dataIn.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

mnemosyne: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mnemosyne

mnemosyne.o: mnemosyne.cpp net.h
	$(CC) $(CFLAGS) mnemosyne.cpp

dataIn.o: dataIn.cpp dataIn.h
	$(CC) $(CFLAGS) dataIn.cpp

neuron.o: neuron.cpp neuron.h
	$(CC) $(CFLAGS) neuron.cpp

net.o: net.cpp net.h neuron.h
	$(CC) $(CFLAGS) net.cpp

clean:
	rm *.o mnemosyne


