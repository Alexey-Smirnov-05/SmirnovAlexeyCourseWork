#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;

ref class Play {
private:
    AxWindowsMediaPlayer^ player;
    ListBox^ trackList;
    List<String^>^ paths;
    Label^ labelMessage;

public:
    Play(AxWindowsMediaPlayer^ p, ListBox^ list, List<String^>^ pths, Label^ msg) {
        player = p;
        trackList = list;
        paths = pths;
        labelMessage = msg;
    }

    void Execute() {
		// Проверяем, существует ли выбранный трек
		if (trackList->SelectedIndex != -1 && trackList->SelectedIndex < paths->Count) {
			// Если плеер на паузе, продолжаем воспроизведение
			if (player->playState == WMPLib::WMPPlayState::wmppsPaused) {
				player->Ctlcontrols->play(); // Продолжаем воспроизведение
				labelMessage->Text = "Playing...";
			}
			else if (player->playState != WMPLib::WMPPlayState::wmppsPlaying) {
				// Если плеер не воспроизводит, устанавливаем URL и начинаем воспроизведение
				player->URL = paths[trackList->SelectedIndex]; // Устанавливаем URL
				player->Ctlcontrols->play(); // Воспроизводим трек
				labelMessage->Text = "Playing...";
			}
		}
		else {
			// Если трек был удален, сбрасываем состояние плеера
			player->Ctlcontrols->stop();
			labelMessage->Text = "Stop";
		}
    }
};