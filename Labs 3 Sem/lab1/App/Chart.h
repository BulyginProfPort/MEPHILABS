#pragma once

#include <wx/wx.h>
#include <vector>
#include <string>

class Chart : public wxWindow{
private:
    void OnPaint(wxPaintEvent& evt);
    static std::tuple<int, double, double> calculateChartSegmentCountAndRange(double origLow, double origHigh);

public:
    std::vector<double> values;
    std::string title;

    Chart(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
};