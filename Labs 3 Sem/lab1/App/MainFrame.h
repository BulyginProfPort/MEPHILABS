#pragma once
#include "Chart.h"
#include "Shower.h"
#include <wx/wx.h>
class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title);

private:
    wxTextCtrl *txtPrint;
    wxStaticText *txtSlider{};
    wxPanel *panel;
    Chart *chart1, *chart2;
    wxRadioBox *rbFirstSort, *rbSecondSort;
    wxSlider *slider;
    wxButton *btnPrint, *btnSort, *btnGraphs, *btnCreate, *btnTests;
    wxArrayString sorts;

    string sorts_std[3] = {"Shaker", "Quick", "Shell"};
    Shower presenter1{}, presenter2{};

    void OnCreateBtnClickedI(wxCommandEvent &evt);
    void OnPrintBtnClicked(wxCommandEvent &evt);
    void OnSortBtnClicked(wxCommandEvent &evt);
    void OnGraphBtnClicked(wxCommandEvent &evt);
    void OnTestsBtnClicked(wxCommandEvent &evt);
};