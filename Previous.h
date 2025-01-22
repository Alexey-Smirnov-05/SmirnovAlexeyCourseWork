#pragma once
using namespace System::Windows::Forms;

ref class Previous {
private:
    ListBox^ trackList;

public:
    Previous(ListBox^ list) {
        trackList = list;
    }

    void Execute() {
        if (trackList->SelectedIndex > 0) {
            trackList->SelectedIndex--;
        }
    }
};
