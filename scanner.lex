%{
/* Definition section */
#include <stdio.h>
#include "tokens.hpp"
%}

%option yylineno
%option noyywrap
string           ([ !#-\[\]-~	])
escape           ([\\ntr\"0])
hex              (x[0-7][0-9A-Fa-f])

%%

int                                                                                 return INT;
byte                                                                                return BYTE;
b                                                                                   return B;
bool                                                                                return BOOL;
and                                                                                 return AND;
or                                                                                  return OR;
not                                                                                 return NOT;
true                                                                                return TRUE;
false                                                                               return FALSE;
return                                                                              return RETURN;
if                                                                                  return IF;
else                                                                                return ELSE;
while                                                                               return WHILE;
break                                                                               return BREAK;
continue                                                                            return CONTINUE;
;                                                                                   return SC;
\(                                                                                  return LPAREN;
\)                                                                                  return RPAREN;
{                                                                                   return LBRACE;
}                                                                                   return RBRACE;
=                                                                                   return ASSIGN;
(==|!=|<|>|<=|>=)                                                                   return RELOP;
(\+|-|\*|\/)                                                                        return BINOP;
(\/\/[^\r\n\n\r]*)                                                                  return COMMENT;
([a-zA-Z][a-zA-Z0-9]*)                                                              return ID;
0|([1-9][0-9]*)                                                                     return NUM;
[ \t\r\n]+                                                                          ;
\"({string}|\\{escape}|\\{hex})*\"                                                   return STRING;
\"({string}|\\{escape}|\\{hex})*                                                    return UNCLOSED_STRING;
\"({string}|\\{escape}|\\{hex})*\\[^\\ntr\"0]                                       return INVALID_ESCAPE_SEQUENCE;
\"({string}|\\{escape}|\\{hex})*\\x([^0-7][0-9A-Fa-f]|[0-7][^0-9A-Fa-f]|[^0-7][^0-9A-Fa-f]|[^0-9A-Fa-f])    return INVALID_HEX;
([0]+[0-9]*)|0												                        return -1;
.                                                                                   return -1;

 













%%

/* C code section */