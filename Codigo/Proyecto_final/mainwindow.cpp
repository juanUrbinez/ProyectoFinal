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
                //plataformas.back()->CambiarOriginal(":/escenario/escenario/muro1.png");
                //plataformas.back()->set_scale(tam,tam);
                //plataformas.back()->set_imagen(0);
                plataformas.back()->setPos(j*tam,(2+i)*tam);
                scene->addItem(plataformas.back());
            }
            else if(nivel1[i][j]==2){
                plataformas.push_back(new escenario());
//                plataformas.back()->CambiarOriginal(":/escenario/escenario/muro1.png");
//                plataformas.back()->set_scale(tam,tam);
//                plataformas.back()->set_imagen(0);
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

            //qDebug()<<bloc_y;

            bool cArriba = false;
            bool cAbajo = false;
            bool cDerecha = false;
            bool cIzquierda = false;

            ////
            qDebug()<<"cArriba "<<getPlayer()->y()<<" "<<bloc_y;
            qDebug()<<"cAbajo "<<getPlayer()->y()<<" "<<bloc_y;
            if( getPlayer()->y()<= bloc_y)
            {
                cArriba = true;qDebug()<<"cArriba: "<<cArriba;
            }

            if( getPlayer()->y() >= bloc_y)
                cAbajo = true;qDebug()<<"cAbajo: "<<cAbajo;

            if( getPlayer()->x() > bloc_x )
            {
                cDerecha = true;qDebug()<<"cDerecha: "<<cDerecha;
            }
            if( getPlayer()->x()<= bloc_x)
            {
                cIzquierda = true;qDebug()<<"cIzquierda: "<<cIzquierda;
            }


            ////
            //qDebug()<<"izquierda: " << cIzquierda;
            //qDebug()<<"derecha: " << cDerecha;

            //qDebug()<<"arriba: " << cArriba;


            if(cArriba && !cAbajo)
            {
                next_y = bloc_y - 40;
                getPlayer()->setVy(0);

            }

            else if (cAbajo && getPlayer()->getEnElAire())
            {

                next_y = bloc_y + 40 ;
                qDebug()<<"2- "<<next_y<<" "<<bloc_y;
                getPlayer()->setVy(  - getPlayer()->getVy() );

            }

            else if(cIzquierda)
            {
                next_x = bloc_x - getPlayer()->getWidth();
                getPlayer()->setVx(0);
            }
            else if(cDerecha)
            {
                next_x = bloc_x + getPlayer()->getWidth();
                getPlayer()->setVx(0);
                //qDebug() <<"1" <<next_x;


            }
        }
        qDebug()<<plataformasColicion.count();
        //qDebug()<<next_x;
        getPlayer()->setPos(next_x,next_y);
        plataformasColicion.pop_back();

    }



}


void MainWindow::ActualizarPosicionPersonaje()
{
    EvaluaColision();
    //getPlayer()->ActualizarMovimiento();
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
//        if(!colision)
//        {
//            if(getPlayer()->getVy() == 0)
//                getPlayer()->setVy(getPlayer()->getVy() + 100);
//        }
    }
    next_x += getPlayer()->getVx();
    getPlayer()->setPos(next_x,next_y);
    //EvaluaColision();





}

personaje *MainWindow::getPlayer() const
{
    return player;

}


