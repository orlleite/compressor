/*
 pre_tokens.l
 Compressor
 
 Created by Orlando Leite on 13/05/13.
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
%option prefix="zz"
%option noyywrap input

%{
	#include <iostream>
	#include "preprocessor.hpp"
	#include "pre_parser.hpp"
	
	#define TOKEN(t) zzlval.tinfo = new TokenInfo( t, 0, *new std::string(), "" )
	#define SAVE_TOKEN(a, t, l) \
		zzlval.tinfo = new TokenInfo( a, \
									  0, \
									  *new std::string(t, l), \
									  "" \
									);
	/*unsigned int linenum = 0;
	int ppnewfile( FILE *file );
	
	struct bufstack
	{
		struct bufstack *prev;
		YY_BUFFER_STATE bs;
		int lineno;
		
		const char *filename;
		FILE *f;
	} *curbs = 0;
	
	const char *curfilename;*/
	
	YY_BUFFER_STATE bp;
%}

%x IDEFINE_NAME IDEFINE_VALUE
%x IIFS

%%

<<EOF>>			{ yyterminate(); TOKEN(TEOF); return TEOF; }

<IIFS>" "[a-zA-Z_][a-zA-Z0-9_]*[\r\n] { BEGIN INITIAL; SAVE_TOKEN(TDEFNAME, zztext+1, zzleng-2 ); return TDEFNAME; }
"#endif"[\r\n] { return TENDIFDEF; }
"#else"[\r\n] { return TELSEDEF; }
"#elseif" { BEGIN IIFS; return TELSEIFDEF; }
"#if" { BEGIN IIFS; return TIFDEF; }

<IDEFINE_VALUE>(\\[\r\n]|[^\r\n])*[\r\n] { BEGIN INITIAL; SAVE_TOKEN(TDEFVALUE, zztext, zzleng-1 ); return TDEFVALUE; }
<IDEFINE_NAME>" "[a-zA-Z_][a-zA-Z0-9_]*" " { BEGIN IDEFINE_VALUE; SAVE_TOKEN(TDEFNAME, zztext+1, zzleng-2 ); return TDEFNAME; }
"#define" { BEGIN IDEFINE_NAME; TOKEN(TDEFINE); return TDEFINE; }


[\r\n] { SAVE_TOKEN( TLINE, zztext, zzleng ); return TLINE; }
^[^#\r\n][^\r\n]*[\r\n] { SAVE_TOKEN( TLINE, zztext, zzleng ); return TLINE; }
^[^#\r\n][^\r\n]* { SAVE_TOKEN( TLINE, zztext, zzleng ); return TLINE; }


%{/*

"@name"			{ TOKEN(TCOMPNAME); return TCOMPNAME; }
"@get"			{ TOKEN(TCOMPGET); return TCOMPGET; }
"@set"			{ TOKEN(TCOMPSET); return TCOMPSET; }

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
[0-9]+|"."[0-9]+|[0-9]+"."[0-9]+|"0x"[0-9a-fA-F]+	{ 
	SAVE_TOKEN( TNUMBER, zztext, zzleng );
	return TNUMBER;
}
[a-zA-Z_][a-zA-Z0-9_]* {
	SAVE_TOKEN( TNAME, zztext, zzleng );
	return TNAME;
}
([ \t]+|[\r\n]) { ; }
\"(\\.|[^\\"])*\" {
	SAVE_TOKEN( TSTRING, zztext, zzleng );
	return TSTRING;
}
\/(\\.|[^\/g])*\/g {
	SAVE_TOKEN( TREGEX, zztext, zzleng );
	return TSTRING;
}
\'(\\.|[^\\'])*\' {
SAVE_TOKEN( TSTRING, zztext, zzleng );
return TSTRING;
}
%{

/*\        { ; }
\n       { nextline(); }
\t       { ; }
"//".*\n { nextline(); }
.        { zzerror("illegal token"); }

[0-9]+		{ zzlval = atoi(zztext); return TNUMERO; }
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


int ppnewfile( FILE *file )
{
	if( bp ) zz_delete_buffer(bp);
	
	// BEGIN(INTIAL);

	bp = zz_create_buffer(file, YY_BUF_SIZE);
	zzin = file;
	
	return 1;
}


