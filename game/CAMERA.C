#include "THISDUST.H"
#include "CAMERA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalculateViewVolumeNormals(struct Camera *camera /*$s0*/)
 // line 229, offset 0x80014720
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x80014720
		// Variables:
	// 		short projDistance; // $v0
	// 		struct _Normal n0; // stack offset -40
	// 		struct _Normal n1; // stack offset -32
	// 		struct _Normal n2; // stack offset -24
	// 		struct _Normal n3; // stack offset -16
	// 		int x1; // $a0
	// 		int x2; // $a2
	// 		int y1; // $v1
	// 		int y2; // $a1
	/* end block 1 */
	// End offset: 0x80014720
	// End Line: 230

	/* begin block 2 */
		// Start line: 458
	/* end block 2 */
	// End Line: 459

void CAMERA_CalculateViewVolumeNormals(Camera *camera)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  sVar3 = ((short)(camera->core).leftX + -0xa0) * 0x10;
  sVar2 = ((short)(camera->core).topY + -0x78) * 0x10;
  sVar4 = ((short)(camera->core).rightX + -0xa0) * 0x10;
  sVar1 = (short)((int)((uint)*(ushort *)&(camera->core).projDistance << 0x10) >> 0xc);
  (camera->core).viewVolumeNormal[0].x = 0;
  (camera->core).viewVolumeNormal[0].y = 0;
  (camera->core).viewVolumeNormal[0].z = 0x1000;
  (camera->core).viewVolumeNormal[1].x =
       (short)((int)sVar2 * (int)sVar1 - (int)sVar1 * (int)sVar2 >> 0xc);
  (camera->core).viewVolumeNormal[1].y =
       -(short)((int)sVar3 * (int)sVar1 - (int)sVar1 * (int)sVar4 >> 0xc);
                    /* WARNING: Subroutine does not return */
  (camera->core).viewVolumeNormal[1].z =
       (short)((int)sVar3 * (int)sVar2 - (int)sVar2 * (int)sVar4 >> 0xc);
  CAMERA_Normalize((_SVector *)((camera->core).viewVolumeNormal + 1));
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcVVClipInfo(struct Camera *camera /*$s0*/)
 // line 262, offset 0x80014a5c
	/* begin block 1 */
		// Start line: 551
	/* end block 1 */
	// End Line: 552

void CAMERA_CalcVVClipInfo(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal,
                (camera->core).vvNormalWorVecMat);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetViewVolume(struct Camera *camera /*$s0*/)
 // line 273, offset 0x80014b7c
	/* begin block 1 */
		// Start line: 575
	/* end block 1 */
	// End Line: 576

void CAMERA_SetViewVolume(Camera *camera)

