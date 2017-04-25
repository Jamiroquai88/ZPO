/*
 *  * detectionmethod.h
 *   *
 *    *  Created on: Mar 16, 2017
 *     *      Author: darthvader
 *      */

#ifndef DETECTIONMETHOD_H_
#define DETECTIONMETHOD_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>

class DetectionMethod {
    public:
        DetectionMethod();
        virtual ~DetectionMethod();

        virtual std::vector<cv::Rect> ProcessFile(std::string input_file) = 0;
};

#endif /* DETECTIONMETHOD_H_ */
