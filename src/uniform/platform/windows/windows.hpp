#include <uniform/application/application.hpp>

#ifndef WINDOWS_HPP
#define WINDOWS_HPP

# if defined(_RELEASE_)
#  if defined(WINAPI)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
#  else
int WinMain()
#  endif
# else
int main()
# endif
{
  Uniform::IApplication *application = Uniform::CreateApplication();
  application->run();
  delete application;
  return 0;
}

#endif