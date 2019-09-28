#include "THISDUST.H"
#include "MONMSG.H"


// decompiled code
// original method signature: 
// int /*$ra*/ MON_GroundMoveQueueHandler(struct _Instance *instance /*$s1*/)
 // line 32, offset 0x800847b8
	/* begin block 1 */
		// Start line: 33
		// Start offset: 0x800847B8
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $a1
	// 		int ret; // $s0
	/* end block 1 */
	// End offset: 0x80084824
	// End Line: 52

	/* begin block 2 */
		// Start line: 64
	/* end block 2 */
	// End Line: 65

int MON_GroundMoveQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$a1*/)
 // line 60, offset 0x80084840
	/* begin block 1 */
		// Start line: 61
		// Start offset: 0x80084840
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 72
			// Start offset: 0x800848F4
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s1
		/* end block 1.1 */
		// End offset: 0x8008497C
		// End Line: 79

		/* begin block 1.2 */
			// Start line: 86
			// Start offset: 0x800849BC
			// Variables:
		// 		struct evFXHitData data; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x800849FC
		// End Line: 93
	/* end block 1 */
	// End offset: 0x80084A6C
	// End Line: 165

	/* begin block 2 */
		// Start line: 128
	/* end block 2 */
	// End Line: 129

void MON_PupateMessageHandler(_Instance *param_1,int *param_2)

