#include "THISDUST.H"
#include "SOUND.H"

SoundEffectChannel *SndOpenSfxChannel(u_char *channelNum)

{
  SoundEffectChannel *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &soundEffectChannelTbl;
  do
  {
    if (pSVar1->inUse == '\0')
    {
      pSVar1->inUse = -1;
      pSVar1->pitchChangeTime = 0;
      pSVar1->volumeChangeTime = 0;
      *channelNum = (u_char)iVar2;
      return pSVar1;
    }
    iVar2 = iVar2 + 1;
    pSVar1 = pSVar1 + 1;
  } while (iVar2 < 0x10);
  return (SoundEffectChannel *)0x0;
}

void SndCloseSfxChannel(int channelNum)

{
  if (channelNum < 0x10)
  {
    (&soundEffectChannelTbl)[channelNum].inUse = '\0';
  }
  return;
}

SoundEffectChannel *SndGetSfxChannel(int channelNum)

{
  if (0xf < channelNum)
  {
    return (SoundEffectChannel *)0x0;
  }
  return &soundEffectChannelTbl + channelNum;
}

void SOUND_StartInstanceSound(u_char *sfxFileData, SoundInstance *soundInstTbl, _Position *position,
                              int livesInOnePlace, int inSpectral, int hidden, long *triggerFlags)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ObjectPeriodicSound *sound;
  int iVar4;

  if ((((gameTrackerX.gameMode != 6) && (sfxFileData != (u_char *)0x0)) &&
       (soundInstTbl != (SoundInstance *)0x0)) &&
      ((*sfxFileData == -0x42 && (sfxFileData[1] == -0x11))))
  {
    bVar1 = sfxFileData[2];
    sound = (ObjectPeriodicSound *)(sfxFileData + 4);
    iVar4 = 0;
    if (bVar1 != 0)
    {
      do
      {
        bVar2 = sound->type;
        if (bVar2 == 1)
        {
          processEventSound(position, soundInstTbl, (ObjectEventSound *)sound);
        LAB_8003f390:
          iVar3 = (u_int)sound->numSfxIDs * 2 + 0xe;
        LAB_8003f3a0:
          sound = (ObjectPeriodicSound *)(&sound->type + iVar3);
        }
        else
        {
          if (bVar2 < 2)
          {
            if (bVar2 == 0)
            {
              processPeriodicSound(position, livesInOnePlace, inSpectral, hidden, soundInstTbl, sound);
              iVar3 = (u_int)sound->numSfxIDs * 2 + 0x12;
              goto LAB_8003f3a0;
            }
          }
          else
          {
            if (bVar2 < 5)
            {
              processOneShotSound(position, hidden, triggerFlags, soundInstTbl,
                                  (ObjectOneShotSound *)sound);
              goto LAB_8003f390;
            }
          }
        }
        soundInstTbl = soundInstTbl + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(u_int)bVar1);
    }
  }
  return;
}

void SOUND_StopInstanceSound(u_char *sfxFileData, SoundInstance *soundInstTbl)

{
  byte bVar1;
  byte bVar2;
  SoundEffectChannel *pSVar3;
  byte *pbVar4;
  int iVar5;

  if ((((sfxFileData != (u_char *)0x0) && (soundInstTbl != (SoundInstance *)0x0)) &&
       (*sfxFileData == -0x42)) &&
      (sfxFileData[1] == -0x11))
  {
    bVar1 = sfxFileData[2];
    pbVar4 = sfxFileData + 4;
    iVar5 = 0;
    if (bVar1 != 0)
    {
      do
      {
        bVar2 = *pbVar4;
        if (bVar2 == 1)
        {
          pbVar4 = pbVar4 + (u_int)pbVar4[1] * 2 + 0xe;
          pSVar3 = SndGetSfxChannel((u_int)soundInstTbl->channel);
          if (pSVar3 != (SoundEffectChannel *)0x0)
          {
            SndEndLoop(pSVar3->handle);
          LAB_8003f50c:
            SndCloseSfxChannel((u_int)soundInstTbl->channel);
            soundInstTbl->channel = -1;
            soundInstTbl->state = '\0';
          }
        }
        else
        {
          if (bVar2 < 2)
          {
            if (bVar2 == 0)
            {
              pbVar4 = pbVar4 + (u_int)pbVar4[1] * 2 + 0x12;
              pSVar3 = SndGetSfxChannel((u_int)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0)
              {
                SndEndLoop(pSVar3->handle);
                goto LAB_8003f50c;
              }
            }
          }
          else
          {
            if (bVar2 < 5)
            {
              pbVar4 = pbVar4 + (u_int)pbVar4[1] * 2 + 0xe;
              pSVar3 = SndGetSfxChannel((u_int)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0)
                goto LAB_8003f50c;
            }
          }
        }
        soundInstTbl = soundInstTbl + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(u_int)bVar1);
    }
  }
  return;
}

int isOkayToPlaySound(int flags, int spectralPlane, int hidden)

{
  int iVar1;
  u_int uVar2;

  if ((flags & 0xfU) == 0)
    goto LAB_8003f5f0;
  iVar1 = GAMELOOP_GetTimeOfDay();
  if (iVar1 == 700)
  {
    uVar2 = 2;
  LAB_8003f5e4:
    uVar2 = flags & uVar2;
  }
  else
  {
    if (700 < iVar1)
    {
      if (iVar1 == 0x708)
      {
        uVar2 = 4;
      }
      else
      {
        if (iVar1 != 0x76c)
        {
          uVar2 = flags & 2;
          goto LAB_8003f5e8;
        }
        uVar2 = 8;
      }
      goto LAB_8003f5e4;
    }
    if (iVar1 == 600)
    {
      uVar2 = 1;
      goto LAB_8003f5e4;
    }
    uVar2 = flags & 2;
  }
LAB_8003f5e8:
  if (uVar2 == 0)
  {
    return 0;
  }
LAB_8003f5f0:
  if (((((flags & 0x10U) == 0) || (iVar1 = 0, spectralPlane != 0)) &&
       (((flags & 0x20U) == 0 || (iVar1 = 0, spectralPlane == 0)))) &&
      ((iVar1 = 1, (flags & 0x40U) != 0 && (iVar1 = 0, hidden == 0))))
  {
    iVar1 = 1;
  }
  return iVar1;
}

