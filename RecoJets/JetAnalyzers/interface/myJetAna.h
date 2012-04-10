#ifndef RecoExamples_myJetAna_h
#define RecoExamples_myJetAna_h
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TFile.h>

/* \class myJetAna
 *
 * \author Frank Chlebana
 *
 * \version 1
 *
 */
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"


// class TFile;

/****
class RBX {
  RBX();

 private:
  int nTowers;
  int ieta;
  int iphi;
  float energy;
  float time;
};

class RBXCollection {

  RBXCollection();
  void addRBX(RBX r)  {rbx_.push_back(r)};

 private:
  std::vector<RBX> rbx_;

};
*****/


class myJetAna : public edm::EDAnalyzer {

public:
  myJetAna( const edm::ParameterSet & );

private:
  void beginJob( );
  void analyze ( const edm::Event& , const edm::EventSetup& );
  void endJob();

  virtual void beginRun(edm::Run const&, edm::EventSetup const&);

  std::string CaloJetAlgorithm;
  std::string GenJetAlgorithm;
  edm::InputTag theTriggerResultsLabel;
  std::string JetCorrectionService;


  // Channel quality/reconstruction information
  //  HcalChannelQuality*  chanquality_;
  //  const HcalQIEShape*  shape_;
  //  int hfFirstTimeSlice_ = 3;
  const HcalQIEShape*  shape_;

  edm::ESHandle<HcalDbService> conditions;

  // --- Passed selection cuts
  TH1F *h_pt;
  TH1F *h_ptTower;
  TH1F *h_ptRBX;
  TH1F *h_ptHPD;
  TH1F *h_et;
  TH1F *h_eta;
  TH1F *h_phi;
  // ---
  
  // --- RecHits
  TH1F *HBEneOOT;
  TH1F *HEEneOOT;
  TH1F *HFEneOOT;
  TH1F *HOEneOOT;

  TH1F *HBEneOOTTh;
  TH1F *HEEneOOTTh;
  TH1F *HFEneOOTTh;
  TH1F *HOEneOOTTh;

  TH1F *HBEneOOTTh1;
  TH1F *HEEneOOTTh1;
  TH1F *HFEneOOTTh1;
  TH1F *HOEneOOTTh1;


  TH1F *HBEneTThr;
  TH1F *HEEneTThr;
  TH1F *HFEneTThr;

  TH1F *HBEne;
  TH1F *HBEneTh;
  TH1F *HBEneTh1;
  TH1F *HBEneX;
  TH1F *HBEneY;
  TH1F *HBTime;
  TH1F *HBTimeTh;
  TH1F *HBTimeTh1;
  TH1F *HBTimeTh2;
  TH1F *HBTimeTh3;
  TH1F *HBTimeTh4;
  TH1F *HBTimeThR;
  TH1F *HBTimeTh1R;
  TH1F *HBTimeTh2R;
  TH1F *HBTimeTh3R;

  TH1F *HBTimeFlagged;
  TH1F *HBTimeThFlagged;
  TH1F *HBTimeTh1Flagged;
  TH1F *HBTimeTh2Flagged;
  TH1F *HBTimeTh3Flagged;

  TH1F *HBTimeFlagged2;
  TH1F *HBTimeThFlagged2;
  TH1F *HBTimeTh1Flagged2;
  TH1F *HBTimeTh2Flagged2;
  TH1F *HBTimeTh3Flagged2;

  TH1F *HBTimeTh3Flagged3;
  TH1F *HBTimeTh3Flagged3Clean;

  TH1F *HBTimeTh3Flagged3FN;
  TH1F *HBTimeTh3Flagged3SN;
  TH1F *HBTimeTh3Flagged3TN;

  TH1F *HBTimeTh4Flagged3FN;
  TH1F *HBTimeTh4Flagged3SN;
  TH1F *HBTimeTh4Flagged3TN;

