#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;

#include "SavePlaylistManager.h"  // Подключаем менеджер сохранения

ref class PlaylistManager {
private:
    ListBox^ trackList;
    List<String^>^ paths;
	Label^ labelMessage;
	AxWindowsMediaPlayer^ player;
	SavePlaylistManager^ savePlaylistManager;  // Добавляем менеджер сохранения

public:
    PlaylistManager(ListBox^ list, List<String^>^ pths, Label^ msg, AxWindowsMediaPlayer^ p, SavePlaylistManager^ saveMgr) {
        trackList = list;
        paths = pths;
		labelMessage = msg;
		player = p;
		savePlaylistManager = saveMgr;  // Сохраняем ссылку на объект сохранения
    }

    void Execute(KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Delete) {
			int selectedIndex = trackList->SelectedIndex;
			if (selectedIndex != -1) {
				// Останавливаем воспроизведение, если трек удаляется
				if (player->URL == paths[selectedIndex]) {
					player->Ctlcontrols->stop(); // Останавливаем воспроизведение
					labelMessage->Text = "Stop"; // Обновляем сообщение
				}
				// Удаляем трек из списка
				trackList->Items->RemoveAt(selectedIndex);
				paths->RemoveAt(selectedIndex); // Удаляем путь из списка
				savePlaylistManager->Execute();  // Сохраняем изменения
			}
		}
    }
};
