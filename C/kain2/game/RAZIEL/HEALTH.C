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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitHealthSystem(void)

{
  int iVar1;

  _CHAR____800d5614 = 0;
  _CHAR____800d560c = 1;
  _CHAR____800d560e = 0;
  _CHAR____800d5624 = 0;
  if (DAT_800d0fb6 == 0)
  {
    _CHAR____800d564c = 2;
    _CHAR____800d5610 = 100000;
    razMaterialShift();
  }
  else
  {
    _CHAR____800d564c = 1;
    _CHAR____800d5610 = GetMaxHealth();
    razSpectralShift();
  }
  iVar1 = razInBaseArea(s_under_800cf860, 5);
  if (iVar1 == 0)
  {
    razSetPlayerEventHistory(0x1000);
  }
  else
  {
    _CHAR____800d5610 = 100;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GainHealth(int data)

{
  int iVar1;

  data = data * 20000;
  if (data < 0)
  {
    data = data + 0xfff;
  }
  _CHAR____800d5610 = _CHAR____800d5610 + (data >> 0xc);
  iVar1 = GetMaxHealth();
  if ((iVar1 <= _CHAR____800d5610) && (_CHAR____800d564c == 1))
  {
    _CHAR____800d5610 = GetMaxHealth();
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoseHealth(int amount)

{
  if ((((_BlockVramEntry_800d59a0._12_4_ & 0x1000000) == 0) && (_CHAR____800d5618 == 0)) &&
      (0x20d < _CHAR____800d5610))
  {
    amount = amount * 20000;
    if (amount < 0)
    {
      amount = amount + 0xfff;
    }
    _CHAR____800d5610 = _CHAR____800d5610 - (amount >> 0xc);
    _CHAR____800d5614 = _CHAR____800d5614 - (amount >> 0xc);
    _CHAR____800d5618 = (int)*(short *)(_PlayerData + 0x34) * 0x1e000;
    if (_CHAR____800d564c == 1)
    {
      razReaverOff();
      if (_CHAR____800d5644 != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(_CHAR____800d5644, 0x800101, 0);
      }
    }
    if ((DAT_800d10ec & 0x80) == 0)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DrainHealth(int amount)

{
  int iVar1;

  if ((_BlockVramEntry_800d59a0._12_4_ & 0x1000000) == 0)
  {
    if (amount < 0)
    {
      amount = amount + 0xfff;
    }
    if (_CHAR____800d564c == 1)
    {
      iVar1 = (int)*(short *)(_PlayerData + 0x30) * (amount >> 0xc) * DAT_800d11ec;
      if (iVar1 < 0)
      {
        iVar1 = iVar1 + 0xfff;
      }
      _CHAR____800d5610 = _CHAR____800d5610 + (iVar1 >> 0xc);
      if (_CHAR____800d5644 != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(_CHAR____800d5644, 0x800101, 0);
      }
    }
    else
    {
      if ((_CHAR____800d5618 == 0) && (0x20d < _CHAR____800d5610))
      {
        iVar1 = -(int)*(short *)(_PlayerData + 0x32) * (amount >> 0xc) * DAT_800d11ec;
        if (iVar1 < 0)
        {
          iVar1 = iVar1 + 0xfff;
        }
        _CHAR____800d5610 = _CHAR____800d5610 + (iVar1 >> 0xc);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void BumpUpHealth(void)

{
  _CHAR____800d560c = _CHAR____800d560c + 1;
  if (4 < _CHAR____800d560c)
  {
    _CHAR____800d560c = 4;
  }
  _CHAR____800d5610 = GetMaxHealth();
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int GetMaxHealth(void)

{
  if (_CHAR____800d564c != 2)
  {
    return ((int)_CHAR____800d560c + 1) * 100000;
  }
  return 100000;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessHealth(_Instance *instance)

{
  int number;
  undefined *current_health;
  int max_health;
  int in_a3;

  if ((_CHAR____800d5618 == 0) && ((_CHAR____800d57c8 & 0x1000) != 0))
  {
    current_health = (undefined *)GetMaxHealth();
    if ((_CHAR____800d5610 == current_health) || (_CHAR____800d564c == 2))
    {
      razReaverOn();
    }
    else
    {
      razReaverOff();
    }
    if (_CHAR____800d564c == 1)
    {
      if ((instance->waterFace != (_TFace *)0x0) && ((_CHAR____800d561c & 0x10) == 0))
      {
        DrainHealth((int)&DAT_0000a000);
      }
      if ((_CHAR____800d5644 == (_Instance *)0x0) ||
          (current_health = (undefined *)GetMaxHealth(), _CHAR____800d5610 != current_health))
      {
        number = *(short *)(_PlayerData + 0x30) * DAT_800d11ec;
        if (number < 0)
        {
          number = number + 0xfff;
        }
        _CHAR____800d5610 = _CHAR____800d5610 + (number >> 0xc);
      }
      if ((int)_CHAR____800d5610 < 100000)
      {
        razPlaneShift(instance);
        _CHAR____800d5618 = (int)*(short *)(_PlayerData + 0x36) * 0x1e000;
        if ((_CHAR____800d5574 & 0x40000) != 0)
        {
          CAMERA_ChangeToOutOfWater((Camera *)&theCamera, instance);
        }
      }
      else
      {
        if ((int)_CHAR____800d5610 < 150000)
        {
          number = DAT_800d11ec * 1000;
          if (number < 0)
          {
            number = number + 0xfff;
          }
          _CHAR____800d5614 = _CHAR____800d5614 + -(number >> 0xc);
          if ((int)_CHAR____800d5614 < 0)
          {
            _CHAR____800d5614 = _CHAR____800d5610 + -100000;
            if ((int)_CHAR____800d5614 < 0x493e)
            {
              _CHAR____800d5614 = &DAT_0000493e;
            }
            FX_DoInstancePowerRing(instance, 0x2ee - ((int)(&DAT_0000c350 + -(int)_CHAR____800d5614) * 300) / 0x7a12, (long *)0x0, 0, 0);
            if ((DAT_800d10ec & 0x80) == 0)
            {
              GAMEPAD_Shock1(0x80, (int)&DAT_00005000);
            }
          }
        }
      }
      number = (int)_CHAR____800d560c;
      current_health = _CHAR____800d5610 + -100000;
      max_health = number * 100000;
      goto LAB_800a4e34;
    }
    if ((int)_CHAR____800d5610 < 0x20e)
    {
      number = *(short *)(_PlayerData + 0x32) * DAT_800d11ec;
      if (number < 0)
      {
        number = number + 0xfff;
      }
      _CHAR____800d5610 = _CHAR____800d5610 + -(number >> 0xc);
    }
    else
    {
      if ((int)_CHAR____800d5610 < 100000)
      {
        number = *(short *)(_PlayerData + 0x32) * DAT_800d11ec;
        if (number < 0)
        {
          number = number + 0xfff;
        }
        _CHAR____800d5610 = _CHAR____800d5610 + (number >> 0xc);
      }
      else
      {
        _CHAR____800d5610 = (undefined *)0x186a0;
      }
    }
    if (((_BlockVramEntry_800d59a0._12_4_ & 0x800000) == 0) && ((int)_CHAR____800d5610 < 0x20d))
    {
      /* WARNING: Subroutine does not return */
      SetPhysicsWallCrawlData(0, 0, 3, in_a3);
    }
    if ((int)_CHAR____800d5610 < 0)
    {
      *(uint *)&gameTracker.next[0xb].w = *(uint *)&gameTracker.next[0xb].w | 0x80000;
      if (_CHAR____800d5644 != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(_CHAR____800d5644, 0x800105, 0);
      }
      razSetPlayerEventHistory(0x8000);
      _CHAR____800d5610 = &DAT_0000c350;
      DAT_800d0fb6 = 1;
      _CHAR____800d57c4 = _CHAR____800d57c4 | 0x8000;
      razPlayUnderworldSounds(DAT_800d0fd8);
    }
  }
  else
  {
    _CHAR____800d5618 = _CHAR____800d5618 - DAT_800d11ec;
    if (_CHAR____800d5618 < 0)
    {
      _CHAR____800d5618 = 0;
    }
    if (_CHAR____800d564c == 1)
    {
      number = (int)_CHAR____800d560c;
      max_health = number * 100000;
      current_health = _CHAR____800d5610 + -100000;
      goto LAB_800a4e34;
    }
  }
  number = 0;
  max_health = 100000;
  current_health = _CHAR____800d5610;
LAB_800a4e34:
  FX_Health_Spiral(number, (int)current_health, max_health);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int HealthCheckForLowHealth(void)

{
  int iVar1;
  int iVar2;

  iVar1 = STREAM_IsMorphInProgress();
  iVar2 = 1;
  if (iVar1 == 0)
  {
    if (_CHAR____800d564c == 1)
    {
      iVar2 = 0;
      if (_CHAR____800d5610 < 0x18704)
      {
        iVar2 = 1;
      }
    }
    else
    {
      iVar2 = 1;
      if (99 < _CHAR____800d5610)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DrainMana(int amount)

{
  uint uVar1;

  uVar1 = (uint)_CHAR____800d5624;
  _CHAR____800d5624 = (ushort)(uVar1 - amount);
  if ((uVar1 - amount & 0xffff) == 0)
  {
    _CHAR____800d5624 = 0;
  }
  if (_CHAR____800d5626 < _CHAR____800d5624)
  {
    _CHAR____800d5624 = _CHAR____800d5626;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetMana(int amount)

{
  if (amount < 1)
  {
    _CHAR____800d5624 = 0;
    return;
  }
  _CHAR____800d5624 = _CHAR____800d5626;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HealthInstantDeath(_Instance *instance)

{
  DAT_800d0fb6 = 1;
  razSpectralShift();
  _CHAR____800d5610 = &DAT_0000c350;
  *(uint *)&gameTracker.next[0xb].w = *(uint *)&gameTracker.next[0xb].w | 0x80000;
  if (_CHAR____800d5644 != (_Instance *)0x0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(_CHAR____800d5644, 0x800105, 0);
  }
  razSetPlayerEventHistory(0x8000);
  _CHAR____800d57c4 = _CHAR____800d57c4 | 0x8000;
  razPlayUnderworldSounds(DAT_800d0fd8);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RAZIEL_DebugHealthSetScale(long healthScale)

{
  _CHAR____800d560c = (short)healthScale;
  _CHAR____800d560e = (_CHAR____800d560c + -1) * 5;
  _CHAR____800d5610 = (int)_CHAR____800d560c * 100000 + 100000;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RAZIEL_DebugManaSetMax(long manaScale)

{
  _CHAR____800d5624 = (undefined2)(manaScale << 2);
  _CHAR____800d5626 = _CHAR____800d5624;
  if (0x34 < (manaScale << 2 & 0xfffcU))
  {
    _CHAR____800d5626 = 0x34;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugHealthFillUp(void)

{
  if (_CHAR____800d564c == 1)
  {
    _CHAR____800d5610 = (int)_CHAR____800d560c * 100000 + 100000;
    return;
  }
  _CHAR____800d5610 = 100000;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razPlayUnderworldSounds(_Instance *instance)

{
  if (_CHAR____800d577c != 0)
  {
    /* WARNING: Subroutine does not return */
    SndEndLoop(_CHAR____800d577c);
  }
  razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x1a, -0xfa, -0xfa, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x1a, -300, -300, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x12, -0xdc, -0xdc, 0x78, 0x78, 0, 0xdac);
  razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x1a, -0xfa, -0xfa, 0x78, 0x78, 0, 0xdac);
  return;
}
