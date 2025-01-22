#pragma once
#include <Windows.h> // ��������� include ��� Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // ��������� using namespace System;
using namespace System::IO;  // ����� ��� ������ � �������

ref class LoadPlaylistManager {
private:
    ListBox^ trackList;
    List<String^>^ paths;

public:
    LoadPlaylistManager(ListBox^ list, List<String^>^ pths) {
        trackList = list;
        paths = pths;
    }

    void Execute() {
        if (File::Exists("playlist.txt")) {  // ���������, ���������� �� ���� ���������
            StreamReader^ reader = gcnew StreamReader("playlist.txt");
            String^ line;
            while ((line = reader->ReadLine()) != nullptr) {
                trackList->Items->Add(System::IO::Path::GetFileName(line));  // ��������� ��� ����� � ������
                paths->Add(line);  // ��������� ������ ���� � ������ �����
            }
            reader->Close();
        }
    }
};