{
  CAMERA_CalculateViewVolumeNormals(camera);
  CAMERA_CalcVVClipInfo(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetProjDistance(struct Camera *camera /*$s3*/, long distance /*$s0*/)
 // line 279, offset 0x80014ba8
	/* begin block 1 */
		// Start line: 280
		// Start offset: 0x80014BA8
		// Variables:
	// 		struct Level *level; // $s0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x80014C30
	// End Line: 299

	/* begin block 2 */
		// Start line: 587
	/* end block 2 */
	// End Line: 588

void CAMERA_SetProjDistance(Camera *camera,long distance)

{
  Level *level;
  STracker *pSVar1;
  int iVar2;
  
  SetGeomScreen(distance);
  (camera->core).projDistance = distance;
  CAMERA_CalculateViewVolumeNormals(camera);
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  do {
    if (pSVar1->StreamList[0].used == 2) {
      level = pSVar1->StreamList[0].level;
      SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,(camera->core).projDistance);
                    /* WARNING: Subroutine does not return */
      LIGHT_CalcDQPTable(level);
    }
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CreateNewFocuspoint(struct Camera *camera /*$s0*/)
 // line 301, offset 0x80014c50
	/* begin block 1 */
		// Start line: 302
		// Start offset: 0x80014C50
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 302
			// Start offset: 0x80014C50
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v0
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x80014C50
		// End Line: 302

		/* begin block 1.2 */
			// Start line: 302
			// Start offset: 0x80014C50
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		struct _Position *_v; // $a2
		/* end block 1.2 */
		// End offset: 0x80014C50
		// End Line: 302
	/* end block 1 */
	// End offset: 0x80014C50
	// End Line: 302

	/* begin block 2 */
		// Start line: 642
	/* end block 2 */
	// End Line: 643

void CAMERA_CreateNewFocuspoint(Camera *camera)

{
  short distance;
  
  distance = camera->focusDistance;
                    /* WARNING: Subroutine does not return */
  (camera->focusRotation).x = camera->actual_x_rot;
  CAMERA_CalcPosition(&camera->targetPos,(_Position *)camera,&camera->focusRotation,distance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SaveMode(struct Camera *camera /*$a0*/, long mode /*$a1*/)
 // line 314, offset 0x80014cf4
	/* begin block 1 */
		// Start line: 316
		// Start offset: 0x80014CF4
		// Variables:
	// 		long i; // $t4
	/* end block 1 */
	// End offset: 0x80015024
	// End Line: 356

	/* begin block 2 */
		// Start line: 672
	/* end block 2 */
	// End Line: 673

	/* begin block 3 */
		// Start line: 673
	/* end block 3 */
	// End Line: 674

	/* begin block 4 */
		// Start line: 675
	/* end block 4 */
	// End Line: 676

void CAMERA_SaveMode(Camera *camera,long mode)

{
  short sVar1;
  int iVar2;
  _Position *p_Var3;
  undefined4 *puVar4;
  _SavedCinematic *p_Var5;
  Camera *pCVar6;
  int iVar7;
  Camera *pCVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  sVar1 = camera->stack + 1;
  camera->stack = sVar1;
  if (2 < sVar1) {
    camera->stack = 2;
    iVar10 = 0;
    iVar9 = 0x70;
    iVar7 = 4;
    pCVar6 = camera;
    pCVar8 = camera;
    do {
      p_Var5 = pCVar8->savedCinematic;
      iVar2 = (int)&(camera->core).position.x + iVar9;
      puVar4 = (undefined4 *)(iVar2 + 0x2a0);
      pCVar6->savedMode[0] = *(long *)((int)camera->savedMode + iVar7);
      do {
        uVar11 = puVar4[1];
        uVar12 = puVar4[2];
        uVar13 = puVar4[3];
        *(undefined4 *)&p_Var5->position = *puVar4;
        *(undefined4 *)&(p_Var5->position).z = uVar11;
        *(undefined4 *)&(p_Var5->focusPoint).y = uVar12;
        *(undefined4 *)&p_Var5->base = uVar13;
        puVar4 = puVar4 + 4;
        p_Var5 = (_SavedCinematic *)&(p_Var5->base).z;
      } while (puVar4 != (undefined4 *)(iVar2 + 0x310));
      iVar9 = iVar9 + 0x70;
      pCVar8 = (Camera *)&(pCVar8->core).wcTransform2;
      iVar7 = iVar7 + 4;
      iVar10 = iVar10 + 1;
      pCVar6 = (Camera *)&(pCVar6->core).position.z;
    } while (iVar10 < 2);
  }
  camera->savedMode[camera->stack] = mode;
  if (((mode == 2) || (mode == 5)) || (mode == 4)) {
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    sVar1 = (camera->core).position.z;
    *(undefined4 *)(p_Var3 + 0x70) = *(undefined4 *)&(camera->core).position;
    p_Var3[0x70].z = sVar1;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    sVar1 = (camera->focusPoint).z;
    *(undefined4 *)(p_Var3 + 0x71) = *(undefined4 *)&camera->focusPoint;
    p_Var3[0x71].z = sVar1;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    sVar1 = (camera->targetPos).z;
    *(undefined4 *)(p_Var3 + 0x73) = *(undefined4 *)&camera->targetPos;
    p_Var3[0x73].z = sVar1;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    sVar1 = (camera->targetFocusPoint).z;
    *(undefined4 *)(p_Var3 + 0x74) = *(undefined4 *)&camera->targetFocusPoint;
    p_Var3[0x74].z = sVar1;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    uVar11 = *(undefined4 *)&(camera->focusRotation).z;
    *(undefined4 *)&p_Var3[0x77].y = *(undefined4 *)&camera->focusRotation;
    *(undefined4 *)(p_Var3 + 0x78) = uVar11;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    uVar11 = *(undefined4 *)&(camera->targetFocusRotation).z;
    *(undefined4 *)&p_Var3[0x78].z = *(undefined4 *)&camera->targetFocusRotation;
    *(undefined4 *)&p_Var3[0x79].y = uVar11;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    uVar11 = *(undefined4 *)&(camera->focusPointVel).z;
    *(undefined4 *)&p_Var3[0x7a].z = *(undefined4 *)&camera->focusPointVel;
    *(undefined4 *)&p_Var3[0x7b].y = uVar11;
    p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
    uVar11 = *(undefined4 *)&(camera->focusPointAccl).z;
    *(undefined4 *)(p_Var3 + 0x7c) = *(undefined4 *)&camera->focusPointAccl;
    *(undefined4 *)&p_Var3[0x7c].z = uVar11;
    camera->savedCinematic[camera->stack].maxVel = (int)camera->maxVel;
    camera->savedCinematic[camera->stack].focusDistance = camera->focusDistance;
    camera->savedCinematic[camera->stack].targetFocusDistance = camera->targetFocusDistance;
    camera->savedCinematic[camera->stack].posSpline = (camera->data).Cinematic.posSpline;
    camera->savedCinematic[camera->stack].targetSpline = (camera->data).Cinematic.targetSpline;
    camera->savedCinematic[camera->stack].level = gameTrackerX.level;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_RestoreMode(struct Camera *camera /*$s0*/)
 // line 358, offset 0x8001502c
	/* begin block 1 */
		// Start line: 359
		// Start offset: 0x8001502C

		/* begin block 1.1 */
			// Start line: 371
			// Start offset: 0x80015050
			// Variables:
		// 		long mode; // $s1
		/* end block 1.1 */
		// End offset: 0x800154C4
		// End Line: 484
	/* end block 1 */
	// End offset: 0x800154C4
	// End Line: 485

	/* begin block 2 */
		// Start line: 768
	/* end block 2 */
	// End Line: 769

void CAMERA_RestoreMode(Camera *camera)

{
  short sVar1;
  _Position *p_Var2;
  MultiSpline *pMVar3;
  _Instance *Inst;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  
  if (-1 < (int)camera->stack) {
    iVar6 = camera->savedMode[(int)camera->stack];
    if (camera->mode == 5) {
      if (camera->smooth == 0) {
        camera->flags = camera->flags | 0x1000;
      }
      else {
        camera->smooth = 8;
      }
    }
    sVar5 = (short)iVar6;
    switch(iVar6) {
    case 0:
    case 0xc:
    case 0xd:
    case 0x10:
      CAMERA_SetProjDistance(camera,0x140);
      Inst = gameTrackerX.playerInstance;
      if (camera->mode == 5) {
        (camera->focusOffset).x = 0;
        (camera->focusOffset).y = 0;
        (camera->focusOffset).z = 0x160;
        camera->focusInstance = Inst;
        CAMERA_Restore(camera,7);
      }
      if (iVar6 == 0xc) {
        gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffffbf;
      }
      else {
        gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x40;
      }
      cameraMode = iVar6;
      camera->mode = sVar5;
      sVar5 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)&camera_modeToIndex + ((iVar6 << 0x10) >> 0xe)) * 3 +
                        (int)camera->presetIndex);
      (camera->data).Follow.stopTimer = -0x1a5e0000;
      (camera->focusRotVel).z = 0;
      camera->targetFocusDistance = sVar5;
      if (iVar6 == 0x10) {
        camera->flags = camera->flags | 0x2000;
      }
      else {
        camera->flags = camera->flags & 0xffffdfff;
      }
      break;
    default:
      camera->mode = sVar5;
      break;
    case 2:
    case 4:
    case 5:
      CAMERA_SetProjDistance(camera,0x140);
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var2[0x70].z;
      *(undefined4 *)&(camera->core).position = *(undefined4 *)(p_Var2 + 0x70);
      (camera->core).position.z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var2[0x71].z;
      *(undefined4 *)&camera->focusPoint = *(undefined4 *)(p_Var2 + 0x71);
      (camera->focusPoint).z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var2[0x73].z;
      *(undefined4 *)&camera->targetPos = *(undefined4 *)(p_Var2 + 0x73);
      (camera->targetPos).z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var2[0x74].z;
      *(undefined4 *)&camera->targetFocusPoint = *(undefined4 *)(p_Var2 + 0x74);
      (camera->targetFocusPoint).z = sVar1;
      camera->targetFocusDistance = camera->savedCinematic[(int)camera->stack].targetFocusDistance;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar4 = *(undefined4 *)&p_Var2[0x79].y;
      *(undefined4 *)&camera->targetFocusRotation = *(undefined4 *)&p_Var2[0x78].z;
      *(undefined4 *)&(camera->targetFocusRotation).z = uVar4;
      if ((camera->smooth == 0) && (camera->mode != 6)) {
        camera->focusDistance = camera->savedCinematic[(int)camera->stack].focusDistance;
        p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
        uVar4 = *(undefined4 *)(p_Var2 + 0x78);
        *(undefined4 *)&camera->focusRotation = *(undefined4 *)&p_Var2[0x77].y;
        *(undefined4 *)&(camera->focusRotation).z = uVar4;
      }
      else {
        camera->always_rotate_flag = 1;
      }
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar4 = *(undefined4 *)&p_Var2[0x7b].y;
      *(undefined4 *)&camera->focusPointVel = *(undefined4 *)&p_Var2[0x7a].z;
      *(undefined4 *)&(camera->focusPointVel).z = uVar4;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar4 = *(undefined4 *)&p_Var2[0x7c].z;
      *(undefined4 *)&camera->focusPointAccl = *(undefined4 *)(p_Var2 + 0x7c);
      *(undefined4 *)&(camera->focusPointAccl).z = uVar4;
      iVar6 = (int)camera->stack;
      Inst = camera->focusInstance;
      camera->maxVel = *(short *)&camera->savedCinematic[iVar6].maxVel;
      (camera->data).Cinematic.posSpline = camera->savedCinematic[iVar6].posSpline;
      pMVar3 = camera->savedCinematic[iVar6].targetSpline;
      camera->mode = sVar5;
                    /* WARNING: Subroutine does not return */
      (camera->data).Cinematic.targetSpline = pMVar3;
      INSTANCE_Query(Inst,9);
    case 6:
      if (((uint)(ushort)camera->mode - 4 < 2) || (camera->mode == 2)) {
        sVar1 = *(short *)(camera->savedTargetFocusDistance + camera->targetStack);
        camera->focusDistance = sVar1;
        camera->targetFocusDistance = sVar1;
        if (-1 < camera->targetStack) {
          camera->targetStack = camera->targetStack + -1;
        }
        camera->flags = camera->flags | 0x800;
      }
      camera->lookTimer = 4;
      camera->mode = sVar5;
      camera->targetFocusDistance = 2000;
    }
    camera->stack = camera->stack + -1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Save(struct Camera *camera /*$a0*/, long save /*$a1*/)
 // line 488, offset 0x800154d8
	/* begin block 1 */
		// Start line: 489
		// Start offset: 0x800154D8

		/* begin block 1.1 */
			// Start line: 492
			// Start offset: 0x800154E8
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x80015550
		// End Line: 504
	/* end block 1 */
	// End offset: 0x80015598
	// End Line: 519

	/* begin block 2 */
		// Start line: 1058
	/* end block 2 */
	// End Line: 1059

void CAMERA_Save(Camera *camera,long save)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if ((save & 1U) != 0) {
    sVar1 = camera->targetStack + 1;
    camera->targetStack = sVar1;
    if (sVar1 == 3) {
      camera->targetStack = 2;
      iVar3 = 0;
      iVar2 = 0;
      do {
        iVar3 = iVar3 + 1;
        *(long *)((int)camera->savedTargetFocusDistance + iVar2) =
             camera->savedTargetFocusDistance[iVar3];
        iVar2 = iVar3 * 4;
      } while (iVar3 < 2);
    }
    camera->savedTargetFocusDistance[camera->targetStack] = (int)camera->targetFocusDistance;
  }
  if ((save & 2U) != 0) {
    (camera->savedfocusRotation).x = (camera->targetFocusRotation).x;
  }
  if ((save & 4U) != 0) {
    (camera->savedfocusRotation).z = (camera->focusRotation).z;
  }
  if ((save & 0x100U) != 0) {
                    /* WARNING: Subroutine does not return */
    CAMERA_SaveMode(camera,(int)camera->mode);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Restore(struct Camera *camera /*$a0*/, long restore /*$a1*/)
 // line 523, offset 0x800155a8
	/* begin block 1 */
		// Start line: 1131
	/* end block 1 */
	// End Line: 1132

void CAMERA_Restore(Camera *camera,long restore)

{
  short sVar1;
  
  if ((restore & 7U) != 0) {
    if (((restore & 1U) != 0) && (-1 < (int)camera->targetStack)) {
      camera->distanceState = 3;
      camera->signalFocusDistance =
           *(short *)(camera->savedTargetFocusDistance + (int)camera->targetStack);
      if (-1 < camera->targetStack) {
        camera->targetStack = camera->targetStack + -1;
      }
    }
    if ((restore & 2U) != 0) {
      sVar1 = (camera->savedfocusRotation).x;
      camera->tiltState = 3;
      (camera->signalRot).x = sVar1;
    }
    if ((restore & 4U) != 0) {
      sVar1 = (camera->savedfocusRotation).z;
      camera->rotState = 3;
      camera->forced_movement = 0;
      camera->always_rotate_flag = 1;
      (camera->signalRot).z = sVar1;
      camera->teleportZRot = sVar1;
    }
  }
  if ((restore & 0x100U) != 0) {
    CAMERA_RestoreMode(camera);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetNextPointDC(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/)
 // line 563, offset 0x80015664
	/* begin block 1 */
		// Start line: 564
		// Start offset: 0x80015664
		// Variables:
	// 		static struct _SVector point; // offset 0x0
	/* end block 1 */
	// End offset: 0x800156B4
	// End Line: 575

	/* begin block 2 */
		// Start line: 1217
	/* end block 2 */
	// End Line: 1218

_SVector * SplineGetNextPointDC(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetNext(spline,def,gameTrackerX.timeMult);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_42);
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMode(struct Camera *camera /*$s2*/, long mode /*$s3*/)
 // line 577, offset 0x800156c8
	/* begin block 1 */
		// Start line: 578
		// Start offset: 0x800156C8
		// Variables:
	// 		int oldMode; // $s0
	// 		struct SplineDef curPositional; // stack offset -56
	// 		struct _SVector sv; // stack offset -48

		/* begin block 1.1 */
			// Start line: 620
			// Start offset: 0x8001576C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		// 		struct _Rotation *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x8001576C
		// End Line: 620

		/* begin block 1.2 */
			// Start line: 620
			// Start offset: 0x8001576C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x8001576C
		// End Line: 620

		/* begin block 1.3 */
			// Start line: 620
			// Start offset: 0x8001576C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a1
		// 		short _z0; // $v1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		// 		struct _Position *_v0; // $v1
		/* end block 1.3 */
		// End offset: 0x8001576C
		// End Line: 620

		/* begin block 1.4 */
			// Start line: 680
			// Start offset: 0x800158C8
			// Variables:
		// 		struct _SVector *camPos; // stack offset -32
		// 		struct _SVector *targetPos; // $a0

			/* begin block 1.4.1 */
				// Start line: 685
				// Start offset: 0x800158DC
				// Variables:
			// 		struct _Position pos; // stack offset -40
			/* end block 1.4.1 */
			// End offset: 0x800158DC
			// End Line: 687

			/* begin block 1.4.2 */
				// Start line: 701
				// Start offset: 0x8001598C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.2 */
			// End offset: 0x8001598C
			// End Line: 701

			/* begin block 1.4.3 */
				// Start line: 711
				// Start offset: 0x800159E0
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.3 */
			// End offset: 0x800159FC
			// End Line: 711
		/* end block 1.4 */
		// End offset: 0x800159FC
		// End Line: 715
	/* end block 1 */
	// End offset: 0x80015B2C
	// End Line: 766

	/* begin block 2 */
		// Start line: 1250
	/* end block 2 */
	// End Line: 1251

void CAMERA_SetMode(Camera *camera,long mode)

{
  short sVar1;
  short sVar2;
  MultiSpline *pMVar3;
  _SVector *p_Var4;
  uint uVar5;
  MultiSpline *pMVar6;
  undefined4 uVar7;
  _Position _Stack40;
  _SVector *local_20;
  
  sVar1 = camera->mode;
  if (((int)sVar1 != mode) || (1 < mode - 0xcU)) {
    switch(camera->mode) {
    case 2:
    case 4:
CAMERA_SetMode:
                    /* WARNING: Subroutine does not return */
      CAMERA_SaveMode(camera,(int)camera->mode);
    case 5:
      if (mode != 5) {
                    /* WARNING: Subroutine does not return */
        CAMERA_SaveMode(camera,(int)camera->mode);
      }
      break;
    case 6:
      CAMERA_EndLook(camera);
      if (mode != 0xf) goto CAMERA_SetMode;
      break;
    case 0xc:
    case 0xd:
                    /* WARNING: Subroutine does not return */
      CAMERA_SaveMode(camera,(int)camera->mode);
    }
    switch(mode) {
    case 0:
    case 10:
    case 0xb:
      break;
    default:
      camera->mode = (short)mode;
      break;
    case 2:
    case 4:
    case 5:
      CAMERA_SetProjDistance(camera,0x140);
      (camera->data).Cinematic.posSpline = camera->Spline00;
      pMVar3 = camera->Spline01;
      pMVar6 = (camera->data).Cinematic.posSpline;
      (camera->data).Cinematic.cinema_done = 0;
      camera->Spline00 = (MultiSpline *)0x0;
      (camera->data).Cinematic.lastSplinePos.z = 0;
      (camera->data).Cinematic.lastSplinePos.y = 0;
      (camera->data).Cinematic.lastSplinePos.x = 0;
      camera->Spline01 = (MultiSpline *)0x0;
      (camera->data).Cinematic.targetSpline = pMVar3;
      if (pMVar6 != (MultiSpline *)0x0) {
        *(undefined4 *)&pMVar6->curPositional = 0;
      }
      pMVar3 = (camera->data).Cinematic.targetSpline;
      if (pMVar3 != (MultiSpline *)0x0) {
        *(undefined4 *)&pMVar3->curPositional = 0;
      }
      pMVar3 = (camera->data).Cinematic.posSpline;
      camera->mode = (short)mode;
      if (pMVar3 != (MultiSpline *)0x0) {
        if ((mode == 4) || (mode == 2)) {
          splinecam_helprot.x = (camera->focusRotation).x;
          splinecam_helprot.z = (camera->focusRotation).z + 0x800U & 0xfff;
                    /* WARNING: Subroutine does not return */
          CAMERA_CalcPosition(&_Stack40,&camera->targetFocusPoint,&splinecam_helprot,
                              camera->targetFocusDistance);
        }
        local_20 = SplineGetFirstPoint(pMVar3->positional,&pMVar3->curPositional);
        if (local_20 != (_SVector *)0x0) {
          sVar1 = local_20->y;
          sVar2 = local_20->z;
          (camera->targetPos).x = local_20->x;
          (camera->targetPos).y = sVar1;
          (camera->targetPos).z = sVar2;
          if (mode == 5) {
            camera->posState = 3;
          }
          pMVar3 = (camera->data).Cinematic.targetSpline;
          if ((pMVar3 != (MultiSpline *)0x0) &&
             (p_Var4 = SplineGetFirstPoint(pMVar3->positional,&pMVar3->curPositional),
             p_Var4 != (_SVector *)0x0)) {
            sVar1 = p_Var4->y;
            sVar2 = p_Var4->z;
            (camera->targetFocusPoint).x = p_Var4->x;
            (camera->targetFocusPoint).y = sVar1;
            (camera->targetFocusPoint).z = sVar2;
          }
        }
      }
      uVar7 = *(undefined4 *)&(camera->focusRotation).z;
      *(undefined4 *)&camera->targetRotation = *(undefined4 *)&camera->focusRotation;
      *(undefined4 *)&(camera->targetRotation).z = uVar7;
      camera->tiltState = 0;
      camera->lead_angle = 0;
      camera->flags = camera->flags & 0xffffdfff;
      break;
    case 0xc:
    case 0xd:
    case 0x10:
      CAMERA_SetProjDistance(camera,0x140);
      if (mode == 0x10) {
        mode = 0xc;
        uVar5 = camera->flags | 0x2000;
      }
      else {
        uVar5 = camera->flags & 0xffffdfff;
      }
      camera->flags = uVar5;
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffffbf;
      cameraMode = mode;
      camera->mode = (short)mode;
      sVar2 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)&camera_modeToIndex + ((mode << 0x10) >> 0xe)) * 3 +
                        (int)camera->presetIndex);
      camera->smooth = 8;
      (camera->data).Follow.stopTimer = -0x1a5e0000;
      (camera->focusRotVel).z = 0;
      camera->targetFocusDistance = sVar2;
      if (((int)sVar1 == 5) && (camera->focusInstance != (_Instance *)0x0)) {
        CAMERA_SetFocus(camera,&camera->targetFocusPoint);
      }
    }
    camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    uVar7 = *(undefined4 *)&(camera->targetFocusRotation).z;
    *(undefined4 *)&camera->collisionTargetFocusRotation =
         *(undefined4 *)&camera->targetFocusRotation;
    *(undefined4 *)&(camera->collisionTargetFocusRotation).z = uVar7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Initialize(struct Camera *camera /*$s1*/)
 // line 768, offset 0x80015b48
	/* begin block 1 */
		// Start line: 769
		// Start offset: 0x80015B48
		// Variables:
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x80015DE0
	// End Line: 987

	/* begin block 2 */
		// Start line: 1671
	/* end block 2 */
	// End Line: 1672

void CAMERA_Initialize(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  memset(camera,0,0x4c4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetInstanceFocus(struct Camera *camera /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1010, offset 0x80015e50
	/* begin block 1 */
		// Start line: 2454
	/* end block 1 */
	// End Line: 2455

	/* begin block 2 */
		// Start line: 2458
	/* end block 2 */
	// End Line: 2459

void CAMERA_SetInstanceFocus(Camera *camera,_Instance *instance)

{
  short sVar1;
  
  camera->focusInstance = instance;
  camera->flags = camera->flags | 0x800;
  sVar1 = (instance->position).z;
  *(undefined4 *)&camera->newFocusInstancePos = *(undefined4 *)&instance->position;
  (camera->newFocusInstancePos).z = sVar1;
  if (instance->object != (Object *)0x0) {
    sVar1 = 0x200;
    if (instance == gameTrackerX.playerInstance) {
      sVar1 = 0x160;
    }
    (camera->focusOffset).x = 0;
    (camera->focusOffset).y = 0;
    (camera->focusOffset).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetZRotation(struct Camera *camera /*$a0*/, short zrot /*$a1*/)
 // line 1044, offset 0x80015eb0
	/* begin block 1 */
		// Start line: 2523
	/* end block 1 */
	// End Line: 2524

	/* begin block 2 */
		// Start line: 2524
	/* end block 2 */
	// End Line: 2525

void CAMERA_SetZRotation(Camera *camera,short zrot)

{
  (camera->core).rotation.z = zrot;
  (camera->focusRotation).z = zrot;
  (camera->targetRotation).z = zrot;
  (camera->targetFocusRotation).z = zrot;
  (camera->rotationAccl).z = 0;
  (camera->rotationVel).z = 0;
  (camera->rotationAccl).z = 0;
  (camera->rotationVel).z = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_LengthSVector(struct _SVector *sv /*$a0*/)
 // line 1099, offset 0x80015ed4
	/* begin block 1 */
		// Start line: 2633
	/* end block 1 */
	// End Line: 2634

long CAMERA_LengthSVector(_SVector *sv)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_FastSqrt0((int)sv->x * (int)sv->x + (int)sv->y * (int)sv->y + (int)sv->z * (int)sv->z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetValue(struct Camera *camera /*$a0*/, long index /*$a1*/, long value /*$a2*/)
 // line 1108, offset 0x80015f28
	/* begin block 1 */
		// Start line: 1110
		// Start offset: 0x80015F28
		// Variables:
	// 		long min; // $t1
	// 		long max; // $t0
	// 		long minTilt; // $a3
	// 		long maxTilt; // $a1
	/* end block 1 */
	// End offset: 0x8001634C
	// End Line: 1162

	/* begin block 2 */
		// Start line: 2651
	/* end block 2 */
	// End Line: 2652

	/* begin block 3 */
		// Start line: 2652
	/* end block 3 */
	// End Line: 2653

void CAMERA_SetValue(Camera *camera,long index,long value)

{
  short sVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  
  puVar10 = (undefined *)0x0;
  puVar9 = &DAT_00003e80;
  iVar8 = -0x1000;
  (&camera->minFocusDistance)[index] = value;
  iVar5 = 0x1000;
  if (camera->cineControl == 0) {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff7f;
  }
  else {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x80;
  }
  sVar1 = camera->mode;
  if (sVar1 == 0xc) {
    puVar6 = (undefined *)camera->focusDistanceList[3];
    puVar3 = (undefined *)camera->focusDistanceList[4];
    if ((int)puVar6 < (int)puVar3) {
      bVar2 = (int)puVar3 < (int)puVar6;
      puVar10 = (undefined *)camera->focusDistanceList[5];
      if ((int)puVar6 < (int)(undefined *)camera->focusDistanceList[5]) {
        puVar10 = puVar6;
      }
    }
    else {
      puVar10 = (undefined *)camera->focusDistanceList[5];
      if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[5]) {
        puVar10 = puVar3;
      }
      puVar6 = (undefined *)camera->focusDistanceList[3];
      puVar3 = (undefined *)camera->focusDistanceList[4];
      bVar2 = (int)puVar3 < (int)puVar6;
    }
    if (bVar2) {
      puVar9 = (undefined *)camera->focusDistanceList[5];
      if ((int)(undefined *)camera->focusDistanceList[5] < (int)puVar6) {
        puVar9 = puVar6;
      }
    }
    else {
      puVar9 = (undefined *)camera->focusDistanceList[5];
      if ((int)(undefined *)camera->focusDistanceList[5] < (int)puVar3) {
        puVar9 = puVar3;
      }
    }
    iVar4 = camera->tiltList[3];
    iVar5 = camera->tiltList[4];
    if (iVar4 < iVar5) {
      iVar8 = camera->tiltList[5];
      if (iVar4 < camera->tiltList[5]) {
        iVar8 = iVar4;
      }
    }
    else {
      iVar8 = camera->tiltList[5];
      if (iVar5 < camera->tiltList[5]) {
        iVar8 = iVar5;
      }
    }
    iVar7 = camera->tiltList[3];
    iVar4 = camera->tiltList[4];
    if (iVar7 <= iVar4) {
      iVar5 = camera->tiltList[5];
      bVar2 = iVar5 < iVar4;
LAB_800162f0:
      if (bVar2) {
        iVar5 = iVar4;
      }
      goto LAB_800162fc;
    }
    iVar5 = camera->tiltList[5];
    bVar2 = iVar5 < iVar7;
  }
  else {
    if (sVar1 < 0xd) {
      if (sVar1 != 0) goto LAB_800162fc;
      puVar6 = (undefined *)camera->focusDistanceList[0];
      puVar3 = (undefined *)camera->focusDistanceList[1];
      if ((int)puVar6 < (int)puVar3) {
        bVar2 = (int)puVar3 < (int)puVar6;
        puVar10 = (undefined *)camera->focusDistanceList[2];
        if ((int)puVar6 < (int)(undefined *)camera->focusDistanceList[2]) {
          puVar10 = puVar6;
        }
      }
      else {
        puVar10 = (undefined *)camera->focusDistanceList[2];
        if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[2]) {
          puVar10 = puVar3;
        }
        puVar6 = (undefined *)camera->focusDistanceList[0];
        puVar3 = (undefined *)camera->focusDistanceList[1];
        bVar2 = (int)puVar3 < (int)puVar6;
      }
      if (bVar2) {
        puVar9 = (undefined *)camera->focusDistanceList[2];
        if ((int)(undefined *)camera->focusDistanceList[2] < (int)puVar6) {
          puVar9 = puVar6;
        }
      }
      else {
        puVar9 = (undefined *)camera->focusDistanceList[2];
        if ((int)(undefined *)camera->focusDistanceList[2] < (int)puVar3) {
          puVar9 = puVar3;
        }
      }
      iVar4 = camera->tiltList[0];
      iVar5 = camera->tiltList[1];
      if (iVar4 < iVar5) {
        iVar8 = camera->tiltList[2];
        if (iVar4 < camera->tiltList[2]) {
          iVar8 = iVar4;
        }
      }
      else {
        iVar8 = camera->tiltList[2];
        if (iVar5 < camera->tiltList[2]) {
          iVar8 = iVar5;
        }
      }
      iVar7 = camera->tiltList[0];
      iVar4 = camera->tiltList[1];
      if (iVar7 <= iVar4) {
        iVar5 = camera->tiltList[2];
        bVar2 = iVar5 < iVar4;
        goto LAB_800162f0;
      }
      iVar5 = camera->tiltList[2];
      bVar2 = iVar5 < iVar7;
    }
    else {
      if (sVar1 != 0xd) goto LAB_800162fc;
      puVar6 = (undefined *)camera->focusDistanceList[6];
      puVar3 = (undefined *)camera->focusDistanceList[7];
      if ((int)puVar6 < (int)puVar3) {
        bVar2 = (int)puVar3 < (int)puVar6;
        puVar10 = (undefined *)camera->focusDistanceList[8];
        if ((int)puVar6 < (int)(undefined *)camera->focusDistanceList[8]) {
          puVar10 = puVar6;
        }
      }
      else {
        puVar10 = (undefined *)camera->focusDistanceList[8];
        if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[8]) {
          puVar10 = puVar3;
        }
        puVar6 = (undefined *)camera->focusDistanceList[6];
        puVar3 = (undefined *)camera->focusDistanceList[7];
        bVar2 = (int)puVar3 < (int)puVar6;
      }
      if (bVar2) {
        puVar9 = (undefined *)camera->focusDistanceList[8];
        if ((int)(undefined *)camera->focusDistanceList[8] < (int)puVar6) {
          puVar9 = puVar6;
        }
      }
      else {
        puVar9 = (undefined *)camera->focusDistanceList[8];
        if ((int)(undefined *)camera->focusDistanceList[8] < (int)puVar3) {
          puVar9 = puVar3;
        }
      }
      iVar4 = camera->tiltList[6];
      iVar5 = camera->tiltList[7];
      if (iVar4 < iVar5) {
        iVar8 = camera->tiltList[8];
        if (iVar4 < camera->tiltList[8]) {
          iVar8 = iVar4;
        }
      }
      else {
        iVar8 = camera->tiltList[8];
        if (iVar5 < camera->tiltList[8]) {
          iVar8 = iVar5;
        }
      }
      iVar7 = camera->tiltList[6];
      iVar4 = camera->tiltList[7];
      if (iVar7 <= iVar4) {
        iVar5 = camera->tiltList[8];
        bVar2 = iVar5 < iVar4;
        goto LAB_800162f0;
      }
      iVar5 = camera->tiltList[8];
      bVar2 = iVar5 < iVar7;
    }
  }
  if (bVar2) {
    iVar5 = iVar7;
  }
LAB_800162fc:
  if ((int)camera->targetFocusDistance < (int)puVar10) {
    camera->targetFocusDistance = (short)puVar10;
  }
  else {
    if ((int)puVar9 < (int)camera->targetFocusDistance) {
      camera->targetFocusDistance = (short)puVar9;
    }
  }
  iVar4 = (int)(camera->targetFocusRotation).x;
  if (iVar8 <= iVar4) {
    if (iVar5 < iVar4) {
      (camera->targetFocusRotation).x = (short)iVar5;
    }
    return;
  }
  (camera->targetFocusRotation).x = (short)iVar8;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_AngleDifference(short angle0 /*$t0*/, short angle1 /*$a3*/)
 // line 1165, offset 0x80016354
	/* begin block 1 */
		// Start line: 2769
	/* end block 1 */
	// End Line: 2770

	/* begin block 2 */
		// Start line: 2770
	/* end block 2 */
	// End Line: 2771

short CAMERA_AngleDifference(short angle0,short angle1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)(ushort)angle0 & 0xfff;
  uVar3 = (uint)(ushort)angle1 & 0xfff;
  if ((int)(uVar3 - uVar2) < 0x801) {
    if (0x800 < (int)(uVar2 - uVar3)) {
      uVar3 = uVar3 | 0x1000;
    }
  }
  else {
    uVar2 = uVar2 | 0x1000;
  }
  uVar1 = uVar3;
  if (uVar3 < uVar2) {
    uVar1 = uVar2;
  }
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  return (short)((uVar1 - uVar3) * 0x10000 >> 0x10);
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_SignedAngleDifference(short angle0 /*$a0*/, short angle1 /*$a1*/)
 // line 1182, offset 0x800163cc
	/* begin block 1 */
		// Start line: 2803
	/* end block 1 */
	// End Line: 2804

short CAMERA_SignedAngleDifference(short angle0,short angle1)

{
                    /* WARNING: Subroutine does not return */
  AngleDiff(angle1,angle0);
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ CAMERA_QueryMode(struct Camera *camera /*$s0*/)
 // line 1201, offset 0x800163fc
	/* begin block 1 */
		// Start line: 1202
		// Start offset: 0x800163FC
		// Variables:
	// 		unsigned long mode; // $s0
	/* end block 1 */
	// End offset: 0x80016484
	// End Line: 1220

	/* begin block 2 */
		// Start line: 2842
	/* end block 2 */
	// End Line: 2843

ulong CAMERA_QueryMode(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(camera->focusInstance,10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMaxVel(struct Camera *camera /*$s1*/)
 // line 1225, offset 0x80016498
	/* begin block 1 */
		// Start line: 1226
		// Start offset: 0x80016498
		// Variables:
	// 		long extraVel; // $s0
	// 		long targetMaxVel; // $v0
	// 		struct _SVector cam_dist; // stack offset -24
	// 		static long maxVelAccl; // offset 0x8
	// 		static long maxVelVel; // offset 0xc

		/* begin block 1.1 */
			// Start line: 1226
			// Start offset: 0x80016498
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // $a1
		// 		struct _Position *_v0; // $a0
		// 		struct _Position *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x80016498
		// End Line: 1226
	/* end block 1 */
	// End offset: 0x80016590
	// End Line: 1258

	/* begin block 2 */
		// Start line: 2890
	/* end block 2 */
	// End Line: 2891

void CAMERA_SetMaxVel(Camera *camera)

{
  _SVector local_18;
  
  local_18.x = (camera->focusPoint).x - (camera->targetFocusPoint).x;
  local_18.y = (camera->focusPoint).y - (camera->targetFocusPoint).y;
  local_18.z = (camera->focusPoint).z - (camera->targetFocusPoint).z;
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(&local_18);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetTarget(struct Camera *camera /*$s0*/, struct _Position *pos /*$s1*/)
 // line 1260, offset 0x800165a4
	/* begin block 1 */
		// Start line: 1261
		// Start offset: 0x800165A4
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1261
			// Start offset: 0x800165A4
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x800165A4
		// End Line: 1261
	/* end block 1 */
	// End offset: 0x800165A4
	// End Line: 1261

	/* begin block 2 */
		// Start line: 2978
	/* end block 2 */
	// End Line: 2979

void CAMERA_SetTarget(Camera *camera,_Position *pos)

{
  _SVector local_18;
  
  CAMERA_CalcRotation(&camera->targetFocusRotation,pos,(_Position *)camera);
  local_18.x = pos->x - (camera->core).position.x;
  local_18.y = pos->y - (camera->core).position.y;
  local_18.z = pos->z - (camera->core).position.z;
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(&local_18);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcPosition(struct _Position *position /*$s3*/, struct _Position *base /*$s2*/, struct _Rotation *rotation /*$s1*/, short distance /*$a3*/)
 // line 1271, offset 0x80016620
	/* begin block 1 */
		// Start line: 1272
		// Start offset: 0x80016620
		// Variables:
	// 		struct SVECTOR sv; // stack offset -96
	// 		struct VECTOR v; // stack offset -88
	// 		struct MATRIX matrix; // stack offset -72
	// 		struct _Vector vectorPos; // stack offset -40

		/* begin block 1.1 */
			// Start line: 1272
			// Start offset: 0x80016620
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80016620
		// End Line: 1272
	/* end block 1 */
	// End offset: 0x80016620
	// End Line: 1272

	/* begin block 2 */
		// Start line: 3003
	/* end block 2 */
	// End Line: 3004

void CAMERA_CalcPosition(_Position *position,_Position *base,_Rotation *rotation,short distance)

{
  MATRIX local_48;
  
  MATH3D_SetUnityMatrix(&local_48);
  RotMatrixX((int)rotation->x,(int)&local_48);
  RotMatrixY((int)rotation->y,(uint *)&local_48);
                    /* WARNING: Subroutine does not return */
  RotMatrixZ((int)rotation->z,(uint *)&local_48);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetFocus(struct Camera *camera /*$s3*/, struct _Position *targetfocusPoint /*$s1*/)
 // line 1312, offset 0x80016748
	/* begin block 1 */
		// Start line: 1313
		// Start offset: 0x80016748
		// Variables:
	// 		struct _Instance *focusInstance; // $s0
	// 		struct _Model *model; // $v0
	// 		struct _SVector temp1; // stack offset -64
	// 		struct _SVector offset; // stack offset -56
	// 		struct _SVector *segPosVector; // $v1
	// 		struct _Vector temp2; // stack offset -48

		/* begin block 1.1 */
			// Start line: 1328
			// Start offset: 0x80016794
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $s2
		/* end block 1.1 */
		// End offset: 0x80016794
		// End Line: 1328

		/* begin block 1.2 */
			// Start line: 1328
			// Start offset: 0x80016794
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $t1
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x80016794
		// End Line: 1328

		/* begin block 1.3 */
			// Start line: 1338
			// Start offset: 0x80016818

			/* begin block 1.3.1 */
				// Start line: 1340
				// Start offset: 0x80016818
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a2
			// 		short _x1; // $a3
			// 		short _y1; // $t0
			// 		short _z1; // $v1
			/* end block 1.3.1 */
			// End offset: 0x80016818
			// End Line: 1340
		/* end block 1.3 */
		// End offset: 0x80016868
		// End Line: 1348

		/* begin block 1.4 */
			// Start line: 1360
			// Start offset: 0x800168AC
			// Variables:
		// 		struct _Instance *instance; // $v0
		// 		struct _SVector output; // stack offset -32

			/* begin block 1.4.1 */
				// Start line: 1366
				// Start offset: 0x800168BC
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.4.1 */
			// End offset: 0x800168BC
			// End Line: 1366

			/* begin block 1.4.2 */
				// Start line: 1373
				// Start offset: 0x800168F4
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v1; // $v0
			/* end block 1.4.2 */
			// End offset: 0x800168F4
			// End Line: 1373
		/* end block 1.4 */
		// End offset: 0x800168F4
		// End Line: 1373

		/* begin block 1.5 */
			// Start line: 1378
			// Start offset: 0x800168F4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x80016910
		// End Line: 1378

		/* begin block 1.6 */
			// Start line: 1381
			// Start offset: 0x80016910
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x80016910
		// End Line: 1381
	/* end block 1 */
	// End offset: 0x800169A4
	// End Line: 1418

	/* begin block 2 */
		// Start line: 3098
	/* end block 2 */
	// End Line: 3099

void CAMERA_SetFocus(Camera *camera,_Position *targetfocusPoint)

{
  short sVar1;
  short sVar2;
  _Segment *p_Var3;
  _Instance *Inst;
  short local_40;
  short local_3e;
  short local_3c;
  _SVector local_38;
  undefined auStack48 [24];
  
  Inst = camera->focusInstance;
  if (((camera->flags & 0x10000U) != 0) || ((camera->instance_mode & 0x4000000) != 0)) {
    p_Var3 = Inst->object->modelList[Inst->currentModel]->segmentList;
    local_40 = p_Var3[1].px;
    local_3e = p_Var3[1].py;
    local_3c = p_Var3[1].pz;
                    /* WARNING: Subroutine does not return */
    ApplyMatrix(Inst->matrix + 1,&local_40,auStack48);
  }
  if (((camera->instance_mode & 0x2000000) != 0) && ((uint)(ushort)camera->mode - 0xc < 2)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst,0x22);
  }
  sVar1 = (Inst->position).y;
  sVar2 = (Inst->position).z;
  targetfocusPoint->x = (Inst->position).x;
  targetfocusPoint->y = sVar1;
  targetfocusPoint->z = sVar2;
  CAMERA_CalcFocusOffset(&local_38,camera);
  targetfocusPoint->x = targetfocusPoint->x + local_38.x;
  targetfocusPoint->y = targetfocusPoint->y + local_38.y;
  targetfocusPoint->z = targetfocusPoint->z + local_38.z;
  sVar1 = targetfocusPoint->z;
  *(undefined4 *)&camera->real_focuspoint = *(undefined4 *)targetfocusPoint;
  (camera->real_focuspoint).z = sVar1;
  if (((camera->instance_mode & 0x2038) == 0) ||
     (((camera->instance_mode & 0x2000) != 0 && (0x46 < (camera->focusInstanceVelVec).z)))) {
    camera->focuspoint_fallz = targetfocusPoint->z;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Lock(struct Camera *camera /*$a0*/, long lock /*$a1*/)
 // line 1420, offset 0x800169c4
	/* begin block 1 */
		// Start line: 3345
	/* end block 1 */
	// End Line: 3346

	/* begin block 2 */
		// Start line: 3346
	/* end block 2 */
	// End Line: 3347

void CAMERA_Lock(Camera *camera,long lock)

{
  camera->lock = camera->lock | lock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Unlock(struct Camera *camera /*$a0*/, long unlock /*$a1*/)
 // line 1425, offset 0x800169d8
	/* begin block 1 */
		// Start line: 3355
	/* end block 1 */
	// End Line: 3356

	/* begin block 2 */
		// Start line: 3356
	/* end block 2 */
	// End Line: 3357

void CAMERA_Unlock(Camera *camera,long unlock)

{
  camera->lock = camera->lock & ~unlock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetSmoothValue(struct Camera *camera /*$a0*/, long smooth /*$a1*/)
 // line 1430, offset 0x800169ec
	/* begin block 1 */
		// Start line: 3365
	/* end block 1 */
	// End Line: 3366

	/* begin block 2 */
		// Start line: 3367
	/* end block 2 */
	// End Line: 3368

void CAMERA_SetSmoothValue(Camera *camera,long smooth)

{
  short sVar1;
  
  camera->smooth = (short)smooth;
  if ((smooth == 0) && (((uint)(ushort)camera->mode - 0xc < 2 || (camera->mode == 0x10)))) {
    sVar1 = (camera->targetFocusPoint).z;
    *(undefined4 *)&camera->focusPoint = *(undefined4 *)&camera->targetFocusPoint;
    (camera->focusPoint).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetTimer(struct Camera *camera /*$a0*/, long time /*$a1*/)
 // line 1443, offset 0x80016a3c
	/* begin block 1 */
		// Start line: 3391
	/* end block 1 */
	// End Line: 3392

void CAMERA_SetTimer(Camera *camera,long time)

{
  CAMERA_Save(camera,-1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_tilt(struct Camera *camera /*$a0*/, long tilt /*$a1*/)
 // line 1449, offset 0x80016a5c
	/* begin block 1 */
		// Start line: 3403
	/* end block 1 */
	// End Line: 3404

	/* begin block 2 */
		// Start line: 3404
	/* end block 2 */
	// End Line: 3405

void CAMERA_Adjust_tilt(Camera *camera,long tilt)

{
  short sVar1;
  ushort uVar2;
  
  camera->tiltState = 3;
  sVar1 = camera->smooth;
  uVar2 = (ushort)tilt & 0xfff;
  (camera->signalRot).x = uVar2;
  if (sVar1 == 0) {
    camera->tilt = 0;
    (camera->targetFocusRotation).x = uVar2;
    (camera->targetRotation).x = uVar2;
    (camera->focusRotation).x = uVar2;
    camera->tfaceTilt = uVar2;
    camera->actual_x_rot = uVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_distance(struct Camera *camera /*$a0*/, long dist /*$a1*/)
 // line 1467, offset 0x80016a98
	/* begin block 1 */
		// Start line: 3442
	/* end block 1 */
	// End Line: 3443

	/* begin block 2 */
		// Start line: 3443
	/* end block 2 */
	// End Line: 3444

void CAMERA_Adjust_distance(Camera *camera,long dist)

{
  short sVar1;
  int time;
  
  camera->signalFocusDistance = (short)dist;
  camera->distanceState = 3;
  time = (int)(short)dist;
  if (camera->maxFocusDistance < time) {
    camera->signalFocusDistance = *(short *)&camera->maxFocusDistance;
    CAMERA_SetTimer((char)camera,time);
    return;
  }
  if (time < camera->minFocusDistance) {
    camera->signalFocusDistance = *(short *)&camera->minFocusDistance;
  }
  if (camera->smooth == 0) {
    sVar1 = camera->signalFocusDistance;
    camera->focusDistance = sVar1;
    camera->targetFocusDistance = sVar1;
    camera->collisionTargetFocusDistance = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_rotation(struct Camera *camera /*$s0*/, long rotation /*$s1*/)
 // line 1485, offset 0x80016b14
	/* begin block 1 */
		// Start line: 3480
	/* end block 1 */
	// End Line: 3481

void CAMERA_Adjust_rotation(Camera *camera,long rotation)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_AngleDifference((short)rotation,(camera->targetFocusRotation).z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_roll(long roll_degrees /*$s0*/, int frames /*$s1*/)
 // line 1504, offset 0x80016b98
	/* begin block 1 */
		// Start line: 3526
	/* end block 1 */
	// End Line: 3527

void CAMERA_Adjust_roll(long roll_degrees,int frames)

{
  long lVar1;
  
  if (frames == 0) {
    roll_target = (roll_degrees & 0xfffU) << 0xc;
    current_roll_amount = roll_target;
    roll_inc = 0;
    return;
  }
  lVar1 = current_roll_amount;
  if (current_roll_amount < 0) {
    lVar1 = current_roll_amount + 0xfff;
  }
                    /* WARNING: Subroutine does not return */
  CAMERA_SignedAngleDifference((short)(roll_degrees & 0xfffU),(short)((uint)(lVar1 << 4) >> 0x10));
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust(struct Camera *camera /*$s1*/, long adjust /*$s2*/)
 // line 1520, offset 0x80016c1c
	/* begin block 1 */
		// Start line: 1521
		// Start offset: 0x80016C1C

		/* begin block 1.1 */
			// Start line: 1525
			// Start offset: 0x80016C44

			/* begin block 1.1.1 */
				// Start line: 1528
				// Start offset: 0x80016C50
				// Variables:
			// 		struct _SVector dv; // stack offset -24

				/* begin block 1.1.1.1 */
					// Start line: 1529
					// Start offset: 0x80016C50
					// Variables:
				// 		short _x0; // $v0
				// 		short _y0; // $v1
				// 		short _z0; // $a1
				// 		short _x1; // $a2
				// 		short _y1; // $t0
				// 		short _z1; // $a3
				// 		struct _SVector *_v; // $a0
				// 		struct _SVector *_v1; // $a3
				/* end block 1.1.1.1 */
				// End offset: 0x80016C50
				// End Line: 1529
			/* end block 1.1.1 */
			// End offset: 0x80016C94
			// End Line: 1544
		/* end block 1.1 */
		// End offset: 0x80016CC4
		// End Line: 1575
	/* end block 1 */
	// End offset: 0x80016CC4
	// End Line: 1580

	/* begin block 2 */
		// Start line: 3560
	/* end block 2 */
	// End Line: 3561

void CAMERA_Adjust(Camera *camera,long adjust)

{
  _CameraKey *p_Var1;
  _SVector local_18;
  
  p_Var1 = camera->cameraKey;
  if (p_Var1 != (_CameraKey *)0x0) {
    if ((adjust & 1U) != 0) {
      local_18.x = p_Var1->x - p_Var1->tx;
      local_18.y = p_Var1->y - p_Var1->ty;
      local_18.z = p_Var1->z - p_Var1->tz;
                    /* WARNING: Subroutine does not return */
      CAMERA_LengthSVector(&local_18);
    }
    if ((adjust & 2U) != 0) {
      CAMERA_Adjust_tilt(camera,(int)p_Var1->rx);
    }
    if ((adjust & 4U) != 0) {
      CAMERA_Adjust_rotation(camera,(int)p_Var1->rz);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ChangeTo(struct Camera *camera /*$a0*/, struct _CameraKey *cameraKey /*$a1*/)
 // line 1583, offset 0x80016cdc
	/* begin block 1 */
		// Start line: 3686
	/* end block 1 */
	// End Line: 3687

	/* begin block 2 */
		// Start line: 3687
	/* end block 2 */
	// End Line: 3688

void CAMERA_ChangeTo(Camera *camera,_CameraKey *cameraKey)

{
  camera->cameraKey = cameraKey;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetShake(struct Camera *camera /*$t0*/, long shake /*$a1*/, long scale /*$a2*/)
 // line 1588, offset 0x80016ce4
	/* begin block 1 */
		// Start line: 1589
		// Start offset: 0x80016CE4
		// Variables:
	// 		int shock; // $a0
	// 		int duration; // $a1
	/* end block 1 */
	// End offset: 0x80016D7C
	// End Line: 1608

	/* begin block 2 */
		// Start line: 3696
	/* end block 2 */
	// End Line: 3697

void CAMERA_SetShake(Camera *camera,long shake,long scale)

{
  int motor1_speed;
  short sVar1;
  int motor1_time;
  
  motor1_speed = camera->shake;
  camera->shakeFrame = 0;
  if (motor1_speed == 0) {
    camera->shake = shake << 0xc;
    camera->shakeScale = (short)scale;
  }
  else {
    if (motor1_speed < shake << 0xc) {
      motor1_speed = shake << 0xc;
    }
    camera->shake = motor1_speed;
    sVar1 = camera->shakeScale;
    if (camera->shakeScale < scale) {
      sVar1 = (short)scale;
    }
    camera->shakeScale = sVar1;
  }
  motor1_speed = (int)((uint)(ushort)camera->shakeScale << 0x10) >> 0x11;
  if (0xff < motor1_speed) {
    motor1_speed = 0xff;
  }
  motor1_time = camera->shake;
  if (motor1_time < 0x4000) {
    motor1_time = 0x4000;
  }
                    /* WARNING: Subroutine does not return */
  GAMEPAD_Shock1(motor1_speed,motor1_time);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Decouple_AngleMoveToward(short *current_ptr /*$a0*/, short destination /*$a1*/, short step /*$a3*/)
 // line 1611, offset 0x80016d94
	/* begin block 1 */
		// Start line: 3742
	/* end block 1 */
	// End Line: 3743

void Decouple_AngleMoveToward(short *current_ptr,short destination,short step)

{
  if (gameTrackerX.timeMult != 0x1000) {
    step = (short)((int)step * gameTrackerX.timeMult >> 0xc);
  }
                    /* WARNING: Subroutine does not return */
  AngleMoveToward(current_ptr,destination,step);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampValue(long dampMode /*$a0*/, short *sourceVal /*$a1*/, short targetVal /*$t2*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1619, offset 0x80016de4
	/* begin block 1 */
		// Start line: 1620
		// Start offset: 0x80016DE4
		// Variables:
	// 		short maxVel; // $t0
	// 		short useVel; // $a0
	/* end block 1 */
	// End offset: 0x80016F90
	// End Line: 1678

	/* begin block 2 */
		// Start line: 3758
	/* end block 2 */
	// End Line: 3759

void CriticalDampValue(long dampMode,short *sourceVal,short targetVal,short *vel,short *accl,
                      int smooth)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)(short)smooth;
  if (iVar5 == 0) {
    *sourceVal = targetVal;
    return;
  }
  if (iVar5 < 0) {
    smooth._0_2_ = (short)(-0x1000 / iVar5);
  }
  if (dampMode == 1) {
LAB_80016e8c:
    iVar5 = (uint)(ushort)targetVal - (uint)(ushort)*sourceVal;
    if (dampMode == 5) {
      sVar4 = *vel;
      sVar3 = (short)(iVar5 * 0x10000 >> 0x11);
    }
    else {
      sVar3 = (short)((uint)(iVar5 * 0x10000) >> 0x10);
      if (dampMode == 6) {
        sVar4 = *vel;
        sVar3 = sVar3 >> 3;
      }
      else {
        sVar4 = *vel;
        sVar3 = sVar3 >> 2;
      }
    }
    *accl = sVar3 - sVar4;
    uVar1 = *vel;
    uVar2 = *accl;
    sVar3 = (short)((uint)uVar1 + (uint)uVar2);
    *vel = sVar3;
    iVar5 = (int)(((uint)uVar1 + (uint)uVar2) * 0x10000) >> 0x10;
    iVar6 = (int)(short)smooth;
    if (iVar6 < iVar5) {
      *vel = (short)smooth;
      sVar3 = (short)smooth;
      if (gameTrackerX.timeMult != 0x1000) {
        sVar3 = (short)(iVar6 * gameTrackerX.timeMult >> 0xc);
      }
    }
    else {
      if (iVar5 < -iVar6) {
        *vel = -(short)smooth;
        sVar3 = -(short)smooth;
        if (gameTrackerX.timeMult != 0x1000) {
          sVar3 = (short)(-(iVar6 * gameTrackerX.timeMult) >> 0xc);
        }
      }
    }
    sVar3 = *sourceVal + sVar3;
  }
  else {
    if (1 < dampMode) {
      if (6 < dampMode) goto code_r0x80016f74;
      if (dampMode < 5) {
        CriticalDampPosition(dampMode,(char)sourceVal,(char)targetVal,(char)vel,accl._0_1_,smooth);
        return;
      }
      goto LAB_80016e8c;
    }
    if (dampMode != 0) {
      CriticalDampPosition(dampMode,(char)sourceVal,(char)targetVal,(char)vel,accl._0_1_,smooth);
      return;
    }
    sVar3 = (short)((int)(((uint)(ushort)targetVal - (uint)(ushort)*sourceVal) * 0x10000) >> 0x12) -
            *vel;
    *accl = sVar3;
    sVar3 = *vel + sVar3;
    *vel = sVar3;
    sVar3 = *sourceVal + sVar3;
  }
  *sourceVal = sVar3;
code_r0x80016f74:
  if (*vel != 0) {
    return;
  }
  *sourceVal = targetVal;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampPosition(long dampMode /*$a0*/, struct _Position *position /*$s1*/, struct _Position *targetPos /*$s3*/, struct _SVector *vel /*$s2*/, struct _SVector *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1731, offset 0x80016f98
	/* begin block 1 */
		// Start line: 1732
		// Start offset: 0x80016F98
		// Variables:
	// 		long length; // $s0
	// 		struct _Vector vector; // stack offset -48
	// 		struct _SVector svector; // stack offset -32
	// 		short maxVel; // $s4
	// 		int shift; // $a3

		/* begin block 1.1 */
			// Start line: 1753
			// Start offset: 0x80017014
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.1 */
		// End offset: 0x80017014
		// End Line: 1753

		/* begin block 1.2 */
			// Start line: 1768
			// Start offset: 0x800170D0
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.2 */
		// End offset: 0x800170D0
		// End Line: 1768

		/* begin block 1.3 */
			// Start line: 1802
			// Start offset: 0x80017274
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $s2
		/* end block 1.3 */
		// End offset: 0x80017274
		// End Line: 1802

		/* begin block 1.4 */
			// Start line: 1806
			// Start offset: 0x800172C8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.4 */
		// End offset: 0x800172C8
		// End Line: 1806

		/* begin block 1.5 */
			// Start line: 1810
			// Start offset: 0x800172C8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.5 */
		// End offset: 0x800172C8
		// End Line: 1810

		/* begin block 1.6 */
			// Start line: 1817
			// Start offset: 0x80017364
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $a1
		/* end block 1.6 */
		// End offset: 0x80017364
		// End Line: 1817

		/* begin block 1.7 */
			// Start line: 1831
			// Start offset: 0x800174F4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.7 */
		// End offset: 0x800174F4
		// End Line: 1831

		/* begin block 1.8 */
			// Start line: 1862
			// Start offset: 0x80017624
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.8 */
		// End offset: 0x8001763C
		// End Line: 1862
	/* end block 1 */
	// End offset: 0x8001763C
	// End Line: 1864

	/* begin block 2 */
		// Start line: 3984
	/* end block 2 */
	// End Line: 3985

void CriticalDampPosition
               (long dampMode,_Position *position,_Position *targetPos,_SVector *vel,_SVector *accl,
               int smooth)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  _SVector _Stack32;
  
  if ((short)smooth == 0) {
    sVar4 = targetPos->y;
    sVar3 = targetPos->z;
    position->x = targetPos->x;
    position->y = sVar4;
    position->z = sVar3;
  }
  else {
    switch(dampMode) {
    case 0:
      sVar4 = targetPos->y;
      sVar3 = targetPos->z;
      sVar1 = position->z;
      sVar2 = position->y;
      accl->x = (short)((int)targetPos->x - (int)position->x >> 2) - vel->x;
      accl->y = (short)((int)sVar4 - (int)sVar2 >> 2) - vel->y;
      accl->z = (short)((int)sVar3 - (int)sVar1 >> 2) - vel->z;
      vel->x = vel->x + accl->x;
      vel->y = vel->y + accl->y;
      vel->z = vel->z + accl->z;
      position->x = position->x + vel->x;
      position->y = position->y + vel->y;
      position->z = position->z + vel->z;
      break;
    case 1:
    case 5:
      iVar5 = 2;
      if (dampMode == 5) {
        iVar5 = 1;
      }
      sVar4 = targetPos->y;
      sVar3 = targetPos->z;
      sVar1 = position->z;
      sVar2 = position->y;
      accl->x = (short)((int)targetPos->x - (int)position->x >> iVar5) - vel->x;
      accl->y = (short)((int)sVar4 - (int)sVar2 >> iVar5) - vel->y;
      accl->z = (short)((int)sVar3 - (int)sVar1 >> iVar5) - vel->z;
      vel->x = vel->x + accl->x;
      vel->y = vel->y + accl->y;
                    /* WARNING: Subroutine does not return */
      vel->z = vel->z + accl->z;
      CAMERA_LengthSVector(vel);
    case 3:
      _Stack32.x = targetPos->x - position->x;
      _Stack32.y = targetPos->y - position->y;
      _Stack32.z = targetPos->z - position->z;
                    /* WARNING: Subroutine does not return */
      CAMERA_LengthSVector(&_Stack32);
    case 4:
      iVar5 = (uint)(ushort)targetPos->x - (uint)(ushort)position->x;
      _Stack32.y = targetPos->y - position->y;
      _Stack32.z = targetPos->z - position->z;
      _Stack32.x = (short)iVar5;
      accl->x = (short)(iVar5 * 0x10000 >> 0x12) - vel->x;
      accl->y = (_Stack32.y >> 2) - vel->y;
      accl->z = (_Stack32.z >> 2) - vel->z;
      if (_Stack32.x < 1) {
        sVar4 = accl->x;
        if (0 < accl->x) {
          sVar4 = 0;
        }
      }
      else {
        sVar4 = accl->x;
        if (accl->x < 0) {
          sVar4 = 0;
        }
      }
      accl->x = sVar4;
      if (_Stack32.y < 1) {
        sVar4 = accl->y;
        if (0 < accl->y) {
          sVar4 = 0;
        }
      }
      else {
        sVar4 = accl->y;
        if (accl->y < 0) {
          sVar4 = 0;
        }
      }
      accl->y = sVar4;
      if (_Stack32.z < 1) {
        sVar4 = accl->z;
        if (0 < accl->z) {
          sVar4 = 0;
        }
      }
      else {
        sVar4 = accl->z;
        if (accl->z < 0) {
          sVar4 = 0;
        }
      }
      accl->z = sVar4;
      vel->x = vel->x + accl->x;
      vel->y = vel->y + accl->y;
                    /* WARNING: Subroutine does not return */
      vel->z = vel->z + accl->z;
      CAMERA_LengthSVector(vel);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampAngle(long dampMode /*$a0*/, short *currentVal /*$s0*/, short target /*$t1*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1866, offset 0x8001765c
	/* begin block 1 */
		// Start line: 1867
		// Start offset: 0x8001765C
		// Variables:
	// 		short current; // stack offset -16
	/* end block 1 */
	// End offset: 0x800176B8
	// End Line: 1882

	/* begin block 2 */
		// Start line: 4272
	/* end block 2 */
	// End Line: 4273

void CriticalDampAngle(long dampMode,short *currentVal,short target,short *vel,short *accl,
                      int smooth)

{
  uint uVar1;
  uint uVar2;
  ushort targetVal;
  ushort local_10 [4];
  
  uVar2 = (uint)(ushort)target & 0xfff;
  targetVal = (ushort)uVar2;
  uVar1 = (uint)(ushort)*currentVal & 0xfff;
  local_10[0] = (ushort)uVar1;
  if ((int)(uVar2 - uVar1) < 0x800) {
    if (0x800 < (int)(uVar1 - uVar2)) {
      targetVal = targetVal | 0x1000;
    }
  }
  else {
    local_10[0] = local_10[0] + 0x1000;
  }
  CriticalDampValue(dampMode,(short *)local_10,targetVal,vel,accl,(int)(short)smooth);
  *currentVal = local_10[0] & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_CalcZRotation(struct _Position *target /*$a0*/, struct _Position *position /*$a1*/)
 // line 1887, offset 0x800176fc
	/* begin block 1 */
		// Start line: 1888
		// Start offset: 0x800176FC
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1888
			// Start offset: 0x800176FC
			// Variables:
		// 		short _x0; // $a2
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x800176FC
		// End Line: 1888
	/* end block 1 */
	// End offset: 0x800176FC
	// End Line: 1888

	/* begin block 2 */
		// Start line: 4324
	/* end block 2 */
	// End Line: 4325

short CAMERA_CalcZRotation(_Position *target,_Position *position)

{
  _SVector local_10;
  
  local_10.x = position->x - target->x;
  local_10.y = position->y - target->y;
  local_10.z = 0;
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(&local_10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcRotation(struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a1*/, struct _Position *position /*$a2*/)
 // line 1904, offset 0x80017774
	/* begin block 1 */
		// Start line: 1905
		// Start offset: 0x80017774
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1905
			// Start offset: 0x80017774
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a0
		// 		short _y1; // $a2
		// 		short _z1; // $a1
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80017774
		// End Line: 1905
	/* end block 1 */
	// End offset: 0x80017774
	// End Line: 1905

	/* begin block 2 */
		// Start line: 4363
	/* end block 2 */
	// End Line: 4364

void CAMERA_CalcRotation(_Rotation *rotation,_Position *target,_Position *position)

{
  _SVector local_10;
  
  local_10.x = position->x - target->x;
  local_10.y = position->y - target->y;
  local_10.z = 0;
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(&local_10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFSRotation(struct Camera *camera /*$a0*/, struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a2*/, struct _Position *position /*$a3*/)
 // line 1921, offset 0x80017810
	/* begin block 1 */
		// Start line: 1922
		// Start offset: 0x80017810
		// Variables:
	// 		struct _SVector sv; // stack offset -32
	// 		struct _SVector onPlane; // stack offset -24
	// 		struct _SVector sv2; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1922
			// Start offset: 0x80017810
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $v0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x80017810
		// End Line: 1922

		/* begin block 1.2 */
			// Start line: 1922
			// Start offset: 0x80017810
			// Variables:
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80017810
		// End Line: 1922
	/* end block 1 */
	// End offset: 0x80017810
	// End Line: 1922

	/* begin block 2 */
		// Start line: 4401
	/* end block 2 */
	// End Line: 4402

void CAMERA_CalcFSRotation(Camera *camera,_Rotation *rotation,_Position *target,_Position *position)

{
  _SVector local_18;
  short local_10;
  short local_e;
  short local_c;
  
  local_18.x = position->x - target->x;
  local_18.y = position->y - target->y;
  local_c = position->z - target->z;
  local_18.z = 0;
  local_10 = local_18.x;
  local_e = local_18.y;
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(&local_18);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Relocate(struct Camera *camera /*$a0*/, struct _SVector *offset /*$a1*/, int streamSignalFlag /*$a2*/)
 // line 1941, offset 0x800178bc
	/* begin block 1 */
		// Start line: 4445
	/* end block 1 */
	// End Line: 4446

	/* begin block 2 */
		// Start line: 4450
	/* end block 2 */
	// End Line: 4451

void CAMERA_Relocate(Camera *camera,_SVector *offset,int streamSignalFlag)

{
  if ((streamSignalFlag != 0) || (camera->mode != 5)) {
    (camera->core).position.x = (camera->core).position.x + offset->x;
    (camera->core).position.y = (camera->core).position.y + offset->y;
    (camera->core).position.z = (camera->core).position.z + offset->z;
    (camera->focusPoint).x = (camera->focusPoint).x + offset->x;
    (camera->focusPoint).y = (camera->focusPoint).y + offset->y;
    (camera->focusPoint).z = (camera->focusPoint).z + offset->z;
    (camera->targetPos).x = (camera->targetPos).x + offset->x;
    (camera->targetPos).y = (camera->targetPos).y + offset->y;
    (camera->targetPos).z = (camera->targetPos).z + offset->z;
    (camera->targetFocusPoint).x = (camera->targetFocusPoint).x + offset->x;
    (camera->targetFocusPoint).y = (camera->targetFocusPoint).y + offset->y;
    (camera->targetFocusPoint).z = (camera->targetFocusPoint).z + offset->z;
    (camera->newFocusInstancePos).x = (camera->newFocusInstancePos).x + offset->x;
    (camera->newFocusInstancePos).y = (camera->newFocusInstancePos).y + offset->y;
    (camera->newFocusInstancePos).z = (camera->newFocusInstancePos).z + offset->z;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _TFace * /*$ra*/ CAMERA_SphereToSphereWithLines(struct Camera *camera /*$s6*/, struct CameraCollisionInfo *colInfo /*stack 4*/, int secondcheck_flag /*stack 8*/)
 // line 2010, offset 0x80017a08
	/* begin block 1 */
		// Start line: 2011
		// Start offset: 0x80017A08
		// Variables:
	// 		long minLength; // stack offset -68
	// 		struct _SVector sv; // stack offset -344
	// 		struct _SVector startPt[5]; // stack offset -336
	// 		struct _SVector endPt[5]; // stack offset -296
	// 		struct _SVector startLine; // stack offset -256
	// 		struct _Vector adjStartLine; // stack offset -248
	// 		struct _SVector endLine; // stack offset -232
	// 		struct _Vector adjEndLine; // stack offset -224
	// 		struct _Vector CamLineNormalized; // stack offset -208
	// 		struct _Rotation rotation; // stack offset -192
	// 		struct MATRIX matrix; // stack offset -184
	// 		struct _TFace *result; // stack offset -64
	// 		long i; // stack offset -60
	// 		long init; // stack offset -56
	// 		struct Level *level; // stack offset -52
	// 		struct _Instance *focusInstance; // $v0
	// 		struct _Vector ACE_vect; // stack offset -152
	// 		struct _LCollideInfo lcol; // stack offset -136
	// 		int ACE_force; // $s2
	// 		int in_warpRoom; // stack offset -48

		/* begin block 1.1 */
			// Start line: 2126
			// Start offset: 0x80017D14
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $v0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $v1
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80017D14
		// End Line: 2126

		/* begin block 1.2 */
			// Start line: 2126
			// Start offset: 0x80017D14
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $v0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $v1
		// 		struct _Position *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80017D14
		// End Line: 2126

		/* begin block 1.3 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $v0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $s3
		// 		struct _Position *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.4 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a1
		// 		short _z0; // $v0
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $v1
		// 		struct _Position *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.5 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a1
		// 		short _z0; // $a2
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.6 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a1
		// 		short _z0; // $a2
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.6 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.7 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a2
		// 		short _z0; // $v0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v1
		// 		struct _Position *_v0; // $v0
		/* end block 1.7 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.8 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a3
		// 		short _z0; // $v0
		// 		short _x1; // $t0
		// 		short _y1; // $t1
		// 		short _z1; // $t2
		// 		struct _SVector *_v; // $v1
		// 		struct _Position *_v0; // $v0
		/* end block 1.8 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.9 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t2
		// 		short _z1; // $t3
		// 		struct _SVector *_v; // $v0
		// 		struct _SVector *_v0; // $a3
		// 		struct _SVector *_v1; // $t1
		/* end block 1.9 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.10 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t2
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v0
		/* end block 1.10 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.11 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.11 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.12 */
			// Start line: 2139
			// Start offset: 0x80017E20
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a2
		// 		struct _Position *_v1; // $v0
		/* end block 1.12 */
		// End offset: 0x80017E20
		// End Line: 2139

		/* begin block 1.13 */
			// Start line: 2225
			// Start offset: 0x80018170
			// Variables:
		// 		int flag; // $fp
		// 		short backface_flag; // stack offset -72
		// 		struct _PCollideInfo pCollideInfo; // stack offset -120

			/* begin block 1.13.1 */
				// Start line: 2250
				// Start offset: 0x800181D0
				// Variables:
			// 		int n; // $s2

				/* begin block 1.13.1.1 */
					// Start line: 2255
					// Start offset: 0x800181E0
					// Variables:
				// 		struct Level *thislevel; // $s1
				/* end block 1.13.1.1 */
				// End offset: 0x80018268
				// End Line: 2272
			/* end block 1.13.1 */
			// End offset: 0x80018278
			// End Line: 2273

			/* begin block 1.13.2 */
				// Start line: 2298
				// Start offset: 0x800182B8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // stack offset -44
			/* end block 1.13.2 */
			// End offset: 0x800182B8
			// End Line: 2298

			/* begin block 1.13.3 */
				// Start line: 2329
				// Start offset: 0x8001840C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.13.3 */
			// End offset: 0x8001840C
			// End Line: 2329
		/* end block 1.13 */
		// End offset: 0x8001848C
		// End Line: 2354
	/* end block 1 */
	// End offset: 0x80018520
	// End Line: 2373

	/* begin block 2 */
		// Start line: 4583
	/* end block 2 */
	// End Line: 4584

_TFace * CAMERA_SphereToSphereWithLines
                   (Camera *camera,CameraCollisionInfo *colInfo,int secondcheck_flag)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(camera->focusInstance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_CalcTilt(struct _Normal *normal /*$s1*/, short zRot /*$a1*/)
 // line 2375, offset 0x80018550
	/* begin block 1 */
		// Start line: 2376
		// Start offset: 0x80018550
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct VECTOR newNormal; // stack offset -32
	/* end block 1 */
	// End offset: 0x80018550
	// End Line: 2376

	/* begin block 2 */
		// Start line: 5809
	/* end block 2 */
	// End Line: 5810

long CAMERA_CalcTilt(_Normal *normal,short zRot)

{
  MATRIX MStack64;
  
  MATH3D_SetUnityMatrix(&MStack64);
                    /* WARNING: Subroutine does not return */
  RotMatrixZ(-(int)zRot,(uint *)&MStack64);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance /*$a0*/, struct _Position *focusPoint /*$a1*/)
 // line 2392, offset 0x800185c4
	/* begin block 1 */
		// Start line: 2393
		// Start offset: 0x800185C4
		// Variables:
	// 		struct _Position lookFocus; // stack offset -8
	/* end block 1 */
	// End offset: 0x800185C4
	// End Line: 2393

	/* begin block 2 */
		// Start line: 5844
	/* end block 2 */
	// End Line: 5845

	/* begin block 3 */
		// Start line: 5849
	/* end block 3 */
	// End Line: 5850

void CAMERA_SetLookFocusAndBase(_Instance *focusInstance,_Position *focusPoint)

{
  short sVar1;
  
  sVar1 = (focusInstance->position).z;
  *(undefined4 *)focusPoint = *(undefined4 *)&focusInstance->position;
  focusPoint->z = sVar1 + 0x200;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookFocusAndDistance(struct Camera *camera /*$a0*/, struct VECTOR *focuspoint /*$a1*/, int distance /*$a2*/)
 // line 2405, offset 0x8001860c
	/* begin block 1 */
		// Start line: 5875
	/* end block 1 */
	// End Line: 5876

	/* begin block 2 */
		// Start line: 5876
	/* end block 2 */
	// End Line: 5877

void CAMERA_SetLookFocusAndDistance(Camera *camera,VECTOR *focuspoint,int distance)

{
  (camera->targetFocusPoint).x = *(short *)&focuspoint->vx;
  (camera->targetFocusPoint).y = *(short *)&focuspoint->vy;
  Camera_lookDist = (short)distance;
  (camera->targetFocusPoint).z = *(short *)&focuspoint->vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_LookProcess(struct Camera *camera /*$s2*/)
 // line 2413, offset 0x80018634
	/* begin block 1 */
		// Start line: 2414
		// Start offset: 0x80018634
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		int smooth; // $t0
	// 		int distance; // $a3
	// 		long dampMode; // $a0

		/* begin block 1.1 */
			// Start line: 2459
			// Start offset: 0x80018724
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80018724
		// End Line: 2459

		/* begin block 1.2 */
			// Start line: 2480
			// Start offset: 0x8001878C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.2 */
		// End offset: 0x8001878C
		// End Line: 2480

		/* begin block 1.3 */
			// Start line: 2480
			// Start offset: 0x8001878C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x8001878C
		// End Line: 2480

		/* begin block 1.4 */
			// Start line: 2480
			// Start offset: 0x8001878C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x8001878C
		// End Line: 2480
	/* end block 1 */
	// End offset: 0x8001878C
	// End Line: 2486

	/* begin block 2 */
		// Start line: 5888
	/* end block 2 */
	// End Line: 5889

	/* begin block 3 */
		// Start line: 5892
	/* end block 3 */
	// End Line: 5893

void CAMERA_LookProcess(Camera *camera)

{
  short sVar1;
  short sVar2;
  short distance;
  
  sVar2 = Camera_lookDist;
  sVar1 = (camera->focusInstanceVelVec).y;
  distance = camera->focusDistance;
  (camera->targetFocusPoint).x = (camera->targetFocusPoint).x + (camera->focusInstanceVelVec).x;
  (camera->targetFocusPoint).y = (camera->targetFocusPoint).y + sVar1;
  (camera->targetFocusPoint).z = (camera->targetFocusPoint).z + (camera->focusInstanceVelVec).z;
  if (distance <= sVar2) {
    distance = sVar2;
  }
                    /* WARNING: Subroutine does not return */
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,&camera->focusRotation,distance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Normalize(struct _SVector *svector /*$s0*/)
 // line 2539, offset 0x80018888
	/* begin block 1 */
		// Start line: 2540
		// Start offset: 0x80018888
		// Variables:
	// 		long len; // $a1
	/* end block 1 */
	// End offset: 0x800188F0
	// End Line: 2548

	/* begin block 2 */
		// Start line: 6187
	/* end block 2 */
	// End Line: 6188

void CAMERA_Normalize(_SVector *svector)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_LengthSVector(svector);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_HandleTransitions(struct Camera *camera /*$s0*/)
 // line 2550, offset 0x80018900
	/* begin block 1 */
		// Start line: 2551
		// Start offset: 0x80018900
	/* end block 1 */
	// End offset: 0x80018AA4
	// End Line: 2662

	/* begin block 2 */
		// Start line: 6211
	/* end block 2 */
	// End Line: 6212

void CAMERA_HandleTransitions(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  if (camera->rotState == 3) {
    sVar2 = (camera->signalRot).z;
    sVar1 = camera->forced_movement;
    (camera->targetFocusRotation).z = sVar2;
    (camera->collisionTargetFocusRotation).z = sVar2;
    if ((sVar1 != 1) || ((camera->lock & 4U) != 0)) {
                    /* WARNING: Subroutine does not return */
      CAMERA_AngleDifference((camera->targetFocusRotation).z,(camera->focusRotation).z);
    }
    camera->rotState = 0;
    (camera->focusRotVel).z = 0;
    (camera->focusRotAccl).z = 0;
  }
  if (camera->tiltState == 3) {
    sVar1 = camera->forced_movement;
    (camera->targetFocusRotation).x = (camera->signalRot).x;
    if ((sVar1 != 3) || ((camera->lock & 2U) != 0)) {
                    /* WARNING: Subroutine does not return */
      CAMERA_AngleDifference((camera->focusRotation).x,(camera->signalRot).x);
    }
    camera->tiltState = 0;
    (camera->focusRotVel).x = 0;
    (camera->focusRotAccl).x = 0;
  }
  if (camera->distanceState != 3) goto LAB_80018a6c;
  if ((camera->forced_movement == 2) && ((camera->lock & 1U) == 0)) {
LAB_80018a54:
    camera->distanceState = 0;
LAB_80018a58:
    camera->focusDistanceVel = 0;
    camera->focusDistanceAccl = 0;
  }
  else {
    iVar3 = (int)camera->targetFocusDistance - (int)camera->signalFocusDistance;
    if (iVar3 < 0) {
      if ((int)camera->signalFocusDistance - (int)camera->targetFocusDistance < 4)
      goto LAB_80018a54;
    }
    else {
      if (iVar3 < 4) {
        camera->distanceState = 0;
        goto LAB_80018a58;
      }
    }
  }
  camera->targetFocusDistance = camera->signalFocusDistance;
LAB_80018a6c:
  if ((camera->posState == 3) && ((camera->mode != 5 || ((camera->flags & 0x1000U) != 0)))) {
    camera->posState = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFocusOffset(struct _SVector *offset /*$a2*/, struct Camera *camera /*$a1*/)
 // line 2666, offset 0x80018ab4
	/* begin block 1 */
		// Start line: 2667
		// Start offset: 0x80018AB4
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -24
	// 		struct _SVector temp; // stack offset -8
	// 		struct _Instance *focusInstance; // $a0

		/* begin block 1.1 */
			// Start line: 2691
			// Start offset: 0x80018AF4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x80018AF4
		// End Line: 2691
	/* end block 1 */
	// End offset: 0x80018AF4
	// End Line: 2691

	/* begin block 2 */
		// Start line: 6445
	/* end block 2 */
	// End Line: 6446

void CAMERA_CalcFocusOffset(_SVector *offset,Camera *camera)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  MATRIX *pMVar5;
  short local_18;
  short local_14;
  short local_10;
  uint local_4;
  
  uVar1 = (camera->focusOffset).z;
  if ((int)camera->instance_mode < 0) {
    uVar1 = uVar1 + 0x100;
  }
  local_4 = local_4 & 0xffff0000 | (uint)uVar1;
  pMVar5 = camera->focusInstance->matrix;
  setCopControlWord(2,0,*(undefined4 *)pMVar5->m);
  setCopControlWord(2,0x800,*(undefined4 *)(pMVar5->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(pMVar5->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(pMVar5->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(pMVar5->m + 8));
  setCopReg(2,in_zero,*(undefined4 *)&camera->focusOffset);
  setCopReg(2,in_at,local_4);
  copFunction(2,0x486012);
  uVar2 = getCopReg(2,0x19);
  uVar3 = getCopReg(2,0x1a);
  uVar4 = getCopReg(2,0x1b);
  local_18 = (short)uVar2;
  local_14 = (short)uVar3;
  local_10 = (short)uVar4;
  offset->x = local_18;
  offset->y = local_14;
  offset->z = local_10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset /*$s0*/, struct Camera *camera /*$a1*/)
 // line 2696, offset 0x80018b68
	/* begin block 1 */
		// Start line: 2697
		// Start offset: 0x80018B68
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -32
	// 		struct _SVector temp; // stack offset -16
	// 		struct _Instance *focusInstance; // $v1

		/* begin block 1.1 */
			// Start line: 2697
			// Start offset: 0x80018B68
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80018B68
		// End Line: 2697
	/* end block 1 */
	// End offset: 0x80018B68
	// End Line: 2697

	/* begin block 2 */
		// Start line: 6513
	/* end block 2 */
	// End Line: 6514

void CAMERA_CalcFocusOffsetForSwim(_SVector *offset,Camera *camera)

{
  undefined local_20 [16];
  short local_10;
  short local_e;
  short local_c;
  
  local_10 = (camera->focusOffset).x;
  local_e = (camera->focusOffset).y;
  local_c = (camera->focusOffset).z;
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(camera->focusInstance->matrix + 1,&local_10,local_20);
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_CalcIntersectAngle(struct _SVector *linept /*$s0*/, struct _SVector *vertex0 /*$a1*/, struct _SVector *vertex1 /*$a2*/, short *high /*$s2*/, short *low /*stack 16*/)
 // line 2720, offset 0x80018bd4
	/* begin block 1 */
		// Start line: 2721
		// Start offset: 0x80018BD4
		// Variables:
	// 		struct _SVector point; // stack offset -24
	// 		short zrot; // $a0
	// 		long camera_plane_d; // $v0
	/* end block 1 */
	// End offset: 0x80018CB0
	// End Line: 2740

	/* begin block 2 */
		// Start line: 6579
	/* end block 2 */
	// End Line: 6580

	/* begin block 3 */
		// Start line: 6584
	/* end block 3 */
	// End Line: 6585

short CAMERA_CalcIntersectAngle
                (_SVector *linept,_SVector *vertex0,_SVector *vertex1,short *high,short *low)

{
  short angle0;
  int iVar1;
  _Position _Stack24;
  
  iVar1 = COLLIDE_IntersectLineAndPlane_S
                    (&_Stack24,vertex0,vertex1,&camera_plane,
                     (int)camera_plane.x * (int)linept->x + (int)camera_plane.y * (int)linept->y +
                     (int)camera_plane.z * (int)linept->z >> 0xc);
  if (iVar1 != 0) {
    angle0 = CAMERA_CalcZRotation((_Position *)linept,&_Stack24);
                    /* WARNING: Subroutine does not return */
    CAMERA_SignedAngleDifference(angle0,hitline_rot);
  }
  return -9999;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_GetLineAngle(struct Camera *camera /*$a0*/, struct CameraCollisionInfo *colInfo /*$a1*/, struct _SVector *linept /*$a2*/, int line /*$s5*/)
 // line 2742, offset 0x80018cc8
	/* begin block 1 */
		// Start line: 2743
		// Start offset: 0x80018CC8
		// Variables:
	// 		struct _Terrain *terrain; // $t1
	// 		struct _SVector *vertex0; // $s1
	// 		struct _SVector *vertex1; // $s0
	// 		struct _SVector *vertex2; // $s3
	// 		struct _SVector new_linept; // stack offset -48
	// 		short high; // stack offset -40
	// 		short low; // stack offset -38
	/* end block 1 */
	// End offset: 0x80018E6C
	// End Line: 2772

	/* begin block 2 */
		// Start line: 6646
	/* end block 2 */
	// End Line: 6647

short CAMERA_GetLineAngle(Camera *camera,CameraCollisionInfo *colInfo,_SVector *linept,int line)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  _SVector *vertex1;
  _SVector *vertex0;
  int iVar4;
  _SVector *vertex1_00;
  _SVector local_30;
  short local_28;
  short local_26 [3];
  
  local_28 = -5000;
  local_26[0] = 5000;
  puVar3 = (ushort *)(colInfo->tfaceList + line)[5];
  puVar1 = (ushort *)colInfo->tfaceList[line];
  iVar2 = (int)colInfo->bspTree[line] * 0x24;
  iVar4 = *(int *)(puVar3 + 0xe);
  vertex0 = (_SVector *)(iVar4 + (uint)*puVar1 * 0xc);
  local_30.x = linept->x - *(short *)(iVar2 + *(int *)(puVar3 + 0x24) + 0xc);
  local_30.y = linept->y - *(short *)(iVar2 + *(int *)(puVar3 + 0x24) + 0xe);
  vertex1 = (_SVector *)(iVar4 + (uint)puVar1[1] * 0xc);
  local_30.z = linept->z - *(short *)(iVar2 + *(int *)(puVar3 + 0x24) + 0x10);
  vertex1_00 = (_SVector *)(iVar4 + (uint)puVar1[2] * 0xc);
  CAMERA_CalcIntersectAngle(&local_30,vertex0,vertex1,&local_28,local_26);
  CAMERA_CalcIntersectAngle(&local_30,vertex1,vertex1_00,&local_28,local_26);
  CAMERA_CalcIntersectAngle(&local_30,vertex1_00,vertex0,&local_28,local_26);
  if (local_28 == -5000) {
    local_28 = 0;
  }
  if (local_26[0] == 5000) {
    local_26[0] = 0;
  }
  if (0x400 < local_28) {
    local_28 = 0;
  }
  if (local_26[0] < -0x400) {
    local_26[0] = 0;
  }
  if (line != 2) {
    local_28 = local_26[0];
  }
  return local_28;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_ACForcedMovement(struct Camera *camera /*$s1*/, struct CameraCollisionInfo *colInfo /*$s0*/)
 // line 2786, offset 0x80018e90
	/* begin block 1 */
		// Start line: 2787
		// Start offset: 0x80018E90
		// Variables:
	// 		long dp; // $v0
	// 		struct _Normal normal; // stack offset -32
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 2787
			// Start offset: 0x80018E90
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $a2
		// 		short _z0; // $v0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v; // $a0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80018E90
		// End Line: 2787
	/* end block 1 */
	// End offset: 0x80018F48
	// End Line: 2825

	/* begin block 2 */
		// Start line: 6854
	/* end block 2 */
	// End Line: 6855

long CAMERA_ACForcedMovement(Camera *camera,CameraCollisionInfo *colInfo)

{
  _SVector local_20 [2];
  
                    /* WARNING: Subroutine does not return */
  COLLIDE_GetNormal(*(short *)(colInfo->tfaceList[colInfo->line] + 8),
                    *(short **)((colInfo->tfaceList + colInfo->line)[5] + 0x24),local_20);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_update_dist_debounced(struct Camera *camera /*$a0*/, short dist /*$a2*/)
 // line 2828, offset 0x80018f60
	/* begin block 1 */
		// Start line: 6945
	/* end block 1 */
	// End Line: 6946

	/* begin block 2 */
		// Start line: 6946
	/* end block 2 */
	// End Line: 6947

void CAMERA_update_dist_debounced(Camera *camera,short dist)

{
  if ((((camera->instance_mode & 0x2000000) == 0) || (599 < dist)) || (0xfc7 < combat_cam_weight)) {
    shorten_flag = 1;
    shorten_count = shorten_count + 1;
    if (2 < shorten_count) {
      camera->collisionTargetFocusDistance = dist;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_dampgetline(short angle /*$a0*/)
 // line 2840, offset 0x80018fd0
	/* begin block 1 */
		// Start line: 2841
		// Start offset: 0x80018FD0
		// Variables:
	// 		static short target_angle; // offset 0x50
	// 		static short angle_vel; // offset 0x52
	// 		static short angle_accl; // offset 0x54
	/* end block 1 */
	// End offset: 0x80019074
	// End Line: 2858

	/* begin block 2 */
		// Start line: 6970
	/* end block 2 */
	// End Line: 6971

short CAMERA_dampgetline(short angle)

{
                    /* WARNING: Subroutine does not return */
  CriticalDampAngle(1,&DAT_800cf160,angle,(short *)&DAT_800cf162,(short *)&DAT_800cf164,0x400);
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_ACNoForcedMovement(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *colInfo /*$s1*/)
 // line 2866, offset 0x80019088
	/* begin block 1 */
		// Start line: 2867
		// Start offset: 0x80019088
		// Variables:
	// 		long hit; // $s2
	// 		short playerSamePos; // $s3
	// 		short angle; // $a0

		/* begin block 1.1 */
			// Start line: 2893
			// Start offset: 0x80019100
			// Variables:
		// 		int n; // $a0
		// 		int flag; // $t1
		// 		short dist; // $a1
		/* end block 1.1 */
		// End offset: 0x800192B4
		// End Line: 2949
	/* end block 1 */
	// End offset: 0x80019578
	// End Line: 3117

	/* begin block 2 */
		// Start line: 7030
	/* end block 2 */
	// End Line: 7031

long CAMERA_ACNoForcedMovement(Camera *camera,CameraCollisionInfo *colInfo)

{
  bool bVar1;
  _func_18 **pp_Var2;
  short dist;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  
  lVar9 = 0;
  iVar4 = CAMERA_FocusInstanceMoved(camera);
  if ((((camera->always_rotate_flag == 0) && (camera->rotState != 3)) && (1 < colInfo->numCollided))
     && (bVar1 = true, colInfo->line - 1U < 2)) {
    dist = 0x7fff;
    if (((colInfo->flags & 6U) == 6) && (iVar7 = (int)colInfo->lengthList[2], 0x78 < iVar7)) {
      iVar6 = (int)colInfo->lengthList[1];
      iVar5 = iVar7 - iVar6;
      if (0x78 < iVar6) {
        if (iVar5 < 0) {
          iVar5 = iVar6 - iVar7;
        }
        if (iVar5 < 600) {
          CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
          CAMERA_dampgetline(0);
          if (camera->mode != 0xd) {
            return 1;
          }
          iVar4 = ACE_amount;
          if (ACE_amount < 0) {
            iVar4 = -ACE_amount;
          }
          if (10 < iVar4) {
            (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
            return 1;
          }
          return 1;
        }
      }
    }
    iVar7 = 1;
    pp_Var2 = colInfo->tfaceList;
    do {
      if (iVar7 != colInfo->line) {
        if (*(short *)((int)pp_Var2 + 0x36) < 800) {
          bVar1 = false;
          break;
        }
        if (*(short *)((int)pp_Var2 + 0x36) < dist) {
          dist = *(short *)((int)pp_Var2 + 0x36);
        }
      }
      iVar7 = iVar7 + 1;
      pp_Var2 = (_func_18 **)((int)pp_Var2 + 2);
    } while (iVar7 < 5);
    if (bVar1) {
      colInfo->numCollided = 1;
      colInfo->flags = 1 << (colInfo->line & 0x1fU);
      if (colInfo->lenCenterToExtend < 0x321) {
        CAMERA_update_dist_debounced(camera,dist);
      }
      else {
        CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
      }
      goto LAB_800192b4;
    }
    if (colInfo->numCollided == 4) {
      if ((camera->collision_lastPush != 0) && (colInfo->lenCenterToExtend < 400)) {
        colInfo->numCollided = 1;
        if (camera->collision_lastPush == 2) {
          colInfo->flags = 2;
          colInfo->line = 1;
        }
        else {
          colInfo->line = 2;
          colInfo->flags = 4;
        }
      }
      goto LAB_800192b4;
    }
  }
  else {
LAB_800192b4:
    if ((colInfo->numCollided == 4) && ((camera->lock & 1U) == 0)) {
      dist = (camera->targetFocusRotation).z;
      lVar9 = 1;
      camera->collisionTargetFocusDistance = *(short *)&colInfo->lenCenterToExtend;
      (camera->collisionTargetFocusRotation).z = dist;
      goto LAB_8001956c;
    }
  }
  uVar8 = colInfo->flags;
  if ((((uVar8 & 2) == 0) || ((camera->lock & 4U) != 0)) ||
     ((iVar4 == 0 && (camera->collision_lastPush == 1)))) {
    if ((((uVar8 & 4) == 0) || ((camera->lock & 4U) != 0)) ||
       ((iVar4 == 0 && (camera->collision_lastPush == 2)))) {
      if ((((colInfo->flags & 8U) != 0) && ((camera->lock & 2U) == 0)) ||
         (((colInfo->flags & 0x10U) != 0 && ((camera->lock & 2U) == 0)))) {
        CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
        lVar9 = 1;
      }
LAB_8001956c:
      CAMERA_dampgetline(0);
      return lVar9;
    }
    if ((uVar8 & 2) != 0) goto LAB_8001947c;
    camera->collideRotControl = 1;
    camera->collision_lastPush = 1;
    if ((camera->mode != 0xd) || (ACE_amount < 0xb)) {
      dist = CAMERA_GetLineAngle(camera,colInfo,&left_point,2);
      uVar3 = CAMERA_dampgetline(dist);
      iVar4 = ACE_amount;
      if (ACE_amount < 0) {
        iVar4 = -ACE_amount;
      }
      if (iVar4 < 6) {
        if (0x3f < (short)uVar3) {
          dist = (camera->collisionTargetFocusRotation).z + 0x40;
          goto LAB_80019510;
        }
      }
      else {
        if ((int)((uint)uVar3 << 0x10) < 0) {
          return 1;
        }
      }
      dist = (camera->focusRotation).z + 4;
      goto LAB_8001950c;
    }
  }
  else {
    if ((uVar8 & 4) != 0) goto LAB_8001947c;
    camera->collideRotControl = 1;
    camera->collision_lastPush = 2;
    if ((camera->mode != 0xd) || (-0xb < ACE_amount)) {
      dist = CAMERA_GetLineAngle(camera,colInfo,&right_point,1);
      uVar3 = CAMERA_dampgetline(dist);
      iVar4 = ACE_amount;
      if (ACE_amount < 0) {
        iVar4 = -ACE_amount;
      }
      if (5 < iVar4) {
        if ((int)((uint)uVar3 << 0x10) < 1) {
          (camera->collisionTargetFocusRotation).z = uVar3 + (camera->focusRotation).z + -4;
          return 1;
        }
        return 1;
      }
      if ((short)uVar3 < -0x3f) {
        dist = (camera->collisionTargetFocusRotation).z + -0x40;
        goto LAB_80019510;
      }
      dist = (camera->focusRotation).z + -4;
LAB_8001950c:
      dist = uVar3 + dist;
LAB_80019510:
      (camera->collisionTargetFocusRotation).z = dist;
      return 1;
    }
  }
  (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
LAB_8001947c:
  CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_AbsoluteCollision(struct Camera *camera /*$a0*/, struct CameraCollisionInfo *colInfo /*$a1*/)
 // line 3123, offset 0x80019594
	/* begin block 1 */
		// Start line: 3124
		// Start offset: 0x80019594
		// Variables:
	// 		long hit; // $a3
	/* end block 1 */
	// End offset: 0x800196AC
	// End Line: 3193

	/* begin block 2 */
		// Start line: 7563
	/* end block 2 */
	// End Line: 7564

long CAMERA_AbsoluteCollision(Camera *camera,CameraCollisionInfo *colInfo)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  
  if ((gameTrackerX.debugFlags & 0x10000U) != 0) {
    return 0;
  }
  uVar3 = camera->flags;
  (camera->focusRotation).x = (camera->focusRotation).x & 0xfff;
  if ((((((uVar3 & 0x10000) == 0) && ((camera->instance_mode & 0x24000000) == 0)) &&
       ((uVar3 & 0x2000) == 0)) && ((camera->rotState == 0 && (camera->always_rotate_flag == 0))))
     || ((camera->lock & 1U) != 0)) {
    if (*(int *)&camera->forced_movement != 0) {
      lVar2 = CAMERA_ACForcedMovement(camera,colInfo);
      return lVar2;
    }
  }
  else {
    if ((camera->flags & 0x10000U) == 0) {
      camera->collisionTargetFocusDistance = *(short *)&colInfo->lenCenterToExtend;
      return 0;
    }
    if ((colInfo->flags & 0x18U) != 0) {
      sVar1 = *(short *)&colInfo->lenCenterToExtend + -0x96;
      camera->collisionTargetFocusDistance = sVar1;
      if (399 < sVar1) {
        return 0;
      }
      camera->collisionTargetFocusDistance = 400;
      return 0;
    }
  }
  lVar2 = CAMERA_ACNoForcedMovement(camera,colInfo);
  return lVar2;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_update_z_damped(struct Camera *camera /*$a0*/, short current /*$a3*/, short target /*$t0*/)
 // line 3198, offset 0x800196bc
	/* begin block 1 */
		// Start line: 3199
		// Start offset: 0x800196BC
		// Variables:
	// 		static short upvel; // offset 0x56
	// 		static short upaccl; // offset 0x58
	// 		static short upmaxVel; // offset 0x5a
	// 		short current_tmp; // stack offset -16
	/* end block 1 */
	// End offset: 0x80019924
	// End Line: 3243

	/* begin block 2 */
		// Start line: 7723
	/* end block 2 */
	// End Line: 7724

short CAMERA_update_z_damped(Camera *camera,short current,short target)

{
  long lVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short local_10 [4];
  
  iVar3 = (int)current;
  iVar4 = (int)target;
  local_10[0] = current;
  if (iVar4 < iVar3) {
    if (((camera->instance_mode & 0x1038) == 0) ||
       ((camera->real_focuspoint).z < camera->focuspoint_fallz)) {
      iVar3 = (int)current - (int)target;
      if (iVar3 < 0) {
        iVar3 = (int)target - (int)current;
      }
      DAT_800cf16a = (short)(iVar3 << 1);
    }
    else {
      if (iVar3 - iVar4 < 0) {
        DAT_800cf16a = (short)((iVar4 - iVar3) / 6);
      }
      else {
        DAT_800cf16a = (short)((iVar3 - iVar4) / 6);
      }
    }
    goto LAB_800198d8;
  }
  if (iVar3 - iVar4 < 0) {
    if (iVar4 - iVar3 < 5) {
      DAT_800cf166 = 0;
      DAT_800cf168 = 0;
      DAT_800cf16a = 0;
      return current;
    }
  }
  else {
    if (iVar3 - iVar4 < 5) {
      lVar1 = CAMERA_AbsoluteCollision((char)camera,(char)current);
      return (short)lVar1;
    }
  }
  iVar3 = (int)current;
  if ((camera->instance_mode & 0x100) == 0) {
    iVar4 = iVar3 - target;
    sVar2 = (short)((uint)iVar4 >> 0x10);
    if (iVar4 < 0) {
      iVar3 = target - iVar3;
      sVar2 = (short)((uint)iVar3 >> 0x10);
      sVar5 = (short)(iVar3 / 6) + (sVar2 >> 0xf);
    }
    else {
      sVar5 = (short)(iVar4 / 6) + (sVar2 >> 0xf);
    }
    sVar5 = sVar5 - (sVar2 >> 0xf);
LAB_80019870:
    DAT_800cf16a = sVar5;
  }
  else {
    iVar4 = iVar3 - target;
    sVar2 = (short)((uint)iVar4 >> 0x10);
    if (iVar4 < 0) {
      iVar3 = target - iVar3;
      sVar2 = (short)((uint)iVar3 >> 0x10);
      DAT_800cf16a = (short)(iVar3 / 6) + (sVar2 >> 0xf);
    }
    else {
      DAT_800cf16a = (short)(iVar4 / 6) + (sVar2 >> 0xf);
    }
    DAT_800cf16a = DAT_800cf16a - (sVar2 >> 0xf);
    sVar5 = 0x32;
    if (DAT_800cf16a < 0x32) goto LAB_80019870;
  }
  iVar3 = (int)current - (int)target;
  if (iVar3 < 0) {
    iVar3 = (int)target - (int)current;
  }
  if ((iVar3 < DAT_800cf16a) && (DAT_800cf16a = current - target, (int)current - (int)target < 0)) {
    DAT_800cf16a = target - current;
  }
LAB_800198d8:
  CriticalDampValue(1,local_10,target,&DAT_800cf166,&DAT_800cf168,(int)DAT_800cf16a);
  return local_10[0];
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CombatCamDist(struct Camera *camera /*$s0*/)
 // line 3303, offset 0x80019934
	/* begin block 1 */
		// Start line: 3304
		// Start offset: 0x80019934
		// Variables:
	// 		struct DVECTOR xy; // stack offset -48
	// 		struct DVECTOR xy2; // stack offset -40
	// 		struct _SVector position; // stack offset -32
	// 		long z; // stack offset -24
	// 		struct _Instance *instance; // $s1
	/* end block 1 */
	// End offset: 0x80019BE4
	// End Line: 3385

	/* begin block 2 */
		// Start line: 7937
	/* end block 2 */
	// End Line: 7938

void CAMERA_CombatCamDist(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(camera->focusInstance,0x22);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_GenericCameraProcess(struct Camera *camera /*$s0*/)
 // line 3388, offset 0x80019bf8
	/* begin block 1 */
		// Start line: 3389
		// Start offset: 0x80019BF8
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3441
			// Start offset: 0x80019D1C
			// Variables:
		// 		short angle; // $a0
		// 		struct _Rotation test_rot; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80019D7C
		// End Line: 3459

		/* begin block 1.2 */
			// Start line: 3467
			// Start offset: 0x80019D8C
			// Variables:
		// 		struct _Instance *warpInstance; // $v0
		// 		int tmp; // $v0
		/* end block 1.2 */
		// End offset: 0x80019D9C
		// End Line: 3473

		/* begin block 1.3 */
			// Start line: 3505
			// Start offset: 0x80019E4C
			// Variables:
		// 		int mod; // $v1
		/* end block 1.3 */
		// End offset: 0x80019ECC
		// End Line: 3520

		/* begin block 1.4 */
			// Start line: 3528
			// Start offset: 0x80019EE8
			// Variables:
		// 		int dist; // $a3
		/* end block 1.4 */
		// End offset: 0x80019F3C
		// End Line: 3546

		/* begin block 1.5 */
			// Start line: 3560
			// Start offset: 0x80019F7C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x80019F7C
		// End Line: 3560

		/* begin block 1.6 */
			// Start line: 3569
			// Start offset: 0x80019FC0
			// Variables:
		// 		struct _Position target; // stack offset -24
		/* end block 1.6 */
		// End offset: 0x8001A040
		// End Line: 3589
	/* end block 1 */
	// End offset: 0x8001A040
	// End Line: 3592

	/* begin block 2 */
		// Start line: 8108
	/* end block 2 */
	// End Line: 8109

void CAMERA_GenericCameraProcess(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  _Instance *focusInstance;
  _Position _Stack32;
  undefined4 local_18;
  short local_14;
  
  focusInstance = camera->focusInstance;
  if (((camera->flags & 0x10000U) != 0) || ((camera->instance_mode & 0x4000000) != 0)) {
    (camera->rotationVel).z = 0x40;
  }
  if ((camera->instance_mode & 0x2000000) == 0) {
    combat_cam_weight = 0x800;
  }
  CAMERA_SetMaxVel(camera);
  CAMERA_SetFocus(camera,&camera->targetFocusPoint);
  if (((camera->flags & 0x10000U) == 0) && ((camera->instance_mode & 0x4000000) == 0)) {
    CAMERA_UpdateFocusRotationX(camera,focusInstance);
    if (((((camera->mode == 0xd) && (0 < camera->instance_xyvel)) &&
         ((camera->instance_mode & 0x82000400) == 0)) &&
        ((camera->always_rotate_flag == 0 && (camera->rotState != 3)))) &&
       (((camera->instance_mode & 0x2000) == 0 && (gameTrackerX.cheatMode != '\x01')))) {
      CAMERA_CalcRotation((_Rotation *)&local_18,&camera->targetFocusPoint,(_Position *)camera);
                    /* WARNING: Subroutine does not return */
      CAMERA_SignedAngleDifference(local_14,(camera->focusRotation).z);
    }
  }
  else {
    CAMERA_FollowPlayerTilt(camera,focusInstance);
  }
  uVar4 = camera->instance_mode;
  if ((int)uVar4 < 0) {
    focusInstance = RAZIEL_QueryEngagedInstance(0xe);
    if (focusInstance != (_Instance *)0x0) {
      sVar2 = (focusInstance->rotation).z;
      camera->tfaceTilt = 0xf94;
      (camera->rotationVel).z = 0x40;
      camera->smooth = 8;
      camera->always_rotate_flag = 1;
      camera->forced_movement = 0;
      sVar2 = (short)(((uint)(((int)sVar2 & 0xfffU) - 0x401 < 0x7ff) ^ 1) << 0xb);
      (camera->collisionTargetFocusRotation).z = sVar2;
      (camera->targetFocusRotation).z = sVar2;
    }
  }
  else {
    if (((camera->flags & 0x2000U) == 0) && ((uVar4 & 0x20000000) == 0)) {
      if (((camera->flags & 0x10000U) == 0) && ((uVar4 & 0x4000000) == 0)) {
        if (((uVar4 & 0x400) != 0) && ((camera->prev_instance_mode & 0x400) == 0)) {
          iVar5 = (int)(camera->core).rotation.z;
          iVar3 = iVar5;
          if (iVar5 < 0) {
            iVar3 = iVar5 + 0x3ff;
          }
          iVar3 = (iVar5 + (iVar3 >> 10) * -0x400) * 0x10000 >> 0x10;
          if (iVar3 < 0x201) {
            iVar3 = -iVar3;
          }
          else {
            iVar3 = 0x400 - iVar3;
          }
          iVar5 = iVar3;
          if (iVar3 < 0) {
            iVar5 = -iVar3;
          }
          if (0x80 < iVar5) {
            (camera->targetFocusRotation).z = (short)iVar3 + (camera->core).rotation.z & 0xfff;
          }
        }
        CAMERA_FollowGoBehindPlayerWithTimer(camera);
        goto LAB_80019ed4;
      }
    }
    else {
      if ((uVar4 & 0x2000000) != 0) goto LAB_80019ed4;
      (camera->rotationVel).z = 0x40;
    }
    CAMERA_FollowGoBehindPlayer(camera);
  }
LAB_80019ed4:
  if ((camera->flags & 0x1800U) != 0) {
    if ((int)camera->instance_mode < 0) {
      camera->collisionTargetFocusDistance = 2000;
    }
    CAMERA_UpdateFocusDistance(camera);
    CAMERA_UpdateFocusTilt(camera);
    CAMERA_UpdateFocusRotate(camera);
    if ((camera->flags & 0x1800U) == 0) {
      local_18 = *(undefined4 *)&camera->targetFocusPoint;
      local_14 = (camera->targetFocusPoint).z;
      if ((camera->flags & 0x10000U) == 0) {
        local_14 = (camera->focusPoint).z;
      }
      CriticalDampPosition
                (1,&camera->focusPoint,(_Position *)&local_18,&camera->focusPointVel,
                 &camera->focusPointAccl,(int)camera->maxVel);
      if ((camera->flags & 0x10000U) == 0) {
        sVar2 = CAMERA_update_z_damped(camera,(camera->focusPoint).z,(camera->targetFocusPoint).z);
        (camera->focusPoint).z = sVar2;
      }
    }
    else {
      sVar2 = (camera->targetFocusPoint).y;
      sVar1 = (camera->targetFocusPoint).z;
      (camera->focusPoint).x = (camera->targetFocusPoint).x;
      (camera->focusPoint).y = sVar2;
      (camera->focusPoint).z = sVar1;
      camera->focusDistance = camera->targetFocusDistance;
      if ((camera->flags & 0x1000U) != 0) {
        CAMERA_SetZRotation(camera,camera->teleportZRot);
      }
    }
    CAMERA_CalcFollowPosition(camera,&camera->focusRotation);
    CAMERA_CalculateLead(camera);
    CAMERA_UpdateFocusRoll(camera);
    return;
  }
  if ((camera->instance_mode & 0x2000000) == 0) {
    combat_cam_distance = camera->targetFocusDistance;
  }
  else {
    CAMERA_CombatCamDist(camera);
  }
                    /* WARNING: Subroutine does not return */
  CAMERA_CalcPosition(&_Stack32,&camera->focusPoint,&camera->focusRotation,combat_cam_distance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CinematicProcess(struct Camera *camera /*$s2*/)
 // line 3600, offset 0x8001a074
	/* begin block 1 */
		// Start line: 3601
		// Start offset: 0x8001A074
		// Variables:
	// 		struct _SVector *camPos; // $s0
	// 		struct _SVector *camTarget; // $s3
	// 		struct MultiSpline *posSpline; // $s4
	// 		struct MultiSpline *targetSpline; // $s1

		/* begin block 1.1 */
			// Start line: 3624
			// Start offset: 0x8001A0EC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001A0EC
		// End Line: 3624

		/* begin block 1.2 */
			// Start line: 3628
			// Start offset: 0x8001A108
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _SVector *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001A120
		// End Line: 3628

		/* begin block 1.3 */
			// Start line: 3633
			// Start offset: 0x8001A130
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x8001A130
		// End Line: 3633

		/* begin block 1.4 */
			// Start line: 3641
			// Start offset: 0x8001A178
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a2
		// 		struct _Position *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x8001A178
		// End Line: 3641

		/* begin block 1.5 */
			// Start line: 3654
			// Start offset: 0x8001A1D8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x8001A1D8
		// End Line: 3654

		/* begin block 1.6 */
			// Start line: 3702
			// Start offset: 0x8001A42C
		/* end block 1.6 */
		// End offset: 0x8001A528
		// End Line: 3719

		/* begin block 1.7 */
			// Start line: 3722
			// Start offset: 0x8001A528
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.7 */
		// End offset: 0x8001A528
		// End Line: 3722
	/* end block 1 */
	// End offset: 0x8001A528
	// End Line: 3722

	/* begin block 2 */
		// Start line: 8553
	/* end block 2 */
	// End Line: 8554

void CAMERA_CinematicProcess(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  _SVector *pos;
  MultiSpline *pMVar6;
  _SVector *pos_00;
  MultiSpline *pMVar7;
  
  pos = (_SVector *)0x0;
  pMVar7 = (camera->data).Cinematic.posSpline;
  pMVar6 = (camera->data).Cinematic.targetSpline;
  pos_00 = (_SVector *)0x0;
  if (camera->posState == 0) {
    if (pMVar6 == (MultiSpline *)0x0) {
      CAMERA_SetFocus(camera,&camera->targetFocusPoint);
    }
    if (pMVar7 != (MultiSpline *)0x0) {
      pos = SplineGetNextPointDC(pMVar7->positional,&pMVar7->curPositional);
      if (pos != (_SVector *)0x0) {
        if ((camera->data).Cinematic.splinePointAhead == 0) {
          sVar1 = pos->y;
          sVar2 = pos->z;
          (camera->core).position.x = pos->x;
          (camera->core).position.y = sVar1;
          (camera->core).position.z = sVar2;
        }
        else {
          sVar1 = (camera->data).Cinematic.lastSplinePos.y;
          sVar2 = (camera->data).Cinematic.lastSplinePos.z;
          (camera->core).position.x = (camera->data).Cinematic.lastSplinePos.x;
          (camera->core).position.y = sVar1;
          (camera->core).position.z = sVar2;
        }
      }
      if ((camera->data).Cinematic.splinePointAhead == 0) {
        if (pMVar6 == (MultiSpline *)0x0) {
          CAMERA_SetMaxVel(camera);
          CriticalDampPosition
                    (1,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
                     &camera->focusPointAccl,((int)camera->maxVel << 0x11) >> 0x10);
        }
        else {
          pos_00 = SplineGetNextPointDC(pMVar6->positional,&pMVar6->curPositional);
          if (pos_00 != (_SVector *)0x0) {
            sVar1 = pos_00->y;
            sVar2 = pos_00->z;
            (camera->targetFocusPoint).x = pos_00->x;
            (camera->targetFocusPoint).y = sVar1;
            (camera->targetFocusPoint).z = sVar2;
            CAMERA_SetTarget(camera,(_Position *)pos_00);
          }
        }
      }
      else {
        CAMERA_SetTarget(camera,(_Position *)pos);
        sVar1 = pos->y;
        sVar2 = pos->z;
        (camera->data).Cinematic.lastSplinePos.x = pos->x;
        (camera->data).Cinematic.lastSplinePos.y = sVar1;
        (camera->data).Cinematic.lastSplinePos.z = sVar2;
      }
      sVar1 = (camera->core).position.y;
      sVar2 = (camera->core).position.z;
      (camera->targetPos).x = (camera->core).position.x;
      (camera->targetPos).y = sVar1;
      (camera->targetPos).z = sVar2;
      if ((pMVar7 != (MultiSpline *)0x0) &&
         (((camera->data).Cinematic.targetSpline != (MultiSpline *)0x0 ||
          ((camera->data).Cinematic.splinePointAhead != 0)))) {
        CAMERA_SetMaxVel(camera);
        CriticalDampPosition
                  (1,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
                   &camera->focusPointAccl,((int)camera->maxVel << 0x11) >> 0x10);
      }
    }
    CAMERA_CalcRotation(&camera->focusRotation,&camera->focusPoint,(_Position *)camera);
    if (pos == (_SVector *)0x0 && pos_00 == (_SVector *)0x0) {
      (camera->data).Cinematic.cinema_done = 1;
    }
    goto LAB_8001a530;
  }
  CriticalDampPosition
            (4,(_Position *)camera,&camera->targetPos,&camera->positionVel,&camera->positionAccl,
             (int)-camera->smooth);
  if ((camera->data).Cinematic.targetSpline == (MultiSpline *)0x0) {
    CAMERA_SetFocus(camera,&camera->targetFocusPoint);
    CriticalDampPosition
              (4,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
               &camera->focusPointAccl,(int)-camera->smooth);
    CAMERA_SetTarget(camera,&camera->focusPoint);
    iVar5 = (int)(camera->core).position.x;
    iVar4 = (int)(camera->targetPos).x;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->core).position.z;
    iVar4 = (int)(camera->targetPos).z;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
  }
  else {
    CriticalDampPosition
              (4,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
               &camera->focusPointAccl,(int)-camera->smooth);
    CAMERA_SetTarget(camera,&camera->focusPoint);
    iVar5 = (int)(camera->core).position.x;
    iVar4 = (int)(camera->targetPos).x;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->core).position.z;
    iVar4 = (int)(camera->targetPos).z;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->focusPoint).x;
    iVar4 = (int)(camera->targetFocusPoint).x;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->focusPoint).y;
    iVar4 = (int)(camera->targetFocusPoint).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a530;
    iVar5 = (int)(camera->focusPoint).z;
    iVar4 = (int)(camera->targetFocusPoint).z;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
  }
  if (iVar3 < 9) {
    camera->posState = 0;
  }
LAB_8001a530:
  CAMERA_CalcRotation(&camera->targetRotation,&camera->focusPoint,(_Position *)camera);
  sVar1 = (camera->targetRotation).y;
  sVar2 = (camera->targetRotation).z;
  (camera->core).rotation.x = (camera->targetRotation).x;
  (camera->core).rotation.y = sVar1;
  (camera->core).rotation.z = sVar2;
  sVar1 = (camera->core).rotation.z;
  camera->actual_x_rot = (camera->core).rotation.x;
  camera->lagZ = sVar1;
  CAMERA_UpdateFocusRoll(camera);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_GetDistSq(struct _SVector *point1 /*$a0*/, struct _SVector *point2 /*$a1*/)
 // line 3736, offset 0x8001a590
	/* begin block 1 */
		// Start line: 3737
		// Start offset: 0x8001A590
		// Variables:
	// 		struct _Vector d; // stack offset -16
	/* end block 1 */
	// End offset: 0x8001A590
	// End Line: 3737

	/* begin block 2 */
		// Start line: 8838
	/* end block 2 */
	// End Line: 8839

	/* begin block 3 */
		// Start line: 8842
	/* end block 3 */
	// End Line: 8843

int CAMERA_GetDistSq(_SVector *point1,_SVector *point2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  
  setCopReg(2,in_t1,(int)point1->x - (int)point2->x);
  setCopReg(2,in_t2,(int)point1->y - (int)point2->y);
  setCopReg(2,in_t3,(int)point1->z - (int)point2->z);
  copFunction(2,0xa00428);
  iVar1 = getCopReg(2,0x19);
  iVar2 = getCopReg(2,0x1a);
  iVar3 = getCopReg(2,0x1b);
  return iVar1 + iVar2 + iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_NearestPointOnLineVec(struct _SVector *linePoint /*$s2*/, struct _SVector *start /*$s1*/, struct _SVector *line /*$s0*/, struct _Position *point /*$a3*/)
 // line 3751, offset 0x8001a60c
	/* begin block 1 */
		// Start line: 3752
		// Start offset: 0x8001A60C
		// Variables:
	// 		struct MATRIX nmat; // stack offset -64
	// 		struct _Vector dpv; // stack offset -32
	// 		long t; // $a0
	/* end block 1 */
	// End offset: 0x8001A6C0
	// End Line: 3770

	/* begin block 2 */
		// Start line: 8872
	/* end block 2 */
	// End Line: 8873

void CAMERA_NearestPointOnLineVec
               (_SVector *linePoint,_SVector *start,_SVector *line,_Position *point)

{
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  undefined local_20 [16];
  
  local_40 = line->x;
  local_3e = line->y;
  local_3c = line->z;
  local_3a = start->x;
  local_38 = start->y;
  local_36 = start->z;
  local_34 = point->x;
  local_32 = point->y;
  local_30 = point->z;
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(&local_40,line,local_20);
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_CheckPoint(int linePoint /*$a0*/, int linept1 /*$a1*/, int linept2 /*$a2*/)
 // line 3776, offset 0x8001a738
	/* begin block 1 */
		// Start line: 8935
	/* end block 1 */
	// End Line: 8936

	/* begin block 2 */
		// Start line: 8936
	/* end block 2 */
	// End Line: 8937

int CAMERA_CheckPoint(int linePoint,int linept1,int linept2)

{
  int iVar1;
  
  if ((linept1 < linePoint + -0x14) && (linept2 < linePoint + -0x14)) {
    return 1;
  }
  if ((linept1 <= linePoint + 0x14) || (iVar1 = 1, linept2 <= linePoint + 0x14)) {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_CheckIfPointOnLine(struct _SVector *linePoint /*$s0*/, struct _SVector *linept1 /*$s1*/, struct _SVector *linept2 /*$s2*/)
 // line 3782, offset 0x8001a77c
	/* begin block 1 */
		// Start line: 8947
	/* end block 1 */
	// End Line: 8948

int CAMERA_CheckIfPointOnLine(_SVector *linePoint,_SVector *linept1,_SVector *linept2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = CAMERA_CheckPoint((int)linePoint->x,(int)linept1->x,(int)linept2->x);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = CAMERA_CheckPoint((int)linePoint->y,(int)linept1->y,(int)linept2->y);
    if (iVar1 == 0) {
      iVar1 = CAMERA_CheckPoint((int)linePoint->z,(int)linept1->z,(int)linept2->z);
      uVar2 = (uint)(iVar1 == 0);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_FindLinePoint(struct _Position *point /*$s0*/, struct _SVector *linept1 /*$s5*/, struct _SVector *linept2 /*$s6*/, int target_dist_sq /*$s1*/, struct _SVector *results /*stack 16*/)
 // line 3790, offset 0x8001a80c
	/* begin block 1 */
		// Start line: 3791
		// Start offset: 0x8001A80C
		// Variables:
	// 		struct _SVector outPoint; // stack offset -56
	// 		struct _SVector line; // stack offset -48
	// 		int calc; // $s1
	// 		int hits; // $s4

		/* begin block 1.1 */
			// Start line: 3791
			// Start offset: 0x8001A80C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t1
		// 		short _z1; // $t2
		// 		struct _SVector *_v; // $s2
		/* end block 1.1 */
		// End offset: 0x8001A80C
		// End Line: 3791

		/* begin block 1.2 */
			// Start line: 3805
			// Start offset: 0x8001A8A0
			// Variables:
		// 		struct _SVector linePoint; // stack offset -40
		// 		int n; // $s3

			/* begin block 1.2.1 */
				// Start line: 3819
				// Start offset: 0x8001A954
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8001A954
			// End Line: 3819
		/* end block 1.2 */
		// End offset: 0x8001A9A8
		// End Line: 3825
	/* end block 1 */
	// End offset: 0x8001A9A8
	// End Line: 3827

	/* begin block 2 */
		// Start line: 8963
	/* end block 2 */
	// End Line: 8964

int CAMERA_FindLinePoint
              (_Position *point,_SVector *linept1,_SVector *linept2,int target_dist_sq,
              _SVector *results)

{
  int iVar1;
  _SVector local_38;
  _SVector local_30 [2];
  
  local_30[0].x = linept2->x - linept1->x;
  local_30[0].y = linept2->y - linept1->y;
  local_30[0].z = linept2->z - linept1->z;
  CAMERA_NearestPointOnLineVec(&local_38,linept1,local_30,point);
  iVar1 = CAMERA_GetDistSq(&local_38,(_SVector *)point);
  if (0 < target_dist_sq - iVar1) {
                    /* WARNING: Subroutine does not return */
    MATH3D_FastSqrt0(target_dist_sq - iVar1);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineGetNearestPoint2(struct Camera *camera /*stack 0*/, struct Spline *spline /*stack 4*/, struct _SVector *point /*stack 8*/, int *currkey /*stack 12*/, struct _SVector *ret_dpoint /*stack 16*/)
 // line 3830, offset 0x8001a9d0
	/* begin block 1 */
		// Start line: 3831
		// Start offset: 0x8001A9D0
		// Variables:
	// 		struct SplineKey *key; // stack offset -56
	// 		int n; // $s2
	// 		int target_dist_sq; // stack offset -52
	// 		long dist; // $fp

		/* begin block 1.1 */
			// Start line: 3831
			// Start offset: 0x8001A9D0
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001A9D0
		// End Line: 3831

		/* begin block 1.2 */
			// Start line: 3850
			// Start offset: 0x8001AA84
			// Variables:
		// 		struct _SVector point1; // stack offset -88
		// 		struct _SVector point2; // stack offset -80
		// 		struct _SVector results[2]; // stack offset -72
		// 		int i; // $s1
		// 		int hits; // $s3

			/* begin block 1.2.1 */
				// Start line: 3854
				// Start offset: 0x8001AAA0
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a2
			// 		short _z1; // $v0
			// 		struct _SVector *_v0; // $s7
			// 		struct vecS *_v1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8001AAA0
			// End Line: 3854

			/* begin block 1.2.2 */
				// Start line: 3854
				// Start offset: 0x8001AAA0
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $a2
			// 		short _z1; // $v1
			// 		struct _SVector *_v0; // $s6
			// 		struct vecS *_v1; // $v1
			/* end block 1.2.2 */
			// End offset: 0x8001AAA0
			// End Line: 3854

			/* begin block 1.2.3 */
				// Start line: 3861
				// Start offset: 0x8001AB18
				// Variables:
			// 		int tmpdist; // $a1

				/* begin block 1.2.3.1 */
					// Start line: 3872
					// Start offset: 0x8001AB34
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.2.3.1 */
				// End offset: 0x8001AB34
				// End Line: 3872
			/* end block 1.2.3 */
			// End offset: 0x8001AB58
			// End Line: 3876
		/* end block 1.2 */
		// End offset: 0x8001AB68
		// End Line: 3884
	/* end block 1 */
	// End offset: 0x8001AB88
	// End Line: 3885

	/* begin block 2 */
		// Start line: 9080
	/* end block 2 */
	// End Line: 9081

void CAMERA_SplineGetNearestPoint2
               (Camera *camera,Spline *spline,_SVector *point,int *currkey,_SVector *ret_dpoint)

{
  short sVar1;
  short sVar2;
  SplineKey *pSVar3;
  int iVar4;
  int iVar5;
  SplineKey *pSVar6;
  _SVector *point2;
  int iVar7;
  int iVar8;
  int iVar9;
  _SVector local_58;
  _SVector local_50;
  _SVector a_Stack72 [2];
  SplineKey *local_38;
  int local_34;
  _SVector *local_30;
  
  pSVar6 = spline->key;
  sVar1 = (camera->core).position.y;
  sVar2 = (camera->core).position.z;
  ret_dpoint->x = (camera->core).position.x;
  ret_dpoint->y = sVar1;
  ret_dpoint->z = sVar2;
  sVar1 = spline->numkeys;
  local_34 = (int)camera->targetFocusDistance * (int)camera->targetFocusDistance;
  iVar9 = 0x7fffffff;
  iVar8 = 0;
  if (0 < (int)spline->numkeys + -1) {
    local_30 = a_Stack72;
    local_38 = pSVar6;
    do {
      if ((-1 < iVar8) && (iVar8 <= (int)sVar1 + -2)) {
        local_58.x = (pSVar6->point).x;
        local_58.y = (pSVar6->point).y;
        local_58.z = (pSVar6->point).z;
        iVar7 = 0;
        pSVar3 = local_38 + iVar8 + 1;
        local_50.x = (pSVar3->point).x;
        local_50.y = (pSVar3->point).y;
        local_50.z = (pSVar3->point).z;
        iVar4 = CAMERA_FindLinePoint
                          (&camera->targetFocusPoint,&local_58,&local_50,local_34,local_30);
        point2 = local_30;
        if (0 < iVar4) {
          do {
            iVar5 = CAMERA_GetDistSq(point,point2);
            if (iVar5 < iVar9) {
              sVar1 = point2->y;
              sVar2 = point2->z;
              ret_dpoint->x = point2->x;
              ret_dpoint->y = sVar1;
              ret_dpoint->z = sVar2;
              *currkey = iVar8;
              iVar9 = iVar5;
            }
            iVar7 = iVar7 + 1;
            point2 = point2 + 1;
          } while (iVar7 < iVar4);
        }
      }
      iVar8 = iVar8 + 1;
      sVar1 = spline->numkeys;
      pSVar6 = pSVar6 + 1;
    } while (iVar8 < (int)spline->numkeys + -1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineGetNearestPoint(struct Spline *spline /*$s4*/, struct _SVector *point /*$s6*/, int *currkey /*$s7*/, struct _SVector *ret_dpoint /*stack 12*/)
 // line 3887, offset 0x8001abb8
	/* begin block 1 */
		// Start line: 3888
		// Start offset: 0x8001ABB8
		// Variables:
	// 		struct _SVector dpoint; // stack offset -96
	// 		struct _SVector dpoint2; // stack offset -88
	// 		struct _SVector dpoint3; // stack offset -80
	// 		struct _SVector point0; // stack offset -72
	// 		struct _SVector point1; // stack offset -64
	// 		struct _SVector point2; // stack offset -56
	// 		struct _SVector point3; // stack offset -48
	// 		int current_keyframe; // $s0
	// 		int dist; // $fp
	// 		int ret; // $s5
	// 		int ret2; // $s4
	// 		int ret3; // $s0
	// 		struct SplineKey *key; // $s1
	// 		int circular_spline; // $s2
	// 		int prev_key; // $s2
	// 		int next_key; // $s3

		/* begin block 1.1 */
			// Start line: 3913
			// Start offset: 0x8001ACE4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $a3
		/* end block 1.1 */
		// End offset: 0x8001ACE4
		// End Line: 3913

		/* begin block 1.2 */
			// Start line: 3913
			// Start offset: 0x8001ACE4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.2 */
		// End offset: 0x8001ACE4
		// End Line: 3913

		/* begin block 1.3 */
			// Start line: 3928
			// Start offset: 0x8001ADAC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.3 */
		// End offset: 0x8001ADAC
		// End Line: 3928

		/* begin block 1.4 */
			// Start line: 3941
			// Start offset: 0x8001AE0C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $v1
		/* end block 1.4 */
		// End offset: 0x8001AE0C
		// End Line: 3941
	/* end block 1 */
	// End offset: 0x8001AF20
	// End Line: 3967

	/* begin block 2 */
		// Start line: 9273
	/* end block 2 */
	// End Line: 9274

void CAMERA_SplineGetNearestPoint(Spline *spline,_SVector *point,int *currkey,_SVector *ret_dpoint)

{
  int iVar1;
  SplineKey *pSVar2;
  int iVar3;
  SplineKey *pSVar4;
  uint auStack96 [8];
  short sStack64;
  short sStack62;
  short sStack60;
  short sStack56;
  short sStack54;
  short sStack52;
  
  pSVar4 = spline->key;
  iVar1 = (int)spline->numkeys + -2;
  iVar3 = *currkey;
  if (iVar1 < *currkey) {
    *currkey = iVar1;
    iVar3 = iVar1;
  }
  pSVar2 = pSVar4 + iVar3;
  sStack64 = (pSVar2->point).x;
  sStack62 = (pSVar2->point).y;
  sStack60 = (pSVar2->point).z;
  pSVar4 = pSVar4 + iVar3 + 1;
  sStack56 = (pSVar4->point).x;
  sStack54 = (pSVar4->point).y;
  sStack52 = (pSVar4->point).z;
                    /* WARNING: Subroutine does not return */
  COLLIDE_NearestPointOnLine_S(auStack96,(uint *)&sStack64,(uint *)&sStack56,(uint *)point);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineHelpMove(struct Camera *camera /*$s1*/)
 // line 3973, offset 0x8001af50
	/* begin block 1 */
		// Start line: 3974
		// Start offset: 0x8001AF50
		// Variables:
	// 		struct _SVector camPos; // stack offset -48
	// 		struct _Position pos; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Instance *focusInstance; // $s3
	// 		struct MultiSpline *posSpline; // $s2
	/* end block 1 */
	// End offset: 0x8001B0A8
	// End Line: 4018

	/* begin block 2 */
		// Start line: 9458
	/* end block 2 */
	// End Line: 9459

void CAMERA_SplineHelpMove(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_AngleDifference(splinecam_helprot.z,(camera->targetFocusRotation).z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineProcess(struct Camera *camera /*$s1*/)
 // line 4020, offset 0x8001b0c4
	/* begin block 1 */
		// Start line: 4021
		// Start offset: 0x8001B0C4
		// Variables:
	// 		struct _SVector camPos; // stack offset -48
	// 		struct _SVector sv; // stack offset -40
	// 		short targetFocusDistance; // $s4
	// 		struct MultiSpline *posSpline; // $s3
	// 		short smooth; // $s0
	// 		short dist_smooth; // $s2
	// 		static short hold_flag; // offset 0x5c
	// 		struct _Rotation targetFocusRotation; // stack offset -32

		/* begin block 1.1 */
			// Start line: 4106
			// Start offset: 0x8001B210
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a1
		// 		short _z0; // $a2
		// 		short _x1; // $v1
		// 		short _y1; // $v1
		// 		short _z1; // $v0
		// 		struct _SVector *_v; // $a0
		// 		struct _SVector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001B210
		// End Line: 4106
	/* end block 1 */
	// End offset: 0x8001B3F8
	// End Line: 4169

	/* begin block 2 */
		// Start line: 9571
	/* end block 2 */
	// End Line: 9572

void CAMERA_SplineProcess(Camera *camera)

{
  MultiSpline *pMVar1;
  _Rotation local_20;
  
  pMVar1 = (camera->data).Cinematic.posSpline;
  local_20.x = (camera->targetFocusRotation).x;
  local_20.y = 0;
  local_20.z = (camera->targetFocusRotation).z;
  CAMERA_SetFocus(camera,&camera->targetFocusPoint);
  if (pMVar1 != (MultiSpline *)0x0) {
                    /* WARNING: Subroutine does not return */
    CAMERA_CalcPosition(&camera->targetPos,&camera->targetFocusPoint,&local_20,
                        camera->targetFocusDistance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ShakeCamera(struct Camera *camera /*$a2*/)
 // line 4193, offset 0x8001b418
	/* begin block 1 */
		// Start line: 9936
	/* end block 1 */
	// End Line: 9937

void CAMERA_ShakeCamera(Camera *camera)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if (0 < camera->shake) {
    uVar1 = camera->shakeFrame;
    (camera->core).position.x =
         (camera->core).position.x +
         (short)((int)(&camera_shakeOffset)[(uint)(ushort)camera->shakeFrame & 0xf].x *
                 (int)camera->shakeScale >> 0xc);
    uVar2 = camera->shakeFrame;
    (camera->core).position.y =
         (camera->core).position.y +
         (short)((int)(&camera_shakeOffset)[(uint)uVar1 & 0xf].y * (int)camera->shakeScale >> 0xc);
    (camera->core).position.z =
         (camera->core).position.z +
         (short)((int)(&camera_shakeOffset)[(uint)uVar2 & 0xf].z * (int)camera->shakeScale >> 0xc);
    iVar3 = camera->shake - gameTrackerX.timeMult;
    camera->shake = iVar3;
    if (iVar3 < 0) {
      camera->shake = 0;
    }
    camera->shakeFrame = camera->shakeFrame + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Process(struct Camera *camera /*$s0*/)
 // line 4212, offset 0x8001b504
	/* begin block 1 */
		// Start line: 4213
		// Start offset: 0x8001B504
		// Variables:
	// 		struct _Instance *focusInstance; // $a1

		/* begin block 1.1 */
			// Start line: 4272
			// Start offset: 0x8001B5D8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // $v0
		// 		struct _Position *_v0; // $a0
		// 		struct _Position *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x8001B5D8
		// End Line: 4272
	/* end block 1 */
	// End offset: 0x8001B740
	// End Line: 4375

	/* begin block 2 */
		// Start line: 9978
	/* end block 2 */
	// End Line: 9979

void CAMERA_Process(Camera *camera)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  _Instance *p_Var8;
  undefined4 uVar9;
  
  p_Var8 = camera->focusInstance;
  camera->focuspoint_fallz =
       camera->focuspoint_fallz - ((camera->newFocusInstancePos).z - (p_Var8->oldPos).z);
  sVar1 = (camera->newFocusInstancePos).z;
  *(undefined4 *)&camera->oldFocusInstancePos = *(undefined4 *)&camera->newFocusInstancePos;
  (camera->oldFocusInstancePos).z = sVar1;
  sVar1 = (p_Var8->position).z;
  *(undefined4 *)&camera->newFocusInstancePos = *(undefined4 *)&p_Var8->position;
  (camera->newFocusInstancePos).z = sVar1;
  uVar9 = *(undefined4 *)&(camera->newFocusInstanceRot).z;
  *(undefined4 *)&camera->oldFocusInstanceRot = *(undefined4 *)&camera->newFocusInstanceRot;
  *(undefined4 *)&(camera->oldFocusInstanceRot).z = uVar9;
  uVar9 = *(undefined4 *)&(p_Var8->rotation).z;
  *(undefined4 *)&camera->newFocusInstanceRot = *(undefined4 *)&p_Var8->rotation;
  *(undefined4 *)&(camera->newFocusInstanceRot).z = uVar9;
  if ((*(int *)&camera->signalPos == *(int *)&(camera->core).position) &&
     ((camera->signalPos).z == (camera->core).position.z)) {
    camera_still = 1;
  }
  else {
    camera_still = 0;
  }
  sVar1 = (camera->core).position.z;
  *(undefined4 *)&camera->signalPos = *(undefined4 *)&(camera->core).position;
  (camera->signalPos).z = sVar1;
  camera->x_rot_change = 0;
  camera->prev_instance_mode = camera->instance_mode;
  uVar5 = CAMERA_QueryMode(camera);
  camera->instance_mode = uVar5;
  sVar1 = (camera->newFocusInstancePos).y;
  sVar2 = (camera->newFocusInstancePos).z;
  sVar3 = (camera->oldFocusInstancePos).y;
  sVar4 = (camera->oldFocusInstancePos).z;
  (camera->focusInstanceVelVec).x =
       (camera->newFocusInstancePos).x - (camera->oldFocusInstancePos).x;
  (camera->focusInstanceVelVec).y = sVar1 - sVar3;
  (camera->focusInstanceVelVec).z = sVar2 - sVar4;
  iVar6 = (int)(camera->focusInstanceVelVec).x;
  iVar7 = (int)(camera->focusInstanceVelVec).y;
  camera->instance_prev_xyvel = camera->instance_xyvel;
                    /* WARNING: Subroutine does not return */
  MATH3D_FastSqrt0(iVar6 * iVar6 + iVar7 * iVar7);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CenterCamera(struct Camera *camera /*$s1*/)
 // line 4397, offset 0x8001b750
	/* begin block 1 */
		// Start line: 4398
		// Start offset: 0x8001B750

		/* begin block 1.1 */
			// Start line: 4402
			// Start offset: 0x8001B778
			// Variables:
		// 		int tmp1; // $s0
		// 		int tmp2; // $v0
		/* end block 1.1 */
		// End offset: 0x8001B7E4
		// End Line: 4406
	/* end block 1 */
	// End offset: 0x8001B810
	// End Line: 4413

	/* begin block 2 */
		// Start line: 10359
	/* end block 2 */
	// End Line: 10360

void CAMERA_CenterCamera(Camera *camera)

{
  short sVar1;
  
  if ((camera->instance_mode & 0x2000000) != 0) {
                    /* WARNING: Subroutine does not return */
    CAMERA_AngleDifference
              ((camera->focusRotation).z,
               (short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x400) * 0x10000 >> 0x10
                      ));
  }
  sVar1 = (camera->focusInstance->rotation).z;
  (camera->focusRotAccl).z = 0;
  (camera->focusRotVel).z = 0;
  CenterFlag = sVar1 + 0x800U & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookRot(struct Camera *camera /*$a0*/, int x_rotation /*$a1*/, int z_rotation /*$a2*/)
 // line 4429, offset 0x8001b838
	/* begin block 1 */
		// Start line: 8853
	/* end block 1 */
	// End Line: 8854

	/* begin block 2 */
		// Start line: 10412
	/* end block 2 */
	// End Line: 10413

void CAMERA_SetLookRot(Camera *camera,int x_rotation,int z_rotation)

{
  (camera->lookRot).x = (short)x_rotation;
  (camera->lookRot).z = (short)z_rotation;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_StartLookaroundMode(struct Camera *camera /*$s0*/)
 // line 4435, offset 0x8001b844
	/* begin block 1 */
		// Start line: 10423
	/* end block 1 */
	// End Line: 10424

void CAMERA_StartLookaroundMode(Camera *camera)

{
  Camera_lookHeight = 0x200;
  Camera_lookDist = 0x28a;
                    /* WARNING: Subroutine does not return */
  CAMERA_SaveMode(camera,(int)camera->mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_StartSwimThrowMode(struct Camera *camera /*$s0*/)
 // line 4453, offset 0x8001b8d4
	/* begin block 1 */
		// Start line: 10469
	/* end block 1 */
	// End Line: 10470

void CAMERA_StartSwimThrowMode(Camera *camera)

{
  CameraLookStickyFlag = 1;
  CAMERA_StartLookaroundMode(camera);
  PLAYER_SetLookAround(camera->focusInstance);
  camera->lookTimer = 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_EndSwimThrowMode(struct Camera *camera /*$a0*/)
 // line 4461, offset 0x8001b914
	/* begin block 1 */
		// Start line: 10486
	/* end block 1 */
	// End Line: 10487

void CAMERA_EndSwimThrowMode(Camera *camera)

{
  CameraLookStickyFlag = 0;
  CAMERA_EndLook(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ForceEndLookaroundMode(struct Camera *camera /*$s0*/)
 // line 4467, offset 0x8001b938
	/* begin block 1 */
		// Start line: 10498
	/* end block 1 */
	// End Line: 10499

void CAMERA_ForceEndLookaroundMode(Camera *camera)

{
  CameraLookStickyFlag = 0;
  CAMERA_EndLook(camera);
  camera->flags = camera->flags & 0xfffdffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Control(struct Camera *camera /*$s0*/, struct _Instance *playerInstance /*$s5*/)
 // line 4476, offset 0x8001b974
	/* begin block 1 */
		// Start line: 4477
		// Start offset: 0x8001B974
		// Variables:
	// 		long *controlCommand; // $s2
	// 		int lookmode; // $s1
	// 		struct _Instance *focusInstance; // $s4
	/* end block 1 */
	// End offset: 0x8001BEA0
	// End Line: 4711

	/* begin block 2 */
		// Start line: 10516
	/* end block 2 */
	// End Line: 10517

void CAMERA_Control(Camera *camera,_Instance *playerInstance)

{
  bool bVar1;
  ulong uVar2;
  short sVar3;
  long lVar4;
  ushort uVar5;
  _Instance *instance;
  
  instance = camera->focusInstance;
  if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
    bVar1 = true;
    if (CameraLookStickyFlag == 0) {
      bVar1 = (gameTrackerX.controlCommand[0][0] & 0xc00U) == 0xc00;
    }
    camera->last_forced_movement = camera->forced_movement;
    if (((camera->instance_xyvel != 0) || (camera->forced_movement != 1)) ||
       ((camera->instance_mode & 0x2000000) != 0)) {
      camera->forced_movement = 0;
    }
    sVar3 = camera->mode;
    if ((sVar3 != 8) && (-1 < (int)camera->instance_mode)) {
      if (CenterFlag != -1) {
        if ((camera->instance_mode & 0x2000000) == 0) {
          camera->forced_movement = 1;
        }
                    /* WARNING: Subroutine does not return */
        CriticalDampAngle(1,&(camera->focusRotation).z,CenterFlag,&(camera->focusRotVel).z,
                          &(camera->focusRotAccl).z,0x90);
      }
      if ((gameTrackerX.cheatMode != '\x01') || ((gameTrackerX.controlCommand[0][0] & 0xfU) == 0)) {
        if ((((camera->lock & 4U) == 0) && ((camera->flags & 0x10000U) == 0)) &&
           (((((sVar3 == 0 || (sVar3 == 0xc)) || (sVar3 == 4)) || (sVar3 == 0xd)) &&
            ((playerInstance->flags & 0x100U) == 0)))) {
          if (((gameTrackerX.controlCommand[0][0] & 0x400U) == 0) || (bVar1)) {
            if (((uint)(ushort)camera->leftTimer - 1 < 3) && (!bVar1)) {
              CAMERA_CenterCamera(camera);
            }
            camera->leftTimer = 0;
          }
          else {
            sVar3 = camera->leftTimer + 1;
            camera->leftTimer = sVar3;
            if (2 < sVar3) {
              camera->rotDirection = -1;
              uVar5 = (camera->focusRotation).z - (short)((gameTrackerX.timeMult << 5) >> 0xc) &
                      0xfff;
              (camera->focusRotation).z = uVar5;
              uVar2 = gameTrackerX.frameCount;
              camera->forced_movement = 1;
              (camera->data).Follow.stopTimer = -0x1a5e0000;
              (camera->focusRotation).z = uVar5;
              (camera->collisionTargetFocusRotation).z = uVar5;
              (camera->targetFocusRotation).z = uVar5;
              camera->lastModTime = uVar2;
            }
          }
          if (((gameTrackerX.controlCommand[0][0] & 0x800U) == 0) || (bVar1)) {
            if (((uint)(ushort)camera->rightTimer - 1 < 3) && (!bVar1)) {
              CAMERA_CenterCamera(camera);
            }
            camera->rightTimer = 0;
          }
          else {
            sVar3 = camera->rightTimer + 1;
            camera->rightTimer = sVar3;
            if (2 < sVar3) {
              camera->rotDirection = 1;
              camera->forced_movement = 1;
              uVar5 = (camera->focusRotation).z + (short)((gameTrackerX.timeMult << 5) >> 0xc) &
                      0xfff;
              (camera->focusRotation).z = uVar5;
              uVar2 = gameTrackerX.frameCount;
              (camera->data).Follow.stopTimer = -0x1a5e0000;
              (camera->focusRotation).z = uVar5;
              (camera->collisionTargetFocusRotation).z = uVar5;
              (camera->targetFocusRotation).z = uVar5;
              camera->lastModTime = uVar2;
            }
          }
        }
        else {
          camera->rightTimer = 0;
          camera->leftTimer = 0;
        }
        if ((gameTrackerX.debugFlags2 & 0x2000000U) != 0) {
          if ((camera->lock & 1U) == 0) {
            if (((gameTrackerX.controlCommand[0][0] & 0x40000008U) == 0x40000008) &&
               (sVar3 = camera->targetFocusDistance + -0x14, camera->targetFocusDistance = sVar3,
               sVar3 < 200)) {
              camera->targetFocusDistance = 200;
            }
            if (((gameTrackerX.controlCommand[0][0] & 0x40000004U) == 0x40000004) &&
               (sVar3 = camera->targetFocusDistance + 0x14, camera->targetFocusDistance = sVar3,
               0x1000 < sVar3)) {
              camera->targetFocusDistance = 0x1000;
            }
          }
          if ((camera->lock & 2U) == 0) {
            if ((gameTrackerX.controlCommand[0][0] & 0x40000002U) == 0x40000002) {
              camera->extraXRot = camera->extraXRot + 0x10;
            }
            if ((gameTrackerX.controlCommand[0][0] & 0x40000001U) == 0x40000001) {
              camera->extraXRot = camera->extraXRot + -0x10;
            }
          }
        }
        if ((bVar1) && ((playerInstance->flags & 0x100U) == 0)) {
          if (((camera->flags & 0x20000U) != 0) && (camera->mode != 5)) {
            sVar3 = camera->lookTimer + 1;
            camera->lookTimer = sVar3;
            if (sVar3 == 2) {
              lVar4 = PLAYER_OkToLookAround(instance);
              if ((lVar4 != 0) && ((camera->lock & 0x200U) == 0)) {
                CAMERA_StartLookaroundMode(camera);
                PLAYER_SetLookAround(instance);
                camera->collideRotControl = 0;
                return;
              }
              camera->lookTimer = 0;
            }
            else {
              if ((2 < sVar3) && (camera->mode == 6)) {
                PLAYER_TurnHead(instance,(short *)&camera->lookRot,&(camera->lookRot).z,
                                &gameTrackerX);
                camera->collideRotControl = 0;
                return;
              }
            }
          }
        }
        else {
          camera->flags = camera->flags | 0x20000;
          CAMERA_EndLook(camera);
        }
        camera->collideRotControl = 0;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_EndLook(struct Camera *camera /*$s0*/)
 // line 4714, offset 0x8001bec4
	/* begin block 1 */
		// Start line: 4715
		// Start offset: 0x8001BEC4
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001BF6C
	// End Line: 4770

	/* begin block 2 */
		// Start line: 11022
	/* end block 2 */
	// End Line: 11023

void CAMERA_EndLook(Camera *camera)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  _Instance *instance;
  
  instance = camera->focusInstance;
  if ((1 < camera->lookTimer) && (camera->mode == 6)) {
    CAMERA_RestoreMode(camera);
    camera->forced_movement = 0;
    camera->smooth = 8;
    camera->targetFocusDistance = camera->savedFocusDistance;
    uVar3 = *(undefined4 *)&(camera->savedFocusRotation).z;
    *(undefined4 *)&camera->targetFocusRotation = *(undefined4 *)&camera->savedFocusRotation;
    *(undefined4 *)&(camera->targetFocusRotation).z = uVar3;
    uVar2 = (instance->rotation).z + 0x800U & 0xfff;
    (camera->targetFocusRotation).z = uVar2;
    (camera->collisionTargetFocusRotation).z = uVar2;
    CAMERA_CenterCamera(camera);
    sVar1 = (camera->core).rotation.x;
    camera->always_rotate_flag = 1;
    camera->actual_x_rot = sVar1;
    PLAYER_ReSetLookAround(instance);
  }
  camera->lookTimer = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ChangeToUnderWater(struct Camera *camera /*$s0*/, struct _Instance *instance /*$a1*/)
 // line 4774, offset 0x8001bf84
	/* begin block 1 */
		// Start line: 11182
	/* end block 1 */
	// End Line: 11183

void CAMERA_ChangeToUnderWater(Camera *camera,_Instance *instance)

{
  short sVar1;
  undefined camera_00;
  undefined instance_00;
  
  instance_00 = SUB41(instance,0);
  camera_00 = SUB41(camera,0);
  if (instance == camera->focusInstance) {
    sVar1 = camera->mode;
    if (sVar1 != 4) {
      if (sVar1 != 5) {
        if (sVar1 == 0xd) {
          CAMERA_CreateNewFocuspoint(camera);
        }
        else {
          instance_00 = 0xd;
          CAMERA_SetMode(camera,0xd);
        }
        camera->smooth = 8;
        camera->targetFocusDistance = 0x640;
        camera->collisionTargetFocusDistance = 0x640;
        camera->signalFocusDistance = 0x640;
        (camera->rotationVel).z = 0x20;
        camera->always_rotate_flag = 0;
        CAMERA_ChangeToUnderWater(camera_00,instance_00);
        return;
      }
                    /* WARNING: Subroutine does not return */
      CAMERA_SaveMode(camera,0xd);
    }
    camera->flags = camera->flags | 0x10000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ChangeToOutOfWater(struct Camera *camera /*$s0*/, struct _Instance *instance /*$a1*/)
 // line 4801, offset 0x8001c030
	/* begin block 1 */
		// Start line: 11236
	/* end block 1 */
	// End Line: 11237

void CAMERA_ChangeToOutOfWater(Camera *camera,_Instance *instance)

{
  undefined camera_00;
  undefined instance_00;
  
  camera_00 = SUB41(camera,0);
  if (instance != camera->focusInstance) {
    return;
  }
  if (camera->mode != 5) {
    instance_00 = 0xd;
    CAMERA_SetMode(camera,0xd);
    (camera->rotationVel).z = 0;
    camera->targetTilt = 0;
    CAMERA_ChangeToUnderWater(camera_00,instance_00);
    return;
  }
                    /* WARNING: Subroutine does not return */
  CAMERA_SaveMode(camera,0xd);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusDistance(struct Camera *camera /*$a3*/)
 // line 4917, offset 0x8001c0a4
	/* begin block 1 */
		// Start line: 4918
		// Start offset: 0x8001C0A4
		// Variables:
	// 		int smooth; // $v1
	// 		long dampMode; // $a0
	/* end block 1 */
	// End offset: 0x8001C164
	// End Line: 4965

	/* begin block 2 */
		// Start line: 9816
	/* end block 2 */
	// End Line: 9817

void CAMERA_UpdateFocusDistance(Camera *camera)

{
  int smooth;
  long dampMode;
  
  if ((camera->forced_movement != 2) && ((camera->lock & 1U) == 0)) {
    if ((camera->targetFocusDistance < camera->collisionTargetFocusDistance) &&
       ((camera->instance_mode & 0x82000000) == 0)) {
      camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    }
    dampMode = 6;
    if (camera->collisionTargetFocusDistance < camera->focusDistance) {
      smooth = 0x200;
      if (camera->collisionTargetFocusDistance < camera->targetFocusDistance) {
        dampMode = 5;
      }
      else {
        smooth = 0x80;
        dampMode = 1;
      }
    }
    else {
      smooth = 0x40;
    }
    CriticalDampValue(dampMode,&camera->focusDistance,camera->collisionTargetFocusDistance,
                      &camera->focusDistanceVel,&camera->focusDistanceAccl,smooth);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusTilt(struct Camera *camera /*$s0*/)
 // line 4967, offset 0x8001c174
	/* begin block 1 */
		// Start line: 11467
	/* end block 1 */
	// End Line: 11468

void CAMERA_UpdateFocusTilt(Camera *camera)

{
  if ((camera->flags & 0x1800U) != 0) {
    camera->x_rot_change = 0;
    (camera->focusRotation).x = camera->tfaceTilt;
    return;
  }
  camera->x_rot_change = (camera->focusRotation).x;
  if (((camera->forced_movement == 3) || ((camera->lock & 2U) != 0)) &&
     ((camera->flags & 0x10000U) == 0)) {
    (camera->focusRotation).x = (camera->targetFocusRotation).x;
                    /* WARNING: Subroutine does not return */
    CAMERA_SignedAngleDifference(camera->x_rot_change,(camera->focusRotation).x);
  }
                    /* WARNING: Subroutine does not return */
  CriticalDampAngle(1,(short *)&camera->focusRotation,camera->tfaceTilt,
                    (short *)&camera->focusRotVel,(short *)&camera->focusRotAccl,0x20);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRoll(struct Camera *camera /*$s1*/)
 // line 5001, offset 0x8001c240
	/* begin block 1 */
		// Start line: 5002
		// Start offset: 0x8001C240
		// Variables:
	// 		long tmp_inc; // $s0
	/* end block 1 */
	// End offset: 0x8001C340
	// End Line: 5019

	/* begin block 2 */
		// Start line: 11538
	/* end block 2 */
	// End Line: 11539

	/* begin block 3 */
		// Start line: 11541
	/* end block 3 */
	// End Line: 11542

void CAMERA_UpdateFocusRoll(Camera *camera)

{
  long lVar1;
  long lVar2;
  
  if (roll_inc != 0) {
    lVar1 = current_roll_amount;
    if (current_roll_amount < 0) {
      lVar1 = current_roll_amount + 0xfff;
    }
    lVar2 = roll_target;
    if (roll_target < 0) {
      lVar2 = roll_target + 0xfff;
    }
                    /* WARNING: Subroutine does not return */
    CAMERA_AngleDifference((short)((uint)(lVar1 << 4) >> 0x10),(short)((uint)(lVar2 << 4) >> 0x10));
  }
  lVar1 = current_roll_amount;
  if (current_roll_amount < 0) {
    lVar1 = current_roll_amount + 0xfff;
  }
  (camera->core).rotation.y = (short)(lVar1 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotate(struct Camera *camera /*$s0*/)
 // line 5025, offset 0x8001c35c
	/* begin block 1 */
		// Start line: 5026
		// Start offset: 0x8001C35C

		/* begin block 1.1 */
			// Start line: 5029
			// Start offset: 0x8001C390
			// Variables:
		// 		int dampspeed; // $v1
		// 		long dampmode; // $a0
		/* end block 1.1 */
		// End offset: 0x8001C410
		// End Line: 5054
	/* end block 1 */
	// End offset: 0x8001C438
	// End Line: 5061

	/* begin block 2 */
		// Start line: 11590
	/* end block 2 */
	// End Line: 11591

void CAMERA_UpdateFocusRotate(Camera *camera)

{
  short sVar1;
  long dampMode;
  
  if (camera->forced_movement == 1) {
    if ((camera->lock & 4U) == 0) {
      return;
    }
  }
  else {
    if ((camera->lock & 4U) == 0) {
      dampMode = 1;
      if (camera->always_rotate_flag == 0) {
        sVar1 = 0x80;
        if ((camera->flags & 0x10000U) == 0) {
          dampMode = 5;
          sVar1 = 0xa0;
        }
      }
      else {
        sVar1 = -camera->smooth;
      }
                    /* WARNING: Subroutine does not return */
      CriticalDampAngle(dampMode,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z
                        ,&(camera->focusRotVel).z,&(camera->focusRotAccl).z,(int)sVar1);
    }
  }
  (camera->focusRotation).z = (camera->targetFocusRotation).z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotationX(struct Camera *camera /*$s0*/, struct _Instance *focusInstance /*$a1*/)
 // line 5067, offset 0x8001c448
	/* begin block 1 */
		// Start line: 5068
		// Start offset: 0x8001C448
		// Variables:
	// 		short cameraPlayerRotX; // $a1
	// 		short dist; // $s1

		/* begin block 1.1 */
			// Start line: 5088
			// Start offset: 0x8001C4C4
			// Variables:
		// 		struct _Normal normal; // stack offset -24
		// 		int mult; // $v1
		/* end block 1.1 */
		// End offset: 0x8001C588
		// End Line: 5113

		/* begin block 1.2 */
			// Start line: 5118
			// Start offset: 0x8001C5AC
			// Variables:
		// 		int tmpsmooth; // $t0
		/* end block 1.2 */
		// End offset: 0x8001C61C
		// End Line: 5133
	/* end block 1 */
	// End offset: 0x8001C6AC
	// End Line: 5159

	/* begin block 2 */
		// Start line: 11674
	/* end block 2 */
	// End Line: 11675

void CAMERA_UpdateFocusRotationX(Camera *camera,_Instance *focusInstance)

{
  _TFace *p_Var1;
  int smooth;
  _SVector _Stack24;
  
  p_Var1 = focusInstance->tface;
  if ((((p_Var1 != (_TFace *)0x0) && (smooth = *(int *)focusInstance->tfaceLevel, smooth != 0)) &&
      (p_Var1->textoff != 0xffff)) &&
     (((*(ushort *)(*(int *)(smooth + 0x34) + (uint)p_Var1->textoff + 10) & 0x8000) != 0 &&
      (camera->targetFocusDistance < 0xb60)))) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_GetNormal(p_Var1->normal,*(short **)(smooth + 0x24),&_Stack24);
  }
  smooth = 0x18;
  if ((camera->instance_mode & 0x38) == 0) {
    camera->targetTilt = 0;
  }
  if (((camera->instance_mode & 0x2000) != 0) &&
     ((camera->real_focuspoint).z < camera->focuspoint_fallz)) {
    camera->targetTilt = -0x180;
    smooth = 0xc;
  }
                    /* WARNING: Subroutine does not return */
  CriticalDampAngle(1,&camera->tilt,camera->targetTilt,&camera->tiltVel,&camera->tiltAccl,smooth);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowPlayerTilt(struct Camera *camera /*$s1*/, struct _Instance *focusInstance /*$a1*/)
 // line 5164, offset 0x8001c6c0
	/* begin block 1 */
		// Start line: 5165
		// Start offset: 0x8001C6C0
		// Variables:
	// 		int speed; // $s2
	// 		long focusInstanceStatus; // $a0

		/* begin block 1.1 */
			// Start line: 5186
			// Start offset: 0x8001C728
			// Variables:
		// 		struct _SVector offset; // stack offset -32
		// 		struct _Normal normal; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 5210
				// Start offset: 0x8001C7E0
				// Variables:
			// 		int waterZ; // $v0
			// 		int target; // $v0
			// 		int height; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 5218
					// Start offset: 0x8001C820
					// Variables:
				// 		int fdsq; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8001C860
				// End Line: 5226
			/* end block 1.1.1 */
			// End offset: 0x8001C860
			// End Line: 5227
		/* end block 1.1 */
		// End offset: 0x8001C860
		// End Line: 5228
	/* end block 1 */
	// End offset: 0x8001C860
	// End Line: 5233

	/* begin block 2 */
		// Start line: 11872
	/* end block 2 */
	// End Line: 11873

void CAMERA_FollowPlayerTilt(Camera *camera,_Instance *focusInstance)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(focusInstance,9);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera /*$s0*/)
 // line 5242, offset 0x8001c8b0
	/* begin block 1 */
		// Start line: 5243
		// Start offset: 0x8001C8B0
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001C998
	// End Line: 5281

	/* begin block 2 */
		// Start line: 12039
	/* end block 2 */
	// End Line: 12040

void CAMERA_FollowGoBehindPlayerWithTimer(Camera *camera)

{
  int iVar1;
  _Instance *p_Var2;
  
  p_Var2 = camera->focusInstance;
  if ((camera->data).Follow.hit != 0) {
    (camera->data).Follow.stopTimer = -0x1a5e0000;
  }
  iVar1 = CAMERA_FocusInstanceMoved(camera);
  if (iVar1 == 0) {
    if ((gameTrackerX.streamFlags & 0x100000U) != 0) goto LAB_8001c928;
    iVar1 = (camera->data).Follow.stopTimer + gameTrackerX.timeMult;
  }
  else {
    iVar1 = CameraCenterDelay * -0x1e000;
  }
  (camera->data).Follow.stopTimer = iVar1;
LAB_8001c928:
  if (0 < (camera->data).Follow.stopTimer) {
    Decouple_AngleMoveToward
              (&(camera->targetFocusRotation).z,
               (short)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000 >> 0x10),0x20);
    Decouple_AngleMoveToward
              (&(camera->collisionTargetFocusRotation).z,
               (short)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000 >> 0x10),0x20);
                    /* WARNING: Subroutine does not return */
    CriticalDampAngle(1,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z,
                      &(camera->focusRotVel).z,&(camera->focusRotAccl).z,0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayer(struct Camera *camera /*$v1*/)
 // line 5284, offset 0x8001c9ac
	/* begin block 1 */
		// Start line: 5285
		// Start offset: 0x8001C9AC
		// Variables:
	// 		struct _Instance *focusInstance; // $v0
	/* end block 1 */
	// End offset: 0x8001C9AC
	// End Line: 5285

	/* begin block 2 */
		// Start line: 12131
	/* end block 2 */
	// End Line: 12132

void CAMERA_FollowGoBehindPlayer(Camera *camera)

{
  Decouple_AngleMoveToward
            (&(camera->targetFocusRotation).z,
             (short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x800) * 0x10000 >> 0x10),
             (camera->rotationVel).z);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalculateLead(struct Camera *camera /*$s1*/)
 // line 5296, offset 0x8001c9e8
	/* begin block 1 */
		// Start line: 5297
		// Start offset: 0x8001C9E8
		// Variables:
	// 		short lead_target; // $s0
	// 		short lead_smooth; // $v1

		/* begin block 1.1 */
			// Start line: 5303
			// Start offset: 0x8001CA34
			// Variables:
		// 		int speedxy; // $s0
		// 		short angle; // $a0

			/* begin block 1.1.1 */
				// Start line: 5315
				// Start offset: 0x8001CABC
				// Variables:
			// 		int calc; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8001CB2C
			// End Line: 5332
		/* end block 1.1 */
		// End offset: 0x8001CB34
		// End Line: 5337
	/* end block 1 */
	// End offset: 0x8001CB40
	// End Line: 5351

	/* begin block 2 */
		// Start line: 12155
	/* end block 2 */
	// End Line: 12156

void CAMERA_CalculateLead(Camera *camera)

{
  if ((((camera->flags & 0x10000U) == 0) && (camera->mode != 6)) &&
     ((camera->instance_mode & 0x3002043) == 0)) {
                    /* WARNING: Subroutine does not return */
    CAMERA_SignedAngleDifference
              ((short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x800) * 0x10000 >> 0x10
                      ),(camera->core).rotation.z);
  }
  camera->lead_timer = 0;
                    /* WARNING: Subroutine does not return */
  CriticalDampAngle(1,&camera->lead_angle,0,&camera->lead_vel,&camera->lead_accl,3);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFollowPosition(struct Camera *camera /*$s1*/, struct _Rotation *rotation /*$s0*/)
 // line 5367, offset 0x8001cb90
	/* begin block 1 */
		// Start line: 5368
		// Start offset: 0x8001CB90

		/* begin block 1.1 */
			// Start line: 5368
			// Start offset: 0x8001CB90
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CB90
		// End Line: 5368

		/* begin block 1.2 */
			// Start line: 5385
			// Start offset: 0x8001CC08
			// Variables:
		// 		short target_rotx; // $s0
		// 		int hypotXY; // $s2
		// 		int smooth; // $v1
		// 		int diff; // $a0
		// 		struct _Vector dpv; // stack offset -32
		// 		int zdiff; // $a0

			/* begin block 1.2.1 */
				// Start line: 5406
				// Start offset: 0x8001CCA4
				// Variables:
			// 		int velz; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 5414
					// Start offset: 0x8001CCBC
					// Variables:
				// 		int ground; // $a0
				// 		int pos; // $v1
				/* end block 1.2.1.1 */
				// End offset: 0x8001CD3C
				// End Line: 5429
			/* end block 1.2.1 */
			// End offset: 0x8001CD3C
			// End Line: 5429
		/* end block 1.2 */
		// End offset: 0x8001CE48
		// End Line: 5476
	/* end block 1 */
	// End offset: 0x8001CE60
	// End Line: 5481

	/* begin block 2 */
		// Start line: 12299
	/* end block 2 */
	// End Line: 12300

void CAMERA_CalcFollowPosition(Camera *camera,_Rotation *rotation)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,rotation,camera->focusDistance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetupColInfo(struct Camera *camera /*$a3*/, struct CameraCollisionInfo *colInfo /*$t0*/, struct _Position *targetCamPos /*$a2*/)
 // line 5485, offset 0x8001ce84
	/* begin block 1 */
		// Start line: 5486
		// Start offset: 0x8001CE84
		// Variables:
	// 		static short toggle; // offset 0x62

		/* begin block 1.1 */
			// Start line: 5491
			// Start offset: 0x8001CE98
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CE98
		// End Line: 5491

		/* begin block 1.2 */
			// Start line: 5495
			// Start offset: 0x8001CEA4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001CEC4
		// End Line: 5495

		/* begin block 1.3 */
			// Start line: 5497
			// Start offset: 0x8001CEC4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v1
		/* end block 1.3 */
		// End offset: 0x8001CEC4
		// End Line: 5497
	/* end block 1 */
	// End offset: 0x8001CF3C
	// End Line: 5518

	/* begin block 2 */
		// Start line: 12547
	/* end block 2 */
	// End Line: 12548

void CAMERA_SetupColInfo(Camera *camera,CameraCollisionInfo *colInfo,_Position *targetCamPos)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  _Position *p_Var4;
  long lVar5;
  short sVar6;
  
  if (camera->mode == 6) {
    sVar6 = (camera->targetFocusPoint).x;
    p_Var4 = &camera->targetFocusPoint;
  }
  else {
    p_Var4 = &camera->real_focuspoint;
    sVar6 = (camera->real_focuspoint).x;
  }
  sVar2 = p_Var4->y;
  sVar3 = p_Var4->z;
  (camera->focusSphere).position.x = sVar6;
  (camera->focusSphere).position.y = sVar2;
  (camera->focusSphere).position.z = sVar3;
  sVar6 = targetCamPos->y;
  sVar2 = targetCamPos->z;
  (camera->posSphere).position.x = targetCamPos->x;
  (camera->posSphere).position.y = sVar6;
  (camera->posSphere).position.z = sVar2;
  colInfo->start = &camera->focusSphere;
  colInfo->end = &camera->posSphere;
  lVar5 = 0x1e;
  if ((camera->data).Follow.tface == (_TFace *)0x0) {
    bVar1 = DAT_800cf172 == 0;
    colInfo->cldLines = 6;
    if (bVar1) {
      lVar5 = 0x16;
    }
    else {
      lVar5 = 0xe;
    }
  }
  colInfo->cldLines = lVar5;
  if (DAT_800cf172 != 0) {
    DAT_800cf172 = 0;
    return;
  }
  DAT_800cf172 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_DoPanicCheck(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *tmpcolInfo /*$s1*/, struct _Rotation *rotation /*$s3*/, short *best_z /*$s4*/, short *max_dist /*stack 16*/)
 // line 5526, offset 0x8001cf44
	/* begin block 1 */
		// Start line: 5527
		// Start offset: 0x8001CF44
		// Variables:
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 5527
			// Start offset: 0x8001CF44
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CF44
		// End Line: 5527
	/* end block 1 */
	// End offset: 0x8001CFF4
	// End Line: 5539

	/* begin block 2 */
		// Start line: 12632
	/* end block 2 */
	// End Line: 12633

void CAMERA_DoPanicCheck(Camera *camera,CameraCollisionInfo *tmpcolInfo,_Rotation *rotation,
                        short *best_z,short *max_dist)

{
  _Position local_20;
  
                    /* WARNING: Subroutine does not return */
  CAMERA_CalcPosition(&local_20,&camera->focusPoint,rotation,camera->targetFocusDistance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Panic(struct Camera *camera /*$s2*/, short min_dist /*$fp*/)
 // line 5541, offset 0x8001d014
	/* begin block 1 */
		// Start line: 5542
		// Start offset: 0x8001D014
		// Variables:
	// 		struct _Position targetCamPos; // stack offset -160
	// 		struct _Rotation rotation; // stack offset -152
	// 		int n; // $s1
	// 		short best_z; // stack offset -48
	// 		short max_dist; // stack offset -46
	// 		struct CameraCollisionInfo tmpcolInfo; // stack offset -144
	// 		short free_count1; // $s7
	// 		short free_count2; // $s6
	/* end block 1 */
	// End offset: 0x8001D194
	// End Line: 5591

	/* begin block 2 */
		// Start line: 12670
	/* end block 2 */
	// End Line: 12671

/* WARNING: Could not reconcile some variable overlaps */

void CAMERA_Panic(Camera *camera,short min_dist)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _Position _Stack160;
  undefined4 local_98;
  uint local_94;
  CameraCollisionInfo CStack144;
  short local_30;
  short local_2e [3];
  
  iVar4 = 0;
  iVar3 = 0;
  local_2e[0] = min_dist;
  CAMERA_SetupColInfo(camera,&CStack144,&_Stack160);
  iVar2 = 0;
  local_98 = *(undefined4 *)&camera->focusRotation;
  local_94 = *(uint *)&(camera->focusRotation).z;
  local_30 = (short)local_94;
  while( true ) {
    local_94 = local_94 & 0xffff0000 | (uint)(ushort)((camera->focusRotation).z + (short)iVar2);
    CAMERA_DoPanicCheck(camera,&CStack144,(_Rotation *)&local_98,&local_30,local_2e);
    if ((CStack144.numCollided == 0) && (iVar4 = iVar4 + 1, 2 < iVar4 * 0x10000 >> 0x10)) break;
    local_94 = local_94 & 0xffff0000 | (uint)(ushort)((camera->focusRotation).z - (short)iVar2);
    CAMERA_DoPanicCheck(camera,&CStack144,(_Rotation *)&local_98,&local_30,local_2e);
    iVar1 = iVar3 + 1;
    if (((CStack144.numCollided == 0) && (iVar3 = iVar1, 2 < iVar1 * 0x10000 >> 0x10)) ||
       (iVar2 = iVar2 + 0x80, 0x7ff < iVar2)) break;
  }
  if (local_2e[0] == min_dist) {
    panic_count = -0x7fff;
  }
  else {
    camera->always_rotate_flag = 1;
    camera->rotState = 3;
    camera->smooth = -0x70;
    (camera->targetFocusRotation).z = local_30;
    (camera->collisionTargetFocusRotation).z = local_30;
    (camera->signalRot).z = local_30;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_DoCameraCollision2(struct Camera *camera /*$s1*/, struct _Position *targetCamPos /*$v0*/, int simpleflag /*$s3*/)
 // line 5595, offset 0x8001d1c4
	/* begin block 1 */
		// Start line: 5596
		// Start offset: 0x8001D1C4
		// Variables:
	// 		int secondcheck_flag; // $s0
	// 		long hit; // $s2
	// 		struct CameraCollisionInfo colInfo; // stack offset -120
	// 		static long collisiontimeDown; // offset 0x68

		/* begin block 1.1 */
			// Start line: 5685
			// Start offset: 0x8001D3F0
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001D3F0
		// End Line: 5685

		/* begin block 1.2 */
			// Start line: 5741
			// Start offset: 0x8001D53C
			// Variables:
		// 		int speed; // $s0
		/* end block 1.2 */
		// End offset: 0x8001D604
		// End Line: 5761

		/* begin block 1.3 */
			// Start line: 5791
			// Start offset: 0x8001D68C
			// Variables:
		// 		int angle1; // $s0
		// 		int angle2; // $v0
		/* end block 1.3 */
		// End offset: 0x8001D738
		// End Line: 5807
	/* end block 1 */
	// End offset: 0x8001D798
	// End Line: 5846

	/* begin block 2 */
		// Start line: 12828
	/* end block 2 */
	// End Line: 12829

/* WARNING: Could not reconcile some variable overlaps */

long CAMERA_DoCameraCollision2(Camera *camera,_Position *targetCamPos,int simpleflag)

{
  short sVar1;
  short sVar2;
  int iVar3;
  _TFace *p_Var4;
  int iVar5;
  int secondcheck_flag;
  long lVar6;
  undefined auStack120 [52];
  undefined auStack68 [12];
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  lVar6 = 0;
  CAMERA_SetupColInfo(camera,(CameraCollisionInfo *)auStack120,targetCamPos);
  secondcheck_flag = 0;
  if ((camera->flags & 0x10000U) == 0) {
    iVar5 = (int)(camera->real_focuspoint).z;
    secondcheck_flag = (int)(camera->targetFocusPoint).z;
    iVar3 = iVar5 - secondcheck_flag;
    if (iVar3 < 0) {
      iVar3 = secondcheck_flag - iVar5;
    }
    secondcheck_flag = 0;
    if (4 < iVar3) {
      secondcheck_flag = 1;
    }
  }
  p_Var4 = CAMERA_SphereToSphereWithLines(camera,(CameraCollisionInfo *)auStack120,secondcheck_flag)
  ;
  (camera->data).Follow.tface = p_Var4;
  if ((((((camera->instance_mode & 0x2000000) != 0) && (0 < local_30)) && (local_2c < 600)) &&
      ((CenterFlag = -1, local_30 != 1 || ((local_38 & 6) == 0)))) && (combat_cam_weight < 0x1000))
  {
    if ((short)(combat_cam_weight + 0x90) < 0x1000) {
      CenterFlag = -1;
      combat_cam_weight = combat_cam_weight + 0x90;
      return 1;
    }
    combat_cam_weight = 0x1000;
  }
  if ((((((camera->flags & 0x12000U) == 0) && (camera->instance_xyvel == 0)) &&
       ((secondcheck_flag == 0 &&
        (((camera->always_rotate_flag == 0 && (camera->forced_movement == 0)) && (0 < local_30))))))
      && ((local_30 == 4 || (camera_still != 0)))) && (local_2c < 400)) {
    panic_count = panic_count + 1;
    if ((gameTrackerX.controlCommand[0][0] & 1U) == 0) {
      if (panic_count < 2) goto LAB_8001d3d8;
    }
    else {
      if (panic_count < 0xb) goto LAB_8001d3d8;
    }
    CAMERA_Panic(camera,(short)local_2c);
  }
  else {
    panic_count = 0;
  }
LAB_8001d3d8:
  if (((camera->data).Follow.tface != (_TFace *)0x0) && (secondcheck_flag != 0)) {
    sVar1 = (camera->targetFocusPoint).y;
    sVar2 = (camera->targetFocusPoint).z;
    (camera->focusSphere).position.x = (camera->targetFocusPoint).x;
    (camera->focusSphere).position.y = sVar1;
    (camera->focusSphere).position.z = sVar2;
    p_Var4 = CAMERA_SphereToSphereWithLines(camera,(CameraCollisionInfo *)auStack120,0);
    (camera->data).Follow.tface = p_Var4;
  }
  if (simpleflag == 0) {
    if (0 < DAT_800cf178) {
      DAT_800cf178 = DAT_800cf178 + -1;
    }
    if (camera->always_rotate_flag != 0) {
      local_30 = 4;
    }
    if ((camera->flags & 0x10000U) == 0) {
      if (((camera->instance_mode & 0x24000000) == 0) &&
         ((((camera->flags & 0x2000U) == 0 || ((camera->instance_mode & 0x2000000) != 0)) &&
          (camera->always_rotate_flag == 0)))) {
        if ((camera->data).Follow.tface != (_TFace *)0x0) {
          lVar6 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
          DAT_800cf178 = 0x1e;
          (camera->targetFocusRotation).z = (camera->collisionTargetFocusRotation).z;
          return lVar6;
        }
        CAMERA_dampgetline(0);
        if ((camera->mode == 0xd) && (0 < camera->instance_xyvel)) {
                    /* WARNING: Subroutine does not return */
          CAMERA_AngleDifference((camera->collisionTargetFocusRotation).z,(camera->focusRotation).z)
          ;
        }
        if (DAT_800cf178 == 0) {
          Decouple_AngleMoveToward
                    (&(camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z,0x40)
          ;
          camera->collision_lastPush = 0;
        }
        if ((camera->instance_mode & 0x2000000) == 0) {
          camera->collisionTargetFocusDistance = camera->targetFocusDistance;
          return 0;
        }
        DAT_800cf178 = 0;
        camera->collisionTargetFocusDistance = combat_cam_distance;
        return 0;
      }
    }
    if ((camera->data).Follow.tface == (_TFace *)0x0) {
      camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    }
    else {
      lVar6 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
      DAT_800cf178 = 0x1e;
    }
    if ((camera->flags & 0x10000U) != 0) {
                    /* WARNING: Subroutine does not return */
      AngleDiff((camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z);
    }
    Decouple_AngleMoveToward
              (&(camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z,0x40);
    return lVar6;
  }
  if ((camera->data).Follow.tface == (_TFace *)0x0) {
    return 0;
  }
  sVar1 = camera->mode;
  if (((sVar1 != 4) && (sVar1 != 2)) && (sVar1 != 6)) {
    return 1;
  }
  camera->collisionTargetFocusDistance = *(short *)(auStack120 + local_34 * 2 + 0x34);
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_FocusInstanceMoved(struct Camera *camera /*$a0*/)
 // line 5851, offset 0x8001d7b4
	/* begin block 1 */
		// Start line: 13382
	/* end block 1 */
	// End Line: 13383

	/* begin block 2 */
		// Start line: 13383
	/* end block 2 */
	// End Line: 13384

int CAMERA_FocusInstanceMoved(Camera *camera)

{
  int iVar1;
  
  iVar1 = 0;
  if (((((camera->newFocusInstancePos).x != (camera->oldFocusInstancePos).x) ||
       ((camera->newFocusInstancePos).y != (camera->oldFocusInstancePos).y)) ||
      ((camera->newFocusInstancePos).z != (camera->oldFocusInstancePos).z)) ||
     ((*(int *)&camera->newFocusInstanceRot != *(int *)&camera->oldFocusInstanceRot ||
      ((camera->newFocusInstanceRot).z != (camera->oldFocusInstanceRot).z)))) {
    iVar1 = 1;
  }
  return iVar1;
}





