#pragma once
using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class VolumeManager {
private:
    AxWindowsMediaPlayer^ player;
    TrackBar^ trackBar;
    Label^ labelVolume;
    int currentVolume;  // ���������� ��� �������� ������� ���������

public:
    VolumeManager(AxWindowsMediaPlayer^ p, TrackBar^ tb, Label^ lv) {
        player = p;
        trackBar = tb;
        labelVolume = lv;
        currentVolume = 50;  // ������������� ��������� �� ���������
        player->settings->volume = currentVolume;
        trackBar->Value = currentVolume;
        labelVolume->Text = currentVolume.ToString() + "%";
    }

    void Execute() {
        currentVolume = trackBar->Value; // �������� ������� �������� ���������
        player->settings->volume = currentVolume; // ������������� ���������
        labelVolume->Text = currentVolume.ToString() + "%"; // ��������� ����� ����� ���������
    }

    int GetCurrentVolume() {
        return currentVolume;  // ���������� ������� ������� ���������
    }
};
