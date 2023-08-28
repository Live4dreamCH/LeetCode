#include <iostream>
#include "load_step_file.h"

// 加载文件类
// 定义
LoadStepFile::LoadStepFile() { std::cout << "init LoadStepFile\n"; }

void LoadStepFile::print() const { std::cout << "I'm LoadStepFile"; }

namespace loader
{
    void debug(const int &loader) { std::cout << "loader::debug " << loader; }
}