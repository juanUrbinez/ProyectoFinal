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
    //ui->graphicsView->setScene(scene);
   setFixedSize(tam*50+2,tam*(14+2)+2);
    setWindowTitle("Poison Run");
}

void MainWindow::generar_mapa()
{
    //escenario *plataforma;

    int c1=0;
    int c2=0;
    //level->set_scale(tam*(ui->graphicsView->width()),tam*(ui->graphicsView->height()));
    for(int i=0;i<14;i++)
    {
        //
        for(int j=0;j<50;j++)
        {


            if(nivel1[i][j]==1)
            {// falta añadir las paredes
                plataforma=new escenario();
                plataforma->CambiarOriginal(":/escenario/escenario/muro1.png");
                plataforma->set_scale(tam,tam);
                plataforma->set_imagen(0);
                plataforma->setPos(c1,c2);
                scene->addItem(plataforma);

            }
//            else if(nivel1[i][j]==2)
//            {
//                plataforma->CambiarOriginal(":/escenario/escenario/muro1.png");
//                plataforma->set_scale(tam,tam);
//                plataforma->set_imagen(0);
//                plataforma->setPos(c1,c2);
//                scene->addItem(plataforma);
//            }
            c1+=tam;

        }
        c1=0;
        c2=c2+tam;
    }
}

/*void MainWindow::inicializar()
{
    m=new matriz(14,16);
    bloques = new escenario**[14];
    for (int f=0;f<14;f++){
        bloques[f] = new escenario*[50];
        for(int c=0;c<50;c++){
            bloques[f][c]=new escenario();
        }
    }
}*/
