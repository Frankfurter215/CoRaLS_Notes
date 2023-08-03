void maxnumpartsgraph()
{
  TGraph *gr = new TGraph(); // Empty because we don't know how many inputs

  gr->SetMarkerStyle(8);
  gr->SetMarkerSize(1);
  gr->SetLineWidth(2);
  gr->SetLineColor(kRed);

  gr->SetTitle("Peak Number of Particles at Different Primary Proton Energies");
  gr->GetXaxis()->SetTitle("Energies (GeV)");
  gr->GetYaxis()->SetTitle("Number of Particles");

  fstream file;
  file.open("maxnumparts_81.txt", ios::in);

  while (1)
  {
    double x, y;
    file >> x >> y;
    gr->SetPoint(gr->GetN(), x, y);

    if (file.eof())
      break;
  }

  file.close();

  TCanvas *c1 = new TCanvas();

  gr->Draw("AP");

  TF1 *f1 = new TF1("f1", "pol1", 0, 10000);
  gr->Fit("f1", "Q");

  // Enable the display of fit information
  gStyle->SetOptFit(1);

  // Print the fit parameters and related information
  gr->GetFunction("f1")->Print();

  // Residual graph
  TGraph *residualGraph = new TGraph();
  residualGraph->SetTitle("Residuals");
  residualGraph->GetXaxis()->SetTitle("Energies (GeV)");
  residualGraph->GetYaxis()->SetTitle("Residuals");

  for (int i = 0; i < gr->GetN(); i++)
  {
    double x = gr->GetX()[i];
    double y = gr->GetY()[i];
    double residual = y - f1->Eval(x);
    residualGraph->SetPoint(residualGraph->GetN(), x, residual);
  }

  TCanvas *c2 = new TCanvas();
  residualGraph->SetMarkerStyle(8);
  residualGraph->SetMarkerSize(1);
  residualGraph->SetLineWidth(2);
  residualGraph->SetLineColor(kBlue);
  residualGraph->Draw("AP");

  c1->Print("avgprotonmaxnumparts_731.pdf");
  c2->Print("protonresiduals_731.pdf");
}

/*void maxnumpartsgraph()
  {
    TGraph *gr = new TGraph(); //empty cus we dont know how many inputs
    
    gr->SetMarkerStyle(8);
    gr->SetMarkerSize(1);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);
    
    gr->SetTitle("Peak Number of Particles at Different Primary Energies");
    gr->GetXaxis()->SetTitle("Energies (GeV)");
    gr->GetYaxis()->SetTitle("Number of Particles");
    
    fstream file;
    file.open("maxnumparts.txt", ios::in);
    
    while(1)
    {
      double x, y;
      file >> x >> y;
      gr->SetPoint(gr->GetN(), x, y); //GetN takes the max number of data points included and sets this as the max
    
      if(file.eof()) break;
    }
    
    file.close();
    
    TCanvas *c1 = new TCanvas();

 //   gPad->SetLogx();
   // gPad->SetLogy();

    gr->Draw("AP"); //A= all things draw including axis, L= style, line, P= show points
    //C is smooth line
    TF1 *f1 = new TF1("f1", "pol1", 20, 10000);
    gr->Fit("f1", "Q");

  // Enable the display of fit information
  gStyle->SetOptFit(1);

  // Print the fit parameters and related information
  gr->GetFunction("f1")->Print();

    c1->Print("showerlengths.pdf");
  }*/
