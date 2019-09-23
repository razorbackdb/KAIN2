#include "THISDUST.H"
#include "SOUND.H"

// int @0x800CEA8C, len = 0x00000004
gSramFullMsgCnt = 0x0;
// MusicLoadInfo @0x800D1510, len = 0x0000004C
musicInfo =
    {
        // int @0x800D1510, len = 0x00000004
        .state = null,
        // int @0x800D1514, len = 0x00000004
        .nextState = null,
        // int @0x800D1518, len = 0x00000004
        .errorStatus = null,
        // int @0x800D151C, len = 0x00000004
        .bankLoaded = null,
        // int @0x800D1520, len = 0x00000004
        .checkMusicDelay = null,
        // int @0x800D1524, len = 0x00000004
        .currentMusicPlane = null,
        // char[8] @0x800D1528, len = 0x00000008
        .currentMusicName =
            {
                '\x00',
                '\x00',
                '\x00',
                '\x00',
                '\x00',
                '\x00',
                '\x00',
                '\x00'},
        // MusicLoadCmd[4] @0x800D1530, len = 0x00000020
        .commandQueue =
            {
                // MusicLoadCmd @0x800D1530, len = 0x00000008
                {
                    // int @0x800D1530, len = 0x00000004
                    .type = null,
                    // int @0x800D1534, len = 0x00000004
                    .data = null},
                // MusicLoadCmd @0x800D1538, len = 0x00000008
                {
                    // int @0x800D1538, len = 0x00000004
                    .type = null,
                    // int @0x800D153C, len = 0x00000004
                    .data = null},
                // MusicLoadCmd @0x800D1540, len = 0x00000008
                {
                    // int @0x800D1540, len = 0x00000004
                    .type = null,
                    // int @0x800D1544, len = 0x00000004
                    .data = null},
                // MusicLoadCmd @0x800D1548, len = 0x00000008
                {
                    // int @0x800D1548, len = 0x00000004
                    .type = null,
                    // int @0x800D154C, len = 0x00000004
                    .data = null}},
        // int @0x800D1550, len = 0x00000004
        .commandIn = null,
        // int @0x800D1554, len = 0x00000004
        .commandOut = null,
        // int @0x800D1558, len = 0x00000004
        .numCmdsInQueue = null};
// long @0x800CEA90, len = 0x00000004
objectOneShotTriggerTbl = 0x1000;
// char @0x800D5C08, len = 0x00000001
soundBuffer = 0x00;
// SoundEffectChannel @0x800D12C0, len = 0x00000024
soundEffectChannelTbl =
    {
        // uchar @0x800D12C0, len = 0x00000001
        .inUse = 0x00,
        // uchar @0x800D12C1, len = 0x00000001
        .unused = 0x00,
        // ushort @0x800D12C2, len = 0x00000002
        .unused1 = null,
        // ulong @0x800D12C4, len = 0x00000004
        .handle = null,
        // short @0x800D12C8, len = 0x00000002
        .volume = null,
        // short @0x800D12CA, len = 0x00000002
        .volumeChangeTime = null,
        // short @0x800D12CC, len = 0x00000002
        .volumeChangeTimeSave = null,
        // short @0x800D12CE, len = 0x00000002
        .volumeChangePerUpdate = null,
        // short @0x800D12D0, len = 0x00000002
        .volumeChangeSign = null,
        // short @0x800D12D2, len = 0x00000002
        .volumeChangeErrPerUpdate = null,
        // short @0x800D12D4, len = 0x00000002
        .volumeChangeError = null,
        // short @0x800D12D6, len = 0x00000002
        .pitch = null,
        // short @0x800D12D8, len = 0x00000002
        .pitchChangeTime = null,
        // short @0x800D12DA, len = 0x00000002
        .pitchChangeTimeSave = null,
        // short @0x800D12DC, len = 0x00000002
        .pitchChangePerUpdate = null,
        // short @0x800D12DE, len = 0x00000002
        .pitchChangeSign = null,
        // short @0x800D12E0, len = 0x00000002
        .pitchChangeErrPerUpdate = null,
        // short @0x800D12E2, len = 0x00000002
        .pitchChangeError = null};
// decompiled code
// original method signature:
// struct SoundEffectChannel * /*$ra*/ SndOpenSfxChannel(unsigned char *channelNum /*$a0*/)
// line 40, offset 0x8003e64c
/* begin block 1 */
// Start line: 42
// Start offset: 0x8003E64C
// Variables:
// 		int i; // $a1
/* end block 1 */
// End offset: 0x8003E68C
// End Line: 56

/* begin block 2 */
// Start line: 80
/* end block 2 */
// End Line: 81

/* begin block 3 */
// Start line: 81
/* end block 3 */
// End Line: 82

/* begin block 4 */
// Start line: 83
/* end block 4 */
// End Line: 84

SoundEffectChannel *SndOpenSfxChannel(uchar *channelNum)

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
      *channelNum = (uchar)iVar2;
      return pSVar1;
    }
    iVar2 = iVar2 + 1;
    pSVar1 = pSVar1 + 1;
  } while (iVar2 < 0x10);
  return (SoundEffectChannel *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ SndCloseSfxChannel(int channelNum /*$a0*/)
// line 59, offset 0x8003e694
/* begin block 1 */
// Start line: 126
/* end block 1 */
// End Line: 127

/* begin block 2 */
// Start line: 127
/* end block 2 */
// End Line: 128

void SndCloseSfxChannel(int channelNum)

{
  if (channelNum < 0x10)
  {
    (&soundEffectChannelTbl)[channelNum].inUse = '\0';
  }
  return;
}

// decompiled code
// original method signature:
// struct SoundEffectChannel * /*$ra*/ SndGetSfxChannel(int channelNum /*$a0*/)
// line 66, offset 0x8003e6bc
/* begin block 1 */
// Start line: 140
/* end block 1 */
// End Line: 141

/* begin block 2 */
// Start line: 141
/* end block 2 */
// End Line: 142

SoundEffectChannel *SndGetSfxChannel(int channelNum)

{
  if (0xf < channelNum)
  {
    return (SoundEffectChannel *)0x0;
  }
  return &soundEffectChannelTbl + channelNum;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ProcessInstanceSounds(unsigned char *sfxFileData /*$s0*/, struct SoundInstance *soundInstTbl /*$a1*/, struct _Position *position /*$s4*/, int livesInOnePlace /*stack 12*/, int inSpectral /*stack 16*/, int hidden /*stack 20*/, int burning /*stack 24*/, long *triggerFlags /*stack 28*/)
// line 97, offset 0x8003e6e4
/* begin block 1 */
// Start line: 98
// Start offset: 0x8003E6E4
// Variables:
// 		int numSounds; // $s3
// 		int numSfxIDs; // $v0
// 		int i; // $s2
/* end block 1 */
// End offset: 0x8003E83C
// End Line: 141

/* begin block 2 */
// Start line: 177
/* end block 2 */
// End Line: 178

/* begin block 3 */
// Start line: 204
/* end block 3 */
// End Line: 205

void SOUND_ProcessInstanceSounds(uchar *sfxFileData, SoundInstance *soundInstTbl, _Position *position,
                                 int livesInOnePlace, int inSpectral, int hidden, int burning, long *triggerFlags)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ObjectPeriodicSound *sound;
  int iVar4;

  if ((((gameTrackerX.gameMode != 6) && (sfxFileData != (uchar *)0x0)) &&
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
        LAB_8003e814:
          iVar3 = (uint)sound->numSfxIDs * 2 + 0xe;
        LAB_8003e824:
          sound = (ObjectPeriodicSound *)(&sound->type + iVar3);
        }
        else
        {
          if (bVar2 < 2)
          {
            if (bVar2 == 0)
            {
              processPeriodicSound(position, livesInOnePlace, inSpectral, hidden, burning, soundInstTbl, sound);
              iVar3 = (uint)sound->numSfxIDs * 2 + 0x12;
              goto LAB_8003e824;
            }
          }
          else
          {
            if (bVar2 < 5)
            {
              processOneShotSound(position, hidden, burning, triggerFlags, soundInstTbl,
                                  (ObjectOneShotSound *)sound);
              goto LAB_8003e814;
            }
          }
        }
        soundInstTbl = soundInstTbl + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)bVar1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_EndInstanceSounds(unsigned char *sfxFileData /*$s0*/, struct SoundInstance *soundInstTbl /*$a1*/)
// line 149, offset 0x8003e86c
/* begin block 1 */
// Start line: 150
// Start offset: 0x8003E86C
// Variables:
// 		int numSounds; // $s3
// 		int numSfxIDs; // $v0
// 		int i; // $s2
// 		struct SoundEffectChannel *channel; // $v0
/* end block 1 */
// End offset: 0x8003E9B8
// End Line: 211

/* begin block 2 */
// Start line: 336
/* end block 2 */
// End Line: 337

void SOUND_EndInstanceSounds(uchar *sfxFileData, SoundInstance *soundInstTbl)

{
  byte bVar1;
  byte bVar2;
  SoundEffectChannel *pSVar3;
  byte *pbVar4;
  int iVar5;

  if ((((sfxFileData != (uchar *)0x0) && (soundInstTbl != (SoundInstance *)0x0)) &&
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
          pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0xe;
          pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
          if (pSVar3 != (SoundEffectChannel *)0x0)
          {
            SndEndLoop(pSVar3->handle);
          LAB_8003e990:
            SndCloseSfxChannel((uint)soundInstTbl->channel);
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
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0x12;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0)
              {
                SndEndLoop(pSVar3->handle);
                goto LAB_8003e990;
              }
            }
          }
          else
          {
            if (bVar2 < 5)
            {
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0xe;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0)
                goto LAB_8003e990;
            }
          }
        }
        soundInstTbl = soundInstTbl + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)bVar1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ isOkayToPlaySound(int flags /*$s0*/, int spectralPlane /*$s1*/, int hidden /*$s2*/, int burning /*$s3*/)
