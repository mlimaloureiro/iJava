lex ijparser.l && yacc -d ijparser.y
cc -o ijparser y.tab.c lex.yy.c functions.c show.c -ll -ly
./ijparser -t < gcd.ijava
