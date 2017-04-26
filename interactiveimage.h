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
    QPixmap scaledPixmap() const;
public slots:
    void setPixmap ( const QPixmap &p);
    void resizeEvent(QResizeEvent *ev);
protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void resizeImage();
private:
    std::vector<cv::Rect> m_FinalRects;
    QPixmap pix;
signals:
    void sendRectToUi(cv::Rect smallestRect);
};

#endif // INTERACTIVEIMAGE_H
