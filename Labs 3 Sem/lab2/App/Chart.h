//
// Created by Fedor Bulygin on 05.12.2022.
//

#ifndef LAB2_3_CHART_H
#define LAB2_3_CHART_H

#include <wx/wx.h>
#include <vector>
#include <string>

class Chart : public wxWindow{
public:
    Chart(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    Chart(int i);

    std::vector<double> values;
    std::string title;

private:
    void OnPaint(wxPaintEvent& evt);
    std::tuple<int, double, double> calculateChartSegmentCountAndRange(double origLow, double origHigh);
};


#endif //LAB2_3_CHART_H
