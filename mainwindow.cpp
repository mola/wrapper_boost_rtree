#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mTree = new RTree;
    mTree->insert(value_t(point_t(1.0, 1.0), 11));
    mTree->insert(value_t(point_t(2.0, 2.0), 22));
    mTree->insert(value_t(point_t(3.0, 3.0), 33));

    box_t   search_box(point_t(0.0, 0.0), point_t(2.5, 2.5));
    auto    r       = mTree->query(search_box);
    auto    clicked = point_t(1.8, 1.8);
    auto    r2      = mTree->nearset(clicked);
    double  dist_qt = bg::distance(clicked, r2[0].first);
}

MainWindow::~MainWindow()
{
    delete ui;
}
