.PHONY: all clean

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))
OKS := $(patsubst %.c, %.ok, $(SRCS))

all: $(OBJS) $(OKS)

%.o: %.c
	@gcc -o $@ $<

%.ok: %.o
	@echo "\033[32m*** Running $< ***\n\033[0m"
	@./$<
	@touch $@

clean:
	@rm -rf *.o *.ok