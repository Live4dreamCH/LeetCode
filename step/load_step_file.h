#pragma once
// 加载文件类
// 声明
class LoadStepFile
{
public:
    // 1000行
    LoadStepFile();

    void print() const;
};

namespace loader
{
    void debug(const int &loader);
}