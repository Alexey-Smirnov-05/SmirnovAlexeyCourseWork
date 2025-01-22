#define WIN32_LEAN_AND_MEAN  // ��������� ����� ������������ ���������� Windows API
#define NOMINMAX             // ������������� ��������� � ��������� min/max Windows.h

#include "Player.h"
#include <Windows.h>

using namespace SmirnovAlexeyCourseWork;
using namespace System::Windows::Forms;

[STAThread]
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Player());
    return 0;
}
