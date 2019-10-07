#include "THISDUST.H"
#include "PUPPET.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPuppetShow(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 8, offset 0x8009a0d4
	/* begin block 1 */
		// Start line: 9
		// Start offset: 0x8009A0D4
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 37
			// Start offset: 0x8009A280
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A280
		// End Line: 39

		/* begin block 1.2 */
			// Start line: 51
			// Start offset: 0x8009A2F0
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009A2F0
		// End Line: 53

		/* begin block 1.3 */
			// Start line: 65
			// Start offset: 0x8009A36C
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x8009A36C
		// End Line: 65

		/* begin block 1.4 */
			// Start line: 76
			// Start offset: 0x8009A3B0
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.4.1 */
				// Start line: 76
				// Start offset: 0x8009A3B0
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.1 */
			// End offset: 0x8009A3B0
			// End Line: 76
		/* end block 1.4 */
		// End offset: 0x8009A3B0
		// End Line: 76
	/* end block 1 */
	// End offset: 0x8009A430
	// End Line: 96

	/* begin block 2 */
		// Start line: 16
	/* end block 2 */
	// End Line: 17

/* WARNING: Type propagation algorithm not settling */

void StateHandlerGlide(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  int Ptr;
  short *psVar3;
  undefined *puVar4;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      razApplyMotion(In,CurrentSection);
      return;
    }
    puVar4 = (undefined *)p_Var1->ID;
    if (puVar4 == (undefined *)0x40016) {
      G2EmulatePlayAnimation(In,CurrentSection,0x7b,0,4,2);
LAB_8009a344:
      StateSwitchStateData(In,CurrentSection,StateHandlerMoveToPosition,p_Var1->Data);
    }
    else {
      if ((int)puVar4 < 0x40017) {
        if (puVar4 == (undefined *)0x4000d) {
          if (CurrentSection == 0) {
            Raziel.puppetRotToPoint.z = *(short *)(p_Var1->Data + 4);
            SteerSwitchMode(In->CharacterInstance,0xd);
          }
        }
        else {
          if ((int)puVar4 < 0x4000e) {
            if (puVar4 != (undefined *)0x40003) {
              if (puVar4 == (undefined *)0x4000c) goto LAB_8009a344;
              goto LAB_8009a418;
            }
            if (CurrentSection == 0) {
              p_Var2 = (_Instance *)p_Var1->Data;
              G2EmulationInstancePlayAnimation
                        (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                         (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,
                         (int)p_Var2->flags);
            }
          }
          else {
            if (puVar4 == (undefined *)0x40010) {
              Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
              ControlFlag = ControlFlag & 0xfffdffff;
            }
            else {
              if (puVar4 != (undefined *)0x40014) goto LAB_8009a418;
              Ptr = SetControlInitIdleData(0,0,3);
              StateInitIdle(In,CurrentSection,Ptr);
            }
          }
        }
      }
      else {
        if (puVar4 == &DAT_00100001) {
          if (p_Var1->Data != 0) {
            StateInitIdle(In,CurrentSection,p_Var1->Data);
          }
          Raziel.Mode = 1;
          Raziel.idleCount = 0;
          ControlFlag = 0x1020008;
          PhysicsMode = 0;
          SteerSwitchMode(In->CharacterInstance,0);
          PhysicsMove(In->CharacterInstance,-0x10);
          Raziel.movementMinRate = 0;
          if (CurrentSection == 0) {
            Raziel.constrictGoodCircle = 0;
          }
        }
        else {
          if ((int)puVar4 < 0x100002) {
            if (puVar4 == (undefined *)0x40018) {
              if (CurrentSection == 0) {
                psVar3 = (short *)p_Var1->Data;
                Raziel.puppetRotToPoint.x = *psVar3;
                Raziel.puppetRotToPoint.y = psVar3[1];
                Raziel.puppetRotToPoint.z = psVar3[2];
                SteerSwitchMode(In->CharacterInstance,0xc);
              }
            }
            else {
              if (puVar4 != (undefined *)0x40021) goto LAB_8009a418;
              Raziel.steeringVelocity = *(short *)&p_Var1->Data;
            }
          }
          else {
            if (puVar4 != (undefined *)0x4000001) {
              if ((int)puVar4 < 0x4000002) {
                if (puVar4 != (undefined *)0x1000001) {
LAB_8009a418:
                  StateHandlerStartMove(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x8000008) goto LAB_8009a418;
                if (CurrentSection == 0) {
                  Ptr = p_Var1->Data;
                  G2EmulationSwitchAnimationSync
                            (In,*(int *)(Ptr + 4),*(int *)(Ptr + 8),*(int *)(Ptr + 0xc),
                             *(int *)(Ptr + 0x10));
                }
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerMoveToPosition(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 100, offset 0x8009a45c
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8009A45C
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		long distance; // $s0
	// 		int motion; // $v0
	// 		int applyMotion; // $s5

		/* begin block 1.1 */
			// Start line: 111
			// Start offset: 0x8009A56C
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.1.1 */
				// Start line: 113
				// Start offset: 0x8009A56C
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v0; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8009A56C
			// End Line: 113
		/* end block 1.1 */
		// End offset: 0x8009A56C
		// End Line: 113

		/* begin block 1.2 */
			// Start line: 132
			// Start offset: 0x8009A608
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.2.1 */
				// Start line: 134
				// Start offset: 0x8009A608
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009A608
			// End Line: 134
		/* end block 1.2 */
		// End offset: 0x8009A62C
		// End Line: 138
	/* end block 1 */
	// End offset: 0x8009A6E8
	// End Line: 172

	/* begin block 2 */
		// Start line: 213
	/* end block 2 */
	// End Line: 214

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
        lVar5 = MATH3D_LengthXY((int)(p_Var4->position).x - (int)Raziel.puppetMoveToPoint.x,
                                (int)(p_Var4->position).y - (int)Raziel.puppetMoveToPoint.y,
                                (int)(p_Var4->position).z - (int)Raziel.puppetMoveToPoint.z);
        Data_00 = razApplyMotion(In,CurrentSection);
        if ((CurrentSection == 0) && (lVar5 < Data_00 << 1)) {
          INSTANCE_Query(In->CharacterInstance,0x100000,0);
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
        if (puVar6 == (undefined *)0x40016) {
          G2EmulatePlayAnimation(In,CurrentSection,0x7b,0,4,2);
LAB_8009a608:
          psVar3 = (short *)p_Var2->Data;
          Raziel.puppetMoveToPoint.x = *psVar3;
          Raziel.puppetMoveToPoint.y = psVar3[1];
          Raziel.puppetMoveToPoint.z = psVar3[2];
        }
        else {
          if ((int)puVar6 < 0x40017) {
            if (puVar6 == (undefined *)0x4000c) goto LAB_8009a608;
          }
          else {
            if (puVar6 == (undefined *)0x100000) {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerGlide,Data_00);
              bVar1 = false;
              goto LAB_8009a654;
            }
          }
LAB_8009a64c:
          StateHandlerStartMove(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar6 == (undefined *)0x4000001) {
          PhysicsMode = 0;
          SetDropPhysics(In->CharacterInstance,&Raziel);
        }
        else {
          if ((int)puVar6 < 0x4000002) {
            if (puVar6 != (undefined *)0x1000000) goto LAB_8009a64c;
          }
          else {
            if ((puVar6 != (undefined *)0x4010400) && (puVar6 != (undefined *)0x4020000))
            goto LAB_8009a64c;
          }
        }
      }
    }
LAB_8009a654:
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultPuppetStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s2*/)
 // line 172, offset 0x8009a710
	/* begin block 1 */
		// Start line: 173
		// Start offset: 0x8009A710
		// Variables:
	// 		struct __Event *Ptr; // $a2

		/* begin block 1.1 */
			// Start line: 196
			// Start offset: 0x8009A858
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A858
		// End Line: 196

		/* begin block 1.2 */
			// Start line: 203
			// Start offset: 0x8009A86C
			// Variables:
		// 		struct evPositionData *data; // $v1

			/* begin block 1.2.1 */
				// Start line: 205
				// Start offset: 0x8009A86C
				// Variables:
			// 		long _x1; // $a0
			// 		long _y1; // $a2
			// 		long _z1; // $a1
			// 		struct _Vector *_v0; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009A86C
			// End Line: 205
		/* end block 1.2 */
		// End offset: 0x8009A8B0
		// End Line: 210
	/* end block 1 */
	// End offset: 0x8009A914
	// End Line: 230

	/* begin block 2 */
		// Start line: 379
	/* end block 2 */
	// End Line: 380

void StateHandlerStartMove(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  short *psVar3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 != (__Event *)0x0) {
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x40020) {
      if (CurrentSection == 0) {
        G2Anim_SetSpeedAdjustment(&(gameTrackerX.playerInstance)->anim,p_Var1->Data);
      }
    }
    else {
      if ((int)puVar2 < 0x40021) {
        if (puVar2 == (undefined *)0x4000a) {
          STREAM_SetInstancePosition
                    (&gameTrackerX,gameTrackerX.playerInstance,(evPositionData *)p_Var1->Data);
          return;
        }
        if ((int)puVar2 < 0x4000b) {
          if (puVar2 == (undefined *)0x80000000) {
            return;
          }
          if (puVar2 == &DAT_80000008) {
            return;
          }
        }
        else {
          if (puVar2 == (undefined *)0x4000b) {
            if (CurrentSection != 0) {
              return;
            }
            ((gameTrackerX.playerInstance)->rotation).z = *(short *)(p_Var1->Data + 4);
            return;
          }
          if (puVar2 == (undefined *)0x4000f) {
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
      else {
        if (puVar2 == (undefined *)0x1000001) {
          return;
        }
        if ((int)puVar2 < 0x1000002) {
          if (puVar2 == &DAT_00100004) {
            razResetMotion(gameTrackerX.playerInstance);
            return;
          }
          if (puVar2 == (undefined *)0x800027) {
            if (Data != 0) {
              ControlFlag = ControlFlag | 8;
              return;
            }
            ControlFlag = ControlFlag & 0xfffffff7;
            return;
          }
        }
        else {
          if (puVar2 == (undefined *)0x4010200) {
            return;
          }
          if (puVar2 == (undefined *)0x8000000) {
            return;
          }
        }
      }
      StateHandlerDragObject(In,CurrentSection,Data);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWarpGate(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 233, offset 0x8009a92c
	/* begin block 1 */
		// Start line: 234
		// Start offset: 0x8009A92C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int anim; // $s3

		/* begin block 1.1 */
			// Start line: 276
			// Start offset: 0x8009AC30
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009AC84
		// End Line: 283

		/* begin block 1.2 */
			// Start line: 288
			// Start offset: 0x8009ACA8
		/* end block 1.2 */
		// End offset: 0x8009ACA8
		// End Line: 288
	/* end block 1 */
	// End offset: 0x8009AD84
	// End Line: 329

	/* begin block 2 */
		// Start line: 507
	/* end block 2 */
	// End Line: 508

void StateHandlerThrow2(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  int iVar2;
  __Event *p_Var3;
  int Ptr;
  undefined *puVar4;
  _Instance *Inst;
  __State *p_Var5;
  
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  do {
    p_Var3 = PeekMessageQueue(&p_Var5->Event);
    if (p_Var3 == (__Event *)0x0) {
      if (CurrentSection == 0) {
        razApplyMotion(In,0);
      }
      return;
    }
    puVar4 = (undefined *)p_Var3->ID;
    if (puVar4 != &DAT_00100004) {
      if ((int)puVar4 < 0x100005) {
        if (puVar4 != &DAT_80000020) {
          if ((int)puVar4 < -0x7fffffdf) {
            if (puVar4 != &DAT_80000008) {
              if ((int)puVar4 < -0x7ffffff7) {
                if (puVar4 == (undefined *)0x80000000) goto LAB_8009ab84;
              }
              else {
                if (puVar4 == &DAT_80000010) goto LAB_8009ad64;
              }
LAB_8009ad5c:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == (undefined *)0x100000) {
              Ptr = WARPGATE_IsWarpgateActive();
              if (Ptr == 0) {
                Ptr = SetControlInitIdleData(0,0,3);
                StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Ptr);
              }
              else {
                DeMessageQueue(&p_Var5->Defer,0x100000,0);
              }
            }
            else {
              if ((int)puVar4 < 0x100001) {
                if (puVar4 != (undefined *)0x40005) goto LAB_8009ad5c;
              }
              else {
                if (puVar4 != &DAT_00100001) goto LAB_8009ad5c;
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
                  *(u_char *)&Inst->position =
                       *(u_char *)&(Raziel.Senses.EngagedList[0xe].instance)->position;
                  (Inst->position).z = sVar1;
                  razSetPlayerEventHistory(0x800);
                  WARPGATE_EndUsingWarpgate();
                }
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x2000000) {
LAB_8009ab84:
          if (iVar2 != 0x7b) {
            DeMessageQueue(&p_Var5->Defer,0x100000,0);
            WARPGATE_IsWarpgateUsable();
          }
        }
        else {
          if ((int)puVar4 < 0x2000001) {
            if (puVar4 == &DAT_00100015) {
              if (CurrentSection == 0) {
                DeMessageQueue(&In->SectionList[0].Defer,0x100000,0);
                WARPGATE_IsWarpgateUsable();
              }
              Ptr = SetControlInitIdleData(0,0,3);
              StateInitIdle(In,CurrentSection,Ptr);
            }
            else {
              if ((int)puVar4 < 0x100016) {
                if (puVar4 != &DAT_00100014) goto LAB_8009ad5c;
              }
              else {
                if (puVar4 != (undefined *)0x1000001) goto LAB_8009ad5c;
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x10000000) {
              if ((CurrentSection == 0) && (iVar2 != 0x7b)) {
                if ((*PadData & 4U) != 0) {
                  WARPGATE_IncrementIndex();
                }
                if ((*PadData & 8U) != 0) {
                  WARPGATE_DecrementIndex();
                }
                if ((*PadData & 1U) != 0) {
                  Ptr = WARPGATE_IsWarpgateSpectral();
                  if (Ptr == 0) {
                    if ((Raziel.playerEventHistory & 0x20000) == 0) {
                      LOAD_PlayXA(0xef);
                      razSetPlayerEventHistory(0x20000);
                    }
                  }
                  else {
                    CAMERA_SetShake(0x4b);
                    Inst = razGetHeldItem();
                    if (Inst != (_Instance *)0x0) {
                      INSTANCE_Query(Inst,0x800008,0);
                    }
                    G2EmulationSwitchAnimationSync(In,0x7b,0,6,2);
                    Ptr = WARPGATE_StartUsingWarpgate();
                    if (Ptr != 0) {
                      razSpectralShift();
                    }
                  }
                }
              }
            }
            else {
              if ((int)puVar4 < 0x10000001) {
                if (puVar4 != (undefined *)0x8000000) goto LAB_8009ad5c;
              }
              else {
                if ((0x10002002 < (int)puVar4) || ((int)puVar4 < 0x10002001)) goto LAB_8009ad5c;
              }
            }
          }
        }
      }
    }
LAB_8009ad64:
    PurgeMessageQueue(&p_Var5->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerForcedGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 333, offset 0x8009ada4
	/* begin block 1 */
		// Start line: 334
		// Start offset: 0x8009ADA4
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s5

		/* begin block 1.1 */
			// Start line: 342
			// Start offset: 0x8009ADE0
		/* end block 1.1 */
		// End offset: 0x8009AE18
		// End Line: 348
	/* end block 1 */
	// End offset: 0x8009B15C
	// End Line: 415

	/* begin block 2 */
		// Start line: 707
	/* end block 2 */
	// End Line: 708

void StateHandlerGlyphs(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  Level *pLVar2;
  __Event *p_Var3;
  int iVar4;
  undefined *puVar5;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  if ((CurrentSection == 0) &&
     (pLVar2 = STREAM_GetWaterZLevel(In->CharacterInstance->currentStreamUnitID),
     (pLVar2->unitFlags & 0x1000U) == 0)) {
    DeMessageQueue(&In->SectionList[0].Event,0x100000,0);
  }
  do {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0) {
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 != (undefined *)0x1000001) {
      if ((int)puVar5 < 0x1000002) {
        if (puVar5 != &DAT_80000020) {
          if ((int)puVar5 < -0x7fffffdf) {
            if (puVar5 != &DAT_80000004) {
              if ((int)puVar5 < -0x7ffffffb) {
                if (puVar5 != (undefined *)0x80000000) {
LAB_8009b144:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_80000008) goto LAB_8009b144;
              }
            }
          }
          else {
            if (puVar5 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x2000;
                ControlFlag = 0;
                PhysicsMode = 0;
                SteerSwitchMode(In->CharacterInstance,0);
                DeInitAlgorithmicWings(In->CharacterInstance);
                SetExternalForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
                gameTrackerX.wipeType = 0xb;
                gameTrackerX.wipeTime = -10;
                gameTrackerX.maxWipeTime = 10;
                if (0xffffffe8 < Raziel.forcedGlideSpeed) {
                  Raziel.forcedGlideSpeed = 0xffffffe8;
                }
              }
              G2EmulatePlayAnimation(In,CurrentSection,0x10,p_Var3->Data,5,1);
            }
            else {
              if ((int)puVar5 < 0x100002) {
                if (puVar5 != (undefined *)0x100000) goto LAB_8009b144;
                SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
                iVar4 = razSwitchVAnimCharacterSingle
                                  (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (iVar4 != 0) {
                  G2EmulationSwitchAnimationSync(In,0x24,0,4,1);
                }
                StateSwitchStateCharacterDataDefault(In,StateHandlerGrab,0);
              }
              else {
                if (puVar5 != &DAT_00100004) goto LAB_8009b144;
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
        if (puVar5 != (undefined *)0x4020000) {
          if ((int)puVar5 < 0x4020001) {
            if (puVar5 != (undefined *)0x4000007) {
              if ((int)puVar5 < 0x4000008) {
                if (puVar5 != (undefined *)0x4000001) goto LAB_8009b144;
              }
              else {
                if (puVar5 != (undefined *)0x4010008) goto LAB_8009b144;
                StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
              }
            }
          }
          else {
            if (puVar5 != (undefined *)0x10000000) {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000000) goto LAB_8009b144;
                if (iVar1 == 0x10) {
                  SetAnimationInstanceSwitchData(In,CurrentSection,0x11,0,5,1,4);
                  SetExternalForce(&ExternalForces,In->CharacterInstance,4,0,0,
                                   Raziel.forcedGlideSpeed);
                }
              }
              else {
                if ((puVar5 != (undefined *)0x20000001) && (puVar5 != (undefined *)0x20000004))
                goto LAB_8009b144;
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}





