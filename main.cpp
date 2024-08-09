#include"./macos/main.macos.hpp"
#include"./windows/main.windows.hpp"

#if defined(__APPLE__) || defined(__MACH__)
	#define OS_MACOS
#elif defined(_WIN32) || defined(_WIN64)
	#define OS_WINDOWS
#else
	#define OS_UNKNOW
#endif

int main (int argc, char const *argv[]) {

	#ifdef OS_MACOS
		return macos::main(argc, argv);
	#elif OS_WINDOWS
		return windowsMain(argc, argv)
	#endif

	return 0;
}
