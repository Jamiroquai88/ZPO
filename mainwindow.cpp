#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gradient.h"
#include "closeerdgeelements.h"
#include "fusion.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gradientButton->setEnabled(false);
    ui->ceeButton->setEnabled(false);
    ui->fusionButton->setEnabled(false);
    ui->showAreaButton->setEnabled(false);
    ui->saveImageButton->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString testFileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    if(testFileName != "")
    {
        m_fileName = testFileName;
        QImage m_myImage;
        m_myImage.load(m_fileName);
        ui->labelimage->setPixmap(QPixmap::fromImage(m_myImage));
        //ui->labelimage->setText("Choose method");  //show large image or set text?
        setRadioButtons();
    }
}


void MainWindow::on_gradientButton_clicked()
{
    Gradient grad;
    std::string str = m_fileName.toStdString();
    cv::Mat imgMAT = cv::imread(str);
    std::vector<cv::Rect> boundaryRects = grad.detectText(imgMAT);
    cv::pyrDown(imgMAT, imgMAT);
    for (int i = 0; i < boundaryRects.size(); i++)
    {
        cv::rectangle(imgMAT, boundaryRects[i], cv::Scalar(0, 255, 0), 2);
    }
    QImage img = Mat2QImage(imgMAT);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    ui->labelimage->setRects(boundaryRects);
    ui->saveImageButton->setEnabled(true);
}


void MainWindow::on_ceeButton_clicked()
{
    CloseEdgeElements cee;
    std::string str = m_fileName.toStdString();
    cv::Mat imgMat = cv::imread(str);
    std::vector<cv::Rect> boundaryRects = cee.DetectLetters(imgMat);
    cv::pyrDown(imgMat, imgMat);
    for(int i=0; i< boundaryRects.size(); i++)
    {
        cv::rectangle(imgMat,boundaryRects[i],cv::Scalar(0,255,0),2,8,0);
    }

    QImage img = Mat2QImage(imgMat);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    ui->labelimage->setRects(boundaryRects);
    ui->saveImageButton->setEnabled(true);
}


void MainWindow::on_fusionButton_clicked()
{
    Fusion fus;
    std::string str = m_fileName.toStdString();
     std::vector<cv::Rect> intersectionRects = fus.getFusion(str);
    cv::Mat imgMat = cv::imread(str);
    cv::pyrDown(imgMat, imgMat);

    for (int i = 0; i < intersectionRects.size(); i++)
    {
        cv::rectangle(imgMat, intersectionRects[i], cv::Scalar(0, 255, 0), 2) ;
    }
    QImage img = Mat2QImage(imgMat);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    ui->labelimage->setRects(intersectionRects);
    ui->saveImageButton->setEnabled(true);
}


void MainWindow::displayText(cv::Rect detectedRect)
{
    ui->showAreaButton->setEnabled(true);
    /*********************
     * call function to recognize text- TO DO
     *********************/
}


void MainWindow::on_saveImageButton_clicked()
{

     QString outputFileName =  QFileDialog::getSaveFileName(this, tr("Save image as"), "", "*.png");
    if(outputFileName != "")
    {
        QImage qimageToSave = ui->labelimage->pixmap()->toImage();
        qimageToSave.save(outputFileName);
    }
}


QImage MainWindow::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp;
     cvtColor(src, temp,CV_BGR2RGB);
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits();
     return dest;

}


//reseting buttons
void MainWindow::setRadioButtons(){
    ui->gradientButton->setEnabled(true);
    ui->gradientButton->setAutoExclusive(false);
    ui->gradientButton->setChecked(false);
    ui->gradientButton->setAutoExclusive(true);

    ui->ceeButton->setEnabled(true);
    ui->ceeButton->setAutoExclusive(false);
    ui->ceeButton->setChecked(false);
    ui->ceeButton->setAutoExclusive(true);

    ui->fusionButton->setEnabled(true);
    ui->fusionButton->setAutoExclusive(false);
    ui->fusionButton->setChecked(false);
    ui->fusionButton->setAutoExclusive(true);

}
