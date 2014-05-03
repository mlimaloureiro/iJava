	typedef struct struct1 startNode;
	typedef struct struct2 programNode;
	typedef struct struct3 fieldOrMethodNode;
	typedef struct struct4 fieldDeclNode;
	typedef struct struct5 varDeclNode;
	typedef struct struct6 optionalVariableNode;
	typedef struct struct7 methodDeclNode;
	typedef struct struct8 functionTypeNode;
	typedef struct struct9 typeNode;
	typedef struct struct10 varTypeNode;
	typedef struct struct11 optionalArrayNode;
	typedef struct struct12 optionalFormalParamsNode;
	typedef struct struct13 formalParamsNode;
	typedef struct struct14 optionalParamNode;
	typedef struct struct15 optionalVarDeclNode;
	typedef struct struct16 optionalStatementNode;
	typedef struct struct17 statementNode;
	typedef struct struct18 optionalArrayPositionNode;
	typedef struct struct19 optionalExpressionNode;
	typedef struct struct20 expressionNode;
	typedef struct struct21 arrayDimNode;
	typedef struct struct22 optionalArgsNode;
	typedef struct struct23 argsNode;
	typedef struct struct24 optionalArgumentNode;

	struct struct1{
		programNode *program;
	};

	struct struct2{
		char* id;
		fieldOrMethodNode* fieldOrMethod; 
	};
	
	struct struct3{
		fieldDeclNode* field;
		methodDeclNode* method;
		fieldOrMethodNode* next;
	};

	struct struct4{
		varDeclNode* varDecl;
	};

	struct struct5{
		char* id;
		typeNode* type;
		optionalVariableNode* optionalVariable;
	};

	struct struct6{
		char* id;
		optionalVariableNode* next;
	}; 

	struct struct7{
		functionTypeNode* functionType;
		char* id;
		optionalFormalParamsNode* optionalFormalParams;
		optionalVarDeclNode* optionalVarDecl;
		optionalStatementNode* optionalStatement;
	};

	struct struct8{
		typeNode* type;
	};

	struct struct9{
		varTypeNode* varType;
		optionalArrayNode* optionalArray;
	};

	typedef enum {isInt,isBool} intBoolType;
	struct struct10{
		intBoolType type;
	};

	typedef enum {isArray,notArray} optArray;
	struct struct11{
		optArray arr;
	};

	struct struct12{
		formalParamsNode* formalParams;
	};

	struct struct13{
		typeNode* type;
		char* id;
		optionalParamNode* optionalParam;
	};

	struct struct14{
		typeNode* type;
		char* id;
		optionalParamNode* next;
	};

	struct struct15{
		varDeclNode* varDecl;
		optionalVarDeclNode* next;
	};

	struct struct16{
		statementNode* statement;
		optionalStatementNode* next;
	};


	typedef enum {regStatement,ifStatement,elseStatement,whileStatement,printStatement,terminStatement,returnStatement} statementType;
	struct struct17{
		statementType type;
		optionalStatementNode* optionalStatement;
		expressionNode* expression;
		statementNode* statement1;
		statementNode* statement2;
		char* id;
		optionalArrayPositionNode* optionalArrayPosition;
		optionalExpressionNode* optionalExpression;
	};

	struct struct18{
		expressionNode* expression;
	};

	struct struct19{
		expressionNode* expression;
	};

	typedef enum {arrayDimExpr, newExpr, opExpr, op3Expr, notExpr, arrayDimExpr2} expressionType; 
	struct struct20{
		expressionType type;
		varTypeNode* varType;
		arrayDimNode* arrayDim;
		expressionNode* expression1;
		expressionNode* expression2;
	};


	struct struct21{
		char* id;
		expressionNode* expression;
		optionalArgsNode* optionalArgs;
	};

	struct struct22{
		argsNode* args;
	};

	struct struct23{
		expressionNode* expression;
		optionalArgumentNode* optionalArgument;
	};

	struct struct24{
		expressionNode* expression;
		optionalArgumentNode* next;
	};

