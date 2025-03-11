void plotMassWidth()
{
    // Opening File
    fstream file;
    file.open("br.sm2", ios::in);
    
    // Skipping the header
    std::string line;
    for (int i = 0; i < 4; ++i) {
        std::getline(file, line);
    }
    
    // Extracting values
    std::istringstream iss(line);
    std::vector<double> values;
    double val;
    while(iss >> val){
        values.push_back(val);
    }
    
    double MHSM = values.front();
    double WIDTH = values.back();
    
    
    std::cout << MHSM << std::endl;
    std::cout << WIDTH << std::endl;
    
    file.close();
    
    // Plotting
    TGraph *graph = new TGraph(1, &MHSM, &WIDTH);
    TCanvas *c1 = new TCanvas("c1", "SM Higgs Boson Width vs Mass", 800, 600);
    
    graph->SetTitle("SM Higgs Boson Width vs Mass;Mass (GeV);Width (GeV)");
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(1.5);
    graph->SetMarkerColor(kBlue);
    graph->GetYaxis()->SetRangeUser(0.0035,0.0045);
    c1->SetLeftMargin(0.1403509);
    c1->SetRightMargin(0.06015038);
    graph->Draw();
    
    // Saving
    c1->SaveAs("MassWidthPlot.png");
}
