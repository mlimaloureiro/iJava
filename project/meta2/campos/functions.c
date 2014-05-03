#include "functions.h"

startNode* insertStart(programNode *program){  
	startNode *start =(startNode*) malloc(sizeof(startNode));
	start->program=program;
    return start;
}

programNode* insertProgram(char *id,fieldOrMethodNode *fieldOrMethod){
    
	programNode *program =(programNode*) malloc(sizeof(programNode));
	program->id=id;
	program->fieldOrMethod=fieldOrMethod;
    return program;
}

fieldOrMethodNode* insertFieldOrMethod(fieldDeclNode *field,methodDeclNode *method, fieldOrMethodNode * fieldOrMethod)
{
	fieldOrMethodNode *fildOrMethod =(fieldOrMethodNode*) malloc(sizeof(fieldOrMethodNode));
	fildOrMethod->next=fieldOrMethod;
	fildOrMethod->field=field;
	fildOrMethod->method=method;
	return fildOrMethod;
}

fieldDeclNode* insertFieldDecl(varDeclNode *varDecl){
	fieldDeclNode *fieldDecl = (fieldDeclNode*) malloc(sizeof(fieldDeclNode));
	fieldDecl->varDecl = varDecl;
	return fieldDecl;
}

varDeclNode* insertVarDecl(typeNode *type, char *id, optionalVariableNode *optionalVariable){
	varDeclNode *varDecl = (varDeclNode*) malloc(sizeof(varDeclNode));
	varDecl->type = type;
	varDecl->id = id;
	varDecl->optionalVariable = optionalVariable;
	return varDecl;
}

optionalVariableNode* insertOptionalVariable(char *id, optionalVariableNode *next){
	optionalVariableNode *optionalVariable = (optionalVariableNode*) malloc(sizeof(optionalVariableNode));
	optionalVariable->id = id;
	optionalVariable->next = next;
	return optionalVariable;
}

methodDeclNode* insertMethodDecl(functionTypeNode* functionType, char* id, optionalFormalParamsNode* optionalFormalParams,
									optionalVarDeclNode* optionalVarDecl, optionalStatementNode* optionalStatement)
{

	methodDeclNode *methodDecl = (methodDeclNode*) malloc(sizeof(methodDeclNode));
	methodDecl->functionType = functionType;
	methodDecl->id = id;
	methodDecl->optionalFormalParams = optionalFormalParams;
	methodDecl->optionalVarDecl = optionalVarDecl;
	methodDecl->optionalStatement = optionalStatement;

	return methodDecl;
}

functionTypeNode* insertFunctionType(typeNode* type){
	functionTypeNode *functionType = (functionTypeNode*) malloc(sizeof(functionTypeNode));
	functionType->type = type;
	return functionType;
}

typeNode* insertType(varTypeNode* varType, optionalArrayNode* optArray) {
	typeNode* type = (typeNode*) malloc(sizeof(typeNode));
	type->varType = varType;
	type->optionalArray = optArray;
	return type;
}

varTypeNode* insertVarType(intBoolType type){
	varTypeNode* varType = (varTypeNode*) malloc(sizeof(varTypeNode));
	varType->type = type;
	return varType;
}

optionalArrayNode* insertOptionalArray(optArray arr){
	optionalArrayNode *optionalArray = (optionalArrayNode*) malloc(sizeof(optionalArrayNode));
	optionalArray->arr = arr;
	return optionalArray;
}

optionalFormalParamsNode* insertOptionalFormalParams(formalParamsNode* formalParams){
	optionalFormalParamsNode *optionalFormalParams = (optionalFormalParamsNode*) malloc(sizeof(optionalFormalParamsNode));
	optionalFormalParams->formalParams = formalParams;
	return optionalFormalParams;
}

formalParamsNode* insertFormalParams(typeNode* type, char* id, optionalParamNode* optionalParam){
	formalParamsNode *formalParams = (formalParamsNode*) malloc(sizeof(formalParamsNode));
	formalParams->type = type;
	formalParams->id = id;
	formalParams->optionalParam = optionalParam;
	return formalParams;
}

