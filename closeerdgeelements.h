/*
 * closeedgeelements.h
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#ifndef CLOSEEDGEELEMENTS_H_
#define CLOSEEDGEELEMENTS_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <vector>


class CloseEdgeElements
{
    public:
        CloseEdgeElements();
        virtual ~CloseEdgeElements();

       // cv::Mat CloseEdgeElements::ProcessFile(std::string input_file);
        std::vector<cv::Rect> CloseEdgeElements::DetectLetters(cv::Mat img);
    private:

};

#endif /* CLOSEEDGEELEMENTS_H_ */
