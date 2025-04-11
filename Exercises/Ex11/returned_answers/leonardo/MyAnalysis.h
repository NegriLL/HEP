//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 10 15:54:43 2025 by ROOT version 6.34.04
// from TTree Events/Events
// found on file: DYJetsToLL.root
//////////////////////////////////////////////////////////

#ifndef MyAnalysis_h
#define MyAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class MyAnalysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run = {fReader, "run"};
   TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
   TTreeReaderValue<ULong64_t> event = {fReader, "event"};
   TTreeReaderValue<Bool_t> HLT_IsoMu24_eta2p1 = {fReader, "HLT_IsoMu24_eta2p1"};
   TTreeReaderValue<Bool_t> HLT_IsoMu24 = {fReader, "HLT_IsoMu24"};
   TTreeReaderValue<Bool_t> HLT_IsoMu17_eta2p1_LooseIsoPFTau20 = {fReader, "HLT_IsoMu17_eta2p1_LooseIsoPFTau20"};
   TTreeReaderValue<Int_t> PV_npvs = {fReader, "PV_npvs"};
   TTreeReaderValue<Float_t> PV_x = {fReader, "PV_x"};
   TTreeReaderValue<Float_t> PV_y = {fReader, "PV_y"};
   TTreeReaderValue<Float_t> PV_z = {fReader, "PV_z"};
   TTreeReaderValue<UInt_t> nMuon = {fReader, "nMuon"};
   TTreeReaderArray<Float_t> Muon_pt = {fReader, "Muon_pt"};
   TTreeReaderArray<Float_t> Muon_eta = {fReader, "Muon_eta"};
   TTreeReaderArray<Float_t> Muon_phi = {fReader, "Muon_phi"};
   TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
   TTreeReaderArray<Int_t> Muon_charge = {fReader, "Muon_charge"};
   TTreeReaderArray<Float_t> Muon_pfRelIso03_all = {fReader, "Muon_pfRelIso03_all"};
   TTreeReaderArray<Float_t> Muon_pfRelIso04_all = {fReader, "Muon_pfRelIso04_all"};
   TTreeReaderArray<Bool_t> Muon_tightId = {fReader, "Muon_tightId"};
   TTreeReaderArray<Bool_t> Muon_softId = {fReader, "Muon_softId"};
   TTreeReaderArray<Float_t> Muon_dxy = {fReader, "Muon_dxy"};
   TTreeReaderArray<Float_t> Muon_dxyErr = {fReader, "Muon_dxyErr"};
   TTreeReaderArray<Float_t> Muon_dz = {fReader, "Muon_dz"};
   TTreeReaderArray<Float_t> Muon_dzErr = {fReader, "Muon_dzErr"};
   TTreeReaderArray<Int_t> Muon_jetIdx = {fReader, "Muon_jetIdx"};
   TTreeReaderArray<Int_t> Muon_genPartIdx = {fReader, "Muon_genPartIdx"};
   TTreeReaderValue<UInt_t> nTau = {fReader, "nTau"};
   TTreeReaderArray<Float_t> Tau_pt = {fReader, "Tau_pt"};
   TTreeReaderArray<Float_t> Tau_eta = {fReader, "Tau_eta"};
   TTreeReaderArray<Float_t> Tau_phi = {fReader, "Tau_phi"};
   TTreeReaderArray<Float_t> Tau_mass = {fReader, "Tau_mass"};
   TTreeReaderArray<Int_t> Tau_charge = {fReader, "Tau_charge"};
   TTreeReaderArray<Int_t> Tau_decayMode = {fReader, "Tau_decayMode"};
   TTreeReaderArray<Float_t> Tau_relIso_all = {fReader, "Tau_relIso_all"};
   TTreeReaderArray<Int_t> Tau_jetIdx = {fReader, "Tau_jetIdx"};
   TTreeReaderArray<Int_t> Tau_genPartIdx = {fReader, "Tau_genPartIdx"};
   TTreeReaderArray<Bool_t> Tau_idDecayMode = {fReader, "Tau_idDecayMode"};
   TTreeReaderArray<Float_t> Tau_idIsoRaw = {fReader, "Tau_idIsoRaw"};
   TTreeReaderArray<Bool_t> Tau_idIsoVLoose = {fReader, "Tau_idIsoVLoose"};
   TTreeReaderArray<Bool_t> Tau_idIsoLoose = {fReader, "Tau_idIsoLoose"};
   TTreeReaderArray<Bool_t> Tau_idIsoMedium = {fReader, "Tau_idIsoMedium"};
   TTreeReaderArray<Bool_t> Tau_idIsoTight = {fReader, "Tau_idIsoTight"};
   TTreeReaderArray<Bool_t> Tau_idAntiEleLoose = {fReader, "Tau_idAntiEleLoose"};
   TTreeReaderArray<Bool_t> Tau_idAntiEleMedium = {fReader, "Tau_idAntiEleMedium"};
   TTreeReaderArray<Bool_t> Tau_idAntiEleTight = {fReader, "Tau_idAntiEleTight"};
   TTreeReaderArray<Bool_t> Tau_idAntiMuLoose = {fReader, "Tau_idAntiMuLoose"};
   TTreeReaderArray<Bool_t> Tau_idAntiMuMedium = {fReader, "Tau_idAntiMuMedium"};
   TTreeReaderArray<Bool_t> Tau_idAntiMuTight = {fReader, "Tau_idAntiMuTight"};
   TTreeReaderValue<Float_t> MET_pt = {fReader, "MET_pt"};
   TTreeReaderValue<Float_t> MET_phi = {fReader, "MET_phi"};
   TTreeReaderValue<Float_t> MET_sumet = {fReader, "MET_sumet"};
   TTreeReaderValue<Float_t> MET_significance = {fReader, "MET_significance"};
   TTreeReaderValue<Float_t> MET_CovXX = {fReader, "MET_CovXX"};
   TTreeReaderValue<Float_t> MET_CovXY = {fReader, "MET_CovXY"};
   TTreeReaderValue<Float_t> MET_CovYY = {fReader, "MET_CovYY"};
   TTreeReaderValue<UInt_t> nJet = {fReader, "nJet"};
   TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
   TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
   TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
   TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
   TTreeReaderArray<Bool_t> Jet_puId = {fReader, "Jet_puId"};
   TTreeReaderArray<Float_t> Jet_btag = {fReader, "Jet_btag"};
   TTreeReaderValue<UInt_t> nGenPart = {fReader, "nGenPart"};
   TTreeReaderArray<Float_t> GenPart_pt = {fReader, "GenPart_pt"};
   TTreeReaderArray<Float_t> GenPart_eta = {fReader, "GenPart_eta"};
   TTreeReaderArray<Float_t> GenPart_phi = {fReader, "GenPart_phi"};
   TTreeReaderArray<Float_t> GenPart_mass = {fReader, "GenPart_mass"};
   TTreeReaderArray<Int_t> GenPart_pdgId = {fReader, "GenPart_pdgId"};
   TTreeReaderArray<Int_t> GenPart_status = {fReader, "GenPart_status"};


   MyAnalysis(TTree * /*tree*/ =0) { }
   ~MyAnalysis() override { }
   Int_t   Version() const override { return 2; }
   void    Begin(TTree *tree) override;
   void    SlaveBegin(TTree *tree) override;
   void    Init(TTree *tree) override;
   bool    Notify() override;
   bool    Process(Long64_t entry) override;
   Int_t   GetEntry(Long64_t entry, Int_t getall = 0) override { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   void    SetOption(const char *option) override { fOption = option; }
   void    SetObject(TObject *obj) override { fObject = obj; }
   void    SetInputList(TList *input) override { fInput = input; }
   TList  *GetOutputList() const override { return fOutput; }
   void    SlaveTerminate() override;
   void    Terminate() override;
   
   TH1F* h_pileup;

   ClassDefOverride(MyAnalysis,0);

};

#endif

#ifdef MyAnalysis_cxx
void MyAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

bool MyAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}


#endif // #ifdef MyAnalysis_cxx