  TH1F *HBTimeX;
  TH1F *HBTimeY;
  TH1F *HEEne;
  TH1F *HEEneTh;
  TH1F *HEEneTh1;
  TH1F *HEEneX;
  TH1F *HEEneY;
  TH1F *HEposEne;
  TH1F *HEnegEne;
  TH1F *HETime;
  TH1F *HETimeTh;
  TH1F *HETimeTh1;
  TH1F *HETimeTh2;
  TH1F *HETimeTh3;
  TH1F *HETimeTh4;
  TH1F *HETimeThR;
  TH1F *HETimeTh1R;
  TH1F *HETimeTh2R;
  TH1F *HETimeTh3R;

  TH1F *HETimeFlagged;
  TH1F *HETimeThFlagged;
  TH1F *HETimeTh1Flagged;
  TH1F *HETimeTh2Flagged;
  TH1F *HETimeTh3Flagged;

  TH1F *HETimeFlagged2;
  TH1F *HETimeThFlagged2;
  TH1F *HETimeTh1Flagged2;
  TH1F *HETimeTh2Flagged2;
  TH1F *HETimeTh3Flagged2;

  TH1F *HETimeTh3Flagged3;
  TH1F *HETimeTh3Flagged3Clean;

  TH1F *HETimeTh3Flagged3FN;
  TH1F *HETimeTh3Flagged3SN;
  TH1F *HETimeTh3Flagged3TN;

  TH1F *HETimeTh4Flagged3FN;
  TH1F *HETimeTh4Flagged3SN;
  TH1F *HETimeTh4Flagged3TN;

  TH1F *HETimeX;
  TH1F *HETimeY;
  TH1F *HEposTime;
  TH1F *HEnegTime;
  TH1F *HFLSRatio;
  TH1F *HFOERatio;
  TH1F *HFEnePMT0;
  TH1F *HFEnePMT1;
  TH1F *HFEnePMT2;
  TH1F *HFEne;
  TH1F *HFEneFlagged;
  TH1F *HFEneFlagged2;
  TH1F *HFEneFlagged3;
  TH1F *HFEneTh;
  TH1F *HFEneTh1;
  TH1F *HFTimePMT0;
  TH1F *HFTimePMT1;
  TH1F *HFTimePMT2;
  TH1F *HFTime;
  TH1F *PMTHits;
  TH1F *HFTimeFlagged;
  TH1F *HFTimeFlagged2;
  TH1F *HFTimeThFlagged2;
  TH1F *HFTimeTh1Flagged2;
  TH1F *HFTimeTh2Flagged2;
  TH1F *HFTimeTh3Flagged2;
  TH1F *HFTimeTh4Flagged2;
  TH1F *HFTimeFlagged3;
  TH1F *HFTimeThFlagged3;
  TH1F *HFTimeTh1Flagged3;
  TH1F *HFTimeTh2Flagged3;
  TH1F *HFTimeTh3Flagged3;
  TH1F *HFTimeTh4Flagged3;
  TH1F *HFTimeTh;
  TH1F *HFTimeTh1;
  TH1F *HFTimeTh2;
  TH1F *HFTimeTh3;
  TH1F *HFTimeTh4;
  TH1F *HFTimeThPass;
  TH1F *HFTimeTh1Pass;
  TH1F *HFTimeTh2Pass;
  TH1F *HFTimeTh3Pass;
  TH1F *HFTimeTh4Pass;
  TH1F *HFTimeThR;
  TH1F *HFTimeTh1R;
  TH1F *HFTimeTh2R;
  TH1F *HFTimeTh3R;
  TH1F *TrkMultFlagged0;
  TH1F *TrkMultFlagged1;
  TH1F *TrkMultFlagged2;
  TH1F *TrkMultFlagged3;
  TH1F *TrkMultFlagged4;
  TH1F *TrkMultFlaggedM;
  TH1F *HFTimeThFlagged;
  TH1F *HFTimeTh2Flagged;
  TH1F *HFTimeTh3Flagged;
  TH1F *HFTimeThFlaggedR;
  TH1F *HFTimeThFlaggedR1;
  TH1F *HFTimeThFlaggedR2;
  TH1F *HFTimeThFlaggedR3;
  TH1F *HFTimeThFlaggedR4;
  TH1F *HFTimeThFlaggedRM;
  TH1F *HFEneP;
  TH1F *HFTimeP;
  TH1F *HFTimePMa;
  TH1F *HFTimePM;
  TH1F *HFEneM;
  TH1F *HFTimeM;
  TH1F *HFLEne;
  TH1F *HFLEneNoS;
  TH1F *HFLEneNoSFlagged;
  TH1F *HFLEneNoSFlaggedN;
  TH1F *HFLTime;
  TH1F *HFSEneAll;
  TH1F *HFSEneAllF;
  TH1F *HFLEneAll;
  TH1F *HFLEneAllF;
  TH1F *HFSEne;
  TH1F *HFSEneNoL;
  TH1F *HFSEneNoLFlagged;
  TH1F *HFSEneNoLFlaggedN;
  TH2F *HFLvsS;

