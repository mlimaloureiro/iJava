%S JAVADOC
%%
"/**"          		{ BEGIN JAVADOC;}
<JAVADOC>"@param".*	{printf("\nParametro: %s", &yytext[6]);}
<JAVADOC>"@return".*    {printf("\nDevolve %s", &yytext[7]);}
<JAVADOC>"@see".*       ; //ignorar 
<JAVADOC>"*"" "*	;
<JAVADOC><p>		{printf("\n");}
<JAVADOC>"*/"     	{BEGIN 0; printf("\n");} //regressar ao modo normal
<JAVADOC>\n		; 
<JAVADOC>.              ECHO;
.      			;	//Caso seja codigo normal java
\n			;	//nao faz nada
%%
int main()
{
yylex();
}

int yywrap()
{
return 1;
}
