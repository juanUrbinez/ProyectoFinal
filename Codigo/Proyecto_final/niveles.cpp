#include "niveles.h"
#include "ui_niveles.h"

niveles::niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::niveles)
{
    ui->setupUi(this);

    scena=new QGraphicsScene;
    segundo=new QGraphicsScene;


    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(temporizador()));
    time=new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(tempor()));
    mov1=new QTimer;
    connect(mov1,SIGNAL(timeout()),this,SLOT(Movim_per2()));
    mov2=new QTimer;
    connect(mov2,SIGNAL(timeout()),this,SLOT(Movim_per3()));
    act=new QTimer;
    connect(act,SIGNAL(timeout()),this,SLOT(actualizar()));



    set_widow();
    generar_nivel2();

    ui->temp->hide();
}

niveles::~niveles()
{
    delete ui;
    delete scena;
    delete segundo;
    delete timer;
    delete mov1;
    delete mov2;
    delete act;
    //delete shoot;
}

void niveles::temporizador()
{
    if(ui->lcdNumber->intValue()==0){
        scena->removeItem(jugador);
        generar_nivel2();
        ui->lcdNumber->display(30);
        scena->addItem(jugador);

    }
    else{
     ui->lcdNumber->display((ui->lcdNumber->intValue())-1);
    }
}

void niveles::tempor()
{
     if(ui->temp->intValue()==0){
         segundo->removeItem(jug);
         generar_nivel3();
         ui->temp->display(30);
         segundo->addItem(jug);
     }
     else{
      ui->temp->display((ui->temp->intValue())-1);
     }
}

void niveles::generar_nivel2()
{
    play();
    for(int i=0;i<14;i++){
           for(int j=0;j<50;j++){
               if(nivel2[i][j]==1){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro2"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==2){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma2"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==3){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==4){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==6){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==7){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==8){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                   scena->addItem(platafor.last());
               }
               else if(nivel2[i][j]==11){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                   scena->addItem(platafor.last());
               }

          }
       }
    timer->start(1000);
    mov1->start(jugador->Vel_mov);
    ui->lcdNumber->display(30);
    act->start(10);
}

void niveles::generar_nivel3()
{
    play2();
    for(int i=0;i<14;i++){
           for(int j=0;j<50;j++){
               if(nivel3[i][j]==1){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"muro3"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==2){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"plataforma3"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==3){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"orbe"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==4){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"moneda"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==6){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"puerta"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==7){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==8){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"zonaM"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==11){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==12){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"item2"));
                   segundo->addItem(platafor.last());
               }
               else if(nivel3[i][j]==13){
                   platafor.push_back(new escenario(j*tam,(2+i)*tam,tam,tam,"torreta2"));
                   segundo->addItem(platafor.last());
               }
          }
       }
    time->start(1000);
    mov2->start(jug->Vel_mov);
    ui->temp->display(30);

}

void niveles::keyPressEvent(QKeyEvent *i)
{
    press=i->key();
}

void niveles::set_widow()
{
    ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
    ui->graphicsView->setScene(scena);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
    scena->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
    setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
}

void niveles::set_widow2()
{
    ui->graphicsView->setGeometry(0,0,tam*50+2,tam*(14+2)+2);
    ui->graphicsView->setScene(segundo);
    ui->graphicsView->setBackgroundBrush(QImage(":/escenario/escenario/escenario.png").scaled(tam*50,tam*(14+2)));
    segundo->setSceneRect(0,0,tam*50,tam*(14+2));//tamaño de la escena
    setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
    setWindowIcon(QIcon(":/personaje/Personaje/icon.png"));
}

