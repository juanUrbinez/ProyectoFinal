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
    timfis=new QTimer;
    connect(timfis,SIGNAL(timeout()),this,SLOT(simulacion()));


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
    delete timfis;
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
   // player->setPos(tam,14*tam);
    scene->addItem(player);
    //if(ui->lcdNumber->intValue()==0) scene->removeItem(player);
     //player->focusItem();

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

                //if(plataforma.at(i)->getClase()=="moneda" && player->collidesWithItem(plataforma.at(i))){
                    player->monedas+=100;
                    scene->removeItem(plataforma.at(i));
                    plataforma.removeAt(i);

                    //nivel1[f][c]=0;
                    //plataforma.clear();
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
            ui->graphicsView->focusWidget();
        }
        else if(tecla==Qt::Key_Space){
            player->cambio_imagen('j');
            //timfis->start(player->Vel_mov);
           // player->salto();
           //player->MRU(player->x(),player->Vel_mov);
            //player->lan_very(player->y()+12*tam,player->Vel_mov);
            //player->caida_libre(player->y());
           // player->setY(player->y()-3*tam);
           // Py=-player->y()-(0.5*g*T*T);
            //player->Vel_mov=g*T;
            //player->setY(Py);
            simulacion();
        }
        tecla=0;
        time->start(player->Vel_mov);

        /*if(player->get_Py()+22>(w_limit+2002)/2 && player->get_Px()<4000){
            w_limit+=2002/2;
            player->posicion(player->x()+60,player->y());
            scene->setSceneRect(w_limit,0,tam*50+2,tam*(14+2)+2);
        }
        else if(player->get_Px()-22<w_limit && player->get_Px()>200){
           w_limit-=2002/2;
           player->posicion(player->x()-60,player->y());
           scene->setSceneRect(w_limit,0,tam*50+2,tam*(14+2)+2);
        }*/

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


void MainWindow::simulacion()//no funciona
{
    float x,y;
   // player->setY(player->y()-3*tam);
    int xo=player->x(),yo=player->y() ;
    vxo=50;
    vyo=-50;


        x = xo+vxo*cos(45)*(0.1*T);
    //x=xo+vxo*(0.01*T);
        y = yo+vyo*sin(45)*(0.1*T)+0.5*g*(0.1*T)*(0.1*T);
       // T++;
    //y=yo+0.5*g*(0.1*T)*(0.01*T);
    //x=xo;

        /*if(y>player->y()-3*tam){
            vxo=-50;
            vyo=50;
            y = yo+vyo*sin(45)*(0.1*T)-0.5*g*(0.1*T)*(0.1*T);
        }*/
        //yo=player->y();

        player->setPos(int(x),int(y));
        //n++;

    timfis->stop();

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


    ui->graphicsView->setScene(scene);

    set_window();
    generar_mapa();
}




