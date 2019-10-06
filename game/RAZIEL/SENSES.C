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

/* WARNING: Could not reconcile some variable overlaps */

void UpdateEngagementList(evCollideInstanceStatsData *Ptr,__Player *player)

{
  short sVar1;
  ulong uVar2;
  ulong Attribute;
  short *Data;
  ulong uVar3;
  MATRIX *pMVar4;
  _Instance *Inst;
  uint uVar5;
  int Data_00;
  uint in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  uint uVar6;
  uint Data_01;
  int iVar7;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  short local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  
  uVar2 = INSTANCE_Query(Ptr->instance,1);
  Inst = Ptr->instance;
  Data_01 = Inst->flags & 0x800;
  if ((uVar2 & 0x20) == 0) {
    if (((uVar2 & 0x10000a) == 0) || ((Inst->flags2 & 0x20000000U) != 0)) {
      if (((uVar2 & 0x20000) != 0) && (Raziel.soulReaver == (_Instance *)0x0)) {
        if (((Ptr->instance->LinkParent != (player->State).CharacterInstance) &&
            (Ptr->xyDistance < 0x200)) && (Ptr->zDelta + 99U < 0x2e3)) {
          SetEngagedInstance(player,Ptr,0xb);
        }
        if ((Raziel.Abilities & 8U) != 0) {
          razReaverPickup((player->State).CharacterInstance,Ptr->instance);
        }
      }
      goto LAB_800a32a0;
    }
    Attribute = INSTANCE_Query(Inst,0);
    if ((Attribute & 0x44000000) != 0) goto LAB_800a32a0;
    Inst = Ptr->instance;
    if ((((Inst->flags2 & 0x20U) != 0) && (Ptr->xyDistance < 0x780)) &&
       (Ptr->zDelta + 0x1ffU < 0x3ff)) {
      if ((ControlFlag & 4U) == 0) {
        if ((Inst != Raziel.Senses.LastAutoFace) ||
           (Raziel.Senses.CurrentAutoFace == (_Instance *)0x0)) goto LAB_800a30a0;
      }
      else {
        if (Raziel.Senses.CurrentAutoFace == (_Instance *)0x0) {
LAB_800a30a0:
          Data_00 = SetEngagedInstance(player,Ptr,6);
          if (Data_00 != 0) {
LAB_800a30b4:
            AutoFaceAngle = UpdateAutoFaceAngle((player->State).CharacterInstance,Ptr->instance);
          }
        }
        else {
          if (Inst == Raziel.Senses.CurrentAutoFace) {
            Data_00 = SetEngagedInstance(player,Ptr,6);
            if (Data_00 != 0) goto LAB_800a30b4;
            Raziel.Senses.CurrentAutoFace = (_Instance *)0x0;
          }
        }
      }
    }
    if ((0x3c0 < Ptr->distance) &&
       (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x2aa,0x2aa), Data_00 != 0)) {
      SetEngagedInstance(player,Ptr,7);
    }
    if (((Ptr->xyDistance < 0x280) && (Ptr->zDelta + 0xffU < 0x1ff)) &&
       (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x555,0x38e), Data_00 != 0)) {
      SetEngagedInstance(player,Ptr,8);
    }
    if (((Ptr->xyDistance < 0x3c0) && (Ptr->zDelta + 0xffU < 0x1ff)) &&
       (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x555,0x38e), Data_00 != 0)) {
      SetEngagedInstance(player,Ptr,9);
    }
    if ((Ptr->distance < 0xc80) &&
       (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x3c7,0x3c7), Data_00 != 0)) {
      SetEngagedInstance(player,Ptr,10);
    }
    if ((Ptr->distance < 0x1e00) && (Attribute = INSTANCE_Query(Ptr->instance,0x25), Attribute != 0)
       ) {
      Raziel.Senses.Flags = Raziel.Senses.Flags | 0x20;
    }
    goto LAB_800a32a0;
  }
  Attribute = INSTANCE_Query(Inst,2);
  if (((Attribute & 0x100) != 0) && ((Ptr->instance->flags & 0x800U) == 0)) {
    Data = (short *)INSTANCE_Query(Ptr->instance,0x16);
    if ((Ptr->xyDistance < (int)(uint)(ushort)Data[1]) && (Data_00 = Ptr->zDelta, Data_00 < 0)) {
      if ((int)-(uint)(ushort)Data[3] < Data_00) {
        in_t2 = 0x1000;
        iVar7 = (0x1000 - (Ptr->xyDistance << 0xc) / (int)(uint)(ushort)Data[1]) * (int)*Data;
        if (iVar7 < 0) {
          iVar7 = iVar7 + 0xfff;
        }
        in_t1 = (uint)(ushort)Data[2];
        iVar7 = (iVar7 >> 0xc) * in_t1;
        if (iVar7 < 0) {
          iVar7 = iVar7 + 0xfff;
        }
        Data_00 = (0x1000 - (Data_00 * -0x1000) / (int)(uint)(ushort)Data[3]) * (int)*Data;
        if (Data_00 < 0) {
          Data_00 = Data_00 + 0xfff;
        }
        Data_00 = (Data_00 >> 0xc) * (0x1000 - in_t1);
        if (Data_00 < 0) {
          Data_00 = Data_00 + 0xfff;
        }
        *Data = (short)(iVar7 >> 0xc) + (short)(Data_00 >> 0xc);
        INSTANCE_Post((player->State).CharacterInstance,0x4000007,(int)Data);
      }
    }
  }
  if ((Attribute & 1) != 0) {
    if (player->Mode == 0x40000) {
      Ptr->xyDistance = Ptr->xyDistance / 2;
      Ptr->zDelta = Ptr->zDelta / 2;
    }
    Inst = Ptr->instance->LinkParent;
    if ((((Inst == (_Instance *)0x0) || (uVar3 = INSTANCE_Query(Inst,0), (uVar3 & 0x40000000) != 0))
        && (Ptr->xyDistance < 0x200)) && (Ptr->zDelta + 0xffU < 0x37f)) {
      SetEngagedInstance(player,Ptr,5);
    }
  }
  if ((((Attribute & 0xe) != 0) && (Data_01 == 0)) &&
     (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x3c7,0x3c7), Data_00 != 0)) {
    PHYSICS_GenericLineCheckSetup(0,0,0,(SVECTOR *)&local_40);
    PHYSICS_GenericLineCheckSetup(0,-0x140,0,(SVECTOR *)&local_38);
    Data_00 = PHYSICS_CheckForTerrainCollide
                        (gameTrackerX.playerInstance,(SVECTOR *)&local_40,(SVECTOR *)&local_38,1);
    if (Data_00 == 0) {
      if ((Ptr->xyDistance < 0x280) && (Ptr->zDelta + 0xfU < 0x1f)) {
        if ((Attribute & 4) != 0) {
          SetEngagedInstance(player,Ptr,1);
        }
        if ((Attribute & 2) != 0) {
          SetEngagedInstance(player,Ptr,2);
        }
      }
      if (((Ptr->xyDistance < 0x20d) && (Ptr->zDelta + 0xffU < 0x1ff)) && ((Attribute & 8) != 0)) {
        SetEngagedInstance(player,Ptr,0);
      }
    }
  }
  if ((((Attribute & 0x40) != 0) &&
      (uVar3 = INSTANCE_Query(Ptr->instance,0x17),
      Ptr->xyDistance < (int)(uint)*(ushort *)(uVar3 + 0x1a))) &&
     (((int)*(char *)(uVar3 + 0x1c) < Ptr->zDelta && (Ptr->zDelta < (int)*(char *)(uVar3 + 0x1d)))))
  {
    Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,
                                (int)((uint)*(byte *)(uVar3 + 0x1e) * 0x1000) / 0x168,
                                (int)((uint)*(byte *)(uVar3 + 0x1f) * 0x1000) / 0x168);
    if (Data_00 != 0) {
      SetEngagedInstance(player,Ptr,3);
    }
    INSTANCE_Query(Ptr->instance,5);
  }
  if ((Attribute & 0x80) != 0) {
    Attribute = INSTANCE_Query(Ptr->instance,0x15);
    uVar6 = 0;
    if (((*(ushort *)(Attribute + 8) & 1) == 0) && ((*(ushort *)(Attribute + 10) & 1) == 0)) {
      Inst = razGetHeldItem();
      if (Inst == (_Instance *)0x0) {
        uVar6 = 0x800;
        if (Raziel.soulReaver != (_Instance *)0x0) {
          uVar6 = (uint)Raziel.Abilities >> 9 & 0x1fe & (uint)*(ushort *)(Attribute + 8) | 0x800;
        }
        if (Raziel.currentSoulReaver == 6) {
          uVar6 = uVar6 | 0x200;
        }
      }
      else {
        uVar3 = INSTANCE_Query(Inst,2);
        if ((uVar3 & 0x20) != 0) {
          uVar3 = INSTANCE_Query(Inst,3);
          uVar6 = 0x400;
          if ((uVar3 & 0x10000) != 0) {
            uVar6 = 0x200;
          }
        }
      }
    }
    else {
      uVar6 = 0xffff;
    }
    if (((((uVar6 & *(ushort *)(Attribute + 8)) != 0) ||
         ((uVar6 & *(ushort *)(Attribute + 10)) != 0)) && (*(short *)(Attribute + 0x1c) != 2)) &&
       (((Ptr->xyDistance < (int)(uint)*(ushort *)(Attribute + 0x1e) &&
         ((int)*(short *)(Attribute + 0x20) < Ptr->zDelta)) &&
        ((Ptr->zDelta < (int)*(short *)(Attribute + 0x22) &&
         (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,
                                      (int)((uint)*(byte *)(Attribute + 0x24) * 0x1000) / 0x168,
                                      (int)((uint)*(byte *)(Attribute + 0x25) * 0x1000) / 0x168),
         Data_00 != 0)))))) {
      if ((uVar6 & *(ushort *)(Attribute + 8)) == 0) {
        Attribute = 0xd;
      }
      else {
        Attribute = 4;
      }
      SetEngagedInstance(player,Ptr,Attribute);
    }
  }
  Attribute = INSTANCE_Query(Ptr->instance,0x1d);
  if ((Attribute != 0) && (Data_01 == 0)) {
    uVar3 = INSTANCE_Query(Ptr->instance,0xe);
    if (uVar3 != 0) {
      local_38 = CONCAT22(*(undefined2 *)(uVar3 + 0x18),*(undefined2 *)(uVar3 + 0x14));
      local_34 = *(short *)(uVar3 + 0x1c);
    }
    local_40 = CONCAT22(*(undefined2 *)((gameTrackerX.playerInstance)->matrix[0x12].t + 1),
                        *(undefined2 *)(gameTrackerX.playerInstance)->matrix[0x12].t);
    local_3c._0_2_ = *(short *)((gameTrackerX.playerInstance)->matrix[0x12].t + 2);
    Data_01 = MATH3D_DistanceBetweenPositions((_Position *)&local_40,(_Position *)&local_38);
    local_40 = CONCAT22(*(undefined2 *)((gameTrackerX.playerInstance)->matrix[1].t + 1),
                        *(undefined2 *)(gameTrackerX.playerInstance)->matrix[1].t);
    local_3c = CONCAT22(local_3c._2_2_,
                        *(undefined2 *)((gameTrackerX.playerInstance)->matrix[1].t + 2));
    uVar6 = MATH3D_DistanceBetweenPositions((_Position *)&local_40,(_Position *)&local_38);
    uVar5 = *(uint *)(Attribute + 0xc);
    if (((Ptr->distance < uVar5) || (Data_01 < uVar5)) || (uVar6 < uVar5)) {
      switch((int)(((uint)*(ushort *)(Attribute + 8) - 1) * 0x10000) >> 0x10) {
      case 0:
        Raziel.HealthBalls = Raziel.HealthBalls + 1;
        in_t3 = (undefined4)((ulonglong)((longlong)(int)Raziel.HealthBalls * 0x66666667) >> 0x20);
        if ((int)Raziel.HealthScale < (((int)Raziel.HealthBalls / 5) * 0x10000 >> 0x10) + 1) {
          BumpUpHealth();
        }
        Inst = Ptr->instance;
        Data_01 = SEXT24(Raziel.HealthBalls);
LAB_800a2e9c:
        INSTANCE_Post(Inst,0x800026,Data_01);
        break;
      case 1:
        if (Raziel.GlyphManaBalls < Raziel.GlyphManaMax) {
          Raziel.GlyphManaBalls = Raziel.GlyphManaBalls + *(short *)(Attribute + 10);
          if (Raziel.GlyphManaMax < Raziel.GlyphManaBalls) {
            Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
          }
          Inst = Ptr->instance;
          Data_01 = (uint)Raziel.GlyphManaBalls;
          goto LAB_800a2e9c;
        }
        break;
      case 2:
        INSTANCE_Post(Ptr->instance,0x800026,0);
        debugRazielFlags1 = Raziel.Abilities | (int)*(short *)(Attribute + 10) << 0x11;
        Raziel.Abilities = debugRazielFlags1;
        break;
      case 4:
        Raziel.GlyphManaBalls = Raziel.GlyphManaMax + *(short *)(Attribute + 10);
        Raziel.GlyphManaMax = Raziel.GlyphManaBalls;
        INSTANCE_Post(Ptr->instance,0x800026,0);
        break;
      case 5:
        INSTANCE_Post(Ptr->instance,0x800026,(uint)Raziel.GlyphManaBalls);
        RAZIEL_DebugHealthFillUp();
        break;
      case 6:
        INSTANCE_Post(Ptr->instance,0x800026,(uint)Raziel.GlyphManaBalls);
        SetMana(1);
      }
    }
  }
  if ((((Ptr->instance->object->oflags2 & 0x400000U) != 0) && (Ptr->distance < 0xc80)) &&
     (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x3c7,0x3c7), Data_00 != 0)) {
    SetEngagedInstance(player,Ptr,10);
  }
