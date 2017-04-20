/*
 * gradient.h
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#ifndef GRADIENT_H_
#define GRADIENT_H_

#include "detectionmethod.h"
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Gradient : DetectionMethod {
	public:
		Gradient();
		virtual ~Gradient();

		bool ProcessFile(std::string input_file, std::string output_file);

		std::vector<cv::Rect> detectText(cv::Mat inputImg);
};

#endif /* GRADIENT_H_ */
