#ifndef COMPILER_H
#define COMPILER_H

#include <QString>

class Compiler
{
public:
    Compiler(QString);
    QString sym,exp,ans;
    double num;
    enum Token
    {
        NUMBER,PLUS,SUB,MUL,DIV,LEFT,RIGHT
    };
    int getCh();
};

#endif // COMPILER_H
