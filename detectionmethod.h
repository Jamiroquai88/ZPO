/*
 * detectionmethod.h
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#ifndef DETECTIONMETHOD_H_
#define DETECTIONMETHOD_H_

#include <string>

class DetectionMethod {
	public:
		DetectionMethod();
		virtual ~DetectionMethod();

		virtual bool ProcessFile(std::string input_file, std::string output_file) = 0;
};

#endif /* DETECTIONMETHOD_H_ */
