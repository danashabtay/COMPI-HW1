#include <iostream>
#include <sstream>
#include "tokens.hpp"

using std::cout;
using std::endl;

void printToken(std::string name)
{
    cout << yylineno << " " << name << " " << yytext << endl;
}

void printInvalidChar()
{
    cout << "Error " << yytext << "\n";
}

void handleString()
{

}

void handleInvalidEscapeSeq()
{

}

void handleInvalidHex()
{

}

void handleUnclosedString()
{

}

void handleToken(int token)
{
    switch (token)
    {
    case INT:
        printToken("INT");
        break;
    case BYTE:
        printToken("BYTE");
        break;
    case B:
        printToken("B");
        break;
    case BOOL:
        printToken("BOOL");
        break;
    case AND:
        printToken("AND");
        break;
    case OR:
        printToken("OR");
        break;
    case NOT:
        printToken("NOT");
        break;
    case TRUE:
        printToken("TRUE");
        break;
    case FALSE:
        printToken("FALSE");
        break;
    case RETURN:
        printToken("RETURN");
        break;
    case IF:
        printToken("IF");
        break;
    case ELSE:
        printToken("ELSE");
        break;
    case WHILE:
        printToken("WHILE");
        break;
    case BREAK:
        printToken("BREAK");
        break;
    case CONTINUE:
        printToken("CONTINUE");
        break;
    case SC:
        printToken("SC");
        break;
    case LPAREN:
        printToken("LPAREN");
        break;
    case RPAREN:
        printToken("RPAREN");
        break;
    case LBRACE:
        printToken("LBRACE");
        break;
    case RBRACE:
        printToken("RBRACE");
        break;
    case ASSIGN:
        printToken("ASSIGN");
        break;
    case RELOP:
        printToken("RELOP");
        break;
    case BINOP:
        printToken("BINOP");
        break;
    case ID:
        printToken("ID");
        break;
    case NUM:
        printToken("NUM");
        break;
    case COMMENT:
        cout << yylineno << " COMMENT //" << endl;
        break;
    case STRING:
        handleString();
        break;
    case UNCLOSED_STRING:
        handleUnclosedString();
        break;
    case INVALID_HEX:
        handleInvalidHex();
        break;
    case INVALID_ESCAPE_SEQUENCE:
        handleString();
        break;
    case -1:
        printInvalidChar();
        exit(0);
    }
}
int main()
{
    int token;
    while (token = yylex())
    {
        handleToken(token);
    }
    return 0;
}
