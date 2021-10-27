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
    //login = new QGraphicsScene;

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




    ui->inicio->setGeometry(600,200,100,40);
    ui->salir->setGeometry(600,300,100,40);
   // ui->newpartida->hide();
    ui->partida->hide();
    ui->anterior->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->lcdNumber->hide();
    ui->monedas->hide();
    ui->aceptar->hide();
    ui->nivel->hide();


   // ui->salir->setStyleSheet("font: 75 18pt ;color: rgb(80,170,58);");
    //QPalette::button(1);
    //ui->salir->setBackgroundRole(ui->salir(1));
    /*QPixmap pixmap(":/escenario/escenario/menu.png");
    QIcon ButtonIcon(pixmap);
    ui->salir->setIcon(ButtonIcon);
    ui->salir->setIconSize(pixmap.rect().size());*/ //pone al boton igual al icon, no se ve la letra
    //jugador();

    //set_window();
    //generar_mapa();
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
    //delete login;
}

void MainWindow::set_window()
{
   // w_limit=0;
    ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
    scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
    setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));


    //generar_mapa();
    //ventana  nueva
   //now=new QMainWindow(this);
    //login=new QGraphicsScene; ya

   // news=new QGraphicsView(login,now);
   // news->setGeometry(0,0,tam*20,tam*20);

    //ventana emergente
    //now->setGeometry(100,200,50,50);
   // now->show();


}

void MainWindow::generar_mapa()
{
    player = new personaje();
    player->setPos(tam+40,13*tam);
    scene->addItem(player);

    for(int i=0;i<14;i++){
        for(int j=0;j<50;j++){
            if(nivel1[i][j]==1){
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
            else if(nivel1[i][j]==6){
                plataforma.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                scene->addItem(plataforma.last());
            }
        }        
    }

    tempo->start(1000);
    ui->lcdNumber->display(30);

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




void MainWindow::on_anterior_clicked()
{
    ui->graphicsView->setScene(menu);
    ui->partida->hide();
    ui->anterior->hide();
    ui->inicio->show();
    ui->salir->show();
}


/*void MainWindow::on_siguiente_clicked()
{
    ui->graphicsView->setScene(scene);

}*/


void MainWindow::on_inicio_clicked()
{
    ui->anterior->show();
    ui->partida->show();
    ui->anterior->setGeometry(600,250,100,40);
    ui->partida->setGeometry(600,200,100,40);
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
    ui->aceptar->setEnabled(false);
   /* ui->label->show();
    ui->label_2->show();
    ui->lcdNumber->show();
    ui->monedas->show();


    ui->graphicsView->setScene(scene);

    set_window();
    generar_mapa();*/

    registro *datos=new registro(0);
    datos->show();
 //on_aceptar_clicked();

    if(datos->get_verif()){
        ui->aceptar->setEnabled(true);
    }

    /*if(datos->correcto){
        ui->label->show();
        ui->label_2->show();
        ui->lcdNumber->show();
        ui->monedas->show();


        ui->graphicsView->setScene(scene);

        set_window();
        //generar_mapa();
    }*/
   /* ui->label->show();
    ui->label_2->show();
    ui->lcdNumber->show();
    ui->monedas->show();
    ui->graphicsView->setScene(scene);*/
   // ui->graphicsView->setScene(login);

    //set_window();
    //generar_mapa();

    //ventana  nueva
   //now=new QMainWindow(this);
    //login=new QGraphicsScene; ya

    //news=new QGraphicsView(login,now);
    //news->setGeometry(0,0,tam*20,tam*20);

    //ventana emergente
    //now->setGeometry(600,600,500,500);
    //now->show();



}


/*void MainWindow::on_cancelar_clicked()
{
    //close();
    ui->graphicsView->setScene(option);
    ui->partida->show();
    ui->anterior->show();
    ui->aceptar->hide();
    ui->cancelar->hide();
    ui->login->hide();
    ui->password->hide();
    ui->contrasena->hide();
    ui->usuario->hide();

    //ui->inicio->show();
    //ui->salir->show();
}
*/

void MainWindow::on_aceptar_clicked()
{
    ui->label->show();
    ui->label_2->show();
    ui->lcdNumber->show();
    ui->monedas->show();
    ui->aceptar->hide();
    ui->nivel->show();
    ui->graphicsView->setScene(scene);

    set_window();
    generar_mapa();

    refreshTimer = new QTimer(this);
    connect(refreshTimer,SIGNAL(timeout()),this,SLOT(ActualizarPosicionPersonaje()));
    refreshTimer->start(1000/60);



}


personaje *MainWindow::getPlayer() const
{
    return player;

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


void MainWindow::on_nivel_clicked()
{
    niveles *level= new niveles(0);
    level->show();
}

