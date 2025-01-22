#pragma once
#include <Windows.h> // ��������� include ��� Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // ��������� using namespace System;
using namespace System::IO;  // ����� ��� ������ � �������

ref class SavePlaylistManager {
private:
    List<String^>^ paths;  // ������ ����� ������

public:
    SavePlaylistManager(List<String^>^ pths) {
        paths = pths;
    }

    void Execute() {
        StreamWriter^ writer = gcnew StreamWriter("playlist.txt");  // ��������� ���� ��� ������
        for each (String ^ path in paths) {
            writer->WriteLine(path);  // ���������� ������ ���� � ����
        }
        writer->Close();  // ��������� ����� ������
    }
};
