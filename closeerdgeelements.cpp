/*
 * closeedgeelements.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#include "closeerdgeelements.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

CloseEdgeElements::CloseEdgeElements() {

}

CloseEdgeElements::~CloseEdgeElements() {

}

std::vector<cv::Rect> CloseEdgeElements::DetectLetters(cv::Mat img)
{
    std::vector<cv::Rect> boundRect;
    cv::Mat img_gray, img_sobel, img_threshold, element;
    cvtColor(img, img_gray, CV_BGR2GRAY);
    cv::Sobel(img_gray, img_sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
    cv::pyrDown(img_sobel, img_sobel);
    cv::threshold(img_sobel, img_threshold, 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);
    element = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
    cv::morphologyEx(img_threshold, img_threshold, CV_MOP_CLOSE, element); //Does the trick
    std::vector< std::vector< cv::Point> > contours;
    cv::findContours(img_threshold, contours, 0, 1);
    std::vector<std::vector<cv::Point> > contours_poly(contours.size());
    for (unsigned int i = 0; i < contours.size(); i++)
        if (contours[i].size() > 100)
        {
            cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
            cv::Rect appRect(boundingRect(cv::Mat(contours_poly[i])));
            if (appRect.width > appRect.height)
                boundRect.push_back(appRect);
        }
    return boundRect;
}

