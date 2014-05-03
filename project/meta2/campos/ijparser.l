variable				([a-z]|[A-Z]|"_"|"$")+([0-9]|[a-z]|[A-Z]|"_"|"$")*
number					[0-9]+
hexa					"0x"([a-f]|[A-F]|[0-9])+

%{
	#define YY_USER_ACTION nCol+=yyleng;nLine=yylineno; 

	#include "functions.h"
	#include "y.tab.h"
	int nCol = 0;
	int comLine;
	int comCol;

	int nLine=1;
%}

%option yylineno
%X COMMENT

%%

"class"			{return CLASS;}

{number}|{hexa}				{yylval.num=atoi(yytext);return INTLIT;}

("&&"|"||")						{return OP1;}
("<"|">"|"=="|"!="|"<="|">=")	{return OP2;}
("+"|"-")						{return OP3;}
("*"|"/"|"%")					{return OP4;}

";"							{return SEMIC;}
","							{return COMMA;}
"="							{return ASSIGN;}
"!"							{return NOT;}

"{"							{return OBRACE;}
"}"							{return CBRACE;}

"("							{return OCURV;}
")"							{return CCURV;}

"["							{return OSQUARE;}
"]"							{return CSQUARE;}

"public"					{return PUBLIC;}
"static"					{return STATIC;}

"void"						{return VOID;}


"new"						{return NEW;}

"int"						{return INT;}

"String"					{return STRING;}

("true"|"false")			{return BOOLIT;}


"boolean"					{return BOOL;}

"return"					{return RETURN;}
".length"					{return DOTLENGTH;}

"Integer.parseInt"			{return PARSEINT;}
"System.out.println"		{return PRINT;}

"if"						{return IF;}
"else"						{return ELSE;}
"while"						{return WHILE;}



"abstract"|"continue"|"for"|"switch"|"assert"|"default"|"goto"|"package"                 		{return RESERVED;}
"do"|"private"|"this"|"break"|"double"|"implements"|"protected"|"throw"                  		{return RESERVED;}
"byte"|"import"|"throws"|"case"|"enum"|"instanceof"|"transient"|"null"                   		{return RESERVED;}
"catch"|"extends"|"short"|"try"|"char"|"final"|"interface"|"synchronized"                		{return RESERVED;}
"finally"|"long"|"strictfp"|"volatile"|"const"|"float"|"native"|"super"|"++"|"--"  				{return RESERVED;}


\t|\ 						;
\n						    {nCol=0;}
"//".*						;
"/*"						{BEGIN COMMENT;
							 comLine=yylineno;
							 comCol=nCol-1;
							}

<COMMENT>"*/"				{BEGIN 0;}

<COMMENT>"\n"				{nCol=0;}
<COMMENT>.					;

<COMMENT><<EOF>>			{printf("Line %d, col %d: unterminated comment\n",comLine,comCol);
							 yyterminate();
							}


{variable}					{yylval.id=(char*)strdup(yytext);return ID;}
.							{printf("Line %d, col %d: illegal character (\'%c\')\n",yylineno,nCol,yytext[0]);}
%%

int yywrap()
{
return 1;
}
