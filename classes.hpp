#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <stack> 

using namespace std;

typedef union type {
	int a;
	double b;
}tipoVariavel;

class Variavel{
public:
	Variavel(tipoVariavel valor, int tipo): valor(valor), tipo(tipo){}//construtor
	Variavel(){}
	int getTipo();
	void setTipo(int t);
	tipoVariavel getValor();
	void insereDouble(double valor);
	void insereInteiro(int valor);
private:
	int tipo;
	tipoVariavel valor;
};

class Node {
public:
	virtual Variavel *execute() = 0;
};

class Resultado {};

class Functions {};

class Function: public Functions {
private:
	int tipo;
	IdValue *idValue;
	Parametros *parametros;
	VarDeclarations *varDecList;
	Commands *commands;
public:
	Function(int t,IdValue *idv,Parametros *prm, VarDeclarations *varList, Commands *comms) : varDecList(varList), commands(comms),idValue(idv), parametros(prm), tipo(t) {} //construtor
	VarDeclarations *getVarDecList();
	IdValue *getIdValue();
	int getTipo();
	Parametros * getParametros();
	Commands *getCommands();
	Variavel *execute();

};

class FunctionList: public Functions{
private:	
	Functions *functions;
	Function *function;
public:
	FunctionList(Functions *fl, Function *f): functions(fl), function(f) {}
	Functions *getFunctions();
	Function *getFunction();
	Variavel *execute();
};

//asdsadsa

class Parametros {};

class Parametro: public Parametros {
private:
	int tipo;
	IdValue value;
public:
	Parametro(int a, IdValue *iv) : tipo(a), value(iv){} //construtor
	int getTipo();
	IdValue *getValue();
	Variavel *execute();

};

class ValorLiterals {};

class ValorLiteral : public ValorLiterals{
private:
	LValue *lValue;
public:
	ValorLiteral(LValue *l): lValue(l) {}
	LValue *getLValue();
	Variavel *execute();
};

class ValorLiteralList : public ValorLiterals{
private:
	ValorLiterals *valorLiterals;
	ValorLiteral *valorLiteral;
public:
	ValorLiteralList(ValorLiterals *vls, ValorLiteral *vl): valorLiterals(vls), valorLiteral(vl) {}
	ValorLiterals *getValorLiterals();
	ValorLiteral *getValorLiteral();
	Variavel *execute();
};

class ChamadaFuncao: public Command{
private:
	IdValue *idValue;
	ValorLiterals *valorLiterals;
public:
	ChamadaFuncao(ValorLiterals *l, IdValue *iv): valorLiterals(l), idValue(iv) {}
	ValorLiterals *getValorLiterals();
	IdValue *getIdValue();
	Variavel *execute();
};





class ParametroList: public Parametros{ //done
private:	
	Parametros *parametros;
	Parametro *parametro;
public:
	ParametroList(Parametros *ps, Parametro *p): parametros(ps), parametro(p) {}
	Parametros *getParametros();
	Parametro *getParametro();
	Variavel *execute();
};


class Commands : public Node{};

class Command : public Commands{};

class NameList : public Node{};

class VarDeclarations : public Node {};

class VarDeclaration : public VarDeclarations {
private:
	int type;
	NameList *nameList;
public:
	VarDeclaration(int t, NameList *n) : type(t), nameList(n){} //construtor
	int getType();
	NameList *getNameList();
	Variavel *execute();	
};

class VarDeclarationList : public VarDeclarations {
private:
	VarDeclarations *varDeclarations;
	VarDeclaration *varDeclaration;
public:
	VarDeclarationList(VarDeclarations *vdl, VarDeclaration *vd) : varDeclarations(vdl), varDeclaration(vd){} //construtor
	VarDeclarations *getVarDeclarations();
	VarDeclaration *getVarDeclaration();
	Variavel *execute();
};

class Programa : public Node{
private:
	VarDeclarations *varDecList;
	Commands *commands;
public:
	Programa(VarDeclarations *varList, Commands *comms) : varDecList(varList), commands(comms){} //construtor
	VarDeclarations *getVarDecList();
	Commands *getCommands();
	Variavel *execute();
};

class Name : public NameList {};

