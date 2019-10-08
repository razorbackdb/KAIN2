#include "THISDUST.H"
#include "AADLIB.H"

u_long aadGetMemorySize(AadInitAttr *attributes)

{
  return (u_long)(&DAT_00001c88 + attributes->numSlots * 0x5d0);
}

int aadInit(AadInitAttr *attributes, u_char *memoryPtr)

{
  byte bVar1;
  AadMemoryStruct *pAVar2;
  AadMemoryStruct *pAVar3;
  u_long __n;
  undefined *puVar4;
  _func_36 *p_Var5;
  _func_36 *p_Var6;
  _func_36 *p_Var7;
  int iVar8;
  u_int uVar9;
  int iVar10;

  aadGp = (u_long)GetGp();
  ExitCriticalSection();
  __n = aadGetMemorySize(attributes);
  aadMem = (AadMemoryStruct *)memoryPtr;
  if (memoryPtr == (u_char *)0x0)
  {
    puVar4 = &DAT_00001009;
  }
  else
  {
    memset(memoryPtr, 0, __n);
    pAVar2 = aadMem;
    puVar4 = &DAT_00001008;
    if ((attributes->nonBlockLoadProc != (_func_32 *)0x0) &&
        (puVar4 = &DAT_00001008, attributes->nonBlockBufferedLoadProc != (_func_33 *)0x0))
    {
      if (attributes->memoryMallocProc == (_func_34 *)0x0)
      {
        puVar4 = &DAT_00001008;
      }
      else
      {
        *(_func_32 **)&aadMem->nonBlockLoadProc = attributes->nonBlockLoadProc;
        *(_func_33 **)&pAVar2->nonBlockBufferedLoadProc = attributes->nonBlockBufferedLoadProc;
        *(_func_34 **)&pAVar2->memoryMallocProc = attributes->memoryMallocProc;
        *(_func_35 **)&pAVar2->memoryFreeProc = attributes->memoryFreeProc;
        memset(pAVar2->sfxToneMasterList, 0xff, 0x200);
        memset(aadMem->sfxWaveMasterList, 0xff, 0x200);
        pAVar2 = aadMem;
        aadMem->sramDescriptorTbl[0].prevIndex = -1;
        pAVar3 = aadMem;
        pAVar2->nextSramDescIndex = 1;
        pAVar2->sramDescriptorTbl[0].waveID = 0x8000;
        pAVar2->sramDescriptorTbl[0].address = 0x202;
        pAVar2->firstSramBlockDescIndex = 0;
        pAVar2->sramDescriptorTbl[0].size = 0x91d8;
        pAVar3->sramDescriptorTbl[0].nextIndex = -1;
        aadPurgeLoadQueue();
        _SpuInit();
        SpuSetCommonMasterVolume(0, 0);
        iVar10 = 0;
        if (0 < attributes->numSlots)
        {
          puVar4 = &DAT_00001c88;
          do
          {
            iVar8 = 0;
            p_Var6 = (_func_36 *)((int)&aadMem->updateCounter + (int)puVar4);
            aadMem->sequenceSlots[iVar10] = p_Var6;
            p_Var6[0x53f] = SUB41(iVar10, 0);
            p_Var6[0x53e] = (_func_36)0xff;
            p_Var6[0x551] = SUB41(iVar10 << 4, 0);
            p_Var6[0x552] = (_func_36)0x7f;
            p_Var6[0x553] = (_func_36)0x3f;
            *(int **)(p_Var6 + 0x554) = &aadMem->musicMasterVol;
            p_Var7 = p_Var6;
            do
            {
              p_Var5 = p_Var6 + iVar8;
              p_Var5[0x590] = (_func_36)0xff;
              p_Var5[0x5a0] = (_func_36)0x7f;
              p_Var5[0x5b0] = (_func_36)0x3f;
              *(undefined2 *)(p_Var7 + 0x570) = 0x2000;
              iVar8 = iVar8 + 1;
              p_Var7 = p_Var7 + 2;
            } while (iVar8 < 0x10);
            *(_func_36 **)(p_Var6 + 0x538) = p_Var6;
            p_Var6[0x53c] = SUB41(iVar10, 0);
            iVar10 = iVar10 + 1;
            puVar4 = puVar4 + 0x5d0;
          } while (iVar10 < attributes->numSlots);
        }
        pAVar2 = aadMem;
        uVar9 = 0;
        (aadMem->sfxSlot).handleCounter = 0x3039;
        (pAVar2->sfxSlot).sfxVolume = '\x7f';
        pAVar2 = aadMem;
        iVar10 = 0;
        aadMem->numSlots = (u_int) * (byte *)&attributes->numSlots;
        bVar1 = *(byte *)&attributes->updateMode;
        pAVar2->sfxMasterVol = 0x7f;
        pAVar2->musicMasterVol = 0x7f;
        pAVar2->endSequenceCallback = (_func_49 *)0x0;
        pAVar2->controller11Callback = (_func_48 *)0x0;
        pAVar2->updateMode = (u_int)bVar1;
        do
        {
          iVar8 = (int)&aadMem->updateCounter + iVar10;
          *(undefined *)(iVar8 + 0x1e4) = 0xff;
          pAVar2 = aadMem;
          *(int *)(iVar8 + 0x1dc) = 1 << (uVar9 & 0x1f);
          (&pAVar2->synthVoice[0].voiceNum)[iVar10] = (u_char)uVar9;
          pAVar2 = aadMem;
          uVar9 = uVar9 + 1;
          iVar10 = iVar10 + 0x1c;
        } while ((int)uVar9 < 0x18);
        iVar10 = aadMem->updateMode;
        aadMem->voiceKeyOffRequest = 0;
        pAVar2->voiceKeyOnRequest = 0;
        pAVar2->voiceReverbRequest = 0;
        if (iVar10 < 4)
        {
          aadInstallUpdateFunc(aadSlotUpdateWrapper, (u_int)(&aadHblanksPerUpdate)[iVar10]);
        }
        aadMem->flags = 0;
        EnterCriticalSection();
        puVar4 = (undefined *)0x0;
      }
    }
  }
  return (int)puVar4;
}

void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, int hblanksPerUpdate)

{
  ExitCriticalSection();
  __hblankEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000001, (short)hblanksPerUpdate, 0x1000);
  StartRCnt(0xf2000001);
  EnterCriticalSection();
  return;
}

void aadInitVolume(void)

{
  aadMem->masterVolume = 0;
  SpuSetCommonAttr(0);
  SpuSetCommonMasterVolume(0, 0);
  return;
}

void aadSetMusicMasterVolume(int volume)

{
  int iVar1;

  iVar1 = (int)(short)volume;
  aadMem->masterVolume = iVar1;
  SpuSetCommonMasterVolume(iVar1, iVar1);
  return;
}

void aadSetSfxMasterVolume(int targetVolume, int volumeStep,
                           TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback)

{
  AadMemoryStruct *pAVar1;

  pAVar1 = aadMem;
  (aadMem->masterVolFader).volumeStep = volumeStep;
  (pAVar1->masterVolFader).targetVolume = targetVolume;
  *(TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback *)&(pAVar1->masterVolFader).fadeCompleteCallback = fadeCompleteCallback;
  return;
}

void aadSetMasterVolume(int volume)

{
  aadMem->sfxMasterVol = volume & 0xff;
  return;
}

void SOUND_SetMusicVolume(int volume)

{
  int *piVar1;
  _AadSequenceSlot **pp_Var2;
  int iVar3;

  piVar1 = &aadMem->numSlots;
  iVar3 = 0;
  aadMem->musicMasterVol = volume;
  if (0 < *piVar1)
  {
    do
    {
      pp_Var2 = (_AadSequenceSlot **)(aadMem->sequenceSlots + iVar3);
      iVar3 = iVar3 + 1;
      aadUpdateSlotVolPan(*pp_Var2);
    } while (iVar3 < aadMem->numSlots);
  }
  return;
}

void aadStartMasterVolumeFade(int targetVolume, int volumeStep,
                              TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback)

{
  AadMemoryStruct *pAVar1;

  pAVar1 = aadMem;
  (aadMem->musicMasterVolFader).volumeStep = volumeStep;
  (pAVar1->musicMasterVolFader).targetVolume = targetVolume;
  *(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback *)&(pAVar1->musicMasterVolFader).fadeCompleteCallback = fadeCompleteCallback;
  return;
}

void aadShutdownReverb(void)

{
  u_int uVar1;
  u_char uVar2;
  u_int in_a2;

  ExitCriticalSection();
  StopRCnt(0xf2000001);
  DisableEvent();
  CloseEvent();
  aadMem->flags = aadMem->flags | 2;
  EnterCriticalSection();
  uVar2 = 0xffffff;
  SpuSetKey(0, 0xffffff);
  uVar1 = aadGetReverbMode();
  SpuClearReverbWorkArea(uVar1, uVar2, in_a2);
  SpuQuit();
  aadMem = (AadMemoryStruct *)0x0;
  return;
}

long aadSlotUpdateWrapper(void)

{
  GetGp();
  SetGp();
  aadSlotUpdate();
  SetGp();
  return 0;
}

void aadSlotUpdate(void)

