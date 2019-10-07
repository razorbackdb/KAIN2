#include "THISDUST.H"
#include "MISSILE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MISSILE_Process(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 53, offset 0x8007d7ac
	/* begin block 1 */
		// Start line: 106
	/* end block 1 */
	// End Line: 107

void MISSILE_Process(_Instance *instance,GameTracker *gameTracker)

{
  u_long uVar1;
  
  PhysicalObjectQuery(instance,gameTracker);
  if ((instance->LinkParent == (_Instance *)0x0) &&
     (uVar1 = MON_GetAnim(instance), (u_int)instance->work2 < uVar1)) {
    INSTANCE_NewInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MISSILE_Collide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 65, offset 0x8007d804
	/* begin block 1 */
		// Start line: 130
	/* end block 1 */
	// End Line: 131

void MISSILE_Collide(_Instance *instance,GameTracker *gameTracker)

{
  InitPhysicalObject(instance,gameTracker);
  if (instance->LinkParent == (_Instance *)0x0) {
    INSTANCE_NewInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ MISSILE_Find(struct _Instance *instance /*$a0*/, struct _MonsterMissile *missiledef /*$a1*/)
 // line 73, offset 0x8007d840
	/* begin block 1 */
		// Start line: 75
		// Start offset: 0x8007D840
		// Variables:
	// 		struct Object *ob; // $v1
	// 		struct _Instance *missile; // $a2
	/* end block 1 */
	// End offset: 0x8007D8AC
	// End Line: 87

	/* begin block 2 */
		// Start line: 146
	/* end block 2 */
	// End Line: 147

	/* begin block 3 */
		// Start line: 147
	/* end block 3 */
	// End Line: 148

	/* begin block 4 */
		// Start line: 154
	/* end block 4 */
	// End Line: 155

_Instance * MISSILE_Find(_Instance *instance,_MonsterMissile *missiledef)

{
  _Instance *p_Var1;
  
  p_Var1 = instance->LinkChild;
  if (p_Var1 != (_Instance *)0x0) {
    do {
      if ((p_Var1->ParentLinkNode == (u_int)missiledef->segment) &&
         (p_Var1->object ==
          (Object *)(&objectAccess)[(&MISSILE_objectTable)[missiledef->graphic].object].object)) {
        return p_Var1;
      }
      p_Var1 = p_Var1->LinkSibling;
    } while (p_Var1 != (_Instance *)0x0);
  }
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ MISSILE_Birth(struct _Instance *instance /*$s1*/, struct _MonsterMissile *missiledef /*$s0*/)
 // line 89, offset 0x8007d8bc
	/* begin block 1 */
		// Start line: 90
		// Start offset: 0x8007D8BC
		// Variables:
	// 		struct _Instance *missile; // $a1

		/* begin block 1.1 */
			// Start line: 122
			// Start offset: 0x8007D944
			// Variables:
		// 		struct MATRIX *matrix; // $v0
		/* end block 1.1 */
		// End offset: 0x8007D978
		// End Line: 126
	/* end block 1 */
	// End offset: 0x8007D97C
	// End Line: 157

	/* begin block 2 */
		// Start line: 181
	/* end block 2 */
	// End Line: 182

_Instance * MISSILE_Process(_Instance *instance,_MonsterMissile *missiledef)

{
  _Instance *p_Var1;
  evObjectBirthProjectileData *peVar2;
  MATRIX *pMVar3;
  
  if ((missiledef->type == '\x03') &&
     (p_Var1 = MISSILE_Find(instance,missiledef), p_Var1 != (_Instance *)0x0)) {
    p_Var1->processFunc = MISSILE_Process;
    p_Var1->collideFunc = MISSILE_Collide;
  }
  else {
    peVar2 = PHYSOB_BirthCollectible(instance,(u_int)missiledef->segment,(u_int)missiledef->graphic);
    p_Var1 = peVar2->birthInstance;
    if (p_Var1 != (_Instance *)0x0) {
      p_Var1->processFunc = MISSILE_Process;
      if (instance->matrix != (MATRIX *)0x0) {
        pMVar3 = instance->matrix + missiledef->segment;
        (p_Var1->position).x = *(short *)pMVar3->t;
        (p_Var1->position).y = *(short *)(pMVar3->t + 1);
        (p_Var1->position).z = *(short *)(pMVar3->t + 2);
      }
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ MISSILE_Fire(struct _Instance *instance /*$a0*/, struct _MonsterMissile *missiledef /*$s1*/, void *target /*$s2*/, int type /*$s3*/)
 // line 159, offset 0x8007d990
	/* begin block 1 */
		// Start line: 160
		// Start offset: 0x8007D990
		// Variables:
	// 		struct _Instance *miss; // $s0

		/* begin block 1.1 */
			// Start line: 167
			// Start offset: 0x8007D9C4
			// Variables:
		// 		int spin; // $a3
		// 		struct _SVector rotVel; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8007DA30
		// End Line: 188
	/* end block 1 */
	// End offset: 0x8007DA30
	// End Line: 190

	/* begin block 2 */
		// Start line: 321
	/* end block 2 */
	// End Line: 322

_Instance * MISSILE_Fire(_Instance *instance,_MonsterMissile *missiledef,void *target,int type)

{
  _Instance *Inst;
  int Data;
  u_long uVar1;
  ushort spinType;
  _SVector local_20;
  
  Inst = MISSILE_Process(instance,missiledef);
  if (Inst != (_Instance *)0x0) {
    spinType = 1;
    if (missiledef->type == '\x03') {
      spinType = 2;
      local_20.x = 0x111;
      local_20.y = 0;
      local_20.z = 0;
    }
    Data = SetObjectData(target,&local_20,(ushort)type,spinType,(u_int)missiledef->speed,0,0,0);
    INSTANCE_Query(Inst,0x800010,Data);
    uVar1 = MON_GetAnim(Inst);
    *(undefined **)&Inst->work2 = &DAT_00001388 + uVar1;
  }
  return Inst;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ MISSILE_FireAtInstance(struct _Instance *instance /*$a0*/, struct _MonsterMissile *missiledef /*$a1*/, struct _Instance *target /*$a2*/)
 // line 198, offset 0x8007da50
	/* begin block 1 */
		// Start line: 402
	/* end block 1 */
	// End Line: 403

_Instance * MISSILE_Birth(_Instance *instance,_MonsterMissile *missiledef,_Instance *target)

{
  _Instance *p_Var1;
  
  p_Var1 = MISSILE_Fire(instance,missiledef,target,1);
  return p_Var1;
}





