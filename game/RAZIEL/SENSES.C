#include "THISDUST.H"
#include "SENSES.H"


// decompiled code
// original method signature: 
// int /*$ra*/ SetEngagedInstance(struct __Player *player /*$t0*/, struct evCollideInstanceStatsData *Ptr /*$a1*/, unsigned long Attribute /*$a2*/)
 // line 4, offset 0x800a2638
	/* begin block 1 */
		// Start line: 5
		// Start offset: 0x800A2638
		// Variables:
	// 		int rc; // $t1
	/* end block 1 */
	// End offset: 0x800A26C8
	// End Line: 23

	/* begin block 2 */
		// Start line: 8
	/* end block 2 */
	// End Line: 9

int SetEngagedInstance(__Player *player,evCollideInstanceStatsData *Ptr,ulong Attribute)

{
  uint uVar1;
  __EngagedInstance *p_Var2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (player->Senses).EngagedMask;
  uVar1 = 1 << (Attribute & 0x1f);
  iVar4 = 0;
  if ((uVar3 & uVar1) == 0) {
    iVar4 = 1;
    (player->Senses).EngagedMask = uVar3 | uVar1;
    (player->Senses).EngagedList[Attribute].instance = Ptr->instance;
    (player->Senses).EngagedList[Attribute].distance = Ptr->distance;
  }
  else {
    p_Var2 = (player->Senses).EngagedList + Attribute;
    if (Ptr->distance < p_Var2->distance) {
      iVar4 = 1;
      p_Var2->instance = Ptr->instance;
      (player->Senses).EngagedList[Attribute].distance = Ptr->distance;
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ UpdateEngagementList(struct evCollideInstanceStatsData *Ptr /*$s3*/, struct __Player *player /*$s4*/)
 // line 29, offset 0x800a26d0
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x800A26D0
		// Variables:
	// 		int WhoAmI; // $s5
	// 		int Ability; // $s1
	// 		int hidden; // $s6
	// 		struct PhysObCollectibleProperties *collectibleProp; // $s1

		/* begin block 1.1 */
			// Start line: 44
			// Start offset: 0x800A2738
			// Variables:
		// 		struct evObjectDraftData *draft; // $a2

			/* begin block 1.1.1 */
				// Start line: 50
				// Start offset: 0x800A27A0
				// Variables:
			// 		int force; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800A2844
			// End Line: 61
		/* end block 1.1 */
		// End offset: 0x800A2844
		// End Line: 63

		/* begin block 1.2 */
			// Start line: 93
			// Start offset: 0x800A291C
			// Variables:
		// 		struct SVECTOR startVec; // stack offset -64
		// 		struct SVECTOR endVec; // stack offset -56
		/* end block 1.2 */
		// End offset: 0x800A29F8
		// End Line: 116

		/* begin block 1.3 */
			// Start line: 120
			// Start offset: 0x800A2A04
			// Variables:
		// 		struct PhysObSwitchProperties *prop; // $a1

			/* begin block 1.3.1 */
				// Start line: 123
				// Start offset: 0x800A2A58
			/* end block 1.3.1 */
			// End offset: 0x800A2AC8
			// End Line: 141
		/* end block 1.3 */
		// End offset: 0x800A2AC8
		// End Line: 142

		/* begin block 1.4 */
			// Start line: 144
			// Start offset: 0x800A2AD4
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $s1
		// 		int testConditions; // $s2

			/* begin block 1.4.1 */
				// Start line: 154
				// Start offset: 0x800A2B14
				// Variables:
			// 		struct _Instance *heldInst; // $s0
			/* end block 1.4.1 */
			// End offset: 0x800A2B98
			// End Line: 177
		/* end block 1.4 */
		// End offset: 0x800A2C9C
		// End Line: 211

		/* begin block 1.5 */
			// Start line: 216
			// Start offset: 0x800A2CBC
			// Variables:
		// 		struct MATRIX *collectMat; // $v1
		// 		struct _Position headPos; // stack offset -64
		// 		struct _Position collectPos; // stack offset -56
		// 		long headDistance; // $s0
		// 		long rootDistance; // $a1
		/* end block 1.5 */
		// End offset: 0x800A2F50
		// End Line: 292

		/* begin block 1.6 */
			// Start line: 444
			// Start offset: 0x800A3330
			// Variables:
		// 		struct _Instance *Inst; // $a0
		/* end block 1.6 */
		// End offset: 0x800A3368
		// End Line: 450

		/* begin block 1.7 */
			// Start line: 457
			// Start offset: 0x800A33A0
			// Variables:
		// 		struct VECTOR in; // stack offset -64
		// 		struct VECTOR out; // stack offset -48

			/* begin block 1.7.1 */
				// Start line: 466
				// Start offset: 0x800A3418
				// Variables:
			// 		int rc; // $v0
			/* end block 1.7.1 */
			// End offset: 0x800A3590
			// End Line: 497
		/* end block 1.7 */
		// End offset: 0x800A3590
		// End Line: 498
	/* end block 1 */
	// End offset: 0x800A36C8
	// End Line: 545

	/* begin block 2 */
		// Start line: 64
	/* end block 2 */
	// End Line: 65

void UpdateEngagementList(evCollideInstanceStatsData *Ptr,__Player *player)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(Ptr->instance,1);
}



// decompiled code
// original method signature: 
// long /*$ra*/ UpdateAutoFaceAngle(struct _Instance *player /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 550, offset 0x800a36f0
	/* begin block 1 */
		// Start line: 551
		// Start offset: 0x800A36F0
		// Variables:
	// 		long rc; // $v0
	/* end block 1 */
	// End offset: 0x800A36F0
	// End Line: 551

	/* begin block 2 */
		// Start line: 1140
	/* end block 2 */
	// End Line: 1141

long UpdateAutoFaceAngle(_Instance *player,_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_FastAtan2((int)(player->position).y - (int)(instance->position).y,
                   (int)(player->position).x - (int)(instance->position).x);
}





