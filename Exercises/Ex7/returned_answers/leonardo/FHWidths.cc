// demo.cc
// demonstration program for calling FeynHiggs from C/C++
// this file is part of FeynHiggs
// last modified 31 Jan 18 th

// compile this file with something like
// build/f++ -Ibuild example/demo.cc build/libFH.a

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
#include <iostream>
#include <fstream>
using namespace std;
#endif

#include "CFeynHiggs.h"
#include "CSLHA.h"

#include "FHCouplings.h" // Added this based on the instruction in the API docs

/**********************************************************************/

static void setFlags() {
  enum {
    mssmpart = 4,
    higgsmix = 2,
    p2approx = 4,
    looplevel = 2,
    loglevel = 3,
    runningMT = 1,
    botResum = 1,
    tlCplxApprox = 3
  };

  int error;

  FHSetFlags(&error,
    mssmpart, higgsmix, p2approx, looplevel, loglevel,
    runningMT, botResum, tlCplxApprox);
  if( error ) exit(error);
}

/**********************************************************************/

static void setPara(cRealType MA0) {
  cRealType invAlfa0 = -1;
  cRealType invAlfaMZ = -1;
  cRealType AlfasMZ = -1;
  cRealType GF = -1;

  cRealType ME = -1;
  cRealType MU = -1;
  cRealType MD = -1;
  cRealType MM = -1;
  cRealType MC = -1;
  cRealType MS = -1;
  cRealType ML = -1;
  cRealType MB = -1;

  cRealType MW = -1;
  cRealType MZ = -1;
  cRealType GammaW = -1;
  cRealType GammaZ = -1;

  cRealType CKMlambda = -1;
  cRealType CKMA = -1;
  cRealType CKMrhobar = -1;
  cRealType CKMetabar = -1;

  cRealType MT = 173.2;
  cRealType TB = 5;
  cRealType MHp = -1;

  cRealType MSusy = 1000;
  cRealType M3SL = MSusy, M2SL = M3SL, M1SL = M2SL;
  cRealType M3SE = MSusy, M2SE = M3SE, M1SE = M2SE;
  cRealType M3SQ = MSusy, M2SQ = M3SQ, M1SQ = M2SQ;
  cRealType M3SU = MSusy, M2SU = M3SU, M1SU = M2SU;
  cRealType M3SD = MSusy, M2SD = M3SD, M1SD = M2SD;

  cComplexType Af = 2000;
  cComplexType At = Af, Ac = At, Au = Ac;
  cComplexType Ab = Af, As = Ab, Ad = As;
  cComplexType Atau = Af, Amu = Atau, Ae = Amu;

  cComplexType MUE = 200;
  cComplexType M_1 = 0;
  cComplexType M_2 = 500;
  cComplexType M_3 = 800;

  cRealType Qtau = 0;
  cRealType Qt = 0;
  cRealType Qb = 0;

  cRealType scalefactor = 1;

  int error;

  FHSetSMPara(&error,
    invAlfa0, invAlfaMZ, AlfasMZ, GF,
    ME, MU, MD, MM, MC, MS, ML, MB,
    MW, MZ, GammaW, GammaZ,
    CKMlambda, CKMA, CKMrhobar, CKMetabar);
  if( error ) exit(error);

  FHSetPara(&error, scalefactor,
    MT, TB, MA0, MHp,
    M3SL, M3SE, M3SQ, M3SU, M3SD,
    M2SL, M2SE, M2SQ, M2SU, M2SD,
    M1SL, M1SE, M1SQ, M1SU, M1SD,
    MUE,
    Atau, At, Ab,
    Amu, Ac, As,
    Ae, Au, Ad,
    M_1, M_2, M_3,
    Qtau, Qt, Qb);
  if( error ) exit(error);
}

/**********************************************************************/

static void setSLHA(const char *filename) {
  int error;
  COMPLEX slhadata[nslhadata];

  SLHARead(&error, slhadata, filename, 1);
  if( error ) exit(error);

  FHSetSLHA(&error, slhadata);
  if( error ) exit(error);
}

/**********************************************************************/

static void getPara() {
  int error, fv;
  RealType MSf[3][5][2], MASf[5][6], MCha[2], MNeu[4];
  ComplexType USf[3][5][2][2], UASf[5][6][6];
  ComplexType UCha[2][2], VCha[2][2], ZNeu[4][4];
  ComplexType DeltaMB;
  RealType MGl;
  RealType MHtree[4], SAtree, AlfasMT;

  FHGetPara(&error,
    &fv, MSf, USf, MASf, UASf,
    MCha, UCha, VCha, MNeu, ZNeu,
    &DeltaMB, &MGl, MHtree, &SAtree, &AlfasMT);
  if( error ) exit(error);


  /* copied this fortran from the API documentation, and rewrote in c++ below
#include "FHCouplings.h"
integer error
  double precision sqrts, prodxs(nprodxs)
  subroutine FHHiggsProd(error, sqrts, prodxs)
  */
  RealType sqrts, prodxs[nprodxs];
  sqrts = 14;
  FHHiggsProd(&error, sqrts, prodxs);
  
}

/**********************************************************************/

static void higgsCorr() {
  int error;
  RealType MHiggs[4];
  ComplexType SAeff, UHiggs[3][3], ZHiggs[3][3];

  FHHiggsCorr(&error, MHiggs, &SAeff, UHiggs, ZHiggs);

}

/**********************************************************************/

static float couplings(cRealType mass){
    int error, fast;
    fast = 1;
    ComplexType couplings[ncouplings], couplingsms[ncouplingsms];
    RealType gammas[ngammas], gammasms[ngammasms];
    FHCouplings(&error,couplings, couplingsms, gammas, gammasms, fast);
    return gammasms[2];
}

int main() {
    setFlags();
    ofstream file("results.txt");
    for(int i = 100; i <= 160; i++){
        cRealType MA0 = i;
        setPara(MA0);
        getPara();
        higgsCorr();
        file << MA0 << "\t" << couplings(MA0) << endl;
    }
    file.close();
}

