#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class ProgressManager {
private:
    AxWindowsMediaPlayer^ player;
    ProgressBar^ progressBar;
	Label^ labelTrackStart;

public:
	ProgressManager(AxWindowsMediaPlayer^ p, ProgressBar^ pb, Label^ trackStart) {
		player = p;
		progressBar = pb;
		labelTrackStart = trackStart;
	}

    void Execute(MouseEventArgs^ e) {
		if (player->currentMedia != nullptr) {
			// ѕолучаем ширину прогресс-бара
			int progressBarWidth = progressBar->Width;
			// ¬ычисл€ем, на какую позицию в треке хочет перемотать пользователь
			double newPosition = (double)e->X / progressBarWidth * player->currentMedia->duration;
			// ”станавливаем позицию воспроизведени€
			player->Ctlcontrols->currentPosition = newPosition;
			// ќбновл€ем прогресс бар и метку времени немедленно
			progressBar->Value = (int)newPosition;
			labelTrackStart->Text = TimeSpan::FromSeconds(newPosition).ToString("mm\\:ss");
		}
    }
};
