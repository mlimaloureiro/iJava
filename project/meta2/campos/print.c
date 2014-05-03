#include "functions.h"
int ntabs = 0;

void spawnTree(startNode* start){
	
	if(start){
		printf("Null\n");
		return;
	}

	programNode* program = start->program;
	
	printf("Program\n");

	ntabs++;

	indentTree();
	printf("Id(%s)\n",program->id);
	
	fieldOrMethodNode* fieldOrMethod = program->fieldOrMethod ; 

	while(fieldOrMethod)
	{
		if(fieldOrMethod->field)
			printFieldDecl(fieldOrMethod->field);

		if(fieldOrMethod->method)
			printMethodDecl(fieldOrMethod->method);

		fieldOrMethod = fieldOrMethod->next;
	}
}

void printFieldDecl(fieldDeclNode* field){
	indentTree();
	printf("FieldDecl\n");
	
	ntabs++;

	printfVarDecl(field->varDecl);

	ntabs--;
}

void printMethodDecl(methodDeclNode* methodDecl) {
	indentTree();
	printf("MethodDecl\n");
	
	ntabs++;

	printfFunctionType(methodDecl->functionType);

	indentTree();
	printf("Id(%s)\n", methodDecl->id);

	indentTree()
	printf("MethodParams\n");
	if(methodDecl->optionalFormalParams->formalParams)
		printOptionalFormalParams(methodDecl->optionalFormalParams);

	indentTree()
	printf("MethodBody\n");
	if(methodDecl->optionalVarDecl->varDecl)
		printOptionalVarDecl(methodDecl->optionalVarDecl);

	if(methodDecl->optionalStatement)
		printOptionalStatement(methodDecl->optionalStatement);

	ntabs--;
}

void printfFunctionType(functionTypeNode* functionType) {
	if(functionType->type) {
		printType(functionType->type);
	}
	else {
		indentTree();
		printf("Void\n");
	}
}

void printOptionalFormalParams(optionalFormalParamsNode* optionalFormalParams) {
	ntabs++;
	printFormalParams(optionalFormalParams->formalParams);
	ntabs--;
}

void printOptionalVarDecl(optionalVarDeclNode* optionalVarDecl) {
	optionalVarDecl* optVar = optionalVarDecl;

	ntabs++;

	while(optVar) {
		printVarDecl(optVar->varDecl);

		optVar = optVar->next;
	}

	ntabs--;
}

void printOptionalStatement(optionalStatementNode* optionalStatement) {
	optionalStatementNode* optStatement;

	while(optStatement) {
		printStatement(optStatement->statement);

		optStatement = optStatement->next;
	}
}

void printStatement(statementNode* statement) {
	
}

void printFormalParams(formalParamsNode* formalParams) {
	indentTree();
	printf("ParamDeclaration\n");

	ntabs++;

	if(formalParams->type) {
		printType(formalParams->type);
		
		indentTree();
		printf("Id(%s)", formalParams->id);
		
		printOptionalParam(formalParams->optionalParam);
	}
	else {
		indentTree();
		printf("StringArray\n");

		indentTree();
		printf("Id(%s)\n", formalParams->id);
	}

	ntabs--;
}

void printOptionalParam(optionalParamNode* optionalParam) {
	optionalParamNode* = optParam;

	while(optParam) {
		ntabs--;
		indentTree();
		printf("ParamDeclaration\n");
		ntabs++;

		printType(optParam->type);

		indentTree();
		printf("Id(%s)\n", optParam->id);

		optParam = optParam->next;
	}
}

void printVarDecl(varDeclNode* varDecl){
	indentTree();
	printf("VarDecl\n");
	
	printType(varDecl->type);
	
	indentTree();
	printf("Id(%s)\n", varDecl->id);
	
	printOptionalVariable(varDecl->optionalVariable);
}

void printType(typeNode* type){

	indentTree();
	if(type->varType->intBoolType == isInt){
		printf("Int");
	}

	if(type->varType->intBoolType == isBool){
		printf("Bool");
	}

	if(type->optionalArray->optArray == isArray){
		printf("Array");
	}

	printf("\n");
}

void printOptionalVariable(optionalVariableNode* optionalVariable) {
	optionalVariableNode* var = optionalVariable;

	while(var) {
		if(var->id) {
			indentTree();
			printf("Id(%s)\n", var->id);
		}
		var = var->next;
	}
}

void indentTree(){
	int i;
	for(i = 0; i < ntabs; i++){
		printf("	");
	}
}
