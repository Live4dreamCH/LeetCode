#include <iostream>
#include "load_step_file.h"
#include "step_format_parser.h"

// 解析文件类
StepFormatParser::StepFormatParser() { std::cout << "init StepFormatParser\n"; }

void StepFormatParser::print() const
{
    std::cout << "I'm LoadStepFile, with inner LoadStepFile:";
    loader.print();
}

void parser::debug(const int &parser) { std::cout << "parser::debug " << parser; }