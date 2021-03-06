// *****************************************************************************
// Written by Ritchie Lee, ritchie.lee@sv.cmu.edu
// *****************************************************************************
// Copyright ã 2015, United States Government, as represented by the
// Administrator of the National Aeronautics and Space Administration. All
// rights reserved.  The Reinforcement Learning Encounter Simulator (RLES)
// platform is licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License. You
// may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0. Unless required by applicable
// law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the License for the specific language
// governing permissions and limitations under the License.
// _____________________________________________________________________________
// Reinforcement Learning Encounter Simulator (RLES) includes the following
// third party software. The SISLES.jl package is licensed under the MIT Expat
// License: Copyright (c) 2014: Youngjun Kim.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED
// "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// *****************************************************************************

#ifndef LIBCCAS_H
#define LIBCCAS_H

#include "../../libcas/interface/libcasshared.h"
#include "libccas_Export.h"

using namespace std;
using namespace libcas;

typedef void* CConstants;
typedef void* CCASShared;
typedef void* COwnInput;
typedef void* CIntruderInput;
typedef void* CCollectionIntruderInput;
typedef void* CInput;
typedef void* CIntruderOutput;
typedef void* CCollectionIntruderOutput;
typedef void* COutput;

#ifdef  __cplusplus
extern "C"
{
#endif

libccas_EXPORT CConstants newCConstants(uint8 quant, const char* config_filename, uint32 max_intruders);

libccas_EXPORT void delCConstants(CConstants cconsts);

libccas_EXPORT CCASShared newCCASShared(CConstants cconsts, const char* library_path);

libccas_EXPORT void delCCASShared(CCASShared cCASShared);

libccas_EXPORT void reset(CCASShared cCASShared);

libccas_EXPORT COwnInput newCOwnInput(real dz, real z, real psi, real h, uint32 modes);

libccas_EXPORT COwnInput getCOwnInput(CInput cInput);

libccas_EXPORT void delCOwnInput(COwnInput cOwnInput);

libccas_EXPORT void setCOwnInput(COwnInput cOwnInput, real dz, real z, real psi, real h, uint32 modes);

libccas_EXPORT CIntruderInput newCIntruderInput(bool valid, uint32 id, uint32 modes, real sr, real chi,
	real z, uint8 cvc, uint8 vrc, uint8 vsb, int equipage,
	uint8 quant, uint8 sensitivity_index, uint8 protection_mode);

libccas_EXPORT void delCIntruderInput(CIntruderInput cIntruderInput);

libccas_EXPORT CIntruderInput getRefCIntruderInput(CCollectionIntruderInput cCollection, uint32 index);

libccas_EXPORT CCollectionIntruderInput newCCollectionIntruderInput();

libccas_EXPORT void delCCollectionIntruderInput(CCollectionIntruderInput cCollection);

libccas_EXPORT CCollectionIntruderInput getRefCCollectionIntruderInput(CInput cInput);

libccas_EXPORT void setCIntruderInput(CIntruderInput cIntruderInput, bool valid, uint32 id,
	uint32 modes, real sr, real chi, real z, uint8 cvc, uint8 vrc, uint8 vsb, int equipage,
	uint8 quant, uint8 sensitivity_index, uint8 protection_mode);

libccas_EXPORT void resizeCCollectionIntrInput(CCollectionIntruderInput cCollection, uint32 size);

libccas_EXPORT CIntruderInput getIndexCCollectionIntrInput(CCollectionIntruderInput cCollection, uint32 index);

libccas_EXPORT void setIndexCCollectionIntrInput(CCollectionIntruderInput cCollection, uint32 index, CIntruderInput cIntruderInput);

libccas_EXPORT uint32 sizeCCollectionIntrInput(CCollectionIntruderInput cCollection);

libccas_EXPORT CInput newCInput();

libccas_EXPORT void delCInput(CInput cInput);

libccas_EXPORT CIntruderOutput newCIntruderOutput(uint32 id, uint8 cvc, uint8 vrc, uint8 vsb, real tds, uint8 code);

libccas_EXPORT void delCIntruderOutput(CIntruderOutput cIntruderOutput);

libccas_EXPORT CIntruderOutput getRefCIntruderOutput(CCollectionIntruderOutput cCollection, uint32 index);

libccas_EXPORT void setCIntrOutput_id(CIntruderOutput cIntruderOutput, uint32 id);

libccas_EXPORT uint32 getCIntrOutput_id(CIntruderOutput cIntruderOutput);

libccas_EXPORT uint8 getCIntrOutput_cvc(CIntruderOutput cIntruderOutput);

libccas_EXPORT uint8 getCIntrOutput_vrc(CIntruderOutput cIntruderOutput);

libccas_EXPORT uint8 getCIntrOutput_vsb(CIntruderOutput cIntruderOutput);

libccas_EXPORT real getCIntrOutput_tds(CIntruderOutput cIntruderOutput);

libccas_EXPORT uint8 getCIntrOutput_code(CIntruderOutput cIntruderOutput);

libccas_EXPORT CCollectionIntruderOutput newCCollectionIntruderOutput();

libccas_EXPORT void delCCollectionIntruderOutput(CCollectionIntruderOutput cCollection);

libccas_EXPORT CCollectionIntruderOutput getRefCCollectionIntruderOutput(COutput cOutput);

libccas_EXPORT void resizeCCollectionIntrOutput(CCollectionIntruderOutput cCollection, uint32 size);

libccas_EXPORT CIntruderOutput getIndexCCollectionIntrOutput(CCollectionIntruderOutput cCollection, uint32 index);

libccas_EXPORT void setIndexCCollectionIntrOutput(CCollectionIntruderOutput cCollection, uint32 index, CIntruderOutput cIntruderOutput);

libccas_EXPORT uint32 sizeCCollectionIntrOutput(CCollectionIntruderOutput cCollection);

libccas_EXPORT COutput newCOutput();

libccas_EXPORT void delCOutput(COutput cOutput);

libccas_EXPORT uint8 getCOutput_cc(COutput cOutput);

libccas_EXPORT uint8 getCOutput_vc(COutput cOutput);

libccas_EXPORT uint8 getCOutput_ua(COutput cOutput);

libccas_EXPORT uint8 getCOutput_da(COutput cOutput);

libccas_EXPORT real getCOutput_target_rate(COutput cOutput);

libccas_EXPORT bool getCOutput_turn_off_aurals(COutput cOutput);

libccas_EXPORT bool getCOutput_crossing(COutput cOutput);

libccas_EXPORT bool getCOutput_alarm(COutput cOutput);

libccas_EXPORT bool getCOutput_alert(COutput cOutput);

libccas_EXPORT real getCOutput_dh_min(COutput cOutput);

libccas_EXPORT real getCOutput_dh_max(COutput cOutput);

libccas_EXPORT uint8 getCOutput_sensitivity_index(COutput cOutput);

libccas_EXPORT real getCOutput_ddh(COutput cOutput);

libccas_EXPORT void update(CCASShared cCASShared, CInput cInput, COutput cOutput);

libccas_EXPORT void print_CInput(CInput cInput);

libccas_EXPORT void print_COutput(COutput cOutput);

libccas_EXPORT const char* version(CCASShared cCASShared);

libccas_EXPORT const char* error(CCASShared cCASShared);

libccas_EXPORT uint32 max_intruders(CCASShared cCASShared);

libccas_EXPORT const char* author();

libccas_EXPORT int enum_EQUIPAGE_ATCRBS();

libccas_EXPORT int enum_EQUIPAGE_MODES();

libccas_EXPORT int enum_EQUIPAGE_TCASTA();

libccas_EXPORT int enum_EQUIPAGE_TCAS();

libccas_EXPORT void debug_main();

#ifdef  __cplusplus
}
#endif

#endif /* LIBCCAS_H */
