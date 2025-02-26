#pragma once
#include <format>
#include <iostream>

#define LOG(fmt, ...) std::cout << std::format(fmt __VA_OPT__(,) __VA_ARGS__) << std::endl;