void setPeriodicSoundStateOff(SoundInstance *soundInst, ObjectPeriodicSound *sound)

{
  int iVar1;

  SndCloseSfxChannel((u_int)soundInst->channel);
  soundInst->channel = -1;
  soundInst->state = '\x03';
  soundInst->delay = sound->offTime;
  if (sound->offTimeVariation != '\0')
  {
    iVar1 = rand();
    soundInst->delay =
        soundInst->delay +
        (sound->offTimeVariation - (char)(iVar1 % ((u_int)sound->offTimeVariation << 1)));
  }
  return;
}

void processPeriodicSound(_Position *position, int livesInOnePlane, int inSpectral, int hidden,
                          SoundInstance *soundInst, ObjectPeriodicSound *sound)

{
  u_char uVar1;
  SoundEffectChannel *pSVar2;
  u_long uVar3;
  int iVar4;
  byte bVar5;
  int spectralPlane;

  spectralPlane = (int)gameTrackerX.gameData.asmData.MorphType;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 == 1)
  {
  LAB_8003f780:
    if (livesInOnePlane != 0)
    {
      if (inSpectral == 0)
      {
        if (spectralPlane != 0)
        {
          return;
        }
      }
      else
      {
        if (spectralPlane == 0)
        {
          return;
        }
      }
    }
    spectralPlane = isOkayToPlaySound((u_int)sound->flags, spectralPlane, hidden);
    if (spectralPlane == 0)
    {
      return;
    }
    if (soundInst->delay != '\0')
    {
      soundInst->delay = soundInst->delay + -1;
      return;
    }
    pSVar2 = SndOpenSfxChannel((u_char *)soundInst);
    if (pSVar2 == (SoundEffectChannel *)0x0)
    {
      return;
    }
    pSVar2->volume = (u_short)sound->maxVolume;
    if (sound->maxVolVariation != '\0')
    {
      spectralPlane = rand();
      pSVar2->volume =
          pSVar2->volume +
          ((u_short)sound->maxVolVariation -
           (short)(spectralPlane % ((u_int)sound->maxVolVariation << 1)));
    }
    pSVar2->pitch = sound->pitch;
    if (sound->pitchVariation != 0)
    {
      spectralPlane = rand();
      pSVar2->pitch =
          pSVar2->pitch +
          (sound->pitchVariation - (short)(spectralPlane % ((u_int)sound->pitchVariation << 1)));
    }
    if (sound->numSfxIDs < 2)
    {
      spectralPlane = 0;
    }
    else
    {
      spectralPlane = rand();
      spectralPlane = spectralPlane % (u_int)sound->numSfxIDs << 1;
    }
    uVar3 = SOUND_Play3dSound(position, (u_int) * (u_short *)(&sound[1].type + spectralPlane),
                              (int)pSVar2->pitch, (int)pSVar2->volume, (u_int)sound->minVolDistance);
    pSVar2->handle = uVar3;
    if (uVar3 == 0)
    {
      SndCloseSfxChannel((u_int)soundInst->channel);
      soundInst->channel = -1;
      return;
    }
    soundInst->state = '\x02';
    soundInst->delay = sound->onTime;
    if (sound->onTimeVariation == '\0')
    {
      return;
    }
    spectralPlane = rand();
    bVar5 = sound->onTimeVariation;
    goto LAB_8003f918;
  }
  if (1 < bVar5)
  {
    if (bVar5 == 2)
    {
      pSVar2 = SndGetSfxChannel((u_int)soundInst->channel);
      iVar4 = SndIsPlayingOrRequested(pSVar2->handle);
      if (iVar4 == 0)
        goto LAB_8003fb1c;
      iVar4 = SndIsPlaying(pSVar2->handle);
      if (iVar4 == 0)
      {
        return;
      }
      if (livesInOnePlane == 0)
      {
      LAB_8003f9ac:
        spectralPlane = isOkayToPlaySound((u_int)sound->flags, spectralPlane, hidden);
        if (spectralPlane != 0)
        {
          uVar1 = soundInst->delay + -1;
          if (soundInst->delay == '\0')
          {
            if (sound->offTime == '\0')
            {
              if (sound->maxVolVariation != '\0')
              {
                pSVar2->volume = (u_short)sound->maxVolume;
                spectralPlane = rand();
                pSVar2->volume =
                    pSVar2->volume +
                    ((u_short)sound->maxVolVariation -
                     (short)(spectralPlane % ((u_int)sound->maxVolVariation << 1)));
              }
              if (sound->pitchVariation != 0)
              {
                pSVar2->pitch = sound->pitch;
                spectralPlane = rand();
                pSVar2->pitch =
                    pSVar2->pitch +
                    (sound->pitchVariation -
                     (short)(spectralPlane % ((u_int)sound->pitchVariation << 1)));
              }
              soundInst->delay = sound->onTime;
              if (sound->onTimeVariation != '\0')
              {
                spectralPlane = rand();
                uVar1 = soundInst->delay +
                        (sound->onTimeVariation -
                         (char)(spectralPlane % ((u_int)sound->onTimeVariation << 1)));
                goto LAB_8003facc;
              }
            }
            else
            {
              SndEndLoop(pSVar2->handle);
              setPeriodicSoundStateOff(soundInst, sound);
            }
          }
          else
          {
          LAB_8003facc:
            soundInst->delay = uVar1;
          }
          bVar5 = soundInst->state;
          if ((bVar5 & 0x10) == 0)
          {
            soundInst->state = bVar5 | 0x10;
            return;
          }
          soundInst->state = bVar5 & 0xef;
          uVar3 = SOUND_Update3dSound(position, pSVar2->handle, (int)pSVar2->pitch, (int)pSVar2->volume, (u_int)sound->minVolDistance);
          if (uVar3 != 0)
          {
            return;
          }
        }
      }
      else
      {
        if (inSpectral == 0)
        {
          if (spectralPlane == 0)
            goto LAB_8003f9ac;
        }
        else
        {
          if (spectralPlane != 0)
            goto LAB_8003f9ac;
        }
      }
      SndEndLoop(pSVar2->handle);
    LAB_8003fb1c:
      setPeriodicSoundStateOff(soundInst, sound);
      return;
    }
    if (bVar5 == 3)
      goto LAB_8003f780;
  }
  soundInst->channel = -1;
  soundInst->state = '\x01';
  soundInst->delay = sound->initialDelay;
  if (sound->initialDelayVariation == '\0')
  {
    return;
  }
  spectralPlane = rand();
  bVar5 = sound->initialDelayVariation;
