#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release build
	return "assets";
#else
	return "C:/Users/OLEGIS/STUDY/UDEMY/LearnCppAndMakeAGameFromScratch04/Projects1/LightYearsGame/assets/";
#endif
}
