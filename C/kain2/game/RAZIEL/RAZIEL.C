#include "THISDUST.H"
#include "RAZIEL.H"

// decompiled code
// original method signature:
// void /*$ra*/ InitStates(struct _Instance *PlayerInstance /*$s2*/)
// line 192, offset 0x800a80c8
/* begin block 1 */
// Start line: 193
// Start offset: 0x800A80C8
// Variables:
// 		unsigned char i; // $s1

/* begin block 1.1 */
// Start line: 222
// Start offset: 0x800A8174
// Variables:
// 		struct _G2AnimSection_Type *animSection; // $v0
/* end block 1.1 */
// End offset: 0x800A8174
// End Line: 223
/* end block 1 */
// End offset: 0x800A81E0
// End Line: 234

/* begin block 2 */
// Start line: 384
/* end block 2 */
// End Line: 385

/* begin block 3 */
// Start line: 388
/* end block 3 */
// End Line: 389

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitStates(_Instance *PlayerInstance)

{
  _G2AnimSection_Type *p_Var1;
  uint uVar2;
  int iVar3;
  byte bVar4;

  if (_Raziel == (Object *)0x0)
  {
    _Raziel = PlayerInstance->object;
  }
  *(char **)&PlayerInstance->InstanceState = &CHAR____800d5218;
  _PlayerData = PlayerInstance->data;
  bVar4 = 0;
  _CHAR____800d5218 = PlayerInstance;
  G2EmulationSetTotalSections((__CharacterState *)&CHAR____800d5218, 3);
  G2EmulationSetStartAndEndSegment((__CharacterState *)&CHAR____800d5218, 0, 0, 0xd);
  G2EmulationSetStartAndEndSegment((__CharacterState *)&CHAR____800d5218, 1, 0xe, 0x31);
  G2EmulationSetStartAndEndSegment((__CharacterState *)&CHAR____800d5218, 2, 0x32, 0x41);
  uVar2 = 0;
  do
  {
    iVar3 = uVar2 * 0x11c;
    p_Var1 = (PlayerInstance->anim).section + uVar2;
    p_Var1->callback = RazielAnimCallback;
    p_Var1->callbackData = (void *)0x0;
    *(undefined4 *)(&CHAR____800d5220 + iVar3) = 0x800a8668;
    InitMessageQueue((__MessageQueue *)(&CHAR____800d5224 + iVar3));
    InitMessageQueue((__MessageQueue *)(&CHAR____800d52ac + iVar3));
    bVar4 = bVar4 + 1;
    uVar2 = (uint)bVar4;
  } while (bVar4 < 3);
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section, (_G2AnimInterpInfo_Type *)&razInterpInfo);
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section + 1, (_G2AnimInterpInfo_Type *)&vramBlockList);
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section + 2, (_G2AnimInterpInfo_Type *)&vramBlockList.x);
  _CHAR____800d5574 = 1;
  vmClock = vmClock | 0x800;
  InitHealthSystem();
  debugRazielFlags1 = 0x1000000;
  _CHAR____800d5624 = 0;
  _CHAR____800d5626 = 0;
  _CHAR____800d561c = 0;
  _CHAR____800d557c = 0;
  _CHAR____800d5724 = 0;
  _CHAR____800d572c = 0;
  (PlayerInstance->rotation).y = 0;
  (PlayerInstance->rotation).x = 0;
  _CHAR____800d55ec = 0x800d5924;
  _CHAR____800d5628 = 0x800d5804;
  _CHAR____800d5608 = 0x100;
  _CHAR____800d55f0 = 0;
  _CHAR____800d5658 = 0;
  _CHAR____800d5644 = 0;
  _CHAR____800d560a = 0xffe0;
  G2EmulationSetAnimation((__CharacterState *)&CHAR____800d5218, 0, 0, 0, 0);
  G2EmulationSetMode((__CharacterState *)&CHAR____800d5218, 0, 2);
  G2EmulationSetAnimation((__CharacterState *)&CHAR____800d5218, 1, 0, 0, 0);
  G2EmulationSetMode((__CharacterState *)&CHAR____800d5218, 1, 2);
  G2EmulationSetAnimation((__CharacterState *)&CHAR____800d5218, 2, 0, 0, 0);
  G2EmulationSetMode((__CharacterState *)&CHAR____800d5218, 2, 2);
  _BlockVramEntry_800d59a0._12_4_ = 0x519;
  PlayerInstance->maxXVel = 0x100;
  PlayerInstance->maxYVel = 0x100;
  PlayerInstance->maxZVel = 0x100;
  razSetCowlNoDraw(1);
  InitExternalForces((__Force *)&_BlockVramEntry_800d58c0.type, 4);
  ResetPhysics(PlayerInstance, -0x10);
  gameTracker._16_4_ = 0;
  CAMERA_ChangeToOutOfWater((Camera *)&theCamera, PlayerInstance);
  razAttachControllers();
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(PlayerInstance, (int)&DAT_00100006, 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateInitIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Ptr /*$a2*/)
// line 459, offset 0x800a83b0
/* begin block 1 */
// Start line: 460
// Start offset: 0x800A83B0
// Variables:
// 		struct evControlInitIdleData *data; // $s0
// 		struct _Instance *linkWeapon; // $a0
/* end block 1 */
// End offset: 0x800A8650
// End Line: 575

/* begin block 2 */
// Start line: 918
/* end block 2 */
// End Line: 919

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateInitIdle(__CharacterState *In, int CurrentSection, int Ptr)

{
  _Instance *p_Var1;
  int NewAnim;
  int in_a3;
  int local_18;
  int local_14;

  if (Ptr == 0)
  {
    /* WARNING: Subroutine does not return */
    SetPhysicsWallCrawlData(0, 0, 3, in_a3);
  }
  p_Var1 = razGetHeldWeapon();
  NewAnim = *(int *)Ptr;
  if (NewAnim == 2)
  {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x60, -1, -1);
    if (NewAnim == 0)
    {
      return;
    }
    NewAnim = 0x8c;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a8648;
  }
  if (NewAnim == 3)
  {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 100, -1, -1);
    if (NewAnim == 0)
    {
      return;
    }
    NewAnim = 0x8d;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a8648;
  }
  if (NewAnim == 4)
  {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x68, -1, -1);
    if (NewAnim == 0)
    {
      return;
    }
    NewAnim = 0x8e;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a8648;
  }
  if ((p_Var1 == (_Instance *)0x0) || (CurrentSection != 1))
  {
    if (NewAnim == 0)
    {
      NewAnim = 0;
    }
    else
    {
      if (NewAnim != 1)
      {
        return;
      }
      if (CurrentSection == 2)
      {
        CurrentSection = 2;
        NewAnim = 0;
      }
      else
      {
        NewAnim = 0x37;
      }
    }
  LAB_800a8638:
    local_18 = *(int *)(Ptr + 8);
  }
  else
  {
    if (NewAnim - 2U < 3)
    {
      *(undefined4 *)Ptr = 0;
    }
    if (_CHAR____800d5600 == 2)
    {
      if (*(int *)Ptr == 0)
      {
        CurrentSection = 1;
        NewAnim = 0x54;
      }
      else
      {
        CurrentSection = 1;
        NewAnim = 0x7e;
      }
      goto LAB_800a8638;
    }
    if (_CHAR____800d5600 < 3)
    {
      if (_CHAR____800d5600 == 0)
      {
        return;
      }
      if (_CHAR____800d5600 != 1)
      {
        return;
      }
      if (*(int *)Ptr == 0)
      {
        CurrentSection = 1;
        NewAnim = 0x32;
        goto LAB_800a8638;
      }
      CurrentSection = 1;
      NewAnim = 0x7f;
      local_18 = *(int *)(Ptr + 8);
    }
    else
    {
      if (_CHAR____800d5600 == 3)
      {
        CurrentSection = 1;
        NewAnim = 0x62;
        goto LAB_800a8638;
      }
      if (_CHAR____800d5600 != 0x1000)
      {
        return;
      }
      if (*(int *)Ptr == 0)
      {
        G2EmulationSwitchAnimation(In, 1, 0x75, 0, *(int *)(Ptr + 8), 2);
        razReaverScale(0xaf0);
        return;
      }
      CurrentSection = 1;
      NewAnim = 0x89;
      local_18 = *(int *)(Ptr + 8);
    }
  }
  local_14 = 2;
LAB_800a8648:
  G2EmulationSwitchAnimation(In, CurrentSection, NewAnim, 0, local_18, local_14);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
// line 624, offset 0x800a8668
/* begin block 1 */
// Start line: 625
// Start offset: 0x800A8668
// Variables:
// 		struct __Event *Ptr; // $s0
// 		int Anim; // $s5
// 		int blockForwardMotion; // $s7

/* begin block 1.1 */
// Start line: 777
// Start offset: 0x800A8C7C
// Variables:
// 		struct _Instance *heldInst; // $v0
/* end block 1.1 */
// End offset: 0x800A8CA4
// End Line: 783

/* begin block 1.2 */
// Start line: 821
// Start offset: 0x800A8D40
// Variables:
// 		struct evPhysicsEdgeData *EdgeData; // $v0
/* end block 1.2 */
// End offset: 0x800A8D98
// End Line: 828
/* end block 1 */
// End offset: 0x800A8EF8
// End Line: 898

/* begin block 2 */
// Start line: 1248
/* end block 2 */
// End Line: 1249

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerIdle(__CharacterState *In, int CurrentSection, int Data)

{
  bool bVar1;
  int iVar2;
  __Event *p_Var3;
  _Instance *Inst;
  int CurrentSection_00;
  undefined *puVar4;
  code *NewProcess;
  int in_a3;
  _Instance **pp_Var5;
  int Mode;

  bVar1 = false;
  _BlockVramEntry_800d59a0._12_4_ =
      (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xffffffef);
  G2EmulationQueryFrame(In, CurrentSection);
  iVar2 = G2EmulationQueryAnimation(In, CurrentSection);
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0)
    {
      if (((((CurrentSection == 0) &&
             (CurrentSection_00 = CheckHolding(In->CharacterInstance), CurrentSection_00 == 0)) &&
            (iVar2 != 0x37)) &&
           ((iVar2 != 0xd6 && (_CHAR____800d5654 = _CHAR____800d5654 + 1, 300 < _CHAR____800d5654)))) &&
          (_CHAR____800d5654 == (_CHAR____800d5654 / 900) * 900))
      {
        if (_CHAR____800d5658 == (_Instance *)0x0)
        {
          G2EmulationSwitchAnimationCharacter(In, 0x18, 0, 3, 1);
          COLLIDE_SegmentCollisionOff(In->CharacterInstance, 1);
        }
        else
        {
          G2EmulationInstanceToInstanceSwitchAnimationCharacter(In->CharacterInstance, _CHAR____800d5658, 1, 0, 3, 1);
        }
      }
      return;
    }
    puVar4 = (undefined *)p_Var3->ID;
    if (puVar4 == (undefined *)0x2000000)
    {
      if (((_CHAR____800d55f0 & 1) == 0) || (_CHAR____800d5600 == 3))
      {
        if (((_CHAR____800d55f0 & 8) == 0) || (_CHAR____800d5600 == 3))
        {
          if ((_CHAR____800d55f0 & 0x2010) == 0)
          {
            if ((_CHAR____800d55f0 & 0x800) == 0)
            {
              if ((_CHAR____800d55f0 & 0x4000) == 0)
              {
                CurrentSection_00 = razPickupAndGrab(In, CurrentSection);
                if (((CurrentSection_00 != 0) && (CurrentSection == 0)) &&
                    ((_CHAR____800d55b0 & 0x80) == 0))
                {
                  NewProcess = StateHandlerAttack2;
                  goto LAB_800a8df0;
                }
              }
              else
              {
                if (CurrentSection == 0)
                {
                  NewProcess = StateHandlerWarpGate;
                LAB_800a8df0:
                  StateSwitchStateCharacterData(In, NewProcess, 0);
                }
              }
            }
            else
            {
              if (CurrentSection == 1)
              {
                razReaverPickup(In->CharacterInstance, *(_Instance **)(_CHAR____800d55ec + 0x58));
              }
            }
          }
          else
          {
            if (CurrentSection == 0)
            {
              if (_CHAR____800d5600 != 3)
              {
                NewProcess = StateHandlerBreakOff;
                goto LAB_800a8df0;
              }
              Inst = razGetHeldItem();
              if (Inst != (_Instance *)0x0)
              {
                /* WARNING: Subroutine does not return */
                INSTANCE_Query(Inst, 2);
              }
            }
          }
        }
        else
        {
          if (CurrentSection == 0)
          {
            NewProcess = StateHandlerPullSwitch;
            goto LAB_800a8df0;
          }
        }
      }
      else
      {
        _CHAR____800d5574 = 0x200;
        pp_Var5[0x47] = (_Instance *)0x0;
        if (CurrentSection == 0)
        {
          in_a3 = 6;
          G2EmulationSwitchAnimationCharacter(In, 0x15, 0, 6, 1);
          StateSwitchStateCharacterData(In, StateHandlerPushObject, 0);
        }
        _BlockVramEntry_800d59a0._12_4_ =
            (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xfffffffe);
      }
    }
    else
    {
      if ((int)puVar4 < 0x2000001)
      {
        if (puVar4 == &DAT_80000002)
        {
          if ((CurrentSection == 0) && ((*gameTracker._4_4_ & LONG_800cf564) != 0))
          {
            _CHAR____800d571c = 0;
            NewProcess = StateHandlerSoulSuck;
            goto LAB_800a8df0;
          }
        }
        else
        {
          if ((int)puVar4 < -0x7ffffffd)
          {
            if (puVar4 == (undefined *)0x80000000)
            {
              if ((_CHAR____800d55b0 & 0x80) == 0)
              {
                NewProcess = StateHandlerAttack2;
              LAB_800a8b34:
                in_a3 = 0;
                StateSwitchStateData(In, CurrentSection, NewProcess, 0);
              }
            }
            else
            {
              if (puVar4 != (undefined *)0x80000001)
                goto LAB_800a8e04;
              if (CurrentSection == 0)
              {
                _CHAR____800d5574 = 0x10;
                _BlockVramEntry_800d59a0._12_4_ =
                    (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ | 0x10);
                in_a3 = 0;
                CurrentSection_00 =
                    razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x10, (int *)0x0, (int *)0x0);
                if (CurrentSection_00 != 0)
                {
                  in_a3 = 2;
                  G2EmulationSwitchAnimationCharacter(In, 0x22, 0, 2, 1);
                }
                NewProcess = StateHandlerCompression;
                goto LAB_800a8df0;
              }
            }
          }
          else
          {
            if (puVar4 == &DAT_00100001)
            {
              if (CurrentSection == 0)
              {
                _CHAR____800d5574 = 1;
                _CHAR____800d5654 = 0;
                _BlockVramEntry_800d59a0._12_4_ = &PTR_0002a109;
                PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
                SteerSwitchMode(In->CharacterInstance, 0);
                _CHAR____800d55a8 = 0;
              }
              StateInitIdle(In, CurrentSection, p_Var3->Data);
            }
            else
            {
              if ((int)puVar4 < 0x100002)
              {
                if (puVar4 == &DAT_80000010)
                {
                  if ((CurrentSection == 0) && ((_CHAR____800d55b0 & 4) != 0))
                  {
                    if (((_CHAR____800d55b0 & 0x80) != 0) || ((DAT_800d10f0 & 4) != 0))
                    {
                      /* WARNING: Subroutine does not return */
                      EnMessageQueueData(&In->SectionList[0].Defer, (int)&DAT_80000010, 0);
                    }
                    NewProcess = StateHandlerGlyphs;
                    goto LAB_800a8df0;
                  }
                }
                else
                {
                LAB_800a8e04:
                  DefaultStateHandler(In, CurrentSection, Data);
                }
              }
              else
              {
                if (puVar4 != &DAT_00100004)
                  goto LAB_800a8e04;
                if (CurrentSection == 0)
                {
                  razReaverScale(0x1000);
                  razResetPauseTranslation(In->CharacterInstance);
                  COLLIDE_SegmentCollisionOn(In->CharacterInstance, 1);
                }
              }
            }
          }
        }
      }
      else
      {
        if (puVar4 == (undefined *)0x4010400)
        {
          if ((((*(uint *)(p_Var3->Data + 0x20) & 0x20000) != 0) && ((_CHAR____800d561c & 1) != 0)) && (_CHAR____800d564c == 2))
          {
            _CHAR____800d57c4 = _CHAR____800d57c4 | 0x10000;
          }
        }
        else
        {
          if ((int)puVar4 < 0x4010401)
          {
            if (0x2000002 < (int)puVar4)
            {
              if (puVar4 != (undefined *)0x4010080)
                goto LAB_800a8e04;
              if (CurrentSection == 0)
              {
                if (p_Var3->Data == 0)
                {
                  razSetPauseTranslation(In->CharacterInstance);
                }
                else
                {
                  razResetPauseTranslation(In->CharacterInstance);
                }
              }
            }
          }
          else
          {
            if (puVar4 == (undefined *)0x8000000)
            {
              if (iVar2 == 0xd7)
              {
                _BlockVramEntry_800d59a0._12_4_ =
                    (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xff7fffff);
              }
              if (iVar2 != 0xd6)
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
              in_a3 = 0;
              G2EmulationSwitchAnimation(In, CurrentSection, 0xd7, 0, 3, 1);
            }
            else
            {
              if ((int)puVar4 < 0x8000001)
              {
                if (puVar4 != (undefined *)0x4010401)
                  goto LAB_800a8e04;
                bVar1 = true;
              }
              else
              {
                if (puVar4 != (undefined *)0x10000000)
                  goto LAB_800a8e04;
                if ((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) != 0)
                {
                LAB_800a8b10:
                  in_a3 = 3;
                  StateSwitchStateData(In, CurrentSection, StateHandlerMove, 3);
                  goto LAB_800a8e10;
                }
                if (-0x201 < _CHAR____800d5598)
                {
                  if (_CHAR____800d5598 < 0x201)
                  {
                    if (bVar1)
                      goto LAB_800a8e10;
                    if (0xfff < _CHAR____800d5588)
                    {
                      NewProcess = StateHandlerStartMove;
                      goto LAB_800a8b34;
                    }
                    goto LAB_800a8b10;
                  }
                  if (CurrentSection == 1)
                  {
                    if (In->CharacterInstance->LinkChild == (_Instance *)0x0)
                    {
                      CurrentSection_00 = 1;
                      Mode = CurrentSection;
                      goto LAB_800a8ac4;
                    }
                  }
                  else
                  {
                    Mode = 1;
                    CurrentSection_00 = CurrentSection;
                  LAB_800a8ac4:
                    G2EmulationSwitchAnimation(In, CurrentSection_00, 0x35, 0, 2, Mode);
                  }
                  in_a3 = 0;
                  StateSwitchStateData(In, CurrentSection, StateHandlerStartTurn, 0);
                  pp_Var5[0x47] = (_Instance *)0x33;
                  goto LAB_800a8e10;
                }
                if (CurrentSection == 1)
                {
                  Inst = razGetHeldWeapon();
                  CurrentSection_00 = 1;
                  Mode = CurrentSection;
                  if (Inst == (_Instance *)0x0)
                    goto LAB_800a8a38;
                }
                else
                {
                  CurrentSection_00 = CurrentSection;
                  Mode = 1;
                LAB_800a8a38:
                  G2EmulationSwitchAnimation(In, CurrentSection_00, 0x36, 0, 2, Mode);
                }
                in_a3 = 0;
                StateSwitchStateData(In, CurrentSection, StateHandlerStartTurn, 0);
                pp_Var5[0x47] = (_Instance *)0x34;
              }
            }
          }
        }
      }
    }
  LAB_800a8e10:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerLookAround(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
// line 902, offset 0x800a8f28
/* begin block 1 */
// Start line: 903
// Start offset: 0x800A8F28
// Variables:
// 		struct __Event *Ptr; // $s0

/* begin block 1.1 */
// Start line: 910
// Start offset: 0x800A9018
// Variables:
// 		struct _Instance *instance; // $s0
/* end block 1.1 */
// End offset: 0x800A905C
// End Line: 918

/* begin block 1.2 */
// Start line: 925
// Start offset: 0x800A9094
// Variables:
// 		struct _Instance *instance; // $s0
/* end block 1.2 */
// End offset: 0x800A9094
// End Line: 926

/* begin block 1.3 */
// Start line: 938
// Start offset: 0x800A90DC
// Variables:
// 		int message; // stack offset -32
// 		int messageData; // stack offset -28
/* end block 1.3 */
// End offset: 0x800A9190
// End Line: 956
/* end block 1 */
// End offset: 0x800A9254
// End Line: 979

/* begin block 2 */
// Start line: 1925
/* end block 2 */
// End Line: 1926

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerLookAround(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess;
  _G2Anim_Type *anim;
  int local_20;
  int iStack28;

  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      if (((*gameTracker._4_4_ & LONG_800cf574) != 0) && ((*gameTracker._4_4_ & LONG_800cf570) != 0))
      {
        return;
      }
      /* WARNING: Subroutine does not return */
      EnMessageQueueData(&In->SectionList[CurrentSection].Defer, 0x100000, 0);
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000)
    {
      Data_00 = 0;
      NewProcess = _CHAR____800d571c;
    LAB_800a91e4:
      StateSwitchStateData(In, CurrentSection, NewProcess, Data_00);
    }
    else
    {
      if ((int)puVar2 < 0x100001)
      {
        if (puVar2 == &DAT_00040005)
        {
        LAB_800a91d4:
          Data_00 = p_Var1->Data;
          NewProcess = StateHandlerStumble;
          goto LAB_800a91e4;
        }
        if ((int)puVar2 < 0x40006)
        {
          if ((puVar2 == &DAT_80000020) &&
              (Data_00 = StateHandlerDecodeHold(&local_20, &iStack28), Data_00 != 0))
          {
            if ((local_20 == 0x80000) && (CurrentSection == 0))
            {
              razLaunchForce(In->CharacterInstance);
              StateSwitchStateData(In, 0, StateHandlerThrow2, 0);
            }
            StateSwitchStateData(In, CurrentSection, StateHandlerThrow2, 0);
            if ((_CHAR____800d5600 != 0x1000) && (_CHAR____800d5600 != 8))
            {
              razSetFadeEffect(In->CharacterInstance->fadeValue, *(short *)(_PlayerData + 0x24),
                               (int)*(short *)(_PlayerData + 0x26));
            }
            _CHAR____800d571c = StateHandlerIdle;
            _CHAR____800d567c = 2;
          }
        }
        else
        {
          if (puVar2 == &UNK_00040025)
            goto LAB_800a91d4;
        }
      }
      else
      {
        if (puVar2 == &DAT_00100004)
        {
          if (CurrentSection == 1)
          {
            anim = &In->CharacterInstance->anim;
            G2Anim_InterpDisableController(anim, 0x11, 0xe, 300);
            G2Anim_InterpDisableController(anim, 0x10, 0xe, 300);
            G2Anim_InterpDisableController(anim, 0xe, 0xe, 300);
          }
        }
        else
        {
          if ((int)puVar2 < 0x100005)
          {
            if (puVar2 == &DAT_00100001)
            {
              if (CurrentSection == 1)
              {
                anim = &In->CharacterInstance->anim;
                G2Anim_EnableController(anim, 0x11, 0xe);
                G2Anim_EnableController(anim, 0x10, 0xe);
                G2Anim_EnableController(anim, 0xe, 0xe);
                _BlockVramEntry_800d59a0._12_4_ = 0x8001008;
              }
              Data_00 = G2EmulationQueryAnimation(In, CurrentSection);
              if (Data_00 == 0x18)
              {
                StateInitIdle(In, CurrentSection, 0);
              }
            }
          }
          else
          {
            if (puVar2 == (undefined *)0x1000000)
            {
              if (CurrentSection == 0)
              {
                CAMERA_ForceEndLookaroundMode((Camera *)&theCamera);
              }
              Data_00 = p_Var1->Data;
              NewProcess = StateHandlerHitReaction;
              goto LAB_800a91e4;
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerCrouch(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s4*/, int Data /*stack 8*/)
// line 982, offset 0x800a9270
/* begin block 1 */
// Start line: 983
// Start offset: 0x800A9270
// Variables:
// 		struct __Event *Ptr; // $s1
// 		int Anim; // $s0
// 		struct _Instance *heldInst; // $s5
// 		int DropThisFrame; // stack offset -48

/* begin block 1.1 */
// Start line: 1097
// Start offset: 0x800A96A0
// Variables:
// 		struct evObjectData *data; // $s0
// 		int i; // $s2
/* end block 1.1 */
// End offset: 0x800A9788
// End Line: 1124
/* end block 1 */
// End offset: 0x800A99B8
// End Line: 1186

/* begin block 2 */
// Start line: 2095
/* end block 2 */
// End Line: 2096

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerCrouch(__CharacterState *In, int CurrentSection, int Data)

{
  _Instance *Inst;
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  _Instance *instance;
  int in_a3;
  __CharacterState *p_Var3;
  int local_38;
  _Instance **pp_Var4;

  Inst = razGetHeldItem();
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      if (((*gameTracker._4_4_ & LONG_800cf578) == 0) &&
          (In->SectionList[CurrentSection].Process == StateHandlerCrouch))
      {
        /* WARNING: Subroutine does not return */
        EnMessageQueueData(&In->SectionList[CurrentSection].Event, 0x20000008, 0);
      }
      return;
    }
    NewAnim = G2EmulationQueryAnimation(In, CurrentSection);
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      if (CurrentSection == 0)
      {
        _CHAR____800d5574 = 0x40;
        _BlockVramEntry_800d59a0._12_4_ = &DAT_00008109;
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        SteerSwitchMode(In->CharacterInstance, 0);
        if (p_Var1->Data == 0)
        {
          in_a3 = 0;
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x4c, (int *)0x0, (int *)0x0);
          if (NewAnim != 0)
          {
            local_38 = 2;
            NewAnim = 4;
            in_a3 = 8;
            goto LAB_800a94ac;
          }
        }
        else
        {
          in_a3 = 0;
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x48, (int *)0x0, (int *)0x0);
          if (NewAnim != 0)
          {
            local_38 = 1;
            NewAnim = 3;
            in_a3 = 3;
          LAB_800a94ac:
            G2EmulationSwitchAnimationCharacter(In, NewAnim, 0, in_a3, local_38);
          }
        }
        if (Inst != (_Instance *)0x0)
        {
          /* WARNING: Subroutine does not return */
          INSTANCE_Post(Inst, 0x80002c, 0);
        }
      }
      if (p_Var1->Data == 0)
      {
        pp_Var4[0x48] = (_Instance *)0x0;
      }
      else
      {
        pp_Var4[0x48] = (_Instance *)0x48;
      }
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if (puVar2 != &DAT_80000008)
        {
          if ((int)puVar2 < -0x7ffffff7)
          {
            if (puVar2 == (undefined *)0x80000001)
            {
              if (((CurrentSection == 0) && (NewAnim != 5)) && (NewAnim != 0x55))
              {
                _CHAR____800d5574 = 0x20;
                in_a3 = 0;
                NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x20, (int *)0x0, (int *)0x0);
                if (NewAnim != 0)
                {
                  in_a3 = 1;
                  G2EmulationSwitchAnimationCharacter(In, 0x26, 0, 1, 1);
                }
                StateSwitchStateCharacterData(In, StateHandlerCompression, 0);
              }
            }
            else
            {
              if ((int)puVar2 < -0x7fffffff)
              {
                if (Inst != (_Instance *)0x0)
                {
                  razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x50, -1, -1);
                  /* WARNING: Subroutine does not return */
                  pp_Var4[0x48] = (_Instance *)0x50;
                  INSTANCE_Post(Inst, 0x200005, 0);
                }
              }
              else
              {
                if (puVar2 != &DAT_80000004)
                  goto LAB_800a9940;
              }
            }
          }
          else
          {
            if (puVar2 == &DAT_80000020)
            {
              if ((NewAnim == 5) || (NewAnim == 0x55))
                goto LAB_800a9950;
            }
            else
            {
              if ((int)puVar2 < -0x7fffffdf)
              {
                if (puVar2 == &DAT_80000010)
                {
                  if ((CurrentSection == 0) && (In->CharacterInstance->tface != (_TFace *)0x0))
                  {
                    /* WARNING: Subroutine does not return */
                    EnMessageQueueData(&In->SectionList[0].Defer, (int)&DAT_80000010, 0);
                  }
                  goto LAB_800a9848;
                }
              }
              else
              {
                if (puVar2 == (undefined *)0x100000)
                {
                  /* WARNING: Subroutine does not return */
                  SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                }
              }
            }
          LAB_800a9940:
            DefaultStateHandler(In, CurrentSection, Data);
          }
        }
      }
      else
      {
        if (puVar2 != (undefined *)0x4020000)
        {
          if ((int)puVar2 < 0x4020001)
          {
            if (puVar2 == (undefined *)0x2000000)
            {
              if ((((_CHAR____800d55f0 & 4) != 0) && (_CHAR____800d5600 != 3)) &&
                  ((NewAnim != 5 && (NewAnim != 0x55))))
              {
                _BlockVramEntry_800d59a0._12_4_ =
                    (undefined *)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xfffffff7 | 0x8041000);
                NewAnim = 0;
                if (CurrentSection == 0)
                {
                  local_38 = 8;
                  p_Var3 = In;
                  do
                  {
                    p_Var3->SectionList[0].Data1 = 0;
                    PurgeMessageQueue((__MessageQueue *)((int)&In->TotalSections + local_38));
                    local_38 = local_38 + 0x11c;
                    NewAnim = NewAnim + 1;
                    p_Var3 = (__CharacterState *)&p_Var3->SectionList[0].Data1;
                  } while (NewAnim < 3);
                  razCenterWithBlock(In->CharacterInstance, *(_Instance **)(_CHAR____800d55ec + 0x10), -0x8d);
                  NewAnim = SetObjectData(-(int)_CHAR____800d55b4, -(int)_CHAR____800d55b6, 0,
                                          (_Instance *)0x0, 0);
                  /* WARNING: Subroutine does not return */
                  INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x10), 0x800001, NewAnim);
                }
              }
            }
            else
            {
              if ((int)puVar2 < 0x2000001)
              {
                if (puVar2 != &DAT_00100004)
                  goto LAB_800a9940;
                if ((CurrentSection == 0) &&
                    (COLLIDE_SegmentCollisionOn(In->CharacterInstance, 1), Inst != (_Instance *)0x0))
                {
                  /* WARNING: Subroutine does not return */
                  INSTANCE_Post(Inst, 0x200003, 7);
                }
              }
              else
              {
                if (puVar2 != (undefined *)0x4010400)
                  goto LAB_800a9940;
              }
            }
          }
          else
          {
            if (puVar2 == (undefined *)0x10000000)
            {
              if (((_CHAR____800d5600 != 3) && (NewAnim != 5)) && (NewAnim != 0x55))
              {
                in_a3 = 3;
                StateSwitchStateData(In, CurrentSection, StateHandlerMove, 3);
              }
            }
            else
            {
              if ((int)puVar2 < 0x10000001)
              {
                if (puVar2 != (undefined *)0x8000000)
                  goto LAB_800a9940;
                if ((NewAnim == 5) || (NewAnim == 0x55))
                {
                  /* WARNING: Subroutine does not return */
                  SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                }
                if (CurrentSection == 1)
                {
                  if ((In->SectionList[1].Data2 == 0x50) && (Inst != (_Instance *)0x0))
                  {
                    /* WARNING: Subroutine does not return */
                    INSTANCE_Post(Inst, 0x800008, 0);
                  }
                  In->SectionList[0].Data2 = 0x4c;
                  pp_Var4[0x48] = (_Instance *)0x4c;
                  instance = In->CharacterInstance;
                  in_a3 = 0;
                  In->SectionList[2].Data2 = 0x4c;
                  NewAnim = razSwitchVAnimCharacterGroup(instance, 0x4c, (int *)0x0, (int *)0x0);
                  if (NewAnim != 0)
                  {
                    in_a3 = 8;
                    G2EmulationSwitchAnimationCharacter(In, 4, 0, 8, 2);
                  }
                }
              }
              else
              {
                if (puVar2 != (undefined *)0x20000008)
                  goto LAB_800a9940;
              LAB_800a9848:
                if (((NewAnim != 5) && (NewAnim != 0x55)) && (pp_Var4[0x48] != (_Instance *)0x50))
                {
                  /* WARNING: Subroutine does not return */
                  SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                }
              }
            }
          }
        }
      }
    }
  LAB_800a9950:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerDropAction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
