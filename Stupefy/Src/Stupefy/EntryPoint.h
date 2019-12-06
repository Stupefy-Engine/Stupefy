#pragma once

#ifdef SF_PLATFORM_WINDOWS

extern Stupefy::Application* Stupefy::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Stupefy::CreateApplication();
	app->Run();
	delete app;
}

#endif