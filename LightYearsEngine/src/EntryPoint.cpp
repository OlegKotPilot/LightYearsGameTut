#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	ly::Application* app = ly::GetApplication();
	app->Run();
	delete app;
}