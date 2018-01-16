#include "compiler.h"

Compiler::Compiler(QString str)
{
    exp=str;
    length=-1;
    getCh();
    ans="0";
}

int Compiler::getCh()
{
    QChar buf[20];
    int pos=0;
    QChar ch=exp.at(++length);
    while (ch==' '||ch=='\t'||ch=='\r'||ch=='\n') {
        if(length>=exp.length()){
            return -1;
        }
        ch=exp.at(++length);
    }
    if(isalpha(ch)){
        while (isalpha(ch)||isdigit(ch)) {
            buf[pos++]=ch;
            length++;
            ch=exp.at(length);
        }

    }

    return 0;
}
