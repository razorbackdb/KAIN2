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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

int MON_GroundMoveQueueHandler(_Instance *instance)

{
  __Event *message;
  int iVar1;
  void *pvVar2;
  
  iVar1 = 0;
  pvVar2 = instance->extraData;
  while( true ) {
    message = DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8));
    if (message == (__Event *)0x0) break;
    if (message->ID == 0x4010080) {
      iVar1 = 0x4010080;
    }
    else {
      MON_IdleMessageHandler(instance,message);
    }
  }
  return iVar1;
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

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_PupateMessageHandler(_Instance *instance,__Event *message)

{
  short angle;
  long lVar1;
  ulong uVar2;
  int iVar3;
  undefined *puVar4;
  _Instance *p_Var5;
  uint *puVar6;
  undefined4 local_48;
  undefined4 in_stack_ffffffbc;
  evFXHitData eStack64;
  evFXHitData eStack40;
  
  puVar4 = (undefined *)message->ID;
  puVar6 = (uint *)instance->extraData;
  if (puVar4 == &DAT_00080004) {
    if (*(char *)(puVar6[0x59] + 0x3a) == '\0') {
      return;
    }
    MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
    *(undefined2 *)(puVar6 + 0x54) = 0x10;
    return;
  }
  if ((int)puVar4 < 0x80005) {
    if (puVar4 == &LAB_00080000_2) {
      iVar3 = MON_TakeDamage(instance,0x3000,0x100);
      if ((iVar3 != 0) && ((*puVar6 & 0x2000) != 0)) {
        *(undefined2 *)(puVar6 + 0x54) = 0x100;
      }
    }
    else {
      if ((int)puVar4 < 0x80003) {
        if (puVar4 != &LAB_00080000_1) {
          return;
        }
        if (instance->zVel != 0) {
          return;
        }
        angle = MATH3D_AngleFromPosToPos((_Position *)(DAT_800d20f8 + 0x5c),&instance->position);
        PhysicsSetVelFromZRot(instance,angle,100);
        instance->zVel = 0x32;
        (instance->position).z = (instance->position).z + 100;
        (instance->oldPos).z = (instance->oldPos).z + 100;
      }
      else {
        if (*(char *)(puVar6[0x59] + 0x3c) == '\0') {
          return;
        }
        MON_SetGlyphHitData(instance,&eStack40,0x200,1);
        *(undefined2 *)(puVar6 + 0x54) = 0x200;
        MON_DamageEffect(instance,&eStack40);
      }
    }
LAB_8008472c:
    MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
  }
  else {
    if (puVar4 != &DAT_00080006) {
      if (0x80005 < (int)puVar4) {
        if (puVar4 == (undefined *)0x1000000) {
          *puVar6 = *puVar6 & 0xffffff7f;
          return;
        }
        if (puVar4 != (undefined *)0x1000011) {
          return;
        }
        p_Var5 = (_Instance *)message->Data;
        lVar1 = MATH3D_LengthXYZ((int)*(short *)((int)&p_Var5->node + 4) -
                                 (int)(instance->position).x,
                                 (int)*(short *)((int)&p_Var5->node + 6) -
                                 (int)(instance->position).y,
                                 (int)*(short *)&p_Var5->next - (int)(instance->position).z);
        if (*(short *)(*(int *)(puVar6[0x59] + 4) + 0xe) <= lVar1) {
          return;
        }
        *puVar6 = *puVar6 & 0xffffff7f;
        if (puVar6[0x31] != 0) {
          return;
        }
        if (*(_Instance **)&p_Var5->node == (_Instance *)0x0) {
          return;
        }
        uVar2 = INSTANCE_Query(*(_Instance **)&p_Var5->node,1);
        if ((uVar2 & 0xb) == 0) {
          return;
        }
        MONSENSE_SetEnemy(instance,*(_Instance **)&p_Var5->node);
        return;
      }
      if (*(char *)(puVar6[0x59] + 0x39) != '\0') {
        MON_SetGlyphHitData(instance,&eStack64,0x20,1);
        *(undefined2 *)(puVar6 + 0x54) = 0x20;
        MON_DamageEffect(instance,&eStack64);
        goto LAB_8008472c;
      }
    }
    if (*(char *)(puVar6[0x59] + 0x38) != '\0') {
      MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
      MON_MonsterGlow(instance,0xffffff,0x46,10,0x14);
      *(undefined2 *)(puVar6 + 0x54) = 0x40;
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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_IdleMessageHandler(_Instance *instance,__Event *message)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  switch(message->ID) {
  case 0x1000002:
  case 0x100000a:
  case 0x1000023:
    if (message->Data == 0) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  default:
    MON_DefaultMessageHandler(instance,message);
    break;
  case 0x100000e:
    if ((*puVar2 & 4) == 0) {
      uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
      if ((uVar1 & 1) != 0) {
        MON_ChangeBehavior(instance,(uint)*(byte *)(puVar2 + 0x56));
      }
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    break;
  case 0x1000012:
    if ((*puVar2 & 4) == 0) {
      uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
      if ((uVar1 & 1) != 0) {
        MON_ChangeBehavior(instance,(uint)*(byte *)(puVar2 + 0x56));
      }
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
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

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_DefaultMessageHandler(_Instance *instance,__Event *message)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  short angle;
  ulong uVar4;
  long lVar5;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar6;
  uint CurrentSection;
  undefined *puVar7;
  short *psVar8;
  uint uVar9;
  _MonsterIR *Data;
  int iVar10;
  evFXHitData *data;
  byte bVar11;
  _Instance *p_Var12;
  int Data_00;
  _MonsterVars *mv;
  _Instance *Inst;
  undefined4 local_58;
  undefined4 local_54;
  evFXHitData eStack72;
  evFXHitData eStack48;
  
  puVar7 = (undefined *)message->ID;
  mv = (_MonsterVars *)instance->extraData;
  if (0x1000008 < (int)puVar7) {
    if (puVar7 == (undefined *)0x1000016) {
      if (mv->subAttr->combatAttributes->hitPoints == '\0') {
        return;
      }
      Data_00 = (int)mv->hitPoints + message->Data;
      angle = (short)Data_00;
      if (0x6000 < Data_00) {
        angle = 0x6000;
      }
LAB_800851b8:
      mv->hitPoints = angle;
      return;
    }
    if ((int)puVar7 < 0x1000017) {
      if (puVar7 == (undefined *)0x100000c) {
        if (((mv->mvFlags & 1) != 0) && (instance->currentMainState == 0xb)) {
          return;
        }
        Data_00 = message->Data;
        if (Data_00 == 0x20) {
          bVar11 = 0;
          if ((mv->mvFlags & 0x400) == 0) {
            bVar11 = mv->subAttr->fireVuln;
          }
        }
        else {
          if (Data_00 < 0x21) {
            bVar11 = 0;
            if (Data_00 == 0x10) {
              bVar11 = mv->subAttr->waterVuln;
            }
          }
          else {
            bVar11 = 0;
            if (Data_00 == 0x40) {
              bVar11 = mv->subAttr->sunVuln;
            }
          }
        }
        if (bVar11 != 0) {
          mv->damageType = *(ushort *)&message->Data;
          Data_00 = SetFXHitData((_Instance *)0x0,0,0,message->Data);
          INSTANCE_Post(instance,0x400000,Data_00);
        }
        if (bVar11 == 1) {
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          return;
        }
        if (bVar11 == 0) {
          return;
        }
        if (3 < bVar11) {
          return;
        }
        mv->mvFlags = mv->mvFlags | 0x200000;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if ((int)puVar7 < 0x100000d) {
        if (puVar7 == (undefined *)0x100000a) {
          p_Var12 = (_Instance *)message->Data;
          if (p_Var12 != (_Instance *)0x0) {
            mv->held = *(_Instance **)&p_Var12->node;
            Data_00 = rsin((int)*(short *)&p_Var12->next);
            Data_00 = *(short *)((int)&p_Var12->instanceID + 2) * Data_00;
            if (Data_00 < 0) {
              Data_00 = Data_00 + 0xfff;
            }
            angle = *(short *)&p_Var12->prev;
            iVar10 = rcos((int)*(short *)&p_Var12->next);
            iVar10 = *(short *)((int)&p_Var12->instanceID + 2) * iVar10;
            if (iVar10 < 0) {
              iVar10 = iVar10 + 0xfff;
            }
            sVar2 = *(short *)((int)&p_Var12->prev + 2);
            (instance->position).x = angle + (short)(Data_00 >> 0xc);
            (instance->position).y = sVar2 - (short)(iVar10 >> 0xc);
            (instance->rotation).z = *(short *)&p_Var12->next + 0x800U & 0xfff;
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
            return;
          }
          Data = mv->enemy;
          if (Data == (_MonsterIR *)0x0) {
            return;
          }
          Data->mirConditions = Data->mirConditions | 0x80;
          return;
        }
        if (0x100000a < (int)puVar7) {
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          return;
        }
        Data_00 = message->Data;
        lVar5 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(Data_00 + 4),
                                 (int)(instance->position).y - (int)*(short *)(Data_00 + 6),
                                 (int)(instance->position).z - (int)*(short *)(Data_00 + 8));
        if (6999 < lVar5) {
          return;
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (puVar7 != (undefined *)0x1000011) {
        if ((int)puVar7 < 0x1000012) {
          if (puVar7 != (undefined *)0x100000e) {
            return;
          }
        }
        else {
          if (puVar7 != (undefined *)0x1000012) {
            if (puVar7 != (undefined *)0x1000014) {
              return;
            }
            if (message->Data == 0) {
              return;
            }
            if (mv->soulJuice < 0x2000) {
              mv->soulJuice = 0;
              mv->damageType = 0;
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
              return;
            }
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
            return;
          }
        }
        if ((mv->mvFlags & 4) != 0) {
          return;
        }
        uVar4 = INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
        if ((uVar4 & 1) == 0) {
          return;
        }
        mv->behaviorState = mv->triggeredBehavior;
        return;
      }
      p_Var12 = (_Instance *)message->Data;
      Inst = *(_Instance **)&p_Var12->node;
      if (Inst == (_Instance *)0x0) {
        return;
      }
      uVar4 = INSTANCE_Query(Inst,1);
      if ((uVar4 & 0xb) == 0) {
        return;
      }
      Data = MONSENSE_FindIR(mv,Inst);
      if (Data != (_MonsterIR *)0x0) {
        return;
      }
      lVar5 = MATH3D_LengthXYZ((int)(instance->position).x -
                               (int)*(short *)((int)&p_Var12->node + 4),
                               (int)(instance->position).y -
                               (int)*(short *)((int)&p_Var12->node + 6),
                               (int)(instance->position).z - (int)*(short *)&p_Var12->next);
      if (mv->subAttr->senses->alarmRadius <= lVar5) {
        return;
      }
      Data = MONSENSE_SetEnemy(instance,Inst);
      if (Data == (_MonsterIR *)0x0) {
        return;
      }
      Data_00 = 0x1000012;
      goto LAB_80085540;
    }
    if (puVar7 != (undefined *)0x1000021) {
      if (0x1000021 < (int)puVar7) {
        if (puVar7 == (undefined *)0x2000002) {
          p_Var12 = (_Instance *)message->Data;
          Data = (_MonsterIR *)
                 SetMonsterHitData(instance,(_Instance *)0x0,(int)p_Var12->prev,
                                   (int)mv->attackType->knockBackDistance,
                                   (int)mv->attackType->knockBackDuration);
          Data_00 = 0x1000000;
          instance = *(_Instance **)&p_Var12->node;
          goto LAB_80085540;
        }
        if (0x2000002 < (int)puVar7) {
          if (puVar7 == (undefined *)0x4010080) {
            return;
          }
          if (puVar7 != (undefined *)0x8000008) {
            return;
          }
          MON_PlayAnimID(instance,*(int *)(message->Data + 4),*(int *)(message->Data + 0x10));
          return;
        }
        if (puVar7 != (undefined *)0x1000023) {
          return;
        }
        if (message->Data != 0x1000) {
          return;
        }
        mv->damageType = 0x400;
        goto LAB_80085350;
      }
      if (puVar7 == (undefined *)0x100001a) {
        if (message->Data != 0) {
          if ((mv->mvFlags & 0x20000000) != 0) {
            return;
          }
          mv->mvFlags = mv->mvFlags | 0x20000000;
          mv->hitPoints = (short)((int)mv->hitPoints << 1);
          return;
        }
        if ((mv->mvFlags & 0x20000000) == 0) {
          return;
        }
        mv->mvFlags = mv->mvFlags & 0xdfffffff;
        angle = (short)(((int)mv->hitPoints + 1) / 2);
        goto LAB_800851b8;
      }
      if ((int)puVar7 < 0x100001b) {
        if (puVar7 != (undefined *)0x1000019) {
          return;
        }
        MONSENSE_SetEnemy(instance,DAT_800d20f8);
        mv->held = (_Instance *)message->Data;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (puVar7 == (undefined *)0x100001c) {
        mv->terrainImpaleID = message->Data;
        MON_MoveInstanceToImpalePoint(instance);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (puVar7 != (undefined *)0x100001f) {
        return;
      }
    }
    if ((mv->mvFlags & 0x200040) != 0) {
      return;
    }
    bVar3 = false;
    iVar10 = message->Data;
    uVar1 = *(ushort *)(iVar10 + 0xc);
    mv->damageType = uVar1;
    Data_00 = 0;
    if (uVar1 == 0x20) {
      bVar3 = true;
    }
    else {
      Data_00 = 0x3000;
      if ((instance->flags2 & 0x8000000U) != 0) {
        Data_00 = 0x2000;
      }
    }
    if (bVar3) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    }
    if (Data_00 == 0) {
      mv->mvFlags = mv->mvFlags | 0x40;
      return;
    }
    *(int *)(iVar10 + 0xc) = Data_00;
LAB_80084bd0:
    if ((mv->mvFlags & 0x200040) != 0) {
      return;
    }
    if (instance->currentMainState == 10) {
      return;
    }
    p_Var12 = (_Instance *)message->Data;
    if (0x2fff < (int)p_Var12->prev) {
      instance->constrictAngle = 0;
    }
    mv->mvFlags = mv->mvFlags | 0x40;
    uVar4 = INSTANCE_Query(*(_Instance **)&p_Var12->node,1);
    Inst = DAT_800d20f8;
    if (uVar4 != 0x20) {
      Inst = *(_Instance **)&p_Var12->node;
    }
    MONSENSE_SetEnemy(instance,Inst);
    Data_00 = MON_TakeDamage(instance,(int)p_Var12->prev,0x100);
    iVar10 = 8;
    if ((Data_00 != 0) && (iVar10 = 9, (mv->mvFlags & 0x2000) != 0)) {
      iVar10 = 0x10;
    }
    if (iVar10 != -1) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    }
    mv->damageType = 0x100;
    *(_Instance **)&mv->messageData = p_Var12;
    return;
  }
  if (0x1000006 < (int)puVar7) {
    return;
  }
  if (puVar7 == &LAB_00080000_1) {
    if (instance->zVel != 0) {
      return;
    }
    if ((mv->mvFlags & 0x200000) != 0) {
      return;
    }
    Data = mv->enemy;
    if (Data != (_MonsterIR *)0x0) {
      Data->mirFlags = Data->mirFlags & 0xefff;
    }
    angle = MATH3D_AngleFromPosToPos(&DAT_800d20f8->position,&instance->position);
    PhysicsSetVelFromZRot(instance,angle,100);
    instance->zVel = 0x46;
    (instance->position).z = (instance->position).z + 0x78;
    (instance->oldPos).z = (instance->oldPos).z + 0x78;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    return;
  }
  if ((int)puVar7 < 0x80002) {
    if (puVar7 == (undefined *)0x4000d) {
      Data_00 = message->Data;
      mv->auxFlags = mv->auxFlags | 0x10000000;
      (mv->destination).z = *(short *)(Data_00 + 4);
      return;
    }
    if ((int)puVar7 < 0x4000e) {
      if (puVar7 == (undefined *)0x40009) {
        mv->damageType = 0x2000;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if ((int)puVar7 < 0x4000a) {
        if (puVar7 != (undefined *)0x40003) {
          return;
        }
        CurrentSection = (uint)mv->subAttr->numSections;
        Data_00 = message->Data;
        while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection) {
          G2EmulationInstanceToInstanceSwitchAnimation
                    (instance,*(_Instance **)(Data_00 + 4),CurrentSection,*(int *)(Data_00 + 8),
                     *(int *)(Data_00 + 0xc),*(int *)(Data_00 + 0x10),*(int *)(Data_00 + 0x14));
        }
        return;
      }
      if (puVar7 != (undefined *)0x4000c) {
        return;
      }
    }
    else {
      if (puVar7 == (undefined *)0x40010) {
        CurrentSection = mv->mvFlags;
        uVar9 = 0x7fffffff;
LAB_800854dc:
        mv->mvFlags = CurrentSection & uVar9;
        return;
      }
      if ((int)puVar7 < 0x40011) {
        if (puVar7 != (undefined *)0x4000f) {
          return;
        }
        psVar8 = (short *)message->Data;
        mv->mvFlags = mv->mvFlags | 0x80000000;
        (mv->lookAtPosData).x = *psVar8;
        (mv->lookAtPosData).y = psVar8[1];
        (mv->lookAtPosData).z = psVar8[2];
        return;
      }
      if (puVar7 != (undefined *)0x40016) {
        if (puVar7 != (undefined *)0x40017) {
          return;
        }
        mv->damageType = *(ushort *)(MISSILE_objectTable + message->Data + 2);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
    }
    psVar8 = (short *)message->Data;
    (mv->destination).x = *psVar8;
    (mv->destination).y = psVar8[1];
    angle = psVar8[2];
    mv->mvFlags = mv->mvFlags | 0x40000;
    (mv->destination).z = angle;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    return;
  }
  if (puVar7 == &DAT_00080005) {
    if (mv->subAttr->fireVuln == '\0') goto LAB_80085200;
    MON_SetGlyphHitData(instance,&eStack72,0x20,1);
    mv->damageType = 0x20;
    data = &eStack72;
  }
  else {
    if (0x80005 < (int)puVar7) {
      if (puVar7 == (undefined *)0x400000) {
        pTVar6 = MONTABLE_GetDamageEffectFunc(instance);
        (*pTVar6)(instance,message->Data);
        return;
      }
      if (0x400000 < (int)puVar7) {
        if (puVar7 != (undefined *)0x1000000) {
          if (puVar7 != (undefined *)0x1000002) {
            return;
          }
          if (message->Data == 0) {
            Data = mv->enemy;
            if (Data == (_MonsterIR *)0x0) {
              return;
            }
            Data->mirConditions = Data->mirConditions | 0x40;
            return;
          }
          MONSENSE_SetEnemy(instance,DAT_800d20f8);
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          CurrentSection = mv->mvFlags;
          uVar9 = 0xfffffffd;
          goto LAB_800854dc;
        }
        goto LAB_80084bd0;
      }
      if (puVar7 != &DAT_00080006) {
        return;
      }
LAB_80085200:
      if ((*(uint *)((int)instance->data + 0x10) & 0x10008) == 0) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        MON_MonsterGlow(instance,0xffffff,0x46,10,0x14);
        mv->damageType = 0x40;
        return;
      }
      Data = (_MonsterIR *)SetMonsterAlarmData(DAT_800d20f8,&DAT_800d20f8->position,2);
      Data_00 = 0x1000011;
LAB_80085540:
      INSTANCE_Post(instance,Data_00,(int)Data);
      return;
    }
    if (puVar7 != &LAB_00080000_3) {
      if ((int)puVar7 < 0x80004) {
        if (instance->petrifyValue != 0) {
          return;
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        instance->petrifyValue = 0x1000;
        return;
      }
      if ((mv->subAttr->waterVuln != '\0') && ((*(uint *)((int)instance->data + 0x10) & 8) == 0)) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        MON_MonsterGlow(instance,0xff0000,0x46,10,0x14);
        mv->damageType = 0x10;
        return;
      }
      Data = (_MonsterIR *)SetMonsterAlarmData(DAT_800d20f8,&DAT_800d20f8->position,2);
      Data_00 = 0x1000011;
      goto LAB_80085540;
    }
    if (mv->subAttr->soundVuln == '\0') {
      Data = (_MonsterIR *)SetMonsterAlarmData(DAT_800d20f8,&DAT_800d20f8->position,2);
      Data_00 = 0x1000011;
      goto LAB_80085540;
    }
    data = &eStack48;
    MON_SetGlyphHitData(instance,data,0x200,1);
    mv->damageType = 0x200;
  }
  MON_DamageEffect(instance,data);
LAB_80085350:
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
  return;
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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_PupateQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0) {
    MON_PupateMessageHandler(instance,message);
  }
  return;
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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_IdleQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0) {
    MON_IdleMessageHandler(instance,message);
  }
  return;
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

/* File: C:\kain2\game\MONSTER\MONMSG.C */

void MON_DefaultQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0) {
    MON_DefaultMessageHandler(instance,message);
  }
  return;
}





