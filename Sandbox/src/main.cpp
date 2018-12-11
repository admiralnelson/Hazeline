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
    printf("TEst!");
    auto program = Hazel::CreateApplication();
    program->Run();
    delete program;
    return EXIT_SUCCESS;
}

