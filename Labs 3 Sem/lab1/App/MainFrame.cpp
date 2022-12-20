//
// Created by Fedor Bulygin on 24.10.2022.
//
#include "Chart.h"
#include "MainFrame.h"
#include "../Tests/test.h"
#include <wx/wx.h>
#include <wx/listbook.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    panel = new wxPanel(this);

    wxSystemAppearance s = wxSystemSettings::GetAppearance();
    if (s.IsDark())
        panel->SetBackgroundColour(*wxBLACK);
    else
        panel->SetBackgroundColour(*wxLIGHT_GREY);

    sorts.Add("Heap");
    sorts.Add("Quick");
    sorts.Add("Shell");

    //Создаем окно вывода
    rbFirstSort = new wxRadioBox(panel, wxID_ANY, "First Sort", wxPoint(30, 20), wxDefaultSize, sorts);
    rbSecondSort = new wxRadioBox(panel, wxID_ANY, "Second Sort", wxPoint(300, 20), wxDefaultSize, sorts);

    rbSecondSort->SetSelection(1);

    new wxStaticText(panel, wxID_ANY, "Number of elements: ", wxPoint(30, 170), wxDefaultSize);

    slider = new wxSlider(panel, wxID_ANY, 850, 10, 100000, wxPoint(30, 180), wxSize(200, -1), wxSL_VALUE_LABEL);

    //Создаем кнопки
    btnCreate = new wxButton(panel, wxID_ANY, "Create arrays", wxPoint(30, 80), wxSize(120, -1));
    btnPrint = new wxButton(panel, wxID_ANY, "Print arrays", wxPoint(30, 105), wxSize(120, -1));
    btnSort = new wxButton(panel, wxID_ANY, "Sort arrays", wxPoint(30, 130), wxSize(120, -1));
    btnGraphs = new wxButton(panel, wxID_ANY, "Construct graphs", wxPoint(250, 200), wxSize(500, -1));
    btnTests = new wxButton(panel, wxID_ANY, "Tests", wxPoint(155, 105), wxSize(90, -1));

    txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(250, 80), wxSize(500, 110), wxTE_MULTILINE);
    txtPrint->SetBackgroundColour(wxTransparentColour);

    btnCreate->Bind(wxEVT_BUTTON, &MainFrame::OnCreateBtnClickedI, this);
    btnPrint->Bind(wxEVT_BUTTON, &MainFrame::OnPrintBtnClicked, this);
    btnSort->Bind(wxEVT_BUTTON, &MainFrame::OnSortBtnClicked, this);
    btnGraphs->Bind(wxEVT_BUTTON, &MainFrame::OnGraphBtnClicked, this);
    btnTests->Bind(wxEVT_BUTTON, &MainFrame::OnTestsBtnClicked, this);

    CreateStatusBar();

    chart1 = new Chart(panel, 121, wxPoint(30, 240), wxSize(750, 250));
    chart1->values = { 0.0,0.25, 0.35, 0.75, 0.99 };

    chart2 = new Chart(panel, wxID_ANY, wxPoint(30, 520), wxSize(750, 250));
    chart2->values = { 0.99,0.75,0.35,0.25,0.0 };

}

void MainFrame::OnCreateBtnClickedI(wxCommandEvent& evt) {
    presenter1.createArr(slider->GetValue());
    presenter2.createArr(slider->GetValue());

    txtPrint->WriteText("Arrays were created!\n\n");
}

void MainFrame::OnPrintBtnClicked(wxCommandEvent& evt) {
    string arr1 = presenter1.getArr();
    string arr2 = presenter2.getArr();

    txtPrint->WriteText("First array: " + arr1 + "\n" + "Second array: " + arr2 + "\n\n");
}

void MainFrame::OnSortBtnClicked(wxCommandEvent& evt) {
    string time1 = presenter1.sortArr(sorts_std[rbFirstSort->GetSelection()] );
    string time2 = presenter2.sortArr(sorts_std[rbSecondSort->GetSelection()] );

    txtPrint->WriteText("Arrays were sorted!\n");
    txtPrint->WriteText("Sorting time first array: " + time1 + " ms" + "\n");
    txtPrint->WriteText("Sorting time second array: " + time2 + " ms" + "\n\n");
}

void MainFrame::OnGraphBtnClicked(wxCommandEvent& evt) {
    vector<double> valVec1 = presenter1.getPointForGraph(sorts_std[ rbFirstSort->GetSelection()] );
    vector<double> valVec2 = presenter2.getPointForGraph(sorts_std[ rbSecondSort->GetSelection()] );

    std::cout<<endl;
    chart1 = new Chart(panel, 121, wxPoint(30, 240), wxSize(750, 250) );
    chart2 = new Chart(panel, wxID_ANY, wxPoint(30, 520), wxSize(750, 250) );

    chart1->title = sorts[rbFirstSort->GetSelection()] + " Sort";
    chart2->title = sorts[rbSecondSort->GetSelection()] + " Sort";
    chart1->values = valVec1;
    chart2->values = valVec2;

    wxSystemAppearance s = wxSystemSettings::GetAppearance();
    if ( true == s.IsDark() ) {
        chart1->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
        chart2->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
    }
    else{
        chart1->SetBackgroundColour(*wxWHITE);
        chart2->SetBackgroundColour(*wxWHITE);
    }

}
void MainFrame::OnTestsBtnClicked(wxCommandEvent& evt) {
    txtPrint->WriteText(SortTests());
}