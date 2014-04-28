lex ijparser.l && yacc -d ijparserdebug.y && cc -o ijparser y.tab.c lex.yy.c -ll -ly && ./ijparser #-t < gcd.ijava
