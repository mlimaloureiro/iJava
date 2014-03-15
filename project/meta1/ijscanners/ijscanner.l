BOOLLIT = “true” | “false” INT = “int”
BOOL = “boolean”
NEW = “new”
IF = “if”
ELSE = “else”
WHILE = “while”
PRINT = “System.out.println”
PARSEINT = “Integer.parseInt”
CLASS = “class”
PUBLIC = “public”
STATIC = “static”
VOID = “void”
STRING = “String”
DOTLENGTH = “.length”
RETURN = “return”
OCURV = “(”
CCURV = “)”
OBRACE = “{”
CBRACE = “}”
OSQUARE = “[”
CSQUARE = “]”
OP1 = “&&” | “||”
OP2 = “<” | “>” | “==” | “!=” | “<=” | “>=”
OP3 = “+” | “-”
OP4 = “*” | “/” | “%”
NOT = “!”
ASSIGN = “=”
SEMIC = “;”
COMMA = “,”

numero				[0-9]+

%%
"if"								{printf("IF\n");}
"else"								{printf("ELSE\n");}
"while"								{printf("WHILE\n");}
"&&"								{printf("OP1(%s)\n", yytext);}
"||"								{printf("OP1(%s)\n", yytext);}
"<"									{printf("OP2(%s)\n", yytext);}
">"									{printf("OP2(%s)\n", yytext);}
"=="								{printf("OP2(%s)\n", yytext);}
"!="								{printf("OP2(%s)\n", yytext);}
"<="								{printf("OP2(%s)\n", yytext);}
">="								{printf("OP2(%s)\n", yytext);}
"+"									{printf("OP3(%s)\n", yytext);}
"-"									{printf("OP3(%s)\n", yytext);}
"*"									{printf("OP4(%s)\n", yytext);}
"/"									{printf("OP4(%s)\n", yytext);}
"%"									{printf("OP4(%s)\n", yytext);}
"!"									{printf("NOT\n");}
"="									{printf("ASSIGN\n");}
";"									{printf("SEMIC\n");}
","									{printf("COMMA\n");}
{numero}							{printf(" integer ");}
. 									{;}
[\n]								{;}

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

