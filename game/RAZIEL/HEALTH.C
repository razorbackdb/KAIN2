
#include "HEALTH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitHealthSystem()
 // line 4, offset 0x800a3730
	/* begin block 1 */
		// Start line: 8
	/* end block 1 */
	// End Line: 9

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void InitHealthSystem(void)

{
  int iVar1;
  
  DAT_800d5b40 = 0;
  DAT_800d5b38 = 1;
  DAT_800d5b3a = 0;
  DAT_800d5b50 = 0;
  if (DAT_800d20d6 == 0) {
    DAT_800d5b78 = 2;
    DAT_800d5b3c = 100000;
    razMaterialShift();
  }
  else {
    DAT_800d5b78 = 1;
    DAT_800d5b3c = GetMaxHealth();
    razSpectralShift();
  }
  iVar1 = razInBaseArea(s_under_800d0ae0,5);
  if (iVar1 == 0) {
    razSetPlayerEventHistory(0x1000);
  }
  else {
    DAT_800d5b3c = 100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GainHealth(int data /*$a0*/)
 // line 32, offset 0x800a37d0
	/* begin block 1 */
		// Start line: 71
	/* end block 1 */
	// End Line: 72

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void GainHealth(int data)

{
  int iVar1;
  
  data = data * 20000;
  if (data < 0) {
    data = data + 0xfff;
  }
  DAT_800d5b3c = DAT_800d5b3c + (data >> 0xc);
  iVar1 = GetMaxHealth();
  if ((iVar1 <= DAT_800d5b3c) && (DAT_800d5b78 == 1)) {
    DAT_800d5b3c = GetMaxHealth();
    razReaverOn();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LoseHealth(int amount /*$a0*/)
 // line 47, offset 0x800a385c
	/* begin block 1 */
		// Start line: 101
	/* end block 1 */
	// End Line: 102

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void LoseHealth(int amount)

{
  if ((((ControlFlag & 0x1000000U) == 0) && (DAT_800d5b44 == 0)) && (0x20d < DAT_800d5b3c)) {
    amount = amount * 20000;
    if (amount < 0) {
      amount = amount + 0xfff;
    }
    DAT_800d5b3c = DAT_800d5b3c - (amount >> 0xc);
    DAT_800d5b40 = DAT_800d5b40 - (amount >> 0xc);
    DAT_800d5b44 = (int)*(short *)(PlayerData + 0x34) * 0x1e000;
    if (DAT_800d5b78 == 1) {
      razReaverOff();
    }
    if ((DAT_800d220c & 0x80) == 0) {
      GAMEPAD_Shock0(1,(int)&DAT_00002328);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrainHealth(int amount /*$a0*/)
 // line 67, offset 0x800a3934
	/* begin block 1 */
		// Start line: 143
	/* end block 1 */
	// End Line: 144

	/* begin block 2 */
		// Start line: 145
	/* end block 2 */
	// End Line: 146

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void DrainHealth(int amount)

{
  int iVar1;
  int iVar2;
  
  if ((ControlFlag & 0x1000000U) == 0) {
    if (amount < 0) {
      amount = amount + 0xfff;
    }
    if (DAT_800d5b78 == 1) {
      iVar1 = (int)*(short *)(PlayerData + 0x30) * (amount >> 0xc) * DAT_800d2314;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0xfff;
      }
      iVar2 = DAT_800d5b3c;
      DAT_800d5b3c = iVar1 >> 0xc;
    }
    else {
      if (DAT_800d5b44 != 0) {
        return;
      }
      if (DAT_800d5b3c < 0x20e) {
        return;
      }
      iVar2 = -(int)*(short *)(PlayerData + 0x32) * (amount >> 0xc) * DAT_800d2314;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      iVar2 = iVar2 >> 0xc;
    }
    DAT_800d5b3c = DAT_800d5b3c + iVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ BumpUpHealth()
 // line 88, offset 0x800a3a18
	/* begin block 1 */
		// Start line: 185
	/* end block 1 */
	// End Line: 186

	/* begin block 2 */
		// Start line: 194
	/* end block 2 */
	// End Line: 195

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void BumpUpHealth(void)

{
  DAT_800d5b38 = DAT_800d5b38 + 1;
  DAT_800d5b3c = GetMaxHealth();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetMaxHealth()
 // line 104, offset 0x800a3a44
	/* begin block 1 */
		// Start line: 226
	/* end block 1 */
	// End Line: 227

	/* begin block 2 */
		// Start line: 227
	/* end block 2 */
	// End Line: 228

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

int GetMaxHealth(void)

{
  if (DAT_800d5b78 != 2) {
    return ((int)DAT_800d5b38 + 1) * 100000;
  }
  return 100000;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessHealth(struct _Instance *instance /*$s0*/)
 // line 121, offset 0x800a3a94
	/* begin block 1 */
		// Start line: 122
		// Start offset: 0x800A3A94

		/* begin block 1.1 */
			// Start line: 217
			// Start offset: 0x800A3CC0
		/* end block 1.1 */
		// End offset: 0x800A3D54
		// End Line: 230
	/* end block 1 */
	// End offset: 0x800A3F3C
	// End Line: 278

	/* begin block 2 */
		// Start line: 236
	/* end block 2 */
	// End Line: 237

	/* begin block 3 */
		// Start line: 294
	/* end block 3 */
	// End Line: 295

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void ProcessHealth(_Instance *instance)

{
  int Data;
  undefined *current_health;
  int max_health;
  
  if ((DAT_800d5b44 == 0) && ((DAT_800d5cec & 0x1000) != 0)) {
    current_health = (undefined *)GetMaxHealth();
    if ((DAT_800d5b3c == current_health) || (DAT_800d5b78 == 2)) {
      razReaverOn();
    }
    else {
      razReaverOff();
    }
    if (DAT_800d5b78 == 1) {
      if ((instance->waterFace != (_TFace *)0x0) && ((DAT_800d5b48 & 0x10) == 0)) {
        DrainHealth((int)&DAT_0000a000);
      }
      if ((DAT_800d5b70 == (_Instance *)0x0) ||
         (current_health = (undefined *)GetMaxHealth(), DAT_800d5b3c != current_health)) {
        Data = *(short *)(PlayerData + 0x30) * DAT_800d2314;
        if (Data < 0) {
          Data = Data + 0xfff;
        }
        DAT_800d5b3c = DAT_800d5b3c + (Data >> 0xc);
      }
      if ((int)DAT_800d5b3c < 100000) {
        razPlaneShift(instance);
        DAT_800d5b44 = (int)*(short *)(PlayerData + 0x36) * 0x1e000;
        if ((DAT_800d5aa4 & 0x40000) != 0) {
          CAMERA_ChangeToOutOfWater((Camera *)&theCamera,instance);
        }
      }
      else {
        if ((int)DAT_800d5b3c < 150000) {
          Data = DAT_800d2314 * 1000;
          if (Data < 0) {
            Data = Data + 0xfff;
          }
          DAT_800d5b40 = DAT_800d5b40 + -(Data >> 0xc);
          if ((int)DAT_800d5b40 < 0) {
            DAT_800d5b40 = DAT_800d5b3c + -100000;
            if ((int)DAT_800d5b40 < 0x493e) {
              DAT_800d5b40 = &DAT_0000493e;
            }
            FX_DoInstancePowerRing
                      (instance,0x2ee - ((int)(&DAT_0000c350 + -(int)DAT_800d5b40) * 300) / 0x7a12,
                       (long *)0x0,0,0);
            if ((DAT_800d220c & 0x80) == 0) {
              GAMEPAD_Shock1(0x80,(int)&DAT_00005000);
            }
          }
        }
      }
      Data = (int)DAT_800d5b38;
      current_health = DAT_800d5b3c + -100000;
      max_health = Data * 100000;
      goto LAB_800a3f34;
    }
    if ((int)DAT_800d5b3c < 0x20e) {
      Data = *(short *)(PlayerData + 0x32) * DAT_800d2314;
      if (Data < 0) {
        Data = Data + 0xfff;
      }
      DAT_800d5b3c = DAT_800d5b3c + -(Data >> 0xc);
    }
    else {
      if ((int)DAT_800d5b3c < 100000) {
        Data = *(short *)(PlayerData + 0x32) * DAT_800d2314;
        if (Data < 0) {
          Data = Data + 0xfff;
        }
        DAT_800d5b3c = DAT_800d5b3c + (Data >> 0xc);
      }
      else {
        DAT_800d5b3c = (undefined *)0x186a0;
      }
    }
    if (((ControlFlag & 0x800000U) == 0) && ((int)DAT_800d5b3c < 0x20d)) {
      Data = SetControlInitIdleData(0,0,3);
      StateSwitchStateCharacterData((__CharacterState *)&DAT_800d5748,StateHandlerIdle,Data);
      G2EmulationSwitchAnimationCharacter((__CharacterState *)&DAT_800d5748,0xd6,0,3,1);
      DAT_800d5b3c = (undefined *)0x20d;
      ControlFlag = ControlFlag | 0x804000;
    }
    if ((int)DAT_800d5b3c < 0) {
      *(uint *)(gameTracker + 0x144) = *(uint *)(gameTracker + 0x144) | 0x80000;
      if (DAT_800d5b70 != (_Instance *)0x0) {
        INSTANCE_Post(DAT_800d5b70,0x800105,0);
      }
      razSetPlayerEventHistory(0x8000);
      DAT_800d5b3c = &DAT_0000c350;
      DAT_800d20d6 = 1;
      DAT_800d5ce8 = DAT_800d5ce8 | 0x8000;
      razPlayUnderworldSounds(DAT_800d20f8);
    }
  }
  else {
    DAT_800d5b44 = DAT_800d5b44 - DAT_800d2314;
    if (DAT_800d5b44 < 0) {
      DAT_800d5b44 = 0;
    }
    if (DAT_800d5b78 == 1) {
      Data = (int)DAT_800d5b38;
      max_health = Data * 100000;
      current_health = DAT_800d5b3c + -100000;
      goto LAB_800a3f34;
    }
  }
  Data = 0;
  max_health = 100000;
  current_health = DAT_800d5b3c;
LAB_800a3f34:
  FX_Health_Spiral(Data,(int)current_health,max_health);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HealthCheckForLowHealth()
 // line 281, offset 0x800a3f4c
	/* begin block 1 */
		// Start line: 624
	/* end block 1 */
	// End Line: 625

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

int HealthCheckForLowHealth(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = STREAM_IsMorphInProgress();
  iVar2 = 1;
  if (iVar1 == 0) {
    if (DAT_800d5b78 == 1) {
      iVar2 = 0;
      if (DAT_800d5b3c < 0x18704) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = 1;
      if (99 < DAT_800d5b3c) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrainMana(int amount /*$a0*/)
 // line 303, offset 0x800a3fb8
	/* begin block 1 */
		// Start line: 668
	/* end block 1 */
	// End Line: 669

	/* begin block 2 */
		// Start line: 669
	/* end block 2 */
	// End Line: 670

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void DrainMana(int amount)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_800d5b50;
  DAT_800d5b50 = (ushort)(uVar1 - amount);
  if ((uVar1 - amount & 0xffff) == 0) {
    DAT_800d5b50 = 0;
  }
  if (DAT_800d5b52 < DAT_800d5b50) {
    DAT_800d5b50 = DAT_800d5b52;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetMana(int amount /*$a0*/)
 // line 313, offset 0x800a3ffc
	/* begin block 1 */
		// Start line: 688
	/* end block 1 */
	// End Line: 689

	/* begin block 2 */
		// Start line: 689
	/* end block 2 */
	// End Line: 690

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void SetMana(int amount)

{
  if (amount < 1) {
    DAT_800d5b50 = 0;
    return;
  }
  DAT_800d5b50 = DAT_800d5b52;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HealthInstantDeath(struct _Instance *instance /*$a0*/)
 // line 322, offset 0x800a4024
	/* begin block 1 */
		// Start line: 706
	/* end block 1 */
	// End Line: 707

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void HealthInstantDeath(_Instance *instance)

{
  DAT_800d20d6 = 1;
  razSpectralShift();
  DAT_800d5b3c = &DAT_0000c350;
  *(uint *)(gameTracker + 0x144) = *(uint *)(gameTracker + 0x144) | 0x80000;
  if (DAT_800d5b70 != (_Instance *)0x0) {
    INSTANCE_Post(DAT_800d5b70,0x800105,0);
  }
  razSetPlayerEventHistory(0x8000);
  DAT_800d5ce8 = DAT_800d5ce8 | 0x8000;
  razPlayUnderworldSounds(DAT_800d20f8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthSetScale(long healthScale /*$a0*/)
 // line 341, offset 0x800a40a4
	/* begin block 1 */
		// Start line: 748
	/* end block 1 */
	// End Line: 749

	/* begin block 2 */
		// Start line: 753
	/* end block 2 */
	// End Line: 754

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void RAZIEL_DebugHealthSetScale(long healthScale)

{
  DAT_800d5b38 = (short)healthScale;
  DAT_800d5b3a = (DAT_800d5b38 + -1) * 5;
  DAT_800d5b3c = (int)DAT_800d5b38 * 100000 + 100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthFillUp()
 // line 352, offset 0x800a40fc
	/* begin block 1 */
		// Start line: 775
	/* end block 1 */
	// End Line: 776

	/* begin block 2 */
		// Start line: 776
	/* end block 2 */
	// End Line: 777

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void RAZIEL_DebugHealthFillUp(void)

{
  if (DAT_800d5b78 == 1) {
    DAT_800d5b3c = (int)DAT_800d5b38 * 100000 + 100000;
    return;
  }
  DAT_800d5b3c = 100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugManaFillUp()
 // line 364, offset 0x800a415c
	/* begin block 1 */
		// Start line: 799
	/* end block 1 */
	// End Line: 800

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void RAZIEL_DebugManaFillUp(void)

{
  SetMana(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razPlayUnderworldSounds(struct _Instance *instance /*$s2*/)
 // line 372, offset 0x800a417c
	/* begin block 1 */
		// Start line: 815
	/* end block 1 */
	// End Line: 816

/* File: C:\kain2\game\RAZIEL\HEALTH.C */

void razPlayUnderworldSounds(_Instance *instance)

{
  razSetupSoundRamp(instance,(_SoundRamp *)&DAT_800d5ca0,0x1a,-0xfa,-0xfa,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&DAT_800d5ca0,0x1a,-300,-300,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&DAT_800d5ca0,0x12,-0xdc,-0xdc,0x78,0x78,0,0xdac);
  razSetupSoundRamp(instance,(_SoundRamp *)&DAT_800d5ca0,0x1a,-0xfa,-0xfa,0x78,0x78,0,0xdac);
  return;
}





