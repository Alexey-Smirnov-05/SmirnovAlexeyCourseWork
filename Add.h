#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;
using namespace System::IO;  // Нужно для работы с файлами

#include "SavePlaylistManager.h"  // Подключаем заголовочный файл

ref class Add {
private:
	ListBox^ trackList;
	List<String^>^ paths;
	SavePlaylistManager^ savePlaylistManager;  // Добавляем менеджер сохранения

public:
	Add(ListBox^ list, List<String^>^ p, SavePlaylistManager^ saveMgr) {
		trackList = list;
		paths = p;
		savePlaylistManager = saveMgr;  // Сохраняем ссылку на объект сохранения
	}

    void Execute()
    {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Multiselect = true;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			array<String^>^ files = ofd->SafeFileNames; // Локальная переменная для файлов
			array<String^>^ newPaths = ofd->FileNames; // Локальная переменная для путей

			List<String^>^ invalidFiles = gcnew List<String^>(); // Список для неподходящих файлов

			for (int x = 0; x < files->Length; x++)
			{
				// Проверяем расширение файла
				String^ extension = Path::GetExtension(newPaths[x]);
				if (extension == ".mp3" || extension == ".wma" || extension == ".wav" ||
					extension == ".m4a" || extension == ".aac" ||
					extension == ".mp4" || extension == ".wmv" ||
					extension == ".avi" || extension == ".mov") {
					trackList->Items->Add(files[x]);
					paths->Add(newPaths[x]); // Добавляем новые пути в список
				}
				else {
					invalidFiles->Add(files[x]); // Добавляем неподходящий файл в список
				}
			}
			
			// Сохраняем плейлист после добавления треков
			savePlaylistManager->Execute();  // Вызываем сохранение

			// Если есть неподходящие файлы, выводим сообщение
			if (invalidFiles->Count > 0) {
				String^ message = "Следующие файлы были отклонены из-за неподходящего расширения:\n";
				for each (String ^ invalidFile in invalidFiles) {
					message += invalidFile + "\n";
				}
				MessageBox::Show(message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
    }
};
