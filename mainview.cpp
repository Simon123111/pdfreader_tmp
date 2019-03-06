#include "mainview.h"

MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    this->resize(1280, 720);
    this->view = new pdfView(this);
    this->view->loadDocument("/home/ink19/c++_qt/pdfreader_new/Test.pdf");
}

MainView::~MainView()
{
    
}

void MainView::resizeEvent(QResizeEvent *event)
{
    this->view->resize(this->size());
    
}
