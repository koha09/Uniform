#pragma once

#include <uniform/application/application.hpp>

#if defined(_RELEASE_)
# if defined(WINAPI)
  int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    INT nCmdShow
  )
# else
  int WinMain()
# endif
#else
 int main()
#endif
{
    Uniform::IApplication *application = Uniform::CreateApplication();
    application->Run();
    delete application;
    return 0;
}