{
  char cVar1;
  byte bVar2;
  u_short uVar3;
  bool bVar4;
  AadSfxSlot *pAVar5;
  AadMemoryStruct *pAVar6;
  u_long uVar7;
  int track;
  int iVar8;
  u_char uVar9;
  _func_12 *p_Var10;
  u_int uVar11;
  AadSeqEvent *event;
  u_int uVar12;
  int iVar13;
  _AadSequenceSlot *p_Var14;
  _AadSequenceSlot *slot;
  _AadSequenceSlot *p_Var15;

  if (aadMem != (AadMemoryStruct *)0x0)
  {
    if ((aadMem->flags & 2U) == 0)
    {
      SpuGetAllKeysStatus(aadMem->voiceStatus);
      pAVar6 = aadMem;
      iVar13 = 0;
      uVar12 = 1;
      do
      {
        cVar1 = pAVar6->voiceStatus[iVar13];
        if (cVar1 == '\x03')
        {
          uVar7 = pAVar6->voiceKeyOffRequest | uVar12;
        LAB_800522e8:
          pAVar6->voiceKeyOffRequest = uVar7;
        }
        else
        {
          if (((pAVar6->voiceKeyOffRequest & uVar12) != 0) && ((cVar1 == '\0' || (cVar1 == '\x02'))))
          {
            uVar7 = pAVar6->voiceKeyOffRequest & ~uVar12;
            goto LAB_800522e8;
          }
        }
        iVar13 = iVar13 + 1;
        uVar12 = uVar12 << 1;
      } while (iVar13 < 0x18);
      if (((aadMem->flags & 4U) == 0) && (iVar13 = 0, 0 < aadMem->numSlots))
      {
        track = 0;
        do
        {
          slot = *(_AadSequenceSlot **)((int)aadMem->sequenceSlots + track);
          if (((slot->status & 1) != 0) && ((slot->slotFlags & 1) == 0))
          {
            (slot->tempo).currentTick =
                (slot->tempo).currentTick + (u_int)(slot->tempo).ticksPerUpdate;
            uVar11 = (slot->tempo).tickTimeFixed;
            uVar12 = (slot->tempo).currentError + (slot->tempo).errorPerUpdate;
            (slot->tempo).currentError = uVar12;
            if (uVar11 <= uVar12)
            {
              (slot->tempo).currentError = uVar12 - uVar11;
              (slot->tempo).currentTick = (slot->tempo).currentTick + 1;
            }
            track = 0;
            p_Var14 = slot;
            p_Var15 = slot;
            do
            {
              if (p_Var15->sequencePosition[0] == (_func_9 *)0x0)
                break;
              bVar2 = p_Var14->eventsInQueue[0];
              while ((bVar2 < 3 && (iVar8 = aadQueueNextEvent(slot, track), iVar8 == 0)))
              {
                bVar2 = p_Var14->eventsInQueue[0];
              }
              p_Var14 = (_AadSequenceSlot *)((int)&(p_Var14->tempo).currentTick + 1);
              track = track + 1;
              p_Var15 = (_AadSequenceSlot *)&(p_Var15->tempo).currentError;
            } while (track < 0x10);
            track = 0;
            iVar8 = 0;
            p_Var14 = slot;
            p_Var15 = slot;
            do
            {
              if (p_Var14->sequencePosition[0] == (_func_9 *)0x0)
                break;
              uVar9 = p_Var15->eventsInQueue[0];
              while (uVar9 != '\0')
              {
                event = (AadSeqEvent *)((int)&slot->eventQueue[(u_int)p_Var15->eventOut[0] * 0x10].deltaTime + iVar8);
                uVar12 = event->deltaTime + p_Var14->lastEventExecutedTime[0];
                if ((slot->tempo).currentTick < uVar12)
                  break;
                p_Var14->lastEventExecutedTime[0] = uVar12;
                uVar9 = p_Var15->eventOut[0] + '\x01';
                p_Var15->eventOut[0] = uVar9;
                p_Var15->eventsInQueue[0] = p_Var15->eventsInQueue[0] + -1;
                if (uVar9 == '\x04')
                {
                  p_Var15->eventOut[0] = '\0';
                }
                aadExecuteSfxCommand(event, slot);
                uVar9 = p_Var15->eventsInQueue[0];
              }
              p_Var14 = (_AadSequenceSlot *)&(p_Var14->tempo).currentError;
              iVar8 = iVar8 + 0xc;
              track = track + 1;
              p_Var15 = (_AadSequenceSlot *)((int)&(p_Var15->tempo).currentTick + 1);
            } while (track < 0x10);
          }
          iVar13 = iVar13 + 1;
          track = iVar13 * 4;
        } while (iVar13 < aadMem->numSlots);
      }
      uVar3 = (aadMem->sfxSlot).commandsInQueue;
      while (uVar3 != 0)
      {
        aadExecuteEvent((aadMem->sfxSlot).commandQueue + (aadMem->sfxSlot).commandOut);
        pAVar6 = aadMem;
        pAVar5 = &aadMem->sfxSlot;
        uVar9 = (aadMem->sfxSlot).commandOut + '\x01';
        (aadMem->sfxSlot).commandOut = uVar9;
        (pAVar6->sfxSlot).commandsInQueue = pAVar5->commandsInQueue - 1;
        if (uVar9 == ' ')
        {
          (aadMem->sfxSlot).commandOut = '\0';
        }
        uVar3 = (aadMem->sfxSlot).commandsInQueue;
      }
      uVar12 = aadMem->voiceKeyOffRequest & ~aadMem->voiceKeyOnRequest;
      aadMem->voiceKeyOffRequest = uVar12;
      if (uVar12 != 0)
      {
        SpuSetKey(0, uVar12);
      }
      SpuSetReverbVoice(1, aadMem->voiceReverbRequest);
      SpuSetReverbVoice(0, ~aadMem->voiceReverbRequest);
      if (aadMem->voiceKeyOnRequest != 0)
      {
        SpuSetKey(1, aadMem->voiceKeyOnRequest);
        aadMem->voiceKeyOnRequest = 0;
      }
    }
    iVar13 = (aadMem->masterVolFader).volumeStep;
    bVar4 = false;
    if (iVar13 != 0)
    {
      track = aadMem->masterVolume + iVar13;
      if (iVar13 < 0)
      {
        bVar4 = track < (aadMem->masterVolFader).targetVolume;
      }
      else
      {
        if ((aadMem->masterVolFader).targetVolume < track)
        {
          bVar4 = true;
        }
      }
      if (bVar4)
      {
        track = (aadMem->masterVolFader).targetVolume;
        p_Var10 = (aadMem->masterVolFader).fadeCompleteCallback;
        (aadMem->masterVolFader).volumeStep = 0;
        if (p_Var10 != (_func_12 *)0x0)
        {
          (*p_Var10)();
        }
      }
      aadSetMusicMasterVolume(track);
    }
    iVar13 = (aadMem->musicMasterVolFader).volumeStep;
    if ((iVar13 != 0) && (bVar4 = false, (aadMem->updateCounter & 1) == 0))
    {
      track = aadMem->musicMasterVol + iVar13;
      if (iVar13 < 0)
      {
        bVar4 = track <= (aadMem->musicMasterVolFader).targetVolume;
      }
      else
      {
        if ((aadMem->musicMasterVolFader).targetVolume <= track)
        {
          bVar4 = true;
        }
      }
      if (bVar4)
      {
        track = (aadMem->musicMasterVolFader).targetVolume;
        p_Var10 = (aadMem->musicMasterVolFader).fadeCompleteCallback;
        (aadMem->musicMasterVolFader).volumeStep = 0;
        if (p_Var10 != (_func_12 *)0x0)
        {
          (*p_Var10)();
        }
      }
      SOUND_SetMusicVolume(track);
    }
    aadMem->updateCounter = aadMem->updateCounter + 1;
  }
  return;
}

u_long aadCreateFourCharID(char a, char b, char c, char d)

{
  return CONCAT13(a, CONCAT12(b, CONCAT11(c, d)));
}

int aadLoadDynamicSfxReturn(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption,
                            TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc)

{
  AadMemoryStruct *pAVar1;
  undefined *puVar2;
  AadMemoryStruct *pAVar3;
  int iVar4;
  AadDynamicBankLoadInfo *__dest;

  pAVar1 = aadMem;
  iVar4 = 0;
  __dest = &aadMem->dynamicBankLoadInfo;
  pAVar3 = aadMem;
  do
  {
    iVar4 = iVar4 + 1;
    if (pAVar3->dynamicBankStatus[0] == 1)
    {
      return (int)&DAT_00001006;
    }
    pAVar3 = (AadMemoryStruct *)&pAVar3->numSlots;
  } while (iVar4 < 2);
  if (dynamicBankIndex < 2)
  {
    if (((&aadMem->updateCounter + dynamicBankIndex)[0x140] == 2) &&
        ((&aadMem->updateCounter + dynamicBankIndex)[0x142] != 0))
    {
      aadFreeDynamicSoundBank(dynamicBankIndex);
    }
    aadMem->dynamicBankStatus[dynamicBankIndex] = 1;
    strncmp((char *)__dest, sndFileName, 0x1f);
    strncmp((pAVar1->dynamicBankLoadInfo).smpFileName, smpFileName, 0x1f);
    (pAVar1->dynamicBankLoadInfo).dynamicBankIndex = dynamicBankIndex;
    (pAVar1->dynamicBankLoadInfo).loadOption = loadOption;
    (pAVar1->dynamicBankLoadInfo).flags = 0;
    *(TDRFuncPtr_aadLoadDynamicSoundBank4retProc *)&(pAVar1->dynamicBankLoadInfo).userCallbackProc =
        retProc;
    (*aadMem->nonBlockLoadProc)(sndFileName, aadLoadDynamicSoundBankReturn, __dest, 0,
                                aadMem->dynamicSoundBankData + dynamicBankIndex, 4);
    puVar2 = (undefined *)0x0;
  }
  else
  {
    puVar2 = &DAT_00001005;
  }
  return (int)puVar2;
}

void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2)

{
  u_long *puVar1;
  AadMemoryStruct *pAVar2;
  u_int uVar3;
  u_int dynamicBankIndex;

  dynamicBankIndex = *(u_int *)((int)data + 0x40);
  uVar3 = aadOpenDynamicSoundBank((u_char *)loadedDataPtr, dynamicBankIndex);
  pAVar2 = aadMem;
  if (uVar3 == 0)
  {
    (*aadMem->nonBlockBufferedLoadProc)((int)data + 0x20, aadLoadDynamicSoundBank, data, 0);
  }
  else
  {
    puVar1 = &aadMem->updateCounter;
    (puVar1 + dynamicBankIndex)[0x140] = uVar3 & 0xff | 0x80;
    if ((puVar1 + dynamicBankIndex)[0x142] != 0)
    {
      (*pAVar2->memoryFreeProc)();
      aadMem->dynamicSoundBankData[dynamicBankIndex] = (_func_43 *)0x0;
    }
    if (*(code **)((int)data + 0x48) != (code *)0x0)
    {
      (**(code **)((int)data + 0x48))(dynamicBankIndex & 0xffff, uVar3);
    }
  }
  return;
}

void aadLoadDynamicSoundBank(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2)

