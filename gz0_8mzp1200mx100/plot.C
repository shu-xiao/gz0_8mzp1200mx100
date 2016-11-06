#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "cstdlib"
#include "iostream"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TROOT.h"
#include "setNCUStyle.C"


void plot()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    setNCUStyle();
	
    TCanvas *c1 = new TCanvas("c1","ma0",900,700);
    TLegend* leg = new TLegend(0.4,0.73,0.92,0.89);

    TFile *f_mzp1 = TFile::Open("300MA0.root"); //dm=10
    TFile *f_mzp2 = TFile::Open("500MA0.root"); //old
    TFile *f_mzp3 = TFile::Open("700MA0.root");
    //TFile *f_mzp4 = TFile::Open("MZp600Ma0_700.root"); //dm=100
    //TFile *f_mzp5 = TFile::Open("MZp600Ma0_800.root");
    //TFile *f_mzp6 = TFile::Open("MZp600Ma0_filedm100_25.root");


    TH1F* h_A0m1 = (TH1F*)f_mzp1->Get("h_Dpt_0");
    TH1F* h_A0m2 = (TH1F*)f_mzp2->Get("h_Dpt_0");
    TH1F* h_A0m3 = (TH1F*)f_mzp3->Get("h_Dpt_0");    
    //TH1F* h_A0m4 = (TH1F*)f_mzp4->Get("h_Dpt_0");
    //TH1F* h_A0m5 = (TH1F*)f_mzp5->Get("h_Dpt_0");
    //TH1F* h_A0m6 = (TH1F*)f_mzp6->Get("h_D_dR0");