LAB_8003f918:
  soundInst->delay = soundInst->delay + (bVar5 - (char)(spectralPlane % ((u_int)bVar5 << 1)));
  return;
}

void processEventSound(_Position *position, SoundInstance *soundInst, ObjectEventSound *sound)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  u_long uVar4;
  byte bVar5;
  int spectralPlane;

  spectralPlane = (int)gameTrackerX.gameData.asmData.MorphType;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 != 1)
  {
    if ((bVar5 < 2) || (bVar5 != 2))
    {
      soundInst->channel = -1;
      soundInst->state = '\x01';
      soundInst->delay = '\0';
    }
    else
    {
      pSVar2 = SndGetSfxChannel((u_int)soundInst->channel);
      if (pSVar2 == (SoundEffectChannel *)0x0)
      {
        spectralPlane = isOkayToPlaySound((u_int)sound->flags, spectralPlane, 0);
        if (spectralPlane == 0)
        {
          return;
        }
        pSVar2 = SndOpenSfxChannel((u_char *)soundInst);
        if (pSVar2 == (SoundEffectChannel *)0x0)
        {
          return;
        }
        pSVar2->volume = (u_short)sound->maxVolume;
        if (sound->maxVolVariation != '\0')
        {
          spectralPlane = rand();
          pSVar2->volume =
              pSVar2->volume +
              ((u_short)sound->maxVolVariation -
               (short)(spectralPlane % ((u_int)sound->maxVolVariation << 1)));
        }
        pSVar2->pitch = sound->pitch;
        if (sound->pitchVariation != 0)
        {
          spectralPlane = rand();
          pSVar2->pitch =
              pSVar2->pitch +
              (sound->pitchVariation - (short)(spectralPlane % ((u_int)sound->pitchVariation << 1)));
        }
        if (sound->numSfxIDs < 2)
        {
          spectralPlane = 0;
        }
        else
        {
          spectralPlane = rand();
          spectralPlane = spectralPlane % (u_int)sound->numSfxIDs << 1;
        }
        uVar4 = SOUND_Play3dSound(position, (u_int) * (u_short *)(&sound[1].type + spectralPlane),
                                  (int)pSVar2->pitch, (int)pSVar2->volume, (u_int)sound->minVolDistance);
        pSVar2->handle = uVar4;
        if (uVar4 != 0)
        {
          return;
        }
      }
      else
      {
        iVar3 = SndIsPlayingOrRequested(pSVar2->handle);
        if (iVar3 == 0)
        {
          SndCloseSfxChannel((u_int)soundInst->channel);
          soundInst->channel = -1;
          soundInst->state = '\x01';
          return;
        }
        iVar3 = SndIsPlaying(pSVar2->handle);
        if (iVar3 == 0)
        {
          return;
        }
        if (pSVar2->pitchChangeTime != 0)
        {
          sVar1 = pSVar2->pitchChangeError + pSVar2->pitchChangeErrPerUpdate;
          pSVar2->pitchChangeError = sVar1;
          pSVar2->pitch = pSVar2->pitch + pSVar2->pitchChangePerUpdate;
          if (pSVar2->pitchChangeTimeSave <= sVar1)
          {
            pSVar2->pitch = pSVar2->pitch + pSVar2->pitchChangeSign;
            pSVar2->pitchChangeError = pSVar2->pitchChangeError - pSVar2->pitchChangeTimeSave;
          }
          pSVar2->pitchChangeTime = pSVar2->pitchChangeTime + -1;
        }
        if (pSVar2->volumeChangeTime != 0)
        {
          sVar1 = pSVar2->volumeChangeError + pSVar2->volumeChangeErrPerUpdate;
          pSVar2->volumeChangeError = sVar1;
          pSVar2->volume = pSVar2->volume + pSVar2->volumeChangePerUpdate;
          if (pSVar2->volumeChangeTimeSave <= sVar1)
          {
            pSVar2->volume = pSVar2->volume + pSVar2->volumeChangeSign;
            pSVar2->volumeChangeError = pSVar2->volumeChangeError - pSVar2->volumeChangeTimeSave;
          }
          pSVar2->volumeChangeTime = pSVar2->volumeChangeTime + -1;
        }
        bVar5 = soundInst->state;
        if ((bVar5 & 0x10) == 0)
        {
          soundInst->state = bVar5 | 0x10;
        }
        else
        {
          soundInst->state = bVar5 & 0xef;
          uVar4 = SOUND_Update3dSound(position, pSVar2->handle, (int)pSVar2->pitch, (int)pSVar2->volume, (u_int)sound->minVolDistance);
          if (uVar4 == 0)
          {
            SndEndLoop(pSVar2->handle);
            SndCloseSfxChannel((u_int)soundInst->channel);
            soundInst->channel = -1;
          }
        }
        spectralPlane = isOkayToPlaySound((u_int)sound->flags, spectralPlane, 0);
        if (spectralPlane != 0)
        {
          return;
        }
        SndEndLoop(pSVar2->handle);
      }
      SndCloseSfxChannel((u_int)soundInst->channel);
      soundInst->channel = -1;
    }
  }
  return;
}