void niveles::Movim_per2()
{
    int X=jugador->x(),Y=jugador->y();
    int monedas=jugador->monedas;
    ui->monedas->display(monedas);
    if(jugador->live){

        if(press==Qt::Key_A && nivel2[(Y/tam)-2][(X-8)/tam]==0 && nivel2[((Y+tam-1)/tam)-2][(X-8)/tam]==0 ){
            jugador->cambio_imagen('a');
            jugador->sprite++;
            jugador->setX(jugador->x()-8);
            jugador->posicion(jugador->x(),jugador->y());
        }
        else if(press==Qt::Key_D && nivel2[(Y/tam)-2][(X+tam-1+8)/tam]==0 && nivel2[((Y+tam-1)/tam)-2][(X+tam-1+8)/tam]==0){
            jugador->cambio_imagen('d');
            jugador->sprite++;
            jugador->setX(jugador->x()+8);
           jugador->posicion(jugador->x(),jugador->y());
            ui->graphicsView->focusWidget();
        }
        if(press==Qt::Key_S && nivel2[((Y+tam-1+8)/tam)-2][(X+tam-1)/tam]==0 && nivel2[((Y+tam-1+8)/tam)-2][X/tam]==0){
            jugador->cambio_imagen('s');
            jugador->setY(jugador->y()+8);
        }
        else if(press==Qt::Key_W && nivel2[((Y-8)/tam)-2][X/tam]==0 && nivel2[((Y-8)/tam)-2][(X+tam-1)/tam]==0){
            jugador->cambio_imagen('w');
            jugador->setY(jugador->y()-8);
        }

        press=0;
        mov1->start(jugador->Vel_mov);


    }
}

void niveles::Movim_per3()
{
    int X=jug->x(),Y=jug->y();
    int monedas=jug->monedas;
    ui->monedas->display(monedas);
    if(jug->live){
        if(press==Qt::Key_A && nivel3[(Y/tam)-2][(X-8)/tam]==0 && nivel3[((Y+tam-1)/tam)-2][(X-8)/tam]==0 ){
            jug->cambio_imagen('a');
            jug->sprite++;
            jug->setX(jug->x()-8);
            jug->posicion(jug->x(),jug->y());
        }
        else if(press==Qt::Key_D && nivel3[(Y/tam)-2][(X+tam-1+8)/tam]==0 && nivel3[((Y+tam-1)/tam)-2][(X+tam-1+8)/tam]==0){
            jug->cambio_imagen('d');
            jug->sprite++;
            jug->setX(jug->x()+8);
           jug->posicion(jug->x(),jug->y());
            ui->graphicsView->focusWidget();
        }
        if(press==Qt::Key_S && nivel3[((Y+tam-1+8)/tam)-2][(X+tam-1)/tam]==0 && nivel3[((Y+tam-1+8)/tam)-2][X/tam]==0){
            jug->cambio_imagen('s');
            jug->setY(jug->y()+8);
        }
        else if(press==Qt::Key_W && nivel3[((Y-8)/tam)-2][X/tam]==0 && nivel3[((Y-8)/tam)-2][(X+tam-1)/tam]==0){
            jug->cambio_imagen('w');
            jug->setY(jug->y()-8);
        }

        press=0;
        mov2->start(jug->Vel_mov);
    }
}

void niveles::play()
{
    jugador= new personaje(tam,14*tam);
    scena->addItem(jugador);

}

void niveles::play2()
{
    jug= new personaje(tam,14*tam);
    segundo->addItem(jug);
}

/*void niveles::Colisionbord(personaje *b)
{
    if(b->get_Px()<b->get_radio()){
        b->set_vel(-1*b->get_e()*b->get_Vx(),b->get_Vy(),b->get_radio(),b->get_Py());
    }
    if(b->get_Px()>5120-b->get_radio()){
        b->set_vel(-1*b->get_e()*b->get_Vx(),b->get_Py(),5120-b->get_radio(),b->get_Py());
    }
    if(b->get_Px()<b->get_radio()){
        b->set_vel(b->get_Vx(),-1*b->get_e()*b->get_Vy(),b->get_Px(),b->get_radio());
    }
}*/

