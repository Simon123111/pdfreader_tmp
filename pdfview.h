#ifndef PDFVIEW_H
#define PDFVIEW_H
#include <QWidget>
#include <QGridLayout>
#include <poppler/qt5/poppler-qt5.h>
#include <QDebug>
#include <QInputDialog>
#include <QScrollArea>
#include <QLineEdit>
#include "pageview.h"

class pdfView: public QScrollArea
{
public:
    pdfView(QWidget *parent = nullptr);
    ~pdfView();
    Poppler::Document *document();
    int loadDocument(const QString &file);
    int closeDocument();
    QGridLayout *layout();
    QVector<PageView *> pages();
    
private:
    Poppler::Document *m_document = nullptr;
    QGridLayout *m_layout = nullptr;
    int m_page_number = 0;
    QWidget *m_pdfView = nullptr;
    QVector<PageView *> m_pages;
    double scale = 1;
};

#endif // PDFVIEW_H
