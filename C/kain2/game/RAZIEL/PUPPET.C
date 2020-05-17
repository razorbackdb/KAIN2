#include "THISDUST.H"
#include "PUPPET.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPuppetShow(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 8, offset 0x8009a90c
	/* begin block 1 */
		// Start line: 9
		// Start offset: 0x8009A90C
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 38
			// Start offset: 0x8009AAD0
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009AAD0
		// End Line: 40

		/* begin block 1.2 */
			// Start line: 53
			// Start offset: 0x8009AB40
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009AB40
		// End Line: 55

		/* begin block 1.3 */
			// Start line: 67
			// Start offset: 0x8009ABBC
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x8009ABBC
		// End Line: 67

		/* begin block 1.4 */
			// Start line: 78
			// Start offset: 0x8009AC00
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.4.1 */
				// Start line: 78
				// Start offset: 0x8009AC00
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.1 */
			// End offset: 0x8009AC00
			// End Line: 78
		/* end block 1.4 */
		// End offset: 0x8009AC00
		// End Line: 78
	/* end block 1 */
	// End offset: 0x8009AC7C
	// End Line: 98

	/* begin block 2 */
		// Start line: 16
	/* end block 2 */
	// End Line: 17

/* WARNING: Type propagation algorithm not settling */

void StateHandlerPuppetShow(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  short *psVar3;
  undefined *puVar4;
  int iVar5;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      razApplyMotion(In,CurrentSection);
      return;
    }
    puVar4 = (undefined *)p_Var1->ID;
    if (puVar4 == &DAT_00040016) {
      G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
LAB_8009ab94:
      StateSwitchStateData(In,CurrentSection,StateHandlerMoveToPosition,p_Var1->Data);
    }
    else {
      if ((int)puVar4 < 0x40017) {
        if (puVar4 == &DAT_0004000d) {
          if (CurrentSection == 0) {
            Raziel.puppetRotToPoint.z = *(short *)(p_Var1->Data + 4);
            SteerSwitchMode(In->CharacterInstance,0xd);
          }
        }
        else {
          if ((int)puVar4 < 0x4000e) {
            if (puVar4 != &DAT_00040003) {
              if (puVar4 == &DAT_0004000c) goto LAB_8009ab94;
              goto LAB_8009ac64;
            }
            if (CurrentSection == 0) {
              p_Var2 = (_Instance *)p_Var1->Data;
              G2EmulationInstanceToInstanceSwitchAnimationCharacter
                        (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                         (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,
                         (int)p_Var2->flags);
            }
          }
          else {
            if (puVar4 == &DAT_00040010) {
              Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
              ControlFlag = ControlFlag & 0xfffdffff;
            }
            else {
              if (puVar4 != &DAT_00040014) goto LAB_8009ac64;
              G2EmulationSwitchAnimation(In,CurrentSection,0,0,3,2);
            }
          }
        }
      }
      else {
        if (puVar4 == &DAT_00100001) {
          if (p_Var1->Data != 0) {
            G2EmulationSwitchAnimation(In,CurrentSection,0,0,3,2);
          }
          Raziel.Mode = 1;
          Raziel.idleCount = 0;
          ControlFlag = 0x1020008;
          PhysicsMode = 0;
          SteerSwitchMode(In->CharacterInstance,0);
          ResetPhysics(In->CharacterInstance,-0x10);
          Raziel.movementMinRate = 0;
          if (CurrentSection == 0) {
            Raziel.constrictGoodCircle = 0;
          }
        }
        else {
          if ((int)puVar4 < 0x100002) {
            if (puVar4 == &DAT_00040018) {
              if (CurrentSection == 0) {
                psVar3 = (short *)p_Var1->Data;
                Raziel.puppetRotToPoint.x = *psVar3;
                Raziel.puppetRotToPoint.y = psVar3[1];
                Raziel.puppetRotToPoint.z = psVar3[2];
                SteerSwitchMode(In->CharacterInstance,0xc);
              }
            }
            else {
              if (puVar4 != &DAT_00040021) goto LAB_8009ac64;
              Raziel.steeringVelocity = *(short *)&p_Var1->Data;
            }
          }
          else {
            if (puVar4 != (undefined *)0x4000001) {
              if ((int)puVar4 < 0x4000002) {
                if (puVar4 != (undefined *)0x1000001) {
LAB_8009ac64:
                  DefaultPuppetStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x8000008) goto LAB_8009ac64;
                if (CurrentSection == 0) {
                  iVar5 = p_Var1->Data;
                  G2EmulationSwitchAnimationCharacter
                            (In,*(int *)(iVar5 + 4),*(int *)(iVar5 + 8),*(int *)(iVar5 + 0xc),
                             *(int *)(iVar5 + 0x10));
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
// void /*$ra*/ StateHandlerMoveToPosition(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 102, offset 0x8009aca8
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x8009ACA8
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		long distance; // $s0
	// 		int motion; // $v0
	// 		int applyMotion; // $s5

		/* begin block 1.1 */
			// Start line: 113
			// Start offset: 0x8009ADB4
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.1.1 */
				// Start line: 115
				// Start offset: 0x8009ADB4
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v0; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8009ADB4
			// End Line: 115
		/* end block 1.1 */
		// End offset: 0x8009ADB4
		// End Line: 115

		/* begin block 1.2 */
			// Start line: 134
			// Start offset: 0x8009AE50
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.2.1 */
				// Start line: 136
				// Start offset: 0x8009AE50
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009AE50
			// End Line: 136
		/* end block 1.2 */
		// End offset: 0x8009AE74
		// End Line: 140
	/* end block 1 */
	// End offset: 0x8009AF28
	// End Line: 174

	/* begin block 2 */
		// Start line: 217
	/* end block 2 */
	// End Line: 218

void StateHandlerMoveToPosition(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  short *psVar3;
  int Data_00;
  _Instance *p_Var4;
  long lVar5;
  undefined *puVar6;
  
  bVar1 = true;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if (bVar1) {
        if (CurrentSection == 0) {
          razAlignYRotInterp(In->CharacterInstance,&Raziel.puppetMoveToPoint,'\0',4);
        }
        p_Var4 = In->CharacterInstance;
        lVar5 = MATH3D_LengthXYZ((int)(p_Var4->position).x - (int)Raziel.puppetMoveToPoint.x,
                                 (int)(p_Var4->position).y - (int)Raziel.puppetMoveToPoint.y,
                                 (int)(p_Var4->position).z - (int)Raziel.puppetMoveToPoint.z);
        Data_00 = razApplyMotion(In,CurrentSection);
        if ((CurrentSection == 0) && (lVar5 < Data_00 << 1)) {
          INSTANCE_Post(In->CharacterInstance,0x100000,0);
        }
      }
      return;
    }
    puVar6 = (undefined *)p_Var2->ID;
    if (puVar6 == &DAT_00100001) {
      if (CurrentSection == 0) {
        psVar3 = (short *)p_Var2->Data;
        Raziel.puppetMoveToPoint.x = *psVar3;
        Raziel.puppetMoveToPoint.y = psVar3[1];
        Raziel.puppetMoveToPoint.z = psVar3[2];
        razAlignYRotInterp(In->CharacterInstance,&Raziel.puppetMoveToPoint,'\0',4);
        PhysicsMode = 0;
        SteerSwitchMode(In->CharacterInstance,0);
      }
    }
    else {
      if ((int)puVar6 < 0x100002) {
        if (puVar6 == &DAT_00040016) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
LAB_8009ae50:
          psVar3 = (short *)p_Var2->Data;
          Raziel.puppetMoveToPoint.x = *psVar3;
          Raziel.puppetMoveToPoint.y = psVar3[1];
          Raziel.puppetMoveToPoint.z = psVar3[2];
        }
        else {
          if ((int)puVar6 < 0x40017) {
            if (puVar6 == &DAT_0004000c) goto LAB_8009ae50;
          }
          else {
            if (puVar6 == (undefined *)0x100000) {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerPuppetShow,Data_00);
              bVar1 = false;
              goto LAB_8009ae98;
            }
          }
LAB_8009ae90:
          DefaultPuppetStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar6 == (undefined *)0x4000001) {
          PhysicsMode = 0;
          SetDropPhysics(In->CharacterInstance,&Raziel);
        }
        else {
          if ((int)puVar6 < 0x4000002) {
            if (puVar6 != (undefined *)0x1000000) goto LAB_8009ae90;
          }
          else {
            if ((puVar6 != (undefined *)0x4010400) && (puVar6 != (undefined *)0x4020000))
            goto LAB_8009ae90;
          }
        }
      }
    }
LAB_8009ae98:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultPuppetStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s2*/)
 // line 174, offset 0x8009af50
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8009AF50
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 194
			// Start offset: 0x8009B118
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009B118
		// End Line: 194

		/* begin block 1.2 */
			// Start line: 201
			// Start offset: 0x8009B12C
			// Variables:
		// 		struct evPositionData *data; // $v1

			/* begin block 1.2.1 */
				// Start line: 203
				// Start offset: 0x8009B12C
				// Variables:
			// 		long _x1; // $a0
			// 		long _y1; // $a2
			// 		long _z1; // $a1
			// 		struct _Vector *_v0; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009B12C
			// End Line: 203
		/* end block 1.2 */
		// End offset: 0x8009B16C
		// End Line: 208
	/* end block 1 */
	// End offset: 0x8009B1EC
	// End Line: 240

	/* begin block 2 */
		// Start line: 383
	/* end block 2 */
	// End Line: 384

void DefaultPuppetStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  short *psVar3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 != (__Event *)0x0) {
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00040020) {
      if (CurrentSection == 0) {
        G2Anim_SetSpeedAdjustment(&(gameTrackerX.playerInstance)->anim,p_Var1->Data);
      }
    }
    else {
      if ((int)puVar2 < 0x40021) {
        if (puVar2 == &DAT_80000020) {
          return;
        }
        if ((int)puVar2 < -0x7fffffdf) {
          if (puVar2 == &DAT_80000008) {
            return;
          }
          if ((int)puVar2 < -0x7ffffff7) {
            if (puVar2 == (undefined *)0x80000000) {
              return;
            }
          }
          else {
            if (puVar2 == &DAT_80000010) {
              return;
            }
          }
        }
        else {
          if (puVar2 == &DAT_0004000b) {
            if (CurrentSection != 0) {
              return;
            }
            ((gameTrackerX.playerInstance)->rotation).z = *(short *)(p_Var1->Data + 4);
            return;
          }
          if ((int)puVar2 < 0x4000c) {
            if (puVar2 == &DAT_0004000a) {
              STREAM_SetInstancePosition(gameTrackerX.playerInstance,(evPositionData *)p_Var1->Data)
              ;
              return;
            }
          }
          else {
            if (puVar2 == &DAT_0004000f) {
              psVar3 = (short *)p_Var1->Data;
              Raziel.Senses.Flags = Raziel.Senses.Flags | 0x10;
              Raziel.Senses.lookAtPoint.x = (int)*psVar3;
              Raziel.Senses.lookAtPoint.y = (int)psVar3[1];
              Raziel.Senses.lookAtPoint.z = (int)psVar3[2];
              ControlFlag = ControlFlag | 0x20000;
              return;
            }
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x1000001) {
          return;
        }
        if ((int)puVar2 < 0x1000002) {
          if (puVar2 == &DAT_00100009) {
            return;
          }
          if ((int)puVar2 < 0x10000a) {
            if (puVar2 == &DAT_00100004) {
              razResetMotion(gameTrackerX.playerInstance);
              return;
            }
          }
          else {
            if (puVar2 == (undefined *)0x800027) {
              if (Data != 0) {
                ControlFlag = ControlFlag | 8;
                return;
              }
              ControlFlag = ControlFlag & 0xfffffff7;
              return;
            }
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000000) {
            return;
          }
          if ((int)puVar2 < 0x8000001) {
            if (puVar2 == (undefined *)0x4010200) {
              return;
            }
          }
          else {
            if (puVar2 == (undefined *)0x10002001) {
              razSpectralShift();
              return;
            }
            if (puVar2 == (undefined *)0x10002002) {
              razMaterialShift();
              return;
            }
          }
        }
      }
      DefaultStateHandler(In,CurrentSection,Data);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWarpGate(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 243, offset 0x8009b204
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8009B204
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int anim; // $s3

		/* begin block 1.1 */
			// Start line: 286
			// Start offset: 0x8009B508
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009B55C
		// End Line: 293

		/* begin block 1.2 */
			// Start line: 299
			// Start offset: 0x8009B590
		/* end block 1.2 */
		// End offset: 0x8009B590
		// End Line: 299
	/* end block 1 */
	// End offset: 0x8009B66C
	// End Line: 341

	/* begin block 2 */
		// Start line: 527
	/* end block 2 */
	// End Line: 528

void StateHandlerWarpGate(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  __Event *p_Var4;
  int Ptr;
  undefined *puVar5;
  _Instance *Inst;
  __State *p_Var6;
  
  iVar3 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var6 = In->SectionList + CurrentSection;
  do {
    p_Var4 = PeekMessageQueue(&p_Var6->Event);
    if (p_Var4 == (__Event *)0x0) {
      if (CurrentSection == 0) {
        razApplyMotion(In,0);
      }
      return;
    }
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 != &DAT_00100004) {
      if ((int)puVar5 < 0x100005) {
        if (puVar5 != &DAT_80000020) {
          if ((int)puVar5 < -0x7fffffdf) {
            if (puVar5 != &DAT_80000008) {
              if ((int)puVar5 < -0x7ffffff7) {
                if (puVar5 == (undefined *)0x80000000) goto LAB_8009b45c;
              }
              else {
                if (puVar5 == &DAT_80000010) goto LAB_8009b64c;
              }
LAB_8009b644:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar5 == (undefined *)0x100000) {
              Ptr = WARPGATE_IsWarpgateActive();
              if (Ptr == 0) {
                Ptr = SetControlInitIdleData(0,0,3);
                StateSwitchStateCharacterData(In,StateHandlerIdle,Ptr);
              }
              else {
                EnMessageQueueData(&p_Var6->Defer,0x100000,0);
              }
            }
            else {
              if ((int)puVar5 < 0x100001) {
                puVar2 = &DAT_00040005;
joined_r0x8009b338:
                if (puVar5 != puVar2) goto LAB_8009b644;
              }
              else {
                if (puVar5 != &DAT_00100001) goto LAB_8009b644;
                Ptr = SetControlInitIdleData(0,0,3);
                StateInitIdle(In,CurrentSection,Ptr);
                ControlFlag = 0x20008;
                Raziel.Mode = -0x80000000;
                PhysicsMode = 3;
                Raziel.idleCount = 0;
                if (CurrentSection == 0) {
                  Raziel.puppetRotToPoint.z =
                       ((Raziel.Senses.EngagedList[0xe].instance)->rotation).z;
                  SteerSwitchMode(In->CharacterInstance,0xd);
                  Inst = In->CharacterInstance;
                  sVar1 = ((Raziel.Senses.EngagedList[0xe].instance)->position).z;
                  *(undefined4 *)&Inst->position =
                       *(undefined4 *)&(Raziel.Senses.EngagedList[0xe].instance)->position;
                  (Inst->position).z = sVar1;
                  razSetPlayerEventHistory(0x800);
                  WARPGATE_StartUsingWarpgate();
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x2000000) {
LAB_8009b45c:
          if (iVar3 != 0x7b) {
            EnMessageQueueData(&p_Var6->Defer,0x100000,0);
            WARPGATE_EndUsingWarpgate();
          }
        }
        else {
          if ((int)puVar5 < 0x2000001) {
            if (puVar5 == &DAT_00100015) {
              if (CurrentSection == 0) {
                EnMessageQueueData(&In->SectionList[0].Defer,0x100000,0);
                WARPGATE_EndUsingWarpgate();
              }
              Ptr = SetControlInitIdleData(0,0,3);
              StateInitIdle(In,CurrentSection,Ptr);
            }
            else {
              if ((int)puVar5 < 0x100016) {
                puVar2 = &DAT_00100014;
                goto joined_r0x8009b338;
              }
              if (puVar5 != (undefined *)0x1000001) goto LAB_8009b644;
            }
          }
          else {
            if (puVar5 == (undefined *)0x10000000) {
              if ((CurrentSection == 0) && (iVar3 != 0x7b)) {
                if ((*PadData & 4U) != 0) {
                  WARPGATE_IncrementIndex();
                }
                if ((*PadData & 8U) != 0) {
                  WARPGATE_DecrementIndex();
                }
                if ((*PadData & 1U) != 0) {
                  Ptr = WARPGATE_IsWarpgateUsable();
                  if (Ptr == 0) {
                    if (((Raziel.playerEventHistory & 0x20000) == 0) &&
                       (Ptr = WARPGATE_IsWarpgateReady(), Ptr != 0)) {
                      LOAD_PlayXA(0xef);
                      razSetPlayerEventHistory(0x20000);
                    }
                  }
                  else {
                    SetTimer(0x4b);
                    Inst = razGetHeldItem();
                    if (Inst != (_Instance *)0x0) {
                      INSTANCE_Post(Inst,0x800008,0);
                    }
                    G2EmulationSwitchAnimationCharacter(In,0x7b,0,6,2);
                    Ptr = WARPGATE_IsWarpgateSpectral();
                    if (Ptr != 0) {
                      razSpectralShift();
                    }
                  }
                }
              }
            }
            else {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000000) goto LAB_8009b644;
              }
              else {
                if ((0x10002002 < (int)puVar5) || ((int)puVar5 < 0x10002001)) goto LAB_8009b644;
              }
            }
          }
        }
      }
    }
LAB_8009b64c:
    DeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerForcedGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 345, offset 0x8009b68c
	/* begin block 1 */
		// Start line: 346
		// Start offset: 0x8009B68C
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s6
	// 		int extraProcess; // $s4

		/* begin block 1.1 */
			// Start line: 422
			// Start offset: 0x8009BA1C
		/* end block 1.1 */
		// End offset: 0x8009BA50
		// End Line: 428
	/* end block 1 */
	// End offset: 0x8009BA50
	// End Line: 432

	/* begin block 2 */
		// Start line: 731
	/* end block 2 */
	// End Line: 732

void StateHandlerForcedGlide(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int iVar2;
  __Event *p_Var3;
  int iVar4;
  Level *pLVar5;
  undefined *puVar6;
  
  bVar1 = false;
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  do {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0) {
      if ((!bVar1) && (CurrentSection == 0)) {
        pLVar5 = STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
        if ((pLVar5->unitFlags & 0x1000U) == 0) {
          EnMessageQueueData(&In->SectionList[0].Event,0x100000,0);
        }
      }
      return;
    }
    puVar6 = (undefined *)p_Var3->ID;
    if (puVar6 != (undefined *)0x1000001) {
      if ((int)puVar6 < 0x1000002) {
        if (puVar6 != &DAT_80000020) {
          if ((int)puVar6 < -0x7fffffdf) {
            if (puVar6 != &DAT_80000004) {
              if ((int)puVar6 < -0x7ffffffb) {
                if (puVar6 != (undefined *)0x80000000) {
LAB_8009b9f4:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar6 != &DAT_80000008) goto LAB_8009b9f4;
              }
            }
          }
          else {
            if (puVar6 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x2000;
                ControlFlag = 0;
                PhysicsMode = 0;
                SteerSwitchMode(In->CharacterInstance,0);
                DeInitAlgorithmicWings(In->CharacterInstance);
                SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
                gameTrackerX.wipeType = 0xb;
                gameTrackerX.wipeTime = -10;
                gameTrackerX.maxWipeTime = 10;
                if (0xffffffe8 < Raziel.forcedGlideSpeed) {
                  Raziel.forcedGlideSpeed = 0xffffffe8;
                }
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var3->Data,5,1);
            }
            else {
              if ((int)puVar6 < 0x100002) {
                if (puVar6 != (undefined *)0x100000) goto LAB_8009b9f4;
                SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                iVar4 = razSwitchVAnimCharacterGroup
                                  (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (iVar4 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
                }
                bVar1 = true;
                StateSwitchStateCharacterData(In,StateHandlerFall,0);
              }
              else {
                if (puVar6 != &DAT_00100004) goto LAB_8009b9f4;
                if (CurrentSection == 0) {
                  InitAlgorithmicWings(In->CharacterInstance);
                  gameTrackerX.wipeType = 0xb;
                  gameTrackerX.wipeTime = 10;
                  gameTrackerX.maxWipeTime = 10;
                  Raziel.forcedGlideSpeed = 0xffffffe8;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar6 != (undefined *)0x4020000) {
          if ((int)puVar6 < 0x4020001) {
            if (puVar6 != (undefined *)0x4000007) {
              if ((int)puVar6 < 0x4000008) {
                if (puVar6 != (undefined *)0x4000001) goto LAB_8009b9f4;
              }
              else {
                if (puVar6 != (undefined *)0x4010008) goto LAB_8009b9f4;
                StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
              }
            }
          }
          else {
            if (puVar6 != (undefined *)0x10000000) {
              if ((int)puVar6 < 0x10000001) {
                if (puVar6 != (undefined *)0x8000000) goto LAB_8009b9f4;
                if (iVar2 == 0x10) {
                  G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x11,0,5,1,4);
                  SetExternalTransitionForce
                            (&ExternalForces,In->CharacterInstance,4,0,0,Raziel.forcedGlideSpeed);
                }
              }
              else {
                if ((puVar6 != (undefined *)0x20000001) && (puVar6 != (undefined *)0x20000004))
                goto LAB_8009b9f4;
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}





