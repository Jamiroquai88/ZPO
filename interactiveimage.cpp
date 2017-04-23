#include "interactiveimage.h"
#include <QMessageBox>
#include <QMouseEvent>

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

   //first rectangle on click-area
    for (int i = 0; i < m_FinalRects.size(); i++)
    {
       if(m_FinalRects[i].contains(P))
       {
           m_smallest = m_FinalRects[i];
           break;
       }
    }
    //goes through all rectangles
    for (int i = 0; i < m_FinalRects.size(); i++)
    {
        if(m_FinalRects[i].contains(P)) //finds those on click-area
        {
            if(m_FinalRects[i].area() <= m_smallest.area())  //finds smallest rectangle
               m_smallest = m_FinalRects[i];
        }
    }
    sendRectToUi(m_smallest); //sends signal to ui (mainwindow)
}
