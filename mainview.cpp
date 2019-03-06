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

void MainView::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == (Qt::ControlModifier)) {
        if(event->key() == Qt::Key_A) {
            this->view->setScale(this->view->scale() * 1.1);
        } else if (event->key() == Qt::Key_S) {
            this->view->setScale(this->view->scale() * 0.9);
        } 
    }
}
