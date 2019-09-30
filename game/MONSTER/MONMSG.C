#include "THISDUST.H"
#include "MONMSG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetGlyphHitData(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/, int type /*$a2*/, int amount /*$a3*/)
 // line 29, offset 0x80084384
	/* begin block 1 */
		// Start line: 58
	/* end block 1 */
	// End Line: 59

	/* begin block 2 */
		// Start line: 59
	/* end block 2 */
	// End Line: 60

void MON_SetGlyphHitData(_Instance *instance,evFXHitData *data,int type,int amount)

{
  short sVar1;
  
  data->type = (short)type;
  data->amount = (short)amount;
  (data->location).x = (instance->position).x;
  (data->location).y = (instance->position).y;
  sVar1 = (instance->position).z;
  (data->velocity).x = 0;
  (data->velocity).y = 0;
  (data->velocity).z = 0;
  (data->location).z = sVar1 + 0x100;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_GroundMoveQueueHandler(struct _Instance *instance /*$s1*/)
 // line 44, offset 0x800843c0
	/* begin block 1 */
		// Start line: 45
		// Start offset: 0x800843C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $a1
	// 		int ret; // $s0
	/* end block 1 */
	// End offset: 0x8008442C
	// End Line: 64

	/* begin block 2 */
		// Start line: 84
	/* end block 2 */
	// End Line: 85

	/* begin block 3 */
		// Start line: 91
	/* end block 3 */
	// End Line: 92

int MON_GroundMoveQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$a1*/)
 // line 72, offset 0x80084448
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x80084448
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 84
			// Start offset: 0x800844E8
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x80084570
		// End Line: 91

		/* begin block 1.2 */
			// Start line: 98
			// Start offset: 0x8008459C
			// Variables:
		// 		struct evFXHitData data; // stack offset -64
		/* end block 1.2 */
		// End offset: 0x800845CC
		// End Line: 105

		/* begin block 1.3 */
			// Start line: 150
			// Start offset: 0x800846A0
			// Variables:
		// 		struct evFXHitData data; // stack offset -40
		/* end block 1.3 */
		// End offset: 0x800846A0
		// End Line: 151

		/* begin block 1.4 */
			// Start line: 160
			// Start offset: 0x800846E4
		/* end block 1.4 */
		// End offset: 0x80084734
		// End Line: 171
	/* end block 1 */
	// End offset: 0x80084734
	// End Line: 176

	/* begin block 2 */
		// Start line: 155
	/* end block 2 */
	// End Line: 156

void MON_PupateMessageHandler(_Instance *instance,__Event *message)

{
  int iVar1;
  uint *puVar2;
  MonsterState in_stack_ffffffb8;
  evFXHitData eStack64;
  evFXHitData eStack40;
  
  iVar1 = message->ID;
  puVar2 = (uint *)instance->extraData;
  if (iVar1 == 0x80004) {
    if (*(char *)(puVar2[0x59] + 0x3a) != '\0') {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,in_stack_ffffffb8);
    }
  }
  else {
    if (iVar1 < 0x80005) {
      if (iVar1 == 0x80002) {
        iVar1 = MON_TakeDamage(instance,0x3000,0x100);
        if ((iVar1 != 0) && ((*puVar2 & 0x2000) != 0)) {
          *(undefined2 *)(puVar2 + 0x54) = 0x100;
        }
LAB_8008472c:
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,in_stack_ffffffb8);
      }
      if (iVar1 < 0x80003) {
        if ((iVar1 == 0x80001) && (instance->zVel == 0)) {
                    /* WARNING: Subroutine does not return */
          MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position,&instance->position);
        }
      }
      else {
        if (*(char *)(puVar2[0x59] + 0x3c) != '\0') {
          MON_SetGlyphHitData(instance,&eStack40,0x200,1);
          *(undefined2 *)(puVar2 + 0x54) = 0x200;
          MON_DamageEffect(instance,&eStack40);
          goto LAB_8008472c;
        }
      }
    }
    else {
      if (iVar1 != 0x80006) {
        if (0x80005 < iVar1) {
          if (iVar1 == 0x1000000) {
            *puVar2 = *puVar2 & 0xffffff7f;
            return;
          }
          if (iVar1 != 0x1000011) {
            return;
          }
          iVar1 = message->Data;
                    /* WARNING: Subroutine does not return */
          MATH3D_LengthXYZ((int)*(short *)(iVar1 + 4) - (int)(instance->position).x,
                           (int)*(short *)(iVar1 + 6) - (int)(instance->position).y,
                           (int)*(short *)(iVar1 + 8) - (int)(instance->position).z);
        }
        if (*(char *)(puVar2[0x59] + 0x39) != '\0') {
          MON_SetGlyphHitData(instance,&eStack64,0x20,1);
          *(undefined2 *)(puVar2 + 0x54) = 0x20;
          MON_DamageEffect(instance,&eStack64);
          goto LAB_8008472c;
        }
      }
      if (*(char *)(puVar2[0x59] + 0x38) != '\0') {
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,in_stack_ffffffb8);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s0*/)
 // line 178, offset 0x8008474c
	/* begin block 1 */
		// Start line: 179
		// Start offset: 0x8008474C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 210
			// Start offset: 0x800847D8
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.1 */
		// End offset: 0x80084804
		// End Line: 213

		/* begin block 1.2 */
			// Start line: 219
			// Start offset: 0x8008482C
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.2 */
		// End offset: 0x80084858
		// End Line: 222
	/* end block 1 */
	// End offset: 0x80084878
	// End Line: 229

	/* begin block 2 */
		// Start line: 379
	/* end block 2 */
	// End Line: 380