class Names : public NameList {
private:
	NameList *nameList;
	Name *name;
public:
	Names(NameList *nl, Name *n) : nameList(nl), name(n){} //construtor
	NameList *getNameList();
	Name *getName();
	Variavel *execute();
};

class IdValue;

class NameID : public Name {
private:
	IdValue *idValue;
public:
	NameID(IdValue *id) : idValue(id){} //construtor
	IdValue *getIdValue();
	Variavel *execute();
};

class Exp : public Command {};

class LValue : public Exp {};

class Assignment : public Exp{
private:
	LValue *exp;
	IdValue *idValue;
public:
	Assignment(IdValue *id, LValue *e) : idValue(id), exp(e){} //construtor
	LValue *getExp();
	IdValue	*getIdValue();
	Variavel *execute();
}; 

class NameAssignment : public Name {
private:
	Assignment *assignment;
public:
	NameAssignment(Assignment *a) : assignment(a){} //construtor
	Assignment *getAssignment();
	Variavel *execute();
};

class CommandsList: public Commands{
private:
    Commands *commands;
    Command *command;
public:
    CommandsList(Commands *cs, Command *c) : commands(cs), command(c){} //construtor
	Commands *getCommands();
	Command *getCommand();
	Variavel *execute();
};

class Print: public Command {
private:
	LValue *exp;
public:
	Print(LValue *e) : exp(e){} //construtor
	LValue *getExp();
	Variavel *execute();
};

class Inicializacoes: public Node{};

class Inicializacao: public Inicializacoes{
private:
    Assignment *assignment;
public:
    Inicializacao(Assignment *a): assignment(a){} //construtor
    Assignment *getAssignment();
	Variavel *execute();
};

class InicializacaoList: public Inicializacoes{
private:
    Inicializacoes *inicializacoes;
    Inicializacao *inicializacao;
public:
    InicializacaoList(Inicializacoes *i, Inicializacao *a): inicializacoes(i), inicializacao(a){} //construtor
    Inicializacoes *getInicializacoes();
    Inicializacao *getInicializacao();
	Variavel *execute();
};

class Incrementos: public Node{};

class Incremento: public Incrementos{
private:
    Assignment *assignment;
public:
    Incremento(Assignment *a): assignment(a){} //construtor
    Assignment *getAssignment();
	Variavel *execute();
};

class IncrementoList: public Incrementos{
private:
    Incrementos *incrementos;
    Incremento *incremento;
public:
    IncrementoList(Incrementos *i, Incremento *a): incrementos(i), incremento(a){} //construtor
    Incrementos *getIncrementos();
    Incremento *getIncremento();
	Variavel *execute();
};

class Laco : public Command{
private:
    LValue *condicao;
    Incrementos *incrementos;
    Inicializacoes *inicializacoes;
	Commands *commands;
public:
    Laco(Inicializacoes *ini, LValue *e, Incrementos *inc, Commands *commands): inicializacoes(ini), condicao(e), incrementos(inc), commands(commands) {} //construtor
    LValue *getExp();
    Incrementos *getIncrementos();
    Inicializacoes *getInicializacoes();
	Commands *getCommands();
	Variavel *execute();
};

class Condicional : public Command{};

class If: public Condicional{
private:
    Commands *ifCommands;
    LValue *exp;
public:
    If(LValue *e, Commands *c): exp(e), ifCommands(c){} //construtor
    Commands *getIfCommands();
    LValue *getExp();
	Variavel *execute();
};

class IfElse: public Condicional{
    private:
    Commands *ifCommands;
    Commands *elseCommands;
    LValue *exp;
public:
    IfElse(LValue *e, Commands *c, Commands *ec): exp(e), ifCommands(c), elseCommands(ec){} //construtor
    Commands *getIfCommands();
    Commands *getElseCommands();
    LValue *getExp();
	Variavel *execute();
};

class BinExpEqualDiff : public LValue {};

class BinExpLessGreater : public LValue {};

class BinExpPlusMinus : public LValue {};

class BinExpAndOr : public LValue {};

class Factor: public LValue {};

class UnExp: public Factor {};

class Value : public UnExp {
public:
	enum Type {
		INT,
		DOUBLE,
		ID_VALUE
	};
	