{
  AadMemoryStruct *pAVar1;
  u_long uVar2;
  int iVar3;
  u_long *puVar4;
  u_int uVar5;
  code *pcVar6;
  u_char *puVar7;
  u_int uVar8;
  int iVar9;

  uVar5 = (u_int)(u_short)status << 0x10;
  iVar9 = (int)uVar5 >> 0x10;
  uVar8 = *(u_int *)((int)data1 + 0x40);
  if (iVar9 < 0x100)
  {
    if ((*(u_int *)((int)data1 + 0x54) & 1) == 0)
    {
      puVar7 = (u_char *)((int)loadedDataPtr + 4);
      *(u_int *)((int)data1 + 0x54) = *(u_int *)((int)data1 + 0x54) | 1;
      loadedDataPtr = (void *)((int)loadedDataPtr + 8);
      loadedDataSize = loadedDataSize - 8;
      *(u_char *)((int)data1 + 0x4c) = *puVar7;
      if ((*(int *)((int)data1 + 0x44) == 0) || (*(int *)((int)data1 + 0x44) != 1))
      {
        *(u_char *)((int)data1 + 0x50) = 0x49ed0;
      }
      else
      {
        uVar2 = aadGetReverbDepth();
        *(int *)((int)data1 + 0x50) = (0x80000 - *(int *)((int)data1 + 0x4c)) - uVar2;
      }
      aadMem->dynamicSoundBankSramData[uVar8] = *(u_long *)((int)data1 + 0x50);
    }
    aadWaitForSramTransferComplete();
    SpuSetTransferCallback(*(u_int *)((int)data1 + 0x50));
    SpuRead((word *)loadedDataPtr, loadedDataSize, uVar5);
    *(int *)((int)data1 + 0x50) = *(int *)((int)data1 + 0x50) + loadedDataSize;
    if (status != 1)
    {
      return;
    }
    iVar9 = 0;
    if (0 < *(int *)(aadMem->dynamicSoundBankHdr[uVar8] + 0x14))
    {
      puVar4 = &aadMem->updateCounter + uVar8;
      iVar3 = 0;
      do
      {
        *(int *)(puVar4[0x13a] + iVar3) = *(int *)(puVar4[0x13a] + iVar3) + puVar4[0x144];
        iVar9 = iVar9 + 1;
        iVar3 = iVar9 * 4;
      } while (iVar9 < *(int *)(puVar4[0x134] + 0x14));
    }
    aadMem->dynamicBankStatus[uVar8] = 2;
    pcVar6 = *(code **)((int)data1 + 0x48);
    uVar8 = uVar8 & 0xffff;
    if (pcVar6 == (code *)0x0)
    {
      return;
    }
    iVar9 = 0;
  }
  else
  {
    if ((*(u_int *)((int)data1 + 0x54) & 2) != 0)
    {
      return;
    }
    *(u_int *)((int)data1 + 0x54) = *(u_int *)((int)data1 + 0x54) | 2;
    pAVar1 = aadMem;
    puVar4 = &aadMem->updateCounter;
    (puVar4 + uVar8)[0x140] = uVar5 >> 0x18 | 0x80;
    if ((puVar4 + uVar8)[0x142] != 0)
    {
      (*pAVar1->memoryFreeProc)();
      aadMem->dynamicSoundBankData[uVar8] = (_func_43 *)0x0;
    }
    pcVar6 = *(code **)((int)data1 + 0x48);
    if (pcVar6 == (code *)0x0)
    {
      return;
    }
  }
  (*pcVar6)(uVar8, iVar9);
  return;
}

int aadFreeDynamicSoundBank(int dynamicBankIndex)

{
  AadMemoryStruct *pAVar1;
  undefined *puVar2;
  u_long *puVar3;

  pAVar1 = aadMem;
  if (dynamicBankIndex < 2)
  {
    puVar3 = &aadMem->updateCounter + dynamicBankIndex;
    puVar2 = &DAT_00001007;
    if ((puVar3[0x140] == 2) && (puVar2 = &DAT_00001007, puVar3[0x142] != 0))
    {
      puVar3[0x140] = 0;
      (*pAVar1->memoryFreeProc)(puVar3[0x142]);
      puVar2 = (undefined *)0x0;
      aadMem->dynamicSoundBankData[dynamicBankIndex] = (_func_43 *)0x0;
    }
  }
  else
  {
    puVar2 = &DAT_00001005;
  }
  return (int)puVar2;
}

int aadOpenDynamicSoundBank(u_char *soundBank, int dynamicBankIndex)

{
  undefined *puVar1;
  u_long uVar2;
  u_char *puVar3;
  u_long *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;

  if (dynamicBankIndex < 2)
  {
    uVar2 = aadCreateFourCharID('a', 'S', 'N', 'D');
    puVar1 = &DAT_00001001;
    if ((*(u_long *)soundBank == uVar2) && (puVar1 = &DAT_00001002, *(int *)(soundBank + 8) == 0x106))
    {
      iVar12 = 0;
      iVar5 = *(int *)(soundBank + 0xc);
      iVar9 = *(int *)(soundBank + 0x10);
      iVar10 = *(int *)(soundBank + 0x14);
      iVar6 = *(int *)(soundBank + 0x18);
      iVar11 = *(int *)(soundBank + 0x1c);
      puVar4 = &aadMem->updateCounter + dynamicBankIndex;
      puVar3 = soundBank + *(int *)(soundBank + 4);
      *(u_char **)(puVar4 + 0x136) = puVar3;
      puVar3 = puVar3 + iVar5 * 8;
      *(u_char **)(puVar4 + 0x138) = puVar3;
      piVar8 = (int *)(puVar3 + iVar9 * 0x10 + iVar10 * 4);
      piVar7 = piVar8 + iVar6;
      *(u_char **)(puVar4 + 0x134) = soundBank;
      *(u_char **)(puVar4 + 0x13a) = puVar3 + iVar9 * 0x10;
      *(int **)(puVar4 + 0x13c) = piVar8;
      *(int **)(puVar4 + 0x13e) = piVar7;
      if (0 < *(int *)(soundBank + 0x18))
      {
        do
        {
          *(int *)(puVar4[0x13c] + iVar12 * 4) = (int)piVar7 + *piVar8 + iVar11 * 4;
          iVar12 = iVar12 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar12 < *(int *)(soundBank + 0x18));
      }
      puVar1 = (undefined *)0x0;
    }
  }
  else
  {
    puVar1 = &DAT_00001005;
  }
  return (int)puVar1;
}

int aadLoadDynamicSoundBankReturn2(char *fileName, long directoryID, long flags)

{
  int *piVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;
  u_int uVar4;
  AadDynamicLoadRequest *pAVar5;

  pAVar2 = aadMem;
  iVar3 = 0;
  if (aadMem->numLoadReqsQueued < 0x10)
  {
    pAVar5 = aadMem->loadRequestQueue + aadMem->nextLoadReqIn;
    pAVar5->type = 0;
    uVar4 = pAVar2->nextFileHandle;
    pAVar5->handle = uVar4 & 0x3fff | 0x4000;
    pAVar2->nextFileHandle = uVar4 + 1;
    pAVar5->directoryID = directoryID;
    pAVar5->flags = flags;
    strncmp(pAVar5->fileName, fileName, 0xb);
    pAVar2 = aadMem;
    piVar1 = &aadMem->numLoadReqsQueued;
    aadMem->nextLoadReqIn = aadMem->nextLoadReqIn + 1U & 0xf;
    pAVar2->numLoadReqsQueued = *piVar1 + 1;
    iVar3 = pAVar5->handle;
  }
  return iVar3;
}

int aadFreeDynamicSfx(int handle)

{
  AadDynamicLoadRequest *pAVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;

  pAVar2 = aadMem;
  if (aadMem->numLoadReqsQueued < 0x10)
  {
    iVar3 = aadMem->nextLoadReqIn;
    pAVar1 = aadMem->loadRequestQueue;
    pAVar1[iVar3].type = 1;
    pAVar1[iVar3].handle = handle;
    pAVar2->nextLoadReqIn = pAVar2->nextLoadReqIn + 1U & 0xf;
    pAVar2->numLoadReqsQueued = pAVar2->numLoadReqsQueued + 1;
    return 0;
  }
  return (int)&DAT_0000100f;
}

void aadRelocateMusicMemoryBegin(void)

{
  aadMem->flags = aadMem->flags | 2;
  return;
}

void aadRelocateSfxMemory(void *oldAddress, int offset)

{
  AadMemoryStruct *pAVar1;
  _func_37 *p_Var2;
  int iVar3;
  int iVar4;
  int iVar5;
  AadMemoryStruct *pAVar6;
  _func_36 *p_Var7;
  int iVar8;
  _func_36 *p_Var9;
  int iVar10;
  int iVar11;

  pAVar1 = aadMem;
  iVar11 = 0;
  pAVar6 = aadMem;
  while ((_func_43 *)oldAddress != pAVar6->dynamicSoundBankData[0])
  {
    iVar11 = iVar11 + 1;
    pAVar6 = (AadMemoryStruct *)&pAVar6->numSlots;
    if (1 < iVar11)
      goto LAB_80053050;
  }
  pAVar6->dynamicSoundBankData[0] = (_func_43 *)((int)oldAddress + offset);
  pAVar6->dynamicProgramAtr[0] = pAVar6->dynamicProgramAtr[0] + offset;
  pAVar6->dynamicToneAtr[0] = pAVar6->dynamicToneAtr[0] + offset;
  p_Var2 = pAVar6->dynamicSoundBankHdr[0] + offset;
  pAVar6->dynamicSoundBankHdr[0] = p_Var2;
  pAVar6->dynamicWaveAddr[0] = pAVar6->dynamicWaveAddr[0] + offset;
  pAVar6->dynamicSequenceAddressTbl[0] =
      (_func_41 **)((int)pAVar6->dynamicSequenceAddressTbl[0] + offset);
  iVar4 = 0;
  if (0 < *(int *)(p_Var2 + 0x18))
  {
    do
    {
      pAVar6->dynamicSequenceAddressTbl[0][iVar4] =
          pAVar6->dynamicSequenceAddressTbl[0][iVar4] + offset;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(p_Var2 + 0x18));
  }
  pAVar6->dynamicSequenceLabelOffsetTbl[0] = pAVar6->dynamicSequenceLabelOffsetTbl[0] + offset;
  iVar4 = 0;
  pAVar6 = pAVar1;
  if (0 < pAVar1->numSlots)
  {
    do
    {
      p_Var9 = pAVar6->sequenceSlots[0];
      if ((p_Var9[0x53e] != (_func_36)0xff) && (*(int *)(p_Var9 + 0x55c) == iVar11))
      {
        iVar8 = 0;
        iVar10 = 0;
        p_Var7 = p_Var9;
        do
        {
          if (*(int *)(p_Var7 + 0x348) != 0)
          {
            *(int *)(p_Var7 + 0x348) = *(int *)(p_Var7 + 0x348) + offset;
            iVar5 = 0;
            iVar3 = iVar10;
            if ((p_Var9 + iVar8)[0x4e8] != (_func_36)0x0)
            {
              do
              {
                *(int *)(p_Var9 + iVar3 + 1000) = *(int *)(p_Var9 + iVar3 + 1000) + offset;
                iVar5 = iVar5 + 1;
                iVar3 = iVar3 + 0x40;
              } while (iVar5 < (int)(u_int)(byte)(p_Var9 + iVar8)[0x4e8]);
            }
          }
          iVar10 = iVar10 + 4;
          iVar8 = iVar8 + 1;
          p_Var7 = p_Var7 + 4;
        } while (iVar8 < 0x10);
      }
      iVar4 = iVar4 + 1;
      pAVar6 = (AadMemoryStruct *)&pAVar6->numSlots;
    } while (iVar4 < pAVar1->numSlots);
  }
LAB_80053050:
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}

