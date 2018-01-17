#include "compiler.h"

Compiler::Compiler(QString str)
{
    exp=str;
    length=0;
    getCh();
    ans="0";
}

int Compiler::getCh()
{
    QString buf="";
    QList<Symbol> tokens;
    int pos=0;
    char ch=exp.at(length++).toLatin1();
    if(isalpha(ch)){
        while (isalpha(ch)||isdigit(ch)) {
            buf+=ch;
            ch=exp.at(length++).toLatin1();
        }
    }else if(isdigit(ch)){
        while (isdigit(ch)) {
            buf+=ch;
            ch=exp.at(length++).toLatin1();
        }
        if(ch=='.'){
            ch=exp.at(length++).toLatin1();
            if(isdigit(ch)){
                while (isdigit(ch)) {
                    buf+=ch;
                    ch=exp.at(length++).toLatin1();
                }
                tokens.append(Symbol('8',buf,buf,"DOUBLE"));
            }else{
                tokens.append(Symbol('5',buf,buf,"INT"));
                tokens.append(Symbol('e',ch,". before num","ERROR"));

            }
        }
    }


    return 0;
}
