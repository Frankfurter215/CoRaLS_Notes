void showerlengthgraph()
  {
    TGraph *gr = new TGraph(); //empty cus we dont know how many inputs
    
    gr->SetMarkerStyle(8);
    gr->SetMarkerSize(1);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);
    
    gr->SetTitle("Peak of Shower at Different Primary Energies");
    gr->GetXaxis()->SetTitle("Energies (GeV)");
    gr->GetYaxis()->SetTitle("Shower Length to Max [mm]");
    
    fstream file;
    file.open("showerlength_81.txt", ios::in);
    
    while(1)
    {
      double x, y;
      file >> x >> y;
      gr->SetPoint(gr->GetN(), x, y); //GetN takes the max number of data points included and sets this as the max
    
      if(file.eof()) break;
    }
    
    file.close();
    
    TCanvas *c1 = new TCanvas();

  //  gPad->SetLogx();
   // gPad->SetLogy();

    gr->Draw("AP"); //A= all things draw including axis, L= style, line, P= show points
    //C is smooth line
    TF1 *f1 = new TF1("f1", "[0]*log(x)", 0, 10000);
    f1->SetParameter(0, 100.);
    gr->Fit("f1", "Q");
/*
    TF1 *f2 = new TF1("f2", "[3]*([0]/[1])*log(x/[2])", -10, 11000);
    f2->SetParameter(0, 0.221); //x_0 g/mm^2
    f2->SetParameter(1, 0.0017); //density g/mm^3
    f2->SetParameter(2, 0.0398); //E_c GeV
    f2->SetParameter(3, 1);
    f2->SetLineColor(kBlack);
/*
    TF1 *f3 = new TF1("f3", "[5]*([0]/[1])*([2]+([3]*log10(x/[4])))", -10, 11000);
    f3->SetParameter(0, 0.221); //x_0 g/mm^2
    f3->SetParameter(1, 0.0017); //density g/mm^3
    f3->SetParameter(2, 12.7); //constant
    f3->SetParameter(3, 0.66666666666); //2/3
    f3->SetParameter(4, 0.0398); //E_c GeV
    f3->SetParameter(5, 0.9);
    f3->SetLineColor(kBlue);
*/
//    f2->Draw("SAME");
//    f3->Draw("SAME");

    TLegend *leg = new TLegend(0.55, 0.15, 0.85, 0.45); //x-y min, max
    leg->SetBorderSize(0); //removes border
    leg->AddEntry(f1, "Best Fit Function", "l"); //histogram, name of entry, what should be drawn "l" =line
 //   leg->AddEntry(f2, "(X_0 / density) * ln(E/E_c)", "l");
    leg->Draw();

  // Enable the display of fit information
  gStyle->SetOptFit(0);

  // Print the fit parameters and related information
  gr->GetFunction("f1")->Print();

    c1->Print("avgprotonshowerlengths_731.pdf");
  }
