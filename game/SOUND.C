#include "THISDUST.H"
#include "SOUND.H"


// decompiled code
// original method signature: 
// struct SoundEffectChannel * /*$ra*/ SndOpenSfxChannel(unsigned char *channelNum /*$a0*/)
 // line 46, offset 0x8003f1c8
	/* begin block 1 */
		// Start line: 48
		// Start offset: 0x8003F1C8
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8003F20C
	// End Line: 62

	/* begin block 2 */
		// Start line: 92
	/* end block 2 */
	// End Line: 93

	/* begin block 3 */
		// Start line: 93
	/* end block 3 */
	// End Line: 94

	/* begin block 4 */
		// Start line: 95
	/* end block 4 */
	// End Line: 96

SoundEffectChannel * SndOpenSfxChannel(uchar *channelNum)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &soundEffectChannelTbl;
  do {
    if (pSVar1->inUse == '\0') {
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
 // line 65, offset 0x8003f214
	/* begin block 1 */
		// Start line: 138
	/* end block 1 */
	// End Line: 139

	/* begin block 2 */
		// Start line: 139
	/* end block 2 */
	// End Line: 140

void SndCloseSfxChannel(int channelNum)

{
  if (channelNum < 0x10) {
    (&soundEffectChannelTbl)[channelNum].inUse = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// struct SoundEffectChannel * /*$ra*/ SndGetSfxChannel(int channelNum /*$a0*/)
 // line 72, offset 0x8003f240
	/* begin block 1 */
		// Start line: 152
	/* end block 1 */
	// End Line: 153

	/* begin block 2 */
		// Start line: 153
	/* end block 2 */
	// End Line: 154

SoundEffectChannel * SndGetSfxChannel(int channelNum)

{
  if (0xf < channelNum) {
    return (SoundEffectChannel *)0x0;
  }
  return &soundEffectChannelTbl + channelNum;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_ProcessInstanceSounds(unsigned char *sfxFileData /*$s0*/, struct SoundInstance *soundInstTbl /*$a1*/, struct _Position *position /*$s4*/, int livesInOnePlace /*$fp*/, int inSpectral /*stack 16*/, int hidden /*stack 20*/, long *triggerFlags /*stack 24*/)
 // line 102, offset 0x8003f26c
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x8003F26C
		// Variables:
	// 		int numSounds; // $s3
	// 		int numSfxIDs; // $v0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8003F3B8
	// End Line: 146

	/* begin block 2 */
		// Start line: 188
	/* end block 2 */
	// End Line: 189

	/* begin block 3 */
		// Start line: 214
	/* end block 3 */
	// End Line: 215

void SOUND_ProcessInstanceSounds
               (uchar *sfxFileData,SoundInstance *soundInstTbl,_Position *position,
               int livesInOnePlace,int inSpectral,int hidden,long *triggerFlags)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ObjectPeriodicSound *sound;
  int iVar4;
  
  if ((((gameTrackerX.gameMode != 6) && (sfxFileData != (uchar *)0x0)) &&
      (soundInstTbl != (SoundInstance *)0x0)) &&
     ((*sfxFileData == -0x42 && (sfxFileData[1] == -0x11)))) {
    bVar1 = sfxFileData[2];
    sound = (ObjectPeriodicSound *)(sfxFileData + 4);
    iVar4 = 0;
    if (bVar1 != 0) {
      do {
        bVar2 = sound->type;
        if (bVar2 == 1) {
          processEventSound(position,soundInstTbl,(ObjectEventSound *)sound);
LAB_8003f390:
          iVar3 = (uint)sound->numSfxIDs * 2 + 0xe;
LAB_8003f3a0:
          sound = (ObjectPeriodicSound *)(&sound->type + iVar3);
        }
        else {
          if (bVar2 < 2) {
            if (bVar2 == 0) {
              processPeriodicSound(position,livesInOnePlace,inSpectral,hidden,soundInstTbl,sound);
              iVar3 = (uint)sound->numSfxIDs * 2 + 0x12;
              goto LAB_8003f3a0;
            }
          }
          else {
            if (bVar2 < 5) {
              processOneShotSound(position,hidden,triggerFlags,soundInstTbl,
                                  (ObjectOneShotSound *)sound);
              goto LAB_8003f390;
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
 // line 154, offset 0x8003f3e8
	/* begin block 1 */
		// Start line: 155
		// Start offset: 0x8003F3E8
		// Variables:
	// 		int numSounds; // $s3
	// 		int numSfxIDs; // $v0
	// 		int i; // $s2
	// 		struct SoundEffectChannel *channel; // $v0
	/* end block 1 */
	// End offset: 0x8003F534
	// End Line: 216

	/* begin block 2 */
		// Start line: 346
	/* end block 2 */
	// End Line: 347

void SOUND_EndInstanceSounds(uchar *sfxFileData,SoundInstance *soundInstTbl)

{
  byte bVar1;
  byte bVar2;
  SoundEffectChannel *pSVar3;
  byte *pbVar4;
  int iVar5;
  
  if ((((sfxFileData != (uchar *)0x0) && (soundInstTbl != (SoundInstance *)0x0)) &&
      (*sfxFileData == -0x42)) && (sfxFileData[1] == -0x11)) {
    bVar1 = sfxFileData[2];
    pbVar4 = sfxFileData + 4;
    iVar5 = 0;
    if (bVar1 != 0) {
      do {
        bVar2 = *pbVar4;
        if (bVar2 == 1) {
          pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0xe;
          pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
          if (pSVar3 != (SoundEffectChannel *)0x0) {
            SndEndLoop(pSVar3->handle);
LAB_8003f50c:
            SndCloseSfxChannel((uint)soundInstTbl->channel);
            soundInstTbl->channel = -1;
            soundInstTbl->state = '\0';
          }
        }
        else {
          if (bVar2 < 2) {
            if (bVar2 == 0) {
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0x12;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0) {
                SndEndLoop(pSVar3->handle);
                goto LAB_8003f50c;
              }
            }
          }
          else {
            if (bVar2 < 5) {
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0xe;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0) goto LAB_8003f50c;
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
// int /*$ra*/ isOkayToPlaySound(int flags /*$s0*/, int spectralPlane /*$s1*/, int hidden /*$s2*/)
 // line 223, offset 0x8003f554
	/* begin block 1 */
		// Start line: 224
		// Start offset: 0x8003F554

		/* begin block 1.1 */
			// Start line: 229
			// Start offset: 0x8003F57C
			// Variables:
		// 		int mask; // $v0
		// 		int tod; // $v1
		/* end block 1.1 */
		// End offset: 0x8003F5F0
		// End Line: 250
	/* end block 1 */
	// End offset: 0x8003F630
	// End Line: 261

	/* begin block 2 */
		// Start line: 525
	/* end block 2 */
	// End Line: 526

int isOkayToPlaySound(int flags,int spectralPlane,int hidden)

{
  int iVar1;
  uint uVar2;
  
  if ((flags & 0xfU) == 0) goto LAB_8003f5f0;
  iVar1 = GAMELOOP_GetTimeOfDay();
  if (iVar1 == 700) {
    uVar2 = 2;
LAB_8003f5e4:
    uVar2 = flags & uVar2;
  }
  else {
    if (700 < iVar1) {
      if (iVar1 == 0x708) {
        uVar2 = 4;
      }
      else {
        if (iVar1 != 0x76c) {
          uVar2 = flags & 2;
          goto LAB_8003f5e8;
        }
        uVar2 = 8;
      }
      goto LAB_8003f5e4;
    }
    if (iVar1 == 600) {
      uVar2 = 1;
      goto LAB_8003f5e4;
    }
    uVar2 = flags & 2;
  }
LAB_8003f5e8:
  if (uVar2 == 0) {
    return 0;
  }
LAB_8003f5f0:
  if (((((flags & 0x10U) == 0) || (iVar1 = 0, spectralPlane != 0)) &&
      (((flags & 0x20U) == 0 || (iVar1 = 0, spectralPlane == 0)))) &&
     ((iVar1 = 1, (flags & 0x40U) != 0 && (iVar1 = 0, hidden == 0)))) {
    iVar1 = 1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ setPeriodicSoundStateOff(struct SoundInstance *soundInst /*$s0*/, struct ObjectPeriodicSound *sound /*$s1*/)
 // line 268, offset 0x8003f648
	/* begin block 1 */
		// Start line: 615
	/* end block 1 */
	// End Line: 616

void setPeriodicSoundStateOff(SoundInstance *soundInst,ObjectPeriodicSound *sound)

{
  int iVar1;
  
  SndCloseSfxChannel((uint)soundInst->channel);
  soundInst->channel = -1;
  soundInst->state = '\x03';
  soundInst->delay = sound->offTime;
  if (sound->offTimeVariation != '\0') {
    iVar1 = rand();
    soundInst->delay =
         soundInst->delay +
         (sound->offTimeVariation - (char)(iVar1 % ((uint)sound->offTimeVariation << 1)));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processPeriodicSound(struct _Position *position /*$s7*/, int livesInOnePlane /*$s4*/, int inSpectral /*$s5*/, int hidden /*$s6*/, struct SoundInstance *soundInst /*stack 16*/, struct ObjectPeriodicSound *sound /*stack 20*/)
 // line 282, offset 0x8003f6d4
	/* begin block 1 */
		// Start line: 283
		// Start offset: 0x8003F6D4
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		int spectralPlane; // $s2
	/* end block 1 */
	// End offset: 0x8003FB34
	// End Line: 445

	/* begin block 2 */
		// Start line: 643
	/* end block 2 */
	// End Line: 644

void processPeriodicSound
               (_Position *position,int livesInOnePlane,int inSpectral,int hidden,
               SoundInstance *soundInst,ObjectPeriodicSound *sound)

{
  uchar uVar1;
  SoundEffectChannel *pSVar2;
  ulong uVar3;
  int iVar4;
  byte bVar5;
  int spectralPlane;
  
  spectralPlane = (int)gameTrackerX.gameData.asmData.MorphType;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 == 1) {
LAB_8003f780:
    if (livesInOnePlane != 0) {
      if (inSpectral == 0) {
        if (spectralPlane != 0) {
          return;
        }
      }
      else {
        if (spectralPlane == 0) {
          return;
        }
      }
    }
    spectralPlane = isOkayToPlaySound((uint)sound->flags,spectralPlane,hidden);
    if (spectralPlane == 0) {
      return;
    }
    if (soundInst->delay != '\0') {
      soundInst->delay = soundInst->delay + -1;
      return;
    }
    pSVar2 = SndOpenSfxChannel((uchar *)soundInst);
    if (pSVar2 == (SoundEffectChannel *)0x0) {
      return;
    }
    pSVar2->volume = (ushort)sound->maxVolume;
    if (sound->maxVolVariation != '\0') {
      spectralPlane = rand();
      pSVar2->volume =
           pSVar2->volume +
           ((ushort)sound->maxVolVariation -
           (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
    }
    pSVar2->pitch = sound->pitch;
    if (sound->pitchVariation != 0) {
      spectralPlane = rand();
      pSVar2->pitch =
           pSVar2->pitch +
           (sound->pitchVariation - (short)(spectralPlane % ((uint)sound->pitchVariation << 1)));
    }
    if (sound->numSfxIDs < 2) {
      spectralPlane = 0;
    }
    else {
      spectralPlane = rand();
      spectralPlane = spectralPlane % (uint)sound->numSfxIDs << 1;
    }
    uVar3 = SOUND_Play3dSound(position,(uint)*(ushort *)(&sound[1].type + spectralPlane),
                              (int)pSVar2->pitch,(int)pSVar2->volume,(uint)sound->minVolDistance);
    pSVar2->handle = uVar3;
    if (uVar3 == 0) {
      SndCloseSfxChannel((uint)soundInst->channel);
      soundInst->channel = -1;
      return;
    }
    soundInst->state = '\x02';
    soundInst->delay = sound->onTime;
    if (sound->onTimeVariation == '\0') {
      return;
    }
    spectralPlane = rand();
    bVar5 = sound->onTimeVariation;
    goto LAB_8003f918;
  }
  if (1 < bVar5) {
    if (bVar5 == 2) {
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      iVar4 = SndIsPlayingOrRequested(pSVar2->handle);
      if (iVar4 == 0) goto LAB_8003fb1c;
      iVar4 = SndIsPlaying(pSVar2->handle);
      if (iVar4 == 0) {
        return;
      }
      if (livesInOnePlane == 0) {
LAB_8003f9ac:
        spectralPlane = isOkayToPlaySound((uint)sound->flags,spectralPlane,hidden);
        if (spectralPlane != 0) {
          uVar1 = soundInst->delay + -1;
          if (soundInst->delay == '\0') {
            if (sound->offTime == '\0') {
              if (sound->maxVolVariation != '\0') {
                pSVar2->volume = (ushort)sound->maxVolume;
                spectralPlane = rand();
                pSVar2->volume =
                     pSVar2->volume +
                     ((ushort)sound->maxVolVariation -
                     (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
              }
              if (sound->pitchVariation != 0) {
                pSVar2->pitch = sound->pitch;
                spectralPlane = rand();
                pSVar2->pitch =
                     pSVar2->pitch +
                     (sound->pitchVariation -
                     (short)(spectralPlane % ((uint)sound->pitchVariation << 1)));
              }
              soundInst->delay = sound->onTime;
              if (sound->onTimeVariation != '\0') {
                spectralPlane = rand();
                uVar1 = soundInst->delay +
                        (sound->onTimeVariation -
                        (char)(spectralPlane % ((uint)sound->onTimeVariation << 1)));
                goto LAB_8003facc;
              }
            }
            else {
              SndEndLoop(pSVar2->handle);
              setPeriodicSoundStateOff(soundInst,sound);
            }
          }
          else {
LAB_8003facc:
            soundInst->delay = uVar1;
          }
          bVar5 = soundInst->state;
          if ((bVar5 & 0x10) == 0) {
            soundInst->state = bVar5 | 0x10;
            return;
          }
          soundInst->state = bVar5 & 0xef;
          uVar3 = SOUND_Update3dSound(position,pSVar2->handle,(int)pSVar2->pitch,(int)pSVar2->volume
                                      ,(uint)sound->minVolDistance);
          if (uVar3 != 0) {
            return;
          }
        }
      }
      else {
        if (inSpectral == 0) {
          if (spectralPlane == 0) goto LAB_8003f9ac;
        }
        else {
          if (spectralPlane != 0) goto LAB_8003f9ac;
        }
      }
      SndEndLoop(pSVar2->handle);
LAB_8003fb1c:
      setPeriodicSoundStateOff(soundInst,sound);
      return;
    }
    if (bVar5 == 3) goto LAB_8003f780;
  }
  soundInst->channel = -1;
  soundInst->state = '\x01';
  soundInst->delay = sound->initialDelay;
  if (sound->initialDelayVariation == '\0') {
    return;
  }
  spectralPlane = rand();
  bVar5 = sound->initialDelayVariation;
LAB_8003f918:
  soundInst->delay = soundInst->delay + (bVar5 - (char)(spectralPlane % ((uint)bVar5 << 1)));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processEventSound(struct _Position *position /*$s5*/, struct SoundInstance *soundInst /*$s1*/, struct ObjectEventSound *sound /*$s3*/)
 // line 451, offset 0x8003fb60
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x8003FB60
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		int spectralPlane; // $s4
	/* end block 1 */
	// End offset: 0x8003FED8
	// End Line: 566

	/* begin block 2 */
		// Start line: 990
	/* end block 2 */
	// End Line: 991

void processEventSound(_Position *position,SoundInstance *soundInst,ObjectEventSound *sound)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  ulong uVar4;
  byte bVar5;
  int spectralPlane;
  
  spectralPlane = (int)gameTrackerX.gameData.asmData.MorphType;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 != 1) {
    if ((bVar5 < 2) || (bVar5 != 2)) {
      soundInst->channel = -1;
      soundInst->state = '\x01';
      soundInst->delay = '\0';
    }
    else {
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      if (pSVar2 == (SoundEffectChannel *)0x0) {
        spectralPlane = isOkayToPlaySound((uint)sound->flags,spectralPlane,0);
        if (spectralPlane == 0) {
          return;
        }
        pSVar2 = SndOpenSfxChannel((uchar *)soundInst);
        if (pSVar2 == (SoundEffectChannel *)0x0) {
          return;
        }
        pSVar2->volume = (ushort)sound->maxVolume;
        if (sound->maxVolVariation != '\0') {
          spectralPlane = rand();
          pSVar2->volume =
               pSVar2->volume +
               ((ushort)sound->maxVolVariation -
               (short)(spectralPlane % ((uint)sound->maxVolVariation << 1)));
        }
        pSVar2->pitch = sound->pitch;
        if (sound->pitchVariation != 0) {
          spectralPlane = rand();
          pSVar2->pitch =
               pSVar2->pitch +
               (sound->pitchVariation - (short)(spectralPlane % ((uint)sound->pitchVariation << 1)))
          ;
        }
        if (sound->numSfxIDs < 2) {
          spectralPlane = 0;
        }
        else {
          spectralPlane = rand();
          spectralPlane = spectralPlane % (uint)sound->numSfxIDs << 1;
        }
        uVar4 = SOUND_Play3dSound(position,(uint)*(ushort *)(&sound[1].type + spectralPlane),
                                  (int)pSVar2->pitch,(int)pSVar2->volume,(uint)sound->minVolDistance
                                 );
        pSVar2->handle = uVar4;
        if (uVar4 != 0) {
          return;
        }
      }
      else {
        iVar3 = SndIsPlayingOrRequested(pSVar2->handle);
        if (iVar3 == 0) {
          SndCloseSfxChannel((uint)soundInst->channel);
          soundInst->channel = -1;
          soundInst->state = '\x01';
          return;
        }
        iVar3 = SndIsPlaying(pSVar2->handle);
        if (iVar3 == 0) {
          return;
        }
        if (pSVar2->pitchChangeTime != 0) {
          sVar1 = pSVar2->pitchChangeError + pSVar2->pitchChangeErrPerUpdate;
          pSVar2->pitchChangeError = sVar1;
          pSVar2->pitch = pSVar2->pitch + pSVar2->pitchChangePerUpdate;
          if (pSVar2->pitchChangeTimeSave <= sVar1) {
            pSVar2->pitch = pSVar2->pitch + pSVar2->pitchChangeSign;
            pSVar2->pitchChangeError = pSVar2->pitchChangeError - pSVar2->pitchChangeTimeSave;
          }
          pSVar2->pitchChangeTime = pSVar2->pitchChangeTime + -1;
        }
        if (pSVar2->volumeChangeTime != 0) {
          sVar1 = pSVar2->volumeChangeError + pSVar2->volumeChangeErrPerUpdate;
          pSVar2->volumeChangeError = sVar1;
          pSVar2->volume = pSVar2->volume + pSVar2->volumeChangePerUpdate;
          if (pSVar2->volumeChangeTimeSave <= sVar1) {
            pSVar2->volume = pSVar2->volume + pSVar2->volumeChangeSign;
            pSVar2->volumeChangeError = pSVar2->volumeChangeError - pSVar2->volumeChangeTimeSave;
          }
          pSVar2->volumeChangeTime = pSVar2->volumeChangeTime + -1;
        }
        bVar5 = soundInst->state;
        if ((bVar5 & 0x10) == 0) {
          soundInst->state = bVar5 | 0x10;
        }
        else {
          soundInst->state = bVar5 & 0xef;
          uVar4 = SOUND_Update3dSound(position,pSVar2->handle,(int)pSVar2->pitch,(int)pSVar2->volume
                                      ,(uint)sound->minVolDistance);
          if (uVar4 == 0) {
            SndEndLoop(pSVar2->handle);
            SndCloseSfxChannel((uint)soundInst->channel);
            soundInst->channel = -1;
          }
        }
        spectralPlane = isOkayToPlaySound((uint)sound->flags,spectralPlane,0);
        if (spectralPlane != 0) {
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
 // line 568, offset 0x8003fefc
	/* begin block 1 */
		// Start line: 1245
	/* end block 1 */
	// End Line: 1246

	/* begin block 2 */
		// Start line: 1246
	/* end block 2 */
	// End Line: 1247

void SOUND_StartInstanceSound(SoundInstance *soundInst)

{
  if ((soundInst->state & 0xf) == 1) {
    soundInst->state = '\x02';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_StopInstanceSound(struct SoundInstance *soundInst /*$s0*/)
 // line 575, offset 0x8003ff1c
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8003FF1C
		// Variables:
	// 		struct SoundEffectChannel *channel; // $v0
	/* end block 1 */
	// End offset: 0x8003FF60
	// End Line: 587

	/* begin block 2 */
		// Start line: 1259
	/* end block 2 */
	// End Line: 1260

void SOUND_StopInstanceSound(SoundInstance *soundInst)

{
  SoundEffectChannel *pSVar1;
  
  pSVar1 = SndGetSfxChannel((uint)soundInst->channel);
  if (pSVar1 != (SoundEffectChannel *)0x0) {
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
 // line 596, offset 0x8003ff78
	/* begin block 1 */
		// Start line: 597
		// Start offset: 0x8003FF78
		// Variables:
	// 		unsigned short *sfxIDList; // $s1
	// 		int numSounds; // $a3
	// 		int numSfxIDs; // $s0
	// 		int i; // $a2
	// 		int status; // $v0
	/* end block 1 */
	// End offset: 0x8004005C
	// End Line: 654

	/* begin block 2 */
		// Start line: 1301
	/* end block 2 */
	// End Line: 1302

int SOUND_IsInstanceSoundLoaded(uchar *sfxFileData,long soundNumber)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  
  if (((sfxFileData != (uchar *)0x0) && (*sfxFileData == -0x42)) && (sfxFileData[1] == -0x11)) {
    pbVar4 = sfxFileData + 4;
    iVar5 = 0;
    if (sfxFileData[2] != 0) {
      do {
        bVar1 = *pbVar4;
        if (((bVar1 == 1) || (1 < bVar1)) || (puVar7 = (ushort *)(pbVar4 + 0x12), bVar1 != 0)) {
          uVar6 = (uint)pbVar4[1];
          puVar7 = (ushort *)(pbVar4 + 0xe);
          iVar3 = uVar6 * 2 + 0xe;
        }
        else {
          uVar6 = (uint)pbVar4[1];
          iVar3 = uVar6 * 2 + 0x12;
        }
        pbVar4 = pbVar4 + iVar3;
        if (iVar5 == soundNumber) {
          while( true ) {
            uVar6 = uVar6 - 1;
            if (uVar6 == 0xffffffff) {
              return 1;
            }
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            iVar5 = aadIsSfxLoaded((uint)uVar2);
            if (iVar5 == 0) break;
            if (iVar5 == -1) {
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
 // line 667, offset 0x80040074
	/* begin block 1 */
		// Start line: 668
		// Start offset: 0x80040074
		// Variables:
	// 		struct SoundEffectChannel *channel; // $a0
	/* end block 1 */
	// End offset: 0x80040120
	// End Line: 689

	/* begin block 2 */
		// Start line: 1478
	/* end block 2 */
	// End Line: 1479

void SOUND_SetInstanceSoundPitch(SoundInstance *soundInst,long pitchChangeAmt,long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  
  if (((soundInst->state & 0xf) == 2) &&
     (pSVar2 = SndGetSfxChannel((uint)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0)) {
    if (time < 0) {
      time = -time;
    }
    if (time == 0) {
      pSVar2->pitchChangeTime = 0;
      pSVar2->pitch = pSVar2->pitch + (short)pitchChangeAmt;
    }
    else {
      pSVar2->pitchChangePerUpdate = (short)(pitchChangeAmt / time);
      if (pitchChangeAmt < 0) {
        sVar1 = -1;
      }
      else {
        sVar1 = 1;
      }
      pSVar2->pitchChangeSign = sVar1;
      sVar1 = (short)(pitchChangeAmt % time);
      pSVar2->pitchChangeError = 0;
      pSVar2->pitchChangeTime = (short)time;
      pSVar2->pitchChangeTimeSave = (short)time;
      if (pitchChangeAmt % time < 0) {
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
 // line 696, offset 0x80040134
	/* begin block 1 */
		// Start line: 697
		// Start offset: 0x80040134
		// Variables:
	// 		struct SoundEffectChannel *channel; // $a0
	/* end block 1 */
	// End offset: 0x80040224
	// End Line: 722

	/* begin block 2 */
		// Start line: 1539
	/* end block 2 */
	// End Line: 1540

void SOUND_SetInstanceSoundVolume(SoundInstance *soundInst,long volumeChangeAmt,long time)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  
  if (((soundInst->state & 0xf) == 2) &&
     (pSVar2 = SndGetSfxChannel((uint)soundInst->channel), pSVar2 != (SoundEffectChannel *)0x0)) {
    if (time < 0) {
      time = -time;
    }
    if ((0 < volumeChangeAmt) && (0x7f < (int)pSVar2->volume + volumeChangeAmt)) {
      volumeChangeAmt = 0x7f - (int)pSVar2->volume;
    }
    if ((volumeChangeAmt < 0) && ((int)pSVar2->volume + volumeChangeAmt < 0)) {
      volumeChangeAmt = -(int)pSVar2->volume;
    }
    if (time == 0) {
      pSVar2->volumeChangeTime = 0;
      pSVar2->volume = pSVar2->volume + (short)volumeChangeAmt;
    }
    else {
      pSVar2->volumeChangePerUpdate = (short)(volumeChangeAmt / time);
      if (volumeChangeAmt < 0) {
        sVar1 = -1;
      }
      else {
        sVar1 = 1;
      }
      pSVar2->volumeChangeSign = sVar1;
      sVar1 = (short)(volumeChangeAmt % time);
      pSVar2->volumeChangeError = 0;
      pSVar2->volumeChangeTime = (short)time;
      pSVar2->volumeChangeTimeSave = (short)time;
      if (volumeChangeAmt % time < 0) {
        sVar1 = -sVar1;
      }
      pSVar2->volumeChangeErrPerUpdate = sVar1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processOneShotSound(struct _Position *position /*$s6*/, int hidden /*$t0*/, long *triggerFlags /*$s4*/, struct SoundInstance *soundInst /*$s2*/, struct ObjectOneShotSound *sound /*stack 16*/)
 // line 742, offset 0x80040238
	/* begin block 1 */
		// Start line: 743
		// Start offset: 0x80040238
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		long triggerMask; // $s3
	// 		int spectralPlane; // $a1
	/* end block 1 */
	// End offset: 0x80040558
	// End Line: 849

	/* begin block 2 */
		// Start line: 1467
	/* end block 2 */
	// End Line: 1468

void processOneShotSound(_Position *position,int hidden,long *triggerFlags,SoundInstance *soundInst,
                        ObjectOneShotSound *sound)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  ulong uVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = soundInst->state & 0xf;
  uVar5 = (&objectOneShotTriggerTbl)[(uint)sound->type - 2];
  if (bVar4 == 1) {
    if ((*triggerFlags & uVar5) == 0) {
      return;
    }
    iVar2 = isOkayToPlaySound((uint)sound->flags,(int)gameTrackerX.gameData.asmData.MorphType,hidden
                             );
    if (iVar2 == 0) {
LAB_8004041c:
      *triggerFlags = *triggerFlags & ~uVar5;
      return;
    }
    soundInst->delay = sound->initialDelay;
    if (sound->initialDelayVariation != '\0') {
      iVar2 = rand();
      soundInst->delay =
           soundInst->delay +
           (sound->initialDelayVariation - (char)(iVar2 % ((uint)sound->initialDelayVariation << 1))
           );
    }
    if (soundInst->delay != '\0') {
      soundInst->state = '\x02';
      return;
    }
LAB_80040370:
    soundInst->state = '\x03';
  }
  else {
    if (1 < bVar4) {
      if (bVar4 == 2) {
        if (soundInst->delay != '\0') {
          soundInst->delay = soundInst->delay + -1;
          return;
        }
        goto LAB_80040370;
      }
      if (bVar4 == 3) {
        pSVar1 = SndGetSfxChannel((uint)soundInst->channel);
        if (pSVar1 == (SoundEffectChannel *)0x0) {
          pSVar1 = SndOpenSfxChannel((uchar *)soundInst);
          if (pSVar1 == (SoundEffectChannel *)0x0) {
            return;
          }
          pSVar1->volume = (ushort)sound->maxVolume;
          if (sound->maxVolVariation != '\0') {
            iVar2 = rand();
            pSVar1->volume =
                 pSVar1->volume +
                 ((ushort)sound->maxVolVariation -
                 (short)(iVar2 % ((uint)sound->maxVolVariation << 1)));
          }
          pSVar1->pitch = sound->pitch;
          if (sound->pitchVariation != 0) {
            iVar2 = rand();
            pSVar1->pitch =
                 pSVar1->pitch +
                 (sound->pitchVariation - (short)(iVar2 % ((uint)sound->pitchVariation << 1)));
          }
          if (sound->numSfxIDs < 2) {
            iVar2 = 0;
          }
          else {
            iVar2 = rand();
            iVar2 = iVar2 % (uint)sound->numSfxIDs << 1;
          }
          uVar3 = SOUND_Play3dSound(position,(uint)*(ushort *)(&sound[1].type + iVar2),
                                    (int)pSVar1->pitch,(int)pSVar1->volume,
                                    (uint)sound->minVolDistance);
          pSVar1->handle = uVar3;
          if (uVar3 != 0) {
            return;
          }
          SndCloseSfxChannel((uint)soundInst->channel);
          soundInst->channel = -1;
          return;
        }
        iVar2 = SndIsPlayingOrRequested(pSVar1->handle);
        if (iVar2 != 0) {
          iVar2 = SndIsPlaying(pSVar1->handle);
          if (iVar2 == 0) {
            return;
          }
          bVar4 = soundInst->state;
          if ((bVar4 & 0x10) == 0) {
            soundInst->state = bVar4 | 0x10;
            return;
          }
          soundInst->state = bVar4 & 0xef;
          uVar3 = SOUND_Update3dSound(position,pSVar1->handle,(int)pSVar1->pitch,(int)pSVar1->volume
                                      ,(uint)sound->minVolDistance);
          if (uVar3 != 0) {
            return;
          }
          SndEndLoop(pSVar1->handle);
        }
        SndCloseSfxChannel((uint)soundInst->channel);
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



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SOUND_Play3dSound(struct _Position *position /*$t0*/, int sfxToneID /*$s5*/, int pitch /*$s6*/, int maxVolume /*$s4*/, int minVolDist /*stack 16*/)
 // line 864, offset 0x80040580
	/* begin block 1 */
		// Start line: 865
		// Start offset: 0x80040580
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
	// End offset: 0x80040780
	// End Line: 953

	/* begin block 2 */
		// Start line: 1875
	/* end block 2 */
	// End Line: 1876

ulong SOUND_Play3dSound(_Position *position,int sfxToneID,int pitch,int maxVolume,int minVolDist)

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
  
  if (maxVolume == 0) {
    return 0;
  }
  if ((theCamera.mode == 5) && ((gameTrackerX.gameFlags & 0x10U) != 0)) {
    sVar1 = position->z;
    uVar7 = (int)position->x - (int)theCamera.core.position.x;
    uVar6 = (int)position->y - (int)theCamera.core.position.y;
    sVar2 = theCamera.core.position.z;
  }
  else {
    uVar7 = (int)position->x - (int)((theCamera.focusInstance)->position).x;
    sVar1 = position->z;
    sVar2 = ((theCamera.focusInstance)->position).z;
    uVar6 = (int)position->y - (int)((theCamera.focusInstance)->position).y;
  }
  lVar3 = MATH3D_FastSqrt0(uVar7 * uVar7 + uVar6 * uVar6 +
                           ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
  if (minVolDist < lVar3) {
    return 0;
  }
  iVar4 = ratan2(uVar6,uVar7);
  _vol = (minVolDist - lVar3) / (minVolDist / maxVolume);
  vol = (ushort)_vol;
  uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
  uVar7 = (int)(uVar6 & 0xfff) >> 10;
  if (0x7f < _vol) {
    vol = 0x7f;
  }
  iVar4 = (int)(uVar6 & 0x3ff) >> 4;
  if (uVar7 == 1) goto LAB_80040718;
  if (uVar7 < 2) {
    if (uVar7 != 0) goto LAB_80040710;
    _vol = 0x3f;
  }
  else {
    if (uVar7 == 2) {
      iVar4 = iVar4 + 0x40;
      goto LAB_80040718;
    }
LAB_80040710:
    _vol = 0x7f;
  }
  iVar4 = _vol - iVar4;
LAB_80040718:
  minVolDist = (lVar3 << 8) / minVolDist;
  if (iVar4 < 0x40) {
    pan = 0x3f - (short)((uint)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else {
    pan = (short)((uint)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
  uVar5 = SndPlayVolPan(sfxToneID,vol,pan,(short)pitch);
  return uVar5;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SOUND_Update3dSound(struct _Position *position /*$t0*/, unsigned long handle /*$s5*/, int pitch /*$s6*/, int maxVolume /*$s4*/, int minVolDist /*stack 16*/)
 // line 959, offset 0x800407a8
	/* begin block 1 */
		// Start line: 960
		// Start offset: 0x800407A8
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
	// End offset: 0x800409A8
	// End Line: 1048

	/* begin block 2 */
		// Start line: 2078
	/* end block 2 */
	// End Line: 2079

ulong SOUND_Update3dSound(_Position *position,ulong handle,int pitch,int maxVolume,int minVolDist)

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
  
  if (maxVolume == 0) {
    return 0;
  }
  if ((theCamera.mode == 5) && ((gameTrackerX.gameFlags & 0x10U) != 0)) {
    sVar1 = position->z;
    uVar7 = (int)position->x - (int)theCamera.core.position.x;
    uVar6 = (int)position->y - (int)theCamera.core.position.y;
    sVar2 = theCamera.core.position.z;
  }
  else {
    uVar7 = (int)position->x - (int)((theCamera.focusInstance)->position).x;
    sVar1 = position->z;
    sVar2 = ((theCamera.focusInstance)->position).z;
    uVar6 = (int)position->y - (int)((theCamera.focusInstance)->position).y;
  }
  lVar3 = MATH3D_FastSqrt0(uVar7 * uVar7 + uVar6 * uVar6 +
                           ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
  if (minVolDist < lVar3) {
    return 0;
  }
  iVar4 = ratan2(uVar6,uVar7);
  _vol = (minVolDist - lVar3) / (minVolDist / maxVolume);
  vol = (ushort)_vol;
  uVar6 = (int)theCamera.core.rotation.z - (iVar4 + 0x400);
  uVar7 = (int)(uVar6 & 0xfff) >> 10;
  if (0x7f < _vol) {
    vol = 0x7f;
  }
  iVar4 = (int)(uVar6 & 0x3ff) >> 4;
  if (uVar7 == 1) goto LAB_80040940;
  if (uVar7 < 2) {
    if (uVar7 != 0) goto LAB_80040938;
    _vol = 0x3f;
  }
  else {
    if (uVar7 == 2) {
      iVar4 = iVar4 + 0x40;
      goto LAB_80040940;
    }
LAB_80040938:
    _vol = 0x7f;
  }
  iVar4 = _vol - iVar4;
LAB_80040940:
  minVolDist = (lVar3 << 8) / minVolDist;
  if (iVar4 < 0x40) {
    pan = 0x3f - (short)((uint)((0x3f - iVar4) * minVolDist) >> 8);
  }
  else {
    pan = (short)((uint)((iVar4 + -0x40) * minVolDist) >> 8) + 0x40;
  }
  uVar5 = SndUpdateVolPanPitch(handle,vol,pan,(short)pitch);
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_HandleGlobalValueSignal(int name /*$a0*/, long data /*$a1*/)
 // line 1081, offset 0x800409d0
	/* begin block 1 */
		// Start line: 2158
	/* end block 1 */
	// End Line: 2159

	/* begin block 2 */
		// Start line: 2302
	/* end block 2 */
	// End Line: 2303

void SOUND_HandleGlobalValueSignal(int name,long data)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_Init()
 // line 1094, offset 0x800409d8
	/* begin block 1 */
		// Start line: 1095
		// Start offset: 0x800409D8
		// Variables:
	// 		struct AadInitAttr initAttr; // stack offset -32
	/* end block 1 */
	// End offset: 0x800409D8
	// End Line: 1095

	/* begin block 2 */
		// Start line: 2327
	/* end block 2 */
	// End Line: 2328

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
  aadInit(&local_20,(uchar *)&soundBuffer);
  gameTrackerX.sound.gMasterVol = 0x3fff;
  SOUND_SetMusicVolume(0x50);
  SOUND_SetSfxVolume(0x7f);
  SOUND_SetVoiceVolume(0x4b);
  gameTrackerX.sound.gSfxOn = '\x01';
  gameTrackerX.sound.gMusicOn = '\x01';
  gameTrackerX.sound.gVoiceOn = '\x01';
  gameTrackerX.sound.soundsLoaded = '\0';
  currentDynamicSoundName = '\0';
  aadInitReverb();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_Free()
 // line 1188, offset 0x80040a88
	/* begin block 1 */
		// Start line: 2557
	/* end block 1 */
	// End Line: 2558

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
 // line 1221, offset 0x80040aac
	/* begin block 1 */
		// Start line: 2438
	/* end block 1 */
	// End Line: 2439

void SOUND_SetMusicVariable(int variable,int value)

{
  aadSetUserVariable(variable,value);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetMusicVolume(int newVolume /*$a0*/)
 // line 1231, offset 0x80040acc
	/* begin block 1 */
		// Start line: 2454
	/* end block 1 */
	// End Line: 2455

void SOUND_SetMusicVolume(int newVolume)

{
  if (newVolume == -1) {
    newVolume = gameTrackerX.sound.gMusicVol;
  }
  gameTrackerX.sound.gMusicVol = newVolume;
  aadSetMusicMasterVolume(newVolume);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetSfxVolume(int newVolume /*$a0*/)
 // line 1238, offset 0x80040b00
	/* begin block 1 */
		// Start line: 2617
	/* end block 1 */
	// End Line: 2618

void SOUND_SetSfxVolume(int newVolume)

{
  if (newVolume == -1) {
    newVolume = gameTrackerX.sound.gSfxVol;
  }
  gameTrackerX.sound.gSfxVol = newVolume;
  aadSetSfxMasterVolume(newVolume);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetVoiceVolume(int newVolume /*$a0*/)
 // line 1245, offset 0x80040b34
	/* begin block 1 */
		// Start line: 2631
	/* end block 1 */
	// End Line: 2632

	/* begin block 2 */
		// Start line: 2632
	/* end block 2 */
	// End Line: 2633

void SOUND_SetVoiceVolume(int newVolume)

{
  if (newVolume == -1) {
    newVolume = gameTrackerX.sound.gVoiceVol;
  }
  gameTrackerX.sound.gVoiceVol = newVolume;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_PauseAllSound()
 // line 1261, offset 0x80040b54
	/* begin block 1 */
		// Start line: 2510
	/* end block 1 */
	// End Line: 2511

	/* begin block 2 */
		// Start line: 2650
	/* end block 2 */
	// End Line: 2651

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_PauseAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0') {
    aadShutdownReverb();
    aadPauseSound();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_ResumeAllSound()
 // line 1270, offset 0x80040b84
	/* begin block 1 */
		// Start line: 2668
	/* end block 1 */
	// End Line: 2669

	/* begin block 2 */
		// Start line: 2669
	/* end block 2 */
	// End Line: 2670

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ResumeAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0') {
    aadInitReverb();
    aadResumeSound();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_StopAllSound()
 // line 1279, offset 0x80040bb4
	/* begin block 1 */
		// Start line: 2687
	/* end block 1 */
	// End Line: 2688

	/* begin block 2 */
		// Start line: 2688
	/* end block 2 */
	// End Line: 2689

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_StopAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0') {
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
 // line 1290, offset 0x80040bf4
	/* begin block 1 */
		// Start line: 2710
	/* end block 1 */
	// End Line: 2711

	/* begin block 2 */
		// Start line: 2711
	/* end block 2 */
	// End Line: 2712

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ResetAllSound(void)

{
  if (gameTrackerX.sound.soundsLoaded != '\0') {
    SOUND_StopAllSound();
    aadInitReverb();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_MusicOff()
 // line 1299, offset 0x80040c24
	/* begin block 1 */
		// Start line: 1300
		// Start offset: 0x80040C24
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80040C74
	// End Line: 1315

	/* begin block 2 */
		// Start line: 2729
	/* end block 2 */
	// End Line: 2730

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicOff(void)

{
  int iVar1;
  int slotNumber;
  
  slotNumber = 1;
  do {
    aadDisableSlot(slotNumber);
    iVar1 = aadGetSlotStatus(slotNumber);
    if (iVar1 == 1) {
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
 // line 1317, offset 0x80040c88
	/* begin block 1 */
		// Start line: 1318
		// Start offset: 0x80040C88
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80040CB0
	// End Line: 1323

	/* begin block 2 */
		// Start line: 2781
	/* end block 2 */
	// End Line: 2782

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicOn(void)

{
  int slotNumber;
  
  slotNumber = 1;
  do {
    aadEnableSlot(slotNumber);
    slotNumber = slotNumber + 1;
  } while (slotNumber < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SfxOff()
 // line 1326, offset 0x80040cc0
	/* begin block 1 */
		// Start line: 2803
	/* end block 1 */
	// End Line: 2804

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOff(void)

{
  aadStopAllSfx();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SfxOn()
 // line 1332, offset 0x80040ce0
	/* begin block 1 */
		// Start line: 2815
	/* end block 1 */
	// End Line: 2816

	/* begin block 2 */
		// Start line: 2817
	/* end block 2 */
	// End Line: 2818

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOn(void)

{
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndIsPlaying(unsigned long handle /*$a0*/)
 // line 1354, offset 0x80040ce8
	/* begin block 1 */
		// Start line: 2698
	/* end block 1 */
	// End Line: 2699

int SndIsPlaying(ulong handle)

{
  int iVar1;
  
  iVar1 = aadIsSfxPlaying(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndIsPlayingOrRequested(unsigned long handle /*$a0*/)
 // line 1359, offset 0x80040d08
	/* begin block 1 */
		// Start line: 2849
	/* end block 1 */
	// End Line: 2850

int SndIsPlayingOrRequested(ulong handle)

{
  int iVar1;
  
  iVar1 = aadIsSfxPlayingOrRequested(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndTypeIsPlayingOrRequested(unsigned int sfxToneID /*$a0*/)
 // line 1369, offset 0x80040d28
	/* begin block 1 */
		// Start line: 2724
	/* end block 1 */
	// End Line: 2725

int SndTypeIsPlayingOrRequested(uint sfxToneID)

{
  int iVar1;
  
  iVar1 = aadIsSfxTypePlayingOrRequested(sfxToneID);
  return iVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SndPlay(unsigned int sample /*$a0*/)
 // line 1380, offset 0x80040d48
	/* begin block 1 */
		// Start line: 2741
	/* end block 1 */
	// End Line: 2742

	/* begin block 2 */
		// Start line: 2873
	/* end block 2 */
	// End Line: 2874

ulong SndPlay(uint sample)

{
  ulong uVar1;
  
  if (gameTrackerX.sound.gSfxOn == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = aadPlaySfx(sample,0x5a,0x40,0);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SndEndLoop(unsigned long handle /*$a0*/)
 // line 1388, offset 0x80040d80
	/* begin block 1 */
		// Start line: 2887
	/* end block 1 */
	// End Line: 2888

	/* begin block 2 */
		// Start line: 2891
	/* end block 2 */
	// End Line: 2892

void SndEndLoop(ulong handle)

{
  aadStopSfx(handle);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SndPlayVolPan(unsigned int sample /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
 // line 1393, offset 0x80040da0
	/* begin block 1 */
		// Start line: 1394
		// Start offset: 0x80040DA0
	/* end block 1 */
	// End offset: 0x80040DCC
	// End Line: 1404

	/* begin block 2 */
		// Start line: 2901
	/* end block 2 */
	// End Line: 2902

	/* begin block 3 */
		// Start line: 2904
	/* end block 3 */
	// End Line: 2905

ulong SndPlayVolPan(uint sample,ushort vol,ushort pan,short pitch)

{
  ulong uVar1;
  
  if (gameTrackerX.sound.gSfxOn == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = aadPlaySfx(sample,(uint)vol,(uint)pan,(int)pitch);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SndUpdateVolPanPitch(unsigned long handle /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
 // line 1414, offset 0x80040ddc
	/* begin block 1 */
		// Start line: 2824
	/* end block 1 */
	// End Line: 2825

ulong SndUpdateVolPanPitch(ulong handle,ushort vol,ushort pan,short pitch)

{
  ulong uVar1;
  
  if ((handle == 0) || (gameTrackerX.sound.gSfxOn == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = aadSetSfxVolPanPitch(handle,(uint)vol,(uint)pan,(int)pitch);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ transitionMusicEndCallback(long userData /*$a0*/, int slot /*$a1*/, int loopFlag /*$a2*/)
 // line 1445, offset 0x80040e24
	/* begin block 1 */
		// Start line: 1446
		// Start offset: 0x80040E24
	/* end block 1 */
	// End offset: 0x80040E68
	// End Line: 1464

	/* begin block 2 */
		// Start line: 3001
	/* end block 2 */
	// End Line: 3002

void transitionMusicEndCallback(long userData,int slot,int loopFlag)

{
  int iVar1;
  
  if (slot == 0) {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0,0);
    iVar1 = aadAssignDynamicSequence(0,0,0);
    if (iVar1 == 0) {
      aadStartSlot(0);
    }
    aadFreeDynamicSoundBank(1);
    musicLoadInProgress = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ loadMainMusicReturn(int dynamicBankIndex /*$a0*/, int errorStatus /*$a1*/)
 // line 1469, offset 0x80040e78
	/* begin block 1 */
		// Start line: 3049
	/* end block 1 */
	// End Line: 3050

void loadMainMusicReturn(int dynamicBankIndex,int errorStatus)

{
  if (errorStatus == 0) {
    aadInstallEndSequenceCallback(transitionMusicEndCallback,0);
    aadSetUserVariable(0x7f,1);
  }
  else {
    musicLoadInProgress = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ mainMusicEndCallback(long userData /*$s1*/, int slot /*$a1*/, int loopFlag /*$a2*/)
 // line 1489, offset 0x80040ebc
	/* begin block 1 */
		// Start line: 1490
		// Start offset: 0x80040EBC
		// Variables:
	// 		char sndFileName[32]; // stack offset -80
	// 		char smpFileName[32]; // stack offset -48
	/* end block 1 */
	// End offset: 0x80040F60
	// End Line: 1517

	/* begin block 2 */
		// Start line: 3089
	/* end block 2 */
	// End Line: 3090

void mainMusicEndCallback(long userData,int slot,int loopFlag)

{
  int iVar1;
  char acStack80 [32];
  char acStack48 [32];
  
  if (slot == 0) {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0,0);
    iVar1 = aadAssignDynamicSequence(1,0,0);
    if (iVar1 == 0) {
      aadStartSlot(0);
      sprintf(acStack80,"\\kain2\\music\\%s\\%s.snd");
      sprintf(acStack48,"\\kain2\\music\\%s\\%s.smp");
      aadLoadDynamicSoundBank(acStack80,acStack48,0,1,loadMainMusicReturn);
    }
    else {
      musicLoadInProgress = 0;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ loadTransitionMusicReturn(int dynamicBankIndex /*$a0*/, int errorStatus /*$a1*/)
 // line 1522, offset 0x80040f74
	/* begin block 1 */
		// Start line: 3155
	/* end block 1 */
	// End Line: 3156

void loadTransitionMusicReturn(int dynamicBankIndex,int errorStatus)

{
  if (errorStatus == 0) {
    aadInstallEndSequenceCallback(mainMusicEndCallback,(long)&currentDynamicSoundName);
    aadSetUserVariable(0x7f,1);
  }
  else {
    musicLoadInProgress = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ initialLoadMainMusicReturn(int dynamicBankIndex /*$a0*/, int errorStatus /*$a1*/)
 // line 1540, offset 0x80040fbc
	/* begin block 1 */
		// Start line: 1541
		// Start offset: 0x80040FBC
	/* end block 1 */
	// End offset: 0x80040FE4
	// End Line: 1550

	/* begin block 2 */
		// Start line: 3191
	/* end block 2 */
	// End Line: 3192

void initialLoadMainMusicReturn(int dynamicBankIndex,int errorStatus)

{
  int iVar1;
  
  iVar1 = aadAssignDynamicSequence(0,0,0);
  if (iVar1 == 0) {
    aadStartSlot(0);
  }
  musicLoadInProgress = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ musicFadeoutDone()
 // line 1555, offset 0x80040ff4
	/* begin block 1 */
		// Start line: 3223
	/* end block 1 */
	// End Line: 3224

/* WARNING: Unknown calling convention yet parameter storage is locked */

void musicFadeoutDone(void)

{
  SOUND_FreeDynamicMusic();
  aadStartMusicMasterVolFade
            (gameTrackerX.sound.gMusicVol,1,
             (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_UpdateSound()
 // line 1565, offset 0x80041024
	/* begin block 1 */
		// Start line: 1566
		// Start offset: 0x80041024
		// Variables:
	// 		char musicName[8]; // stack offset -88
	// 		char sndFileName[32]; // stack offset -80
	// 		char smpFileName[32]; // stack offset -48

		/* begin block 1.1 */
			// Start line: 1608
			// Start offset: 0x80041108
			// Variables:
		// 		struct Level *level; // $a0
		/* end block 1.1 */
		// End offset: 0x80041340
		// End Line: 1675
	/* end block 1 */
	// End offset: 0x80041360
	// End Line: 1686

	/* begin block 2 */
		// Start line: 3243
	/* end block 2 */
	// End Line: 3244

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_UpdateSound(void)

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
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined local_36;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined local_16;
  
  aadProcessLoadQueue();
  if (((gameTrackerX.debugFlags & 0x40000U) == 0) &&
     ((gSramFullAlarm != 0 || (gSramFullMsgCnt != 0)))) {
    bVar1 = gSramFullMsgCnt == 0;
    gSramFullMsgCnt = gSramFullMsgCnt + -1;
    if (bVar1) {
      gSramFullMsgCnt = 0x3c;
    }
    FONT_Print("$\n\n\n\n\n\n\n\n\n\nsound memory full!\nu=%d %d f=%d %d lf=%d\n");
  }
  iVar2 = aadGetNumLoadsQueued();
  if ((((iVar2 == 0) && (musicLoadInProgress == 0)) && (gameTrackerX.sound.gMusicOn != '\0')) &&
     (((aadMem->sramDefragInfo).status == 0 &&
      (bVar1 = checkMusicDelay == 0, checkMusicDelay = checkMusicDelay + -1, bVar1)))) {
    checkMusicDelay = 0x1e;
    pLVar3 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    if (reqMusicStartPlaneShift == 0) {
      if (pLVar3->dynamicMusicName == (char *)0x0) {
        if (currentDynamicSoundName != '\0') {
          currentDynamicSoundName = '\0';
          aadStartMusicMasterVolFade(0,-1,musicFadeoutDone);
        }
      }
      else {
        local_58 = *pLVar3->dynamicMusicName;
        local_57 = pLVar3->dynamicMusicName[1];
        if (currentMusicPlane == 0) {
          local_56 = 0x6d;
          local_55 = 0x61;
        }
        else {
          local_56 = 0x73;
          local_55 = 0x70;
        }
        local_54 = 0;
        iVar2 = strcmpi(&local_58,&currentDynamicSoundName);
        if (iVar2 != 0) {
          if (currentDynamicSoundName == '\0') {
            sprintf((char *)&local_50,"\\kain2\\music\\%s\\%s.snd");
            sprintf((char *)&local_30,"\\kain2\\music\\%s\\%s.smp");
            lVar4 = LOAD_DoesFileExist((char *)&local_50);
            if (lVar4 == 0) {
              return;
            }
            aadLoadDynamicSoundBank
                      ((char *)&local_50,(char *)&local_30,0,1,initialLoadMainMusicReturn);
            strcpy(&currentDynamicSoundName,&local_58);
          }
          else {
            sprintf((char *)&local_50,"\\kain2\\music\\%s\\%s.snd");
            lVar4 = LOAD_DoesFileExist((char *)&local_50);
            if (lVar4 == 0) {
              return;
            }
            strcpy(&currentDynamicSoundName,&local_58);
            local_50 = 0x69616b5c;
            local_4c = 0x6d5c326e;
            local_48 = 0x63697375;
            local_44 = 0x7477755c;
            local_40 = 0x77755c72;
            local_3c = 0x732e7274;
            local_38 = 0x646e;
            local_36 = 0;
            local_30 = 0x69616b5c;
            local_2c = 0x6d5c326e;
            local_28 = 0x63697375;
            local_24 = 0x7477755c;
            local_20 = 0x77755c72;
            local_1c = 0x732e7274;
            local_18 = 0x706d;
            local_16 = 0;
            aadLoadDynamicSoundBank
                      ((char *)&local_50,(char *)&local_30,1,0,loadTransitionMusicReturn);
          }
          musicLoadInProgress = 1;
        }
      }
    }
    else {
      reqMusicStartPlaneShift = 0;
      SOUND_PlaneShift(reqMusicNewPlane);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ musicPlaneShiftFadeoutDone()
 // line 1690, offset 0x80041378
	/* begin block 1 */
		// Start line: 3499
	/* end block 1 */
	// End Line: 3500

/* WARNING: Unknown calling convention yet parameter storage is locked */

void musicPlaneShiftFadeoutDone(void)

{
  SOUND_FreeDynamicMusic();
  aadStartMusicMasterVolFade
            (gameTrackerX.sound.gMusicVol,1,
             (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  checkMusicDelay = 0;
  currentMusicPlane = reqMusicNewPlane;
  currentDynamicSoundName = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_PlaneShift(int newPlane /*$s0*/)
 // line 1700, offset 0x800413b4
	/* begin block 1 */
		// Start line: 3516
	/* end block 1 */
	// End Line: 3517

	/* begin block 2 */
		// Start line: 3521
	/* end block 2 */
	// End Line: 3522

	/* begin block 3 */
		// Start line: 3522
	/* end block 3 */
	// End Line: 3523

void SOUND_PlaneShift(int newPlane)

{
  int iVar1;
  
  iVar1 = newPlane;
  if (gameTrackerX.sound.gMusicOn != '\0') {
    iVar1 = aadGetNumLoadsQueued();
    if ((iVar1 == 0) && (musicLoadInProgress == 0)) {
      iVar1 = newPlane;
      if (currentDynamicSoundName != '\0') {
        checkMusicDelay = 300;
        reqMusicNewPlane = newPlane;
        aadStartMusicMasterVolFade(0,-3,musicPlaneShiftFadeoutDone);
        iVar1 = currentMusicPlane;
      }
    }
    else {
      reqMusicStartPlaneShift = 1;
      iVar1 = currentMusicPlane;
      reqMusicNewPlane = newPlane;
    }
  }
  currentMusicPlane = iVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_FreeDynamicMusic()
 // line 1749, offset 0x80041444
	/* begin block 1 */
		// Start line: 3622
	/* end block 1 */
	// End Line: 3623

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_FreeDynamicMusic(void)

{
  int iVar1;
  
  aadStopAllSlots();
  currentDynamicSoundName = '\0';
  musicLoadInProgress = 0;
  iVar1 = aadGetDynamicBankStatus(0);
  if (iVar1 != 0) {
    aadFreeDynamicSoundBank(0);
  }
  iVar1 = aadGetDynamicBankStatus(1);
  if (iVar1 != 0) {
    aadFreeDynamicSoundBank(1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetMusicModifier(long modifier /*$a0*/)
 // line 1769, offset 0x8004149c
	/* begin block 1 */
		// Start line: 3662
	/* end block 1 */
	// End Line: 3663

void SOUND_SetMusicModifier(long modifier)

{
  int variable;
  int value;
  
  switch(modifier) {
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
  SOUND_SetMusicVariable(variable,value);
switchD_800414c4_caseD_7:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_ResetMusicModifier(long modifier /*$a0*/)
 // line 1826, offset 0x8004155c
	/* begin block 1 */
		// Start line: 3776
	/* end block 1 */
	// End Line: 3777

void SOUND_ResetMusicModifier(long modifier)

{
  int variable;
  
  switch(modifier) {
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
  SOUND_SetMusicVariable(variable,0);
switchD_80041584_caseD_7:
  return;
}





