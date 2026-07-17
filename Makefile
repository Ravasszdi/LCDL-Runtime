CC = gcc
ARGS = -Wall -ffreestanding -nostdlib
OUTPUT = ./.build
FILES = $(OUTPUT)/main.o $(OUTPUT)/libs/runtime.o $(OUTPUT)/libs/operators.o $(OUTPUT)/libs/lexer.o $(OUTPUT)/libs/arenas.o

$(OUTPUT)/main.o: ./src/main.c
	@echo "making main.o"
	@$(CC) $(ARGS) -c ./src/main.c -o $(OUTPUT)/main.o

$(OUTPUT)/libs/runtime.o: ./src/hami_pass32/runtime/runtime.c
	@echo "making runtime.o"
	@$(CC) $(ARGS) -c ./src/hami_pass32/runtime/runtime.c -o $(OUTPUT)/libs/runtime.o


$(OUTPUT)/libs/operators.o: ./src/hami_pass32/operators/operators.c
	@echo "making operators.o"
	@$(CC) $(ARGS) -c ./src/hami_pass32/operators/operators.c -o $(OUTPUT)/libs/operators.o

$(OUTPUT)/libs/lexer.o: ./src/hami_pass32/lexer/lexer.c
	@echo "making operators.o"
	@$(CC) $(ARGS) -c ./src/hami_pass32/lexer/lexer.c -o $(OUTPUT)/libs/lexer.o

build: $(FILES) $(OUTPUT)
	@echo "making build.out"
	@$(CC) $(FILES) -o $(OUTPUT)/build.out

$(OUTPUT)/libs/arenas.o: ./src/arenas/arenas.c
	@echo "making main.o"
	@$(CC) $(ARGS) -c ./src/arenas/arenas.c -o $(OUTPUT)/libs/arenas.o

run: build $(OUTPUT)/build.out
	@echo "---Running program.---"
	@$(OUTPUT)/build.out
	@echo "---Program finished.---"

clear:
	@echo "Cleaning up!"
	rm -f ./build/libs/*
	rm -f ./build/*
	rm -f ./build/micro_controler/*

init:
	@echo "making file structure"
	mkdir build
	mkdir ./build/libs
	mkdir ./build/micro_controler
