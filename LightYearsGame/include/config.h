#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release build
	return "assets/";
#else
	return "C:/Users/olegi/Documents/STUDY/UDEMY/4_LearnCppAndMakeAGameFromScratch/Projects1/LightYears/LightYearsGame/assets/";
#endif
}
