%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

letters		[a-zA-Z]

%%

{letters}	{char* c = strtoupper(yytext);printf("%s\n", c);}
.	;
\n	;

%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
