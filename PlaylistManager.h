#pragma once
#include <Windows.h> // ��������� include ��� Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // ��������� using namespace System;

#include "SavePlaylistManager.h"  // ���������� �������� ����������

ref class PlaylistManager {
private:
    ListBox^ trackList;
    List<String^>^ paths;
	Label^ labelMessage;
	AxWindowsMediaPlayer^ player;
	SavePlaylistManager^ savePlaylistManager;  // ��������� �������� ����������

public:
    PlaylistManager(ListBox^ list, List<String^>^ pths, Label^ msg, AxWindowsMediaPlayer^ p, SavePlaylistManager^ saveMgr) {
        trackList = list;
        paths = pths;
		labelMessage = msg;
		player = p;
		savePlaylistManager = saveMgr;  // ��������� ������ �� ������ ����������
    }

    void Execute(KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Delete) {
			int selectedIndex = trackList->SelectedIndex;
			if (selectedIndex != -1) {
				// ������������� ���������������, ���� ���� ���������
				if (player->URL == paths[selectedIndex]) {
					player->Ctlcontrols->stop(); // ������������� ���������������
					labelMessage->Text = "Stop"; // ��������� ���������
				}
				// ������� ���� �� ������
				trackList->Items->RemoveAt(selectedIndex);
				paths->RemoveAt(selectedIndex); // ������� ���� �� ������
				savePlaylistManager->Execute();  // ��������� ���������
			}
		}
    }
};
