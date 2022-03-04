PROGRAM = hex-driver
IDIR = .
CC = g++
CFLAGS = $(patsubst %, -I%, $(IDIR))
CPPFLAGS =

ODIR = .
BDIR = build
TDIR = test
LDIR = ../lib

LIBS = -lstdc++

_OBJ = hexagon_math
OBJ = $(patsubst %, $(ODIR)/%.o, $(_OBJ) )

$(ODIR)/%.o: %.c $(IDIR)/%.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< $(LIBS)

$(BDIR)/$(PROGRAM): $(TDIR)/hex-driver.cpp $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS)

run:
	make
	./$(BDIR)/$(PROGRAM)
clean:
	rm -f *.o *.os *~ core
	rm $(BDIR)/$(PROGRAM)
