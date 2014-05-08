lex ijparser.l && yacc -d ijparser.y
cc -o ijparser y.tab.c lex.yy.c functions.c show.c -ll -ly
zip -r ijparser.zip ijparser.y ijparser.l functions.c show.c functions.h structures.h show.h
./ijparser -t < $1
