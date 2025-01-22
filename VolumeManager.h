#pragma once
using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class VolumeManager {
private:
    AxWindowsMediaPlayer^ player;
    TrackBar^ trackBar;
    Label^ labelVolume;
    int currentVolume;  // Переменная для хранения текущей громкости

public:
    VolumeManager(AxWindowsMediaPlayer^ p, TrackBar^ tb, Label^ lv) {
        player = p;
        trackBar = tb;
        labelVolume = lv;
        currentVolume = 50;  // Устанавливаем громкость по умолчанию
        player->settings->volume = currentVolume;
        trackBar->Value = currentVolume;
        labelVolume->Text = currentVolume.ToString() + "%";
    }

    void Execute() {
        currentVolume = trackBar->Value; // Получаем текущее значение громкости
        player->settings->volume = currentVolume; // Устанавливаем громкость
        labelVolume->Text = currentVolume.ToString() + "%"; // Обновляем текст метки громкости
    }

    int GetCurrentVolume() {
        return currentVolume;  // Возвращает текущий уровень громкости
    }
};