void aadRelocateMusicMemoryEnd(void *oldAddress, int offset)

{
  _AadDynSfxFileHdr *p_Var1;

  p_Var1 = aadMem->firstDynSfxFile;
  if ((_AadDynSfxFileHdr *)oldAddress == p_Var1)
  {
    p_Var1 = (_AadDynSfxFileHdr *)((int)&p_Var1->snfID + offset);
    aadMem->firstDynSfxFile = p_Var1;
  }
  while (p_Var1 != (_AadDynSfxFileHdr *)0x0)
  {
    if ((_AadDynSfxFileHdr *)oldAddress == p_Var1->prevDynSfxFile)
    {
      p_Var1->prevDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    }
    if ((_AadDynSfxFileHdr *)oldAddress == p_Var1->nextDynSfxFile)
    {
      p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    }
    p_Var1 = p_Var1->nextDynSfxFile;
  }
  return;
}

int aadGetNumLoadsQueued(void)

{
  return aadMem->numLoadReqsQueued;
}

void aadPurgeLoadQueue(void)

{
  AadMemoryStruct *pAVar1;

  pAVar1 = aadMem;
  aadMem->nextLoadReqIn = 0;
  pAVar1->nextLoadReqOut = 0;
  pAVar1->numLoadReqsQueued = 0;
  return;
}

void aadProcessLoadQueue(void)

{
  int *piVar1;
  u_long *puVar2;
  AadMemoryStruct *pAVar3;
  char *fmt;
  long lVar4;
  AadMemoryStruct *pAVar5;
  int id;
  AadDynamicSfxLoadInfo *string;
  _AadDynSfxFileHdr *p_Var6;
  _AadDynSfxFileHdr *p_Var7;
  AadDynamicLoadRequest *pAVar8;
  char acStack32[16];

  pAVar3 = aadMem;
  string = &aadMem->dynamicSfxLoadInfo;
  id = 0;
  pAVar5 = aadMem;
  if (((aadMem->dynamicSfxLoadInfo).flags & 1U) == 0)
  {
    do
    {
      id = id + 1;
      if (pAVar5->dynamicBankStatus[0] == 1)
      {
        return;
      }
      pAVar5 = (AadMemoryStruct *)&pAVar5->numSlots;
    } while (id < 2);
    if ((aadMem->numLoadReqsQueued == 0) || ((aadMem->sramDefragInfo).status != 0))
    {
      if (gSramCheckRequest == 0)
      {
        if (((gDfragRequest != 0) && ((aadMem->sramDefragInfo).status == 0)) &&
            (musicLoadInProgress == 0))
        {
          (aadMem->sramDefragInfo).status = 1;
          gDfragRequest = 0;
        }
      }
      else
      {
        gDfragRequest = aadCheckSramFragmented();
        gSramCheckRequest = 0;
      }
    }
    else
    {
      id = aadMem->nextLoadReqOut;
      piVar1 = &aadMem->numLoadReqsQueued;
      aadMem->nextLoadReqOut = id + 1U & 0xf;
      pAVar8 = pAVar3->loadRequestQueue + id;
      pAVar3->numLoadReqsQueued = *piVar1 + -1;
      if (pAVar8->type == 0)
      {
        strcmp(acStack32, pAVar8->fileName);
        fmt = strpbrk(acStack32, "0123456789");
        if (fmt != (char *)0x0)
        {
          *fmt = '\0';
        }
        if ((pAVar8->flags & 1U) == 0)
        {
          sprintf((char *)string, "\\kain2\\sfx\\object\\%s\\%s.snf");
          fmt = "\\kain2\\sfx\\object\\%s\\%s.smf";
        }
        else
        {
          sprintf((char *)string, "\\kain2\\area\\%s\\bin\\%s.snf");
          fmt = "\\kain2\\area\\%s\\bin\\%s.smf";
        }
        sprintf((pAVar3->dynamicSfxLoadInfo).smfFileName, fmt);
        (pAVar3->dynamicSfxLoadInfo).fileHandle = pAVar8->handle;
        (pAVar3->dynamicSfxLoadInfo).directoryID = pAVar8->directoryID;
        lVar4 = pAVar8->flags;
        id = (pAVar3->dynamicSfxLoadInfo).directoryID;
        gSramFullAlarm = 0;
        (pAVar3->dynamicSfxLoadInfo).flags = 1;
        (pAVar3->dynamicSfxLoadInfo).snfFile = (_AadDynSfxFileHdr *)0x0;
        (pAVar3->dynamicSfxLoadInfo).error = 0;
        (pAVar3->dynamicSfxLoadInfo).totalSramUsed = 0;
        (pAVar3->dynamicSfxLoadInfo).loadFlags = lVar4;
        if (id != 0)
        {
          LOAD_SetSearchDirectory(id);
        }
        (*aadMem->nonBlockLoadProc)(string, aadLoadDynamicSfx, string, 0, &(pAVar3->dynamicSfxLoadInfo).snfFile, 0x2f);
        if ((pAVar3->dynamicSfxLoadInfo).directoryID != 0)
        {
          LOAD_SetSearchDirectory(0);
        }
        gSramCheckRequest = 1;
      }
      else
      {
        if (pAVar8->type == 1)
        {
          p_Var7 = pAVar3->firstDynSfxFile;
          if (p_Var7 != (_AadDynSfxFileHdr *)0x0)
          {
          LAB_80053310:
            if ((u_int)p_Var7->handle != pAVar8->handle)
              goto LAB_800533c8;
            id = 0;
            p_Var6 = p_Var7 + 1;
            if (p_Var7->numSfxInFile != 0)
            {
              do
              {
                puVar2 = &p_Var6->snfID;
                p_Var6 = (_AadDynSfxFileHdr *)((int)&p_Var6->snfID + 2);
                aadFreeSingleDynSfx((u_int) * (u_short *)puVar2);
                id = id + 1;
              } while (id < (int)(u_int)p_Var7->numSfxInFile);
            }
            if (p_Var7->prevDynSfxFile == (_AadDynSfxFileHdr *)0x0)
            {
              aadMem->firstDynSfxFile = p_Var7->nextDynSfxFile;
            }
            else
            {
              p_Var7->prevDynSfxFile->nextDynSfxFile = p_Var7->nextDynSfxFile;
            }
            if (p_Var7->nextDynSfxFile != (_AadDynSfxFileHdr *)0x0)
            {
              p_Var7->nextDynSfxFile->prevDynSfxFile = p_Var7->prevDynSfxFile;
            }
            (*aadMem->memoryFreeProc)(p_Var7);
            gSramFullAlarm = 0;
          }
        LAB_800533d8:
          gSramCheckRequest = 1;
        }
      }
    }
    aadProcessSramDefrag();
  }
  return;
LAB_800533c8:
  p_Var7 = p_Var7->nextDynSfxFile;
  if (p_Var7 == (_AadDynSfxFileHdr *)0x0)
    goto LAB_800533d8;
  goto LAB_80053310;
}

void aadLoadDynamicSfxAbort(AadDynamicSfxLoadInfo *info, int error)

{
  _AadDynSfxFileHdr *p_Var1;

  if (info->snfFile != (_AadDynSfxFileHdr *)0x0)
  {
    if ((info->flags & 2U) != 0)
    {
      p_Var1 = info->snfFile->prevDynSfxFile;
      if (p_Var1 == (_AadDynSfxFileHdr *)0x0)
      {
        aadMem->firstDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
      else
      {
        p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
    }
    (*aadMem->memoryFreeProc)(info->snfFile);
  }
  info->flags = 0;
  return;
}

void aadLoadDynamicSfxDone(AadDynamicSfxLoadInfo *info)

{
  info->flags = 0;
  return;
}

void aadLoadDynamicSfx(void *loadedDataPtr, void *data, void *data2)

{
  AadMemoryStruct *pAVar1;
  u_long uVar2;
  _AadDynSfxFileHdr *p_Var3;
  _AadDynSfxFileHdr *p_Var4;
  u_long *puVar5;

  puVar5 = *(u_long **)((int)data + 0x78);
  if ((puVar5 == (u_long *)0x0) || (puVar5 != (u_long *)loadedDataPtr))
  {
    aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data, (int)&DAT_0000100e);
  }
  else
  {
    uVar2 = aadCreateFourCharID('a', 'S', 'N', 'F');
    pAVar1 = aadMem;
    if ((*puVar5 == uVar2) && (*(short *)(*(int *)((int)data + 0x78) + 4) == 0x100))
    {
      *(undefined2 *)(*(int *)((int)data + 0x78) + 8) = *(undefined2 *)((int)data + 0x50);
      p_Var4 = pAVar1->firstDynSfxFile;
      if (p_Var4 == (_AadDynSfxFileHdr *)0x0)
      {
        pAVar1->firstDynSfxFile = *(_AadDynSfxFileHdr **)((int)data + 0x78);
        *(u_char *)(*(int *)((int)data + 0x78) + 0xc) = 0;
      }
      else
      {
        p_Var3 = p_Var4->nextDynSfxFile;
        while (p_Var3 != (_AadDynSfxFileHdr *)0x0)
        {
          p_Var4 = p_Var4->nextDynSfxFile;
          p_Var3 = p_Var4->nextDynSfxFile;
        }
        p_Var4->nextDynSfxFile = *(_AadDynSfxFileHdr **)((int)data + 0x78);
        *(_AadDynSfxFileHdr **)(*(int *)((int)data + 0x78) + 0xc) = p_Var4;
      }
      *(u_char *)(*(int *)((int)data + 0x78) + 0x10) = 0;
      *(u_char *)((int)data + 0x60) = 0;
      *(u_int *)((int)data + 0x5c) = *(u_int *)((int)data + 0x5c) | 2;
      if (*(int *)((int)data + 0x54) != 0)
      {
        LOAD_SetSearchDirectory(*(int *)((int)data + 0x54));
      }
      (*aadMem->nonBlockBufferedLoadProc)((int)data + 0x28, aadLoadDynamicSfxReturn2, data, 0);
      if (*(int *)((int)data + 0x54) != 0)
      {
        LOAD_SetSearchDirectory(0);
      }
    }
    else
    {
      aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data, (int)&DAT_0000100b);
    }
  }
  return;
}

