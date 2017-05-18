########################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
EJS = graph_test p1_e1 p1_e2
########################################################
OBJECTSGRAPHTEST = graph_test.o graph.o node.o
OBJECTSP1_E1 = p1_e1.o node.o
OBJECTSP1_E2 = p1_e2.o graph.o node.o
########################################################

all: $(EJS) clear

graph_test: $(OBJECTSGRAPHTEST)
	$(CC) $(CFLAGS) -o graph_test $(OBJECTSGRAPHTEST)

p1_e1: $(OBJECTSP1_E1)
	$(CC) $(CFLAGS) -o p1_e1 $(OBJECTSP1_E1)

p1_e2: $(OBJECTSP1_E2)
	$(CC) $(CFLAGS) -o p1_e2 $(OBJECTSP1_E2)

graph_test.o: graph_test.c graph.h node.h
	$(CC) $(CFLAGS) -c graph_test.c

p1_e1.o: p1_e1.c node.h
	$(CC) $(CFLAGS) -c p1_e1.c

p1_e2.o: p1_e2.c graph.h node.h
	$(CC) $(CFLAGS) -c p1_e2.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

clear:
	rm -rf *.o 

clean:
	rm -rf *.o $(EJS)

run:
	@echo ">>>>>>Running p1_e1"
	./p1_e1
	@echo ">>>>>>Running p1_e2"
	./p1_e2
	@echo ">>>>>>Running graph_test"
	./graph_test g2.txt

runv:
	@echo ">>>>>>Running p1_e1 with valgrind"
	valgrind --leak-check=full ./p1_e1
	@echo ">>>>>>Running p1_e2 with valgrind"
	valgrind --leak-check=full ./p1_e2
	@echo ">>>>>>Running graph_test with valgrind"
	valgrind --leak-check=full ./graph_test g2.txt
	

