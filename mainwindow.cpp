#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gradient.h"
#include "closeerdgeelements.h"
#include "fusion.h"
#include "interactiveimage.h"
#include <QDebug>

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
    connect(ui->interactiveImage, SIGNAL(sendRectToUi(cv::Rect)), this, SLOT(onRectClicked(cv::Rect)));
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
        originalImage.load(m_fileName);

        //set image on label
        ui->interactiveImage->setPixmap(QPixmap::fromImage(originalImage));

        imgMatOrig = cv::imread(m_fileName.toStdString());
        cv::pyrDown(imgMatOrig, imgMatOrig);

        setRadioButtons();
    }
}

void MainWindow::onRectClicked(cv::Rect clickedRect)
{
    //if rect is in vector and has been clicked again, then remove it from vector and change it's color
    if(std::find(clickedRects.begin(), clickedRects.end(), clickedRect) != clickedRects.end()) {
        clickedRects.erase(std::remove(clickedRects.begin(), clickedRects.end(), clickedRect), clickedRects.end());
        cv::rectangle(imgMat, clickedRect, cv::Scalar(0, 255, 0), 2);
    }
    //else add it to vector and change it's color to red
    else {
        clickedRects.push_back(clickedRect);
        cv::rectangle(imgMat, clickedRect, cv::Scalar(0, 0, 255), 2);
    }

    QImage img = Mat2QImage(imgMat);
    ui->interactiveImage->setPixmap(QPixmap::fromImage(img));

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
        QImage qimageToSave = ui->interactiveImage->pixmap()->toImage();
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
    QString tmp_filename = "ultra_super_unikatni_nazev_tmp_souboru.png";
    QString detected_text = "";

    //traverse all selected rectangles
    for (unsigned int i = 0; i < clickedRects.size(); i++) {

        //cut area with rectangle from original image and save it
        cv::Mat textArea = imgMatOrig(clickedRects[i]);
        QImage img = Mat2QImage(textArea);
        img.save(tmp_filename);

        //call OCR
        QString text = mp_ocr->ProcessFile(tmp_filename);
        if (text.length() == 0) {
            // TODO
            // show warning dialog
        }
        else {
            detected_text += text;
        }
    }
    ui->textEdit->setText(detected_text);
}


void MainWindow::on_originalImageButton_clicked()
{
    ui->interactiveImage->setPixmap(QPixmap::fromImage(originalImage));

    //clear everything => original_image == fresh start
    clickedRects.clear();
    ui->interactiveImage->setRects(clickedRects);
    ui->textEdit->setText("");
}

void MainWindow::on_processImageButton_clicked()
{
    //clear everything to avoid unwanted behavior
    clickedRects.clear();
    ui->interactiveImage->setRects(clickedRects);

    if (!ui->gradientButton->isChecked() && !ui->ceeButton->isChecked() && !ui->fusionButton->isChecked()) {
        // TODO, display warning
        return;
    }
    std::string str = m_fileName.toStdString();
    std::vector<cv::Rect> boundaryRects;
    imgMat = cv::imread(str);
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
    ui->interactiveImage->setPixmap(QPixmap::fromImage(img));
    ui->interactiveImage->setRects(boundaryRects);
    ui->saveImageButton->setEnabled(true);
    ui->showAreaButton->setEnabled(true);
}