// line 218, offset 0x8003e9d8
/* begin block 1 */
// Start line: 219
// Start offset: 0x8003E9D8

/* begin block 1.1 */
// Start line: 224
// Start offset: 0x8003EA08
// Variables:
// 		int mask; // $v0
// 		int tod; // $v1
/* end block 1.1 */
// End offset: 0x8003EA7C
// End Line: 245
/* end block 1 */
// End offset: 0x8003EAD0
// End Line: 259

/* begin block 2 */
// Start line: 515
/* end block 2 */
// End Line: 516

int isOkayToPlaySound(int flags, int spectralPlane, int hidden, int burning)

{
  int iVar1;
  uint uVar2;

  if ((flags & 0xfU) == 0)
    goto LAB_8003ea7c;
  iVar1 = GAMELOOP_GetTimeOfDay();
  if (iVar1 == 700)
  {
    uVar2 = 2;
  LAB_8003ea70:
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
          goto LAB_8003ea74;
        }
        uVar2 = 8;
      }
      goto LAB_8003ea70;
    }
    if (iVar1 == 600)
    {
      uVar2 = 1;
      goto LAB_8003ea70;
    }
    uVar2 = flags & 2;
  }
LAB_8003ea74:
  if (uVar2 == 0)
  {
    return 0;
  }
LAB_8003ea7c:
  if ((((((flags & 0x10U) == 0) || (iVar1 = 0, spectralPlane != 0)) &&
        (((flags & 0x20U) == 0 || (iVar1 = 0, spectralPlane == 0)))) &&
       ((((flags & 0x40U) == 0 || (iVar1 = 0, hidden == 0)) && (iVar1 = 1, (flags & 0x80U) != 0)))) &&
      (iVar1 = 0, burning != 0))
  {
    iVar1 = 1;
  }
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ setPeriodicSoundStateOff(struct SoundInstance *soundInst /*$s0*/, struct ObjectPeriodicSound *sound /*$s1*/)
// line 266, offset 0x8003eaec
/* begin block 1 */
// Start line: 611
/* end block 1 */
// End Line: 612

void setPeriodicSoundStateOff(SoundInstance *soundInst, ObjectPeriodicSound *sound)

