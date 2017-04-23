#ifndef FUSION_H
#define FUSION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "gradient.h"
#include "closeerdgeelements.h"

class Fusion
{
public:
    Fusion();
    ~Fusion();
    std::vector<cv::Rect> Fusion::getFusion(std::string input_file);
};

#endif // FUSION_H
