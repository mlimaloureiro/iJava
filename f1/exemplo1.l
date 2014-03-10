numero				[0-9]+
token				ab+c
tokenB				[b|B]
tokenC				[c|C]
token2				a?({tokenB}{tokenC})+

%%

{numero}				{printf(" Inteiro ");}
{numero}"."{numero}		{printf(" Real ");}
"-"{numero} 			{printf(" Inteiro negativo ");}
"-"{numero}"."{numero}  {printf(" Real negativo ");}
"+"{numero} 			{printf(" Inteiro positivo explicito ");}
"+"{numero}"."{numero}  {printf(" Real positivo explicito ");}
{token}					{printf(" Token! ");}
{token2}				{printf(" Token! ");}

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

