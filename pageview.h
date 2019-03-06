#ifndef PAGEVIEW_H
#define PAGEVIEW_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QApplication>
#include <QtWidgets/QDesktopWidget>
#include <poppler/qt5/poppler-qt5.h>
#include <QDebug>

class PageView: public QLabel
{
public:
    PageView(Poppler::Page *page);
    ~PageView();
private:
    Poppler::Page *page;
    double m_dpiX;
    double m_dpiY;
};

#endif // PAGEVIEW_H