void SOUND_ProcessInstanceSounds(SoundInstance *soundInst)

{
  if ((soundInst->state & 0xf) == 1)
  {
    soundInst->state = '\x02';
  }
  return;
}

void SOUND_SetInstanceSoundPitch(SoundInstance *soundInst)

{
  SoundEffectChannel *pSVar1;

  pSVar1 = SndGetSfxChannel((u_int)soundInst->channel);
  if (pSVar1 != (SoundEffectChannel *)0x0)
  {
    SndEndLoop(pSVar1->handle);
    SndCloseSfxChannel((u_int)soundInst->channel);
    soundInst->channel = -1;
  }
  soundInst->state = '\x01';
  return;
}

int SOUND_IsInstanceSoundLoaded(u_char *sfxFileData, long soundNumber)

{
  byte bVar1;
  u_short uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  u_int uVar6;
  u_short *puVar7;

  if (((sfxFileData != (u_char *)0x0) && (*sfxFileData == -0x42)) && (sfxFileData[1] == -0x11))
  {
    pbVar4 = sfxFileData + 4;
    iVar5 = 0;
    if (sfxFileData[2] != 0)
    {
      do
      {
        bVar1 = *pbVar4;
        if (((bVar1 == 1) || (1 < bVar1)) || (puVar7 = (u_short *)(pbVar4 + 0x12), bVar1 != 0))
        {
          uVar6 = (u_int)pbVar4[1];
          puVar7 = (u_short *)(pbVar4 + 0xe);
          iVar3 = uVar6 * 2 + 0xe;
        }
        else
        {
          uVar6 = (u_int)pbVar4[1];
          iVar3 = uVar6 * 2 + 0x12;
        }
        pbVar4 = pbVar4 + iVar3;
        if (iVar5 == soundNumber)
        {
          while (true)
          {
            uVar6 = uVar6 - 1;
            if (uVar6 == 0xffffffff)
            {
              return 1;
            }
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            iVar5 = aadIsSfxLoaded((u_int)uVar2);
            if (iVar5 == 0)
              break;
            if (iVar5 == -1)
            {
              return -1;
            }
          }
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(u_int)sfxFileData[2]);
    }
  }
  return -1;
}

void SOUND_SetInstanceSoundPitch(SoundInstance *soundInst, long pitchChangeAmt, long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;

  if (((soundInst->state & 0xf) == 2) &&
      (pSVar2 = SndGetSfxChannel((u_int)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0))
  {
    if (time < 0)
    {
      time = -time;
    }
    if (time == 0)
    {
      pSVar2->pitchChangeTime = 0;
      pSVar2->pitch = pSVar2->pitch + (short)pitchChangeAmt;
    }
    else
    {
 time);
 if (pitchChangeAmt < 0)
 {
   sVar1 = -1;
 }
 else
 {
   sVar1 = 1;
 }
 pSVar2->pitchChangeSign = sVar1;
 sVar1 = (short)(pitchChangeAmt % time);
 pSVar2->pitchChangeError = 0;
 pSVar2->pitchChangeTime = (short)time;
 pSVar2->pitchChangeTimeSave = (short)time;
 if (pitchChangeAmt % time < 0)
 {
   sVar1 = -sVar1;
 }
 pSVar2->pitchChangeErrPerUpdate = sVar1;
    }
  }
  return;
}

void SOUND_EndInstanceSounds(SoundInstance *soundInst, long volumeChangeAmt, long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;

  if (((soundInst->state & 0xf) == 2) &&
      (pSVar2 = SndGetSfxChannel((u_int)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0))
  {
    if (time < 0)
    {
      time = -time;
    }
    if ((0 < volumeChangeAmt) && (0x7f < (int)pSVar2->volume + volumeChangeAmt))
    {
      volumeChangeAmt = 0x7f - (int)pSVar2->volume;
    }
    if ((volumeChangeAmt < 0) && ((int)pSVar2->volume + volumeChangeAmt < 0))
    {
      volumeChangeAmt = -(int)pSVar2->volume;
    }
    if (time == 0)
    {
      pSVar2->volumeChangeTime = 0;
      pSVar2->volume = pSVar2->volume + (short)volumeChangeAmt;
    }
    else
    {
 time);
 if (volumeChangeAmt < 0)
 {
   sVar1 = -1;
 }
 else
 {
   sVar1 = 1;
 }
 pSVar2->volumeChangeSign = sVar1;
 sVar1 = (short)(volumeChangeAmt % time);
 pSVar2->volumeChangeError = 0;
 pSVar2->volumeChangeTime = (short)time;
 pSVar2->volumeChangeTimeSave = (short)time;
 if (volumeChangeAmt % time < 0)
 {
   sVar1 = -sVar1;
 }
 pSVar2->volumeChangeErrPerUpdate = sVar1;
    }
  }
  return;
}

void processOneShotSound(_Position *position, int hidden, long *triggerFlags, SoundInstance *soundInst,
                         ObjectOneShotSound *sound)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  u_long uVar3;
  byte bVar4;
  u_int uVar5;

  bVar4 = soundInst->state & 0xf;
  uVar5 = (&objectOneShotTriggerTbl)[(u_int)sound->type - 2];
  if (bVar4 == 1)
  {
    if ((*triggerFlags & uVar5) == 0)
    {
      return;
    }
    iVar2 = isOkayToPlaySound((u_int)sound->flags, (int)gameTrackerX.gameData.asmData.MorphType, hidden);
    if (iVar2 == 0)
    {
    LAB_8004041c:
      *triggerFlags = *triggerFlags & ~uVar5;
      return;
    }
    soundInst->delay = sound->initialDelay;
    if (sound->initialDelayVariation != '\0')
    {
      iVar2 = rand();
      soundInst->delay =
          soundInst->delay +
          (sound->initialDelayVariation - (char)(iVar2 % ((u_int)sound->initialDelayVariation << 1)));
    }
    if (soundInst->delay != '\0')
    {
      soundInst->state = '\x02';
      return;
    }
  LAB_80040370:
    soundInst->state = '\x03';
  }
  else
  {
    if (1 < bVar4)
    {
      if (bVar4 == 2)
      {
        if (soundInst->delay != '\0')
        {
          soundInst->delay = soundInst->delay + -1;
          return;
        }
        goto LAB_80040370;
      }
      if (bVar4 == 3)
      {
        pSVar1 = SndGetSfxChannel((u_int)soundInst->channel);
        if (pSVar1 == (SoundEffectChannel *)0x0)
        {
          pSVar1 = SndOpenSfxChannel((u_char *)soundInst);
          if (pSVar1 == (SoundEffectChannel *)0x0)
          {
            return;
          }
          pSVar1->volume = (u_short)sound->maxVolume;
          if (sound->maxVolVariation != '\0')
          {
            iVar2 = rand();
            pSVar1->volume =
                pSVar1->volume +
                ((u_short)sound->maxVolVariation -
                 (short)(iVar2 % ((u_int)sound->maxVolVariation << 1)));
          }
          pSVar1->pitch = sound->pitch;
          if (sound->pitchVariation != 0)
          {
            iVar2 = rand();
            pSVar1->pitch =
                pSVar1->pitch +
                (sound->pitchVariation - (short)(iVar2 % ((u_int)sound->pitchVariation << 1)));
          }
          if (sound->numSfxIDs < 2)
          {
            iVar2 = 0;
          }
          else
          {
            iVar2 = rand();
            iVar2 = iVar2 % (u_int)sound->numSfxIDs << 1;
          }
          uVar3 = SOUND_Play3dSound(position, (u_int) * (u_short *)(&sound[1].type + iVar2),
                                    (int)pSVar1->pitch, (int)pSVar1->volume,
                                    (u_int)sound->minVolDistance);
          pSVar1->handle = uVar3;
          if (uVar3 != 0)
          {
            return;
          }
          SndCloseSfxChannel((u_int)soundInst->channel);
          soundInst->channel = -1;
          return;
        }
        iVar2 = SndIsPlayingOrRequested(pSVar1->handle);
        if (iVar2 != 0)
        {
          iVar2 = SndIsPlaying(pSVar1->handle);
          if (iVar2 == 0)
          {
            return;
          }
          bVar4 = soundInst->state;
          if ((bVar4 & 0x10) == 0)
          {
            soundInst->state = bVar4 | 0x10;
            return;
          }
          soundInst->state = bVar4 & 0xef;
          uVar3 = SOUND_Update3dSound(position, pSVar1->handle, (int)pSVar1->pitch, (int)pSVar1->volume, (u_int)sound->minVolDistance);
          if (uVar3 != 0)
          {
            return;
          }
          SndEndLoop(pSVar1->handle);
        }
        SndCloseSfxChannel((u_int)soundInst->channel);
        soundInst->channel = -1;
        soundInst->state = '\x01';
        goto LAB_8004041c;
      }
    }
    soundInst->channel = -1;
    soundInst->state = '\x01';
    soundInst->delay = '\0';
  }
  return;
}

