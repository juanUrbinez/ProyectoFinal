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
    refreshTimer = new QTimer();



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
{   if(MAPA==1)
    {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
    }
    if(MAPA==2)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene2);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
        setWindowTitle("Poison Run");
        setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
        }
    if(MAPA==3)
        {
        ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
        ui->graphicsView->setScene(scene3);
        ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
        scene->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
        setFixedSize(tam*50+2,tam*(14+2)+2);
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
    //act->start(10);
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


    tempo->start(1000);
    ui->lcdNumber->display(10);

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
        generar_mapa(variable);
        ui->lcdNumber->display(10);
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

            //qDebug()<<bloc_y;

            bool cArriba = false;
            bool cAbajo = false;
            bool cDerecha = false;
            bool cIzquierda = false;


            ////
//            qDebug()<<"cArriba "<<getPlayer()->y()<<" "<<bloc_y;
//            qDebug()<<"cAbajo "<<getPlayer()->y()<<" "<<bloc_y;
            if( getPlayer()->y()+1<= bloc_y)
            {
                cArriba = true;//qDebug()<<"cArriba: "<<cArriba;
            }

            if( getPlayer()->y() >= bloc_y)
                cAbajo = true;//qDebug()<<"cAbajo: "<<cAbajo;

            if( getPlayer()->x() > bloc_x )
            {
                cDerecha = true;//qDebug()<<"cDerecha: "<<cDerecha;
            }
            if( getPlayer()->x()<= bloc_x)
            {
                cIzquierda = true;//qDebug()<<"cIzquierda: "<<cIzquierda;
            }
            if(bloc_y - getPlayer()->y()< 50)
            {
                getPlayer()->setRebotando(true);
            }
            //qDebug()<<bloc_y<<" "<<getPlayer()->y();
            //qDebug()<<getPlayer()->getRebotando();


            ////
            //qDebug()<<"izquierda: " << cIzquierda;
            //qDebug()<<"derecha: " << cDerecha;

            //qDebug()<<"arriba: " << cArriba;

            if(cArriba && !cAbajo)
            {
                next_y = bloc_y - 40+1;
                getPlayer()->setVy(0);
            }

            else if (cAbajo && getPlayer()->getEnElAire())
            {

                next_y = bloc_y + 40 ;
                //qDebug()<<"2- "<<next_y<<" "<<bloc_y;
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
                //qDebug() <<"1" <<next_x;


            }
        }
        getPlayer()->setPos(next_x,next_y);
        plataformasColicion.pop_back();

    }



}

void MainWindow::EvaluaColisionPoderes()
{
    for(int i=0;i<plataforma.size();i++)
    {
        if(plataforma.at(i)->getClase() == "moneda" && plataforma.at(i)->collidesWithItem(player))
        {

        getPlayer()->monedas=100;
        cantidad+=getPlayer()->monedas;

        scene->removeItem(plataforma.at(i));
        scene2->removeItem(plataforma.at(i));
        scene3->removeItem(plataforma.at(i));
        plataforma.removeAt(i);
        }
        if(plataforma.at(i)->getClase() == "orbe" && plataforma.at(i)->collidesWithItem(player))
        {

            scene->removeItem(plataforma.at(i));
            scene2->removeItem(plataforma.at(i));
            scene3->removeItem(plataforma.at(i));
            plataforma.removeAt(i);
            ui->lcdNumber->display((ui->lcdNumber->intValue())+5);
        }
        if(plataforma.at(i)->getClase() == "puerta" && plataforma.at(i)->collidesWithItem(player))
        {
            scene->removeItem(player);
            plataforma.clear();
            plataformas.clear();
            variable++;
            generar_mapa(variable);
            set_window(variable);




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
        ui->graphicsView->setScene(scene);

        set_window(variable);
        generar_mapa(variable);
        connect(refreshTimer,SIGNAL(timeout()),this,SLOT(ActualizarPosicionPersonaje()));
        refreshTimer->start(1000/60);

        //connect(act,SIGNAL(timeout()),this,SLOT(disparocanon()));
    }


//    set_window();
//    generar_mapa();


}

void MainWindow::disparoCanon()
{
    qDebug()<<"entra";

    if(estado!=0)
    {
        estado-=1;
    }
        if(est_dis!=0)
        {
            est_dis-=1;
        }



                shoot.push_back(new disparo);
                shoot.back()->posx=4*tam;
                shoot.back()->posy=8*tam;
                shoot.back()->setPos(shoot.back()->posx,shoot.back()->posy);



                est_dis = 800;


         scene2->addItem(shoot.back());

        for(int e=0; e<shoot.size(); e++){

                if(getPlayer()->x()<shoot[e]->posx){
                    shoot[e]->posx -= 0.6 * 1;
                    shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

                }
                else if(getPlayer()->x() > shoot[e]->posx){
                    shoot[e]->posx += 0.6 * 1;
                    shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

                }
                if(40 + getPlayer()->y() < shoot[e]->posy){
                    shoot[e]->posy -= 0.6 * 1;
                    shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

                }

                else if (40 + getPlayer()->y() > shoot[e]->posy){
                    shoot[e]->posy += 0.6 * 1;
                    shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

                }

                if (shoot[e]->collidesWithItem(getPlayer())){
                    scene2->removeItem(shoot[e]);
                    shoot.removeAt(e);
                    //scena->removeItem(jugador);
                    //generar_nivel2();
                }
                else{
    //                scena->removeItem(shoot[0]);
    //                shoot.removeAt(0);

                }
            }
    }




personaje *MainWindow::getPlayer() const
{
    return player;

}

void MainWindow::ActualizarPosicionPersonaje()
{
    ui->monedas->display(cantidad);

    //getPlayer()->setRebotando(false);

    //getPlayer()->ActualizarMovimiento();
    int next_x = getPlayer()->x();
    int next_y = getPlayer()->y();

        //qDebug()<<"en el aire "<<getPlayer()->getEnElAire();
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

    }
    if(!colision )
    {
        qDebug()<<"entra";
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