  TH2F *HBTvsE;
  TH2F *HETvsE;
  TH2F *HFTvsE;
  TH2F *HFTvsEPass;
  TH2F *HFTvsEFlagged;
  TH2F *HFTvsEFlagged2;
  TH2F *HFTvsEThr;
  TH2F *HFTvsEFlaggedThr;
  TH2F *HFTvsEFlagged2Thr;
  TH2F *HOTvsE;

  TH1F *HFSTime;
  TH1F *HOEne;
  TH1F *HOEneTh;
  TH1F *HOEneTh1;
  TH1F *HOTime;
  TH1F *HOTimeTh;
  TH1F *HFPhiNewPMTFlagged;
  TH1F *HFPhiFlagged;
  TH1F *HFPhiFlaggedEta29;
  TH1F *HFPhiFlaggedEta30;
  TH1F *HFPhiFlaggedEta31;

  TH1F *HFEtaFlagged;
  TH1F *HFEtaFlaggedL;
  TH1F *HFEtaFlaggedLN;
  TH1F *HFEtaFlaggedS;
  TH1F *HFEtaFlaggedSN;

  TProfile *HFEtaNFlagged;
  TH2F *HOocc;
  TH2F *HBocc;
  TH2F *HEocc;
  TH2F *HFocc;
  TH2F *HFoccTime;
  TH2F *HFEtaPhiFlagged;
  TH2F *HFEtaPhiNFlagged;
  TH2F *HFoccFlagged;
  TH2F *HFoccFlagged2;
  TH2F *HOoccOOT;
  TH2F *HBoccOOT;
  TH2F *HEoccOOT;
  TH2F *HFoccOOT;
  TH2F *HBHEFBSpike;
  TH2F *HBHEFBFlat;
  TH2F *HBHEFBTriangle;
  TH2F *HBHETS4TS5;
  TH1F *HOSEne;
  TH1F *HOSTime;
  TH1F *HOHEne;
  TH1F *HOHTime;
  TH1F *HOHr0Ene;
  TH1F *HOHr0Time;
  TH1F *HOHrm1Ene;
  TH1F *HOHrm1Time;
  TH1F *HOHrm2Ene;
  TH1F *HOHrm2Time;
  TH1F *HOHrp1Ene;
  TH1F *HOHrp1Time;
  TH1F *HOHrp2Ene;
  TH1F *HOHrp2Time;
  TH1F *EBEne;
  TH1F *EBEneTh;
  TH1F *EBEneX;
  TH1F *EBEneY;
  TH1F *EBTime;
  TH1F *EBTimeTh;
  TH1F *EBTimeX;
  TH1F *EBTimeY;
  TH1F *EEEne;
  TH1F *EEEneTh;
  TH1F *EEEneX;
  TH1F *EEEneY;
  TH1F *EEnegEne;
  TH1F *EEposEne;
  TH1F *EETime;
  TH1F *EETimeTh;
  TH1F *EETimeX;
  TH1F *EETimeY;
  TH1F *EEnegTime;
  TH1F *EEposTime;

