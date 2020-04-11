#include "THISDUST.H"
#include "ATTACK.H"


// decompiled code
// original method signature: 
// int /*$ra*/ StateHandlerDecodeHold(int *Message /*$s3*/, int *Data /*$s4*/)
 // line 16, offset 0x8009b184
	/* begin block 1 */
		// Start line: 17
		// Start offset: 0x8009B184
		// Variables:
	// 		int rc; // $s2
	// 		int WhoAmI; // $s0
	// 		struct _Instance *heldInstance; // $s1

		/* begin block 1.1 */
			// Start line: 53
			// Start offset: 0x8009B2B0
			// Variables:
		// 		int hitState; // $v1
		/* end block 1.1 */
		// End offset: 0x8009B39C
		// End Line: 87

		/* begin block 1.2 */
			// Start line: 109
			// Start offset: 0x8009B404
			// Variables:
		// 		struct _Instance *heldWeapon; // $v1
		/* end block 1.2 */
		// End offset: 0x8009B468
		// End Line: 129
	/* end block 1 */
	// End offset: 0x8009B494
	// End Line: 139

	/* begin block 2 */
		// Start line: 32
	/* end block 2 */
	// End Line: 33

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

int StateHandlerDecodeHold(int *Message,int *Data)

{
  _Instance *Inst;
  uint uVar1;
  ulong uVar2;
  int iVar3;
  
  iVar3 = 1;
  Inst = razGetHeldWeapon();
  if (DAT_800d5b78 == 2) {
    *Data = 1;
    *Message = -0x80000000;
    if ((DAT_800d5b1c & 0x200) != 0) {
      return 1;
    }
    if (DAT_800d5b2c != 0x1000) {
      return 0;
    }
    if ((DAT_800d5b48 & 4) == 0) {
      return 0;
    }
    *Message = 0x800010;
    return 1;
  }
  uVar1 = 0;
  if ((DAT_800d5b1c & 0x200) != 0) {
    uVar2 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x48),1);
    uVar1 = uVar2 & 8;
  }
  if (uVar1 != 0) {
    *Data = 1;
    if (DAT_800d5b2c == 0x1000) {
      *Message = 0x1000023;
    }
    else {
      *Message = -0x80000000;
    }
    goto LAB_8009b468;
  }
  if (((((DAT_800d5b1c & 0x200) == 0) || (Inst == (_Instance *)0x0)) || (DAT_800d5b2c == 3)) ||
     (DAT_800d5b2c == 8)) {
    if (((DAT_800d5b1c & 0x100) != 0) && (Inst == (_Instance *)0x0)) {
      uVar2 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x40),0);
      if ((int)uVar2 < 0) {
        *Data = 1;
        *Message = 0x1000002;
      }
      else {
        *Data = 0;
        *Message = 0x1000002;
      }
      goto LAB_8009b468;
    }
    Inst = razGetHeldWeapon();
    if (Inst == (_Instance *)0x0) {
      if ((DAT_800d5b48 & 4) != 0) {
        *Message = 0x80000;
        goto LAB_8009b468;
      }
    }
    else {
      if ((Inst != DAT_800d5b70) || ((DAT_800d5b48 & 4) != 0)) {
        *Message = 0x800010;
        goto LAB_8009b468;
      }
    }
  }
  else {
    uVar2 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x48),0);
    if ((uVar2 & 0x2000000) == 0) {
      if ((uVar2 & 0x10000000) == 0) {
        *Data = 0;
      }
      else {
        *Data = 1;
      }
      *Message = 0x100000a;
      if (Inst == DAT_800d5b70) {
        *Message = 0x1000023;
        if ((uVar2 & 0x1000000) != 0) {
          *Data = 1;
        }
      }
      else {
        uVar2 = INSTANCE_Query(Inst,2);
        if (((uVar2 & 0x20) != 0) && (*Message = 0x1000018, *Data != 0)) {
          uVar2 = INSTANCE_Query(Inst,3);
          if ((uVar2 & 0x10000) == 0) {
            *Data = 0;
          }
          else {
            *Data = 1;
          }
        }
      }
      goto LAB_8009b468;
    }
    if (Inst == DAT_800d5b70) {
      *Message = 0x1000023;
      *Data = 1;
      goto LAB_8009b468;
    }
  }
  iVar3 = 0;
