#include <stdio.h>

namespace lu
{
	// a macro
	#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}