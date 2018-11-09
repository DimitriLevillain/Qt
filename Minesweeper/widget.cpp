#include "widget.h"
#include "ui_widget.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QPixmap>
#define VIDE 0
#define BOMBE -1


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    int colonne=0, ligne=0;
    int i;
    plateau=new QGridLayout();
    pushButtonJouer = new QPushButton();
    pushButtonQuitter= new QPushButton();
    labelNbMine = new QLabel;
    spinBoxNbMine = new QSpinBox;
    progressBar= new QProgressBar();


    for(i=0;i<NBTOUCHES;i++)
        {
        tab[i] = new QPushButton();
        connect(tab[i],&QPushButton::clicked,this,&Widget::OnQPushButton_clicked);
        }
    i=0;

    for(ligne=10;ligne>0;ligne--)
    {
            for(colonne=0;colonne<6;colonne++)
            {
                plateau->addWidget(tab[i],ligne,colonne);
                tab[i]->setDisabled(true);
                i++;
            }
    }

    pushButtonJouer->setText("Jouer");
    connect(pushButtonJouer,&QPushButton::clicked,this,&Widget::on_pushButtonJouer_clicked);
    plateau->addWidget(pushButtonJouer,11,0,9,2);

    pushButtonQuitter->setText("Quitter");
    connect(pushButtonQuitter,&QPushButton::clicked,this,&Widget::close);
    plateau->addWidget(pushButtonQuitter,11,4,9,2);

    labelNbMine->setText("Nombre de mines:");
    plateau->addWidget(labelNbMine,15,0,9,2);

    spinBoxNbMine->setValue(5);
    plateau->addWidget(spinBoxNbMine,15,2,9,1);

    plateau->addWidget(progressBar,15,4,9,2);

    this->setLayout(plateau);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::OnQPushButton_clicked()
{
    QPushButton *b=qobject_cast<QPushButton*>(sender());
    int colonne;
    int ligne;
    int rs,cs;

    // colonne et ligne seront mis à jour avex les coordonnées du bouton dans le QGridLayout
    // ce qui correspond aux coordonnées dans la grille de données
    plateau->getItemPosition(plateau->indexOf(b),&ligne,&colonne,&rs,&cs);
    if(grille[ligne][colonne] == -1)
    {
        PerduIhm();
    }
    else
    {
        MajCaseVoisine(ligne,colonne);
        b->setText(QString::number(nombreMinesAlentour));
        b->setFlat(true);
        bool verifVictoire;
        verifVictoire = VerifierVictoire();
        if(verifVictoire==true)
        {
            GagnerIhm();
        }
    }
}

void Widget::on_pushButtonJouer_clicked()
{
    InitialiserGrille(spinBoxNbMine->value());
    InitialiserGrilleIhm();
}

void qtPause(int millisecondes)
{
    QTimer timer;
    timer.start(millisecondes);
    QEventLoop loop;
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    loop.exec();
}


void Widget::InitialiserGrille(int nbBombes)
{
    QRandomGenerator gen;
    quint32 ligne;
    quint32 colonne;
    nbMines=nbBombes;
    progressBar->setMaximum(nbMines);
    for(ligne=0;ligne<NBLIGNES;ligne++)
    {
        for(colonne=0;colonne<NBCOLONNES;colonne++)
        {
            grille[ligne][colonne]=VIDE;
        }
    }
    gen.seed(QDateTime::currentDateTime ().toMSecsSinceEpoch());
    do
    {
        ligne= gen.bounded(0,NBLIGNES-1);
        qtPause(300);
        colonne= gen.bounded(0,NBCOLONNES-1);
        qtPause(300);
        if (grille[ligne][colonne]==VIDE)
        {
            grille[ligne][colonne]=BOMBE;
            nbBombes--;
            progressBar->setValue(nbMines-nbBombes);
            qApp->processEvents();
        }
    }while(nbBombes!=0);
    int index=0;
    for(ligne=0;ligne<NBLIGNES;ligne++)
    {
        for(colonne=0;colonne<NBCOLONNES;colonne++)
        {
            MajCaseVoisine(ligne,colonne);
            index++;
        }
    }
}

void Widget::InitialiserGrilleIhm()
{

    for(int i=0;i<NBTOUCHES;i++)
        {
            tab[i]->setEnabled(true);
            tab[i]->setFlat(false);
            tab[i]->setText("");
            tab[i]->setStyleSheet("background-color: white;");
        }
}

bool Widget::VerifierVictoire()
{
    bool victoire=false;
    int nbCasesRestante=0;
    // listeBoutons contiendra la liste des tous les QPushButton de l'interface
    QList <QPushButton*>listeBoutons=findChildren<QPushButton*>();
    foreach(QPushButton *b, listeBoutons)
    {
        // si l' bouton n'est pas flat (-> pas encore cliqué)
        if (!(b->isFlat()))
        {   // si le bouton est bien une case de la grille de jeu
            // j'augmente mon compteur de cases restantes
            if (b->text()!="Quitter" && b->text()!="Jouer")
            {
                nbCasesRestante++;
            }
        }
    }
    qDebug()<<nbCasesRestante;
    if (nbCasesRestante==nbMines)
    {
        victoire=true;
    }
    return victoire;
}

void Widget::PerduIhm()
{
    for(int i=0;i<NBTOUCHES;i++)
    {
        tab[i]->setEnabled(false);
        tab[i]->setFlat(false);
        tab[i]->setText("");
        tab[i]->setStyleSheet("background-color: red;");
    }
}

void Widget::GagnerIhm()
{
    for(int i=0;i<NBTOUCHES;i++)
    {
        tab[i]->setEnabled(false);
        tab[i]->setFlat(false);
        tab[i]->setText("");
        tab[i]->setStyleSheet("background-color: green;");
    }
}

void Widget::MajCaseVoisine(int ligne, int colonne)
{
    nombreMinesAlentour = 0;

    //Cases du milieu de la grille
    if(ligne!=1 && ligne!=10 && colonne!=0 && colonne!=5)
    {
        // cases au dessus
        if(grille[ligne-1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }

        // cases au dessous
        if(grille[ligne+1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }

        // cases de chaque côté

        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }

        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Cases de la première lignes
    if(ligne==1 && colonne!=0 && colonne!=5)
    {

        // cases au dessous
        if(grille[ligne+1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }

        // cases de chaque côté

        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }

        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Cases de la dernière ligne
    if(ligne==10 && colonne!=0 && colonne!=5)
    {
        // cases au dessus
        if(grille[ligne-1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }


        // cases de chaque côté

        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }

        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
    }


    //cases de la première colonne
    if(colonne==0 && ligne!=1 && ligne!=10)
    {
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //cases de la derniere colonne
    if(colonne==5 && ligne!=1 && ligne!=10)
    {
        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Coin en haut à gauche
    if(colonne==0 && ligne==1)
    {
        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Coin en bas à gauche
    if(colonne==0 && ligne==10)
    {
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne][colonne+1]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Coin en haut à droite
    if(colonne==5 && ligne==1)
    {
        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne+1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
    }

    //Coin en bas à droite
    if(colonne==5 && ligne==10)
    {
        if(grille[ligne][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne-1]==-1)
        {
            nombreMinesAlentour++;
        }
        if(grille[ligne-1][colonne]==-1)
        {
            nombreMinesAlentour++;
        }
    }
}


