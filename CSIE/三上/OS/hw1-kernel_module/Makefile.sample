CC := gcc
override CFLAGS += -O3 -Wall

SOURCE := app.c
BINARY := app

GIT_HOOKS := .git/hooks/applied
all: $(GIT_HOOKS) $(BINARY)

debug: CFLAGS += -DDEBUG -g
debug: $(GIT_HOOKS) $(BINARY)

$(GIT_HOOKS):
	scripts/install-git-hooks

$(BINARY): $(SOURCE) $(patsubst %.c, %.h, $(SOURCE))
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(BINARY)