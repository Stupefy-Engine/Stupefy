#include <Stupefy.h>

class Sandbox : public Stupefy::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Stupefy::Application* Stupefy::CreateApplication()
{
	return new Sandbox();
}