  TH2F *fedSize;
  TH1F *totFedSize;

  TH1F *towerHadEnHB;
  TH1F *towerHadEnHE;
  TH1F *towerHadEnHF;
  TH1F *towerHadEn;
  TH1F *towerEmEnHB;
  TH1F *towerEmEnHE;
  TH1F *towerEmEnHF;
  TH1F *towerEmEn;
  TH1F *towerOuterEn;

  TH1F *towerEmFrac;

  TH1F *RBX_et;
  TH1F *RBX_hadEnergy;
  TH1F *RBX_hcalTime;
  TH1F *RBX_nTowers;
  TH1F *RBX_N;

  TH1F *HPD_et;
  TH1F *HPD_hadEnergy;
  TH1F *HPD_hcalTime;
  TH1F *HPD_nTowers;
  TH1F *HPD_N;

  // --- from reco calomet
  TH1F *HFSumEt;
  TH1F *HFMET;

  TH1F *SumEt;
  TH1F *MET;
  TH1F *MET_All;
  TH1F *MET_FBSN;
  TH1F *MET_FBTN;
  TH1F *MET_FBFN;
  TH1F *MET_FBTNR;
  TH1F *MET_FBFNR;
  TH1F *OERMET;
  TH1F *MET_Tower;
  TH1F *MET_RBX;
  TH1F *MET_HPD;
  TH1F *METSig;
  TH1F *MEx;
  TH1F *MEy;
  TH1F *METPhi;
  // ---

  TH1F *SiClusters;

  // --- from reco vertexs
  TH1F *h_Vx;
  TH1F *h_Vy;
  TH1F *h_Vz;
  TH1F *h_VNTrks;
  // ---

  // --- from reco tracks
  TH1F *h_Trk_pt;
  TH1F *h_Trk_NTrk;
  // ---
 
  TH1F *hf_sumTowerAllEx; 
  TH1F *hf_sumTowerAllEy;
  TH1F *hf_TowerJetEt;

  TH1F *ETime; 
  TH1F *HTime; 

  TH1F *nTowers1; 
  TH1F *nTowers2; 
  TH1F *nTowers3; 
  TH1F *nTowers4;
  TH1F *nTowersLeadJetPt1; 
  TH1F *nTowersLeadJetPt2; 
  TH1F *nTowersLeadJetPt3; 
  TH1F *nTowersLeadJetPt4;

  TH1F *totEneLeadJetEta1;
  TH1F *totEneLeadJetEta2; 
  TH1F *totEneLeadJetEta3;
  TH1F *hadEneLeadJetEta1; 
  TH1F *hadEneLeadJetEta2; 
  TH1F *hadEneLeadJetEta3;
  TH1F *emEneLeadJetEta1;  
  TH1F *emEneLeadJetEta2;  
  TH1F *emEneLeadJetEta3;

  TH1F *hadFracEta1; 
  TH1F *hadFracEta2; 
  TH1F *hadFracEta3;

  TH1F *tMassGen;

  TH1F *dijetMass;

  TH1F *h_nCalJets;
  TH1F *h_nGenJets;

  TH1F *caloEtaEt;
  TH1F *caloEta;
  TH1F *caloPhi;

  TH1F *hitEtaEt;
  TH1F *hitEta;
  TH1F *hitPhi;

  TH1F *h_nTowersCal;
  TH1F *h_EMFracCal;
  TH1F *h_ptCal;
  TH1F *h_etaCal;
  TH1F *h_phiCal;

  TH1F *bad_ptCal;
  TH1F *bad_etaCal;
  TH1F *bad_phiCal;



  TH1F *h_ptGen; 
  TH1F *h_etaGen; 
  TH1F *h_phiGen;

  TH1F *h_ptGenL;
  TH1F *h_etaGenL;
  TH1F *h_phiGenL;

  TH1F *h_jetEt;

  TH1F *h_UnclusteredEt;
  TH1F *h_UnclusteredEts;
  TH1F *h_TotalUnclusteredEt;

