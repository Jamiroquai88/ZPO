/*
 * argumentparser.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#include "argumentparser.h"

ArgumentParser::ArgumentParser() : m_in_file(0), m_out_file(0), m_mode(0) {

}

ArgumentParser::~ArgumentParser() {

}

void ArgumentParser::Help() {
	std::cout << "Usage: ./text_detector" << std::endl
			  << "-i input_image" << std::endl
			  << "-o output_image" << std::endl
			  << "-m mode [gradient]" << std::endl;
}

bool ArgumentParser::ParseArguments(int argc, char **argv) {
	int opt;

	while ((opt = getopt(argc, argv, "i:o:m:")) != -1) {
	    switch (opt) {
	        case 'i':
	            m_in_file = optarg;
	            break;
	        case 'o':
	            m_out_file = optarg;
	            break;
	        case 'm':
	        	m_mode = optarg;
	        	break;
	        default:
	            break;
	    }
	}

	//check if all args were given
	if (!m_in_file || !m_out_file || !m_mode) {
	    std::cerr << "ERROR: Too few arguments set." << std::endl;
	    Help();
	    return false;
	}

	return true;
}
