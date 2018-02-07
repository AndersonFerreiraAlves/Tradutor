%{
 
#include "classes.hpp"
#include <cstdio>
#include <map>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int numero_linhas;
void yyerror(const char *s);

%}

%token IF
%token ELSE
%token FOR
%token INT
%token MAIN
%token DOUBLE
%token PARENTESE_D
%token PARENTESE_E
%token CHAVE_D
%token CHAVE_E
%token IDENTIFICADOR
%token SOMA
%token SUBTRACAO
%token MULTIPLICACAO
%token DIVISAO
%token MAIOR
%token MENOR
%token EXCLAMACAO
%token E_COMECIAL
%token OU
%token NUMERO_INTEIRO
%token NUMERO_REAL
%token PONTO_VIRGULA
%token VIRGULA
%token IGUALDADE
%token DOIS_PONTOS
%token COLCHETE_E
%token COLCHETE_D
%token PRINT
%token VOID

%union {
	int int_value;
	double double_value;
	char *id_value;
	class VarDeclarations *varDeclarations;
	class VarDeclaration *varDeclaration;
	class NameList *nameList;
	class Name *name;
	class Names *names;
	class NameID *nameID;
	class NameAssignment *nameAssignment;
	class Assignment *assignment;
	class Commands *commands;
	class Command *command;
	class Print *print;
	class Laco *laco;
	class Inicializacoes *inicializacoes;
	class Inicializacao *inicializacao;
	class Incrementos *incrementos;
	class Incremento *incremento;
	class Condicional *condicional;
	class Exp *exp;
	class LValue *lValue;
	class BinExpEqualDiff *binExpEqualDiff;
	class BinExpLessGreater *binExpLessGreater;
	class BinExpPlusMinus *binExpPlusMinus;
	class BinExpAndOr *binExpAndOr;
	class Factor *factor;
	class UnExp *unExp;
	class Value *value;
	class BinExpPlus *binExpPlus;
	class BinExpMinus *binExpMinus;
	class BinExpLessThen *binExpLessThen;
	class BinExpLessEqualThen *binExpLessEqualThen;
	class BinExpGreaterThen *binExpGreaterThen;
	class BinExpGreaterEqualThen *binExpGreaterEqualThen;
	class BinExpEqual *binExpEqual;
	class BinExpDiff *binExpDiff;
	class BinExpAnd *binExpAnd;
	class BinExpOr *binExpOr;
	class FactorMul *factorMul;
	class FactorDiv *factorDiv;
	class UnExpPlus *unExpPlus;
	class UnExpMinus *unExpMinus;
	class LparExpRpar *lparExpRpar;
};

%type<int_value> Tipo;
%type<int_value> INT;
%type<int_value> DOUBLE;
%type<int_value> NUMERO_INTEIRO;
%type<double_value> NUMERO_REAL;
%type<id_value> IDENTIFICADOR;
%type<varDeclarations> VarDeclarations;
%type<varDeclaration> VarDeclaration;
%type<nameList> NameList;
%type<name> Name;
%type<names> Names;
%type<nameID> NameID;
%type<nameAssignment> NameAssignment;
%type<assignment> Assignment;
%type<commands> Comandos;
%type<command> Comando;
%type<print> Print;
%type<laco> Laco;
%type<inicializacoes> Inicializacoes;
%type<inicializacao> Inicializacao;
%type<incrementos> Incrementos;
%type<incremento> Incremento;
%type<condicional> Condicional;
%type<exp> Exp;
%type<lValue> LValue;
%type<binExpEqualDiff> BinExpEqualDiff;
%type<binExpLessGreater> BinExpLessGreater;
%type<binExpPlusMinus> BinExpPlusMinus;
%type<binExpAndOr> BinExpAndOr;
%type<factor> Factor;
%type<unExp> UnExp;
%type<value> Value;
%type<binExpPlus> BinExpPlus;
%type<binExpMinus> BinExpMinus;
%type<binExpLessThen> BinExpLessThen;
%type<binExpLessEqualThen> BinExpLessEqualThen;
%type<binExpGreaterThen> BinExpGreaterThen;
%type<binExpGreaterEqualThen> BinExpGreaterEqualThen;
%type<binExpEqual> BinExpEqual;
%type<binExpDiff> BinExpDiff;
%type<binExpAnd> BinExpAnd;
%type<binExpOr> BinExpOr;
%type<factorMul> FactorMul;
%type<factorDiv> FactorDiv;
%type<unExpPlus> UnExpPlus;
%type<unExpMinus> UnExpMinus;
%type<lparExpRpar> LparExpRpar;


