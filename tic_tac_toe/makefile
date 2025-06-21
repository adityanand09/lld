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

OBJECT_HEADER = "********************** Building object file **********************"
PROJECT_HEADER = "********************** Building executable **********************"

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(info )
	$(info $(OBJECT_HEADER))
	$(info )
	$(CC) -c -g -o $@ $< $(CFLAGS)

$(ODIR)/%.o: ./%.cpp $(DEPS)
	$(info )
	$(info $(OBJECT_HEADER))
	$(info )
	$(CC) -c -g -o $@ $< $(CFLAGS)

tictactoe: $(OBJ)
	$(info )
	$(info $(PROJECT_HEADER))
	$(info )
	$(CC) -o $@ $^

.PHONY: clean

clean:
	del $(subst /,\,$(OBJ)) $(wildcard *.exe)