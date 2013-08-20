/*
 tokens.l
 Compressor
 
 Created by Orlando Leite on 10/10/12.
 Copyright 2011. All rights reserved.
 
 This file is part of Compressor.
 
 Compressor is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Compressor is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Compressor.  If not, see <http://www.gnu.org/licenses/>.
 */
%option noyywrap input

%{
	#include <iostream>
	#include "types.hpp"
	#include "expressions.hpp"
	#include "instructions.hpp"
	#include "blocks.hpp"
	#include "workspace.hpp"
	#include "parser.hpp"
	
	#define TOKEN(t) yylval.tinfo = new TokenInfo( t, curbs->lineno, *new std::string(), *new std::string( curbs->filename, strlen( curbs->filename ) ) )
	#define SAVE_TOKEN(a, t, l) \
		yylval.tinfo = new TokenInfo( a, \
									  yylineno, \
									  *new std::string(t, l), \
									  *new std::string( curbs->filename, strlen( curbs->filename ) ) \
									);
	
	unsigned int linenum = 0;
	
	extern int newfile(const char *fn, const char *rn);
	extern int popfile(void);
	
	struct bufstack
	{
		struct bufstack *prev;
		YY_BUFFER_STATE bs;
		int lineno;
		
		const char *filename;
		const char *realFilename;
		FILE *f;
	} *curbs = 0;

%}

%x IFILE

%%

"/*"([^\*]|\*[^/])*"*/" { ; }
"//"[^\r\n]*[\r\n] { ; }
^"#include"[ \t]*[\"<] { BEGIN IFILE; }

<IFILE>[^ \t\n\">]+ {
{
	int c;
	while((c = yyinput()) && c != '\n');
}

yylineno++;
// if(!newfile(yytext)) yyterminate();
/* no such file */
BEGIN INITIAL;
}
<IFILE>.|\n {
fprintf(stderr, "%4d bad include line\n", yylineno);
yyterminate();
}
<<EOF>>			{ /*if(!popfile()) TOKEN(TEOF); return TEOF;*/ yyterminate(); }

(\r\n|[\r\n])	{ ++yylineno; }

"@name"			{ TOKEN(TCOMPNAME); return TCOMPNAME; }
"@get"			{ TOKEN(TCOMPGET); return TCOMPGET; }
"@set"			{ TOKEN(TCOMPSET); return TCOMPSET; }
@[a-zA-Z_][a-zA-Z0-9_]* { SAVE_TOKEN( TCOMPVAR, yytext, yyleng ); return TCOMPVAR; /* currently not used */ }

"=="			{ TOKEN(TEQ); return TEQ; }
"==="			{ TOKEN(TEQA); return TEQA; }
"!="			{ TOKEN(TNE); return TNE; }
"!=="			{ TOKEN(TNEA); return TNEA; }
"<"				{ TOKEN(TLT); return TLT; }
"<="			{ TOKEN(TLE); return TLE; }
">"				{ TOKEN(TGT); return TGT; }
">="			{ TOKEN(TGE); return TGE; }
"+"				{ TOKEN(TPLUS); return TPLUS; }
"-"				{ TOKEN(TMINUS); return TMINUS; }
"*"				{ TOKEN(TMULT); return TMULT; }
"/"				{ TOKEN(TDIVIDE); return TDIVIDE; }
"%"				{ TOKEN(TMODULUS); return TMODULUS; }
"!"				{ TOKEN(TNOT); return TNOT; }
"++"			{ TOKEN(TINCREMENT); return TINCREMENT; }
"--"			{ TOKEN(TDECREMENT); return TDECREMENT; }
")"				{ TOKEN(TRPAREN); return TRPAREN; }
"("				{ TOKEN(TLPAREN); return TLPAREN; }
"["				{ TOKEN(TLBRACKET); return TLBRACKET; }
"]"				{ TOKEN(TRBRACKET); return TRBRACKET; }
"{"				{ TOKEN(TLBRACE); return TLBRACE; }
"}"				{ TOKEN(TRBRACE); return TRBRACE; }
","				{ TOKEN(TCOMMA); return TCOMMA; }
"."				{ TOKEN(TDOT); return TDOT; }
"="				{ TOKEN(TASSIGN); return TASSIGN; }
"+="			{ TOKEN(TASSIGN_PLUS); return TASSIGN_PLUS; }
"-="			{ TOKEN(TASSIGN_MINUS); return TASSIGN_MINUS; }
"*="			{ TOKEN(TASSIGN_MULTIPLY); return TASSIGN_MULTIPLY; }
"/="			{ TOKEN(TASSIGN_DIVIDE); return TASSIGN_DIVIDE; }
"|="			{ TOKEN(TASSIGN_BOR); return TASSIGN_BOR; }
";"				{ TOKEN(TSEMICOLON); return TSEMICOLON; }
":"				{ TOKEN(TCOLON); return TCOLON; }
"?"				{ TOKEN(TQUESTION); return TQUESTION; }
"||"			{ TOKEN(TOR); return TOR; }
"|"				{ TOKEN(TBOR); return TBOR; }
"&&"			{ TOKEN(TAND); return TAND; }
"&"				{ TOKEN(TBAND); return TBAND; }
"~"				{ TOKEN(TBNOT); return TBNOT; }
"^"				{ TOKEN(TBXOR); return TBXOR; }
"<<"			{ TOKEN(TLSHIFT); return TLSHIFT; }
">>"			{ TOKEN(TRSHIFT); return TRSHIFT; }
">>>"			{ TOKEN(TZFILL); return TZFILL; }
"instanceof"	{ TOKEN(TINSTANCEOF); return TINSTANCEOF; }
"delete"		{ TOKEN(TDELETE); return TDELETE; }
"continue"		{ TOKEN(TQUESTION); return TCONTINUE; }
"return"		{ TOKEN(TRETURN); return TRETURN; }
"break"			{ TOKEN(TBREAK); return TBREAK; }
"case"			{ TOKEN(TCASE); return TCASE; }
"default"		{ TOKEN(TDEFAULT); return TDEFAULT; }
"switch"		{ TOKEN(TSWITCH); return TSWITCH; }
"null"			{ TOKEN(TNULL); return TNULL; }
"new"			{ TOKEN(TNEW); return TNEW; }
"function"		{ TOKEN(TFUNCTION); return TFUNCTION; }
"get"			{ TOKEN(TGET); return TGET; }
"set"			{ TOKEN(TSET); return TSET; }
"package"		{ TOKEN(TPACKAGE); return TPACKAGE; }
"import"		{ TOKEN(TIMPORT); return TIMPORT; }
"class"			{ TOKEN(TCLASS); return TCLASS; }
"public"		{ TOKEN(TPUBLIC); return TPUBLIC; }
"private"		{ TOKEN(TPRIVATE); return TPRIVATE; }
"protected"		{ TOKEN(TPROTECTED); return TPROTECTED; }
"this"			{ TOKEN(TTHIS); return TTHIS; }
"super"			{ TOKEN(TSUPER); return TSUPER; }
"static"		{ TOKEN(TSTATIC); return TSTATIC; }
"const"			{ TOKEN(TCONST); return TCONST; }
"false"			{ TOKEN(TFALSE); return TFALSE; }
"true"			{ TOKEN(TTRUE); return TTRUE; }
"var"			{ TOKEN(TVAR); return TVAR; }
"if"			{ TOKEN(TIF); return TIF; }
"else"			{ TOKEN(TELSE); return TELSE; }
"while"			{ TOKEN(TWHILE); return TWHILE; }
"try"			{ TOKEN(TTRY); return TTRY; }
"catch"			{ TOKEN(TCATCH); return TCATCH; }
"do"			{ TOKEN(TDO); return TDO; }
"for"			{ TOKEN(TFOR); return TFOR; }
"in"			{ TOKEN(TIN); return TIN; }
"extends"		{ TOKEN(TEXTENDS); return TEXTENDS; }
"implements"	{ TOKEN(TIMPLEMENTS); return TIMPLEMENTS; }
"external"		{ TOKEN(TEXTERNAL); return TEXTERNAL; }
"customize"		{ TOKEN(TCUSTOMIZE); return TCUSTOMIZE; }
"export"		{ TOKEN(TEXPORT); return TEXPORT; }
[0-9]+|"."[0-9]+|[0-9]+"."[0-9]+|"0x"[0-9a-fA-F]+	{ 
	SAVE_TOKEN( TNUMBER, yytext, yyleng );
	return TNUMBER;
}
[a-zA-Z_][a-zA-Z0-9_]* {
	SAVE_TOKEN( TNAME, yytext, yyleng );
	return TNAME;
}
([ \t]+|[\r\n]) { ; }
\"(\\.|[^\\"])*\" {
	SAVE_TOKEN( TSTRING, yytext, yyleng );
	return TSTRING;
}
\/(\\.|[^\/g])*\/g {
	SAVE_TOKEN( TREGEX, yytext, yyleng );
	return TSTRING;
}
\'(\\.|[^\\'])*\' {
SAVE_TOKEN( TSTRING, yytext, yyleng );
return TSTRING;
}
%{/*\        { ; }
\n       { nextline(); }
\t       { ; }
"//".*\n { nextline(); }
.        { yyerror("illegal token"); }

[0-9]+		{ yylval = atoi(yytext); return TNUMERO; }
"+"		return OP_SOMA;
"-"		return OP_SUB;
"*"		return OP_MULT;
"/"		return OP_DIV;* /
%}
[ \t]+
[\r\n]		{ return TEOL;
	/* NAO usar [\r\n]+ senao ele fica 'a espera
	 do proximo caracter apos o Enter!!
	 Note-se que um EOL do Windows ("\r\n")
	 faz gerar dois tokens EOL * /
	 }*/
	%}