%right IF ELSE
%error-verbose

%%

Main: 
	VOID MAIN PARENTESE_E PARENTESE_D CHAVE_E VarDeclarations Comandos CHAVE_D {Programa *n = new Programa($6, $7);Contexto::getContexto().setPrograma(n);}
	;

Tipo: 
	INT {$$ = $1;}
    |DOUBLE {$$ = $1;}
    ;

VarDeclarations: 
	VarDeclarations VarDeclaration {$$ = new VarDeclarationList($1, $2);}
	|VarDeclaration {$$ = $1;}
	;

VarDeclaration: 
	Tipo NameList PONTO_VIRGULA {$$ = new VarDeclaration($1, $2);}
	;

NameList: 
	Name {$$ = $1;}
	|Names {$$ = $1;}
	;

Names: 
	NameList VIRGULA Name {$$ = new Names($1, $3);}
	;

Name: 
	NameID  {$$ = $1;}
	|NameAssignment {$$ = $1;}
	;

NameID: 
	IDENTIFICADOR {$$ = new NameID (new IdValue($1));}
	;

NameAssignment: 
	Assignment {$$ = new NameAssignment ($1);}
	;

Comandos: 
	Comandos Comando {$$ = new CommandsList($1, $2);}
    |Comando {$$ = $1;}
    ;

Comando: 
	Condicional {$$ = $1;}
    |Laco {$$ = $1;}
	|Print PONTO_VIRGULA {$$ = $1;}
	|Exp PONTO_VIRGULA {$$ = $1;}
    ;

Condicional: 
	IF PARENTESE_E LValue PARENTESE_D CHAVE_E Comandos CHAVE_D {$$ = new If($3, $6);}
	|IF PARENTESE_E LValue PARENTESE_D CHAVE_E Comandos CHAVE_D ELSE CHAVE_E Comandos CHAVE_D{$$ = new IfElse($3, $6, $10);}
	;

Laco: 
	FOR PARENTESE_E Inicializacoes PONTO_VIRGULA LValue PONTO_VIRGULA Incrementos PARENTESE_D CHAVE_E Comandos CHAVE_D{$$ = new Laco($3, $5, $7, $10);}
    ;

Print: 
	PRINT PARENTESE_E LValue PARENTESE_D{$$ = new Print($3);}
	;

Inicializacoes: 
	Inicializacoes VIRGULA Inicializacao {$$ = new InicializacaoList($1, $3);}
	|Inicializacao {$$ = $1;}
	;

Inicializacao: 
	IDENTIFICADOR IGUALDADE LValue {$$ = new Inicializacao(new Assignment(new IdValue(string($1)),$3));}
	;

Incrementos: 
    Incrementos VIRGULA Incremento {$$ = new IncrementoList($1, $3);}
    |Incremento{$$ = $1;}
    ;

Incremento: 
    IDENTIFICADOR IGUALDADE LValue {$$ = new Incremento(new Assignment(new IdValue(string($1)),$3));}
    ;

Exp: 
	LValue {$$ = $1;}
	|Assignment {$$ = $1;}
	;

LValue: 
	BinExpEqualDiff {$$ = $1;}
	|BinExpLessGreater {$$ = $1;}
	|BinExpPlusMinus {$$ = $1;}
	|BinExpAndOr {$$ = $1;}
	|Factor {$$ = $1;}
	;	

