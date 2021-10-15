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
        }        
    }
}
