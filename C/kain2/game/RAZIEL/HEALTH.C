#include "THISDUST.H"
#include "HEALTH.H"

// decompiled code
// original method signature:
// void /*$ra*/ InitHealthSystem()
// line 4, offset 0x800a45c8
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
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    Raziel.CurrentPlane = 2;
    Raziel.HitPoints = (int)&LAB_000186a0;
    razMaterialShift();
  }
  else
  {
    Raziel.CurrentPlane = 1;
    Raziel.HitPoints = GetMaxHealth();
    razSpectralShift();
  }
  iVar1 = razInBaseArea(s_under_800cf860, 5);
  if (iVar1 == 0)
  {
    razSetPlayerEventHistory(0x1000);
  }
  else
  {
    Raziel.HitPoints = 100;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GainHealth(int data /*$a0*/)
// line 32, offset 0x800a4668
/* begin block 1 */
// Start line: 71
/* end block 1 */
// End Line: 72

void GainHealth(int data)

{
  int iVar1;

  data = data * 20000;
  if (data < 0)
  {
    data = data + 0xfff;
  }
  Raziel.HitPoints = Raziel.HitPoints + (data >> 0xc);
  iVar1 = GetMaxHealth();
  if ((iVar1 <= Raziel.HitPoints) && (Raziel.CurrentPlane == 1))
  {
    Raziel.HitPoints = GetMaxHealth();
    razReaverOn();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LoseHealth(int amount /*$a0*/)
// line 47, offset 0x800a46f4
/* begin block 1 */
// Start line: 101
/* end block 1 */
// End Line: 102

void LoseHealth(int amount)

{
  if ((((ControlFlag & 0x1000000U) == 0) && (Raziel.invincibleTimer == 0)) &&
      (0x20d < Raziel.HitPoints))
  {
    amount = amount * 20000;
    if (amount < 0)
    {
      amount = amount + 0xfff;
    }
    Raziel.HitPoints = Raziel.HitPoints - (amount >> 0xc);
    Raziel.DamageFrequency = Raziel.DamageFrequency - (amount >> 0xc);
    Raziel.invincibleTimer = (int)PlayerData->healthInvinciblePostHit * 0x1e000;
    if (Raziel.CurrentPlane == 1)
    {
      razReaverOff();
      if (Raziel.soulReaver != (_Instance *)0x0)
      {
        INSTANCE_Post(Raziel.soulReaver, 0x800101, 0);
        razReaverImbue(2);
      }
    }
    if ((gameTrackerX.gameFlags & 0x80U) == 0)
    {
      GAMEPAD_Shock0(1, (int)&DAT_00002328);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ DrainHealth(int amount /*$a0*/)
// line 72, offset 0x800a47f0
/* begin block 1 */
// Start line: 153
/* end block 1 */
// End Line: 154

void DrainHealth(int amount)

{
  int iVar1;

  if ((ControlFlag & 0x1000000U) == 0)
  {
    if (amount < 0)
    {
      amount = amount + 0xfff;
    }
    if (Raziel.CurrentPlane == 1)
    {
      iVar1 = (int)PlayerData->healthMaterialRate * (amount >> 0xc) * gameTrackerX.timeMult;
      if (iVar1 < 0)
      {
        iVar1 = iVar1 + 0xfff;
      }
      Raziel.HitPoints = Raziel.HitPoints + (iVar1 >> 0xc);
      if (Raziel.soulReaver != (_Instance *)0x0)
      {
        INSTANCE_Post(Raziel.soulReaver, 0x800101, 0);
        razReaverImbue(2);
      }
    }
    else
    {
      if ((Raziel.invincibleTimer == 0) && (0x20d < Raziel.HitPoints))
      {
        iVar1 = -(int)PlayerData->healthSpectralRate * (amount >> 0xc) * gameTrackerX.timeMult;
        if (iVar1 < 0)
        {
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
// line 97, offset 0x800a490c
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
  if (4 < Raziel.HealthScale)
  {
    Raziel.HealthScale = 4;
  }
  Raziel.HitPoints = GetMaxHealth();
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetMaxHealth()
// line 115, offset 0x800a4950
/* begin block 1 */
// Start line: 251
/* end block 1 */
// End Line: 252

/* begin block 2 */
// Start line: 252
/* end block 2 */
// End Line: 253

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GetMaxHealth(void)

{
  if (Raziel.CurrentPlane != 2)
  {
    return ((int)Raziel.HealthScale + 1) * 100000;
  }
  return (int)&LAB_000186a0;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessHealth(struct _Instance *instance /*$s0*/)
// line 132, offset 0x800a49a0
/* begin block 1 */
// Start line: 133
// Start offset: 0x800A49A0

/* begin block 1.1 */
// Start line: 228
// Start offset: 0x800A4BC8
/* end block 1.1 */
// End offset: 0x800A4C5C
// End Line: 241
/* end block 1 */
// End offset: 0x800A4E3C
// End Line: 289

/* begin block 2 */
// Start line: 264
/* end block 2 */
// End Line: 265

/* begin block 3 */
// Start line: 319
/* end block 3 */
// End Line: 320

void ProcessHealth(_Instance *instance)

{
  int Data;
  int number;
  undefined *max_health;

  if ((Raziel.invincibleTimer == 0) && ((Raziel.playerEventHistory & 0x1000) != 0))
  {
    Data = GetMaxHealth();
    if ((Raziel.HitPoints == Data) || (Raziel.CurrentPlane == 2))
    {
      razReaverOn();
    }
    else
    {
      razReaverOff();
    }
    if (Raziel.CurrentPlane == 1)
    {
      if ((instance->waterFace != (_TFace *)0x0) && ((Raziel.Abilities & 0x10U) == 0))
      {
        DrainHealth((int)&DAT_0000a000);
      }
      if ((Raziel.soulReaver == (_Instance *)0x0) ||
          (Data = GetMaxHealth(), Raziel.HitPoints != Data))
      {
        Data = (int)PlayerData->healthMaterialRate * gameTrackerX.timeMult;
        if (Data < 0)
        {
          Data = Data + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (Data >> 0xc);
      }
      if (Raziel.HitPoints < 100000)
      {
        razPlaneShift(instance);
        Raziel.invincibleTimer = (int)PlayerData->healthInvinciblePostShunt * 0x1e000;
        if ((Raziel.Mode & 0x40000U) != 0)
        {
          CAMERA_ChangeToOutOfWater(&theCamera, instance);
        }
      }
      else
      {
        if (Raziel.HitPoints < 150000)
        {
          Data = gameTrackerX.timeMult * 1000;
          if (Data < 0)
          {
            Data = Data + 0xfff;
          }
          Raziel.DamageFrequency = Raziel.DamageFrequency - (Data >> 0xc);
          if (Raziel.DamageFrequency < 0)
          {
            Raziel.DamageFrequency = Raziel.HitPoints + -100000;
            if (Raziel.DamageFrequency < 0x493e)
            {
              Raziel.DamageFrequency = (int)&DAT_0000493e;
            }
            FX_DoInstancePowerRing(instance, 0x2ee - ((int)(&DAT_0000c350 + -Raziel.DamageFrequency) * 300) / 0x7a12, (long *)0x0, 0, 0);
            if ((gameTrackerX.gameFlags & 0x80U) == 0)
            {
              GAMEPAD_Shock1(0x80, (int)&DAT_00005000);
            }
          }
        }
      }
      number = (int)Raziel.HealthScale;
      Data = Raziel.HitPoints + -100000;
      max_health = (undefined *)(number * 100000);
      goto LAB_800a4e34;
    }
    if (Raziel.HitPoints < 0x20e)
    {
      Data = (int)PlayerData->healthSpectralRate * gameTrackerX.timeMult;
      if (Data < 0)
      {
        Data = Data + 0xfff;
      }
      Raziel.HitPoints = Raziel.HitPoints - (Data >> 0xc);
    }
    else
    {
      if (Raziel.HitPoints < 100000)
      {
        Data = (int)PlayerData->healthSpectralRate * gameTrackerX.timeMult;
        if (Data < 0)
        {
          Data = Data + 0xfff;
        }
        Raziel.HitPoints = Raziel.HitPoints + (Data >> 0xc);
      }
      else
      {
        Raziel.HitPoints = (int)&LAB_000186a0;
      }
    }
    if (((ControlFlag & 0x800000U) == 0) && (Raziel.HitPoints < 0x20d))
    {
      Data = SetControlInitIdleData(0, 0, 3);
      StateSwitchStateCharacterData(&Raziel.State, StateHandlerIdle, Data);
      G2EmulationSwitchAnimationCharacter(&Raziel.State, 0xd6, 0, 3, 1);
      Raziel.HitPoints = 0x20d;
      ControlFlag = ControlFlag | 0x804000;
    }
    if (Raziel.HitPoints < 0)
    {
      gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
      if (Raziel.soulReaver != (_Instance *)0x0)
      {
        INSTANCE_Post(Raziel.soulReaver, 0x800105, 0);
      }
      razSetPlayerEventHistory(0x8000);
      Raziel.HitPoints = (int)&DAT_0000c350;
      gameTrackerX.gameData.asmData.MorphType = 1;
      Raziel.playerEvent = Raziel.playerEvent | 0x8000;
      razPlayUnderworldSounds(gameTrackerX.playerInstance);
    }
  }
  else
  {
    Raziel.invincibleTimer = Raziel.invincibleTimer - gameTrackerX.timeMult;
    if (Raziel.invincibleTimer < 0)
    {
      Raziel.invincibleTimer = 0;
    }
    if (Raziel.CurrentPlane == 1)
    {
      number = (int)Raziel.HealthScale;
      max_health = (undefined *)(number * 100000);
      Data = Raziel.HitPoints + -100000;
      goto LAB_800a4e34;
    }
  }
  number = 0;
  max_health = &LAB_000186a0;
  Data = Raziel.HitPoints;
LAB_800a4e34:
  FX_Health_Spiral(number, Data, (int)max_health);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ HealthCheckForLowHealth()
// line 292, offset 0x800a4e4c
/* begin block 1 */
// Start line: 649
/* end block 1 */
// End Line: 650

/* WARNING: Unknown calling convention yet parameter storage is locked */

int HealthCheckForLowHealth(void)

{
  int iVar1;
  int iVar2;

  iVar1 = STREAM_IsMorphInProgress();
  iVar2 = 1;
  if (iVar1 == 0)
  {
    if (Raziel.CurrentPlane == 1)
    {
      iVar2 = 0;
      if (Raziel.HitPoints < 0x18704)
      {
        iVar2 = 1;
      }
    }
    else
    {
      iVar2 = 1;
      if (99 < Raziel.HitPoints)
      {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ DrainMana(int amount /*$a0*/)
// line 314, offset 0x800a4eb8
/* begin block 1 */
// Start line: 693
/* end block 1 */
// End Line: 694

/* begin block 2 */
// Start line: 694
/* end block 2 */
// End Line: 695

void DrainMana(int amount)

{
  uint uVar1;

  uVar1 = (uint)Raziel.GlyphManaBalls;
  Raziel.GlyphManaBalls = (ushort)(uVar1 - amount);
  if ((uVar1 - amount & 0xffff) == 0)
  {
    Raziel.GlyphManaBalls = 0;
  }
  if (Raziel.GlyphManaMax < Raziel.GlyphManaBalls)
  {
    Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SetMana(int amount /*$a0*/)
// line 324, offset 0x800a4efc
/* begin block 1 */
// Start line: 713
/* end block 1 */
// End Line: 714

/* begin block 2 */
// Start line: 714
/* end block 2 */
// End Line: 715

void SetMana(int amount)

{
  if (amount < 1)
  {
    Raziel.GlyphManaBalls = 0;
    return;
  }
  Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HealthInstantDeath(struct _Instance *instance /*$a0*/)
// line 333, offset 0x800a4f24
/* begin block 1 */
// Start line: 731
/* end block 1 */
// End Line: 732

void HealthInstantDeath(_Instance *instance)

{
  gameTrackerX.gameData.asmData.MorphType = 1;
  razSpectralShift();
  Raziel.HitPoints = (int)&DAT_0000c350;
  gameTracker->streamFlags = gameTracker->streamFlags | 0x80000;
  if (Raziel.soulReaver != (_Instance *)0x0)
  {
    INSTANCE_Post(Raziel.soulReaver, 0x800105, 0);
  }
  razSetPlayerEventHistory(0x8000);
  Raziel.playerEvent = Raziel.playerEvent | 0x8000;
  razPlayUnderworldSounds(gameTrackerX.playerInstance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_DebugHealthSetScale(long healthScale /*$a0*/)
// line 352, offset 0x800a4fa4
/* begin block 1 */
// Start line: 773
/* end block 1 */
// End Line: 774

/* begin block 2 */
// Start line: 778
/* end block 2 */
// End Line: 779

void RAZIEL_DebugHealthSetScale(long healthScale)

{
  Raziel.HealthScale = (short)healthScale;
  Raziel.HealthBalls = (Raziel.HealthScale + -1) * 5;
  Raziel.HitPoints = (int)(&LAB_000186a0 + (int)Raziel.HealthScale * 100000);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_DebugManaSetMax(long manaScale /*$a0*/)
// line 363, offset 0x800a4ffc
/* begin block 1 */
// Start line: 800
/* end block 1 */
// End Line: 801

/* begin block 2 */
// Start line: 802
/* end block 2 */
// End Line: 803

void RAZIEL_DebugManaSetMax(long manaScale)

{
  Raziel.GlyphManaBalls = (ushort)(manaScale << 2);
  Raziel.GlyphManaMax = Raziel.GlyphManaBalls;
  if (0x34 < (manaScale << 2 & 0xfffcU))
  {
    Raziel.GlyphManaMax = 0x34;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_DebugHealthFillUp()
// line 375, offset 0x800a5024
/* begin block 1 */
// Start line: 824
/* end block 1 */
// End Line: 825

/* begin block 2 */
// Start line: 825
/* end block 2 */
// End Line: 826

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugHealthFillUp(void)

{
  if (Raziel.CurrentPlane == 1)
  {
    Raziel.HitPoints = (int)(&LAB_000186a0 + (int)Raziel.HealthScale * 100000);
    return;
  }
  Raziel.HitPoints = (int)&LAB_000186a0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_DebugManaFillUp()
// line 387, offset 0x800a5084
/* begin block 1 */
// Start line: 848
/* end block 1 */
// End Line: 849

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugManaFillUp(void)

{
  SetMana(1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ razPlayUnderworldSounds(struct _Instance *instance /*$s3*/)
// line 395, offset 0x800a50a4
/* begin block 1 */
// Start line: 864
/* end block 1 */
// End Line: 865

void razPlayUnderworldSounds(_Instance *instance)

{
  if (Raziel.soundHandle != 0)
  {
    SndEndLoop(Raziel.soundHandle);
    Raziel.soundHandle = 0;
  }
  razSetupSoundRamp(instance, (_SoundRamp *)&Raziel.soundHandle, 0x1a, -0xfa, -0xfa, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&Raziel.soundHandle, 0x1a, -300, -300, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&Raziel.soundHandle, 0x12, -0xdc, -0xdc, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&Raziel.soundHandle, 0x1a, -0xfa, -0xfa, 0x78, 0x78, 0, 0xdac);
  return;
}