BinExpEqualDiff: 
	BinExpEqual {$$ = $1;}
	|BinExpDiff {$$ = $1;}
	;

BinExpLessGreater: 
	BinExpLessThen {$$ = $1;}
	|BinExpLessEqualThen {$$ = $1;}
	|BinExpGreaterThen {$$ = $1;}
	|BinExpGreaterEqualThen {$$ = $1;}
	;

BinExpPlusMinus: 
	BinExpPlus {$$ = $1;}
	|BinExpMinus {$$ = $1;}
	;

BinExpAndOr:
	BinExpAnd {$$ = $1;}
	|BinExpOr {$$ = $1;}
	;

BinExpPlus: 
	LValue SOMA Factor {$$ = new BinExpPlus($1,$3);}
	;  

BinExpMinus: 
	LValue SUBTRACAO Factor {$$ = new BinExpMinus($1, $3);}
	;

BinExpLessThen: 
	LValue MENOR Factor {$$ = new BinExpLessThen($1, $3);} 
	;

BinExpLessEqualThen: 
	LValue MENOR IGUALDADE Factor {$$ = new BinExpLessEqualThen($1, $4);} 
	;

BinExpGreaterThen: 
	LValue MAIOR Factor {$$ = new BinExpGreaterThen($1, $3);} 
	;

BinExpGreaterEqualThen: 
	LValue MAIOR IGUALDADE Factor {$$ = new BinExpGreaterEqualThen($1, $4);} 
	;

BinExpEqual: 
	LValue IGUALDADE IGUALDADE Factor {$$ = new BinExpEqual($1, $4);}
	;

BinExpDiff: 
	LValue EXCLAMACAO IGUALDADE Factor {$$ = new BinExpDiff($1, $4);}
	;

BinExpAnd:
	LValue E_COMECIAL E_COMECIAL Factor {$$ = new BinExpAnd($1, $4);}
	;

BinExpOr:
	LValue OU OU Factor {$$ = new BinExpOr($1, $4);}
	;

Factor: 
	FactorMul {$$ = $1;}
	|FactorDiv {$$ = $1;}
	|UnExp {$$ = $1;}
	;

FactorMul: 
	Factor MULTIPLICACAO UnExp {$$ = new FactorMul($1, $3);}
	;		

FactorDiv: 
	Factor DIVISAO UnExp {$$ = new FactorDiv($1, $3);}
	;

UnExp: 
	UnExpPlus {$$ = $1;}
	|UnExpMinus {$$ = $1;}
	|LparExpRpar {$$ = $1;}
	|Value {$$ = $1;}
	;

UnExpPlus: 
	SOMA Value {$$ = new UnExpPlus($2);}
	;

UnExpMinus: 
	SUBTRACAO Value {$$ = new UnExpMinus($2);}
	;

Value: 
	NUMERO_INTEIRO {$$ = new IntValue($1);}
	|NUMERO_REAL {$$ = new DoubleValue($1);}
	|IDENTIFICADOR {$$ = new IdValue($1);}
	;	

LparExpRpar: 
	PARENTESE_E LValue PARENTESE_D {$$ = new LparExpRpar($2);}
	; 

Assignment: 
	IDENTIFICADOR IGUALDADE LValue {$$ = new Assignment(new IdValue(string($1)),$3);}
	;

%%

int main(int, char**) {

	yyin = fopen("entrada.txt", "r");

	do {

		yyparse();

	} while (!feof(yyin));

	Programa *prg = Contexto::getContexto().getPrograma();
	prg->execute();
	//map <string, Variavel> ola;
	//Variavel::tipoVariavel c;	
	//c.a = 0;
	//Variavel v;
	//ola.insert(std::make_pair("moon", v));
	//ola["ola"] = v;
	//double d = 1 != 2;
	//cout << "valor: " << d <<endl;
	//cout << "valor: " << ola["ola"] << endl;

	return 0;

}

void yyerror(const char *s) {

	cout << "\nErro: " << s << "\nLinha do erro: " << numero_linhas + 1<< endl;

	exit(-1);

}
