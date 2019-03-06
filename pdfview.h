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
private:
    Poppler::Document *m_document;
    QGridLayout *m_layout;
    int m_page_number;
    QWidget *m_pdfView;
    QVector<PageView *> m_pages;
    
};

#endif // PDFVIEW_H