u_long SOUND_Play3dSound(_Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  u_long uVar5;
  u_short pan;
  u_int uVar6;
  u_int uVar7;
  u_short vol;

  if (maxVolume == 0)
  {
    return 0;
  }
  if ((theCamera.mode == 5) && ((gameTrackerX.gameFlags & 0x10U) != 0))
  {
    sVar1 = position->z;
    uVar7 = (int)position->x - (int)theCamera.core.position.x;
    uVar6 = (int)position->y - (int)theCamera.core.position.y;
    sVar2 = theCamera.core.position.z;
  }
  else
  {
    uVar7 = (int)position->x - (int)((theCamera.focusInstance)->position).x;
    sVar1 = position->z;
    sVar2 = ((theCamera.focusInstance)->position).z;
    uVar6 = (int)position->y - (int)((theCamera.focusInstance)->position).y;
  }
  lVar3 = MATH3D_FastSqrt0(uVar7 * uVar7 + uVar6 * uVar6 +
                           ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
  if (minVolDist < lVar3)
  {
    return 0;
  }
  iVar4 = ratan2(uVar6, uVar7);
 maxVolume);
 vol = (u_short)_vol;
 uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
 uVar7 = (int)(uVar6 & 0xfff) >> 10;
 if (0x7f < _vol)
 {
   vol = 0x7f;
 }
 iVar4 = (int)(uVar6 & 0x3ff) >> 4;
 if (uVar7 == 1)
   goto LAB_80040718;
 if (uVar7 < 2)
 {
   if (uVar7 != 0)
     goto LAB_80040710;
   _vol = 0x3f;
 }
 else
 {
   if (uVar7 == 2)
   {
     iVar4 = iVar4 + 0x40;
     goto LAB_80040718;
   }
 LAB_80040710:
   _vol = 0x7f;
 }
 iVar4 = _vol - iVar4;
LAB_80040718:
  minVolDist;
  if (iVar4 < 0x40)
  {
    pan = 0x3f - (short)((u_int)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else
  {
    pan = (short)((u_int)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
  uVar5 = SndPlayVolPan(sfxToneID, vol, pan, (short)pitch);
  return uVar5;
}

u_long SOUND_Update3dSound(_Position *position, u_long handle, int pitch, int maxVolume, int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  u_long uVar5;
  u_short pan;
  u_int uVar6;
  u_int uVar7;
  u_short vol;

  if (maxVolume == 0)
  {
    return 0;
  }
  if ((theCamera.mode == 5) && ((gameTrackerX.gameFlags & 0x10U) != 0))
  {
    sVar1 = position->z;
    uVar7 = (int)position->x - (int)theCamera.core.position.x;
    uVar6 = (int)position->y - (int)theCamera.core.position.y;
    sVar2 = theCamera.core.position.z;
  }
  else
  {
    uVar7 = (int)position->x - (int)((theCamera.focusInstance)->position).x;
    sVar1 = position->z;
    sVar2 = ((theCamera.focusInstance)->position).z;
    uVar6 = (int)position->y - (int)((theCamera.focusInstance)->position).y;
  }
  lVar3 = MATH3D_FastSqrt0(uVar7 * uVar7 + uVar6 * uVar6 +
                           ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
  if (minVolDist < lVar3)
  {
    return 0;
  }
  iVar4 = ratan2(uVar6, uVar7);
 maxVolume);
 vol = (u_short)_vol;
 uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
 uVar7 = (int)(uVar6 & 0xfff) >> 10;
 if (0x7f < _vol)
 {
   vol = 0x7f;
 }
 iVar4 = (int)(uVar6 & 0x3ff) >> 4;
 if (uVar7 == 1)
   goto LAB_80040940;
 if (uVar7 < 2)
 {
   if (uVar7 != 0)
     goto LAB_80040938;
   _vol = 0x3f;
 }
 else
 {
   if (uVar7 == 2)
   {
     iVar4 = iVar4 + 0x40;
     goto LAB_80040940;
   }
 LAB_80040938:
   _vol = 0x7f;
 }
 iVar4 = _vol - iVar4;
LAB_80040940:
  minVolDist;
  if (iVar4 < 0x40)
  {
    pan = 0x3f - (short)((u_int)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else
  {
    pan = (short)((u_int)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
  uVar5 = SndUpdateVolPanPitch(handle, vol, pan, (short)pitch);
  return uVar5;
}

void SOUND_HandleGlobalValueSignal(int name, long data)

{
  return;
}

void GAMEPAD_Init(void)

{
  AadInitAttr local_20;

  local_20.numSlots = 4;
  local_20.nonBlockLoadProc = LOAD_IsFileLoading;
  local_20.nonBlockBufferedLoadProc = LOAD_NonBlockingBinaryLoad;
  local_20.memoryMallocProc = MEMPACK_Malloc;
  local_20.updateMode = 1;
  local_20.memoryFreeProc = MEMPACK_Init;
  aadGetMemorySize(&local_20);
  aadInit(&local_20, (u_char *)&soundBuffer);
  gameTrackerX.sound.gMasterVol = 0x3fff;
  SOUND_SetSfxVolume(0x50);
  SOUND_SetInstanceSoundVolume(0x7f);
  SpuSetVoiceVolume(0x4b);
  gameTrackerX.sound.gSfxOn = '\x01';
  gameTrackerX.sound.gMusicOn = '\x01';
  gameTrackerX.sound.gVoiceOn = '\x01';
  gameTrackerX.sound.soundsLoaded = '\0';
  currentDynamicSoundName = '\0';
  aadInitReverb();
  return;
}

void SOUND_Free(void)

{
  gameTrackerX.sound.soundsLoaded = '\0';
  aadShutdownReverb();
  return;
}

void SOUND_SetMusicVariable(int variable, int value)

{
  aadSetUserVariable(variable, value);
  return;
}

void SOUND_SetSfxVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gMusicVol;
  }
  gameTrackerX.sound.gMusicVol = newVolume;
  SOUND_SetMusicVolume(newVolume);
  return;
}

void SOUND_SetInstanceSoundVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gSfxVol;
  }
  gameTrackerX.sound.gSfxVol = newVolume;
  aadSetMasterVolume(newVolume);
  return;
}

void SpuSetVoiceVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gVoiceVol;
  }
  gameTrackerX.sound.gVoiceVol = newVolume;
  return;
}

void SOUND_ResetAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadShutdown();
    aadPauseSound();
  }
  return;
}

