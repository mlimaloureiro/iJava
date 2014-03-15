%{
	int in_comment = 0;
%}

numero				[0-9]+

%S IN_COMMENT

%%

<INITIAL>"/*"									{BEGIN IN_COMMENT; in_comment = 1;}
<INITIAL>"if"									{printf("IF\n");}
<INITIAL>"else"									{printf("ELSE\n");}
<INITIAL>"while"								{printf("WHILE\n");}
<INITIAL>"&&"									{printf("OP1(%s)\n", yytext);}
<INITIAL>"||"									{printf("OP1(%s)\n", yytext);}
<INITIAL>"<"									{printf("OP2(%s)\n", yytext);}
<INITIAL>">"									{printf("OP2(%s)\n", yytext);}
<INITIAL>"=="									{printf("OP2(%s)\n", yytext);}
<INITIAL>"!="									{printf("OP2(%s)\n", yytext);}
<INITIAL>"<="									{printf("OP2(%s)\n", yytext);}
<INITIAL>">="									{printf("OP2(%s)\n", yytext);}
<INITIAL>"+"									{printf("OP3(%s)\n", yytext);}
<INITIAL>"-"									{printf("OP3(%s)\n", yytext);}
<INITIAL>"*"									{printf("OP4(%s)\n", yytext);}
<INITIAL>"/"									{printf("OP4(%s)\n", yytext);}
<INITIAL>"%"									{printf("OP4(%s)\n", yytext);}
<INITIAL>"!"									{printf("NOT\n");}
<INITIAL>"="									{printf("ASSIGN\n");}
<INITIAL>";"									{printf("SEMIC\n");}
<INITIAL>","									{printf("COMMA\n");}
<INITIAL>{numero}								{printf(" integer ");}
<INITIAL>. 									{;}
<INITIAL>[\n]									{;}
<IN_COMMENT>"*/"			{BEGIN INITIAL; in_comment = 0;};	
<IN_COMMENT>.				{;};	
<IN_COMMENT>\n				{;};

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

