#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>
#include <iostream>
#include <string>

#include "gradient.h"
#include "closeerdgeelements.h"
#include "fusion.h"
#include "ocr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static QImage Mat2QImage(cv::Mat const& src);
    static cv::Mat QImage2Mat(QImage const& src);
    ~MainWindow();

public slots:
   void displayText(cv::Rect detectedRect);

private slots:
    void on_actionOpen_triggered();
    void on_saveImageButton_clicked();
    void on_showAreaButton_clicked();

    void on_originalImageButton_clicked();

    void on_processImageButton_clicked();

private:
    Ui::MainWindow *ui;
    Gradient *mp_gradient;
    CloseEdgeElements *mp_cee;
    Fusion *mp_fusion;
    OCR *mp_ocr;
    QString m_fileName;
    void setRadioButtons();
};

#endif // MAINWINDOW_H
