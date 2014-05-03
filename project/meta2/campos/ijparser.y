%{

	#include "functions.h"
	extern int nCol;
	extern int nLine;
	extern char *yytext;
	void yyerror(char *s);
	startNode* treeOfEternity = NULL;

%}

%union{
    
    int num;
    char* id;

	startNode* start;
	programNode* program;
	fieldOrMethodNode* fieldOrMethod;
	fieldDeclNode* fieldDecl;
	methodDeclNode* methodDecl;
	varDeclNode* varDecl;
	optionalVariableNode* optionalVariable;
	functionTypeNode* functionType;
	typeNode* type;
	varTypeNode* varType;
	optionalArrayNode* optionalArray;
	optionalFormalParamsNode* optionalFormalParams;
	formalParamsNode* formalParams;
	optionalParamNode* optionalParam;
	optionalVarDeclNode* optionalVarDecl;
	optionalStatementNode* optionalStatement;
	statementNode* statement;
	expressionNode* expression;
	optionalArrayPositionNode* optionalArrayPosition;
	optionalExpressionNode* optionalExpression;
	arrayDimNode* arrayDim;
	optionalArgsNode* optionalArgs;
	argsNode* args;
	optionalArgumentNode* optionalArgument;
	
}

%token <num> NUMBER
%token ENDOF
%token <id> ID
%token INTLIT
%token BOOLIT
%token INT
%token BOOL
%token NEW
%token IF
%token ELSE
%token WHILE
%token PRINT
%token PARSEINT
%token CLASS
%token PUBLIC
%token STATIC
%token VOID
%token STRING
%token DOTLENGTH
%token RETURN
%token OCURV
%token CCURV
%token OBRACE
%token CBRACE
%token OSQUARE
%token CSQUARE
%token OP1
%token OP2
%token OP3
%token OP4
%token NOT
%token ASSIGN
%token SEMIC
%token COMMA
%token RESERVED


%left OR
%left AND
%left EQUALS
%left OP1
%left OP2
%left OP3
%left OP4
%right NOT
%left DOTLENGTH
%left OCURV CCURV OSQUARE CSQUARE
%nonassoc ELSE

%type <start> Start
%type <program> Program
%type <fieldOrMethod> FieldOrMethod
%type <fieldDecl> FieldDecl
%type <methodDecl> MethodDecl
%type <varDecl> VarDecl
%type <optionalVariable> OptionalVariable
%type <functionType> FunctionType
%type <type> Type
%type <varType> VarType
%type <optionalArray> OptionalArray
%type <optionalFormalParams> OptionalFormalParams
%type <formalParams> FormalParams
%type <optionalParam> OptionalParam
%type <optionalVarDecl> OptionalVarDecl
%type <optionalStatement> OptionalStatement
%type <statement> Statement
%type <expression> Expr
%type <optionalArrayPosition> OptionalArrayPosition
%type <optionalExpression> OptionalExpr
%type <arrayDim> ArrayDim
%type <optionalArgs> OptionalArgs
%type <args> Args
%type <optionalArgument> OptionalArgument

%%
Start : Program 	{$$ = treeOfEternity = insertStart($1);}
;

Program : CLASS ID OBRACE FieldOrMethod CBRACE		{$$ = insertProgram($2,$4);}
;

FieldOrMethod:								{$$ = insertFieldOrMethod(NULL, NULL, NULL);}
			  |FieldDecl FieldOrMethod 		{$$ = insertFieldOrMethod($1, NULL, $2);}
			  |MethodDecl FieldOrMethod 	{$$ = insertFieldOrMethod(NULL, $1, $2);}
;

FieldDecl : STATIC VarDecl 					{$$ = insertFieldDecl($2);}
;

MethodDecl : PUBLIC STATIC FunctionType ID OCURV OptionalFormalParams CCURV OBRACE OptionalVarDecl OptionalStatement CBRACE {$$=insertMethodDecl($3,$4,$6,$9,$10);}
;

FunctionType: Type 	{$$ = insertFunctionType($1);}
			  |VOID {$$ = insertFunctionType(NULL);}
;

OptionalFormalParams:			  {$$ = insertOptionalFormalParams(NULL);}
					|FormalParams {$$ = insertOptionalFormalParams($1);}
;

FormalParams : Type ID OptionalParam {$$ = insertFormalParams($1,$2,$3);}
			 | STRING OSQUARE CSQUARE ID {$$ = insertFormalParams(NULL,$4,NULL);}
;

OptionalParam :								 {$$ = insertOptionalParam(NULL,NULL,NULL);}
				|COMMA Type ID OptionalParam {$$ = insertOptionalParam($2,$3,$4);}
;

OptionalVarDecl:						 {$$ = insertOptionalVarDecl(NULL,NULL);}
				|VarDecl OptionalVarDecl {$$ = insertOptionalVarDecl($1,$2);}
