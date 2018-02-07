#include "classes.hpp"

//Programa
VarDeclarations *Programa::getVarDecList() {
    return this->varDecList;
}

Commands *Programa::getCommands() {
    return this->commands;
}

Variavel *Programa::execute() {//feito
    Contexto::getContexto().setCriarVariavel(true);
	varDecList->execute();
	Contexto::getContexto().setCriarVariavel(false);
	commands->execute();
	return NULL;
}

//Function
VarDeclarations *Function::getVarDecList() {
	return this->varDecList;
}

IdValue *Function::getIdValue(){
	return this->idValue;
}

int Function::getTipo(){
	return this->tipo;
}

Parametros *Function::getParametros(){
	return this->parametros;
}

Commands *Function::getCommands(){
	return this->commands;
}

Variavel *Function::execute(){//falta terminar
	int tipo = this->tipo;
	string nome = this->idValue->getValue();
	this->parametros->execute();
	this->varDecList->execute();
	this->commands->execute();
	return NULL;
}

//FunctionList 
Functions *FunctionList::getFunctions(){//feito
	return this->Functions;
}

Function *FunctionList::getFunction(){
	return this->Function;
}

Variavel *FunctionList::execute(){
	this->Functions->execute();
	this->Function->execute();
	return NULL;
}

//Parametro
int Parametro::getTipo(){
	return this->tipo;
}

IdValue *Parametro::getValue(){
	return this->value;
}

Variavel *Parametro::execute(){
	string nome = this->idValue->getValue();
	return NULL;
}

//ParametroList
Parametros *ParametroList::getParametros(){
	return this->parametros;
}

Parametro *ParametroList::getParametro(){
	return this->parametro;
}

Variavel *ParametroList::execute(){//feito
	this->parametros->execute();
	this->parametro->execute();
	return NULL;
}

//ChamadaFuncao
ValorLiterals *ChamadaFuncao::getValorLiterals(){
	return this->valorLiterals;
}

IdValue *ChamadaFuncao::getIdValue(){
	return this->valorLiteral;
}

Variavel *ChamadaFuncao::execute(){

	Contexto::getContexto().CriaEscopo();
	this->valorLiterals->execute();
	string nome = this->idValue->getValue();

	Contexto::getContexto().DestroiEscopo();

	return ;
}

//ValorLiteralList
ValorLiterals *ValorLiteralList::getValorLiterals(){
	return this->valorLiterals;
}

ValorLiteral *ValorLiteralList::getValorLiteral(){
	return this->valorLiteral;
}

Variavel *ValorLiteralList::execute(){//feito
	this->valorLiterals->execute();
	this->valorLiteral->execute();
	return NULL;
}

//ValorLiteral
LValue *ValorLiteral::getLValue(){
	return this->value;
}

Variavel *ValorLiteral::execute(){
	
	Variavel *v = this->lValue->execute();
}

//VarDeclaration
int VarDeclaration::getType() {
    return this->type;
}

NameList *VarDeclaration::getNameList() {
    return this->nameList;
}

Variavel *VarDeclaration::execute() {//feito
	Contexto::getContexto().setTipo(this->type);
	nameList->execute();
	return NULL;
}

//VarDeclarationList
VarDeclarations *VarDeclarationList::getVarDeclarations(){
    return this->varDeclarations;
}

VarDeclaration *VarDeclarationList::getVarDeclaration(){
    return this->varDeclaration;
}

Variavel *VarDeclarationList::execute() {//feito
	varDeclarations->execute();
	varDeclaration->execute();
	return NULL;
}

//Names
NameList *Names::getNameList() {
    return this->nameList;
}

Name *Names::getName() {
    return this->name;
}

Variavel *Names::execute() {
	nameList->execute();
	name->execute();
	return NULL;
}

//NameID
IdValue * NameID::getIdValue(){
    return this->idValue;
}

Variavel *NameID::execute() {
	int tipo = Contexto::getContexto().getTipo();
	tipoVariavel valor;
	if(tipo==0) {
		valor.a=0;
	}else {
		valor.b=0;
	}
	Variavel *v = new Variavel(valor, tipo);
	Contexto::getContexto().criaVariavel(this->idValue->getValue(), v);
	return NULL;
}

//NameAssignment
Assignment *NameAssignment::getAssignment(){	
    return this->assignment;
}

Variavel *NameAssignment::execute() {
	assignment->execute();
	return NULL;
}

