numero				[0-9]+

%%

{numero}				{printf(" Inteiro ");}
{numero}"."{numero}		{printf(" Real ");}
"-"{numero} 			{printf(" Inteiro negativo ");}
"-"{numero}"."{numero}  {printf(" Real negativo ");}
"+"{numero} 			{printf(" Inteiro positivo explicito ");}
"+"{numero}"."{numero}  {printf(" Real positivo explicito");}

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

