#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gradient.h"
#include "closeerdgeelements.h"
#include "fusion.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mp_ocr(0)
{
    ui->setupUi(this);
    ui->gradientButton->setEnabled(false);
    ui->ceeButton->setEnabled(false);
    ui->fusionButton->setEnabled(false);
    ui->showAreaButton->setEnabled(false);
    ui->saveImageButton->setEnabled(false);
    mp_ocr = new OCR();
    mp_ocr->Init();
}


MainWindow::~MainWindow()
{
    delete mp_gradient;
    delete mp_cee;
    delete mp_fusion;
    delete mp_ocr;
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

void MainWindow::on_showAreaButton_clicked()
{
    QString text = mp_ocr->ProcessFile(m_fileName);
    if (text.length() == 0) {
        // TODO
        // show warning dialog
    }
    else {
        ui->textEdit->setText(text);
    }

}

void MainWindow::on_originalImageButton_clicked()
{

}

void MainWindow::on_processImageButton_clicked()
{
    if (!ui->gradientButton->isChecked() && !ui->ceeButton->isChecked() && !ui->fusionButton->isChecked()) {
        // TODO, display warning
        return;
    }
    std::string str = m_fileName.toStdString();
    std::vector<cv::Rect> boundaryRects;
    cv::Mat imgMat = cv::imread(str);
    if (ui->gradientButton->isChecked()) {
        boundaryRects = mp_gradient->detectText(imgMat);
        cv::pyrDown(imgMat, imgMat);
        for (unsigned int i = 0; i < boundaryRects.size(); i++)
            cv::rectangle(imgMat, boundaryRects[i], cv::Scalar(0, 255, 0), 2);
    }
    if (ui->ceeButton->isChecked()) {
        boundaryRects = mp_cee->DetectLetters(imgMat);
        cv::pyrDown(imgMat, imgMat);
        for(unsigned int i=0; i< boundaryRects.size(); i++)
            cv::rectangle(imgMat, boundaryRects[i], cv::Scalar(0,255,0), 2, 8, 0);
    }
    if (ui->fusionButton->isChecked()) {
        boundaryRects = mp_fusion->getFusion(str);
        cv::pyrDown(imgMat, imgMat);
        for (unsigned int i = 0; i < boundaryRects.size(); i++)
           cv::rectangle(imgMat, boundaryRects[i], cv::Scalar(0, 255, 0), 2);

    }
    QImage img = Mat2QImage(imgMat);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    ui->labelimage->setRects(boundaryRects);
    ui->saveImageButton->setEnabled(true);
    ui->showAreaButton->setEnabled(true);
}