void SOUND_PauseAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadInitReverb();
    aadResumeSound();
  }
  return;
}

void SOUND_ResumeAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadStopAllSlots();
    aadStopAllSfx();
    aadShutdown();
    aadCancelPauseSound();
  }
  return;
}

void SOUND_StopAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    SOUND_ResumeAllSound();
    aadInitReverb();
  }
  return;
}

void SOUND_MusicOff(void)

{
  int iVar1;
  int slotNumber;

  slotNumber = 1;
  do
  {
    aadDisableSlot(slotNumber);
    iVar1 = aadGetSlotStatus(slotNumber);
    if (iVar1 == 1)
    {
      aadStopSfx(slotNumber);
      PadStartCom(slotNumber);
    }
    slotNumber = slotNumber + 1;
  } while (slotNumber < 4);
  return;
}

void SOUND_MusicOn(void)

{
  int slotNumber;

  slotNumber = 1;
  do
  {
    aadEnableSlot(slotNumber);
    slotNumber = slotNumber + 1;
  } while (slotNumber < 4);
  return;
}

void SOUND_SfxOff(void)

{
  aadStopAllSlots();
  return;
}

void SOUND_SfxOn(void)

{
  return;
}

int SndIsPlaying(u_long handle)

{
  int iVar1;

  iVar1 = aadIsSfxPlayingOrRequested(handle);
  return iVar1;
}