{
  int iVar1;

  SndCloseSfxChannel((uint)soundInst->channel);
  soundInst->channel = -1;
  soundInst->state = '\x03';
  soundInst->delay = sound->offTime;
  if (sound->offTimeVariation != '\0')
  {
    iVar1 = rand();
    soundInst->delay =
        soundInst->delay +
        (sound->offTimeVariation - (char)(iVar1 % ((uint)sound->offTimeVariation << 1)));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ processPeriodicSound(struct _Position *position /*$fp*/, int livesInOnePlane /*$s4*/, int inSpectral /*$s5*/, int hidden /*$s7*/, int burning /*stack 16*/, struct SoundInstance *soundInst /*stack 20*/, struct ObjectPeriodicSound *sound /*stack 24*/)
// line 280, offset 0x8003eb78
/* begin block 1 */
// Start line: 281
// Start offset: 0x8003EB78
// Variables:
// 		struct SoundEffectChannel *channel; // $s0
// 		int sfxIDNum; // $v1
// 		int sfxToneID; // $a1
// 		int spectralPlane; // $s2
/* end block 1 */
// End offset: 0x8003EFE8
// End Line: 443

/* begin block 2 */
// Start line: 639
/* end block 2 */
// End Line: 640

void processPeriodicSound(_Position *position, int livesInOnePlane, int inSpectral, int hidden, int burning,
                          SoundInstance *soundInst, ObjectPeriodicSound *sound)

{
  uchar uVar1;
  SoundEffectChannel *pSVar2;
  ulong uVar3;
  int iVar4;
  byte bVar5;
  int spectralPlane;

  spectralPlane = (int)gameTrackerX.gameData.asmData.MorphType;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 == 1)
  {
  LAB_8003ec2c:
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
    spectralPlane = isOkayToPlaySound((uint)sound->flags, spectralPlane, hidden, burning);
    if (spectralPlane == 0)
    {
      return;
    }
    if (soundInst->delay != '\0')
    {
      soundInst->delay = soundInst->delay + -1;
      return;
    }
    pSVar2 = SndOpenSfxChannel((uchar *)soundInst);
    if (pSVar2 == (SoundEffectChannel *)0x0)
    {
      return;
    }
    pSVar2->volume = (ushort)sound->maxVolume;
    if (sound->maxVolVariation != '\0')
    {
      spectralPlane = rand();
      pSVar2->volume =
          pSVar2->volume +
          ((ushort)sound->maxVolVariation -
           (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
    }
    pSVar2->pitch = sound->pitch;
    if (sound->pitchVariation != 0)
    {
      spectralPlane = rand();
      pSVar2->pitch =
          pSVar2->pitch +
          (sound->pitchVariation - (short)(spectralPlane % ((uint)sound->pitchVariation << 1)));
    }
    if (sound->numSfxIDs < 2)
    {
      spectralPlane = 0;
    }
    else
    {
      spectralPlane = rand();
      spectralPlane = spectralPlane % (uint)sound->numSfxIDs << 1;
    }
    uVar3 = SOUND_Play3dSound(position, (uint) * (ushort *)(&sound[1].type + spectralPlane),
                              (int)pSVar2->pitch, (int)pSVar2->volume, (uint)sound->minVolDistance);
    pSVar2->handle = uVar3;
    if (uVar3 == 0)
    {
      SndCloseSfxChannel((uint)soundInst->channel);
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
    goto LAB_8003edc8;
  }
  if (1 < bVar5)
  {
    if (bVar5 == 2)
    {
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      iVar4 = SndIsPlayingOrRequested(pSVar2->handle);
      if (iVar4 == 0)
        goto LAB_8003efd0;
      iVar4 = SndIsPlaying(pSVar2->handle);
      if (iVar4 == 0)
      {
        return;
      }
      if (livesInOnePlane == 0)
      {
      LAB_8003ee5c:
        spectralPlane = isOkayToPlaySound((uint)sound->flags, spectralPlane, hidden, burning);
        if (spectralPlane != 0)
        {
          uVar1 = soundInst->delay + -1;
          if (soundInst->delay == '\0')
          {
            if (sound->offTime == '\0')
            {
              if (sound->maxVolVariation != '\0')
              {
                pSVar2->volume = (ushort)sound->maxVolume;
                spectralPlane = rand();
                pSVar2->volume =
                    pSVar2->volume +
                    ((ushort)sound->maxVolVariation -
                     (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
              }
              if (sound->pitchVariation != 0)
              {
                pSVar2->pitch = sound->pitch;
                spectralPlane = rand();
                pSVar2->pitch =
                    pSVar2->pitch +
                    (sound->pitchVariation -
                     (short)(spectralPlane % ((uint)sound->pitchVariation << 1)));
              }
              soundInst->delay = sound->onTime;
              if (sound->onTimeVariation != '\0')
              {
                spectralPlane = rand();
                uVar1 = soundInst->delay +
                        (sound->onTimeVariation -
                         (char)(spectralPlane % ((uint)sound->onTimeVariation << 1)));
                goto LAB_8003ef80;
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
          LAB_8003ef80:
            soundInst->delay = uVar1;
          }
          bVar5 = soundInst->state;
          if ((bVar5 & 0x10) == 0)
          {
            soundInst->state = bVar5 | 0x10;
            return;
          }
          soundInst->state = bVar5 & 0xef;
          uVar3 = SOUND_Update3dSound(position, pSVar2->handle, (int)pSVar2->pitch, (int)pSVar2->volume, (uint)sound->minVolDistance);
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
            goto LAB_8003ee5c;
        }
        else
        {
          if (spectralPlane != 0)
            goto LAB_8003ee5c;
        }
      }
      SndEndLoop(pSVar2->handle);
    LAB_8003efd0:
      setPeriodicSoundStateOff(soundInst, sound);
      return;
    }
    if (bVar5 == 3)
      goto LAB_8003ec2c;
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
LAB_8003edc8:
  soundInst->delay = soundInst->delay + (bVar5 - (char)(spectralPlane % ((uint)bVar5 << 1)));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ processEventSound(struct _Position *position /*$s5*/, struct SoundInstance *soundInst /*$s1*/, struct ObjectEventSound *sound /*$s3*/)
// line 449, offset 0x8003f018
/* begin block 1 */
// Start line: 450
// Start offset: 0x8003F018
// Variables:
// 		struct SoundEffectChannel *channel; // $s0
// 		int sfxIDNum; // $v1
// 		int sfxToneID; // $a1
// 		int spectralPlane; // $s4
/* end block 1 */
// End offset: 0x8003F398
// End Line: 564

/* begin block 2 */
// Start line: 986
/* end block 2 */
// End Line: 987

void processEventSound(_Position *position, SoundInstance *soundInst, ObjectEventSound *sound)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  ulong uVar4;
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
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      if (pSVar2 == (SoundEffectChannel *)0x0)
      {
        spectralPlane = isOkayToPlaySound((uint)sound->flags, spectralPlane, 0, 0);
        if (spectralPlane == 0)
        {
          return;
        }
        pSVar2 = SndOpenSfxChannel((uchar *)soundInst);
        if (pSVar2 == (SoundEffectChannel *)0x0)
        {
          return;
        }
        pSVar2->volume = (ushort)sound->maxVolume;
        if (sound->maxVolVariation != '\0')
        {
          spectralPlane = rand();
          pSVar2->volume =
              pSVar2->volume +
              ((ushort)sound->maxVolVariation -
               (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
        }
        pSVar2->pitch = sound->pitch;
        if (sound->pitchVariation != 0)
        {
          spectralPlane = rand();
          pSVar2->pitch =
              pSVar2->pitch +
              (sound->pitchVariation - (short)(spectralPlane % ((uint)sound->pitchVariation << 1)));
        }
        if (sound->numSfxIDs < 2)
        {
          spectralPlane = 0;
        }
        else
        {
          spectralPlane = rand();
          spectralPlane = spectralPlane % (uint)sound->numSfxIDs << 1;
        }
        uVar4 = SOUND_Play3dSound(position, (uint) * (ushort *)(&sound[1].type + spectralPlane),
                                  (int)pSVar2->pitch, (int)pSVar2->volume, (uint)sound->minVolDistance);
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
          SndCloseSfxChannel((uint)soundInst->channel);
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
          uVar4 = SOUND_Update3dSound(position, pSVar2->handle, (int)pSVar2->pitch, (int)pSVar2->volume, (uint)sound->minVolDistance);
          if (uVar4 == 0)
          {
            SndEndLoop(pSVar2->handle);
            SndCloseSfxChannel((uint)soundInst->channel);
            soundInst->channel = -1;
          }
        }
        spectralPlane = isOkayToPlaySound((uint)sound->flags, spectralPlane, 0, 0);
        if (spectralPlane != 0)
        {
          return;
        }
        SndEndLoop(pSVar2->handle);
      }
      SndCloseSfxChannel((uint)soundInst->channel);
      soundInst->channel = -1;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_StartInstanceSound(struct SoundInstance *soundInst /*$a0*/)
// line 566, offset 0x8003f3bc
/* begin block 1 */
// Start line: 1241
/* end block 1 */
// End Line: 1242

/* begin block 2 */
// Start line: 1242
/* end block 2 */
// End Line: 1243

void SOUND_StartInstanceSound(SoundInstance *soundInst)

{
  if ((soundInst->state & 0xf) == 1)
  {
    soundInst->state = '\x02';
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_StopInstanceSound(struct SoundInstance *soundInst /*$s0*/)
// line 573, offset 0x8003f3dc
/* begin block 1 */
// Start line: 574
// Start offset: 0x8003F3DC
// Variables:
// 		struct SoundEffectChannel *channel; // $v0
/* end block 1 */
// End offset: 0x8003F420
// End Line: 585

/* begin block 2 */
// Start line: 1255
/* end block 2 */
// End Line: 1256

void SOUND_StopInstanceSound(SoundInstance *soundInst)

{
  SoundEffectChannel *pSVar1;

  pSVar1 = SndGetSfxChannel((uint)soundInst->channel);
  if (pSVar1 != (SoundEffectChannel *)0x0)
  {
    SndEndLoop(pSVar1->handle);
    SndCloseSfxChannel((uint)soundInst->channel);
    soundInst->channel = -1;
  }
  soundInst->state = '\x01';
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SOUND_IsInstanceSoundLoaded(unsigned char *sfxFileData /*$a0*/, long soundNumber /*$a1*/)
// line 594, offset 0x8003f438
/* begin block 1 */
// Start line: 595
// Start offset: 0x8003F438
// Variables:
// 		unsigned short *sfxIDList; // $s1
// 		int numSounds; // $a3
// 		int numSfxIDs; // $s0
// 		int i; // $a2
// 		int status; // $v0
/* end block 1 */
// End offset: 0x8003F51C
// End Line: 652

/* begin block 2 */
// Start line: 1297
/* end block 2 */
// End Line: 1298

int SOUND_IsInstanceSoundLoaded(uchar *sfxFileData, long soundNumber)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;

  if (((sfxFileData != (uchar *)0x0) && (*sfxFileData == -0x42)) && (sfxFileData[1] == -0x11))
  {
    pbVar4 = sfxFileData + 4;
    iVar5 = 0;
    if (sfxFileData[2] != 0)
    {
      do
      {
        bVar1 = *pbVar4;
        if (((bVar1 == 1) || (1 < bVar1)) || (puVar7 = (ushort *)(pbVar4 + 0x12), bVar1 != 0))
        {
          uVar6 = (uint)pbVar4[1];
          puVar7 = (ushort *)(pbVar4 + 0xe);
          iVar3 = uVar6 * 2 + 0xe;
        }
        else
        {
          uVar6 = (uint)pbVar4[1];
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
            iVar5 = aadIsSfxLoaded((uint)uVar2);
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
      } while (iVar5 < (int)(uint)sfxFileData[2]);
    }
  }
  return -1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetInstanceSoundPitch(struct SoundInstance *soundInst /*$a0*/, long pitchChangeAmt /*$s1*/, long time /*$s0*/)
// line 665, offset 0x8003f534
/* begin block 1 */
// Start line: 666
// Start offset: 0x8003F534
// Variables:
// 		struct SoundEffectChannel *channel; // $a0
/* end block 1 */
// End offset: 0x8003F5E0
// End Line: 687

/* begin block 2 */
// Start line: 1474
/* end block 2 */
// End Line: 1475

void SOUND_SetInstanceSoundPitch(SoundInstance *soundInst, long pitchChangeAmt, long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;

  if (((soundInst->state & 0xf) == 2) &&
      (pSVar2 = SndGetSfxChannel((uint)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0))
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
      pSVar2->pitchChangePerUpdate = (short)(pitchChangeAmt / time);
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

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetInstanceSoundVolume(struct SoundInstance *soundInst /*$a0*/, long volumeChangeAmt /*$s0*/, long time /*$s1*/)
// line 694, offset 0x8003f5f4
/* begin block 1 */
// Start line: 695
// Start offset: 0x8003F5F4
// Variables:
// 		struct SoundEffectChannel *channel; // $a0
/* end block 1 */
// End offset: 0x8003F6E4
// End Line: 720

/* begin block 2 */
// Start line: 1535
/* end block 2 */
// End Line: 1536

void SOUND_SetInstanceSoundVolume(SoundInstance *soundInst, long volumeChangeAmt, long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;

  if (((soundInst->state & 0xf) == 2) &&
      (pSVar2 = SndGetSfxChannel((uint)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0))
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
      pSVar2->volumeChangePerUpdate = (short)(volumeChangeAmt / time);
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

// decompiled code
// original method signature:
// void /*$ra*/ processOneShotSound(struct _Position *position /*$s6*/, int hidden /*$t0*/, int burning /*$t1*/, long *triggerFlags /*$s4*/, struct SoundInstance *soundInst /*stack 16*/, struct ObjectOneShotSound *sound /*stack 20*/)
// line 741, offset 0x8003f6f8
/* begin block 1 */
// Start line: 742
// Start offset: 0x8003F6F8
// Variables:
// 		struct SoundEffectChannel *channel; // $s0
// 		int sfxIDNum; // $v1
// 		int sfxToneID; // $a1
// 		long triggerMask; // $s3
// 		int spectralPlane; // $a1
/* end block 1 */
// End offset: 0x8003FA18
// End Line: 848

/* begin block 2 */
// Start line: 1482
/* end block 2 */
// End Line: 1483

void processOneShotSound(_Position *position, int hidden, int burning, long *triggerFlags,
                         SoundInstance *soundInst, ObjectOneShotSound *sound)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  ulong uVar3;
  byte bVar4;
  uint uVar5;

  bVar4 = soundInst->state & 0xf;
  uVar5 = (&objectOneShotTriggerTbl)[(uint)sound->type - 2];
  if (bVar4 == 1)
  {
    if ((*triggerFlags & uVar5) == 0)
    {
      return;
    }
    iVar2 = isOkayToPlaySound((uint)sound->flags, (int)gameTrackerX.gameData.asmData.MorphType, hidden, burning);
    if (iVar2 == 0)
    {
    LAB_8003f8dc:
      *triggerFlags = *triggerFlags & ~uVar5;
      return;
    }
    soundInst->delay = sound->initialDelay;
    if (sound->initialDelayVariation != '\0')
    {
      iVar2 = rand();
      soundInst->delay =
          soundInst->delay +
          (sound->initialDelayVariation - (char)(iVar2 % ((uint)sound->initialDelayVariation << 1)));
    }
    if (soundInst->delay != '\0')
    {
      soundInst->state = '\x02';
      return;
    }
  LAB_8003f830:
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
        goto LAB_8003f830;
      }
      if (bVar4 == 3)
      {
        pSVar1 = SndGetSfxChannel((uint)soundInst->channel);
        if (pSVar1 == (SoundEffectChannel *)0x0)
        {
          pSVar1 = SndOpenSfxChannel((uchar *)soundInst);
          if (pSVar1 == (SoundEffectChannel *)0x0)
          {
            return;
          }
          pSVar1->volume = (ushort)sound->maxVolume;
          if (sound->maxVolVariation != '\0')
          {
            iVar2 = rand();
            pSVar1->volume =
                pSVar1->volume +
                ((ushort)sound->maxVolVariation -
                 (short)(iVar2 % ((uint)sound->maxVolVariation << 1)));
          }
          pSVar1->pitch = sound->pitch;
          if (sound->pitchVariation != 0)
          {
            iVar2 = rand();
            pSVar1->pitch =
                pSVar1->pitch +
                (sound->pitchVariation - (short)(iVar2 % ((uint)sound->pitchVariation << 1)));
          }
          if (sound->numSfxIDs < 2)
          {
            iVar2 = 0;
          }
          else
          {
            iVar2 = rand();
            iVar2 = iVar2 % (uint)sound->numSfxIDs << 1;
          }
          uVar3 = SOUND_Play3dSound(position, (uint) * (ushort *)(&sound[1].type + iVar2),
                                    (int)pSVar1->pitch, (int)pSVar1->volume,
                                    (uint)sound->minVolDistance);
          pSVar1->handle = uVar3;
          if (uVar3 != 0)
          {
            return;
          }
          SndCloseSfxChannel((uint)soundInst->channel);
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
          uVar3 = SOUND_Update3dSound(position, pSVar1->handle, (int)pSVar1->pitch, (int)pSVar1->volume, (uint)sound->minVolDistance);
          if (uVar3 != 0)
          {
            return;
          }
          SndEndLoop(pSVar1->handle);
        }
        SndCloseSfxChannel((uint)soundInst->channel);
        soundInst->channel = -1;
        soundInst->state = '\x01';
        goto LAB_8003f8dc;
      }
    }
    soundInst->channel = -1;
    soundInst->state = '\x01';
    soundInst->delay = '\0';
  }
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SOUND_Play3dSound(struct _Position *position /*$t0*/, int sfxToneID /*$s5*/, int pitch /*$s6*/, int maxVolume /*$s4*/, int minVolDist /*stack 16*/)
// line 863, offset 0x8003fa40
/* begin block 1 */
// Start line: 864
// Start offset: 0x8003FA40
// Variables:
// 		long dx; // $s1
// 		long dy; // $s0
// 		long dz; // $a0
// 		long objDist; // $s3
// 		long workMinVolDist; // $s2
// 		int angle; // $v0
// 		int quadrant; // $a0
// 		int qpos; // $v1
// 		int pan; // $a2
// 		int volume; // $a1
/* end block 1 */
// End offset: 0x8003FC54
// End Line: 956

/* begin block 2 */
// Start line: 1873
/* end block 2 */
// End Line: 1874

ulong SOUND_Play3dSound(_Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  ushort pan;
  uint uVar6;
  uint uVar7;
  ushort vol;

  if (maxVolume == 0)
  {
    return 0;
  }
  if (minVolDist == 0)
  {
    vol = (ushort)maxVolume;
    pan = 0x40;
    goto LAB_8003fc3c;
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
  _vol = (minVolDist - lVar3) / (minVolDist / maxVolume);
  vol = (ushort)_vol;
  uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
  uVar7 = (int)(uVar6 & 0xfff) >> 10;
  if (0x7f < _vol)
  {
    vol = 0x7f;
  }
  iVar4 = (int)(uVar6 & 0x3ff) >> 4;
  if (uVar7 != 1)
  {
    if (uVar7 < 2)
    {
      if (uVar7 == 0)
      {
        _vol = 0x3f;
      }
      else
      {
      LAB_8003fbe4:
        _vol = 0x7f;
      }
      iVar4 = _vol - iVar4;
    }
    else
    {
      if (uVar7 != 2)
        goto LAB_8003fbe4;
      iVar4 = iVar4 + 0x40;
    }
  }
  minVolDist = (lVar3 << 8) / minVolDist;
  if (iVar4 < 0x40)
  {
    pan = 0x3f - (short)((uint)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else
  {
    pan = (short)((uint)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
LAB_8003fc3c:
  uVar5 = SndPlayVolPan(sfxToneID, vol, pan, (short)pitch);
  return uVar5;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SOUND_Update3dSound(struct _Position *position /*$t0*/, unsigned long handle /*$s5*/, int pitch /*$s6*/, int maxVolume /*$s4*/, int minVolDist /*stack 16*/)
// line 962, offset 0x8003fc7c
/* begin block 1 */
// Start line: 963
// Start offset: 0x8003FC7C
// Variables:
// 		long dx; // $s1
// 		long dy; // $s0
// 		long dz; // $a0
// 		long objDist; // $s3
// 		long workMinVolDist; // $s2
// 		int angle; // $v0
// 		int quadrant; // $a0
// 		int qpos; // $v1
// 		int pan; // $a2
// 		int volume; // $a1
/* end block 1 */
// End offset: 0x8003FE88
// End Line: 1054

/* begin block 2 */
// Start line: 2084
/* end block 2 */
// End Line: 2085

ulong SOUND_Update3dSound(_Position *position, ulong handle, int pitch, int maxVolume, int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  ushort pan;
  uint uVar6;
  uint uVar7;
  ushort vol;

  if (maxVolume == 0)
  {
    return 0;
  }
  if (minVolDist == 0)
  {
    return handle;
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
  _vol = (minVolDist - lVar3) / (minVolDist / maxVolume);
  vol = (ushort)_vol;
  uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
  uVar7 = (int)(uVar6 & 0xfff) >> 10;
  if (0x7f < _vol)
  {
    vol = 0x7f;
  }
  iVar4 = (int)(uVar6 & 0x3ff) >> 4;
  if (uVar7 == 1)
    goto LAB_8003fe20;
  if (uVar7 < 2)
  {
    if (uVar7 != 0)
      goto LAB_8003fe18;
    _vol = 0x3f;
  }
  else
  {
    if (uVar7 == 2)
    {
      iVar4 = iVar4 + 0x40;
      goto LAB_8003fe20;
    }
  LAB_8003fe18:
    _vol = 0x7f;
  }
  iVar4 = _vol - iVar4;
LAB_8003fe20:
  minVolDist = (lVar3 << 8) / minVolDist;
  if (iVar4 < 0x40)
  {
    pan = 0x3f - (short)((uint)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else
  {
    pan = (short)((uint)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
  uVar5 = SndUpdateVolPanPitch(handle, vol, pan, (short)pitch);
  return uVar5;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_HandleGlobalValueSignal(int name /*$a0*/, long data /*$a1*/)
// line 1087, offset 0x8003feb0
/* begin block 1 */
// Start line: 2174
/* end block 1 */
// End Line: 2175

/* begin block 2 */
// Start line: 2314
/* end block 2 */
// End Line: 2315

void SOUND_HandleGlobalValueSignal(int name, long data)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_Init()
// line 1100, offset 0x8003feb8
/* begin block 1 */
// Start line: 1101
// Start offset: 0x8003FEB8
// Variables:
// 		struct AadInitAttr initAttr; // stack offset -32
/* end block 1 */
// End offset: 0x8003FEB8
// End Line: 1101

/* begin block 2 */
// Start line: 2339
/* end block 2 */
// End Line: 2340

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_Init(void)

{
  AadInitAttr local_20;

  local_20.numSlots = 4;
  local_20.nonBlockLoadProc = LOAD_NonBlockingFileLoad;
  local_20.nonBlockBufferedLoadProc = LOAD_NonBlockingBufferedLoad;
  local_20.memoryMallocProc = MEMPACK_Malloc;
  local_20.updateMode = 1;
  local_20.memoryFreeProc = MEMPACK_Free;
  aadGetMemorySize(&local_20);
  aadInit(&local_20, (uchar *)&soundBuffer);
  gameTrackerX.sound.gMasterVol = 0x3fff;
  SOUND_SetMusicVolume(0x7f);
  SOUND_SetSfxVolume(0x7f);
  SOUND_SetVoiceVolume(0x50);
  gameTrackerX.sound.gSfxOn = '\x01';
  gameTrackerX.sound.gMusicOn = '\x01';
  gameTrackerX.sound.gVoiceOn = '\x01';
  gameTrackerX.sound.soundsLoaded = '\0';
  SOUND_MusicInit();
  aadInitReverb();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_Free()
// line 1195, offset 0x8003ff6c
/* begin block 1 */
// Start line: 2571
/* end block 1 */
// End Line: 2572

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_Free(void)

{
  gameTrackerX.sound.soundsLoaded = '\0';
  aadShutdown();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetMusicVariable(int variable /*$a0*/, int value /*$a1*/)
// line 1228, offset 0x8003ff90
/* begin block 1 */
// Start line: 2456
/* end block 1 */
// End Line: 2457

void SOUND_SetMusicVariable(int variable, int value)

{
  aadSetUserVariable(variable, value);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetMusicVolume(int newVolume /*$a0*/)
// line 1238, offset 0x8003ffb0
/* begin block 1 */
// Start line: 2476
/* end block 1 */
// End Line: 2477

void SOUND_SetMusicVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gMusicVol;
  }
  gameTrackerX.sound.gMusicVol = newVolume;
  aadSetMusicMasterVolume(newVolume);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetSfxVolume(int newVolume /*$a0*/)
// line 1245, offset 0x8003ffe4
/* begin block 1 */
// Start line: 2631
/* end block 1 */
// End Line: 2632

void SOUND_SetSfxVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gSfxVol;
  }
  gameTrackerX.sound.gSfxVol = newVolume;
  aadSetSfxMasterVolume(newVolume);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetVoiceVolume(int newVolume /*$a0*/)
// line 1252, offset 0x80040018
/* begin block 1 */
// Start line: 2645
/* end block 1 */
// End Line: 2646

/* begin block 2 */
// Start line: 2646
/* end block 2 */
// End Line: 2647

void SOUND_SetVoiceVolume(int newVolume)

{
  if (newVolume == -1)
  {
    newVolume = gameTrackerX.sound.gVoiceVol;
  }
  gameTrackerX.sound.gVoiceVol = newVolume;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_PauseAllSound()
// line 1268, offset 0x80040038
/* begin block 1 */
// Start line: 2536
/* end block 1 */
// End Line: 2537

/* begin block 2 */
// Start line: 2664
/* end block 2 */
// End Line: 2665

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_PauseAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadShutdownReverb();
    aadPauseSound();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ResumeAllSound()
// line 1277, offset 0x80040068
/* begin block 1 */
// Start line: 2682
/* end block 1 */
// End Line: 2683

/* begin block 2 */
// Start line: 2683
/* end block 2 */
// End Line: 2684

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ResumeAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadInitReverb();
    aadResumeSound();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_StopAllSound()
// line 1286, offset 0x80040098
/* begin block 1 */
// Start line: 2701
/* end block 1 */
// End Line: 2702

/* begin block 2 */
// Start line: 2702
/* end block 2 */
// End Line: 2703

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_StopAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    aadStopAllSfx();
    aadStopAllSlots();
    aadShutdownReverb();
    aadCancelPauseSound();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ResetAllSound()
// line 1297, offset 0x800400d8
/* begin block 1 */
// Start line: 2724
/* end block 1 */
// End Line: 2725

/* begin block 2 */
// Start line: 2725
/* end block 2 */
// End Line: 2726

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ResetAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0')
  {
    SOUND_StopAllSound();
    aadInitReverb();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_MusicOff()
// line 1306, offset 0x80040108
/* begin block 1 */
// Start line: 1307
// Start offset: 0x80040108
// Variables:
// 		int slotNumber; // $s0
/* end block 1 */
// End offset: 0x80040158
// End Line: 1322

/* begin block 2 */
// Start line: 2743
/* end block 2 */
// End Line: 2744

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
      aadStopSlot(slotNumber);
      aadStartSlot(slotNumber);
    }
    slotNumber = slotNumber + 1;
  } while (slotNumber < 4);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_MusicOn()
// line 1324, offset 0x8004016c
/* begin block 1 */
// Start line: 1325
// Start offset: 0x8004016C
// Variables:
// 		int slotNumber; // $s0
/* end block 1 */
// End offset: 0x80040194
// End Line: 1330

/* begin block 2 */
// Start line: 2795
/* end block 2 */
// End Line: 2796

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SfxOff()
// line 1333, offset 0x800401a4
/* begin block 1 */
// Start line: 2817
/* end block 1 */
// End Line: 2818

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOff(void)

{
  aadStopAllSfx();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SfxOn()
// line 1339, offset 0x800401c4
/* begin block 1 */
// Start line: 2829
/* end block 1 */
// End Line: 2830

/* begin block 2 */
// Start line: 2831
/* end block 2 */
// End Line: 2832

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOn(void)

{
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SndIsPlaying(unsigned long handle /*$a0*/)
// line 1361, offset 0x800401cc
/* begin block 1 */
// Start line: 2722
/* end block 1 */
// End Line: 2723

int SndIsPlaying(ulong handle)

{
  int iVar1;

  iVar1 = aadIsSfxPlaying(handle);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ SndIsPlayingOrRequested(unsigned long handle /*$a0*/)
// line 1366, offset 0x800401ec
/* begin block 1 */
// Start line: 2863
/* end block 1 */
// End Line: 2864

int SndIsPlayingOrRequested(ulong handle)

{
  int iVar1;

  iVar1 = aadIsSfxPlayingOrRequested(handle);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ SndTypeIsPlayingOrRequested(unsigned int sfxToneID /*$a0*/)
// line 1376, offset 0x8004020c
/* begin block 1 */
// Start line: 2752
/* end block 1 */
// End Line: 2753

int SndTypeIsPlayingOrRequested(uint sfxToneID)

{
  int iVar1;

  iVar1 = aadIsSfxTypePlayingOrRequested(sfxToneID);
  return iVar1;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SndPlay(unsigned int sample /*$a0*/)
// line 1387, offset 0x8004022c
/* begin block 1 */
// Start line: 2774
/* end block 1 */
// End Line: 2775

/* begin block 2 */
// Start line: 2887
/* end block 2 */
// End Line: 2888

ulong SndPlay(uint sample)

{
  ulong uVar1;

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

// decompiled code
// original method signature:
// void /*$ra*/ SndEndLoop(unsigned long handle /*$a0*/)
// line 1395, offset 0x80040264
/* begin block 1 */
// Start line: 2901
/* end block 1 */
// End Line: 2902

/* begin block 2 */
// Start line: 2905
/* end block 2 */
// End Line: 2906

void SndEndLoop(ulong handle)

{
  aadStopSfx(handle);
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SndPlayVolPan(unsigned int sample /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
// line 1400, offset 0x80040284
/* begin block 1 */
// Start line: 1401
// Start offset: 0x80040284
/* end block 1 */
// End offset: 0x800402B0
// End Line: 1411

/* begin block 2 */
// Start line: 2915
/* end block 2 */
// End Line: 2916

/* begin block 3 */
// Start line: 2918
/* end block 3 */
// End Line: 2919

ulong SndPlayVolPan(uint sample, ushort vol, ushort pan, short pitch)

{
  ulong uVar1;

  if (gameTrackerX.sound.gSfxOn == '\0')
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = aadPlaySfx(sample, (uint)vol, (uint)pan, (int)pitch);
  }
  return uVar1;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SndUpdateVolPanPitch(unsigned long handle /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
// line 1421, offset 0x800402c0
/* begin block 1 */
// Start line: 2842
/* end block 1 */
// End Line: 2843

ulong SndUpdateVolPanPitch(ulong handle, ushort vol, ushort pan, short pitch)

{
  ulong uVar1;

  if ((handle == 0) || (gameTrackerX.sound.gSfxOn == '\0'))
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = aadSetSfxVolPanPitch(handle, (uint)vol, (uint)pan, (int)pitch);
  }
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ musicLoadReturnFunc(int dynamicBankIndex /*$a0*/, int errorStatus /*$a1*/)
// line 1454, offset 0x80040308
/* begin block 1 */
// Start line: 3019
/* end block 1 */
// End Line: 3020

/* begin block 2 */
// Start line: 3021
/* end block 2 */
// End Line: 3022

void musicLoadReturnFunc(int dynamicBankIndex, int errorStatus)

{
  musicInfo.state = musicInfo.nextState;
  musicInfo.errorStatus = errorStatus;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ musicFadeoutReturnFunc()
// line 1461, offset 0x8004031c
/* begin block 1 */
// Start line: 3034
/* end block 1 */
// End Line: 3035

/* begin block 2 */
// Start line: 3035
/* end block 2 */
// End Line: 3036

/* WARNING: Unknown calling convention yet parameter storage is locked */

void musicFadeoutReturnFunc(void)

{
  musicInfo.state = musicInfo.nextState;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ musicEndCallbackFunc(long userData /*$a0*/, int slot /*$a1*/, int loopFlag /*$a2*/)
// line 1467, offset 0x80040330
/* begin block 1 */
// Start line: 3046
/* end block 1 */
// End Line: 3047

void musicEndCallbackFunc(long userData, int slot, int loopFlag)

{
  int iVar1;

  if (slot == 0)
  {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0, 0);
    iVar1 = aadAssignDynamicSequence(musicInfo.bankLoaded, 0, 0);
    if (iVar1 == 0)
    {
      aadStartSlot(0);
      musicInfo.state = musicInfo.nextState;
    }
    else
    {
      musicInfo.state = 0;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_PutMusicCommand(int cmdType /*$a0*/, int cmdData /*$a1*/)
// line 1487, offset 0x80040390
/* begin block 1 */
// Start line: 1489
// Start offset: 0x80040390
// Variables:
// 		struct MusicLoadCmd *cmd; // $v0
/* end block 1 */
// End offset: 0x800403D0
// End Line: 1498

/* begin block 2 */
// Start line: 3086
/* end block 2 */
// End Line: 3087

/* begin block 3 */
// Start line: 3087
/* end block 3 */
// End Line: 3088

void SOUND_PutMusicCommand(int cmdType, int cmdData)

{
  int iVar1;

  iVar1 = musicInfo.commandIn;
  musicInfo.commandQueue[musicInfo.commandIn].type = cmdType;
  musicInfo.commandQueue[iVar1].data = cmdData;
  if (musicInfo.numCmdsInQueue < 3)
  {
    musicInfo.commandIn = musicInfo.commandIn + 1U & 3;
    musicInfo.numCmdsInQueue = musicInfo.numCmdsInQueue + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_MusicInit()
// line 1501, offset 0x800403d8
/* begin block 1 */
// Start line: 3115
/* end block 1 */
// End Line: 3116

/* begin block 2 */
// Start line: 3119
/* end block 2 */
// End Line: 3120

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicInit(void)

{
  musicInfo.state = 0;
  musicInfo.errorStatus = 0;
  musicInfo.checkMusicDelay = 0;
  musicInfo.currentMusicPlane = -1;
  musicInfo.currentMusicName[0] = '\0';
  musicInfo.commandIn = 0;
  musicInfo.commandOut = 0;
  musicInfo.numCmdsInQueue = 0;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SOUND_IsMusicLoading()
// line 1512, offset 0x80040404
/* begin block 1 */
// Start line: 3140
/* end block 1 */
// End Line: 3141

/* begin block 2 */
// Start line: 3141
/* end block 2 */
// End Line: 3142

/* WARNING: Unknown calling convention yet parameter storage is locked */

int SOUND_IsMusicLoading(void)

{
  int iVar1;

  iVar1 = 0;
  if (((musicInfo.state == 1) || (musicInfo.state == 3)) || (musicInfo.state == 7))
  {
    iVar1 = 1;
  }
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ProcessMusicLoad()
// line 1533, offset 0x80040434
/* begin block 1 */
// Start line: 1534
// Start offset: 0x80040434
// Variables:
// 		char musicName[8]; // stack offset -88
// 		char sndFileName[32]; // stack offset -80
// 		char smpFileName[32]; // stack offset -48

/* begin block 1.1 */
// Start line: 1546
// Start offset: 0x80040484
// Variables:
// 		struct MusicLoadCmd *cmd; // $v1
/* end block 1.1 */
// End offset: 0x800404F4
// End Line: 1558

/* begin block 1.2 */
// Start line: 1562
// Start offset: 0x80040504
// Variables:
// 		struct Level *level; // $v1
/* end block 1.2 */
// End offset: 0x8004074C
// End Line: 1630
/* end block 1 */
// End offset: 0x80040918
// End Line: 1724

/* begin block 2 */
// Start line: 3182
/* end block 2 */
// End Line: 3183

/* begin block 3 */
// Start line: 3188
/* end block 3 */
// End Line: 3189

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ProcessMusicLoad(void)

{
  Level *pLVar1;
  long lVar2;
  int dynamicBankIndex;
  int loadOption;
  char local_58;
  char local_57;
  undefined local_56;
  undefined local_55;
  undefined local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  char local_36;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  char local_16;

  switch (musicInfo.state)
  {
  case 0:
    if (musicInfo.numCmdsInQueue != 0)
    {
      if (musicInfo.commandQueue[musicInfo.commandOut].type == 0)
      {
        musicInfo.state = 0xb;
        musicInfo.nextState = 0xd;
        musicInfo.currentMusicPlane = musicInfo.commandQueue[musicInfo.commandOut].data;
        aadStartMusicMasterVolFade(0, -3, musicFadeoutReturnFunc);
      }
      musicInfo.commandOut = musicInfo.commandOut + 1U & 3;
      musicInfo.numCmdsInQueue = musicInfo.numCmdsInQueue + -1;
      return;
    }
    if (musicInfo.checkMusicDelay != 0)
    {
      musicInfo.checkMusicDelay = musicInfo.checkMusicDelay + -1;
      return;
    }
    if ((aadMem->sramDefragInfo).status != 0)
    {
      return;
    }
    musicInfo.checkMusicDelay = 0x1e;
    pLVar1 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    if (pLVar1 != (Level *)0x0)
    {
      if (pLVar1->dynamicMusicName == (char *)0x0)
      {
        if (musicInfo.currentMusicName[0] != '\0')
        {
          musicInfo.currentMusicName[0] = '\0';
          musicInfo.state = 0xb;
          musicInfo.nextState = 0xc;
          aadStartMusicMasterVolFade(0, -1, musicFadeoutReturnFunc);
          return;
        }
        return;
      }
      local_58 = *pLVar1->dynamicMusicName;
      local_57 = pLVar1->dynamicMusicName[1];
      if (musicInfo.currentMusicPlane == -1)
      {
        musicInfo.currentMusicPlane = (int)gameTrackerX.gameData.asmData.MorphType;
      }
      if (musicInfo.currentMusicPlane == 0)
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
      dynamicBankIndex = strcmpi(&local_58, musicInfo.currentMusicName);
      if (dynamicBankIndex != 0)
      {
        if (musicInfo.currentMusicName[0] == '\0')
        {
          sprintf((char *)&local_50, s__kain2_music__s__s_snd_800cea9c);
          sprintf((char *)&local_30, s__kain2_music__s__s_smp_800ceaec);
          lVar2 = LOAD_DoesFileExist((char *)&local_50);
          if (lVar2 == 0)
          {
            return;
          }
          strcpy(musicInfo.currentMusicName, &local_58);
          dynamicBankIndex = 0;
          loadOption = 1;
          musicInfo.state = 1;
          musicInfo.nextState = 2;
        }
        else
        {
          sprintf((char *)&local_50, s__kain2_music__s__s_snd_800cea9c);
          lVar2 = LOAD_DoesFileExist((char *)&local_50);
          if (lVar2 == 0)
          {
            return;
          }
          strcpy(musicInfo.currentMusicName, &local_58);
          dynamicBankIndex = 1;
          loadOption = 0;
          local_50 = s__kain2_music_uwtr_uwtr_snd_800ceab4._0_4_;
          local_4c = s__kain2_music_uwtr_uwtr_snd_800ceab4._4_4_;
          local_48 = s__kain2_music_uwtr_uwtr_snd_800ceab4._8_4_;
          local_44 = s__kain2_music_uwtr_uwtr_snd_800ceab4._12_4_;
          local_40 = s__kain2_music_uwtr_uwtr_snd_800ceab4._16_4_;
          local_3c = s__kain2_music_uwtr_uwtr_snd_800ceab4._20_4_;
          local_38 = s__kain2_music_uwtr_uwtr_snd_800ceab4._24_2_;
          local_36 = s__kain2_music_uwtr_uwtr_snd_800ceab4[26];
          local_30 = s__kain2_music_uwtr_uwtr_smp_800cead0._0_4_;
          local_2c = s__kain2_music_uwtr_uwtr_smp_800cead0._4_4_;
          local_28 = s__kain2_music_uwtr_uwtr_smp_800cead0._8_4_;
          local_24 = s__kain2_music_uwtr_uwtr_smp_800cead0._12_4_;
          local_20 = s__kain2_music_uwtr_uwtr_smp_800cead0._16_4_;
          local_1c = s__kain2_music_uwtr_uwtr_smp_800cead0._20_4_;
          local_18 = s__kain2_music_uwtr_uwtr_smp_800cead0._24_2_;
          local_16 = s__kain2_music_uwtr_uwtr_smp_800cead0[26];
          musicInfo.state = 3;
          musicInfo.nextState = 4;
        }
        aadLoadDynamicSoundBank((char *)&local_50, (char *)&local_30, dynamicBankIndex, loadOption,
                                musicLoadReturnFunc);
        return;
      }
      return;
    }
    return;
  default:
    goto switchD_8004046c_caseD_1;
  case 2:
    dynamicBankIndex = aadAssignDynamicSequence(0, 0, 0);
    if (dynamicBankIndex == 0)
    {
      aadStartSlot(0);
    }
    break;
  case 4:
    if (musicInfo.errorStatus != 0)
    {
      musicInfo.state = 0;
      return;
    }
    musicInfo.state = 5;
    musicInfo.nextState = 6;
    musicInfo.bankLoaded = 1;
    goto LAB_80040890;
  case 6:
    if ((aadMem->sramDefragInfo).status == 0)
    {
      sprintf((char *)&local_50, s__kain2_music__s__s_snd_800cea9c);
      sprintf((char *)&local_30, s__kain2_music__s__s_smp_800ceaec);
      aadLoadDynamicSoundBank((char *)&local_50, (char *)&local_30, 0, 1, musicLoadReturnFunc);
      musicInfo.state = 7;
      musicInfo.nextState = 8;
      return;
    }
    return;
  case 8:
    if (musicInfo.errorStatus != 0)
    {
      musicInfo.state = 0;
      return;
    }
    musicInfo.state = 9;
    musicInfo.nextState = 10;
    musicInfo.bankLoaded = 0;
  LAB_80040890:
    aadInstallEndSequenceCallback(musicEndCallbackFunc, 0);
    aadSetUserVariable(0x7f, 1);
    return;
  case 10:
    aadFreeDynamicSoundBank(1);
    break;
  case 0xc:
    aadStopAllSlots();
    aadFreeDynamicSoundBank(0);
    aadStartMusicMasterVolFade(gameTrackerX.sound.gMusicVol, 1,
                               (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    break;
  case 0xd:
    aadStopAllSlots();
    aadFreeDynamicSoundBank(0);
    aadStartMusicMasterVolFade(gameTrackerX.sound.gMusicVol, 1,
                               (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    musicInfo.currentMusicName[0] = '\0';
    musicInfo.checkMusicDelay = 0;
  }
  musicInfo.state = 0;
switchD_8004046c_caseD_1:
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_UpdateSound()
// line 1730, offset 0x80040930
/* begin block 1 */
// Start line: 3609
/* end block 1 */
// End Line: 3610

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_UpdateSound(void)

{
  bool bVar1;

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
    FONT_Print(s___sound_memory_full__u__d__d_f___800ceb04);
  }
  if (gameTrackerX.sound.gMusicOn != '\0')
  {
    SOUND_ProcessMusicLoad();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_PlaneShift(int newPlane /*$a1*/)
// line 1763, offset 0x800409dc
/* begin block 1 */
// Start line: 3675
/* end block 1 */
// End Line: 3676

void SOUND_PlaneShift(int newPlane)

{
  if (gameTrackerX.sound.gMusicOn == '\0')
  {
    musicInfo.currentMusicPlane = -1;
  }
  else
  {
    SOUND_PutMusicCommand(0, newPlane);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ShutdownMusic()
// line 1793, offset 0x80040a18
/* begin block 1 */
// Start line: 1794
// Start offset: 0x80040A18
/* end block 1 */
// End offset: 0x80040A94
// End Line: 1814

/* begin block 2 */
// Start line: 3736
/* end block 2 */
// End Line: 3737

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ShutdownMusic(void)

{
  aadStopAllSlots();
  EnterCriticalSection();
  if (((musicInfo.state == 1) || (musicInfo.state == 3)) || (musicInfo.state == 7))
  {
    musicInfo.nextState = 0;
    ExitCriticalSection();
    while (musicInfo.state != 0)
    {
      STREAM_PollLoadQueue();
    }
  }
  else
  {
    ExitCriticalSection();
  }
  musicInfo.currentMusicName[0] = '\0';
  aadFreeDynamicSoundBank(0);
  aadFreeDynamicSoundBank(1);
  musicInfo.state = 0;
  aadStartMusicMasterVolFade(gameTrackerX.sound.gMusicVol, 1,
                             (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_SetMusicModifier(long modifier /*$a0*/)
// line 1826, offset 0x80040acc
/* begin block 1 */
// Start line: 3804
/* end block 1 */
// End Line: 3805

void SOUND_SetMusicModifier(long modifier)

{
  int variable;
  int value;

  switch (modifier)
  {
  case 0:
    variable = 0;
    value = 0;
    goto LAB_80040b74;
  case 1:
    variable = 0;
    break;
  case 2:
    variable = 0;
    value = 3;
    goto LAB_80040b74;
  case 3:
    variable = 0;
    value = 4;
    goto LAB_80040b74;
  case 4:
    variable = 0;
    value = 2;
    goto LAB_80040b74;
  case 5:
    variable = 1;
    break;
  case 6:
    variable = 2;
    break;
  default:
    goto switchD_80040af4_caseD_7;
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
LAB_80040b74:
  SOUND_SetMusicVariable(variable, value);
switchD_80040af4_caseD_7:
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SOUND_ResetMusicModifier(long modifier /*$a0*/)
// line 1883, offset 0x80040b8c
/* begin block 1 */
// Start line: 3918
/* end block 1 */
// End Line: 3919

void SOUND_ResetMusicModifier(long modifier)

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
    goto switchD_80040bb4_caseD_7;
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
switchD_80040bb4_caseD_7:
  return;
}
