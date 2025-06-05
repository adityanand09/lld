IDIR=./includes
ODIR=./obj
SRCDIR=./src
CC=g++
CFLAGS=-I $(IDIR)

# _DEPS=board.h piece.h player.h tic_tac_toe.h
# DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS));
DEPS=$(wildcard $(IDIR)/*.h)


SRC=$(wildcard $(SRCDIR)/*.cpp ./*.cpp)
_SRC=$(notdir $(SRC))
#$(info $(SRC))

_OBJ=$(_SRC:.cpp=.o) #pattern substition
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
# $(info $(OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(info )
	$(info  ********************** Building object file **********************)
	$(info )
	$(CC) -c -g -o $@ $< $(CFLAGS)

$(ODIR)/%.o: ./%.cpp $(DEPS)
	$(info )
	$(info  ********************** Building object file **********************)
	$(info )
	$(CC) -c -g -o $@ $< $(CFLAGS)

tictactoe: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	del $(subst /,\,$(OBJ)) $(wildcard *.exe)