// line 1189, offset 0x800a99e8
/* begin block 1 */
// Start line: 1190
// Start offset: 0x800A99E8
// Variables:
// 		struct __Event *Ptr; // $v0
/* end block 1 */
// End offset: 0x800A9C48
// End Line: 1260

/* begin block 2 */
// Start line: 2528
/* end block 2 */
// End Line: 2529

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerDropAction(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  _Instance *Inst;
  undefined *puVar2;
  int NewAnim;
  int in_a3;
  uint Frames;

  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x8000000)
    {
      if (CurrentSection == 1)
      {
        Inst = razGetHeldItem();
        if (Inst == (_Instance *)0x0)
        {
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, 3, in_a3);
        }
        Inst = razGetHeldItem();
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(Inst, 0x800008, 0);
      }
    }
    else
    {
      if ((int)puVar2 < 0x8000001)
      {
        if (puVar2 != (undefined *)0x80000001)
        {
          if (puVar2 != &DAT_00100001)
            goto LAB_800a9c30;
          Inst = razGetHeldItem();
          if ((Inst != (_Instance *)0x0) && (CurrentSection == 1))
          {
            if (_CHAR____800d5600 == 2)
            {
              NewAnim = 0x69;
              Frames = 3;
            }
            else
            {
              if (_CHAR____800d5600 < 3)
              {
                if ((_CHAR____800d5600 == 0) || (_CHAR____800d5600 != 1))
                  goto LAB_800a9b40;
                NewAnim = 0x53;
                Frames = 3;
              }
              else
              {
                if (_CHAR____800d5600 != 3)
                  goto LAB_800a9b40;
                NewAnim = 99;
                Frames = _CHAR____800d5600;
              }
            }
            G2EmulationSwitchAnimation(In, 1, NewAnim, 0, Frames, 1);
          LAB_800a9b40:
            Inst = razGetHeldItem();
            /* WARNING: Subroutine does not return */
            INSTANCE_Post(Inst, 0x80002c, 0);
          }
          if (CurrentSection == 2)
          {
            in_a3 = 0;
            G2EmulationSwitchAnimationAlpha(In, 2, 0x45, 0, 3, 1, 1);
          }
          else
          {
            if (CurrentSection == 0)
            {
              in_a3 = 0;
              G2EmulationSwitchAnimationAlpha(In, 0, 3, 0, 3, 1, 1);
              _CHAR____800d5574 = 0x40;
            }
          }
        }
      }
      else
      {
        if ((puVar2 != (undefined *)0x10000000) && (puVar2 != (undefined *)0x20000008))
        {
        LAB_800a9c30:
          DefaultStateHandler(In, CurrentSection, Data);
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerSoulSuck(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s5*/)
// line 1267, offset 0x800a9c68
/* begin block 1 */
// Start line: 1268
// Start offset: 0x800A9C68
// Variables:
// 		struct __Event *Ptr; // $a0
// 		int Anim; // $s3

/* begin block 1.1 */
// Start line: 1375
// Start offset: 0x800AA130
// Variables:
// 		struct evPhysicsSwimData *SwimData; // $v0
/* end block 1.1 */
// End offset: 0x800AA160
// End Line: 1382
/* end block 1 */
// End offset: 0x800AA17C
// End Line: 1390

/* begin block 2 */
// Start line: 2693
/* end block 2 */
// End Line: 2694

/* begin block 3 */
// Start line: 2698
/* end block 3 */
// End Line: 2699

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSoulSuck(__CharacterState *In, int CurrentSection, int Data)

{
  int iVar1;
  __Event *p_Var2;
  _Instance *p_Var3;
  undefined *puVar4;
  int Frames;
  int NewAnim;
  int in_a3;
  __State *p_Var5;

  if ((LoopCounter & 3U) == 0)
  {
    FX_MakeSoulDust(In->CharacterInstance, 0x10);
  }
  iVar1 = G2EmulationQueryAnimation(In, CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  do
  {
    p_Var2 = PeekMessageQueue(&p_Var5->Event);
    if (p_Var2 == (__Event *)0x0)
    {
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x1000006)
    {
    LAB_800a9f14:
      if (iVar1 == 0x4f)
      {
        in_a3 = 0;
        G2EmulationSwitchAnimation(In, CurrentSection, 0x2f, 0, 3, 1);
        PurgeMessageQueue(&p_Var5->Event);
      }
      else
      {
        if (_CHAR____800d571c == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0)
        {
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, 3, in_a3);
        }
        in_a3 = 0;
        StateSwitchStateData(In, CurrentSection, _CHAR____800d571c, 0);
      }
      if (((_CHAR____800d55f0 & 0x1000) != 0) && (CurrentSection == 0))
      {
      LAB_800a9fac:
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x60), 0x1000014, 0);
      }
    }
    else
    {
      if ((int)puVar4 < 0x1000007)
      {
        if (puVar4 == &DAT_00100001)
        {
          if (CurrentSection == 0)
          {
            _BlockVramEntry_800d59a0._12_4_ = 9;
            PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
            if (((_CHAR____800d55f0 & 0x1000) != 0) && (_CHAR____800d5600 != 3))
            {
              razAlignYRotMove(*(_Instance **)(_CHAR____800d55ec + 0x60), 0xdc,
                               &In->CharacterInstance->position, &In->CharacterInstance->rotation, 0);
              /* WARNING: Subroutine does not return */
              INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x60), 0x1000014, 1);
            }
            in_a3 = 0;
            G2EmulationSwitchAnimationAlpha(In, 0, 0x4e, 0, 4, 1, 4);
          }
          if (CurrentSection == 2)
          {
            in_a3 = 0;
            G2EmulationSwitchAnimation(In, 2, 0, 0, 4, 2);
          }
          if (CurrentSection == 1)
          {
            p_Var3 = razGetHeldWeapon();
            if ((p_Var3 == (_Instance *)0x0) && ((_CHAR____800d55f0 & 0x1000) == 0))
            {
              Frames = 0x4e;
            }
            else
            {
              Frames = 0x5e;
            }
            in_a3 = 0;
            G2EmulationSwitchAnimation(In, 1, Frames, 0, 4, 1);
            _CHAR____800d5574 = _CHAR____800d5574 | 0x10000000;
          }
        }
        else
        {
          if ((int)puVar4 < 0x100002)
          {
            if (puVar4 != &DAT_80000010)
            {
            LAB_800aa164:
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
          else
          {
            if (puVar4 == &DAT_00100004)
            {
              if (CurrentSection == 1)
              {
                razSetCowlNoDraw(1);
                _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xffffffbf;
                _CHAR____800d5574 = _CHAR____800d5574 & 0xefffffff;
                if ((_CHAR____800d55f0 & 0x1000) != 0)
                  goto LAB_800a9fac;
              }
            }
            else
            {
              if (puVar4 != (undefined *)0x1000001)
                goto LAB_800aa164;
            }
          }
        }
      }
      else
      {
        if (puVar4 == (undefined *)0x4020000)
        {
          if ((*(ushort *)(p_Var2->Data + 0x10) & 0x40) != 0)
          {
            StateHandlerInitSwim(In, CurrentSection, 0);
          }
        }
        else
        {
          if ((int)puVar4 < 0x4020001)
          {
            if (puVar4 == (undefined *)0x1000009)
            {
              NewAnim = 0x50;
              Frames = 2;
            LAB_800aa11c:
              in_a3 = 0;
              G2EmulationSwitchAnimation(In, CurrentSection, NewAnim, 0, Frames, 1);
            }
            else
            {
              if (puVar4 != (undefined *)0x1000016)
                goto LAB_800aa164;
              if (((vmClock & 0x800U) != 0) && (CurrentSection == 1))
              {
                GainHealth(p_Var2->Data);
                razSetPlayerEventHistory(0x1000);
              }
            }
          }
          else
          {
            if (puVar4 != (undefined *)0x8000000)
            {
              if (puVar4 == (undefined *)0x20000002)
                goto LAB_800a9f14;
              goto LAB_800aa164;
            }
            if (iVar1 == 0x2f)
            {
              if (_CHAR____800d571c == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0)
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
              in_a3 = 0;
              StateSwitchStateData(In, CurrentSection, _CHAR____800d571c, 0);
            }
            if (iVar1 == 0x4e)
            {
              in_a3 = 0;
              G2EmulationSwitchAnimation(In, CurrentSection, 0x4f, 0, 0, 1);
            }
            if (iVar1 == 0x50)
            {
              if ((*gameTracker._4_4_ & LONG_800cf564) != 0)
              {
                NewAnim = 0x4f;
                Frames = 8;
                goto LAB_800aa11c;
              }
              if (_CHAR____800d571c == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0)
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
              in_a3 = 0;
              StateSwitchStateData(In, CurrentSection, _CHAR____800d571c, 0);
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var5->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerStartTurn(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
// line 1396, offset 0x800aa1a0
/* begin block 1 */
// Start line: 1397
// Start offset: 0x800AA1A0
// Variables:
// 		struct __Event *Ptr; // $v0
/* end block 1 */
// End offset: 0x800AA384
// End Line: 1457

/* begin block 2 */
// Start line: 2961
/* end block 2 */
// End Line: 2962

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerStartTurn(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int iVar2;
  undefined *puVar3;
  code *NewProcess;
  int in_a3;

  G2EmulationQueryFrame(In, CurrentSection);
  if (_CHAR____800d5598 == 0)
  {
    /* WARNING: Subroutine does not return */
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer, 0x100000, 0);
  }
  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == (undefined *)0x100000)
    {
    LAB_800aa2b4:
      if (CurrentSection == 0)
      {
        if ((*gameTracker._4_4_ & 0x8000000f) == 0)
        {
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, 3, in_a3);
        }
        NewProcess = StateHandlerStartMove;
      LAB_800aa35c:
        StateSwitchStateCharacterData(In, NewProcess, 0);
      }
    }
    else
    {
      if ((int)puVar3 < 0x100001)
      {
        if (puVar3 == (undefined *)0x80000001)
        {
          if (CurrentSection == 0)
          {
            _CHAR____800d5574 = 8;
            in_a3 = 0;
            iVar2 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0, (int *)0x0, (int *)0x0);
            if (iVar2 != 0)
            {
              in_a3 = 0;
              G2EmulationSwitchAnimationCharacter(In, 0x1a, 0, 0, 1);
            }
            NewProcess = StateHandlerCompression;
            goto LAB_800aa35c;
          }
        }
        else
        {
          if (puVar3 == (undefined *)0x0)
            goto LAB_800aa2b4;
        LAB_800aa36c:
          DefaultStateHandler(In, CurrentSection, Data);
        }
      }
      else
      {
        if (puVar3 != &DAT_00100001)
        {
          if (puVar3 != (undefined *)0x8000000)
            goto LAB_800aa36c;
          goto LAB_800aa2b4;
        }
        if (CurrentSection == 0)
        {
          _CHAR____800d5574 = 0x4000;
          _BlockVramEntry_800d59a0._12_4_ = 0x20109;
          PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
          SteerSwitchMode(In->CharacterInstance, 1);
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateInitStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Frame /*$s3*/)
// line 1461, offset 0x800aa3a0
/* begin block 1 */
// Start line: 3096
/* end block 1 */
// End Line: 3097

/* begin block 2 */
// Start line: 3099
/* end block 2 */
// End Line: 3100

void StateInitStartMove(__CharacterState *In, int CurrentSection, int Frame)

{
  int iVar1;

  if ((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) != 0)
  {
    StateSwitchStateData(In, CurrentSection, StateHandlerMove, 3);
  }
  iVar1 = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x30, Frame, -1);
  if (iVar1 != 0)
  {
    razSwitchVAnimSingle(In->CharacterInstance, CurrentSection, 0, Frame, -1);
  }
  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
// line 1550, offset 0x800aa44c
/* begin block 1 */
// Start line: 1551
// Start offset: 0x800AA44C
// Variables:
// 		struct __Event *Ptr; // $a1

/* begin block 1.1 */
// Start line: 1613
// Start offset: 0x800AA728
// Variables:
// 		int mode; // $a0
/* end block 1.1 */
// End offset: 0x800AA780
// End Line: 1631
/* end block 1 */
// End offset: 0x800AAACC
// End Line: 1722

/* begin block 2 */
// Start line: 3277
/* end block 2 */
// End Line: 3278

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerStartMove(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int iVar2;
  _Instance *p_Var3;
  undefined *puVar4;
  uint Segment;
  code *NewProcess;
  code *Frame;
  int in_a3;
  _Instance **pp_Var5;
  int local_20;
  int in_stack_ffffffe4;

  Frame = (code *)Data;
  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      if ((*gameTracker._4_4_ & 0x8000000f) != 0)
      {
        pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
        p_Var3 = (_Instance *)((int)&(pp_Var5[0x48]->node).prev + 1);
        if ((pp_Var5[0x48] != (_Instance *)0x0) && (pp_Var5[0x48] = p_Var3, 7 < (int)p_Var3))
        {
          G2EmulationSetMode(In, CurrentSection, 1);
          pp_Var5[0x48] = (_Instance *)0x0;
          _BlockVramEntry_800d59a0._12_4_ =
              (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xffffdfff);
        }
      }
      iVar2 = G2EmulationQueryFrame(In, CurrentSection);
      if (((10 < iVar2) && (CurrentSection == 0)) &&
          (iVar2 = CheckHolding(In->CharacterInstance), iVar2 != 0))
      {
        if (In->SectionList[1].Process == StateHandlerStartMove)
        {
          StateSwitchStateData(In, 1, StateHandlerMove, 0xb);
        }
        if (In->SectionList[2].Process == StateHandlerStartMove)
        {
          StateSwitchStateData(In, 2, StateHandlerMove, 0xb);
        }
      }
      if (((_CHAR____800d5588 != 0) && (_CHAR____800d5588 < 0x1000)) &&
          ((_CHAR____800d5720 & 1) != 0))
      {
        StateSwitchStateData(In, CurrentSection, StateHandlerMove, 0);
      }
      return;
    }
    puVar4 = (undefined *)p_Var1->ID;
    if (puVar4 == &DAT_00100001)
    {
      Frame = (code *)p_Var1->Data;
      StateInitStartMove(In, CurrentSection, (int)Frame);
      In->SectionList[CurrentSection].Data2 = 1;
      if (CurrentSection == 0)
      {
        _BlockVramEntry_800d59a0._12_4_ = &PTR_0002a119;
        _CHAR____800d5574 = _CHAR____800d5574 & 0x200800 | 4;
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        SteerSwitchMode(In->CharacterInstance, 2);
        _CHAR____800d55a8 = 0xccc;
        _CHAR____800d55ac = 0x400;
        _CHAR____800d55ae = 0x1000;
        _CHAR____800d5720 = 0;
      }
      goto LAB_800aa990;
    }
    if ((int)puVar4 < 0x100002)
    {
      if (puVar4 == &DAT_80000002)
      {
      LAB_800aa6c0:
        if (CurrentSection == 0)
        {
          if (In->CharacterInstance->tface != (_TFace *)0x0)
          {
            /* WARNING: Subroutine does not return */
            EnMessageQueueData(&In->SectionList[0].Defer, p_Var1->ID, 0);
          }
        LAB_800aa6fc:
          if (CurrentSection == 0)
          {
            if (((_CHAR____800d5720 & 7) != 0) || (iVar2 = G2EmulationQueryMode(In, 0), iVar2 == 0))
            {
              if ((_CHAR____800d5720 & 1) == 0)
              {
                Segment = _CHAR____800d5720 & 4;
                if ((_CHAR____800d5720 & 2) != 0)
                {
                  Segment = 3;
                }
              }
              else
              {
                Segment = 2;
              }
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(Segment, 5, 5, in_a3);
            }
            _BlockVramEntry_800d59a0._12_4_ =
                (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ | 0x2000);
          }
        }
      }
      else
      {
        if ((int)puVar4 < -0x7ffffffd)
        {
          if (puVar4 == (undefined *)0x80000000)
          {
            if ((_CHAR____800d5720 & 4) == 0)
            {
              if ((CurrentSection == 0) && ((_CHAR____800d55b0 & 0x80) == 0))
              {
                NewProcess = StateHandlerAttack2;
                goto LAB_800aa940;
              }
            }
            else
            {
              if (CurrentSection != 1)
                goto LAB_800aa858;
              if ((_CHAR____800d55b0 & 0x80) == 0)
              {
                Frame = StateHandlerAttack2;
                in_a3 = 10;
                StateSwitchStateData(In, 1, StateHandlerAttack2, 10);
              }
            }
          }
          else
          {
            if (puVar4 != (undefined *)0x80000001)
              goto LAB_800aa984;
            if (CurrentSection == 0)
            {
              _CHAR____800d5574 = 8;
              in_a3 = 0;
              iVar2 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0, (int *)0x0, (int *)0x0);
              if (iVar2 != 0)
              {
                local_20 = 1;
                in_a3 = 0;
                G2EmulationSwitchAnimationCharacter(In, 0x1a, 0, 0, 1);
              }
              Frame = (code *)0x0;
              StateSwitchStateCharacterData(In, StateHandlerCompression, 0);
            LAB_800aa7f0:
              _BlockVramEntry_800d59a0._12_4_ =
                  (undefined **)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xffffdfff);
            }
          }
          goto LAB_800aa990;
        }
        if (puVar4 == &DAT_80000010)
          goto LAB_800aa6c0;
        if ((int)puVar4 < -0x7fffffef)
        {
          if (puVar4 == &DAT_80000004)
          {
            Frame = StateHandlerMove;
            in_a3 = 3;
            StateSwitchStateData(In, CurrentSection, StateHandlerMove, 3);
            goto LAB_800aa990;
          }
        }
        else
        {
          if (puVar4 == (undefined *)0x0)
            goto LAB_800aa6fc;
        }
      LAB_800aa984:
        Frame = (code *)Data;
        DefaultStateHandler(In, CurrentSection, Data);
      }
    }
    else
    {
      if (puVar4 == (undefined *)0x4010401)
      {
        /* WARNING: Subroutine does not return */
        SetPhysicsWallCrawlData(0, 5, 5, in_a3);
      }
      if ((int)puVar4 < 0x4010402)
      {
        if (puVar4 == (undefined *)0x4000001)
        {
          if ((CurrentSection == 0) && (iVar2 = G2EmulationQueryFrame(In, 0), 6 < iVar2))
          {
            PhysicsMode.next = (_BlockVramEntry *)0x0;
            SetExternalForce((__Force *)In->CharacterInstance, 0x5214, (short)Frame, (short)in_a3,
                             local_20, in_stack_ffffffe4);
            if (In->CharacterInstance->zVel < -0x20)
            {
              in_a3 = 0;
              iVar2 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x18, (int *)0x0, (int *)0x0);
              if (iVar2 != 0)
              {
                local_20 = 1;
                in_a3 = 4;
                G2EmulationSwitchAnimationCharacter(In, 0x24, 0, 4, 1);
              }
              NewProcess = StateHandlerFall;
            LAB_800aa940:
              Frame = (code *)0x0;
              StateSwitchStateCharacterData(In, NewProcess, 0);
            }
          }
        }
        else
        {
          if ((int)puVar4 < 0x4000002)
          {
            if (puVar4 != (undefined *)0x2000000)
              goto LAB_800aa984;
            if ((_CHAR____800d55f0 & 0x20) == 0)
              goto LAB_800aa6c0;
            razPickupAndGrab(In, CurrentSection);
          }
          else
          {
            if (puVar4 != (undefined *)0x4010080)
              goto LAB_800aa984;
            if (CurrentSection != 2)
            {
              Frame = (code *)(uint)(p_Var1->Data != 0);
              G2EmulationSetMode(In, CurrentSection, (int)Frame);
            }
            if (((_CHAR____800d5720 & 2) != 0) && ((*gameTracker._4_4_ & 0x8000000f) != 0))
            {
              Frame = (code *)0x2;
              G2EmulationSetMode(In, CurrentSection, 2);
              goto LAB_800aa7f0;
            }
          }
        }
      }
      else
      {
        if ((int)puVar4 < 0x8000000)
          goto LAB_800aa984;
        if ((int)puVar4 < 0x8000002)
        {
        LAB_800aa858:
          Frame = StateHandlerMove;
          in_a3 = 0;
          StateSwitchStateData(In, CurrentSection, StateHandlerMove, 0);
        }
        else
        {
          if (puVar4 != (undefined *)0x10000000)
            goto LAB_800aa984;
        }
      }
    }
  LAB_800aa990:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateInitMove(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s0*/, int Frames /*$a2*/)
// line 1725, offset 0x800aaaec
/* begin block 1 */
// Start line: 3642
/* end block 1 */
// End Line: 3643

/* begin block 2 */
// Start line: 3647
/* end block 2 */
// End Line: 3648

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateInitMove(__CharacterState *In, int CurrentSection, int Frames)

{
  uint uVar1;
  int iVar2;

  if ((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) == 0)
  {
    if ((*gameTracker._4_4_ & LONG_800cf578) == 0)
    {
      _CHAR____800d5574 = _CHAR____800d5574 & 0x200800 | 4;
      uVar1 = _BlockVramEntry_800d59a0._12_4_ | 0x28119;
      if ((_CHAR____800d561c & 0x20) != 0)
      {
        uVar1 = _BlockVramEntry_800d59a0._12_4_ | 0x228119;
      }
      _BlockVramEntry_800d59a0._12_4_ = uVar1;
      razSelectMotionAnim(In, CurrentSection, Frames, &In->SectionList[CurrentSection].Data2);
    }
    else
    {
      _CHAR____800d5574 = 0x1000000;
      if ((_BlockVramEntry_800d59a0._12_4_ & 0x800000) == 0)
      {
        _BlockVramEntry_800d59a0._12_4_ = 0;
      }
      else
      {
        _BlockVramEntry_800d59a0._12_4_ = 0x800000;
      }
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2119;
      if ((&In->CharacterInstance + CurrentSection * 0x47)[0x48] != (_Instance *)0x38)
      {
        razResetMotion(In->CharacterInstance);
        iVar2 = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x38, -1, -1);
        if (iVar2 != 0)
        {
          G2EmulationSwitchAnimation(In, CurrentSection, 0x4a, 0, 3, 2);
        }
        (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0x38;
      }
    }
  }
  else
  {
    _CHAR____800d5574 = 2;
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x800000) == 0)
    {
      _BlockVramEntry_800d59a0._12_4_ = 0;
    }
    else
    {
      _BlockVramEntry_800d59a0._12_4_ = 0x800000;
    }
    _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x22119;
    if ((&In->CharacterInstance + CurrentSection * 0x47)[0x48] != (_Instance *)0x34)
    {
      razResetMotion(In->CharacterInstance);
      iVar2 = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x34, -1, -1);
      if (iVar2 != 0)
      {
        razSwitchVAnimSingle(In->CharacterInstance, CurrentSection, 1, -1, -1);
      }
      (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0x34;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
// line 1931, offset 0x800aad30
/* begin block 1 */
// Start line: 1932
// Start offset: 0x800AAD30
// Variables:
// 		struct __Event *Ptr; // $s0
// 		int Anim; // $s6

/* begin block 1.1 */
// Start line: 1997
// Start offset: 0x800AB0E8
// Variables:
// 		int data; // $a2
/* end block 1.1 */
// End offset: 0x800AB144
// End Line: 2011
/* end block 1 */
// End offset: 0x800AB404
// End Line: 2102

/* begin block 2 */
// Start line: 4090
/* end block 2 */
// End Line: 4091

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerMove(__CharacterState *In, int CurrentSection, int Data)

{
  int iVar1;
  _Instance **pp_Var2;
  __Event *p_Var3;
  int Data_00;
  _Instance *p_Var4;
  undefined *puVar5;
  code *NewProcess;
  int in_a3;
  int local_2c;

  iVar1 = G2EmulationQueryAnimation(In, CurrentSection);
  pp_Var2 = &In->CharacterInstance + CurrentSection * 0x47;
  pp_Var2[0x47] = (_Instance *)((int)&(pp_Var2[0x47]->node).prev + 1);
  do
  {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0)
    {
      if ((CurrentSection == 0) && (In->SectionList[0].Process != StateHandlerMove))
      {
        razResetMotion(In->CharacterInstance);
      }
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 == (undefined *)0x0)
    {
    LAB_800aafdc:
      if (CurrentSection == 0)
      {
        if (((_CHAR____800d559c == 9) || (_CHAR____800d559c == 0xe)) || (_CHAR____800d559c == 0xf))
        {
          razApplyMotion(In, 0);
        }
        else
        {
          if (((_CHAR____800d5574 == 2) || (iVar1 == 0x7b)) || (iVar1 == 0x7c))
          {
            /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0, 0, 3, in_a3);
          }
          if (_CHAR____800d5574 == 0x1000000)
          {
            NewProcess = StateHandlerCrouch;
          LAB_800ab380:
            StateSwitchStateCharacterData(In, NewProcess, 0);
          }
          else
          {
            if ((p_Var3->Data < 4) && ((_BlockVramEntry_800d59a0._12_4_ & 0x800000) == 0))
            {
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000;
              if ((*gameTracker._4_4_ & 0x8000000f) == 0)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer, 0, p_Var3->Data + 1);
              }
            }
            else
            {
              Data_00 = 0;
              if ((_CHAR____800d5720 & 0x2000) != 0)
              {
                Data_00 = 0x1e;
              }
              if ((_CHAR____800d5720 & 0x1000) != 0)
              {
                Data_00 = 0x3c;
              }
              StateSwitchStateCharacterData(In, StateHandlerStopMove, Data_00);
              if ((*gameTracker._4_4_ & LONG_800cf578) != 0)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer, (int)&DAT_80000008, 0);
              }
            }
          }
        }
      }
    }
    else
    {
      if ((int)puVar5 < 1)
      {
        if (puVar5 == &DAT_80000002)
        {
        LAB_800aaf84:
          if ((*gameTracker._4_4_ & LONG_800cf578) == 0)
          {
          LAB_800aafa0:
            if (CurrentSection == 0)
            {
              if (In->CharacterInstance->tface != (_TFace *)0x0)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer, p_Var3->ID, 0);
              }
              goto LAB_800aafdc;
            }
          }
        }
        else
        {
          if ((int)puVar5 < -0x7ffffffd)
          {
            if (puVar5 == (undefined *)0x80000000)
            {
              if ((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) == 0)
              {
                if (pp_Var2[0x48] == (_Instance *)0x44)
                {
                  if ((CurrentSection == 1) && ((_CHAR____800d55b0 & 0x80) == 0))
                  {
                    in_a3 = 10;
                    StateSwitchStateData(In, 1, StateHandlerAttack2, 10);
                  }
                  _CHAR____800d5608 = 200;
                  _CHAR____800d560a = 0xffa0;
                }
                else
                {
                  if (pp_Var2[0x48] != (_Instance *)0x38)
                    goto LAB_800ab390;
                  p_Var4 = razGetHeldItem();
                  if ((p_Var4 != (_Instance *)0x0) && (CurrentSection == 0))
                  {
                    NewProcess = StateHandlerDropAction;
                    goto LAB_800ab380;
                  }
                }
              }
              else
              {
              LAB_800ab390:
                if ((_CHAR____800d55b0 & 0x80) == 0)
                {
                  in_a3 = 0;
                  StateSwitchStateData(In, CurrentSection, StateHandlerAttack2, 0);
                }
              }
            }
            else
            {
              if (puVar5 != (undefined *)0x80000001)
                goto LAB_800ab3c4;
              if (CurrentSection != 0)
                goto LAB_800ab3d0;
              if ((*gameTracker._4_4_ & LONG_800cf578) == 0)
              {
                _CHAR____800d5574 = 8;
                in_a3 = 0;
                Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0, (int *)0x0, (int *)0x0);
                if (Data_00 != 0)
                {
                  in_a3 = 0;
                  goto LAB_800ab2a8;
                }
              }
              else
              {
                _CHAR____800d5574 = 0x20;
                in_a3 = 0;
                Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x20, (int *)0x0, (int *)0x0);
                if (Data_00 != 0)
                {
                  in_a3 = 1;
                LAB_800ab2a8:
                  G2EmulationSwitchAnimationCharacter(In, 0x1a, 0, in_a3, 1);
                }
              }
              StateSwitchStateCharacterData(In, StateHandlerCompression, 0);
            LAB_800ab2c4:
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xffffdfff;
            }
          }
          else
          {
            if (puVar5 != &DAT_80000008)
            {
              if ((int)puVar5 < -0x7ffffff7)
              {
                if (puVar5 == &DAT_80000004)
                {
                  if ((_CHAR____800d5574 & 0x200000) == 0)
                  {
                    if (CurrentSection != 2)
                    {
                      local_2c = 2;
                      Data_00 = CurrentSection;
                    }
                    else
                    {
                      Data_00 = 2;
                      local_2c = CurrentSection;
                    }
                    in_a3 = 0;
                    G2EmulationSwitchAnimation(In, Data_00, (uint)(CurrentSection != 2), 0, 3, local_2c);
                    _CHAR____800d5574 = 2;
                    _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000;
                  }
                  goto LAB_800ab3d0;
                }
              }
              else
              {
                if (puVar5 == &DAT_80000010)
                  goto LAB_800aafa0;
              }
            LAB_800ab3c4:
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
        }
      }
      else
      {
        if (puVar5 == (undefined *)0x4010080)
        {
          if (CurrentSection == 0)
          {
            if (p_Var3->Data == 0)
            {
              razSetPauseTranslation(In->CharacterInstance);
            }
            else
            {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else
        {
          if (0x4010080 < (int)puVar5)
          {
            if (puVar5 == (undefined *)0x20000004)
            {
            LAB_800ab204:
              _CHAR____800d5574 = 4;
              goto LAB_800ab2c4;
            }
            if ((int)puVar5 < 0x20000005)
            {
              if (puVar5 == (undefined *)0x10000000)
              {
                if (_CHAR____800d5588 < 0x1000)
                {
                  StateInitMove(In, CurrentSection, 3);
                }
                else
                {
                  StateInitMove(In, CurrentSection, 0);
                }
                goto LAB_800ab3d0;
              }
            }
            else
            {
              if (puVar5 == (undefined *)0x20000008)
                goto LAB_800ab204;
            }
            goto LAB_800ab3c4;
          }
          if (puVar5 == &DAT_00100004)
          {
            FX_EndConstrict(0, (_Instance *)0x0);
            pp_Var2[0x47] = (_Instance *)0x0;
          }
          else
          {
            if ((int)puVar5 < 0x100005)
            {
              if (puVar5 != &DAT_00100001)
                goto LAB_800ab3c4;
              pp_Var2[0x48] = (_Instance *)0xffffffff;
              StateInitMove(In, CurrentSection, p_Var3->Data);
              _CHAR____800d5638 = 1;
              SteerSwitchMode(In->CharacterInstance, 2);
              pp_Var2[0x47] = (_Instance *)0x0;
              _CHAR____800d5720 = _CHAR____800d5720 | 0x1000;
            }
            else
            {
              if (puVar5 != (undefined *)0x2000000)
                goto LAB_800ab3c4;
              if ((_CHAR____800d55f0 & 0x20) == 0)
                goto LAB_800aaf84;
              razPickupAndGrab(In, CurrentSection);
            }
          }
        }
      }
    }
  LAB_800ab3d0:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerStopMove(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
// line 2105, offset 0x800ab430
/* begin block 1 */
// Start line: 2106
// Start offset: 0x800AB430
// Variables:
// 		struct __Event *Ptr; // $a1
/* end block 1 */
// End offset: 0x800AB768
// End Line: 2202

/* begin block 2 */
// Start line: 4448
/* end block 2 */
// End Line: 4449

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerStopMove(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int anim;
  undefined *puVar2;
  int in_a3;
  __State *p_Var3;

  p_Var3 = In->SectionList + CurrentSection;
  do
  {
    p_Var1 = PeekMessageQueue(&p_Var3->Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      if (CurrentSection == 0)
      {
        _CHAR____800d5574 = 4;
        if ((_BlockVramEntry_800d59a0._12_4_ & 0x800000) == 0)
        {
          _BlockVramEntry_800d59a0._12_4_ = 0;
        }
        else
        {
          _BlockVramEntry_800d59a0._12_4_ = 0x800000;
        }
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2119;
      }
      if (p_Var1->Data == 0x3c)
      {
        in_a3 = -1;
        anim = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x58, -1, -1);
        if (anim != 0)
        {
          anim = 2;
        LAB_800ab5e4:
          in_a3 = -1;
          razSwitchVAnimSingle(In->CharacterInstance, CurrentSection, anim, -1, -1);
        }
      }
      else
      {
        if (p_Var1->Data != 0x1e)
        {
          anim = 6;
        LAB_800ab6ac:
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, anim, in_a3);
        }
        in_a3 = -1;
        anim = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x5c, -1, -1);
        if (anim != 0)
        {
          anim = 3;
          goto LAB_800ab5e4;
        }
      }
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if (puVar2 == &DAT_80000002)
        {
        LAB_800ab688:
          /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var3->Defer, p_Var1->ID, 0);
        }
        if ((int)puVar2 < -0x7ffffffd)
        {
          if (puVar2 == (undefined *)0x80000001)
          {
            if (CurrentSection == 0)
            {
              _CHAR____800d5574 = 0x10;
              in_a3 = 0;
              anim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0, (int *)0x0, (int *)0x0);
              if (anim != 0)
              {
                in_a3 = 0;
                G2EmulationSwitchAnimationCharacter(In, 0x1a, 0, 0, 1);
              }
              StateSwitchStateCharacterData(In, StateHandlerCompression, 0);
            }
          }
          else
          {
          LAB_800ab750:
            DefaultStateHandler(In, CurrentSection, Data);
          }
        }
        else
        {
          if (puVar2 != &DAT_80000008)
          {
            if (puVar2 == &DAT_80000010)
              goto LAB_800ab688;
            goto LAB_800ab750;
          }
          if (CurrentSection == 0)
          {
            StateSwitchStateCharacterData(In, StateHandlerCrouch, 1);
          }
        }
      }
      else
      {
        if ((int)puVar2 < 0x8000002)
        {
          if (0x7ffffff < (int)puVar2)
          {
            anim = 5;
            goto LAB_800ab6ac;
          }
          if (puVar2 == (undefined *)0x2000000)
            goto LAB_800ab688;
          if (puVar2 != (undefined *)0x4010080)
            goto LAB_800ab750;
          if (CurrentSection == 0)
          {
            if (p_Var1->Data == 0)
            {
              razSetPauseTranslation(In->CharacterInstance);
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0, 0, 5, in_a3);
            }
            razResetPauseTranslation(In->CharacterInstance);
          }
        }
        else
        {
          if (puVar2 != (undefined *)0x10000000)
            goto LAB_800ab750;
          in_a3 = 0;
          StateSwitchStateData(In, CurrentSection, StateHandlerStartMove, 0);
        }
      }
    }
    DeMessageQueue(&p_Var3->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
// line 2209, offset 0x800ab788
/* begin block 1 */
// Start line: 2210
// Start offset: 0x800AB788
// Variables:
// 		struct __Event *Ptr; // $v0
/* end block 1 */
// End offset: 0x800ABB2C
// End Line: 2305

/* begin block 2 */
// Start line: 4667
/* end block 2 */
// End Line: 4668

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerCompression(__CharacterState *In, int CurrentSection, int Data)

{
  short sVar1;
  __Event *p_Var2;
  long lVar3;
  _G2Bool_Enum _Var4;
  int iVar5;
  undefined *puVar6;
  _Instance *p_Var7;
  uint uVar8;
  __State *p_Var9;

  p_Var9 = In->SectionList + CurrentSection;
  do
  {
    p_Var2 = PeekMessageQueue(&p_Var9->Event);
    if (p_Var2 == (__Event *)0x0)
    {
      return;
    }
    puVar6 = (undefined *)p_Var2->ID;
    if (puVar6 != (undefined *)0x4000001)
    {
      if ((int)puVar6 < 0x4000002)
      {
        if (puVar6 == (undefined *)0x80000001)
        {
          uVar8 = 0x80000000;
        LAB_800abb00:
          /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var9->Defer, uVar8 | 1, 0);
        }
        if (-0x80000000 < (int)puVar6)
        {
          if (puVar6 != &DAT_00100001)
            goto LAB_800abb14;
          if (CurrentSection == 0)
          {
            _BlockVramEntry_800d59a0._12_4_ = 0x111;
            SetExternalForce((__Force *)&_BlockVramEntry_800d58dc.w, 0, 0, 0, 1, 0);
            In->SectionList[0].Data1 = 0;
            PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
            _CHAR____800d55a8 = 0;
            if (_CHAR____800d5574 == 0x10)
            {
              SteerSwitchMode(In->CharacterInstance, 4);
              sVar1 = (In->CharacterInstance->rotation).z;
              p_Var7 = In->CharacterInstance;
              lVar3 = 0x28;
            }
            else
            {
              if ((_CHAR____800d5574 < 0x11) || (_CHAR____800d5574 != 0x20))
                goto LAB_800abb1c;
              SteerSwitchMode(In->CharacterInstance, 4);
              sVar1 = (In->CharacterInstance->rotation).z;
              p_Var7 = In->CharacterInstance;
              lVar3 = 0x15;
            }
            _CHAR____800d55a4 = (int)sVar1;
            p_Var7->yVel = lVar3;
            _Var4 = G2Anim_IsControllerActive(&In->CharacterInstance->anim, 1, 0xe);
            if (_Var4 == G2FALSE)
            {
              G2Anim_EnableController(&In->CharacterInstance->anim, 1, 0xe);
            }
          }
        }
      }
      else
      {
        if (puVar6 == (undefined *)0x8000000)
        {
          if (_CHAR____800d5574 == 8)
          {
            if (CurrentSection == 0)
            {
              iVar5 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 4, (int *)0x0, (int *)0x0);
              if (iVar5 != 0)
              {
                G2EmulationSwitchAnimationCharacter(In, 0x1b, 0, 0, 1);
              }
              SetPhysics(In->CharacterInstance, -0x10, 0, 0x53, 0x9a);
            }
          }
          else
          {
            if (_CHAR____800d5574 == 0x20)
            {
              if (CurrentSection == 0)
              {
                iVar5 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x24, (int *)0x0, (int *)0x0);
                if (iVar5 != 0)
                {
                  G2EmulationSwitchAnimationCharacter(In, 0x27, 0, 0, 1);
                }
                SetPhysics(In->CharacterInstance, -0x10, 0, 0x15, 0xc3);
                In->CharacterInstance->yVel = 0;
              }
            }
            else
            {
              if (CurrentSection == 0)
              {
                iVar5 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x14, (int *)0x0, (int *)0x0);
                if (iVar5 != 0)
                {
                  G2EmulationSwitchAnimationCharacter(In, 0x23, 0, 0, 1);
                }
                SetPhysics(In->CharacterInstance, -0x10, 0, 0x28, 0x9a);
                In->CharacterInstance->yVel = 0;
                if (In->SectionList[0].Data1 == 1)
                {
                  In->CharacterInstance->zVel = (In->CharacterInstance->zVel << 1) / 3;
                }
              }
            }
          }
          StateSwitchStateData(In, CurrentSection, StateHandlerJump, 0);
        }
        else
        {
          if ((int)puVar6 < 0x8000001)
          {
            if (puVar6 != (undefined *)0x4020000)
            {
            LAB_800abb14:
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
          else
          {
            if (puVar6 != (undefined *)0x20000001)
              goto LAB_800abb14;
            if (CurrentSection == 0)
            {
              if (_CHAR____800d5574 == 0x10)
              {
                In->SectionList[0].Data1 = 1;
              }
              p_Var9 = In->SectionList;
              uVar8 = 0x20000000;
              goto LAB_800abb00;
            }
          }
        }
      }
    }
  LAB_800abb1c:
    DeMessageQueue(&p_Var9->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerJump(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
// line 2308, offset 0x800abb4c
/* begin block 1 */
// Start line: 2309
// Start offset: 0x800ABB4C
// Variables:
// 		struct __Event *Ptr; // $v0
/* end block 1 */
// End offset: 0x800ABF5C
// End Line: 2408

/* begin block 2 */
// Start line: 4888
/* end block 2 */
// End Line: 4889

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerJump(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  __MessageQueue *In_00;
  uint uVar3;
  short y;
  code *Data_00;
  short z;
  undefined4 in_a3;
  int Frames;
  __State *p_Var4;
  int local_28;
  int in_stack_ffffffdc;

  p_Var4 = In->SectionList + CurrentSection;
  Data_00 = (code *)Data;
  do
  {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    z = (short)in_a3;
    y = (short)Data_00;
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 != (undefined *)0x1000001)
    {
      if ((int)puVar2 < 0x1000002)
      {
        if (puVar2 != &DAT_80000008)
        {
          if ((int)puVar2 < -0x7ffffff7)
          {
            if (puVar2 != (undefined *)0x80000000)
            {
              if (puVar2 != (undefined *)0x80000001)
                goto LAB_800abf44;
              NewAnim = G2EmulationQueryFrame(In, CurrentSection);
              In_00 = &p_Var4->Defer;
              if (NewAnim < 2)
              {
                uVar3 = 0x80000000;
                goto LAB_800abf20;
              }
              if ((_CHAR____800d5600 != 3) && (CurrentSection == 0))
              {
                Data_00 = (code *)0x0;
                StateSwitchStateCharacterData(In, StateHandlerGlide, 0);
              }
            }
          }
          else
          {
            if (puVar2 != &DAT_00040005)
            {
              if ((int)puVar2 < 0x40006)
              {
                if (puVar2 != &DAT_80000020)
                {
                LAB_800abf44:
                  Data_00 = (code *)Data;
                  DefaultStateHandler(In, CurrentSection, Data);
                }
              }
              else
              {
                if (puVar2 != &DAT_00100001)
                  goto LAB_800abf44;
                if (CurrentSection == 0)
                {
                  _BlockVramEntry_800d59a0._12_4_ = 0x511;
                  _CHAR____800d5774 = 200;
                  PhysicsMode.next = (_BlockVramEntry *)0x0;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5774;
                }
                In->SectionList[CurrentSection].Data2 = 0;
              }
            }
          }
        }
      }
      else
      {
        if (puVar2 != (undefined *)0x4020000)
        {
          if ((int)puVar2 < 0x4020001)
          {
            if (puVar2 != (undefined *)0x4000001)
            {
              if ((int)puVar2 < 0x4000002)
              {
                if (puVar2 != (undefined *)0x2000000)
                  goto LAB_800abf44;
                razPickupAndGrab(In, CurrentSection);
              }
              else
              {
                if (puVar2 != (undefined *)0x4010008)
                  goto LAB_800abf44;
              }
            }
          }
          else
          {
            if (puVar2 == (undefined *)0x8000004)
            {
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 8;
            }
            else
            {
              if (0x8000004 < (int)puVar2)
              {
                if (puVar2 != (undefined *)0x20000001)
                  goto LAB_800abf44;
                In->SectionList[CurrentSection].Data2 = 1;
                if (CurrentSection != 0)
                  goto LAB_800abf4c;
                if ((_CHAR____800d5574 == 0x10) || (_CHAR____800d5574 == 0x20))
                {
                  In_00 = &In->SectionList[0].Defer;
                  uVar3 = 0x20000000;
                  goto LAB_800abf20;
                }
                if (In->SectionList[0].Data1 == 0)
                {
                  NewAnim = G2EmulationQueryFrame(In, 0);
                  In->SectionList[0].Data1 = NewAnim + 4;
                  if (NewAnim + 4 != 0)
                    goto LAB_800abe58;
                }
                else
                {
                LAB_800abe58:
                  NewAnim = G2EmulationQueryFrame(In, 0);
                  if (In->SectionList[0].Data1 < NewAnim)
                  {
                    SetExternalForce((__Force *)In->CharacterInstance, 0x5214, y, z, local_28,
                                     in_stack_ffffffdc);
                    in_a3 = 0;
                    NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 8, (int *)0x0, (int *)0x0);
                    if (NewAnim != 0)
                    {
                      local_28 = 1;
                      in_a3 = 7;
                      G2EmulationSwitchAnimationCharacter(In, 0x1c, 0, 7, 1);
                    }
                    Data_00 = (code *)In->SectionList[0].Data2;
                    StateSwitchStateCharacterData(In, StateHandlerFall, (int)Data_00);
                    goto LAB_800abf4c;
                  }
                }
                In_00 = &p_Var4->Defer;
                uVar3 = 0x20000000;
              LAB_800abf20:
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(In_00, uVar3 | 1, 0);
              }
              if (puVar2 != (undefined *)0x8000000)
                goto LAB_800abf44;
              if (CurrentSection == 0)
              {
                if (_CHAR____800d5574 == 0x10)
                {
                  NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x18, (int *)0x0, (int *)0x0);
                  if (NewAnim != 0)
                  {
                    NewAnim = 0x24;
                    Frames = 4;
                    goto LAB_800abdb8;
                  }
                }
                else
                {
                  if (_CHAR____800d5574 == 0x20)
                  {
                    NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x28, (int *)0x0, (int *)0x0);
                    if (NewAnim != 0)
                    {
                      NewAnim = 0x28;
                      Frames = 10;
                    LAB_800abdb8:
                      local_28 = 1;
                      G2EmulationSwitchAnimationCharacter(In, NewAnim, 0, Frames, 1);
                    }
                  }
                  else
                  {
                    NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 8, (int *)0x0, (int *)0x0);
                    if (NewAnim != 0)
                    {
                      NewAnim = 0x1c;
                      Frames = 7;
                      goto LAB_800abdb8;
                    }
                  }
                }
              }
              Data_00 = StateHandlerFall;
              in_a3 = 0;
              StateSwitchStateData(In, CurrentSection, StateHandlerFall, 0);
              if ((*gameTracker._4_4_ & LONG_800cf56c) == 0)
              {
                In->SectionList[CurrentSection].Data2 = 1;
              }
            }
          }
        }
      }
    }
  LAB_800abf4c:
    DeMessageQueue(&p_Var4->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerFall(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
// line 2411, offset 0x800abf84
/* begin block 1 */
// Start line: 2412
// Start offset: 0x800ABF84
// Variables:
// 		struct __Event *Ptr; // $s0
// 		int Moving; // $s7
// 		int DeferFlag; // $s6
// 		struct evPhysicsSwimData *SwimData; // $s1

/* begin block 1.1 */
// Start line: 2430
// Start offset: 0x800ABFC8
/* end block 1.1 */
// End offset: 0x800ABFFC
// End Line: 2436
/* end block 1 */
// End offset: 0x800AC3C8
// End Line: 2617

/* begin block 2 */
// Start line: 5132
/* end block 2 */
// End Line: 5133

/* WARNING: Removing unreachable block (ram,0x800ac208) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerFall(__CharacterState *In, int CurrentSection, int Data)

{
  short sVar1;
  __Event *p_Var2;
  undefined *puVar3;
  _Instance *instance;
  code *SwimData;
  undefined4 in_a3;
  int local_28;
  int local_24;
  int iVar4;
  __State *p_Var5;

  if (CurrentSection == 0)
  {
    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
  }
  p_Var5 = In->SectionList + CurrentSection;
  SwimData = (code *)Data;
  do
  {
    p_Var2 = PeekMessageQueue(&p_Var5->Event);
    if (p_Var2 == (__Event *)0x0)
    {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 != (undefined *)0x1000001)
    {
      if ((int)puVar3 < 0x1000002)
      {
        if (puVar3 != &DAT_80000020)
        {
          if ((int)puVar3 < -0x7fffffdf)
          {
            if (puVar3 == (undefined *)0x80000001)
            {
              if (((_CHAR____800d5600 != 3) && ((_BlockVramEntry_800d59a0._12_4_ & 0x2000000) == 0)) && (CurrentSection == 0))
              {
                SwimData = (code *)&DAT_00000003;
                StateSwitchStateCharacterData(In, StateHandlerGlide, 3);
              }
            }
            else
            {
              if ((-0x80000000 < (int)puVar3) && (puVar3 != &DAT_80000008))
                goto LAB_800ac3ac;
            }
          }
          else
          {
            if (puVar3 == (undefined *)0x100000)
            {
              SwimData = (code *)0x0;
              StateSwitchStateCharacterData(In, StateHandlerForcedGlide, 0);
            }
            else
            {
              if ((int)puVar3 < 0x100001)
              {
                if (puVar3 != &DAT_00040005)
                  goto LAB_800ac3ac;
                if (_CHAR____800d5610 < 100000)
                {
                  SwimData = StateHandlerStumble;
                  in_a3 = 0;
                  StateSwitchStateData(In, CurrentSection, StateHandlerStumble, 0);
                }
              }
              else
              {
                if (puVar3 != &DAT_00100001)
                  goto LAB_800ac3ac;
                if (CurrentSection == 0)
                {
                  _BlockVramEntry_800d59a0._12_4_ = 0x119;
                  if (_CHAR____800d5574 != 0x100)
                  {
                    _BlockVramEntry_800d59a0._12_4_ = 0x519;
                  }
                  In->SectionList[0].Data1 = 0;
                  _CHAR____800d55a8 = 0;
                  PhysicsMode.next = (_BlockVramEntry *)0x0;
                }
                if ((p_Var2->Data != 0) && ((*gameTracker._4_4_ & LONG_800cf56c) != 0))
                {
                  /* WARNING: Subroutine does not return */
                  EnMessageQueueData(&p_Var5->Defer, -0x7fffffff, 0);
                }
              }
            }
          }
        }
      }
      else
      {
        if (puVar3 == (undefined *)0x4020000)
        {
          iVar4 = p_Var2->Data;
          if (((*(short *)(iVar4 + 0xc) < 0) &&
               (instance = In->CharacterInstance, instance->zVel == 0)) &&
              (-1 < instance->zAccl))
          {
            ResetPhysics(instance, -0x10);
          }
          _CHAR____800d5574 = _CHAR____800d5574 & 0xfffbffff;
          SwimData = (code *)p_Var2->Data;
          razEnterWater(In, CurrentSection, (evPhysicsSwimData *)SwimData);
          sVar1 = *(short *)(iVar4 + 0xe);
          if (((sVar1 < 0) && (sVar1 != -0x7fff)) && (_CHAR____800d564c == 1))
          {
            _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000000;
          }
        }
        else
        {
          if ((int)puVar3 < 0x4020001)
          {
            if (puVar3 != (undefined *)0x4000001)
            {
              if ((int)puVar3 < 0x4000002)
              {
                if (puVar3 == (undefined *)0x2000000)
                {
                  razPickupAndGrab(In, CurrentSection);
                  goto LAB_800ac3b8;
                }
              }
              else
              {
                if (puVar3 == (undefined *)0x4010008)
                {
                  /* WARNING: Subroutine does not return */
                  EnMessageQueueData(&p_Var5->Event, 0x4010008, 0);
                }
              }
            LAB_800ac3ac:
              SwimData = (code *)Data;
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
          else
          {
            if (puVar3 != (undefined *)0x10000000)
            {
              if ((int)puVar3 < 0x10000001)
              {
                if (puVar3 != (undefined *)0x8000000)
                  goto LAB_800ac3ac;
              }
              else
              {
                if (puVar3 != (undefined *)0x20000001)
                  goto LAB_800ac3ac;
                if (((_CHAR____800d5574 != 0x10) && (_CHAR____800d5574 != 0x20)) &&
                    (CurrentSection == 0))
                {
                  SetExternalForce((__Force *)In->CharacterInstance, 0x5214, (short)SwimData,
                                   (short)in_a3, local_28, local_24);
                }
              }
            }
          }
        }
      }
    }
  LAB_800ac3b8:
    DeMessageQueue(&p_Var5->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerSlide(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
// line 2621, offset 0x800ac3f8
/* begin block 1 */
// Start line: 2622
// Start offset: 0x800AC3F8
// Variables:
// 		struct __Event *Ptr; // $v0
/* end block 1 */
// End offset: 0x800AC5BC
// End Line: 2678

/* begin block 2 */
// Start line: 5560
/* end block 2 */
// End Line: 5561

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSlide(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  int in_a3;

  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000)
    {
    LAB_800ac570:
      /* WARNING: Subroutine does not return */
      SetPhysicsWallCrawlData(0, 0, 3, in_a3);
    }
    if ((int)puVar2 < 0x100001)
    {
      if (puVar2 != &DAT_80000008)
      {
        if ((int)puVar2 < -0x7ffffff7)
        {
          if (-0x7fffffff < (int)puVar2)
          {
          LAB_800ac5a4:
            DefaultStateHandler(In, CurrentSection, Data);
          }
        }
        else
        {
          if (puVar2 != &DAT_80000020)
            goto LAB_800ac5a4;
        }
      }
    }
    else
    {
      if (puVar2 == (undefined *)0x4010008)
        goto LAB_800ac570;
      if ((int)puVar2 < 0x4010009)
      {
        if (puVar2 == &DAT_00100001)
        {
          if (CurrentSection == 0)
          {
            _CHAR____800d5574 = 0x400000;
            _BlockVramEntry_800d59a0._12_4_ = 0x509;
            PhysicsMode.next = (_BlockVramEntry *)0x0;
            ResetPhysics(In->CharacterInstance, -0x10);
            in_a3 = 0x3c;
            _CHAR____800d577c =
                SOUND_Play3dSound(&In->CharacterInstance->position, 0x1e, 0, 0x3c, 0xdac);
          }
        }
        else
        {
          if (puVar2 != &DAT_00100004)
            goto LAB_800ac5a4;
          if (_CHAR____800d577c != 0)
          {
            /* WARNING: Subroutine does not return */
            SndEndLoop(_CHAR____800d577c);
          }
        }
      }
      else
      {
        if ((puVar2 != (undefined *)0x4010200) && (puVar2 != (undefined *)0x20000001))
          goto LAB_800ac5a4;
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerBlock(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$s7*/)
// line 2688, offset 0x800ac5d8
/* begin block 1 */
// Start line: 2689
// Start offset: 0x800AC5D8
// Variables:
// 		struct __Event *Ptr; // $a0
// 		int Anim; // $s3

/* begin block 1.1 */
// Start line: 2727
// Start offset: 0x800AC7E0
// Variables:
// 		struct _Rotation rot; // stack offset -56
/* end block 1.1 */
// End offset: 0x800AC7E0
// End Line: 2728

/* begin block 1.2 */
// Start line: 2743
// Start offset: 0x800AC868
/* end block 1.2 */
// End offset: 0x800AC868
// End Line: 2744

/* begin block 1.3 */
// Start line: 2757
// Start offset: 0x800AC90C
// Variables:
// 		struct evPhysicsEdgeData *EdgeData; // $s1

/* begin block 1.3.1 */
// Start line: 2762
// Start offset: 0x800AC94C
// Variables:
// 		struct SVECTOR startVec; // stack offset -56
// 		struct SVECTOR endVec; // stack offset -48
/* end block 1.3.1 */
// End offset: 0x800AC9A4
// End Line: 2770
/* end block 1.3 */
// End offset: 0x800AC9F8
// End Line: 2779
/* end block 1 */
// End offset: 0x800ACA18
// End Line: 2792

/* begin block 2 */
// Start line: 5703
/* end block 2 */
// End Line: 5704

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerBlock(__CharacterState *In, int CurrentSection, int Data)

{
  int Data_00;
  __Event *p_Var1;
  undefined *puVar2;
  int in_a3;
  SVECTOR aSStack56[2];

  Data_00 = G2EmulationQueryAnimation(In, CurrentSection);
  if (CurrentSection == 0)
  {
    BlockCount = BlockCount + 1;
  }
  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100004)
    {
      COLLIDE_SegmentCollisionOn(In->CharacterInstance, 1);
      BlockCount = 0;
      FX_EndPassthruFX(In->CharacterInstance);
    }
    else
    {
      if ((int)puVar2 < 0x100005)
      {
        if (puVar2 != &DAT_80000008)
        {
          if ((int)puVar2 < -0x7ffffff7)
          {
            if (puVar2 != (undefined *)0x80000000)
            {
            LAB_800ac9fc:
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
          else
          {
            if (puVar2 == (undefined *)0x0)
            {
              if ((CurrentSection == 0) && (Data_00 != 0x6c))
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
            }
            else
            {
              if (puVar2 != &DAT_00100001)
                goto LAB_800ac9fc;
              if (CurrentSection == 0)
              {
                _CHAR____800d5574 = 0x800000;
                _BlockVramEntry_800d59a0._12_4_ = &DAT_00008009;
                PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
                SteerSwitchMode(In->CharacterInstance, 0);
                in_a3 = 10;
                G2EmulationSwitchAnimationCharacter(In, 0x51, 0, 10, 1);
              }
              In->SectionList[CurrentSection].Data1 = 0;
            }
          }
        }
      }
      else
      {
        if (puVar2 == (undefined *)0x4010400)
        {
          if ((((*(uint *)(p_Var1->Data + 0x20) & 0x20000) != 0) && ((_CHAR____800d561c & 1) != 0)) && (_CHAR____800d564c == 2))
          {
            /* WARNING: Subroutine does not return */
            PHYSICS_GenericLineCheckSetup(0, 0, 0, aSStack56);
          }
        }
        else
        {
          if ((int)puVar2 < 0x4010401)
          {
            if ((puVar2 != (undefined *)0x4000001) && (puVar2 != (undefined *)0x4010200))
              goto LAB_800ac9fc;
          }
          else
          {
            if (puVar2 == (undefined *)0x8000000)
            {
              if (CurrentSection == 0)
              {
                if ((Data_00 == 0x52) || (Data_00 == 0x6c))
                {
                  /* WARNING: Subroutine does not return */
                  SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                }
                if (In->SectionList[0].Data1 == 0)
                {
                  in_a3 = 3;
                  G2EmulationSwitchAnimationCharacter(In, 0x52, 0, 3, 1);
                  _CHAR____800d5774 = 0x640;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5774;
                }
                else
                {
                  in_a3 = 5;
                  G2EmulationSwitchAnimationCharacter(In, 0x6c, 0, 5, 1);
                  COLLIDE_SegmentCollisionOff(In->CharacterInstance, 1);
                  razGetRotFromNormal((_SVector *)&CHAR____800d55b4, (_Rotation *)aSStack56);
                  (In->CharacterInstance->rotation).z = aSStack56[0].vz;
                }
              }
            }
            else
            {
              if (puVar2 != (undefined *)0x8000004)
                goto LAB_800ac9fc;
              if ((_CHAR____800d55f0 & 1) != 0)
              {
                razGetForwardNormal(In->CharacterInstance, *_CHAR____800d55ec);
                SetupReaction(In->CharacterInstance, *_CHAR____800d55ec);
                Data_00 = SetObjectData(-(int)_CHAR____800d55b4, -(int)_CHAR____800d55b6, 6,
                                        (_Instance *)0x0, 0);
                /* WARNING: Subroutine does not return */
                INSTANCE_Post(*_CHAR____800d55ec, 0x800000, Data_00);
              }
            }
          }
        }
      }
    }
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerDeCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
// line 2795, offset 0x800aca44
/* begin block 1 */
// Start line: 2796
// Start offset: 0x800ACA44
// Variables:
// 		struct __Event *Ptr; // $s1

/* begin block 1.1 */
// Start line: 2805
// Start offset: 0x800ACB1C
/* end block 1.1 */
// End offset: 0x800ACC94
// End Line: 2844
/* end block 1 */
// End offset: 0x800ACD90
// End Line: 2884

/* begin block 2 */
// Start line: 5926
/* end block 2 */
// End Line: 5927

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerDeCompression(__CharacterState *In, int CurrentSection, int Data)

{
  short sVar1;
  __Event *p_Var2;
  int NewAnim;
  undefined *puVar3;
  _Instance *instance;
  code *NewProcess;
  int in_a3;
  _Instance **pp_Var4;

  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  In->CharacterInstance->cachedTFace = -1;
  do
  {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0)
    {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100001)
    {
      if (CurrentSection == 0)
      {
        In->SectionList[0].Data1 = _CHAR____800d5574;
        _BlockVramEntry_800d59a0._12_4_ = 0x119;
        _CHAR____800d5574 = _CHAR____800d5574 | 0x1000;
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        SteerSwitchMode(In->CharacterInstance, 0);
        NewAnim = G2EmulationQueryAnimation(In, 0);
        sVar1 = (short)NewAnim;
        if (((((_CHAR____800d5574 & 0x20) == 0) && (sVar1 != 0x11)) && (sVar1 != 0x12)) &&
            (sVar1 != 0x13))
        {
          instance = In->CharacterInstance;
          if (instance->zVel < -0x100)
            goto LAB_800acbe4;
          if (((_CHAR____800d5574 & 0x10) == 0) && (p_Var2->Data != 0))
          {
            in_a3 = 0;
            NewAnim = razSwitchVAnimCharacterGroup(instance, 0xc, (int *)0x0, (int *)0x0);
            if (NewAnim != 0)
            {
              in_a3 = 0;
              G2EmulationSwitchAnimationCharacter(In, 0x1d, 0, 0, 1);
            }
            goto LAB_800acd80;
          }
          in_a3 = 0;
          NewAnim = razSwitchVAnimCharacterGroup(instance, 0x1c, (int *)0x0, (int *)0x0);
          if (NewAnim == 0)
            goto LAB_800acd80;
          NewAnim = 0x25;
        }
        else
        {
        LAB_800acbe4:
          in_a3 = 0;
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x2c, (int *)0x0, (int *)0x0);
          if (NewAnim == 0)
            goto LAB_800acd80;
          NewAnim = 0x29;
        }
        in_a3 = 1;
        G2EmulationSwitchAnimationCharacter(In, NewAnim, 0, 1, 1);
      }
      else
      {
        pp_Var4[0x47] = (_Instance *)In->SectionList[CurrentSection + -1].Data1;
      }
    }
    else
    {
      if ((int)puVar3 < 0x100002)
      {
        if ((puVar3 != (undefined *)0x80000000) && (puVar3 != &DAT_80000020))
          goto LAB_800acd78;
      }
      else
      {
        if (puVar3 == (undefined *)0x8000000)
        {
          if ((*gameTracker._4_4_ & LONG_800cf578) == 0)
          {
            if ((*gameTracker._4_4_ & 0x8000000f) == 0)
            {
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0, 0, 4, in_a3);
            }
            if (CurrentSection != 0)
              goto LAB_800acd70;
            NewAnim = G2EmulationQueryAnimation(In, 0);
            if (NewAnim != 0x1d)
            {
              StateSwitchStateCharacterData(In, StateHandlerStartMove, 5);
              pp_Var4[0x47] = (_Instance *)0x0;
              goto LAB_800acd80;
            }
            NewProcess = StateHandlerMove;
          }
          else
          {
            if (CurrentSection != 0)
            {
            LAB_800acd70:
              pp_Var4[0x47] = (_Instance *)0x0;
              goto LAB_800acd80;
            }
            NewProcess = StateHandlerCrouch;
          }
          StateSwitchStateCharacterData(In, NewProcess, 0);
          pp_Var4[0x47] = (_Instance *)0x0;
        }
        else
        {
          if ((int)puVar3 < 0x8000001)
          {
            if (puVar3 == &DAT_00100004)
            {
              in_a3 = 0;
              SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
            }
            else
            {
            LAB_800acd78:
              DefaultStateHandler(In, CurrentSection, Data);
            }
          }
          else
          {
            if (puVar3 != (undefined *)0x10000000)
              goto LAB_800acd78;
          }
        }
      }
    }
  LAB_800acd80:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$fp*/)
// line 2889, offset 0x800acdb4
/* begin block 1 */
// Start line: 2890
// Start offset: 0x800ACDB4
// Variables:
// 		struct __Event *Ptr; // $s0
// 		int Frame; // $s7
// 		int Anim; // $s5
// 		int moving; // $s6

/* begin block 1.1 */
// Start line: 3009
// Start offset: 0x800AD32C
// Variables:
// 		struct evObjectDraftData *draft; // $a2
/* end block 1.1 */
// End offset: 0x800AD384
// End Line: 3016

/* begin block 1.2 */
// Start line: 3021
// Start offset: 0x800AD3AC
// Variables:
// 		struct evPhysicsSwimData *SwimData; // $v0
/* end block 1.2 */
// End offset: 0x800AD43C
// End Line: 3034
/* end block 1 */
// End offset: 0x800AD4F0
// End Line: 3087

/* begin block 2 */
// Start line: 6140
/* end block 2 */
// End Line: 6141

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerGlide(__CharacterState *In, int CurrentSection, int Data)

{
  bool bVar1;
  undefined *puVar2;
  int local_38;
  int iVar3;
  __Event *p_Var4;
  undefined *puVar5;
  uint uVar6;
  code *NewProcess;
  short z;
  _Instance **pp_Var7;
  __State *p_Var8;
  int local_34;

  bVar1 = false;
  local_38 = G2EmulationQueryAnimation(In, CurrentSection);
  iVar3 = G2EmulationQueryFrame(In, CurrentSection);
  if (CurrentSection == 0)
  {
    In->SectionList[0].Data2 = In->SectionList[0].Data2 & 0xfffffffd;
  }
  p_Var8 = In->SectionList + CurrentSection;
  pp_Var7 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var4 = PeekMessageQueue(&p_Var8->Event);
    if (p_Var4 == (__Event *)0x0)
    {
      if ((CurrentSection == 0) && (uVar6 = In->SectionList[0].Data2, (uVar6 & 1) != 0))
      {
        if ((uVar6 & 2) == 0)
        {
          if (bVar1)
          {
            local_38 = 0x34;
          }
          else
          {
            local_38 = 0;
          }
          SetExternalTransitionForce((__Force *)&_BlockVramEntry_800d58c0.type, In->CharacterInstance, 10, 0, local_38,
                                     -0x18);
          In->SectionList[0].Data2 = 0;
        }
        else
        {
          if (bVar1)
          {
            In->CharacterInstance->yVel = 0x34;
          }
          else
          {
            In->CharacterInstance->yVel = 0;
          }
        }
      }
      return;
    }
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 != (undefined *)0x4000001)
    {
      if ((int)puVar5 < 0x4000002)
      {
        if (puVar5 != &DAT_80000020)
        {
          if ((int)puVar5 < -0x7fffffdf)
          {
            if (puVar5 == &DAT_80000004)
            {
              if (CurrentSection == 1)
              {
                SetExternalTransitionForce((__Force *)&_BlockVramEntry_800d58c0.type, In->CharacterInstance, 4, 0, 0x18,
                                           -0x18);
              }
              G2EmulationSwitchAnimation(In, CurrentSection, 0x11, 0, 5, 2);
              pp_Var7[0x47] = (_Instance *)0x0;
              if (((uint)pp_Var7[0x48] & 1) != 0)
              {
                razSetPlayerEventHistory(0x4000);
              }
            }
            else
            {
              if ((int)puVar5 < -0x7ffffffb)
              {
                if (puVar5 != (undefined *)0x80000000)
                  goto LAB_800ad43c;
              }
              else
              {
                puVar2 = &DAT_80000008;
              joined_r0x800aced8:
                if (puVar5 != puVar2)
                  goto LAB_800ad43c;
              }
            }
          }
          else
          {
            if (puVar5 == &DAT_00100001)
            {
              if (CurrentSection == 0)
              {
                _CHAR____800d5574 = 0x2000;
                _BlockVramEntry_800d59a0._12_4_ = 0x518;
                PhysicsMode.next = (_BlockVramEntry *)0x0;
                SteerSwitchMode(In->CharacterInstance, 8);
                DeInitAlgorithmicWings(In->CharacterInstance);
                if (In->CharacterInstance->zVel < 0)
                {
                  SetPhysics(In->CharacterInstance, 0, 0, 0x34, -0x18);
                }
              }
              pp_Var7[0x47] = (_Instance *)0x1;
              pp_Var7[0x48] = (_Instance *)0x0;
              G2EmulationSwitchAnimation(In, CurrentSection, 0x10, p_Var4->Data, 5, 1);
            }
            else
            {
              if ((int)puVar5 < 0x100002)
              {
                puVar2 = &DAT_00040005;
                goto joined_r0x800aced8;
              }
              if (puVar5 == &DAT_00100004)
              {
                if (CurrentSection == 0)
                {
                  InitAlgorithmicWings(In->CharacterInstance);
                  In->SectionList[0].Data2 = 0;
                }
              }
              else
              {
                if (puVar5 != (undefined *)0x1000001)
                  goto LAB_800ad43c;
              }
            }
          }
        }
      }
      else
      {
        if (puVar5 == (undefined *)0x8000000)
        {
          if (pp_Var7[0x47] != (_Instance *)0x0)
          {
            G2EmulationSwitchAnimationAlpha(In, CurrentSection, 0x12, 0, 5, 2, 4);
            pp_Var7[0x47] = (_Instance *)0x0;
          }
        }
        else
        {
          if ((int)puVar5 < 0x8000001)
          {
            if (puVar5 == (undefined *)0x4010008)
            {
              NewProcess = StateHandlerDeCompression;
            LAB_800ad42c:
              StateSwitchStateData(In, CurrentSection, NewProcess, 0);
            }
            else
            {
              if ((int)puVar5 < 0x4010009)
              {
                if (puVar5 == (undefined *)0x4000007)
                {
                  if (CurrentSection == 0)
                  {
                    if ((int)(uint)(ushort)((short *)p_Var4->Data)[4] < In->CharacterInstance->zVel)
                    {
                      z = 0;
                      local_34 = 0;
                    }
                    else
                    {
                      z = *(short *)p_Var4->Data;
                      local_34 = 0xffc;
                    }
                    SetExternalForce((__Force *)&_BlockVramEntry_800d58c0.udata, 0, 0, z, 0, local_34);
                    pp_Var7[0x48] = (_Instance *)((uint)pp_Var7[0x48] | 3);
                    _CHAR____800d57c4 = _CHAR____800d57c4 | 0x4000;
                  }
                }
                else
                {
                LAB_800ad43c:
                  DefaultStateHandler(In, CurrentSection, Data);
                }
              }
              else
              {
                if (puVar5 != (undefined *)0x4020000)
                  goto LAB_800ad43c;
                z = *(short *)(p_Var4->Data + 0xe);
                if (((z < 0) && (z != -0x7fff)) && (_CHAR____800d564c == 1))
                {
                  if (CurrentSection == 0)
                  {
                    SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
                  }
                  G2EmulationSwitchAnimation(In, CurrentSection, 0x13, 0, 4, 1);
                  NewProcess = StateHandlerFall;
                  goto LAB_800ad42c;
                }
              }
            }
          }
          else
          {
            if (puVar5 == (undefined *)0x10000000)
            {
              bVar1 = true;
              if (local_38 != 0x10)
              {
                if (0 < _CHAR____800d5598)
                {
                  G2EmulationSwitchAnimation(In, CurrentSection, 0x2b, 0, 6, 1);
                  pp_Var7[0x47] = (_Instance *)0x2;
                }
                if (_CHAR____800d5598 < 0)
                {
                  G2EmulationSwitchAnimation(In, CurrentSection, 0x2c, 0, 6, 1);
                  pp_Var7[0x47] = (_Instance *)0x2;
                }
                bVar1 = true;
                if ((_CHAR____800d5598 == 0) && (pp_Var7[0x47] == (_Instance *)0x2))
                {
                  G2EmulationSwitchAnimation(In, CurrentSection, 0x12, 0, 5, 2);
                  pp_Var7[0x47] = (_Instance *)0x0;
                  bVar1 = true;
                }
              }
            }
            else
            {
              if ((int)puVar5 < 0x10000001)
              {
                if (puVar5 != (undefined *)0x8000003)
                  goto LAB_800ad43c;
                if (local_38 == 0x10)
                {
                  SetPhysics(In->CharacterInstance, 0, 0, 0x34, -0x18);
                }
              }
              else
              {
                if (puVar5 == (undefined *)0x20000001)
                {
                  if (((iVar3 < 0xd) && (local_38 == 0x10)) ||
                      ((*gameTracker._4_4_ & LONG_800cf56c) != 0))
                  {
                    /* WARNING: Subroutine does not return */
                    EnMessageQueueData(&p_Var8->Defer, 0x20000001, 0);
                  }
                  if (CurrentSection == 0)
                  {
                    SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
                    local_34 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x18, (int *)0x0, (int *)0x0);
                    if (local_34 != 0)
                    {
                      G2EmulationSwitchAnimationCharacter(In, 0x24, 0, 4, 1);
                    }
                  }
                  StateSwitchStateCharacterData(In, StateHandlerFall, 0);
                }
                else
                {
                  if (puVar5 != (undefined *)0x20000004)
                    goto LAB_800ad43c;
                  if (CurrentSection == 0)
                  {
                    SetExternalTransitionForce((__Force *)&_BlockVramEntry_800d58c0.type, In->CharacterInstance, 4, 0,
                                               0x34, -0x18);
                  }
                  G2EmulationSwitchAnimation(In, CurrentSection, 0x12, 0, 5, 2);
                  pp_Var7[0x47] = (_Instance *)0x0;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var8->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerHang(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
// line 3090, offset 0x800ad520
/* begin block 1 */
// Start line: 3091
// Start offset: 0x800AD520
// Variables:
// 		struct __Event *Ptr; // $a0
// 		int Anim; // $s7

/* begin block 1.1 */
// Start line: 3103
// Start offset: 0x800AD6E0
// Variables:
// 		struct evControlInitHangData *data; // $s0
/* end block 1.1 */
// End offset: 0x800AD7F4
// End Line: 3133
/* end block 1 */
// End offset: 0x800ADA94
// End Line: 3244

/* begin block 2 */
// Start line: 6555
/* end block 2 */
// End Line: 6556

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerHang(__CharacterState *In, int CurrentSection, int Data)

{
  int iVar1;
  __Event *p_Var2;
  int CurrentSection_00;
  undefined *puVar3;
  _Instance *p_Var4;
  int NewAnim;
  int in_a3;
  int local_2c;
  int *piVar5;
  _Instance **pp_Var6;
  __MessageQueue *In_00;
  __State *p_Var7;

  iVar1 = G2EmulationQueryAnimation(In, CurrentSection);
  p_Var7 = In->SectionList + CurrentSection;
  In_00 = &p_Var7->Event;
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var2 = PeekMessageQueue(In_00);
    if (p_Var2 == (__Event *)0x0)
    {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if ((int)puVar3 < 0x1000002)
    {
      if ((int)puVar3 < 0x1000000)
      {
        if (puVar3 == (undefined *)0x100000)
        {
          if ((*gameTracker._4_4_ & 0x8000000f) == 0)
          {
            /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0, 0, 3, in_a3);
          }
          in_a3 = 10;
          StateSwitchStateData(In, CurrentSection, StateHandlerStartMove, 10);
          pp_Var6[0x47] = (_Instance *)0x0;
        }
        else
        {
          if ((int)puVar3 < 0x100001)
          {
            if (puVar3 != &DAT_80000008)
            {
              if ((int)puVar3 < -0x7ffffff7)
              {
                if (puVar3 != (undefined *)0x80000000)
                  goto LAB_800ada7c;
              }
              else
              {
                if (puVar3 != &DAT_80000020)
                  goto LAB_800ada7c;
              }
            }
          }
          else
          {
            if (puVar3 == &DAT_00100004)
            {
              if (CurrentSection == 0)
              {
                _CHAR____800d5604 = 0;
                _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff;
                In->CharacterInstance->attachedID = 0;
              }
              In->CharacterInstance->flags2 = In->CharacterInstance->flags2 | 0x40;
            }
            else
            {
              if ((int)puVar3 < 0x100005)
              {
                if (puVar3 != &DAT_00100001)
                  goto LAB_800ada7c;
                piVar5 = (int *)p_Var2->Data;
                if (CurrentSection == 0)
                {
                  if ((_CHAR____800d5574 & 0x40000) != 0)
                  {
                    CAMERA_ChangeToOutOfWater((Camera *)&theCamera, In->CharacterInstance);
                  }
                  p_Var4 = In->CharacterInstance;
                  In->SectionList[0].Data2 = In->CharacterInstance->attachedID;
                  _BlockVramEntry_800d59a0._12_4_ = 0x8001501;
                  if (p_Var4->attachedID == 0)
                  {
                    _BlockVramEntry_800d59a0._12_4_ = 0xc001501;
                  }
                  In->CharacterInstance->attachedID = 0;
                  _CHAR____800d5574 = 0x100;
                  if (*piVar5 != 0)
                  {
                    _CHAR____800d5604 = *piVar5;
                  }
                  SteerSwitchMode(In->CharacterInstance, 0);
                }
                if (_CHAR____800d5584 < 0)
                {
                  CurrentSection_00 = piVar5[2];
                  local_2c = 4;
                }
                else
                {
                  CurrentSection_00 = piVar5[2];
                  local_2c = 0;
                }
                G2EmulationSwitchAnimation(In, CurrentSection, 7, local_2c, CurrentSection_00, 1);
                pp_Var6[0x47] = (_Instance *)0x0;
                PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
                in_a3 = 0;
                SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
                In->CharacterInstance->flags2 = In->CharacterInstance->flags2 & 0xffffffbf;
              }
              else
              {
                if (puVar3 != &DAT_00100014)
                  goto LAB_800ada7c;
              LAB_800ada10:
                if (CurrentSection == 1)
                {
                  SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
                  in_a3 = 0;
                  CurrentSection_00 =
                      razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x18, (int *)0x0, (int *)0x0);
                  if (CurrentSection_00 != 0)
                  {
                    in_a3 = 4;
                    G2EmulationSwitchAnimationCharacter(In, 0x24, 0, 4, 1);
                  }
                  StateSwitchStateCharacterData(In, StateHandlerFall, 0);
                }
              }
            }
          }
        }
      }
    }
    else
    {
      if (puVar3 != (undefined *)0x4010200)
      {
        if ((int)puVar3 < 0x4010201)
        {
          if (puVar3 != (undefined *)0x4000011)
          {
            if ((int)puVar3 < 0x4000012)
            {
              if (puVar3 != (undefined *)0x4000001)
              {
              LAB_800ada7c:
                DefaultStateHandler(In, CurrentSection, Data);
              }
            }
            else
            {
              if (puVar3 != (undefined *)0x4010010)
                goto LAB_800ada7c;
            }
          }
        }
        else
        {
          if (puVar3 == (undefined *)0x8000001)
          {
            if (pp_Var6[0x47] == (_Instance *)0x1)
            {
              /* WARNING: Subroutine does not return */
              EnMessageQueueData(In_00, 0x100000, 0);
            }
          }
          else
          {
            if ((int)puVar3 < 0x8000002)
            {
              if (puVar3 != (undefined *)0x8000000)
                goto LAB_800ada7c;
              if (pp_Var6[0x47] == (_Instance *)0x1)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(In_00, 0x100000, 0);
              }
              if (CurrentSection == 2)
              {
                NewAnim = 0;
                CurrentSection_00 = 2;
                local_2c = CurrentSection;
              }
              else
              {
                NewAnim = 6;
                local_2c = 0;
                CurrentSection_00 = CurrentSection;
              }
              in_a3 = 0;
              G2EmulationSwitchAnimation(In, CurrentSection_00, NewAnim, 0, 3, local_2c);
              if (CurrentSection == 0)
              {
                _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff;
              }
            }
            else
            {
              if (puVar3 == (undefined *)0x8000003)
              {
                if ((CurrentSection == 0) &&
                    (_BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff,
                     In->SectionList[0].Data2 != 0))
                {
                  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x4000000;
                }
              }
              else
              {
                if (puVar3 != (undefined *)0x10000000)
                  goto LAB_800ada7c;
                CurrentSection_00 = p_Var2->Data;
                if (CurrentSection_00 == 0x10000003)
                {
                  if (iVar1 == 6)
                    goto LAB_800ada10;
                  CurrentSection_00 = p_Var2->Data;
                }
                if ((CurrentSection_00 == 0x10000001) || ((*gameTracker._4_4_ & 1) != 0))
                {
                  if (pp_Var6[0x47] == (_Instance *)0x0)
                  {
                    in_a3 = 0;
                    G2EmulationSwitchAnimation(In, CurrentSection, 8, 0, 2, 1);
                    PurgeMessageQueue(&p_Var7->Event);
                  }
                  pp_Var6[0x47] = (_Instance *)0x1;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var7->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerPushObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
// line 3247, offset 0x800adac4
/* begin block 1 */
// Start line: 3248
// Start offset: 0x800ADAC4
// Variables:
// 		struct __Event *Ptr; // $v0

/* begin block 1.1 */
// Start line: 3300
// Start offset: 0x800ADD58
// Variables:
// 		struct evObjectData *data; // $s0
/* end block 1.1 */
// End offset: 0x800ADDB0
// End Line: 3309
/* end block 1 */
// End offset: 0x800ADDCC
// End Line: 3319

/* begin block 2 */
// Start line: 6879
/* end block 2 */
// End Line: 6880

/* begin block 3 */
// Start line: 6882
/* end block 3 */
// End Line: 6883

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerPushObject(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int CurrentSection_00;
  undefined *puVar2;
  int NewAnim;
  int in_a3;
  int local_24;

  if ((_CHAR____800d55f0 & 3) == 0)
  {
    /* WARNING: Subroutine does not return */
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer, 0x100000, 0);
  }
  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      if (CurrentSection == 0)
      {
        _CHAR____800d5574 = 0x400;
        _BlockVramEntry_800d59a0._12_4_ = 0x8001108;
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        SteerSwitchMode(In->CharacterInstance, 0);
        razCenterWithBlock(In->CharacterInstance, *_CHAR____800d55ec, -0x8d);
      }
      In->SectionList[CurrentSection].Data1 = 0;
      razSetPlayerEventHistory(1);
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if (puVar2 == &DAT_80000008)
          goto LAB_800addbc;
        if (puVar2 == (undefined *)0x100000)
        {
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, 6, in_a3);
        }
      }
      else
      {
        if (0x7ffffff < (int)puVar2)
        {
          if ((int)puVar2 < 0x8000002)
          {
            if (((*gameTracker._4_4_ & LONG_800cf568) == 0) || ((_CHAR____800d55f0 & 2) == 0))
            {
              if (In->SectionList[CurrentSection].Data1 != 0)
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
              if (CurrentSection == 2)
              {
                NewAnim = 0;
                CurrentSection_00 = 2;
                local_24 = CurrentSection;
              }
              else
              {
                NewAnim = 0x17;
                local_24 = 1;
                CurrentSection_00 = CurrentSection;
              }
              in_a3 = 0;
              G2EmulationSwitchAnimation(In, CurrentSection_00, NewAnim, 0, 3, local_24);
              In->SectionList[CurrentSection].Data1 = 1;
              if (CurrentSection == 0)
              {
                _CHAR____800d5774 = 400;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5774;
              }
            }
            else
            {
              in_a3 = 0;
              StateSwitchStateData(In, CurrentSection, StateHandlerDragObject, 0);
            }
            goto LAB_800addbc;
          }
          if (puVar2 == (undefined *)0x8000004)
          {
            CurrentSection_00 =
                SetObjectData(-(int)_CHAR____800d55b4, -(int)_CHAR____800d55b6, 6, (_Instance *)0x0, 0);
            /* WARNING: Subroutine does not return */
            INSTANCE_Post(*_CHAR____800d55ec, 0x800000, CurrentSection_00);
          }
        }
      }
      DefaultStateHandler(In, CurrentSection, Data);
    }
  LAB_800addbc:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerBreakOff(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s4*/, int Data /*$s7*/)
// line 3322, offset 0x800addf0
/* begin block 1 */
// Start line: 3323
// Start offset: 0x800ADDF0
// Variables:
// 		struct __Event *Ptr; // $v0

/* begin block 1.1 */
// Start line: 3334
// Start offset: 0x800ADEF4
// Variables:
// 		struct PhysObInteractProperties *interactProp; // $s0
// 		struct _Instance *Inst; // $s1
// 		int anim; // $a2
/* end block 1.1 */
// End offset: 0x800AE07C
// End Line: 3383

/* begin block 1.2 */
// Start line: 3397
// Start offset: 0x800AE0D4
// Variables:
// 		struct PhysObInteractProperties *interactProp; // $v0
// 		int action; // $s1
// 		int condition; // $v0
// 		struct _Instance *Inst; // $s0
/* end block 1.2 */
// End offset: 0x800AE17C
// End Line: 3428
/* end block 1 */
// End offset: 0x800AE1C8
// End Line: 3443

/* begin block 2 */
// Start line: 7040
/* end block 2 */
// End Line: 7041

void StateHandlerBreakOff(__CharacterState *param_1, int param_2, int param_3, int param_4)

{
  __Event *p_Var1;
  undefined *puVar2;
  _Instance *Inst;

  uGpffffb63c = uGpffffb63c | 4;
  do
  {
    p_Var1 = PeekMessageQueue(&param_1->SectionList[param_2].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100015)
    {
      if (param_2 == 0)
      {
        /* WARNING: Subroutine does not return */
        SetPhysicsWallCrawlData(0, 0, 3, param_4);
      }
    }
    else
    {
      if (0x100015 < (int)puVar2)
      {
        if (0x7ffffff < (int)puVar2)
        {
          if ((int)puVar2 < 0x8000002)
          {
            /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0, 0, 3, param_4);
          }
          if (puVar2 == (undefined *)0x8000004)
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Query((_Instance *)param_1->SectionList[param_2].Data2, 0x15);
          }
        }
        goto LAB_800ae1b0;
      }
      if (puVar2 == &DAT_00100001)
      {
        if (param_2 == 0)
        {
          if ((uGpfffffb3c & 0x10) == 0)
          {
            Inst = *(_Instance **)(iGpfffffb38 + 0x68);
          }
          else
          {
            Inst = *(_Instance **)(iGpfffffb38 + 0x20);
          }
          /* WARNING: Subroutine does not return */
          INSTANCE_Query(Inst, 0x15);
        }
      }
      else
      {
        if ((int)puVar2 < 0x100002)
        {
          if (puVar2 != (undefined *)0x80000000)
          {
          LAB_800ae1b0:
            DefaultStateHandler(param_1, param_2, param_3);
          }
        }
        else
        {
          if (puVar2 != &DAT_00100004)
            goto LAB_800ae1b0;
        }
      }
    }
    DeMessageQueue(&param_1->SectionList[param_2].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerPullSwitch(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
// line 3446, offset 0x800ae1f4
/* begin block 1 */
// Start line: 3447
// Start offset: 0x800AE1F4
// Variables:
// 		struct __Event *Ptr; // $s2
// 		int switchDone; // stack offset -56
// 		int hitPosted; // stack offset -52

/* begin block 1.1 */
// Start line: 3459
// Start offset: 0x800AE32C
// Variables:
// 		struct PhysObSwitchProperties *switchData; // $fp

/* begin block 1.1.1 */
// Start line: 3465
// Start offset: 0x800AE35C
// Variables:
// 		int switchStatus; // $s1
// 		int switchSuccess; // $s3
// 		struct _Instance *inst; // $s2
// 		struct PhysObSwitchProperties *switchProperties; // $s0
// 		int extraZ; // $s6

/* begin block 1.1.1.1 */
// Start line: 3478
// Start offset: 0x800AE3B0
/* end block 1.1.1.1 */
// End offset: 0x800AE408
// End Line: 3490
/* end block 1.1.1 */
// End offset: 0x800AE534
// End Line: 3539
/* end block 1.1 */
// End offset: 0x800AE534
// End Line: 3539

/* begin block 1.2 */
// Start line: 3545
// Start offset: 0x800AE544
// Variables:
// 		int switchStatus; // $v1
// 		struct _Instance *inst; // $s0
// 		struct PhysObSwitchProperties *switchProperties; // $s0
// 		int switchClass; // $s1
/* end block 1.2 */
// End offset: 0x800AE6C8
// End Line: 3586

/* begin block 1.3 */
// Start line: 3598
// Start offset: 0x800AE740
// Variables:
// 		struct evMonsterHitData *data; // $s0
/* end block 1.3 */
// End offset: 0x800AE7A8
// End Line: 3609
/* end block 1 */
// End offset: 0x800AE7D4
// End Line: 3629

/* begin block 2 */
// Start line: 7314
/* end block 2 */
// End Line: 7315

/* WARNING: Removing unreachable block (ram,0x800ae750) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerPullSwitch(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  int in_a3;
  _Instance *p_Var3;
  __State *p_Var4;

  G2EmulationQueryAnimation(In, CurrentSection);
  p_Var4 = In->SectionList + CurrentSection;
  do
  {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0)
    {
      if (CurrentSection == 0)
      {
        razApplyMotion(In, 0);
      }
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x18), 4);
    }
    if ((int)puVar2 < 0x100001)
    {
      if (puVar2 != &DAT_80000008)
      {
        if ((int)puVar2 < -0x7ffffff7)
        {
          if (puVar2 != (undefined *)0x80000000)
          {
          LAB_800ae7a8:
            DefaultStateHandler(In, CurrentSection, Data);
          }
        }
        else
        {
          if ((puVar2 != &DAT_80000010) && (puVar2 != &DAT_80000020))
            goto LAB_800ae7a8;
        }
      }
    }
    else
    {
      if (puVar2 == (undefined *)0x1000000)
      {
        p_Var3 = (_Instance *)p_Var1->Data;
        Data_00 = SetMonsterHitData(*(_Instance **)&p_Var3->node,
                                    *(_Instance **)((int)&p_Var3->node + 4), (int)p_Var3->prev,
                                    (int)*(short *)&p_Var3->next,
                                    (int)*(short *)((int)&p_Var3->next + 2));
        /* WARNING: Subroutine does not return */
        EnMessageQueueData(&p_Var4->Defer, 0x1000000, Data_00);
      }
      if ((int)puVar2 < 0x1000001)
      {
        if (puVar2 != &DAT_00100001)
        {
          if (puVar2 == &DAT_00100015)
          {
            /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0, 0, 3, in_a3);
          }
          goto LAB_800ae7a8;
        }
        if (CurrentSection == 0)
        {
          _BlockVramEntry_800d59a0._12_4_ = 0x9041108;
          PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
          SteerSwitchMode(In->CharacterInstance, 0);
          if ((_CHAR____800d55f0 & 8) != 0)
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x18), 0x17);
          }
        }
      }
      else
      {
        if (puVar2 != (undefined *)0x1000001)
        {
          if (puVar2 != (undefined *)0x8000000)
            goto LAB_800ae7a8;
          if (CurrentSection != 2)
          {
            /* WARNING: Subroutine does not return */
            EnMessageQueueData(&p_Var4->Defer, 0x100000, 0);
          }
          in_a3 = 0;
          G2EmulationSwitchAnimation(In, 2, 0, 0, 3, 2);
        }
      }
    }
    DeMessageQueue(&p_Var4->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerDragObject(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$fp*/)
// line 3632, offset 0x800ae804
/* begin block 1 */
// Start line: 3633
// Start offset: 0x800AE804
// Variables:
// 		struct __Event *Ptr; // $s1
// 		struct _Instance *instance; // $s3
// 		int anim; // $s0
// 		int hitPosted; // $s7

/* begin block 1.1 */
// Start line: 3676
// Start offset: 0x800AEA10
// Variables:
// 		struct evPhysicsSlideData *slideData; // stack offset -48

/* begin block 1.1.1 */
// Start line: 3681
// Start offset: 0x800AEA2C
// Variables:
// 		struct evObjectData *data; // $s0
/* end block 1.1.1 */
// End offset: 0x800AED18
// End Line: 3738
/* end block 1.1 */
// End offset: 0x800AED18
// End Line: 3739

/* begin block 1.2 */
// Start line: 3795
// Start offset: 0x800AEEA0
// Variables:
// 		struct evMonsterHitData *data; // $v0
/* end block 1.2 */
// End offset: 0x800AEEA0
// End Line: 3796
/* end block 1 */
// End offset: 0x800AEEFC
// End Line: 3810

/* begin block 2 */
// Start line: 7694
/* end block 2 */
// End Line: 7695

/* begin block 3 */
// Start line: 7700
/* end block 3 */
// End Line: 7701

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerDragObject(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  int CurrentSection_00;
  uint uVar2;
  undefined *puVar3;
  int NewAnim;
  evPhysicsSlideData **in_a3;
  _Instance *Inst;
  __State *p_Var4;
  int local_38;
  int local_34;
  evPhysicsSlideData *apeStack48[2];

  if ((_CHAR____800d55f0 & 2) == 0)
  {
    /* WARNING: Subroutine does not return */
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer, 0x100000, 0);
  }
  Inst = *(_Instance **)(_CHAR____800d55ec + 8);
  if (Inst->introUniqueID == In->CharacterInstance->attachedID)
  {
    In->CharacterInstance->attachedID = 0;
  }
  p_Var4 = In->SectionList + CurrentSection;
  do
  {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    CurrentSection_00 = G2EmulationQueryAnimation(In, CurrentSection);
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == (undefined *)0x100000)
    {
    LAB_800aee44:
      /* WARNING: Subroutine does not return */
      SetPhysicsWallCrawlData(0, 0, 3, (int)in_a3);
    }
    if ((int)puVar3 < 0x100001)
    {
      if (puVar3 != &DAT_80000008)
      {
        if ((int)puVar3 < -0x7ffffff7)
        {
          if (-0x7fffffff < (int)puVar3)
          {
          LAB_800aeee4:
            DefaultStateHandler(In, CurrentSection, Data);
          }
        }
        else
        {
          if ((puVar3 != &DAT_80000010) && (puVar3 != &DAT_80000020))
            goto LAB_800aeee4;
        }
      }
    }
    else
    {
      if (puVar3 == (undefined *)0x8000000)
      {
        if (CurrentSection_00 == 0x17)
        {
          /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0, 0, 3, (int)in_a3);
        }
        if (Inst == (_Instance *)0x0)
          goto LAB_800aee44;
        if (CurrentSection == 0)
        {
          /* WARNING: Subroutine does not return */
          INSTANCE_Post(Inst, 0x800004, 0);
        }
        if (CurrentSection == 2)
        {
          NewAnim = 0;
          local_38 = 3;
          CurrentSection_00 = 2;
          local_34 = CurrentSection;
        }
        else
        {
          NewAnim = 0x16;
          local_38 = 2;
          local_34 = 2;
          CurrentSection_00 = CurrentSection;
        }
        in_a3 = (evPhysicsSlideData **)0x0;
        G2EmulationSwitchAnimation(In, CurrentSection_00, NewAnim, 0, local_38, local_34);
      LAB_800aee10:
        if ((*gameTracker._4_4_ & LONG_800cf568) == 0)
        {
          /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var4->Event, 0x100000, 0);
        }
      }
      else
      {
        if ((int)puVar3 < 0x8000001)
        {
          if (puVar3 == &DAT_00100001)
          {
            if (CurrentSection == 0)
            {
              _CHAR____800d5574 = 0x400;
              _BlockVramEntry_800d59a0._12_4_ = 0x9001508;
              PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
              SteerSwitchMode(In->CharacterInstance, 0);
            }
            in_a3 = (evPhysicsSlideData **)0x0;
            G2EmulationSwitchAnimation(In, CurrentSection, 0x14, 0, 3, 1);
          }
          else
          {
            if (puVar3 != (undefined *)0x1000000)
              goto LAB_800aeee4;
            if (CurrentSection == 0)
            {
              if (CurrentSection_00 != 0x16)
              {
                Inst = (_Instance *)p_Var1->Data;
                CurrentSection_00 =
                    SetMonsterHitData(*(_Instance **)&Inst->node,
                                      *(_Instance **)((int)&Inst->node + 4), (int)Inst->prev,
                                      (int)*(short *)&Inst->next,
                                      (int)*(short *)((int)&Inst->next + 2));
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer, 0x1000000, CurrentSection_00);
              }
              StateSwitchStateCharacterData(In, StateHandlerHitReaction, p_Var1->Data);
            }
          }
        }
        else
        {
          if (puVar3 == (undefined *)0x10000000)
          {
            if (CurrentSection == 0)
            {
              DAT_800d11c5 = 1;
              if (((CurrentSection_00 == 0) || (CurrentSection_00 == 0x16)) &&
                  (Inst != (_Instance *)0x0))
              {
                CurrentSection_00 = p_Var1->Data;
                if (CurrentSection_00 == 0x10000002)
                {
                  in_a3 = apeStack48;
                  uVar2 = PHYSOB_CheckSlideNormal(In->CharacterInstance, -(int)_CHAR____800d55b6,
                                                  (int)_CHAR____800d55b4, in_a3);
                  if ((uVar2 & 0x4002) == 0x4000)
                  {
                    CurrentSection_00 =
                        SetObjectData(-(int)_CHAR____800d55b6, (int)_CHAR____800d55b4, 2,
                                      (_Instance *)0x0, 0);
                    /* WARNING: Subroutine does not return */
                    INSTANCE_Post(Inst, 0x800000, CurrentSection_00);
                  }
                }
                else
                {
                  if (CurrentSection_00 < 0x10000003)
                  {
                    if (CurrentSection_00 == 0x10000001)
                    {
                      DAT_800d11c5 = 0;
                      CurrentSection_00 =
                          SetObjectData(-(int)_CHAR____800d55b4, -(int)_CHAR____800d55b6, 5,
                                        (_Instance *)0x0, 0);
                      /* WARNING: Subroutine does not return */
                      INSTANCE_Post(Inst, 0x800000, CurrentSection_00);
                    }
                  }
                  else
                  {
                    if (CurrentSection_00 == 0x10000003)
                    {
                      in_a3 = apeStack48;
                      uVar2 = PHYSOB_CheckSlideNormal(In->CharacterInstance, (int)_CHAR____800d55b4,
                                                      (int)_CHAR____800d55b6, in_a3);
                      if ((uVar2 & 0x4002) == 0x4000)
                      {
                        CurrentSection_00 =
                            SetObjectData((int)_CHAR____800d55b4, (int)_CHAR____800d55b6, 4,
                                          (_Instance *)0x0, 0);
                        /* WARNING: Subroutine does not return */
                        INSTANCE_Post(Inst, 0x800000, CurrentSection_00);
                      }
                    }
                    else
                    {
                      in_a3 = apeStack48;
                      if ((CurrentSection_00 == 0x10000004) &&
                          (uVar2 = PHYSOB_CheckSlideNormal(In->CharacterInstance, (int)_CHAR____800d55b6,
                                                           -(int)_CHAR____800d55b4, in_a3),
                           (uVar2 & 0x4002) == 0x4000))
                      {
                        CurrentSection_00 =
                            SetObjectData((int)_CHAR____800d55b6, -(int)_CHAR____800d55b4, 3,
                                          (_Instance *)0x0, 0);
                        /* WARNING: Subroutine does not return */
                        INSTANCE_Post(Inst, 0x800000, CurrentSection_00);
                      }
                    }
                  }
                }
              }
              DAT_800d11c5 = 0;
            }
          }
          else
          {
            if ((int)puVar3 < 0x10000001)
            {
              if (puVar3 != (undefined *)0x8000001)
                goto LAB_800aeee4;
              if (((CurrentSection_00 == 0) || (CurrentSection_00 == 0x16)) ||
                  (CurrentSection_00 == 0x14))
                goto LAB_800aee10;
            }
            else
            {
              if (puVar3 != (undefined *)0x20000000)
                goto LAB_800aeee4;
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var4->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerPickupObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
// line 3813, offset 0x800aef2c
/* begin block 1 */
// Start line: 3814
// Start offset: 0x800AEF2C
// Variables:
// 		struct __Event *Ptr; // $v0

/* begin block 1.1 */
// Start line: 3822
// Start offset: 0x800AEFE4
// Variables:
// 		long colorArray[1]; // stack offset -32
/* end block 1.1 */
// End offset: 0x800AEFE4
// End Line: 3822
/* end block 1 */
// End offset: 0x800AF128
// End Line: 3870

/* begin block 2 */
// Start line: 8073
/* end block 2 */
// End Line: 8074

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerPickupObject(__CharacterState *In, int CurrentSection, int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess;
  int in_a3;
  long local_20[2];

  do
  {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0)
    {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      if (CurrentSection == 1)
      {
        local_20[0] = 0xff5400;
        _BlockVramEntry_800d59a0._12_4_ = &DAT_00001108;
        _CHAR____800d5574 = _CHAR____800d5574 | 0x800;
        _CHAR____800d55b0 = _CHAR____800d55b0 | 0x80;
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        in_a3 = 1;
        FX_DoInstanceOneSegmentGlowWithTime(In->CharacterInstance, 0x29, local_20, 1, 0, 0x4b, 0x4b, 10);
        razSetPlayerEventHistory(0x10);
      }
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if ((puVar2 != (undefined *)0x80000000) && (puVar2 != &DAT_80000020))
        {
        LAB_800af110:
          DefaultStateHandler(In, CurrentSection, Data);
        }
      }
      else
      {
        if (puVar2 == &DAT_00100004)
        {
          if (CurrentSection == 1)
          {
            _BlockVramEntry_800d59a0._12_4_ =
                (undefined *)((uint)_BlockVramEntry_800d59a0._12_4_ & 0xffffefff);
            FX_StopAllGlowEffects(In->CharacterInstance, 0);
          }
        }
        else
        {
          if (puVar2 != (undefined *)0x8000000)
            goto LAB_800af110;
          if (CurrentSection == 1)
          {
            FX_StopAllGlowEffects(In->CharacterInstance, 0);
          }
          if ((_CHAR____800d5574 & 0x40000) == 0)
          {
            if ((_CHAR____800d571c == StateHandlerIdle) ||
                (NewProcess = _CHAR____800d571c,
                 _CHAR____800d571c == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0))
            {
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0, 0, 3, in_a3);
            }
          }
          else
          {
            NewProcess = StateHandlerSwim;
          }
          in_a3 = 0;
          StateSwitchStateData(In, CurrentSection, NewProcess, 0);
          _CHAR____800d571c = (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0;
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerAutoFace(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*stack 8*/)
// line 3870, offset 0x800af148
/* begin block 1 */
// Start line: 3871
// Start offset: 0x800AF148
// Variables:
// 		struct __Event *Ptr; // $a0
// 		int Frames; // $s3
// 		int Anim; // $s2
/* end block 1 */
// End offset: 0x800AF858
// End Line: 4077

/* begin block 2 */
// Start line: 8216
/* end block 2 */
// End Line: 8217

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerAutoFace(__CharacterState *In, int CurrentSection, int Data)

{
  int iVar1;
  __Event *p_Var2;
  int local_30;
  undefined *puVar3;
  uint uVar4;
  int NewAnim;
  code *NewProcess;
  int in_a3;
  int iVar5;
  _Instance **pp_Var6;

  iVar1 = G2EmulationQueryAnimation(In, CurrentSection);
  iVar5 = 4;
  if (CurrentSection == 2)
  {
    iVar5 = 6;
  }
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0)
    {
      if ((_CHAR____800d5758 != 6) && ((_CHAR____800d55f0 & 0x40) != 0))
      {
        return;
      }
      /* WARNING: Subroutine does not return */
      EnMessageQueueData(&In->SectionList[CurrentSection].Event, 0x100000, 0);
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100004)
    {
      if (CurrentSection == 0)
      {
      LAB_800af3d0:
        razResetPauseTranslation(In->CharacterInstance);
      }
    }
    else
    {
      local_30 = CurrentSection;
      if ((int)puVar3 < 0x100005)
      {
        if (puVar3 == &DAT_80000002)
        {
          if (_CHAR____800d5600 != 3)
          {
            _CHAR____800d571c = StateHandlerIdle;
            NewProcess = StateHandlerSoulSuck;
            goto LAB_800af7b0;
          }
        }
        else
        {
          if ((int)puVar3 < -0x7ffffffd)
          {
            if (puVar3 == (undefined *)0x80000000)
            {
              if ((CurrentSection == 0) && ((_CHAR____800d55b0 & 0x80) == 0))
              {
                StateSwitchStateCharacterData(In, StateHandlerAttack2, 0);
              }
            }
            else
            {
              if (puVar3 != (undefined *)0x80000001)
                goto LAB_800af7f0;
            }
          }
          else
          {
            if (puVar3 == (undefined *)0x100000)
            {
            LAB_800af71c:
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0, 0, 3, in_a3);
            }
            if ((int)puVar3 < 0x100001)
            {
              if (puVar3 == (undefined *)0x0)
              {
                if (2 < iVar1 - 0x5bU)
                {
                  if (5 < _CHAR____800d5758)
                    goto LAB_800af71c;
                  if (iVar1 != 0x37)
                  {
                    /* WARNING: Subroutine does not return */
                    SetPhysicsWallCrawlData(1, 0, 6, in_a3);
                  }
                }
              }
              else
              {
              LAB_800af7f0:
                DefaultStateHandler(In, CurrentSection, Data);
              }
            }
            else
            {
              if (puVar3 != &DAT_00100001)
                goto LAB_800af7f0;
              _BlockVramEntry_800d59a0._12_4_ = &LAB_00012108_3;
              if ((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) == 0)
              {
                uVar4 = 0x2000001;
              }
              else
              {
                uVar4 = 0x2000002;
              }
              _CHAR____800d5574 = _CHAR____800d5574 | uVar4;
              PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
              if (CurrentSection == 0)
              {
                SteerSwitchMode(In->CharacterInstance, 5);
              }
              pp_Var6[0x47] = (_Instance *)0x0;
              in_a3 = -1;
              local_30 = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x54, -1, -1);
              if (local_30 != 0)
              {
                in_a3 = 0;
                G2EmulationSwitchAnimation(In, CurrentSection, 0x37, 0, 6, 2);
              }
              razSetPlayerEventHistory(0x20);
            }
          }
        }
      }
      else
      {
        if (puVar3 == (undefined *)0x8000000)
        {
          if (CurrentSection == 0)
          {
            SteerSwitchMode(In->CharacterInstance, 5);
          }
          NewAnim = 0x37;
          pp_Var6[0x47] = (_Instance *)0x0;
          local_30 = 6;
          goto LAB_800af70c;
        }
        if ((int)puVar3 < 0x8000001)
        {
          if (puVar3 == (undefined *)0x2000000)
          {
            NewAnim = razPickupAndGrab(In, CurrentSection);
            if (NewAnim != 0)
            {
              NewProcess = StateHandlerAttack2;
            LAB_800af7b0:
              in_a3 = 0;
              StateSwitchStateData(In, local_30, NewProcess, 0);
            }
          }
          else
          {
            if ((int)puVar3 < 0x2000001)
            {
              if (puVar3 != (undefined *)0x1000001)
                goto LAB_800af7f0;
              if ((CurrentSection == 1) && (In->CharacterInstance->LinkChild != (_Instance *)0x0))
              {
                p_Var2->Data = 0;
              }
              NewAnim = p_Var2->Data;
              local_30 = iVar5;
              if (NewAnim == 0x10001002)
              {
                if ((iVar1 != 0xf) && (iVar1 != 0x5d))
                {
                  NewAnim = 0xf;
                  goto LAB_800af70c;
                }
                if (((gameTracker._4_4_[1] & LONG_800cf56c) != 0) && (iVar1 != 0x5d))
                {
                  SteerSwitchMode(In->CharacterInstance, 0xe);
                  local_30 = 0x5d;
                  goto LAB_800af620;
                }
              }
              else
              {
                if (NewAnim < 0x10001003)
                {
                  if (NewAnim == 0x10001001)
                  {
                    if (iVar1 != 0xc)
                    {
                      NewAnim = 0xc;
                      goto LAB_800af70c;
                    }
                    if (((gameTracker._4_4_[1] & LONG_800cf56c) != 0) &&
                        ((_CHAR____800d55b0 & 0x80) == 0))
                    {
                      in_a3 = 5;
                      StateSwitchStateData(In, CurrentSection, StateHandlerAttack2, 5);
                      if (CurrentSection == 2)
                      {
                        in_a3 = 5;
                        StateSwitchStateData(In, 1, StateHandlerAttack2, 5);
                      }
                    }
                  }
                }
                else
                {
                  if (NewAnim == 0x10001003)
                  {
                    if ((iVar1 == 0xd) || (iVar1 == 0x5b))
                    {
                      if (((gameTracker._4_4_[1] & LONG_800cf56c) != 0) && (iVar1 != 0x5b))
                      {
                        SteerSwitchMode(In->CharacterInstance, 0xe);
                        local_30 = 0x5b;
                      LAB_800af620:
                        in_a3 = 0;
                        G2EmulationSwitchAnimation(In, CurrentSection, local_30, 0, 0, 1);
                      }
                    }
                    else
                    {
                      NewAnim = 0xd;
                    LAB_800af70c:
                      in_a3 = 0;
                      G2EmulationSwitchAnimation(In, CurrentSection, NewAnim, 0, local_30, 2);
                    }
                  }
                  else
                  {
                    if (NewAnim == 0x10001004)
                    {
                      if ((iVar1 != 0xe) && (iVar1 != 0x5c))
                      {
                        NewAnim = 0xe;
                        goto LAB_800af70c;
                      }
                      if (((gameTracker._4_4_[1] & LONG_800cf56c) != 0) && (iVar1 != 0x5c))
                      {
                        SteerSwitchMode(In->CharacterInstance, 0xe);
                        local_30 = 0x5c;
                        goto LAB_800af620;
                      }
                    }
                  }
                }
              }
            }
            else
            {
              if (puVar3 != (undefined *)0x4010080)
                goto LAB_800af7f0;
              if (CurrentSection == 0)
              {
                if (p_Var2->Data != 0)
                  goto LAB_800af3d0;
                razSetPauseTranslation(In->CharacterInstance);
              }
            }
          }
        }
        else
        {
          if (puVar3 == (undefined *)0x10000000)
          {
            if (((uint)_BlockVramEntry_800d59a0._12_4_ & 2) == 0)
            {
              if (CurrentSection != 0)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Event, (int)&DAT_00100005, CurrentSection);
              }
              local_30 = 0;
              NewProcess = StateHandlerStartMove;
              goto LAB_800af7b0;
            }
          }
          else
          {
            if ((int)puVar3 < 0x10000001)
            {
              if (puVar3 != (undefined *)0x8000003)
                goto LAB_800af7f0;
              if (iVar1 == 0x37)
              {
                pp_Var6[0x47] = (_Instance *)0x1;
              }
            }
            else
            {
              if (puVar3 != (undefined *)0x20000004)
                goto LAB_800af7f0;
              if (CurrentSection == 0)
              {
                _CHAR____800d55e4 = *(undefined4 *)(_CHAR____800d55ec + 0x30);
              }
            }
          }
        }
      }
    }
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ StateHandlerGlyphs(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
// line 4083, offset 0x800af888
/* begin block 1 */
// Start line: 4084
// Start offset: 0x800AF888
// Variables:
// 		struct __Event *Ptr; // $s0
// 		int hitPosted; // $s5

/* begin block 1.1 */
// Start line: 4285
// Start offset: 0x800B0018
// Variables:
// 		struct evActionPlayHostAnimationData *ptr; // $v0
/* end block 1.1 */
// End offset: 0x800B005C
// End Line: 4292

/* begin block 1.2 */
// Start line: 4295
// Start offset: 0x800B005C
// Variables:
// 		struct evMonsterHitData *data; // $v1
/* end block 1.2 */
// End offset: 0x800B00B0
// End Line: 4304
/* end block 1 */
// End offset: 0x800B00E0
// End Line: 4333

/* begin block 2 */
// Start line: 8645
/* end block 2 */
// End Line: 8646

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerGlyphs(__CharacterState *In, int CurrentSection, int Data)

{
  undefined *puVar1;
  __Event *p_Var2;
  int Data_00;
  undefined *puVar3;
  _Instance *p_Var4;
  int ID;
  code *pcVar5;
  int in_a3;
  _Instance **pp_Var6;
  __State *p_Var7;
  int local_38;
  int local_34;

  pcVar5 = (code *)Data;
  G2EmulationQueryAnimation(In, CurrentSection);
  _CHAR____800d5618 = 0x3000;
  p_Var7 = In->SectionList + CurrentSection;
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do
  {
    p_Var2 = PeekMessageQueue(&p_Var7->Event);
    if (p_Var2 == (__Event *)0x0)
    {
      In->CharacterInstance->cachedTFace = -1;
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x80007)
    {
      if (pp_Var6[0x47] != (_Instance *)0x0)
      {
        if (CurrentSection == 0)
        {
          razPrepGlyph();
          razSwitchStringAnimation(In->CharacterInstance, 0);
        }
        pp_Var6[0x47] = (_Instance *)0x0;
        if (CurrentSection == 0)
        {
          razPlaneShift(In->CharacterInstance);
          if ((_CHAR____800d5574 & 0x40000) != 0)
          {
            CAMERA_ChangeToOutOfWater((Camera *)&theCamera, In->CharacterInstance);
            SteerSwitchMode(In->CharacterInstance, 6);
          }
          SteerSwitchMode(In->CharacterInstance, 0);
          if ((_CHAR____800d57c4 & 0x2000) != 0)
          {
            razSetPlayerEventHistory(0x2000);
            HINT_KillSpecificHint(0x28);
          }
        }
        _CHAR____800d5618 = 0x1e000;
      }
    }
    else
    {
      if ((int)puVar3 < 0x80008)
      {
        if (puVar3 == &UNK_00040025)
        {
        LAB_800b00b0:
          /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var7->Defer, p_Var2->ID, p_Var2->Data);
        }
        if ((int)puVar3 < 0x40026)
        {
          if (puVar3 == &DAT_80000010)
          {
            if (pp_Var6[0x47] != (_Instance *)0x0)
            {
              if (CurrentSection == 0)
              {
                In->SectionList[0].Data1 = 0;
                /* WARNING: Subroutine does not return */
                INSTANCE_Post(_CHAR____800d5620, (int)&DAT_80000010, (int)In->CharacterInstance);
              }
              if ((_CHAR____800d5574 & 0x40000) == 0)
              {
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
              pcVar5 = StateHandlerSwim;
              in_a3 = 0;
              StateSwitchStateData(In, CurrentSection, StateHandlerSwim, 0);
            }
          }
          else
          {
            if ((int)puVar3 < -0x7fffffef)
            {
              if (puVar3 == (undefined *)0x80000000)
                goto LAB_800aff50;
              puVar1 = &DAT_80000008;
            }
            else
            {
              if (puVar3 == &DAT_00040003)
              {
                p_Var4 = (_Instance *)p_Var2->Data;
                Data_00 = SetActionPlayHostAnimationData(*(_Instance **)&p_Var4->node,
                                                         *(_Instance **)((int)&p_Var4->node + 4), (int)p_Var4->next,
                                                         (int)p_Var4->prev, (int)p_Var4->instanceID, (int)p_Var4->flags);
                ID = p_Var2->ID;
              LAB_800b00a0:
                /* WARNING: Subroutine does not return */
                EnMessageQueueData(&p_Var7->Defer, ID, Data_00);
              }
              if (0x40003 < (int)puVar3)
              {
                if (puVar3 == &DAT_00040005)
                  goto LAB_800b00b0;
                goto LAB_800b00c8;
              }
              puVar1 = &DAT_80000020;
            }
            if (puVar3 != puVar1)
              goto LAB_800b00c8;
          }
          goto LAB_800b00d0;
        }
        if (puVar3 == (undefined *)0x80003)
        {
          if (CurrentSection == 0)
          {
            razPrepGlyph();
            razSwitchStringAnimation(In->CharacterInstance, 4);
            pcVar5 = (code *)0x13;
            local_38 = 0x2ee;
            local_34 = 0x3c;
            _CHAR____800d5730 = _CHAR____800d5730 | 4;
            in_a3 = 600;
            razSetupSoundRamp(In->CharacterInstance, (_SoundRamp *)&CHAR____800d577c, 0x13, 600, 0x2ee,
                              0x3c, 0x78, 0x32000, 0xdac);
            _CHAR____800d57b0 = 1;
            _CHAR____800d57ac = (undefined *)0x32000;
          }
        }
        else
        {
          if ((int)puVar3 < 0x80004)
          {
            if (puVar3 == (undefined *)0x80001)
            {
              if (CurrentSection == 0)
              {
                razPrepGlyph();
                razSwitchStringAnimation(In->CharacterInstance, 1);
                pcVar5 = (code *)0xc;
                local_38 = 0x7d;
                local_34 = 0x50;
                _CHAR____800d5730 = _CHAR____800d5730 | 4;
                in_a3 = 0;
                razSetupSoundRamp(In->CharacterInstance, (_SoundRamp *)&CHAR____800d577c, 0xc, 0, 0x7d,
                                  0x50, 0x50, (int)&LAB_0004d000, 0xdac);
                _CHAR____800d57b0 = 3;
                _CHAR____800d57ac = &LAB_0004d000;
              }
            }
            else
            {
              if (puVar3 != (undefined *)0x80002)
                goto LAB_800b00c8;
              if (CurrentSection == 0)
              {
                razPrepGlyph();
                razSwitchStringAnimation(In->CharacterInstance, 2);
                pp_Var6[0x47] = (_Instance *)0x0;
                goto LAB_800b00d0;
              }
            }
          }
          else
          {
            if (puVar3 != (undefined *)0x80005)
            {
              if ((int)puVar3 < 0x80006)
              {
                if (CurrentSection != 0)
                  goto LAB_800afe94;
                razPrepGlyph();
                razSwitchStringAnimation(In->CharacterInstance, 5);
                pp_Var6[0x47] = (_Instance *)0x0;
              }
              else
              {
                if (CurrentSection != 0)
                  goto LAB_800afe94;
                razPrepGlyph();
                razSwitchStringAnimation(In->CharacterInstance, 6);
                pp_Var6[0x47] = (_Instance *)0x0;
              }
              goto LAB_800b00d0;
            }
            if (CurrentSection == 0)
            {
              razPrepGlyph();
              razSwitchStringAnimation(In->CharacterInstance, 3);
              pp_Var6[0x47] = (_Instance *)0x0;
              goto LAB_800b00d0;
            }
          }
        }
      LAB_800afe94:
        pp_Var6[0x47] = (_Instance *)0x0;
      }
      else
      {
        if (puVar3 == (undefined *)0x2000000)
        {
        LAB_800aff50:
          if ((pp_Var6[0x47] != (_Instance *)0x0) && (CurrentSection == 0))
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Post(_CHAR____800d5620, -0x80000000, 0);
          }
        }
        else
        {
          if ((int)puVar3 < 0x2000001)
          {
            if (puVar3 == &DAT_00100004)
            {
              if (CurrentSection == 0)
              {
                razReaverOn();
                Data_00 = GlyphIsGlyphOpen(_CHAR____800d5620);
                if (Data_00 != 0)
                {
                  /* WARNING: Subroutine does not return */
                  INSTANCE_Post(_CHAR____800d5620, (int)&DAT_80000010, (int)In->CharacterInstance);
                }
              }
              _CHAR____800d5618 = 0;
            }
            else
            {
              if ((int)puVar3 < 0x100005)
              {
                if (puVar3 == (undefined *)0x100000)
                {
                  if (pp_Var6[0x47] == (_Instance *)0x0)
                  {
                    if (((_CHAR____800d5574 & 0x40000) == 0) || (_CHAR____800d564c != 1))
                    {
                      /* WARNING: Subroutine does not return */
                      SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                    }
                    pcVar5 = StateHandlerSwim;
                    in_a3 = 0;
                    StateSwitchStateData(In, CurrentSection, StateHandlerSwim, 0);
                    if (CurrentSection == 0)
                    {
                      pcVar5 = (code *)0x100;
                      razSetFadeEffect(0x1000, 0, 0x100);
                    }
                  }
                  else
                  {
                    if (((_CHAR____800d5574 & 0x40000) == 0) && (pp_Var6[0x47] != (_Instance *)0x2))
                    {
                      /* WARNING: Subroutine does not return */
                      SetPhysicsWallCrawlData(0, 0, 3, in_a3);
                    }
                  }
                }
                else
                {
                  if (puVar3 != &DAT_00100001)
                    goto LAB_800b00c8;
                  if (CurrentSection == 0)
                  {
                    if (p_Var2->Data == 0)
                    {
                      /* WARNING: Subroutine does not return */
                      INSTANCE_Post(_CHAR____800d5620, (int)&DAT_80000010, (int)In->CharacterInstance);
                    }
                    _CHAR____800d5574 = _CHAR____800d5574 | 1;
                    _BlockVramEntry_800d59a0._12_4_ = 0x1100008;
                    SteerSwitchMode(In->CharacterInstance, 0x10);
                    razResetMotion(In->CharacterInstance);
                  }
                  pp_Var6[0x47] = (_Instance *)0x1;
                  PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
                  if (p_Var2->Data != 0)
                  {
                    /* WARNING: Subroutine does not return */
                    EnMessageQueueData(&p_Var7->Defer, 0x80007, 0);
                  }
                }
              }
              else
              {
                if (puVar3 == (undefined *)0x1000000)
                {
                  p_Var4 = (_Instance *)p_Var2->Data;
                  if (_CHAR____800d5618 == 0)
                  {
                    Data_00 = SetMonsterHitData(*(_Instance **)&p_Var4->node,
                                                *(_Instance **)((int)&p_Var4->node + 4),
                                                (int)p_Var4->prev, (int)*(short *)&p_Var4->next,
                                                (int)*(short *)((int)&p_Var4->next + 2));
                    ID = 0x1000000;
                    goto LAB_800b00a0;
                  }
                }
                else
                {
                  if ((int)puVar3 < 0x1000001)
                  {
                    if (puVar3 == &DAT_00100015)
                      goto LAB_800afbac;
                  }
                  else
                  {
                    if (puVar3 == (undefined *)0x1000001)
                      goto LAB_800b00d0;
                  }
                LAB_800b00c8:
                  pcVar5 = (code *)Data;
                  DefaultStateHandler(In, CurrentSection, Data);
                }
              }
            }
          }
          else
          {
            if (puVar3 != (undefined *)0x4020000)
            {
              if ((int)puVar3 < 0x4020001)
              {
                if (puVar3 == (undefined *)0x4000001)
                {
                  if ((_CHAR____800d5574 & 0x40000) == 0)
                  {
                    PhysicsMode.next = (_BlockVramEntry *)0x0;
                    SetExternalForce((__Force *)In->CharacterInstance, 0x5214, (short)pcVar5,
                                     (short)in_a3, local_38, local_34);
                  }
                }
                else
                {
                  if (puVar3 != (undefined *)0x4010200)
                    goto LAB_800b00c8;
                }
              }
              else
              {
                if (puVar3 != (undefined *)0x8000003)
                {
                  if ((int)puVar3 < 0x8000004)
                  {
                    if (puVar3 == (undefined *)0x8000000)
                      goto LAB_800afbac;
                  }
                  else
                  {
                    if (puVar3 == (undefined *)0x10000000)
                    {
                      if (CurrentSection == 0)
                      {
                        if ((*gameTracker._4_4_ & 4) != 0)
                        {
                          /* WARNING: Subroutine does not return */
                          INSTANCE_Post(_CHAR____800d5620, 0x10000004, p_Var2->Data);
                        }
                        if ((*gameTracker._4_4_ & 8) != 0)
                        {
                          /* WARNING: Subroutine does not return */
                          INSTANCE_Post(_CHAR____800d5620, 0x10000002, p_Var2->Data);
                        }
                      }
                      goto LAB_800b00d0;
                    }
                  }
                  goto LAB_800b00c8;
                }
              LAB_800afbac:
                if (CurrentSection == 0)
                {
                  CheckStringAnimation(In->CharacterInstance, p_Var2->ID);
                }
              }
            }
          }
        }
      }
    }
  LAB_800b00d0:
    DeMessageQueue(&p_Var7->Event);
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ DefaultStateHandler(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
// line 4391, offset 0x800b0114
/* begin block 1 */
// Start line: 4392
// Start offset: 0x800B0114
// Variables:
// 		struct __Event *Ptr; // $s0

/* begin block 1.1 */
// Start line: 4411
// Start offset: 0x800B03B4
// Variables:
// 		int message; // stack offset -32
// 		int messageData; // stack offset -28

/* begin block 1.1.1 */
// Start line: 4431
// Start offset: 0x800B0478
// Variables:
// 		int i; // $s1
/* end block 1.1.1 */
// End offset: 0x800B04B8
// End Line: 4437
/* end block 1.1 */
// End offset: 0x800B04B8
// End Line: 4440

/* begin block 1.2 */
// Start line: 4602
// Start offset: 0x800B0634
// Variables:
// 		struct evPhysicsGravityData *ptr; // $v1
// 		short zRot; // $s0

/* begin block 1.2.1 */
// Start line: 4608
// Start offset: 0x800B0640
// Variables:
// 		struct _Position pos1; // stack offset -48
// 		struct _Position pos2; // stack offset -40
// 		int diff; // $v0
/* end block 1.2.1 */
// End offset: 0x800B0720
// End Line: 4628
/* end block 1.2 */
// End offset: 0x800B0720
// End Line: 4628

/* begin block 1.3 */
// Start line: 4661
// Start offset: 0x800B07B4
// Variables:
// 		struct evFXHitData *BloodData; // $a0
// 		struct _SVector Accel; // stack offset -48
/* end block 1.3 */
// End offset: 0x800B07B4
// End Line: 4662

/* begin block 1.4 */
// Start line: 4710
// Start offset: 0x800B0960
// Variables:
// 		struct evPhysicsEdgeData *data; // $s0
/* end block 1.4 */
// End offset: 0x800B099C
// End Line: 4716
/* end block 1 */
// End offset: 0x800B0A90
// End Line: 4753

/* begin block 2 */
// Start line: 9276
/* end block 2 */
// End Line: 9277

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DefaultStateHandler(__CharacterState *In, int CurrentSection, int Data)

{
  short y;
  __Event *p_Var1;
  _G2Bool_Enum _Var2;
  undefined *puVar3;
  code *NewProcess;
  int in_a3;
  int Data_00;
  _Instance *p_Var4;
  int iVar5;
  int local_38;
  int local_34;
  _Position local_30;
  _Position local_28;
  int local_20;
  int local_1c;

  y = (short)Data;
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0)
  {
    return;
  }
  puVar3 = (undefined *)p_Var1->ID;
  if (puVar3 == (undefined *)0x1000000)
  {
    if (CurrentSection != 0)
    {
      return;
    }
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x4000) != 0)
    {
      return;
    }
    if (_CHAR____800d5618 != 0)
    {
      return;
    }
    StateSwitchStateCharacterDataDefault(In, StateHandlerHitReaction, p_Var1->Data);
    CAMERA_ForceEndLookaroundMode((Camera *)&theCamera);
    return;
  }
  if ((int)puVar3 < 0x1000001)
  {
    if (puVar3 == &DAT_00040005)
    {
    LAB_800b0a2c:
      StateSwitchStateDataDefault(In, CurrentSection, StateHandlerStumble, p_Var1->Data);
      In->SectionList[CurrentSection].Data1 = p_Var1->Data * 0x1e;
      return;
    }
    if ((int)puVar3 < 0x40006)
    {
      if (puVar3 == &DAT_80000008)
      {
        if (CurrentSection != 0)
        {
          return;
        }
        StateSwitchStateCharacterDataDefault(In, StateHandlerCrouch, 1);
        return;
      }
      if (-0x7ffffff8 < (int)puVar3)
      {
        if (puVar3 != &DAT_80000020)
        {
          if (puVar3 != (undefined *)0x40000)
          {
            return;
          }
          if (CurrentSection == 2)
          {
            G2EmulationSwitchAnimation(In, 2, 0, 0, 3, 2);
            return;
          }
          G2EmulationSwitchAnimation(In, CurrentSection, 0x17, 0, 3, 1);
          return;
        }
        if (CurrentSection != 0)
        {
          return;
        }
        if ((_CHAR____800d55b0 & 0x80) != 0)
        {
          return;
        }
        if ((*(uint *)(gameTracker._4_4_ + 4) & LONG_800cf568) != 0)
        {
          return;
        }
        Data_00 = StateHandlerDecodeHold(&local_20, &local_1c);
        if (Data_00 == 0)
        {
          return;
        }
        if (local_20 == 0x800010)
        {
          NewProcess = StateHandlerThrow2;
        }
        else
        {
          if (local_20 == 0x1000002)
          {
            StateSwitchStateCharacterDataDefault(In, StateHandlerGrab, local_1c);
            return;
          }
          if (local_20 != 0x80000)
          {
            StateSwitchStateCharacterDataDefault(In, StateHandlerAttack2, 0);
            /* WARNING: Subroutine does not return */
            EnMessageQueueData(&In->SectionList[0].Defer, (int)&DAT_80000020, 0);
          }
          _CHAR____800d57c4 = _CHAR____800d57c4 | 0x400;
          razSetPlayerEventHistory(0x400);
          razLaunchForce(In->CharacterInstance);
          NewProcess = StateHandlerThrow2;
        }
        goto LAB_800b0858;
      }
      if (puVar3 != (undefined *)0x80000000)
      {
        if (puVar3 != &DAT_80000004)
        {
          return;
        }
        _CHAR____800d5574 = _CHAR____800d5574 | 2;
        return;
      }
      if ((_CHAR____800d5574 & 0x40000) != 0)
      {
        return;
      }
      if ((_CHAR____800d55b0 & 0x80) != 0)
      {
        return;
      }
      Data_00 = 0;
      NewProcess = StateHandlerAttack2;
    }
    else
    {
      if (puVar3 == &DAT_00100005)
      {
        Data_00 = p_Var1->Data;
        if (Data_00 == 1)
        {
          if (In->CharacterInstance->LinkChild != (_Instance *)0x0)
          {
            G2EmulationSwitchAnimation(In, p_Var1->Data, 0x32, 0, 3, 2);
            NewProcess = In->SectionList[CurrentSection].Process;
            Data_00 = 0;
            CurrentSection = p_Var1->Data;
            goto LAB_800b0a88;
          }
          Data_00 = 1;
        }
        G2EmulationSwitchAnimationSync(In, Data_00, 0, 3);
        return;
      }
      if ((int)puVar3 < 0x100006)
      {
        if (puVar3 == &UNK_00040025)
          goto LAB_800b0a2c;
        if (puVar3 != (undefined *)0x100000)
        {
          return;
        }
        if ((TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)p_Var1->Data ==
            (TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)0x0)
        {
          return;
        }
        Data_00 = 0;
        NewProcess = (TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)p_Var1->Data;
      }
      else
      {
        if (puVar3 != &DAT_00100009)
        {
          if ((int)puVar3 < 0x10000a)
          {
            if (puVar3 != &DAT_00100006)
            {
              return;
            }
            InitAlgorithmicWings(In->CharacterInstance);
            return;
          }
          if (puVar3 != (undefined *)0x400000)
          {
            return;
          }
          if (CurrentSection != 0)
          {
            return;
          }
          /* WARNING: Subroutine does not return */
          memset(&local_30, 0, 8);
        }
        if (p_Var1->Data == 0)
        {
          if (_CHAR____800d571c == (_func_14 *)0x0)
          {
            _CHAR____800d571c = StateHandlerIdle;
          }
          Data_00 = 0;
          NewProcess = _CHAR____800d571c;
        }
        else
        {
          if (CurrentSection == 0)
          {
            _CHAR____800d571c = In->SectionList[0].Process;
            if (_CHAR____800d571c == StateHandlerSoulSuck)
            {
              _CHAR____800d571c = StateHandlerIdle;
            }
            In->SectionList[0].Data1 = _CHAR____800d5574;
            _CHAR____800d5574 = 0x80000;
          }
          Data_00 = 0;
          NewProcess = StateHandlerLookAround;
        }
      }
    }
  LAB_800b0a88:
    StateSwitchStateDataDefault(In, CurrentSection, NewProcess, Data_00);
    return;
  }
  if (puVar3 == (undefined *)0x4010200)
  {
    Data_00 = p_Var1->Data;
    if (CurrentSection != 0)
    {
      return;
    }
    local_30.x = 0;
    local_30.y = 0;
    local_28.x = *(short *)(Data_00 + 4);
    local_28.y = *(short *)(Data_00 + 6);
    local_28.z = *(short *)(Data_00 + 8);
    y = MATH3D_AngleFromPosToPos(&local_30, &local_28);
    _Var2 = G2Anim_IsControllerActive(&In->CharacterInstance->anim, 1, 0xe);
    if (_Var2 != G2FALSE)
    {
      G2Anim_DisableController(&In->CharacterInstance->anim, 1, 0xe);
      if (gameTracker._16_4_ != 0)
      {
        (In->CharacterInstance->rotation).z =
            (In->CharacterInstance->rotation).z + *(short *)(gameTracker._16_4_ + 4);
      }
      gameTracker._16_4_ = 0;
    }
    p_Var4 = In->CharacterInstance;
    if (((int)(p_Var4->rotation).z - (int)y) + 0x3ffU < 0x7ff)
    {
      (p_Var4->rotation).z = y;
      G2EmulationSwitchAnimationCharacter((__CharacterState *)&CHAR____800d5218, 0x49, 0, 6, 2);
      NewProcess = StateHandlerSlide;
      In = (__CharacterState *)&CHAR____800d5218;
    }
    else
    {
      (p_Var4->rotation).z = y + 0x800;
      G2EmulationSwitchAnimationCharacter((__CharacterState *)&CHAR____800d5218, 0x4d, 0, 6, 2);
      NewProcess = StateHandlerSlide;
      In = (__CharacterState *)&CHAR____800d5218;
    }
  }
  else
  {
    if (0x4010200 < (int)puVar3)
    {
      if (puVar3 == (undefined *)0x8000000)
      {
        /* WARNING: Subroutine does not return */
        SetPhysicsWallCrawlData(0, 0, 3, in_a3);
      }
      if ((int)puVar3 < 0x8000001)
      {
        if (puVar3 != (undefined *)0x4010400)
        {
          if (puVar3 != (undefined *)0x4020000)
          {
            return;
          }
          razEnterWater(In, CurrentSection, (evPhysicsSwimData *)p_Var1->Data);
          return;
        }
        if (CurrentSection == 0)
        {
          if (LastBlock + 2 < LoopCounter)
          {
            BlockCount = 0;
          }
          LastBlock = LoopCounter;
          BlockCount = BlockCount + 1;
        }
        if (BlockCount < 0x10)
        {
          return;
        }
        NewProcess = StateHandlerBlock;
        Data_00 = 0;
      }
      else
      {
        if ((int)puVar3 < 0x10002001)
        {
          return;
        }
        if (0x10002002 < (int)puVar3)
        {
          if (puVar3 != (undefined *)0x20000004)
          {
            return;
          }
          _CHAR____800d5574 = _CHAR____800d5574 & 0xfffffffd | 1;
          return;
        }
        NewProcess = StateHandlerGlyphs;
        Data_00 = 1;
      }
      goto LAB_800b0a88;
    }
    if (puVar3 == (undefined *)0x4000004)
    {
      return;
    }
    if ((int)puVar3 < 0x4000005)
    {
      if (puVar3 == (undefined *)0x1000001)
      {
        NewProcess = StateHandlerAutoFace;
        Data_00 = 0;
        goto LAB_800b0a88;
      }
      if (puVar3 != (undefined *)0x4000001)
      {
        return;
      }
      PhysicsMode.next = (_BlockVramEntry *)0x0;
      SetExternalForce((__Force *)In->CharacterInstance, 0x5214, y, (short)in_a3, local_38, local_34);
      if ((int)_CHAR____800d560a <= In->CharacterInstance->zVel)
      {
        return;
      }
      if (CurrentSection != 0)
      {
        return;
      }
      Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance, 0x18, (int *)0x0, (int *)0x0);
      if (Data_00 != 0)
      {
        G2EmulationSwitchAnimationCharacter(In, 0x24, 0, 4, 1);
      }
      NewProcess = StateHandlerFall;
    }
    else
    {
      if (puVar3 == (undefined *)0x4010008)
      {
        if (PhysicsMode.next == (_BlockVramEntry *)&DAT_00000003)
        {
          return;
        }
        PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
        SetPhysics(In->CharacterInstance, -0x10, 0, 0, 0);
        return;
      }
      if (0x4010008 < (int)puVar3)
      {
        if (puVar3 != (undefined *)0x4010010)
        {
          return;
        }
        iVar5 = p_Var1->Data;
        Data_00 = SetControlInitHangData(*(_Instance **)(iVar5 + 0x18), 0, 3);
        StateSwitchStateDataDefault(In, CurrentSection, StateHandlerHang, Data_00);
        (In->CharacterInstance->rotation).z = *(short *)(iVar5 + 0x1c);
        return;
      }
      if (puVar3 != (undefined *)0x4000011)
      {
        return;
      }
      if ((_CHAR____800d561c & 2) == 0)
      {
        return;
      }
      if (_CHAR____800d5600 == 3)
      {
        return;
      }
      if (_CHAR____800d564c != 1)
      {
        return;
      }
      if (CurrentSection != 0)
      {
        return;
      }
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance, -0x80);
      if (Data_00 != 0)
      {
        return;
      }
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance, 0x80);
      if (Data_00 != 0)
      {
        return;
      }
      NewProcess = StateHandlerWallGrab;
    }
  }
LAB_800b0858:
  StateSwitchStateCharacterDataDefault(In, NewProcess, 0);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ RazielAnimCallback(struct _G2Anim_Type *anim /*$s3*/, int sectionID /*$s1*/, enum _G2AnimCallbackMsg_Enum message /*$s4*/, long messageDataA /*$s5*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
// line 4757, offset 0x800b0aac
/* begin block 1 */
// Start line: 4758
// Start offset: 0x800B0AAC
// Variables:
// 		struct __State *pSection; // $a0
// 		struct _G2AnimSection_Type *animSection; // $a2

/* begin block 1.1 */
// Start line: 4776
// Start offset: 0x800B0B70
// Variables:
// 		struct evAnimationControllerDoneData *ControllerData; // $v1
/* end block 1.1 */
// End offset: 0x800B0BF8
// End Line: 4792

/* begin block 1.2 */
// Start line: 4806
// Start offset: 0x800B0C40
// Variables:
// 		struct __AlarmData *data; // $s0
// 		struct _Instance *inst; // $a0

/* begin block 1.2.1 */
// Start line: 4877
// Start offset: 0x800B0E40
// Variables:
// 		int test; // $a0

/* begin block 1.2.1.1 */
// Start line: 4897
// Start offset: 0x800B0EA4
// Variables:
// 		struct _SoundRamp *soundRamp; // $t0
/* end block 1.2.1.1 */
// End offset: 0x800B0FC4
// End Line: 4912
/* end block 1.2.1 */
// End offset: 0x800B0FC4
// End Line: 4912
/* end block 1.2 */
// End offset: 0x800B0FDC
// End Line: 4921

/* begin block 1.3 */
// Start line: 4925
// Start offset: 0x800B0FE4

/* begin block 1.3.1 */
// Start line: 4930
// Start offset: 0x800B1008
// Variables:
// 		struct _Instance *heldInstance; // $s0
/* end block 1.3.1 */
// End offset: 0x800B1048
// End Line: 4936
/* end block 1.3 */
// End offset: 0x800B105C
// End Line: 4945
/* end block 1 */
// End offset: 0x800B1088
// End Line: 4960

/* begin block 2 */
// Start line: 10027
/* end block 2 */
// End Line: 10028

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long RazielAnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message,
                        long messageDataA, long messageDataB, void *data)

{
  short sVar1;
  bool bVar2;
  evAnimationControllerDoneData *ControllerData;
  _Instance *Inst;
  int iVar3;
  _G2AnimSection_Type *p_Var4;
  long messageDataA_00;

  iVar3 = sectionID * 0x11c;
  p_Var4 = anim->section + sectionID;
  switch (message)
  {
  case G2ANIM_MSG_DONE:
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)(&CHAR____800d5224 + iVar3), 0x8000000,
                       (uint)p_Var4->keylistID);
  case G2ANIM_MSG_LOOPPOINT:
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)(&CHAR____800d5224 + iVar3), 0x8000001,
                       (uint)p_Var4->keylistID);
  case G2ANIM_MSG_SECTION_INTERPDONE:
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)(&CHAR____800d5224 + iVar3), 0x8000003,
                       (uint)p_Var4->keylistID);
  case G2ANIM_MSG_SEGCTRLR_INTERPDONE:
    ControllerData =
        (evAnimationControllerDoneData *)
            SetAnimationControllerDoneData(_CHAR____800d5218, messageDataB, messageDataA, (int)data);
    iVar3 = ControllerData->data;
    if (iVar3 == 2)
    {
      AlgorithmicWings(_CHAR____800d5218, ControllerData);
    }
    else
    {
      if (iVar3 == 0)
      {
        G2Anim_InterpDisableController(&ControllerData->instance->anim, ControllerData->segment, ControllerData->type, 300);
      }
      else
      {
        if (iVar3 == 4)
        {
          G2Anim_DisableController(&ControllerData->instance->anim, ControllerData->segment, ControllerData->type);
        }
      }
    }
    break;
  case G2ANIM_MSG_SWALARMSET:
    p_Var4->swAlarmTable = (short *)0x0;
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)(&CHAR____800d5224 + iVar3), 0x8000004, 0);
  case G2ANIM_MSG_PLAYEFFECT:
    if (messageDataA != 2)
    {
      messageDataA_00 = messageDataA;
      if (messageDataA == 0)
      {
        if (*(short *)messageDataB == 0x2d)
        {
          if ((_BlockVramEntry_800d59a0._12_4_ & 0x100000) != 0)
          {
            return 0;
          }
          Inst = razGetHeldWeapon();
          if (Inst == (_Instance *)0x0)
          {
            return 0;
          }
          /* WARNING: Subroutine does not return */
          INSTANCE_Query(Inst, 2);
        }
        messageDataA_00 = 0;
      }
      INSTANCE_DefaultAnimCallback(anim, sectionID, message, messageDataA_00, messageDataB, _CHAR____800d5218);
      return messageDataA;
    }
    Inst = razGetHeldWeapon();
    switch ((int)(((uint) * (ushort *)messageDataB - 1) * 0x10000) >> 0x10)
    {
    case 0:
      if (Inst != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(Inst, 0x200002, (int)*(short *)(messageDataB + 2));
      }
      EnableWristCollision(DAT_800d0fd8, (int)*(short *)(messageDataB + 2));
      break;
    case 1:
      if (Inst != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(Inst, 0x200003, (int)*(short *)(messageDataB + 2));
      }
      DisableWristCollision(DAT_800d0fd8, (int)*(short *)(messageDataB + 2));
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x10000000;
      break;
    case 2:
      razSetCowlNoDraw(0);
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x40;
      break;
    case 3:
      razSetCowlNoDraw(1);
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xffffffbf;
      break;
    case 4:
      if ((int)*(short *)(messageDataB + 2) < 0x20)
      {
        _CHAR____800d5720 = _CHAR____800d5720 | 1 << ((int)*(short *)(messageDataB + 2) & 0x1fU);
      }
      else
      {
        _CHAR____800d5720 = 0xffffffff;
      }
      break;
    case 5:
      if ((int)*(short *)(messageDataB + 2) < 0x20)
      {
        _CHAR____800d5720 = _CHAR____800d5720 & ~(1 << ((int)*(short *)(messageDataB + 2) & 0x1fU));
      }
      else
      {
        _CHAR____800d5720 = 0;
      }
      break;
    case 6:
      _CHAR____800d5734 = DAT_800d0fd8->fadeValue;
      _CHAR____800d5736 = *(undefined2 *)(messageDataB + 2);
      _CHAR____800d5730 = _CHAR____800d5730 | 1;
      break;
    case 7:
      _CHAR____800d573c = 0;
      _CHAR____800d5730 = _CHAR____800d5730 | 1;
      _CHAR____800d5738 = (int)*(short *)(messageDataB + 2);
      break;
    case 8:
      if (Inst != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(Inst, 0x200005, (int)*(short *)(messageDataB + 2));
      }
      break;
    case 9:
      if (Inst != (_Instance *)0x0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(Inst, 0x200006, (int)*(short *)(messageDataB + 2));
      }
      break;
    case 10:
      sVar1 = *(short *)(messageDataB + 2);
      bVar2 = false;
      if (sVar1 == 2)
      {
        iVar3 = 1;
      code_r0x800b0e90:
        if (_CHAR____800d5648 == iVar3)
        {
          bVar2 = true;
        }
      }
      else
      {
        if (sVar1 < 3)
        {
          if (-1 < sVar1)
          {
            bVar2 = true;
          }
        }
        else
        {
          iVar3 = 6;
          if (sVar1 == 3)
            goto code_r0x800b0e90;
        }
      }
      if (bVar2)
      {
        iVar3 = (int)*(short *)(messageDataB + 2);
        razSetupSoundRamp(DAT_800d0fd8,
                          (_SoundRamp *)(&CHAR____800d577c + (int)cannedSound[iVar3].bank * 0x18),
                          (int)cannedSound[iVar3].sound, (int)cannedSound[iVar3].startPitch,
                          (int)cannedSound[iVar3].endPitch,
                          (int)cannedSound[*(short *)(messageDataB + 2)].startVolume,
                          (int)cannedSound[*(short *)(messageDataB + 2)].endVolume,
                          cannedSound[*(short *)(messageDataB + 2)].time,
                          cannedSound[*(short *)(messageDataB + 2)].distance);
        iVar3 = (int)*(short *)(messageDataB + 2);
        if (cannedSound[iVar3].bank == 0)
        {
          _CHAR____800d5730 = _CHAR____800d5730 | 4;
          iVar3 = (int)*(short *)(messageDataB + 2);
        }
        if (cannedSound[iVar3].bank == 1)
        {
          _CHAR____800d5730 = _CHAR____800d5730 | 8;
        }
      }
    }
  }
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  return messageDataA;
}

// decompiled code
// original method signature:
// long /*$ra*/ RazielAnimCallbackDuringPause(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$s0*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
// line 4961, offset 0x800b10b0
/* begin block 1 */
// Start line: 4962
// Start offset: 0x800B10B0

/* begin block 1.1 */
// Start line: 4971
// Start offset: 0x800B10D0
// Variables:
// 		struct evAnimationControllerDoneData *ControllerData; // $v1
/* end block 1.1 */
// End offset: 0x800B114C
// End Line: 4987
/* end block 1 */
// End offset: 0x800B114C
// End Line: 4992

/* begin block 2 */
// Start line: 10454
/* end block 2 */
// End Line: 10455

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long RazielAnimCallbackDuringPause(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message, long messageDataA,
                                   long messageDataB, void *data)

{
  evAnimationControllerDoneData *ControllerData;
  int iVar1;

  if (message == G2ANIM_MSG_SEGCTRLR_INTERPDONE)
  {
    ControllerData =
        (evAnimationControllerDoneData *)
            SetAnimationControllerDoneData(_CHAR____800d5218, messageDataB, messageDataA, (int)data);
    iVar1 = ControllerData->data;
    if (iVar1 == 2)
    {
      AlgorithmicWings(_CHAR____800d5218, ControllerData);
    }
    else
    {
      if (iVar1 == 0)
      {
        G2Anim_InterpDisableController(&ControllerData->instance->anim, ControllerData->segment, ControllerData->type, 300);
      }
      else
      {
        if (iVar1 == 4)
        {
          G2Anim_DisableController(&ControllerData->instance->anim, ControllerData->segment, ControllerData->type);
        }
      }
    }
  }
  return messageDataA;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ RazielQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
// line 5035, offset 0x800b1164
/* begin block 1 */
// Start line: 5036
// Start offset: 0x800B1164

/* begin block 1.1 */
// Start line: 5098
// Start offset: 0x800B1278
// Variables:
// 		struct _Normal *Ptr; // $a0
/* end block 1.1 */
// End offset: 0x800B1320
// End Line: 5114

/* begin block 1.2 */
// Start line: 5117
// Start offset: 0x800B1320
// Variables:
// 		unsigned long ability; // $s0
/* end block 1.2 */
// End offset: 0x800B1398
// End Line: 5135

/* begin block 1.3 */
// Start line: 5137
// Start offset: 0x800B1398
// Variables:
// 		struct PlayerSaveData *data; // $s0
/* end block 1.3 */
// End offset: 0x800B1404
// End Line: 5154

/* begin block 1.4 */
// Start line: 5178
// Start offset: 0x800B1484
// Variables:
// 		struct evShadowSegmentData *shadowData; // $v0
/* end block 1.4 */
// End offset: 0x800B14A0
// End Line: 5185
/* end block 1 */
// End offset: 0x800B1518
// End Line: 5212

/* begin block 2 */
// Start line: 10070
/* end block 2 */
// End Line: 10071

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong RazielQuery(_Instance *instance, ulong Query)

{
  int iVar1;
  _Instance *p_Var2;

  switch (Query)
  {
  case 1:
    p_Var2 = (_Instance *)&UNK_00000001;
    break;
  case 6:
    p_Var2 = (_Instance *)
        SetPositionData((int)(instance->position).x, (int)(instance->position).y,
                        (int)(instance->position).z);
    break;
  case 7:
    if (_CHAR____800d559c == 4)
    {
      p_Var2 = (_Instance *)
          SetPositionData((int)(instance->rotation).x, (int)(instance->rotation).y,
                          _CHAR____800d55a4);
    }
    else
    {
      p_Var2 = (_Instance *)
          SetPositionData((int)(instance->rotation).x, (int)(instance->rotation).y,
                          (int)(instance->rotation).z);
    }
    break;
  case 8:
    p_Var2 = (_Instance *)0x0;
    if (gameTracker._16_4_ != (_Instance *)0x0)
    {
      p_Var2 = gameTracker._16_4_;
    }
    break;
  case 9:
    p_Var2 = (_Instance *)WaterStatus;
    break;
  case 10:
    p_Var2 = _CHAR____800d5574;
    break;
  case 0xb:
    p_Var2 = _CHAR____800d564c;
    break;
  case 0xc:
    if (instance->oldMatrix != (MATRIX *)0x0)
    {
      return (ulong)(instance->oldMatrix + 0xf);
    }
  default:
    p_Var2 = (_Instance *)0x0;
    break;
  case 0xd:
    p_Var2 = (_Instance *)0x0;
    if ((_Instance *)instance->oldMatrix != (_Instance *)0x0)
    {
      p_Var2 = (_Instance *)instance->oldMatrix;
    }
    break;
  case 0x10:
    /* WARNING: Subroutine does not return */
    CIRC_Alloc(8);
  case 0x13:
    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  case 0x18:
    /* WARNING: Subroutine does not return */
    CIRC_Alloc(0x18);
  case 0x1f:
    p_Var2 = (_Instance *)(int)_CHAR____800d560e;
    break;
  case 0x20:
    p_Var2 = (_Instance *)(uint)_CHAR____800d5624;
    break;
  case 0x22:
    p_Var2 = _CHAR____800d55e4;
    if (((*gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) != 0) &&
        (p_Var2 = (_Instance *)0x0, ((uint)_CHAR____800d55f0 & 0x40) != 0))
    {
      p_Var2 = *(_Instance **)(_CHAR____800d55ec + 0x30);
    }
    break;
  case 0x24:
    p_Var2 = _CHAR____800d561c;
    break;
  case 0x26:
    p_Var2 = (_Instance *)SetShadowSegmentData(2);
    *(undefined2 *)&(p_Var2->node).next = 0xc;
    *(undefined2 *)((int)&(p_Var2->node).next + 2) = 8;
    break;
  case 0x27:
    p_Var2 = _CHAR____800d55f0;
    break;
  case 0x29:
    p_Var2 = _CHAR____800d57c4;
    break;
  case 0x2a:
    p_Var2 = _CHAR____800d57c8;
    break;
  case 0x2b:
    iVar1 = GetMaxHealth();
    p_Var2 = (_Instance *)(uint)(_CHAR____800d5610 == iVar1);
    break;
  case 0x2c:
    p_Var2 = razGetHeldItem();
    break;
  case 0x2d:
    p_Var2 = (_Instance *)(uint)_CHAR____800d5626;
    break;
  case 0x2e:
    p_Var2 = _CHAR____800d5618;
    break;
  case 0x30:
    p_Var2 = (_Instance *)(uint)(_CHAR____800d571c == StateHandlerPuppetShow);
  }
  return (ulong)p_Var2;
}

// decompiled code
// original method signature:
// void /*$ra*/ RazielPost(struct _Instance *instance /*$s0*/, unsigned long Message /*$s2*/, unsigned long Data /*$s3*/)
// line 5216, offset 0x800b1528
/* begin block 1 */
// Start line: 5217
// Start offset: 0x800B1528
// Variables:
// 		int i; // $s1

/* begin block 1.1 */
// Start line: 5224
// Start offset: 0x800B1764
/* end block 1.1 */
// End offset: 0x800B179C
// End Line: 5242

/* begin block 1.2 */
// Start line: 5288
// Start offset: 0x800B180C
// Variables:
// 		struct PlayerSaveData *data; // $s0
/* end block 1.2 */
// End offset: 0x800B18CC
// End Line: 5333

/* begin block 1.3 */
// Start line: 5359
// Start offset: 0x800B197C
/* end block 1.3 */
// End offset: 0x800B1990
// End Line: 5365

/* begin block 1.4 */
// Start line: 5385
// Start offset: 0x800B19EC
/* end block 1.4 */
// End offset: 0x800B1A54
// End Line: 5401

/* begin block 1.5 */
// Start line: 5404
// Start offset: 0x800B1A5C
// Variables:
// 		struct _G2AnimSection_Type *animSection; // $v0
/* end block 1.5 */
// End offset: 0x800B1A84
// End Line: 5409

/* begin block 1.6 */
// Start line: 5413
// Start offset: 0x800B1A9C
// Variables:
// 		struct _G2AnimSection_Type *animSection; // $v0
/* end block 1.6 */
// End offset: 0x800B1AC4
// End Line: 5418

/* begin block 1.7 */
// Start line: 5475
// Start offset: 0x800B1C20
/* end block 1.7 */
// End offset: 0x800B1C5C
// End Line: 5485

/* begin block 1.8 */
// Start line: 5487
// Start offset: 0x800B1C5C
/* end block 1.8 */
// End offset: 0x800B1CA0
// End Line: 5504

/* begin block 1.9 */
// Start line: 5514
// Start offset: 0x800B1CE8
// Variables:
// 		int i; // $s2
// 		struct _Instance *heldWeapon; // $s0
/* end block 1.9 */
// End offset: 0x800B1D80
// End Line: 5541

/* begin block 1.10 */
// Start line: 5548
// Start offset: 0x800B1D94
// Variables:
// 		struct _Instance *heldWeapon; // $v1
/* end block 1.10 */
// End offset: 0x800B1E5C
// End Line: 5576
/* end block 1 */
// End offset: 0x800B1EDC
// End Line: 5593

/* begin block 2 */
// Start line: 10927
/* end block 2 */
// End Line: 10928

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RazielPost(_Instance *instance, ulong Message, ulong Data)

{
  ulong uVar1;
  int iVar2;
  _Instance *instance_00;
  int iVar3;
  uint uVar4;
  code *NewProcess;
  int in_a3;
  ulong *puVar5;
  char *In;
  char *In_00;
  int reaverType;

  if ((undefined *)Message == &DAT_0010000a)
  {
    reaverType = 0;
    if (Data == 0)
    {
      iVar3 = 0x1b8;
      do
      {
        iVar2 = (int)&(instance->node).prev + iVar3;
        reaverType = reaverType + 1;
        *(undefined4 *)(iVar2 + 0x1c) = 0x800b0aac;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        iVar3 = iVar3 + 0x30;
      } while (reaverType < 3);
      InitAlgorithmicWings(instance);
      uVar1 = _CHAR____800d5650;
    }
    else
    {
      iVar3 = 0x1b8;
      do
      {
        iVar2 = (int)&(instance->node).prev + iVar3;
        reaverType = reaverType + 1;
        *(undefined4 *)(iVar2 + 0x1c) = 0x800b10b0;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        iVar3 = iVar3 + 0x30;
      } while (reaverType < 3);
      DeInitAlgorithmicWings(instance);
      razResetPauseTranslation(instance);
      uVar1 = _CHAR____800d5650;
    }
  }
  else
  {
    if (&DAT_0010000a < Message)
    {
      uVar1 = _CHAR____800d5650;
      if (Message == 0x200001)
      {
        if (((_BlockVramEntry_800d59a0._12_4_ & 0x40000) == 0) &&
            (reaverType = HealthCheckForLowHealth(), uVar1 = _CHAR____800d5650, reaverType == 0))
        {
          UpdateEngagementList((evCollideInstanceStatsData *)Data, (__Player *)&Raziel);
          uVar1 = _CHAR____800d5650;
        }
      }
      else
      {
        if (Message < 0x200002)
        {
          if ((undefined *)Message == &DAT_00100012)
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Query((_Instance *)Data, 4);
          }
          if (&DAT_00100012 < Message)
          {
            if ((undefined *)Message == &UNK_00100016)
            {
              razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x33, -200, -200, 0x78, 0x78,
                                Data << 0xc, 0xdac);
              _CHAR____800d57b0 = 0;
              uVar1 = _CHAR____800d5650;
              _CHAR____800d57ac = Data << 0xc;
            }
            else
            {
              if (&UNK_00100016 < Message)
              {
                if (Message != 0x200000)
                  goto LAB_800b1eb8;
                if ((_BlockVramEntry_800d59a0._12_4_ & 0x40000) == 0)
                {
                  _CHAR____800d55f0 = 0;
                }
                _CHAR____800d55b0 = _CHAR____800d55b0 & 0xffffffdf;
                uVar4 = 0xffffffbf;
              }
              else
              {
                if ((undefined *)Message != &DAT_00100013)
                  goto LAB_800b1eb8;
                if ((_Instance *)Data != _CHAR____800d5644)
                {
                  reaverType = razReaverOn();
                  if (reaverType == 0)
                  {
                    _CHAR____800d5600 = 0;
                  }
                  razReaverBladeOn();
                }
                uVar4 = 0xffffff7f;
              }
              _CHAR____800d55b0 = _CHAR____800d55b0 & uVar4;
              uVar1 = _CHAR____800d5650;
            }
          }
          else
          {
            if ((undefined *)Message != &DAT_00100010)
            {
              if ((undefined *)Message == &DAT_00100011)
              {
                /* WARNING: Subroutine does not return */
                EnMessageQueueData((__MessageQueue *)&CHAR____800d52ac, (int)&DAT_00100011, Data);
              }
              goto LAB_800b1eb8;
            }
            if (Data == 0)
            {
              if ((_CHAR____800d5574 & 0x40000000) != 0)
              {
                _CHAR____800d5574 = _CHAR____800d5574 & 0xbfffffff;
              }
            }
            else
            {
              if ((_CHAR____800d5574 & 0x40000000) == 0)
              {
                _CHAR____800d5574 = 0x40000000;
                ResetPhysics(instance, -0x10);
                /* WARNING: Subroutine does not return */
                SetPhysicsWallCrawlData(0, 0, 3, in_a3);
              }
            }
          }
        }
        else
        {
          if (Message == 0x4000001)
          {
            if (((_BlockVramEntry_800d59a0._12_4_ & 8) != 0) && ((_CHAR____800d55b0 & 2) == 0))
            {
              /* WARNING: Subroutine does not return */
              EnMessageQueueData((__MessageQueue *)&CHAR____800d52ac, 0x4000001, Data);
            }
          }
          else
          {
            if (Message < 0x4000002)
            {
              if (Message == 0x200004)
              {
                if ((_BlockVramEntry_800d59a0._12_4_ & 0x40000000) != 0)
                {
                  *(ulong *)&instance->collideInfo = Data;
                  *(undefined2 *)(Data + 0x2c) = 0;
                  RazielCollide(instance, (GameTracker *)&gameTrackerX);
                  instance_00 = razGetHeldItem();
                  COLLIDE_UpdateAllTransforms(instance_00, (SVECTOR *)((int)instance->collideInfo + 0x28));
                  uVar1 = _CHAR____800d5650;
                }
              }
              else
              {
                if (Message != 0x800024)
                  goto LAB_800b1eb8;
                _CHAR____800d5658 = *(undefined4 *)(Data + 4);
              }
            }
            else
            {
              if (Message == 0x4000006)
              {
                _CHAR____800d5650 = 0xb50;
                uVar1 = _CHAR____800d5650;
              }
              else
              {
                if (Message < 0x4000007)
                {
                  uVar1 = Data;
                  if (Message != 0x4000005)
                    goto LAB_800b1eb8;
                }
                else
                {
                  if (Message != 0x10002000)
                    goto LAB_800b1eb8;
                  razPlaneShift(instance);
                  uVar1 = _CHAR____800d5650;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      if ((undefined *)Message == &LAB_00040010_2)
      {
        NewProcess = StateHandlerDropAction;
      }
      else
      {
        if (&LAB_00040010_2 < Message)
        {
          if (Message == 0x40022)
          {
            _CHAR____800d57b4 = Data;
            return;
          }
          if (Message < 0x40023)
          {
            if ((undefined *)Message == &LAB_00040014_1)
            {
              debugRazielFlags1 = _CHAR____800d561c | Data;
              _CHAR____800d561c = debugRazielFlags1;
              RAZIEL_DebugHealthFillUp();
              if ((Data & 0x3fc00) == 0)
              {
                return;
              }
              if (_CHAR____800d5644 == (_Instance *)0x0)
              {
                return;
              }
              razReaverOn();
              reaverType = razGetReaverFromMask(Data);
              razReaverImbue(reaverType);
              return;
            }
            if (Message == 0x40019)
            {
              SetMana(Data);
              return;
            }
          }
          else
          {
            if ((undefined *)Message == &DAT_00100007)
            {
              puVar5 = *(ulong **)(Data + 4);
              debugRazielFlags1 = *puVar5;
              _CHAR____800d561c = debugRazielFlags1;
              reaverType = razInBaseArea(s_under_800cf860, 5);
              _CHAR____800d564c = 2;
              if (reaverType == 0)
              {
                _CHAR____800d564c = puVar5[1];
              }
              _CHAR____800d560c = *(undefined2 *)(puVar5 + 2);
              _CHAR____800d560e = *(undefined2 *)(puVar5 + 3);
              HUD_Setup_Chit_Count(puVar5[3]);
              _CHAR____800d5624 = *(undefined2 *)(puVar5 + 4);
              _CHAR____800d5626 = *(undefined2 *)((int)puVar5 + 0x12);
              _CHAR____800d5644 = (_Instance *)0x0;
              if ((_CHAR____800d561c & 8) != 0)
              {
                debugRazielFlags2 = 0;
              }
              _CHAR____800d57c8 = puVar5[5];
              if ((_CHAR____800d57c8 & 0x1000) == 0)
              {
                _CHAR____800d5610 = 100;
                _CHAR____800d5644 = (_Instance *)0x0;
                return;
              }
              _CHAR____800d5610 = GetMaxHealth();
              return;
            }
            if (&DAT_00100007 < Message)
            {
              if ((undefined *)Message == &DAT_00100008)
              {
                if ((_BlockVramEntry_800d59a0._12_4_ & 0x200000) != 0)
                {
                  RelocateConstrict((_SVector *)Data);
                }
                _CHAR____800d5760 = _CHAR____800d5760 + *(short *)Data;
                _CHAR____800d5762 = _CHAR____800d5762 + *(short *)(Data + 2);
                _CHAR____800d5764 = _CHAR____800d5764 + *(short *)(Data + 4);
                STREAM_MORPH_Relocate();
                return;
              }
            }
            else
            {
              if ((undefined *)Message == &DAT_00040024)
              {
                reaverType = SndTypeIsPlayingOrRequested(1);
                if (reaverType != 0)
                {
                  return;
                }
                SOUND_Play3dSound((_Position *)(DAT_800d0fd8 + 0x5c), 1, 0, 0x4b, 0xdac);
                return;
              }
            }
          }
        LAB_800b1eb8:
          /* WARNING: Subroutine does not return */
          EnMessageQueueData((__MessageQueue *)&CHAR____800d52ac, Message, Data);
        }
        if ((undefined **)Message == &PTR_00040006)
        {
          DrainHealth(Data);
          return;
        }
        if (&PTR_00040006 < Message)
        {
          if ((undefined *)Message == &LAB_0004000c_2)
          {
            if (Data == 0)
            {
              _CHAR____800d571c = StateHandlerIdle;
              _CHAR____800d55b0 = _CHAR____800d55b0 & 0xffffffef;
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffdffff;
              /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0, 0, 3, -0x11);
            }
            _CHAR____800d571c = StateHandlerPuppetShow;
            StateSwitchStateCharacterDataDefault((__CharacterState *)&CHAR____800d5218, StateHandlerPuppetShow, 0);
            InitAlgorithmicWings(instance);
            reaverType = 0;
            In_00 = &CHAR____800d52ac;
            In = &CHAR____800d5224;
            do
            {
              PurgeMessageQueue((__MessageQueue *)In);
              PurgeMessageQueue((__MessageQueue *)In_00);
              In_00 = (char *)&((__MessageQueue *)In_00)[2].Queue[0].Data;
              reaverType = reaverType + 1;
              In = (char *)&((__MessageQueue *)In)[2].Queue[0].Data;
            } while (reaverType < 3);
            GAMELOOP_Reset24FPS();
            instance_00 = razGetHeldWeapon();
            _CHAR____800d576c = HINT_GetCurrentHint();
            if (_CHAR____800d576c != -1)
            {
              HINT_KillSpecificHint(_CHAR____800d576c);
            }
            if (instance_00 == (_Instance *)0x0)
            {
              return;
            }
            if (instance_00 == _CHAR____800d5644)
            {
              return;
            }
            razSetFadeEffect(0, 0x1000, 10);
            return;
          }
          if (&LAB_0004000c_2 < Message)
          {
            if ((undefined *)Message == &LAB_00040010_1)
            {
              HealthInstantDeath(instance);
              return;
            }
          }
          else
          {
            if (Message == 0x40008)
            {
              DrainMana(Data);
              return;
            }
          }
          goto LAB_800b1eb8;
        }
        if ((undefined *)Message == &DAT_00040001)
        {
          instance->currentStreamUnitID = Data;
          instance->tface = (_TFace *)0x0;
          *(ulong *)(_CHAR____800d5620 + 0x38) = Data;
          *(undefined4 *)(_CHAR____800d5620 + 0xb4) = 0;
          if (_CHAR____800d5644 == (_Instance *)0x0)
          {
            return;
          }
          _CHAR____800d5644->currentStreamUnitID = Data;
          _CHAR____800d5644->tface = (_TFace *)0x0;
          return;
        }
        if ((undefined *)Message != &UNK_00040004)
          goto LAB_800b1eb8;
        G2EmulationSwitchAnimationCharacter((__CharacterState *)&CHAR____800d5218, 0x80, 0, 3, 1);
        NewProcess = StateHandlerCannedReaction;
      }
      StateSwitchStateCharacterData((__CharacterState *)&CHAR____800d5218, NewProcess, 0);
      uVar1 = _CHAR____800d5650;
    }
  }
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  /* WARNING: Read-only address (ram,0x800d5620) is written */
  _CHAR____800d5650 = uVar1;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SetStates(struct _Instance *instance /*$s4*/, struct GameTracker *GT /*$s7*/, long *controlCommand /*$s6*/, int AnalogLength /*$a3*/)
// line 5597, offset 0x800b1ef8
/* begin block 1 */
// Start line: 5598
// Start offset: 0x800B1EF8
// Variables:
// 		int i; // $s1
// 		int Event; // $s2
// 		int Data1; // $s3
// 		static unsigned long LastTime; // offset 0x0
// 		struct __Event *Ptr; // $v0

/* begin block 1.1 */
// Start line: 5708
// Start offset: 0x800B209C
// Variables:
// 		struct __Event *message; // $v0
/* end block 1.1 */
// End offset: 0x800B2188
// End Line: 5746

/* begin block 1.2 */
// Start line: 5871
// Start offset: 0x800B249C
/* end block 1.2 */
// End offset: 0x800B24B4
// End Line: 5873

/* begin block 1.3 */
// Start line: 5879
// Start offset: 0x800B24F8
/* end block 1.3 */
// End offset: 0x800B2558
// End Line: 5888
/* end block 1 */
// End offset: 0x800B2558
// End Line: 5890

/* begin block 2 */
// Start line: 11735
/* end block 2 */
// End Line: 11736

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SetStates(_Instance *instance, GameTracker *GT, long *controlCommand, int AnalogLength)

{
  code **ppcVar1;
  uint Data;
  __Event *Element;
  _Instance *Target;
  int ID;
  char *pcVar2;
  int iVar3;

  Data = GetRCnt(0xf2000000);
  iVar3 = 0;
  ID = 0;
  _LastTime_366 = Data & 0xffff | gameTimer << 0x10;
  LoopCounter = LoopCounter + 1;
  gameTracker.next = (_BlockVramEntry *)GT;
  gameTracker._4_4_ = (char *)controlCommand;
  do
  {
    while (true)
    {
      Element = DeMessageQueue((__MessageQueue *)(&CHAR____800d52ac + ID));
      if (Element == (__Event *)0x0)
        break;
      EnMessageQueue((__MessageQueue *)(&CHAR____800d5224 + ID), Element);
    }
    iVar3 = iVar3 + 1;
    ID = ID + 0x11c;
  } while (iVar3 < 3);
  if ((*(int *)&instance->offset != 0) || ((instance->offset).z != 0))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, 0x4000004, LoopCounter);
  }
  if (_CHAR____800d55dc != (_Instance *)0x0)
  {
    ID = SetMonsterHitData(_CHAR____800d55dc, (_Instance *)0x0, 0x1000,
                           (uint) * (ushort *)(_CHAR____800d565c + 0x20),
                           (uint) * (byte *)(_CHAR____800d565c + 0xf));
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, 0x2000002, ID);
  }
  if ((*(uint *)(DAT_800d0fd8 + 0x14) & 0x100) == 0)
  {
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x800000) != 0)
    {
      gameTracker._4_4_ = &CHAR____800d572c;
      /* WARNING: Subroutine does not return */
      EnMessageQueueData((__MessageQueue *)&CHAR____800d5224, 0, 0);
    }
    GetControllerMessages(controlCommand);
    do
    {
      Element = DeMessageQueue((__MessageQueue *)&CHAR____800d5694);
      if (Element == (__Event *)0x0)
      {
        Data = ProcessMovement(instance, controlCommand, GT);
        if (Data == 0)
        {
          ID = 0;
        }
        else
        {
          ID = 0x10000000;
          if ((Data & 0x1000) != 0)
          {
            ID = 0x1000001;
          }
        }
        /* WARNING: Subroutine does not return */
        EnMessageQueueData((__MessageQueue *)&CHAR____800d5224, ID, Data);
      }
      ID = Element->ID;
      if ((ID == -0x80000000) &&
          (((_CHAR____800d55f0 & 0x681f) != 0 ||
            (((_CHAR____800d55f0 & 0x20) != 0 &&
              (Target = razGetHeldItem(), Target == (_Instance *)0x0))))))
      {
        ID = 0x2000000;
      }
    } while (ID == 0);
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)&CHAR____800d5224, ID, 0);
  }
  razSetPlayerEvent();
  G2EmulatePlayAnimation((__CharacterState *)&CHAR____800d5218);
  pcVar2 = &Raziel;
  ID = 0;
  do
  {
    ppcVar1 = (code **)(pcVar2 + 0xc);
    pcVar2 = pcVar2 + 0x11c;
    iVar3 = ID + 1;
    (**ppcVar1)(&CHAR____800d5218, ID);
    ID = iVar3;
  } while (iVar3 < 3);
  if (*(char *)((int)&gameTracker.next[0x10].time + 1) == '\x01')
  {
    PhysicsMode.next = (_BlockVramEntry *)&DAT_00000003;
  }
  ProcessPhysics((__Player *)&Raziel, (__CharacterState *)&CHAR____800d5218, 0, (int)PhysicsMode.next);
  if ((*(uint *)gameTracker._4_4_ & LONG_ARRAY_800cf57c[0]) == 0)
  {
    _CHAR____800d5758 = _CHAR____800d5758 + 1;
    if (_CHAR____800d5758 < 6)
    {
      if (((_CHAR____800d55f0 & 0x40) != 0) && ((_CHAR____800d5574 & 0x2000000) == 0))
      {
        /* WARNING: Subroutine does not return */
        EnMessageQueueData((__MessageQueue *)&CHAR____800d5224, 0x1000001, 0);
      }
    }
    else
    {
      if (_CHAR____800d5758 == 6)
      {
        _CHAR____800d55e4 = 0;
        _CHAR____800d55e0 = 0;
      }
    }
    _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffffb;
  }
  else
  {
    _CHAR____800d5758 = 0;
    if (((_CHAR____800d55f0 & 0x40) != 0) && ((_CHAR____800d5574 & 0x2000000) == 0))
    {
      /* WARNING: Subroutine does not return */
      EnMessageQueueData((__MessageQueue *)&CHAR____800d5224, 0x1000001, 0);
    }
    _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 4;
    if ((_CHAR____800d55f0 & 0x40) == 0)
    {
      _CHAR____800d55e0 = 0;
    }
    else
    {
      _CHAR____800d55e0 = *(undefined4 *)(_CHAR____800d55ec + 0x30);
    }
  }
  _BlockVramEntry_800d59a0._8_4_ = 0xffffffff;
  _CHAR____800d5580 = ((instance->position).x - (instance->oldPos).x) - (instance->offset).x;
  _CHAR____800d5582 = ((instance->position).y - (instance->oldPos).y) - (instance->offset).y;
  _CHAR____800d5584 = ((instance->position).z - (instance->oldPos).z) - (instance->offset).z;
  StateGovernState((__CharacterState *)&CHAR____800d5218, 3);
  if (((vmClock & 0x800U) != 0) && ((_BlockVramEntry_800d59a0._12_4_ & 0x1000000) == 0))
  {
    ProcessHealth(instance);
  }
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x20000) != 0)
  {
    if ((_CHAR____800d55f0 & 0x400) == 0)
    {
      Target = (_Instance *)0x0;
      if ((_CHAR____800d55b0 & 0x10) == 0)
        goto LAB_800b2424;
    }
    else
    {
      Target = *(_Instance **)(_CHAR____800d55ec + 0x50);
    }
    AlgorithmicNeck(instance, Target);
  }
