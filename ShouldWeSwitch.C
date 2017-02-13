#include "TROOT.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGraphAsymmErrors.h"

void ShouldWeSwitch()
{

  int nFills_8tev = 10;

  // 2 more fills at 405
  // 10 more of half and half 405, 432
  //
  // 2 more fills at 405
  // 7 or 8  more at 513
  //

  float LengthOfFill_8tev = 9;//hours

  char saythis[500];

  TF1 *fexp = new TF1("fexp","[0]*TMath::Exp([1]-x/[2])",0,6);
  fexp->SetLineStyle(2);

  double tau = 10.0;//hours

  double peak_rate = 1.69/4.0;
  double nBunches_old  = 405.0;
  double nBunches_new  = 513.0;
  double increase  = nBunches_new/nBunches_old;
  //double increase  = 1.5*1.5;
  //double decrease  = nBunches_old/nBunches_new;
  double decrease  = 1.0;
  int WeLoseBunches = 3;

  //fexp->SetParameters((418.5/405.)*8.5/9.0,peak_rate,tau);
  fexp->SetParameters(8.5/9.0,peak_rate,tau);


  TCanvas *c1 = new TCanvas("c1","c1");

  double metric = 0.0;
  for(int i=0; i<nFills_8tev; i++)
    metric += fexp->Integral(0,LengthOfFill_8tev);

  cout << "run 8 till the end :: " << metric << endl;

  cout << "  if we increase bunches by " << increase << " and decay const decreases by " << decrease << endl;

  metric = 0.0;
  fexp->SetParameters(increase*8.5/9.0,peak_rate,tau*decrease);
  for(int i=0; i<nFills_8tev-WeLoseBunches; i++)
    metric += fexp->Integral(0,LengthOfFill_8tev);

  cout << "run 8 till the end :: " << metric << endl;



}
