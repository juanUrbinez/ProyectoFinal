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

   //setGeometry(0,0,1002,1002);
    ui->graphicsView->setGeometry(0,0,1900,1005);
    menu->setSceneRect(0,0,1898,1003);
    menu->setBackgroundBrush(QImage(":/escenario/escenario/option.png").scaled(1550,820));
    ui->graphicsView->setScene(menu);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));

    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Mov_per()));
    tempo=new QTimer;
    connect(tempo,SIGNAL(timeout()),this,SLOT(temporizador()));
    //timfis=new QTimer;
    //connect(timfis,SIGNAL(timeout()),this,SLOT(simulacion()));


    ui->inicio->setGeometry(600,200,120,80);
    ui->salir->setGeometry(600,350,120,80);

    ui->partida->hide();
    ui->anterior->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->lcdNumber->hide();
    ui->monedas->hide();
    ui->aceptar->hide();
    ui->nivel->hide();

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

void MainWindow::set_window()
{
    ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
    scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
    setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
}

void MainWindow::generar_mapa()
{

    jugador();

    for(int i=0;i<14;i++){
        for(int j=0;j<50;j++){
            if(nivel1[i][j]==1){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro"));
                scene->addItem(plataforma.last());
            }
            else if(nivel1[i][j]==2){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma"));
                scene->addItem(plataforma.last());
            }
            else if(nivel1[i][j]==3){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                scene->addItem(plataforma.last());
            }
            else if(nivel1[i][j]==4){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                scene->addItem(plataforma.last());
            }
            else if(nivel1[i][j]==6){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                scene->addItem(plataforma.last());
            }
        }        
    }

    time->start(player->Vel_mov);
    tempo->start(1000);
    ui->lcdNumber->display(30);

}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    tecla=i->key();
}

void MainWindow::jugador()
{
    player=new personaje(tam,14*tam);
    //ui->graphicsView->translate(player->x(),0);
    //scene->setFocusItem(player);
    //player->setFlag(QGraphicsItem::ItemIsFocusable);
    //player->setFocus();
   // player->setPos(tam,14*tam);
    scene->addItem(player);
     //player->focusItem();

}


/*bool MainWindow::colisiones(QGraphicsItem *item, QGraphicsItem *item2){
    QList<QGraphicsItem *> coll=scene->collidingItems(item);
    if(coll.count(item2)>0){
        return true;
    }
    else return false;

}*/

void MainWindow::temporizador()
{//se puede modificar cuando se tenga las escenas de muerte del personaje
    if(ui->lcdNumber->intValue()==0){
        scene->removeItem(player);
        generar_mapa();
        ui->lcdNumber->display(30);
        scene->addItem(player);
    }
    else{
     ui->lcdNumber->display((ui->lcdNumber->intValue())-1);
    }
}

void MainWindow::Mov_per()
{
    int X=player->x(),Y=player->y();
    int monedas=player->monedas;
    ui->monedas->display(monedas);
    if(player->live){

        if(tecla==Qt::Key_A && nivel1[(Y/tam)-2][(X-8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]==0){
            player->cambio_imagen('a');
            player->sprite++;
            player->setX(player->x()-8);
            player->posicion(player->x(),player->y());

        }
        else if(tecla==Qt::Key_D && nivel1[(Y/tam)-2][(X+tam-1+8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X+tam-1+8)/tam]==0){
            player->cambio_imagen('d');
            player->sprite++;
            player->setX(player->x()+8);
            player->posicion(player->x(),player->y());

        }
        if(tecla==Qt::Key_S && nivel1[((Y+tam-1+8)/tam)-2][(X+tam-1)/tam]==0 && nivel1[((Y+tam-1+8)/tam)-2][X/tam]==0){
            player->cambio_imagen('s');
            player->setY(player->y()+8);
        }
        else if(tecla==Qt::Key_W && nivel1[((Y-8)/tam)-2][X/tam]==0 && nivel1[((Y-8)/tam)-2][(X+tam-1)/tam]==0){
            player->cambio_imagen('w');
            player->setY(player->y()-8);
        }

        tecla=0;
        time->start(player->Vel_mov);

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
    ui->anterior->setGeometry(600,300,120,80);
    ui->partida->setGeometry(600,200,120,80);
    ui->inicio->hide();
    ui->salir->hide();

    ui->graphicsView->setGeometry(0,0,1900,1005);
    option->setSceneRect(0,0,1898,1003);
    option->setBackgroundBrush(QImage(":/escenario/escenario/menu.png").scaled(1550,820));
    ui->graphicsView->setScene(option);
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
    ui->aceptar->setGeometry(450,300,400,120);

    datos=new registro(0);
    datos->show();

}


void MainWindow::on_aceptar_clicked()
{
    if(datos->correcto){

        ui->label->show();
        ui->label_2->show();
        ui->lcdNumber->show();
        ui->monedas->show();
        ui->aceptar->hide();
        ui->nivel->show();
        ui->graphicsView->setScene(scene);

        set_window();
        generar_mapa();
    }

}





void MainWindow::on_nivel_clicked()
{
    niveles *level= new niveles(0);
    level->show();
    hide();
}


