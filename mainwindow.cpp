#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <hand.h>
#include <table.h>
#include <solver.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Hand hand;
    hand.cards[0].value = 13;
    hand.cards[0].suit = Diamonds;
    hand.cards[0].valid = true;
    hand.cards[1].value = 14;
    hand.cards[1].suit = Hearts;
    hand.cards[1].valid = true;

    Table table;
    table.cards[0].value = 4;
    table.cards[0].valid = true;
    table.cards[0].suit = Spades;
    table.cards[1].valid = true;
    table.cards[1].value = 6;
    table.cards[1].suit = Clubs;
    table.cards[2].valid = true;
    table.cards[2].suit = Diamonds;
    table.cards[2].value = 10;

    Solver solver(Situation(hand, table));
    solver.solve();
    qDebug() << solver.winrate << solver.wins << solver.louses;
}

MainWindow::~MainWindow()
{
    delete ui;
}