  TH1F *h_UnclusteredE;
  TH1F *h_TotalUnclusteredE;

  TH1F *h_ClusteredE;
  TH1F *h_TotalClusteredE;

  TH1F *h_jet1Pt;
  TH1F *h_jet2Pt;
  TH1F *h_jet1Eta;
  TH1F *h_jet2Eta;
  TH1F *h_jet1PtHLT;

  TH1F *jetHOEne;
  TH1F *jetEMFraction;
  TH1F *NTowers;

  TH2F *h_EmEnergy;
  TH2F *h_HadEnergy;

  TH1F *st_Pt;
  TH1F *st_Constituents;
  TH1F *st_Energy;
  TH1F *st_EmEnergy;
  TH1F *st_HadEnergy;
  TH1F *st_OuterEnergy;
  TH1F *st_Eta;
  TH1F *st_Phi;
  TH1F *st_iEta;
  TH1F *st_iPhi;
  TH1F *st_Frac;

  TH1F *NPass;
  TH1F *NTotal;
  TH1F *NTime;

  TH1F *HFRecHitEne;
  TH1F *HFRecHitEneClean;
  TH1F *HFRecHitEneCleanTopological;
  TH1F *HFRecHitEneCleanPulseShape;
  TH1F *HFRecHitEneOnlyPulseShape;
  TH1F *HFRecHitTime;

  TH1F *HFLongShortPhi;
  TH1F *HFLongShortEta;
  TH1F *HFLongShortEne;
  TH1F *HFLongShortTime;

  TH1F *HFDigiTimePhi; 
  TH1F *HFDigiTimeEta;
  TH1F *HFDigiTimeEne; 
  TH1F *HFDigiTimeTime;

  TH1F *HFLongShortNHits;
  TH1F *HFDigiTimeNHits;

  TH1F *ADC1;
  TH1F *ADC2;
  TH1F *ADC3;
  TH1F *ADC1E1000;
  TH1F *ADC2E1000;
  TH1F *ADC3E1000;
  TH1F *ADC1F;
  TH1F *ADC2F;
  TH1F *ADC3F;
  TH1F *ADC1E1000F;
  TH1F *ADC2E1000F;
  TH1F *ADC3E1000F;

  TH2F *ADC1vsE;
  TH2F *ADC2vsE;
  TH2F *ADC3vsE;
  TH2F *ADC1vsEF;
  TH2F *ADC2vsEF;
  TH2F *ADC3vsEF;

  TH2F *HFRatVsTS4;
  TH2F *HFPulseShapeVsTS5;
  TH2F *HFPulseShapeVsTS6;

  TProfile *HFPulseShapeFPX;
  TProfile *HFPulseShapeFP;
  TProfile *HFPulseShapeFT;
  TProfile *HFPulseShapeP;

  TH2F *HFPS4VsPS6E0;
  TH2F *HFPS4VsPS6E0F;
  TH2F *HFPS4VsPS6E10;
  TH2F *HFPS4VsPS6E10F;

  TH2F *HFPulseShape1;
  TH2F *HFPulseShape2;
  TH2F *HFPulseShape3;
  TH2F *HFPulseShape1F;
  TH2F *HFPulseShape2F;
  TH2F *HFPulseShape3F;
  TH2F *HFPulseShape1FT;
  TH2F *HFPulseShape1FTE;
  TH2F *HFPulseShape2FT;
  TH2F *HFPulseShape3FT;
  TH2F *HFPulseShape1FP;
  TH2F *HFPulseShape1FPE;
  TH2F *HFPulseShape2FP;
  TH2F *HFPulseShape3FP;
  TH2F *HFPulseShape1C;
  TH2F *HFPulseShape2C;
  TH2F *HFPulseShape3C;

