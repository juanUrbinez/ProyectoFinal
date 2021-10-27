#include "registro.h"
#include "ui_registro.h"

registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;

    ui->graphicsView->setGeometry(0,0,1900,1005);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/menu.png").scaled(1550,820));
    scene->setSceneRect(0,0,1898,1003);//tamaño de la escena
    //setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));

    ui->regist->setGeometry(300,300,100,40);//pushbotton  (registrar)
    ui->crear->setGeometry(300,350,100,40);//pushbotton  (login)
    ui->contrasena->hide();//label (label_2)
    ui->usuario->hide();//label (label)
    ui->enviar->hide();//pushbotton
    ui->volver->hide();//pushbotton
    ui->entrar->hide();//commandlinkbotton
    ui->login->hide();//lineEdit usuario  (usuario)
    ui->pass->hide();//lineEdit contraseña (contrasena)

}

registro::~registro()
{
    delete ui;
    delete scene;

}

bool registro::get_verif()
{
    return correcto;
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

     QFile file("TExto.txt");
     if(!file.exists()){
         qCritical()<<"Archivo no encontrado";
     }
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
         return;
     }
     QTextStream strem(&file);
     while(!strem.atEnd()){
         linea=strem.readLine();
         for(int i=0;i<linea.size();i++){
             if(linea[i]== ' ' or linea[i]== '\n'){
                 if(espacio==0){
                     if(usuario==work){
                         cont++;
                         dec=true;
                     }
                 }
                 else if(espacio==1){
                     if(contrasena==work){
                         cont++;
                         dec=false;
                     }
                 }
                 espacio+=1;
                 work= "";
             }
             else{
                 work+=linea[i];
             }
         }
         espacio=0;

     }
     if(cont==1){
         if(dec){
             QMessageBox::warning(this,"Iniciar sesion","Usuario Existente");

         }
         else{
             QMessageBox::warning(this,"Iniciar sesion","Constraseña  Existente");
         }
     }
     else{
         QMessageBox::warning(this,"Iniciar sesion","Usuario y Contraseña Existen");
         correcto=true;
        // get_verif();
         //MainWindow *principal=new MainWindow;
        //principal->show();
     }
     cont =0;
     file.close();

}


void registro::on_enviar_clicked()
{
    QString usuario=ui->login->text();
    QString contrasena=ui->pass->text();
    qDebug()<<usuario;
    qDebug()<<contrasena;


    QFile file("Texto.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qCritical()<<file.errorString();
        return;
    }

    QTextStream stream(&file);
    stream<<usuario<<" "<<contrasena<<" "<<"\r\n";
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
    ui->enviar->setGeometry(300,400,100,40);
    ui->volver->setGeometry(0,0,100,40);

    /*ui->graphicsView->setGeometry(0,0,800,800);
    regist->setSceneRect(0,0,800,800);
   // registro->setBackgroundBrush(QImage(":/escenario/escenario/menu.png").scaled(1550,820));
    ui->graphicsView->setScene(regist);
    setWindowTitle("Poison Run");
   // setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));*/
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
    ui->entrar->setGeometry(300,400,100,40);
    ui->volver->setGeometry(0,0,100,40);
}
