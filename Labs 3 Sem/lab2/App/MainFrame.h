//
// Created by Fedor Bulygin on 05.12.2022.
//

#ifndef LAB2_3_MAINFRAME_H
#define LAB2_3_MAINFRAME_H

#include "Presenter.h"
#include <string>
#include <wx/statline.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    wxPanel *panel;
    wxStaticText *backPack, *subSequence, *txtSlider1, *txtSlider2,  *EnterSubSequence;
    wxSlider *slider1, *slider2;
    wxButton *btnFindSubSequence, *btnBackpack, *btnClearTxtPrint;
    wxTextCtrl *txtSubSequence, *txtPrint;
    wxStaticLine *staticLine;

    Presenter presenter;

    void OnClearTextPrintBtnClicked(wxCommandEvent& evt);
    void OnFindMostPopularBtnClicked(wxCommandEvent& evt);
    void OnBackPackBtnClicked(wxCommandEvent& evt);
};

#endif //LR2_MAINFRAME_H