  TH1F *HFPS1A;
  TH1F *HFPS1ATh2;
  TH1F *HFPS1ATh3;
  TH1F *HFPS1ATh4;
  TH1F *HFPS1ATh5;
  TH1F *HFPS2ATh2;
  TH1F *HFPS2ATh3;
  TH1F *HFPS2ATh4;
  TH1F *HFPS2ATh5;
  TH1F *HFPS3ATh2;
  TH1F *HFPS3ATh3;
  TH1F *HFPS3ATh4;
  TH1F *HFPS3ATh5;
  TH1F *HFPS1C;
  TH1F *HFPS1CTh2;
  TH1F *HFPS1CTh3;
  TH1F *HFPS1CTh4;
  TH1F *HFPS1CTh5;
  TH1F *HFPS2CTh2;
  TH1F *HFPS2CTh3;
  TH1F *HFPS2CTh4;
  TH1F *HFPS2CTh5;
  TH1F *HFPS3CTh2;
  TH1F *HFPS3CTh3;
  TH1F *HFPS3CTh4;
  TH1F *HFPS3CTh5;
  TH1F *HFPS1CTim1;
  TH1F *HFPS1CTim2;
  TH1F *HFPS1CEne;
  TH1F *HFPS1F;
  TH1F *HFPS1FT;
  TH1F *HFPS1FP;

  TH1F *HFPS2A;
  TH1F *HFPS2C;
  TH1F *HFPS2CTim1;
  TH1F *HFPS2CTim2;
  TH1F *HFPS2CEne;
  TH1F *HFPS2F;
  TH1F *HFPS2FT;
  TH1F *HFPS2FP;

  TH1F *HFPS3A;
  TH1F *HFPS3C;
  TH1F *HFPS3CTim1;
  TH1F *HFPS3CTim2;
  TH1F *HFPS3CEne;
  TH1F *HFPS3F;
  TH1F *HFPS3FT;
  TH1F *HFPS3FP;

  TH2F *HFvsZ;
  TH2F *EBvHB;
  TH2F *EEvHE;
  TH2F *ECALvHCAL;
  TH2F *ECALvHCALEta1;
  TH2F *ECALvHCALEta2;
  TH2F *ECALvHCALEta3;
  TProfile *EMF_Phi;
  TProfile *EMF_Eta;
  TProfile *EMF_PhiX;
  TProfile *EMF_EtaX;

  TProfile *HFTimeVsiEtaP;
  TProfile *HFTimeVsiEtaM;
  TProfile *HFTimeVsiEtaP5;
  TProfile *HFTimeVsiEtaM5;
  TProfile *HFTimeVsiEtaP20;
  TProfile *HFTimeVsiEtaM20;

  TH1F *BunchCrossing;
  TH1F *OddBunchCrossing;
  TH1F *EvenBunchCrossing;
  TH1F *BadBunchCrossing;
  TH1F *GoodBunchCrossing;
  TH1F *CentralBunchCrossing;
  TH1F *OKBunchCrossing;

  TProfile *HFFlaggedLVsE;
  TProfile *HFFlaggedPVsE;
  TProfile *HFFlaggedLVsE1;
  TProfile *HFFlaggedPVsE1;


  TProfile *HFMEFlaggedVsE;
  TProfile *HFMECleanVsE;
  TProfile *HFPEFlaggedVsE;
  TProfile *HFPECleanVsE;

  TProfile *HFRecHitsVsNVtx;
  TProfile *HFRecHitsFlaggedVsNVtx;

  TH1F *NVTX;
  TH1F *NVTX_R45;
  TH1F *NVTX_NoiseSummary;
  TH1F *NVTX_MaxHPD;
  TH1F *NVTX_NoOther;
  TH1F *NVTX_MaxZero;

  TH1F *NVTXMET200;
  TH1F *NVTX_R45MET200;
  TH1F *NVTX_NoiseSummaryMET200;
  TH1F *NVTX_MaxHPDMET200;
  TH1F *NVTX_NoOtherMET200;
  TH1F *NVTX_MaxZeroMET200;

  TH1F *NHFRecHits;

  TH1F *HBHENFlagged;
  TH2F *HBHEFlaggedVsJet;

