%{
    #include<stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '/' '*'

%%
calc: 		expression 			{printf("%d\n", $1);}

expression:	expression '+' expression {$$=$1+$3;}
	| 	expression '-' expression  	  {$$=$1-$3;}
	| 	expression '/' expression  	  {$$=$1/$3;}
	| 	expression '*' expression  	  {$$=$1*$3;}
	| 	NUMBER				          {$$=$1;}
    |   '(' expression ')'            {$$=$2;}
	;

%%
int main()
{
    yyparse();
}
