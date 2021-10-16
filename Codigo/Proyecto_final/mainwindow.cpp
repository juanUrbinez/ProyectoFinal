#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_window();
    generar_mapa();
    jugador();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    for(int i=0;i<14;i++){
        for(int j=0;j<50;j++){
            if(nivel1[i][j]==1){
                plataforma=new escenario();
                plataforma->CambiarOriginal(":/escenario/escenario/muro1.png");
                plataforma->set_scale(tam,tam);
                plataforma->set_imagen(0);
                plataforma->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataforma);
            }
            else if(nivel1[i][j]==2){
                plataforma=new escenario();
                plataforma->CambiarOriginal(":/escenario/escenario/muro1.png");
                plataforma->set_scale(tam,tam);
                plataforma->set_imagen(0);
                plataforma->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataforma);

            }
            else if(nivel1[i][j]==3){
                plataforma=new escenario();
                plataforma->CambiarOriginal(":/escenario/Bonos/orbes de energia.png");
                plataforma->set_scale(tam,tam);
                plataforma->set_orbe(0);
                plataforma->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataforma);
            }
            else if(nivel1[i][j]==4){
                plataforma=new escenario();
                plataforma->CambiarOriginal(":/escenario/Bonos/moneda.png");
                plataforma->set_scale(tam,tam);
                plataforma->set_money(0);
                plataforma->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataforma);
            }
        }        
    }
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    int X=player->x(),Y=player->y();
    if(player->live){
        if(i->key()==Qt::Key_A && nivel1[(Y/tam)-2][(X-8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X-8)/tam]==0){
            player->cambio_imagen('a');
            player->sprite++;
            player->setX(player->x()-8);
        }
        else if(i->key()==Qt::Key_D && nivel1[(Y/tam)-2][(X+tam-1+8)/tam]==0 && nivel1[((Y+tam-1)/tam)-2][(X+tam-1+8)/tam]==0){
            player->cambio_imagen('d');
            player->sprite++;
            player->setX(player->x()+8);
        }
    }
}

void MainWindow::jugador()
{
    player=new personaje();
    player->setPos(tam,14*tam);
    scene->addItem(player);
}

bool MainWindow::colisiones(QGraphicsItem *item, QGraphicsItem *item2){
    QList<QGraphicsItem *> coll=scene->collidingItems(item);
    if(coll.count(item2)>0){
        return true;
    }
    else return false;

}