int aadWaveMalloc(u_short waveID, u_long waveSize)

{
  byte bVar1;
  u_short uVar2;
  u_int uVar3;
  u_short uVar4;
  u_int uVar5;
  AadNewSramBlockDesc *pAVar6;
  int iVar7;
  u_char uVar8;
  u_int uVar9;
  AadNewSramBlockDesc *pAVar10;
  AadNewSramBlockDesc *pAVar11;
  u_int uVar12;

  pAVar10 = (AadNewSramBlockDesc *)0x0;
  uVar12 = 0xff;
  uVar9 = aadMem->firstSramBlockDescIndex;
  pAVar11 = aadMem->sramDescriptorTbl;
  pAVar6 = pAVar11 + uVar9;
  uVar5 = waveSize >> 3;
  if (pAVar6 != (AadNewSramBlockDesc *)0x0)
  {
    iVar7 = 0x7f;
    do
    {
      if (iVar7 == -1)
        break;
      if ((((pAVar6->waveID & 0x4000) == 0) && (uVar5 + 6 <= (u_int)pAVar6->size)) &&
          ((pAVar10 == (AadNewSramBlockDesc *)0x0 ||
            (((u_int)pAVar6->size - 6) - uVar5 < ((u_int)pAVar10->size - 6) - uVar5))))
      {
        pAVar10 = pAVar6;
        uVar12 = uVar9;
      }
      if ((char)pAVar6->nextIndex < '\0')
      {
        pAVar6 = (AadNewSramBlockDesc *)0x0;
      }
      else
      {
        uVar3 = (u_int)pAVar6->nextIndex;
        pAVar6 = (AadNewSramBlockDesc *)0x0;
        if (uVar3 != uVar9)
        {
          pAVar6 = pAVar11 + uVar3;
          uVar9 = uVar3;
        }
      }
      iVar7 = iVar7 + -1;
    } while (pAVar6 != (AadNewSramBlockDesc *)0x0);
  }
  if (pAVar10 == (AadNewSramBlockDesc *)0x0)
  {
    return 0xff;
  }
  pAVar10->waveID = waveID | 0xc000;
  if (uVar5 < pAVar10->size)
  {
    uVar4 = (u_short)uVar5;
    if (-1 < (char)pAVar10->nextIndex)
    {
      pAVar6 = pAVar11 + pAVar10->nextIndex;
      if ((pAVar6->waveID & 0x4000) == 0)
      {
        pAVar6->address = pAVar6->address - (pAVar10->size - uVar4);
        pAVar6->size = pAVar6->size + (pAVar10->size - uVar4);
        pAVar10->size = uVar4;
        return uVar12;
      }
    }
    uVar5 = aadMem->nextSramDescIndex;
    uVar8 = (u_char)uVar5;
    pAVar6 = pAVar11 + uVar5;
    uVar2 = pAVar6->waveID;
    uVar9 = uVar5;
    while ((uVar2 & 0x8000) != 0)
    {
      uVar9 = uVar9 + 1 & 0x7f;
      uVar8 = (u_char)uVar9;
      if (uVar9 == uVar5)
      {
        return 0xff;
      }
      pAVar6 = pAVar11 + uVar9;
      uVar2 = pAVar6->waveID;
    }
    aadMem->nextSramDescIndex = aadMem->nextSramDescIndex + 8U & 0x7f;
    pAVar6->waveID = 0x8000;
    pAVar6->address = pAVar10->address + uVar4;
    uVar2 = pAVar10->size;
    pAVar6->prevIndex = (u_char)uVar12;
    pAVar6->size = uVar2 - uVar4;
    bVar1 = pAVar10->nextIndex;
    pAVar6->nextIndex = bVar1;
    if (-1 < (int)((u_int)bVar1 << 0x18))
    {
      pAVar11[pAVar6->nextIndex].prevIndex = uVar8;
    }
    pAVar10->size = uVar4;
    pAVar10->nextIndex = uVar8;
  }
  return uVar12;
}

u_long aadGetSramBlockAddr(int handle)

{
  if (0x7f < handle)
  {
    return 0;
  }
  return (u_int)aadMem->sramDescriptorTbl[handle].address << 3;
}

void aadWaveFree(int handle)

{
  byte bVar1;
  AadNewSramBlockDesc *pAVar2;
  AadNewSramBlockDesc *pAVar3;
  AadNewSramBlockDesc *pAVar4;

  if (handle < 0x80)
  {
    pAVar4 = aadMem->sramDescriptorTbl;
    pAVar2 = pAVar4 + handle;
    pAVar2->waveID = 0x8000;
    if ((-1 < (char)pAVar2->nextIndex) &&
        (pAVar3 = pAVar4 + pAVar2->nextIndex, (pAVar3->waveID & 0x4000) == 0))
    {
      pAVar2->size = pAVar2->size + pAVar3->size;
      bVar1 = pAVar3->nextIndex;
      pAVar3->waveID = 0;
      pAVar2->nextIndex = bVar1;
      if (-1 < (int)((u_int)bVar1 << 0x18))
      {
        pAVar4[pAVar2->nextIndex].prevIndex = (u_char)handle;
      }
    }
    if ((-1 < (char)pAVar2->prevIndex) &&
        (pAVar3 = pAVar4 + pAVar2->prevIndex, (pAVar3->waveID & 0x4000) == 0))
    {
      pAVar3->size = pAVar3->size + pAVar2->size;
      bVar1 = pAVar2->nextIndex;
      pAVar2->waveID = 0;
      pAVar3->nextIndex = bVar1;
      if (-1 < (int)((u_int)bVar1 << 0x18))
      {
        pAVar4[pAVar2->nextIndex].prevIndex = pAVar2->prevIndex;
      }
    }
  }
  return;
}

void aadFreeSingleDynSfx(int sfxID)

{
  byte bVar1;
  short sVar2;
  AadMemoryStruct *pAVar3;
  u_short uVar4;
  short *psVar5;
  AadLoadedSfxToneAttr *pAVar6;

  sfxID = (int)&aadMem->updateCounter + sfxID;
  bVar1 = *(byte *)(sfxID + 0x808);
  if (bVar1 < 0xfe)
  {
    pAVar6 = aadMem->sfxToneAttrTbl + bVar1;
    uVar4 = pAVar6->referenceCount - 1;
    pAVar6->referenceCount = uVar4;
    if (uVar4 == 0)
    {
      *(undefined *)(sfxID + 0x808) = 0xff;
      pAVar3 = aadMem;
      if (aadMem->sfxWaveMasterList[pAVar6->waveID] < 0xfe)
      {
        psVar5 = (short *)(&DAT_00001608 +
                           (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[pAVar6->waveID]));
        sVar2 = *psVar5;
        *psVar5 = sVar2 + -1;
        if ((short)(sVar2 + -1) == 0)
        {
          pAVar3->sfxWaveMasterList[pAVar6->waveID] = -1;
          aadWaveFree((u_int) * (byte *)((int)psVar5 + 3));
        }
      }
    }
  }
  return;
}

void setSramFullAlarm(void)