//Assignment
LValue *Assignment::getExp(){
    return this->exp;
}

IdValue	*Assignment::getIdValue(){
    return this->idValue;
}

Variavel *Assignment::execute() {//feito
	Variavel *e = exp->execute();
	if(Contexto::getContexto().getCriarVariavel()) {
		int tipo = Contexto::getContexto().getTipo();
		tipoVariavel valor;
		if(tipo==0) {
			valor.a = (int)e->getValor().b;
		}else {
			valor.b = e->getValor().b;
		}
		Variavel *v = new Variavel(valor, tipo);
		Contexto::getContexto().criaVariavel(this->idValue->getValue(), v);
	}
	else {
		Variavel *r = Contexto::getContexto().retornaVariavel(this->idValue->getValue());
		if(r->getTipo()==0) {
			r->insereInteiro((int)e->getValor().b);
		}else {
			r->insereDouble(e->getValor().b);
		}
	}
	return NULL;
}

//CommandsList
Commands *CommandsList::getCommands(){
    return this->commands;
}

Command *CommandsList::getCommand(){
    return this->command;
}

Variavel *CommandsList::execute() {//feito
	commands->execute();
	command->execute();
	return NULL;
}

//Print
LValue *Print::getExp(){
    return this->exp;
}

Variavel *Print::execute() {
	Variavel *e = exp->execute();
	cout <<e->getValor().b<< endl;
	return NULL;
}

//Laco
LValue *Laco::getExp(){
    return this->condicao;
}

Incrementos *Laco::getIncrementos(){
    return this->incrementos;
}

Inicializacoes *Laco::getInicializacoes(){
    return this->inicializacoes;
}

Commands *Laco::getCommands() {
	return this->commands;
}

Variavel *Laco::execute() {//feito
	for(inicializacoes->execute(); condicao->execute()->getValor().b; incrementos->execute()) {
		commands->execute();
	}
	return NULL;
}

//Inicializacao
Assignment *Inicializacao::getAssignment(){
    return this->assignment;
}

Variavel *Inicializacao::execute() {//feito
	assignment->execute();
	return NULL;
}

//InicializacaoList
Inicializacoes *InicializacaoList::getInicializacoes(){
    return this->inicializacoes;
}

Inicializacao *InicializacaoList::getInicializacao(){
    return this->inicializacao;
}

Variavel *InicializacaoList::execute() {//feito
	inicializacoes->execute();
	inicializacao->execute();
	return NULL;
}

//Incremento
Assignment *Incremento::getAssignment(){
    return this->assignment;
}

Variavel *Incremento::execute() {//feito
	assignment->execute();
	return NULL;
}

//IncrementoList
Incrementos *IncrementoList::getIncrementos(){
    return this->incrementos;
}

Incremento *IncrementoList::getIncremento(){
    return this->incremento;
}

Variavel *IncrementoList::execute() {//feito
	incrementos->execute();
	incremento->execute();
	return NULL;
}

//If
Commands *If::getIfCommands(){
    return this->ifCommands;
}

LValue *If::getExp(){
    return this->exp;
}

Variavel *If::execute() {//feito
	Variavel *e = exp->execute();
	if(e->getValor().b) {
		ifCommands->execute();
	}	
	return NULL;
}

//IfElse
Commands *IfElse::getIfCommands(){
    return this->ifCommands;
}

Commands *IfElse::getElseCommands(){
    return this->elseCommands;
}

LValue *IfElse::getExp(){
    return this->exp;
}

Variavel *IfElse::execute() {//feito
	Variavel *e = exp->execute();
	if(e->getValor().b) {
		ifCommands->execute();
	}else {
		elseCommands->execute();
	}
	return NULL;
}

//BinExpPlus
LValue *BinExpPlus::getLValue (){
	return this->lValue;
}

Factor *BinExpPlus::getFactor(){
	return this->factor;
}

Variavel *BinExpPlus::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)+(u->getValor().b));
	return g;
}

//BinExpMinus
LValue *BinExpMinus::getLValue (){
	return this->lValue; 
}

Factor *BinExpMinus::getFactor(){ 
	return this->factor; 
}

Variavel *BinExpMinus::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)-(u->getValor().b));
	return g;
}

//BinExpLessThen
LValue *BinExpLessThen::getLValue(){
	return this->lValue;
}

Factor *BinExpLessThen::getFactor(){
	return this->factor;
}

