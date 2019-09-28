#include "THISDUST.H"
#include "SENSES.H"


// decompiled code
// original method signature: 
// int /*$ra*/ SetEngagedInstance(struct __Player *player /*$t0*/, struct evCollideInstanceStatsData *Ptr /*$a1*/, unsigned long Attribute /*$a2*/)
 // line 4, offset 0x800a3394
	/* begin block 1 */
		// Start line: 5
		// Start offset: 0x800A3394
		// Variables:
	// 		int rc; // $t1
	/* end block 1 */
	// End offset: 0x800A3424
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
 // line 29, offset 0x800a342c
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x800A342C
		// Variables:
	// 		int WhoAmI; // $s5
	// 		int Ability; // $s1
	// 		int hidden; // $s6
	// 		struct PhysObCollectibleProperties *collectibleProp; // $s1

		/* begin block 1.1 */
			// Start line: 44
			// Start offset: 0x800A3494
			// Variables:
		// 		struct evObjectDraftData *draft; // $a2

			/* begin block 1.1.1 */
				// Start line: 50
				// Start offset: 0x800A34FC
				// Variables:
			// 		int force; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800A35A0
			// End Line: 61
		/* end block 1.1 */
		// End offset: 0x800A35A0
		// End Line: 63

		/* begin block 1.2 */
			// Start line: 93
			// Start offset: 0x800A3678
			// Variables:
		// 		struct SVECTOR startVec; // stack offset -64
		// 		struct SVECTOR endVec; // stack offset -56
		/* end block 1.2 */
		// End offset: 0x800A3754
		// End Line: 116

		/* begin block 1.3 */
			// Start line: 120
			// Start offset: 0x800A3760
			// Variables:
		// 		struct PhysObSwitchProperties *prop; // $a1

			/* begin block 1.3.1 */
				// Start line: 123
				// Start offset: 0x800A37B4
			/* end block 1.3.1 */
			// End offset: 0x800A3824
			// End Line: 141
		/* end block 1.3 */
		// End offset: 0x800A3824
		// End Line: 142

		/* begin block 1.4 */
			// Start line: 144
			// Start offset: 0x800A3830
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $s1
		// 		int testConditions; // $s2

			/* begin block 1.4.1 */
				// Start line: 166
				// Start offset: 0x800A3870
				// Variables:
			// 		struct _Instance *heldInst; // $s0
			/* end block 1.4.1 */
			// End offset: 0x800A390C
			// End Line: 192
		/* end block 1.4 */
		// End offset: 0x800A3A10
		// End Line: 230

		/* begin block 1.5 */
			// Start line: 235
			// Start offset: 0x800A3A30
			// Variables:
		// 		struct MATRIX *collectMat; // $v1
		// 		struct _Position headPos; // stack offset -64
		// 		struct _Position collectPos; // stack offset -56
		// 		long headDistance; // $s0
		// 		long rootDistance; // $a1

			/* begin block 1.5.1 */
				// Start line: 288
				// Start offset: 0x800A3C40
				// Variables:
			// 		unsigned long ability_bit; // $v1
			/* end block 1.5.1 */
			// End offset: 0x800A3CA0
			// End Line: 300
		/* end block 1.5 */
		// End offset: 0x800A3D54
		// End Line: 328

		/* begin block 1.6 */
			// Start line: 490
			// Start offset: 0x800A419C
			// Variables:
		// 		struct _Instance *Inst; // $a0
		/* end block 1.6 */
		// End offset: 0x800A41D4
		// End Line: 496

		/* begin block 1.7 */
			// Start line: 503
			// Start offset: 0x800A420C
			// Variables:
		// 		struct VECTOR in; // stack offset -64
		// 		struct VECTOR out; // stack offset -48

			/* begin block 1.7.1 */
				// Start line: 512
				// Start offset: 0x800A4284
				// Variables:
			// 		int rc; // $v0
			/* end block 1.7.1 */
			// End offset: 0x800A4408
			// End Line: 544
		/* end block 1.7 */
		// End offset: 0x800A4408
		// End Line: 545
	/* end block 1 */
	// End offset: 0x800A4560
	// End Line: 593

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
 // line 598, offset 0x800a4588
	/* begin block 1 */
		// Start line: 599
		// Start offset: 0x800A4588
		// Variables:
	// 		long rc; // $v0
	/* end block 1 */
	// End offset: 0x800A4588
	// End Line: 599

	/* begin block 2 */
		// Start line: 1243
	/* end block 2 */
	// End Line: 1244

uint UpdateAutoFaceAngle(int param_1,int param_2)

{
  short sVar1;
  
  sVar1 = MATH3D_FastAtan2((int)*(short *)(param_1 + 0x5e) - (int)*(short *)(param_2 + 0x5e),
                           (int)*(short *)(param_1 + 0x5c) - (int)*(short *)(param_2 + 0x5c));
  return (int)sVar1 + 0xc00U & 0xfff;
}





