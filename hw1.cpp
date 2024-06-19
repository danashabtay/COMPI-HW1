#include <iostream>
#include <sstream>
#include "tokens.hpp"
#include <string>

using std::cout;
using std::endl;

void printToken(std::string name)
{
    cout << yylineno << " " << name << " " << yytext << endl;
}

void printInvalidChar()
{
    cout << "Error " << yytext << endl;
}

void handleString()
{
    std::string str = yytext;
    cout << yylineno << " STRING " ;
    for(int index =0; index<yyleng; index++){

        if(str[index]=='"'){
            continue;
        }
        else if(str[index]=='\\'){
            index++;
            if(str[index]=='x'){ //hex
            std::stringstream ss;
            ss << std::hex << str.substr(index+1, 2);
            int x;
            ss >> x;
            cout << char(x);
            index += 2;
            }
            else if(str[index]=='n'){
                cout << '\n';
            }
            else if(str[index]=='r'){
                cout << '\r';
            }
            else if(str[index]=='t'){
                cout << '\t';  
            }
            else if(str[index]=='\"'){
                cout << '\"';  
            }
            else{
                cout << '\\';
            }
        }
        cout << str[index];
    }
    cout << endl;
        
}

void handleInvalidEscapeSeq()
{
    std::string str = yytext;
    cout << "Error undefined escape sequence " << str[yyleng-1] << endl;
    exit(0);
}

void handleInvalidHex()
{
    std::string str = yytext;
    cout << "Error undefined escape sequence ";
    if(str[yyleng-2] == 'x'){
        cout << str[yyleng - 2] << endl;
        return;
    }
    cout << "x" << str[yyleng - 2];
    if(str[yyleng - 1] != '"')
        cout << str[yyleng-1];
    cout << endl;

}

void handleUnclosedString()
{
    cout << "Error unclosed string" << endl;
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
        handleInvalidEscapeSeq();
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
