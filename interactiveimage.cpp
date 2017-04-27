#include "interactiveimage.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>

InteractiveImage::InteractiveImage(QWidget *parent) : QLabel(parent)
{

}

//saves detected rectangles to member variable FinalRects
void InteractiveImage::setRects(std::vector<cv::Rect> Rects)
{
    m_FinalRects = Rects;
}


void InteractiveImage::mousePressEvent(QMouseEvent *ev)
{
    //saves coordinates from mouse-click
    QPoint pos = ev->pos();
    cv::Point P{pos.x(),pos.y()};

    //set empty rect
    cv::Rect init(0,0,0,0);
    m_smallest = init;

    //first rectangle on click-area
    for (unsigned int i = 0; i < m_FinalRects.size(); i++)
    {
       if(m_FinalRects[i].contains(P))
       {
           m_smallest = m_FinalRects[i];
           break;
       }
    }
    //goes through all rectangles
    for (unsigned int i = 0; i < m_FinalRects.size(); i++)
    {
        if(m_FinalRects[i].contains(P)) //finds those on click-area
        {
            if(m_FinalRects[i].area() <= m_smallest.area())  //finds smallest rectangle
               m_smallest = m_FinalRects[i];
        }
    }

    //rect is not empty
    if(m_smallest.width != 0)
        sendRectToUi(m_smallest); //sends signal to ui (mainwindow)

}

void InteractiveImage::setPixmap(const QPixmap &p) {
    pix = p;
    QLabel::setPixmap(scaledPixmap());
}

//rescales pixmap to current size of label
QPixmap InteractiveImage::scaledPixmap() const {
    return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void InteractiveImage::resizeEvent(QResizeEvent *event) {
    if(!pix.isNull()) {
        QLabel::setPixmap(scaledPixmap());
    }
}
