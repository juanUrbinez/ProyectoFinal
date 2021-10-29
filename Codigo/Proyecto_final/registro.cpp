#include "registro.h"
#include "ui_registro.h"

registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;

    ui->graphicsView->setGeometry(0,0,1900/2,1150/2);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/menu.png").scaled(1000,650));
    scene->setSceneRect(0,0,1890/2,1140/2);//tamaño de la escena
    setFixedSize(1900/2,1150/2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));

    ui->regist->setGeometry(400,150,120,80);
    ui->crear->setGeometry(400,250,120,80);

    ui->contrasena->hide();
    ui->usuario->hide();
    ui->enviar->hide();
    ui->volver->hide();
    ui->entrar->hide();
    ui->login->hide();
    ui->pass->hide();

    ui->regist->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->crear->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->enviar->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->volver->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->entrar->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");

}

registro::~registro()
{
    delete ui;
    delete scene;

}

void registro::on_volver_clicked()
{
    ui->regist->show();
    ui->crear->show();

    ui->pass->hide();
    ui->login->hide();
    ui->enviar->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
    ui->volver->hide();
    ui->entrar->hide();
}


void registro::on_entrar_clicked()
{
    QString usuario=ui->login->text();
    QString contrasena=ui->pass->text();

     QString linea="",work="";

     QFile file("../Proyecto_final/texto.txt");
     if(!file.exists()){
         qCritical()<<"Archivo no encontrado";
     }
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
         return;
     }
     QTextStream strem(&file);
     while(!strem.atEnd())
     {
         linea=strem.readLine();
         for(int i=0;i<linea.size();i++)
         {
             if(linea[i]== ' ' or linea[i]== '*')
             {
                 if(espacio==0)
                 {
                     if(usuario==work)
                     {
                         cont++;
                         dec=true;
                     }
                 }
                 else if(espacio==1)
                 {
                     if(contrasena==work)
                     {
                         cont++;
                         dec=false;
                     }
                 }
                  else if(espacio==2)
                  {
                      nivel=work;
                  }

                 else if(espacio==3)
                 {
                     score=work;
                 }
                 qDebug()<<nivel;
                 qDebug()<<score;


                 espacio+=1;
                 work= "";
             }
             else
             {
                 work+=linea[i];
             }
         }
         espacio=0;

     }
     if(cont==1){
         if(dec)
         {
             QMessageBox::warning(this,"Iniciar sesion","Contraseña incorrecta");

         }
         else
         {
             QMessageBox::warning(this,"Iniciar sesion","Usuario Incorrecto");
         }
     }
     else if(cont==2)
     {
         QMessageBox::warning(this,"Iniciar sesion","Sesion Iniciada");
         correcto=true;

     }
     else
     {
         QMessageBox::warning(this,"Iniciar sesion","Usuario y contraseña incorrecto");
     }
     cont =0;
     file.close();

}

void registro::on_enviar_clicked()
{
    QString usuario=ui->login->text();
    QString contrasena=ui->pass->text();
    QString nivel="*1";
    QString score="*0 ";
    qDebug()<<usuario;
    qDebug()<<contrasena;


    QFile file("../Proyecto_final/texto.txt");
    if(!file.open(QIODevice::Append| QIODevice::Text))
    {
        qCritical()<<file.errorString();
        return;
    }

    QTextStream stream(&file);
    stream<<usuario<<" "<<contrasena<<nivel<<score<<"\r\n";
    QMessageBox::warning(this,"Iniciar sesion","Usuario creado");

    file.close();
}


void registro::on_regist_clicked()
{
    ui->regist->hide();
    ui->crear->hide();

    ui->contrasena->show();
    ui->usuario->show();
    ui->enviar->show();
    ui->login->show();
    ui->pass->show();
    ui->volver->show();


    ui->usuario->setGeometry(200,100,100,40);
    ui->login->setGeometry(310,110,100,30);
    ui->contrasena->setGeometry(200,200,100,50);
    ui->pass->setGeometry(310,210,100,30);
    ui->enviar->setGeometry(310,300,100,40);
    ui->volver->setGeometry(0,0,100,40);

}


void registro::on_crear_clicked()
{
    ui->login->clear();
    ui->pass->clear();

    ui->regist->hide();
    ui->crear->hide();
    ui->pass->show();
    ui->login->show();
    ui->entrar->show();
    ui->usuario->show();
    ui->contrasena->show();
    ui->volver->show();

    ui->usuario->setGeometry(200,100,100,40);
    ui->login->setGeometry(310,110,100,30);
    ui->contrasena->setGeometry(200,200,100,50);
    ui->pass->setGeometry(310,210,100,30);
    ui->entrar->setGeometry(310,300,100,40);
    ui->volver->setGeometry(0,0,100,40);
}


/*
void registro::guardarProgreso()
{
    QString usuario=ui->login->text();
    QString contrasena=ui->pass->text();

     QString linea="",work="";

     QFile file("../Proyecto_final/texto.txt");
     if(!file.exists()){
         qCritical()<<"Archivo no encontrado";
     }
     if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
         return;
     }
     QTextStream strem(&file);
     while(!strem.atEnd())
     {
         linea=strem.readLine();
         for(int i=0;i<linea.size();i++)
         {
             if(linea[i]== ' ' or linea[i]== '*')
             {
                 if(espacio==0)
                 {
                     if(usuario==work)
                     {
                         cont++;
                         dec=true;
                     }
                 }

                 espacio+=1;
                 work= "";
             }
             else
             {
                 work+=linea[i];
             }
         }
         espacio=0;

     }
     if(cont==1){
         if(dec)
         {


         }
         else
         {
             QMessageBox::warning(this,"Iniciar sesion","Usuario Incorrecto");
         }
     }
     else if(cont==2)
     {
         QMessageBox::warning(this,"Iniciar sesion","Sesion Iniciada");
         correcto=true;

     }
     else
     {
         QMessageBox::warning(this,"Iniciar sesion","Usuario y contraseña incorrecto");
     }
     cont =0;
     file.close();

}





*/
