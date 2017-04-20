#include <iostream>

#include "argumentparser.h"
#include "gradient.h"
#include "closeedgeelements.h"

int main(int argc, char *argv[]) {
	ArgumentParser argparse = ArgumentParser();
	if (!argparse.ParseArguments(argc, argv))
		return 1;
	if (argparse.m_mode == "gradient") {
		Gradient gradient = Gradient();
		gradient.ProcessFile(argparse.m_in_file, argparse.m_out_file);
	}
	else if (argparse.m_mode == "cee") {
		CloseEdgeElements cee = CloseEdgeElements();
		cee.ProcessFile(argparse.m_in_file, argparse.m_out_file);
	}
	else if (argparse.m_mode == "mixed") {
		CloseEdgeElements cee;
		Gradient grad;
		auto first = cv::imread(argparse.m_in_file);
		cv::pyrDown(first, first);
		auto second = cv::imread(argparse.m_in_file);
		auto rectsCee = cee.DetectLetters(first);
		auto rectsGrad = grad.detectText(second);
		std::vector<cv::Rect> intersectionRects;


		for (const auto& r1 : rectsCee)
		{
				for (const auto& r2 : rectsGrad)
				{
					
					auto result = r1 & r2;
					if (result.area() > 0)
					{

						intersectionRects.push_back(result);
					}
				}
		}
		
		bool change;

		for (int i = 0; i < intersectionRects.size(); i++)
		{
				cv::rectangle(first, intersectionRects[i], cv::Scalar(0, 255, 0), 2);
		}
		cv::imwrite(argparse.m_out_file, first);
	}
	else {
		std::cerr << "ERROR: Unexpected mode." << std::endl;
		argparse.Help();
		return 1;
	}

	return 0;
}