{
  u_int uVar1;
  AadNewSramBlockDesc *pAVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u_int uVar6;

  iVar4 = 0;
  iVar5 = 0;
  uVar6 = 0;
  gSramFreeBlocks = 0;
  gSramUsedBlocks = 0;
  pAVar2 = aadMem->sramDescriptorTbl + aadMem->firstSramBlockDescIndex;
  iVar3 = 0x80;
  do
  {
    if (pAVar2 == (AadNewSramBlockDesc *)0x0)
      break;
    if ((pAVar2->waveID & 0x4000) == 0)
    {
      uVar1 = (u_int)pAVar2->size;
      gSramFreeBlocks = gSramFreeBlocks + 1;
      iVar5 = iVar5 + uVar1;
      if (uVar6 < uVar1)
      {
        uVar6 = uVar1;
      }
    }
    else
    {
      gSramUsedBlocks = gSramUsedBlocks + 1;
      iVar4 = iVar4 + (u_int)pAVar2->size;
    }
    if ((char)pAVar2->nextIndex < '\0')
    {
      pAVar2 = (AadNewSramBlockDesc *)0x0;
    }
    else
    {
      pAVar2 = aadMem->sramDescriptorTbl + pAVar2->nextIndex;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  gSramFullAlarm = 1;
  gSramLargestFree = uVar6 << 3;
  gSramTotalUsed = iVar4 << 3;
  gSramTotalFree = iVar5 << 3;
  return;
}

void aadLoadSingleDynSfx(AadDynamicSfxLoadInfo *info)

{
  u_short uVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;
  u_long uVar4;
  u_char uVar5;
  u_int uVar6;
  int iVar7;
  AadLoadedSfxToneAttr *pAVar8;
  int iVar9;
  u_char uVar10;
  u_char uVar11;
  u_char uVar12;
  short *psVar13;
  AadDynSfxAttr *pAVar14;

  pAVar2 = aadMem;
  uVar1 = (info->attr).sfxID;
  info->waveTransferAddr = 0;
  iVar3 = (int)&pAVar2->updateCounter + (u_int)uVar1;
  pAVar14 = &info->attr;
  if (*(char *)(iVar3 + 0x808) == -2)
  {
    *(undefined *)(iVar3 + 0x808) = 0xff;
  }
  pAVar2 = aadMem;
  if (aadMem->sfxToneMasterList[(info->attr).sfxID] == 0xff)
  {
    _uVar5 = aadMem->nextToneIndex;
    uVar5 = (u_char)_uVar5;
    pAVar8 = aadMem->sfxToneAttrTbl + _uVar5;
    uVar1 = pAVar8->referenceCount;
    uVar6 = _uVar5;
    while (uVar1 != 0)
    {
      uVar6 = uVar6 + 1 & 0x7f;
      uVar5 = (u_char)uVar6;
      if (uVar6 == _uVar5)
      {
        info->smfLoadingState = 2;
        iVar3 = (int)&pAVar2->updateCounter + (u_int)pAVar14->sfxID;
        goto LAB_80053e3c;
      }
      pAVar8 = aadMem->sfxToneAttrTbl + uVar6;
      uVar1 = pAVar8->referenceCount;
    }
    aadMem->nextToneIndex = aadMem->nextToneIndex + 8U & 0x7f;
    pAVar8->referenceCount = 1;
    pAVar8->waveID = (info->attr).waveID;
    pAVar2 = aadMem;
    uVar10 = *(u_char *)&(info->attr).toneAttr.centerNote;
    uVar11 = *(u_char *)&(info->attr).toneAttr.mode;
    uVar12 = *(u_char *)&(info->attr).toneAttr.adsr2;
    *(u_char *)&pAVar8->toneAttr = *(u_char *)&(info->attr).toneAttr;
    *(u_char *)&(pAVar8->toneAttr).centerNote = uVar10;
    *(u_char *)&(pAVar8->toneAttr).mode = uVar11;
    *(u_char *)&(pAVar8->toneAttr).adsr2 = uVar12;
    pAVar2->sfxToneMasterList[pAVar14->sfxID] = uVar5;
    pAVar2 = aadMem;
    if (aadMem->sfxWaveMasterList[(info->attr).waveID] == 0xff)
    {
      iVar3 = aadMem->nextWaveIndex;
      do
      {
        psVar13 = (short *)(&DAT_00001608 + (int)(&aadMem->updateCounter + iVar3));
        iVar7 = iVar3 + 1;
        if (*psVar13 == 0)
        {
          iVar9 = aadMem->nextWaveIndex;
          iVar7 = iVar9 + 8;
          aadMem->nextWaveIndex = iVar7;
          if (0x77 < iVar7)
          {
            pAVar2->nextWaveIndex = iVar9 + -0x70;
          }
          *psVar13 = 1;
          aadMem->sfxWaveMasterList[(info->attr).waveID] = (u_char)iVar3;
          iVar3 = aadWaveMalloc((info->attr).waveID, (info->attr).waveSize);
          *(undefined *)((int)psVar13 + 3) = (char)iVar3;
          if (-1 < iVar3 << 0x18)
          {
            uVar4 = aadGetSramBlockAddr((u_int) * (byte *)((int)psVar13 + 3));
            info->waveTransferAddr = uVar4;
            info->smfLoadingState = 3;
            return;
          }
          break;
        }
        if (0x77 < iVar7)
        {
          iVar7 = 0;
        }
        iVar3 = iVar7;
      } while (iVar7 != aadMem->nextWaveIndex);
      aadFreeSingleDynSfx((u_int)pAVar14->sfxID);
      info->smfLoadingState = 2;
      iVar3 = (int)&aadMem->updateCounter + (u_int)pAVar14->sfxID;
    LAB_80053e3c:
      *(undefined *)(iVar3 + 0x808) = 0xfe;
      setSramFullAlarm();
      return;
    }
    *(short *)(&DAT_00001608 +
               (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[(info->attr).waveID])) =
        *(short *)(&DAT_00001608 +
                   (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[(info->attr).waveID])) +
        1;
  }
  else
  {
    aadMem->sfxToneAttrTbl[aadMem->sfxToneMasterList[(info->attr).sfxID]].referenceCount =
        aadMem->sfxToneAttrTbl[aadMem->sfxToneMasterList[(info->attr).sfxID]].referenceCount + 1;
  }
  info->smfLoadingState = 2;
  return;
}

void VSyncCallback(void)

{
  SpuSetTransferStartAddr(0);
  aadLoadDynamicSfxReturn2(smfDataPtr, smfBytesLeft, 0, smfInfo, (void *)0x0);
  return;
}

void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2)

{
  u_long uVar1;
  u_int __n;
  int iVar2;
  void *__src;
  undefined2 in_register_0000001a;
  size_t sVar3;
  int iVar4;

  sVar3 = CONCAT22(in_register_0000001a, status);
  iVar4 = 0;
  if (loadedDataSize != 0)
  {
    do
    {
      iVar2 = *(int *)((int)data1 + 0x60);
      if (iVar2 == 1)
      {
        __src = (void *)((int)loadedDataPtr + iVar4);
        __n = *(u_int *)((int)data1 + 100);
        if ((u_int)loadedDataSize < *(u_int *)((int)data1 + 100))
        {
          __n = loadedDataSize;
        }
        iVar4 = iVar4 + __n;
        sVar3 = __n;
        memcpy((void *)((int)data1 - (*(int *)((int)data1 + 100) + -0x94)), __src, __n);
        loadedDataSize = loadedDataSize - __n;
        iVar2 = *(int *)((int)data1 + 100) - __n;
        *(int *)((int)data1 + 100) = iVar2;
        if (iVar2 == 0)
        {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(u_char *)((int)data1 + 100) = *(u_char *)((int)data1 + 0x90);
        }
      }
      else
      {
        if (iVar2 < 2)
        {
          if (iVar2 == 0)
          {
            sVar3 = 0x4d;
            uVar1 = aadCreateFourCharID('a', 'S', 'M', 'F');
            if (*(u_long *)loadedDataPtr != uVar1)
            {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1, (int)&DAT_0000100b);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 4) != 0x100)
            {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1, (int)&DAT_0000100c);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 6) != *(short *)(*(int *)((int)data1 + 0x78) + 6))
            {
            LAB_80053f98:
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1, (int)&DAT_0000100d);
              return;
            }
            __n = (u_int) * (u_short *)(*(int *)((int)data1 + 0x78) + 10);
            iVar4 = iVar4 + 0x10;
            if ((u_int) * (u_short *)((int)loadedDataPtr + 8) != __n)
              goto LAB_80053f98;
            loadedDataSize = loadedDataSize - 0x10;
            *(u_char *)((int)data1 + 0x60) = 1;
            *(u_char *)((int)data1 + 100) = 0x18;
            *(u_int *)((int)data1 + 0x68) = __n;
          }
        }
        else
        {
          if (iVar2 == 2)
          {
            __n = *(u_int *)((int)data1 + 100);
            if ((u_int)loadedDataSize < *(u_int *)((int)data1 + 100))
            {
              __n = loadedDataSize;
            }
            iVar4 = iVar4 + __n;
            loadedDataSize = loadedDataSize - __n;
            iVar2 = *(int *)((int)data1 + 100) - __n;
            *(int *)((int)data1 + 100) = iVar2;
            if (iVar2 == 0)
            {
              iVar2 = *(int *)((int)data1 + 0x68) + -1;
              *(int *)((int)data1 + 0x68) = iVar2;
              if (iVar2 == 0)
              {
              LAB_800540f4:
                aadLoadDynamicSfxDone((AadDynamicSfxLoadInfo *)data1);
                return;
              }
              *(u_char *)((int)data1 + 0x60) = 1;
              *(u_char *)((int)data1 + 100) = 0x18;
            }
          }
          else
          {
            if (iVar2 == 3)
            {
              __n = *(u_int *)((int)data1 + 100);
              if ((u_int)loadedDataSize < *(u_int *)((int)data1 + 100))
              {
                __n = loadedDataSize;
              }
              loadedDataSize = loadedDataSize - __n;
              aadWaitForSramTransferComplete();
              SpuSetTransferStartAddr((int)VSyncCallback);
              SpuSetTransferCallback(*(u_int *)((int)data1 + 0x70));
              SpuRead((word *)((int)loadedDataPtr + iVar4), __n, sVar3);
              iVar4 = iVar4 + __n;
              iVar2 = *(int *)((int)data1 + 100) - __n;
              *(int *)((int)data1 + 0x70) = *(int *)((int)data1 + 0x70) + __n;
              *(int *)((int)data1 + 100) = iVar2;
              if (iVar2 == 0)
              {
                iVar2 = *(int *)((int)data1 + 0x68) + -1;
                *(int *)((int)data1 + 0x74) =
                    *(int *)((int)data1 + 0x74) + *(int *)((int)data1 + 0x90);
                *(int *)((int)data1 + 0x68) = iVar2;
                if (iVar2 == 0)
                {
                  SpuSetTransferStartAddr(0);
                  goto LAB_800540f4;
                }
                *(u_char *)((int)data1 + 0x60) = 1;
                *(u_char *)((int)data1 + 100) = 0x18;
              }
              if (loadedDataSize != 0)
              {
                smfDataPtr = (u_char *)((int)loadedDataPtr + iVar4);
                smfBytesLeft = loadedDataSize;
                smfInfo = (AadDynamicSfxLoadInfo *)data1;
                return;
              }
              SpuSetTransferStartAddr(0);
            }
          }
        }
      }
    } while (loadedDataSize != 0);
  }
  return;
}

int aadCheckSramFragmented(void)

