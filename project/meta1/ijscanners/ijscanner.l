%{
	int in_comment = 0;
%}

%S IN_COMMENT DASH_COMMENT

%%

<INITIAL>"//"										{BEGIN DASH_COMMENT; in_comment = 1;}
<INITIAL>"/*"										{BEGIN IN_COMMENT; in_comment = 1;}
<INITIAL>"("										{printf("OCURV\n");}
<INITIAL>")"										{printf("CCURV\n");}
<INITIAL>"{"										{printf("OBRACE\n");}
<INITIAL>"}"										{printf("CBRACE\n");}
<INITIAL>"["										{printf("OSQUARE\n");}
<INITIAL>"]"										{printf("CSQUARE\n");}
<INITIAL>"true"										{printf("BOOLLIT\n");}
<INITIAL>"false"									{printf("BOOLLIT\n");}
<INITIAL>"int"										{printf("INT\n");}
<INITIAL>"boolean"									{printf("BOOL\n");}
<INITIAL>"new"										{printf("NEW\n");}
<INITIAL>"System.out.println"						{printf("PRINT\n");}
<INITIAL>"Integer.parseInt"							{printf("PARSEINT\n");}
<INITIAL>"class"									{printf("CLASS\n");}
<INITIAL>"public"									{printf("PUBLIC\n");}
<INITIAL>"static"									{printf("STATIC\n");}
<INITIAL>"void"										{printf("VOID\n");}
<INITIAL>"String"									{printf("STRING\n");}
<INITIAL>".length"									{printf("DOTLENGTH\n");}
<INITIAL>"return"									{printf("RETURN\n");}
<INITIAL>"if"										{printf("IF\n");}
<INITIAL>"else"										{printf("ELSE\n");}
<INITIAL>"while"									{printf("WHILE\n");}
<INITIAL>"abstract"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"null"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"assert"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"break"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"byte"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"case"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"catch"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"char"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"const"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"continue"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"default"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"do"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"double"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"enum"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"extends"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"final"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"finally"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"float"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"for"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"goto"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"implements"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"import"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"instanceof"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"interface"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"long"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"native"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"package"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"private"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"protected"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"short"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"strictfp"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"super"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"switch"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"synchronized"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"this"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"throw"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"throws"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"transient"								{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"try"										{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"volatile"									{printf("RESERVED(%s)\n", yytext);}
<INITIAL>"&&"										{printf("OP1(%s)\n", yytext);}
<INITIAL>"||"										{printf("OP1(%s)\n", yytext);}
<INITIAL>"<"										{printf("OP2(%s)\n", yytext);}
<INITIAL>">"										{printf("OP2(%s)\n", yytext);}
<INITIAL>"=="										{printf("OP2(%s)\n", yytext);}
<INITIAL>"!="										{printf("OP2(%s)\n", yytext);}
<INITIAL>"<="										{printf("OP2(%s)\n", yytext);}
<INITIAL>">="										{printf("OP2(%s)\n", yytext);}
<INITIAL>"+"										{printf("OP3(%s)\n", yytext);}
<INITIAL>"-"										{printf("OP3(%s)\n", yytext);}
<INITIAL>"*"										{printf("OP4(%s)\n", yytext);}
<INITIAL>"/"										{printf("OP4(%s)\n", yytext);}
<INITIAL>"%"										{printf("OP4(%s)\n", yytext);}
<INITIAL>"!"										{printf("NOT\n");}
<INITIAL>"="										{printf("ASSIGN\n");}
<INITIAL>";"										{printf("SEMIC\n");}
<INITIAL>","										{printf("COMMA\n");}
<INITIAL>. 											{;}
<INITIAL>[\n]										{;}
<IN_COMMENT>"*/"									{BEGIN INITIAL; in_comment = 0;};	
<IN_COMMENT>.										{;};	
<IN_COMMENT>\n										{;};
<DASH_COMMENT>.										{;};
<DASH_COMMENT>\n									{BEGIN INITIAL; in_comment = 0;};
<INITIAL>([a-zA-Z"$"])+([0-9a-zA-Z_"$"])*			{printf("ID(%s)\n",yytext);}
<INITIAL>(([1-9])([0-9])*|0)	  					{printf("INTLIT(%s)\n",yytext);}
<INITIAL>(0[xX][0-9a-fA-F]+)	  					{printf("INTLIT(%s)\n",yytext);}

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

