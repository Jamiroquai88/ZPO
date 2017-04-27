/*
 * gradient.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */


#include <vector>
#include "gradient.h"

using namespace cv;
using namespace std;

Gradient::Gradient() {

}

Gradient::~Gradient() {

}

std::vector<cv::Rect> Gradient::detectText(cv::Mat inputImg) {

    Mat rgb = inputImg.clone();
    std::vector<cv::Rect> boundRects;
    //downsample input image
    pyrDown(inputImg, rgb);

    Mat small;
    cvtColor(rgb, small, CV_BGR2GRAY);
    //morphological gradient
    Mat grad;
    Mat morphKernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    morphologyEx(small, grad, MORPH_GRADIENT, morphKernel);
    //get black-white representation
    Mat bw;
    threshold(grad, bw, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);
    //connect horizontally oriented regions
    Mat connected;
    morphKernel = getStructuringElement(MORPH_RECT, Size(9, 1));
    morphologyEx(bw, connected, MORPH_CLOSE, morphKernel);

    //find contours
    Mat mask = Mat::zeros(bw.size(), CV_8UC1);
    vector <vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(connected, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    //filter contours
    for (int i = 0; i >= 0; i = hierarchy[i][0]) {
        Rect rect = boundingRect(contours[i]);
        Mat maskROI(mask, rect);
        maskROI = Scalar(0, 0, 0);
        //fill the contour
        drawContours(mask, contours, i, Scalar(255, 255, 255), CV_FILLED);
        //ratio of non-zero pixels in the filled region
        double r = (double)countNonZero(maskROI) / (rect.width*rect.height);

        if (r > 0.45 && (rect.height > 8 && rect.width > 8)) {
            boundRects.push_back(rect);
        }
    }

    return boundRects;
}

