%{
    #include"syntax.tab.h"
%}
%option noyywrap

string \"[a-zA-Z]+\"

int 0|[1-9][0-9]*
frac \.[0-9]+
exp [Ee][+-]?{int}
number -?{int}{frac}?{exp}?

empty [ \n\r\t]

%%

"{" { return LC; }
"}" { return RC; }
"[" { return LB; }
"]" { return RB; }
":" { return COLON; }
"," { return COMMA; }

"true" { return TRUE; }
"false" { return FALSE; }
"null" { return VNULL; }

{string} { return STRING; }
{number} { return NUMBER; }

{empty} {}

. { printf("lexical error: %s\n", yytext); }