I_DIR=./includes
O_DIR=./obj
SRC_DIR=./src
CC=g++
CFLAGS=-I $(I_DIR)

DEPS=$(wildcard $(I_DIR)/*.h)

#-------------------------------------------------------
# specific to project
_SRC=$(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/cash_withdraw/*.cc $(SRC_DIR)/atm_state/*.cc ./*.cc)
SRC=$(notdir $(_SRC))
_OBJ=$(SRC:.cc=.o)
OBJ=$(patsubst %,$(O_DIR)/%,$(_OBJ))
VPATH:=./;src;src/cash_withdraw;src/atm_state
$(info $(OBJ))
#-------------------------------------------------------

OBJECT_HEADER = "********************** Building object file **********************"
PROJECT_HEADER = "********************** Building executable **********************"

$(O_DIR)/%.o: %.cc $(DEPS)
	$(info )
	$(info $(OBJECT_HEADER))
	$(info )
	$(CC) -c -g -o $@ $< $(CFLAGS)

atm: $(OBJ)
	$(info )
	$(info $(PROJECT_HEADER))
	$(info )
	$(CC) -g -o $@ $^

.PHONY: clean

clean:
	del $(subst /,\,$(OBJ)) $(wildcard *.exe)