LAB_8009b468:
  if (DAT_800d5b2c != 3) {
    return iVar3;
  }
  if (*Message == 0x800010) {
    return iVar3;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAttack2(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 149, offset 0x8009b4b4
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8009B4B4
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int message; // stack offset -64
	// 		int messageData; // stack offset -60
	// 		int Frame; // stack offset -56
	// 		int Anim; // stack offset -52

		/* begin block 1.1 */
			// Start line: 208
			// Start offset: 0x8009B804
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s3
		// 		unsigned long endColor; // $s2
		/* end block 1.1 */
		// End offset: 0x8009B930
		// End Line: 249

		/* begin block 1.2 */
			// Start line: 348
			// Start offset: 0x8009BC94
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s2
		// 		unsigned long endColor; // $s1
		/* end block 1.2 */
		// End offset: 0x8009BD78
		// End Line: 380

		/* begin block 1.3 */
			// Start line: 427
			// Start offset: 0x8009BECC
			// Variables:
		// 		struct _Instance *Inst; // $a0
		/* end block 1.3 */
		// End offset: 0x8009BF0C
		// End Line: 437

		/* begin block 1.4 */
			// Start line: 455
			// Start offset: 0x8009BF9C
		/* end block 1.4 */
		// End offset: 0x8009BF9C
		// End Line: 456

		/* begin block 1.5 */
			// Start line: 478
			// Start offset: 0x8009C050
		/* end block 1.5 */
		// End offset: 0x8009C098
		// End Line: 485

		/* begin block 1.6 */
			// Start line: 505
			// Start offset: 0x8009C124
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.6 */
		// End offset: 0x8009C1F0
		// End Line: 518

		/* begin block 1.7 */
			// Start line: 538
			// Start offset: 0x8009C2A4
			// Variables:
		// 		struct evMonsterHitData *hitData; // $s0
		/* end block 1.7 */
		// End offset: 0x8009C2BC
		// End Line: 543

		/* begin block 1.8 */
			// Start line: 562
			// Start offset: 0x8009C334
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v1
		/* end block 1.8 */
		// End offset: 0x8009C398
		// End Line: 569
	/* end block 1 */
	// End offset: 0x8009C398
	// End Line: 572

	/* begin block 2 */
		// Start line: 305
	/* end block 2 */
	// End Line: 306

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\RAZIEL\ATTACK.C */

void StateHandlerAttack2(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  ulong uVar2;
  undefined *puVar3;
  _Instance *instance;
  __MessageQueue *In_00;
  int mode;
  _Instance **pp_Var4;
  int NewAnim;
  code *NewProcess;
  long endColor;
  ulong startColor;
  __MessageQueue *In_01;
  int local_58;
  int local_54;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  __State *local_30;
  
  local_38 = G2EmulationQueryFrame(In,CurrentSection);
  local_34 = G2EmulationQueryAnimation(In,CurrentSection);
  if (((CurrentSection == 0) && ((ControlFlag & 0x10000000U) != 0)) && ((DAT_800d5aa4 & 2) == 0)) {
    mode = 2;
    if ((*PadData & 0x8000000fU) == 0) {
      instance = In->CharacterInstance;
      mode = 0;
    }
    else {
      instance = In->CharacterInstance;
    }
    SteerSwitchMode(instance,mode);
  }
  local_30 = In->SectionList + CurrentSection;
  In_01 = &local_30->Event;
  do {
    p_Var1 = PeekMessageQueue(In_01);
    mode = PlayerData;
    if (p_Var1 == (__Event *)0x0) {
      if (((DAT_800d5b8c & 4) != 0) &&
         ((int)((uint)DAT_800d5b88[4] * 100) <=
          (int)(In->CharacterInstance->anim).section[CurrentSection & 0xff].elapsedTime)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == (undefined *)0x1000002) {
      if (DAT_800d5b78 == 1) {
        StateSwitchStateData(In,CurrentSection,StateHandlerGrab,local_3c);
      }
    }
    else {
      if ((int)puVar3 < 0x1000003) {
        if (puVar3 == (undefined *)0x100000) {
          pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
          instance = (_Instance *)((int)&(pp_Var4[0x48]->node).prev + 1);
          pp_Var4[0x48] = instance;
          if (*(int *)((int)instance * 4 + *(int *)(DAT_800d5b90 * 4 + *(int *)(mode + 0x10))) == 0)
          {
            pp_Var4[0x48] = (_Instance *)0x1;
          }
          DAT_800d5b88 = *(byte **)((int)pp_Var4[0x48] * 4 +
                                   *(int *)(DAT_800d5b90 * 4 + *(int *)(PlayerData + 0x10)));
          G2EmulationSwitchAnimationAlpha
                    (In,CurrentSection,(uint)*DAT_800d5b88,0,(uint)DAT_800d5b88[1],1,
                     (uint)DAT_800d5b88[2]);
          if (CurrentSection == 1) {
            startColor = *(ulong *)(DAT_800d5b88 + 0x14);
            endColor = *(long *)(DAT_800d5b88 + 0x18);
            instance = razGetHeldWeapon();
            if (instance == (_Instance *)0x0) {
              instance = In->CharacterInstance;
            }
            else {
              instance = razGetHeldWeapon();
              uVar2 = INSTANCE_Query(instance,2);
              if ((uVar2 & 0x20) == 0) {
                if (DAT_800d5b2c == 0x1000) {
                  startColor = REAVER_GetGlowColor(instance);
                  endColor = 0;
                }
              }
              else {
                uVar2 = INSTANCE_Query(instance,3);
                if ((uVar2 & 0x10000) != 0) {
                  startColor = *(ulong *)(PlayerData + 4);
                  endColor = *(long *)(PlayerData + 8);
                }
              }
            }
            DAT_800d5b98 = DAT_800d5b94;
            DAT_800d5b94 = (_Instance *)0x0;
            FX_StartRibbon(instance,(ushort)DAT_800d5b88[0xb],(ushort)DAT_800d5b88[0xc],0,
                           (uint)DAT_800d5b88[0xd],(uint)DAT_800d5b88[0xe],
                           (int)*(short *)(DAT_800d5b88 + 0x12),startColor,endColor);
          }
          EnMessageQueueData(&local_30->Defer,(int)&DAT_00100002,0);
          PurgeMessageQueue(&local_30->Event);
        }
        else {
          if ((int)puVar3 < 0x100001) {
            if (puVar3 == (undefined *)0x80000001) {
              if (CurrentSection == 0) {
                if ((ControlFlag & 0x10000000U) == 0) {
                  mode = -0x7fffffff;
                  In_00 = &In->SectionList[0].Defer;
                  goto LAB_8009c28c;
                }
                DAT_800d5aa4 = 8;
                mode = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (mode != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
                ControlFlag = ControlFlag & 0xffffdfff;
              }
            }
            else {
              if ((int)puVar3 < -0x7fffffff) goto LAB_8009b994;
              if (puVar3 == &DAT_80000020) {
                mode = StateHandlerDecodeHold(&local_40,&local_3c);
                if (mode != 0) {
                  EnMessageQueueData(In_01,local_40,local_3c);
                }
              }
              else {
                if (puVar3 != (undefined *)0x80000) goto LAB_8009c300;
                DAT_800d5ce8 = DAT_800d5ce8 | 0x400;
                razSetPlayerEventHistory(0x400);
                StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
                if (CurrentSection == 1) {
                  razLaunchForce(In->CharacterInstance);
                }
              }
            }
          }
          else {
            if (puVar3 == &DAT_00100004) {
              if (CurrentSection == 1) {
                DisableWristCollision(In->CharacterInstance,2);
                DisableWristCollision(In->CharacterInstance,1);
                DAT_800d5b34 = 0x100;
                DAT_800d5b36 = 0xffa0;
              }
              DAT_800d5aa4 = DAT_800d5aa4 & 0xffdfffff;
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 == &DAT_00100001) {
                  DAT_800d5b90 = p_Var1->Data;
                  In->SectionList[CurrentSection].Data2 = 0;
                  instance = razGetHeldWeapon();
                  if (instance != (_Instance *)0x0) {
                    if (DAT_800d5b2c == 2) {
                      DAT_800d5b90 = p_Var1->Data + 2;
                    }
                    else {
                      if (DAT_800d5b2c < 3) {
                        if (DAT_800d5b2c == 1) {
                          DAT_800d5b90 = p_Var1->Data + 1;
                        }
                      }
                      else {
                        if (DAT_800d5b2c == 3) {
                          DAT_800d5b90 = p_Var1->Data + 4;
                        }
                        else {
                          if (DAT_800d5b2c == 0x1000) {
                            DAT_800d5b90 = p_Var1->Data + 3;
                          }
                        }
                      }
                    }
                  }
                  DAT_800d5b88 = *(byte **)(In->SectionList[CurrentSection].Data2 * 4 +
                                           *(int *)(DAT_800d5b90 * 4 + *(int *)(PlayerData + 0x10)))
                  ;
                  G2EmulationSwitchAnimationAlpha
                            (In,CurrentSection,(uint)*DAT_800d5b88,0,(uint)DAT_800d5b88[1],1,
                             (uint)DAT_800d5b88[2]);
                  if (CurrentSection == 1) {
                    startColor = *(ulong *)(DAT_800d5b88 + 0x14);
                    endColor = *(long *)(DAT_800d5b88 + 0x18);
                    instance = razGetHeldWeapon();
                    if (instance == (_Instance *)0x0) {
                      instance = In->CharacterInstance;
                    }
                    else {
                      instance = razGetHeldWeapon();
                      uVar2 = INSTANCE_Query(instance,2);
                      if ((uVar2 & 0x20) == 0) {
                        if (DAT_800d5b2c == 0x1000) {
                          startColor = REAVER_GetGlowColor(instance);
                          endColor = 0;
                        }
                      }
                      else {
                        uVar2 = INSTANCE_Query(instance,3);
                        if ((uVar2 & 0x10000) != 0) {
                          startColor = *(ulong *)(PlayerData + 4);
                          endColor = *(long *)(PlayerData + 8);
                        }
                      }
                    }
                    FX_StartRibbon(instance,(ushort)DAT_800d5b88[0xb],(ushort)DAT_800d5b88[0xc],0,
                                   (uint)DAT_800d5b88[0xd],(uint)DAT_800d5b88[0xe],
                                   (int)*(short *)(DAT_800d5b88 + 0x12),startColor,endColor);
                    mode = 9;
                    if (p_Var1->Data < 10) {
                      instance = In->CharacterInstance;
LAB_8009b918:
                      SteerSwitchMode(instance,mode);
                    }
                    else {
                      mode = 0xf;
                      if ((DAT_800d5b1c & 0x40) != 0) {
                        instance = In->CharacterInstance;
                        goto LAB_8009b918;
                      }
                    }
                    ControlFlag = ControlFlag | 0x2000;
                  }
                  DAT_800d5b98 = (_Instance *)0x0;
                  DAT_800d5b94 = (_Instance *)0x0;
                  DAT_800d5b9c = (_FXGlowEffect *)0x0;
                  DAT_800d5aa4 = DAT_800d5aa4 | 0x200000;
                }
                else {
                  if (puVar3 != &DAT_00100002) goto LAB_8009c300;
                  DAT_800d5b8c = 0;
                }
              }
              else {
                if (puVar3 == (undefined *)0x800010) {
                  NewProcess = StateHandlerThrow2;
                  goto LAB_8009c0c0;
                }
                if (puVar3 != (undefined *)0x1000001) goto LAB_8009c300;
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x2000000) {
LAB_8009b994:
          DAT_800d5b88 = *(byte **)(In->SectionList[CurrentSection].Data2 * 4 +
                                   *(int *)(DAT_800d5b90 * 4 + *(int *)(PlayerData + 0x10)));
          if ((local_34 == (uint)*DAT_800d5b88) && ((int)(uint)DAT_800d5b88[5] <= local_38)) {
            DAT_800d5b8c = DAT_800d5b8c | 4;
          }
          if ((CurrentSection == 1) && (DAT_800d5b9c != (_FXGlowEffect *)0x0)) {
            FX_StopGlowEffect(DAT_800d5b9c,0);
            DAT_800d5b9c = (_FXGlowEffect *)0x0;
          }
        }
        else {
          if ((int)puVar3 < 0x2000001) {
            if (puVar3 == (undefined *)0x1000018) {
              if (p_Var1->Data == 0) {
                if (CurrentSection == 1) {
                  mode = 0x5a;
LAB_8009bfe4:
                  G2EmulationSwitchAnimationCharacter(In,mode,0,3,CurrentSection);
                  if ((DAT_800d5b1c & 0x200) != 0) {
                    mode = 0x100000a;
                    instance = *(_Instance **)(DAT_800d5b18 + 0x48);
LAB_8009c014:
                    INSTANCE_Post(instance,mode,0);
                  }
                }
              }
              else {
                razSetPlayerEventHistory(0x100);
                ControlFlag = ControlFlag | 0x40000;
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  local_58 = 3;
                  mode = 2;
                  local_54 = CurrentSection;
                }
                else {
                  NewAnim = 0x8a;
                  local_58 = 0;
                  local_54 = 1;
                  mode = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,mode,NewAnim,0,local_58,local_54);
                if ((CurrentSection == 1) && ((DAT_800d5b1c & 0x200) != 0)) {
                  DAT_800d5c98 = 900;
                  razAlignYRotMoveInterp
                            (In->CharacterInstance,*(_Instance **)(DAT_800d5b18 + 0x48),0x1e6,'\0',
                             0x14,0);
                  (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5c98;
                }
              }
            }
            else {
              if ((int)puVar3 < 0x1000019) {
                if (puVar3 == (undefined *)0x100000a) {
                  if (p_Var1->Data == 0) {
                    if (CurrentSection == 1) {
                      mode = 0x48;
                      goto LAB_8009bfe4;
                    }
                  }
                  else {
                    razSetPlayerEventHistory(0x80);
                    ControlFlag = ControlFlag | 0x40000;
                    if (CurrentSection == 2) {
                      NewAnim = 0;
                      mode = 2;
                      local_54 = CurrentSection;
                    }
                    else {
                      NewAnim = 0x3b;
                      local_54 = 1;
                      mode = CurrentSection;
                    }
                    G2EmulationSwitchAnimation(In,mode,NewAnim,0,3,local_54);
                    StateSwitchStateData(In,CurrentSection,StateHandlerCannedReaction,0);
                    if ((CurrentSection == 0) && ((DAT_800d5b1c & 0x200) != 0)) {
                      razAlignYRotMoveInterp
                                (In->CharacterInstance,*(_Instance **)(DAT_800d5b18 + 0x48),0x208,
                                 '\0',3,0);
                    }
                  }
                }
                else {
LAB_8009c300:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar3 == (undefined *)0x100001f) {
                  if ((CurrentSection == 1) &&
                     (instance = (_Instance *)p_Var1->Data,
                     *(_Instance **)((int)&instance->node + 4) != (_Instance *)0x0)) {
                    mode = SetMonsterHitData(*(_Instance **)&instance->node,(_Instance *)0x0,
                                             (int)instance->prev,
                                             (uint)*(ushort *)(DAT_800d5b88 + 0x20),
                                             (uint)DAT_800d5b88[0xf]);
                    local_54 = 0x100001f;
                    instance = *(_Instance **)((int)&instance->node + 4);
LAB_8009c2f0:
                    INSTANCE_Post(instance,local_54,mode);
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x1000023) goto LAB_8009c300;
                  if ((CurrentSection == 0) &&
                     (razSwitchVAnimCharacterSingle
                                (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0),
                     (DAT_800d5b1c & 0x200) != 0)) {
                    INSTANCE_Post(*(_Instance **)(DAT_800d5b18 + 0x48),0x1000023,p_Var1->Data);
                    razAlignYRotMoveInterp
                              (In->CharacterInstance,*(_Instance **)(DAT_800d5b18 + 0x48),0x1e6,'\0'
                               ,0x14,0);
                    if (p_Var1->Data != 0) {
                      DAT_800d5c98 = 0xdac;
                      (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
                    }
                  }
                }
              }
            }
          }
          else {
            if (puVar3 != (undefined *)0x4020000) {
              if ((int)puVar3 < 0x4020001) {
                if (puVar3 == (undefined *)0x2000002) {
                  if (CurrentSection == 1) {
                    instance = (_Instance *)p_Var1->Data;
                    mode = (int)instance->prev * (uint)*(ushort *)(DAT_800d5b88 + 0x22);
                    if (mode < 0) {
                      mode = mode + 0xfff;
                    }
                    mode = SetMonsterHitData(In->CharacterInstance,DAT_800d5b98,mode >> 0xc,
                                             (uint)*(ushort *)(DAT_800d5b88 + 0x20),
                                             (uint)DAT_800d5b88[0xf]);
                    INSTANCE_Post(*(_Instance **)&instance->node,0x1000000,mode);
                    if ((DAT_800d5b88[8] & 2) != 0) {
                      mode = SetFXHitData(In->CharacterInstance,0x29,0x20,0x100);
                      INSTANCE_Post(*(_Instance **)&instance->node,0x400000,mode);
                    }
                    if ((DAT_800d5b88[8] & 1) != 0) {
                      mode = SetFXHitData(In->CharacterInstance,0x1f,0x20,0x100);
                      INSTANCE_Post(*(_Instance **)&instance->node,0x400000,mode);
                    }
                    DAT_800d5b94 = *(_Instance **)&instance->node;
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x4010080) goto LAB_8009c300;
                  if (CurrentSection == 0) {
                    if (p_Var1->Data == 0) {
                      razSetPauseTranslation(In->CharacterInstance);
                    }
                    else {
                      razResetPauseTranslation(In->CharacterInstance);
                    }
                  }
                }
              }
              else {
                if (puVar3 == (undefined *)0x8000000) {
                  if (((DAT_800d5b8c & 4) == 0) ||
                     (*(int *)(In->SectionList[CurrentSection].Data2 * 4 +
                               *(int *)(DAT_800d5b90 * 4 + *(int *)(PlayerData + 0x10)) + 4) == 0))
                  {
                    if (DAT_800d5b90 < 10) {
                      if ((DAT_800d5c80 < 7) && ((DAT_800d5b1c & 0x40) != 0)) {
                        NewProcess = StateHandlerAutoFace;
                        goto LAB_8009c0c0;
                      }
                      mode = SetControlInitIdleData(1,0,(uint)DAT_800d5b88[3]);
                      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,mode);
                    }
                    else {
                      if ((*PadData & 0x8000000fU) == 0) {
                        StateSwitchStateCharacterData(In,StateHandlerStopMove,0x3c);
                      }
                      else {
                        NewProcess = StateHandlerMove;
LAB_8009c0c0:
                        StateSwitchStateData(In,CurrentSection,NewProcess,0);
                      }
                    }
                  }
                  else {
                    In_00 = In_01;
                    if (DAT_800d5b90 < 10) {
                      mode = 0x100000;
                    }
                    else {
                      if ((*PadData & 0x8000000fU) == 0) goto LAB_8009c30c;
                      mode = 0x100000;
                    }
LAB_8009c28c:
                    EnMessageQueueData(In_00,mode,0);
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x8000004) goto LAB_8009c300;
                  if ((DAT_800d5b1c & 0x200) != 0) {
                    instance = *(_Instance **)(DAT_800d5b18 + 0x48);
                    mode = 0x1000;
                    if (DAT_800d5b2c == 0x1000) {
                      local_54 = 0x1000023;
                      goto LAB_8009c2f0;
                    }
                    INSTANCE_Post(instance,0x100000c,0x20);
                    instance = razGetHeldWeapon();
                    if (instance != (_Instance *)0x0) {
                      mode = 0x800029;
                      goto LAB_8009c014;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_8009c30c:
    DeMessageQueue(&local_30->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCannedReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 575, offset 0x8009c3c8
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8009C3C8
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 618
			// Start offset: 0x8009C58C
			// Variables:
		// 		struct _Instance *Inst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009C5A8
		// End Line: 621

		/* begin block 1.2 */
			// Start line: 631
			// Start offset: 0x8009C5B0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009C620
		// End Line: 648
	/* end block 1 */
	// End offset: 0x8009C63C
	// End Line: 691

	/* begin block 2 */
		// Start line: 1183
	/* end block 2 */
	// End Line: 1184

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

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
    if (puVar2 == &DAT_00100014) {
LAB_8009c54c:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
      DAT_800d5aa4 = 1;
    }
    else {
      if ((int)puVar2 < 0x100015) {
        if (puVar2 != &DAT_80000020) {
          if ((int)puVar2 < -0x7fffffdf) {
            if ((puVar2 != (undefined *)0x80000000) && (puVar2 != &DAT_80000008)) goto LAB_8009c624;
          }
          else {
            if (puVar2 == &DAT_00100001) {
              if (CurrentSection == 0) {
                DAT_800d5c98 = 0x1194;
                DAT_800d5aa4 = 0x10000;
                ControlFlag = 0x1041009;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
              }
            }
            else {
              if (puVar2 != &DAT_00100004) goto LAB_8009c624;
              if (CurrentSection == 1) {
                G2EmulationSwitchAnimationSync(In,2,1,4);
              }
            }
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x8000000) goto LAB_8009c54c;
        if ((int)puVar2 < 0x8000001) {
          if ((0x1000001 < (int)puVar2) || ((int)puVar2 < 0x1000000)) {
LAB_8009c624:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000003) {
            if (CurrentSection != 0) goto LAB_8009c62c;
            Inst = razGetHeldItem();
          }
          else {
            if (puVar2 != (undefined *)0x8000004) goto LAB_8009c624;
            Inst = razGetHeldItem();
            INSTANCE_Post(Inst,0x800008,2);
            razReaverOn();
          }
          if ((DAT_800d5b1c & 0x200) != 0) {
            Data_00 = SetMonsterImpaleData
                                (Inst,&In->CharacterInstance->rotation,
                                 &In->CharacterInstance->position,0x208);
            INSTANCE_Post(*(_Instance **)(DAT_800d5b18 + 0x48),0x100000a,Data_00);
          }
        }
      }
    }
LAB_8009c62c:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStumble(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$s6*/)
 // line 694, offset 0x8009c65c
	/* begin block 1 */
		// Start line: 695
		// Start offset: 0x8009C65C
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int processTime; // $s5

		/* begin block 1.1 */
			// Start line: 740
			// Start offset: 0x8009C95C
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009C95C
		// End Line: 742

		/* begin block 1.2 */
			// Start line: 750
			// Start offset: 0x8009C9B0
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8009C9B0
		// End Line: 751
	/* end block 1 */
	// End offset: 0x8009CA2C
	// End Line: 780

	/* begin block 2 */
		// Start line: 1451
	/* end block 2 */
	// End Line: 1452

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\RAZIEL\ATTACK.C */

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
      if ((((CurrentSection == 0) && (bVar1)) &&
          (Data_00 = In->SectionList[0].Data1 - DAT_800d2314, In->SectionList[0].Data1 = Data_00,
          Data_00 < 1)) && (Data_00 = STREAM_IsMorphInProgress(), Data_00 == 0)) {
        EnMessageQueueData((__MessageQueue *)&DAT_800d57dc,0x100000,0);
      }
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x100000) {
      if (((*PadData & RazielCommands[5]) == 0) || ((*PadData & RazielCommands[4]) == 0)) {
        Data_00 = SetControlInitIdleData(0,0,0xc);
        StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
      }
      else {
        DAT_800d5c48 = StateHandlerIdle;
        Data_00 = SetControlInitIdleData(0,0,0xc);
        StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
        StateSwitchStateCharacterData(In,StateHandlerLookAround,0);
      }
    }
    else {
      if ((int)puVar4 < 0x100001) {
        if (puVar4 != &DAT_80000020) {
          if ((int)puVar4 < -0x7fffffdf) {
            if ((puVar4 != (undefined *)0x80000000) && (puVar4 != &DAT_80000008)) goto LAB_8009c9cc;
          }
          else {
            if (puVar4 == (undefined *)0x40003) {
              if (CurrentSection == 0) {
                p_Var3 = (_Instance *)p_Var2->Data;
                G2EmulationInstanceToInstanceSwitchAnimationCharacter
                          (*(_Instance **)&p_Var3->node,*(_Instance **)((int)&p_Var3->node + 4),
                           (int)p_Var3->next,(int)p_Var3->prev,(int)p_Var3->instanceID,
                           (int)p_Var3->flags);
              }
            }
            else {
              if ((int)puVar4 < 0x40004) {
                if (puVar4 == (undefined *)0x0) {
                  pp_Var5[0x48] = (_Instance *)0x1;
                }
                else {
LAB_8009c9cc:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x40005) goto LAB_8009c9cc;
              }
            }
          }
        }
      }
      else {
        if (puVar4 != (undefined *)0x1000001) {
          if ((int)puVar4 < 0x1000002) {
            if (puVar4 == &DAT_00100004) {
              bVar1 = false;
              G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
            }
            else {
              if ((int)puVar4 < 0x100005) {
                if (puVar4 != &DAT_00100001) goto LAB_8009c9cc;
                if (CurrentSection == 0) {
                  ControlFlag = 8;
                  SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                  PhysicsMode = 0;
                  SteerSwitchMode(In->CharacterInstance,0);
                  razResetMotion(In->CharacterInstance);
                }
                pp_Var5[0x47] = (_Instance *)(p_Var2->Data * 0x1e);
                G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x800);
                G2EmulationSwitchAnimation(In,CurrentSection,0x80,0,3,2);
              }
              else {
                if (puVar4 != (undefined *)0x1000000) goto LAB_8009c9cc;
                if ((DAT_800d2190 & 0x800) != 0) {
                  LoseHealth(*(int *)(p_Var2->Data + 0xc));
                }
              }
            }
          }
          else {
            if (puVar4 != (undefined *)0x4000001) {
              if ((int)puVar4 < 0x4000002) {
                if (puVar4 != (undefined *)0x2000000) goto LAB_8009c9cc;
              }
              else {
                if (puVar4 != (undefined *)0x10000000) goto LAB_8009c9cc;
                if (pp_Var5[0x48] == (_Instance *)0x1) {
                  pp_Var5[0x48] = (_Instance *)0x0;
                  pp_Var5[0x47] = (_Instance *)(pp_Var5[0x47][-1].relativeMatrix.m + 2);
                }
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
 // line 801, offset 0x8009ca54
	/* begin block 1 */
		// Start line: 802
		// Start offset: 0x8009CA54
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 811
			// Start offset: 0x8009CB38
			// Variables:
		// 		struct evMonsterHitData *data; // $s0

			/* begin block 1.1.1 */
				// Start line: 815
				// Start offset: 0x8009CB44
				// Variables:
			// 		struct _Instance *weapon; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009CBD0
			// End Line: 836
		/* end block 1.1 */
		// End offset: 0x8009CC18
		// End Line: 843
	/* end block 1 */
	// End offset: 0x8009CCB0
	// End Line: 878

	/* begin block 2 */
		// Start line: 1595
	/* end block 2 */
	// End Line: 1596

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

void StateHandlerHitReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  int NewAnim;
  undefined *puVar2;
  code *NewProcess;
  undefined4 *puVar3;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001) {
      puVar3 = (undefined4 *)p_Var1->Data;
      if (CurrentSection == 0) {
        DAT_800d5ba0 = *puVar3;
        instance = razGetHeldWeapon();
        if (instance != (_Instance *)0x0) {
          TurnOffCollisionPhysOb(instance,7);
        }
        if ((DAT_800d2190 & 0x800) != 0) {
          LoseHealth(puVar3[3]);
        }
        PhysicsMode = 0;
        DAT_800d5aa4 = DAT_800d5aa4 | 0x208000;
        ControlFlag = ControlFlag & 0xf7ffffffU | 0x1008;
        ResetPhysics(In->CharacterInstance,-0x10);
        SteerSwitchMode(In->CharacterInstance,10);
      }
      if ((int)puVar3[3] < 0x1001) {
        NewAnim = 0x7d;
      }
      else {
        NewAnim = 0x38;
      }
      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,2,1);
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if ((-0x7fffffff < (int)puVar2) && (puVar2 != &DAT_80000020)) goto LAB_8009cc98;
      }
      else {
        if (puVar2 != (undefined *)0x4020000) {
          if ((int)puVar2 < 0x4020001) {
            if (puVar2 != (undefined *)0x1000000) {
LAB_8009cc98:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if ((0x8000001 < (int)puVar2) || ((int)puVar2 < 0x8000000)) goto LAB_8009cc98;
            if (CurrentSection == 0) {
              if ((ControlFlag & 0x100000U) == 0) {
                if ((DAT_800d5aa4 & 0x40000) == 0) {
                  NewAnim = SetControlInitIdleData(0,0,3);
                  StateSwitchStateCharacterData(In,StateHandlerIdle,NewAnim);
                  goto LAB_8009cca0;
                }
                NewProcess = StateHandlerSwim;
              }
              else {
                NewProcess = StateHandlerGlyphs;
              }
              StateSwitchStateCharacterData(In,NewProcess,0);
            }
          }
        }
      }
    }
LAB_8009cca0:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerThrow2(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 958, offset 0x8009ccd0
	/* begin block 1 */
		// Start line: 959
		// Start offset: 0x8009CCD0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1164
			// Start offset: 0x8009D41C
			// Variables:
		// 		struct _Instance *weaponInst; // $s0

			/* begin block 1.1.1 */
				// Start line: 1168
				// Start offset: 0x8009D430

				/* begin block 1.1.1.1 */
					// Start line: 1178
					// Start offset: 0x8009D490
					// Variables:
				// 		struct _Position To; // stack offset -64
				// 		struct _Rotation Rot; // stack offset -56
				// 		struct MATRIX *matrix; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8009D490
				// End Line: 1183
			/* end block 1.1.1 */
			// End offset: 0x8009D570
			// End Line: 1199
		/* end block 1.1 */
		// End offset: 0x8009D59C
		// End Line: 1203

		/* begin block 1.2 */
			// Start line: 1248
			// Start offset: 0x8009D6E0
			// Variables:
		// 		struct _Position To; // stack offset -64
		// 		struct _Rotation Rot; // stack offset -48
		// 		struct MATRIX *matrix; // $v0
		/* end block 1.2 */
		// End offset: 0x8009D724
		// End Line: 1258
	/* end block 1 */
	// End offset: 0x8009D724
	// End Line: 1281

	/* begin block 2 */
		// Start line: 1910
	/* end block 2 */
	// End Line: 1911

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

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
  undefined *puVar8;
  __MessageQueue *In_00;
  undefined2 *target;
  int CurrentSection_00;
  int local_54;
  ushort type;
  int NewAnim;
  code *NewProcess;
  _Instance **pp_Var9;
  __State *p_Var10;
  int local_58;
  _Position local_40;
  _Rotation _Stack56;
  _Rotation _Stack48;
  
  uVar5 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var10 = In->SectionList + CurrentSection;
  pp_Var9 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var6 = PeekMessageQueue(&p_Var10->Event);
    if (p_Var6 == (__Event *)0x0) {
      if ((CurrentSection == 1) && ((DAT_800d5b1c & 0x80) != 0)) {
        uVar7 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x38),0xc);
        local_40.x = *(short *)(uVar7 + 0x14);
        local_40.y = *(short *)(uVar7 + 0x18);
        local_40.z = *(short *)(uVar7 + 0x1c);
        PointAt(In->CharacterInstance,&local_40,&_Stack48);
      }
      return;
    }
    puVar8 = (undefined *)p_Var6->ID;
    if (puVar8 == &DAT_00100009) {
      if (CurrentSection == 1) {
        if (p_Var6->Data == 1) {
          if ((DAT_800d5b2c != 0x1000) && (DAT_800d5b2c != 8)) {
            razSetFadeEffect(In->CharacterInstance->fadeValue,*(short *)(PlayerData + 0x24),
                             (int)*(short *)(PlayerData + 0x26));
          }
          DAT_800d5c48 = StateHandlerIdle;
          DAT_800d5ba8 = 2;
        }
        else {
          razSetFadeEffect(In->CharacterInstance->fadeValue,0,-(int)*(short *)(PlayerData + 0x26));
          G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,600);
          DAT_800d5ba8 = 0;
        }
      }
    }
    else {
      if ((int)puVar8 < 0x10000a) {
        if (puVar8 != &DAT_80000020) {
          if ((int)puVar8 < -0x7fffffdf) {
            if (puVar8 != (undefined *)0x80000000) {
              if (puVar8 != &DAT_80000008) goto LAB_8009d6a8;
              if (DAT_800d5bb4 != (_Instance *)0x0) {
                local_54 = 0x100000;
                In_00 = &p_Var10->Event;
LAB_8009d40c:
                EnMessageQueueData(In_00,local_54,0);
              }
            }
          }
          else {
            if (puVar8 == &DAT_00100001) {
              if (CurrentSection == 0) {
                ControlFlag = 0x40041001;
                if ((DAT_800d5aa4 & 0x40000) == 0) {
                  SteerSwitchMode(In->CharacterInstance,0);
                  ControlFlag = ControlFlag | 8;
                }
                else {
                  SteerSwitchMode(In->CharacterInstance,0xb);
                }
                PhysicsMode = 3;
                DAT_800d5aa4 = DAT_800d5aa4 | 0x20000;
                pp_Var9[0x47] = (_Instance *)0x0;
                Inst = razGetHeldWeapon();
                if (Inst != (_Instance *)0x0) {
                  DAT_800d5bb4 = razGetHeldItem();
                  local_54 = PlayerData;
                  if (DAT_800d5b2c == 3) {
                    DAT_800d5ba4 = *(byte **)(*(int *)(PlayerData + 0x14) + 8);
                  }
                  else {
                    if (DAT_800d5b2c < 4) {
                      if (DAT_800d5b2c == 1) {
                        DAT_800d5ba4 = **(byte ***)(PlayerData + 0x14);
                      }
                      else {
                        if (DAT_800d5b2c == 2) {
                          DAT_800d5ba4 = *(byte **)(*(int *)(PlayerData + 0x14) + 4);
                        }
                      }
                    }
                    else {
                      if (DAT_800d5b2c == 8) {
                        pp_Var9[0x47] = (_Instance *)0x1;
                        DAT_800d5ba4 = *(byte **)(*(int *)(local_54 + 0x14) + 0x10);
                        DAT_800d5bb4 = (_Instance *)0x0;
                      }
                      else {
                        if (DAT_800d5b2c == 0x1000) {
                          DAT_800d5bb4 = (_Instance *)0x0;
                          DAT_800d5ba4 = *(byte **)(*(int *)(PlayerData + 0x14) + 0x14);
                          INSTANCE_Post(DAT_800d5b70,0x800104,0);
                          DAT_800d5c58 = DAT_800d5c58 | 4;
                          razSetupSoundRamp(In->CharacterInstance,(_SoundRamp *)&DAT_800d5ca0,0xc,
                                            -100,0,0x32,0x55,0x2d000,(int)&DAT_00002710);
                          DAT_800d5cd0 = 0;
                          DAT_800d5cd4 = 0;
                        }
                      }
                    }
                  }
                }
                DAT_800d5ba8 = 0;
              }
              if (CurrentSection == 2) {
                CurrentSection_00 = 2;
                local_54 = CurrentSection;
                if ((DAT_800d5aa4 & 0x40000) == 0) {
                  CurrentSection_00 = 2;
                  NewAnim = 0;
                  local_58 = 3;
                }
                else {
                  NewAnim = 0x3d;
                  local_58 = 3;
                }
LAB_8009d130:
                G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_58,local_54);
              }
              else {
                if (((DAT_800d5aa4 & 0x40000) == 0) || (CurrentSection != 0)) {
                  bVar1 = *DAT_800d5ba4;
                  if (bVar1 == 0) {
                    bVar1 = DAT_800d5ba4[3];
                    bVar2 = DAT_800d5ba4[4];
                    bVar3 = DAT_800d5ba4[5];
                  }
                  else {
                    bVar2 = DAT_800d5ba4[1];
                    bVar3 = DAT_800d5ba4[2];
                  }
                  G2EmulationSwitchAnimationAlpha
                            (In,CurrentSection,(uint)bVar1,0,(uint)bVar2,1,(uint)bVar3);
                }
                else {
                  if (uVar5 != 0x3f) {
                    CurrentSection_00 = 0;
                    NewAnim = 0x3f;
                    local_58 = 0x10;
                    local_54 = 2;
                    goto LAB_8009d130;
                  }
                }
              }
              pp_Var9[0x48] = (_Instance *)0x1;
            }
            else {
              if ((int)puVar8 < 0x100002) {
                if (puVar8 == (undefined *)0x100000) {
                  if ((DAT_800d5aa4 & 0x40000) == 0) {
                    local_54 = SetControlInitIdleData(0,0,(uint)DAT_800d5ba4[9]);
                    StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_54);
                    if (((*PadData & RazielCommands[5]) == 0) ||
                       ((*PadData & RazielCommands[4]) == 0)) goto LAB_8009d6b0;
                    DAT_800d5c48 = StateHandlerIdle;
                    NewProcess = StateHandlerLookAround;
                  }
                  else {
                    NewProcess = StateHandlerSwim;
                  }
LAB_8009d5ec:
                  StateSwitchStateData(In,CurrentSection,NewProcess,0);
                }
                else {
LAB_8009d6a8:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar8 != &DAT_00100004) goto LAB_8009d6a8;
                G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,300);
                if ((DAT_800d5c58 & 2) != 0) {
                  razSetFadeEffect(In->CharacterInstance->fadeValue,0,-*(int *)(PlayerData + 0x28));
                }
                if ((CurrentSection == 0) && (DAT_800d5ca0 != 0)) {
                  SndEndLoop(DAT_800d5ca0);
                  DAT_800d5ca0 = 0;
                }
                if (DAT_800d5b2c == 8) {
                  Inst = razGetHeldItem();
                  INSTANCE_PlainDeath(Inst);
                }
                if (DAT_800d5b2c == 0x1000) {
                  local_54 = 0x800105;
                  Inst = DAT_800d5b70;
                  goto LAB_8009d324;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar8 == (undefined *)0x8000000) {
          DAT_800d5ba8 = DAT_800d5ba8 & 0xfffffffb;
          if (uVar5 == (uint)*DAT_800d5ba4) {
            if (((DAT_800d5aa4 & 0x40000) == 0) || (CurrentSection != 0)) {
              G2EmulationSwitchAnimationAlpha
                        (In,CurrentSection,(uint)DAT_800d5ba4[3],0,(uint)DAT_800d5ba4[4],1,
                         (uint)DAT_800d5ba4[5]);
            }
          }
          else {
            if ((uVar5 == (uint)DAT_800d5ba4[6]) && (local_54 = 0x100000, CurrentSection == 1)) {
              Inst = In->CharacterInstance;
LAB_8009d324:
              INSTANCE_Post(Inst,local_54,0);
            }
          }
        }
        else {
          if ((int)puVar8 < 0x8000001) {
            if (puVar8 == (undefined *)0x4000001) {
              if (CurrentSection == 0) {
                SetDropPhysics(In->CharacterInstance,(__Player *)&Raziel);
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
              NewProcess = StateHandlerFall;
              goto LAB_8009d5ec;
            }
            if ((int)puVar8 < 0x4000002) {
              if (puVar8 != (undefined *)0x1000001) goto LAB_8009d6a8;
            }
            else {
              if (puVar8 != (undefined *)0x4020000) goto LAB_8009d6a8;
            }
          }
          else {
            if (puVar8 != (undefined *)0x20000002) {
              if ((int)puVar8 < 0x20000003) {
                if (puVar8 != (undefined *)0x8000004) goto LAB_8009d6a8;
                Inst = razGetHeldWeapon();
                if (Inst == (_Instance *)0x0) goto LAB_8009d6b0;
                if ((DAT_800d5ba8 & 2) == 0) {
                  if ((DAT_800d5b1c & 0x80) == 0) {
                    target = (undefined2 *)0x0;
                    type = 0;
                    uVar4 = *(ushort *)(DAT_800d5ba4 + 0x18);
                    local_54 = 0;
                    goto LAB_8009d554;
                  }
                  local_54 = SetObjectThrowData(*(void **)(DAT_800d5b18 + 0x38),(_SVector *)0x0,1,0,
                                                (uint)*(ushort *)(DAT_800d5ba4 + 0x18),
                                                (int)*(short *)(DAT_800d5ba4 + 0x1a),0,-0x400);
                  INSTANCE_Post(Inst,0x800010,local_54);
                  uVar7 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x38),0xc);
                  local_40.x = *(short *)(uVar7 + 0x14);
                  local_40.y = *(short *)(uVar7 + 0x18);
                  local_40.z = *(short *)(uVar7 + 0x1c);
                  PointAt(In->CharacterInstance,&local_40,&_Stack56);
                }
                else {
                  target = &DAT_800d5bac;
                  type = 4;
                  uVar4 = *(ushort *)(DAT_800d5ba4 + 0x18);
                  local_54 = (int)*(short *)(DAT_800d5ba4 + 0x1a);
LAB_8009d554:
                  local_54 = SetObjectThrowData(target,(_SVector *)0x0,type,0,(uint)uVar4,local_54,0
                                                ,-0x400);
                  INSTANCE_Post(Inst,0x800010,local_54);
                }
                razSetFadeEffect(In->CharacterInstance->fadeValue,0,-*(int *)(PlayerData + 0x28));
                razReaverOn();
              }
              else {
                if (puVar8 != (undefined *)0x20000020) goto LAB_8009d6a8;
                if (pp_Var9[0x48] != (_Instance *)0x0) {
                  In_00 = &p_Var10->Defer;
                  if (uVar5 != (uint)DAT_800d5ba4[3]) {
                    local_54 = 0x20000020;
                    goto LAB_8009d40c;
                  }
                  if (((DAT_800d5aa4 & 0x40000) == 0) || (CurrentSection != 0)) {
                    G2EmulationSwitchAnimation
                              (In,CurrentSection,(uint)DAT_800d5ba4[6],0,(uint)DAT_800d5ba4[7],1);
                  }
                  if (CurrentSection == 1) {
                    DAT_800d5c98 = (ushort)DAT_800d5ba4[8] * 100;
                    (In->CharacterInstance->anim).section[1].swAlarmTable = (short *)0x800d5c98;
                  }
                  pp_Var9[0x48] = (_Instance *)0x0;
                  if ((DAT_800d5ce8 & 0x200) != 0) {
                    razSetPlayerEventHistory(0x200);
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_8009d6b0:
    DeMessageQueue(&p_Var10->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ PointAt(struct _Instance *instance /*$s0*/, struct _Position *Target /*$s1*/, struct _Rotation *Rot1 /*$s2*/)
 // line 1282, offset 0x8009d750
	/* begin block 1 */
		// Start line: 1283
		// Start offset: 0x8009D750
		// Variables:
	// 		struct _Position From; // stack offset -48
	// 		struct SVECTOR v1; // stack offset -40
	// 		struct VECTOR v3; // stack offset -32
	// 		struct MATRIX *tempMat; // $a0
	/* end block 1 */
	// End offset: 0x8009D83C
	// End Line: 1315

	/* begin block 2 */
		// Start line: 2579
	/* end block 2 */
	// End Line: 2580

	/* begin block 3 */
		// Start line: 2587
	/* end block 3 */
	// End Line: 2588

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\RAZIEL\ATTACK.C */

void PointAt(_Instance *instance,_Position *Target,_Rotation *Rot1)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  _G2Anim_Type *anim;
  _Position local_30;
  SVECTOR local_28;
  int local_20;
  int local_1c;
  int local_18;
  
  local_28.vx = *(short *)(DAT_800d5ba4 + 10);
  local_28.vy = *(short *)(DAT_800d5ba4 + 0xc);
  local_28.vz = *(short *)(DAT_800d5ba4 + 0xe);
  ApplyMatrix(instance->matrix,&local_28,(VECTOR *)&local_20);
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
 // line 1320, offset 0x8009d870
	/* begin block 1 */
		// Start line: 1321
		// Start offset: 0x8009D870
		// Variables:
	// 		struct MATRIX *pTempMat; // $s0
	// 		struct _Instance *weaponInstance; // $s1
	// 		struct SVECTOR v1; // stack offset -48
	// 		struct VECTOR v4; // stack offset -40
	/* end block 1 */
	// End offset: 0x8009D994
	// End Line: 1367

	/* begin block 2 */
		// Start line: 2690
	/* end block 2 */
	// End Line: 2691

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\RAZIEL\ATTACK.C */

void ThrowSetFocusPoint(_Instance *instance,_Rotation *rot)

{
  MATRIX *m;
  _Instance *p_Var1;
  _G2Bool_Enum _Var2;
  _G2Anim_Type *anim;
  SVECTOR local_30;
  long local_28;
  long local_24;
  long local_20;
  
  rot->x = -rot->x;
  m = DAT_800d1010;
  p_Var1 = razGetHeldWeapon();
  if ((p_Var1 != (_Instance *)0x0) && (p_Var1->matrix != (MATRIX *)0x0)) {
    local_30.vx = 0;
    local_30.vy = 0;
    local_30.vz = *(short *)(DAT_800d5ba4 + 0x18);
    ApplyMatrix(m,&local_30,(VECTOR *)&local_28);
    anim = &instance->anim;
    DAT_800d5bac = (undefined2)local_28;
    DAT_800d5bae = (undefined2)local_24;
    DAT_800d5bb0 = (undefined2)local_20;
    _Var2 = G2Anim_IsControllerActive(anim,0xe,0xe);
    if (_Var2 == G2FALSE) {
      G2Anim_EnableController(anim,0xe,0xe);
    }
    MATH3D_ZYXtoXYZ(rot);
    G2Anim_SetController_Vector(anim,0xe,0xe,(_G2SVector3_Type *)rot);
    local_28 = p_Var1->matrix[1].t[0];
    local_24 = p_Var1->matrix[1].t[1];
    local_20 = p_Var1->matrix[1].t[2];
    CAMERA_SetLookFocusAndDistance
              ((Camera *)&theCamera,(char)(VECTOR *)&local_28,*(int *)(PlayerData + 0x2c));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LimitRotation(struct _Rotation *rot /*$a1*/)
 // line 1368, offset 0x8009d9b4
	/* begin block 1 */
		// Start line: 2804
	/* end block 1 */
	// End Line: 2805

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

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
    bVar2 = sVar3 < *(short *)(DAT_800d5ba4 + 0x16);
    sVar3 = *(short *)(DAT_800d5ba4 + 0x16);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)(DAT_800d5ba4 + 0x14);
      bVar2 = *(short *)(DAT_800d5ba4 + 0x14) < sVar1;
    }
    else {
      sVar3 = *(short *)(DAT_800d5ba4 + 0x16);
      bVar2 = sVar1 < *(short *)(DAT_800d5ba4 + 0x16);
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
    bVar2 = sVar3 < *(short *)(DAT_800d5ba4 + 0x12);
    sVar3 = *(short *)(DAT_800d5ba4 + 0x12);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)(DAT_800d5ba4 + 0x10);
      bVar2 = *(short *)(DAT_800d5ba4 + 0x10) < sVar1;
    }
    else {
      sVar3 = *(short *)(DAT_800d5ba4 + 0x12);
      bVar2 = sVar1 < *(short *)(DAT_800d5ba4 + 0x12);
    }
  }
  if (bVar2) {
    rot->x = sVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGrab(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$s7*/)
 // line 1428, offset 0x8009db28
	/* begin block 1 */
		// Start line: 1429
		// Start offset: 0x8009DB28
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1462
			// Start offset: 0x8009DD74
			// Variables:
		// 		struct _Instance *Inst; // $a1
		/* end block 1.1 */
		// End offset: 0x8009DDC4
		// End Line: 1473

		/* begin block 1.2 */
			// Start line: 1499
			// Start offset: 0x8009DE34
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009DE50
		// End Line: 1517

		/* begin block 1.3 */
			// Start line: 1604
			// Start offset: 0x8009E028
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.3 */
		// End offset: 0x8009E0D8
		// End Line: 1636

		/* begin block 1.4 */
			// Start line: 1643
			// Start offset: 0x8009E0F0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.4 */
		// End offset: 0x8009E140
		// End Line: 1655

		/* begin block 1.5 */
			// Start line: 1662
			// Start offset: 0x8009E1A0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.5 */
		// End offset: 0x8009E1F0
		// End Line: 1676
	/* end block 1 */
	// End offset: 0x8009E264
	// End Line: 1708

	/* begin block 2 */
		// Start line: 2928
	/* end block 2 */
	// End Line: 2929

/* File: C:\kain2\game\RAZIEL\ATTACK.C */

void StateHandlerGrab(__CharacterState *In,int CurrentSection,int Data)

{
  uint uVar1;
  __Event *p_Var2;
  _Instance *Inst;
  int Data_00;
  undefined *puVar3;
  uint NewAnim;
  uint local_30;
  int local_2c;
  
  uVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100015) {
      if (CurrentSection == 0) {
        if (uVar1 == (uint)*DAT_800d5ba4) {
          if ((DAT_800d5b1c & 0x100) != 0) {
            INSTANCE_Post(*(_Instance **)(DAT_800d5b18 + 0x40),0x1000002,(int)In->CharacterInstance)
            ;
            razReaverOff();
            In->SectionList[0].Data1 = 1;
            In->SectionList[1].Data1 = 1;
            In->SectionList[2].Data1 = 1;
          }
        }
        else {
          Inst = razGetHeldItem();
          if (Inst != (_Instance *)0x0) {
LAB_8009e098:
            Data_00 = SetMonsterThrownData
                                (In->CharacterInstance,&In->CharacterInstance->rotation,100);
            INSTANCE_Post(Inst,0x1000003,Data_00);
            Inst = razGetHeldItem();
            if (Inst != (_Instance *)0x0) {
              INSTANCE_UnlinkFromParent(Inst);
            }
          }
          razReaverOn();
        }
      }
    }
    else {
      if ((int)puVar3 < 0x100016) {
        if (puVar3 == (undefined *)0x0) {
          if ((((CurrentSection == 0) && (uVar1 != (uint)*DAT_800d5ba4)) && (uVar1 != 0x47)) &&
             ((uVar1 != (uint)DAT_800d5ba4[6] &&
              (SteerSwitchMode(In->CharacterInstance,0), uVar1 == 1)))) {
            Data_00 = 0x37;
LAB_8009df04:
            G2EmulationSwitchAnimation(In,0,Data_00,0,3,2);
          }
        }
        else {
          if ((int)puVar3 < 1) {
            if (puVar3 != &DAT_80000008) {
              if ((int)puVar3 < -0x7ffffff7) {
                if (puVar3 != (undefined *)0x80000000) goto LAB_8009e24c;
              }
              else {
                if (puVar3 != &DAT_80000020) goto LAB_8009e24c;
              }
            }
          }
          else {
            if (puVar3 == &DAT_00100004) {
              Inst = razGetHeldItem();
              if (Inst != (_Instance *)0x0) goto LAB_8009e098;
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 != &DAT_00100001) goto LAB_8009e24c;
                if (CurrentSection == 0) {
                  DAT_800d5ba4 = *(byte **)(*(int *)(PlayerData + 0x14) + 0x18);
                  ControlFlag = 0x41043009;
                  PhysicsMode = 3;
                  SteerSwitchMode(In->CharacterInstance,0);
                }
                if (p_Var2->Data == 0) {
                  Inst = (_Instance *)0xd;
                  if (CurrentSection == 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x47,0,(uint)DAT_800d5ba4[1],1);
                    if ((DAT_800d5b1c & 0x100) != 0) {
                      INSTANCE_Post(*(_Instance **)(DAT_800d5b18 + 0x40),0x1000002,0);
                    }
                    Inst = (_Instance *)0xd;
                  }
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
                    NewAnim = (uint)*DAT_800d5ba4;
                    local_30 = (uint)DAT_800d5ba4[1];
                    local_2c = 1;
                    Data_00 = CurrentSection;
                  }
                  G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
                  if (CurrentSection == 0) {
                    if ((DAT_800d5b1c & 0x100) != 0) {
                      razAlignYRotMoveInterp
                                (In->CharacterInstance,*(_Instance **)(DAT_800d5b18 + 0x40),200,'\0'
                                 ,(uint)DAT_800d5ba4[1],0);
                    }
                    SetTimer((uint)DAT_800d5ba4[4] + (uint)DAT_800d5ba4[1]);
                  }
                  DAT_800d5aa4 = 0x20000000;
                  Inst = (_Instance *)0xb;
                }
                (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = Inst;
                (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
              }
              else {
                if (puVar3 != &DAT_00100014) goto LAB_8009e24c;
                if ((CurrentSection == 0) && (Inst = razGetHeldItem(), Inst != (_Instance *)0x0)) {
                  Data_00 = SetMonsterThrownData
                                      (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                  INSTANCE_Post(Inst,0x1000003,Data_00);
                  Inst = razGetHeldItem();
                  if (Inst != (_Instance *)0x0) {
                    INSTANCE_UnlinkFromParent(Inst);
                  }
                }
LAB_8009e140:
                Data_00 = SetControlInitIdleData(0,0,(uint)DAT_800d5ba4[9]);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var2->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
          goto LAB_8009e24c;
        }
        if ((int)puVar3 < 0x4010081) {
          if (puVar3 != (undefined *)0x1000001) {
            if ((int)puVar3 < 0x1000002) {
              if (puVar3 == (undefined *)0x1000000) {
                if (((CurrentSection == 0) && ((ControlFlag & 0x4000U) == 0)) && (DAT_800d5b44 == 0)
                   ) {
                  Inst = razGetHeldItem();
                  if (Inst != (_Instance *)0x0) {
                    Data_00 = SetMonsterThrownData
                                        (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                    INSTANCE_Post(Inst,0x1000003,Data_00);
                  }
                  Inst = razGetHeldItem();
                  if (Inst != (_Instance *)0x0) {
                    INSTANCE_UnlinkFromParent(Inst);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var2->Data);
                }
                goto LAB_8009e254;
              }
            }
            else {
              if (puVar3 == (undefined *)0x1000006) goto LAB_8009e140;
            }
LAB_8009e24c:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
        else {
          if (puVar3 == (undefined *)0x8000000) {
            if (CurrentSection == 0) {
              if (In->SectionList[0].Data2 == 0xb) {
                G2EmulationSwitchAnimation(In,0,0x37,0,3,2);
                In->SectionList[0].Data2 = 0xe;
              }
              else {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
              }
            }
          }
          else {
            if ((int)puVar3 < 0x8000001) {
              if (puVar3 != (undefined *)0x4020000) goto LAB_8009e24c;
            }
            else {
              if (puVar3 == (undefined *)0x10000000) {
                if ((((CurrentSection == 0) && (uVar1 != (uint)*DAT_800d5ba4)) && (uVar1 != 0x47))
                   && ((uVar1 != (uint)DAT_800d5ba4[6] &&
                       (SteerSwitchMode(In->CharacterInstance,0x12), uVar1 == 0x37)))) {
                  Data_00 = 1;
                  goto LAB_8009df04;
                }
              }
              else {
                if (puVar3 != (undefined *)0x20000020) goto LAB_8009e24c;
                if (CurrentSection == 0) {
                  if (In->SectionList[0].Data1 == 0) {
                    EnMessageQueueData(&In->SectionList[0].Defer,0x20000020,0);
                  }
                  else {
                    if (In->SectionList[0].Data2 != 0xc) {
                      G2EmulationSwitchAnimationCharacter
                                (In,(uint)DAT_800d5ba4[6],0,(uint)DAT_800d5ba4[7],1);
                      PurgeMessageQueue(&In->SectionList[0].Event);
                      DAT_800d5aa4 = 0x20000;
                      SetTimer((uint)DAT_800d5ba4[8] + (uint)DAT_800d5ba4[7]);
                      In->SectionList[0].Data2 = 0xc;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_8009e254:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}





