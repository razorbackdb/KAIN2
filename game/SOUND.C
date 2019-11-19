#include "THISDUST.H"
#include "SOUND.H"


// decompiled code
// original method signature: 
// struct SoundEffectChannel * /*$ra*/ SndOpenSfxChannel(unsigned char *channelNum /*$a0*/)
 // line 39, offset 0x8003fbcc
	/* begin block 1 */
		// Start line: 41
		// Start offset: 0x8003FBCC
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8003FC10
	// End Line: 55

	/* begin block 2 */
		// Start line: 78
	/* end block 2 */
	// End Line: 79

	/* begin block 3 */
		// Start line: 79
	/* end block 3 */
	// End Line: 80

	/* begin block 4 */
		// Start line: 81
	/* end block 4 */
	// End Line: 82

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
 // line 58, offset 0x8003fc18
	/* begin block 1 */
		// Start line: 124
	/* end block 1 */
	// End Line: 125

	/* begin block 2 */
		// Start line: 125
	/* end block 2 */
	// End Line: 126

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
 // line 65, offset 0x8003fc44
	/* begin block 1 */
		// Start line: 138
	/* end block 1 */
	// End Line: 139

	/* begin block 2 */
		// Start line: 139
	/* end block 2 */
	// End Line: 140

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
 // line 95, offset 0x8003fc70
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x8003FC70
		// Variables:
	// 		int numSounds; // $s3
	// 		int numSfxIDs; // $v0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8003FDBC
	// End Line: 139

	/* begin block 2 */
		// Start line: 174
	/* end block 2 */
	// End Line: 175

	/* begin block 3 */
		// Start line: 200
	/* end block 3 */
	// End Line: 201

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
LAB_8003fd94:
          iVar3 = (uint)sound->numSfxIDs * 2 + 0xe;