//dR(bb):h_D_dR0
//PT(A0): h_Bpt1
//PT(H): h_Bpt0
//TM(x):h_XmT
//h_Xm; h_Xy;
//h_Xpz;h_Bpz0;h_Bpz1;h_Dpz0;h_Dpz1;
//h_cosThetaStar;h_cosPhi;h_Bm0;h_BmT0;h_BmT1;h_By0;h_By1

    float scale1 = 1.0/h_A0m1->Integral();
    float scale2 = 1.0/h_A0m2->Integral();
    float scale3 = 1.0/h_A0m3->Integral();
    //float scale4 = 1.0/h_A0m4->Integral();
    //float scale5 = 1.0/h_A0m5->Integral();
    //float scale6 = 1.0/h_A0m6->Integral();

    h_A0m1->Scale(scale1);
    h_A0m2->Scale(scale2);
    h_A0m3->Scale(scale3);
    //h_A0m4->Scale(scale4);
    //h_A0m5->Scale(scale5);
    //h_A0m6->Scale(scale6);
    // h_zpM700_hA0_bbxx->Scale(scale7);

    h_A0m1->Sumw2();
    h_A0m2->Sumw2();
    h_A0m3->Sumw2();
    //h_A0m4->Sumw2();
    //h_A0m5->Sumw2();
    //h_A0m6->Sumw2();

    h_A0m2->SetFillColor(4);
    h_A0m2->SetLineColor(4);
    h_A0m2->SetFillStyle(3014);
    h_A0m1->SetFillColor(2);
    h_A0m1->SetLineColor(2);
    h_A0m1->SetFillStyle(3014);
    h_A0m3->SetFillColor(6);
    h_A0m3->SetLineColor(6);
    h_A0m3->SetFillStyle(3014);
    //h_A0m4->SetLineColor(1);
    //h_A0m5->SetLineColor(5);
    //h_A0m6->SetFillColor(81);

    h_A0m1->GetXaxis()->SetTitleFont(42);
    h_A0m1->GetYaxis()->SetTitleFont(42);
    h_A0m2->GetXaxis()->SetTitleFont(42);
    h_A0m2->GetYaxis()->SetTitleFont(42);
    h_A0m3->GetXaxis()->SetTitleFont(42);
    h_A0m3->GetYaxis()->SetTitleFont(42);
    //h_A0m4->GetXaxis()->SetLabelFont(22);
    //h_A0m4->GetYaxis()->SetLabelFont(22);
    //h_A0m5->GetXaxis()->SetLabelFont(22);
    //h_A0m5->GetYaxis()->SetLabelFont(22);
    //h_A0m6->GetXaxis()->SetLabelFont(22);
    //h_A0m6->GetYaxis()->SetLabelFont(22);

    h_A0m1->GetXaxis()->SetLabelFont(42);
    h_A0m1->GetYaxis()->SetLabelFont(42);
    h_A0m2->GetXaxis()->SetLabelFont(42);
    h_A0m2->GetYaxis()->SetLabelFont(42);
    h_A0m3->GetXaxis()->SetLabelFont(42);
    h_A0m3->GetYaxis()->SetLabelFont(42);


    h_A0m1->GetXaxis()->SetTitleSize(0.04);
    h_A0m1->GetYaxis()->SetTitleSize(0.04);  
    h_A0m2->GetXaxis()->SetLabelSize(0.04);
    h_A0m2->GetYaxis()->SetLabelSize(0.04);
    h_A0m3->GetXaxis()->SetLabelSize(0.055);
    h_A0m3->GetYaxis()->SetLabelSize(0.055);
    //h_A0m4->GetXaxis()->SetLabelSize(0.045);
    //h_A0m4->GetYaxis()->SetLabelSize(0.045);
    //h_A0m5->GetXaxis()->SetLabelSize(0.045);
    //h_A0m5->GetYaxis()->SetLabelSize(0.045);
    //h_A0m6->GetXaxis()->SetLabelSize(0.045);
    //h_A0m6->GetYaxis()->SetLabelSize(0.045);

    h_A0m1->GetYaxis()->SetTitleOffset(1.2);
    h_A0m2->GetYaxis()->SetTitleOffset(1.2);
    h_A0m3->GetYaxis()->SetTitleOffset(1.2);   
    //h_A0m4->GetYaxis()->SetTitleOffset(1.45);
    //h_A0m5->GetYaxis()->SetTitleOffset(1.45);
    //h_A0m6->GetYaxis()->SetTitleOffset(1.45);

    h_A0m1->SetLineWidth(2);
    h_A0m2->SetLineWidth(2);
    h_A0m3->SetLineWidth(2);
    //h_A0m4->SetLineWidth(2);
    //h_A0m5->SetLineWidth(2);
    //h_A0m6->SetLineWidth(2);
    // h->SetLineColor(1);

    // h_A0m1->GetYaxis()->SetRange(0,700);
    // h_A0m2->GetYaxis()->SetRange(0,700);
    // h_A0m3->GetYaxis()->SetRange(0,700);
    h_A0m3->GetYaxis()->SetTitle("arbirary units");
    h_A0m3->GetYaxis()->SetTitleSize(0.055);
    //h_A0m3->GetYaxis()->CenterTitle();
    h_A0m3->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
    h_A0m3->GetXaxis()->SetTitleSize(0.055);
    //h_A0m3->GetXaxis()->CenterTitle();
    h_A0m3->SetAxisRange(0,700,"X");
    h_A0m3->SetAxisRange(0,0.3,"y");
    
    // h_A0m5->GetYaxis()->SetRange(0,700);
    // h_A0m6->GetYaxis()->SetRange(0,700); 

    h_A0m3->Draw("hist");        
    //h_A0m5->Draw("histsame");
    //h_A0m4->Draw("histsame"); 
    h_A0m2->Draw("histsame");
    h_A0m1->Draw("histsame");
    //h_A0m6->Draw("histsame");

    leg->AddEntry(h_A0m1,"m_{Z'} = 1200 GeV, m_{A0} = 300 GeV");
    leg->AddEntry(h_A0m2,"m_{Z'} = 1200 GeV, m_{A0} = 500 GeV");
    leg->AddEntry(h_A0m3,"m_{Z'} = 1200 GeV, m_{A0} = 700 GeV");
    //leg->AddEntry(h_A0m4,"MZ'_600GeV,MA0_700GeV");
    //leg->AddEntry(h_A0m5,"MZ'_600GeV,MA0_800GeV");
    //leg->AddEntry(h_A0m6,"MZ'_1400GeV,DM_100GeV");

    leg->Draw();


    c1->Update();
    // Latex
    TString latexCMSname= "13 TeV";
    TString latexCMSname2= "Z' #rightarrow DM + H";
    TString latexCMSname3= "g_{Z} = 0.8, m_{Z'} = 1200 GeV";
    TString latexCMSname4= "tan#beta = 1, m_{#chi} = 100 GeV";
    TString latexCMSname5= "#it{Simulation}";
    TLatex Tl; Tl.SetTextFont(42); Tl.SetTextSize(0.04); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(11);
    Tl.DrawLatex(0.86,0.945,latexCMSname);
    Tl.DrawLatex(0.17,0.8,latexCMSname2);
   // Tl.DrawLatex(0.2, 0.75,"m_{Z'} = 1200 GeV");
    //Tl.DrawLatex(0.2, 0.7, latexCMSname4);
    //Tl.DrawLatex(0.23, 0.85, latexCMSname5);
    Tl.SetTextFont(61);
    Tl.DrawLatex(0.17, 0.85, "CMS");
}
