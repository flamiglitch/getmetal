PROG    := cfetch
CC      := cc
CCFLAGS := -Wall
LIB     := -lpthread -lvulkan
OBJ     := thrd/cpu.o thrd/gpu.o thrd/kernel.o thrd/board.o thrd/memory.o thrd/name.o thrd/distro.o
OWNER   := $(shell stat -c "%U" /usr/bin)

.PHONY: all clean install

$(PROG): $(OBJ)
	$(CC) main.c $(CCFLAGS) $(LIB) $(OBJ) -o $(PROG)

all: $(PROG)

install: $(PROG)
ifeq ($(OWNER), $(shell whoami))
	@cp -v $(PROG) /usr/bin/$(PROG)
else
	@echo run as $(OWNER)
endif

clean:
	rm -v $(OBJ) $(PROG)

thrd/%.o: thrd/%.c
	$(CC) -c $^ $(CCFLAGS) -o $@

thrd/cpu.o:    thrd/cpu.c
thrd/gpu.o:    thrd/gpu.c
thrd/kernel.o: thrd/kernel.c
thrd/board.o:  thrd/board.c
thrd/memory.o: thrd/memory.c
thrd/name.o:   thrd/name.c
thrd/distro.o: thrd/distro.c
