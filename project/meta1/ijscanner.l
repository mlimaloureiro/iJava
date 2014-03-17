%{
	int in_comment = 0;
	int in_dash_comment = 0;
	int linha=0;
	int coluna=0;
	int linhaerro=0;
	int colunaerro=0;
	void conta();
	int ilegallcaracter;
%}

%S IN_COMMENT DASH_COMMENT

%%
<INITIAL>"//"										{conta(); BEGIN DASH_COMMENT; in_dash_comment = 1;}
<INITIAL>"/*"										{conta(); BEGIN IN_COMMENT; in_comment = 1; linhaerro = linha; colunaerro = coluna-2;}
<INITIAL>"("										{conta(); printf("OCURV\n");}
<INITIAL>")"										{conta();printf("CCURV\n");}
<INITIAL>"{"										{conta();printf("OBRACE\n");}
<INITIAL>"}"										{conta();printf("CBRACE\n");}
<INITIAL>"["										{conta();printf("OSQUARE\n");}
<INITIAL>"]"										{conta();printf("CSQUARE\n");}
<INITIAL>"true"										{conta();printf("BOOLLIT(%s)\n", yytext);}
<INITIAL>"false"									{conta();printf("BOOLLIT(%s)\n", yytext);}
<INITIAL>"int"										{conta();printf("INT\n");}
<INITIAL>"boolean"									{conta();printf("BOOL\n");}
<INITIAL>"new"										{conta();printf("NEW\n");}
<INITIAL>"System.out.println"						{conta();printf("PRINT\n");}
<INITIAL>"Integer.parseInt"							{conta();printf("PARSEINT\n");}
<INITIAL>"class"									{conta();printf("CLASS\n");}
<INITIAL>"public"									{conta();printf("PUBLIC\n");}
<INITIAL>"static"									{conta();printf("STATIC\n");}
<INITIAL>"void"										{conta();printf("VOID\n");}
<INITIAL>"String"									{conta();printf("STRING\n");}
<INITIAL>".length"									{conta();printf("DOTLENGTH\n");}
<INITIAL>"return"									{conta();printf("RETURN\n");}
<INITIAL>"if"										{conta();printf("IF\n");}
<INITIAL>"else"										{conta();printf("ELSE\n");}
<INITIAL>"while"									{conta();printf("WHILE\n");}
<INITIAL>"abstract"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"null"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"assert"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"break"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"byte"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"case"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"catch"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"char"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"const"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"continue"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"default"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"do"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"double"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"enum"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"extends"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"final"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"finally"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"float"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"for"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"goto"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"implements"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"import"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"instanceof"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"interface"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"long"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"native"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"package"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"private"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"protected"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"short"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"strictfp"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"super"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"switch"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"synchronized"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"this"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"throw"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"throws"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"transient"								{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"try"										{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"volatile"									{conta();printf("RESERVED(%s)\n", yytext);}
<INITIAL>"&&"										{conta();printf("OP1(%s)\n", yytext);}
<INITIAL>"||"										{conta();printf("OP1(%s)\n", yytext);}
<INITIAL>"<"										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>">"										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>"=="										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>"!="										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>"<="										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>">="										{conta();printf("OP2(%s)\n", yytext);}
<INITIAL>"+"										{conta();printf("OP3(%s)\n", yytext);}
<INITIAL>"-"										{conta();printf("OP3(%s)\n", yytext);}
<INITIAL>"*"										{conta();printf("OP4(%s)\n", yytext);}
<INITIAL>"/"										{conta();printf("OP4(%s)\n", yytext);}
<INITIAL>"%"										{conta();printf("OP4(%s)\n", yytext);}
<INITIAL>"!"										{conta();printf("NOT\n");}
<INITIAL>"="										{conta();printf("ASSIGN\n");}
<INITIAL>";"										{conta();printf("SEMIC\n");}
<INITIAL>","										{conta();printf("COMMA\n");}
<INITIAL>(\"(((\\)?[^\"\n\\])|\\\\|\\\")*\") 		{conta();printf("STRLIT(%s)\n", yytext);}
<INITIAL>(\'(((\\)?[^'\n\\])|\\\\|\\')\') 			{conta();printf("CHRLIT(%s)\n", yytext);}
<INITIAL>([a-zA-Z_$])+([0-9a-zA-Z_$])*				{conta();printf("ID(%s)\n", yytext);}
<INITIAL>(([1-9])([0-9])*|0)	  					{conta();printf("INTLIT(%s)\n", yytext);}
<INITIAL>(0[xX][0-9a-fA-F]+)	  					{conta();printf("INTLIT(%s)\n", yytext);}
<INITIAL>[\n]										{conta();}
<INITIAL>. 											{printf("Line %d, col %d: illegal character ('%c')\n",linha+1,coluna+1,yytext[0]);conta();}
<IN_COMMENT>"*/"									{conta();BEGIN INITIAL; in_comment = 0;};	
<IN_COMMENT>.										{conta();};	
<IN_COMMENT>\n										{conta();};
<DASH_COMMENT>.										{conta();};
<DASH_COMMENT>\n									{conta();BEGIN INITIAL; in_comment = 0;};


%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	if(in_comment) {
		printf ("Line %d, col %d: unterminated comment\n", linhaerro+1, colunaerro+1);
	}
	return 1;
}

void conta()
{
	int i;
	for(i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n'){
			linha++;
			coluna = 0;
		}
		
		else
			coluna++;
	}
}