LAB_800b2424:
  if (((_BlockVramEntry_800d59a0._12_4_ & 0x200000) != 0) && (ULONG_800d120c != 0))
  {
    ProcessConstrict();
  }
  if (_CHAR____800d5730 != 0)
  {
    ProcessEffects(instance);
  }
  ProcessInteractiveMusic(instance);
  ProcessSpecialAbilities(instance);
  if (((_CHAR____800d55b0 & 0x40) != 0) && (ID = RAZIEL_OkToShift(), ID != 0))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(_CHAR____800d55e8, 0x11);
  }
  if (_CHAR____800d55e8 != (_Instance *)0x0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(_CHAR____800d55e8, 0x11);
  }
  _CHAR____800d55e8 = (_Instance *)0x0;
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessConstrict()
// line 5900, offset 0x800b2588
/* begin block 1 */
// Start line: 5901
// Start offset: 0x800B2588

/* begin block 1.1 */
// Start line: 5942
// Start offset: 0x800B268C
// Variables:
// 		int i; // $s0

/* begin block 1.1.1 */
// Start line: 5990
// Start offset: 0x800B2754
// Variables:
// 		int thisIndex; // $v1
// 		int nextIndex; // $v0
/* end block 1.1.1 */
// End offset: 0x800B27B8
// End Line: 6011
/* end block 1.1 */
// End offset: 0x800B284C
// End Line: 6034
/* end block 1 */
// End offset: 0x800B284C
// End Line: 6065

