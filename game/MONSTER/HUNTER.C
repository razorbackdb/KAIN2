#include "THISDUST.H"
#include "HUNTER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_InitFlamethrow(struct _Instance *instance /*$a0*/)
 // line 98, offset 0x8007cf6c
	/* begin block 1 */
		// Start line: 100
		// Start offset: 0x8007CF6C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $v0
	/* end block 1 */
	// End offset: 0x8007CFA4
	// End Line: 109

	/* begin block 2 */
		// Start line: 196
	/* end block 2 */
	// End Line: 197

	/* begin block 3 */
		// Start line: 197
	/* end block 3 */
	// End Line: 198

void HUNTER_InitFlamethrow(_Instance *instance)

{
  undefined2 *puVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  puVar1 = *(undefined2 **)((int)pvVar2 + 0x16c);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[1] = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffb;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HUNTER_Flamethrow(struct _Instance *instance /*$s5*/, int damage /*$s4*/, int newPoint /*$s7*/, int segment /*$s6*/)
 // line 146, offset 0x8007cfac
	/* begin block 1 */
		// Start line: 147
		// Start offset: 0x8007CFAC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _HunterVars *hv; // $s3
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct _MonsterIR *enemy; // $s2
	// 		struct MATRIX *matrix; // $a1
	// 		int tick; // $v1
	// 		int time; // $a1
	// 		int dist; // $s1
	// 		int angle; // $s0
	// 		struct _Instance *weapon; // $s0
	// 		struct _Position mypos; // stack offset -72
	// 		struct _Position targpos; // stack offset -64
	// 		struct _Rotation rot; // stack offset -56
	// 		struct _Position zero; // stack offset -48

		/* begin block 1.1 */
			// Start line: 220
			// Start offset: 0x8007D170
		/* end block 1.1 */
		// End offset: 0x8007D29C
		// End Line: 254

		/* begin block 1.2 */
			// Start line: 288
			// Start offset: 0x8007D29C
			// Variables:
		// 		int i; // $s4
		// 		int size; // $v1
		// 		int angle; // $s6
		// 		int flamedist; // $s0

			/* begin block 1.2.1 */
				// Start line: 303
				// Start offset: 0x8007D304
				// Variables:
			// 		int flamesize; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8007D324
			// End Line: 305
		/* end block 1.2 */
		// End offset: 0x8007D360
		// End Line: 312
	/* end block 1 */
	// End offset: 0x8007D36C
	// End Line: 317

	/* begin block 2 */
		// Start line: 292
	/* end block 2 */
	// End Line: 293

int HUNTER_Flamethrow(_Instance *instance,int damage,int newPoint,int segment)

{
  undefined auStack48 [8];
  
                    /* WARNING: Subroutine does not return */
  memset(auStack48,0,6);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_Init(struct _Instance *instance /*$s1*/)
 // line 323, offset 0x8007d398
	/* begin block 1 */
		// Start line: 324
		// Start offset: 0x8007D398
		// Variables:
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _HunterVars *hv; // $v0
	// 		struct _Instance *weapon; // $v0
	/* end block 1 */
	// End offset: 0x8007D448
	// End Line: 371

	/* begin block 2 */
		// Start line: 828
	/* end block 2 */
	// End Line: 829

void HUNTER_Init(_Instance *instance)

{
  byte bVar1;
  undefined2 uVar2;
  _Instance *p_Var3;
  int weaponid;
  void *pvVar4;
  
  pvVar4 = instance->extraData;
  weaponid = 0xe;
  if (*(char *)((int)pvVar4 + 0x15a) == '\0') {
    bVar1 = *(byte *)((int)instance->data + 0x23);
    weaponid = 0xd;
  }
  else {
    bVar1 = *(byte *)((int)instance->data + 0x23);
  }
  p_Var3 = HUMAN_CreateWeapon(instance,weaponid,(uint)bVar1);
  if (p_Var3 != (_Instance *)0x0) {
    HUMAN_Init(instance);
    *(undefined4 *)((int)pvVar4 + 0x16c) = 0;
    if (*(char *)((int)pvVar4 + 0x15a) == '\0') {
      uVar2 = 0x5000;
    }
    else {
      if (pvVar4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        MEMPACK_Malloc(0x2c,'$');
      }
      uVar2 = 0x6000;
    }
    *(undefined2 *)((int)pvVar4 + 0x144) = uVar2;
    G2Anim_DisableSegment(&instance->anim,0x1f);
    G2Anim_DisableSegment(&instance->anim,0x17);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_CleanUp(struct _Instance *instance /*$s0*/)
 // line 373, offset 0x8007d45c
	/* begin block 1 */
		// Start line: 374
		// Start offset: 0x8007D45C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $a0
	/* end block 1 */
	// End offset: 0x8007D494
	// End Line: 386

	/* begin block 2 */
		// Start line: 933
	/* end block 2 */
	// End Line: 934

void HUNTER_CleanUp(_Instance *instance)

{
  char *address;
  
  if ((instance->extraData != (void *)0x0) &&
     (address = *(char **)((int)instance->extraData + 0x16c), address != (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free(address);
  }
  HUMAN_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_ProjectileEntry(struct _Instance *instance /*$a0*/)
 // line 389, offset 0x8007d4ac
	/* begin block 1 */
		// Start line: 390
		// Start offset: 0x8007D4AC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D4EC
	// End Line: 401

	/* begin block 2 */
		// Start line: 965
	/* end block 2 */
	// End Line: 966

void HUNTER_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_ProjectileEntry(instance);
  if (*(char *)((int)pvVar1 + 0x15a) != '\0') {
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffffc;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_Projectile(struct _Instance *instance /*$s2*/)
 // line 403, offset 0x8007d4fc
	/* begin block 1 */
		// Start line: 404
		// Start offset: 0x8007D4FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $a0
	// 		struct _MonsterMissile *missileDef; // $s1
	// 		struct _HunterVars *hv; // $s3
	// 		struct _HunterAttributes *ha; // $s4
	// 		int dist; // $s1
	// 		int playMode; // $a3
	/* end block 1 */
	// End offset: 0x8007D78C
	// End Line: 496

	/* begin block 2 */
		// Start line: 993
	/* end block 2 */
	// End Line: 994

void HUNTER_Projectile(_Instance *instance)

{
  char cVar1;
  uint animtype;
  int mode;
  undefined4 local_18;
  void *pvVar2;
  undefined4 local_14;
  int iVar3;
  
  pvVar2 = instance->extraData;
  iVar3 = *(int *)((int)instance->data + 0x3c) +
          (int)*(char *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 0x1a) * 0x10;
  if (*(char *)((int)pvVar2 + 0x15a) == '\0') {
    MON_Projectile(instance);
  }
  else {
    if ((*(int *)((int)pvVar2 + 0x16c) == 0) || (*(int *)((int)instance->data + 4) == 0)) {
      return;
    }
    if ((*(uint *)((int)pvVar2 + 4) & 1) == 0) {
      if (*(int *)((int)pvVar2 + 0xc4) != 0) {
        if ((instance->flags2 & 0x10U) == 0) {
          mode = MON_AnimPlayingFromList(instance,(char *)(iVar3 + 0xe),(uint)*(byte *)(iVar3 + 5));
          if ((mode != 0) &&
             (iVar3 = G2EmulationInstanceQueryPassedFrame(instance,0,(uint)*(byte *)(iVar3 + 4)),
             iVar3 != 0)) {
            *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 1;
            HUNTER_InitFlamethrow(instance);
                    /* WARNING: Subroutine does not return */
            MON_GetTime(instance);
          }
          goto LAB_8007d784;
        }
        cVar1 = *(char *)((int)pvVar2 + 0x15b) + '\x01';
        *(char *)((int)pvVar2 + 0x15b) = cVar1;
        animtype = SEXT14(cVar1);
        if ((int)animtype < (int)(uint)*(byte *)(iVar3 + 0xd)) {
          mode = 1;
          if (animtype == (uint)*(byte *)(iVar3 + 5)) {
            mode = 2;
          }
                    /* WARNING: Subroutine does not return */
          MON_PlayAnimFromList(instance,(char *)(iVar3 + 0xe),animtype,mode);
        }
      }
LAB_8007d6dc:
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
    if ((*(uint *)((int)pvVar2 + 4) & 2) == 0) {
      HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar3 + 7),1,(uint)*(byte *)(iVar3 + 6));
      *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 2;
      if (*(int *)((int)pvVar2 + 0xc4) != 0) {
        iVar3 = *(int *)(*(int *)((int)pvVar2 + 0xc4) + 4);
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXY((int)*(short *)(iVar3 + 0x5c) - (int)(instance->position).x,
                        (int)*(short *)(iVar3 + 0x5e) - (int)(instance->position).y);
      }
    }
    else {
      if (*(int *)((int)pvVar2 + 0xc4) != 0) {
                    /* WARNING: Subroutine does not return */
        MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c)
                           ,*(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c));
      }
      mode = HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar3 + 7),0,(uint)*(byte *)(iVar3 + 6));
      if (mode != 0) {
        cVar1 = *(char *)((int)pvVar2 + 0x15b) + '\x01';
        *(char *)((int)pvVar2 + 0x15b) = cVar1;
        if ((int)cVar1 < (int)(uint)*(byte *)(iVar3 + 0xd)) {
                    /* WARNING: Subroutine does not return */
          MON_PlayAnimFromList(instance,(char *)(iVar3 + 0xe),(int)cVar1,1);
        }
        goto LAB_8007d6dc;
      }
    }
  }
LAB_8007d784:
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}





