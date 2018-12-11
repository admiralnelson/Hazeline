#include <iostream>
#include <Hazel.h>

#define HZ_BUILD_LINUX

class Sandbox: public Hazel::Application
{
    public:
        Sandbox()
        {

        }
        ~Sandbox()
        {

        }
};

extern Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}


int main()
{
    Hazel::Log::Init();
    HZ_CORE_WARN("Log started");
    auto a = 100;
    HZ_INFO("TEST variable={0}", a);

    auto program = Hazel::CreateApplication();
    program->Run();
    delete program;
    return EXIT_SUCCESS;
}

