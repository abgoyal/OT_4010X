
// ----------------------------------------------------------------------
//
// This Software is an original work of authorship of PacketVideo Corporation.
// Portions of the Software were developed in collaboration with NTT  DoCoMo,
// Inc. or were derived from the public domain or materials licensed from
// third parties.  Title and ownership, including all intellectual property
// rights in and to the Software shall remain with PacketVideo Corporation
// and NTT DoCoMo, Inc.
//
// -----------------------------------------------------------------------
/*****************************************************************************/
/*  file name            : tsc_sub.h                                         */
/*  file contents        : Sub Routine Information Header                    */
/*  draw                 : '96.10.09                                         */
/*---------------------------------------------------------------------------*/
/*  amendment                                                                */
/*              Copyright (C) 1996 NTT DoCoMo                                */
/*****************************************************************************/
#if !defined (_TSC_SUB)
#define _TSC_SUB

#include <stdio.h>
#include "h245inf.h"
#include "pvt_params.h"

/*---------------------------------------------------------------------------*/
/*  Constant Definition                                                      */
/*---------------------------------------------------------------------------*/
typedef enum _parameterflag
{
    NOPARA,
    REJECT,
    ERRCODE,
    SOURCECAUSE
} ENUM_ParameterFlag;

/*---------------------------------------------------------------------------*/
/*  Prototype Declare                                                        */
/*---------------------------------------------------------------------------*/
void Tsc_UserNotify(ENUM_UserOperationId  UserOpId,
                    ENUM_ParameterFlag fParameter,
                    PS_ControlMsgHeader pReceiveInf);
void Tsc_SendDataSet(PS_ControlMsgHeader pInfHeader,
                     uint32 InfType,
                     uint32 InfId,
                     uint32 InfSupplement1,
                     uint32 InfSupplement2,
                     uint8* pParameter, uint32 Size);
void Tsc_ChoiceDataSet(uint32 TrueTarget,
                       uint8* pFirstTarget,
                       uint32 NumberTarget);
void Tsc_DescriptorFlagChange(uint32 fActDact,
                              uint32 TblEntryNumber,
                              uint32 isLocal);
void Tsc_InternalError(PS_ControlMsgHeader  pReceiveInf);

#endif
