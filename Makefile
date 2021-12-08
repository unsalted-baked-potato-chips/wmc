wmc: src/wmc.c src/parse.c src/parse.h
	mkdir -p bin/
	gcc src/wmc.c src/parse.c -o bin/wmc

clean:
	rm -rf bin/

.PHONY: clean