;

OptionalVariable:						   {$$ = insertOptionalVariable(NULL,NULL);}
				|COMMA ID OptionalVariable {$$ = insertOptionalVariable($2,$3);}
;

VarDecl : Type ID OptionalVariable SEMIC {$$ = insertVarDecl($1,$2,$3);}
;

Type : VarType OptionalArray 	{$$ = insertType($1,$2);}
;

VarType:INT 		{$$ = insertVarType(isInt);}
		|BOOL 		{$$ = insertVarType(isBool);}
;

OptionalArray: 				{$$ = insertOptionalArray(notArray);}
		|OSQUARE CSQUARE 	{$$ = insertOptionalArray(isArray);}
;

OptionalStatement: 									{$$ = insertOptionalStatement(NULL, NULL);}
				 	|Statement OptionalStatement 	{$$ = insertOptionalStatement($1, $2);}
;

Statement : OBRACE OptionalStatement CBRACE		{$$ = insertStatement($2,regStatement,NULL,NULL,NULL,NULL,NULL,NULL);}
			| IF OCURV Expr CCURV Statement 	{$$ = insertStatement(NULL,ifStatement,$5,NULL,NULL,NULL,$3,NULL);}
			| IF OCURV Expr CCURV Statement ELSE Statement {$$ = insertStatement(NULL,elseStatement,$5,$7,NULL,NULL,$3,NULL);}
			| WHILE OCURV Expr CCURV Statement  {$$ = insertStatement(NULL,whileStatement,$5,NULL,NULL,NULL,$3,NULL);}
			| PRINT OCURV Expr CCURV SEMIC		{$$ = insertStatement(NULL,printStatement,NULL,NULL,NULL,NULL,$3,NULL);}
			| ID OptionalArrayPosition ASSIGN Expr SEMIC	{$$ = insertStatement(NULL,terminStatement,NULL,NULL,$1,$2,$4,NULL);}
			| RETURN OptionalExpr SEMIC			{$$ = insertStatement(NULL,returnStatement,NULL,NULL,NULL,NULL,NULL,$2);}
;


OptionalArrayPosition:	{$$ = insertOptionalArrayPosition(NULL);}
					|OSQUARE Expr CSQUARE {$$ = insertOptionalArrayPosition($2);}
;

OptionalExpr:	{$$ = insertOptionalExpression(NULL);}
			|Expr {$$ = insertOptionalExpression($1);}
;

Expr : ArrayDim OSQUARE Expr CSQUARE {$$ = insertExpression(arrayDimExpr,$1,$3,NULL,NULL);}
	 | NEW VarType OSQUARE Expr CSQUARE {$$ = insertExpression(newExpr,NULL,$4,NULL,$2);}
	 | Expr OP1 Expr {$$ = insertExpression(opExpr,NULL,$1,$3,NULL);}
	 | Expr OP2 Expr {$$ = insertExpression(opExpr,NULL,$1,$3,NULL);}
	 | Expr OP3 Expr {$$ = insertExpression(opExpr,NULL,$1,$3,NULL);}
	 | Expr OP4 Expr {$$ = insertExpression(opExpr,NULL,$1,$3,NULL);}
	 | OP3 Expr {$$ = insertExpression(op3Expr,NULL,$2,NULL,NULL);}
	 | NOT Expr {$$ = insertExpression(notExpr,NULL,$2,NULL,NULL);}
	 | ArrayDim {$$ = insertExpression(arrayDimExpr2,$1,NULL,NULL,NULL);}
;

ArrayDim: ID {$$ = insertArrayDim($1,NULL,NULL);}
	 | INTLIT {$$ = insertArrayDim(NULL,NULL,NULL);}
	 | BOOLIT {$$ = insertArrayDim(NULL,NULL,NULL);}
	 | OCURV Expr CCURV {$$ = insertArrayDim(NULL,$2,NULL);}
	 | Expr DOTLENGTH {$$ = insertArrayDim(NULL,$1,NULL);}
	 | PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {$$ = insertArrayDim(NULL,$5,NULL);}
	 | ID OCURV OptionalArgs CCURV {$$ = insertArrayDim($1,NULL,$3);}
;

OptionalArgs: {$$ = insertOptionalArgs(NULL);}
			|Args {$$ = insertOptionalArgs($1);}
;

Args : Expr OptionalArgument {$$ = insertArgs($1, $2);}
;

OptionalArgument: {$$ = insertOptionalArgument(NULL, NULL);}
				|COMMA Expr OptionalArgument {$$ = insertOptionalArgument($2, $3);}
;

%%

int main()
{
	yyparse();
	return 0;

}

void yyerror (char *s) {
	printf ("Line %d, col %d: %s: %s\n", nLine, nCol-((int)strlen(yytext))+1, s, yytext);
}