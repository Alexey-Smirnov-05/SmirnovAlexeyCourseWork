#pragma once
using namespace System::Windows::Forms;
using namespace AxWMPLib;

ref class Pause {
private:
    AxWindowsMediaPlayer^ player;
    Label^ labelMessage;

public:
    Pause(AxWindowsMediaPlayer^ p, Label^ msg) {
        player = p;
        labelMessage = msg;
    }

    void Execute() {
        if (player->playState == WMPLib::WMPPlayState::wmppsPlaying) {
            player->Ctlcontrols->pause();
            labelMessage->Text = "Pause";
        }
    }
};
