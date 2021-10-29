#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    menu=new QGraphicsScene;
    scene = new QGraphicsScene;
    option = new QGraphicsScene;
    scene2 = new QGraphicsScene;
    scene3 = new QGraphicsScene;
    scene4 = new QGraphicsScene;
    scene5 = new QGraphicsScene;
    scene6 = new QGraphicsScene;
    scene7 = new QGraphicsScene;
    scene8 = new QGraphicsScene;

   //setGeometry(0,0,1002,1002);
    ui->graphicsView->setGeometry(0,0,1900/2,1150/2);
    menu->setSceneRect(0,0,1890/2,1140/2);
    menu->setBackgroundBrush(QImage(":/escenario/escenario/option.png").scaled(1000,650));
    ui->graphicsView->setScene(menu);
    setFixedSize(1900/2,1150/2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));

    mundo= new QGraphicsItemGroup;


    tempo=new QTimer;
    connect(tempo,SIGNAL(timeout()),this,SLOT(temporizador()));
    //refreshTimer = new QTimer();
    sprite=1;
    sprite2=1;



    //timfis=new QTimer;
    //connect(timfis,SIGNAL(timeout()),this,SLOT(simulacion()));


    ui->inicio->setGeometry(385,200,120,80);
    ui->salir->setGeometry(385,300,120,80);
    ui->partida->hide();
    ui->anterior->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->lcdNumber->hide();
    ui->monedas->hide();
    ui->aceptar->hide();

    ui->inicio->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->salir->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->partida->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->anterior->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");
    ui->aceptar->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(80,170,58);");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete time;
    delete tempo;
    //delete timfis;
    delete player;
    delete scene;
    delete option;
    delete menu;
}

void MainWindow::set_window(int MAPA)
{
    MAPA=variable;
    if(MAPA==1)
    {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
    }
    else if(MAPA==2)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene2);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene2->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==3)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene3);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene3->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==4)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene4);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene4->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==5)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene5);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene5->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==6)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene6);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene6->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==7)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene7);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene7->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    else if(MAPA==8)
        {
        ui->graphicsView->setGeometry(0,0,1900/2,1150/2);
        ui->graphicsView->setScene(scene8);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/WIN.png").scaled(1000,650));
        scene8->setSceneRect(0,0,1890/2,1140/2);//tamaño de la escena
        setFixedSize(1900/2,1150/2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }


}


void MainWindow::generar_mapa(int a)
{
    variable=a;

    if(variable==1)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene->addItem(player);
        for(int i=0;i<14;i++){
            for(int j=0;j<50;j++){
                if(nivel1[i][j]==1)
                {
                    plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro"));
                    scene->addItem(plataformas.last());

                }
                else if(nivel1[i][j]==2){
                    plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma"));
                    scene->addItem(plataformas.last());
                }
                else if(nivel1[i][j]==3){
                    plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                    scene->addItem(plataforma.last());
                }
                else if(nivel1[i][j]==4){
                    plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                    scene->addItem(plataforma.last());
                }
                else if(nivel1[i][j]==5){
                    plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                    scene->addItem(plataforma.last());
                }

                else if(nivel1[i][j]==6){
                    plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                    scene->addItem(plataforma.last());
                }
            }
        }
    }
    else if(variable==2)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene2->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel2[i][j]==1)
                   {
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro"));
                       scene2->addItem(plataformas.last());

                   }
                   else if(nivel2[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma"));
                       scene2->addItem(plataformas.last());
                   }
                   else if(nivel2[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene2->addItem(plataforma.last());
                   }
                   else if(nivel2[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene2->addItem(plataforma.last());
                   }

                   else if(nivel2[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene2->addItem(plataforma.last());
                   }
                   else if(nivel2[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene2->addItem(plataforma.last());
                   }
                   else if(nivel2[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene2->addItem(plataforma.last());
                   }
                   else if(nivel2[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                        scene2->addItem(plataforma.last());
                   }
                   else if(nivel2[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                        scene2->addItem(plataforma.last());
                   }

              }
           }
    }


    else if (variable==3)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene3->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel3[i][j]==1){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                       scene3->addItem(plataformas.last());
                   }
                   else if(nivel3[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                       scene3->addItem(plataformas.last());
                   }
                   else if(nivel3[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==12){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                       scene3->addItem(plataforma.last());
                   }
                   else if(nivel3[i][j]==13){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                       scene3->addItem(plataforma.last());
                   }
              }
           }
    }

    else if (variable==4)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene4->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel4[i][j]==1){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                       scene4->addItem(plataformas.last());
                   }
                   else if(nivel4[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                       scene4->addItem(plataformas.last());
                   }
                   else if(nivel4[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==12){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                       scene4->addItem(plataforma.last());
                   }
                   else if(nivel4[i][j]==13){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                       scene4->addItem(plataforma.last());
                   }
              }
           }
    }
    else if (variable==5)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene5->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel5[i][j]==1){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                       scene5->addItem(plataformas.last());
                   }
                   else if(nivel5[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                       scene5->addItem(plataformas.last());
                   }
                   else if(nivel5[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==12){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                       scene5->addItem(plataforma.last());
                   }
                   else if(nivel5[i][j]==13){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                       scene5->addItem(plataforma.last());
                   }
              }
           }
    }
    else if (variable==6)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene6->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel6[i][j]==1){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                       scene6->addItem(plataformas.last());
                   }
                   else if(nivel6[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                       scene6->addItem(plataformas.last());
                   }
                   else if(nivel6[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==12){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                       scene6->addItem(plataforma.last());
                   }
                   else if(nivel6[i][j]==13){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                       scene6->addItem(plataforma.last());
                   }
              }
           }
    }

    else if (variable==7)
    {
        player = new personaje();
        player->setPos(tam+40,13*tam);
        scene7->addItem(player);
        for(int i=0;i<14;i++){
               for(int j=0;j<50;j++){
                   if(nivel7[i][j]==1){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                       scene7->addItem(plataformas.last());
                   }
                   else if(nivel7[i][j]==2){
                       plataformas.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                       scene7->addItem(plataformas.last());
                   }
                   else if(nivel7[i][j]==3){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==4){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==5){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"VacioVenenoso"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==6){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==7){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==8){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==11){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==12){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                       scene7->addItem(plataforma.last());
                   }
                   else if(nivel7[i][j]==13){
                       plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                       scene7->addItem(plataforma.last());
                   }
              }
           }
    }




    tempo->start(1000);
    ui->lcdNumber->display(10);

}



