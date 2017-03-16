/*
 * argumentparser.h
 *
 *  Created on: Mar 16, 2017
 *      Author: darthvader
 */

#ifndef ARGUMENTPARSER_H_
#define ARGUMENTPARSER_H_

#include <iostream>
#include <string>

class ArgumentParser {
	public:
		ArgumentParser();
		virtual ~ArgumentParser();

		bool ParseArguments(int argc, char **argv);
		void Help();

		std::string m_in_file;
		std::string m_out_file;
		std::string m_mode;
};

#endif /* ARGUMENTPARSER_H_ */