void niveles::on_anterior_clicked()
{
    scena->removeItem(jugador);
    ui->graphicsView->setScene(scena);
    ui->lcdNumber->show();
    ui->temp->hide();
    set_widow();
    generar_nivel2();
    segundo->removeItem(jug);
}


void niveles::on_siguiente_clicked()
{
    ui->graphicsView->setScene(segundo);
    ui->lcdNumber->hide();
    ui->temp->show();
    set_widow2();

    generar_nivel3();
    scena->removeItem(jugador);
}

void niveles::actualizar() //dismag->shoot
{//disparo    ->mago=platafor->torreta
    //float torre;
    //int cont=0;
    //jugador->actualizarmov();
    //jugador->setPos(jugador->get_Px(),720-jugador->get_Py());
    //Colisionbord(jugador);


    if ( estado != 0){estado -= 1;}
    if(est_dis!=0){est_dis-=1;}


    /*shoot= new disparo();
    shoot->posx=4*tam;
    shoot->posy=7.5*tam;
    shoot->setPos(shoot->posx,shoot->posy);
    scena->addItem(shoot);
    est_dis=80;

    if(jugador->get_Px()<shoot->posx){
        shoot->posx -= 0.6 * dificultad;
        shoot->setPos(shoot->posx,shoot->posy);
    }
    else if(jugador->get_Px() > shoot->posx){
        shoot->posx += 0.6 * dificultad;
        shoot->setPos(shoot->posx,shoot->posy);
    }
    if(40 + jugador->get_Py() < shoot->posy){
        shoot->posy -= 0.6 * dificultad;
        shoot->setPos(shoot->posx,shoot->posy);
    }

    else if (40 + jugador->get_Py() > shoot->posy){
        shoot->posy += 0.6 * dificultad;
        shoot->setPos(shoot->posx,shoot->posy);
    }

    if (shoot->collidesWithItem(jugador)){
        scena->removeItem(shoot);
        //shoot.removeAt(e);
        scena->removeItem(jugador);
        generar_nivel2();
    }
    else if (est_dis <= 0){
        scena->removeItem(shoot);
        //shoot.removeAt(0);
    }
*/



/****************************************************************************************************/

    //for(int i=0;i<platafor.size();i++){
        //estado = 500 / dificultad;
        //if(platafor.at(i)->getClase()=="torreta"){
            //estado = 500 / dificultad;
            shoot.push_back(new disparo);
            shoot.back()->posx=4*tam;
            shoot.back()->posy=8*tam;
            shoot.back()->setPos(shoot.back()->posx,shoot.back()->posy);


            /*else{
                shoot.back()->setPos(shoot.back()->x(),shoot.back()->y());
                scena->addItem(shoot.back());
            }*/
            est_dis = 800; //tiempo_disparo_del_mago
       // }
        //cont+=10;
   // }
     scena->addItem(shoot.back());

    for(int e=0; e<shoot.size(); e++){ // disparos del mago
    //b->elemnto.>todas las ecuaciones->colisiones
            if(jugador->get_Px()<shoot[e]->posx){
                shoot[e]->posx -= 0.6 * 1;
                shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

            }
            else if(jugador->get_Px() > shoot[e]->posx){
                shoot[e]->posx += 0.6 * 1;
                shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

            }
            if(40 + jugador->get_Py() < shoot[e]->posy){
                shoot[e]->posy -= 0.6 * 1;
                shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

            }

            else if (40 + jugador->get_Py() > shoot[e]->posy){
                shoot[e]->posy += 0.6 * 1;
                shoot[e]->setPos(shoot[e]->posx,shoot[e]->posy);

            }

            if (shoot[e]->collidesWithItem(jugador)){
                scena->removeItem(shoot[e]);
                shoot.removeAt(e);
                scena->removeItem(jugador);
                generar_nivel2();
            }
            else if (est_dis <= 0){
                scena->removeItem(shoot[0]);
                shoot.removeAt(0);
            }
        }
}


