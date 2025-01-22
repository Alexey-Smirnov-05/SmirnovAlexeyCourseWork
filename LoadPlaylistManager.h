#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;
using namespace System::IO;  // Нужно для работы с файлами

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
        if (File::Exists("playlist.txt")) {  // Проверяем, существует ли файл плейлиста
            StreamReader^ reader = gcnew StreamReader("playlist.txt");
            String^ line;
            while ((line = reader->ReadLine()) != nullptr) {
                trackList->Items->Add(System::IO::Path::GetFileName(line));  // Добавляем имя файла в список
                paths->Add(line);  // Добавляем полный путь в список путей
            }
            reader->Close();
        }
    }
};