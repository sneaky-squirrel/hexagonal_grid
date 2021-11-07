PROGRAM = hex-driver
IDIR = .
CC = g++
CFLAGS = -I$(IDIR)
CPPFLAGS =

ODIR = .
BDIR = build
TDIR = test
LDIR = ../lib

LIBS = -lstdc++

_OBJ = hexagon_math.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ) )

$(ODIR)/%.o: %.c $(IDIR)/%.h
	$(CC) $(CPPFLAGS) -c -o $@ $< $(CFLAGS) $(LIBS)

$(BDIR)/$(PROGRAM): $(TDIR)/hex-driver.cpp $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^ $(CFLAGS)

run:
	make
	./$(BDIR)/$(PROGRAM)
clean:
	rm -f $(ODIR)/*.o *~ core
	rm $(PROGRAM)