{
  u_int uVar1;
  undefined *puVar2;
  AadNewSramBlockDesc *pAVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;

  puVar6 = (undefined *)0x0;
  puVar7 = &UNK_000f423f;
  iVar5 = 0;
  pAVar3 = aadMem->sramDescriptorTbl + aadMem->firstSramBlockDescIndex;
  iVar4 = 0x80;
  do
  {
    if (pAVar3 == (AadNewSramBlockDesc *)0x0)
      break;
    if ((pAVar3->waveID & 0x4000) == 0)
    {
      puVar2 = (undefined *)(u_int)pAVar3->size;
      iVar5 = iVar5 + 1;
      puVar6 = puVar2 + (int)puVar6;
      if (puVar2 < puVar7)
      {
        puVar7 = puVar2;
      }
    }
    if ((char)pAVar3->nextIndex < '\0')
    {
      pAVar3 = (AadNewSramBlockDesc *)0x0;
    }
    else
    {
      pAVar3 = aadMem->sramDescriptorTbl + pAVar3->nextIndex;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar1 = 0;
  if (2 < iVar5)
  {
    uVar1 = (u_int)((int)puVar7<(int)puVar6>> 2);
  }
  return uVar1;
}

void aadProcessSramDefrag(void)

{
  byte bVar1;
  byte bVar2;
  u_short uVar3;
  AadMemoryStruct *pAVar4;
  AadMemoryStruct *pAVar5;
  u_char *puVar6;
  int iVar7;
  undefined *puVar8;
  u_long uVar9;
  u_int in_a2;
  undefined *puVar10;
  u_int uVar11;
  AadNewSramBlockDesc *pAVar12;
  AadNewSramBlockDesc *pAVar13;
  AadSramDefragInfo *pAVar14;
  byte bVar15;
  AadNewSramBlockDesc *pAVar16;

  pAVar4 = aadMem;
  iVar7 = (aadMem->sramDefragInfo).status;
  pAVar14 = &aadMem->sramDefragInfo;
  if (iVar7 == 1)
  {
    uVar11 = aadMem->firstSramBlockDescIndex;
    pAVar16 = aadMem->sramDescriptorTbl;
    pAVar12 = pAVar16 + uVar11;
    iVar7 = 0x80;
    if (pAVar12 != (AadNewSramBlockDesc *)0x0)
    {
      do
      {
        bVar15 = (byte)uVar11;
        if ((pAVar12->waveID & 0x4000) == 0)
          break;
        iVar7 = iVar7 + -1;
        bVar15 = pAVar12->nextIndex;
        uVar11 = (u_int)bVar15;
        if ((iVar7 == 0) || (0x7f < bVar15))
        {
          pAVar12 = (AadNewSramBlockDesc *)0x0;
        }
        else
        {
          pAVar12 = pAVar16 + uVar11;
        }
      } while (pAVar12 != (AadNewSramBlockDesc *)0x0);
      if ((pAVar12 != (AadNewSramBlockDesc *)0x0) && (-1 < (char)pAVar12->nextIndex))
      {
        bVar1 = pAVar12->nextIndex;
        pAVar13 = pAVar16 + bVar1;
        if ((pAVar13->waveID & 0x4000) != 0)
        {
          puVar6 = (u_char *)(*aadMem->memoryMallocProc)(0x1000, 0x30);
          (pAVar4->sramDefragInfo).fragBuffer = puVar6;
          pAVar5 = aadMem;
          if (puVar6 != (u_char *)0x0)
          {
            uVar11 = (u_int)pAVar13->waveID & 0x3fff;
            iVar7 = (int)&aadMem->updateCounter + uVar11;
            bVar2 = *(byte *)(iVar7 + 0xa08);
            (pAVar4->sramDefragInfo).masterListEntry = (u_int)bVar2;
            if (bVar2 < 0xfe)
            {
              *(undefined *)(iVar7 + 0xa08) = 0xff;
              (pAVar4->sramDefragInfo).waveID = uVar11;
              (pAVar4->sramDefragInfo).destSramAddr = (u_int)pAVar12->address << 3;
              (pAVar4->sramDefragInfo).srcSramAddr = (u_int)pAVar13->address << 3;
              (pAVar4->sramDefragInfo).moveSize = (u_int)pAVar13->size << 3;
              uVar3 = pAVar12->size;
              pAVar12->size = pAVar13->size;
              pAVar13->size = uVar3;
              uVar3 = pAVar12->waveID;
              pAVar12->waveID = pAVar13->waveID;
              pAVar13->waveID = uVar3;
              pAVar13->address = pAVar12->address + pAVar12->size;
              if ((-1 < (char)pAVar13->nextIndex) &&
                  (pAVar12 = pAVar16 + pAVar13->nextIndex, (pAVar12->waveID & 0x4000) == 0))
              {
                pAVar13->size = pAVar13->size + pAVar12->size;
                bVar2 = pAVar12->nextIndex;
                pAVar12->waveID = 0;
                pAVar13->nextIndex = bVar2;
                if (-1 < (int)((u_int)bVar2 << 0x18))
                {
                  pAVar16[pAVar13->nextIndex].prevIndex = bVar1;
                }
              }
              aadMem->sfxWaveAttrTbl[(pAVar4->sramDefragInfo).masterListEntry].sramHandle = bVar15;
              pAVar14->status = 2;
              return;
            }
            (*pAVar5->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
          }
        }
      }
    }
    pAVar14->status = 0;
  }
  else
  {
    if (1 < iVar7)
    {
      if (iVar7 == 2)
      {
        iVar7 = SpuIsTransferCompleted(0);
        if (iVar7 != 0)
        {
          puVar8 = (undefined *)(pAVar4->sramDefragInfo).moveSize;
          puVar10 = (undefined *)0x1000;
          if (puVar8 < &DAT_00001001)
          {
            puVar10 = puVar8;
          }
          SpuSetTransferCallback((pAVar4->sramDefragInfo).srcSramAddr);
          SpuWrite((u_int)(pAVar4->sramDefragInfo).fragBuffer, (u_int)puVar10, in_a2);
          *(undefined **)&(pAVar4->sramDefragInfo).readSize = puVar10;
          (pAVar4->sramDefragInfo).status = 3;
        }
      }
      else
      {
        if ((iVar7 == 3) && (iVar7 = SpuIsTransferCompleted(0), iVar7 != 0))
        {
          SpuSetTransferCallback((pAVar4->sramDefragInfo).destSramAddr);
          uVar11 = (pAVar4->sramDefragInfo).readSize;
          SpuRead((word *)(pAVar4->sramDefragInfo).fragBuffer, uVar11, in_a2);
          (pAVar4->sramDefragInfo).srcSramAddr = (pAVar4->sramDefragInfo).srcSramAddr + uVar11;
          uVar9 = (pAVar4->sramDefragInfo).moveSize - uVar11;
          (pAVar4->sramDefragInfo).moveSize = uVar9;
          (pAVar4->sramDefragInfo).destSramAddr = (pAVar4->sramDefragInfo).destSramAddr + uVar11;
          if (uVar9 == 0)
          {
            (*aadMem->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
            aadMem->sfxWaveMasterList[(pAVar4->sramDefragInfo).waveID] =
                *(u_char *)&(pAVar4->sramDefragInfo).masterListEntry;
            (pAVar4->sramDefragInfo).status = 0;
            gSramCheckRequest = 1;
          }
          else
          {
            (pAVar4->sramDefragInfo).status = 2;
          }
        }
      }
    }
  }
  return;
}

int aadIsSfxLoaded(u_int toneID)

{
  int iVar1;

  iVar1 = 1;
  if ((0xfd < aadMem->sfxToneMasterList[toneID]) &&
      (iVar1 = -1, aadMem->sfxToneMasterList[toneID] != 0xfe))
  {
    return 0;
  }
  return iVar1;
}

void aadInitSequenceSlot(_AadSequenceSlot *slot)

{
  undefined uVar1;
  int iVar2;
  _AadSequenceSlot *p_Var3;
  int iVar4;
  _func_41 *p_Var5;
  _func_41 *p_Var6;

  iVar4 = 0;
  slot->status = 0;
  slot->selectedDynamicBank = slot->sequenceAssignedDynamicBank;
  slot->slotFlags = slot->slotFlags & 1;
  p_Var6 = aadMem->dynamicSequenceAddressTbl[slot->sequenceAssignedDynamicBank]
                                            [slot->sequenceNumberAssigned];
  p_Var3 = slot;
  p_Var5 = p_Var6;
  do
  {
    if (iVar4 < (int)(u_int) * (u_short *)(p_Var6 + 0xc))
    {
      *(_func_41 **)p_Var3->sequencePosition = p_Var6 + *(int *)(p_Var5 + 0x10);
    }
    else
    {
      p_Var3->sequencePosition[0] = (_func_9 *)0x0;
    }
    p_Var3 = (_AadSequenceSlot *)&(p_Var3->tempo).currentError;
    iVar2 = (int)&(slot->tempo).currentTick + iVar4;
    *(undefined *)(iVar2 + 0x3d8) = 0;
    iVar4 = iVar4 + 1;
    *(undefined *)(iVar2 + 0x4e8) = 0;
    *(undefined *)(iVar2 + 0x338) = 0;
    *(undefined *)(iVar2 + 0x318) = 0;
    *(undefined *)(iVar2 + 0x328) = 0;
    *(byte *)(iVar2 + 0x3d8) = *(byte *)(iVar2 + 0x3d8) | 0x20;
    p_Var5 = p_Var5 + 4;
  } while (iVar4 < 0x10);
  iVar4 = 0;
  p_Var3 = slot;
  do
  {
    iVar2 = (int)&(slot->tempo).currentTick + iVar4;
    uVar1 = *(undefined *)&slot->sequenceAssignedDynamicBank;
    iVar4 = iVar4 + 1;
    *(undefined *)(iVar2 + 0x590) = 0xff;
    *(undefined *)(iVar2 + 0x5a0) = 0x7f;
    *(undefined *)(iVar2 + 0x5b0) = 0x3f;
    *(undefined *)(iVar2 + 0x560) = uVar1;
    p_Var3->pitchWheel[0] = 0x2000;
    p_Var3 = (_AadSequenceSlot *)((int)&(p_Var3->tempo).currentTick + 2);
  } while (iVar4 < 0x10);
  slot->selectedSlotPtr = slot;
  slot->delayedMuteMode = 0;
  slot->delayedMuteCmds = 0;
  slot->delayedUnMuteCmds = 0;
  slot->selectedSlotNum = slot->thisSlotNumber;
  return;
}

int aadWaitForSramTransferComplete(void)

{
  int iVar1;
  int iVar2;

  iVar2 = 100000;
  do
  {
    iVar1 = SpuIsTransferCompleted(0);
    if (iVar1 != 0)
    {
      return 1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

void aadInitReverb(void)

{
  u_int uVar1;
  int iVar2;
  int iVar3;
  u_char uVar4;
  u_int in_a2;

  uVar1 = aadGetReverbMode();
  SpuSetReverbModeType(uVar1);
  uVar4 = 0xffffff;
  SpuSetReverbVoice(0, 0xffffff);
  iVar2 = aadWaitForSramTransferComplete();
  if (iVar2 != 0)
  {
    uVar1 = aadGetReverbMode();
    SpuClearReverbWorkArea(uVar1, uVar4, in_a2);
  }
  iVar2 = aadGetReverbSize();
  iVar3 = aadGetReverbSize();
  aadGetReverbDepth((word)iVar2, (word)iVar3);
  SpuSetReverbModeDepth(1);
  return;
}

void aadShutdown(void)

{
  int iVar1;
  u_int uVar2;
  u_char in_a1;
  u_int in_a2;

  iVar1 = aadWaitForSramTransferComplete();
  if (iVar1 != 0)
  {
    uVar2 = aadGetReverbMode();
    SpuClearReverbWorkArea(uVar2, in_a1, in_a2);
  }
  return;
}

int aadGetReverbMode(void)

{
  return 3;
}

u_long aadGetReverbDepth(void)

{
  int iVar1;

  iVar1 = aadGetReverbMode();
  return (&aadReverbModeSize)[iVar1] + 0x30;
}

int aadGetReverbSize(void)

{
  return (int)&DAT_00002710;
}

int aadGetDynamicBankStatus(int bank)

{
  return aadMem->dynamicBankStatus[bank];
}

int aadGetTempoFromDynamicSequence(int bank)

{
  int iVar1;

  iVar1 = 0;
  if ((&aadMem->updateCounter + bank)[0x140] == 2)
  {
    iVar1 = *(int *)((&aadMem->updateCounter + bank)[0x134] + 0x18);
  }
  return iVar1;
}

int aadGetNumDynamicSequences(int bank, int sequenceNumber, int slotNumber)

{
  undefined *puVar1;
  AadTempo *tempo;
  int iVar2;
  int iVar3;
  _AadSequenceSlot *slot;
  AadTempo AStack32;

  if (aadMem->dynamicBankStatus[bank] == 2)
  {
    slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber];
    slot->sequenceNumberAssigned = (u_char)sequenceNumber;
    slot->sequenceAssignedDynamicBank = bank;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
    if ((slot->tempo).ticksPerUpdate == 0)
    {
      tempo = metaCmdAssignSequence(bank, sequenceNumber, &AStack32);
      aadSetSlotTempo(slotNumber, tempo);
    }
    iVar3 = 0xf;
    iVar2 = (int)&(slot->tempo).errorPerUpdate + 3;
    slot->channelMute = 0;
    slot->enableSustainUpdate = 0;
    slot->ignoreTranspose = 0;
    do
    {
      *(undefined *)(iVar2 + 0x5c0) = 0;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar3);
    puVar1 = (undefined *)0x0;
  }
  else
  {
    puVar1 = &DAT_00001007;
  }
  return (int)puVar1;
}

AadTempo *metaCmdAssignSequence(int bank, int sequenceNumber, AadTempo *tempo)

{
  int iVar1;

  if ((&aadMem->updateCounter + bank)[0x140] == 2)
  {
    iVar1 = *(int *)((&aadMem->updateCounter + bank)[0x13c] + sequenceNumber * 4);
    tempo->quarterNoteTime = *(u_long *)(iVar1 + 4);
    tempo->ppqn = (u_int) * (u_short *)(iVar1 + 8);
  }
  return tempo;
}

void aadSetSlotTempo(int slotNumber, AadTempo *tempo)

{
  AadMemoryStruct *pAVar1;
  u_int uVar2;
  _func_36 *p_Var3;

  pAVar1 = aadMem;
  uVar2 = tempo->ppqn;
  p_Var3 = aadMem->sequenceSlots[slotNumber];
 uVar2) * 0x10000 +
 uVar2;
 *(u_int *)(p_Var3 + 8) = uVar2;
 uVar2);
 *(u_int *)(p_Var3 + 0xc) = (&aadUpdateRate)[pAVar1->updateMode & 3] % *(u_int *)(p_Var3 + 8);
 *(u_long *)(p_Var3 + 0x14) = tempo->quarterNoteTime;
 *(undefined2 *)(p_Var3 + 0x12) = *(undefined2 *)&tempo->ppqn;
 return;
}

void PadStartCom(int slotNumber)

{
  _AadSequenceSlot *slot;

  if (((slotNumber < aadMem->numSlots) &&
       (slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber], (slot->status & 1) == 0)) &&
      (slot->sequenceNumberAssigned != -1))
  {
    aadInitSequenceSlot(slot);
    slot->status = slot->status | 1;
  }
  return;
}

void aadStopSfx(int slotNumber)

{
  _AadSequenceSlot *slot;

  if ((slotNumber < aadMem->numSlots) &&
      (slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber],
       slot->sequenceNumberAssigned != -1))
  {
    slot->status = slot->status & 0xfffe;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
  }
  return;
}

void aadStopAllSfx(void)

{
  int iVar1;
  int slotNumber;

  slotNumber = 0;
  if (0 < aadMem->numSlots)
  {
    iVar1 = 0;
    do
    {
      iVar1 = *(int *)((int)aadMem->sequenceSlots + iVar1);
      if ((*(u_short *)(iVar1 + 0x540) & 1) != 0)
      {
        aadStopSfx(slotNumber);
      }
      *(undefined *)(iVar1 + 0x53e) = 0xff;
      slotNumber = slotNumber + 1;
      iVar1 = slotNumber * 4;
    } while (slotNumber < aadMem->numSlots);
  }
  return;
}

void aadDisableSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots)
  {
    *(byte *)(aadMem->sequenceSlots[slotNumber] + 0x550) =
        (byte)aadMem->sequenceSlots[slotNumber][0x550] | 1;
    aadAllNotesOff(slotNumber);
  }
  return;
}

void aadEnableSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots)
  {
    *(byte *)(aadMem->sequenceSlots[slotNumber] + 0x550) =
        (byte)aadMem->sequenceSlots[slotNumber][0x550] & 0xfe;
  }
  return;
}

void aadPauseSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots)
  {
    *(u_short *)(aadMem->sequenceSlots[slotNumber] + 0x540) =
        *(u_short *)(aadMem->sequenceSlots[slotNumber] + 0x540) & 0xfffe;
    aadAllNotesOff(slotNumber);
  }
  return;
}

void metaCmdResumeSlot(int slotNumber)

{
  _func_36 *p_Var1;
  int iVar2;
  _func_36 *p_Var3;

  if (slotNumber < aadMem->numSlots)
  {
    p_Var3 = aadMem->sequenceSlots[slotNumber];
    iVar2 = 0;
    p_Var1 = p_Var3;
    if (p_Var3[0x53e] != (_func_36)0xff)
    {
      do
      {
        iVar2 = iVar2 + 1;
        *(byte *)(p_Var1 + 0x3d8) = (byte)p_Var1[0x3d8] | 0x20;
        p_Var1 = p_Var3 + iVar2;
      } while (iVar2 < 0x10);
      *(u_short *)(p_Var3 + 0x540) = *(u_short *)(p_Var3 + 0x540) | 1;
    }
  }
  return;
}

int aadGetSlotStatus(int slotNumber)

{
  return (u_int) * (u_short *)(aadMem->sequenceSlots[slotNumber] + 0x540);
}

void aadAllNotesOff(int slotNumber)

{
  AadMemoryStruct *pAVar1;
  u_int *puVar2;
  u_int uVar3;
  int iVar4;
  int iVar5;
  _func_36 *p_Var6;

  uVar3 = 0;
  iVar5 = 0;
  iVar4 = 0x1dc;
  p_Var6 = aadMem->sequenceSlots[slotNumber];
  do
  {
    puVar2 = (u_int *)((int)&aadMem->updateCounter + iVar4);
    if ((_func_36)(*(byte *)(puVar2 + 2) & 0xf0) == p_Var6[0x551])
    {
      *(undefined *)(puVar2 + 2) = 0xff;
      uVar3 = uVar3 | *puVar2;
      *(u_short *)((int)puVar2 + 0x12) = *(u_short *)((int)puVar2 + 0x12) | 2;
    }
    pAVar1 = aadMem;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x1c;
  } while (iVar5 < 0x18);
  if (uVar3 != 0)
  {
    aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar3;
    pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar3;
  }
  return;
}

void aadMuteChannels(_AadSequenceSlot *slot, u_long channelList)

{
  AadMemoryStruct *pAVar1;
  u_int uVar2;
  u_int *puVar3;
  int iVar4;
  int iVar5;
  u_int uVar6;
  u_int uVar7;

  uVar2 = slot->delayedMuteMode & channelList;
  if (uVar2 != 0)
  {
    channelList = channelList & ~uVar2;
    slot->delayedMuteCmds = slot->delayedMuteCmds | (u_short)uVar2;
  }
  uVar7 = 0;
  uVar6 = 0;
  slot->channelMute = slot->channelMute | (u_short)channelList;
  uVar2 = 1;
  do
  {
    if ((channelList & uVar2) != 0)
    {
      iVar5 = 0;
      iVar4 = 0x1dc;
      do
      {
        puVar3 = (u_int *)((int)&aadMem->updateCounter + iVar4);
        if ((u_int) * (byte *)(puVar3 + 2) == (slot->slotID | uVar6))
        {
          *(undefined *)(puVar3 + 2) = 0xff;
          uVar7 = uVar7 | *puVar3;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar5 < 0x18);
    }
    pAVar1 = aadMem;
    uVar6 = uVar6 + 1;
    uVar2 = 1 << (uVar6 & 0x1f);
  } while ((int)uVar6 < 0x10);
  if (uVar7 != 0)
  {
    aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar7;
    pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar7;
  }
  return;
}

void metaCmdUnMuteChannel(_AadSequenceSlot *slot, u_long channelList)

{
  u_short uVar1;
  u_short uVar2;
  u_int uVar3;

  uVar2 = (u_short)channelList;
  uVar3 = slot->delayedMuteMode & channelList;
  uVar1 = (u_short)uVar3;
  if (uVar3 != 0)
  {
    uVar2 = uVar2 & ~uVar1;
    slot->delayedUnMuteCmds = slot->delayedUnMuteCmds | uVar1;
  }
  slot->channelMute = slot->channelMute & ~uVar2;
  return;
}

TDRFuncPtr_aadInstallEndSequenceCallback
aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data)

{
  AadMemoryStruct *pAVar1;
  TDRFuncPtr_aadInstallEndSequenceCallback pTVar2;

  pAVar1 = aadMem;
  pTVar2 = (TDRFuncPtr_aadInstallEndSequenceCallback)aadMem->endSequenceCallback;
  *(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc *)&aadMem->endSequenceCallback =
      callbackProc;
  pAVar1->endSequenceCallbackData = data;
  return pTVar2;
}

void aadSetUserVariable(int variableNumber, int value)

{
  (&DAT_00001c08)[(int)&aadMem->updateCounter + variableNumber] = (char)value;
  return;
}

void aadSetNoUpdateMode(int noUpdate)

{
  if (noUpdate != 0)
  {
    aadMem->flags = aadMem->flags | 2;
    return;
  }
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}

void aadPauseSound(void)

{
  int iVar1;
  word *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;

  if ((aadMem->flags & 8U) == 0)
  {
    aadMem->flags = aadMem->flags | 0xc;
    iVar3 = 0;
    iVar5 = 0x494;
    iVar4 = 0;
    do
    {
      pwVar2 = (word *)((int)&aadMem->updateCounter + iVar5);
      iVar5 = iVar5 + 2;
      iVar1 = (int)&aadMem->updateCounter + iVar4;
      iVar4 = iVar4 + 0x1c;
      *(u_short *)(iVar1 + 0x1ee) = *(u_short *)(iVar1 + 0x1ee) & 0xfffd;
      SpuGetVoicePitch(iVar3, pwVar2);
      SpuSetVoiceStartAddr(iVar3, 0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x18);
  }
  return;
}

void aadCancelPauseSound(void)

{
  aadMem->flags = aadMem->flags & 0xfffffff3;
  return;
}

void aadResumeSound(void)

{
  int iVar1;
  int iVar2;

  if ((aadMem->flags & 8U) != 0)
  {
    aadMem->flags = aadMem->flags & 0xfffffff3;
    iVar1 = 0;
    iVar2 = 0;
    do
    {
      if ((*(u_short *)((int)&aadMem->synthVoice[0].flags + iVar2) & 2) == 0)
      {
        SpuSetVoiceStartAddr(iVar1, aadMem->voicePitchSave[iVar1]);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < 0x18);
  }
  return;
}
