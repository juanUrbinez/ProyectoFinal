#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_window();
    generar_mapa();
    refreshTimer = new QTimer(this);
    connect(refreshTimer,SIGNAL(timeout()),this,SLOT(ActualizarPosicionPersonaje()));
    refreshTimer->start(1000/60);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete player;
    refreshTimer->stop();

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
    player->setPos(500,500);
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
        qDebug()<<"enttro";
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


void MainWindow::EvaluaColision()
{
    int next_x = getPlayer()->x();
    int next_y = getPlayer()->y();



    bool colision=false;

    escenario *BloqueColision;

    QList<escenario*>plataformasColicion;

    QList<escenario*>::Iterator it;
    for (it=plataformas.begin();it!=plataformas.end() ;it++ )
    {
        if ((*it)->collidesWithItem(player))
        {
            //getPlayer()->setVx(0);
            plataformasColicion.append(*it);
            colision=true;

        }
    }

    if (colision)
    {
        QList<escenario*>::Iterator it;
        for (it=plataformas.begin();it!=plataformas.end() ;it++ )
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
            if( getPlayer()->y() + getPlayer()->getHeight() - 1 <= (*it)->y())
            {
                cArriba = true;
            }


            if( getPlayer()->x() + getPlayer()->getWidth() <= (*it)->x())
            {
                cIzquierda = true;
            }

            if( getPlayer()->x() >= (*it)->x() + (*it)->getWidth() )
            {
                cDerecha = true;
            }
            ////
            //qDebug()<<"izquierda: " << cIzquierda;
            //qDebug()<<"derecha: " << cDerecha;
            qDebug()<<"arriba: " << cArriba;


            if(cArriba)
            {
                next_y = bloc_y - getPlayer()->getHeight() ;
                getPlayer()->setVy(0);
            }


            else if(cDerecha)
            {
                next_x = bloc_x + getPlayer()->getWidth()+1;
                getPlayer()->setVx(0);
                //qDebug() <<"1" <<next_x;


            }
            else if(cIzquierda)
            {
                next_x = bloc_x - getPlayer()->getWidth()+1;
                getPlayer()->setVx(0);
                //qDebug() << "Posicion x"<< next_x <<" Bloque "<<(*it)->getWidth() ;
                //qDebug() <<"2" <<next_x;
            }



        }
        qDebug()<<next_x;
        getPlayer()->setPos(next_x,next_y);
        plataformasColicion.pop_back();
    }



}


void MainWindow::ActualizarPosicionPersonaje()
{
    getPlayer()->ActualizarMovimiento();

    int next_x = getPlayer()->x();
    int next_y = getPlayer()->y();


    if(getPlayer()->getEnElAire() == true)
    {
        qDebug()<<"enttro2";
        next_y += getPlayer()->getVy() * 1/60;
        float dt = 1/(float)60;
        getPlayer()->setVy( getPlayer()->getVy() + 200 * 10 * dt);
    }


    if(getPlayer()->getMoviendo_Derecha())
    {
        getPlayer()->AumentarVelocidadDerecha();
         //player->setPos(500,500);

    }
    else if(getPlayer()->getMoviendo_Izquierda())
    {
        getPlayer()->AumentarVelocidadIzquierda();
         //player->setPos(500,500);
    }
    else
    {
        getPlayer()->BajarVelocidadX();

    }
    next_x += getPlayer()->getVx();
    getPlayer()->setPos(next_x,next_y);
    EvaluaColision();


}

personaje *MainWindow::getPlayer() const
{
    return player;

}