Variavel *BinExpLessThen::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)<(u->getValor().b));
	return g;
}

//BinExpLessEqualThen
LValue *BinExpLessEqualThen::getLValue(){
	return this->lValue;
}

Factor *BinExpLessEqualThen::getFactor(){
	return this->factor;
}

Variavel *BinExpLessEqualThen::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)<=(u->getValor().b));
	return g;
}

//BinExpGreaterThen
LValue *BinExpGreaterThen::getLValue(){
	return this->lValue;
}

Factor *BinExpGreaterThen::getFactor(){
	return this->factor;
}

Variavel *BinExpGreaterThen::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)>(u->getValor().b));
	return g;
}

//BinExpGreaterEqualThen
LValue *BinExpGreaterEqualThen::getLValue(){
	return this->lValue;
}

Factor *BinExpGreaterEqualThen::getFactor(){
	return this->factor;
}

Variavel *BinExpGreaterEqualThen::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)>=(u->getValor().b));
	return g;
}

//BinExpEqual
LValue *BinExpEqual::getLValue(){
	return this->lValue;
}

Factor *BinExpEqual::getFactor(){
	return this->factor;
}

Variavel *BinExpEqual::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)==(u->getValor().b));
	return g;
}

//BinExpDiff
LValue *BinExpDiff::getLValue(){
	return this->lValue;
}

Factor *BinExpDiff::getFactor(){
	return this->factor;
}

Variavel *BinExpDiff::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)!=(u->getValor().b));
	return g;
}

//BinExpAnd
LValue *BinExpAnd::getLValue(){
	return this->lValue;
}

Factor *BinExpAnd::getFactor(){
	return this->factor;
}

Variavel *BinExpAnd::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)&&(u->getValor().b));
	return g;
}

//BinExpOr
LValue *BinExpOr::getLValue(){
	return this->lValue;
}

Factor *BinExpOr::getFactor(){
	return this->factor;
}

Variavel *BinExpOr::execute() {//feito
	Variavel *f = lValue->execute();
	Variavel *u = factor->execute();
	Variavel *g = new Variavel();
	g->insereDouble((f->getValor().b)||(u->getValor().b));
	return g;
}

//FactorMul
Factor *FactorMul::getFactor(){ 
	return this->factor; 
}

UnExp *FactorMul::getUnExp(){ 
	return this->unExp; 
}

Variavel *FactorMul::execute() {//feito
	Variavel *f = factor->execute();
	Variavel *u = unExp->execute();
	Variavel *g = new Variavel();
	if(f->getTipo()==0 && u->getTipo()==0) {
		g->insereDouble((f->getValor().a)*(u->getValor().a));
		g->setTipo(1);
	}
	else {
		if(f->getTipo()==0 && u->getTipo()==1) {
			g->insereDouble((f->getValor().a)*(u->getValor().b));
			g->setTipo(1);
		}
		else {
			if(f->getTipo()==1 && u->getTipo()==0) {
				g->insereDouble((f->getValor().b)*(u->getValor().a));
				g->setTipo(1);
			}
			else {
				g->insereDouble((f->getValor().b)*(u->getValor().b));
				g->setTipo(1);
			}
		}
	}
	return g;
}

//FactorDiv
Factor *FactorDiv::getFactor(){ 
	return this->factor; 
}

UnExp *FactorDiv::getUnExp(){	
	return this->unExp; 
}

Variavel *FactorDiv::execute() {//feito
	Variavel *f = factor->execute();
	Variavel *u = unExp->execute();
	Variavel *g = new Variavel();
	if(f->getTipo()==0 && u->getTipo()==0) {
		g->insereDouble((f->getValor().a)/(u->getValor().a));
		g->setTipo(1);
	}
	else {
		if(f->getTipo()==0 && u->getTipo()==1) {
			g->insereDouble((f->getValor().a)/(u->getValor().b));
			g->setTipo(1);
		}
		else {
			if(f->getTipo()==1 && u->getTipo()==0) {
				g->insereDouble((f->getValor().b)/(u->getValor().a));
				g->setTipo(1);
			}
			else {
				g->insereDouble((f->getValor().b)/(u->getValor().b));
				g->setTipo(1);
			}
		}
	}
	return g;
}

//UnExpPlus
Value *UnExpPlus::getValue(){ 
	return this->value;
}