	virtual Type getType() = 0;		 
private:
	Type type;
};

class IdValue: public Value {
private:
	string idValue;
public:
	IdValue(string idvalue):idValue(idvalue){} //construtor
	string getValue();
	virtual Type getType();
	Variavel *execute();
};

class BinExpPlus: public BinExpPlusMinus {
private:
	LValue *lValue;
	Factor *factor;

public:
	BinExpPlus(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpMinus: public BinExpPlusMinus {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpMinus(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpLessThen : public BinExpLessGreater {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpLessThen(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpLessEqualThen : public BinExpLessGreater {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpLessEqualThen(LValue *lv, Factor *f): lValue(lv) , factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpGreaterThen : public BinExpLessGreater {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpGreaterThen(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpGreaterEqualThen : public BinExpLessGreater {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpGreaterEqualThen(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpEqual : public BinExpEqualDiff {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpEqual(LValue *lv, Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpDiff : public BinExpEqualDiff {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpDiff(LValue *lv, class Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpAnd : public BinExpAndOr {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpAnd(LValue *lv, class Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class BinExpOr : public BinExpAndOr {
private:
	LValue *lValue;
	Factor *factor;
public:
	BinExpOr(LValue *lv, class Factor *f): lValue(lv), factor(f){} //construtor
	LValue *getLValue();
	Factor *getFactor();
	Variavel *execute();
};

class FactorMul: public Factor {
private:
	Factor *factor;
	UnExp *unExp;
public:
	FactorMul(Factor *f, UnExp *ue): factor(f), unExp(ue){} //construtor
	Factor *getFactor();
	UnExp *getUnExp();
	Variavel *execute();
};

class FactorDiv: public Factor {
private:
	Factor *factor;
	UnExp *unExp;
public:
	FactorDiv(Factor *f, UnExp *ue): factor(f), unExp(ue){} //construtor
	Factor *getFactor();
	UnExp *getUnExp();
	Variavel *execute();
};

class UnExpPlus : public UnExp {
private:	
	Value *value;
public:
	UnExpPlus(Value *v): value(v){} //construtor
	Value *getValue();
	Variavel *execute();
};

class UnExpMinus : public UnExp {
private:
	Value *value;
public:
	UnExpMinus(Value *v): value(v){} //construtor
	Value *getValue();
	Variavel *execute();
};

class IntValue: public Value {
private:
	int value;
public:
	IntValue(int value):value(value){} //construtor
	int getValue();
	virtual Type getType();
	Variavel *execute();
};

class DoubleValue: public Value {
private:
	double value;
public:
	DoubleValue(double value):value(value){} //construtor
	double getValue();
	virtual Type getType();
	Variavel *execute();
};

class LparExpRpar : public UnExp {
private:
	LValue *exp;
public:
	LparExpRpar(LValue *e) : exp(e){} //construtor
	LValue *getExp();
	Variavel *execute();
};

class Scopo {
private: 
	map<string, Variavel*> variaveis;
	bool criarVariavel;
	int tipo;
public:
	bool getCriarVariavel();
	void setCriarVariavel(bool modo);
	int getTipo();
	void setTipo(int tp);
	void criaVariavel(string nome, Variavel *v);
	Variavel *retornaVariavel(string nome);
};

class Contexto2 {
private:
	static Contexto2 *instance;
	Programa *programa;
	Contexto2(){} //construtor
	stack <Scopo> pilha; 
public:
	void CriaEscopo();
	void DestroiEscopo();
	static Contexto2 &getContexto2();
	void setPrograma(Programa *prog);
	Programa *getPrograma();
};

class Contexto {
private:
	static Contexto *instance;
	Programa *programa;
	Contexto(){} //construtor
	map<string, Variavel*> variaveis;
	bool criarVariavel;
	int tipo;
public:
	bool getCriarVariavel();
	void setCriarVariavel(bool modo);
	int getTipo();
	void setTipo(int tp);
	void criaVariavel(string nome, Variavel *v);
	Variavel *retornaVariavel(string nome);
	static Contexto &getContexto();
	void setPrograma(Programa *prog);
	Programa *getPrograma();
};

#endif
