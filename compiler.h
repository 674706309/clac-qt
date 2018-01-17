#ifndef COMPILER_H
#define COMPILER_H

#include <QString>
#include <QList>

class Compiler
{
public:
    Compiler(QString);
private:
    QString sym,exp,ans;
    int length;
    double num;
    enum Token
    {
        INT,DOUBLE,PLUS,SUB,MUL,DIV,LEFT,RIGHT
    };
    struct Symbol{
      QChar num;
      QString name;
      QString value;
      QString type;
      Symbol(QChar num,QString name,QString value,QString type){
          this->num=num;
          this->name=name;
          this->value=value;
          this->type=type;
      }
    };

    int getCh();
};

#endif // COMPILER_H