/* begin block 2 */
// Start line: 12443
/* end block 2 */
// End Line: 12444

/* begin block 3 */
// Start line: 12446
/* end block 3 */
// End Line: 12447

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void ProcessConstrict(void)

{
  ushort uVar1;
  short *psVar2;
  ulong uVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;

  if ((_CHAR____800d5638 & 1) != 0)
  {
    _CHAR____800d5638 = _CHAR____800d5638 & 0xfffe | 4;
    _CHAR____800d562c = 0;
    _CHAR____800d562e = 0;
    _CHAR____800d563c = 0;
    _CHAR____800d5640 = 0;
    _CHAR____800d563a = 0;
  }
  _CHAR____800d563c = _CHAR____800d563c + (int)*(short *)(_CHAR____800d5218 + 0x5c);
  _CHAR____800d5640 = _CHAR____800d5640 + (int)*(short *)(_CHAR____800d5218 + 0x5e);
  *(undefined2 *)((int)_CHAR____800d562c * 4 + _CHAR____800d5628) =
      *(undefined2 *)(_CHAR____800d5218 + 0x5c);
  *(undefined2 *)((int)_CHAR____800d562c * 4 + _CHAR____800d5628 + 2) =
      *(undefined2 *)(_CHAR____800d5218 + 0x5e);
  _CHAR____800d562c = _CHAR____800d562c + 1;
  if (0x1f < _CHAR____800d562c)
  {
    _CHAR____800d562c = 0;
  }
  uVar1 = _CHAR____800d5638;
  if (((_CHAR____800d5638 & 4) != 0) &&
      (uVar1 = _CHAR____800d5638 & 0xffdf, _CHAR____800d562e == _CHAR____800d562c))
  {
    uVar1 = _CHAR____800d5638 | 0x22;
  }
  _CHAR____800d5638 = uVar1;
  iVar6 = 0;
  if ((_CHAR____800d5638 & 2) != 0)
  {
    _CHAR____800d5630 = (short)(_CHAR____800d563c >> 5);
    _CHAR____800d5632 = (short)(_CHAR____800d5640 >> 5);
    _CHAR____800d5634 = *(short *)(_CHAR____800d5218 + 0x60) + 0x100;
    psVar2 = (short *)((int)_CHAR____800d562c * 4 + _CHAR____800d5628);
    _CHAR____800d563c = _CHAR____800d563c - (int)*psVar2;
    _CHAR____800d563a = 1;
    _CHAR____800d5640 = _CHAR____800d5640 - (int)psVar2[1];
    do
    {
      psVar2 = (short *)(iVar6 * 4 + _CHAR____800d5628);
      uVar3 = MATH3D_SquareLength((int)*psVar2 - (int)_CHAR____800d5630,
                                  (int)psVar2[1] - (int)_CHAR____800d5632, 0);
      if (0xc7ffe < uVar3 - 1)
      {
        _CHAR____800d563a = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
    if (_CHAR____800d563a != 0)
    {
      iVar6 = (int)_CHAR____800d562c + -1;
      iVar5 = iVar6 * 4;
      if (iVar6 < 0)
      {
        iVar5 = 0x7c;
      }
      psVar2 = (short *)((int)_CHAR____800d562c * 4 + _CHAR____800d5628);
      puVar4 = (undefined *)
          MATH3D_SquareLength((int)*(short *)(iVar5 + _CHAR____800d5628) - (int)*psVar2,
                              (int)((short *)(iVar5 + _CHAR____800d5628))[1] - (int)psVar2[1], 0);
      if (&UNK_0015f900 < puVar4)
      {
        _CHAR____800d563a = 0;
      }
      if (_CHAR____800d563a != 0)
      {
        _CHAR____800d563c = 0;
        _CHAR____800d5640 = 0;
        _CHAR____800d5638 = _CHAR____800d5638 & 0xfffd | 0x1c;
        _CHAR____800d562e = _CHAR____800d562c;
        if (1 < _CHAR____800d563a)
        {
          DAT_800d10f0 = DAT_800d10f0 | 4;
          FX_EndConstrict(1, (_Instance *)0x0);
          _CHAR____800d5638 = 1;
        }
        _CHAR____800d563a = _CHAR____800d563a + 1;
        return;
      }
    }
    _CHAR____800d563a = 1;
    _CHAR____800d5638 = _CHAR____800d5638 & 0xffef;
    FX_EndConstrict(0, (_Instance *)0x0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RelocateConstrict(struct _SVector *offset /*$a3*/)
// line 6068, offset 0x800b285c
/* begin block 1 */
// Start line: 6069
// Start offset: 0x800B285C
// Variables:
// 		int i; // $a2
/* end block 1 */
// End offset: 0x800B29B4
// End Line: 6097

/* begin block 2 */
// Start line: 12827
/* end block 2 */
// End Line: 12828

/* begin block 3 */
// Start line: 12832
/* end block 3 */
// End Line: 12833

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RelocateConstrict(_SVector *offset)

{
  int iVar1;
  int iVar2;

  _CHAR____800d563c = 0;
  _CHAR____800d5640 = 0;
  if ((_CHAR____800d5638 & 2) == 0)
  {
    iVar1 = (int)_CHAR____800d562e + 1;
    if (iVar1 == 0x20)
    {
      iVar1 = 0;
    }
    if (iVar1 != (int)_CHAR____800d562c)
    {
      do
      {
        iVar2 = iVar1 * 4;
        *(short *)(iVar2 + _CHAR____800d5628) = *(short *)(iVar2 + _CHAR____800d5628) + offset->x;
        *(short *)(iVar2 + _CHAR____800d5628 + 2) =
            *(short *)(iVar2 + _CHAR____800d5628 + 2) + offset->y;
        _CHAR____800d563c = _CHAR____800d563c + *(short *)(iVar2 + _CHAR____800d5628);
        iVar1 = iVar1 + 1;
        _CHAR____800d5640 = _CHAR____800d5640 + ((short *)(iVar2 + _CHAR____800d5628))[1];
        if (iVar1 == 0x20)
        {
          iVar1 = 0;
        }
      } while (iVar1 != (int)_CHAR____800d562c);
      return;
    }
  }
  else
  {
    iVar2 = 0;
    iVar1 = 0;
    do
    {
      *(short *)(iVar1 + _CHAR____800d5628) = *(short *)(iVar1 + _CHAR____800d5628) + offset->x;
      *(short *)(iVar1 + _CHAR____800d5628 + 2) =
          *(short *)(iVar1 + _CHAR____800d5628 + 2) + offset->y;
      _CHAR____800d563c = _CHAR____800d563c + *(short *)(iVar1 + _CHAR____800d5628);
      iVar2 = iVar2 + 1;
      _CHAR____800d5640 = _CHAR____800d5640 + ((short *)(iVar1 + _CHAR____800d5628))[1];
      iVar1 = iVar2 * 4;
    } while (iVar2 < 0x20);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessEffects(struct _Instance *instance /*$s0*/)
// line 6097, offset 0x800b29bc
/* begin block 1 */
// Start line: 6098
// Start offset: 0x800B29BC
// Variables:
// 		struct _Instance *heldInst; // $s2

/* begin block 1.1 */
// Start line: 6149
// Start offset: 0x800B2AE0
// Variables:
// 		int step; // $v1
/* end block 1.1 */
// End offset: 0x800B2BB8
// End Line: 6188
/* end block 1 */
// End offset: 0x800B2BB8
// End Line: 6190

/* begin block 2 */
// Start line: 12903
/* end block 2 */
// End Line: 12904

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessEffects(_Instance *instance)

{
  uint uVar1;
  _Instance *p_Var2;
  int iVar3;
  int iVar4;
  _Instance *p_Var5;

  p_Var2 = razGetHeldItem();
  if (((_CHAR____800d5730 & 4) != 0) &&
      (iVar3 = razUpdateSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c), iVar3 == 0))
  {
    /* WARNING: Subroutine does not return */
    SndEndLoop(_CHAR____800d577c);
  }
  if (((_CHAR____800d5730 & 8) != 0) &&
      (iVar3 = razUpdateSoundRamp(instance, (_SoundRamp *)&CHAR____800d5794), iVar3 == 0))
  {
    /* WARNING: Subroutine does not return */
    SndEndLoop(_CHAR____800d5794);
  }
  p_Var5 = instance;
  if (((((_CHAR____800d5730 & 2) != 0) &&
        (p_Var5 = _CHAR____800d5688, _CHAR____800d5688 == (_Instance *)0x0)) &&
       (p_Var5 = instance, p_Var2 != (_Instance *)0x0)) &&
      (p_Var5 = p_Var2, 2 < _CHAR____800d5600 - 1U))
  {
    _CHAR____800d5730 = _CHAR____800d5730 & 0xfffffffd;
    _CHAR____800d5688 = (_Instance *)0x0;
    p_Var5 = instance;
  }
  uVar1 = _CHAR____800d5730;
  if ((_CHAR____800d5730 & 1) != 0)
  {
    _CHAR____800d573c = _CHAR____800d573c + _CHAR____800d5738 * DAT_800d11ec;
    iVar3 = _CHAR____800d573c;
    if (_CHAR____800d573c < 0)
    {
      iVar3 = _CHAR____800d573c + 0xfff;
    }
    iVar3 = iVar3 >> 0xc;
    iVar4 = (uint)(ushort)p_Var5->fadeValue + iVar3;
    p_Var5->fadeValue = (short)iVar4;
    uVar1 = _CHAR____800d5730;
    if (iVar3 < 1)
    {
      if ((iVar3 < 0) && (iVar4 * 0x10000 >> 0x10 < (int)_CHAR____800d5736))
      {
        p_Var5->fadeValue = _CHAR____800d5736;
        uVar1 = _CHAR____800d5730 & 0xfffffffe;
        if (p_Var5 == _CHAR____800d5688)
        {
          _CHAR____800d5688 = (_Instance *)0x0;
          uVar1 = _CHAR____800d5730 & 0xfffffffc;
        }
      }
    }
    else
    {
      if ((int)_CHAR____800d5736<iVar4 * 0x10000>> 0x10)
      {
        p_Var5->fadeValue = _CHAR____800d5736;
        uVar1 = _CHAR____800d5730 & 0xfffffffe;
        if (p_Var5 == _CHAR____800d5688)
        {
          uVar1 = _CHAR____800d5730 & 0xfffffffc;
        }
      }
    }
  }
  _CHAR____800d5730 = uVar1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessHints()
// line 6194, offset 0x800b2bd0
/* begin block 1 */
// Start line: 6195
// Start offset: 0x800B2BD0
// Variables:
// 		long hint; // $s0
/* end block 1 */
// End offset: 0x800B2CF8
// End Line: 6256

/* begin block 2 */
// Start line: 13103
/* end block 2 */
// End Line: 13104

void ProcessTimers(_Instance *instance)

{
  short hintNumber;
  long lVar1;
  int iVar2;

  lVar1 = HINT_GetCurrentHint();
  if ((__Force_800d72a0.LinearForce.z & 0x2000U) == 0)
  {
    if ((__Force_800d72a0.LinearForce.y & 0x2000U) != 0)
    {
      if (lVar1 == -1)
      {
        HINT_StartHint(0xc);
      }
      if ((lVar1 == 0xc) && (DAT_800d6d04 == StateHandlerGlyphs))
      {
        HINT_KillSpecificHint(0xc);
        HINT_StartHint(0x28);
      }
      if ((lVar1 == 0x28) && (DAT_800d6d04 != StateHandlerGlyphs))
      {
        HINT_KillSpecificHint(0x28);
        HINT_StartHint(0xc);
      }
      goto LAB_800b2ca4;
    }
    iVar2 = 0xc;
  LAB_800b2c94:
    hintNumber = (short)iVar2;
    if (lVar1 != iVar2)
      goto LAB_800b2ca4;
  }
  else
  {
    hintNumber = 0xc;
    if (lVar1 != 0xc)
    {
      iVar2 = 0x28;
      goto LAB_800b2c94;
    }
  }
  HINT_KillSpecificHint(hintNumber);
LAB_800b2ca4:
  if ((__Force_800d72a0.LinearForce.z & 0x10000U) == 0)
  {
    if ((__Force_800d72a0.LinearForce.y & 0x10000U) == 0)
    {
      if (lVar1 == 0x20)
      {
        HINT_KillSpecificHint(0x20);
      }
    }
    else
    {
      if (lVar1 == -1)
      {
        HINT_StartHint(0x20);
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessInteractiveMusic(struct _Instance *instance /*$a0*/)
// line 6261, offset 0x800b2d08
/* begin block 1 */
// Start line: 6262
// Start offset: 0x800B2D08
// Variables:
// 		struct Level *level; // $s1

/* begin block 1.1 */
// Start line: 6279
// Start offset: 0x800B2DB4
/* end block 1.1 */
// End offset: 0x800B2DD8
// End Line: 6286
/* end block 1 */
// End offset: 0x800B2EA4
// End Line: 6335

/* begin block 2 */
// Start line: 13237
/* end block 2 */
// End Line: 13238

void ProcessInteractiveMusic(_Instance *instance)

{
  /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessTimers(struct _Instance *instance /*$s3*/)
// line 6339, offset 0x800b2eb8
/* begin block 1 */
// Start line: 13393
/* end block 1 */
// End Line: 13394

/* begin block 2 */
// Start line: 13394
/* end block 2 */
// End Line: 13395

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessTimers(_Instance *instance)

{
  char *sound;
  int sfx;
  int startPitch;
  int local_30;

  if ((0 < _CHAR____800d575c) &&
      (_CHAR____800d575c = _CHAR____800d575c - DAT_800d11ec, _CHAR____800d575c < 1))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, (int)&DAT_00100015, -_CHAR____800d575c);
  }
  if ((int)_CHAR____800d57ac < 1)
  {
    return;
  }
  if (0 < (int)_CHAR____800d57ac - DAT_800d11ec)
  {
    _CHAR____800d57ac = (undefined *)((int)_CHAR____800d57ac - DAT_800d11ec);
    return;
  }
  _CHAR____800d57ac = (undefined *)0x0;
  switch (_CHAR____800d57b0)
  {
  case 1:
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x13, 1000, 1000, 0x78, 0x78, 0x1000, 0xdac);
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d5794, 0x14, 0x406, 0x406, 0x78, 0x78, 0x1000,
                      0xdac);
    _CHAR____800d57ac = (undefined *)0x1e000;
    _CHAR____800d57b0 = 2;
    goto LAB_800b3110;
  case 2:
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0x13, 1000, 1000, 0x78, 0, 0x3c000, 0xdac);
    sound = &CHAR____800d5794;
    sfx = 0x14;
    startPitch = 0x406;
    local_30 = 0x406;
    goto LAB_800b3360;
  case 3:
    if (_CHAR____800d577c != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d577c);
    }
    _CHAR____800d577c = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0xd, 0, 0, 100, 100, 0x1000, 0xdac);
    _CHAR____800d57ac = &DAT_0000a000;
    _CHAR____800d57b0 = 4;
    break;
  case 4:
    if (_CHAR____800d5794 != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d5794);
    }
    _CHAR____800d5794 = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d5794, 0xd, 0x32, 0x32, 0x5f, 0x5f, 0x1000, 0xdac);
    _CHAR____800d57ac = (undefined *)0x7000;
    _CHAR____800d57b0 = 5;
  LAB_800b3110:
    _CHAR____800d5730 = _CHAR____800d5730 | 8;
    break;
  case 5:
    if (_CHAR____800d577c != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d577c);
    }
    _CHAR____800d577c = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0xd, -0x14, -0x14, 0x50, 0x50, 0x1000,
                      0xdac);
    _CHAR____800d57ac = (undefined *)0x8000;
    _CHAR____800d57b0 = 6;
    break;
  case 6:
    if (_CHAR____800d5794 != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d5794);
    }
    _CHAR____800d5794 = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d5794, 0xd, 100, 100, 0x4b, 0x4b, 0x1000, 0xdac);
    _CHAR____800d57ac = &DAT_0000a000;
    _CHAR____800d57b0 = 7;
    break;
  case 7:
    if (_CHAR____800d577c != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d577c);
    }
    _CHAR____800d577c = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d577c, 0xd, -100, -100, 0x41, 0x41, 0x1000, 0xdac);
    _CHAR____800d57ac = &DAT_00005000;
    _CHAR____800d57b0 = 8;
    break;
  case 8:
    if (_CHAR____800d5794 != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d5794);
    }
    _CHAR____800d5794 = 0;
    razSetupSoundRamp(instance, (_SoundRamp *)&CHAR____800d5794, 0xd, 0x1e, 0x1e, 0x3c, 0x3c, 0x1000, 0xdac);
    _CHAR____800d57ac = &DAT_0000a000;
    _CHAR____800d57b0 = 9;
    break;
  case 9:
    if (_CHAR____800d577c != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d577c);
    }
    _CHAR____800d577c = 0;
    if (_CHAR____800d5794 != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d5794);
    }
    _CHAR____800d5794 = 0;
    _CHAR____800d5730 = _CHAR____800d5730 & 0xfffffff3;
    break;
  case 10:
    sound = &CHAR____800d577c;
    sfx = 0x33;
    startPitch = -200;
    local_30 = -200;
  LAB_800b3360:
    razSetupSoundRamp(instance, (_SoundRamp *)sound, sfx, startPitch, local_30, 0x78, 0, 0x3c000, 0xdac);
    _CHAR____800d57ac = (undefined *)0x0;
    _CHAR____800d57b0 = 0;
    break;
  default:
    if (_CHAR____800d577c != 0)
    {
      /* WARNING: Subroutine does not return */
      SndEndLoop(_CHAR____800d577c);
    }
    _CHAR____800d57ac = (undefined *)0x0;
    return;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SetTimer(int ticks /*$a0*/)
