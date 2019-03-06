#include "pdfview.h"

pdfView::pdfView(QWidget *parent): QScrollArea (parent)
{
    m_pdfView = new QWidget;
    //m_pdfView->resize(1280, 10000);
    this->m_layout = new QGridLayout(m_pdfView);
    this->setWidget(m_pdfView);
    this->setAlignment(Qt::AlignCenter);
    this->m_layout->setVerticalSpacing(10);
    this->resize(1280, 720);
}

pdfView::~pdfView()
{
    closeDocument();
    if(m_document) delete m_document;
    delete m_layout;
    delete m_pdfView;
}

Poppler::Document *pdfView::document()
{
    
    return m_document;
}

int pdfView::loadDocument(const QString &file)
{
    closeDocument();
    m_document = Poppler::Document::load(file);
    if(!(this->document())) {
        qDebug() << "Not File";
        return -1;
    }
    while(this->document()->isLocked()) {
        bool ok = true;
        QString password = QInputDialog::getText(this, tr("Document Password"),
                                                 tr("Please insert the password of the document:"),
                                                 QLineEdit::Password, QString(), &ok);
        if(!ok) {
            delete m_document;
            m_document = nullptr;
            return -1;
        }
        this->document()->unlock(password.toLatin1(), password.toLatin1());
    }
    
    this->document()->setRenderHint(Poppler::Document::TextAntialiasing, 1);
    this->document()->setRenderHint(Poppler::Document::Antialiasing, 1);
    m_page_number = this->document()->numPages();
    PageView *page = nullptr;
    for (int loop_page = 0; loop_page < m_page_number; ++loop_page) {
        page = new PageView(this->document()->page(loop_page));
        this->layout()->addWidget(page, loop_page, 0, Qt::AlignCenter);
        this->m_pages.append(page);
    }
    m_pdfView->resize(page->width(), page->height() * m_page_number + (m_page_number - 1) * 10);
    return 0;
}

int pdfView::closeDocument()
{
    if(m_document == nullptr) {
        return 0;
    }
    
    for (int loop_page = 0; loop_page < this->m_page_number; ++loop_page) {
        delete m_pages.at(loop_page);
    }
    m_pages.clear();
    m_document = nullptr;
    return 0;
}

QGridLayout *pdfView::layout()
{
    return m_layout;
}

QVector<PageView *> pdfView::pages()
{
    return m_pages;
}

int pdfView::setScale(double scale)
{
    m_scale = scale;
    if(m_document == nullptr) return 0;
    for (int loop_page = 0; loop_page < m_page_number; ++loop_page) {
        m_pages.at(loop_page)->setScale(scale);
    }
    m_pdfView->resize(m_pages.at(0)->width(), m_pages.at(0)->height() * m_page_number + (m_page_number - 1) * 10);
    return 0;
}

double pdfView::scale()
{
    return m_scale;
}


