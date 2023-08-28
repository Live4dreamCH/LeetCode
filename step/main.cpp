#include <iostream>
#include "load_step_file.h"
#include "step_format_parser.h"

LoadStepFile global;

int main()
{
    LoadStepFile f;
    parser::debug(1);
    StepFormatParser parser;
    loader::debug(2);
    return 0;
}