// line 6444, offset 0x800b33ac
/* begin block 1 */
// Start line: 13615
/* end block 1 */
// End Line: 13616

/* begin block 2 */
// Start line: 13616
/* end block 2 */
// End Line: 13617

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetTimer(int ticks)

{
  _CHAR____800d575c = ticks << 0xc;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessSpecialAbilities(struct _Instance *instance /*$s1*/)
// line 6452, offset 0x800b33bc
/* begin block 1 */
// Start line: 6453
// Start offset: 0x800B33BC
// Variables:
// 		unsigned long reaver; // $s0

/* begin block 1.1 */
// Start line: 6460
// Start offset: 0x800B33EC
// Variables:
// 		unsigned long temp; // $a0
/* end block 1.1 */
// End offset: 0x800B340C
// End Line: 6469

/* begin block 1.2 */
// Start line: 6493
// Start offset: 0x800B3450
// Variables:
// 		struct Object *soulReaverOb; // $a1

/* begin block 1.2.1 */
// Start line: 6497
// Start offset: 0x800B3460
/* end block 1.2.1 */
// End offset: 0x800B3460
// End Line: 6497
/* end block 1.2 */
// End offset: 0x800B3460
// End Line: 6497

/* begin block 1.3 */
// Start line: 6518
// Start offset: 0x800B34B8
// Variables:
// 		struct Level *level; // $a1
/* end block 1.3 */
// End offset: 0x800B351C
// End Line: 6529
/* end block 1 */
// End offset: 0x800B3560
// End Line: 6548

/* begin block 2 */
// Start line: 13631
/* end block 2 */
// End Line: 13632

/* begin block 3 */
// Start line: 13635
/* end block 3 */
// End Line: 13636

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessSpecialAbilities(_Instance *instance)

{
  int Data;
  _Instance *soulReaver;
  uint reaverMask;

  if ((_CHAR____800d561c & 8) == 0)
  {
    if (_CHAR____800d5644 != (_Instance *)0x0)
    {
      INSTANCE_UnlinkFromParent(_CHAR____800d5644);
      INSTANCE_KillInstance(_CHAR____800d5644);
      _CHAR____800d5644 = (_Instance *)0x0;
      _CHAR____800d5648 = 0;
      debugRazielFlags2 = 0;
      _CHAR____800d5600 = 0;
    }
  }
  else
  {
    if (debugRazielFlags2 == 0)
    {
      Data = 1;
      if (_CHAR____800d564c == 1)
      {
        Data = 2;
        debugRazielFlags2 = 0x800;
      }
      else
      {
        debugRazielFlags2 = 0x400;
      }
    }
    else
    {
      reaverMask = 1 << (_CHAR____800d5648 + 9U & 0x1f);
      if (reaverMask != debugRazielFlags2)
      {
        reaverMask = debugRazielFlags2 & ~reaverMask;
        debugRazielFlags2 = reaverMask;
      }
      Data = razGetReaverFromMask(reaverMask);
    }
    if (_CHAR____800d5644 == (_Instance *)0x0)
    {
      if (DebugMenuLine_800c8828.upper != 0)
      {
        soulReaver = INSTANCE_BirthObject(instance, (Object *)DebugMenuLine_800c8828.upper, 0);
        razReaverPickup(instance, soulReaver);
        RAZIEL_DebugHealthFillUp();
      }
    }
    else
    {
      if (_CHAR____800d5648 != Data)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(_CHAR____800d5644, 0x800103, Data);
      }
      if (Data == 6)
      {
        /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID(instance->currentStreamUnitID);
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetControllerMessages(long *controlCommand /*$s0*/)
// line 6582, offset 0x800b3574
/* begin block 1 */
// Start line: 6583
// Start offset: 0x800B3574
/* end block 1 */
// End offset: 0x800B3768
// End Line: 6637

/* begin block 2 */
// Start line: 13895
/* end block 2 */
// End Line: 13896

int GetControllerMessages(long *controlCommand)

{
  int ID;
  undefined *ID_00;

  ID = -0x80000000;
  if (((controlCommand[1] & LONG_800cf568) != 0) ||
      (ID = 0x20000000, (controlCommand[2] & LONG_800cf568) != 0))
  {
    /* WARNING: Subroutine does not return */
    EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, ID, 0);
  }
  if ((controlCommand[1] & LONG_800cf564) == 0)
  {
    if ((controlCommand[2] & LONG_800cf564) == 0)
    {
      if ((controlCommand[1] & LONG_800cf56c) == 0)
      {
        if ((controlCommand[2] & LONG_800cf56c) == 0)
        {
          if ((controlCommand[1] & LONG_ARRAY_800cf57c[0]) == 0)
          {
            if ((controlCommand[2] & LONG_ARRAY_800cf57c[0]) == 0)
            {
              if ((controlCommand[1] & LONG_800cf578) == 0)
              {
                if ((controlCommand[2] & LONG_800cf578) == 0)
                {
                  if ((controlCommand[1] & LONG_800cf584) == 0)
                  {
                    if ((controlCommand[2] & LONG_800cf584) == 0)
                    {
                      if (((controlCommand[1] & RazielCommands) != 0) &&
                          (ID = STREAM_IsMorphInProgress(), ID == 0))
                      {
                        /* WARNING: Subroutine does not return */
                        EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, (int)&DAT_80000010, 0);
                      }
                      return 0;
                    }
                    ID_00 = (undefined *)0x20000020;
                  }
                  else
                  {
                    ID_00 = &DAT_80000020;
                  }
                  /* WARNING: Subroutine does not return */
                  EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, (int)ID_00, 0);
                }
                ID_00 = (undefined *)0x20000008;
              }
              else
              {
                ID_00 = &DAT_80000008;
              }
              /* WARNING: Subroutine does not return */
              EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, (int)ID_00, 0);
            }
            ID_00 = (undefined *)0x20000004;
          }
          else
          {
            ID_00 = &DAT_80000004;
          }
          /* WARNING: Subroutine does not return */
          EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, (int)ID_00, 0);
        }
        ID = 0x20000001;
      }
      else
      {
        ID = -0x7fffffff;
      }
      /* WARNING: Subroutine does not return */
      EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, ID, 0);
    }
    ID_00 = (undefined *)0x20000002;
  }
  else
  {
    ID_00 = &DAT_80000002;
  }
  /* WARNING: Subroutine does not return */
  EnMessageQueueData((__MessageQueue *)&CHAR____800d5694, (int)ID_00, 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ RazielAdditionalCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
// line 6721, offset 0x800b377c
/* begin block 1 */
// Start line: 6722
// Start offset: 0x800B377C
// Variables:
// 		int rc; // $s0
// 		int Mode; // $s0
// 		short Height; // $a1

/* begin block 1.1 */
// Start line: 6753
// Start offset: 0x800B37F8
/* end block 1.1 */
// End offset: 0x800B38A0
// End Line: 6773

/* begin block 1.2 */
// Start line: 6785
// Start offset: 0x800B38E0
// Variables:
// 		struct evPhysicsEdgeData *Data; // $s1
/* end block 1.2 */
// End offset: 0x800B39EC
// End Line: 6818

/* begin block 1.3 */
// Start line: 6836
// Start offset: 0x800B3A00
// Variables:
// 		struct evPhysicsSwimData *swimData; // $s1
// 		struct _Instance *Inst; // $s0
/* end block 1.3 */
// End offset: 0x800B3AF0
// End Line: 6876

/* begin block 1.4 */
// Start line: 6967
// Start offset: 0x800B3C18
/* end block 1.4 */
// End offset: 0x800B3C5C
// End Line: 6972
/* end block 1 */
// End offset: 0x800B3C5C
// End Line: 6974

/* begin block 2 */
// Start line: 14234
/* end block 2 */
// End Line: 14235

/* begin block 3 */
// Start line: 14239
/* end block 3 */
// End Line: 14240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RazielAdditionalCollide(_Instance *instance, GameTracker *gameTracker)

{
  short *psVar1;
  uint uVar2;
  int Data;
  evPhysicsEdgeData *Data_00;
  _Instance *Inst;
  ushort uVar3;
  int local_30;

  uVar2 = _BlockVramEntry_800d59a0._12_4_ & 8;
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x2000) != 0)
  {
    local_30 = 0x100;
    Data = SetPhysicsDropOffData(0, -0x60, (int)_CHAR____800d5608, (int)_CHAR____800d5650, 0x100);
    PhysicsCheckDropOff(instance, Data, 2);
  }
  if (uVar2 == 0)
  {
    instance->oldTFace = (_TFace *)0x0;
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
  }
  else
  {
    uVar3 = 0x80;
    if (aadMem._3_1_ == '\x01')
    {
      uVar3 = 0x40;
    }
    Data = (uint)uVar3 << 0x10;
    if ((int)(short)uVar3 < (int)(instance->oldPos).z - (int)(instance->position).z)
    {
      Data = ((uint)(ushort)(instance->oldPos).z - (uint)(ushort)(instance->position).z) * 0x10000;
    }
    local_30 = 0;
    Data = SetPhysicsGravityData((int)*(short *)(instance->matrix[1].t + 2) - instance->matrix->t[2],
                                 Data >> 0x10, 0, 0, 0, (int)_CHAR____800d5650);
    uVar2 = PhysicsCheckGravity(instance, Data, 7);
    if ((uVar2 & 1) == 0)
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 & 0xfffffffb;
    }
    else
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 | 4;
    }
    FX_UpdateInstanceWaterSplit(instance);
  }
  if (((_BlockVramEntry_800d59a0._12_4_ & 0x400) != 0) && (_CHAR____800d5600 != 3))
  {
    local_30 = -0xc4;
    Data_00 = (evPhysicsEdgeData *)
        SetPhysicsEdgeData(400, -0x100, 0x90, 0, -0xc4, 0x1f2, (_SVector *)&CHAR____800d55b4,
                           (_SVector *)&CHAR____800d55bc, (_SVector *)&CHAR____800d55d4);
    uVar2 = PhysicsCheckEdgeGrabbing(instance, gameTracker, (int)Data_00, 3);
    if ((uVar2 & 6) == 6)
    {
      local_30 = 0;
      SetPhysics(instance, 0, 0, 0, 0);
      _CHAR____800d55b0 = _CHAR____800d55b0 | 2;
      if (gameTracker._16_4_ != 0)
      {
        G2Anim_DisableController(&instance->anim, 1, 0xe);
        psVar1 = (short *)(gameTracker._16_4_ + 4);
        gameTracker._16_4_ = 0;
        (instance->rotation).z = (instance->rotation).z + *psVar1;
      }
      if (Data_00 != (evPhysicsEdgeData *)0x0)
      {
        PhysicsDefaultEdgeGrabResponse(instance, Data_00, 0);
      }
    }
    else
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 & 0xfffffffd;
    }
    if ((uVar2 & 2) == 0)
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 & 0xfffffffe;
    }
    else
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 | 1;
    }
  }
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x100) == 0)
  {
    WaterStatus = 0x20;
    FX_UpdateInstanceWaterSplit(instance);
  }
  else
  {
    Inst = razGetHeldWeapon();
    local_30 = 0x70;
    Data = SetPhysicsSwimData(_CHAR____800d5574 >> 0x12 & 1, (_SVector *)&CHAR____800d5580, 0x100,
                              0x1a0, 0x70);
    WaterStatus = PhysicsCheckSwim(instance, Data, 3);
    if (((*(ushort *)(Data + 0x10) & 0x10) != 0) && (Inst != (_Instance *)0x0))
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(Inst, 4);
    }
    if (((*(ushort *)(Data + 0x10) & 0x20) != 0) && (Inst != (_Instance *)0x0))
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(Inst, 4);
    }
    if (((PhysicsMode.next == (_BlockVramEntry *)((int)&mainMenuScreen + 1)) && (instance->zVel < 0)) && (-0x96 < (int)*(short *)(Data + 0xe) - (int)*(short *)(Data + 0xc)))
    {
      ResetPhysics(instance, 0);
    }
  }
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x8000) != 0)
  {
    local_30 = -0x68;
    Data = SetPhysicsEdgeData(0x100, -0x100, 0x50, 0, -0x68, 0, (_SVector *)&CHAR____800d55b4,
                              (_SVector *)&CHAR____800d55bc, (_SVector *)&CHAR____800d55d4);
    uVar2 = PhysicsCheckBlockers(instance, gameTracker, Data, 3);
    if ((uVar2 & 4) == 0)
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 & 0xfffffffd;
    }
    else
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 | 2;
    }
    if ((uVar2 & 2) == 0)
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 & 0xfffffffe;
    }
    else
    {
      _CHAR____800d55b0 = _CHAR____800d55b0 | 1;
    }
  }
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x80000) != 0)
  {
    Data = SetMonsterHitData((_Instance *)0x0, (_Instance *)0xfffffe40, 0xa0, -0xba, local_30);
    PhysicsFollowWall(instance, gameTracker, Data, 7);
  }
  if (((_BlockVramEntry_800d59a0._12_4_ & 0x4000000) != 0) &&
      (_CHAR____800d5604 != (_Instance *)0x0))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(_CHAR____800d5604, 2);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetEngageEvent(struct _Instance *instance /*$a0*/)
