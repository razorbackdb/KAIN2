#include "THISDUST.H"
#include "ATTACK.H"


// decompiled code
// original method signature: 
// int /*$ra*/ StateHandlerDecodeHold(int *Message /*$s2*/, int *Data /*$s1*/)
 // line 16, offset 0x80099268
	/* begin block 1 */
		// Start line: 17
		// Start offset: 0x80099268
		// Variables:
	// 		int rc; // $s3
	// 		struct _Instance *heldInstance; // $s0
	/* end block 1 */
	// End offset: 0x80099420
	// End Line: 82

	/* begin block 2 */
		// Start line: 32
	/* end block 2 */
	// End Line: 33

int StateHandlerDecodeHold(int *Message,int *Data)

{
  _Instance *Inst;
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  Inst = razGetHeldItem();
  if (((Raziel.Senses.EngagedMask & 0x200) == 0) || (Inst == (_Instance *)0x0)) {
    if (((Raziel.Senses.EngagedMask & 0x100) == 0) || (Inst != (_Instance *)0x0)) {
      Inst = razGetHeldWeapon();
      if (Inst == (_Instance *)0x0) {
        if ((Raziel.Abilities & 4U) == 0) {
          iVar3 = 0;
        }
        else {
          *Message = 0x80000;
        }
      }
      else {
        *Message = 0x800010;
      }
    }
    else {
      uVar1 = INSTANCE_Query(Raziel.Senses.EngagedList[8].instance,0);
      if ((int)uVar1 < 0) {
        *Data = 1;
        *Message = 0x1000002;
      }
      else {
        *Data = 0;
        *Message = 0x1000002;
      }
    }
  }
  else {
    uVar1 = INSTANCE_Query(Raziel.Senses.EngagedList[9].instance,0);
    if ((uVar1 & 0x10000000) == 0) {
      *Data = 0;
      *Message = 0x100000a;
    }
    else {
      *Data = 1;
      *Message = 0x100000a;
      ControlFlag = ControlFlag | 0x40000;
    }
    uVar1 = INSTANCE_Query(Inst,2);
    if (((uVar1 & 0x20) != 0) && (*Message = 0x1000018, *Data != 0)) {
      uVar1 = INSTANCE_Query(Inst,3);
      if ((uVar1 & 0x10000) == 0) {
        *Data = 0;
      }
      else {
        *Data = 1;
      }
    }
  }
  iVar2 = iVar3;
  if ((Raziel.Senses.heldClass == 3) && (iVar2 = 0, *Message == 0x800010)) {
    iVar2 = iVar3;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAttack2(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 92, offset 0x8009943c
	/* begin block 1 */
		// Start line: 93
		// Start offset: 0x8009943C
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int message; // stack offset -64
	// 		int messageData; // stack offset -60
	// 		int Frame; // stack offset -56
	// 		int Anim; // stack offset -52

		/* begin block 1.1 */
			// Start line: 135
			// Start offset: 0x800996F4
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s4
		// 		unsigned long endColor; // $s3
		/* end block 1.1 */
		// End offset: 0x800997E8
		// End Line: 168

		/* begin block 1.2 */
			// Start line: 254
			// Start offset: 0x80099B0C
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s3
		// 		unsigned long endColor; // $s1
		/* end block 1.2 */
		// End offset: 0x80099BCC
		// End Line: 282

		/* begin block 1.3 */
			// Start line: 328
			// Start offset: 0x80099D3C
			// Variables:
		// 		struct _Instance *Inst; // $v0
		/* end block 1.3 */
		// End offset: 0x80099D60
		// End Line: 333

		/* begin block 1.4 */
			// Start line: 351
			// Start offset: 0x80099DF4
		/* end block 1.4 */
		// End offset: 0x80099DF4
		// End Line: 352

		/* begin block 1.5 */
			// Start line: 384
			// Start offset: 0x80099EF8
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.5 */
		// End offset: 0x80099FC4
		// End Line: 397

		/* begin block 1.6 */
			// Start line: 429
			// Start offset: 0x8009A0A0
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v1
		/* end block 1.6 */
		// End offset: 0x8009A104
		// End Line: 436
	/* end block 1 */
	// End offset: 0x8009A140
	// End Line: 444

	/* begin block 2 */
		// Start line: 191
	/* end block 2 */
	// End Line: 192

/* WARNING: Type propagation algorithm not settling */

void StateHandlerAttack2(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *Inst;
  ulong uVar2;
  int Data_00;
  undefined *puVar3;
  __MessageQueue *In_00;
  int NewAnim;
  code *NewProcess;
  ulong endColor;
  ulong startColor;
  _Instance **pp_Var4;
  __State *p_Var5;
  int local_58;
  int local_54;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  __MessageQueue *local_30;
  
  local_38 = G2EmulationQueryFrame(In,CurrentSection);
  local_34 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  local_30 = &p_Var5->Event;
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var1 = PeekMessageQueue(local_30);
    Data_00 = Raziel.padCommands.Queue[13].ID;
    if (p_Var1 == (__Event *)0x0) {
      if (((Raziel.attackFlags & 4U) != 0) &&
         ((int)((uint)(Raziel.attack)->switchDelay * 100) <=
          (int)(In->CharacterInstance->anim).section[CurrentSection & 0xff].elapsedTime)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
      }
      if (((CurrentSection == 0) && ((ControlFlag & 0x10000000U) != 0)) && ((Raziel.Mode & 2U) == 0)
         ) {
        SteerSwitchMode(In->CharacterInstance,2);
      }
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 != (undefined *)0x1000001) {
      local_54 = CurrentSection;
      if ((int)puVar3 < 0x1000002) {
        if (puVar3 == (undefined *)0x100000) {
          Inst = (_Instance *)((int)&(pp_Var4[0x48]->node).prev + 1);
          pp_Var4[0x48] = Inst;
          if (*(int *)((int)Inst * 4 + *(int *)((int)pp_Var4[0x47] * 4 + *(int *)(Data_00 + 0x10)))
              == 0) {
            pp_Var4[0x48] = (_Instance *)0x1;
          }
          Raziel.attack =
               *(__AttackItem **)
                ((int)pp_Var4[0x48] * 4 +
                *(int *)((int)pp_Var4[0x47] * 4 + *(int *)(Raziel.padCommands.Queue[13].ID + 0x10)))
          ;
          G2EmulationSwitchAnimationAlpha
                    (In,CurrentSection,(uint)(Raziel.attack)->anim,0,(uint)(Raziel.attack)->framesIn
                     ,1,(uint)(Raziel.attack)->alphaIn);
          if (CurrentSection == 1) {
            startColor = (Raziel.attack)->ribbonStartColor;
            endColor = (Raziel.attack)->ribbonEndColor;
            Inst = razGetHeldWeapon();
            if (Inst == (_Instance *)0x0) {
              Inst = In->CharacterInstance;
            }
            else {
              Inst = razGetHeldWeapon();
              uVar2 = INSTANCE_Query(Inst,2);
              if (((uVar2 & 0x20) != 0) && (uVar2 = INSTANCE_Query(Inst,3), (uVar2 & 0x10000) != 0))
              {
                startColor = *(ulong *)(Raziel.padCommands.Queue[13].ID + 4);
                endColor = *(ulong *)(Raziel.padCommands.Queue[13].ID + 8);
              }
            }
            Raziel.attackCurrentHit = (_Instance *)Raziel.currentAttack;
            Raziel.currentAttack = 0;
            FX_StartRibbon(Inst,(ushort)(Raziel.attack)->ribbonStartSegment,
                           (ushort)(Raziel.attack)->ribbonEndSegment,0,
                           (uint)(Raziel.attack)->ribbonLifeTime,
                           (uint)(Raziel.attack)->ribbonFaceLifeTime,
                           (int)(short)(Raziel.attack)->ribbonStartOpacity,startColor,endColor);
          }
          EnMessageQueueData(&p_Var5->Defer,0x100002,0);
          PurgeMessageQueue(&p_Var5->Event);
        }
        else {
          if ((int)puVar3 < 0x100001) {
            if (puVar3 == (undefined *)0x80000001) {
              if (CurrentSection == 0) {
                if ((ControlFlag & 0x10000000U) == 0) {
                  Data_00 = -0x7fffffff;
                  In_00 = &In->SectionList[0].Defer;
LAB_8009a060:
                  EnMessageQueueData(In_00,Data_00,0);
                }
                else {
                  Raziel.Mode = 8;
                  Data_00 = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                  if (Data_00 != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerCompression,0);
                  ControlFlag = ControlFlag & 0xffffdfff;
                }
              }
            }
            else {
              if ((int)puVar3 < -0x7fffffff) {
LAB_8009984c:
                Raziel.attack =
                     *(__AttackItem **)
                      ((int)pp_Var4[0x48] * 4 +
                      *(int *)((int)pp_Var4[0x47] * 4 +
                              *(int *)(Raziel.padCommands.Queue[13].ID + 0x10)));
                if ((local_34 == (uint)(Raziel.attack)->anim) &&
                   ((int)(uint)(Raziel.attack)->ignoreDelay <= local_38)) {
                  Raziel.attackFlags = Raziel.attackFlags | 4;
                }
                if ((CurrentSection == 1) && (Raziel.attackLastHit != (_Instance *)0x0)) {
                  FX_StopGlowEffect((_FXGlowEffect *)Raziel.attackLastHit,0);
                  Raziel.attackLastHit = (_Instance *)0x0;
                }
              }
              else {
                if (puVar3 == &DAT_80000020) {
                  Data_00 = StateHandlerDecodeHold(&local_40,&local_3c);
                  if (Data_00 != 0) {
                    EnMessageQueueData(local_30,local_40,local_3c);
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x80000) goto LAB_8009a070;
                  Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x400;
                  razSetPlayerEventHistory(0x400);
                  StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
                  if (CurrentSection == 1) {
                    razLaunchForce(In->CharacterInstance);
                  }
                }
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x100002) {
              Raziel.attackFlags = 0;
            }
            else {
              if ((int)puVar3 < 0x100002) {
                Inst = (_Instance *)p_Var1->Data;
                pp_Var4[0x48] = (_Instance *)0x0;
                pp_Var4[0x47] = Inst;
                Inst = razGetHeldWeapon();
                if (Inst != (_Instance *)0x0) {
                  if (Raziel.Senses.heldClass == 2) {
                    Inst = (_Instance *)(p_Var1->Data + 2);
                  }
                  else {
                    if (Raziel.Senses.heldClass < 3) {
                      if (Raziel.Senses.heldClass != 1) goto LAB_80099694;
                      Inst = (_Instance *)(p_Var1->Data + 1);
                    }
                    else {
                      if (Raziel.Senses.heldClass == 3) {
                        Inst = (_Instance *)(p_Var1->Data + 4);
                      }
                      else {
                        if (Raziel.Senses.heldClass != 0x1000) goto LAB_80099694;
                        Inst = (_Instance *)(p_Var1->Data + 3);
                      }
                    }
                  }
                  pp_Var4[0x47] = Inst;
                }
LAB_80099694:
                Raziel.attack =
                     *(__AttackItem **)
                      ((int)pp_Var4[0x48] * 4 +
                      *(int *)((int)pp_Var4[0x47] * 4 +
                              *(int *)(Raziel.padCommands.Queue[13].ID + 0x10)));
                G2EmulationSwitchAnimationAlpha
                          (In,CurrentSection,(uint)(Raziel.attack)->anim,0,
                           (uint)(Raziel.attack)->framesIn,1,(uint)(Raziel.attack)->alphaIn);
                if (CurrentSection == 1) {
                  startColor = (Raziel.attack)->ribbonStartColor;
                  endColor = (Raziel.attack)->ribbonEndColor;
                  Inst = razGetHeldWeapon();
                  if (Inst == (_Instance *)0x0) {
                    Inst = In->CharacterInstance;
                  }
                  else {
                    Inst = razGetHeldWeapon();
                    uVar2 = INSTANCE_Query(Inst,2);
                    if (((uVar2 & 0x20) != 0) &&
                       (uVar2 = INSTANCE_Query(Inst,3), (uVar2 & 0x10000) != 0)) {
                      startColor = *(ulong *)(Raziel.padCommands.Queue[13].ID + 4);
                      endColor = *(ulong *)(Raziel.padCommands.Queue[13].ID + 8);
                    }
                  }
                  FX_StartRibbon(Inst,(ushort)(Raziel.attack)->ribbonStartSegment,
                                 (ushort)(Raziel.attack)->ribbonEndSegment,0,
                                 (uint)(Raziel.attack)->ribbonLifeTime,
                                 (uint)(Raziel.attack)->ribbonFaceLifeTime,
                                 (int)(short)(Raziel.attack)->ribbonStartOpacity,startColor,endColor
                                );
                  Data_00 = 9;
                  if (p_Var1->Data < 10) {
                    Inst = In->CharacterInstance;
                  }
                  else {
                    Inst = In->CharacterInstance;
                    Data_00 = 0xf;
                  }
                  SteerSwitchMode(Inst,Data_00);
                  ControlFlag = ControlFlag | 0x2000;
                }
                Raziel.attackCurrentHit = (_Instance *)0x0;
                Raziel.currentAttack = 0;
                Raziel.attackLastHit = (_Instance *)0x0;
                Raziel.Mode = Raziel.Mode | 0x200000;
              }
              else {
                if (puVar3 != (undefined *)0x100004) {
                  if (puVar3 == (undefined *)0x800010) {
                    razSetPlayerEventHistory(0x200);
                    NewProcess = StateHandlerThrow2;
                    goto LAB_80099e94;
                  }
                  goto LAB_8009a070;
                }
                if (CurrentSection == 1) {
                  DisableWristCollision(In->CharacterInstance,2);
                  DisableWristCollision(In->CharacterInstance,1);
                  Raziel.dropOffHeight = 0x9b;
                  Raziel.fallZVelocity = -0x60;
                }
                Raziel.Mode = Raziel.Mode & 0xffdfffff;
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x2000002) {
          if (CurrentSection == 1) {
            Inst = (_Instance *)p_Var1->Data;
            Data_00 = (int)Inst->prev * (uint)(Raziel.attack)->hitPowerScale;
            if (Data_00 < 0) {
              Data_00 = Data_00 + 0xfff;
            }
            Data_00 = SetMonsterHitData(In->CharacterInstance,Raziel.attackCurrentHit,Data_00 >> 0xc
                                        ,(uint)(Raziel.attack)->knockBackDistance,
                                        (uint)(Raziel.attack)->knockBackFrames);
            INSTANCE_Post(*(_Instance **)&Inst->node,0x1000000,Data_00);
            if (((Raziel.attack)->handsToCollide & 2) != 0) {
              Data_00 = SetFXHitData(In->CharacterInstance,0x29,0x20,0x100);
              INSTANCE_Post(*(_Instance **)&Inst->node,0x400000,Data_00);
            }
            if (((Raziel.attack)->handsToCollide & 1) != 0) {
              Data_00 = SetFXHitData(In->CharacterInstance,0x1f,0x20,0x100);
              INSTANCE_Post(*(_Instance **)&Inst->node,0x400000,Data_00);
            }
            Raziel.currentAttack = *(int *)&Inst->node;
          }
        }
        else {
          if ((int)puVar3 < 0x2000003) {
            if (puVar3 == (undefined *)0x100000a) {
              if (p_Var1->Data == 0) {
                if (CurrentSection == 1) {
                  Data_00 = 0x48;
LAB_80099e3c:
                  G2EmulationSwitchAnimationCharacter(In,Data_00,0,3,CurrentSection);
                  if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
                    Data_00 = 0x100000a;
                    Inst = Raziel.Senses.EngagedList[9].instance;
LAB_80099e6c:
                    INSTANCE_Post(Inst,Data_00,0);
                  }
                }
              }
              else {
                razSetPlayerEventHistory(0x80);
                ControlFlag = ControlFlag | 0x40000;
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  local_58 = 3;
                  Data_00 = 2;
                }
                else {
                  NewAnim = 0x3b;
                  local_58 = 0;
                  local_54 = 1;
                  Data_00 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_58,local_54);
                NewProcess = StateHandlerCannedReaction;
                StateSwitchStateData(In,CurrentSection,StateHandlerCannedReaction,0);
                if ((CurrentSection == 1) &&
                   (In->SectionList[0].Data1 = 1, (Raziel.Senses.EngagedMask & 0x200) != 0)) {
                  razAlignYRotMoveInterp
                            (In->CharacterInstance,Raziel.Senses.EngagedList[9].instance,0x208,'\0',
                             3,0);
                  G2EmulationSwitchAnimation(In,0,0x3b,0,3,1);
                  local_54 = 0;
LAB_80099e94:
                  StateSwitchStateData(In,local_54,NewProcess,0);
                }
              }
            }
            else {
              if ((int)puVar3 < 0x100000b) {
                if (puVar3 == (undefined *)0x1000002) {
                  if (Raziel.CurrentPlane == 1) {
                    StateSwitchStateData(In,CurrentSection,StateHandlerGrab,local_3c);
                  }
                }
                else {
LAB_8009a070:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar3 != (undefined *)0x1000018) {
                  if (puVar3 == (undefined *)0x2000000) goto LAB_8009984c;
                  goto LAB_8009a070;
                }
                if (p_Var1->Data == 0) {
                  if (CurrentSection == 1) {
                    Data_00 = 0x5a;
                    goto LAB_80099e3c;
                  }
                }
                else {
                  razSetPlayerEventHistory(0x100);
                  ControlFlag = ControlFlag | 0x40000;
                  if (CurrentSection == 2) {
                    NewAnim = 0;
                    local_58 = 3;
                    Data_00 = 2;
                  }
                  else {
                    NewAnim = 0x8b;
                    local_58 = 0;
                    local_54 = 1;
                    Data_00 = CurrentSection;
                  }
                  G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_58,local_54);
                  if ((CurrentSection == 1) && ((Raziel.Senses.EngagedMask & 0x200) != 0)) {
                    Raziel.padCommands.Queue[8].ID._0_2_ = 900;
                    razAlignYRotMoveInterp
                              (In->CharacterInstance,Raziel.Senses.EngagedList[9].instance,0x1e6,
                               '\0',0x14,0);
                    (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5b20;
                  }
                }
              }
            }
          }
          else {
            if (puVar3 != (undefined *)0x4020000) {
              if ((int)puVar3 < 0x4020001) {
                if (puVar3 != (undefined *)0x4010080) goto LAB_8009a070;
                if (CurrentSection == 0) {
                  if (p_Var1->Data == 0) {
                    razSetPauseTranslation(In->CharacterInstance);
                  }
                  else {
                    razResetPauseTranslation(In->CharacterInstance);
                  }
                }
              }
              else {
                if (puVar3 == (undefined *)0x8000000) {
                  if (((Raziel.attackFlags & 4U) != 0) &&
                     (Data_00 = 0x100000, In_00 = local_30,
                     *(int *)((int)pp_Var4[0x48] * 4 +
                              *(int *)((int)pp_Var4[0x47] * 4 +
                                      *(int *)(Raziel.padCommands.Queue[13].ID + 0x10)) + 4) != 0))
                  goto LAB_8009a060;
                  if ((int)pp_Var4[0x47] < 10) {
                    if (Raziel.padCommands.Queue[5].ID < 7) {
                      NewProcess = StateHandlerAutoFace;
                      goto LAB_80099e94;
                    }
                    Data_00 = SetControlInitIdleData(1,0,(uint)(Raziel.attack)->framesOut);
                    StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
                  }
                  else {
                    if ((*PadData & 0x8000000fU) == 0) {
                      StateSwitchStateCharacterData(In,StateHandlerStopMove,0x3c);
                    }
                    else {
                      StateSwitchStateCharacterData(In,StateHandlerMove,0);
                    }
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x8000004) goto LAB_8009a070;
                  if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
                    INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x100000c,0x20);
                    Inst = razGetHeldWeapon();
                    if (Inst != (_Instance *)0x0) {
                      Data_00 = 0x800029;
                      goto LAB_80099e6c;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var5->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCannedReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 447, offset 0x8009a170
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x8009A170
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 489
			// Start offset: 0x8009A334
			// Variables:
		// 		struct _Instance *Inst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A350
		// End Line: 492

		/* begin block 1.2 */
			// Start line: 502
			// Start offset: 0x8009A358
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009A3C8
		// End Line: 518
	/* end block 1 */
	// End offset: 0x8009A3E4
	// End Line: 561

	/* begin block 2 */
		// Start line: 924
	/* end block 2 */
	// End Line: 925

void StateHandlerCannedReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *Inst;
  int Data_00;
  undefined *puVar2;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100014) {
LAB_8009a2f4:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
      Raziel.Mode = 1;
    }
    else {
      if ((int)puVar2 < 0x100015) {
        if (puVar2 != &DAT_80000020) {
          if ((int)puVar2 < -0x7fffffdf) {
            if ((puVar2 != (undefined *)0x80000000) && (puVar2 != &DAT_80000008)) goto LAB_8009a3cc;
          }
          else {
            if (puVar2 == (undefined *)0x100001) {
              if (CurrentSection == 0) {
                Raziel.padCommands.Queue[8].ID._0_2_ = 0x1194;
                Raziel.Mode = 0x10000;
                ControlFlag = 0x1041009;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
              }
            }
            else {
              if (puVar2 != (undefined *)0x100004) goto LAB_8009a3cc;
              if (CurrentSection == 1) {
                G2EmulationSwitchAnimationSync(In,2,1,4);
              }
            }
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x8000000) goto LAB_8009a2f4;
        if ((int)puVar2 < 0x8000001) {
          if ((0x1000001 < (int)puVar2) || ((int)puVar2 < 0x1000000)) {
LAB_8009a3cc:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000003) {
            if (CurrentSection != 0) goto LAB_8009a3d4;
            Inst = razGetHeldItem();
          }
          else {
            if (puVar2 != (undefined *)0x8000004) goto LAB_8009a3cc;
            Inst = razGetHeldItem();
            INSTANCE_Post(Inst,0x800008,0);
            razReaverOn();
          }
          if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
            Data_00 = SetMonsterImpaleData
                                (Inst,&In->CharacterInstance->rotation,
                                 &In->CharacterInstance->position,0x208);
            INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x100000a,Data_00);
          }
        }
      }
    }
LAB_8009a3d4:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStumble(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*$s6*/)
 // line 564, offset 0x8009a404
	/* begin block 1 */
		// Start line: 565
		// Start offset: 0x8009A404
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int processTime; // $s5

		/* begin block 1.1 */
			// Start line: 601
			// Start offset: 0x8009A630
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A630
		// End Line: 603

		/* begin block 1.2 */
			// Start line: 611
			// Start offset: 0x8009A684
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8009A684
		// End Line: 612
	/* end block 1 */
	// End offset: 0x8009A710
	// End Line: 634

	/* begin block 2 */
		// Start line: 1187
	/* end block 2 */
	// End Line: 1188

/* WARNING: Type propagation algorithm not settling */

void StateHandlerStumble(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  int Data_00;
  _Instance *p_Var3;
  undefined *puVar4;
  _Instance **pp_Var5;
  
  bVar1 = true;
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if (bVar1) {
        p_Var3 = (_Instance *)
                 ((int)(&In->CharacterInstance + CurrentSection * 0x47)[0x47] -
                 gameTrackerX.idleTime);
        (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = p_Var3;
        if (((int)p_Var3 < 1) && (Data_00 = STREAM_IsMorphInProgress(), Data_00 == 0)) {
          EnMessageQueueData(&Raziel.State.SectionList[CurrentSection].Defer,0x100000,0);
        }
      }
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x100000) {
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
    }
    else {
      if ((int)puVar4 < 0x100001) {
        if (puVar4 != &DAT_80000020) {
          if ((int)puVar4 < -0x7fffffdf) {
            if (puVar4 != (undefined *)0x80000000) {
LAB_8009a6a0:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == (undefined *)0x0) {
              pp_Var5[0x48] = (_Instance *)0x1;
            }
            else {
              if (puVar4 != (undefined *)0x40003) goto LAB_8009a6a0;
              if (CurrentSection == 0) {
                p_Var3 = (_Instance *)p_Var2->Data;
                G2EmulationInstanceToInstanceSwitchAnimationCharacter
                          (*(_Instance **)&p_Var3->node,*(_Instance **)((int)&p_Var3->node + 4),
                           (int)p_Var3->next,(int)p_Var3->prev,(int)p_Var3->instanceID,
                           (int)p_Var3->flags);
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x1000000) {
          if ((gameTrackerX.debugFlags2 & 0x800U) != 0) {
            LoseHealth(*(int *)(p_Var2->Data + 0xc));
          }
        }
        else {
          if ((int)puVar4 < 0x1000001) {
            if (puVar4 == (undefined *)0x100001) {
              if (CurrentSection == 0) {
                ControlFlag = 8;
                SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                PhysicsMode = 0;
                SteerSwitchMode(In->CharacterInstance,0);
                razResetMotion(In->CharacterInstance);
              }
              pp_Var5[0x47] = (_Instance *)(p_Var2->Data * 0x1e);
              G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x800);
              G2EmulationSwitchAnimation(In,CurrentSection,0x81,0,3,2);
            }
            else {
              if (puVar4 != (undefined *)0x100004) goto LAB_8009a6a0;
              bVar1 = false;
              G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
            }
          }
          else {
            if (puVar4 != (undefined *)0x1000001) {
              if (puVar4 != (undefined *)0x10000000) goto LAB_8009a6a0;
              if (pp_Var5[0x48] == (_Instance *)0x1) {
                pp_Var5[0x48] = (_Instance *)0x0;
                pp_Var5[0x47] = (_Instance *)&pp_Var5[0x47][-1].attachedID;
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHitReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 655, offset 0x8009a738
	/* begin block 1 */
		// Start line: 656
		// Start offset: 0x8009A738
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 665
			// Start offset: 0x8009A800
			// Variables:
		// 		struct evMonsterHitData *data; // $s0

			/* begin block 1.1.1 */
				// Start line: 669
				// Start offset: 0x8009A80C
				// Variables:
			// 		struct _Instance *weapon; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009A890
			// End Line: 686
		/* end block 1.1 */
		// End offset: 0x8009A8D8
		// End Line: 692
	/* end block 1 */
	// End offset: 0x8009A954
	// End Line: 720

	/* begin block 2 */
		// Start line: 1303
	/* end block 2 */
	// End Line: 1304

/* WARNING: Type propagation algorithm not settling */

void StateHandlerHitReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  int NewAnim;
  undefined *puVar2;
  _FXGlowEffect *p_Var3;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100001) {
      p_Var3 = (_FXGlowEffect *)p_Var1->Data;
      if (CurrentSection == 0) {
        Raziel.glowEffect = (_FXGlowEffect *)p_Var3->next;
        instance = razGetHeldWeapon();
        if (instance != (_Instance *)0x0) {
          TurnOffCollisionPhysOb(instance,7);
        }
        if ((gameTrackerX.debugFlags2 & 0x800U) != 0) {
          LoseHealth((int)*(_FXGlowEffect **)&p_Var3->effectType);
        }
        PhysicsMode = 3;
        Raziel.Mode = Raziel.Mode | 0x208000;
        ControlFlag = ControlFlag & 0xf7ffffffU | 0x1000;
        SteerSwitchMode(In->CharacterInstance,10);
      }
      if ((int)*(_FXGlowEffect **)&p_Var3->effectType < 0x1001) {
        NewAnim = 0x7e;
      }
      else {
        NewAnim = 0x38;
      }
      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,2,1);
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if ((puVar2 != (undefined *)0x80000000) && (puVar2 != &DAT_80000020)) {
LAB_8009a93c:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar2 != (undefined *)0x1000000) {
          if ((((int)puVar2 < 0x1000000) || (0x8000001 < (int)puVar2)) || ((int)puVar2 < 0x8000000))
          goto LAB_8009a93c;
          if (CurrentSection == 0) {
            if ((ControlFlag & 0x100000U) == 0) {
              NewAnim = SetControlInitIdleData(0,0,3);
              StateSwitchStateCharacterData(In,StateHandlerIdle,NewAnim);
            }
            else {
              StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerThrow2(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*stack 8*/)
 // line 808, offset 0x8009a974
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x8009A974
		// Variables:
	// 		struct __Event *Ptr; // $a2
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 992
			// Start offset: 0x8009B09C
			// Variables:
		// 		struct _Instance *weaponInst; // $s0

			/* begin block 1.1.1 */
				// Start line: 996
				// Start offset: 0x8009B0B0

				/* begin block 1.1.1.1 */
					// Start line: 1006
					// Start offset: 0x8009B110
					// Variables:
				// 		struct _Position To; // stack offset -64
				// 		struct _Rotation Rot; // stack offset -56
				// 		struct MATRIX *matrix; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8009B110
				// End Line: 1011
			/* end block 1.1.1 */
			// End offset: 0x8009B1F0
			// End Line: 1026
		/* end block 1.1 */
		// End offset: 0x8009B200
		// End Line: 1029

		/* begin block 1.2 */
			// Start line: 1064
			// Start offset: 0x8009B2E8
			// Variables:
		// 		struct _Instance *instance; // $a0
		/* end block 1.2 */
		// End offset: 0x8009B30C
		// End Line: 1072

		/* begin block 1.3 */
			// Start line: 1084
			// Start offset: 0x8009B34C
			// Variables:
		// 		struct _Position To; // stack offset -64
		// 		struct _Rotation Rot; // stack offset -48
		// 		struct MATRIX *matrix; // $v0
		/* end block 1.3 */
		// End offset: 0x8009B390
		// End Line: 1094

		/* begin block 1.4 */
			// Start line: 1098
			// Start offset: 0x8009B3A0
			// Variables:
		// 		int pitch; // $a2
		// 		int volume; // $a3
		/* end block 1.4 */
		// End offset: 0x8009B478
		// End Line: 1111
	/* end block 1 */
	// End offset: 0x8009B478
	// End Line: 1115

	/* begin block 2 */
		// Start line: 1602
	/* end block 2 */
	// End Line: 1603

/* WARNING: Type propagation algorithm not settling */

void StateHandlerThrow2(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  __Event *p_Var6;
  _Instance *Inst;
  ulong uVar7;
  void *pvVar8;
  undefined *puVar9;
  int *target;
  int CurrentSection_00;
  int local_4c;
  ushort type;
  int NewAnim;
  code *NewProcess;
  uint NewAnim_00;
  __MessageQueue *In_00;
  _Instance **pp_Var10;
  int local_50;
  _Position local_40;
  _Rotation _Stack56;
  _Rotation _Stack48;
  
  uVar5 = G2EmulationQueryAnimation(In,CurrentSection);
  pp_Var10 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    In_00 = &In->SectionList[CurrentSection].Event;
    p_Var6 = PeekMessageQueue(In_00);
    if (p_Var6 == (__Event *)0x0) {
      if (CurrentSection == 1) {
        if ((Raziel.Senses.EngagedMask & 0x80) != 0) {
          uVar7 = INSTANCE_Query(Raziel.Senses.EngagedList[7].instance,0xc);
          local_40.x = *(short *)(uVar7 + 0x14);
          local_40.y = *(short *)(uVar7 + 0x18);
          local_40.z = *(short *)(uVar7 + 0x1c);
          PointAt(In->CharacterInstance,&local_40,&_Stack48);
        }
        if ((Raziel.padCommands.Queue[9].ID != 0) &&
           (uVar5 = *(int *)(Raziel.padCommands.Queue[13].ID + 0x40) * 0x1e,
           (uint)Raziel.padCommands.Queue[9].Data < uVar5)) {
          uVar7 = SOUND_Update3dSound(&In->CharacterInstance->position,
                                      Raziel.padCommands.Queue[9].ID,
                                      (int)(((int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x38)
                                            + (uint)(((int)*(short *)(Raziel.padCommands.Queue[13].
                                                                      ID + 0x3a) -
                                                     (int)*(short *)(Raziel.padCommands.Queue[13].ID
                                                                    + 0x38)) *
                                                    Raziel.padCommands.Queue[9].Data) / uVar5) *
                                           0x10000) >> 0x10,
                                      (int)(((int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x3c)
                                            + (uint)(((int)*(short *)(Raziel.padCommands.Queue[13].
                                                                      ID + 0x3e) -
                                                     (int)*(short *)(Raziel.padCommands.Queue[13].ID
                                                                    + 0x3c)) *
                                                    Raziel.padCommands.Queue[9].Data) / uVar5) *
                                           0x10000) >> 0x10,10000);
          if (uVar7 == 0) {
            SndEndLoop(Raziel.padCommands.Queue[9].ID);
            Raziel.padCommands.Queue[9].ID = 0;
          }
          Raziel.padCommands.Queue[9].Data =
               Raziel.padCommands.Queue[9].Data + gameTrackerX.idleTime;
        }
      }
      return;
    }
    puVar9 = (undefined *)p_Var6->ID;
    if (puVar9 == (undefined *)0x100009) {
      if (CurrentSection == 1) {
        if (p_Var6->Data == 1) {
          razSetFadeEffect(In->CharacterInstance->fadeValue,
                           *(short *)(Raziel.padCommands.Queue[13].ID + 0x24),
                           (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x26));
          Raziel._1140_4_ = StateHandlerIdle;
          Raziel.throwData = (__ThrowItem *)0x2;
        }
        else {
          razSetFadeEffect(In->CharacterInstance->fadeValue,0,
                           -(int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x26));
          G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,600);
          Raziel.throwData = (__ThrowItem *)0x0;
        }
      }
    }
    else {
      if ((int)puVar9 < 0x10000a) {
        if (puVar9 != &DAT_80000020) {
          if ((int)puVar9 < -0x7fffffdf) {
            if (puVar9 != (undefined *)0x80000000) {
              if (puVar9 != &DAT_80000008) goto LAB_8009b30c;
              if (Raziel._1132_4_ == (_Instance *)0x0) {
                local_4c = 0x20000020;
              }
              else {
                local_4c = 0x100000;
              }
              EnMessageQueueData(In_00,local_4c,0);
            }
          }
          else {
            if (puVar9 == (undefined *)0x100001) {
              if (CurrentSection == 0) {
                ControlFlag = 0x41101;
                if ((Raziel.Mode & 0x40000U) == 0) {
                  SteerSwitchMode(In->CharacterInstance,0);
                  ControlFlag = ControlFlag | 8;
                }
                else {
                  SteerSwitchMode(In->CharacterInstance,0xb);
                }
                PhysicsMode = 3;
                Raziel.Mode = Raziel.Mode | 0x20000;
                pp_Var10[0x47] = (_Instance *)0x0;
                Inst = razGetHeldWeapon();
                if (Inst != (_Instance *)0x0) {
                  Raziel._1132_4_ = razGetHeldItem();
                  local_4c = Raziel.padCommands.Queue[13].ID;
                  if (Raziel.Senses.heldClass == 3) {
                    Raziel.attackedBy =
                         *(_Instance **)(*(int *)(Raziel.padCommands.Queue[13].ID + 0x14) + 8);
                  }
                  else {
                    if (Raziel.Senses.heldClass < 4) {
                      if (Raziel.Senses.heldClass == 1) {
                        Raziel.attackedBy =
                             *(_Instance **)
                              &(*(_Instance **)(Raziel.padCommands.Queue[13].ID + 0x14))->node;
                      }
                      else {
                        if (Raziel.Senses.heldClass == 2) {
                          Raziel.attackedBy =
                               *(_Instance **)(*(int *)(Raziel.padCommands.Queue[13].ID + 0x14) + 4)
                          ;
                        }
                      }
                    }
                    else {
                      if (Raziel.Senses.heldClass == 8) {
                        pp_Var10[0x47] = (_Instance *)0x1;
                        Raziel.attackedBy = *(_Instance **)(*(int *)(local_4c + 0x14) + 0x10);
                        Raziel._1132_4_ = (_Instance *)0x0;
                      }
                      else {
                        if (Raziel.Senses.heldClass == 0x1000) {
                          Raziel._1132_4_ = (_Instance *)0x0;
                          Raziel.attackedBy =
                               *(_Instance **)
                                (*(int *)(Raziel.padCommands.Queue[13].ID + 0x14) + 0x14);
                          INSTANCE_Post(Raziel.soulReaver,0x800104,0);
                        }
                      }
                    }
                  }
                }
                Raziel.throwData = (__ThrowItem *)0x0;
              }
              if (CurrentSection == 2) {
                CurrentSection_00 = 2;
                local_4c = CurrentSection;
                if ((Raziel.Mode & 0x40000U) == 0) {
                  CurrentSection_00 = 2;
                  NewAnim = 0;
                  local_50 = 3;
                }
                else {
                  NewAnim = 0x3d;
                  local_50 = 3;
                }
LAB_8009ad6c:
                G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_50,local_4c);
              }
              else {
                if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
                  bVar1 = *(byte *)&((Raziel.attackedBy)->node).prev;
                  if (bVar1 == 0) {
                    bVar1 = *(byte *)((int)&((Raziel.attackedBy)->node).prev + 3);
                    bVar2 = *(byte *)&((Raziel.attackedBy)->node).next;
                    bVar3 = *(byte *)((int)&((Raziel.attackedBy)->node).next + 1);
                  }
                  else {
                    bVar2 = *(byte *)((int)&((Raziel.attackedBy)->node).prev + 1);
                    bVar3 = *(byte *)((int)&((Raziel.attackedBy)->node).prev + 2);
                  }
                  G2EmulationSwitchAnimationAlpha
                            (In,CurrentSection,(uint)bVar1,0,(uint)bVar2,1,(uint)bVar3);
                  pp_Var10[0x48] = (_Instance *)0x1;
                  goto LAB_8009b31c;
                }
                if (uVar5 != 0x3f) {
                  CurrentSection_00 = 0;
                  NewAnim = 0x3f;
                  local_50 = 0x10;
                  local_4c = 2;
                  goto LAB_8009ad6c;
                }
              }
              pp_Var10[0x48] = (_Instance *)0x1;
            }
            else {
              if ((int)puVar9 < 0x100002) {
                if (puVar9 != (undefined *)0x100000) goto LAB_8009b30c;
                if ((Raziel.Mode & 0x40000U) == 0) {
                  local_4c = SetControlInitIdleData
                                       (0,0,(uint)*(byte *)((int)&(Raziel.attackedBy)->next + 1));
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_4c);
                  if (((*PadData & 0x800) == 0) || ((*PadData & 0x400) == 0)) goto LAB_8009b31c;
                  Raziel._1140_4_ = StateHandlerIdle;
                  NewProcess = StateHandlerLookAround;
                }
                else {
                  NewProcess = StateHandlerSwim;
                }
LAB_8009b24c:
                StateSwitchStateData(In,CurrentSection,NewProcess,0);
              }
              else {
                if (puVar9 != (undefined *)0x100004) goto LAB_8009b30c;
                G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,300);
                razSetFadeEffect(In->CharacterInstance->fadeValue,0,
                                 -*(int *)(Raziel.padCommands.Queue[13].ID + 0x28));
                if ((CurrentSection == 1) && (Raziel.padCommands.Queue[9].ID != 0)) {
                  SndEndLoop(Raziel.padCommands.Queue[9].ID);
                  Raziel.padCommands.Queue[9].ID = 0;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar9 == (undefined *)0x8000000) {
          uVar5 = G2EmulationQueryAnimation(In,CurrentSection);
          Raziel.throwData = (__ThrowItem *)((uint)Raziel.throwData & 0xfffffffb);
          if (uVar5 == (uint)*(byte *)&((Raziel.attackedBy)->node).prev) {
            if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
              G2EmulationSwitchAnimationAlpha
                        (In,CurrentSection,
                         (uint)*(byte *)((int)&((Raziel.attackedBy)->node).prev + 3),0,
                         (uint)*(byte *)&((Raziel.attackedBy)->node).next,1,
                         (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 1));
            }
          }
          else {
            if ((uVar5 == (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 2)) &&
               (CurrentSection == 1)) {
              INSTANCE_Post(In->CharacterInstance,0x100000,0);
            }
          }
        }
        else {
          if ((int)puVar9 < 0x8000001) {
            if (puVar9 != (undefined *)0x1000001) {
              if ((int)puVar9 < 0x1000002) {
                if (puVar9 == (undefined *)0x200004) {
                  Inst = In->CharacterInstance;
                  pvVar8 = (void *)p_Var6->Data;
                  Inst->collideInfo = pvVar8;
                  *(undefined2 *)((int)pvVar8 + 0x2c) = 0;
                  RazielCollide(Inst,&gameTrackerX);
                  goto LAB_8009b31c;
                }
              }
              else {
                if (puVar9 == (undefined *)0x4000001) {
                  if (CurrentSection == 0) {
                    SetDropPhysics(In->CharacterInstance,&Raziel);
                  }
                  G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
                  NewProcess = StateHandlerFall;
                  goto LAB_8009b24c;
                }
              }
LAB_8009b30c:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar9 == (undefined *)0x20000002) {
              if ((pp_Var10[0x47] != (_Instance *)0x0) &&
                 (NewAnim_00 = (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 2),
                 uVar5 != NewAnim_00)) {
                if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
                  G2EmulationSwitchAnimation
                            (In,CurrentSection,NewAnim_00,0,
                             (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 3),1);
                }
                if (CurrentSection == 1) {
                  Raziel.padCommands.Queue[8].ID._0_2_ =
                       (ushort)*(byte *)&(Raziel.attackedBy)->next * 100;
                  (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5b20;
                }
              }
            }
            else {
              if ((int)puVar9 < 0x20000003) {
                if (puVar9 != (undefined *)0x8000004) goto LAB_8009b30c;
                Inst = razGetHeldWeapon();
                if (Inst == (_Instance *)0x0) goto LAB_8009b31c;
                if (((uint)Raziel.throwData & 2) == 0) {
                  if ((Raziel.Senses.EngagedMask & 0x80) == 0) {
                    target = (int *)0x0;
                    type = 0;
                    uVar4 = *(ushort *)&(Raziel.attackedBy)->flags2;
                    local_4c = 0;
                    goto LAB_8009b1d4;
                  }
                  local_4c = SetObjectThrowData(Raziel.Senses.EngagedList[7].instance,
                                                (_SVector *)0x0,1,0,
                                                (uint)*(ushort *)&(Raziel.attackedBy)->flags2,
                                                (int)*(short *)((int)&(Raziel.attackedBy)->flags2 +
                                                               2),0,-0x400);
                  INSTANCE_Post(Inst,0x800010,local_4c);
                  uVar7 = INSTANCE_Query(Raziel.Senses.EngagedList[7].instance,0xc);
                  local_40.x = *(short *)(uVar7 + 0x14);
                  local_40.y = *(short *)(uVar7 + 0x18);
                  local_40.z = *(short *)(uVar7 + 0x1c);
                  PointAt(In->CharacterInstance,&local_40,&_Stack56);
                }
                else {
                  target = &Raziel.throwMode;
                  type = 4;
                  uVar4 = *(ushort *)&(Raziel.attackedBy)->flags2;
                  local_4c = (int)*(short *)((int)&(Raziel.attackedBy)->flags2 + 2);
LAB_8009b1d4:
                  local_4c = SetObjectThrowData(target,(_SVector *)0x0,type,0,(uint)uVar4,local_4c,0
                                                ,-0x400);
                  INSTANCE_Post(Inst,0x800010,local_4c);
                }
                razReaverOn();
              }
              else {
                if (puVar9 != (undefined *)0x20000020) goto LAB_8009b30c;
                if ((pp_Var10[0x48] != (_Instance *)0x0) &&
                   (NewAnim_00 = (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 2),
                   uVar5 != NewAnim_00)) {
                  if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
                    G2EmulationSwitchAnimation
                              (In,CurrentSection,NewAnim_00,0,
                               (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 3),1);
                  }
                  if (CurrentSection == 1) {
                    Raziel.padCommands.Queue[8].ID._0_2_ =
                         (ushort)*(byte *)&(Raziel.attackedBy)->next * 100;
                    (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5b20;
                  }
                  pp_Var10[0x48] = (_Instance *)0x0;
                }
              }
            }
          }
        }
      }
    }
LAB_8009b31c:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ PointAt(struct _Instance *instance /*$s0*/, struct _Position *Target /*$s1*/, struct _Rotation *Rot1 /*$s2*/)
 // line 1116, offset 0x8009b4a8
	/* begin block 1 */
		// Start line: 1117
		// Start offset: 0x8009B4A8
		// Variables:
	// 		struct _Position From; // stack offset -48
	// 		struct SVECTOR v1; // stack offset -40
	// 		struct VECTOR v3; // stack offset -32
	// 		struct MATRIX *tempMat; // $a0
	/* end block 1 */
	// End offset: 0x8009B594
	// End Line: 1149

	/* begin block 2 */
		// Start line: 2243
	/* end block 2 */
	// End Line: 2244

	/* begin block 3 */
		// Start line: 2251
	/* end block 3 */
	// End Line: 2252

/* WARNING: Could not reconcile some variable overlaps */

void PointAt(_Instance *instance,_Position *Target,_Rotation *Rot1)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  _G2Anim_Type *anim;
  _Position local_30;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  local_28 = *(undefined2 *)((int)&(Raziel.attackedBy)->next + 2);
  local_26 = *(undefined2 *)&(Raziel.attackedBy)->prev;
  local_24 = *(undefined2 *)((int)&(Raziel.attackedBy)->prev + 2);
  ApplyMatrix(instance->matrix,&local_28,&local_20);
  local_20 = local_20 + (instance->position).x;
  local_1c = local_1c + (instance->position).y;
  local_18 = local_18 + (instance->position).z;
  local_30.x = (short)local_20;
  local_30.y = (short)local_1c;
  local_30.z = (short)local_18;
  MATH3D_RotationFromPosToPos(&local_30,Target,Rot1);
  sVar1 = (instance->rotation).z;
  Rot1->y = 0;
  Rot1->z = Rot1->z - sVar1;
  LimitRotation(Rot1);
  anim = &instance->anim;
  _Var2 = G2Anim_IsControllerActive(anim,0xe,0xe);
  if (_Var2 == G2FALSE) {
    G2Anim_EnableController(anim,0xe,0xe);
  }
  MATH3D_ZYXtoXYZ(Rot1);
  G2Anim_SetController_Vector(anim,0xe,0xe,(_G2SVector3_Type *)Rot1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ThrowSetFocusPoint(struct _Instance *instance /*$s4*/, struct _Rotation *rot /*$s2*/)
 // line 1154, offset 0x8009b5c8
	/* begin block 1 */
		// Start line: 1155
		// Start offset: 0x8009B5C8
		// Variables:
	// 		struct MATRIX *pTempMat; // $s0
	// 		struct _Instance *weaponInstance; // $s1
	// 		struct SVECTOR v1; // stack offset -48
	// 		struct VECTOR v4; // stack offset -40
	/* end block 1 */
	// End offset: 0x8009B6EC
	// End Line: 1201

	/* begin block 2 */
		// Start line: 2354
	/* end block 2 */
	// End Line: 2355

/* WARNING: Could not reconcile some variable overlaps */

void ThrowSetFocusPoint(_Instance *instance,_Rotation *rot)

{
  MATRIX *pMVar1;
  _Instance *p_Var2;
  _G2Bool_Enum _Var3;
  _G2Anim_Type *anim;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  long local_28;
  long local_24;
  long local_20;
  
  rot->x = -rot->x;
  pMVar1 = theCamera.core.cwTransform2;
  p_Var2 = razGetHeldWeapon();
  if ((p_Var2 != (_Instance *)0x0) && (p_Var2->matrix != (MATRIX *)0x0)) {
    local_30 = 0;
    local_2e = 0;
    local_2c = *(undefined2 *)&(Raziel.attackedBy)->flags2;
    ApplyMatrix(pMVar1,&local_30,(VECTOR *)&local_28);
    anim = &instance->anim;
    Raziel.throwMode._0_2_ = (undefined2)local_28;
    Raziel.throwMode._2_2_ = (undefined2)local_24;
    Raziel.throwTarget.x = (short)local_20;
    _Var3 = G2Anim_IsControllerActive(anim,0xe,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,0xe,0xe);
    }
    MATH3D_ZYXtoXYZ(rot);
    G2Anim_SetController_Vector(anim,0xe,0xe,(_G2SVector3_Type *)rot);
    local_28 = p_Var2->matrix[1].t[0];
    local_24 = p_Var2->matrix[1].t[1];
    local_20 = p_Var2->matrix[1].t[2];
    CAMERA_SetLookFocusAndDistance
              (&theCamera,(VECTOR *)&local_28,*(int *)(Raziel.padCommands.Queue[13].ID + 0x2c));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LimitRotation(struct _Rotation *rot /*$a1*/)
 // line 1202, offset 0x8009b70c
	/* begin block 1 */
		// Start line: 2468
	/* end block 1 */
	// End Line: 2469

void LimitRotation(_Rotation *rot)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  rot->z = rot->z & 0xfff;
  iVar5 = (int)rot->z;
  rot->x = rot->x & 0xfff;
  iVar4 = iVar5;
  while (0x1000 < iVar4) {
    iVar5 = iVar5 + -0x1000;
    rot->z = (short)iVar5;
    iVar4 = iVar5 * 0x10000 >> 0x10;
  }
  sVar1 = rot->z;
  sVar3 = rot->z + 0x1000;
  if (sVar1 < 1) {
    rot->z = sVar3;
    bVar2 = sVar3 < *(short *)((int)&(Raziel.attackedBy)->flags + 2);
    sVar3 = *(short *)((int)&(Raziel.attackedBy)->flags + 2);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)&(Raziel.attackedBy)->flags;
      bVar2 = *(short *)&(Raziel.attackedBy)->flags < sVar1;
    }
    else {
      sVar3 = *(short *)((int)&(Raziel.attackedBy)->flags + 2);
      bVar2 = sVar1 < *(short *)((int)&(Raziel.attackedBy)->flags + 2);
    }
  }
  if (bVar2) {
    rot->z = sVar3;
  }
  iVar5 = (int)rot->x;
  iVar4 = iVar5;
  while (0x1000 < iVar4) {
    iVar5 = iVar5 + -0x1000;
    rot->x = (short)iVar5;
    iVar4 = iVar5 * 0x10000 >> 0x10;
  }
  sVar1 = rot->x;
  sVar3 = rot->x + 0x1000;
  if (sVar1 < 1) {
    rot->x = sVar3;
    bVar2 = sVar3 < *(short *)((int)&(Raziel.attackedBy)->instanceID + 2);
    sVar3 = *(short *)((int)&(Raziel.attackedBy)->instanceID + 2);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)&(Raziel.attackedBy)->instanceID;
      bVar2 = *(short *)&(Raziel.attackedBy)->instanceID < sVar1;
    }
    else {
      sVar3 = *(short *)((int)&(Raziel.attackedBy)->instanceID + 2);
      bVar2 = sVar1 < *(short *)((int)&(Raziel.attackedBy)->instanceID + 2);
    }
  }
  if (bVar2) {
    rot->x = sVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGrab(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 1257, offset 0x8009b880
	/* begin block 1 */
		// Start line: 1258
		// Start offset: 0x8009B880
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1289
			// Start offset: 0x8009BADC
			// Variables:
		// 		struct _Instance *Inst; // $a1
		/* end block 1.1 */
		// End offset: 0x8009BB4C
		// End Line: 1298

		/* begin block 1.2 */
			// Start line: 1319
			// Start offset: 0x8009BBAC
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009BBD4
		// End Line: 1331

		/* begin block 1.3 */
			// Start line: 1410
			// Start offset: 0x8009BD8C
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.3 */
		// End offset: 0x8009BE24
		// End Line: 1432

		/* begin block 1.4 */
			// Start line: 1435
			// Start offset: 0x8009BE24
			// Variables:
		// 		struct _Instance *instance; // $a0
		/* end block 1.4 */
		// End offset: 0x8009BE48
		// End Line: 1443

		/* begin block 1.5 */
			// Start line: 1446
			// Start offset: 0x8009BE50
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.5 */
		// End offset: 0x8009BE84
		// End Line: 1450

		/* begin block 1.6 */
			// Start line: 1456
			// Start offset: 0x8009BEE8
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.6 */
		// End offset: 0x8009BF0C
		// End Line: 1461
	/* end block 1 */
	// End offset: 0x8009BF8C
	// End Line: 1493

	/* begin block 2 */
		// Start line: 2582
	/* end block 2 */
	// End Line: 2583

void StateHandlerGrab(__CharacterState *In,int CurrentSection,int Data)

{
  uint uVar1;
  __Event *p_Var2;
  void *pvVar3;
  _Instance *instance;
  int Data_00;
  undefined *puVar4;
  _Instance *Sender;
  uint NewAnim;
  __State *p_Var5;
  _Instance **pp_Var6;
  uint local_30;
  int local_2c;
  
  uVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&p_Var5->Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x200004) {
      instance = In->CharacterInstance;
      pvVar3 = (void *)p_Var2->Data;
      instance->collideInfo = pvVar3;
      *(undefined2 *)((int)pvVar3 + 0x2c) = 0;
      RazielCollide(instance,&gameTrackerX);
    }
    else {
      if ((int)puVar4 < 0x200005) {
        if (puVar4 == (undefined *)0x0) {
          if ((CurrentSection == 0) && (SteerSwitchMode(In->CharacterInstance,0), uVar1 == 1)) {
            Data_00 = 0x37;
LAB_8009bc24:
            G2EmulationSwitchAnimation(In,0,Data_00,0,3,2);
          }
        }
        else {
          if ((int)puVar4 < 1) {
            if (puVar4 != &DAT_80000008) {
              if ((int)puVar4 < -0x7ffffff7) {
                if (puVar4 != (undefined *)0x80000000) goto LAB_8009bf74;
              }
              else {
                if (puVar4 != &DAT_80000020) goto LAB_8009bf74;
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x100004) {
              instance = razGetHeldItem();
              if ((instance != (_Instance *)0x0) && (CurrentSection == 1)) {
                Sender = In->CharacterInstance;
LAB_8009bdf8:
                Data_00 = SetMonsterThrownData(Sender,&Sender->rotation,100);
                INSTANCE_Post(instance,0x1000003,Data_00);
                razReaverOn();
              }
            }
            else {
              if ((int)puVar4 < 0x100005) {
                if (puVar4 != (undefined *)0x100001) goto LAB_8009bf74;
                if (CurrentSection == 0) {
                  Raziel.attackedBy = (_Instance *)PlayerData->throwList[6];
                  ControlFlag = 0x1043009;
                  PhysicsMode = 3;
                  SteerSwitchMode(In->CharacterInstance,0);
                }
                if (p_Var2->Data == 0) {
                  if ((CurrentSection == 1) &&
                     (G2EmulationSwitchAnimationCharacter
                                (In,0x47,0,
                                 (uint)*(byte *)((int)&((Raziel.attackedBy)->node).prev + 1),1),
                     (Raziel.Senses.EngagedMask & 0x100) != 0)) {
                    INSTANCE_Post(Raziel.Senses.EngagedList[8].instance,0x1000002,0);
                  }
                  pp_Var6[0x47] = (_Instance *)0x0;
                }
                else {
                  razSetPlayerEventHistory(0x40);
                  if (CurrentSection == 2) {
                    NewAnim = 0;
                    local_30 = 3;
                    Data_00 = 2;
                    local_2c = CurrentSection;
                  }
                  else {
                    NewAnim = (uint)*(byte *)&((Raziel.attackedBy)->node).prev;
                    local_30 = (uint)*(byte *)((int)&((Raziel.attackedBy)->node).prev + 1);
                    local_2c = 1;
                    Data_00 = CurrentSection;
                  }
                  G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
                  if (CurrentSection == 1) {
                    if ((Raziel.Senses.EngagedMask & 0x100) != 0) {
                      razAlignYRotMoveInterp
                                (In->CharacterInstance,Raziel.Senses.EngagedList[8].instance,200,
                                 '\0',(uint)*(byte *)((int)&((Raziel.attackedBy)->node).prev + 1),0)
                      ;
                    }
                    Raziel.padCommands.Queue[8].ID._0_2_ =
                         (ushort)*(byte *)&((Raziel.attackedBy)->node).next * 100;
                    (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5b20;
                  }
                  Raziel.Mode = 0x20000000;
                  pp_Var6[0x47] = (_Instance *)0x0;
                }
              }
              else {
                if (puVar4 != (undefined *)0x100014) goto LAB_8009bf74;
                if ((CurrentSection == 0) &&
                   (instance = razGetHeldItem(), instance != (_Instance *)0x0)) {
                  Data_00 = SetMonsterThrownData
                                      (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                  INSTANCE_Post(instance,0x1000003,Data_00);
                }
LAB_8009be84:
                local_2c = SetControlInitIdleData
                                     (0,0,(uint)*(byte *)((int)&(Raziel.attackedBy)->next + 1));
                Data_00 = CurrentSection;
LAB_8009bea4:
                StateSwitchStateData(In,Data_00,StateHandlerIdle,local_2c);
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var2->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
          goto LAB_8009bf74;
        }
        if ((int)puVar4 < 0x4010081) {
          if (puVar4 != (undefined *)0x1000001) {
            if ((int)puVar4 < 0x1000002) {
              if (puVar4 == (undefined *)0x1000000) {
                if (((CurrentSection == 0) && ((ControlFlag & 0x4000U) == 0)) &&
                   (Raziel.invincibleTimer == 0)) {
                  StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var2->Data);
                  instance = razGetHeldItem();
                  if (instance != (_Instance *)0x0) {
                    Data_00 = SetMonsterThrownData
                                        (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                    INSTANCE_Post(instance,0x1000003,Data_00);
                  }
                }
                goto LAB_8009bf7c;
              }
            }
            else {
              if (puVar4 == (undefined *)0x1000006) goto LAB_8009be84;
            }
LAB_8009bf74:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
        else {
          if (puVar4 == (undefined *)0x8000004) {
            if (uVar1 != (uint)*(byte *)&((Raziel.attackedBy)->node).prev) {
              instance = razGetHeldItem();
              Sender = In->CharacterInstance;
              goto LAB_8009bdf8;
            }
            if ((Raziel.Senses.EngagedMask & 0x100) != 0) {
              INSTANCE_Post(Raziel.Senses.EngagedList[8].instance,0x1000002,
                            (int)In->CharacterInstance);
              razReaverOff();
              In->SectionList[0].Data1 = 1;
              In->SectionList[1].Data1 = 1;
              In->SectionList[2].Data1 = 1;
            }
          }
          else {
            if ((int)puVar4 < 0x8000005) {
              if (puVar4 != (undefined *)0x8000000) goto LAB_8009bf74;
              if ((uVar1 == (uint)*(byte *)&((Raziel.attackedBy)->node).prev) &&
                 (CurrentSection == 0)) {
                G2EmulationSwitchAnimation(In,0,0x37,0,3,2);
              }
              if ((uVar1 == (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 2)) ||
                 (uVar1 == 0x47)) {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
                if (CurrentSection == 1) {
                  local_2c = SetControlInitIdleData(0,0,3);
                  Data_00 = 2;
                  goto LAB_8009bea4;
                }
              }
            }
            else {
              if (puVar4 == (undefined *)0x10000000) {
                if ((CurrentSection == 0) &&
                   (SteerSwitchMode(In->CharacterInstance,1), uVar1 == 0x37)) {
                  Data_00 = 1;
                  goto LAB_8009bc24;
                }
              }
              else {
                if (puVar4 != (undefined *)0x20000020) goto LAB_8009bf74;
                if (pp_Var6[0x47] == (_Instance *)0x0) {
                  EnMessageQueueData(&p_Var5->Defer,0x20000020,0);
                }
                else {
                  local_30 = (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 2);
                  if (uVar1 != local_30) {
                    G2EmulationSwitchAnimation
                              (In,CurrentSection,local_30,0,
                               (uint)*(byte *)((int)&((Raziel.attackedBy)->node).next + 3),1);
                    Raziel.Mode = 0x20000;
                    if (CurrentSection == 1) {
                      Raziel.padCommands.Queue[8].ID._0_2_ =
                           (ushort)*(byte *)&(Raziel.attackedBy)->next * 100;
                      (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5b20;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_8009bf7c:
    DeMessageQueue(&p_Var5->Event);
  } while( true );
}





