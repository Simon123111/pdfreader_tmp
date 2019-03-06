#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
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
};

#endif // MAINVIEW_H