Variavel *UnExpPlus::execute() {//feito
	Variavel *v;
	tipoVariavel a;
	if(this->value->getType() == Value::Type::INT) {
		a.b = (((IntValue*)this->value)->getValue())*(-1);
		v = new Variavel(a, 1);
	}
	else {
		if(this->value->getType() == Value::Type::DOUBLE) {
			a.b = ((DoubleValue*)this->value)->getValue();
			v = new Variavel(a, 1);
		}
		else {
			Variavel *c = Contexto::getContexto().retornaVariavel(((IdValue*)this->value)->getValue());
			if(c->getTipo()==0) {
				a.b=c->getValor().a;
				v = new Variavel(a, 1);
			}
			else {
				a.b=c->getValor().b;
				v = new Variavel(a, 1);
			}
		}
	}
	return v;
}

//UnExpMinus
Value *UnExpMinus::getValue(){
	return this->value;
}

Variavel *UnExpMinus::execute() {//feito
	Variavel *v;
	tipoVariavel a;
	if(this->value->getType() == Value::Type::INT) {
		a.b = (((IntValue*)this->value)->getValue())*(-1);
		v = new Variavel(a, 1);
	}
	else {
		if(this->value->getType() == Value::Type::DOUBLE) {
			a.b = (((DoubleValue*)this->value)->getValue())*(-1);
			v = new Variavel(a, 1);
		}
		else {
			Variavel *c = Contexto::getContexto().retornaVariavel(((IdValue*)this->value)->getValue());
			if(c->getTipo()==0) {
				a.b=(c->getValor()).a*(-1);
				v = new Variavel(a, 1);
			}
			else {
				a.b=(c->getValor().b)*(-1);
				v = new Variavel(a, 1);
			}
		}
	}
	return v;
}

//IntValue
int IntValue::getValue(){
	return this->value; 
}

Value::Type IntValue::getType(){ 
	return INT; 
}

Variavel *IntValue::execute() {//feito
	tipoVariavel a;
	a.b = this->value;
	Variavel *v = new Variavel(a, 1);
	return v;
}

//DoubleValue
double DoubleValue::getValue(){ 
	return this->value; 
}

Value::Type DoubleValue::getType(){ 
	return DOUBLE; 
}

Variavel *DoubleValue::execute() {//feito
	tipoVariavel a;
	a.b = this->value;
	Variavel *v = new Variavel(a, 1);
	return v;
}

//IdValue
string IdValue::getValue(){ 
	return this->idValue; 
}

Value::Type IdValue::getType(){ 
	return ID_VALUE; 
}

Variavel *IdValue::execute() {//feito
	Variavel *c = Contexto::getContexto().retornaVariavel(this->getValue());
	Variavel *g = new Variavel();
	if(c->getTipo()==0) {
		g->setTipo(1);
		g->insereDouble((c->getValor()).a);
	}
	else {
		g->setTipo(1);
		g->insereDouble((c->getValor()).b);
	}
	return g;
}

//LparExpRpar
LValue *LparExpRpar::getExp(){ 
	return this->exp; 
}

Variavel *LparExpRpar::execute() {//feito
	Variavel *c = this->exp->execute();
	c->setTipo(1);
	return c;
}

//Variavel
int Variavel::getTipo(){
    return this->tipo;
}

tipoVariavel Variavel::getValor(){
    return this->valor;
}

void Variavel::insereDouble(double valor){
	this->valor.b = valor;
}

void Variavel::insereInteiro(int valor){
	this->valor.a = valor;
}

void Variavel::setTipo(int t) {
	this->tipo = t;
}

//Context
Contexto &Contexto::getContexto(){
	if (instance == NULL){ 
		instance = new Contexto(); 
	}
	return *instance;
}

void Contexto::setPrograma(Programa *prog){ 
	programa = prog;
}

Programa *Contexto::getPrograma(){
	return this->programa;
}

void Contexto::criaVariavel(string nome, Variavel *v) {
    this->variaveis[nome] = v;
}

Variavel *Contexto::retornaVariavel(string nome) {
	return this->variaveis[nome];
}

bool Contexto::getCriarVariavel(){
	return this->criarVariavel;
}

void Contexto::setCriarVariavel(bool modo){
	this->criarVariavel=modo;
}

int Contexto::getTipo(){
 	return this->tipo;
}

void Contexto::setTipo(int tp){
	this->tipo=tipo;
}

Contexto *Contexto::instance = NULL;
