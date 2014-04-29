%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "structures.h"
	int in_comment = 0;
	int in_dash_comment = 0;
	int linha=1;
	int coluna=0;
	int linhaerro=1;
	int colunaerro=0;
	void conta();
%}

%S IN_COMMENT DASH_COMMENT

%%
<INITIAL>"//"										{conta();BEGIN DASH_COMMENT; in_dash_comment = 1; linhaerro = linha; colunaerro = coluna-2;}
<INITIAL>"/*"										{conta();BEGIN IN_COMMENT; in_comment = 1; linhaerro = linha; colunaerro = coluna-2;}
<INITIAL>"("                         				{conta();return OCURV;}
<INITIAL>")"										{conta();return CCURV;}
<INITIAL>"{"										{conta();return OBRACE;}
<INITIAL>"}"										{conta();return CBRACE;}
<INITIAL>"["										{conta();return OSQUARE;}
<INITIAL>"]"										{conta();return CSQUARE;}
<INITIAL>"true"										{conta();yylval.value=(char*)strdup(yytext); return BOOLLIT;}
<INITIAL>"false"									{conta();yylval.value=(char*)strdup(yytext); return BOOLLIT;}
<INITIAL>"int"										{conta();return INT;}
<INITIAL>"boolean"									{conta();return BOOL;}
<INITIAL>"new"										{conta();return NEW;}
<INITIAL>"System.out.println"						{conta();return PRINT;}
<INITIAL>"Integer.parseInt"							{conta();return PARSEINT;}
<INITIAL>"class"									{conta();return CLASS;}
<INITIAL>"public"									{conta();return PUBLIC;}
<INITIAL>"static"									{conta();return STATIC;}
<INITIAL>"void"										{conta();return VOID;}
<INITIAL>"String"									{conta();return STRING;}
<INITIAL>".length"									{conta();return DOTLENGTH;}
<INITIAL>"return"									{conta();return RETURN;}
<INITIAL>"if"										{conta();return IF;}
<INITIAL>"else"										{conta();return ELSE;}
<INITIAL>"while"									{conta();return WHILE;}
<INITIAL>"abstract"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"null"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"assert"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"break"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"byte"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"case"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"catch"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"char"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"const"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"continue"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"default"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"do"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"double"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"enum"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"extends"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"final"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"finally"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"float"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"for"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"goto"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"implements"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"import"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"instanceof"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"interface"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"long"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"native"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"package"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"private"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"protected"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"short"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"strictfp"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"super"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"switch"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"synchronized"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"this"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"throw"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"throws"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"transient"								{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"try"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"volatile"									{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"++"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"--"										{conta();yylval.value=(char*)strdup(yytext);return RESERVED;}
<INITIAL>"&&"										{conta();yylval.value=(char*)strdup(yytext);return OP1;}
<INITIAL>"||"										{conta();yylval.value=(char*)strdup(yytext);return OP1;}
<INITIAL>"<"										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>">"										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>"=="										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>"!="										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>"<="										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>">="										{conta();yylval.value=(char*)strdup(yytext);return OP2;}
<INITIAL>"+"										{conta();yylval.value=(char*)strdup(yytext);return OP3;}
<INITIAL>"-"										{conta();yylval.value=(char*)strdup(yytext);return OP3;}
<INITIAL>"*"										{conta();yylval.value=(char*)strdup(yytext);return OP4;}
<INITIAL>"/"										{conta();yylval.value=(char*)strdup(yytext);return OP4;}
<INITIAL>"%"										{conta();yylval.value=(char*)strdup(yytext);return OP4;}
<INITIAL>"!"										{conta();return NOT;}
<INITIAL>"="										{conta();return ASSIGN;}
<INITIAL>";"										{conta();return SEMIC;}
<INITIAL>","										{conta();return COMMA;}
<INITIAL>([a-zA-Z_$])+([0-9a-zA-Z_$])*				{conta();yylval.identifier=(char*)strdup(yytext); return ID;}
<INITIAL>(([1-9])([0-9])*|0+([1-9])([0-9])*|0+)	  	{conta();yylval.intlit=atoi(yytext);return INTLIT;}
<INITIAL>(0[xX][0-9a-fA-F]+)	  					{conta();yylval.intlit=atoi(yytext); return INTLIT;}
<INITIAL>\n|\t|[ ]									{conta();};
<INITIAL>.											{printf("Line %d, col %d: illegal character ('%c')\n",linha,coluna,yytext[0]);conta();};
<IN_COMMENT>"*/"									{conta();BEGIN INITIAL; in_comment = 0;};
<IN_COMMENT>.										{conta();};
<IN_COMMENT>\n										{conta();};
<DASH_COMMENT>.										{conta();};
<DASH_COMMENT>\n									{conta();BEGIN INITIAL; in_dash_comment = 0;};

%%

int yywrap()
{
	if(in_comment) {
		printf ("Line %d, col %d: unterminated comment\n", linhaerro, colunaerro);
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