%%

const char *curfilename;

int newfile( const char *fn, const char *realPath )
{
	FILE *f = fopen(fn, "r");
	
	bufstack *bs = new bufstack();
	/* die if no file or no room */
	if(!f) {
		perror(fn);
		return 0;
	}
	
	if(!bs) {
		perror("malloc"); exit(1);
	}
	
	/* remember state */
	if(curbs)curbs->lineno = yylineno;
	bs->prev = curbs;
	/* set up current entry */
	bs->bs = yy_create_buffer(f, YY_BUF_SIZE);
	
	bs->f = f;
	bs->realFilename = realPath;
	bs->filename = realPath;
	
	// std::cout << fn << std::endl;
	
	yy_switch_to_buffer(bs->bs);
	curbs = bs;
	yylineno = 1;
	currentFile = realPath;
	curfilename = fn;
	
	return 1;
}

int popfile(void)
{
	struct bufstack *bs = curbs;
	struct bufstack *prevbs;
	if(!bs) return 0;
	/* get rid of current entry fclose(bs->f); yy_delete_buffer(bs->bs);
	 /* switch back to previous */
	prevbs = bs->prev;
	free(bs);
	if(!prevbs) return 0;
	yy_switch_to_buffer(prevbs->bs); curbs = prevbs;
	yylineno = curbs->lineno;
	curfilename = curbs->filename;
	currentFile = curbs->realFilename;
	
	return 1;
}
