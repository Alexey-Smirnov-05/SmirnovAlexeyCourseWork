#pragma once
#include <Windows.h> // Добавляем include для Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // Добавляем using namespace System;

ref class IndexManager { 
private:
	AxWindowsMediaPlayer^ player;
	ListBox^ trackList;
	List<String^>^ paths;
	Label^ labelMessage;
	Timer^ timer;
	TrackBar^ trackBar;
	Label^ labelVolume;
	int currentVolume;  // Локальная переменная громкости

public:
	IndexManager(AxWindowsMediaPlayer^ p, ListBox^ list, List<String^>^ pths, Label^ msg, Timer^ tmr, TrackBar^ tb, Label^ lv) {
		player = p;
		trackList = list;
		paths = pths;
		labelMessage = msg;
		timer = tmr;
		trackBar = tb;
		labelVolume = lv;
		currentVolume = 50;  // Устанавливаем громкость по умолчанию
	}

	void Execute(int volume) {
		if (trackList->SelectedIndex != -1) {
			// Проверяем, существует ли выбранный трек
			if (trackList->SelectedIndex < paths->Count) {
				player->URL = paths[trackList->SelectedIndex]; // Используем List
				player->Ctlcontrols->play();
				labelMessage->Text = "Playing...";
				timer->Start();

				player->settings->volume = volume;  // Устанавливаем громкость напрямую
				trackBar->Value = volume;
				labelVolume->Text = volume.ToString() + "%";
			}
			else {
				// Если трек был удален, сбрасываем состояние
				player->Ctlcontrols->stop();
				labelMessage->Text = "Stop";
			}
		}
	}
};