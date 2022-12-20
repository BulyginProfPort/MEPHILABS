//
// Created by Fedor Bulygin on 05.12.2022.
//
#include <wx/wx.h>
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto* mainFrame = new MainFrame("lr2");
    mainFrame->SetClientSize(1200, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}