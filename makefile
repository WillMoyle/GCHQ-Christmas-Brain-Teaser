OBJ = gchq.o table.o
EXEC = gchq
TAGS = g++ -Wall -g

$(EXEC): $(OBJ)
	$(TAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(TAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)