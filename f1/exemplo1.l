numero				[0-9]+
token				ab+c
tokenB				[b|B]
tokenC				[c|C]
token2				a?({tokenB}{tokenC})+


%%

{numero}				{printf(" integer ");}
{numero}"l"				{printf(" long ");}
{numero}"u"				{printf(" unsigned int ");}
{numero}"ul"			{printf(" unsigned long ");}
{numero}","{numero}		{printf(" float ");}
{numero}"."{numero}		{printf(" float ");}
{numero}"e-"{numero}    {printf(" floating point ");}
{numero}"e+"{numero}    {printf(" floating point ");}
{numero}"f"    			{printf(" float ");}

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

