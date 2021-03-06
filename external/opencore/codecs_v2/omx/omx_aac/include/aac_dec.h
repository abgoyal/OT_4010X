
#ifndef AAC_DEC_H_INCLUDED
#define AAC_DEC_H_INCLUDED

#ifndef OSCL_BASE_H_INCLUDED
#include "oscl_base.h"
#endif

#ifndef OMX_Component_h
#include "OMX_Component.h"
#endif

#ifndef OSCL_MEM_H_INCLUDED
#include "oscl_mem.h"
#endif

#ifndef PVMP4AUDIODECODER_API_H
#include "pvmp4audiodecoder_api.h"
#endif

#define AACDEC_PCM_FRAME_SAMPLE_SIZE 1024 // 1024 samples 

class OmxAacDecoder
{
    public:
        OmxAacDecoder();

        OMX_BOOL AacDecInit(OMX_U32 aDesiredChannels);

        void AacDecDeinit();

        Int AacDecodeFrames(OMX_S16* aOutputBuffer,
                            OMX_U32* aOutputLength, OMX_U8** aInBuffer,
                            OMX_U32* aInBufSize, OMX_S32* aIsFirstBuffer,
                            OMX_AUDIO_PARAM_PCMMODETYPE* aAudioPcmParam,
                            OMX_AUDIO_PARAM_AACPROFILETYPE* aAudioAacParam,
                            OMX_U32* aSamplesPerFrame, OMX_BOOL* aResizeFlag);

        void UpdateAACPlusEnabled(OMX_BOOL flag);

        void ResetDecoder(); // for repositioning

        OMX_S32 iAacInitFlag;
        OMX_S32 iInputUsedLength;

    private:

        Int RetrieveDecodedStreamType();

        void*    ipMem;
        tPVMP4AudioDecoderExternal  iExt;
        OMX_U32 iNumOfChannels;
        OMX_U32  iMemReq;
        OMX_S32 iConfigUpSamplingFactor;

};



#endif  //#ifndef AVC_DEC_H_INCLUDED

