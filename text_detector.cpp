#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#include "gradient.h"


int main(int argc, char *argv[]) {
    ArgumentParser argparse = ArgumentParser();
    if (!argparse.ParseArguments(argc, argv))
    	return 1;

    if (argparse.m_mode == "gradient") {
    	Gradient gradient = Gradient();
    	gradient.ProcessFile(argparse.m_in_file, argparse.m_out_file);
    } else {
    	std::cerr << "ERROR: Unexpected mode." << std::endl;
    	argparse.Help();
    	return 1;
    }

    return 0;
}
