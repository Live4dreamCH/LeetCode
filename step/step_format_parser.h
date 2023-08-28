#include "load_step_file.h"

// 解析文件类
class StepFormatParser
{
public:
    StepFormatParser();

    void print() const;

private:
    LoadStepFile loader;
};

namespace parser
{
    void debug(const int &parser);
}