void MainWindow::temporizador()
{
    if(ui->lcdNumber->intValue()<=0)
    {
        cantidad=0;
        if(variable==1)
        {
            scene->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene->addItem(player);
        }
        else if(variable==2)
        {
            scene2->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene2->addItem(player);
        }
        else if(variable==3)
        {
            scene3->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene3->addItem(player);
        }
        else if(variable==4)
        {
            scene4->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene4->addItem(player);
        }
        else if(variable==5)
        {
            scene5->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene5->addItem(player);
        }
        else if(variable==6)
        {
            scene6->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene6->addItem(player);
        }
        else if(variable==7)
        {
            scene7->removeItem(player);
            generar_mapa(variable);
            ui->lcdNumber->display(10);
            scene7->addItem(player);
        }

    }
    else{
     ui->lcdNumber->display((ui->lcdNumber->intValue())-1);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_A)
    {
        //if(!EvaluaColision())
        getPlayer()->Mover_A_Izquierda(true);

    }
    else if (event->key() == Qt::Key_D)
    {
        //if(!EvaluaColision())
        getPlayer()->Mover_A_Derecha(true);
    }
    else if (event->key() == Qt::Key_W)
    {
        if(!getPlayer()->getEnElAire())
        {

            getPlayer()->Saltar();
        }
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        getPlayer()->Mover_A_Izquierda(false);
    }
    else if (event->key() == Qt::Key_D){
        getPlayer()->Mover_A_Derecha(false);
    }
}


