/*****************************************************************************
 * Copyright (C) 2009-2013   this file is part of the NPTool Project         *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Adrien MATTA  contact address: a.matta@surrey.ac.uk      *
 *                                                                           *
 * Creation Date  : November 2012                                            *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 *  This class hold the GeTAMU  raw data (Made for TIG10 card)              *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "TGeTAMUData.h"

ClassImp(TGeTAMUData)

/////////////////////////
TGeTAMUData::TGeTAMUData(){
}

/////////////////////////
TGeTAMUData::~TGeTAMUData(){
}

/////////////////////////
void TGeTAMUData::Clear(){
  fTIG_Ge_CloverNbr.clear();
  fTIG_Ge_CrystalNbr.clear();
  fTIG_Ge_SegmentNbr.clear();
  fTIG_Ge_Energy.clear();
  fTIG_Ge_TimeCFD.clear();
  fTIG_Ge_TimeLED.clear();

  fTIG_BGO_CloverNbr.clear();
  fTIG_BGO_CrystalNbr.clear();
  fTIG_BGO_PmNbr.clear();
  fTIG_BGO_Energy.clear();
  fTIG_BGO_TimeCFD.clear();
  fTIG_BGO_TimeLED.clear();
}

/////////////////////////
void TGeTAMUData::Dump() const{
  // Energy
 // cout << "GeTAMU_Mult = " << fTIG_CloverNbr.size() << endl;
  
  // Front
 // for (UShort_t i = 0; i < fTIG_CloverNbr.size(); i++){
 //   cout << "Clover: " << fTIG_CloverNbr[i]
 //        << " Crystal: " << fTIG_CrystalNbr[i]
 //        << " Energy: " << fTIG_Energy[i]
 //        << " Time: " << fTIG_Time[i] << endl;
 // }
}