{
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar1;
  int iVar2;
  uint *puVar3;
  MonsterState in_stack_ffffffd0;
  evFXHitData eStack40;
  
  iVar2 = *param_2;
  puVar3 = (uint *)param_1->extraData;
  if (iVar2 == 0x80005) {
    if ((*(char *)(puVar3[0x55] + 0x39) != '\0') && ((*puVar3 & 0x400) == 0)) {
      MON_SetFXHitData(param_1,&eStack40,0x20,1);
      *(undefined2 *)(puVar3 + 0x50) = 0x20;
      pTVar1 = MONTABLE_GetDamageEffectFunc(param_1);
      (*pTVar1)(param_1,&eStack40);
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(param_1,in_stack_ffffffd0);
    }
  }
  else {
    if (iVar2 < 0x80006) {
      if (iVar2 < 0x80001) {
        return;
      }
      if (iVar2 < 0x80004) {
        return;
      }
      if (*(char *)(puVar3[0x55] + 0x3a) == '\0') {
        return;
      }
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(param_1,in_stack_ffffffd0);
    }
    if (iVar2 == 0x1000000) {
      *puVar3 = *puVar3 & 0xffffff7f;
      return;
    }
    if (0x1000000 < iVar2) {
      if (iVar2 != 0x1000011) {
        return;
      }
      iVar2 = param_2[1];
                    /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)*(short *)(iVar2 + 4) - (int)(param_1->position).x,
                       (int)*(short *)(iVar2 + 6) - (int)(param_1->position).y,
                       (int)*(short *)(iVar2 + 8) - (int)(param_1->position).z);
    }
    if (iVar2 != 0x80006) {
      return;
    }
  }
  if (*(char *)(puVar3[0x55] + 0x38) == '\0') {
    return;
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(param_1,in_stack_ffffffd0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s0*/)
 // line 167, offset 0x80084a84
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80084A84
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 199
			// Start offset: 0x80084B10
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.1 */
		// End offset: 0x80084B3C
		// End Line: 202

		/* begin block 1.2 */
			// Start line: 208
			// Start offset: 0x80084B64
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.2 */
		// End offset: 0x80084B90
		// End Line: 211
	/* end block 1 */
	// End offset: 0x80084BB0
	// End Line: 218

	/* begin block 2 */
		// Start line: 348
	/* end block 2 */
	// End Line: 349

void MON_IdleMessageHandler(_Instance *param_1,__Event *param_2)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  switch(param_2->ID) {
  case 0x1000002:
  case 0x100000a:
  case 0x1000023:
    if (param_2->Data == 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(param_1,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    }
  default:
    MON_DefaultMessageHandler(param_1,param_2);
    break;
  case 0x100000e:
    if ((*(uint *)param_1->extraData & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(param_2->Data + 4),1);
    }
    break;
  case 0x1000012:
    if ((*(uint *)param_1->extraData & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(param_2->Data + 4),1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s3*/)
 // line 220, offset 0x80084bc8
	/* begin block 1 */
		// Start line: 221
		// Start offset: 0x80084BC8
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a1
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $a0

		/* begin block 1.1 */
			// Start line: 232
			// Start offset: 0x80084E94
			// Variables:
		// 		struct evMonsterHitData *data; // $s5
		// 		int fatal; // $s4
		// 		int damage; // $s0

			/* begin block 1.1.1 */
				// Start line: 296
				// Start offset: 0x80084EEC
				// Variables:
			// 		struct _MonsterCombatAttributes *combat; // $s0
			/* end block 1.1.1 */
			// End offset: 0x80084EEC
			// End Line: 296
		/* end block 1.1 */
		// End offset: 0x80084F7C
		// End Line: 329

		/* begin block 1.2 */
			// Start line: 333
			// Start offset: 0x80084FA4
			// Variables:
		// 		int state; // $a1
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x80085048
		// End Line: 372

		/* begin block 1.3 */
			// Start line: 395
			// Start offset: 0x800850A4
			// Variables:
		// 		struct evMonsterSoulSuckData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x800850DC
		// End Line: 399

		/* begin block 1.4 */
			// Start line: 437
			// Start offset: 0x800851C8
			// Variables:
		// 		int vuln; // $s0
		/* end block 1.4 */
		// End offset: 0x800852A4
		// End Line: 471

		/* begin block 1.5 */
			// Start line: 486
			// Start offset: 0x800852FC
		/* end block 1.5 */
		// End offset: 0x80085360
		// End Line: 490

		/* begin block 1.6 */
			// Start line: 530
			// Start offset: 0x800853F8
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s0
		// 		struct _Instance *enemy; // $s3

			/* begin block 1.6.1 */
				// Start line: 537
				// Start offset: 0x8008543C

				/* begin block 1.6.1.1 */
					// Start line: 542
					// Start offset: 0x80085488
					// Variables:
				// 		struct _MonsterIR *mir; // $v0
				/* end block 1.6.1.1 */
				// End offset: 0x800854A0
				// End Line: 547
			/* end block 1.6.1 */
			// End offset: 0x800854A0
			// End Line: 548
		/* end block 1.6 */
		// End offset: 0x800854A0
		// End Line: 552

		/* begin block 1.7 */
			// Start line: 558
			// Start offset: 0x800854BC
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.7 */
		// End offset: 0x800854DC
		// End Line: 560

		/* begin block 1.8 */
			// Start line: 566
			// Start offset: 0x80085508
			// Variables:
		// 		int hp; // $v1
		/* end block 1.8 */
		// End offset: 0x80085524
		// End Line: 569

		/* begin block 1.9 */
			// Start line: 602
			// Start offset: 0x800855B8
			// Variables:
		// 		struct evFXHitData data; // stack offset -80
		/* end block 1.9 */
		// End offset: 0x800855F8
		// End Line: 609

		/* begin block 1.10 */
			// Start line: 668
			// Start offset: 0x80085720
			// Variables:
		// 		struct evFXHitData data; // stack offset -56
		/* end block 1.10 */
		// End offset: 0x80085720
		// End Line: 669

		/* begin block 1.11 */
			// Start line: 683
			// Start offset: 0x800857B0
		/* end block 1.11 */
		// End offset: 0x800857B0
		// End Line: 686

		/* begin block 1.12 */
			// Start line: 701
			// Start offset: 0x80085810
			// Variables:
		// 		struct evPositionData *posData; // $a0
		/* end block 1.12 */
		// End offset: 0x80085810
		// End Line: 701

		/* begin block 1.13 */
			// Start line: 709
			// Start offset: 0x80085830
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.13 */
		// End offset: 0x80085830
		// End Line: 709

		/* begin block 1.14 */
			// Start line: 719
			// Start offset: 0x80085870
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.14 */
		// End offset: 0x80085870
		// End Line: 719

		/* begin block 1.15 */
			// Start line: 732
			// Start offset: 0x800858BC
			// Variables:
		// 		static int deaths[9]; // offset 0x0
		/* end block 1.15 */
		// End offset: 0x800858BC
		// End Line: 743

		/* begin block 1.16 */
			// Start line: 749
			// Start offset: 0x800858E8
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.16 */
		// End offset: 0x800858E8
		// End Line: 749

		/* begin block 1.17 */
			// Start line: 756
			// Start offset: 0x80085924
			// Variables:
		// 		int i; // $s1
		// 		struct evActionPlayHostAnimationData *data; // $s0
		/* end block 1.17 */
		// End offset: 0x8008597C
		// End Line: 760

		/* begin block 1.18 */
			// Start line: 764
			// Start offset: 0x80085984
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v0
		/* end block 1.18 */
		// End offset: 0x8008599C
		// End Line: 766
	/* end block 1 */
	// End offset: 0x8008599C
	// End Line: 771

	/* begin block 2 */
		// Start line: 459
	/* end block 2 */
	// End Line: 460

/* WARNING: Removing unreachable block (ram,0x80084f54) */
/* WARNING: Removing unreachable block (ram,0x8008529c) */
/* WARNING: Removing unreachable block (ram,0x800852a4) */
/* WARNING: Removing unreachable block (ram,0x80085284) */
/* WARNING: Type propagation algorithm not settling */

void MON_DefaultMessageHandler(_Instance *instance,__Event *message)

{
  short sVar1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  uint CurrentSection;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined *puVar5;
  int Message;
  char cVar6;
  uint *puVar7;
  int Data;
  uint *puVar8;
  _Instance *Inst;
  undefined4 local_60;
  undefined4 local_5c;
  evFXHitData eStack80;
  evFXHitData eStack56;
  
  puVar5 = (undefined *)message->ID;
  puVar8 = (uint *)instance->extraData;
  if (0x1000008 < (int)puVar5) {
    if (puVar5 == (undefined *)0x1000016) {
      if (*(char *)(*(int *)(puVar8[0x55] + 8) + 0x1c) == '\0') {
        return;
      }
      Data = (int)*(short *)(puVar8 + 0x4c) + message->Data;
      uVar3 = (undefined2)Data;
      if (0x6000 < Data) {
        uVar3 = 0x6000;
      }
LAB_80085598:
      *(undefined2 *)(puVar8 + 0x4c) = uVar3;
      return;
    }
    if ((int)puVar5 < 0x1000017) {
      if (puVar5 == (undefined *)0x100000c) {
        if (((*puVar8 & 1) != 0) && (instance->currentMainState == 0xb)) {
          return;
        }
        Data = message->Data;
        if (Data == 0x20) {
          cVar6 = '\0';
          if ((*puVar8 & 0x400) == 0) {
            cVar6 = *(char *)(puVar8[0x55] + 0x39);
          }
        }
        else {
          if (Data < 0x21) {
            cVar6 = '\0';
            if (Data == 0x10) {
              cVar6 = *(char *)(puVar8[0x55] + 0x3a);
            }
          }
          else {
            cVar6 = '\0';
            if (Data == 0x40) {
              cVar6 = *(char *)(puVar8[0x55] + 0x38);
            }
          }
        }
        if (cVar6 == '\0') {
          return;
        }
        *(undefined2 *)(puVar8 + 0x50) = *(undefined2 *)&message->Data;
        Data = SetFXHitData((_Instance *)0x0,0,0,message->Data);
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance,0x400000,Data);
      }
      if (0x100000c < (int)puVar5) {
        if (puVar5 == (undefined *)0x1000011) {
          Inst = *(_Instance **)&((_Instance *)message->Data)->node;
          if (Inst == (_Instance *)0x0) {
            return;
          }
                    /* WARNING: Subroutine does not return */
          INSTANCE_Query(Inst,1);
        }
        if ((int)puVar5 < 0x1000012) {
          if (puVar5 != (undefined *)0x100000e) {
            return;
          }
        }
        else {
          if (puVar5 != (undefined *)0x1000012) {
            if (puVar5 != (undefined *)0x1000014) {
              return;
            }
            if (message->Data == 0) {
              return;
            }
            if (0x1fff < *(short *)(puVar8 + 0x4d)) {
                    /* WARNING: Subroutine does not return */
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
            }
            *(undefined2 *)(puVar8 + 0x4d) = 0;
                    /* WARNING: Subroutine does not return */
            *(undefined2 *)(puVar8 + 0x50) = 0;
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
          }
        }
        if ((*puVar8 & 4) != 0) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
      }
      if (puVar5 != (undefined *)0x100000a) {
        if (0x100000a < (int)puVar5) {
                    /* WARNING: Subroutine does not return */
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
        }
        Data = message->Data;
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(Data + 4),
                         (int)(instance->position).y - (int)*(short *)(Data + 6),
                         (int)(instance->position).z - (int)*(short *)(Data + 8));
      }
      puVar7 = (uint *)message->Data;
      if (puVar7 == (uint *)0x0) {
        CurrentSection = puVar8[0x31];
        if (CurrentSection == 0) {
          return;
        }
        *(ushort *)(CurrentSection + 0x18) = *(ushort *)(CurrentSection + 0x18) | 0x80;
        return;
      }
      puVar8[0x34] = *puVar7;
                    /* WARNING: Subroutine does not return */
      rsin((int)*(short *)(puVar7 + 2));
    }
    if (puVar5 != (undefined *)0x1000021) {
      if (0x1000021 < (int)puVar5) {
        if (puVar5 == (undefined *)0x2000002) {
          Inst = (_Instance *)message->Data;
          Data = SetMonsterHitData(instance,(_Instance *)0x0,(int)Inst->prev,
                                   (int)*(short *)(puVar8[0x2e] + 4),
                                   (int)*(char *)(puVar8[0x2e] + 6));
          Message = 0x1000000;
          instance = *(_Instance **)&Inst->node;
          goto LAB_80085914;
        }
        if (0x2000002 < (int)puVar5) {
          if (puVar5 == (undefined *)0x4010080) {
            return;
          }
          if (puVar5 != (undefined *)0x8000008) {
            return;
          }
          MON_PlayAnimID(instance,*(int *)(message->Data + 4),*(int *)(message->Data + 0x10));
          return;
        }
        if (puVar5 != (undefined *)0x1000023) {
          return;
        }
        if (message->Data == 0) {
          return;
        }
        if (message->Data == 0x1000) {
          MONSENSE_SetEnemy(instance,(_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]);
          *(undefined2 *)(puVar8 + 0x50) = 0x400;
                    /* WARNING: Subroutine does not return */
          instance->flags2 = instance->flags2 | 0x1000;
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
        }
        goto LAB_80085800;
      }
      if (puVar5 == (undefined *)0x100001a) {
        if (message->Data != 0) {
          if ((*puVar8 & 0x20000000) != 0) {
            return;
          }
          *puVar8 = *puVar8 | 0x20000000;
          *(short *)(puVar8 + 0x4c) = (short)((int)*(short *)(puVar8 + 0x4c) << 1);
          return;
        }
        if ((*puVar8 & 0x20000000) == 0) {
          return;
        }
        *puVar8 = *puVar8 & 0xdfffffff;
        uVar3 = (undefined2)(((int)*(short *)(puVar8 + 0x4c) + 1) / 2);
        goto LAB_80085598;
      }
      if ((int)puVar5 < 0x100001b) {
        if (puVar5 != (undefined *)0x1000019) {
          return;
        }
        MONSENSE_SetEnemy(instance,(_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]);
                    /* WARNING: Subroutine does not return */
        puVar8[0x34] = message->Data;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
      }
      if (puVar5 == (undefined *)0x100001c) {
        puVar8[100] = message->Data;
        MON_MoveInstanceToImpalePoint(instance);
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
      }
      if (puVar5 != (undefined *)0x100001f) {
        return;
      }
    }
    if ((*puVar8 & 0x200040) != 0) {
      return;
    }
    Data = message->Data;
    sVar1 = *(short *)(Data + 0xc);
    *(short *)(puVar8 + 0x50) = sVar1;
    if (sVar1 == 0x20) {
      if (puVar5 != (undefined *)0x1000021) {
                    /* WARNING: Subroutine does not return */
        *puVar8 = *puVar8 | 0x800110;
        MON_GetTime(instance);
      }
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(instance,0);
    }
    Message = 0x3000;
    if ((instance->flags2 & 0x8000000U) != 0) {
      Message = 0x2000;
    }
    if (Message == 0) {
      *puVar8 = *puVar8 | 0x40;
      return;
    }
    *(int *)(Data + 0xc) = Message;
LAB_80084f7c:
    if (((*puVar8 & 0x200040) == 0) && (instance->currentMainState != 10)) {
      Inst = (_Instance *)message->Data;
      if (0x2fff < (int)Inst->prev) {
        instance->constrictAngle = 0;
      }
      *puVar8 = *puVar8 | 0x40;
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)&Inst->node,1);
    }
    return;
  }
  if (0x1000006 < (int)puVar5) {
    return;
  }
  if (puVar5 == (undefined *)0x80001) {
    if (instance->zVel != 0) {
      return;
    }
    if ((*puVar8 & 0x200000) != 0) {
      return;
    }
    sVar1 = MATH3D_AngleFromPosToPos
                      ((_Position *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c),
                       &instance->position);
    (instance->position).z = (instance->position).z + 0x78;
    (instance->oldPos).z = (instance->oldPos).z + 0x78;
    MON_LaunchMonster(instance,(int)sVar1,100,0x46);
    return;
  }
  if ((int)puVar5 < 0x80002) {
    if (puVar5 == &LAB_0004000c_1) {
      Data = message->Data;
      puVar8[1] = puVar8[1] | 0x10000000;
      *(undefined2 *)((int)puVar8 + 0x116) = *(undefined2 *)(Data + 4);
      return;
    }
    if ((int)puVar5 < 0x4000e) {
      if (puVar5 == (undefined *)0x40009) {
        *(undefined2 *)(puVar8 + 0x50) = 0x2000;
LAB_80085800:
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
      }
      if ((int)puVar5 < 0x4000a) {
        if (puVar5 != &DAT_00040003) {
          return;
        }
        CurrentSection = (uint)*(byte *)(puVar8[0x55] + 0x2a);
        Data = message->Data;
        while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection) {
          G2EmulationInstanceToInstanceSwitchAnimation
                    (instance,*(_Instance **)(Data + 4),CurrentSection,*(int *)(Data + 8),
                     *(int *)(Data + 0xc),*(int *)(Data + 0x10),*(int *)(Data + 0x14));
        }
        return;
      }
      if (puVar5 != &LAB_0004000c) {
        return;
      }
    }
    else {
      if (puVar5 == &LAB_00040010) {
        *puVar8 = *puVar8 & 0x7fffffff;
        return;
      }
      if ((int)puVar5 < 0x40011) {
        if (puVar5 != &LAB_0004000c_3) {
          return;
        }
        puVar4 = (undefined2 *)message->Data;
        *puVar8 = *puVar8 | 0x80000000;
        *(undefined2 *)((int)puVar8 + 0x122) = *puVar4;
        *(undefined2 *)(puVar8 + 0x49) = puVar4[1];
        *(undefined2 *)((int)puVar8 + 0x126) = puVar4[2];
        return;
      }
      if (puVar5 != &LAB_00040014_2) {
        if (puVar5 != &LAB_00040014_3) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        *(undefined2 *)(puVar8 + 0x50) = *(undefined2 *)(&LAB_800ca9c8 + message->Data * 4);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
      }
    }
    puVar4 = (undefined2 *)message->Data;
    *(undefined2 *)((int)puVar8 + 0x112) = *puVar4;
    *(undefined2 *)(puVar8 + 0x45) = puVar4[1];
    uVar3 = puVar4[2];
    *puVar8 = *puVar8 | 0x40000;
                    /* WARNING: Subroutine does not return */
    *(undefined2 *)((int)puVar8 + 0x116) = uVar3;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
  }
  if (puVar5 == (undefined *)0x80005) {
    if (*(char *)(puVar8[0x55] + 0x39) != '\0') {
      MON_SetFXHitData(instance,&eStack80,0x20,1);
      *(undefined2 *)(puVar8 + 0x50) = 0x20;
      pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
      (*pTVar2)(instance,&eStack80);
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
    }
  }
  else {
    if ((int)puVar5 < 0x80006) {
      if (puVar5 == (undefined *)0x80003) {
        if (*(char *)(puVar8[0x55] + 0x3c) != '\0') {
          MON_SetFXHitData(instance,&eStack56,0x200,0x10);
          *(undefined2 *)(puVar8 + 0x50) = 0x200;
          *(undefined2 *)(puVar8 + 0x4c) = 0;
          *puVar8 = *puVar8 | 0x800000;
          pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
          (*pTVar2)(instance,&eStack56);
          goto LAB_80085800;
        }
        Data = SetMonsterAlarmData((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],
                                   (_Position *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c),2)
        ;
        Message = 0x1000011;
      }
      else {
        if ((int)puVar5 < 0x80004) {
          if (instance->petrifyValue != 0) {
            return;
          }
                    /* WARNING: Subroutine does not return */
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
        }
        if ((*(char *)(puVar8[0x55] + 0x3a) != '\0') &&
           ((*(uint *)((int)instance->data + 0x10) & 8) == 0)) {
                    /* WARNING: Subroutine does not return */
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
        }
        Data = SetMonsterAlarmData((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],
                                   (_Position *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c),2)
        ;
        Message = 0x1000011;
      }
      goto LAB_80085914;
    }
    if (puVar5 == (undefined *)0x400000) {
      pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
      (*pTVar2)(instance,message->Data);
      return;
    }
    if (0x400000 < (int)puVar5) {
      if (puVar5 != (undefined *)0x1000000) {
        if (puVar5 != (undefined *)0x1000002) {
          return;
        }
        if (message->Data == 0) {
          CurrentSection = puVar8[0x31];
          if (CurrentSection == 0) {
            return;
          }
          *(ushort *)(CurrentSection + 0x18) = *(ushort *)(CurrentSection + 0x18) | 0x40;
          return;
        }
        MONSENSE_SetEnemy(instance,(_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]);
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
      }
      goto LAB_80084f7c;
    }
    if (puVar5 != (undefined *)0x80006) {
      return;
    }
  }
  if ((*(uint *)((int)instance->data + 0x10) & 0x10008) == 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_5c,local_60));
  }
  Data = SetMonsterAlarmData((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],
                             (_Position *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c),2);
  Message = 0x1000011;
LAB_80085914:
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(instance,Message,Data);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateQueueHandler(struct _Instance *instance /*$s0*/)
 // line 773, offset 0x800859c0
	/* begin block 1 */
		// Start line: 774
		// Start offset: 0x800859C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x800859F8
	// End Line: 780

	/* begin block 2 */
		// Start line: 1633
	/* end block 2 */
	// End Line: 1634

void MON_PupateQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleQueueHandler(struct _Instance *instance /*$s0*/)
 // line 782, offset 0x80085a0c
	/* begin block 1 */
		// Start line: 783
		// Start offset: 0x80085A0C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x80085A44
	// End Line: 789

	/* begin block 2 */
		// Start line: 1651
	/* end block 2 */
	// End Line: 1652

void MON_IdleQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultQueueHandler(struct _Instance *instance /*$s0*/)
 // line 791, offset 0x80085a58
	/* begin block 1 */
		// Start line: 792
		// Start offset: 0x80085A58
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x80085A90
	// End Line: 798

	/* begin block 2 */
		// Start line: 1669
	/* end block 2 */
	// End Line: 1670

void MON_DefaultQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}





