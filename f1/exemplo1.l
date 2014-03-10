numero				[0-9]+

%%

{numero}				{printf(" Inteiro ");}
{numero}"."{numero}		{printf(" Real ");}
"-"{numero} 			{printf(" Inteiro negativo ");}
"-"{numero}"."{numero}  {printf(" Real negativo ");}

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

