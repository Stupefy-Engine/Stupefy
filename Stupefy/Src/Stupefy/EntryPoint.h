#pragma once

#ifdef SF_PLATFORM_WINDOWS

extern Stupefy::Application* Stupefy::CreateApplication();

int main(int argc, char** argv)
{
	Stupefy::Log::Init();
	SF_CORE_INFO("Initialized");
	SF_CLIENT_INFO("Hello! Welcome to Stupefy...");

	auto app = Stupefy::CreateApplication();
	app->Run();
	delete app;
}

#endif