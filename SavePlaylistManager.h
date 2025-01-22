#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;
using namespace System::IO;  // Нужно для работы с файлами

ref class SavePlaylistManager {
private:
    List<String^>^ paths;  // Список путей треков

public:
    SavePlaylistManager(List<String^>^ pths) {
        paths = pths;
    }

    void Execute() {
        StreamWriter^ writer = gcnew StreamWriter("playlist.txt");  // Открываем файл для записи
        for each (String ^ path in paths) {
            writer->WriteLine(path);  // Записываем каждый путь в файл
        }
        writer->Close();  // Закрываем поток записи
    }
};
