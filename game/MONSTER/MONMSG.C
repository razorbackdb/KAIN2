#include "THISDUST.H"
#include "MONMSG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetGlyphHitData(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/, int type /*$a2*/, int amount /*$a3*/)
 // line 29, offset 0x800836f8
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
 // line 44, offset 0x80083734
	/* begin block 1 */
		// Start line: 45
		// Start offset: 0x80083734
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $a1
	// 		int ret; // $s0
	/* end block 1 */
	// End offset: 0x800837A0
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
 // line 72, offset 0x800837bc
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x800837BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 84
			// Start offset: 0x8008385C
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800838E4
		// End Line: 91

		/* begin block 1.2 */
			// Start line: 98
			// Start offset: 0x80083910
			// Variables:
		// 		struct evFXHitData data; // stack offset -64
		/* end block 1.2 */
		// End offset: 0x80083940
		// End Line: 105

		/* begin block 1.3 */
			// Start line: 150
			// Start offset: 0x80083A14
			// Variables:
		// 		struct evFXHitData data; // stack offset -40
		/* end block 1.3 */
		// End offset: 0x80083A14
		// End Line: 151

		/* begin block 1.4 */
			// Start line: 160
			// Start offset: 0x80083A58
		/* end block 1.4 */
		// End offset: 0x80083AA8
		// End Line: 171
	/* end block 1 */
	// End offset: 0x80083AA8
	// End Line: 176

	/* begin block 2 */
		// Start line: 155
	/* end block 2 */
	// End Line: 156

/* WARNING: Type propagation algorithm not settling */

void MON_PupateMessageHandler(_Instance *instance,__Event *message)

{
  short angle;
  long lVar1;
  ulong uVar2;
  int iVar3;
  _Instance *p_Var4;
  uint *puVar5;
  undefined4 local_48;
  undefined4 in_stack_ffffffbc;
  evFXHitData eStack64;
  evFXHitData eStack40;
  
  iVar3 = message->ID;
  puVar5 = (uint *)instance->extraData;
  if (iVar3 == 0x80004) {
    iVar3 = MON_TakeDamage(instance,0x3000,0x100);
    if ((iVar3 != 0) && ((*puVar5 & 0x2000) != 0)) {
      *(undefined2 *)(puVar5 + 0x54) = 0x100;
    }
  }
  else {
    if (iVar3 < 0x80005) {
      if (iVar3 == 0x80002) {
        if (*(char *)(puVar5[0x59] + 0x3a) == '\0') {
          return;
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
        *(undefined2 *)(puVar5 + 0x54) = 0x10;
        return;
      }
      if (iVar3 < 0x80003) {
        if (iVar3 != 0x80001) {
          return;
        }
      }
      else {
        if (*(char *)(puVar5[0x59] + 0x39) != '\0') {
          MON_SetGlyphHitData(instance,&eStack64,0x20,1);
          *(undefined2 *)(puVar5 + 0x54) = 0x20;
          MON_DamageEffect(instance,&eStack64);
          goto LAB_80083aa0;
        }
      }
      if (*(char *)(puVar5[0x59] + 0x38) == '\0') {
        return;
      }
      MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
      MON_MonsterGlow(instance,0xffffff,0x46,10,0x14);
      *(undefined2 *)(puVar5 + 0x54) = 0x40;
      return;
    }
    if (iVar3 == 0x80006) {
      if (*(char *)(puVar5[0x59] + 0x3c) == '\0') {
        return;
      }
      MON_SetGlyphHitData(instance,&eStack40,0x200,1);
      *(undefined2 *)(puVar5 + 0x54) = 0x200;
      MON_DamageEffect(instance,&eStack40);
    }
    else {
      if (0x80005 < iVar3) {
        if (iVar3 == 0x1000000) {
          *puVar5 = *puVar5 & 0xffffff7f;
          return;
        }
        if (iVar3 != 0x1000011) {
          return;
        }
        p_Var4 = (_Instance *)message->Data;
        lVar1 = MATH3D_LengthXYZ((int)*(short *)((int)&p_Var4->node + 4) -
                                 (int)(instance->position).x,
                                 (int)*(short *)((int)&p_Var4->node + 6) -
                                 (int)(instance->position).y,
                                 (int)*(short *)&p_Var4->next - (int)(instance->position).z);
        if (*(short *)(*(int *)(puVar5[0x59] + 4) + 0xe) <= lVar1) {
          return;
        }
        *puVar5 = *puVar5 & 0xffffff7f;
        if (puVar5[0x31] != 0) {
          return;
        }
        if (*(_Instance **)&p_Var4->node == (_Instance *)0x0) {
          return;
        }
        uVar2 = INSTANCE_Query(*(_Instance **)&p_Var4->node,1);
        if ((uVar2 & 0xb) == 0) {
          return;
        }
        MONSENSE_SetEnemy(instance,*(_Instance **)&p_Var4->node);
        return;
      }
      if (instance->zVel != 0) {
        return;
      }
      angle = MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position,&instance->position)
      ;
      PhysicsSetVelFromZRot(instance,angle,100);
      instance->zVel = 0x32;
      (instance->position).z = (instance->position).z + 100;
      (instance->oldPos).z = (instance->oldPos).z + 100;
    }
  }
LAB_80083aa0:
  MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffbc,local_48));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s1*/)
 // line 178, offset 0x80083ac0
	/* begin block 1 */
		// Start line: 179
		// Start offset: 0x80083AC0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 203
			// Start offset: 0x80083B64
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.1 */
		// End offset: 0x80083B90
		// End Line: 206

		/* begin block 1.2 */
			// Start line: 212
			// Start offset: 0x80083BB8
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.2 */
		// End offset: 0x80083BE4
		// End Line: 215
	/* end block 1 */
	// End offset: 0x80083C00
	// End Line: 222

	/* begin block 2 */
		// Start line: 379
	/* end block 2 */
	// End Line: 380

