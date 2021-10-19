#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Mov_per()));
    tempo=new QTimer;
    connect(tempo,SIGNAL(timeout()),this,SLOT(temporizador()));

    set_window();
    generar_mapa();
    //jugador();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete time;
    delete tempo;
    delete player;
}

void MainWindow::set_window()
{
    scene = new QGraphicsScene;

    ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
    scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamanio de la escena
    setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");

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
    //int X=player->x(),Y=player->y();
    //int monedas=player->monedas;
    //ui->monedas->display(monedas);
    tecla=i->key();
   // if(player->live){
        //for(int k=0;k<plataforma.size();k++){
       // if(tecla==Qt::Key_A && nivel1[(Y/tam)-2][(X-8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]==0){
           // player->cambio_imagen('a');
           //player->sprite++;
            //player->setX(player->x()-8);
            //player->posicion(player->x(),player->y());


            /*if(nivel1[(Y/tam)-2][(X-8)/tam]==4 && nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]==4 && plataforma.at(k)->getClase()=="moneda" && plataforma.at(k)->collidesWithItem(player)){
                player->monedas+=100;
                scene->removeItem(plataforma.at(k));
                plataforma.removeAt(k);
                nivel1[(Y/tam)-2][(X-8)/tam]=0;
                nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]=0;

            }*/
       // }
        /*else if(tecla==Qt::Key_D && nivel1[(Y/tam)-2][(X+tam-1+8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X+tam-1+8)/tam]==0){
            player->cambio_imagen('d');
            player->sprite++;
            player->setX(player->x()+8);
            player->posicion(player->x(),player->y());
        }
        else if(tecla==Qt::Key_J){
            player->cambio_imagen('j');
            player->salto();*/
       // }
        //}
        //time->start(player->Vel_mov);
   // }
    /*else{
        time->start(400);
        scene->removeItem(player);
        time->stop();
    }*/
}

void MainWindow::jugador()
{
    player=new personaje(tam,14*tam);
   // player->setPos(tam,14*tam);
    scene->addItem(player);
    //if(ui->lcdNumber->intValue()==0) scene->removeItem(player);
}

void MainWindow::colision()
{
    //int X=player->x(),Y=player->y();
   //for (int f=0;f<14;f++){
        //for (int c=0;c<50;c++){
            for(int i=0;i<plataforma.size();i++){
                //scene->items().count(plataforma.at(i));
                //if(colisiones(scene->items().count(plataforma.at(i)->getClase()=="moneda"),player)){
                if(plataforma.at(i)->getClase()=="moneda" && plataforma.at(i)->collidesWithItem(player)){
                    player->monedas+=100;
                    scene->removeItem(plataforma.at(i));
                    plataforma.removeAt(i);
                    //nivel1[f][c]=0;
                    //nivel1[(Y/tam)-2][(X-8)/tam]=0;
                    //nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]=0;
                    /*if(nivel1[(Y/tam)-2][(X-8)/tam]==4 && nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]==4){
                        nivel1[X][Y]=0;
                    }*/
                }
                else if( plataforma.at(i)->collidesWithItem(player) && plataforma.at(i)->getClase()=="orbe"){
                    ui->lcdNumber->display((ui->lcdNumber->intValue())+20);
                    scene->removeItem(plataforma.at(i));
                }
            }

       //}
    //}

}

bool MainWindow::colisiones(QGraphicsItem *item, QGraphicsItem *item2){
    QList<QGraphicsItem *> coll=scene->collidingItems(item);
    if(coll.count(item2)>0){
        return true;
    }
    else return false;

}

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
        else if(tecla==Qt::Key_J){
            player->cambio_imagen('j');
            player->salto();
        }
        time->start(player->Vel_mov);

    }
}

/*void MainWindow::timeEvent(QTimerEvent i)
{
    if(Qt::Key_J){
        player->cambio_imagen('j');
        player->salto();
    }
}*/

//void MainWindow::simulacion()
//{
    /*bool saltando=true;
    int prog_salto=0;
    int dur_salto=1000;
    int X=player->x(),Y=player->y();//no me sirven para la posicion en salto()
    if(tecla==Qt::Key_M){
        if(saltando){
            prog_salto+=100;
            if(prog_salto>dur_salto){
                prog_salto=dur_salto;
            }
        }
        //player->salto(X,Y);

        x = X+vxo*n*(0.001*T);
        y = Y+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);

        player->setPos(int(x),int(ui->graphicsView->height()-y-player->get_h()));//invierte eje y
        n++;

        if(prog_salto==dur_salto){
            prog_salto=0;
            saltando=false;
        }
       // time->start(player->Vel_mov);
    }
    time->stop();
    //tecla=0;
    //time->start(player->Vel_mov);*/
//}

//mov parabolico

/*MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=ui->graphicsView->height();
    setup_scene();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete p;
    delete time;
}

void MainWindow::setup_scene()
{
    scene = new QGraphicsScene;
    p = new pelota(50,50);
    time = new QTimer;

    ui->iniciar->setEnabled(false);
    ui->parar->setEnabled(false);

    connect(time,SIGNAL(timeout()),this,SLOT(simulacion()));

    scene->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
}

void MainWindow::simulacion()
{
    float x,y;

    x = xo+vxo*n*(0.001*T);
    y = yo+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);

    p->setPos(int(x),int(h-y-p->get_h()));//invierte eje y
    n++;
}*/
