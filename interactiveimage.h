#ifndef INTERACTIVEIMAGE_H
#define INTERACTIVEIMAGE_H

#include <QLabel>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class InteractiveImage : public QLabel
{
    Q_OBJECT
public:
    InteractiveImage(QWidget *parent);
    void setRects(std::vector<cv::Rect> Rects);
    cv::Rect m_smallest;
protected:
    void mousePressEvent(QMouseEvent *ev) override;
private:
    std::vector<cv::Rect> m_FinalRects;
signals:
    void sendRectToUi(cv::Rect smallestRect);
};

#endif // INTERACTIVEIMAGE_H
