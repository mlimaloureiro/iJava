lex ijscanner.l && yacc -d ijparser.y && cc -o ijparser y.tab.c lex.yy.c -ll -ly && ./ijparser