// line 6975, offset 0x800b3c78
/* begin block 1 */
// Start line: 6976
// Start offset: 0x800B3C78
// Variables:
// 		int Ability; // $v1
/* end block 1 */
// End offset: 0x800B3CC0
// End Line: 6994

/* begin block 2 */
// Start line: 14764
/* end block 2 */
// End Line: 14765

int GetEngageEvent(_Instance *instance)

{
  if (instance != (_Instance *)0x0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instance, 2);
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ SetupReaction(struct _Instance *player /*$s2*/, struct _Instance *instance /*$a0*/)
// line 6997, offset 0x800b3cd0
/* begin block 1 */
// Start line: 6998
// Start offset: 0x800B3CD0
// Variables:
// 		int FaceAngle; // $s3

/* begin block 1.1 */
// Start line: 7014
// Start offset: 0x800B3D14
/* end block 1.1 */
// End offset: 0x800B3D9C
// End Line: 7023
/* end block 1 */
// End offset: 0x800B3D9C
// End Line: 7024

/* begin block 2 */
// Start line: 14808
/* end block 2 */
// End Line: 14809

int SetupReaction(_Instance *player, _Instance *instance)

{
  short sVar1;
  int Data;
  evPhysicsEdgeData *Data_00;

  player->yVel = 0;
  player->xVel = 0;
  *(_Instance **)&player->work3 = instance;
  Data = GetEngageEvent(instance);
  sVar1 = (player->position).z;
  if (Data != 0x2000001)
  {
    Data = SetPhysicsEdgeData(400, -0x100, 0x90, 0, -0xc4, 0x1f2, (_SVector *)&CHAR____800d55b4,
                              (_SVector *)&CHAR____800d55bc, (_SVector *)&CHAR____800d55d4);
    PhysicsCheckEdgeGrabbing(player, (GameTracker *)gameTracker.next, Data, 1);
    Data_00 = (evPhysicsEdgeData *)
        SetPhysicsEdgeData(0, 0, 0, 0, -0x8d, 0, (_SVector *)&CHAR____800d55b4, (_SVector *)0x0,
                           (_SVector *)&CHAR____800d55d4);
    PhysicsDefaultEdgeGrabResponse(player, Data_00, 1);
  }
  (player->position).z = sVar1;
  return (int)sVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckHolding(struct _Instance *instance /*$a0*/)
// line 7050, offset 0x800b3dc0
/* begin block 1 */
// Start line: 14917
/* end block 1 */
// End Line: 14918

/* begin block 2 */
// Start line: 14918
/* end block 2 */
// End Line: 14919

int CheckHolding(_Instance *instance)

{
  return (uint)(instance->LinkChild != (_Instance *)0x0);
}

// decompiled code
// original method signature:
// void /*$ra*/ DisableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
// line 7056, offset 0x800b3dcc
/* begin block 1 */
// Start line: 14929
/* end block 1 */
// End Line: 14930

void DisableWristCollision(_Instance *instance, int Side)

{
  if ((Side & 1U) != 0)
  {
    COLLIDE_SegmentCollisionOff(instance, 0x1f);
  }
  if ((Side & 2U) != 0)
  {
    COLLIDE_SegmentCollisionOff(instance, 0x29);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EnableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
// line 7065, offset 0x800b3e1c
/* begin block 1 */
// Start line: 14947
/* end block 1 */
// End Line: 14948

void EnableWristCollision(_Instance *instance, int Side)

{
  if ((Side & 1U) != 0)
  {
    COLLIDE_SegmentCollisionOn(instance, 0x1f);
  }
  if ((Side & 2U) != 0)
  {
    COLLIDE_SegmentCollisionOn(instance, 0x29);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetCollisionType(struct _Instance *instance /*$s1*/)
// line 7202, offset 0x800b3e6c
/* begin block 1 */
// Start line: 7203
// Start offset: 0x800B3E6C
// Variables:
// 		struct _CollideInfo *collideInfo; // $s0
// 		struct _HSphere *S; // $v0

/* begin block 1.1 */
// Start line: 7217
// Start offset: 0x800B3EB0
// Variables:
// 		struct _Instance *inst; // $v1
/* end block 1.1 */
// End offset: 0x800B3EB0
// End Line: 7217
/* end block 1 */
// End offset: 0x800B4000
// End Line: 7273

/* begin block 2 */
// Start line: 15221
/* end block 2 */
// End Line: 15222

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetCollisionType(_Instance *instance)

{
  int iVar1;
  _CollideInfo *collideInfo;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t')
  {
    if (collideInfo->type1 == '\x03')
    {
      COLLIDE_SetBSPTreeFlag(collideInfo, 0x800);
    }
    else
    {
      *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
    }
    if (collideInfo->type1 == '\x01')
      goto LAB_800b3f18;
    COLLIDE_SegmentCollisionOff(instance, (uint)(byte)collideInfo->segment);
    if (_CHAR____800d55dc != (_Instance *)0x0)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(_CHAR____800d55dc, 0x1000024, 0);
    }
    _CHAR____800d55dc = (_Instance *)0x0;
  LAB_800b3f10:
    iVar1 = 1;
  }
  else
  {
  LAB_800b3f18:
    if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000)
    {
      if ((_BlockVramEntry_800d59a0._12_4_ & 0x1000) != 0)
      {
        return 1;
      }
      if ((*(char *)((int)collideInfo->prim0 + 4) == '\t') &&
          (*(char *)((int)collideInfo->prim1 + 4) == '\b'))
      {
        if (_CHAR____800d55dc == (_Instance *)0x0)
        {
          _CHAR____800d55dc = (_Instance *)collideInfo->inst1;
          return 1;
        }
        if (_CHAR____800d55dc != (_Instance *)collideInfo->inst1)
        {
          printf(s_MultiHit_800cf888);
          return 1;
        }
        goto LAB_800b3f10;
      }
    }
    if (((((collideInfo->type0 == '\x05') || (collideInfo->type1 == '\x05')) ||
          (collideInfo->type0 == '\x02')) ||
         (iVar1 = 0, collideInfo->type1 == '\x02')) &&
        (iVar1 = 1, (_BlockVramEntry_800d59a0._12_4_ & 0x8000000) == 0))
    {
      iVar1 = 0;
    }
  }
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitGlyphSystem(struct _Instance *instance /*$a0*/)
// line 7346, offset 0x800b4014
/* begin block 1 */
// Start line: 7347
// Start offset: 0x800B4014
// Variables:
// 		struct Object *GlyphOb; // $a1

/* begin block 1.1 */
// Start line: 7352
// Start offset: 0x800B4028
// Variables:
// 		struct _Instance *iGlyph; // $v0
/* end block 1.1 */
// End offset: 0x800B403C
// End Line: 7361
/* end block 1 */
// End offset: 0x800B403C
// End Line: 7368

/* begin block 2 */
// Start line: 15509
/* end block 2 */
// End Line: 15510

/* begin block 3 */
// Start line: 15512
/* end block 3 */
// End Line: 15513

void InitGlyphSystem(_Instance *param_1)

{
  _Instance *p_Var1;

  if ((DebugMenuLine_800c8810.var_address != (long *)0x0) &&
      (p_Var1 = INSTANCE_BirthObject(param_1, (Object *)DebugMenuLine_800c8810.var_address, 0),
       p_Var1 != (_Instance *)0x0))
  {
    p_Gpfffffb6c = p_Var1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ mdRazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$s2*/, long *controlCommand /*$s1*/)
// line 7373, offset 0x800b404c
/* begin block 1 */
// Start line: 15566
/* end block 1 */
// End Line: 15567

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mdRazielProcess(_Instance *playerInstance, GameTracker *gameTracker, long *controlCommand)

{
  _Instance *instance;

  ProcessTimers(playerInstance);
  razClearPlayerEvent();
  ProcessRazControl(controlCommand);
  instance = playerInstance;
  SetStates(playerInstance, gameTracker, controlCommand, -1);
  ProcessTimers(instance);
  CAMERA_Control((Camera *)&theCamera, playerInstance);
  (playerInstance->offset).x = 0;
  (playerInstance->offset).y = 0;
  (playerInstance->offset).z = 0;
  _CHAR____800d57b8 = 0;
  _CHAR____800d57ba = 0;
  _CHAR____800d57bc = 0;
  _CHAR____800d55dc = 0;
  if (_CHAR____800d5620 != (_Instance *)0x0)
  {
    GlyphProcess(_CHAR____800d5620, gameTracker);
  }
  _CHAR____800d561c = debugRazielFlags1;
  debugRazielFlags1 = debugRazielFlags1 | debugRazielFlags2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 7407, offset 0x800b4104
/* begin block 1 */
// Start line: 7408
// Start offset: 0x800B4104
/* end block 1 */
// End offset: 0x800B4104
// End Line: 7408

/* begin block 2 */
// Start line: 15640
/* end block 2 */
// End Line: 15641

void RazielProcess(_Instance *playerInstance, GameTracker *gameTracker)

{
  mdRazielProcess(gameTracker->playerInstance, gameTracker, gameTracker->controlCommand);
  DebugProcess(playerInstance, (__Player *)&Raziel);
  _BlockVramEntry_800d5984.udata._0_2_ = 0;
  _BlockVramEntry_800d5984.udata._2_2_ = 0;
  _BlockVramEntry_800d59a0.next._0_2_ = 0;
  /* WARNING: Read-only address (ram,0x800d599e) is written */
  /* WARNING: Read-only address (ram,0x800d599c) is written */
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RazielInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 7422, offset 0x800b4148
/* begin block 1 */
// Start line: 15671
/* end block 1 */
// End Line: 15672

void RazielInit(_Instance *instance, GameTracker *gameTracker)

{
  uint uVar1;

  instance->data = instance->object->data;
  gameTracker->playerInstance = instance;
  uVar1 = instance->flags;
  instance->intro = (Intro *)0x0;
  instance->zVel = 0;
  instance->zAccl = 0;
  instance->yVel = 0;
  instance->yAccl = 0;
  instance->work0 = 0;
  instance->work1 = 0;
  (instance->offset).x = 0;
  (instance->offset).y = 0;
  (instance->offset).z = 0;
  instance->currentMainState = 0;
  instance->matrix = (MATRIX *)0x0;
  instance->maxZVel = 0;
  instance->work3 = 0;
  instance->lightGroup = '\0';
  instance->flags = uVar1 & 0xfffffeff | 0x480;
  instance->flags2 = instance->flags2 | 0x84;
  OBTABLE_GetInstanceCollideFunc(instance);
  OBTABLE_GetInstanceProcessFunc(instance);
  DisableWristCollision(instance, 2);
  DisableWristCollision(instance, 1);
  InitStates(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RazielCollide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 7491, offset 0x800b420c
/* begin block 1 */
// Start line: 7492
// Start offset: 0x800B420C
// Variables:
// 		struct _CollideInfo *collideInfo; // $s2

/* begin block 1.1 */
// Start line: 7521
// Start offset: 0x800B42B8
// Variables:
// 		struct SVECTOR *offset; // $s1
/* end block 1.1 */
// End offset: 0x800B434C
// End Line: 7537

/* begin block 1.2 */
// Start line: 7555
// Start offset: 0x800B43EC
// Variables:
// 		struct SVECTOR *offset; // $a1
/* end block 1.2 */
// End offset: 0x800B4454
// End Line: 7571
/* end block 1 */
// End offset: 0x800B4454
// End Line: 7573

/* begin block 2 */
// Start line: 15836
/* end block 2 */
// End Line: 15837

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RazielCollide(_Instance *instance, GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;

  pvVar3 = instance->collideInfo;
  iVar2 = GetCollisionType(instance);
  if (iVar2 == 1)
  {
    return;
  }
  cVar1 = *(char *)((int)pvVar3 + 7);
  if (cVar1 == '\x01')
  {
    if ((**(uint **)((int)pvVar3 + 0xc) & 0x2000) == 0)
    {
      return;
    }
    pvVar4 = instance->collideInfo;
    *(undefined2 *)((int)pvVar4 + 0x2c) = 0;
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar4 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
  }
  else
  {
    if ((*(char *)((int)pvVar3 + 6) != '\x04') && (*(char *)((int)pvVar3 + 6) != '\x01'))
    {
      return;
    }
    if ((((cVar1 != '\x03') || ((*(byte *)(*(int *)((int)pvVar3 + 0xc) + 6) & 8) != 0)) &&
         ((cVar1 != '\x05' || ((**(ushort **)((int)pvVar3 + 0xc) & 0x2000) == 0)))) &&
        (cVar1 != '\x02'))
    {
      return;
    }
    pvVar4 = instance->collideInfo;
    if ((*(uint *)((int)pvVar3 + 4) & 10) == 0)
    {
      (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
      (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
      (instance->position).z = (instance->position).z + *(short *)((int)pvVar4 + 0x2c);
      COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)((int)pvVar3 + 0x28));
      _CHAR____800d57b8 = _CHAR____800d57b8 + *(short *)((int)pvVar4 + 0x28);
      _CHAR____800d57ba = _CHAR____800d57ba + *(short *)((int)pvVar4 + 0x2a);
      _CHAR____800d57bc = _CHAR____800d57bc + *(short *)((int)pvVar4 + 0x2c);
      return;
    }
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar4 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->offset).z = (instance->offset).z + *(short *)((int)pvVar4 + 0x2c);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->position).z = (instance->position).z + *(short *)((int)pvVar4 + 0x2c);
  }
  COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)((int)pvVar3 + 0x28));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_TurnHead(struct _Instance *instance /*$s2*/, short *rotx /*$s0*/, short *rotz /*$s1*/, struct GameTracker *gameTracker /*$a3*/)
// line 7573, offset 0x800b4470
/* begin block 1 */
// Start line: 7574
// Start offset: 0x800B4470

/* begin block 1.1 */
// Start line: 7578
// Start offset: 0x800B44B4
// Variables:
// 		struct _Rotation rot; // stack offset -40
/* end block 1.1 */
// End offset: 0x800B4598
// End Line: 7600

/* begin block 1.2 */
// Start line: 7603
// Start offset: 0x800B45BC
// Variables:
// 		struct evActionLookAroundData data; // stack offset -32
/* end block 1.2 */
// End offset: 0x800B467C
// End Line: 7621
/* end block 1 */
// End offset: 0x800B467C
// End Line: 7623

/* begin block 2 */
// Start line: 16013
/* end block 2 */
// End Line: 16014

void RAZIEL_TurnHead(_Instance *param_1, ushort *param_2, ushort *param_3)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  _Rotation _Stack40;
  ushort *local_20;
  ushort *local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;

  sVar1 = (short)(iGpffffb574 >> 0x1f);
  if (((uGpfffffac0 & 0x20000) == 0) || ((uGpfffffbc8 & 4) != 0))
  {
    iVar2 = iGpffffb578;
    if (iGpffffb578 < 0)
    {
      iVar2 = iGpffffb578 + 3;
    }
    *param_2 = *param_2 + (short)(iVar2 >> 2);
    *param_3 = *param_3 - ((short)((ulonglong)((longlong)iGpffffb574 * 0x55555556) >> 0x20) - sVar1);
    uVar3 = *param_2 & 0xfff;
    if (0x800 < uVar3)
    {
      uVar3 = uVar3 | 0xf000;
    }
    *param_2 = uVar3;
    uVar3 = *param_3 & 0xfff;
    if (0x800 < uVar3)
    {
      uVar3 = uVar3 | 0xf000;
    }
    *param_3 = uVar3;
    local_18 = 0xfd00;
    local_16 = 0x200;
    local_14 = 0xfc00;
    local_12 = 0x400;
    local_20 = param_2;
    local_1c = param_3;
    razRotateUpperBody((int)param_1, (short **)&local_20);
  }
  else
  {
    iVar2 = iGpffffb578;
    if (iGpffffb578 < 0)
    {
      iVar2 = iGpffffb578 + 7;
    }
    *param_2 = *param_2 + (short)(iVar2 >> 3);
    *param_3 = *param_3 - ((short)((ulonglong)((longlong)iGpffffb574 * 0x2aaaaaab) >> 0x20) - sVar1);
    if ((sGpfffffc70 != 0) && (*param_2 != 0))
    {
      *param_2 = *param_2 - *(short *)(iGpfffffbc4 + 0x1c);
    }
    _Stack40.x = sGpfffffc70 + (*param_2 - 0x1000);
    *param_2 = _Stack40.x;
    _Stack40.y = 0;
    _Stack40.z = *param_3;
    LimitRotation(&_Stack40);
    *param_2 = (_Stack40.x + 0x1000) - sGpfffffc70;
    *param_3 = _Stack40.z;
    ThrowSetFocusPoint(param_1, &_Stack40);
    if (sGpfffffc70 != 0)
    {
      CAMERA_SetLookRot((Camera *)&gp0xffffa3dc,
                        (int)(short)*param_2 + (int)*(short *)(iGpfffffbc4 + 0x1c),
                        (int)(short)*param_3);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_SetLookAround(struct _Instance *instance /*$s1*/)
// line 7623, offset 0x800b4694
/* begin block 1 */
// Start line: 16133
/* end block 1 */
// End Line: 16134

void RAZIEL_SetLookAround(_Instance *param_1)

{
  _G2Anim_Type *anim;

  anim = &param_1->anim;
  G2Anim_EnableController(anim, 0x11, 0xe);
  G2Anim_EnableController(anim, 0x10, 0xe);
  G2Anim_EnableController(anim, 0xe, 0xe);
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(param_1, (int)&DAT_00100009, 1);
}

// decompiled code
// original method signature:
// void /*$ra*/ RAZIEL_ResetLookAround(struct _Instance *instance /*$s1*/)
// line 7652, offset 0x800b470c
/* begin block 1 */
// Start line: 16208
/* end block 1 */
// End Line: 16209

void RAZIEL_ResetLookAround(_Instance *param_1)

{
  _G2Anim_Type *anim;

  anim = &param_1->anim;
  G2Anim_InterpDisableController(anim, 0x11, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0x10, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0xe, 0xe, 300);
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(param_1, (int)&DAT_00100009, 0);
}

// decompiled code
// original method signature:
// long /*$ra*/ RAZIEL_OkToLookAround(struct _Instance *playerInstance /*$a0*/)
// line 7675, offset 0x800b4788
/* begin block 1 */
// Start line: 16266
/* end block 1 */
// End Line: 16267

/* begin block 2 */
// Start line: 16280
/* end block 2 */
// End Line: 16281

uint RAZIEL_OkToLookAround(void)

{
  int iVar1;

  if ((uGpfffffafc & 4) != 0)
  {
    if (pcGpfffff76c == StateHandlerIdle)
    {
      iVar1 = G2EmulationQueryAnimation((__CharacterState *)&gp0xfffff764, 0);
      return (uint)(iVar1 == 0);
    }
    if (pcGpfffff76c == StateHandlerThrow2)
    {
      return 1;
    }
  }
  if ((pcGpfffff888 != StateHandlerSwim) && (pcGpfffff888 != StateHandlerSwimTread))
  {
    return 0;
  }
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ TrailWaterFX(struct _Instance *instance /*$s2*/, int Segment /*$s0*/, int Bubbles /*$s7*/, int Type /*$s6*/)
// line 7714, offset 0x800b4810
/* begin block 1 */
// Start line: 7715
// Start offset: 0x800B4810
// Variables:
// 		struct _SVector Pos; // stack offset -88
// 		struct _SVector Vel; // stack offset -80
// 		struct _SVector Accl; // stack offset -72
// 		int i; // $s4
// 		int j; // $s1
// 		struct Level *level; // $s5
// 		struct __BubbleParams BP; // stack offset -64
/* end block 1 */
// End offset: 0x800B4B64
// End Line: 7761

/* begin block 2 */
// Start line: 16358
/* end block 2 */
// End Line: 16359

void TrailWaterFX(_Instance *instance, int Segment, int Bubbles, int Type)

{
  undefined auStack72[32];

  /* WARNING: Subroutine does not return */
  memset(auStack72, 0, 8);
}
