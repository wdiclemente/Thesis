#include <iostream>
#include <sstream>   
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "TH1F.h"
#include "TColor.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TRint.h"
#include "TROOT.h"


using namespace std;

bool extractDate(const std::string& s, int& d, int& m, int& y);
string  extractNextDate(const std::string& s, int& d, int& m, int& y);
TLegend* makeLegend(vector<string> legendNames, vector<TObject*> legendObjects, vector<string> legendTypes, int cols, float x1, float y1, float x2, float y2);
void ATLAS2Label(Double_t x,Double_t y,const char* text, string fbtext);
void drawText(Double_t x,Double_t y, const char *ttext, double tsize, bool bold = false);
void paintText(Double_t x,Double_t y, Double_t angle, double tsize, const char *ttext);
void SetAtlasStyle();
TStyle* AtlasStyle();
int getDays(string day1, string day2);

int main()
{
  SetAtlasStyle();

  string value;
  vector<string> dates;
  vector<int> pages;
  int d, m, y;

  //----------------------- 
  //Read in the pages.cvs
  //-----------------------
  ifstream file ( "pages.csv" ); 
  getline ( file, value, '\n' ); 
  while ( file.good() )
  {
    getline ( file, value, ',' ); 
    if(value != "")
      dates.push_back(value); 
    getline ( file, value, '\n' ); 
    value.erase(0, 1);
    if(value != "")
      pages.push_back(std::stoi(value)); 
  }

  //----------------------- 
  //Calculate the difference in days between the first and last entry 
  //-----------------------
  int totalDiff = getDays(dates.front(), dates.back());
  //cout << totalDiff << endl;


  //----------------------- 
  // Fill histogram with entries or duplicate entries on days with no update.
  //-----------------------

  TH1F* h = new TH1F("h", "h", totalDiff+1, 0, totalDiff+1);
  int tempDays;
  int fillDays = 0;
  for(int i = 0; i < dates.size()-1; i++)
  {
    tempDays = getDays(dates[i], dates[i+1]);
    //cout << "The difference between entry " << i << " and entry " << i + 1 << " is " << tempDays << endl;
    tempDays = tempDays+fillDays;
    for(int j = fillDays; j < tempDays; j++)
    {
      h->Fill(fillDays, pages[i]);
      //cout << "filling " <<  fillDays << endl;
      fillDays++;
    }
  }

  h->Fill(totalDiff, pages.back());

  //----------------------- 
  // Get intermediate date logos.
  //-----------------------

  int day = std::stoi(dates.front().substr(0,1))*10  + std::stoi(dates.front().substr(1,2)); 
  int newday1 = day  + totalDiff/6; 
  int newday2 = day  + (totalDiff/6)*2; 
  int newday3 = day  + (totalDiff/6)*3; 
  int newday4 = day  + (totalDiff/6)*4; 
  int newday5 = day  + (totalDiff/6)*5; 

  string d1 = dates.front();
  string d2 = dates.front();
  string d3 = dates.front();
  string d4 = dates.front();
  string d5 = dates.front();

  d1.replace(0,2, to_string(newday1)); 
  d2.replace(0,2, to_string(newday2)); 
  d3.replace(0,2, to_string(newday3)); 
  d4.replace(0,2, to_string(newday4)); 
  d5.replace(0,2, to_string(newday5)); 

  d1 = extractNextDate(d1, d, m, y);
  d2 = extractNextDate(d2, d, m, y);
  d3 = extractNextDate(d3, d, m, y);
  d4 = extractNextDate(d4, d, m, y);
  d5 = extractNextDate(d5, d, m, y);

  int max = pages.back();

  //----------------------- 
  // Histogram style settings
  //-----------------------


  if(max < 101)
    h->GetYaxis()->SetRangeUser(0,100);
  else if(max < 201)
    h->GetYaxis()->SetRangeUser(0,200);
  else if(max < 301)
    h->GetYaxis()->SetRangeUser(0,300);
  else if(max < 401)
    h->GetYaxis()->SetRangeUser(0,400);
  else if(max < 501)
    h->GetYaxis()->SetRangeUser(0,500);
  else
  {
    cerr << "Stop overachiving" << endl; 
    return 0;
  }


  h->SetLineColor(kBlack); 
  h->SetLineWidth(2); 
  //-------------------
  //You should choose between kBlue-7, kCyan-3, kGreen-9, or kYellow -9
  //to adhere to the kHilesh color scheme 
  //-------------------
  h->SetFillColor(kCyan-3); 
  h->SetFillStyle(1001); 
  h->GetXaxis()->SetTitle("Day");
  h->GetYaxis()->SetTitle("Pages");
  h->GetYaxis()->SetTitleSize(0.06);
  h->GetYaxis()->SetTitleOffset(0.90);
  h->GetYaxis()->SetLabelSize(0.05);
  h->GetYaxis()->SetLabelOffset(0.007);
  h->GetXaxis()->SetLabelOffset(1.7);
  h->GetXaxis()->SetNdivisions(6, 2, 0, kFALSE);
  h->GetXaxis()->SetTitleOffset(1.60);
  h->GetYaxis()->SetNdivisions(10,4, 0, kTRUE);


  //----------------------- 
  // Draw and Save 
  //-----------------------

  TCanvas *c = new TCanvas("c","",0,0,800,600);
  h->Draw("hist");
  ATLAS2Label(0.20,0.85,"Thesis", "");
  paintText(0.11, 0.07, 30, 0.032, dates.front().c_str());
  paintText(0.90, 0.07, 30, 0.032, dates.back().c_str());
  paintText(0.24, 0.07, 30, 0.032, d1.c_str());
  paintText(0.37, 0.07, 30, 0.032, d2.c_str());
  paintText(0.50, 0.07, 30, 0.032, d3.c_str());
  paintText(0.63, 0.07, 30, 0.032, d4.c_str());
  paintText(0.76, 0.07, 30, 0.032, d5.c_str());
  c->Print("thesis_lumi.pdf");

}
bool extractDate(const std::string& s, int& d, int& m, int& y){
  std::istringstream is(s);
  char delimiter;
  if (is >> d >> delimiter >> m >> delimiter >> y) {
    struct tm t = {0};
    t.tm_mday = d;
    t.tm_mon = m - 1;
    t.tm_year = y - 1900;
    t.tm_isdst = -1;

    // normalize:
    time_t when = mktime(&t);
    const struct tm *norm = localtime(&when);
    // the actual date would be:
    // m = norm->tm_mon + 1;
    // d = norm->tm_mday;
    // y = norm->tm_year;
    // e.g. 29/02/2013 would become 01/03/2013

    // validate (is the normalized date still the same?):
    return (norm->tm_mday == d    &&
        norm->tm_mon  == m - 1 &&
        norm->tm_year == y - 1900);
  }
  return false;
}
string extractNextDate(const std::string& s, int& d, int& m, int& y){
  std::istringstream is(s);
  char delimiter;
  if (is >> d >> delimiter >> m >> delimiter >> y) {
    struct tm t = {0};
    t.tm_mday = d;
    t.tm_mon = m - 1;
    //t.tm_year = y - 1900;
    t.tm_year = y;
    t.tm_isdst = -1;

    // normalize:
    time_t when = mktime(&t);
    const struct tm *norm = localtime(&when);
    // the actual date would be:
    m = norm->tm_mon + 1;
    d = norm->tm_mday;
    y = norm->tm_year;
    t.tm_year = y - 1900;
    // e.g. 29/02/2013 would become 01/03/2013

    string temp_d; 

    if(d < 10)
      temp_d = "0"+to_string(d);
    else 
      temp_d = to_string(d);

    if(m < 10)
      temp_d = temp_d + "/0"+to_string(m);
    else 
      temp_d = temp_d + "/"+to_string(m);

    temp_d = temp_d + "/"+to_string(y);

    return temp_d;
  }
  return "";

}
int getDays(string day1, string day2)
{
  int d,m,y;
  struct std::tm a;
  struct std::tm b;
  if (extractDate(day1, d, m, y))
  {
    y=y+100;
    m--;
    a = {0,0,0,d,m,y};
  }

  if (extractDate(day2, d, m, y))
  {
    y=y+100;
    m--;
    b = {0,0,0,d,m,y};
  }

  std::time_t x = std::mktime(&a);
  std::time_t y1 = std::mktime(&b);
  double difference;
  if ( x != (std::time_t)(-1) && y1 != (std::time_t)(-1) )
  {
    difference = std::difftime(y1, x) / (60 * 60 * 24);
  }

  return (int) difference;
}

