#include "THISDUST.H"
#include "HEALTH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitHealthSystem()
 // line 4, offset 0x800a44a0
	/* begin block 1 */
		// Start line: 8
	/* end block 1 */
	// End Line: 9

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitHealthSystem(void)

{
  int iVar1;
  
  Raziel.DamageFrequency = 0;
  Raziel.HealthScale = 1;
  Raziel.HealthBalls = 0;
  Raziel.GlyphManaBalls = 0;
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    Raziel.CurrentPlane = 2;
    Raziel.HitPoints = 100000;
    razMaterialShift();
  }
  else {
    Raziel.CurrentPlane = 1;
    Raziel.HitPoints = GetMaxHealth();
    razSpectralShift();
  }
  iVar1 = razInBaseArea("under",5);
  if (iVar1 == 0) {
    razSetPlayerEventHistory(0x1000);
  }
  else {
    Raziel.HitPoints = 100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GainHealth(int data /*$a0*/)
 // line 32, offset 0x800a4540
	/* begin block 1 */
		// Start line: 71
	/* end block 1 */
	// End Line: 72

void GainHealth(int data)

{
  int iVar1;
  
  data = data * 20000;
  if (data < 0) {
    data = data + 0xfff;
  }
  Raziel.HitPoints = Raziel.HitPoints + (data >> 0xc);
  iVar1 = GetMaxHealth();
  if ((iVar1 <= Raziel.HitPoints) && (Raziel.CurrentPlane == 1)) {
    Raziel.HitPoints = GetMaxHealth();
    razReaverOn();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LoseHealth(int amount /*$a0*/)
 // line 47, offset 0x800a45cc
	/* begin block 1 */
		// Start line: 101
	/* end block 1 */
	// End Line: 102

void LoseHealth(int amount)

{
  if ((((ControlFlag & 0x1000000U) == 0) && (Raziel.invincibleTimer == 0)) &&
     (0x20d < Raziel.HitPoints)) {
    amount = amount * 20000;
    if (amount < 0) {
      amount = amount + 0xfff;
    }
    Raziel.HitPoints = Raziel.HitPoints - (amount >> 0xc);
    Raziel.DamageFrequency = Raziel.DamageFrequency - (amount >> 0xc);
    Raziel.invincibleTimer = (int)PlayerData->healthInvinciblePostHit * 0x1e000;
    if (Raziel.CurrentPlane == 1) {
      razReaverOff();
      if (Raziel.soulReaver != (_Instance *)0x0) {
        INSTANCE_Post(Raziel.soulReaver,0x800101,0);
        razReaverImbue(2);
      }
    }
    if ((gameTrackerX.gameFlags & 0x80U) == 0) {
      GAMEPAD_Shock0(1,(int)&DAT_00002328);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrainHealth(int amount /*$a0*/)
 // line 72, offset 0x800a46c8
	/* begin block 1 */
		// Start line: 153
	/* end block 1 */
	// End Line: 154

void DrainHealth(int amount)

{
  int iVar1;
  
  if ((ControlFlag & 0x1000000U) == 0) {
    if (amount < 0) {
      amount = amount + 0xfff;
    }
    if (Raziel.CurrentPlane == 1) {
      iVar1 = (int)PlayerData->healthMaterialRate * (amount >> 0xc) * gameTrackerX.timeMult;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0xfff;
      }
      Raziel.HitPoints = Raziel.HitPoints + (iVar1 >> 0xc);
      if (Raziel.soulReaver != (_Instance *)0x0) {
        INSTANCE_Post(Raziel.soulReaver,0x800101,0);
        razReaverImbue(2);
      }
    }
    else {
      if ((Raziel.invincibleTimer == 0) && (0x20d < Raziel.HitPoints)) {
        iVar1 = -(int)PlayerData->healthSpectralRate * (amount >> 0xc) * gameTrackerX.timeMult;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (iVar1 >> 0xc);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ BumpUpHealth()
 // line 97, offset 0x800a47e4
	/* begin block 1 */
		// Start line: 206
	/* end block 1 */
	// End Line: 207

	/* begin block 2 */
		// Start line: 215
	/* end block 2 */
	// End Line: 216

/* WARNING: Unknown calling convention yet parameter storage is locked */

void BumpUpHealth(void)

{
  Raziel.HealthScale = Raziel.HealthScale + 1;
  Raziel.HitPoints = GetMaxHealth();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetMaxHealth()
 // line 113, offset 0x800a4810
	/* begin block 1 */
		// Start line: 247
	/* end block 1 */
	// End Line: 248

	/* begin block 2 */
		// Start line: 248
	/* end block 2 */
	// End Line: 249

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GetMaxHealth(void)

{
  if (Raziel.CurrentPlane != 2) {
    return ((int)Raziel.HealthScale + 1) * 100000;
  }
  return 100000;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessHealth(struct _Instance *instance /*$s0*/)
 // line 130, offset 0x800a4860
	/* begin block 1 */
		// Start line: 131
		// Start offset: 0x800A4860

		/* begin block 1.1 */
			// Start line: 226
			// Start offset: 0x800A4A88
		/* end block 1.1 */
		// End offset: 0x800A4B1C
		// End Line: 239
	/* end block 1 */
	// End offset: 0x800A4CFC
	// End Line: 287

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

	/* begin block 3 */
		// Start line: 315
	/* end block 3 */
	// End Line: 316

void ProcessHealth(_Instance *instance)

{
  int Data;
  int number;
  int max_health;
  
  if ((Raziel.invincibleTimer == 0) && ((Raziel.playerEventHistory & 0x1000) != 0)) {
    Data = GetMaxHealth();
    if ((Raziel.HitPoints == Data) || (Raziel.CurrentPlane == 2)) {
      razReaverOn();
    }
    else {
      razReaverOff();
    }
    if (Raziel.CurrentPlane == 1) {
      if ((instance->waterFace != (_TFace *)0x0) && ((Raziel.Abilities & 0x10U) == 0)) {
        DrainHealth((int)&DAT_0000a000);
      }
      if ((Raziel.soulReaver == (_Instance *)0x0) ||
         (Data = GetMaxHealth(), Raziel.HitPoints != Data)) {
        Data = (int)PlayerData->healthMaterialRate * gameTrackerX.timeMult;
        if (Data < 0) {
          Data = Data + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (Data >> 0xc);
      }
      if (Raziel.HitPoints < 100000) {
        razPlaneShift(instance);
        Raziel.invincibleTimer = (int)PlayerData->healthInvinciblePostShunt * 0x1e000;
        if ((Raziel.Mode & 0x40000U) != 0) {
          CAMERA_ChangeToOutOfWater(&theCamera,instance);
        }
      }
      else {
        if (Raziel.HitPoints < 150000) {
          Data = gameTrackerX.timeMult * 1000;
          if (Data < 0) {
            Data = Data + 0xfff;
          }
          Raziel.DamageFrequency = Raziel.DamageFrequency - (Data >> 0xc);
          if (Raziel.DamageFrequency < 0) {
            Raziel.DamageFrequency = Raziel.HitPoints + -100000;
            if (Raziel.DamageFrequency < 0x493e) {
              Raziel.DamageFrequency = (int)&DAT_0000493e;
            }
            FX_DoInstancePowerRing
                      (instance,0x2ee - ((int)(&DAT_0000c350 + -Raziel.DamageFrequency) * 300) /
                                        0x7a12,(long *)0x0,0,0);
            if ((gameTrackerX.gameFlags & 0x80U) == 0) {
              GAMEPAD_Shock1(0x80,(int)&DAT_00005000);
            }
          }
        }
      }
      number = (int)Raziel.HealthScale;
      Data = Raziel.HitPoints + -100000;
      max_health = number * 100000;
      goto LAB_800a4cf4;
    }
    if (Raziel.HitPoints < 0x20e) {
      Data = (int)PlayerData->healthSpectralRate * gameTrackerX.timeMult;
      if (Data < 0) {
        Data = Data + 0xfff;
      }
      Raziel.HitPoints = Raziel.HitPoints - (Data >> 0xc);
    }
    else {
      if (Raziel.HitPoints < 100000) {
        Data = (int)PlayerData->healthSpectralRate * gameTrackerX.timeMult;
        if (Data < 0) {
          Data = Data + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (Data >> 0xc);
      }
      else {
        Raziel.HitPoints = 100000;
      }
    }
    if (((ControlFlag & 0x800000U) == 0) && (Raziel.HitPoints < 0x20d)) {
      Data = SetControlInitIdleData(0,0,3);
      StateSwitchStateCharacterData(&Raziel.State,StateHandlerIdle,Data);
      G2EmulationSwitchAnimationCharacter(&Raziel.State,0xd6,0,3,1);
      Raziel.HitPoints = 0x20d;
      ControlFlag = ControlFlag | 0x804000;
    }
    if (Raziel.HitPoints < 0) {
      gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
      if (Raziel.soulReaver != (_Instance *)0x0) {
        INSTANCE_Post(Raziel.soulReaver,0x800105,0);
      }
      razSetPlayerEventHistory(0x8000);
      Raziel.HitPoints = (int)&DAT_0000c350;
      gameTrackerX.gameData.asmData.MorphType = 1;
      Raziel.playerEvent = Raziel.playerEvent | 0x8000;
      razPlayUnderworldSounds(gameTrackerX.playerInstance);
    }
  }
  else {
    Raziel.invincibleTimer = Raziel.invincibleTimer - gameTrackerX.timeMult;
    if (Raziel.invincibleTimer < 0) {
      Raziel.invincibleTimer = 0;
    }
    if (Raziel.CurrentPlane == 1) {
      number = (int)Raziel.HealthScale;
      max_health = number * 100000;
      Data = Raziel.HitPoints + -100000;
      goto LAB_800a4cf4;
    }
  }
  number = 0;
  max_health = 100000;
  Data = Raziel.HitPoints;
LAB_800a4cf4:
  FX_Health_Spiral(number,Data,max_health);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HealthCheckForLowHealth()
 // line 290, offset 0x800a4d0c
	/* begin block 1 */
		// Start line: 645
	/* end block 1 */
	// End Line: 646

/* WARNING: Unknown calling convention yet parameter storage is locked */

int HealthCheckForLowHealth(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = STREAM_IsMorphInProgress();
  iVar2 = 1;
  if (iVar1 == 0) {
    if (Raziel.CurrentPlane == 1) {
      iVar2 = 0;
      if (Raziel.HitPoints < 0x18704) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = 1;
      if (99 < Raziel.HitPoints) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrainMana(int amount /*$a0*/)
 // line 312, offset 0x800a4d78
	/* begin block 1 */
		// Start line: 689
	/* end block 1 */
	// End Line: 690

	/* begin block 2 */
		// Start line: 690
	/* end block 2 */
	// End Line: 691

void DrainMana(int amount)

{
  uint uVar1;
  
  uVar1 = (uint)Raziel.GlyphManaBalls;
  Raziel.GlyphManaBalls = (ushort)(uVar1 - amount);
  if ((uVar1 - amount & 0xffff) == 0) {
    Raziel.GlyphManaBalls = 0;
  }
  if (Raziel.GlyphManaMax < Raziel.GlyphManaBalls) {
    Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetMana(int amount /*$a0*/)
 // line 322, offset 0x800a4dbc
	/* begin block 1 */
		// Start line: 709
	/* end block 1 */
	// End Line: 710

	/* begin block 2 */
		// Start line: 710
	/* end block 2 */
	// End Line: 711

void SetMana(int amount)

{
  if (amount < 1) {
    Raziel.GlyphManaBalls = 0;
    return;
  }
  Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HealthInstantDeath(struct _Instance *instance /*$a0*/)
 // line 331, offset 0x800a4de4
	/* begin block 1 */
		// Start line: 727
	/* end block 1 */
	// End Line: 728

void HealthInstantDeath(_Instance *instance)

{
  gameTrackerX.gameData.asmData.MorphType = 1;
  razSpectralShift();
  Raziel.HitPoints = (int)&DAT_0000c350;
  gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
  if (Raziel.soulReaver != (_Instance *)0x0) {
    INSTANCE_Post(Raziel.soulReaver,0x800105,0);
  }
  razSetPlayerEventHistory(0x8000);
  Raziel.playerEvent = Raziel.playerEvent | 0x8000;
  razPlayUnderworldSounds(gameTrackerX.playerInstance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthSetScale(long healthScale /*$a0*/)
 // line 350, offset 0x800a4e64
	/* begin block 1 */
		// Start line: 769
	/* end block 1 */
	// End Line: 770

	/* begin block 2 */
		// Start line: 774
	/* end block 2 */
	// End Line: 775

void RAZIEL_DebugHealthSetScale(long healthScale)

{
  Raziel.HealthScale = (short)healthScale;
  Raziel.HealthBalls = (Raziel.HealthScale + -1) * 5;
  Raziel.HitPoints = (int)Raziel.HealthScale * 100000 + 100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugManaSetMax(long manaScale /*$a0*/)
 // line 361, offset 0x800a4ebc
	/* begin block 1 */
		// Start line: 796
	/* end block 1 */
	// End Line: 797

	/* begin block 2 */
		// Start line: 798
	/* end block 2 */
	// End Line: 799

void RAZIEL_DebugManaSetMax(long manaScale)

{
  Raziel.GlyphManaBalls = (ushort)(manaScale << 2);
  Raziel.GlyphManaMax = Raziel.GlyphManaBalls;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthFillUp()
 // line 370, offset 0x800a4ed0
	/* begin block 1 */
		// Start line: 814
	/* end block 1 */
	// End Line: 815

	/* begin block 2 */
		// Start line: 815
	/* end block 2 */
	// End Line: 816

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugHealthFillUp(void)

{
  if (Raziel.CurrentPlane == 1) {
    Raziel.HitPoints = (int)Raziel.HealthScale * 100000 + 100000;
    return;
  }
  Raziel.HitPoints = 100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugManaFillUp()
 // line 382, offset 0x800a4f30
	/* begin block 1 */
		// Start line: 838
	/* end block 1 */
	// End Line: 839

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugManaFillUp(void)

{
  SetMana(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razPlayUnderworldSounds(struct _Instance *instance /*$s3*/)
 // line 390, offset 0x800a4f50
	/* begin block 1 */
		// Start line: 854
	/* end block 1 */
	// End Line: 855

void razPlayUnderworldSounds(_Instance *instance)

{
  if (Raziel.soundHandle != 0) {
    SndEndLoop(Raziel.soundHandle);
    Raziel.soundHandle = 0;
  }
  razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x1a,-0xfa,-0xfa,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x1a,-300,-300,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x12,-0xdc,-0xdc,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x1a,-0xfa,-0xfa,0x78,0x78,0,0xdac);
  return;
}