int SndIsPlayingOrRequested(u_long handle)

{
  int iVar1;

  iVar1 = SndTypeIsPlayingOrRequested(handle);
  return iVar1;
}

int aadIsSfxTypePlayingOrRequested(u_int sfxToneID)

{
  int iVar1;

  iVar1 = aadIsSfxPlaying(sfxToneID);
  return iVar1;
}

u_long SndPlay(u_int sample)

{
  u_long uVar1;

  if (gameTrackerX.sound.gSfxOn == '\0')
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = aadPlaySfx(sample, 0x5a, 0x40, 0);
  }
  return uVar1;
}

void SndEndLoop(u_long handle)

{
  aadStopSfx(handle);
  return;
}

u_long SndPlayVolPan(u_int sample, u_short vol, u_short pan, short pitch)

{
  u_long uVar1;

  if (gameTrackerX.sound.gSfxOn == '\0')
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = aadPlaySfx(sample, (u_int)vol, (u_int)pan, (int)pitch);
  }
  return uVar1;
}

u_long SndUpdateVolPanPitch(u_long handle, u_short vol, u_short pan, short pitch)

{
  u_long uVar1;

  if ((handle == 0) || (gameTrackerX.sound.gSfxOn == '\0'))
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = aadSetSfxVolPanPitch(handle, (u_int)vol, (u_int)pan, (int)pitch);
  }
  return uVar1;
}

void transitionMusicEndCallback(long userData, int slot, int loopFlag)

{
  int iVar1;

  if (slot == 0)
  {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0, 0);
    iVar1 = aadGetNumDynamicSequences(0, 0, 0);
    if (iVar1 == 0)
    {
      PadStartCom(0);
    }
    aadFreeDynamicSoundBank(1);
    musicLoadInProgress = 0;
  }
  return;
}

void loadMainMusicReturn(int dynamicBankIndex, int errorStatus)

{
  if (errorStatus == 0)
  {
    aadInstallEndSequenceCallback(transitionMusicEndCallback, 0);
    aadSetUserVariable(0x7f, 1);
  }
  else
  {
    musicLoadInProgress = 0;
  }
  return;
}

void mainMusicEndCallback(long userData, int slot, int loopFlag)

{
  int iVar1;
  char acStack80[32];
  char acStack48[32];

  if (slot == 0)
  {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0, 0);
    iVar1 = aadGetNumDynamicSequences(1, 0, 0);
    if (iVar1 == 0)
    {
      PadStartCom(0);
      sprintf(acStack80, "\\kain2\\music\\%s\\%s.snd");
      sprintf(acStack48, "\\kain2\\music\\%s\\%s.smp");
      aadLoadDynamicSfxReturn(acStack80, acStack48, 0, 1, loadMainMusicReturn);
    }
    else
    {
      musicLoadInProgress = 0;
    }
  }
  return;
}

void loadTransitionMusicReturn(int dynamicBankIndex, int errorStatus)

{
  if (errorStatus == 0)
  {
    aadInstallEndSequenceCallback(mainMusicEndCallback, (long)&currentDynamicSoundName);
    aadSetUserVariable(0x7f, 1);
  }
  else
  {
    musicLoadInProgress = 0;
  }
  return;
}

void initialLoadMainMusicReturn(int dynamicBankIndex, int errorStatus)

{
  int iVar1;

  iVar1 = aadGetNumDynamicSequences(0, 0, 0);
  if (iVar1 == 0)
  {
    PadStartCom(0);
  }
  musicLoadInProgress = 0;
  return;
}

void musicFadeoutDone(void)

