void NP_post_fit_xsec_ExpObs()
{
//=========Macro generated from canvas: xsec_can/xsec_can
//=========  (Fri Jun 15 09:11:43 2018) by ROOT version6.06/02
   TCanvas *canvas = new TCanvas("canvas", "canvas",0,61,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvas->SetHighLightColor(2);
   canvas->Range(0,0,1,1);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetLeftMargin(0);
   canvas->SetRightMargin(0);
   canvas->SetTopMargin(0);
   canvas->SetBottomMargin(0);
   canvas->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: main
   TPad *main = new TPad("main", "main",0,0,1,1);
   main->Draw();
   main->cd();
   main->Range(-1.405063e-05,-222784.8,1.126582e-05,1169620);
   main->SetFillColor(0);
   main->SetFillStyle(4000);
   main->SetBorderMode(0);
   main->SetBorderSize(0);
   main->SetTickx(1);
   main->SetTicky(1);
   main->SetLeftMargin(0.16);
   main->SetRightMargin(0.05);
   main->SetTopMargin(0.05);
   main->SetBottomMargin(0.16);
   main->SetFrameBorderMode(0);
   main->SetFrameBorderMode(0);
   
   TH1F *master__5 = new TH1F("master__5","Main Coordinate System",3,0.,3.);
   master__5->SetMinimum(1.2);
   master__5->SetMaximum(4.75);
   master__5->SetStats(0);
   master__5->SetFillStyle(0);
   master__5->SetLineColor(0);
   master__5->SetMarkerColor(0);
   master__5->GetXaxis()->SetLabelFont(42);
   master__5->GetXaxis()->SetLabelSize(0.055);
   master__5->GetXaxis()->SetLabelOffset(0.01);
   master__5->GetXaxis()->SetTitleSize(0.05);
   master__5->GetXaxis()->SetTitleOffset(1.4);
   master__5->GetXaxis()->SetTitleFont(42);
   master__5->GetYaxis()->SetTitle("#sigma^{fid.} [fb]");
   master__5->GetYaxis()->SetLabelFont(42);
   master__5->GetYaxis()->SetLabelSize(0.05);
   master__5->GetYaxis()->SetLabelOffset(0.01);
   master__5->GetYaxis()->SetTitleSize(0.05);
   master__5->GetYaxis()->SetTitleOffset(1.4);
   master__5->GetYaxis()->SetTitleFont(42);
   master__5->GetZaxis()->SetLabelFont(42);
   master__5->GetZaxis()->SetLabelSize(0.035);
   master__5->GetZaxis()->SetTitleSize(0.035);
   master__5->GetZaxis()->SetTitleFont(42);
   master__5->GetXaxis()->SetNoExponent(kTRUE);
   master__5->GetYaxis()->SetNdivisions(505);

   master__5->GetXaxis()->SetBinLabel(2,"Sherpa v2.2.2");
   master__5->GetXaxis()->SetBinLabel(3,"Powheg+Pythia8");
   master__5->GetXaxis()->SetBinLabel(1,"Data");

   master__5->Draw("hist");
   TH1F *poi__15 = new TH1F("poi__15","",3,0,3);
   poi__15->SetMinimum(1);
   poi__15->SetMaximum(3.610362);
   poi__15->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   poi__15->SetLineColor(ci);
   poi__15->GetXaxis()->SetLabelFont(42);
   poi__15->GetXaxis()->SetLabelSize(0.06);
   poi__15->GetXaxis()->SetTitleSize(0.035);
   poi__15->GetXaxis()->SetTitleFont(42);
   poi__15->GetYaxis()->SetLabelFont(42);
   poi__15->GetYaxis()->SetLabelSize(0.05);
   poi__15->GetYaxis()->SetTitleSize(0.05);
   poi__15->GetYaxis()->SetTitleFont(42);
   poi__15->GetZaxis()->SetLabelFont(42);
   poi__15->GetZaxis()->SetLabelSize(0.035);
   poi__15->GetZaxis()->SetTitleSize(0.035);
   poi__15->GetZaxis()->SetTitleFont(42);
   poi__15->Draw("same");


   // =======================================================
   // =======================================================
   //  SHERPA TOTAL UNCERTAINTYa
   // =======================================================
   // =======================================================
   Double_t Total_Uncert_exp_fx19[4] = {
   1,
   2,
   2,
   1};
   Double_t Total_Uncert_exp_fy19[4] = {
   2.35,
   2.35,
   1.77,
   1.77};
   TGraph *graph = new TGraph(4,Total_Uncert_exp_fx19,Total_Uncert_exp_fy19);
   graph->SetName("Total_Uncert_exp");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#99ccff");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_Total_Uncert_exp19 = new TH1F("Graph_Total_Uncert_exp19","Graph",100,0,1.1); // tot unc sherpa
   Graph_Total_Uncert_exp19->SetMinimum(1.712);
   Graph_Total_Uncert_exp19->SetMaximum(2.408);
   Graph_Total_Uncert_exp19->SetDirectory(0);
   Graph_Total_Uncert_exp19->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Total_Uncert_exp19->SetLineColor(ci);
   Graph_Total_Uncert_exp19->GetXaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp19->GetXaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp19->GetXaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp19->GetXaxis()->SetTitleFont(42);
   Graph_Total_Uncert_exp19->GetYaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp19->GetYaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp19->GetYaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp19->GetYaxis()->SetTitleFont(42);
   Graph_Total_Uncert_exp19->GetZaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp19->GetZaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp19->GetZaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Total_Uncert_exp19);
   
   graph->Draw("f");
   
   // =======================================================
   // =======================================================
   //  SHERPA SCALE VARIATIONS
   // =======================================================
   // =======================================================
   Double_t Scale_Variation_exp_fx20[4] = {
   1,
   2,
   2,
   1};
   Double_t Scale_Variation_exp_fy20[4] = {
   2.3,
   2.3,
   1.78,
   1.78};
   graph = new TGraph(4,Scale_Variation_exp_fx20,Scale_Variation_exp_fy20);
   graph->SetName("Scale_Variation_exp");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#3366ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(3353);

   ci = TColor::GetColor("#3366ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#3366ff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_Scale_Variation_exp20 = new TH1F("Graph_Scale_Variation_exp20","Graph",100,0,1.1);
   Graph_Scale_Variation_exp20->SetMinimum(1.728);
   Graph_Scale_Variation_exp20->SetMaximum(2.352);
   Graph_Scale_Variation_exp20->SetDirectory(0);
   Graph_Scale_Variation_exp20->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Scale_Variation_exp20->SetLineColor(ci);
   Graph_Scale_Variation_exp20->GetXaxis()->SetLabelFont(42);
   Graph_Scale_Variation_exp20->GetXaxis()->SetLabelSize(0.035);
   Graph_Scale_Variation_exp20->GetXaxis()->SetTitleSize(0.035);
   Graph_Scale_Variation_exp20->GetXaxis()->SetTitleFont(42);
   Graph_Scale_Variation_exp20->GetYaxis()->SetLabelFont(42);
   Graph_Scale_Variation_exp20->GetYaxis()->SetLabelSize(0.035);
   Graph_Scale_Variation_exp20->GetYaxis()->SetTitleSize(0.035);
   Graph_Scale_Variation_exp20->GetYaxis()->SetTitleFont(42);
   Graph_Scale_Variation_exp20->GetZaxis()->SetLabelFont(42);
   Graph_Scale_Variation_exp20->GetZaxis()->SetLabelSize(0.035);
   Graph_Scale_Variation_exp20->GetZaxis()->SetTitleSize(0.035);
   Graph_Scale_Variation_exp20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Scale_Variation_exp20);
   
   graph->Draw("f");
   
   Double_t Mean_Value_exp_fx1006[1] = {
   1.5};
   Double_t Mean_Value_exp_fy1006[1] = {
   2.01};
   Double_t Mean_Value_exp_fex1006[1] = {
   0.499};
   Double_t Mean_Value_exp_fey1006[1] = {
   0};
   gre = new TGraphErrors(1,Mean_Value_exp_fx1006,Mean_Value_exp_fy1006,Mean_Value_exp_fex1006,Mean_Value_exp_fey1006);
   gre->SetName("Mean_Value_exp");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerSize(1.2);
   gre->SetMarkerStyle(20);
   gre->SetLineWidth(2);
   
   TH1F *Graph_Mean_Value_exp1006 = new TH1F("Graph_Mean_Value_exp1006","Graph",100,0,1.0988);
   Graph_Mean_Value_exp1006->SetMinimum(1.91);
   Graph_Mean_Value_exp1006->SetMaximum(3.11);
   Graph_Mean_Value_exp1006->SetDirectory(0);
   Graph_Mean_Value_exp1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Mean_Value_exp1006->SetLineColor(ci);
   Graph_Mean_Value_exp1006->GetXaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1006->GetXaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1006->GetXaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1006->GetXaxis()->SetTitleFont(42);
   Graph_Mean_Value_exp1006->GetYaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1006->GetYaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1006->GetYaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1006->GetYaxis()->SetTitleFont(42);
   Graph_Mean_Value_exp1006->GetZaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1006->GetZaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1006->GetZaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Mean_Value_exp1006);
   
   gre->Draw("p");
   
   // =======================================================
   // =======================================================
   //  POWHEG
   // =======================================================
   // =======================================================
   Double_t Total_Uncert_exp_fx21[4] = {
   2,
   3,
   3,
   2};
   Double_t Total_Uncert_exp_fy21[4] = { // 
     //3.08 \pm 0.01(stat) +0.02 -0.06(scales) \pm 0.05(PDF+\alpha_s) \pm 0.45(PS)
   3.08-TMath::Sqrt(0.06*0.06+0.05*0.05+0.01*0.01+0.45*0.45),
   3.08-TMath::Sqrt(0.06*0.06+0.05*0.05+0.01*0.01+0.45*0.45),
   3.08+TMath::Sqrt(0.02*0.02+0.05*0.05+0.01*0.01+0.45*0.45),
   3.08+TMath::Sqrt(0.02*0.02+0.05*0.05+0.01*0.01+0.45*0.45)};
   graph = new TGraph(4,Total_Uncert_exp_fx21,Total_Uncert_exp_fy21);
   graph->SetName("Total_Uncert_exp");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#99ccff");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_Total_Uncert_exp21 = new TH1F("Graph_Total_Uncert_exp21","Graph",100,0.9,2.1);
   Graph_Total_Uncert_exp21->SetMinimum(1.327404);
   Graph_Total_Uncert_exp21->SetMaximum(2.692596);
   Graph_Total_Uncert_exp21->SetDirectory(0);
   Graph_Total_Uncert_exp21->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Total_Uncert_exp21->SetLineColor(ci);
   Graph_Total_Uncert_exp21->GetXaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp21->GetXaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp21->GetXaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp21->GetXaxis()->SetTitleFont(42);
   Graph_Total_Uncert_exp21->GetYaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp21->GetYaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp21->GetYaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp21->GetYaxis()->SetTitleFont(42);
   Graph_Total_Uncert_exp21->GetZaxis()->SetLabelFont(42);
   Graph_Total_Uncert_exp21->GetZaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_exp21->GetZaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_exp21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Total_Uncert_exp21);
   
   graph->Draw("f");
   
   Double_t StatOnly_Uncert_exp_fx22[4] = {
   2,
   3,
   3,
   2};
   Double_t StatOnly_Uncert_exp_fy22[4] = {
   3.08-TMath::Sqrt(0.06*0.06),
   3.08-TMath::Sqrt(0.06*0.06),
   3.08+TMath::Sqrt(0.02*0.02),
   3.08+TMath::Sqrt(0.02*0.02)};
   graph = new TGraph(4,StatOnly_Uncert_exp_fx22,StatOnly_Uncert_exp_fy22);
   graph->SetName("Scale_Variation_exp");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#3366ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(3353);

   ci = TColor::GetColor("#3366ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#3366ff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_StatOnly_Uncert_exp22 = new TH1F("Graph_StatOnly_Uncert_exp22","Graph",100,0.9,2.1);
   Graph_StatOnly_Uncert_exp22->SetMinimum(1.445592);
   Graph_StatOnly_Uncert_exp22->SetMaximum(2.574408);
   Graph_StatOnly_Uncert_exp22->SetDirectory(0);
   Graph_StatOnly_Uncert_exp22->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_StatOnly_Uncert_exp22->SetLineColor(ci);
   Graph_StatOnly_Uncert_exp22->GetXaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_exp22->GetXaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetXaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetXaxis()->SetTitleFont(42);
   Graph_StatOnly_Uncert_exp22->GetYaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_exp22->GetYaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetYaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetYaxis()->SetTitleFont(42);
   Graph_StatOnly_Uncert_exp22->GetZaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_exp22->GetZaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetZaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_exp22->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_StatOnly_Uncert_exp22);
   
   graph->Draw("f");
   
   Double_t Mean_Value_exp_fx1007[1] = {
   2.5};
   Double_t Mean_Value_exp_fy1007[1] = {
   3.08};
   Double_t Mean_Value_exp_fex1007[1] = {
   0.4999};
   Double_t Mean_Value_exp_fey1007[1] = {
   0.01};
   gre = new TGraphErrors(1,Mean_Value_exp_fx1007,Mean_Value_exp_fy1007,Mean_Value_exp_fex1007,Mean_Value_exp_fey1007);
   gre->SetName("Mean_Value_exp");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillColor(1);
   gre->SetMarkerSize(1.2);
   gre->SetMarkerStyle(20);
   gre->SetLineWidth(2);
   
   TH1F *Graph_Mean_Value_exp1007 = new TH1F("Graph_Mean_Value_exp1007","Graph",100,0.9012,2.098);
   Graph_Mean_Value_exp1007->SetMinimum(2.098+0.513);
   Graph_Mean_Value_exp1007->SetMaximum(2.098+0.473);
   Graph_Mean_Value_exp1007->SetDirectory(0);
   Graph_Mean_Value_exp1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Mean_Value_exp1007->SetLineColor(ci);
   Graph_Mean_Value_exp1007->GetXaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1007->GetXaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1007->GetXaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1007->GetXaxis()->SetTitleFont(42);
   Graph_Mean_Value_exp1007->GetYaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1007->GetYaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1007->GetYaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1007->GetYaxis()->SetTitleFont(42);
   Graph_Mean_Value_exp1007->GetZaxis()->SetLabelFont(42);
   Graph_Mean_Value_exp1007->GetZaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_exp1007->GetZaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_exp1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Mean_Value_exp1007);
   
   gre->Draw("p");
   
   // =======================================================
   // =======================================================
   //  DATA
   // =======================================================
   // =======================================================
   Double_t Total_Uncert_obs_fx23[4] = {
   0,
   1,
   1,
   0};
   Double_t Total_Uncert_obs_fy23[4] = {
   2.908+0.585,
   2.908+0.585,
   2.908-0.550,
   2.908-0.550};
   graph = new TGraph(4,Total_Uncert_obs_fx23,Total_Uncert_obs_fy23);
   graph->SetName("Total_Uncert_obs");
   graph->SetTitle("Graph");

   ci = kOrange-2;//TColor::GetColor("#99ccff");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#99ccff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_Total_Uncert_obs23 = new TH1F("Graph_Total_Uncert_obs23","Graph",100,1.9,3.1);
   Graph_Total_Uncert_obs23->SetMinimum(1.1118);
   Graph_Total_Uncert_obs23->SetMaximum(1.782098);
   Graph_Total_Uncert_obs23->SetDirectory(0);
   Graph_Total_Uncert_obs23->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Total_Uncert_obs23->SetLineColor(ci);
   Graph_Total_Uncert_obs23->GetXaxis()->SetLabelFont(42);
   Graph_Total_Uncert_obs23->GetXaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_obs23->GetXaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_obs23->GetXaxis()->SetTitleFont(42);
   Graph_Total_Uncert_obs23->GetYaxis()->SetLabelFont(42);
   Graph_Total_Uncert_obs23->GetYaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_obs23->GetYaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_obs23->GetYaxis()->SetTitleFont(42);
   Graph_Total_Uncert_obs23->GetZaxis()->SetLabelFont(42);
   Graph_Total_Uncert_obs23->GetZaxis()->SetLabelSize(0.035);
   Graph_Total_Uncert_obs23->GetZaxis()->SetTitleSize(0.035);
   Graph_Total_Uncert_obs23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Total_Uncert_obs23);
   
   graph->Draw("f");
   
   Double_t StatOnly_Uncert_obs_fx24[4] = {
   0,
   1,
   1,
   0};
   Double_t StatOnly_Uncert_obs_fy24[4] = {
   2.908+TMath::Sqrt(0.513*0.513),
   2.908+TMath::Sqrt(0.513*0.513),
   2.908-TMath::Sqrt(0.473*0.473),
   2.908-TMath::Sqrt(0.473*0.473)};
   graph = new TGraph(4,StatOnly_Uncert_obs_fx24,StatOnly_Uncert_obs_fy24);
   graph->SetName("StatOnly_Uncert_obs");
   graph->SetTitle("Graph");

   ci = kOrange+10;//TColor::GetColor("#3366ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(3244);

   ci = TColor::GetColor("#3366ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#3366ff");
   graph->SetMarkerColor(ci);
   
   TH1F *Graph_StatOnly_Uncert_obs24 = new TH1F("Graph_StatOnly_Uncert_obs24","Graph",100,1.9,3.1);
   Graph_StatOnly_Uncert_obs24->SetMinimum(1.152991);
   Graph_StatOnly_Uncert_obs24->SetMaximum(1.740907);
   Graph_StatOnly_Uncert_obs24->SetDirectory(0);
   Graph_StatOnly_Uncert_obs24->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_StatOnly_Uncert_obs24->SetLineColor(ci);
   Graph_StatOnly_Uncert_obs24->GetXaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_obs24->GetXaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetXaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetXaxis()->SetTitleFont(42);
   Graph_StatOnly_Uncert_obs24->GetYaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_obs24->GetYaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetYaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetYaxis()->SetTitleFont(42);
   Graph_StatOnly_Uncert_obs24->GetZaxis()->SetLabelFont(42);
   Graph_StatOnly_Uncert_obs24->GetZaxis()->SetLabelSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetZaxis()->SetTitleSize(0.035);
   Graph_StatOnly_Uncert_obs24->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_StatOnly_Uncert_obs24);
   
   graph->Draw("f");
   
   Double_t Mean_Value_obs_fx1008[1] = {
   0.5};
   Double_t Mean_Value_obs_fy1008[1] = {
   2.908};
   Double_t Mean_Value_obs_fex1008[1] = {
   0.4999};
   Double_t Mean_Value_obs_fey1008[1] = {
   0.};
   gre = new TGraphErrors(1,Mean_Value_obs_fx1008,Mean_Value_obs_fy1008,Mean_Value_obs_fex1008,Mean_Value_obs_fey1008);
   gre->SetName("Mean_Value_obs");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerSize(1.2);
   gre->SetMarkerStyle(20);
   gre->SetLineWidth(2);
   
   TH1F *Graph_Mean_Value_obs1008 = new TH1F("Graph_Mean_Value_obs1008","Graph",100,1.9012,3.0988); // data marker
   Graph_Mean_Value_obs1008->SetMinimum(1.346949);
   Graph_Mean_Value_obs1008->SetMaximum(2.546949);
   Graph_Mean_Value_obs1008->SetDirectory(0);
   Graph_Mean_Value_obs1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Mean_Value_obs1008->SetLineColor(ci);
   Graph_Mean_Value_obs1008->GetXaxis()->SetLabelFont(42);
   Graph_Mean_Value_obs1008->GetXaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_obs1008->GetXaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_obs1008->GetXaxis()->SetTitleFont(42);
   Graph_Mean_Value_obs1008->GetYaxis()->SetLabelFont(42);
   Graph_Mean_Value_obs1008->GetYaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_obs1008->GetYaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_obs1008->GetYaxis()->SetTitleFont(42);
   Graph_Mean_Value_obs1008->GetZaxis()->SetLabelFont(42);
   Graph_Mean_Value_obs1008->GetZaxis()->SetLabelSize(0.035);
   Graph_Mean_Value_obs1008->GetZaxis()->SetTitleSize(0.035);
   Graph_Mean_Value_obs1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Mean_Value_obs1008);
   
   gre->Draw("p");
   


   TLatex *   tex = new TLatex(0.2,0.88,"ATLAS");
   tex->SetNDC();
   tex->SetTextFont(72);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.325,0.88,"Internal");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.2,0.82,"#sqrt{s} = 13 TeV, 36.1 fb^{-1}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.0425);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.2,0.22,"#splitline{Interference with strong production and NLO EW}{corrections are not included in theoretical predictions}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   //tex->Draw();
   
   TLegend *leg = new TLegend(0.48,0.68,0.9,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.036);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry;
   entry=leg->AddEntry("dummy1"               ," Total experimental uncertainties","lf");
   entry->SetFillColor(kOrange-2);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("dummy3"               ," Experimental stat. uncertainties","lf");
   entry->SetLineColor(1);
   entry->SetFillColor(kOrange+10);
   entry->SetFillStyle(3244);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("dummy2"               ," Total theoretical uncertainties","lf");
   entry->SetFillColor(TColor::GetColor("#99ccff"));
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("dummy2"               ," Theoretical scale uncertainties","lf");
   entry->SetFillColor(TColor::GetColor("#3366ff"));
   entry->SetFillStyle(3353);
   entry->SetLineStyle(1);
   entry->SetLineColor(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   gPad->RedrawAxis();
   leg->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);

   canvas->SaveAs("NP_post_fit__xsec_ExpObs.pdf");
   canvas->SaveAs("NP_post_fit__xsec_ExpObs.eps");
   canvas->SaveAs("NP_post_fit__xsec_ExpObs.png");
   
}
