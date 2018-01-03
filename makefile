CC = gcc

CFLAGS = -Wall -Lsrc

RM = rm -f

OBJS = main.c trie.c

VALGRIND = valgrind -v --read-var-info=yes --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes
#VALGRIND = valgrind  --read-var-info=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --track-origins=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --tool=memcheck

MAIN = tp0

$(MAIN): $(OBJS)
	@echo ""
	@echo "------------------------"
	@echo " Compilando programa..."
	@echo "------------------------"
	@$(CC) $(CFLAGS) $(OBJS) -g3 -std=c99 -o $(MAIN)
	@echo "------------------------"
	@echo " Compilacao feita com sucesso!"
	@echo "------------------------"

%.o: %.c %.h
	@echo "------------------------"
	@echo " Compilando objeto \"$@\""
	@echo "------------------------"
	@$(CC) $(CFLAGS) $< -c

clean:
	$(RM) $(MAIN) *.o *~ testes/*~
	$(RM) entrada/ent* saida/sai* tempo/*
	clear

val: $(MAIN)
	$(VALGRIND) ./$(MAIN) input.txt output.txt

run: $(MAIN)
	@echo " Executando programa..."
	@echo "------------------------"
	@echo ""
	./$(MAIN) input.txt output.txt

all: clean run val
