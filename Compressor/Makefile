INC=-I./include

all: compr
clean:
	rm parser.cpp parser.hpp parser tokens.cpp

pre_parser.cpp: pre_parser.y
	/opt/local/bin/bison -d $^ -o $@

parser.cpp: parser.y
	/opt/local/bin/bison -d $^ -o $@

pre_tokens.cpp: pre_tokens.l
	/opt/local/bin/flex -o $@ $^

tokens.cpp: tokens.l
	/opt/local/bin/flex -o $@ $^

compr: preprocessor.cpp pre_parser.cpp pre_tokens.cpp types.cpp expressions.cpp instructions.cpp blocks.cpp workspace.cpp parser.cpp tokens.cpp main.cpp
	g++ -g -Wall $(INC) -o ../Product/$@ $^

#