void MainWindow::EvaluaColisionMovimiento()
{

    getPlayer()->ActualizarMovimiento();

    int next_x = getPlayer()->x();
    int next_y = getPlayer()->y();

    colision=false;

    escenario *BloqueColision;

    QList<escenario*>plataformasColicion;

    QList<escenario*>::Iterator it;
    for (it=plataformas.begin();it!=plataformas.end() ;it++ )
    {
        if ((*it)->collidesWithItem(player))
        {
            plataformasColicion.append(*it);
            colision=true;

        }
    }

    if (colision)
    {

        for(int i = 0 ; i < plataformasColicion.count() ; i ++)
        {
            BloqueColision=plataformasColicion[i];

            int bloc_x = BloqueColision->x();
            int bloc_y = BloqueColision->y();


            bool cArriba = false;
            bool cAbajo = false;
            bool cDerecha = false;
            bool cIzquierda = false;


            ////
            if( getPlayer()->y()<= bloc_y)
            {
                cArriba = true;
            }

            if( getPlayer()->y() >= bloc_y)
                cAbajo = true;

            if( getPlayer()->x() > bloc_x )
            {
                cDerecha = true;
            }
            if( getPlayer()->x()<= bloc_x)
            {
                cIzquierda = true;
            }
            if(bloc_y - getPlayer()->y()< 50)
            {
                getPlayer()->setRebotando(true);
            }

            if(cArriba && !cAbajo)
            {
                next_y = bloc_y - 40+1;
                getPlayer()->setVy(0);
            }

            else if (cAbajo && getPlayer()->getEnElAire())
            {

                next_y = bloc_y + 40 ;
                getPlayer()->setVy(  - getPlayer()->getVy() );

            }

            else if(cIzquierda && !cArriba)
            {
                next_x = bloc_x - getPlayer()->getWidth();
                getPlayer()->setVx(0);
            }
            else if(cDerecha && !cArriba)
            {
                next_x = bloc_x + getPlayer()->getWidth();
                getPlayer()->setVx(0);


            }
        }
        getPlayer()->setPos(next_x,next_y);
        plataformasColicion.pop_back();

    }




}

void MainWindow::EvaluaColisionPoderes()
{
    bool flag=false;
    for(int i=0;i<plataforma.size();i++)
    {
        if(plataforma.at(i)->getClase() == "moneda" && plataforma.at(i)->collidesWithItem(player))
        {
            getPlayer()->monedas=100;
            cantidad+=getPlayer()->monedas;
            if(variable==1)
            {
                scene->removeItem(plataforma.at(i));
            }
            else if(variable==2)
            {
               scene2->removeItem(plataforma.at(i));
            }
            else if(variable==3)
            {
               scene3->removeItem(plataforma.at(i));
            }
            else if(variable==4)
            {
               scene4->removeItem(plataforma.at(i));
            }
            else if(variable==5)
            {
               scene5->removeItem(plataforma.at(i));
            }
            else if(variable==6)
            {
               scene6->removeItem(plataforma.at(i));
            }
            else if(variable==7)
            {
               scene7->removeItem(plataforma.at(i));
            }


            plataforma.removeAt(i);
        }
        if(plataforma.at(i)->getClase() == "orbe" && plataforma.at(i)->collidesWithItem(player))
        {
            ui->lcdNumber->display(((ui->lcdNumber->intValue())-5)+10);

            if(variable==1)
            {
                scene->removeItem(plataforma.at(i));
            }
            else if(variable==2)
            {
               scene2->removeItem(plataforma.at(i));
            }
            else if(variable==3)
            {
               scene3->removeItem(plataforma.at(i));
            }
            else if(variable==4)
            {
               scene4->removeItem(plataforma.at(i));
            }
            else if(variable==5)
            {
               scene5->removeItem(plataforma.at(i));
            }
            else if(variable==6)
            {
               scene6->removeItem(plataforma.at(i));
            }
            else if(variable==7)
            {
               scene7->removeItem(plataforma.at(i));
            }
            plataforma.removeAt(i);

        }

        if(plataforma.at(i)->getClase() == "zonaM" && plataforma.at(i)->collidesWithItem(player))
        {
            ui->lcdNumber->display((ui->lcdNumber->intValue())-1);
            flag=true;

        }
        if(plataforma.at(i)->getClase() == "VacioVenenoso" && plataforma.at(i)->collidesWithItem(player))
        {
            ui->lcdNumber->display(0);
            flag=true;

        }
        if(plataforma.at(i)->getClase() == "puerta" && plataforma.at(i)->collidesWithItem(player))
        {

            if(variable==1)
            {
                scene->removeItem(player);
            }
            else if(variable==2)
            {
               scene2->removeItem(player);
            }
            else if(variable==3)
            {
               scene3->removeItem(player);
            }
            else if(variable==4)
            {
               scene4->removeItem(player);
            }
            else if(variable==5)
            {
               scene5->removeItem(player);
            }
            else if(variable==6)
            {
               scene6->removeItem(player);
            }
            else if(variable==7)
            {
               scene7->removeItem(player);
            }
            plataforma.clear();
            plataformas.clear();
            variable++;
            generar_mapa(variable);
            set_window(variable);
        }

    }
    if(flag &&getPlayer()->live)
    {
        cantidad=0;
        getPlayer()->live=false;
    }

}