optionalParamNode* insertOptionalParam(typeNode* type, char* id, optionalParamNode* next){
	optionalParamNode *optionalParam = (optionalParamNode*) malloc(sizeof(optionalParamNode));
	optionalParam->type = type;
	optionalParam->id = id;
	optionalParam->next = next;
	return optionalParam;
}

optionalVarDeclNode* insertOptionalVarDecl(varDeclNode* varDecl, optionalVarDeclNode* next){
	optionalVarDeclNode *optionalVarDecl = (optionalVarDeclNode*) malloc(sizeof(optionalVarDeclNode));
	optionalVarDecl->varDecl = varDecl;
	optionalVarDecl->next = next;
	return optionalVarDecl;
}

optionalStatementNode* insertOptionalStatement(statementNode* statement, optionalStatementNode* next){
	optionalStatementNode *optionalStatement = (optionalStatementNode*) malloc(sizeof(optionalStatementNode));
	optionalStatement->next = next;
	return optionalStatement;
}

statementNode* insertStatement(optionalStatementNode* optStatement, statementType type, statementNode* statement1, 
									statementNode* statement2, char* id, optionalArrayPositionNode* optionalArrayPosition, expressionNode* expression,optionalExpressionNode* optionalExpression){
	
	statementNode *statement = (statementNode*) malloc(sizeof(statementNode));
	statement->optionalStatement = optStatement;
	statement->type = type;
	statement->statement1 = statement1;
	statement->statement2 = statement2;
	statement->id = id;
	statement->optionalArrayPosition = optionalArrayPosition;
	statement->optionalExpression = optionalExpression;
	statement->expression = expression;
	return statement;
}

optionalArrayPositionNode* insertOptionalArrayPosition(expressionNode* expression){
	optionalArrayPositionNode *optionalArrayPosition = (optionalArrayPositionNode*) malloc(sizeof(optionalArrayPositionNode));
	return optionalArrayPosition;
}

expressionNode* insertExpression(expressionType type, arrayDimNode* arrayDim, expressionNode* expression1, expressionNode* expression2, varTypeNode* varType){
	expressionNode *expression = (expressionNode*) malloc(sizeof(expressionNode));
	expression->type = type;
	expression->arrayDim = arrayDim;
	expression->expression1 = expression1;
	expression->expression2 = expression2;
	expression->varType = varType;
	return expression;
}

optionalExpressionNode* insertOptionalExpression(expressionNode* expression) {
	optionalExpressionNode* optExpr = (optionalExpressionNode*) malloc(sizeof(optionalExpressionNode));
	optExpr->expression = expression;
	return optExpr;
}

arrayDimNode* insertArrayDim(char* id, expressionNode* expression, optionalArgsNode* optionalArgs){
	arrayDimNode *arrayDim = (arrayDimNode*) malloc(sizeof(arrayDimNode));
	arrayDim->id = id;
	arrayDim->expression = expression;
	arrayDim->optionalArgs = optionalArgs;
	return arrayDim;
}

optionalArgsNode* insertOptionalArgs(argsNode* args){
	optionalArgsNode *optionalArgs = (optionalArgsNode*) malloc(sizeof(optionalArgsNode));
	optionalArgs->args = args;
	return optionalArgs;
}

argsNode* insertArgs(expressionNode* expression, optionalArgumentNode* optionalArgument){
	argsNode *args = (argsNode*) malloc(sizeof(argsNode));
	args->expression;
	args->optionalArgument = optionalArgument;
	return args;
}

optionalArgumentNode* insertOptionalArgument(expressionNode* expression,optionalArgumentNode* next){
	optionalArgumentNode *optionalArgument = (optionalArgumentNode*) malloc(sizeof(optionalArgumentNode));
	optionalArgument->expression = expression;
	optionalArgument->next = next;
	return optionalArgument;
}
