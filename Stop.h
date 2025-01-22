#pragma once

using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class Stop
{
private:
    AxWindowsMediaPlayer^ player;
    ProgressBar^ progressBar;
    Label^ labelTrackStart;
    Label^ labelMessage;

public:
    Stop(AxWindowsMediaPlayer^ playerControl, ProgressBar^ progress, Label^ trackStart, Label^ message)
    {
        this->player = playerControl;
        this->progressBar = progress;
        this->labelTrackStart = trackStart;
        this->labelMessage = message;
    }

    void Execute()
    {
        player->Ctlcontrols->stop();
        player->Ctlcontrols->currentPosition = 0; // Сбрасываем позицию
        progressBar->Value = 0; // Обновляем progressBar
        labelTrackStart->Text = "00:00"; // Сбрасываем метку времени
        labelMessage->Text = "Stop"; // Обновляем сообщение
    }
};
