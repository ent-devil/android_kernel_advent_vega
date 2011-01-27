/*
 * Copyright (c) 2006-2009 NVIDIA Corporation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of the NVIDIA Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "nvodm_touch.h"
#include "nvodm_touch_int.h"

#if defined(NV_TOUCH_TPK)
#include "nvodm_touch_tpk.h"
#endif
#if defined(NV_TOUCH_PANJIT)
#include "nvodm_touch_panjit.h"
#endif

/** Implementation for the NvOdm TouchPad */

NvBool
NvOdmTouchDeviceOpen( NvOdmTouchDeviceHandle *hDevice )
{
    NvBool ret = NV_TRUE;

#if defined(NV_TOUCH_TPK)
    ret = TPK_Open(hDevice);
#endif
#if defined(NV_TOUCH_PANJIT)
    ret = PANJIT_Open(hDevice);
#endif

    return ret;
}


void
NvOdmTouchDeviceGetCapabilities(NvOdmTouchDeviceHandle hDevice, NvOdmTouchCapabilities* pCapabilities)
{
    hDevice->GetCapabilities(hDevice, pCapabilities);
}


NvBool
NvOdmTouchReadCoordinate( NvOdmTouchDeviceHandle hDevice, NvOdmTouchCoordinateInfo *coord)
{
    return hDevice->ReadCoordinate(hDevice, coord);
}

NvBool
NvOdmTouchGetSampleRate(NvOdmTouchDeviceHandle hDevice, NvOdmTouchSampleRate* pTouchSampleRate)
{
    return hDevice->GetSampleRate(hDevice, pTouchSampleRate);
}

void NvOdmTouchDeviceClose(NvOdmTouchDeviceHandle hDevice)
{
    hDevice->Close(hDevice);    
}

NvBool NvOdmTouchEnableInterrupt(NvOdmTouchDeviceHandle hDevice, NvOdmOsSemaphoreHandle hInterruptSemaphore)
{
    return hDevice->EnableInterrupt(hDevice, hInterruptSemaphore);
}

NvBool NvOdmTouchHandleInterrupt(NvOdmTouchDeviceHandle hDevice)
{
    return hDevice->HandleInterrupt(hDevice);
}

NvBool
NvOdmTouchSetSampleRate(NvOdmTouchDeviceHandle hDevice, NvU32 SampleRate)
{
    return hDevice->SetSampleRate(hDevice, SampleRate);
}


NvBool
NvOdmTouchPowerControl(NvOdmTouchDeviceHandle hDevice, NvOdmTouchPowerModeType mode)
{
    return hDevice->PowerControl(hDevice, mode);
}

void
NvOdmTouchPowerOnOff(NvOdmTouchDeviceHandle hDevice, NvBool OnOff)
{
    hDevice->PowerOnOff(hDevice, OnOff);
}


NvBool
NvOdmTouchOutputDebugMessage(NvOdmTouchDeviceHandle hDevice)
{
    return hDevice->OutputDebugMessage;
}

NvBool
NvOdmTouchGetCalibrationData(NvOdmTouchDeviceHandle hDevice, NvU32 NumOfCalibrationData, NvS32* pRawCoordBuffer)
{
    return hDevice->GetCalibrationData(hDevice, NumOfCalibrationData, pRawCoordBuffer);
}
