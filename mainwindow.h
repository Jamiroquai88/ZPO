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
    void on_gradientButton_clicked();
    void on_ceeButton_clicked();
    void on_fusionButton_clicked();
    void on_saveImageButton_clicked();

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    void MainWindow::setRadioButtons();
};

#endif // MAINWINDOW_H
