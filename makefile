main:
	gcc dush.c bootstrap.c path.c parser.c handleBuiltIn.c executeCommand.c -o dush

clean:
	rm -f dush