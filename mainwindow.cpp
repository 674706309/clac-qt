#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->activeEdit->setAlignment(Qt::AlignRight);
//    ui->lastEdit->setAlignment(Qt::AlignRight);

    ui->modButton->setShortcut(tr("shift+5"));
//    ui->powerButton->setShortcut(tr("shift+5"));
//    ui->semicolonButton->setShortcut(tr("shift+5"));
//    ui->CEButton->setShortcut(tr("shift+5"));
//    ui->CButton->setShortcut(tr("shift+5"));
//    ui->backButton->setShortcut(tr("shift+5"));
//    ui->divButton->setShortcut(tr("shift+5"));
//    ui->mulButton->setShortcut(tr("shift+5"));
//    ui->subButton->setShortcut(tr("shift+5"));
//    ui->addButton->setShortcut(tr("shift+5"));
//    ui->ansbutton->setShortcut(tr("shift+5"));
//    ui->pointButton->setShortcut(tr("shift+5"));
//    ui->andButton->setShortcut(tr("shift+5"));
    ui->zeroButton->setShortcut(QKeySequence(Qt::Key_0));
    ui->oneButton->setShortcut(QKeySequence(Qt::Key_1));
    ui->twoButton->setShortcut(QKeySequence(Qt::Key_2));
    ui->threeButton->setShortcut(QKeySequence(Qt::Key_3));
    ui->fourButton->setShortcut(QKeySequence(Qt::Key_4));
    ui->fiveButton->setShortcut(QKeySequence(Qt::Key_5));
    ui->sixButton->setShortcut(QKeySequence(Qt::Key_6));
    ui->sevenButton->setShortcut(QKeySequence(Qt::Key_7));
    ui->eightButton->setShortcut(QKeySequence(Qt::Key_8));
    ui->nineButton->setShortcut(QKeySequence(Qt::Key_9));
    ui->ansbutton->setShortcut(QKeySequence(Qt::Key_Return));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearEdit()
{
    if(ui->activeEdit->text()=="0"||!status){
        ui->activeEdit->setText("");
    }
    status=true;
}
//按钮0
void MainWindow::on_zeroButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'0');
}
//按钮1
void MainWindow::on_oneButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'1');
}
//按钮2
void MainWindow::on_twoButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'2');
}
//按钮3
void MainWindow::on_threeButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'3');
}
//按钮4
void MainWindow::on_fourButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'4');
}
//按钮5
void MainWindow::on_fiveButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'5');
}
//按钮6
void MainWindow::on_sixButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'6');
}
//按钮7
void MainWindow::on_sevenButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'7');
}
//按钮8
void MainWindow::on_eightButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'8');
}
//按钮9
void MainWindow::on_nineButton_clicked()
{
    clearEdit();
    ui->activeEdit->setText(ui->activeEdit->text()+'9');
}
//按钮.
void MainWindow::on_pointButton_clicked()
{
    QString str=ui->activeEdit->text();
    if(str.indexOf('.')==-1){
        ui->activeEdit->setText(str+'.');
    }
}
//按钮1/x
void MainWindow::on_semicolonButton_clicked()
{
    if(status){
        if(ui->lastEdit->text()==""){
            ui->lastEdit->setText(QString("1/(%1)").arg(ui->activeEdit->text()));
        }else{
            ui->lastEdit->setText(QString("1/(%1)").arg(ui->lastEdit->text()));
        }
    }else{
        ui->lastEdit->setText(ui->lastEdit->text()+QString("1/(%1)").arg(ui->activeEdit->text()));
    }
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮x^2
void MainWindow::on_powerButton_clicked()
{
    if(status){
        if(ui->lastEdit->text()==""){
            ui->lastEdit->setText(QString("sqr(%1)").arg(ui->activeEdit->text()));
        }else{
            ui->lastEdit->setText(QString("sqr(%1)").arg(ui->lastEdit->text()));
        }
    }else{
        ui->lastEdit->setText(ui->lastEdit->text()+QString("sqr(%1)").arg(ui->activeEdit->text()));
    }
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮sqrt
void MainWindow::on_sqrtButton_clicked()
{
    if(status){
        if(ui->lastEdit->text()==""){
            ui->lastEdit->setText(QString("sqrt(%1)").arg(ui->activeEdit->text()));
        }else{
            ui->lastEdit->setText(QString("sqrt(%1)").arg(ui->lastEdit->text()));
        }
    }else{
        ui->lastEdit->setText(ui->lastEdit->text()+QString("sqrt(%1)").arg(ui->activeEdit->text()));
    }
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮%
void MainWindow::on_modButton_clicked()
{

}
//按钮CE
void MainWindow::on_CEButton_clicked()
{
    ui->activeEdit->setText("0");
}
//按钮C
void MainWindow::on_CButton_clicked()
{
    ui->activeEdit->setText("0");
    ui->lastEdit->setText("");
}
//按钮back
void MainWindow::on_backButton_clicked()
{
    QString str=ui->activeEdit->text();
    if(str.length()>1){
        ui->activeEdit->setText(str.mid(0,str.length()-1));
    }else{
        ui->activeEdit->setText("0");
    }
}
//按钮÷
void MainWindow::on_divButton_clicked()
{
    ui->lastEdit->setText(ui->lastEdit->text()+ui->activeEdit->text()+QChar(0x00F7));
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮×
void MainWindow::on_mulButton_clicked()
{
    ui->lastEdit->setText(ui->lastEdit->text()+ui->activeEdit->text()+QChar(0x00D7));
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮-
void MainWindow::on_subButton_clicked()
{
    ui->lastEdit->setText(ui->lastEdit->text()+ui->activeEdit->text()+'-');
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮+
void MainWindow::on_addButton_clicked()
{
    ui->lastEdit->setText(ui->lastEdit->text()+ui->activeEdit->text()+'+');
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
}
//按钮=
void MainWindow::on_ansbutton_clicked()
{
    ui->lastEdit->setText(ui->lastEdit->text()+ui->activeEdit->text());
    status=false;
    getAns();
    ui->activeEdit->setText(ans);
    ui->lastEdit->setText("");
}
//表达式求值
void MainWindow::getAns()
{
    QString str=ui->lastEdit->text();
    exp=(!status)?str.mid(0,str.length()-1):str;
    Compiler *com=new Compiler(exp);
    ans=com->ans;
}


//中缀转后缀
QString MainWindow::RPN(QString str)
{
    QStack<QChar> stack;
    QString re;
    stack.push('#');
    for(int i=0;i<str.length();i++){
        QChar c=str.at(i);
        if(c=='('){
            stack.push(c);
        }else if(c==')'){
            while (stack.top()!='(') {
                re+=stack.pop();
            }
            stack.pop();
        }else if(c=='+'||c=='-'){
            for(QChar ch=stack.top();ch!='#';ch=stack.top()){
                if(ch=='('){
                    break;
                }else{
                    re+=stack.pop();
                }
            }
            stack.push(c);
        }else if(c==QChar(0x00D7)||c==QChar(0x00F7)){
            for(QChar ch=stack.top();ch!='#'&&ch!='+'&&ch!='-';ch=stack.top()){
                if(ch=='('){
                    break;
                }else{
                    re+=stack.pop();
                }
            }
            stack.push(c);
        }else{
            re+=c;
        }
    }
    while(!stack.empty()&&stack.top()!='#'){
        re+=stack.pop();
    }
    qDebug()<<re;
    return re;
}
//后缀表达式求值
float MainWindow::work(QString str)
{
    QString exp=RPN(str);
    QStack<QChar> stack;
    for(int i=0;i<exp.length();i++){
        QChar c=exp.at(i);
        if(c=='+'){
            int num2=stack.pop().digitValue();
            int num1=stack.pop().digitValue();
            qDebug()<<num1<<num2;
            stack.push(QChar(num1+num2));
        }else if(c=='-'){
            int num2=stack.pop().digitValue();
            int num1=stack.pop().digitValue();
            stack.push(QChar(num1-num2));
        }else if(c==QChar(0x00D7)){
            int num2=stack.pop().digitValue();
            int num1=stack.pop().digitValue();
            stack.push(QChar(num1*num2));
        }else if(c==QChar(0x00F7)){
            int num2=stack.pop().digitValue();
            int num1=stack.pop().digitValue();
            stack.push(QChar(num1/num2));
        }else{
            stack.push(c);
        }
    }
    qDebug()<<stack.top();
    return stack.top().digitValue();
}



