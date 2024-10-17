# Nome dell'eseguibile
OUT_NAME=tests-e10

# Trova sorgenti, headers e nomi dei .o
HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:%c=%o)

# Compila l'eseguibile di default
all: $(OUT_NAME)

# Linking dell'eseguibile dai file oggetto
$(OUT_NAME): $(OBJECTS)
	g++ -o $(OUT_NAME) $(OBJECTS)

# Regola per creare ogni file oggetto
%.o: %.c
	g++ -c -o $@ $^ -I.

# Rimuovere i file compilati
clean:
	rm -rf $(OUT_NAME) $(OBJECTS) *~

# Ogni regola che non produce file va elencata qui
.PHONY: all clean
