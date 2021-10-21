#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_window();
    generar_mapa();
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
    player = new personaje();
    player->setPos(100,500);
    scene->addItem(player);
    for(int i=0;i<14;i++){
        for(int j=0;j<50;j++){
            if(nivel1[i][j]==1){
                plataformas.push_back(new escenario());
                plataformas.back()->CambiarOriginal(":/escenario/escenario/muro1.png");
                plataformas.back()->set_scale(tam,tam);
                plataformas.back()->set_imagen(0);
                plataformas.back()->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataformas.back());
            }
            else if(nivel1[i][j]==2){
                plataformas.push_back(new escenario());
                plataformas.back()->CambiarOriginal(":/escenario/escenario/muro1.png");
                plataformas.back()->set_scale(tam,tam);
                plataformas.back()->set_imagen(0);
                plataformas.back()->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataformas.back());

            }
        }        
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        Mover_A_Derecha(true);
    }
    else if (event->key() == Qt::Key_Right)
    {
        //Mover_A_Izquierda(true);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

}

bool MainWindow::EvaluaColision()
{
    bool colision=false;
    QList<escenario*>::Iterator it;
    for (it=plataformas.begin();it!=plataformas.end() ;it++ )
    {
        if ((*it)->collidesWithItem(player))
        {
            colision=true;
        }
    }

    return colision;


}
