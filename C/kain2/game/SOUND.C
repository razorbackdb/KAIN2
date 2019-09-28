#include "THISDUST.H"
#include "SOUND.H"


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

SoundEffectChannel * SndOpenSfxChannel(uchar *channelNum)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = (SoundEffectChannel *)&theCamera.savedCinematic[1].targetPos.y;
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
  if (channelNum < 0x10) {
    *(undefined *)&(&theCamera.savedCinematic[1].targetPos)[channelNum * 6].y = 0;
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

SoundEffectChannel * SndGetSfxChannel(int channelNum)

{
  if (0xf < channelNum) {
    return (SoundEffectChannel *)0x0;
  }
  return (SoundEffectChannel *)&(&theCamera.savedCinematic[1].targetPos)[channelNum * 6].y;
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

void SOUND_ProcessInstanceSounds
               (uchar *sfxFileData,SoundInstance *soundInstTbl,_Position *position,
               int livesInOnePlace,int inSpectral,int hidden,int burning,long *triggerFlags)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ObjectPeriodicSound *sound;
  int iVar4;
  
  if ((((theCamera.maxFocusVel.pad != 6) && (sfxFileData != (uchar *)0x0)) &&
      (soundInstTbl != (SoundInstance *)0x0)) &&
     ((*sfxFileData == -0x42 && (sfxFileData[1] == -0x11)))) {
    bVar1 = sfxFileData[2];
    sound = (ObjectPeriodicSound *)(sfxFileData + 4);
    iVar4 = 0;
    if (bVar1 != 0) {
      do {
        bVar2 = sound->type;
        if (bVar2 == 1) {
          GenericMessage((_Instance *)position,(ulong)soundInstTbl,(ulong)sound);
LAB_8003e814:
          iVar3 = (uint)sound->numSfxIDs * 2 + 0xe;
LAB_8003e824:
          sound = (ObjectPeriodicSound *)(&sound->type + iVar3);
        }
        else {
          if (bVar2 < 2) {
            if (bVar2 == 0) {
              processPeriodicSound
                        (position,livesInOnePlace,inSpectral,hidden,burning,soundInstTbl,sound);
              iVar3 = (uint)sound->numSfxIDs * 2 + 0x12;
              goto LAB_8003e824;
            }
          }
          else {
            if (bVar2 < 5) {
              processOneShotSound(position,hidden,burning,triggerFlags,soundInstTbl,
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
                    /* WARNING: Subroutine does not return */
            SndEndLoop(pSVar3->handle);
          }
        }
        else {
          if (bVar2 < 2) {
            if (bVar2 == 0) {
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0x12;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0) {
                    /* WARNING: Subroutine does not return */
                SndEndLoop(pSVar3->handle);
              }
            }
          }
          else {
            if (bVar2 < 5) {
              pbVar4 = pbVar4 + (uint)pbVar4[1] * 2 + 0xe;
              pSVar3 = SndGetSfxChannel((uint)soundInstTbl->channel);
              if (pSVar3 != (SoundEffectChannel *)0x0) {
                SndCloseSfxChannel((uint)soundInstTbl->channel);
                soundInstTbl->channel = -1;
                soundInstTbl->state = '\0';
              }
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

int isOkayToPlaySound(int flags,int spectralPlane,int hidden,int burning)

{
  int iVar1;
  uint uVar2;
  Object *oldObject;
  Object *newObject;
  
  if ((flags & 0xfU) == 0) goto LAB_8003ea7c;
  oldObject = (Object *)flags;
  newObject = (Object *)spectralPlane;
  iVar1 = GAMELOOP_GetTimeOfDay();
  uVar2 = (uint)(iVar1 < 0x2bd);
  if (iVar1 == 700) {
    OBTABLE_ChangeObjectAccessPointers(oldObject,newObject);
    return uVar2;
  }
  if (iVar1 < 0x2bd) {
    if (iVar1 == 600) {
      uVar2 = 1;
      goto LAB_8003ea70;
    }
    uVar2 = flags & 2;
  }
  else {
    if (iVar1 == 0x708) {
      uVar2 = 4;
    }
    else {
      if (iVar1 != 0x76c) {
        uVar2 = flags & 2;
        goto LAB_8003ea74;
      }
      uVar2 = 8;
    }
LAB_8003ea70:
    uVar2 = flags & uVar2;
  }
LAB_8003ea74:
  if (uVar2 == 0) {
    return 0;
  }
LAB_8003ea7c:
  if ((((((flags & 0x10U) == 0) || (iVar1 = 0, spectralPlane != 0)) &&
       (((flags & 0x20U) == 0 || (iVar1 = 0, spectralPlane == 0)))) &&
      ((((flags & 0x40U) == 0 || (iVar1 = 0, hidden == 0)) && (iVar1 = 1, (flags & 0x80U) != 0))))
     && (iVar1 = 0, burning != 0)) {
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

void setPeriodicSoundStateOff(SoundInstance *soundInst,ObjectPeriodicSound *sound)

{
  _ObjectTracker *objectTracker;
  
  objectTracker = (_ObjectTracker *)(uint)soundInst->channel;
  SndCloseSfxChannel((int)objectTracker);
  soundInst->channel = -1;
  soundInst->state = '\x03';
  soundInst->delay = sound->offTime;
  if (sound->offTimeVariation == '\0') {
    OBTABLE_InitAnimPointers(objectTracker);
    return;
  }
                    /* WARNING: Subroutine does not return */
  rand();
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

void processPeriodicSound
               (_Position *position,int livesInOnePlane,int inSpectral,int hidden,int burning,
               SoundInstance *soundInst,ObjectPeriodicSound *sound)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  ulong uVar4;
  byte bVar5;
  _Instance *instance;
  GameTracker *gameTracker;
  
  sVar1 = theCamera.core.vvNormalWorVecMat[0]._18_2_;
  bVar5 = soundInst->state & 0xf;
  if (bVar5 == 1) {
    GenericRelocateTune((Object *)&UNK_00000001,livesInOnePlane);
    return;
  }
  if (1 < bVar5) {
    if (bVar5 == 2) {
      gameTracker = (GameTracker *)livesInOnePlane;
      pSVar2 = SndGetSfxChannel((uint)soundInst->channel);
      iVar3 = SndIsPlayingOrRequested(pSVar2->handle);
      if (iVar3 == 0) {
        setPeriodicSoundStateOff(soundInst,sound);
        return;
      }
      instance = (_Instance *)pSVar2->handle;
      iVar3 = SndIsPlaying((ulong)instance);
      if (iVar3 == 0) {
        return;
      }
      if (livesInOnePlane == 0) {
        FUN_8003ee5c(instance,gameTracker);
        return;
      }
      if (inSpectral == 0) {
        if ((sVar1 == 0) &&
           (iVar3 = isOkayToPlaySound((uint)sound->flags,0,hidden,burning), iVar3 != 0)) {
          if (soundInst->delay == '\0') {
            if (sound->offTime != '\0') {
                    /* WARNING: Subroutine does not return */
              SndEndLoop(pSVar2->handle);
            }
            if (sound->maxVolVariation != '\0') {
                    /* WARNING: Subroutine does not return */
              pSVar2->volume = (ushort)sound->maxVolume;
              rand();
            }
            if (sound->pitchVariation != 0) {
                    /* WARNING: Subroutine does not return */
              pSVar2->pitch = sound->pitch;
              rand();
            }
            soundInst->delay = sound->onTime;
            if (sound->onTimeVariation != '\0') {
                    /* WARNING: Subroutine does not return */
              rand();
            }
          }
          else {
            soundInst->delay = soundInst->delay + -1;
          }
          bVar5 = soundInst->state;
          if ((bVar5 & 0x10) == 0) {
            soundInst->state = bVar5 | 0x10;
            return;
          }
          soundInst->state = bVar5 & 0xef;
          uVar4 = SOUND_Update3dSound(position,pSVar2->handle,(int)pSVar2->pitch,(int)pSVar2->volume
                                      ,(uint)sound->minVolDistance);
          if (uVar4 != 0) {
            return;
          }
        }
      }
      else {
        if (sVar1 != 0) {
          FUN_8003ee5c(instance,gameTracker);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      SndEndLoop(pSVar2->handle);
    }
    if (bVar5 == 3) {
      GenericRelocateTune((Object *)&UNK_00000001,livesInOnePlane);
      return;
    }
  }
  soundInst->channel = -1;
  soundInst->state = '\x01';
  soundInst->delay = sound->initialDelay;
  if (sound->initialDelayVariation == '\0') {
    return;
  }
                    /* WARNING: Subroutine does not return */
  rand();
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

void GenericMessage(_Instance *instance,ulong message,ulong data)

{
  short sVar1;
  SoundEffectChannel *pSVar2;
  int iVar3;
  ulong uVar4;
  byte bVar5;
  int spectralPlane;
  
  spectralPlane = (int)fontTracker.font_buffer[33].x;
  bVar5 = *(byte *)(message + 1) & 0xf;
  if (bVar5 != 1) {
    if ((bVar5 < 2) || (bVar5 != 2)) {
      *(undefined *)message = 0xff;
      *(undefined *)(message + 1) = 1;
      *(undefined *)(message + 2) = 0;
    }
    else {
      pSVar2 = SndGetSfxChannel((uint)*(byte *)message);
      if (pSVar2 == (SoundEffectChannel *)0x0) {
        spectralPlane = isOkayToPlaySound((uint)*(byte *)(data + 3),spectralPlane,0,0);
        if ((spectralPlane != 0) &&
           (pSVar2 = SndOpenSfxChannel((uchar *)message), pSVar2 != (SoundEffectChannel *)0x0)) {
          pSVar2->volume = (ushort)*(byte *)(data + 10);
          if (*(char *)(data + 0xb) != '\0') {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          pSVar2->pitch = *(short *)(data + 6);
          if (*(short *)(data + 8) != 0) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          if (1 < *(byte *)(data + 1)) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          uVar4 = SOUND_Play3dSound((_Position *)instance,(uint)*(ushort *)(data + 0xe),
                                    (int)pSVar2->pitch,(int)pSVar2->volume,
                                    (uint)*(ushort *)(data + 4));
          pSVar2->handle = uVar4;
          if (uVar4 == 0) {
            SndCloseSfxChannel((uint)*(byte *)message);
            *(undefined *)message = 0xff;
          }
        }
      }
      else {
        iVar3 = SndIsPlayingOrRequested(pSVar2->handle);
        if (iVar3 == 0) {
          SndCloseSfxChannel((uint)*(byte *)message);
          *(undefined *)message = 0xff;
          *(undefined *)(message + 1) = 1;
        }
        else {
          iVar3 = SndIsPlaying(pSVar2->handle);
          if (iVar3 != 0) {
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
                pSVar2->volumeChangeError = pSVar2->volumeChangeError - pSVar2->volumeChangeTimeSave
                ;
              }
              pSVar2->volumeChangeTime = pSVar2->volumeChangeTime + -1;
            }
            bVar5 = *(byte *)(message + 1);
            if ((bVar5 & 0x10) == 0) {
              *(byte *)(message + 1) = bVar5 | 0x10;
            }
            else {
              *(byte *)(message + 1) = bVar5 & 0xef;
              uVar4 = SOUND_Update3dSound((_Position *)instance,pSVar2->handle,(int)pSVar2->pitch,
                                          (int)pSVar2->volume,(uint)*(ushort *)(data + 4));
              if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                SndEndLoop(pSVar2->handle);
              }
            }
            spectralPlane = isOkayToPlaySound((uint)*(byte *)(data + 3),spectralPlane,0,0);
            if (spectralPlane == 0) {
                    /* WARNING: Subroutine does not return */
              SndEndLoop(pSVar2->handle);
            }
          }
        }
      }
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
  if ((soundInst->state & 0xf) == 1) {
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
  if (pSVar1 != (SoundEffectChannel *)0x0) {
                    /* WARNING: Subroutine does not return */
    SndEndLoop(pSVar1->handle);
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

void SOUND_SetInstanceSoundVolume(SoundInstance *soundInst,long volumeChangeAmt,long time)

{
  short sVar1;
  SoundEffectChannel *position;
  long livesInOnePlane;
  long inSpectral;
  int in_a3;
  SoundInstance *local_10;
  ObjectPeriodicSound *local_c;
  
  if (((soundInst->state & 0xf) == 2) &&
     (livesInOnePlane = volumeChangeAmt, inSpectral = time,
     position = SndGetSfxChannel((uint)soundInst->channel), position != (SoundEffectChannel *)0x0))
  {
    if (time < 0) {
      time = -time;
    }
    if ((0 < volumeChangeAmt) && (0x7f < (int)position->volume + volumeChangeAmt)) {
      volumeChangeAmt = 0x7f - (int)position->volume;
    }
    if ((volumeChangeAmt < 0) && ((int)position->volume + volumeChangeAmt < 0)) {
      volumeChangeAmt = -(int)position->volume;
    }
    if (time == 0) {
      processPeriodicSound((_Position *)position,livesInOnePlane,inSpectral,in_a3,local_10,local_c);
      return;
    }
    position->volumeChangePerUpdate = (short)(volumeChangeAmt / time);
    if (volumeChangeAmt < 0) {
      sVar1 = -1;
    }
    else {
      sVar1 = 1;
    }
    position->volumeChangeSign = sVar1;
    sVar1 = (short)(volumeChangeAmt % time);
    position->volumeChangeError = 0;
    position->volumeChangeTime = (short)time;
    position->volumeChangeTimeSave = (short)time;
    if (volumeChangeAmt % time < 0) {
      sVar1 = -sVar1;
    }
    position->volumeChangeErrPerUpdate = sVar1;
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

void processOneShotSound(_Position *position,int hidden,int burning,long *triggerFlags,
                        SoundInstance *soundInst,ObjectOneShotSound *sound)

{
  SoundEffectChannel *pSVar1;
  int iVar2;
  ulong uVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = soundInst->state & 0xf;
  uVar5 = objectOneShotTriggerTbl[(uint)sound->type - 2];
  if (bVar4 == 1) {
    if ((*triggerFlags & uVar5) == 0) {
      return;
    }
    iVar2 = isOkayToPlaySound((uint)sound->flags,(int)theCamera.core.vvNormalWorVecMat[0]._18_2_,
                              hidden,burning);
    if (iVar2 == 0) {
LAB_8003f8dc:
      *triggerFlags = *triggerFlags & ~uVar5;
      return;
    }
    soundInst->delay = sound->initialDelay;
    if (sound->initialDelayVariation != '\0') {
                    /* WARNING: Subroutine does not return */
      rand();
    }
    if (soundInst->delay != '\0') {
      soundInst->state = '\x02';
      return;
    }
LAB_8003f830:
    soundInst->state = '\x03';
  }
  else {
    if (1 < bVar4) {
      if (bVar4 == 2) {
        if (soundInst->delay != '\0') {
          soundInst->delay = soundInst->delay + -1;
          return;
        }
        goto LAB_8003f830;
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
                    /* WARNING: Subroutine does not return */
            rand();
          }
          pSVar1->pitch = sound->pitch;
          if (sound->pitchVariation != 0) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          if (sound->numSfxIDs < 2) {
            uVar3 = SOUND_Play3dSound(position,(uint)*(ushort *)(sound + 1),(int)pSVar1->pitch,
                                      (int)pSVar1->volume,(uint)sound->minVolDistance);
            pSVar1->handle = uVar3;
            if (uVar3 != 0) {
              return;
            }
            SndCloseSfxChannel((uint)soundInst->channel);
            soundInst->channel = -1;
            return;
          }
                    /* WARNING: Subroutine does not return */
          rand();
        }
        iVar2 = SndIsPlayingOrRequested(pSVar1->handle);
        if (iVar2 != 0) {
          iVar2 = SndIsPlaying(pSVar1->handle);
          if (iVar2 == 0) {
            return;
          }
          bVar4 = soundInst->state;
          if ((bVar4 & 0x10) != 0) {
            soundInst->state = bVar4 & 0xef;
            uVar3 = SOUND_Update3dSound(position,pSVar1->handle,(int)pSVar1->pitch,
                                        (int)pSVar1->volume,(uint)sound->minVolDistance);
            if (uVar3 != 0) {
              return;
            }
                    /* WARNING: Subroutine does not return */
            SndEndLoop(pSVar1->handle);
          }
          soundInst->state = bVar4 | 0x10;
          return;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong SOUND_Play3dSound(_Position *position,int sfxToneID,int pitch,int maxVolume,int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  
  if (maxVolume == 0) {
    uVar4 = 0;
  }
  else {
    if (minVolDist == 0) {
      uVar4 = SndPlayVolPan(sfxToneID,(ushort)maxVolume,0x40,(short)pitch);
    }
    else {
      if (((short)ULONG_800cff80 == 5) && ((theCamera.positionAccl._0_4_ & 0x10) != 0)) {
        sVar1 = position->z;
        uVar6 = (int)position->x - (int)theCamera;
        uVar5 = (int)position->y - (int)DAT_800cfe92;
        sVar2 = DAT_800cfe94;
      }
      else {
        uVar6 = (int)position->x - (int)*(short *)(_CHAR_00h_800cff98 + 0x5c);
        sVar1 = position->z;
        sVar2 = *(short *)(_CHAR_00h_800cff98 + 0x60);
        uVar5 = (int)position->y - (int)*(short *)(_CHAR_00h_800cff98 + 0x5e);
      }
      lVar3 = MATH3D_FastSqrt0(uVar6 * uVar6 + uVar5 * uVar5 +
                               ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
      uVar4 = 0;
      if (lVar3 <= minVolDist) {
                    /* WARNING: Subroutine does not return */
        ratan2(uVar5,uVar6);
      }
    }
  }
  return uVar4;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong SOUND_Update3dSound(_Position *position,ulong handle,int pitch,int maxVolume,int minVolDist)

{
  short sVar1;
  short sVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  if (maxVolume == 0) {
    handle = 0;
  }
  else {
    if (minVolDist != 0) {
      if (((short)ULONG_800cff80 == 5) && ((theCamera.positionAccl._0_4_ & 0x10) != 0)) {
        sVar1 = position->z;
        uVar5 = (int)position->x - (int)theCamera;
        uVar4 = (int)position->y - (int)DAT_800cfe92;
        sVar2 = DAT_800cfe94;
      }
      else {
        uVar5 = (int)position->x - (int)*(short *)(_CHAR_00h_800cff98 + 0x5c);
        sVar1 = position->z;
        sVar2 = *(short *)(_CHAR_00h_800cff98 + 0x60);
        uVar4 = (int)position->y - (int)*(short *)(_CHAR_00h_800cff98 + 0x5e);
      }
      lVar3 = MATH3D_FastSqrt0(uVar5 * uVar5 + uVar4 * uVar4 +
                               ((int)sVar1 - (int)sVar2) * ((int)sVar1 - (int)sVar2));
      handle = 0;
      if (lVar3 <= minVolDist) {
                    /* WARNING: Subroutine does not return */
        ratan2(uVar4,uVar5);
      }
    }
  }
  return handle;
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

void SOUND_HandleGlobalValueSignal(int name,long data)

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
  aadInit(&local_20,(uchar *)&soundBuffer);
  theCamera.collisionTargetFocusRotation._4_4_ = 0x3fff;
  SOUND_SetMusicVolume(0x7f);
  SOUND_SetSfxVolume(0x7f);
  SOUND_SetVoiceVolume(0x50);
  theCamera.focusSphere.position.z._0_1_ = 1;
  theCamera.focusSphere.position.z._1_1_ = 1;
  theCamera.focusSphere.radius._0_1_ = 1;
  theCamera.focusSphere.radius._1_1_ = 0;
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
  theCamera.focusSphere.radius._1_1_ = 0;
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

void SOUND_SetMusicVariable(int variable,int value)

{
  aadSetUserVariable(variable,value);
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
  if (newVolume == -1) {
    newVolume = theCamera._452_4_;
  }
  theCamera._452_4_ = newVolume;
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
  if (newVolume == -1) {
    newVolume = (int)theCamera.cameraKey;
  }
  theCamera.cameraKey = (_CameraKey *)newVolume;
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
  if (newVolume == -1) {
    newVolume = theCamera.focusSphere.position._0_4_;
  }
  theCamera.focusSphere.position._0_4_ = newVolume;
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

void SOUND_PauseAllSound(void)

{
  if (cGpffffb6bb != '\0') {
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
  if (theCamera.focusSphere.radius._1_1_ != '\0') {
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
  if (theCamera.focusSphere.radius._1_1_ != '\0') {
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
  if (theCamera.focusSphere.radius._1_1_ != '\0') {
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
  uint toneID;
  
  toneID = 1;
  do {
    aadDisableSlot(toneID);
    iVar1 = aadIsSfxLoaded(toneID);
    if (iVar1 == 1) {
      aadStopSlot(toneID);
      aadStartSlot(toneID);
    }
    toneID = toneID + 1;
  } while ((int)toneID < 4);
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
  do {
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
  int in_v0;
  _AadSequenceSlot *in_a1;
  
  metaCmdLoopEnd((AadSeqEvent *)handle,in_a1);
  return in_v0;
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
  
  if ((char)theCamera.focusSphere.position.z == '\0') {
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

ulong SndPlayVolPan(uint sample,ushort vol,ushort pan,short pitch)

{
  ulong uVar1;
  
  if ((char)theCamera.focusSphere.position.z == '\0') {
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
 // line 1421, offset 0x800402c0
	/* begin block 1 */
		// Start line: 2842
	/* end block 1 */
	// End Line: 2843

ulong SndUpdateVolPanPitch(ulong param_1,uint param_2,uint param_3,short param_4)

{
  ulong uVar1;
  
  if ((param_1 == 0) || (cGpffffb6b8 == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = aadSetSfxVolPanPitch(param_1,param_2 & 0xffff,param_3 & 0xffff,param_4);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void musicLoadReturnFunc(int dynamicBankIndex,int errorStatus)

{
  _musicInfo = _CHAR____800d1514;
  _CHAR____800d1518 = errorStatus;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void musicFadeoutReturnFunc(void)

{
  _musicInfo = _CHAR____800d1514;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void musicEndCallbackFunc(long userData,int slot,int loopFlag)

{
  int iVar1;
  
  if (slot == 0) {
    aadInstallEndSequenceCallback((TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)0x0,0);
    iVar1 = aadAssignDynamicSequence(_CHAR____800d151c,0,0);
    if (iVar1 == 0) {
      aadStartSlot(0);
      _musicInfo = _CHAR____800d1514;
    }
    else {
      _musicInfo = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SOUND_PutMusicCommand(int cmdType,int cmdData)

{
  int iVar1;
  
  iVar1 = _CHAR____800d1550 * 8;
  *(int *)(&CHAR____800d1530 + iVar1) = cmdType;
  *(int *)(&CHAR____800d1534 + iVar1) = cmdData;
  if (_CHAR____800d1558 < 3) {
    _CHAR____800d1550 = _CHAR____800d1550 + 1 & 3;
    _CHAR____800d1558 = _CHAR____800d1558 + 1;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_MusicInit(void)

{
  _musicInfo = 0;
  _CHAR____800d1518 = 0;
  _CHAR____800d1520 = 0;
  _CHAR____800d1524 = 0xffffffff;
  CHAR____800d1528 = '\0';
  _CHAR____800d1550 = 0;
  _CHAR____800d1554 = 0;
  _CHAR____800d1558 = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int SOUND_IsMusicLoading(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (((_musicInfo == 1) || (_musicInfo == 3)) || (_musicInfo == 7)) {
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_ProcessMusicLoad(void)

{
  int dynamicBankIndex;
  int in_a1;
  int errorStatus;
  int errorStatus_00;
  char local_50 [64];
  
  switch(_musicInfo) {
  case 0:
    if (_CHAR____800d1558 == 0) {
      if (_CHAR____800d1520 != 0) {
        SOUND_MusicOn();
        return;
      }
      if ((aadMem->sramDefragInfo).status == 0) {
        _CHAR____800d1520 = 0x1e;
                    /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID(*(long *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x38));
      }
    }
    else {
      if (*(int *)(&CHAR____800d1530 + _CHAR____800d1554 * 8) == 0) {
        _musicInfo = 0xb;
        _CHAR____800d1514 = 0xd;
        _CHAR____800d1524 = *(undefined4 *)(&CHAR____800d1534 + _CHAR____800d1554 * 8);
        aadStartMusicMasterVolFade(0,-3,musicFadeoutReturnFunc);
      }
      _CHAR____800d1554 = _CHAR____800d1554 + 1 & 3;
      _CHAR____800d1558 = _CHAR____800d1558 + -1;
    }
    break;
  case 2:
    errorStatus_00 = 0;
    errorStatus = 0;
    dynamicBankIndex = aadAssignDynamicSequence(0,0,0);
    if (dynamicBankIndex != 0) {
      musicLoadReturnFunc(errorStatus_00,errorStatus);
      return;
    }
    dynamicBankIndex = 0;
    aadStartSlot(0);
    musicLoadReturnFunc(dynamicBankIndex,errorStatus);
    return;
  case 4:
    if (_CHAR____800d1518 != 0) {
      _musicInfo = 0;
      return;
    }
    _musicInfo = 5;
    _CHAR____800d1514 = 6;
    _CHAR____800d151c = 1;
    goto SndPlayVolPan;
  case 6:
    if ((aadMem->sramDefragInfo).status == 0) {
                    /* WARNING: Subroutine does not return */
      sprintf(local_50,s__kain2_music__s__s_snd_800cea9c);
    }
    break;
  case 8:
    if (_CHAR____800d1518 != 0) {
      _musicInfo = 0;
      return;
    }
    _musicInfo = 9;
    _CHAR____800d1514 = 10;
    _CHAR____800d151c = 0;
SndPlayVolPan:
    aadInstallEndSequenceCallback(musicEndCallbackFunc,0);
    aadSetUserVariable(0x7f,1);
    break;
  case 10:
    dynamicBankIndex = 1;
    aadFreeDynamicSoundBank(1);
    musicLoadReturnFunc(dynamicBankIndex,in_a1);
    return;
  case 0xc:
    aadStopAllSlots();
    aadFreeDynamicSoundBank(0);
    errorStatus_00 = 1;
    dynamicBankIndex = theCamera._452_4_;
    aadStartMusicMasterVolFade
              (theCamera._452_4_,1,(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    musicLoadReturnFunc(dynamicBankIndex,errorStatus_00);
    return;
  case 0xd:
    aadStopAllSlots();
    aadFreeDynamicSoundBank(0);
    aadStartMusicMasterVolFade
              (theCamera._452_4_,1,(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    CHAR____800d1528 = '\0';
    _CHAR____800d1520 = 0;
    _musicInfo = 0;
  }
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SOUND_UpdateSound(void)

{
  bool bVar1;
  void *in_a0;
  long in_a1;
  short in_a2;
  void *in_a3;
  void *local_10;
  
  aadLoadDynamicSoundBankReturn2(in_a0,in_a1,in_a2,in_a3,local_10);
  if (((theCamera.core.debugRot._4_4_ & 0x40000) == 0) &&
     ((gSramFullAlarm != 0 || (gSramFullMsgCnt != 0)))) {
    bVar1 = gSramFullMsgCnt == 0;
    gSramFullMsgCnt = gSramFullMsgCnt + -1;
    if (bVar1) {
      gSramFullMsgCnt = 0x3c;
    }
                    /* WARNING: Subroutine does not return */
    FONT_Print(s___sound_memory_full__u__d__d_f___800ceb04);
  }
  if (theCamera.focusSphere.position.z._1_1_ != '\0') {
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SOUND_PlaneShift(int newPlane)

{
  if (theCamera.focusSphere.position.z._1_1_ == '\0') {
    _CHAR____800d1524 = 0xffffffff;
  }
  else {
    SOUND_PutMusicCommand(0,newPlane);
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
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUND_SetMusicModifier(long modifier /*$a0*/)
 // line 1826, offset 0x80040acc
	/* begin block 1 */
		// Start line: 3804
	/* end block 1 */
	// End Line: 3805

void SOUND_SetMusicVolume(int newVolume)

{
  int variable;
  int value;
  
  switch(newVolume) {
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
  SOUND_SetMusicVariable(variable,value);
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
  SOUND_SetMusicVariable(variable,0);
switchD_80040bb4_caseD_7:
  return;
}





