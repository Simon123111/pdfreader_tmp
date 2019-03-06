#include "pageview.h"

PageView::PageView(Poppler::Page *page)
    : m_dpiX(QApplication::desktop()->physicalDpiX())
    , m_dpiY(QApplication::desktop()->physicalDpiY())
{
    this->page = page;
    auto image = page->renderToImage(m_dpiX, m_dpiY, -1, -1, -1, -1, Poppler::Page::Rotate0);
    this->resize(image.size());
    this->setPixmap(QPixmap::fromImage(image));
}

PageView::~PageView()
{
    delete this->page;
}
