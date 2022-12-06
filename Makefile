OUTPUT	:= output
SRC		:= src
INCLUDE	:= inc
LIB		:= lib

MAIN	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p

INCLUDES:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
LIBS	:= $(patsubst %,-L%, $(LIBDIRS:%/=%))
SOURCES	:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS	:= $(SOURCES:.c=.o)

OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)
	
$(MAIN): $(OBJECTS) 
	$(CC) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LIBS)

.c.o:
	$(CC) $(INCLUDES) -c $<  -o $@ 

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!