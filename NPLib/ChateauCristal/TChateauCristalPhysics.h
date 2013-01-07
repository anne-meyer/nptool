#ifndef __ChateauCristalPhysics__
#define __ChateauCristalPhysics__
/*****************************************************************************
 * Copyright (C) 2009-2010   this file is part of the NPTool Project         *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Adrien MATTA  contact address: matta@ipno.in2p3.fr       *
 *                                                                           *
 * Creation Date  : November 2009                                            *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Description:                                                              *
 *                                                                           *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/

//   STL
#include <vector>
using namespace std ;
//   ROOT
#include "TObject.h"
//   NPL
#include "TChateauCristalData.h"
#include "../include/VDetector.h"
#include "../include/CalibrationManager.h"

class TChateauCristalPhysics : public TObject, public NPA::VDetector
{
 public:   //   Constructor and Destructor
   TChateauCristalPhysics();
   ~TChateauCristalPhysics();

 public:   //   Calibrated Data
   vector<UShort_t>   DetectorNumber;
   vector<Double_t>   Energy;
   vector<Double_t>   Time;

   map<Int_t, Double_t> mapDetectorAngleCorrec; //!
   map<Int_t, Double_t> mapDetectorAngleGeo;    //!

 public:   //   inherited from VDetector
   // Read stream at ConfigFile to pick-up parameters of detector (Position,...) using Token
   void ReadConfiguration(string);
      
   // Add Parameter to the CalibrationManager
   void AddParameterToCalibrationManager();      

   //   Activated associated Branches and link it to the private member DetectorData address
   //   In this method mother Branches (Detector) AND daughter leaf (fDetector_parameter) have to be activated
   void InitializeRootInputRaw() ;
   
   //   Activated associated Branches and link it to the private member DetectorPhysics address
   //   In this method mother Branches (Detector) AND daughter leaf (parameter) have to be activated
   void InitializeRootInputPhysics() ;

   // Create associated branches and associated private member DetectorPhysics address
   void InitializeRootOutput();

   // This method is called at each event read from the Input Tree. Aime is to build treat Raw dat in order to extract physical parameter. 
   void BuildPhysicalEvent();
            
   // Same as above, but only the simplest event and/or simple method are used (low multiplicity, faster algorythm but less efficient ...).
   // This method aimed to be used for analysis performed during experiment, when speed is requiered.
   // NB: This method can eventually be the same as BuildPhysicalEvent.
   void BuildSimplePhysicalEvent();

   // Same as above but for online analysis
   void BuildOnlinePhysicalEvent()  {BuildPhysicalEvent();};

   // Those two method all to clear the Event Physics or Data
   void ClearEventPhysics() {Clear();}
   void ClearEventData()    {EventData->Clear();}

 public: //   Specific to ChateauCristal
   // Clear The PreTeated object
   void ClearPreTreatedData()   {PreTreatedData->Clear();}
      
   // Remove bad channel, calibrate the data and apply threshold
   void PreTreat();

   // Initialize the standard parameter for analysis
   // ie: all channel enable, maximum multiplicity for strip = number of telescope
   void InitializeStandardParameter();
   
   //  Read the user configuration file; if no file found, load standard one
   void ReadAnalysisConfig();

   // Give an external TChateauCristalData object to TChateauCristalPhysics, needed for online analysis
   void SetRawDataPointer(TChateauCristalData* rawDataPointer) {EventData = rawDataPointer;}
 
   // Retrieve pre-treated data
   TChateauCristalData* GetPreTreatedData() const {return PreTreatedData;}

 protected:
   double DopplerCorrection(double Energy, double Theta);

   // Add a BaF2 module
   void AddModule(string AngleFile);

private:   // Data not written in the tree
   int           NumberOfDetectors;//!
   TChateauCristalData*    EventData;//!
   TChateauCristalData*    PreTreatedData;//!
   TChateauCristalPhysics* EventPhysics;//!

   double E_Threshold;//!
   double Pedestal_Threshold;//!
            
 private: //  Map of activated Channel
   map< int, bool > ChannelStatus;//!
    
 public:  
   void Clear();
   void Clear(const Option_t*) {};
   
   ClassDef(TChateauCristalPhysics,1)  // ChateauCristalPhysics structure
};


namespace ChateauCristal_LOCAL
{
   double fChateauCristal_E( const TChateauCristalData* EventData , const int i );
   double fChateauCristal_T( const TChateauCristalData* EventData , const int i );
}

#endif
