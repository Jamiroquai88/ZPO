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

#include "detectionmethod.h"

class CloseEdgeElements : DetectionMethod {
	public:
		CloseEdgeElements();
		virtual ~CloseEdgeElements();

		bool ProcessFile(std::string input_file, std::string output_file);
		std::vector<cv::Rect> DetectLetters(cv::Mat img);
	private:
		
};

#endif /* CLOSEEDGEELEMENTS_H_ */
