%{
    #include<stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '/' '*'

%%
calc: 		expression 			{printf("%d\n", $1);}
    |       'end'               {return -1;}

expression:	expression '+' expression {$$=$1+$3;}
	| 	expression '-' expression  	  {$$=$1-$3;}
	| 	expression '/' expression  	  {if($3 == 0) {printf("Error: Devide by 0!\n");return -1;} else {$$=$1/$3;}}
	| 	expression '*' expression  	  {$$=$1*$3;}
	| 	NUMBER				          {$$=$1;}
    |   '(' expression ')'            {$$=$2;}
	;

%%
int main()
{
    while(yyparse()!=(-1));
}
