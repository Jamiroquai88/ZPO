#ifndef GRADIENT_H
#define GRADIENT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <vector>

class Gradient
{
public:
    Gradient();
    ~Gradient();

    std::vector<cv::Rect> detectText(cv::Mat inputImg);
};

#endif // GRADIENT_H