{
  SOUND_FreeDynamicMusic();
  aadStartMasterVolumeFade(gameTrackerX.sound.gMusicVol, 1,
                           (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  return;
}

void SOUND_Update3dSound(void)

{
  bool bVar1;
  int iVar2;
  Level *pLVar3;
  long lVar4;
  char local_58;
  char local_57;
  undefined local_56;
  undefined local_55;
  undefined local_54;
  u_char local_50;
  u_char local_4c;
  u_char local_48;
  u_char local_44;
  u_char local_40;
  u_char local_3c;
  undefined2 local_38;
  char local_36;
  u_char local_30;
  u_char local_2c;
  u_char local_28;
  u_char local_24;
  u_char local_20;
  u_char local_1c;
  undefined2 local_18;
  char local_16;

  aadProcessLoadQueue();
  if (((gameTrackerX.debugFlags & 0x40000U) == 0) &&
      ((gSramFullAlarm != 0 || (gSramFullMsgCnt != 0))))
  {
    bVar1 = gSramFullMsgCnt == 0;
    gSramFullMsgCnt = gSramFullMsgCnt + -1;
    if (bVar1)
    {
      gSramFullMsgCnt = 0x3c;
    }
    FONT_Print("$\n\n\n\n\n\n\n\n\n\nsound memory full!\nu=%d %d f=%d %d lf=%d\n");
  }
  iVar2 = aadGetNumLoadsQueued();
  if ((((iVar2 == 0) && (musicLoadInProgress == 0)) && (gameTrackerX.sound.gMusicOn != '\0')) &&
      (((aadMem->sramDefragInfo).status == 0 &&
        (bVar1 = checkMusicDelay == 0, checkMusicDelay = checkMusicDelay + -1, bVar1))))
  {
    checkMusicDelay = 0x1e;
    pLVar3 = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID);
    if (reqMusicStartPlaneShift == 0)
    {
      if (pLVar3->dynamicMusicName == (char *)0x0)
      {
        if (currentDynamicSoundName != '\0')
        {
          currentDynamicSoundName = '\0';
          aadStartMasterVolumeFade(0, -1, musicFadeoutDone);
        }
      }
      else
      {
        local_58 = *pLVar3->dynamicMusicName;
        local_57 = pLVar3->dynamicMusicName[1];
        if (currentMusicPlane == 0)
        {
          local_56 = 0x6d;
          local_55 = 0x61;
        }
        else
        {
          local_56 = 0x73;
          local_55 = 0x70;
        }
        local_54 = 0;
        iVar2 = strcpy(&local_58, &currentDynamicSoundName);
        if (iVar2 != 0)
        {
          if (currentDynamicSoundName == '\0')
          {
            sprintf((char *)&local_50, "\\kain2\\music\\%s\\%s.snd");
            sprintf((char *)&local_30, "\\kain2\\music\\%s\\%s.smp");
            lVar4 = LOAD_DoesFileExist((char *)&local_50);
            if (lVar4 == 0)
            {
              return;
            }
            aadLoadDynamicSfxReturn((char *)&local_50, (char *)&local_30, 0, 1, initialLoadMainMusicReturn);
            strcmp(&currentDynamicSoundName, &local_58);
          }
          else
          {
            sprintf((char *)&local_50, "\\kain2\\music\\%s\\%s.snd");
            lVar4 = LOAD_DoesFileExist((char *)&local_50);
            if (lVar4 == 0)
            {
              return;
            }
            strcmp(&currentDynamicSoundName, &local_58);
            local_50 = 0x69616b5c;
            local_4c = 0x6d5c326e;
            local_48 = 0x63697375;
            local_44 = 0x7477755c;
            local_40 = 0x77755c72;
            local_3c = 0x732e7274;
            local_38 = 0x646e;
            local_36 = '\0';
            local_30 = 0x69616b5c;
            local_2c = 0x6d5c326e;
            local_28 = 0x63697375;
            local_24 = 0x7477755c;
            local_20 = 0x77755c72;
            local_1c = 0x732e7274;
            local_18 = 0x706d;
            local_16 = '\0';
            aadLoadDynamicSfxReturn((char *)&local_50, (char *)&local_30, 1, 0, loadTransitionMusicReturn);
          }
          musicLoadInProgress = 1;
        }
      }
    }
    else
    {
      reqMusicStartPlaneShift = 0;
      razPlaneShift(reqMusicNewPlane);
    }
  }
  return;
}

void musicPlaneShiftFadeoutDone(void)

{
  SOUND_FreeDynamicMusic();
  aadStartMasterVolumeFade(gameTrackerX.sound.gMusicVol, 1,
                           (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  checkMusicDelay = 0;
  currentMusicPlane = reqMusicNewPlane;
  currentDynamicSoundName = '\0';
  return;
}

void razPlaneShift(int newPlane)

{
  int iVar1;

  iVar1 = newPlane;
  if (gameTrackerX.sound.gMusicOn != '\0')
  {
    iVar1 = aadGetNumLoadsQueued();
    if ((iVar1 == 0) && (musicLoadInProgress == 0))
    {
      iVar1 = newPlane;
      if (currentDynamicSoundName != '\0')
      {
        checkMusicDelay = 300;
        reqMusicNewPlane = newPlane;
        aadStartMasterVolumeFade(0, -3, musicPlaneShiftFadeoutDone);
        iVar1 = currentMusicPlane;
      }
    }
    else
    {
      reqMusicStartPlaneShift = 1;
      iVar1 = currentMusicPlane;
      reqMusicNewPlane = newPlane;
    }
  }
  currentMusicPlane = iVar1;
  return;
}

void SOUND_FreeDynamicMusic(void)

{
  int iVar1;

  aadStopAllSfx();
  currentDynamicSoundName = '\0';
  musicLoadInProgress = 0;
  iVar1 = aadGetDynamicBankStatus(0);
  if (iVar1 != 0)
  {
    aadFreeDynamicSoundBank(0);
  }
  iVar1 = aadGetDynamicBankStatus(1);
  if (iVar1 != 0)
  {
    aadFreeDynamicSoundBank(1);
  }
  return;
}

void SOUND_ResetMusicModifier(long modifier)

{
  int variable;
  int value;

  switch (modifier)
  {
  case 0:
    variable = 0;
    value = 0;
    goto LAB_80041544;
  case 1:
    variable = 0;
    break;
  case 2:
    variable = 0;
    value = 3;
    goto LAB_80041544;
  case 3:
    variable = 0;
    value = 4;
    goto LAB_80041544;
  case 4:
    variable = 0;
    value = 2;
    goto LAB_80041544;
  case 5:
    variable = 1;
    break;
  case 6:
    variable = 2;
    break;
  default:
    goto switchD_800414c4_caseD_7;
  case 9:
    variable = 0x7d;
    break;
  case 10:
    variable = 0x7e;
    break;
  case 0xb:
    variable = 0x7c;
    break;
  case 0xd:
    variable = 0x78;
    break;
  case 0xe:
    variable = 3;
    break;
  case 0xf:
    variable = 0x77;
  }
  value = 1;
LAB_80041544:
  SOUND_SetMusicVariable(variable, value);
switchD_800414c4_caseD_7:
  return;
}

void SOUND_SetMusicModifier(long modifier)

{
  int variable;

  switch (modifier)
  {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    variable = 0;
    break;
  case 5:
    variable = 1;
    break;
  case 6:
    variable = 2;
    break;
  default:
    goto switchD_80041584_caseD_7;
  case 9:
    variable = 0x7d;
    break;
  case 10:
    variable = 0x7e;
    break;
  case 0xb:
    variable = 0x7c;
    break;
  case 0xd:
    variable = 0x78;
    break;
  case 0xe:
    variable = 3;
    break;
  case 0xf:
    variable = 0x77;
  }
  SOUND_SetMusicVariable(variable, 0);
switchD_80041584_caseD_7:
  return;
}
