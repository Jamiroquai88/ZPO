/*
 * gradient.h
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#ifndef GRADIENT_H_
#define GRADIENT_H_

#include "detectionmethod.h"


class Gradient : DetectionMethod {
	public:
		Gradient();
		virtual ~Gradient();

		bool ProcessFile(std::string input_file, std::string output_file);
};

#endif /* GRADIENT_H_ */
