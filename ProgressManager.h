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
			// �������� ������ ��������-����
			int progressBarWidth = progressBar->Width;
			// ���������, �� ����� ������� � ����� ����� ���������� ������������
			double newPosition = (double)e->X / progressBarWidth * player->currentMedia->duration;
			// ������������� ������� ���������������
			player->Ctlcontrols->currentPosition = newPosition;
			// ��������� �������� ��� � ����� ������� ����������
			progressBar->Value = (int)newPosition;
			labelTrackStart->Text = TimeSpan::FromSeconds(newPosition).ToString("mm\\:ss");
		}
    }
};
