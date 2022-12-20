//
// Created by Fedor Bulygin on 05.12.2022.
//
#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/listbook.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    panel = new wxPanel(this);

    wxSystemAppearance s = wxSystemSettings::GetAppearance();
    if (s.IsDark())
        panel->SetBackgroundColour(*wxBLACK);
    else
        panel->SetBackgroundColour(*wxLIGHT_GREY);

    txtSlider1 = new wxStaticText(panel, wxID_ANY, "Number of items in pack: ", wxPoint(510, 45), wxDefaultSize);
    txtSlider2 = new wxStaticText(panel, wxID_ANY, "Max V of bag packz", wxPoint(750, 45), wxDefaultSize);

    slider1 = new wxSlider(panel, wxID_ANY, 3, 3, 10, wxPoint(510, 55), wxSize(200, -1), wxSL_VALUE_LABEL);
    slider2 = new wxSlider(panel, wxID_ANY, 100, 100, 2000, wxPoint(750, 55), wxSize(200, -1), wxSL_VALUE_LABEL);

    //Кнопки
    btnFindSubSequence = new wxButton(panel, wxID_ANY, "Find", wxPoint(25, 105), wxSize(200, -1));
    btnBackpack = new wxButton(panel, wxID_ANY, "Get result", wxPoint(505, 105), wxSize(445, -1));
    btnClearTxtPrint = new wxButton(panel, wxID_ANY, "Clear", wxPoint(25, 150), wxSize(1150, -1));

    btnFindSubSequence->Bind(wxEVT_BUTTON, &MainFrame::OnFindMostPopularBtnClicked, this);
    btnBackpack->Bind(wxEVT_BUTTON, &MainFrame::OnBackPackBtnClicked, this);
    btnClearTxtPrint->Bind(wxEVT_BUTTON, &MainFrame::OnClearTextPrintBtnClicked, this);

    subSequence = new wxStaticText(panel, wxID_ANY, "Find Most Popular Sub Sequence:", wxPoint(25, 20), wxDefaultSize);
    EnterSubSequence = new wxStaticText(panel, wxID_ANY, "Enter sequence:", wxPoint(25, 45), wxDefaultSize);
    backPack = new wxStaticText(panel, wxID_ANY, "BackPack:", wxPoint(510, 20), wxDefaultSize);

    staticLine = new wxStaticLine(panel, wxID_ANY, wxPoint(485, 5), wxSize(10, 130));

    txtSubSequence= new wxTextCtrl(panel, wxID_ANY, "", wxPoint(25, 70), wxSize(200, -1));
    txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(25, 185), wxSize(1150, 400), wxTE_MULTILINE);

    CreateStatusBar();
}

void MainFrame::OnClearTextPrintBtnClicked(wxCommandEvent& evt) {
    txtPrint->Clear();
}

void MainFrame::OnFindMostPopularBtnClicked(wxCommandEvent& evt) {
    string res = presenter.findMostPopularSubSequence(txtSubSequence->GetValue().ToStdString());
    txtPrint->WriteText(res + "\n\n");
}

void MainFrame::OnBackPackBtnClicked(wxCommandEvent& evt){
    string res = presenter.BackPack(slider1->GetValue(), slider2->GetValue());
    txtPrint->WriteText(res + "\n\n");
}