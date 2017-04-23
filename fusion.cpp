#include "fusion.h"

Fusion::Fusion()
{

}
Fusion::~Fusion() {

}

//makes a fusion of both methods (CEE and Gradiant)
std::vector<cv::Rect> Fusion::getFusion(std::string input_file)
{
    Gradient grad;
    CloseEdgeElements cee;

    cv::Mat imgCee = cv::imread(input_file);
    cv::Mat imgRad = cv::imread(input_file);
    std::vector<cv::Rect> rectsCee = cee.DetectLetters(imgCee);
    std::vector<cv::Rect> rectsGrad = grad.detectText(imgRad);

    //rectangles got from fusion
    std::vector<cv::Rect> intersectionRects;

    //goes through both detected rectangles looking for matched areas
   for (const cv::Rect& r1 : rectsCee)
   {
       for (const cv::Rect& r2 : rectsGrad)
       {
           cv::Rect result = r1 & r2;
           if (result.area() > 0)
           {
               intersectionRects.push_back(result);
           }
       }
   }
   return intersectionRects;
}