void MON_IdleMessageHandler(_Instance *instance,__Event *message)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  
  iVar2 = message->ID;
  puVar3 = (uint *)instance->extraData;
  if (iVar2 != 0x100000a) {
    if (0x100000a < iVar2) {
      if (iVar2 == 0x100000e) {
        if ((*puVar3 & 4) != 0) {
          return;
        }
        uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
        if ((uVar1 & 1) != 0) {
          MON_ChangeBehavior(instance,(uint)*(byte *)(puVar3 + 0x56));
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
        return;
      }
      if (iVar2 == 0x1000012) {
        if ((*puVar3 & 4) != 0) {
          return;
        }
        uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4),1);
        if ((uVar1 & 1) != 0) {
          MON_ChangeBehavior(instance,(uint)*(byte *)(puVar3 + 0x56));
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
        return;
      }
      goto LAB_80083bf8;
    }
    if (iVar2 != 0x1000002) goto LAB_80083bf8;
  }
  if (message->Data == 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
LAB_80083bf8:
  MON_DefaultMessageHandler(instance,message);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultMessageHandler(struct _Instance *instance /*$s3*/, struct __Event *message /*$s2*/)
 // line 224, offset 0x80083c18
	/* begin block 1 */
		// Start line: 225
		// Start offset: 0x80083C18
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long id; // $v1

		/* begin block 1.1 */
			// Start line: 236
			// Start offset: 0x80083EF4
			// Variables:
		// 		struct evMonsterHitData *data; // $s4
		// 		int fatal; // $a0
		// 		int damage; // $s0
		/* end block 1.1 */
		// End offset: 0x80083F6C
		// End Line: 322

		/* begin block 1.2 */
			// Start line: 326
			// Start offset: 0x80083F84
			// Variables:
		// 		int state; // $a1
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x80084028
		// End Line: 365

		/* begin block 1.3 */
			// Start line: 371
			// Start offset: 0x80084038
			// Variables:
		// 		struct evMonsterSoulSuckData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x80084070
		// End Line: 375

		/* begin block 1.4 */
			// Start line: 412
			// Start offset: 0x80084138
			// Variables:
		// 		int vuln; // $s0
		/* end block 1.4 */
		// End offset: 0x8008421C
		// End Line: 446

		/* begin block 1.5 */
			// Start line: 461
			// Start offset: 0x80084274
		/* end block 1.5 */
		// End offset: 0x800842D8
		// End Line: 465

		/* begin block 1.6 */
			// Start line: 505
			// Start offset: 0x80084370
			// Variables:
		// 		struct evMonsterAlarmData *data; // $s0
		// 		struct _Instance *enemy; // $s2

			/* begin block 1.6.1 */
				// Start line: 512
				// Start offset: 0x800843B4

				/* begin block 1.6.1.1 */
					// Start line: 517
					// Start offset: 0x80084400
					// Variables:
				// 		struct _MonsterIR *mir; // $v0
				/* end block 1.6.1.1 */
				// End offset: 0x80084418
				// End Line: 522
			/* end block 1.6.1 */
			// End offset: 0x80084418
			// End Line: 523
		/* end block 1.6 */
		// End offset: 0x80084418
		// End Line: 527

		/* begin block 1.7 */
			// Start line: 533
			// Start offset: 0x80084434
			// Variables:
		// 		struct _MonsterIR *mir; // $v0
		/* end block 1.7 */
		// End offset: 0x80084454
		// End Line: 535

		/* begin block 1.8 */
			// Start line: 576
			// Start offset: 0x80084544
			// Variables:
		// 		struct evFXHitData data; // stack offset -72
		/* end block 1.8 */
		// End offset: 0x80084568
		// End Line: 583

		/* begin block 1.9 */
			// Start line: 628
			// Start offset: 0x80084630
			// Variables:
		// 		struct evFXHitData data; // stack offset -48
		/* end block 1.9 */
		// End offset: 0x80084630
		// End Line: 629

		/* begin block 1.10 */
			// Start line: 638
			// Start offset: 0x80084694
		/* end block 1.10 */
		// End offset: 0x80084694
		// End Line: 641

		/* begin block 1.11 */
			// Start line: 658
			// Start offset: 0x80084700
			// Variables:
		// 		struct evPositionData *posData; // $a0
		/* end block 1.11 */
		// End offset: 0x80084700
		// End Line: 658

		/* begin block 1.12 */
			// Start line: 666
			// Start offset: 0x8008471C
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.12 */
		// End offset: 0x8008471C
		// End Line: 666

		/* begin block 1.13 */
			// Start line: 676
			// Start offset: 0x8008475C
			// Variables:
		// 		struct evPositionData *posData; // $v1
		/* end block 1.13 */
		// End offset: 0x8008475C
		// End Line: 676

		/* begin block 1.14 */
			// Start line: 689
			// Start offset: 0x800847AC
			// Variables:
		// 		static int deaths[9]; // offset 0x0
		/* end block 1.14 */
		// End offset: 0x800847AC
		// End Line: 700

		/* begin block 1.15 */
			// Start line: 706
			// Start offset: 0x800847DC
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.15 */
		// End offset: 0x800847DC
		// End Line: 706

		/* begin block 1.16 */
			// Start line: 713
			// Start offset: 0x80084818
			// Variables:
		// 		int i; // $s1
		// 		struct evActionPlayHostAnimationData *data; // $s0
		/* end block 1.16 */
		// End offset: 0x80084870
		// End Line: 717

		/* begin block 1.17 */
			// Start line: 721
			// Start offset: 0x80084878
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v0
		/* end block 1.17 */
		// End offset: 0x80084890
		// End Line: 723
	/* end block 1 */
	// End offset: 0x80084890
	// End Line: 732

	/* begin block 2 */
		// Start line: 476
	/* end block 2 */
	// End Line: 477

/* WARNING: Type propagation algorithm not settling */

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
  int Data;
  short *psVar7;
  uint uVar8;
  _MonsterIR *Data_00;
  int iVar9;
  evFXHitData *data;
  byte bVar10;
  _Instance *p_Var11;
  _MonsterVars *mv;
  _Instance *Inst;
  undefined4 local_58;
  undefined4 local_54;
  evFXHitData eStack72;
  evFXHitData eStack48;
  
  Data = message->ID;
  mv = (_MonsterVars *)instance->extraData;
  if (0x1000008 < Data) {
    if (Data == 0x1000016) {
      if (*(char *)&mv->subAttr->combatAttributes->suckTime == '\0') {
        return;
      }
      angle = mv->hitPoints + *(short *)&message->Data;
      mv->hitPoints = angle;
      if (angle < 0x6001) {
        return;
      }
      mv->hitPoints = 0x6000;
      return;
    }
    if (Data < 0x1000017) {
      if (Data == 0x100000c) {
        Data = message->Data;
        if (Data == 0x20) {
          bVar10 = 0;
          if ((mv->mvFlags & 0x400) == 0) {
            bVar10 = mv->subAttr->fireVuln;
          }
        }
        else {
          if (Data < 0x21) {
            bVar10 = 0;
            if (Data == 0x10) {
              bVar10 = mv->subAttr->waterVuln;
            }
          }
          else {
            bVar10 = 0;
            if (Data == 0x40) {
              bVar10 = mv->subAttr->sunVuln;
            }
          }
        }
        if (bVar10 != 0) {
          mv->damageType = *(ushort *)&message->Data;
          Data = SetFXHitData((_Instance *)0x0,0,0,message->Data);
          INSTANCE_Post(instance,0x400000,Data);
        }
        if (bVar10 == 1) {
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          return;
        }
        if (bVar10 == 0) {
          return;
        }
        if (3 < bVar10) {
          return;
        }
        mv->mvFlags = mv->mvFlags | 0x200000;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (Data < 0x100000d) {
        if (Data == 0x100000a) {
          p_Var11 = (_Instance *)message->Data;
          if (p_Var11 != (_Instance *)0x0) {
            mv->held = *(_Instance **)&p_Var11->node;
            Data = rsin((int)*(short *)&p_Var11->next);
            Data = *(short *)((int)&p_Var11->instanceID + 2) * Data;
            if (Data < 0) {
              Data = Data + 0xfff;
            }
            angle = *(short *)&p_Var11->prev;
            iVar9 = rcos((int)*(short *)&p_Var11->next);
            iVar9 = *(short *)((int)&p_Var11->instanceID + 2) * iVar9;
            if (iVar9 < 0) {
              iVar9 = iVar9 + 0xfff;
            }
            sVar2 = *(short *)((int)&p_Var11->prev + 2);
            (instance->position).x = angle + (short)(Data >> 0xc);
            (instance->position).y = sVar2 - (short)(iVar9 >> 0xc);
            (instance->rotation).z = *(short *)&p_Var11->next + 0x800U & 0xfff;
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
            return;
          }
          Data_00 = mv->enemy;
          if (Data_00 == (_MonsterIR *)0x0) {
            return;
          }
          Data_00->mirConditions = Data_00->mirConditions | 0x80;
          return;
        }
        if (0x100000a < Data) {
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
          return;
        }
        Data = message->Data;
        lVar5 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(Data + 4),
                                 (int)(instance->position).y - (int)*(short *)(Data + 6),
                                 (int)(instance->position).z - (int)*(short *)(Data + 8));
        if (6999 < lVar5) {
          return;
        }
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (Data != 0x1000011) {
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
        MON_ChangeBehavior(instance,(uint)mv->triggeredBehavior);
        return;
      }
      p_Var11 = (_Instance *)message->Data;
      Inst = *(_Instance **)&p_Var11->node;
      if (Inst == (_Instance *)0x0) {
        return;
      }
      uVar4 = INSTANCE_Query(Inst,1);
      if ((uVar4 & 0xb) == 0) {
        return;
      }
      Data_00 = MONSENSE_FindIR(mv,Inst);
      if (Data_00 != (_MonsterIR *)0x0) {
        return;
      }
      lVar5 = MATH3D_LengthXYZ((int)(instance->position).x -
                               (int)*(short *)((int)&p_Var11->node + 4),
                               (int)(instance->position).y -
                               (int)*(short *)((int)&p_Var11->node + 6),
                               (int)(instance->position).z - (int)*(short *)&p_Var11->next);
      if (mv->subAttr->senses->alarmRadius <= lVar5) {
        return;
      }
      Data_00 = MONSENSE_SetEnemy(instance,Inst);
      if (Data_00 == (_MonsterIR *)0x0) {
        return;
      }
      Data = 0x1000012;
LAB_80084808:
      INSTANCE_Post(instance,Data,(int)Data_00);
      return;
    }
    if (Data != 0x1000021) {
      if (0x1000021 < Data) {
        if (Data == 0x4010080) {
          return;
        }
        if (0x4010080 < Data) {
          if (Data == 0x4010401) {
            return;
          }
          if (Data != 0x8000008) {
            return;
          }
          MON_PlayAnimID(instance,*(int *)(message->Data + 4),*(int *)(message->Data + 0x10));
          return;
        }
        if (Data != 0x2000002) {
          return;
        }
        p_Var11 = (_Instance *)message->Data;
        Data_00 = (_MonsterIR *)
                  SetMonsterHitData(instance,(_Instance *)0x0,(int)p_Var11->prev,
                                    (int)mv->attackType->knockBackDistance,
                                    (int)mv->attackType->knockBackDuration);
        Data = 0x1000000;
        instance = *(_Instance **)&p_Var11->node;
        goto LAB_80084808;
      }
      if (Data == 0x100001a) {
        if (message->Data == 0) {
          if ((mv->mvFlags & 0x20000000) == 0) {
            return;
          }
          mv->mvFlags = mv->mvFlags & 0xdfffffff;
          mv->hitPoints = (short)(((int)mv->hitPoints + 1) / 2);
          return;
        }
        if ((mv->mvFlags & 0x20000000) != 0) {
          return;
        }
        mv->mvFlags = mv->mvFlags | 0x20000000;
        mv->hitPoints = (short)((int)mv->hitPoints << 1);
        return;
      }
      if (Data < 0x100001b) {
        if (Data != 0x1000019) {
          return;
        }
        MONSENSE_SetEnemy(instance,gameTrackerX.playerInstance);
        mv->held = (_Instance *)message->Data;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (Data == 0x100001c) {
        mv->terrainImpaleID = message->Data;
        MON_MoveInstanceToImpalePoint(instance);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (Data != 0x100001f) {
        return;
      }
    }
    if ((mv->mvFlags & 0x200040) != 0) {
      return;
    }
    bVar3 = false;
    iVar9 = message->Data;
    uVar1 = *(ushort *)(iVar9 + 0xc);
    mv->damageType = uVar1;
    Data = 0;
    if (uVar1 == 0x20) {
      bVar3 = true;
    }
    else {
      Data = 0x3000;
      if ((instance->flags2 & 0x8000000U) != 0) {
        Data = 0x2000;
      }
    }
    if (bVar3) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    }
    if (Data == 0) {
      mv->mvFlags = mv->mvFlags | 0x40;
      return;
    }
    *(int *)(iVar9 + 0xc) = Data;
LAB_80083f6c:
    if ((mv->mvFlags & 0x200040) == 0) {
      p_Var11 = (_Instance *)message->Data;
      if (0x2fff < (int)p_Var11->prev) {
        instance->constrictAngle = 0;
      }
      mv->mvFlags = mv->mvFlags | 0x40;
      uVar4 = INSTANCE_Query(*(_Instance **)&p_Var11->node,1);
      Inst = gameTrackerX.playerInstance;
      if (uVar4 != 0x20) {
        Inst = *(_Instance **)&p_Var11->node;
      }
      MONSENSE_SetEnemy(instance,Inst);
      Data = MON_TakeDamage(instance,(int)p_Var11->prev,0x100);
      iVar9 = 8;
      if ((Data != 0) && (iVar9 = 9, (mv->mvFlags & 0x2000) != 0)) {
        iVar9 = 0x10;
      }
      if (iVar9 != -1) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      }
      mv->damageType = 0x100;
      *(_Instance **)&mv->messageData = p_Var11;
    }
    return;
  }
  if (0x1000006 < Data) {
    return;
  }
  if (Data == 0x40017) {
    mv->damageType = *(ushort *)(&LAB_800c5a4c + message->Data * 4);
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    return;
  }
  if (Data < 0x40018) {
    if (Data != 0x4000c) {
      if (Data < 0x4000d) {
        if (Data == 0x40003) {
          CurrentSection = (uint)mv->subAttr->numSections;
          Data = message->Data;
          while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection) {
            G2EmulationInstanceToInstanceSwitchAnimation
                      (instance,*(_Instance **)(Data + 4),CurrentSection,*(int *)(Data + 8),
                       *(int *)(Data + 0xc),*(int *)(Data + 0x10),*(int *)(Data + 0x14));
          }
          return;
        }
        if (Data < 0x40004) {
          return;
        }
        if (Data != 0x40009) {
          return;
        }
        mv->damageType = 0x2000;
LAB_800846f0:
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        return;
      }
      if (Data == 0x4000f) {
        psVar7 = (short *)message->Data;
        mv->mvFlags = mv->mvFlags | 0x80000000;
        (mv->lookAtPosData).x = *psVar7;
        (mv->lookAtPosData).y = psVar7[1];
        (mv->lookAtPosData).z = psVar7[2];
        return;
      }
      if (Data < 0x40010) {
        if (Data != 0x4000d) {
          return;
        }
        Data = message->Data;
        mv->auxFlags = mv->auxFlags | 0x10000000;
        (mv->destination).z = *(short *)(Data + 4);
        return;
      }
      if (Data == 0x40010) {
        CurrentSection = mv->mvFlags;
        uVar8 = 0x7fffffff;
        goto LAB_800847a0;
      }
      if (Data != 0x40016) {
        return;
      }
    }
    psVar7 = (short *)message->Data;
    (mv->destination).x = *psVar7;
    (mv->destination).y = psVar7[1];
    angle = psVar7[2];
    mv->mvFlags = mv->mvFlags | 0x40000;
    (mv->destination).z = angle;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    return;
  }
  if (Data == 0x80005) {
    if (instance->zVel != 0) {
      return;
    }
    if ((mv->mvFlags & 0x200000) != 0) {
      return;
    }
    angle = MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position,&instance->position);
    PhysicsSetVelFromZRot(instance,angle,100);
    instance->zVel = 0x32;
    (instance->position).z = (instance->position).z + 100;
    (instance->oldPos).z = (instance->oldPos).z + 100;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
    return;
  }
  if (Data < 0x80006) {
    if (Data == 0x80002) {
      if (mv->subAttr->waterVuln == '\0') {
        return;
      }
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      mv->damageType = 0x10;
      return;
    }
    if (Data < 0x80003) {
      if (Data != 0x80001) {
        return;
      }
LAB_80084568:
      if (mv->subAttr->sunVuln == '\0') {
        return;
      }
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
      MON_MonsterGlow(instance,0xffffff,0x46,10,0x14);
      mv->damageType = 0x40;
      return;
    }
    if (Data != 0x80003) {
      if (Data != 0x80004) {
        return;
      }
      Data = MON_TakeDamage(instance,0x3000,0x100);
      if ((Data == 0) || ((mv->mvFlags & 0x2000) == 0)) goto LAB_800846f0;
      mv->damageType = 0x100;
      goto LAB_80084660;
    }
    if (mv->subAttr->fireVuln == '\0') goto LAB_80084568;
    MON_SetGlyphHitData(instance,&eStack72,0x20,1);
    mv->damageType = 0x20;
    data = &eStack72;
  }
  else {
    if (Data == 0x400000) {
      pTVar6 = MONTABLE_GetDamageEffectFunc(instance);
      (*pTVar6)(instance,message->Data);
      return;
    }
    if (0x400000 < Data) {
      if (Data != 0x1000000) {
        if (Data != 0x1000002) {
          return;
        }
        if (message->Data == 0) {
          Data_00 = mv->enemy;
          if (Data_00 == (_MonsterIR *)0x0) {
            return;
          }
          Data_00->mirConditions = Data_00->mirConditions | 0x40;
          return;
        }
        MONSENSE_SetEnemy(instance,gameTrackerX.playerInstance);
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
        CurrentSection = mv->mvFlags;
        uVar8 = 0xfffffffd;
LAB_800847a0:
        mv->mvFlags = CurrentSection & uVar8;
        return;
      }
      goto LAB_80083f6c;
    }
    if (Data != 0x80006) {
      return;
    }
    data = &eStack48;
    if (mv->subAttr->soundVuln == '\0') {
      return;
    }
    MON_SetGlyphHitData(instance,data,0x200,1);
    mv->damageType = 0x200;
  }
  MON_DamageEffect(instance,data);
LAB_80084660:
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_54,local_58));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateQueueHandler(struct _Instance *instance /*$s0*/)
 // line 734, offset 0x800848b0
	/* begin block 1 */
		// Start line: 735
		// Start offset: 0x800848B0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x800848E8
	// End Line: 741

	/* begin block 2 */
		// Start line: 1547
	/* end block 2 */
	// End Line: 1548

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
 // line 743, offset 0x800848fc
	/* begin block 1 */
		// Start line: 744
		// Start offset: 0x800848FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x80084934
	// End Line: 750

	/* begin block 2 */
		// Start line: 1565
	/* end block 2 */
	// End Line: 1566

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
 // line 752, offset 0x80084948
	/* begin block 1 */
		// Start line: 753
		// Start offset: 0x80084948
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x80084980
	// End Line: 759

	/* begin block 2 */
		// Start line: 1583
	/* end block 2 */
	// End Line: 1584

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