void MainWindow::sprites()
{
    if(getPlayer()->getSaltando())
    {
        getPlayer()->setSprite(QString(":/escenario/Personaje/subiendo.png"));
        sprite ++;
    }
    else if (getPlayer()->getCayendo())
    {
        getPlayer()->setSprite(QString(":/escenario/Personaje/6.png"));
        sprite ++;
    }
    else if(getPlayer()->getMoviendo_Derecha() || getPlayer()->getMoviendo_Izquierda())
    {
        if(sprite < 1 || sprite > 8)
        {
            sprite = 1;
        }
        getPlayer()->setSprite(QString(":/escenario/Personaje/%1.png").arg(sprite));
        sprite ++;
    }
    else if(getPlayer()->getQuieto())
    {
        if(sprite > 16 || sprite < 14)
        {
            sprite = 14;
        }
        getPlayer()->setSprite(QString(":/escenario/Personaje/%1.png").arg(sprite));
        sprite2 ++;
        sprite ++;
         if(sprite > 16 && sprite2 > 4)
         {
            sprite = 16;
            sprite2 = 1;
        }
        else if(sprite > 16 )
         {
            sprite = 14;
        }
    }



}

void MainWindow::on_anterior_clicked()
{
    ui->graphicsView->setScene(menu);
    ui->partida->hide();
    ui->anterior->hide();
    ui->inicio->show();
    ui->salir->show();
}

void MainWindow::on_inicio_clicked()
{
    ui->anterior->show();
    ui->partida->show();
    ui->anterior->setGeometry(385,300,120,80);
    ui->partida->setGeometry(385,200,120,80);
    ui->inicio->hide();
    ui->salir->hide();

    ui->graphicsView->setGeometry(0,0,1900/2,1150/2);
    option->setSceneRect(0,0,1890/2,1140/2);
    option->setBackgroundBrush(QImage(":/escenario/escenario/menu.png").scaled(1000,650));
    ui->graphicsView->setScene(option);
    setFixedSize(1900/2,1150/2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));

}

void MainWindow::on_salir_clicked()
{
    close();
}


void MainWindow::on_partida_clicked()
{
    ui->anterior->hide();
    ui->partida->hide();
    ui->aceptar->show();
    ui->aceptar->setGeometry(250,240,400,120);

    datos=new registro(0);
    datos->show();

}


void MainWindow::on_aceptar_clicked()
{
    if(datos->correcto)
    {
        variable=(datos->nivel.toInt());
        ui->label->show();
        ui->label_2->show();
        ui->lcdNumber->show();
        ui->monedas->show();
        ui->aceptar->hide();

        if(variable==1)
        {
            ui->graphicsView->setScene(scene);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==2)
        {
            ui->graphicsView->setScene(scene2);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==3)
        {
            ui->graphicsView->setScene(scene3);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==4)
        {
            ui->graphicsView->setScene(scene4);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==5)
        {
            ui->graphicsView->setScene(scene5);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==6)
        {
            ui->graphicsView->setScene(scene3);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==7)
        {
            ui->graphicsView->setScene(scene4);
            set_window(variable);
            generar_mapa(variable);

        }
        else if(variable==8)
        {
            ui->graphicsView->setScene(scene5);
            set_window(variable);
            generar_mapa(variable);
        }


        refreshTimer = new QTimer();
        connect(refreshTimer,SIGNAL(timeout()),this,SLOT(ActualizarPosicionPersonaje()));
        refreshTimer->start(1000/60);

        spriteTimer = new QTimer(this);
        connect(spriteTimer,SIGNAL(timeout()),this,SLOT(sprites()));
        spriteTimer->start(90);

    }

}


personaje *MainWindow::getPlayer() const
{
    return player;

}

void MainWindow::ActualizarPosicionPersonaje()
{
    ui->monedas->display(cantidad);

    int next_x = getPlayer()->x();
    int next_y = getPlayer()->y();

    if(getPlayer()->getEnElAire() == true)
    {
        next_y += getPlayer()->getVy() * 1/60;
        float dt = 1/(float)60;
        getPlayer()->setVy( getPlayer()->getVy() + 250 * 10 * dt);
    }


    if(getPlayer()->getMoviendo_Derecha())
    {
        getPlayer()->AumentarVelocidadDerecha();

    }
    else if(getPlayer()->getMoviendo_Izquierda())
    {
        getPlayer()->AumentarVelocidadIzquierda();
    }
    else
    {
        getPlayer()->BajarVelocidadX();

    }
    if(!colision )
    {
        if(getPlayer()->getVy() == 0)
        {
            getPlayer()->setVy(getPlayer()->getVy() + 100);
        }
    }


    next_x += getPlayer()->getVx();
    getPlayer()->setPos(next_x,next_y);
    EvaluaColisionMovimiento();
    EvaluaColisionPoderes();
}