void SetAtlasStyle ()
{
  static TStyle* atlasStyle = 0;
  //std::cout << "\nApplying ATLAS style settings...\n" << std::endl ;
  if ( atlasStyle==0 ) atlasStyle = AtlasStyle();
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
}
TStyle* AtlasStyle()
{
  TStyle *atlasStyle = new TStyle("ATLAS","Atlas style");

  // use plain black on white colors
  Int_t icol=0; // WHITE
  atlasStyle->SetFrameBorderMode(icol);
  atlasStyle->SetFrameFillColor(icol);
  atlasStyle->SetCanvasBorderMode(icol);
  atlasStyle->SetCanvasColor(icol);
  atlasStyle->SetPadBorderMode(icol);
  atlasStyle->SetPadColor(icol);
  atlasStyle->SetStatColor(icol);
  //atlasStyle->SetFillColor(icol); // don't use: white fill color for *all* objects

  // set the paper & margin sizes
  atlasStyle->SetPaperSize(20,26);

  // set margin sizes
  atlasStyle->SetPadTopMargin(0.05);
  atlasStyle->SetPadRightMargin(0.05);
  atlasStyle->SetPadBottomMargin(0.16);
  atlasStyle->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  atlasStyle->SetTitleXOffset(1.4);
  atlasStyle->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  atlasStyle->SetTextFont(font);

  atlasStyle->SetTextSize(tsize);
  atlasStyle->SetLabelFont(font,"x");
  atlasStyle->SetTitleFont(font,"x");
  atlasStyle->SetLabelFont(font,"y");
  atlasStyle->SetTitleFont(font,"y");
  atlasStyle->SetLabelFont(font,"z");
  atlasStyle->SetTitleFont(font,"z");

  atlasStyle->SetLabelSize(tsize,"x");
  atlasStyle->SetTitleSize(tsize,"x");
  atlasStyle->SetLabelSize(tsize,"y");
  atlasStyle->SetTitleSize(tsize,"y");
  atlasStyle->SetLabelSize(tsize,"z");
  atlasStyle->SetTitleSize(tsize,"z");
  // use bold lines and markers
  atlasStyle->SetMarkerStyle(20);
  atlasStyle->SetMarkerSize(1.2);
  atlasStyle->SetHistLineWidth(2.);
  atlasStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars (as recommended in ATLAS figure guidelines)
  //atlasStyle->SetErrorX(0.0001);
  // get rid of error bar caps
  atlasStyle->SetEndErrorSize(0.);

  // do not display any of the standard histogram decorations
  atlasStyle->SetOptTitle(0);
  //atlasStyle->SetOptStat(1111);
  atlasStyle->SetOptStat(0);
  //atlasStyle->SetOptFit(1111);
  atlasStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  atlasStyle->SetPadTickX(1);
  atlasStyle->SetPadTickY(1);

  return atlasStyle;

}
TLegend* makeLegend(vector<string> legendNames, vector<TObject*> legendObjects, vector<string> legendTypes, int cols, float x1, float y1, float x2, float y2)
{
  if(legendNames.size() != legendObjects.size() || legendNames.size() != legendTypes.size() || legendTypes.size() != legendNames.size())
  {
    std::cerr << "Check your legend input sizes..." << endl;
    cout << "Objects" << legendObjects.size() << endl;
    cout << "Titles" << legendNames.size() << endl;
    cout << "Types" << legendTypes.size() << endl;
    exit(0);
    return nullptr;
  }

  TLegend *leg = new TLegend(x1,y1,x2,y2);
  leg->SetLineColor(0);
  leg->SetFillStyle(0);
  leg->SetShadowColor(0);
  leg->SetBorderSize(0);
  leg->SetNColumns(cols);
  //gStyle->SetLegendTextSize(0.045);
  leg->SetTextSize(0.045);

  for(size_t i = 0; i < legendObjects.size(); i++)
  {
    auto o = legendObjects[i];
    auto n = legendNames[i];
    auto s = legendTypes[i];
    leg->AddEntry(o,n.c_str(),s.c_str());
  }

  float h = leg->GetY2()-leg->GetY1();
  float w = leg->GetX2()-leg->GetX1()*0.85;
  leg->SetMargin(leg->GetNColumns()*h/(leg->GetNRows()*w));
  if(cols == 1)
  {
    //gStyle->SetLegendTextSize(0.050);
    leg->SetTextSize(0.050);
    leg->SetMargin(0.25);
  }
  return leg;
} 
void ATLAS2Label(Double_t x,Double_t y,const char* text, string fbtext)
{
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextFont(72);
  l.SetTextSize(.060);
  l.SetTextColor(kBlack);

  double delx = 0.14*696*gPad->GetWh()/(472*gPad->GetWw());

  l.DrawLatex(x,y,"ATLAS");

  TLatex k;
  k.SetNDC(kTRUE);
  k.SetTextFont(42);
  k.SetTextSize(.055);
  k.SetTextColor(kBlack);
  k.DrawLatex(x+delx,y,text);

  delx = 0.06*696*gPad->GetWh()/(472*gPad->GetWw());

  if(fbtext != "")
  {
    TLatex p;
    p.SetNDC();
    p.SetTextFont(42);
    p.SetTextSize(.055);
    p.SetTextColor(kBlack);
    p.DrawLatex(x,y-delx,("#scale[0.7]{#sqrt{s}=13TeV, " + fbtext + " fb^{-1}}").c_str());
  }
}
void drawText(Double_t x,Double_t y, const char *ttext, double tsize, bool bold)
{
  TLatex l;
  l.SetNDC();
  l.SetTextFont(42);
  if(bold)
    l.SetTextFont(62);
  l.SetTextSize(tsize);
  l.SetTextColor(kBlack);
  l.DrawLatex(x,y,ttext);
}
void paintText(Double_t x,Double_t y, Double_t angle, double tsize, const char *ttext)
{
  TText *t = new TText(x,y,ttext);
  t->SetNDC();
  t->SetTextColor(kBlack);
  t->SetTextFont(42);
  t->SetTextSize(tsize);
  t->SetTextAngle(angle);
  t->Draw();
}

