%{
#include <iostream>
#include "b.tab.h" 
using namespace std;
#define YY_DECL extern "C" int yylex()

int numero_linhas = 0;
%}

%option noyywrap
%x COMENTARIO
%x UMA


%%
[ ]         	   
[\t]                   	{}
[\n]                   	{numero_linhas++;}
0|[+-]?[0-9]+\.[0-9]+  	{yylval.double_value = atof(yytext); return NUMERO_REAL;}
0|[+-]?[1-9][0-9]*     	{yylval.int_value = atoi(yytext); return NUMERO_INTEIRO;}
"="					   	{return IGUALDADE;}
"+"					   	{return SOMA;}
"-"					   	{return SUBTRACAO;}
"*"					   	{return MULTIPLICACAO;}
"/"					   	{return DIVISAO;}
"("					   	{return PARENTESE_E;}
")"					   	{return PARENTESE_D;}
"{"					   	{return CHAVE_E;}
"}"					   	{return CHAVE_D;}
"if"                   	{return IF;}
"else"                 	{return ELSE;}
"for"                  	{return FOR;}
"int"		           	{yylval.int_value = 0; return INT;}
"double"		        {yylval.int_value = 1; return DOUBLE;}
"void"		            {return VOID;}
"main"					{return MAIN;}
"print"					{return PRINT;}
"!"				   		{return EXCLAMACAO;}
"<"					   	{return MENOR;}
">"					   	{return MAIOR;}	
"&"				  		{return E_COMECIAL;}
"|"				  		{return OU;}
";"				       	{return PONTO_VIRGULA;}
","				       	{return VIRGULA;}
":"					   	{return DOIS_PONTOS;}
"["				       	{return COLCHETE_E;}
"]"				       	{return COLCHETE_D;}
[a-zA-Z][a-zA-Z0-9_]*  	{yylval.id_value = strdup(yytext); return IDENTIFICADOR;}


"//"					{BEGIN(UMA);}
<UMA>\n 				{numero_linhas++; BEGIN(INITIAL);}
<UMA>.					{}
"/*"					{BEGIN(COMENTARIO);}
<COMENTARIO>"*/"		{BEGIN(INITIAL);}
<COMENTARIO>. 			{}
<COMENTARIO>\n 			{}
.					   	{printf("token nao indentificado: %s", yytext);}
%%