void MON_IdleMessageHandler(_Instance *instance,__Event *message)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  switch(message->ID) {
  case 0x1000002:
  case 0x100000a:
  case 0x1000023:
    if (message->Data == 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    }
  default:
    MON_DefaultMessageHandler(instance,message);
    break;
  case 0x100000e:
    if ((*(uint *)instance->extraData & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
    }
    break;
  case 0x1000012:
    if ((*(uint *)instance->extraData & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s3*/)
 // line 231, offset 0x80084890
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80084890
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a0
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 243
			// Start offset: 0x80084B58
			// Variables:
		// 		struct evMonsterHitData *data; // $s4
		// 		int fatal; // $a0
		// 		int damage; // $s0
		/* end block 1.1 */
		// End offset: 0x80084BD0
		// End Line: 329

		/* begin block 1.2 */
			// Start line: 333
			// Start offset: 0x80084BF8
			// Variables:
		// 		int state; // $a1
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x80084C9C
		// End Line: 372

		/* begin block 1.3 */
			// Start line: 386
			// Start offset: 0x80084CC4
			// Variables:
		// 		struct evMonsterSoulSuckData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x80084CFC
		// End Line: 390

		/* begin block 1.4 */
			// Start line: 428
			// Start offset: 0x80084DE8
			// Variables:
		// 		int vuln; // $s0
		/* end block 1.4 */
		// End offset: 0x80084EC4
		// End Line: 462

		/* begin block 1.5 */
			// Start line: 477
			// Start offset: 0x80084F1C
		/* end block 1.5 */
		// End offset: 0x80084F80
		// End Line: 481

		/* begin block 1.6 */
			// Start line: 521
			// Start offset: 0x80085018
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s0
		// 		struct _Instance *enemy; // $s3

			/* begin block 1.6.1 */
				// Start line: 528
				// Start offset: 0x8008505C

				/* begin block 1.6.1.1 */
					// Start line: 533
					// Start offset: 0x800850A8
					// Variables:
				// 		struct _MonsterIR *mir; // $v0
				/* end block 1.6.1.1 */
				// End offset: 0x800850C0
				// End Line: 538
			/* end block 1.6.1 */
			// End offset: 0x800850C0
			// End Line: 539
		/* end block 1.6 */
		// End offset: 0x800850C0
		// End Line: 543

		/* begin block 1.7 */
			// Start line: 549
			// Start offset: 0x800850DC
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.7 */
		// End offset: 0x800850FC
		// End Line: 551

		/* begin block 1.8 */
			// Start line: 557
			// Start offset: 0x80085128
			// Variables:
		// 		int hp; // $v1
		/* end block 1.8 */
		// End offset: 0x80085144
		// End Line: 560

		/* begin block 1.9 */
			// Start line: 593
			// Start offset: 0x800851D8
			// Variables:
		// 		struct evFXHitData data; // stack offset -72
		/* end block 1.9 */
		// End offset: 0x800851FC
		// End Line: 600

		/* begin block 1.10 */
			// Start line: 659
			// Start offset: 0x80085324
			// Variables:
		// 		struct evFXHitData data; // stack offset -48
		/* end block 1.10 */
		// End offset: 0x80085324
		// End Line: 660

		/* begin block 1.11 */
			// Start line: 671
			// Start offset: 0x800853A8
		/* end block 1.11 */
		// End offset: 0x800853C8
		// End Line: 676

		/* begin block 1.12 */
			// Start line: 693
			// Start offset: 0x8008543C
			// Variables:
		// 		struct evPositionData *posData; // $a0
		/* end block 1.12 */
		// End offset: 0x8008543C
		// End Line: 693

		/* begin block 1.13 */
			// Start line: 701
			// Start offset: 0x8008545C
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.13 */
		// End offset: 0x8008545C
		// End Line: 701

		/* begin block 1.14 */
			// Start line: 711
			// Start offset: 0x8008549C
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.14 */
		// End offset: 0x8008549C
		// End Line: 711

		/* begin block 1.15 */
			// Start line: 724
			// Start offset: 0x800854E8
			// Variables:
		// 		static int deaths[9]; // offset 0x0
		/* end block 1.15 */
		// End offset: 0x800854E8
		// End Line: 735

		/* begin block 1.16 */
			// Start line: 741
			// Start offset: 0x80085514
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.16 */
		// End offset: 0x80085514
		// End Line: 741

		/* begin block 1.17 */
			// Start line: 748
			// Start offset: 0x80085550
			// Variables:
		// 		int i; // $s1
		// 		struct evActionPlayHostAnimationData *data; // $s0
		/* end block 1.17 */
		// End offset: 0x800855A8
		// End Line: 752

		/* begin block 1.18 */
			// Start line: 756
			// Start offset: 0x800855B0
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v0
		/* end block 1.18 */
		// End offset: 0x800855C8
		// End Line: 758
	/* end block 1 */
	// End offset: 0x800855C8
	// End Line: 763

	/* begin block 2 */
		// Start line: 490
	/* end block 2 */
	// End Line: 491

/* WARNING: Removing unreachable block (ram,0x80084ea4) */
/* WARNING: Removing unreachable block (ram,0x80084ebc) */
/* WARNING: Removing unreachable block (ram,0x80084ec4) */
/* WARNING: Type propagation algorithm not settling */

void MON_DefaultMessageHandler(_Instance *instance,__Event *message)

{
  short sVar1;
  bool bVar2;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar3;
  uint CurrentSection;
  undefined2 uVar4;
  int Data;
  undefined2 *puVar5;
  evFXHitData *data;
  char cVar6;
  uint *puVar7;
  uint *puVar8;
  _Instance *Inst;
  int iVar9;
  undefined4 local_58;
  undefined4 local_54;
  evFXHitData eStack72;
  evFXHitData eStack48;
  
  Data = message->ID;
  puVar8 = (uint *)instance->extraData;
  if (0x1000008 < Data) {
    if (Data == 0x1000016) {
      if (*(char *)(*(int *)(puVar8[0x59] + 8) + 0x18) == '\0') {
        return;
      }
      Data = (int)*(short *)(puVar8 + 0x50) + message->Data;
      uVar4 = (undefined2)Data;
      if (0x6000 < Data) {
        uVar4 = 0x6000;
      }
LAB_800851b8:
      *(undefined2 *)(puVar8 + 0x50) = uVar4;
      return;
    }
    if (Data < 0x1000017) {
      if (Data == 0x100000c) {
        if (((*puVar8 & 1) != 0) && (instance->currentMainState == 0xb)) {
          return;
        }
        Data = message->Data;
        if (Data == 0x20) {
          cVar6 = '\0';
          if ((*puVar8 & 0x400) == 0) {
            cVar6 = *(char *)(puVar8[0x59] + 0x39);
          }
        }
        else {
          if (Data < 0x21) {
            cVar6 = '\0';
            if (Data == 0x10) {
              cVar6 = *(char *)(puVar8[0x59] + 0x3a);
            }
          }
          else {
            cVar6 = '\0';
            if (Data == 0x40) {
              cVar6 = *(char *)(puVar8[0x59] + 0x38);
            }
          }
        }
        if (cVar6 == '\0') {
          return;
        }
        *(undefined2 *)(puVar8 + 0x54) = *(undefined2 *)&message->Data;
        Data = SetFXHitData((_Instance *)0x0,0,0,message->Data);
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance,0x400000,Data);
      }
      if (0x100000c < Data) {
        if (Data == 0x1000011) {
          Inst = *(_Instance **)&((_Instance *)message->Data)->node;
          if (Inst == (_Instance *)0x0) {
            return;
          }
                    /* WARNING: Subroutine does not return */
          INSTANCE_Query(Inst,1);
        }
        if (Data < 0x1000012) {
          if (Data != 0x100000e) {
            return;
          }
        }
        else {
          if (Data != 0x1000012) {
            if (Data != 0x1000014) {
              return;
            }
            if (message->Data == 0) {
              return;
            }
            if (0x1fff < *(short *)(puVar8 + 0x51)) {
                    /* WARNING: Subroutine does not return */
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
            }
            *(undefined2 *)(puVar8 + 0x51) = 0;
                    /* WARNING: Subroutine does not return */
            *(undefined2 *)(puVar8 + 0x54) = 0;
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          }
        }
        if ((*puVar8 & 4) != 0) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
      }
      if (Data != 0x100000a) {
        if (0x100000a < Data) {
                    /* WARNING: Subroutine does not return */
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
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
    if (Data != 0x1000021) {
      if (0x1000021 < Data) {
        if (Data == 0x2000002) {
                    /* WARNING: Subroutine does not return */
          SetMonsterHitData(instance,(_Instance *)0x0,*(int *)(message->Data + 0xc),
                            (int)*(short *)(puVar8[0x2e] + 4),(int)*(char *)(puVar8[0x2e] + 6));
        }
        if (0x2000002 < Data) {
          if (Data == 0x4010080) {
            return;
          }
          if (Data != 0x8000008) {
            return;
          }
                    /* WARNING: Subroutine does not return */
          MON_PlayAnimID(instance,*(int *)(message->Data + 4),*(int *)(message->Data + 0x10));
        }
        if (Data != 0x1000023) {
          return;
        }
        if (message->Data != 0x1000) {
          return;
        }
        *(undefined2 *)(puVar8 + 0x54) = 0x400;
        goto LAB_80085350;
      }
      if (Data == 0x100001a) {
        if (message->Data != 0) {
          if ((*puVar8 & 0x20000000) != 0) {
            return;
          }
          *puVar8 = *puVar8 | 0x20000000;
          *(short *)(puVar8 + 0x50) = (short)((int)*(short *)(puVar8 + 0x50) << 1);
          return;
        }
        if ((*puVar8 & 0x20000000) == 0) {
          return;
        }
        *puVar8 = *puVar8 & 0xdfffffff;
        uVar4 = (undefined2)(((int)*(short *)(puVar8 + 0x50) + 1) / 2);
        goto LAB_800851b8;
      }
      if (Data < 0x100001b) {
        if (Data != 0x1000019) {
          return;
        }
        MONSENSE_SetEnemy(instance,gameTrackerX.playerInstance);
                    /* WARNING: Subroutine does not return */
        puVar8[0x34] = message->Data;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      if (Data == 0x100001c) {
        puVar8[0x68] = message->Data;
        MON_MoveInstanceToImpalePoint(instance);
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      if (Data != 0x100001f) {
        return;
      }
    }
    if ((*puVar8 & 0x200040) != 0) {
      return;
    }
    bVar2 = false;
    iVar9 = message->Data;
    sVar1 = *(short *)(iVar9 + 0xc);
    *(short *)(puVar8 + 0x54) = sVar1;
    Data = 0;
    if (sVar1 == 0x20) {
      bVar2 = true;
    }
    else {
      Data = 0x3000;
      if ((instance->flags2 & 0x8000000U) != 0) {
        Data = 0x2000;
      }
    }
    if (bVar2) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    }
    if (Data == 0) {
      *puVar8 = *puVar8 | 0x40;
      return;
    }
    *(int *)(iVar9 + 0xc) = Data;
LAB_80084bd0:
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
  if (0x1000006 < Data) {
    return;
  }
  if (Data == 0x80001) {
    if (instance->zVel != 0) {
      return;
    }
    if ((*puVar8 & 0x200000) != 0) {
      return;
    }
    CurrentSection = puVar8[0x31];
    if (CurrentSection != 0) {
      *(ushort *)(CurrentSection + 0x16) = *(ushort *)(CurrentSection + 0x16) & 0xefff;
    }
                    /* WARNING: Subroutine does not return */
    MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position,&instance->position);
  }
  if (Data < 0x80002) {
    if (Data == 0x4000d) {
      Data = message->Data;
      puVar8[1] = puVar8[1] | 0x10000000;
      *(undefined2 *)(puVar8 + 0x49) = *(undefined2 *)(Data + 4);
      return;
    }
    if (Data < 0x4000e) {
      if (Data == 0x40009) {
        *(undefined2 *)(puVar8 + 0x54) = 0x2000;
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      if (Data < 0x4000a) {
        if (Data != 0x40003) {
          return;
        }
        CurrentSection = (uint)*(byte *)(puVar8[0x59] + 0x2a);
        Data = message->Data;
        while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection) {
          G2EmulationInstanceToInstanceSwitchAnimation
                    (instance,*(_Instance **)(Data + 4),CurrentSection,*(int *)(Data + 8),
                     *(int *)(Data + 0xc),*(int *)(Data + 0x10),*(int *)(Data + 0x14));
        }
        return;
      }
      if (Data != 0x4000c) {
        return;
      }
    }
    else {
      if (Data == 0x40010) {
        *puVar8 = *puVar8 & 0x7fffffff;
        return;
      }
      if (Data < 0x40011) {
        if (Data != 0x4000f) {
          return;
        }
        puVar5 = (undefined2 *)message->Data;
        *puVar8 = *puVar8 | 0x80000000;
        *(undefined2 *)((int)puVar8 + 0x12e) = *puVar5;
        *(undefined2 *)(puVar8 + 0x4c) = puVar5[1];
        *(undefined2 *)((int)puVar8 + 0x132) = puVar5[2];
        return;
      }
      if (Data != 0x40016) {
        if (Data != 0x40017) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        *(undefined2 *)(puVar8 + 0x54) = *(undefined2 *)(&LAB_800cb194 + message->Data * 4);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
    }
    puVar5 = (undefined2 *)message->Data;
    *(undefined2 *)(puVar8 + 0x48) = *puVar5;
    *(undefined2 *)((int)puVar8 + 0x122) = puVar5[1];
    uVar4 = puVar5[2];
    *puVar8 = *puVar8 | 0x40000;
                    /* WARNING: Subroutine does not return */
    *(undefined2 *)(puVar8 + 0x49) = uVar4;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
  }
  if (Data == 0x80005) {
    if (*(char *)(puVar8[0x59] + 0x39) == '\0') goto LAB_80085200;
    MON_SetGlyphHitData(instance,&eStack72,0x20,1);
    *(undefined2 *)(puVar8 + 0x54) = 0x20;
    data = &eStack72;
  }
  else {
    if (0x80005 < Data) {
      if (Data == 0x400000) {
        pTVar3 = MONTABLE_GetDamageEffectFunc(instance);
        (*pTVar3)(instance,message->Data);
        return;
      }
      if (0x400000 < Data) {
        if (Data != 0x1000000) {
          if (Data != 0x1000002) {
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
          MONSENSE_SetEnemy(instance,gameTrackerX.playerInstance);
                    /* WARNING: Subroutine does not return */
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        }
        goto LAB_80084bd0;
      }
      if (Data != 0x80006) {
        return;
      }
LAB_80085200:
      if ((*(uint *)((int)instance->data + 0x10) & 0x10008) == 0) {
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      Data = SetMonsterAlarmData(gameTrackerX.playerInstance,
                                 &(gameTrackerX.playerInstance)->position,2);
LAB_80085540:
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance,0x1000011,Data);
    }
    if (Data != 0x80003) {
      if (Data < 0x80004) {
        if (instance->petrifyValue != 0) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      if ((*(char *)(puVar8[0x59] + 0x3a) != '\0') &&
         ((*(uint *)((int)instance->data + 0x10) & 8) == 0)) {
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      Data = SetMonsterAlarmData(gameTrackerX.playerInstance,
                                 &(gameTrackerX.playerInstance)->position,2);
      goto LAB_80085540;
    }
    if (*(char *)(puVar8[0x59] + 0x3c) == '\0') {
      Data = SetMonsterAlarmData(gameTrackerX.playerInstance,
                                 &(gameTrackerX.playerInstance)->position,2);
      goto LAB_80085540;
    }
    data = &eStack48;
    MON_SetGlyphHitData(instance,data,0x200,1);
    *(undefined2 *)(puVar8 + 0x54) = 0x200;
  }
  MON_DamageEffect(instance,data);
LAB_80085350:
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateQueueHandler(struct _Instance *instance /*$s0*/)
 // line 765, offset 0x800855e8
	/* begin block 1 */
		// Start line: 766
		// Start offset: 0x800855E8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x80085620
	// End Line: 772

	/* begin block 2 */
		// Start line: 1609
	/* end block 2 */
	// End Line: 1610

void MON_PupateQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleQueueHandler(struct _Instance *instance /*$s0*/)
 // line 774, offset 0x80085634
	/* begin block 1 */
		// Start line: 775
		// Start offset: 0x80085634
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x8008566C
	// End Line: 781

	/* begin block 2 */
		// Start line: 1627
	/* end block 2 */
	// End Line: 1628

void MON_IdleQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultQueueHandler(struct _Instance *instance /*$s0*/)
 // line 783, offset 0x80085680
	/* begin block 1 */
		// Start line: 784
		// Start offset: 0x80085680
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x800856B8
	// End Line: 790

	/* begin block 2 */
		// Start line: 1645
	/* end block 2 */
	// End Line: 1646

void MON_DefaultQueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}