LAB_8003fda4:
          sound = (ObjectPeriodicSound *)(&sound->type + iVar3);
        }
        else {
          if (bVar2 < 2) {
            if (bVar2 == 0) {
              processPeriodicSound(position,livesInOnePlace,inSpectral,hidden,soundInstTbl,sound);
              iVar3 = (uint)sound->numSfxIDs * 2 + 0x12;
              goto LAB_8003fda4;
            }
          }
          else {
            if (bVar2 < 5) {
              processOneShotSound(position,hidden,triggerFlags,soundInstTbl,
                                  (ObjectOneShotSound *)sound);
              goto LAB_8003fd94;
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
// void /*$ra*/ SOUND_EndInstanceSounds(unsigned char *sfxFileData /*$s1*/, struct SoundInstance *soundInstTbl /*$a1*/)
 // line 147, offset 0x8003fdec
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8003FDEC
		// Variables:
	// 		int numSounds; // $s3
	// 		int i; // $s2
	// 		struct SoundEffectChannel *channel; // $v0
	/* end block 1 */
	// End offset: 0x8003FED0
	// End Line: 196

	/* begin block 2 */
		// Start line: 332
	/* end block 2 */
	// End Line: 333

void SOUND_EndInstanceSounds(uchar *sfxFileData,SoundInstance *soundInstTbl)

{
  byte bVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  
  if ((((sfxFileData != (uchar *)0x0) && (soundInstTbl != (SoundInstance *)0x0)) &&
      (*sfxFileData == -0x42)) && (sfxFileData[1] == -0x11)) {
    bVar1 = sfxFileData[2];
    iVar3 = 0;
    if (bVar1 != 0) {
      do {
        if (sfxFileData[4] < 2) {
          pSVar2 = SndGetSfxChannel((uint)soundInstTbl->channel);
          if (pSVar2 != (SoundEffectChannel *)0x0) {
            SndEndLoop(pSVar2->handle);
LAB_8003feac:
            SndCloseSfxChannel((uint)soundInstTbl->channel);
            soundInstTbl->channel = -1;
            soundInstTbl->state = '\0';
          }
        }
        else {
          if ((sfxFileData[4] < 5) &&
             (pSVar2 = SndGetSfxChannel((uint)soundInstTbl->channel),
             pSVar2 != (SoundEffectChannel *)0x0)) goto LAB_8003feac;
        }
        iVar3 = iVar3 + 1;
        soundInstTbl = soundInstTbl + 1;
      } while (iVar3 < (int)(uint)bVar1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ isOkayToPlaySound(int flags /*$s0*/, int spectralPlane /*$s1*/, int hidden /*$s2*/)
 // line 203, offset 0x8003fef0
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x8003FEF0

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x8003FF18
			// Variables:
		// 		int mask; // $v0
		// 		int tod; // $v1
		/* end block 1.1 */
		// End offset: 0x8003FF8C
		// End Line: 230
	/* end block 1 */
	// End offset: 0x8003FFCC
	// End Line: 241

	/* begin block 2 */
		// Start line: 477
	/* end block 2 */
	// End Line: 478

int isOkayToPlaySound(int flags,int spectralPlane,int hidden)

{
  int iVar1;
  uint uVar2;
  
  if ((flags & 0xfU) == 0) goto LAB_8003ff8c;
  iVar1 = GAMELOOP_GetTimeOfDay();
  if (iVar1 == 700) {
    uVar2 = 2;
LAB_8003ff80:
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
          goto LAB_8003ff84;
        }
        uVar2 = 8;
      }
      goto LAB_8003ff80;
    }
    if (iVar1 == 600) {
      uVar2 = 1;
      goto LAB_8003ff80;
    }
    uVar2 = flags & 2;
  }
LAB_8003ff84:
  if (uVar2 == 0) {
    return 0;
  }
LAB_8003ff8c:
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
 // line 248, offset 0x8003ffe4
	/* begin block 1 */
		// Start line: 567
	/* end block 1 */
	// End Line: 568

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
 // line 262, offset 0x80040070
	/* begin block 1 */
		// Start line: 263
		// Start offset: 0x80040070
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		int spectralPlane; // $s2
	/* end block 1 */
	// End offset: 0x800404D0
	// End Line: 425

	/* begin block 2 */
		// Start line: 595
	/* end block 2 */
	// End Line: 596

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
LAB_8004011c:
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
    goto LAB_800402b4;
  }
  if (1 < bVar5) {
    if (bVar5 == 2) {
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      iVar4 = SndIsPlayingOrRequested(pSVar2->handle);
      if (iVar4 == 0) goto LAB_800404b8;
      iVar4 = SndIsPlaying(pSVar2->handle);
      if (iVar4 == 0) {
        return;
      }
      if (livesInOnePlane == 0) {
LAB_80040348:
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
                goto LAB_80040468;
              }
            }
            else {
              SndEndLoop(pSVar2->handle);
              setPeriodicSoundStateOff(soundInst,sound);
            }
          }
          else {
LAB_80040468:
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
          if (spectralPlane == 0) goto LAB_80040348;
        }
        else {
          if (spectralPlane != 0) goto LAB_80040348;
        }
      }
      SndEndLoop(pSVar2->handle);
LAB_800404b8:
      setPeriodicSoundStateOff(soundInst,sound);
      return;
    }
    if (bVar5 == 3) goto LAB_8004011c;
  }
  soundInst->channel = -1;
  soundInst->state = '\x01';
  soundInst->delay = sound->initialDelay;
  if (sound->initialDelayVariation == '\0') {
    return;
  }
  spectralPlane = rand();
  bVar5 = sound->initialDelayVariation;
LAB_800402b4:
  soundInst->delay = soundInst->delay + (bVar5 - (char)(spectralPlane % ((uint)bVar5 << 1)));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processEventSound(struct _Position *position /*$s5*/, struct SoundInstance *soundInst /*$s1*/, struct ObjectEventSound *sound /*$s3*/)
 // line 431, offset 0x800404fc
	/* begin block 1 */
		// Start line: 432
		// Start offset: 0x800404FC
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		int spectralPlane; // $s4
	/* end block 1 */
	// End offset: 0x80040874
	// End Line: 546

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

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
 // line 548, offset 0x80040898
	/* begin block 1 */
		// Start line: 1197
	/* end block 1 */
	// End Line: 1198

	/* begin block 2 */
		// Start line: 1198
	/* end block 2 */
	// End Line: 1199

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
 // line 555, offset 0x800408b8
	/* begin block 1 */
		// Start line: 556
		// Start offset: 0x800408B8
		// Variables:
	// 		struct SoundEffectChannel *channel; // $v0
	/* end block 1 */
	// End offset: 0x800408FC
	// End Line: 567

	/* begin block 2 */
		// Start line: 1211
	/* end block 2 */
	// End Line: 1212

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
 // line 576, offset 0x80040914
	/* begin block 1 */
		// Start line: 577
		// Start offset: 0x80040914
		// Variables:
	// 		unsigned short *sfxIDList; // $s1
	// 		int numSounds; // $a3
	// 		int numSfxIDs; // $s0
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80040A00
	// End Line: 627

	/* begin block 2 */
		// Start line: 1253
	/* end block 2 */
	// End Line: 1254

int SOUND_IsInstanceSoundLoaded(uchar *sfxFileData,long soundNumber)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  
  if ((sfxFileData != (uchar *)0x0) && (*sfxFileData == -0x42)) {
    if (sfxFileData[1] != -0x11) {
      return -1;
    }
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
          do {
            uVar6 = uVar6 - 1;
            if (uVar6 == 0xffffffff) {
              return 1;
            }
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            iVar5 = aadIsSfxLoaded((uint)uVar2);
          } while (iVar5 != 0);
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
 // line 640, offset 0x80040a18
	/* begin block 1 */
		// Start line: 641
		// Start offset: 0x80040A18
		// Variables:
	// 		struct SoundEffectChannel *channel; // $a0
	/* end block 1 */
	// End offset: 0x80040AC4
	// End Line: 662

	/* begin block 2 */
		// Start line: 1445
	/* end block 2 */
	// End Line: 1446

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
 // line 669, offset 0x80040ad8
	/* begin block 1 */
		// Start line: 670
		// Start offset: 0x80040AD8
		// Variables:
	// 		struct SoundEffectChannel *channel; // $a0
	/* end block 1 */
	// End offset: 0x80040BC8
	// End Line: 695

	/* begin block 2 */
		// Start line: 1506
	/* end block 2 */
	// End Line: 1507

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
 // line 715, offset 0x80040bdc
	/* begin block 1 */
		// Start line: 716
		// Start offset: 0x80040BDC
		// Variables:
	// 		struct SoundEffectChannel *channel; // $s0
	// 		int sfxIDNum; // $v1
	// 		int sfxToneID; // $a1
	// 		long triggerMask; // $s3
	// 		int spectralPlane; // $a1
	/* end block 1 */
	// End offset: 0x80040EFC
	// End Line: 822

	/* begin block 2 */
		// Start line: 1413
	/* end block 2 */
	// End Line: 1414

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
LAB_80040dc0:
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
LAB_80040d14:
    soundInst->state = '\x03';
  }
  else {
    if (1 < bVar4) {
      if (bVar4 == 2) {
        if (soundInst->delay != '\0') {
          soundInst->delay = soundInst->delay + -1;
          return;
        }
        goto LAB_80040d14;
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
        goto LAB_80040dc0;
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
 // line 837, offset 0x80040f24
	/* begin block 1 */
		// Start line: 838
		// Start offset: 0x80040F24
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
	// End offset: 0x80041124
	// End Line: 926

	/* begin block 2 */
		// Start line: 1842
	/* end block 2 */
	// End Line: 1843

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
  if (uVar7 == 1) goto LAB_800410bc;
  if (uVar7 < 2) {
    if (uVar7 != 0) goto LAB_800410b4;
    _vol = 0x3f;
  }
  else {
    if (uVar7 == 2) {
      iVar4 = iVar4 + 0x40;
      goto LAB_800410bc;
    }
LAB_800410b4:
    _vol = 0x7f;
  }
  iVar4 = _vol - iVar4;
LAB_800410bc:
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
 // line 932, offset 0x8004114c
	/* begin block 1 */
		// Start line: 933
		// Start offset: 0x8004114C
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
	// End offset: 0x8004134C
	// End Line: 1021

	/* begin block 2 */
		// Start line: 2045
	/* end block 2 */
	// End Line: 2046

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
  if (uVar7 == 1) goto LAB_800412e4;
  if (uVar7 < 2) {
    if (uVar7 != 0) goto LAB_800412dc;
    _vol = 0x3f;
  }
  else {
    if (uVar7 == 2) {
      iVar4 = iVar4 + 0x40;
      goto LAB_800412e4;
    }
LAB_800412dc:
    _vol = 0x7f;
  }
  iVar4 = _vol - iVar4;
LAB_800412e4:
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
 // line 1054, offset 0x80041374
	/* begin block 1 */
		// Start line: 2104
	/* end block 1 */
	// End Line: 2105

	/* begin block 2 */
		// Start line: 2269
	/* end block 2 */
	// End Line: 2270

void SOUND_HandleGlobalValueSignal(int name,long data)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_Init()
 // line 1067, offset 0x8004137c
	/* begin block 1 */
		// Start line: 1068
		// Start offset: 0x8004137C
		// Variables:
	// 		struct AadInitAttr initAttr; // stack offset -32
	/* end block 1 */
	// End offset: 0x8004137C
	// End Line: 1068

	/* begin block 2 */
		// Start line: 2294
	/* end block 2 */
	// End Line: 2295

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_Init(void)

{
  undefined2 local_20;
  undefined2 local_1e;
  code *local_1c;
  code *local_18;
  code *local_14;
  code *local_10;
  undefined local_c;
  
  local_1c = LOAD_NonBlockingFileLoad;
  local_18 = LOAD_NonBlockingBufferedLoad;
  local_14 = MEMPACK_Malloc;
  local_20 = 1;
  local_1e = 4;
  local_10 = MEMPACK_Free;
  local_c = 4;
  aadGetMemorySize((AadInitAttr *)&local_20);
  aadInit((AadInitAttr *)&local_20,(uchar *)&soundBuffer);
  gameTrackerX.sound.gMasterVol = 0x3fff;
  SOUND_SetMusicVolume(0x46);
  SOUND_SetSfxVolume(0x7f);
  SOUND_SetVoiceVolume(0x7f);
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
 // line 1163, offset 0x80041430
	/* begin block 1 */
		// Start line: 2529
	/* end block 1 */
	// End Line: 2530

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
 // line 1196, offset 0x80041454
	/* begin block 1 */
		// Start line: 2388
	/* end block 1 */
	// End Line: 2389

void SOUND_SetMusicVariable(int variable,int value)

{
  aadSetUserVariable(variable,value);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetMusicVolume(int newVolume /*$a0*/)
 // line 1206, offset 0x80041474
	/* begin block 1 */
		// Start line: 2404
	/* end block 1 */
	// End Line: 2405

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
 // line 1213, offset 0x800414a8
	/* begin block 1 */
		// Start line: 2589
	/* end block 1 */
	// End Line: 2590

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
 // line 1220, offset 0x800414dc
	/* begin block 1 */
		// Start line: 2603
	/* end block 1 */
	// End Line: 2604

	/* begin block 2 */
		// Start line: 2604
	/* end block 2 */
	// End Line: 2605

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
 // line 1236, offset 0x800414fc
	/* begin block 1 */
		// Start line: 2460
	/* end block 1 */
	// End Line: 2461

	/* begin block 2 */
		// Start line: 2622
	/* end block 2 */
	// End Line: 2623

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
 // line 1245, offset 0x8004152c
	/* begin block 1 */
		// Start line: 2640
	/* end block 1 */
	// End Line: 2641

	/* begin block 2 */
		// Start line: 2641
	/* end block 2 */
	// End Line: 2642

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
 // line 1254, offset 0x8004155c
	/* begin block 1 */
		// Start line: 2659
	/* end block 1 */
	// End Line: 2660

	/* begin block 2 */
		// Start line: 2660
	/* end block 2 */
	// End Line: 2661

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
 // line 1265, offset 0x8004159c
	/* begin block 1 */
		// Start line: 2682
	/* end block 1 */
	// End Line: 2683

	/* begin block 2 */
		// Start line: 2683
	/* end block 2 */
	// End Line: 2684

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
 // line 1274, offset 0x800415cc
	/* begin block 1 */
		// Start line: 1275
		// Start offset: 0x800415CC
		// Variables:
	// 		unsigned short slotNumber; // $s1
	/* end block 1 */
	// End offset: 0x80041628
	// End Line: 1290

	/* begin block 2 */
		// Start line: 2701
	/* end block 2 */
	// End Line: 2702

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicOff(void)

{
  int iVar1;
  uint slotNumber;
  ushort uVar2;
  
  uVar2 = 1;
  slotNumber = 1;
  do {
    aadDisableSlot(slotNumber);
    iVar1 = aadGetSlotStatus(slotNumber);
    if (iVar1 == 1) {
      aadStopSlot(slotNumber);
      aadStartSlot(slotNumber);
    }
    uVar2 = uVar2 + 1;
    slotNumber = (uint)uVar2;
  } while (uVar2 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_MusicOn()
 // line 1292, offset 0x80041640
	/* begin block 1 */
		// Start line: 1293
		// Start offset: 0x80041640
		// Variables:
	// 		unsigned short slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x8004166C
	// End Line: 1298

	/* begin block 2 */
		// Start line: 2753
	/* end block 2 */
	// End Line: 2754

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicOn(void)

{
  ushort uVar1;
  
  uVar1 = 1;
  do {
    aadEnableSlot((uint)uVar1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SfxOff()
 // line 1301, offset 0x8004167c
	/* begin block 1 */
		// Start line: 2775
	/* end block 1 */
	// End Line: 2776

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOff(void)

{
  aadStopAllSfx();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SfxOn()
 // line 1307, offset 0x8004169c
	/* begin block 1 */
		// Start line: 2787
	/* end block 1 */
	// End Line: 2788

	/* begin block 2 */
		// Start line: 2789
	/* end block 2 */
	// End Line: 2790

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_SfxOn(void)

{
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndIsPlaying(unsigned long handle /*$a0*/)
 // line 1329, offset 0x800416a4
	/* begin block 1 */
		// Start line: 2648
	/* end block 1 */
	// End Line: 2649

int SndIsPlaying(ulong handle)

{
  int iVar1;
  
  iVar1 = aadIsSfxPlaying(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndIsPlayingOrRequested(unsigned long handle /*$a0*/)
 // line 1334, offset 0x800416c4
	/* begin block 1 */
		// Start line: 2821
	/* end block 1 */
	// End Line: 2822

int SndIsPlayingOrRequested(ulong handle)

{
  int iVar1;
  
  iVar1 = aadIsSfxPlayingOrRequested(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SndTypeIsPlayingOrRequested(unsigned int sfxToneID /*$a0*/)
 // line 1344, offset 0x800416e4
	/* begin block 1 */
		// Start line: 2674
	/* end block 1 */
	// End Line: 2675

int SndTypeIsPlayingOrRequested(uint sfxToneID)

{
  int iVar1;
  
  iVar1 = aadIsSfxTypePlayingOrRequested(sfxToneID);
  return iVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SndPlay(unsigned int sample /*$a0*/)
 // line 1355, offset 0x80041704
	/* begin block 1 */
		// Start line: 2691
	/* end block 1 */
	// End Line: 2692

	/* begin block 2 */
		// Start line: 2845
	/* end block 2 */
	// End Line: 2846

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
 // line 1363, offset 0x8004173c
	/* begin block 1 */
		// Start line: 2859
	/* end block 1 */
	// End Line: 2860

	/* begin block 2 */
		// Start line: 2863
	/* end block 2 */
	// End Line: 2864

void SndEndLoop(ulong handle)

{
  aadStopSfx(handle);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SndPlayVolPan(unsigned int sample /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
 // line 1368, offset 0x8004175c
	/* begin block 1 */
		// Start line: 1369
		// Start offset: 0x8004175C
	/* end block 1 */
	// End offset: 0x80041788
	// End Line: 1379

	/* begin block 2 */
		// Start line: 2873
	/* end block 2 */
	// End Line: 2874

	/* begin block 3 */
		// Start line: 2876
	/* end block 3 */
	// End Line: 2877

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
 // line 1389, offset 0x80041798
	/* begin block 1 */
		// Start line: 2774
	/* end block 1 */
	// End Line: 2775

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
 // line 1420, offset 0x800417e0
	/* begin block 1 */
		// Start line: 1421
		// Start offset: 0x800417E0
	/* end block 1 */
	// End offset: 0x80041828
	// End Line: 1439

	/* begin block 2 */
		// Start line: 2973
	/* end block 2 */
	// End Line: 2974

void transitionMusicEndCallback(long userData,int slot,int loopFlag)

{
  ushort uVar1;
  
  if (slot == 0) {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0,0);
    uVar1 = aadAssignDynamicSequence(0,0,0);
    if (uVar1 == 0) {
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
 // line 1444, offset 0x80041838
	/* begin block 1 */
		// Start line: 3021
	/* end block 1 */
	// End Line: 3022

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
// void /*$ra*/ mainMusicEndCallback(long userData /*$s0*/, int slot /*$a1*/, int loopFlag /*$a2*/)
 // line 1464, offset 0x8004187c
	/* begin block 1 */
		// Start line: 1465
		// Start offset: 0x8004187C
	/* end block 1 */
	// End offset: 0x8004192C
	// End Line: 1490

	/* begin block 2 */
		// Start line: 3061
	/* end block 2 */
	// End Line: 3062

void mainMusicEndCallback(long userData,int slot,int loopFlag)

{
  ushort uVar1;
  
  if (slot == 0) {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0,0);
    uVar1 = aadAssignDynamicSequence(1,0,0);
    if (uVar1 == 0) {
      aadStartSlot(0);
      sprintf(&sndFileName,"\\kain2\\music\\%s\\%s.snd");
      sprintf(&smpFileName,"\\kain2\\music\\%s\\%s.smp");
      aadLoadDynamicSoundBank(&sndFileName,&smpFileName,0,1,loadMainMusicReturn);
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
 // line 1495, offset 0x8004193c
	/* begin block 1 */
		// Start line: 3123
	/* end block 1 */
	// End Line: 3124

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
 // line 1513, offset 0x80041984
	/* begin block 1 */
		// Start line: 1514
		// Start offset: 0x80041984
	/* end block 1 */
	// End offset: 0x800419B0
	// End Line: 1523

	/* begin block 2 */
		// Start line: 3159
	/* end block 2 */
	// End Line: 3160

void initialLoadMainMusicReturn(int dynamicBankIndex,int errorStatus)

{
  ushort uVar1;
  
  uVar1 = aadAssignDynamicSequence(0,0,0);
  if (uVar1 == 0) {
    aadStartSlot(0);
  }
  musicLoadInProgress = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_UpdateSound()
 // line 1531, offset 0x800419c0
	/* begin block 1 */
		// Start line: 1532
		// Start offset: 0x800419C0

		/* begin block 1.1 */
			// Start line: 1557
			// Start offset: 0x80041A14
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.1 */
		// End offset: 0x80041E64
		// End Line: 1612
	/* end block 1 */
	// End offset: 0x80041ED8
	// End Line: 1626

	/* begin block 2 */
		// Start line: 3197
	/* end block 2 */
	// End Line: 3198

/* WARNING: Removing unreachable block (ram,0x80041cfc) */
/* WARNING: Removing unreachable block (ram,0x80041d48) */
/* WARNING: Removing unreachable block (ram,0x80041acc) */
/* WARNING: Removing unreachable block (ram,0x80041b18) */
/* WARNING: Removing unreachable block (ram,0x80041b84) */
/* WARNING: Removing unreachable block (ram,0x80041bd0) */
/* WARNING: Removing unreachable block (ram,0x80041db4) */
/* WARNING: Removing unreachable block (ram,0x80041e00) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_UpdateSound(void)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  Level *pLVar6;
  long lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  aadProcessLoadQueue();
  iVar5 = aadGetNumLoadsQueued();
  if (iVar5 != 0) {
    return;
  }
  if (musicLoadInProgress != 0) {
    return;
  }
  if (gameTrackerX.sound.gMusicOn == '\0') {
    return;
  }
  if (checkMusicDelay == 0) {
    checkMusicDelay = 0x1e;
    pLVar6 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    if (pLVar6->dynamicMusicName == (char *)0x0) {
      if (currentDynamicSoundName != '\0') {
        return;
      }
      puVar3 = (undefined4 *)"\\kain2\\music\\undrwld1\\undrwld1.snd";
      puVar4 = (undefined4 *)&sndFileName;
      do {
        puVar9 = puVar4;
        puVar8 = puVar3;
        uVar10 = puVar8[1];
        uVar11 = puVar8[2];
        uVar12 = puVar8[3];
        *puVar9 = *puVar8;
        puVar9[1] = uVar10;
        puVar9[2] = uVar11;
        puVar9[3] = uVar12;
        puVar3 = puVar8 + 4;
        puVar4 = puVar9 + 4;
      } while (puVar8 + 4 != (undefined4 *)0x800cf0b4);
      cVar1 = *(char *)((int)puVar8 + 0x11);
      cVar2 = *(char *)((int)puVar8 + 0x12);
      *(char *)(puVar9 + 4) = 'n';
      *(char *)((int)puVar9 + 0x11) = cVar1;
      *(char *)((int)puVar9 + 0x12) = cVar2;
      puVar3 = (undefined4 *)"\\kain2\\music\\undrwld1\\undrwld1.smp";
      puVar4 = (undefined4 *)&smpFileName;
      do {
        puVar9 = puVar4;
        puVar8 = puVar3;
        uVar10 = puVar8[1];
        uVar11 = puVar8[2];
        uVar12 = puVar8[3];
        *puVar9 = *puVar8;
        puVar9[1] = uVar10;
        puVar9[2] = uVar11;
        puVar9[3] = uVar12;
        puVar3 = puVar8 + 4;
        puVar4 = puVar9 + 4;
      } while (puVar8 + 4 != (undefined4 *)0x800cf0d8);
      cVar1 = *(char *)((int)puVar8 + 0x11);
      cVar2 = *(char *)((int)puVar8 + 0x12);
      *(char *)(puVar9 + 4) = 'm';
      *(char *)((int)puVar9 + 0x11) = cVar1;
      *(char *)((int)puVar9 + 0x12) = cVar2;
      lVar7 = LOAD_DoesFileExist(&sndFileName);
      if (lVar7 == 0) {
        return;
      }
      aadLoadDynamicSoundBank(&sndFileName,&smpFileName,0,1,initialLoadMainMusicReturn);
      _currentDynamicSoundName = 0x72646e75;
      _CHAR____800d22e8 = 0x31646c77;
      CHAR____800d22ec = '\0';
    }
    else {
      iVar5 = strcmpi(pLVar6->dynamicMusicName,&currentDynamicSoundName);
      if (iVar5 == 0) {
        return;
      }
      if (currentDynamicSoundName == '\0') {
        sprintf(&sndFileName,"\\kain2\\music\\%s\\%s.snd");
        sprintf(&smpFileName,"\\kain2\\music\\%s\\%s.smp");
        lVar7 = LOAD_DoesFileExist(&sndFileName);
        if (lVar7 == 0) {
          return;
        }
        aadLoadDynamicSoundBank(&sndFileName,&smpFileName,0,1,initialLoadMainMusicReturn);
        strcpy(&currentDynamicSoundName,pLVar6->dynamicMusicName);
      }
      else {
        sprintf(&sndFileName,"\\kain2\\music\\%s\\%s.snd");
        lVar7 = LOAD_DoesFileExist(&sndFileName);
        if (lVar7 == 0) {
          return;
        }
        strcpy(&currentDynamicSoundName,pLVar6->dynamicMusicName);
        puVar3 = (undefined4 *)"\\kain2\\music\\undrtrn1\\undrtrn1.snd";
        puVar4 = (undefined4 *)&sndFileName;
        do {
          puVar9 = puVar4;
          puVar8 = puVar3;
          uVar10 = puVar8[1];
          uVar11 = puVar8[2];
          uVar12 = puVar8[3];
          *puVar9 = *puVar8;
          puVar9[1] = uVar10;
          puVar9[2] = uVar11;
          puVar9[3] = uVar12;
          puVar3 = puVar8 + 4;
          puVar4 = puVar9 + 4;
        } while (puVar8 + 4 != (undefined4 *)0x800cf06c);
        cVar1 = *(char *)((int)puVar8 + 0x11);
        cVar2 = *(char *)((int)puVar8 + 0x12);
        *(char *)(puVar9 + 4) = 'n';
        *(char *)((int)puVar9 + 0x11) = cVar1;
        *(char *)((int)puVar9 + 0x12) = cVar2;
        puVar3 = (undefined4 *)"\\kain2\\music\\undrtrn1\\undrtrn1.smp";
        puVar4 = (undefined4 *)&smpFileName;
        do {
          puVar9 = puVar4;
          puVar8 = puVar3;
          uVar10 = puVar8[1];
          uVar11 = puVar8[2];
          uVar12 = puVar8[3];
          *puVar9 = *puVar8;
          puVar9[1] = uVar10;
          puVar9[2] = uVar11;
          puVar9[3] = uVar12;
          puVar3 = puVar8 + 4;
          puVar4 = puVar9 + 4;
        } while (puVar8 + 4 != (undefined4 *)0x800cf090);
        cVar1 = *(char *)((int)puVar8 + 0x11);
        cVar2 = *(char *)((int)puVar8 + 0x12);
        *(char *)(puVar9 + 4) = 'm';
        *(char *)((int)puVar9 + 0x11) = cVar1;
        *(char *)((int)puVar9 + 0x12) = cVar2;
        aadLoadDynamicSoundBank(&sndFileName,&smpFileName,1,0,loadTransitionMusicReturn);
      }
    }
    musicLoadInProgress = 1;
    return;
  }
  checkMusicDelay = checkMusicDelay + -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_LoadDynamicMusic(char *newMusicName /*$s0*/)
 // line 1630, offset 0x80041eec
	/* begin block 1 */
		// Start line: 3398
	/* end block 1 */
	// End Line: 3399

void SOUND_LoadDynamicMusic(char *newMusicName)

{
  long lVar1;
  
  if (((newMusicName != (char *)0x0) && (musicLoadInProgress == 0)) &&
     (gameTrackerX.sound.gMusicOn != '\0')) {
    sprintf(&sndFileName,"\\kain2\\music\\%s\\%s.snd");
    sprintf(&smpFileName,"\\kain2\\music\\%s\\%s.smp");
    lVar1 = LOAD_DoesFileExist(&sndFileName);
    if (lVar1 != 0) {
      aadLoadDynamicSoundBank(&sndFileName,&smpFileName,0,1,initialLoadMainMusicReturn);
      strcpy(&currentDynamicSoundName,newMusicName);
      musicLoadInProgress = 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_FreeDynamicMusic()
 // line 1648, offset 0x80041fb8
	/* begin block 1 */
		// Start line: 3434
	/* end block 1 */
	// End Line: 3435

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
// void /*$ra*/ SOUND_DumpAllSound()
 // line 1665, offset 0x80042010
	/* begin block 1 */
		// Start line: 3468
	/* end block 1 */
	// End Line: 3469

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_DumpAllSound(void)

{
  aadFreeAllSfx();
  SOUND_FreeDynamicMusic();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetMusicModifier(long modifier /*$a0*/)
 // line 1674, offset 0x80042038
	/* begin block 1 */
		// Start line: 3486
	/* end block 1 */
	// End Line: 3487

void SOUND_SetMusicModifier(long modifier)

{
  int variable;
  int value;
  
  switch(modifier) {
  case 0:
    variable = 0;
    value = 0;
    goto LAB_800420e4;
  case 1:
    variable = 0;
    break;
  case 2:
    variable = 0;
    value = 3;
    goto LAB_800420e4;
  case 3:
    variable = 0;
    value = 4;
    goto LAB_800420e4;
  case 4:
    variable = 0;
    value = 2;
    goto LAB_800420e4;
  case 5:
    variable = 1;
    break;
  case 6:
    variable = 2;
    break;
  case 7:
    variable = 3;
    value = 0;
    goto LAB_800420e4;
  case 8:
    variable = 3;
    break;
  case 9:
    variable = 0x7d;
    break;
  case 10:
    variable = 0x7e;
    break;
  case 0xb:
    variable = 0x7c;
    break;
  default:
    goto switchD_80042060_caseD_c;
  case 0xd:
    variable = 0x78;
  }
  value = 1;
LAB_800420e4:
  SOUND_SetMusicVariable(variable,value);
switchD_80042060_caseD_c:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_ResetMusicModifier(long modifier /*$a0*/)
 // line 1724, offset 0x800420fc
	/* begin block 1 */
		// Start line: 3586
	/* end block 1 */
	// End Line: 3587

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
    goto switchD_80042124_caseD_7;
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
  }
  SOUND_SetMusicVariable(variable,0);
switchD_80042124_caseD_7:
  return;
}