LAB_800a32a0:
  Attribute = INSTANCE_Query(Ptr->instance,0);
  if ((((Attribute & 0x8000000) != 0) && (Ptr->xyDistance < 0x200)) &&
     ((Ptr->zDelta + 99U < 0x2e3 &&
      (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x2aa,0x2aa), Data_00 != 0)))) {
    SetEngagedInstance(player,Ptr,0xc);
  }
  if (((uVar2 & 4) != 0) &&
     (Raziel.playerEvent = Raziel.playerEvent | 0x1000, (ControlFlag & 0x40U) != 0)) {
    Inst = (player->State).CharacterInstance;
    pMVar4 = Inst->matrix;
    Data_00 = SetMonsterSoulSuckData(Inst,pMVar4[0xf].t[0],pMVar4[0xf].t[1],pMVar4[0xf].t[2]);
    INSTANCE_Post(Ptr->instance,0x1000009,Data_00);
  }
  if ((Ptr->instance->object->oflags2 & 0x4000000U) != 0) {
    if ((Raziel.constrictFlag & 0x20U) != 0) {
      local_40 = (int)(Ptr->instance->position).x - (int)Raziel.constrictCenter.x;
      local_38 = 0;
      local_3c = (int)(Ptr->instance->position).y - (int)Raziel.constrictCenter.y;
      setCopReg(2,in_t1,local_40);
      setCopReg(2,in_t2,local_3c);
      setCopReg(2,in_t3,0);
      copFunction(2,0xa00428);
      local_30 = getCopReg(2,0x19);
      local_2c = getCopReg(2,0x1a);
      local_28 = getCopReg(2,0x1b);
      if (local_30 + local_2c < 0x64000) {
        Data_00 = razConstrictAngle(Ptr->instance);
        if (((Raziel.constrictFlag & 0x10U) == 0) || (Data_00 == 0)) {
          Ptr->instance->constrictAngle = 0;
          FX_EndConstrict(0,(_Instance *)0x0);
        }
        else {
          if (Data_00 < 1) {
            Inst = Ptr->instance;
            if (0 < Inst->constrictAngle) {
              Inst->constrictAngle = 0;
              Inst = Ptr->instance;
            }
            sVar1 = Inst->constrictAngle + -1;
          }
          else {
            Inst = Ptr->instance;
            if (Inst->constrictAngle < 0) {
              Inst->constrictAngle = 0;
              Inst = Ptr->instance;
            }
            sVar1 = Inst->constrictAngle + 1;
          }
          Inst->constrictAngle = sVar1;
          Inst = Ptr->instance;
          if ((Inst->constrictAngle == 1) || (Inst->constrictAngle == -1)) {
            FX_StartConstrict(Raziel.State.CharacterInstance,&Raziel.constrictCenter,1,0x12);
            INSTANCE_Post(Ptr->instance,0x40009,0);
          }
          else {
            if (2 < (ushort)(Inst->constrictAngle + 1U)) {
              FX_EndConstrict(1,Inst);
              Raziel.constrictFlag = 1;
              Data_00 = SetMonsterHitData((player->State).CharacterInstance,Ptr->instance,0x3000,0,0
                                         );
              INSTANCE_Post(Ptr->instance,0x1000000,Data_00);
              razSetupSoundRamp(gameTrackerX.playerInstance,(_SoundRamp *)&Raziel.soundHandle,0x30,
                                100,100,100,100,0,0xdac);
            }
          }
        }
      }
    }
    if (Raziel.constrictGoodCircle == 0) {
      Ptr->instance->constrictAngle = 0;
    }
  }
  if (((((Ptr->instance->object->oflags2 & 0x1000000U) != 0) &&
       (gameTrackerX.gameData.asmData.MorphType != 0)) && (Raziel.CurrentPlane == 2)) &&
     ((Ptr->xyDistance < 0x1c2 && (Ptr->zDelta + 0x3fU < 0x7f)))) {
    Raziel.Senses.Flags = Raziel.Senses.Flags | 0x40;
  }
  if ((((Ptr->instance->object->oflags & 0x100000U) != 0) && (0x3c0 < Ptr->distance)) &&
     (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,0x2aa,0x2aa), Data_00 != 0)) {
    SetEngagedInstance(player,Ptr,7);
  }
  if (((Ptr->instance->object->oflags2 & 0x20U) != 0) && (Ptr->distance < 0x100)) {
    SetEngagedInstance(player,Ptr,0xe);
  }
  return;
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
  short sVar1;
  
  sVar1 = MATH3D_FastAtan2((int)(player->position).y - (int)(instance->position).y,
                           (int)(player->position).x - (int)(instance->position).x);
  return (int)sVar1 + 0xc00U & 0xfff;
}