  TH1F *HBHEJetHadEneFlagged;
  TH1F *HBHEJetHadEne;

  TProfile *NHBHEFlaggedVsNVtx;

  TH1F *RingRat;
  TProfile *RatVsRun;

  TProfile *PSAVsRun;
  TProfile *PSCVsRun;


  TH2F     *R45VsE_HB;
  TH2F     *R45VsE_HE;

  TH2F     *R45VsE;
  TH2F     *R45VsE_Flagged;
  TH2F     *R45VsE_Clean;
  TH2F     *R45VsE_Spike;
  TH2F     *R45VsE_Flat;
  TH2F     *R45VsE_Triangle;
  TH2F     *R45VsE_SpikeEx;
  TH2F     *R45VsE_FlatEx;
  TH2F     *R45VsE_TriangleEx;

  TH2F     *R45VsE_HEM15;
  TH2F     *R45VsE_HEM15G;
  TH2F     *R45VsE_HEM15B;
  TH2F     *R45VsE_HEP18;
  TH2F     *R45VsE_HBP14;
  TH2F     *R45VsE_HBP14G;
  TH2F     *R45VsE_HBP14B;
  TH2F     *R45VsE_HBM14;

  TH2F     *R45VsE_HBM13;
  TH2F     *R45VsE_HBM15;
  TH2F     *R45VsE_HBP13;
  TH2F     *R45VsE_HBP15;

  TH2F     *R45VsE_AllGood;
  TH1F     *R45_HEM15;
  TH1F     *R45_HEM15G;
  TH1F     *R45_HEM15B;
  TH1F     *R45_HEP18;
  TH1F     *R45_HBP14;
  TH1F     *R45_HBP14G;
  TH1F     *R45_HBP14B;
  TH1F     *R45_HBM14;
  TH1F     *R45_AllGood;
  TH1F     *R45_HB_AllGood;
  TH1F     *R45_HE_AllGood;

  TH1F     *R45_HBM13;
  TH1F     *R45_HBM15;
  TH1F     *R45_HBP13;
  TH1F     *R45_HBP15;


  TH1F     *R45_All;
  TH1F     *R45_Flagged;
  TH1F     *R45_Clean;
  TH1F     *R45_Clean_300;
  TH1F     *R45_Spike;
  TH1F     *R45_Flat;
  TH1F     *R45_Triangle;
  TH1F     *R45_Spike_300;
  TH1F     *R45_Flat_300;
  TH1F     *R45_Triangle_300;
  TH1F     *R45_Spike_300Ex;
  TH1F     *R45_Flat_300Ex;
  TH1F     *R45_Triangle_300Ex;
  TH1F     *R45_100;
  TH1F     *R45_200;
  TH1F     *R45_300;
  TH1F     *R45RBXFrac;
  TH1F     *R45RBXFrac_Flagged;
  TH1F     *R45BadRBXFrac;
  TH1F     *R45BadRBXFrac_Flagged;

  TProfile *TS4TS5VsPhi_HBP;
  TProfile *TS4TS5VsPhi_HBM;
  TProfile *TS4TS5VsPhi_HEP;
  TProfile *TS4TS5VsPhi_HEM;

  TProfile *TS4TS5VsRBX;
  TProfile *TS4TS5VsHPD;

  TH1F     *RecHit_numTS4TS5NoiseChannels;
  TH1F     *Noise_numTS4TS5NoiseChannels;
  TH1F     *Noise_numFlatNoiseChannels;
  TH1F     *Noise_numSpikeNoiseChannels;
  TH1F     *Noise_numTriangleNoiseChannels;

  TH1F     *Noise_numTS4TS5NoiseChannelsFlagged;
  TH1F     *Noise_numFlatNoiseChannelsFlagged;
  TH1F     *Noise_numSpikeNoiseChannelsFlagged;
  TH1F     *Noise_numTriangleNoiseChannelsFlagged;

  TH1F     *Noise_maxHPDHits;
  TH1F     *Noise_maxRBXHits;


};

#endif
