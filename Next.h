#pragma once
using namespace System::Windows::Forms;

ref class Next {
private:
    ListBox^ trackList;

public:
    Next(ListBox^ list) {
        trackList = list;
    }

    void Execute() {
        if (trackList->SelectedIndex < trackList->Items->Count - 1) {
            trackList->SelectedIndex++;
        }
    }
};
