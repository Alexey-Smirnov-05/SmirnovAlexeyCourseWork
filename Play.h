#pragma once
#include <Windows.h> // ��������� include ��� Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // ��������� using namespace System;

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
		// ���������, ���������� �� ��������� ����
		if (trackList->SelectedIndex != -1 && trackList->SelectedIndex < paths->Count) {
			// ���� ����� �� �����, ���������� ���������������
			if (player->playState == WMPLib::WMPPlayState::wmppsPaused) {
				player->Ctlcontrols->play(); // ���������� ���������������
				labelMessage->Text = "Playing...";
			}
			else if (player->playState != WMPLib::WMPPlayState::wmppsPlaying) {
				// ���� ����� �� �������������, ������������� URL � �������� ���������������
				player->URL = paths[trackList->SelectedIndex]; // ������������� URL
				player->Ctlcontrols->play(); // ������������� ����
				labelMessage->Text = "Playing...";
			}
		}
		else {
			// ���� ���� ��� ������, ���������� ��������� ������
			player->Ctlcontrols->stop();
			labelMessage->Text = "Stop";
		}
    }
};