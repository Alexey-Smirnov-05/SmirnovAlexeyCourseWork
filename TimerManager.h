#pragma once
using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class TimerManager {
private:
    AxWindowsMediaPlayer^ player;
    ProgressBar^ progressBar;
    Label^ labelTrackStart;
    Label^ labelTrackEnd;

public:
    TimerManager(AxWindowsMediaPlayer^ p, ProgressBar^ pb, Label^ start, Label^ end) {
        player = p;
        progressBar = pb;
        labelTrackStart = start;
        labelTrackEnd = end;
    }

    void Execute() {
		if (player->currentMedia != nullptr) {
			if (player->playState == WMPLib::WMPPlayState::wmppsPlaying) {
				int duration = (int)player->Ctlcontrols->currentItem->duration;
				int currentPosition = (int)player->Ctlcontrols->currentPosition;

				// ������������� ������������ �������� ��� progressBar
				progressBar->Maximum = duration;

				// ������������� �������� ��� progressBar, ��������, ��� ��� � ���������� ���������
				if (currentPosition >= 0 && currentPosition <= duration) {
					progressBar->Value = currentPosition;
				}

				// ��������� ����� �������
				labelTrackStart->Text = player->Ctlcontrols->currentPositionString;
				labelTrackEnd->Text = player->Ctlcontrols->currentItem->durationString->ToString();
			}
			else if (player->playState == WMPLib::WMPPlayState::wmppsStopped) {
				labelTrackStart->Text = "00:00"; // ���������� ����� �������
			}
		}
    }
};
