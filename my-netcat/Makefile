CC := gcc
RM := rm -f
CFLAGS := -Wall -g
OBJS := main.o util.o net.o
BIN := my-netcat

PHONY =

PHONY += all

PREFIX ?= /usr/local
BIN_INSTALL_DIR = $(PREFIX)/bin

$(BIN): $(OBJS)
	# $(CC) $< -o $@
	# gcc x.o y.o -o my-netcat
	$(CC) $^ -o $@

PHONY += gen-deps
Makefile.deps:
	gcc -MM *.c > Makefile.deps

include Makefile.deps


PHONY += test
test:
	$(CC) $(CFLAGS) util.c util_test.c -o util_test.out \
		&& ./util_test.out \
		&& echo "util test success"

PHONY += install
install:
	-mkdir -p $(BIN_INSTALL_DIR) && mv $(BIN) $(BIN_INSTALL_DIR)


PHONY += uninstall
uninstall:
	-$(RM) $(BIN_INSTALL_DIR)/$(BIN)


PHONY += clean
clean:
	$(RM) *.o *.out $(BIN)


.PHONY: $(PHONY)
