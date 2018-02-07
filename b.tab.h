/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     INT = 261,
     MAIN = 262,
     DOUBLE = 263,
     PARENTESE_D = 264,
     PARENTESE_E = 265,
     CHAVE_D = 266,
     CHAVE_E = 267,
     IDENTIFICADOR = 268,
     SOMA = 269,
     SUBTRACAO = 270,
     MULTIPLICACAO = 271,
     DIVISAO = 272,
     MAIOR = 273,
     MENOR = 274,
     EXCLAMACAO = 275,
     E_COMECIAL = 276,
     OU = 277,
     NUMERO_INTEIRO = 278,
     NUMERO_REAL = 279,
     PONTO_VIRGULA = 280,
     VIRGULA = 281,
     IGUALDADE = 282,
     DOIS_PONTOS = 283,
     COLCHETE_E = 284,
     COLCHETE_D = 285,
     PRINT = 286,
     VOID = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 51 "b.y"

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



/* Line 1685 of yacc.c  */
#line 132 "b.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


