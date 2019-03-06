#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "pdfview.h"
class MainView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView() override;
    pdfView *view;
signals:
    
public slots:
    
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override; 
};

#endif // MAINVIEW_H
