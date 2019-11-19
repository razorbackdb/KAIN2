#include "THISDUST.H"
#include "HEALTH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitHealthSystem()
 // line 4, offset 0x800a0f5c
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
  iVar1 = strcmp("under1",gameTrackerX.baseAreaName);
  if (iVar1 == 0) {
    Raziel.HitPoints = 50000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GainHealth(int data /*$a0*/)
 // line 27, offset 0x800a0ff0
	/* begin block 1 */
		// Start line: 61
	/* end block 1 */
	// End Line: 62

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
 // line 40, offset 0x800a107c
	/* begin block 1 */
		// Start line: 87
	/* end block 1 */
	// End Line: 88

	/* begin block 2 */
		// Start line: 88
	/* end block 2 */
	// End Line: 89

void LoseHealth(int amount)

{
  if (Raziel.invincibleTimer == 0) {
    amount = amount * 20000;
    if (amount < 0) {
      amount = amount + 0xfff;
    }
    Raziel.HitPoints = Raziel.HitPoints - (amount >> 0xc);
    Raziel.DamageFrequency = Raziel.DamageFrequency - (amount >> 0xc);
    Raziel.invincibleTimer = (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x34) * 0x1e000;
    if (Raziel.CurrentPlane == 1) {
      razReaverOff();
    }
    if ((gameTrackerX.gameFlags & 0x80U) == 0) {
      GAMEPAD_Shock0(1,9000);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrainHealth(int amount /*$a0*/)
 // line 56, offset 0x800a1130
	/* begin block 1 */
		// Start line: 122
	/* end block 1 */
	// End Line: 123

	/* begin block 2 */
		// Start line: 127
	/* end block 2 */
	// End Line: 128

void DrainHealth(int amount)

{
  int iVar1;
  
  if (Raziel.CurrentPlane == 1) {
    iVar1 = (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x30);
  }
  else {
    iVar1 = -(int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x32);
  }
  iVar1 = iVar1 * amount * gameTrackerX.idleTime;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xffffff;
  }
  Raziel.HitPoints = Raziel.HitPoints + (iVar1 >> 0x18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ BumpUpHealth()
 // line 73, offset 0x800a11a8
	/* begin block 1 */
		// Start line: 156
	/* end block 1 */
	// End Line: 157

	/* begin block 2 */
		// Start line: 157
	/* end block 2 */
	// End Line: 158

/* WARNING: Unknown calling convention yet parameter storage is locked */

void BumpUpHealth(void)

{
  if (Raziel.CurrentPlane == 1) {
    Raziel.HealthScale = Raziel.HealthScale + 1;
    Raziel.HitPoints =
         ((Raziel.HitPoints + -100000) * (int)Raziel.HealthScale) / ((int)Raziel.HealthScale + -1) +
         100000;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetMaxHealth()
 // line 84, offset 0x800a1208
	/* begin block 1 */
		// Start line: 182
	/* end block 1 */
	// End Line: 183

	/* begin block 2 */
		// Start line: 183
	/* end block 2 */
	// End Line: 184

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
 // line 101, offset 0x800a1258
	/* begin block 1 */
		// Start line: 102
		// Start offset: 0x800A1258

		/* begin block 1.1 */
			// Start line: 183
			// Start offset: 0x800A1420
		/* end block 1.1 */
		// End offset: 0x800A14B4
		// End Line: 196
	/* end block 1 */
	// End offset: 0x800A1590
	// End Line: 242

	/* begin block 2 */
		// Start line: 196
	/* end block 2 */
	// End Line: 197

	/* begin block 3 */
		// Start line: 246
	/* end block 3 */
	// End Line: 247

void ProcessHealth(_Instance *instance)

{
  int current_health;
  int number;
  int max_health;
  
  if (Raziel.invincibleTimer == 0) {
    current_health = GetMaxHealth();
    if ((Raziel.HitPoints == current_health) || (Raziel.CurrentPlane == 2)) {
      razReaverOn();
    }
    else {
      razReaverOff();
    }
    if (Raziel.CurrentPlane == 1) {
      if ((Raziel.soulReaver == (_Instance *)0x0) ||
         (current_health = GetMaxHealth(), Raziel.HitPoints != current_health)) {
        current_health =
             (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x30) * gameTrackerX.idleTime;
        if (current_health < 0) {
          current_health = current_health + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (current_health >> 0xc);
      }
      if (Raziel.HitPoints < 100000) {
        razPlaneShift(instance);
        Raziel.invincibleTimer = (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x36) * 0x1e000;
      }
      else {
        if (Raziel.HitPoints < 150000) {
          current_health = gameTrackerX.idleTime * 1000;
          if (current_health < 0) {
            current_health = current_health + 0xfff;
          }
          Raziel.DamageFrequency = Raziel.DamageFrequency - (current_health >> 0xc);
          if (Raziel.DamageFrequency < 0) {
            Raziel.DamageFrequency = Raziel.HitPoints + -100000;
            if (Raziel.DamageFrequency < 0x493e) {
              Raziel.DamageFrequency = 0x493e;
            }
            FX_DoInstancePowerRing
                      (instance,0x2ee - ((50000 - Raziel.DamageFrequency) * 300) / 0x7a12,
                       (long *)0x0,0,0);
            if ((gameTrackerX.gameFlags & 0x80U) == 0) {
              GAMEPAD_Shock1(0x80,0x5000);
            }
          }
        }
      }
      number = (int)Raziel.HealthScale;
      current_health = Raziel.HitPoints + -100000;
      max_health = number * 100000;
      goto LAB_800a1588;
    }
    if (Raziel.HitPoints < 100000) {
      current_health =
           (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x32) * gameTrackerX.idleTime;
      if (current_health < 0) {
        current_health = current_health + 0xfff;
      }
      Raziel.HitPoints = Raziel.HitPoints + (current_health >> 0xc);
    }
    else {
      Raziel.HitPoints = 100000;
    }
    if (Raziel.HitPoints < 0) {
      gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
      Raziel.HitPoints = 50000;
      gameTrackerX.gameData.asmData.MorphType = 1;
    }
  }
  else {
    Raziel.invincibleTimer = Raziel.invincibleTimer - gameTrackerX.idleTime;
    if (Raziel.invincibleTimer < 0) {
      Raziel.invincibleTimer = 0;
    }
    if (Raziel.CurrentPlane == 1) {
      number = (int)Raziel.HealthScale;
      max_health = number * 100000;
      current_health = Raziel.HitPoints + -100000;
      goto LAB_800a1588;
    }
  }
  number = 0;
  max_health = 100000;
  current_health = Raziel.HitPoints;
LAB_800a1588:
  FX_Health_Spiral(number,current_health,max_health);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HealthCheckForLowHealth()
 // line 245, offset 0x800a15a0
	/* begin block 1 */
		// Start line: 538
	/* end block 1 */
	// End Line: 539

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
 // line 267, offset 0x800a160c
	/* begin block 1 */
		// Start line: 582
	/* end block 1 */
	// End Line: 583

	/* begin block 2 */
		// Start line: 583
	/* end block 2 */
	// End Line: 584

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
 // line 277, offset 0x800a1650
	/* begin block 1 */
		// Start line: 602
	/* end block 1 */
	// End Line: 603

	/* begin block 2 */
		// Start line: 603
	/* end block 2 */
	// End Line: 604

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
 // line 286, offset 0x800a1678
	/* begin block 1 */
		// Start line: 620
	/* end block 1 */
	// End Line: 621

void HealthInstantDeath(_Instance *instance)

{
  gameTrackerX.gameData.asmData.MorphType = 1;
  razSpectralShift();
  Raziel.HitPoints = 50000;
  gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthSetScale(long healthScale /*$a0*/)
 // line 300, offset 0x800a16bc
	/* begin block 1 */
		// Start line: 651
	/* end block 1 */
	// End Line: 652

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

void RAZIEL_DebugHealthSetScale(long healthScale)

{
  Raziel.HealthScale = (short)healthScale;
  Raziel.HealthBalls = (Raziel.HealthScale + -1) * 5;
  Raziel.HitPoints = (int)Raziel.HealthScale * 100000 + 100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHealthFillUp()
 // line 311, offset 0x800a1714
	/* begin block 1 */
		// Start line: 678
	/* end block 1 */
	// End Line: 679

	/* begin block 2 */
		// Start line: 679
	/* end block 2 */
	// End Line: 680

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





