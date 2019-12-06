#pragma once

#ifdef SF_PLATFORM_WINDOWS

extern Stupefy::Application* Stupefy::CreateApplication();

int main(int argc, char** argv)
{
	Stupefy::Log::Init();
	SF_CORE_WARN("Initialized");
	int a = 10;
	SF_CLIENT_INFO("HELLO! Var={0}",a);

	auto app = Stupefy::CreateApplication();
	app->Run();
	delete app;
}

#endif