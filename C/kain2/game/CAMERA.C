#include "THISDUST.H"
#include "CAMERA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalculateViewVolumeNormals(struct Camera *camera /*$s0*/)
 // line 230, offset 0x800146e8
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x800146E8
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
	// End offset: 0x800146E8
	// End Line: 231

	/* begin block 2 */
		// Start line: 460
	/* end block 2 */
	// End Line: 461

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
 // line 263, offset 0x80014a24
	/* begin block 1 */
		// Start line: 553
	/* end block 1 */
	// End Line: 554

void CAMERA_CalcVVClipInfo(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal,
                (camera->core).vvNormalWorVecMat);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetViewVolume(struct Camera *camera /*$s0*/)
 // line 274, offset 0x80014b44
	/* begin block 1 */
		// Start line: 577
	/* end block 1 */
	// End Line: 578

void CAMERA_SetViewVolume(Camera *camera)

{
  CAMERA_CalculateViewVolumeNormals(camera);
  CAMERA_CalcVVClipInfo(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetProjDistance(struct Camera *camera /*$s3*/, long distance /*$s0*/)
 // line 280, offset 0x80014b70
	/* begin block 1 */
		// Start line: 281
		// Start offset: 0x80014B70
		// Variables:
	// 		struct Level *level; // $s0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x80014BF4
	// End Line: 300

	/* begin block 2 */
		// Start line: 589
	/* end block 2 */
	// End Line: 590

void CAMERA_SetProjDistance(Camera *camera,long distance)

{
  Level *level;
  int iVar1;
  int iVar2;
  
  SetGeomScreen(distance);
  (camera->core).projDistance = distance;
  CAMERA_CalculateViewVolumeNormals(camera);
  iVar2 = 0;
  iVar1 = -0x7ff2e6e0;
  do {
    if (*(short *)(iVar1 + 4) == 2) {
      level = *(Level **)(iVar1 + 8);
      SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,(camera->core).projDistance);
      LIGHT_CalcDQPTable(level);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x40;
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CreateNewFocuspoint(struct Camera *camera /*$s0*/)
 // line 302, offset 0x80014c14
	/* begin block 1 */
		// Start line: 303
		// Start offset: 0x80014C14
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 303
			// Start offset: 0x80014C14
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v0
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x80014C14
		// End Line: 303

		/* begin block 1.2 */
			// Start line: 303
			// Start offset: 0x80014C14
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		struct _Position *_v; // $a2
		/* end block 1.2 */
		// End offset: 0x80014C14
		// End Line: 303
	/* end block 1 */
	// End offset: 0x80014C14
	// End Line: 303

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

void CAMERA_CreateNewFocuspoint(Camera *camera)

{
  short distance;
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  distance = camera->focusDistance;
  (camera->focusRotation).x = camera->actual_x_rot;
  CAMERA_CalcPosition(&camera->targetPos,(_Position *)camera,&camera->focusRotation,distance);
  distance = (camera->core).position.y;
  sVar1 = (camera->core).position.z;
  sVar2 = (camera->targetPos).y;
  sVar3 = (camera->targetPos).z;
  (camera->focusPoint).x =
       (camera->core).position.x + ((camera->core).position.x - (camera->targetPos).x);
  sVar4 = (camera->core).position.z;
  (camera->focusPoint).y = (camera->core).position.y + (distance - sVar2);
  (camera->focusPoint).z = sVar4 + (sVar1 - sVar3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SaveMode(struct Camera *camera /*$a0*/, long mode /*$a1*/)
 // line 315, offset 0x80014cb8
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x80014CB8
		// Variables:
	// 		long i; // $t4
	/* end block 1 */
	// End offset: 0x80014FE8
	// End Line: 357

	/* begin block 2 */
		// Start line: 674
	/* end block 2 */
	// End Line: 675

	/* begin block 3 */
		// Start line: 675
	/* end block 3 */
	// End Line: 676

	/* begin block 4 */
		// Start line: 677
	/* end block 4 */
	// End Line: 678

void CAMERA_SaveMode(Camera *camera,long mode)

{
  short sVar1;
  _Position *p_Var2;
  _SavedCinematic *p_Var3;
  _SavedCinematic *p_Var4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  sVar1 = camera->stack + 1;
  camera->stack = sVar1;
  if (sVar1 < 3) {
    camera->savedMode[camera->stack] = mode;
    if (((mode == 2) || (mode == 5)) || (mode == 4)) {
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = (camera->core).position.z;
      *(undefined4 *)(p_Var2 + 0x70) = *(undefined4 *)&(camera->core).position;
      p_Var2[0x70].z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = (camera->focusPoint).z;
      *(undefined4 *)(p_Var2 + 0x71) = *(undefined4 *)&camera->focusPoint;
      p_Var2[0x71].z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = (camera->targetPos).z;
      *(undefined4 *)(p_Var2 + 0x73) = *(undefined4 *)&camera->targetPos;
      p_Var2[0x73].z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = (camera->targetFocusPoint).z;
      *(undefined4 *)(p_Var2 + 0x74) = *(undefined4 *)&camera->targetFocusPoint;
      p_Var2[0x74].z = sVar1;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&(camera->focusRotation).z;
      *(undefined4 *)&p_Var2[0x77].y = *(undefined4 *)&camera->focusRotation;
      *(undefined4 *)(p_Var2 + 0x78) = uVar5;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&(camera->targetFocusRotation).z;
      *(undefined4 *)&p_Var2[0x78].z = *(undefined4 *)&camera->targetFocusRotation;
      *(undefined4 *)&p_Var2[0x79].y = uVar5;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&(camera->focusPointVel).z;
      *(undefined4 *)&p_Var2[0x7a].z = *(undefined4 *)&camera->focusPointVel;
      *(undefined4 *)&p_Var2[0x7b].y = uVar5;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&(camera->focusPointAccl).z;
      *(undefined4 *)(p_Var2 + 0x7c) = *(undefined4 *)&camera->focusPointAccl;
      *(undefined4 *)&p_Var2[0x7c].z = uVar5;
      camera->savedCinematic[camera->stack].maxVel = (int)camera->maxVel;
      camera->savedCinematic[camera->stack].focusDistance = camera->focusDistance;
      camera->savedCinematic[camera->stack].targetFocusDistance = camera->targetFocusDistance;
      camera->savedCinematic[camera->stack].posSpline = (camera->data).Cinematic.posSpline;
      camera->savedCinematic[camera->stack].targetSpline = (camera->data).Cinematic.targetSpline;
      camera->savedCinematic[camera->stack].level = theCamera.core.vvNormalWorVecMat[1]._16_4_;
    }
    return;
  }
  camera->stack = 2;
  p_Var4 = camera->savedCinematic;
  p_Var3 = camera->savedCinematic + 1;
  camera->savedMode[0] = camera->savedMode[1];
  do {
    uVar5 = *(undefined4 *)&(p_Var3->position).z;
    uVar6 = *(undefined4 *)&(p_Var3->focusPoint).y;
    uVar7 = *(undefined4 *)&p_Var3->base;
    *(undefined4 *)&p_Var4->position = *(undefined4 *)&p_Var3->position;
    *(undefined4 *)&(p_Var4->position).z = uVar5;
    *(undefined4 *)&(p_Var4->focusPoint).y = uVar6;
    *(undefined4 *)&p_Var4->base = uVar7;
    p_Var3 = (_SavedCinematic *)&(p_Var3->base).z;
    p_Var4 = (_SavedCinematic *)&(p_Var4->base).z;
  } while (p_Var3 != camera->savedCinematic + 2);
  CAMERA_SaveMode(camera,mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_RestoreMode(struct Camera *camera /*$s0*/)
 // line 359, offset 0x80014ff0
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x80014FF0

		/* begin block 1.1 */
			// Start line: 372
			// Start offset: 0x80015014
			// Variables:
		// 		long mode; // $s1
		/* end block 1.1 */
		// End offset: 0x80015484
		// End Line: 485
	/* end block 1 */
	// End offset: 0x80015484
	// End Line: 486

	/* begin block 2 */
		// Start line: 770
	/* end block 2 */
	// End Line: 771

void CAMERA_RestoreMode(Camera *camera)

{
  short sVar1;
  long lVar2;
  _Position *p_Var3;
  MultiSpline *pMVar4;
  _Instance *Inst;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  
  if (-1 < (int)camera->stack) {
    iVar7 = camera->savedMode[(int)camera->stack];
    if (camera->mode == 5) {
      if (camera->smooth == 0) {
        camera->flags = camera->flags | 0x1000;
      }
      else {
        camera->smooth = 8;
      }
    }
    sVar6 = (short)iVar7;
    switch(iVar7) {
    case 0:
    case 0xc:
    case 0xd:
    case 0x10:
      CAMERA_SetProjDistance(camera,0x140);
      lVar2 = theCamera.core.vvNormalWorVecMat[1].t[0];
      if (camera->mode == 5) {
        (camera->focusOffset).x = 0;
        (camera->focusOffset).y = 0;
        (camera->focusOffset).z = 0x160;
        *(long *)&camera->focusInstance = lVar2;
        CAMERA_Restore(camera,7);
      }
      if (iVar7 == 0xc) {
        theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xffffffbf;
      }
      else {
        theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ | 0x40;
      }
      cameraMode = iVar7;
      camera->mode = sVar6;
      sVar6 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)camera_modeToIndex + ((iVar7 << 0x10) >> 0xe)) * 3 +
                        (int)camera->presetIndex);
      (camera->data).Follow.stopTimer = -0x1a5e0000;
      (camera->focusRotVel).z = 0;
      camera->targetFocusDistance = sVar6;
      if (iVar7 == 0x10) {
        camera->flags = camera->flags | 0x2000;
      }
      else {
        camera->flags = camera->flags & 0xffffdfff;
      }
      break;
    default:
      camera->mode = sVar6;
      break;
    case 2:
    case 4:
    case 5:
      CAMERA_SetProjDistance(camera,0x140);
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var3[0x70].z;
      *(undefined4 *)&(camera->core).position = *(undefined4 *)(p_Var3 + 0x70);
      (camera->core).position.z = sVar1;
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var3[0x71].z;
      *(undefined4 *)&camera->focusPoint = *(undefined4 *)(p_Var3 + 0x71);
      (camera->focusPoint).z = sVar1;
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var3[0x73].z;
      *(undefined4 *)&camera->targetPos = *(undefined4 *)(p_Var3 + 0x73);
      (camera->targetPos).z = sVar1;
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      sVar1 = p_Var3[0x74].z;
      *(undefined4 *)&camera->targetFocusPoint = *(undefined4 *)(p_Var3 + 0x74);
      (camera->targetFocusPoint).z = sVar1;
      camera->targetFocusDistance = camera->savedCinematic[(int)camera->stack].targetFocusDistance;
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&p_Var3[0x79].y;
      *(undefined4 *)&camera->targetFocusRotation = *(undefined4 *)&p_Var3[0x78].z;
      *(undefined4 *)&(camera->targetFocusRotation).z = uVar5;
      if ((camera->smooth == 0) && (camera->mode != 6)) {
        camera->focusDistance = camera->savedCinematic[(int)camera->stack].focusDistance;
        p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
        uVar5 = *(undefined4 *)(p_Var3 + 0x78);
        *(undefined4 *)&camera->focusRotation = *(undefined4 *)&p_Var3[0x77].y;
        *(undefined4 *)&(camera->focusRotation).z = uVar5;
      }
      else {
        camera->always_rotate_flag = 1;
      }
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&p_Var3[0x7b].y;
      *(undefined4 *)&camera->focusPointVel = *(undefined4 *)&p_Var3[0x7a].z;
      *(undefined4 *)&(camera->focusPointVel).z = uVar5;
      p_Var3 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&p_Var3[0x7c].z;
      *(undefined4 *)&camera->focusPointAccl = *(undefined4 *)(p_Var3 + 0x7c);
      *(undefined4 *)&(camera->focusPointAccl).z = uVar5;
      iVar7 = (int)camera->stack;
      Inst = camera->focusInstance;
      camera->maxVel = *(short *)&camera->savedCinematic[iVar7].maxVel;
      (camera->data).Cinematic.posSpline = camera->savedCinematic[iVar7].posSpline;
      pMVar4 = camera->savedCinematic[iVar7].targetSpline;
      camera->mode = sVar6;
                    /* WARNING: Subroutine does not return */
      (camera->data).Cinematic.targetSpline = pMVar4;
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
      camera->mode = sVar6;
      camera->targetFocusDistance = 2000;
    }
    camera->stack = camera->stack + -1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Save(struct Camera *camera /*$a0*/, long save /*$a1*/)
 // line 489, offset 0x80015498
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x80015498

		/* begin block 1.1 */
			// Start line: 493
			// Start offset: 0x800154A8
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x80015510
		// End Line: 505
	/* end block 1 */
	// End offset: 0x80015558
	// End Line: 520

	/* begin block 2 */
		// Start line: 1060
	/* end block 2 */
	// End Line: 1061

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
    CAMERA_SaveMode(camera,(int)camera->mode);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Restore(struct Camera *camera /*$a0*/, long restore /*$a1*/)
 // line 524, offset 0x80015568
	/* begin block 1 */
		// Start line: 1133
	/* end block 1 */
	// End Line: 1134

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
 // line 564, offset 0x80015624
	/* begin block 1 */
		// Start line: 565
		// Start offset: 0x80015624
		// Variables:
	// 		static struct _SVector point; // offset 0x0
	/* end block 1 */
	// End offset: 0x8001566C
	// End Line: 576

	/* begin block 2 */
		// Start line: 1219
	/* end block 2 */
	// End Line: 1220

_SVector * SplineGetNextPointDC(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetNext(spline,def,theCamera.tiltList[0][0]);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_42);
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMode(struct Camera *camera /*$s2*/, long mode /*$s3*/)
 // line 578, offset 0x80015680
	/* begin block 1 */
		// Start line: 579
		// Start offset: 0x80015680
		// Variables:
	// 		int oldMode; // $s0
	// 		struct SplineDef curPositional; // stack offset -56
	// 		struct _SVector sv; // stack offset -48

		/* begin block 1.1 */
			// Start line: 624
			// Start offset: 0x80015754
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		// 		struct _Rotation *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80015754
		// End Line: 624

		/* begin block 1.2 */
			// Start line: 624
			// Start offset: 0x80015754
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80015754
		// End Line: 624

		/* begin block 1.3 */
			// Start line: 624
			// Start offset: 0x80015754
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
		// End offset: 0x80015754
		// End Line: 624

		/* begin block 1.4 */
			// Start line: 684
			// Start offset: 0x800158B0
			// Variables:
		// 		struct _SVector *camPos; // stack offset -32
		// 		struct _SVector *targetPos; // $a0

			/* begin block 1.4.1 */
				// Start line: 689
				// Start offset: 0x800158C4
				// Variables:
			// 		struct _Position pos; // stack offset -40
			/* end block 1.4.1 */
			// End offset: 0x800158C4
			// End Line: 691

			/* begin block 1.4.2 */
				// Start line: 705
				// Start offset: 0x80015970
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.2 */
			// End offset: 0x80015970
			// End Line: 705

			/* begin block 1.4.3 */
				// Start line: 715
				// Start offset: 0x800159C4
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.3 */
			// End offset: 0x800159E0
			// End Line: 715
		/* end block 1.4 */
		// End offset: 0x800159E0
		// End Line: 719
	/* end block 1 */
	// End offset: 0x80015B14
	// End Line: 771

	/* begin block 2 */
		// Start line: 1252
	/* end block 2 */
	// End Line: 1253

void CAMERA_SetMode(Camera *camera,long mode)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long lVar4;
  MultiSpline *pMVar5;
  _SVector *p_Var6;
  uint uVar7;
  MultiSpline *pMVar8;
  Camera *spline;
  undefined4 uVar9;
  SplineDef local_38;
  _SVector local_30;
  _SVector _Stack40;
  _SVector *local_20 [2];
  
  sVar1 = camera->mode;
  if (((int)sVar1 != mode) || (1 < mode - 0xcU)) {
    switch(camera->mode) {
    case 2:
    case 4:
      CAMERA_SaveMode(camera,(int)camera->mode);
      break;
    case 5:
      if (mode != 5) {
        CAMERA_SaveMode(camera,(int)camera->mode);
        sVar3 = (camera->core).rotation.y;
        sVar2 = (camera->core).rotation.z;
        (camera->targetFocusRotation).x = (camera->core).rotation.x;
        (camera->targetFocusRotation).y = sVar3;
        (camera->targetFocusRotation).z = sVar2;
        sVar3 = (camera->core).rotation.y;
        sVar2 = (camera->core).rotation.z;
        (camera->focusRotation).x = (camera->core).rotation.x;
        (camera->focusRotation).y = sVar3;
        (camera->focusRotation).z = sVar2;
        local_30.x = (camera->core).position.x;
        local_30.y = (camera->core).position.y;
        local_30.z = (camera->core).position.z;
        camera->actual_x_rot = (camera->core).rotation.x;
        local_30.x = (camera->focusPoint).x - local_30.x;
        local_30.y = (camera->focusPoint).y - local_30.y;
        local_30.z = (camera->focusPoint).z - local_30.z;
        lVar4 = CAMERA_LengthSVector(&local_30);
        camera->focusDistance = (short)lVar4;
        roll_target = 0;
        current_roll_amount = 0;
        roll_inc = 0;
      }
      break;
    case 6:
      CAMERA_EndLook(camera);
      CAMERA_SaveMode(camera,(int)camera->mode);
      if (mode == 5) {
        CenterFlag = -1;
        (camera->focusRotation).z = (camera->targetFocusRotation).z;
        CAMERA_Save(camera,7);
      }
      break;
    case 0xc:
    case 0xd:
      CAMERA_SaveMode(camera,(int)camera->mode);
      if (mode == 5) {
        CAMERA_Save(camera,7);
      }
      CAMERA_CreateNewFocuspoint(camera);
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
      spline = camera;
      CAMERA_SetProjDistance(camera,0x140);
      (camera->data).Cinematic.posSpline = camera->Spline00;
      pMVar5 = camera->Spline01;
      pMVar8 = (camera->data).Cinematic.posSpline;
      (camera->data).Cinematic.cinema_done = 0;
      camera->Spline00 = (MultiSpline *)0x0;
      (camera->data).Cinematic.lastSplinePos.z = 0;
      (camera->data).Cinematic.lastSplinePos.y = 0;
      (camera->data).Cinematic.lastSplinePos.x = 0;
      camera->Spline01 = (MultiSpline *)0x0;
      (camera->data).Cinematic.targetSpline = pMVar5;
      if (pMVar8 != (MultiSpline *)0x0) {
        *(undefined4 *)&pMVar8->curPositional = 0;
      }
      pMVar5 = (camera->data).Cinematic.targetSpline;
      if (pMVar5 != (MultiSpline *)0x0) {
        *(undefined4 *)&pMVar5->curPositional = 0;
      }
      pMVar5 = (camera->data).Cinematic.posSpline;
      camera->mode = (short)mode;
      if (pMVar5 == (MultiSpline *)0x0) {
        SplineGetNextPointDC((Spline *)spline,(SplineDef *)0x0);
        return;
      }
      if ((mode == 4) || (mode == 2)) {
        splinecam_helprot.x = (camera->focusRotation).x;
        splinecam_helprot.z = (camera->focusRotation).z + 0x800U & 0xfff;
        CAMERA_CalcPosition((_Position *)&_Stack40,&camera->targetFocusPoint,&splinecam_helprot,
                            camera->targetFocusDistance);
        local_20[0] = SplineGetNearestPoint
                                (((camera->data).Cinematic.posSpline)->positional,&_Stack40,
                                 &local_38);
        CAMERA_CalcRotation(&splinecam_helprot,&camera->focusInstance->position,
                            (_Position *)local_20);
        pMVar5 = (camera->data).Cinematic.posSpline;
        (camera->data).Cinematic.splinecam_helpkey = (int)local_38.currkey;
        local_20[0] = SplineGetNearestPoint(pMVar5->positional,(_SVector *)camera,&local_38);
        (camera->data).Cinematic.splinecam_currkey = (int)local_38.currkey;
      }
      else {
        local_20[0] = SplineGetFirstPoint(pMVar5->positional,&pMVar5->curPositional);
      }
      if (local_20[0] != (_SVector *)0x0) {
        sVar1 = local_20[0]->y;
        sVar3 = local_20[0]->z;
        (camera->targetPos).x = local_20[0]->x;
        (camera->targetPos).y = sVar1;
        (camera->targetPos).z = sVar3;
        if (mode == 5) {
          camera->posState = 3;
        }
        pMVar5 = (camera->data).Cinematic.targetSpline;
        if ((pMVar5 != (MultiSpline *)0x0) &&
           (p_Var6 = SplineGetFirstPoint(pMVar5->positional,&pMVar5->curPositional),
           p_Var6 != (_SVector *)0x0)) {
          sVar1 = p_Var6->y;
          sVar3 = p_Var6->z;
          (camera->targetFocusPoint).x = p_Var6->x;
          (camera->targetFocusPoint).y = sVar1;
          (camera->targetFocusPoint).z = sVar3;
        }
      }
      uVar9 = *(undefined4 *)&(camera->focusRotation).z;
      *(undefined4 *)&camera->targetRotation = *(undefined4 *)&camera->focusRotation;
      *(undefined4 *)&(camera->targetRotation).z = uVar9;
      CenterFlag = -1;
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
        uVar7 = camera->flags | 0x2000;
      }
      else {
        uVar7 = camera->flags & 0xffffdfff;
      }
      camera->flags = uVar7;
      theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xffffffbf;
      cameraMode = mode;
      camera->mode = (short)mode;
      sVar3 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)camera_modeToIndex + ((mode << 0x10) >> 0xe)) * 3 +
                        (int)camera->presetIndex);
      camera->smooth = 8;
      (camera->data).Follow.stopTimer = -0x1a5e0000;
      (camera->focusRotVel).z = 0;
      camera->targetFocusDistance = sVar3;
      if (((int)sVar1 == 5) && (camera->focusInstance != (_Instance *)0x0)) {
        CAMERA_SetFocus(camera,&camera->targetFocusPoint);
      }
    }
    camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    uVar9 = *(undefined4 *)&(camera->targetFocusRotation).z;
    *(undefined4 *)&camera->collisionTargetFocusRotation =
         *(undefined4 *)&camera->targetFocusRotation;
    *(undefined4 *)&(camera->collisionTargetFocusRotation).z = uVar9;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Initialize(struct Camera *camera /*$s1*/)
 // line 773, offset 0x80015b30
	/* begin block 1 */
		// Start line: 774
		// Start offset: 0x80015B30
		// Variables:
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x80015DB8
	// End Line: 992

	/* begin block 2 */
		// Start line: 1692
	/* end block 2 */
	// End Line: 1693

void CAMERA_Initialize(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  memset(camera,0,0x4c4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetInstanceFocus(struct Camera *camera /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1017, offset 0x80015e30
	/* begin block 1 */
		// Start line: 2483
	/* end block 1 */
	// End Line: 2484

	/* begin block 2 */
		// Start line: 2487
	/* end block 2 */
	// End Line: 2488

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
    if (instance == (_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]) {
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
 // line 1051, offset 0x80015e90
	/* begin block 1 */
		// Start line: 2552
	/* end block 1 */
	// End Line: 2553

	/* begin block 2 */
		// Start line: 2553
	/* end block 2 */
	// End Line: 2554

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
 // line 1106, offset 0x80015eb4
	/* begin block 1 */
		// Start line: 2662
	/* end block 1 */
	// End Line: 2663

long CAMERA_LengthSVector(_SVector *sv)

{
  long lVar1;
  
  lVar1 = MATH3D_FastSqrt0((int)sv->x * (int)sv->x + (int)sv->y * (int)sv->y +
                           (int)sv->z * (int)sv->z);
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetValue(struct Camera *camera /*$a0*/, long index /*$a1*/, long value /*$a2*/)
 // line 1115, offset 0x80015f08
	/* begin block 1 */
		// Start line: 1117
		// Start offset: 0x80015F08
		// Variables:
	// 		long min; // $t1
	// 		long max; // $t0
	// 		long minTilt; // $a3
	// 		long maxTilt; // $a1
	/* end block 1 */
	// End offset: 0x8001632C
	// End Line: 1169

	/* begin block 2 */
		// Start line: 2680
	/* end block 2 */
	// End Line: 2681

	/* begin block 3 */
		// Start line: 2681
	/* end block 3 */
	// End Line: 2682

void CAMERA_SetValue(Camera *camera,long index,long value)

{
  short sVar1;
  bool bVar2;
  undefined *puVar3;
  int index_00;
  int iVar4;
  undefined *puVar5;
  int value_00;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  puVar8 = (undefined *)0x0;
  puVar7 = &DAT_00003e80;
  iVar6 = -0x1000;
  (&camera->minFocusDistance)[index] = value;
  iVar4 = 0x1000;
  if (camera->cineControl == 0) {
    theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xffffff7f;
  }
  else {
    theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ | 0x80;
  }
  sVar1 = camera->mode;
  if (sVar1 == 0xc) {
    puVar5 = (undefined *)camera->focusDistanceList[3];
    puVar3 = (undefined *)camera->focusDistanceList[4];
    if ((int)puVar5 < (int)puVar3) {
      bVar2 = (int)puVar3 < (int)puVar5;
      puVar8 = (undefined *)camera->focusDistanceList[5];
      if ((int)puVar5 < (int)(undefined *)camera->focusDistanceList[5]) {
        puVar8 = puVar5;
      }
    }
    else {
      puVar8 = (undefined *)camera->focusDistanceList[5];
      if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[5]) {
        puVar8 = puVar3;
      }
      puVar5 = (undefined *)camera->focusDistanceList[3];
      puVar3 = (undefined *)camera->focusDistanceList[4];
      bVar2 = (int)puVar3 < (int)puVar5;
    }
    if (bVar2) {
      puVar7 = (undefined *)camera->focusDistanceList[5];
      if ((int)(undefined *)camera->focusDistanceList[5] < (int)puVar5) {
        puVar7 = puVar5;
      }
    }
    else {
      puVar7 = (undefined *)camera->focusDistanceList[5];
      if ((int)(undefined *)camera->focusDistanceList[5] < (int)puVar3) {
        puVar7 = puVar3;
      }
    }
    index_00 = camera->tiltList[3];
    iVar4 = camera->tiltList[4];
    if (index_00 < iVar4) {
      iVar6 = camera->tiltList[5];
      if (index_00 < camera->tiltList[5]) {
        iVar6 = index_00;
      }
    }
    else {
      iVar6 = camera->tiltList[5];
      if (iVar4 < camera->tiltList[5]) {
        iVar6 = iVar4;
      }
    }
    value_00 = camera->tiltList[3];
    index_00 = camera->tiltList[4];
    if (value_00 <= index_00) {
      iVar4 = camera->tiltList[5];
      bVar2 = iVar4 < index_00;
LAB_800162d0:
      if (bVar2) {
        iVar4 = index_00;
      }
      goto LAB_800162dc;
    }
    iVar4 = camera->tiltList[5];
    bVar2 = iVar4 < value_00;
  }
  else {
    if (sVar1 < 0xd) {
      if (sVar1 != 0) goto LAB_800162dc;
      puVar5 = (undefined *)camera->focusDistanceList[0];
      puVar3 = (undefined *)camera->focusDistanceList[1];
      if ((int)puVar5 < (int)puVar3) {
        bVar2 = (int)puVar3 < (int)puVar5;
        puVar8 = (undefined *)camera->focusDistanceList[2];
        if ((int)puVar5 < (int)(undefined *)camera->focusDistanceList[2]) {
          puVar8 = puVar5;
        }
      }
      else {
        puVar8 = (undefined *)camera->focusDistanceList[2];
        if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[2]) {
          puVar8 = puVar3;
        }
        puVar5 = (undefined *)camera->focusDistanceList[0];
        puVar3 = (undefined *)camera->focusDistanceList[1];
        bVar2 = (int)puVar3 < (int)puVar5;
      }
      if (bVar2) {
        puVar7 = (undefined *)camera->focusDistanceList[2];
        if ((int)(undefined *)camera->focusDistanceList[2] < (int)puVar5) {
          puVar7 = puVar5;
        }
      }
      else {
        puVar7 = (undefined *)camera->focusDistanceList[2];
        if ((int)(undefined *)camera->focusDistanceList[2] < (int)puVar3) {
          puVar7 = puVar3;
        }
      }
      index_00 = camera->tiltList[0];
      iVar4 = camera->tiltList[1];
      if (index_00 < iVar4) {
        iVar6 = camera->tiltList[2];
        if (index_00 < camera->tiltList[2]) {
          iVar6 = index_00;
        }
      }
      else {
        iVar6 = camera->tiltList[2];
        if (iVar4 < camera->tiltList[2]) {
          iVar6 = iVar4;
        }
      }
      value_00 = camera->tiltList[0];
      index_00 = camera->tiltList[1];
      if (value_00 <= index_00) {
        iVar4 = camera->tiltList[2];
        bVar2 = iVar4 < index_00;
        goto LAB_800162d0;
      }
      iVar4 = camera->tiltList[2];
      bVar2 = iVar4 < value_00;
    }
    else {
      if (sVar1 != 0xd) goto LAB_800162dc;
      puVar5 = (undefined *)camera->focusDistanceList[6];
      puVar3 = (undefined *)camera->focusDistanceList[7];
      if ((int)puVar5 < (int)puVar3) {
        bVar2 = (int)puVar3 < (int)puVar5;
        puVar8 = (undefined *)camera->focusDistanceList[8];
        if ((int)puVar5 < (int)(undefined *)camera->focusDistanceList[8]) {
          puVar8 = puVar5;
        }
      }
      else {
        puVar8 = (undefined *)camera->focusDistanceList[8];
        if ((int)puVar3 < (int)(undefined *)camera->focusDistanceList[8]) {
          puVar8 = puVar3;
        }
        puVar5 = (undefined *)camera->focusDistanceList[6];
        puVar3 = (undefined *)camera->focusDistanceList[7];
        bVar2 = (int)puVar3 < (int)puVar5;
      }
      if (bVar2) {
        puVar7 = (undefined *)camera->focusDistanceList[8];
        if ((int)(undefined *)camera->focusDistanceList[8] < (int)puVar5) {
          puVar7 = puVar5;
        }
      }
      else {
        puVar7 = (undefined *)camera->focusDistanceList[8];
        if ((int)(undefined *)camera->focusDistanceList[8] < (int)puVar3) {
          puVar7 = puVar3;
        }
      }
      index_00 = camera->tiltList[6];
      iVar4 = camera->tiltList[7];
      if (index_00 < iVar4) {
        iVar6 = camera->tiltList[8];
        if (index_00 < camera->tiltList[8]) {
          iVar6 = index_00;
        }
      }
      else {
        iVar6 = camera->tiltList[8];
        if (iVar4 < camera->tiltList[8]) {
          iVar6 = iVar4;
        }
      }
      value_00 = camera->tiltList[6];
      if (value_00 <= camera->tiltList[7]) {
        CAMERA_SetValue(camera,index_00,value_00);
        return;
      }
      iVar4 = camera->tiltList[8];
      bVar2 = iVar4 < value_00;
    }
  }
  if (bVar2) {
    iVar4 = value_00;
  }
LAB_800162dc:
  if ((int)camera->targetFocusDistance < (int)puVar8) {
    camera->targetFocusDistance = (short)puVar8;
  }
  else {
    if ((int)puVar7 < (int)camera->targetFocusDistance) {
      camera->targetFocusDistance = (short)puVar7;
    }
  }
  index_00 = (int)(camera->targetFocusRotation).x;
  if (iVar6 <= index_00) {
    if (iVar4 < index_00) {
      (camera->targetFocusRotation).x = (short)iVar4;
    }
    return;
  }
  (camera->targetFocusRotation).x = (short)iVar6;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_AngleDifference(short angle0 /*$t0*/, short angle1 /*$a3*/)
 // line 1172, offset 0x80016334
	/* begin block 1 */
		// Start line: 2798
	/* end block 1 */
	// End Line: 2799

	/* begin block 2 */
		// Start line: 2799
	/* end block 2 */
	// End Line: 2800

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
 // line 1189, offset 0x800163ac
	/* begin block 1 */
		// Start line: 2832
	/* end block 1 */
	// End Line: 2833

short CAMERA_SignedAngleDifference(short angle0,short angle1)

{
                    /* WARNING: Subroutine does not return */
  AngleDiff(angle1,angle0);
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ CAMERA_QueryMode(struct Camera *camera /*$s0*/)
 // line 1208, offset 0x800163dc
	/* begin block 1 */
		// Start line: 1209
		// Start offset: 0x800163DC
		// Variables:
	// 		unsigned long mode; // $s0
	/* end block 1 */
	// End offset: 0x80016464
	// End Line: 1227

	/* begin block 2 */
		// Start line: 2871
	/* end block 2 */
	// End Line: 2872

ulong CAMERA_QueryMode(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(camera->focusInstance,10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMaxVel(struct Camera *camera /*$s1*/)
 // line 1232, offset 0x80016478
	/* begin block 1 */
		// Start line: 1233
		// Start offset: 0x80016478
		// Variables:
	// 		long extraVel; // $s0
	// 		long targetMaxVel; // $v0
	// 		struct _SVector cam_dist; // stack offset -24
	// 		static long maxVelAccl; // offset 0x8
	// 		static long maxVelVel; // offset 0xc

		/* begin block 1.1 */
			// Start line: 1233
			// Start offset: 0x80016478
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
		// End offset: 0x80016478
		// End Line: 1233
	/* end block 1 */
	// End offset: 0x80016570
	// End Line: 1265

	/* begin block 2 */
		// Start line: 2919
	/* end block 2 */
	// End Line: 2920

void CAMERA_SetMaxVel(Camera *camera)

{
  long lVar1;
  ushort uVar2;
  int iVar3;
  _SVector local_18;
  
  local_18.x = (camera->focusPoint).x - (camera->targetFocusPoint).x;
  local_18.y = (camera->focusPoint).y - (camera->targetFocusPoint).y;
  local_18.z = (camera->focusPoint).z - (camera->targetFocusPoint).z;
  iVar3 = ((int)camera->focusDistance / 100) * 0x10000 >> 0x10;
  if (iVar3 < 0x14) {
    iVar3 = 0x14;
  }
  if (camera->forced_movement != 0) {
    iVar3 = iVar3 * 5;
  }
  lVar1 = CAMERA_LengthSVector(&local_18);
  maxVelAccl_63 = (((short)lVar1 + iVar3) - (int)camera->maxVel >> 2) - maxVelVel_64;
  maxVelVel_64 = maxVelVel_64 + maxVelAccl_63;
  uVar2 = camera->maxVel + (short)maxVelVel_64;
  camera->maxVel = uVar2;
  if ((int)((uint)uVar2 << 0x10) < 1) {
    camera->maxVel = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetTarget(struct Camera *camera /*$s0*/, struct _Position *pos /*$s1*/)
 // line 1267, offset 0x80016584
	/* begin block 1 */
		// Start line: 1268
		// Start offset: 0x80016584
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1268
			// Start offset: 0x80016584
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80016584
		// End Line: 1268
	/* end block 1 */
	// End offset: 0x80016584
	// End Line: 1268

	/* begin block 2 */
		// Start line: 3007
	/* end block 2 */
	// End Line: 3008

void CAMERA_SetTarget(Camera *camera,_Position *pos)

{
  short sVar1;
  long lVar2;
  _SVector local_18;
  
  CAMERA_CalcRotation(&camera->targetFocusRotation,pos,(_Position *)camera);
  local_18.x = pos->x - (camera->core).position.x;
  local_18.y = pos->y - (camera->core).position.y;
  local_18.z = pos->z - (camera->core).position.z;
  lVar2 = CAMERA_LengthSVector(&local_18);
  sVar1 = (short)lVar2;
  camera->focusDistance = sVar1;
  camera->targetFocusDistance = sVar1;
  camera->collisionTargetFocusDistance = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcPosition(struct _Position *position /*$s3*/, struct _Position *base /*$s2*/, struct _Rotation *rotation /*$s1*/, short distance /*$a3*/)
 // line 1278, offset 0x80016600
	/* begin block 1 */
		// Start line: 1279
		// Start offset: 0x80016600
		// Variables:
	// 		struct SVECTOR sv; // stack offset -96
	// 		struct VECTOR v; // stack offset -88
	// 		struct MATRIX matrix; // stack offset -72
	// 		struct _Vector vectorPos; // stack offset -40

		/* begin block 1.1 */
			// Start line: 1279
			// Start offset: 0x80016600
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80016600
		// End Line: 1279
	/* end block 1 */
	// End offset: 0x80016600
	// End Line: 1279

	/* begin block 2 */
		// Start line: 3032
	/* end block 2 */
	// End Line: 3033

void CAMERA_CalcPosition(_Position *position,_Position *base,_Rotation *rotation,short distance)

{
  MATRIX local_48;
  
  MATH3D_SetUnityMatrix(&local_48);
                    /* WARNING: Subroutine does not return */
  RotMatrixX((int)rotation->x,(int)&local_48);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetFocus(struct Camera *camera /*$s3*/, struct _Position *targetfocusPoint /*$s1*/)
 // line 1319, offset 0x80016728
	/* begin block 1 */
		// Start line: 1320
		// Start offset: 0x80016728
		// Variables:
	// 		struct _Instance *focusInstance; // $s0
	// 		struct _Model *model; // $v0
	// 		struct _SVector temp1; // stack offset -64
	// 		struct _SVector offset; // stack offset -56
	// 		struct _SVector *segPosVector; // $v1
	// 		struct _Vector temp2; // stack offset -48

		/* begin block 1.1 */
			// Start line: 1335
			// Start offset: 0x80016774
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $s2
		/* end block 1.1 */
		// End offset: 0x80016774
		// End Line: 1335

		/* begin block 1.2 */
			// Start line: 1335
			// Start offset: 0x80016774
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $t1
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x80016774
		// End Line: 1335

		/* begin block 1.3 */
			// Start line: 1345
			// Start offset: 0x800167F8

			/* begin block 1.3.1 */
				// Start line: 1347
				// Start offset: 0x800167F8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a2
			// 		short _x1; // $a3
			// 		short _y1; // $t0
			// 		short _z1; // $v1
			/* end block 1.3.1 */
			// End offset: 0x800167F8
			// End Line: 1347
		/* end block 1.3 */
		// End offset: 0x80016848
		// End Line: 1355

		/* begin block 1.4 */
			// Start line: 1367
			// Start offset: 0x8001688C
			// Variables:
		// 		struct _Instance *instance; // $v0
		// 		struct _SVector output; // stack offset -32

			/* begin block 1.4.1 */
				// Start line: 1373
				// Start offset: 0x8001689C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.4.1 */
			// End offset: 0x8001689C
			// End Line: 1373

			/* begin block 1.4.2 */
				// Start line: 1380
				// Start offset: 0x800168D4
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v1; // $v0
			/* end block 1.4.2 */
			// End offset: 0x800168D4
			// End Line: 1380
		/* end block 1.4 */
		// End offset: 0x800168D4
		// End Line: 1380

		/* begin block 1.5 */
			// Start line: 1385
			// Start offset: 0x800168D4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x800168F0
		// End Line: 1385

		/* begin block 1.6 */
			// Start line: 1388
			// Start offset: 0x800168F0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x800168F0
		// End Line: 1388
	/* end block 1 */
	// End offset: 0x80016984
	// End Line: 1425

	/* begin block 2 */
		// Start line: 3127
	/* end block 2 */
	// End Line: 3128

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
 // line 1427, offset 0x800169a4
	/* begin block 1 */
		// Start line: 3374
	/* end block 1 */
	// End Line: 3375

	/* begin block 2 */
		// Start line: 3375
	/* end block 2 */
	// End Line: 3376

void CAMERA_Lock(Camera *camera,long lock)

{
  camera->lock = camera->lock | lock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Unlock(struct Camera *camera /*$a0*/, long unlock /*$a1*/)
 // line 1432, offset 0x800169b8
	/* begin block 1 */
		// Start line: 3384
	/* end block 1 */
	// End Line: 3385

	/* begin block 2 */
		// Start line: 3385
	/* end block 2 */
	// End Line: 3386

void CAMERA_Unlock(Camera *camera,long unlock)

{
  camera->lock = camera->lock & ~unlock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetSmoothValue(struct Camera *camera /*$a0*/, long smooth /*$a1*/)
 // line 1437, offset 0x800169cc
	/* begin block 1 */
		// Start line: 3394
	/* end block 1 */
	// End Line: 3395

	/* begin block 2 */
		// Start line: 3396
	/* end block 2 */
	// End Line: 3397

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
 // line 1450, offset 0x80016a1c
	/* begin block 1 */
		// Start line: 3420
	/* end block 1 */
	// End Line: 3421

void CAMERA_SetTimer(Camera *camera,long time)

{
  CAMERA_Save(camera,-1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_tilt(struct Camera *camera /*$a0*/, long tilt /*$a1*/)
 // line 1456, offset 0x80016a3c
	/* begin block 1 */
		// Start line: 3432
	/* end block 1 */
	// End Line: 3433

	/* begin block 2 */
		// Start line: 3433
	/* end block 2 */
	// End Line: 3434

void CAMERA_SetTimer(Camera *camera,long time)

{
  short sVar1;
  ushort uVar2;
  
  camera->tiltState = 3;
  sVar1 = camera->smooth;
  uVar2 = (ushort)time & 0xfff;
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
 // line 1474, offset 0x80016a78
	/* begin block 1 */
		// Start line: 3471
	/* end block 1 */
	// End Line: 3472

	/* begin block 2 */
		// Start line: 3472
	/* end block 2 */
	// End Line: 3473

void CAMERA_Adjust_distance(Camera *camera,long dist)

{
  short sVar1;
  
  sVar1 = (short)dist;
  camera->signalFocusDistance = sVar1;
  camera->distanceState = 3;
  if (camera->maxFocusDistance < (int)sVar1) {
    camera->signalFocusDistance = *(short *)&camera->maxFocusDistance;
  }
  else {
    if ((int)sVar1 < camera->minFocusDistance) {
      camera->signalFocusDistance = *(short *)&camera->minFocusDistance;
    }
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
 // line 1492, offset 0x80016af4
	/* begin block 1 */
		// Start line: 3509
	/* end block 1 */
	// End Line: 3510

void CAMERA_Adjust_rotation(Camera *camera,long rotation)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_AngleDifference((short)rotation,(camera->targetFocusRotation).z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_roll(long roll_degrees /*$s0*/, int frames /*$s1*/)
 // line 1511, offset 0x80016b78
	/* begin block 1 */
		// Start line: 3555
	/* end block 1 */
	// End Line: 3556

void CAMERA_Adjust_roll(long roll_degrees,int frames)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  
  uVar3 = roll_degrees & 0xfff;
  if (frames == 0) {
    current_roll_amount = uVar3 << 0xc;
    roll_inc = 0;
  }
  else {
    lVar2 = current_roll_amount;
    if (current_roll_amount < 0) {
      lVar2 = current_roll_amount + 0xfff;
    }
    uVar1 = CAMERA_SignedAngleDifference((short)uVar3,(short)((uint)(lVar2 << 4) >> 0x10));
    roll_inc = ((int)((uint)uVar1 << 0x10) >> 4) / frames;
  }
  roll_target = uVar3 << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust(struct Camera *camera /*$s1*/, long adjust /*$s2*/)
 // line 1527, offset 0x80016bfc
	/* begin block 1 */
		// Start line: 1528
		// Start offset: 0x80016BFC

		/* begin block 1.1 */
			// Start line: 1532
			// Start offset: 0x80016C24

			/* begin block 1.1.1 */
				// Start line: 1535
				// Start offset: 0x80016C30
				// Variables:
			// 		struct _SVector dv; // stack offset -24

				/* begin block 1.1.1.1 */
					// Start line: 1536
					// Start offset: 0x80016C30
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
				// End offset: 0x80016C30
				// End Line: 1536
			/* end block 1.1.1 */
			// End offset: 0x80016C74
			// End Line: 1551
		/* end block 1.1 */
		// End offset: 0x80016CA4
		// End Line: 1582
	/* end block 1 */
	// End offset: 0x80016CA4
	// End Line: 1587

	/* begin block 2 */
		// Start line: 3589
	/* end block 2 */
	// End Line: 3590

void CAMERA_Adjust(Camera *camera,long adjust)

{
  long dist;
  _CameraKey *p_Var1;
  _SVector local_18;
  
  p_Var1 = camera->cameraKey;
  if (p_Var1 != (_CameraKey *)0x0) {
    if ((adjust & 1U) != 0) {
      local_18.x = p_Var1->x - p_Var1->tx;
      local_18.y = p_Var1->y - p_Var1->ty;
      local_18.z = p_Var1->z - p_Var1->tz;
      dist = CAMERA_LengthSVector(&local_18);
      CAMERA_Adjust_distance(camera,dist);
    }
    if ((adjust & 2U) != 0) {
      CAMERA_SetTimer(camera,(int)p_Var1->rx);
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
 // line 1590, offset 0x80016cbc
	/* begin block 1 */
		// Start line: 3715
	/* end block 1 */
	// End Line: 3716

	/* begin block 2 */
		// Start line: 3716
	/* end block 2 */
	// End Line: 3717

void CAMERA_ChangeTo(Camera *camera,_CameraKey *cameraKey)

{
  camera->cameraKey = cameraKey;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetShake(struct Camera *camera /*$t0*/, long shake /*$a1*/, long scale /*$a2*/)
 // line 1595, offset 0x80016cc4
	/* begin block 1 */
		// Start line: 1596
		// Start offset: 0x80016CC4
		// Variables:
	// 		int shock; // $a0
	// 		int duration; // $a1
	/* end block 1 */
	// End offset: 0x80016D5C
	// End Line: 1615

	/* begin block 2 */
		// Start line: 3725
	/* end block 2 */
	// End Line: 3726

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
  GAMEPAD_Shock1(motor1_speed,motor1_time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Decouple_AngleMoveToward(short *current_ptr /*$a0*/, short destination /*$a1*/, short step /*$a3*/)
 // line 1618, offset 0x80016d74
	/* begin block 1 */
		// Start line: 3771
	/* end block 1 */
	// End Line: 3772

void CAMERA_Unlock(Camera *camera,long unlock)

{
  short in_a2;
  
  if (StreamTracker.StreamList[11]._4_4_ != 0x1000) {
    in_a2 = (short)((uint)(in_a2 * StreamTracker.StreamList[11]._4_4_) >> 0xc);
  }
  AngleMoveToward((short *)camera,(short)unlock,in_a2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampValue(long dampMode /*$a0*/, short *sourceVal /*$a1*/, short targetVal /*$t2*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1626, offset 0x80016dc4
	/* begin block 1 */
		// Start line: 1627
		// Start offset: 0x80016DC4
		// Variables:
	// 		short maxVel; // $t0
	// 		short useVel; // $a0
	/* end block 1 */
	// End offset: 0x80016F70
	// End Line: 1685

	/* begin block 2 */
		// Start line: 3787
	/* end block 2 */
	// End Line: 3788

void CriticalDampValue(long dampMode,short *sourceVal,short targetVal,short *vel,short *accl,
                      int smooth)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  iVar3 = (int)(short)smooth;
  if (iVar3 == 0) {
    *sourceVal = targetVal;
    return;
  }
  if (iVar3 < 0) {
    smooth._0_2_ = (short)(-0x1000 / iVar3);
  }
  if (dampMode != 1) {
    if (dampMode < 2) {
      if (dampMode == 0) {
        CAMERA_Adjust_distance((Camera *)0x0,(long)sourceVal);
        return;
      }
      goto LAB_80016f54;
    }
    if ((6 < dampMode) || (dampMode < 5)) goto LAB_80016f54;
  }
  if (dampMode == 5) {
    CAMERA_Adjust_rotation((Camera *)((int)&mainMenuScreen + 1),(long)sourceVal);
    return;
  }
  if (dampMode == 6) {
    CAMERA_Adjust_rotation((Camera *)((int)&mainMenuScreen + 2),(long)sourceVal);
    return;
  }
  *accl = (short)((int)(((uint)(ushort)targetVal - (uint)(ushort)*sourceVal) * 0x10000) >> 0x12) -
          *vel;
  uVar1 = *vel;
  uVar2 = *accl;
  sVar4 = (short)((uint)uVar1 + (uint)uVar2);
  *vel = sVar4;
  iVar3 = (int)(((uint)uVar1 + (uint)uVar2) * 0x10000) >> 0x10;
  iVar5 = (int)(short)smooth;
  if (iVar5 < iVar3) {
    *vel = (short)smooth;
    sVar4 = (short)smooth;
    if (theCamera.tiltList[0][0] != 0x1000) {
      sVar4 = (short)((uint)(iVar5 * theCamera.tiltList[0][0]) >> 0xc);
    }
  }
  else {
    if (iVar3 < -iVar5) {
      *vel = -(short)smooth;
      sVar4 = -(short)smooth;
      if (theCamera.tiltList[0][0] != 0x1000) {
        sVar4 = (short)((uint)-(iVar5 * theCamera.tiltList[0][0]) >> 0xc);
      }
    }
  }
  *sourceVal = *sourceVal + sVar4;
LAB_80016f54:
  if (*vel != 0) {
    return;
  }
  *sourceVal = targetVal;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampPosition(long dampMode /*$a0*/, struct _Position *position /*$s1*/, struct _Position *targetPos /*$s3*/, struct _SVector *vel /*$s2*/, struct _SVector *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1738, offset 0x80016f78
	/* begin block 1 */
		// Start line: 1739
		// Start offset: 0x80016F78
		// Variables:
	// 		long length; // $s0
	// 		struct _Vector vector; // stack offset -48
	// 		struct _SVector svector; // stack offset -32
	// 		short maxVel; // $s4
	// 		int shift; // $a3

		/* begin block 1.1 */
			// Start line: 1760
			// Start offset: 0x80016FF4
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.1 */
		// End offset: 0x80016FF4
		// End Line: 1760

		/* begin block 1.2 */
			// Start line: 1775
			// Start offset: 0x800170B0
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.2 */
		// End offset: 0x800170B0
		// End Line: 1775

		/* begin block 1.3 */
			// Start line: 1809
			// Start offset: 0x80017254
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $s2
		/* end block 1.3 */
		// End offset: 0x80017254
		// End Line: 1809

		/* begin block 1.4 */
			// Start line: 1813
			// Start offset: 0x800172A8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.4 */
		// End offset: 0x800172A8
		// End Line: 1813

		/* begin block 1.5 */
			// Start line: 1817
			// Start offset: 0x800172A8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.5 */
		// End offset: 0x800172A8
		// End Line: 1817

		/* begin block 1.6 */
			// Start line: 1824
			// Start offset: 0x80017344
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $a1
		/* end block 1.6 */
		// End offset: 0x80017344
		// End Line: 1824

		/* begin block 1.7 */
			// Start line: 1838
			// Start offset: 0x800174D4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.7 */
		// End offset: 0x800174D4
		// End Line: 1838

		/* begin block 1.8 */
			// Start line: 1869
			// Start offset: 0x80017604
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.8 */
		// End offset: 0x8001761C
		// End Line: 1869
	/* end block 1 */
	// End offset: 0x8001761C
	// End Line: 1871

	/* begin block 2 */
		// Start line: 4013
	/* end block 2 */
	// End Line: 4014

void CriticalDampPosition
               (long dampMode,_Position *position,_Position *targetPos,_SVector *vel,_SVector *accl,
               int smooth)

{
  short sVar1;
  short sVar2;
  long lVar3;
  long lVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  _SVector local_20;
  
  iVar7 = (int)(short)smooth;
  if (iVar7 == 0) {
LAB_80017604:
    sVar6 = targetPos->y;
    sVar5 = targetPos->z;
    position->x = targetPos->x;
    position->y = sVar6;
    position->z = sVar5;
    return;
  }
  if (iVar7 < 0) {
    smooth._0_2_ = (short)(-0x1000 / iVar7);
  }
  switch(dampMode) {
  case 0:
    sVar6 = targetPos->y;
    sVar5 = targetPos->z;
    sVar1 = position->z;
    sVar2 = position->y;
    accl->x = (short)((int)targetPos->x - (int)position->x >> 2) - vel->x;
    accl->y = (short)((int)sVar6 - (int)sVar2 >> 2) - vel->y;
    accl->z = (short)((int)sVar5 - (int)sVar1 >> 2) - vel->z;
    vel->x = vel->x + accl->x;
    vel->y = vel->y + accl->y;
    vel->z = vel->z + accl->z;
    break;
  case 1:
  case 5:
    iVar7 = 2;
    if (dampMode == 5) {
      iVar7 = 1;
    }
    sVar6 = targetPos->y;
    sVar5 = targetPos->z;
    sVar1 = position->z;
    sVar2 = position->y;
    accl->x = (short)((int)targetPos->x - (int)position->x >> iVar7) - vel->x;
    accl->y = (short)((int)sVar6 - (int)sVar2 >> iVar7) - vel->y;
    accl->z = (short)((int)sVar5 - (int)sVar1 >> iVar7) - vel->z;
    vel->x = vel->x + accl->x;
    vel->y = vel->y + accl->y;
    vel->z = vel->z + accl->z;
    lVar3 = CAMERA_LengthSVector(vel);
    iVar7 = (int)(short)smooth;
    if (lVar3 <= iVar7) break;
    vel->x = (short)((vel->x * iVar7) / lVar3);
    vel->y = (short)((vel->y * iVar7) / lVar3);
    vel->z = (short)((vel->z * iVar7) / lVar3);
    if (theCamera.tiltList[0][0] == 0x1000) break;
    position->x = position->x + (short)((uint)(vel->x * theCamera.tiltList[0][0]) >> 0xc);
    position->y = position->y + (short)((uint)(vel->y * theCamera.tiltList[0][0]) >> 0xc);
    sVar6 = position->z;
    sVar5 = (short)((uint)(vel->z * theCamera.tiltList[0][0]) >> 0xc);
    goto code_r0x800175f8;
  default:
    goto switchD_80016fec_caseD_2;
  case 3:
    local_20.x = targetPos->x - position->x;
    local_20.y = targetPos->y - position->y;
    local_20.z = targetPos->z - position->z;
    lVar3 = CAMERA_LengthSVector(&local_20);
    iVar7 = (int)(short)smooth;
    if (iVar7 <= lVar3) {
      position->x = position->x + (short)((local_20.x * iVar7) / lVar3);
      position->z = position->z + (short)((local_20.z * iVar7) / lVar3);
      position->y = position->y + (short)((local_20.y * iVar7) / lVar3);
      return;
    }
    goto LAB_80017604;
  case 4:
    iVar7 = (uint)(ushort)targetPos->x - (uint)(ushort)position->x;
    local_20.y = targetPos->y - position->y;
    local_20.z = targetPos->z - position->z;
    local_20.x = (short)iVar7;
    accl->x = (short)(iVar7 * 0x10000 >> 0x12) - vel->x;
    accl->y = (local_20.y >> 2) - vel->y;
    accl->z = (local_20.z >> 2) - vel->z;
    if (local_20.x < 1) {
      sVar6 = accl->x;
      if (0 < accl->x) {
        sVar6 = 0;
      }
    }
    else {
      sVar6 = accl->x;
      if (accl->x < 0) {
        sVar6 = 0;
      }
    }
    accl->x = sVar6;
    if (local_20.y < 1) {
      sVar6 = accl->y;
      if (0 < accl->y) {
        sVar6 = 0;
      }
    }
    else {
      sVar6 = accl->y;
      if (accl->y < 0) {
        sVar6 = 0;
      }
    }
    accl->y = sVar6;
    if (local_20.z < 1) {
      sVar6 = accl->z;
      if (0 < accl->z) {
        sVar6 = 0;
      }
    }
    else {
      sVar6 = accl->z;
      if (accl->z < 0) {
        sVar6 = 0;
      }
    }
    accl->z = sVar6;
    vel->x = vel->x + accl->x;
    vel->y = vel->y + accl->y;
    vel->z = vel->z + accl->z;
    lVar3 = CAMERA_LengthSVector(vel);
    lVar4 = CAMERA_LengthSVector(&local_20);
    if (lVar4 < lVar3) goto LAB_80017604;
    iVar7 = (int)(short)smooth;
    if (iVar7 <= lVar3) {
      vel->x = (short)((vel->x * iVar7) / lVar3);
      vel->y = (short)((vel->y * iVar7) / lVar3);
      vel->z = (short)((vel->z * iVar7) / lVar3);
      if (theCamera.tiltList[0][0] != 0x1000) {
        position->x = position->x + (short)((uint)(vel->x * theCamera.tiltList[0][0]) >> 0xc);
        position->y = position->y + (short)((uint)(vel->y * theCamera.tiltList[0][0]) >> 0xc);
        sVar6 = position->z;
        sVar5 = (short)((uint)(vel->z * theCamera.tiltList[0][0]) >> 0xc);
        goto code_r0x800175f8;
      }
    }
  }
  position->x = position->x + vel->x;
  position->y = position->y + vel->y;
  sVar6 = position->z;
  sVar5 = vel->z;
code_r0x800175f8:
  position->z = sVar6 + sVar5;
switchD_80016fec_caseD_2:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampAngle(long dampMode /*$a0*/, short *currentVal /*$s0*/, short target /*$t1*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1873, offset 0x8001763c
	/* begin block 1 */
		// Start line: 1874
		// Start offset: 0x8001763C
		// Variables:
	// 		short current; // stack offset -16
	/* end block 1 */
	// End offset: 0x80017698
	// End Line: 1889

	/* begin block 2 */
		// Start line: 4301
	/* end block 2 */
	// End Line: 4302

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
 // line 1894, offset 0x800176dc
	/* begin block 1 */
		// Start line: 1895
		// Start offset: 0x800176DC
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1895
			// Start offset: 0x800176DC
			// Variables:
		// 		short _x0; // $a2
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x800176DC
		// End Line: 1895
	/* end block 1 */
	// End offset: 0x800176DC
	// End Line: 1895

	/* begin block 2 */
		// Start line: 4353
	/* end block 2 */
	// End Line: 4354

short CAMERA_CalcZRotation(_Position *target,_Position *position)

{
  short sVar1;
  short sVar2;
  _SVector local_10;
  
  sVar2 = position->x - target->x;
  sVar1 = position->y - target->y;
  local_10.z = 0;
  local_10.x = sVar2;
  local_10.y = sVar1;
  CAMERA_LengthSVector(&local_10);
                    /* WARNING: Subroutine does not return */
  ratan2((int)sVar1,(int)sVar2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcRotation(struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a1*/, struct _Position *position /*$a2*/)
 // line 1911, offset 0x80017754
	/* begin block 1 */
		// Start line: 1912
		// Start offset: 0x80017754
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1912
			// Start offset: 0x80017754
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a0
		// 		short _y1; // $a2
		// 		short _z1; // $a1
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80017754
		// End Line: 1912
	/* end block 1 */
	// End offset: 0x80017754
	// End Line: 1912

	/* begin block 2 */
		// Start line: 4392
	/* end block 2 */
	// End Line: 4393

void CAMERA_CalcRotation(_Rotation *rotation,_Position *target,_Position *position)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  _SVector local_10;
  
  sVar1 = position->z;
  sVar2 = target->z;
  local_10.x = position->x - target->x;
  local_10.y = position->y - target->y;
  local_10.z = 0;
  uVar3 = CAMERA_LengthSVector(&local_10);
                    /* WARNING: Subroutine does not return */
  ratan2((int)(short)(sVar1 - sVar2),uVar3);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFSRotation(struct Camera *camera /*$a0*/, struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a2*/, struct _Position *position /*$a3*/)
 // line 1928, offset 0x800177f0
	/* begin block 1 */
		// Start line: 1929
		// Start offset: 0x800177F0
		// Variables:
	// 		struct _SVector sv; // stack offset -32
	// 		struct _SVector onPlane; // stack offset -24
	// 		struct _SVector sv2; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1929
			// Start offset: 0x800177F0
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $v0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x800177F0
		// End Line: 1929

		/* begin block 1.2 */
			// Start line: 1929
			// Start offset: 0x800177F0
			// Variables:
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x800177F0
		// End Line: 1929
	/* end block 1 */
	// End offset: 0x800177F0
	// End Line: 1929

	/* begin block 2 */
		// Start line: 4430
	/* end block 2 */
	// End Line: 4431

void CAMERA_CalcFSRotation(undefined4 param_1,undefined4 param_2,short *param_3,short *param_4)

{
  uint uVar1;
  _SVector local_18;
  short local_10;
  short local_e;
  short local_c;
  
  local_18.x = *param_4 - *param_3;
  local_18.y = param_4[1] - param_3[1];
  local_c = param_4[2] - param_3[2];
  local_18.z = 0;
  local_10 = local_18.x;
  local_e = local_18.y;
  uVar1 = CAMERA_LengthSVector(&local_18);
                    /* WARNING: Subroutine does not return */
  ratan2((int)local_c,uVar1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Relocate(struct Camera *camera /*$a0*/, struct _SVector *offset /*$a1*/, int streamSignalFlag /*$a2*/)
 // line 1948, offset 0x8001789c
	/* begin block 1 */
		// Start line: 4474
	/* end block 1 */
	// End Line: 4475

	/* begin block 2 */
		// Start line: 4479
	/* end block 2 */
	// End Line: 4480

void CAMERA_Relocate(short *param_1,short *param_2,int param_3)

{
  if ((param_3 != 0) || (param_1[0x78] != 5)) {
    *param_1 = *param_1 + *param_2;
    param_1[1] = param_1[1] + param_2[1];
    param_1[2] = param_1[2] + param_2[2];
    param_1[0x80] = param_1[0x80] + *param_2;
    param_1[0x81] = param_1[0x81] + param_2[1];
    param_1[0x82] = param_1[0x82] + param_2[2];
    param_1[0xcc] = param_1[0xcc] + *param_2;
    param_1[0xcd] = param_1[0xcd] + param_2[1];
    param_1[0xce] = param_1[0xce] + param_2[2];
    param_1[0xd5] = param_1[0xd5] + *param_2;
    param_1[0xd6] = param_1[0xd6] + param_2[1];
    param_1[0xd7] = param_1[0xd7] + param_2[2];
    param_1[0x89] = param_1[0x89] + *param_2;
    param_1[0x8a] = param_1[0x8a] + param_2[1];
    param_1[0x8b] = param_1[0x8b] + param_2[2];
  }
  return;
}



// decompiled code
// original method signature: 
// struct _TFace * /*$ra*/ CAMERA_SphereToSphereWithLines(struct Camera *camera /*$s6*/, struct CameraCollisionInfo *colInfo /*stack 4*/, int secondcheck_flag /*stack 8*/)
 // line 2017, offset 0x800179e8
	/* begin block 1 */
		// Start line: 2018
		// Start offset: 0x800179E8
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
			// Start line: 2133
			// Start offset: 0x80017CF4
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
		// End offset: 0x80017CF4
		// End Line: 2133

		/* begin block 1.2 */
			// Start line: 2133
			// Start offset: 0x80017CF4
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
		// End offset: 0x80017CF4
		// End Line: 2133

		/* begin block 1.3 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.4 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.5 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.6 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.7 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.8 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.9 */
			// Start line: 2146
			// Start offset: 0x80017E00
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
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.10 */
			// Start line: 2146
			// Start offset: 0x80017E00
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t2
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v0
		/* end block 1.10 */
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.11 */
			// Start line: 2146
			// Start offset: 0x80017E00
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.11 */
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.12 */
			// Start line: 2146
			// Start offset: 0x80017E00
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a2
		// 		struct _Position *_v1; // $v0
		/* end block 1.12 */
		// End offset: 0x80017E00
		// End Line: 2146

		/* begin block 1.13 */
			// Start line: 2232
			// Start offset: 0x80018148
			// Variables:
		// 		int flag; // $fp
		// 		short backface_flag; // stack offset -72
		// 		struct _PCollideInfo pCollideInfo; // stack offset -120

			/* begin block 1.13.1 */
				// Start line: 2257
				// Start offset: 0x800181A8
				// Variables:
			// 		int n; // $s2

				/* begin block 1.13.1.1 */
					// Start line: 2262
					// Start offset: 0x800181B4
					// Variables:
				// 		struct Level *thislevel; // $s1
				/* end block 1.13.1.1 */
				// End offset: 0x8001823C
				// End Line: 2279
			/* end block 1.13.1 */
			// End offset: 0x8001824C
			// End Line: 2280

			/* begin block 1.13.2 */
				// Start line: 2305
				// Start offset: 0x8001828C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // stack offset -44
			/* end block 1.13.2 */
			// End offset: 0x8001828C
			// End Line: 2305

			/* begin block 1.13.3 */
				// Start line: 2336
				// Start offset: 0x800183E0
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.13.3 */
			// End offset: 0x800183E0
			// End Line: 2336
		/* end block 1.13 */
		// End offset: 0x80018460
		// End Line: 2361
	/* end block 1 */
	// End offset: 0x800184F4
	// End Line: 2380

	/* begin block 2 */
		// Start line: 4612
	/* end block 2 */
	// End Line: 4613

_TFace * CAMERA_SphereToSphereWithLines
                   (Camera *camera,CameraCollisionInfo *colInfo,int secondcheck_flag)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(camera->focusInstance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_CalcTilt(struct _Normal *normal /*$s1*/, short zRot /*$a1*/)
 // line 2382, offset 0x80018524
	/* begin block 1 */
		// Start line: 2383
		// Start offset: 0x80018524
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct VECTOR newNormal; // stack offset -32
	/* end block 1 */
	// End offset: 0x80018524
	// End Line: 2383

	/* begin block 2 */
		// Start line: 5838
	/* end block 2 */
	// End Line: 5839

long CAMERA_CalcTilt(_Normal *normal,short zRot)

{
  MATRIX MStack64;
  undefined auStack32 [16];
  
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixZ(-(int)zRot,(uint *)&MStack64);
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(&MStack64,normal,auStack32);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance /*$a0*/, struct _Position *focusPoint /*$a1*/)
 // line 2399, offset 0x80018598
	/* begin block 1 */
		// Start line: 2400
		// Start offset: 0x80018598
		// Variables:
	// 		struct _Position lookFocus; // stack offset -8
	/* end block 1 */
	// End offset: 0x80018598
	// End Line: 2400

	/* begin block 2 */
		// Start line: 5873
	/* end block 2 */
	// End Line: 5874

	/* begin block 3 */
		// Start line: 5878
	/* end block 3 */
	// End Line: 5879

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
 // line 2412, offset 0x800185e0
	/* begin block 1 */
		// Start line: 5904
	/* end block 1 */
	// End Line: 5905

	/* begin block 2 */
		// Start line: 5905
	/* end block 2 */
	// End Line: 5906

void CAMERA_SetLookFocusAndDistance(int param_1,undefined2 *param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x1aa) = *param_2;
  *(undefined2 *)(param_1 + 0x1ac) = param_2[2];
  *(undefined2 *)(param_1 + 0x1ae) = param_2[4];
  uGpffffa3da = param_3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_LookProcess(struct Camera *camera /*$s2*/)
 // line 2420, offset 0x80018608
	/* begin block 1 */
		// Start line: 2421
		// Start offset: 0x80018608
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		int smooth; // $t0
	// 		int distance; // $a3
	// 		long dampMode; // $a0

		/* begin block 1.1 */
			// Start line: 2466
			// Start offset: 0x800186F8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x800186F8
		// End Line: 2466

		/* begin block 1.2 */
			// Start line: 2487
			// Start offset: 0x80018760
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.2 */
		// End offset: 0x80018760
		// End Line: 2487

		/* begin block 1.3 */
			// Start line: 2487
			// Start offset: 0x80018760
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80018760
		// End Line: 2487

		/* begin block 1.4 */
			// Start line: 2487
			// Start offset: 0x80018760
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80018760
		// End Line: 2487
	/* end block 1 */
	// End offset: 0x80018760
	// End Line: 2493

	/* begin block 2 */
		// Start line: 5917
	/* end block 2 */
	// End Line: 5918

	/* begin block 3 */
		// Start line: 5921
	/* end block 3 */
	// End Line: 5922

void CAMERA_LookProcess(Camera *camera)

{
  short sVar1;
  short sVar2;
  long dampMode;
  ushort target;
  short distance;
  int smooth;
  _Instance *p_Var3;
  
  sVar2 = Camera_lookDist;
  sVar1 = (camera->focusInstanceVelVec).y;
  distance = camera->focusDistance;
  (camera->targetFocusPoint).x = (camera->targetFocusPoint).x + (camera->focusInstanceVelVec).x;
  (camera->targetFocusPoint).y = (camera->targetFocusPoint).y + sVar1;
  p_Var3 = camera->focusInstance;
  (camera->targetFocusPoint).z = (camera->targetFocusPoint).z + (camera->focusInstanceVelVec).z;
  if (distance <= sVar2) {
    distance = sVar2;
  }
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,&camera->focusRotation,distance);
  dampMode = CAMERA_DoCameraCollision2(camera,&camera->targetPos,1);
  (camera->data).Follow.hit = dampMode;
  if (dampMode == 0) {
    smooth = 0x80;
    dampMode = 1;
    distance = Camera_lookDist;
  }
  else {
    smooth = 0x200;
    dampMode = 5;
    distance = camera->collisionTargetFocusDistance;
    if (Camera_lookDist < camera->collisionTargetFocusDistance) {
      distance = Camera_lookDist;
    }
  }
  if (((camera->instance_mode & 0x20000) != 0) && (distance < 0x226)) {
    distance = 0x226;
  }
  if ((camera->flags & 0x800U) == 0) {
    CriticalDampValue(dampMode,&camera->focusDistance,distance,&camera->focusDistanceVel,
                      &camera->focusDistanceAccl,smooth);
    CriticalDampPosition
              (0,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
               &camera->focusPointAccl,(int)camera->maxVel);
  }
  else {
    distance = (camera->targetFocusPoint).x;
    camera->focusDistance = camera->targetFocusDistance;
    sVar1 = (camera->targetFocusPoint).y;
    sVar2 = (camera->targetFocusPoint).z;
    (camera->focusPoint).x = distance;
    (camera->focusPoint).y = sVar1;
    (camera->focusPoint).z = sVar2;
  }
  distance = (camera->lookRot).y;
  sVar1 = (camera->lookRot).z;
  (camera->targetFocusRotation).x = (camera->lookRot).x;
  (camera->targetFocusRotation).y = distance;
  target = sVar1 + (p_Var3->rotation).z + 0x800U & 0xfff;
  (camera->targetFocusRotation).z = target;
  CriticalDampAngle(1,&(camera->focusRotation).z,target,&(camera->focusRotVel).z,
                    &(camera->focusRotAccl).z,0x40);
  CriticalDampAngle(1,(short *)&camera->focusRotation,(camera->targetFocusRotation).x,
                    (short *)&camera->focusRotVel,(short *)&camera->focusRotAccl,0x40);
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,&camera->focusRotation,
                      camera->focusDistance);
  distance = (camera->targetPos).y;
  sVar1 = (camera->targetPos).z;
  (camera->core).position.x = (camera->targetPos).x;
  sVar2 = (camera->focusRotation).x;
  (camera->core).position.y = distance;
  (camera->core).position.z = sVar1;
  distance = (camera->focusRotation).y;
  sVar1 = (camera->focusRotation).z;
  (camera->targetRotation).x = sVar2;
  (camera->targetRotation).y = distance;
  (camera->targetRotation).z = sVar1;
  distance = (camera->targetRotation).y;
  (camera->core).rotation.x = (camera->targetRotation).x;
  (camera->core).rotation.y = distance;
  (camera->core).rotation.z = sVar1;
  distance = (camera->core).rotation.z;
  camera->distanceState = 0;
  camera->lagZ = distance;
  CAMERA_CalculateLead(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Normalize(struct _SVector *svector /*$s0*/)
 // line 2546, offset 0x8001885c
	/* begin block 1 */
		// Start line: 2547
		// Start offset: 0x8001885C
		// Variables:
	// 		long len; // $a1
	/* end block 1 */
	// End offset: 0x800188C4
	// End Line: 2555

	/* begin block 2 */
		// Start line: 6216
	/* end block 2 */
	// End Line: 6217

void CAMERA_Normalize(_SVector *svector)

{
  long lVar1;
  
  lVar1 = CAMERA_LengthSVector(svector);
  if (lVar1 != 0) {
    svector->x = (short)(((int)svector->x << 0xc) / lVar1);
    svector->y = (short)(((int)svector->y << 0xc) / lVar1);
    svector->z = (short)(((int)svector->z << 0xc) / lVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_HandleTransitions(struct Camera *camera /*$s0*/)
 // line 2557, offset 0x800188d4
	/* begin block 1 */
		// Start line: 2558
		// Start offset: 0x800188D4
	/* end block 1 */
	// End offset: 0x80018A78
	// End Line: 2669

	/* begin block 2 */
		// Start line: 6240
	/* end block 2 */
	// End Line: 6241

void CAMERA_HandleTransitions(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  _Position *in_a1;
  
  if (camera->rotState != 3) {
    CAMERA_SetLookFocusAndBase((_Instance *)camera,in_a1);
    return;
  }
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
  if (camera->distanceState != 3) goto LAB_80018a40;
  if ((camera->forced_movement == 2) && ((camera->lock & 1U) == 0)) {
LAB_80018a28:
    camera->distanceState = 0;
LAB_80018a2c:
    camera->focusDistanceVel = 0;
    camera->focusDistanceAccl = 0;
  }
  else {
    iVar3 = (int)camera->targetFocusDistance - (int)camera->signalFocusDistance;
    if (iVar3 < 0) {
      if ((int)camera->signalFocusDistance - (int)camera->targetFocusDistance < 4)
      goto LAB_80018a28;
    }
    else {
      if (iVar3 < 4) {
        camera->distanceState = 0;
        goto LAB_80018a2c;
      }
    }
  }
  camera->targetFocusDistance = camera->signalFocusDistance;
LAB_80018a40:
  if ((camera->posState == 3) && ((camera->mode != 5 || ((camera->flags & 0x1000U) != 0)))) {
    camera->posState = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFocusOffset(struct _SVector *offset /*$a2*/, struct Camera *camera /*$a1*/)
 // line 2673, offset 0x80018a88
	/* begin block 1 */
		// Start line: 2674
		// Start offset: 0x80018A88
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -24
	// 		struct _SVector temp; // stack offset -8
	// 		struct _Instance *focusInstance; // $a0

		/* begin block 1.1 */
			// Start line: 2698
			// Start offset: 0x80018AC8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x80018AC8
		// End Line: 2698
	/* end block 1 */
	// End offset: 0x80018AC8
	// End Line: 2698

	/* begin block 2 */
		// Start line: 6474
	/* end block 2 */
	// End Line: 6475

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
 // line 2703, offset 0x80018b3c
	/* begin block 1 */
		// Start line: 2704
		// Start offset: 0x80018B3C
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -32
	// 		struct _SVector temp; // stack offset -16
	// 		struct _Instance *focusInstance; // $v1

		/* begin block 1.1 */
			// Start line: 2704
			// Start offset: 0x80018B3C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80018B3C
		// End Line: 2704
	/* end block 1 */
	// End offset: 0x80018B3C
	// End Line: 2704

	/* begin block 2 */
		// Start line: 6542
	/* end block 2 */
	// End Line: 6543

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
 // line 2727, offset 0x80018ba8
	/* begin block 1 */
		// Start line: 2728
		// Start offset: 0x80018BA8
		// Variables:
	// 		struct _SVector point; // stack offset -24
	// 		short zrot; // $a0
	// 		long camera_plane_d; // $v0
	/* end block 1 */
	// End offset: 0x80018C80
	// End Line: 2747

	/* begin block 2 */
		// Start line: 6608
	/* end block 2 */
	// End Line: 6609

	/* begin block 3 */
		// Start line: 6613
	/* end block 3 */
	// End Line: 6614

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
  if (iVar1 == 0) {
    angle0 = -9999;
  }
  else {
    angle0 = CAMERA_CalcZRotation((_Position *)linept,&_Stack24);
    angle0 = CAMERA_SignedAngleDifference(angle0,hitline_rot);
    if (angle0 < *low) {
      *low = angle0;
    }
    if (*high < angle0) {
      *high = angle0;
    }
  }
  return angle0;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_GetLineAngle(struct Camera *camera /*$a0*/, struct CameraCollisionInfo *colInfo /*$a1*/, struct _SVector *linept /*$a2*/, int line /*$s5*/)
 // line 2749, offset 0x80018c98
	/* begin block 1 */
		// Start line: 2750
		// Start offset: 0x80018C98
		// Variables:
	// 		struct _Terrain *terrain; // $t1
	// 		struct _SVector *vertex0; // $s1
	// 		struct _SVector *vertex1; // $s0
	// 		struct _SVector *vertex2; // $s3
	// 		struct _SVector new_linept; // stack offset -48
	// 		short high; // stack offset -40
	// 		short low; // stack offset -38
	/* end block 1 */
	// End offset: 0x80018E3C
	// End Line: 2779

	/* begin block 2 */
		// Start line: 6675
	/* end block 2 */
	// End Line: 6676

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
 // line 2793, offset 0x80018e60
	/* begin block 1 */
		// Start line: 2794
		// Start offset: 0x80018E60
		// Variables:
	// 		long dp; // $v0
	// 		struct _Normal normal; // stack offset -32
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 2794
			// Start offset: 0x80018E60
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
		// End offset: 0x80018E60
		// End Line: 2794
	/* end block 1 */
	// End offset: 0x80018F18
	// End Line: 2832

	/* begin block 2 */
		// Start line: 6883
	/* end block 2 */
	// End Line: 6884

long CAMERA_ACForcedMovement(Camera *camera,CameraCollisionInfo *colInfo)

{
  _Sphere *p_Var1;
  _Sphere *p_Var2;
  _SVector local_20;
  _SVector local_18;
  
  COLLIDE_GetNormal(*(short *)(colInfo->tfaceList[colInfo->line] + 8),
                    *(short **)((colInfo->tfaceList + colInfo->line)[5] + 0x24),&local_20);
  p_Var1 = colInfo->start;
  p_Var2 = colInfo->end;
  local_18.x = (p_Var1->position).x - (p_Var2->position).x;
  local_18.y = (p_Var1->position).y - (p_Var2->position).y;
  local_18.z = (p_Var1->position).z - (p_Var2->position).z;
                    /* WARNING: Subroutine does not return */
  CAMERA_Normalize(&local_18);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_update_dist_debounced(struct Camera *camera /*$a0*/, short dist /*$a2*/)
 // line 2835, offset 0x80018f30
	/* begin block 1 */
		// Start line: 6974
	/* end block 1 */
	// End Line: 6975

	/* begin block 2 */
		// Start line: 6975
	/* end block 2 */
	// End Line: 6976

void CAMERA_update_dist_debounced(Camera *camera,short dist)

{
  if ((((camera->instance_mode & 0x2000000) == 0) || (599 < dist)) || (0xfc7 < (short)Spiral_Max)) {
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
 // line 2847, offset 0x80018fa0
	/* begin block 1 */
		// Start line: 2848
		// Start offset: 0x80018FA0
		// Variables:
	// 		static short target_angle; // offset 0x50
	// 		static short angle_vel; // offset 0x52
	// 		static short angle_accl; // offset 0x54
	/* end block 1 */
	// End offset: 0x80019038
	// End Line: 2865

	/* begin block 2 */
		// Start line: 6999
	/* end block 2 */
	// End Line: 7000

short CAMERA_dampgetline(short angle)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)angle;
  CriticalDampAngle(1,&DAT_800cdf88,angle,(short *)&DAT_800cdf8a,(short *)&DAT_800cdf8c,0x400);
  if (0x800 < DAT_800cdf88) {
    DAT_800cdf88 = DAT_800cdf88 + -0x1000;
  }
  iVar1 = (int)DAT_800cdf88;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x20) {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = -iVar2;
    }
    if ((0x1f < iVar1) && (DAT_800cdf88 = 0x20, iVar2 < 0)) {
      DAT_800cdf88 = -0x20;
    }
  }
  return DAT_800cdf88;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_ACNoForcedMovement(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *colInfo /*$s1*/)
 // line 2873, offset 0x8001904c
	/* begin block 1 */
		// Start line: 2874
		// Start offset: 0x8001904C
		// Variables:
	// 		long hit; // $s2
	// 		short playerSamePos; // $s3
	// 		short angle; // $a0

		/* begin block 1.1 */
			// Start line: 2900
			// Start offset: 0x800190C4
			// Variables:
		// 		int n; // $a0
		// 		int flag; // $t1
		// 		short dist; // $a1
		/* end block 1.1 */
		// End offset: 0x80019278
		// End Line: 2956
	/* end block 1 */
	// End offset: 0x80019534
	// End Line: 3124

	/* begin block 2 */
		// Start line: 7059
	/* end block 2 */
	// End Line: 7060

long CAMERA_ACNoForcedMovement(Camera *camera,CameraCollisionInfo *colInfo)

{
  bool bVar1;
  _func_21 **pp_Var2;
  short angle;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  Camera *camera_00;
  uint uVar8;
  CameraCollisionInfo *colInfo_00;
  long lVar9;
  
  lVar9 = 0;
  iVar4 = CAMERA_FocusInstanceMoved(camera);
  if ((((camera->always_rotate_flag == 0) && (camera->rotState != 3)) && (1 < colInfo->numCollided))
     && (bVar1 = true, colInfo->line - 1U < 2)) {
    colInfo_00 = (CameraCollisionInfo *)&DAT_00007fff;
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
    camera_00 = (Camera *)&UNK_00000001;
    pp_Var2 = colInfo->tfaceList;
    do {
      if (camera_00 != (Camera *)colInfo->line) {
        if (*(short *)((int)pp_Var2 + 0x36) < 800) {
          bVar1 = false;
          break;
        }
        if (*(short *)((int)pp_Var2 + 0x36) < (short)colInfo_00) {
          colInfo_00 = (CameraCollisionInfo *)(uint)*(ushort *)((int)pp_Var2 + 0x36);
        }
      }
      camera_00 = (Camera *)((int)&(camera_00->core).position.x + 1);
      pp_Var2 = (_func_21 **)((int)pp_Var2 + 2);
    } while ((int)camera_00 < 5);
    if (!bVar1) {
      lVar9 = CAMERA_ACForcedMovement(camera_00,colInfo_00);
      return lVar9;
    }
    colInfo->numCollided = 1;
    colInfo->flags = 1 << (colInfo->line & 0x1fU);
    if (colInfo->lenCenterToExtend < 0x321) {
      CAMERA_update_dist_debounced(camera,(short)colInfo_00);
    }
    else {
      CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
    }
  }
  if ((colInfo->numCollided == 4) && ((camera->lock & 1U) == 0)) {
    angle = (camera->targetFocusRotation).z;
    lVar9 = 1;
    camera->collisionTargetFocusDistance = *(short *)&colInfo->lenCenterToExtend;
    (camera->collisionTargetFocusRotation).z = angle;
LAB_80019528:
    CAMERA_dampgetline(0);
    return lVar9;
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
      goto LAB_80019528;
    }
    if ((uVar8 & 2) != 0) goto LAB_8001943c;
    camera->collideRotControl = 1;
    camera->collision_lastPush = 1;
    if ((camera->mode != 0xd) || (ACE_amount < 0xb)) {
      angle = CAMERA_GetLineAngle(camera,colInfo,&left_point,2);
      uVar3 = CAMERA_dampgetline(angle);
      iVar4 = ACE_amount;
      if (ACE_amount < 0) {
        iVar4 = -ACE_amount;
      }
      if (iVar4 < 6) {
        if (0x3f < (short)uVar3) {
          angle = (camera->collisionTargetFocusRotation).z + 0x40;
          goto LAB_800194cc;
        }
      }
      else {
        if ((int)((uint)uVar3 << 0x10) < 0) {
          return 1;
        }
      }
      angle = (camera->focusRotation).z + 4;
      goto LAB_800194c8;
    }
  }
  else {
    if ((uVar8 & 4) != 0) goto LAB_8001943c;
    camera->collideRotControl = 1;
    camera->collision_lastPush = 2;
    if ((camera->mode != 0xd) || (-0xb < ACE_amount)) {
      angle = CAMERA_GetLineAngle(camera,colInfo,&right_point,1);
      uVar3 = CAMERA_dampgetline(angle);
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
        angle = (camera->collisionTargetFocusRotation).z + -0x40;
        goto LAB_800194cc;
      }
      angle = (camera->focusRotation).z + -4;
LAB_800194c8:
      angle = uVar3 + angle;
LAB_800194cc:
      (camera->collisionTargetFocusRotation).z = angle;
      return 1;
    }
  }
  (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
LAB_8001943c:
  CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_AbsoluteCollision(struct Camera *camera /*$a0*/, struct CameraCollisionInfo *colInfo /*$a1*/)
 // line 3130, offset 0x80019550
	/* begin block 1 */
		// Start line: 3131
		// Start offset: 0x80019550
		// Variables:
	// 		long hit; // $a3
	/* end block 1 */
	// End offset: 0x80019668
	// End Line: 3200

	/* begin block 2 */
		// Start line: 7592
	/* end block 2 */
	// End Line: 7593

long CAMERA_AbsoluteCollision(Camera *camera,CameraCollisionInfo *colInfo)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  
  if ((theCamera.core.debugRot._4_4_ & 0x10000) != 0) {
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
 // line 3205, offset 0x80019678
	/* begin block 1 */
		// Start line: 3206
		// Start offset: 0x80019678
		// Variables:
	// 		static short upvel; // offset 0x56
	// 		static short upaccl; // offset 0x58
	// 		static short upmaxVel; // offset 0x5a
	// 		short current_tmp; // stack offset -16
	/* end block 1 */
	// End offset: 0x800198D8
	// End Line: 3250

	/* begin block 2 */
		// Start line: 7752
	/* end block 2 */
	// End Line: 7753

short CAMERA_update_z_damped(Camera *camera,short current,short target)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short local_10 [4];
  
  iVar3 = (int)current;
  iVar4 = (int)target;
  if (iVar4 < iVar3) {
    if (((camera->instance_mode & 0x1038) == 0) ||
       ((camera->real_focuspoint).z < camera->focuspoint_fallz)) {
      iVar3 = (int)current - (int)target;
      if (iVar3 < 0) {
        iVar3 = (int)target - (int)current;
      }
      DAT_800cdf92 = (short)(iVar3 << 1);
    }
    else {
      if (iVar3 - iVar4 < 0) {
        DAT_800cdf92 = (short)((iVar4 - iVar3) / 6);
      }
      else {
        DAT_800cdf92 = (short)((iVar3 - iVar4) / 6);
      }
    }
    goto LAB_80019894;
  }
  iVar1 = iVar3 - iVar4;
  if (iVar1 < 0) {
    iVar1 = iVar4 - iVar3;
  }
  if (iVar1 < 5) {
    DAT_800cdf8e = 0;
    DAT_800cdf90 = 0;
    DAT_800cdf92 = 0;
    return current;
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
LAB_8001982c:
    DAT_800cdf92 = sVar5;
  }
  else {
    iVar4 = iVar3 - target;
    sVar2 = (short)((uint)iVar4 >> 0x10);
    if (iVar4 < 0) {
      iVar3 = target - iVar3;
      sVar2 = (short)((uint)iVar3 >> 0x10);
      DAT_800cdf92 = (short)(iVar3 / 6) + (sVar2 >> 0xf);
    }
    else {
      DAT_800cdf92 = (short)(iVar4 / 6) + (sVar2 >> 0xf);
    }
    DAT_800cdf92 = DAT_800cdf92 - (sVar2 >> 0xf);
    sVar5 = 0x32;
    if (DAT_800cdf92 < 0x32) goto LAB_8001982c;
  }
  iVar3 = (int)current - (int)target;
  if (iVar3 < 0) {
    iVar3 = (int)target - (int)current;
  }
  if ((iVar3 < DAT_800cdf92) && (DAT_800cdf92 = current - target, (int)current - (int)target < 0)) {
    DAT_800cdf92 = target - current;
  }
LAB_80019894:
  local_10[0] = current;
  CriticalDampValue(1,local_10,target,&DAT_800cdf8e,&DAT_800cdf90,(int)DAT_800cdf92);
  return local_10[0];
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CombatCamDist(struct Camera *camera /*$s0*/)
 // line 3310, offset 0x800198e8
	/* begin block 1 */
		// Start line: 3311
		// Start offset: 0x800198E8
		// Variables:
	// 		struct DVECTOR xy; // stack offset -48
	// 		struct DVECTOR xy2; // stack offset -40
	// 		struct _SVector position; // stack offset -32
	// 		long z; // stack offset -24
	// 		struct _Instance *instance; // $s1
	/* end block 1 */
	// End offset: 0x80019B98
	// End Line: 3392

	/* begin block 2 */
		// Start line: 7966
	/* end block 2 */
	// End Line: 7967

void CAMERA_CombatCamDist(Camera *camera)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(camera->focusInstance,0x22);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_GenericCameraProcess(struct Camera *camera /*$s0*/)
 // line 3395, offset 0x80019bac
	/* begin block 1 */
		// Start line: 3396
		// Start offset: 0x80019BAC
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3449
			// Start offset: 0x80019CD0
			// Variables:
		// 		short angle; // $a0
		// 		struct _Rotation test_rot; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80019D30
		// End Line: 3467

		/* begin block 1.2 */
			// Start line: 3475
			// Start offset: 0x80019D40
			// Variables:
		// 		struct _Instance *warpInstance; // $v0
		// 		int tmp; // $v0
		/* end block 1.2 */
		// End offset: 0x80019D50
		// End Line: 3481

		/* begin block 1.3 */
			// Start line: 3513
			// Start offset: 0x80019E00
			// Variables:
		// 		int mod; // $v1
		/* end block 1.3 */
		// End offset: 0x80019E80
		// End Line: 3528

		/* begin block 1.4 */
			// Start line: 3536
			// Start offset: 0x80019E9C
			// Variables:
		// 		int dist; // $a3
		/* end block 1.4 */
		// End offset: 0x80019EF0
		// End Line: 3554

		/* begin block 1.5 */
			// Start line: 3568
			// Start offset: 0x80019F30
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x80019F30
		// End Line: 3568

		/* begin block 1.6 */
			// Start line: 3577
			// Start offset: 0x80019F74
			// Variables:
		// 		struct _Position target; // stack offset -24
		/* end block 1.6 */
		// End offset: 0x80019FF4
		// End Line: 3597
	/* end block 1 */
	// End offset: 0x80019FF4
	// End Line: 3600

	/* begin block 2 */
		// Start line: 8137
	/* end block 2 */
	// End Line: 8138

void CAMERA_GenericCameraProcess(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  _Instance *focusInstance;
  _Position _Stack32;
  undefined4 local_18;
  short local_14;
  
  focusInstance = camera->focusInstance;
  if (((camera->flags & 0x10000U) != 0) || ((camera->instance_mode & 0x4000000) != 0)) {
    (camera->rotationVel).z = 0x40;
  }
  if ((camera->instance_mode & 0x2000000) == 0) {
    Spiral_Max._0_2_ = 0x1000;
  }
  CAMERA_SetMaxVel(camera);
  CAMERA_SetFocus(camera,&camera->targetFocusPoint);
  if (((camera->flags & 0x10000U) == 0) && ((camera->instance_mode & 0x4000000) == 0)) {
    CAMERA_UpdateFocusRotationX(camera,focusInstance);
    if (((((camera->mode == 0xd) && (0 < camera->instance_xyvel)) &&
         ((camera->instance_mode & 0x82000400) == 0)) &&
        ((camera->always_rotate_flag == 0 && (camera->rotState != 3)))) &&
       (((camera->instance_mode & 0x2000) == 0 &&
        (theCamera.focusSphere.radiusSquared._3_1_ != '\x01')))) {
      CAMERA_CalcRotation((_Rotation *)&local_18,&camera->targetFocusPoint,(_Position *)camera);
      sVar2 = CAMERA_SignedAngleDifference(local_14,(camera->focusRotation).z);
      if ((camera->instance_mode & 2) == 0) {
        sVar2 = (short)((uint)((int)sVar2 * 3) >> 2);
      }
      else {
        sVar2 = sVar2 >> 1;
      }
      (camera->targetFocusRotation).z = (camera->focusRotation).z + sVar2;
    }
  }
  else {
    CAMERA_FollowPlayerTilt(camera,focusInstance);
  }
  uVar5 = camera->instance_mode;
  if ((int)uVar5 < 0) {
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
    if (((camera->flags & 0x2000U) == 0) && ((uVar5 & 0x20000000) == 0)) {
      if (((camera->flags & 0x10000U) == 0) && ((uVar5 & 0x4000000) == 0)) {
        if (((uVar5 & 0x400) != 0) && ((camera->prev_instance_mode & 0x400) == 0)) {
          iVar6 = (int)(camera->core).rotation.z;
          iVar3 = iVar6;
          if (iVar6 < 0) {
            iVar3 = iVar6 + 0x3ff;
          }
          iVar3 = (iVar6 + (iVar3 >> 10) * -0x400) * 0x10000 >> 0x10;
          if (iVar3 < 0x201) {
            iVar3 = -iVar3;
          }
          else {
            iVar3 = 0x400 - iVar3;
          }
          iVar6 = iVar3;
          if (iVar3 < 0) {
            iVar6 = -iVar3;
          }
          if (0x80 < iVar6) {
            (camera->targetFocusRotation).z = (short)iVar3 + (camera->core).rotation.z & 0xfff;
          }
        }
        CAMERA_FollowGoBehindPlayerWithTimer(camera);
        goto LAB_80019e88;
      }
    }
    else {
      if ((uVar5 & 0x2000000) != 0) goto LAB_80019e88;
      (camera->rotationVel).z = 0x40;
    }
    CAMERA_FollowGoBehindPlayer(camera);
  }
LAB_80019e88:
  if ((camera->flags & 0x1800U) == 0) {
    if ((camera->instance_mode & 0x2000000) == 0) {
      Spiral_Current._0_2_ = camera->targetFocusDistance;
    }
    else {
      CAMERA_CombatCamDist(camera);
    }
    CAMERA_CalcPosition(&_Stack32,&camera->focusPoint,&camera->focusRotation,(short)Spiral_Current);
    lVar4 = CAMERA_DoCameraCollision2(camera,&_Stack32,0);
    (camera->data).Follow.hit = lVar4;
  }
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



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CinematicProcess(struct Camera *camera /*$s2*/)
 // line 3608, offset 0x8001a028
	/* begin block 1 */
		// Start line: 3609
		// Start offset: 0x8001A028
		// Variables:
	// 		struct _SVector *camPos; // $s0
	// 		struct _SVector *camTarget; // $s3
	// 		struct MultiSpline *posSpline; // $s4
	// 		struct MultiSpline *targetSpline; // $s1

		/* begin block 1.1 */
			// Start line: 3632
			// Start offset: 0x8001A0A0
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001A0A0
		// End Line: 3632

		/* begin block 1.2 */
			// Start line: 3636
			// Start offset: 0x8001A0BC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _SVector *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001A0D4
		// End Line: 3636

		/* begin block 1.3 */
			// Start line: 3641
			// Start offset: 0x8001A0E4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x8001A0E4
		// End Line: 3641

		/* begin block 1.4 */
			// Start line: 3649
			// Start offset: 0x8001A12C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a2
		// 		struct _Position *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x8001A12C
		// End Line: 3649

		/* begin block 1.5 */
			// Start line: 3662
			// Start offset: 0x8001A18C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x8001A18C
		// End Line: 3662

		/* begin block 1.6 */
			// Start line: 3710
			// Start offset: 0x8001A3E0
		/* end block 1.6 */
		// End offset: 0x8001A4DC
		// End Line: 3727

		/* begin block 1.7 */
			// Start line: 3730
			// Start offset: 0x8001A4DC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.7 */
		// End offset: 0x8001A4DC
		// End Line: 3730
	/* end block 1 */
	// End offset: 0x8001A4DC
	// End Line: 3730

	/* begin block 2 */
		// Start line: 8584
	/* end block 2 */
	// End Line: 8585

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
    goto LAB_8001a4e4;
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
    if (8 < iVar3) goto LAB_8001a4e4;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a4e4;
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
    if (8 < iVar3) goto LAB_8001a4e4;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a4e4;
    iVar5 = (int)(camera->core).position.z;
    iVar4 = (int)(camera->targetPos).z;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a4e4;
    iVar5 = (int)(camera->focusPoint).x;
    iVar4 = (int)(camera->targetFocusPoint).x;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a4e4;
    iVar5 = (int)(camera->focusPoint).y;
    iVar4 = (int)(camera->targetFocusPoint).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a4e4;
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
LAB_8001a4e4:
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
 // line 3744, offset 0x8001a544
	/* begin block 1 */
		// Start line: 3745
		// Start offset: 0x8001A544
		// Variables:
	// 		struct _Vector d; // stack offset -16
	/* end block 1 */
	// End offset: 0x8001A544
	// End Line: 3745

	/* begin block 2 */
		// Start line: 8869
	/* end block 2 */
	// End Line: 8870

	/* begin block 3 */
		// Start line: 8873
	/* end block 3 */
	// End Line: 8874

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
 // line 3759, offset 0x8001a5c0
	/* begin block 1 */
		// Start line: 3760
		// Start offset: 0x8001A5C0
		// Variables:
	// 		struct MATRIX nmat; // stack offset -64
	// 		struct _Vector dpv; // stack offset -32
	// 		long t; // $a0
	/* end block 1 */
	// End offset: 0x8001A674
	// End Line: 3778

	/* begin block 2 */
		// Start line: 8903
	/* end block 2 */
	// End Line: 8904

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
 // line 3784, offset 0x8001a6ec
	/* begin block 1 */
		// Start line: 8966
	/* end block 1 */
	// End Line: 8967

	/* begin block 2 */
		// Start line: 8967
	/* end block 2 */
	// End Line: 8968

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
 // line 3790, offset 0x8001a730
	/* begin block 1 */
		// Start line: 8978
	/* end block 1 */
	// End Line: 8979

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
 // line 3798, offset 0x8001a7c0
	/* begin block 1 */
		// Start line: 3799
		// Start offset: 0x8001A7C0
		// Variables:
	// 		struct _SVector outPoint; // stack offset -56
	// 		struct _SVector line; // stack offset -48
	// 		int calc; // $s1
	// 		int hits; // $s4

		/* begin block 1.1 */
			// Start line: 3799
			// Start offset: 0x8001A7C0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t1
		// 		short _z1; // $t2
		// 		struct _SVector *_v; // $s2
		/* end block 1.1 */
		// End offset: 0x8001A7C0
		// End Line: 3799

		/* begin block 1.2 */
			// Start line: 3813
			// Start offset: 0x8001A854
			// Variables:
		// 		struct _SVector linePoint; // stack offset -40
		// 		int n; // $s3

			/* begin block 1.2.1 */
				// Start line: 3827
				// Start offset: 0x8001A908
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8001A908
			// End Line: 3827
		/* end block 1.2 */
		// End offset: 0x8001A95C
		// End Line: 3833
	/* end block 1 */
	// End offset: 0x8001A95C
	// End Line: 3835

	/* begin block 2 */
		// Start line: 8994
	/* end block 2 */
	// End Line: 8995

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
    MATH3D_FastSqrt0(target_dist_sq - iVar1);
                    /* WARNING: Subroutine does not return */
    CAMERA_Normalize(local_30);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineGetNearestPoint2(struct Camera *camera /*stack 0*/, struct Spline *spline /*stack 4*/, struct _SVector *point /*stack 8*/, int *currkey /*stack 12*/, struct _SVector *ret_dpoint /*stack 16*/)
 // line 3838, offset 0x8001a984
	/* begin block 1 */
		// Start line: 3839
		// Start offset: 0x8001A984
		// Variables:
	// 		struct SplineKey *key; // stack offset -56
	// 		int n; // $s2
	// 		int target_dist_sq; // stack offset -52
	// 		long dist; // $fp

		/* begin block 1.1 */
			// Start line: 3839
			// Start offset: 0x8001A984
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001A984
		// End Line: 3839

		/* begin block 1.2 */
			// Start line: 3858
			// Start offset: 0x8001AA38
			// Variables:
		// 		struct _SVector point1; // stack offset -88
		// 		struct _SVector point2; // stack offset -80
		// 		struct _SVector results[2]; // stack offset -72
		// 		int i; // $s1
		// 		int hits; // $s3

			/* begin block 1.2.1 */
				// Start line: 3862
				// Start offset: 0x8001AA54
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a2
			// 		short _z1; // $v0
			// 		struct _SVector *_v0; // $s7
			// 		struct vecS *_v1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8001AA54
			// End Line: 3862

			/* begin block 1.2.2 */
				// Start line: 3862
				// Start offset: 0x8001AA54
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $a2
			// 		short _z1; // $v1
			// 		struct _SVector *_v0; // $s6
			// 		struct vecS *_v1; // $v1
			/* end block 1.2.2 */
			// End offset: 0x8001AA54
			// End Line: 3862

			/* begin block 1.2.3 */
				// Start line: 3869
				// Start offset: 0x8001AACC
				// Variables:
			// 		int tmpdist; // $a1

				/* begin block 1.2.3.1 */
					// Start line: 3880
					// Start offset: 0x8001AAE8
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.2.3.1 */
				// End offset: 0x8001AAE8
				// End Line: 3880
			/* end block 1.2.3 */
			// End offset: 0x8001AB0C
			// End Line: 3884
		/* end block 1.2 */
		// End offset: 0x8001AB1C
		// End Line: 3892
	/* end block 1 */
	// End offset: 0x8001AB3C
	// End Line: 3893

	/* begin block 2 */
		// Start line: 9111
	/* end block 2 */
	// End Line: 9112

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
 // line 3895, offset 0x8001ab6c
	/* begin block 1 */
		// Start line: 3896
		// Start offset: 0x8001AB6C
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
			// Start line: 3921
			// Start offset: 0x8001AC98
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $a3
		/* end block 1.1 */
		// End offset: 0x8001AC98
		// End Line: 3921

		/* begin block 1.2 */
			// Start line: 3921
			// Start offset: 0x8001AC98
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.2 */
		// End offset: 0x8001AC98
		// End Line: 3921

		/* begin block 1.3 */
			// Start line: 3936
			// Start offset: 0x8001AD60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.3 */
		// End offset: 0x8001AD60
		// End Line: 3936

		/* begin block 1.4 */
			// Start line: 3949
			// Start offset: 0x8001ADC0
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $v1
		/* end block 1.4 */
		// End offset: 0x8001ADC0
		// End Line: 3949
	/* end block 1 */
	// End offset: 0x8001AED4
	// End Line: 3975

	/* begin block 2 */
		// Start line: 9304
	/* end block 2 */
	// End Line: 9305

/* WARNING: Type propagation algorithm not settling */

void CAMERA_SplineGetNearestPoint(Spline *spline,_SVector *point,int *currkey,_SVector *ret_dpoint)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SplineKey *pSVar6;
  int iVar7;
  Camera *camera;
  Spline *spline_00;
  _SVector *point_00;
  _SVector *currkey_00;
  SplineKey *pSVar8;
  int iVar9;
  _SVector *local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  short local_3e;
  short local_3c;
  _SVector local_38;
  short local_30;
  short local_2e;
  short local_2c;
  
  pSVar8 = spline->key;
  iVar4 = (int)spline->numkeys + -2;
  iVar9 = *currkey;
  if (iVar4 < *currkey) {
    *currkey = iVar4;
    iVar9 = iVar4;
  }
  iVar7 = (int)(pSVar8->point).x;
  iVar5 = (int)pSVar8[(int)spline->numkeys + -1].point.x;
  iVar4 = iVar7 - iVar5;
  if (iVar4 < 0) {
    iVar4 = iVar5 - iVar7;
  }
  bVar1 = false;
  if (iVar4 < 5) {
    iVar7 = (int)(pSVar8->point).y;
    iVar5 = (int)pSVar8[(int)spline->numkeys + -1].point.y;
    iVar4 = iVar7 - iVar5;
    if (iVar4 < 0) {
      iVar4 = iVar5 - iVar7;
    }
    bVar1 = false;
    if (iVar4 < 5) {
      iVar7 = (int)(pSVar8->point).z;
      iVar5 = (int)pSVar8[(int)spline->numkeys + -1].point.z;
      iVar4 = iVar7 - iVar5;
      if (iVar4 < 0) {
        bVar1 = true;
        if (4 < iVar5 - iVar7) {
          bVar1 = false;
        }
      }
      else {
        bVar1 = true;
        if (4 < iVar4) {
          bVar1 = false;
        }
      }
    }
  }
  pSVar6 = pSVar8 + iVar9;
  point_00 = &local_38;
  local_40 = (pSVar6->point).x;
  local_3e = (pSVar6->point).y;
  local_3c = (pSVar6->point).z;
  pSVar6 = pSVar8 + iVar9 + 1;
  local_38.x = (pSVar6->point).x;
  local_38.y = (pSVar6->point).y;
  local_38.z = (pSVar6->point).z;
  currkey_00 = point;
  iVar4 = COLLIDE_NearestPointOnLine_S
                    ((uint *)&stack0xffffffa0,(uint *)&local_40,(uint *)point_00,(uint *)point);
  camera = (Camera *)&stack0xffffffa0;
  spline_00 = (Spline *)point;
  iVar5 = CAMERA_GetDistSq((_SVector *)camera,point);
  if (iVar9 < (int)spline->numkeys + -2) {
    iVar7 = iVar9 + 1;
  }
  else {
    iVar7 = -1;
    if (bVar1) {
      iVar7 = 0;
    }
  }
  if (iVar9 < 1) {
    CAMERA_SplineGetNearestPoint2(camera,spline_00,point_00,(int *)currkey_00,local_60);
    return;
  }
  iVar9 = iVar9 + -1;
  if (iVar7 == -1) {
    iVar2 = -1;
LAB_8001adb8:
    if (iVar9 == -1) {
      iVar3 = -1;
LAB_8001ae08:
      if ((iVar2 - 1U < 0xfff) &&
         (iVar4 = CAMERA_GetDistSq((_SVector *)&local_58,point), iVar4 < iVar5)) {
        *currkey = iVar7;
        goto LAB_8001ae30;
      }
      if ((0xffe < iVar3 - 1U) ||
         (iVar4 = CAMERA_GetDistSq((_SVector *)&local_50,point), iVar5 <= iVar4)) {
        *(_SVector **)ret_dpoint = local_60;
        *(undefined4 *)&ret_dpoint->z = local_5c;
        return;
      }
      *currkey = iVar9;
    }
    else {
      pSVar8 = pSVar8 + iVar9;
      local_48 = (pSVar8->point).x;
      local_46 = (pSVar8->point).y;
      local_44 = (pSVar8->point).z;
      iVar3 = COLLIDE_NearestPointOnLine_S
                        ((uint *)&local_50,(uint *)&local_48,(uint *)&local_40,(uint *)point);
      if (0 < iVar4) goto LAB_8001ae08;
      *currkey = iVar9;
    }
    *(uint *)ret_dpoint = local_50;
    *(undefined4 *)&ret_dpoint->z = local_4c;
  }
  else {
    pSVar6 = pSVar8 + iVar7 + 1;
    local_30 = (pSVar6->point).x;
    local_2e = (pSVar6->point).y;
    local_2c = (pSVar6->point).z;
    iVar2 = COLLIDE_NearestPointOnLine_S
                      ((uint *)&local_58,(uint *)&local_38,(uint *)&local_30,(uint *)point);
    if (iVar4 < 0x1000) goto LAB_8001adb8;
    *currkey = iVar7;
LAB_8001ae30:
    *(uint *)ret_dpoint = local_58;
    *(undefined4 *)&ret_dpoint->z = local_54;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineHelpMove(struct Camera *camera /*$s1*/)
 // line 3981, offset 0x8001af04
	/* begin block 1 */
		// Start line: 3982
		// Start offset: 0x8001AF04
		// Variables:
	// 		struct _SVector camPos; // stack offset -48
	// 		struct _Position pos; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Instance *focusInstance; // $s3
	// 		struct MultiSpline *posSpline; // $s2
	/* end block 1 */
	// End offset: 0x8001B058
	// End Line: 4026

	/* begin block 2 */
		// Start line: 9489
	/* end block 2 */
	// End Line: 9490

void CAMERA_SplineHelpMove(int param_1)

{
                    /* WARNING: Subroutine does not return */
  CAMERA_AngleDifference(sGpffffa3d4,*(short *)(param_1 + 0x1b6));
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineProcess(struct Camera *camera /*$s1*/)
 // line 4028, offset 0x8001b074
	/* begin block 1 */
		// Start line: 4029
		// Start offset: 0x8001B074
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
			// Start line: 4114
			// Start offset: 0x8001B1C0
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
		// End offset: 0x8001B1C0
		// End Line: 4114
	/* end block 1 */
	// End offset: 0x8001B3A8
	// End Line: 4177

	/* begin block 2 */
		// Start line: 9602
	/* end block 2 */
	// End Line: 9603

void CAMERA_SplineProcess(Camera *camera)

{
  short sVar1;
  long lVar2;
  _SVector *point;
  int smooth;
  int smooth_00;
  MultiSpline *pMVar3;
  short distance;
  _SVector local_30;
  _SVector local_28;
  _Rotation local_20;
  
  pMVar3 = (camera->data).Cinematic.posSpline;
  local_20.x = (camera->targetFocusRotation).x;
  local_20.y = 0;
  local_20.z = (camera->targetFocusRotation).z;
  CAMERA_SetFocus(camera,&camera->targetFocusPoint);
  distance = camera->targetFocusDistance;
  point = (_SVector *)&camera->targetPos;
  if (pMVar3 == (MultiSpline *)0x0) {
    return;
  }
  CAMERA_CalcPosition((_Position *)point,&camera->targetFocusPoint,&local_20,distance);
  if (camera->mode == 4) {
    CAMERA_SplineGetNearestPoint2
              (camera,pMVar3->positional,point,&(camera->data).Cinematic.splinecam_currkey,&local_30
              );
  }
  else {
    CAMERA_SplineGetNearestPoint
              (pMVar3->positional,point,&(camera->data).Cinematic.splinecam_currkey,&local_30);
  }
  camera->maxVel = 0x200;
  CriticalDampPosition
            (5,&camera->focusPoint,&camera->targetFocusPoint,&camera->focusPointVel,
             &camera->focusPointAccl,(int)camera->maxVel);
  if (camera->forced_movement == 1) {
    DAT_800cdf94 = 1;
  }
  else {
    smooth = CAMERA_FocusInstanceMoved(camera);
    if (smooth != 0) {
      if (DAT_800cdf94 != 0) {
        camera->always_rotate_flag = 1;
      }
      DAT_800cdf94 = 0;
    }
  }
  if (((camera->forced_movement != 1) && (DAT_800cdf94 == 0)) && (camera->rotState != 3)) {
    CAMERA_CalcRotation(&local_20,&camera->focusPoint,(_Position *)&local_30);
    local_28.x = (camera->focusPoint).x - local_30.x;
    local_28.y = (camera->focusPoint).y - local_30.y;
    local_28.z = (camera->focusPoint).z - local_30.z;
    lVar2 = CAMERA_LengthSVector(&local_28);
    distance = (short)lVar2;
    (camera->targetFocusRotation).z = local_20.z;
  }
  smooth = 0x40;
  if (camera->always_rotate_flag == 0) {
    smooth = 0x50;
    smooth_00 = 0x40;
  }
  else {
    smooth_00 = 0x80;
  }
  (camera->focusRotation).y = local_20.y;
  camera->x_rot_change = (camera->focusRotation).x;
  CriticalDampAngle(1,(short *)&camera->focusRotation,local_20.x,(short *)&camera->focusRotVel,
                    (short *)&camera->focusRotAccl,0x40);
  sVar1 = CAMERA_SignedAngleDifference(camera->x_rot_change,(camera->focusRotation).x);
  camera->x_rot_change = sVar1;
  if (camera->rotState == 3) {
    local_20.z = (camera->targetFocusRotation).z;
  }
  CriticalDampAngle(5,&(camera->focusRotation).z,local_20.z,&(camera->focusRotVel).z,
                    &(camera->focusRotAccl).z,smooth);
  if (((camera->forced_movement == 1) || (camera->always_rotate_flag != 0)) || (DAT_800cdf94 != 0))
  {
    CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,&camera->focusRotation,
                        camera->targetFocusDistance);
    lVar2 = CAMERA_DoCameraCollision2(camera,&camera->targetPos,1);
    (camera->data).Follow.hit = lVar2;
    if (lVar2 != 0) {
      distance = camera->collisionTargetFocusDistance;
    }
  }
  CriticalDampValue(5,&camera->focusDistance,distance,&camera->focusDistanceVel,
                    &camera->focusDistanceAccl,smooth_00);
                    /* WARNING: Subroutine does not return */
  CAMERA_AngleDifference((camera->focusRotation).z,local_20.z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ShakeCamera(struct Camera *camera /*$a2*/)
 // line 4201, offset 0x8001b3c8
	/* begin block 1 */
		// Start line: 9967
	/* end block 1 */
	// End Line: 9968

void CAMERA_ShakeCamera(Camera *camera)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if (0 < camera->shake) {
    uVar1 = camera->shakeFrame;
    (camera->core).position.x =
         (camera->core).position.x +
         (short)((int)*(short *)(&vmClock + ((uint)(ushort)camera->shakeFrame & 0xf) * 2) *
                 (int)camera->shakeScale >> 0xc);
    uVar2 = camera->shakeFrame;
    (camera->core).position.y =
         (camera->core).position.y +
         (short)((int)*(short *)((int)&vmClock + ((uint)uVar1 & 0xf) * 8 + 2) *
                 (int)camera->shakeScale >> 0xc);
    (camera->core).position.z =
         (camera->core).position.z +
         (short)((int)*(short *)(&DAT_800cfde8 + ((uint)uVar2 & 0xf) * 8) * (int)camera->shakeScale
                >> 0xc);
    iVar3 = camera->shake - theCamera.tiltList[0][0];
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
 // line 4220, offset 0x8001b4b0
	/* begin block 1 */
		// Start line: 4221
		// Start offset: 0x8001B4B0
		// Variables:
	// 		struct _Instance *focusInstance; // $a1

		/* begin block 1.1 */
			// Start line: 4280
			// Start offset: 0x8001B584
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
		// End offset: 0x8001B584
		// End Line: 4280
	/* end block 1 */
	// End offset: 0x8001B6EC
	// End Line: 4383

	/* begin block 2 */
		// Start line: 10009
	/* end block 2 */
	// End Line: 10010

void CAMERA_Process(Camera *camera)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  _Instance *p_Var10;
  undefined4 uVar11;
  
  p_Var10 = camera->focusInstance;
  camera->focuspoint_fallz =
       camera->focuspoint_fallz - ((camera->newFocusInstancePos).z - (p_Var10->oldPos).z);
  sVar1 = (camera->newFocusInstancePos).z;
  *(undefined4 *)&camera->oldFocusInstancePos = *(undefined4 *)&camera->newFocusInstancePos;
  (camera->oldFocusInstancePos).z = sVar1;
  sVar1 = (p_Var10->position).z;
  *(undefined4 *)&camera->newFocusInstancePos = *(undefined4 *)&p_Var10->position;
  (camera->newFocusInstancePos).z = sVar1;
  uVar11 = *(undefined4 *)&(camera->newFocusInstanceRot).z;
  *(undefined4 *)&camera->oldFocusInstanceRot = *(undefined4 *)&camera->newFocusInstanceRot;
  *(undefined4 *)&(camera->oldFocusInstanceRot).z = uVar11;
  uVar11 = *(undefined4 *)&(p_Var10->rotation).z;
  *(undefined4 *)&camera->newFocusInstanceRot = *(undefined4 *)&p_Var10->rotation;
  *(undefined4 *)&(camera->newFocusInstanceRot).z = uVar11;
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
  lVar8 = MATH3D_FastSqrt0(iVar6 * iVar6 + iVar7 * iVar7);
  camera->instance_xyvel = lVar8;
  if (shorten_flag == 0) {
    shorten_count = 0;
  }
  shorten_flag = 0;
  if (0 < camera->cuckooTimer) {
    camera->cuckooTimer = camera->cuckooTimer + -1;
  }
  uVar9 = SEXT24(camera->mode);
  if (uVar9 != 6) {
    CAMERA_HandleTransitions(camera);
    uVar9 = SEXT24(camera->mode);
  }
  if (uVar9 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x8001b68c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_ARRAY_80010134[uVar9])();
    return;
  }
  camera->flags = camera->flags & 0xffffe7ff;
  CAMERA_ShakeCamera(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CenterCamera(struct Camera *camera /*$s1*/)
 // line 4404, offset 0x8001b6fc
	/* begin block 1 */
		// Start line: 4405
		// Start offset: 0x8001B6FC

		/* begin block 1.1 */
			// Start line: 4409
			// Start offset: 0x8001B724
			// Variables:
		// 		int tmp1; // $s0
		// 		int tmp2; // $v0
		/* end block 1.1 */
		// End offset: 0x8001B790
		// End Line: 4413
	/* end block 1 */
	// End offset: 0x8001B7BC
	// End Line: 4420

	/* begin block 2 */
		// Start line: 10388
	/* end block 2 */
	// End Line: 10389

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
 // line 4436, offset 0x8001b7e4
	/* begin block 1 */
		// Start line: 8872
	/* end block 1 */
	// End Line: 8873

	/* begin block 2 */
		// Start line: 10441
	/* end block 2 */
	// End Line: 10442

void CAMERA_SetLookRot(Camera *camera,int x_rotation,int z_rotation)

{
  (camera->lookRot).x = (short)x_rotation;
  (camera->lookRot).z = (short)z_rotation;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_StartLookaroundMode(struct Camera *camera /*$s0*/)
 // line 4442, offset 0x8001b7f0
	/* begin block 1 */
		// Start line: 10452
	/* end block 1 */
	// End Line: 10453

void CAMERA_StartLookaroundMode(Camera *camera)

{
  _Instance *focusInstance;
  undefined4 uVar1;
  
  Camera_lookHeight = 0x200;
  Camera_lookDist = 0x28a;
  CAMERA_SaveMode(camera,(int)camera->mode);
  camera->mode = 6;
  camera->savedFocusDistance = camera->targetFocusDistance;
  uVar1 = *(undefined4 *)&(camera->targetFocusRotation).z;
  *(undefined4 *)&camera->savedFocusRotation = *(undefined4 *)&camera->targetFocusRotation;
  *(undefined4 *)&(camera->savedFocusRotation).z = uVar1;
  focusInstance = camera->focusInstance;
  camera->targetFocusDistance = 0x28a;
  (camera->lookRot).x = 0;
  (camera->lookRot).y = 0;
  (camera->lookRot).z = 0;
  CAMERA_SetLookFocusAndBase(focusInstance,&camera->targetFocusPoint);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_StartSwimThrowMode(struct Camera *camera /*$s0*/)
 // line 4460, offset 0x8001b880
	/* begin block 1 */
		// Start line: 10498
	/* end block 1 */
	// End Line: 10499

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
 // line 4468, offset 0x8001b8c0
	/* begin block 1 */
		// Start line: 10515
	/* end block 1 */
	// End Line: 10516

void CAMERA_EndSwimThrowMode(Camera *camera)

{
  CameraLookStickyFlag = 0;
  CAMERA_EndLook(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ForceEndLookaroundMode(struct Camera *camera /*$s0*/)
 // line 4474, offset 0x8001b8e4
	/* begin block 1 */
		// Start line: 10527
	/* end block 1 */
	// End Line: 10528

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
 // line 4483, offset 0x8001b920
	/* begin block 1 */
		// Start line: 4484
		// Start offset: 0x8001B920
		// Variables:
	// 		long *controlCommand; // $s2
	// 		int lookmode; // $s1
	// 		struct _Instance *focusInstance; // $s4
	/* end block 1 */
	// End offset: 0x8001BE44
	// End Line: 4718

	/* begin block 2 */
		// Start line: 10545
	/* end block 2 */
	// End Line: 10546

void CAMERA_Control(Camera *camera,_Instance *playerInstance)

{
  bool bVar1;
  short angle1;
  ulong uVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  _Instance *instance;
  
  instance = camera->focusInstance;
  if ((theCamera.positionAccl._4_4_ & 0x100000) == 0) {
    bVar1 = true;
    if (CameraLookStickyFlag == 0) {
      bVar1 = (theCamera.core.vvPlaneConsts[4] & 0xc00U) == 0xc00;
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
        CriticalDampAngle(1,&(camera->focusRotation).z,CenterFlag,&(camera->focusRotVel).z,
                          &(camera->focusRotAccl).z,0x90);
        angle1 = CenterFlag;
        sVar3 = (camera->focusRotation).z;
        (camera->collisionTargetFocusRotation).z = sVar3;
                    /* WARNING: Subroutine does not return */
        (camera->targetFocusRotation).z = sVar3;
        CAMERA_AngleDifference((camera->focusRotation).z,angle1);
      }
      if ((theCamera.focusSphere.radiusSquared._3_1_ != '\x01') ||
         ((theCamera.core.vvPlaneConsts[4] & 0xfU) == 0)) {
        if ((((camera->lock & 4U) == 0) && ((camera->flags & 0x10000U) == 0)) &&
           (((((sVar3 == 0 || (sVar3 == 0xc)) || (sVar3 == 4)) || (sVar3 == 0xd)) &&
            ((playerInstance->flags & 0x100U) == 0)))) {
          if (((theCamera.core.vvPlaneConsts[4] & 0x400U) == 0) || (bVar1)) {
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
              uVar5 = (camera->focusRotation).z -
                      (short)((uint)(theCamera.tiltList[0][0] << 5) >> 0xc) & 0xfff;
              (camera->focusRotation).z = uVar5;
              uVar2 = theCamera.focusRotation._0_4_;
              camera->forced_movement = 1;
              (camera->data).Follow.stopTimer = -0x1a5e0000;
              (camera->focusRotation).z = uVar5;
              (camera->collisionTargetFocusRotation).z = uVar5;
              (camera->targetFocusRotation).z = uVar5;
              camera->lastModTime = uVar2;
            }
          }
          if (((theCamera.core.vvPlaneConsts[4] & 0x800U) == 0) || (bVar1)) {
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
              uVar5 = (camera->focusRotation).z +
                      (short)((uint)(theCamera.tiltList[0][0] << 5) >> 0xc) & 0xfff;
              (camera->focusRotation).z = uVar5;
              uVar2 = theCamera.focusRotation._0_4_;
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
        if ((theCamera.core._212_4_ & 0x2000000) != 0) {
          if ((camera->lock & 1U) == 0) {
            if (((theCamera.core.vvPlaneConsts[4] & 0x40000008U) == 0x40000008) &&
               (sVar3 = camera->targetFocusDistance + -0x14, camera->targetFocusDistance = sVar3,
               sVar3 < 200)) {
              camera->targetFocusDistance = 200;
            }
            if (((theCamera.core.vvPlaneConsts[4] & 0x40000004U) == 0x40000004) &&
               (sVar3 = camera->targetFocusDistance + 0x14, camera->targetFocusDistance = sVar3,
               0x1000 < sVar3)) {
              camera->targetFocusDistance = 0x1000;
            }
          }
          if ((camera->lock & 2U) == 0) {
            if ((theCamera.core.vvPlaneConsts[4] & 0x40000002U) == 0x40000002) {
              camera->extraXRot = camera->extraXRot + 0x10;
            }
            if ((theCamera.core.vvPlaneConsts[4] & 0x40000001U) == 0x40000001) {
              camera->extraXRot = camera->extraXRot + -0x10;
            }
          }
        }
        if ((bVar1) && ((playerInstance->flags & 0x100U) == 0)) {
          if (((camera->flags & 0x20000U) != 0) && (camera->mode != 5)) {
            sVar3 = camera->lookTimer + 1;
            camera->lookTimer = sVar3;
            uVar4 = (uint)(sVar3 < 3);
            if (sVar3 == 2) {
              DEBUG_UpdateFog((long *)instance);
              if ((uVar4 != 0) && ((camera->lock & 0x200U) == 0)) {
                CAMERA_StartLookaroundMode(camera);
                PLAYER_SetLookAround(instance);
                camera->collideRotControl = 0;
                return;
              }
              camera->lookTimer = 0;
            }
            else {
              if ((sVar3 >= 3) && (camera->mode == 6)) {
                PLAYER_TurnHead(instance,(short *)&camera->lookRot,&(camera->lookRot).z,
                                (GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
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
 // line 4721, offset 0x8001be68
	/* begin block 1 */
		// Start line: 4722
		// Start offset: 0x8001BE68
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001BF44
	// End Line: 4782

	/* begin block 2 */
		// Start line: 11051
	/* end block 2 */
	// End Line: 11052

void CAMERA_EndLook(Camera *camera)

{
  short sVar1;
  uint uVar2;
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
    if ((camera->mode != 4) && (camera->mode != 2)) {
      (camera->targetFocusRotation).z = (instance->rotation).z + 0x800U & 0xfff;
      CAMERA_CenterCamera(camera);
    }
    sVar1 = (camera->targetFocusRotation).z;
    camera->always_rotate_flag = 1;
    uVar2 = camera->flags;
    (camera->collisionTargetFocusRotation).z = sVar1;
    if ((uVar2 & 0x10000) == 0) {
      camera->actual_x_rot = (camera->core).rotation.x;
    }
    PLAYER_ReSetLookAround(instance);
  }
  camera->lookTimer = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ChangeToUnderWater(struct Camera *camera /*$s0*/, struct _Instance *instance /*$a1*/)
 // line 4786, offset 0x8001bf5c
	/* begin block 1 */
		// Start line: 11218
	/* end block 1 */
	// End Line: 11219

void CAMERA_ChangeToUnderWater(Camera *camera,_Instance *instance)

{
  short sVar1;
  
  if (instance == camera->focusInstance) {
    sVar1 = camera->mode;
    if (sVar1 != 4) {
      if (sVar1 == 5) {
        CAMERA_SaveMode(camera,0xd);
      }
      else {
        if (sVar1 == 0xd) {
          CAMERA_CreateNewFocuspoint(camera);
        }
        else {
          CAMERA_SetMode(camera,0xd);
        }
        camera->smooth = 8;
        camera->targetFocusDistance = 0x640;
        camera->collisionTargetFocusDistance = 0x640;
        camera->signalFocusDistance = 0x640;
        (camera->rotationVel).z = 0x20;
        camera->always_rotate_flag = 0;
      }
    }
    camera->flags = camera->flags | 0x10000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ChangeToOutOfWater(struct Camera *camera /*$s0*/, struct _Instance *instance /*$a1*/)
 // line 4813, offset 0x8001c008
	/* begin block 1 */
		// Start line: 11272
	/* end block 1 */
	// End Line: 11273

void CAMERA_ChangeToOutOfWater(Camera *camera,_Instance *instance)

{
  if (instance == camera->focusInstance) {
    if (camera->mode == 5) {
      CAMERA_SaveMode(camera,0xd);
    }
    else {
      CAMERA_SetMode(camera,0xd);
      (camera->rotationVel).z = 0;
      camera->targetTilt = 0;
    }
    camera->flags = camera->flags & 0xfffeffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusDistance(struct Camera *camera /*$a3*/)
 // line 4929, offset 0x8001c07c
	/* begin block 1 */
		// Start line: 4930
		// Start offset: 0x8001C07C
		// Variables:
	// 		int smooth; // $v1
	// 		long dampMode; // $a0
	/* end block 1 */
	// End offset: 0x8001C13C
	// End Line: 4977

	/* begin block 2 */
		// Start line: 9858
	/* end block 2 */
	// End Line: 9859

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
 // line 4979, offset 0x8001c14c
	/* begin block 1 */
		// Start line: 11503
	/* end block 1 */
	// End Line: 11504

void CAMERA_UpdateFocusTilt(Camera *camera)

{
  short sVar1;
  
  if ((camera->flags & 0x1800U) == 0) {
    camera->x_rot_change = (camera->focusRotation).x;
    if (((camera->forced_movement == 3) || ((camera->lock & 2U) != 0)) &&
       ((camera->flags & 0x10000U) == 0)) {
      (camera->focusRotation).x = (camera->targetFocusRotation).x;
    }
    else {
      CriticalDampAngle(1,(short *)&camera->focusRotation,camera->tfaceTilt,
                        (short *)&camera->focusRotVel,(short *)&camera->focusRotAccl,0x20);
    }
    sVar1 = CAMERA_SignedAngleDifference(camera->x_rot_change,(camera->focusRotation).x);
    camera->x_rot_change = sVar1;
  }
  else {
    camera->x_rot_change = 0;
    (camera->focusRotation).x = camera->tfaceTilt;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRoll(struct Camera *camera /*$s1*/)
 // line 5013, offset 0x8001c218
	/* begin block 1 */
		// Start line: 5014
		// Start offset: 0x8001C218
		// Variables:
	// 		long tmp_inc; // $s0
	/* end block 1 */
	// End offset: 0x8001C318
	// End Line: 5031

	/* begin block 2 */
		// Start line: 11574
	/* end block 2 */
	// End Line: 11575

	/* begin block 3 */
		// Start line: 11577
	/* end block 3 */
	// End Line: 11578

void CAMERA_UpdateFocusRoll(Camera *camera)

{
  long lVar1;
  _Instance *in_a1;
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
  if (-1 < current_roll_amount) {
    CAMERA_ChangeToUnderWater(camera,in_a1);
    return;
  }
  (camera->core).rotation.y = (short)(current_roll_amount + 0xfff >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotate(struct Camera *camera /*$s0*/)
 // line 5037, offset 0x8001c334
	/* begin block 1 */
		// Start line: 5038
		// Start offset: 0x8001C334

		/* begin block 1.1 */
			// Start line: 5041
			// Start offset: 0x8001C368
			// Variables:
		// 		int dampspeed; // $v1
		// 		long dampmode; // $a0
		/* end block 1.1 */
		// End offset: 0x8001C3E8
		// End Line: 5066
	/* end block 1 */
	// End offset: 0x8001C410
	// End Line: 5073

	/* begin block 2 */
		// Start line: 11626
	/* end block 2 */
	// End Line: 11627

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
      CriticalDampAngle(dampMode,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z
                        ,&(camera->focusRotVel).z,&(camera->focusRotAccl).z,(int)sVar1);
                    /* WARNING: Subroutine does not return */
      CAMERA_AngleDifference((camera->targetFocusRotation).z,(camera->focusRotation).z);
    }
  }
  (camera->focusRotation).z = (camera->targetFocusRotation).z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotationX(struct Camera *camera /*$s0*/, struct _Instance *focusInstance /*$a1*/)
 // line 5079, offset 0x8001c420
	/* begin block 1 */
		// Start line: 5080
		// Start offset: 0x8001C420
		// Variables:
	// 		short cameraPlayerRotX; // $a1
	// 		short dist; // $s1
	// 		short tfaceFlag; // $s2

		/* begin block 1.1 */
			// Start line: 5102
			// Start offset: 0x8001C4A0
			// Variables:
		// 		struct _Normal normal; // stack offset -24
		// 		int mult; // $v1
		/* end block 1.1 */
		// End offset: 0x8001C580
		// End Line: 5128

		/* begin block 1.2 */
			// Start line: 5132
			// Start offset: 0x8001C58C
			// Variables:
		// 		int tmpsmooth; // $t0
		/* end block 1.2 */
		// End offset: 0x8001C5F8
		// End Line: 5147
	/* end block 1 */
	// End offset: 0x8001C688
	// End Line: 5173

	/* begin block 2 */
		// Start line: 11710
	/* end block 2 */
	// End Line: 11711

void CAMERA_UpdateFocusRotationX(Camera *camera,_Instance *focusInstance)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  uint uVar6;
  _TFace *p_Var7;
  ushort uVar8;
  int smooth;
  _SVector _Stack24;
  
  p_Var7 = focusInstance->tface;
  sVar1 = camera->targetFocusDistance;
  bVar2 = false;
  if ((((p_Var7 != (_TFace *)0x0) && (smooth = *(int *)focusInstance->tfaceLevel, smooth != 0)) &&
      (p_Var7->textoff != 0xffff)) &&
     (((*(ushort *)(*(int *)(smooth + 0x34) + (uint)p_Var7->textoff + 10) & 0x8000) != 0 &&
      (bVar2 = false, sVar1 < 0xb60)))) {
    COLLIDE_GetNormal(p_Var7->normal,*(short **)(smooth + 0x24),&_Stack24);
    bVar2 = false;
    if (_Stack24.z < 0xf6e) {
      bVar2 = true;
      lVar5 = CAMERA_CalcTilt((_Normal *)&_Stack24,(camera->focusRotation).z);
      smooth = lVar5 * 10;
      if (smooth < 0) {
        smooth = smooth + 0xf;
      }
      sVar3 = (short)(smooth >> 4);
      camera->targetTilt = sVar3;
      sVar4 = -0x100;
      if (sVar3 < -0x100) {
LAB_8001c518:
        camera->targetTilt = sVar4;
      }
      else {
        if (0x100 < sVar3) {
          sVar4 = 0x100;
          goto LAB_8001c518;
        }
      }
      smooth = 0xb60 - (int)sVar1;
      if (smooth < 0x200) {
        smooth = camera->targetTilt * smooth;
        if (smooth < 0) {
          smooth = smooth + 0x1ff;
        }
        camera->targetTilt = (short)(smooth >> 9);
      }
      CriticalDampAngle(1,&camera->tilt,camera->targetTilt,&camera->tiltVel,&camera->tiltAccl,8);
    }
  }
  if (!bVar2) {
    smooth = 0x18;
    if ((camera->instance_mode & 0x38) == 0) {
      camera->targetTilt = 0;
    }
    if (((camera->instance_mode & 0x2000) != 0) &&
       ((camera->real_focuspoint).z < camera->focuspoint_fallz)) {
      camera->targetTilt = -0x180;
      smooth = 0xc;
    }
    CriticalDampAngle(1,&camera->tilt,camera->targetTilt,&camera->tiltVel,&camera->tiltAccl,smooth);
  }
  uVar6 = (uint)(ushort)camera->extraXRot +
          (uint)(ushort)(camera->targetFocusRotation).x + (uint)(ushort)camera->tilt & 0xfff;
  if (uVar6 - 0x301 < 0x4ff) {
    uVar6 = 0x300;
  }
  else {
    if (0x4ff < uVar6 - 0x800) goto LAB_8001c640;
    uVar6 = 0xfffffd00;
  }
  uVar6 = uVar6 & 0xfff;
LAB_8001c640:
  uVar8 = (ushort)uVar6;
  camera->tfaceTilt = uVar8;
  if ((camera->instance_mode & 0x2000000) != 0) {
    if (0x800 < uVar6) {
      uVar8 = uVar8 | 0xf000;
    }
    if (Spiral_Current._2_2_ < (short)uVar8) {
      camera->tfaceTilt = Spiral_Current._2_2_ + 0x1000;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowPlayerTilt(struct Camera *camera /*$s1*/, struct _Instance *focusInstance /*$a1*/)
 // line 5178, offset 0x8001c6a0
	/* begin block 1 */
		// Start line: 5179
		// Start offset: 0x8001C6A0
		// Variables:
	// 		int speed; // $s2
	// 		int mode; // $s3
	// 		long focusInstanceStatus; // $a0

		/* begin block 1.1 */
			// Start line: 5203
			// Start offset: 0x8001C724
			// Variables:
		// 		struct _SVector offset; // stack offset -40
		// 		struct _Normal normal; // stack offset -32

			/* begin block 1.1.1 */
				// Start line: 5227
				// Start offset: 0x8001C7DC
				// Variables:
			// 		int waterZ; // $v0
			// 		int target; // $v0
			// 		int height; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 5235
					// Start offset: 0x8001C81C
					// Variables:
				// 		int fdsq; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8001C85C
				// End Line: 5243
			/* end block 1.1.1 */
			// End offset: 0x8001C85C
			// End Line: 5244
		/* end block 1.1 */
		// End offset: 0x8001C85C
		// End Line: 5245
	/* end block 1 */
	// End offset: 0x8001C85C
	// End Line: 5250

	/* begin block 2 */
		// Start line: 11914
	/* end block 2 */
	// End Line: 11915

void CAMERA_FollowPlayerTilt(Camera *camera,_Instance *focusInstance)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(focusInstance,9);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera /*$s0*/)
 // line 5259, offset 0x8001c8b0
	/* begin block 1 */
		// Start line: 5260
		// Start offset: 0x8001C8B0
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001C998
	// End Line: 5298

	/* begin block 2 */
		// Start line: 12087
	/* end block 2 */
	// End Line: 12088

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
    if ((fontTracker.font_buffer[85]._2_4_ & 0x100000) != 0) goto LAB_8001c928;
    iVar1 = (camera->data).Follow.stopTimer + fontTracker.font_buffer[127]._2_4_;
  }
  else {
    iVar1 = DAT_800d0b64 * -0x1e000;
  }
  (camera->data).Follow.stopTimer = iVar1;
LAB_8001c928:
  if (0 < (camera->data).Follow.stopTimer) {
    CAMERA_Unlock((Camera *)&(camera->targetFocusRotation).z,
                  (int)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000) >> 0x10);
    CAMERA_Unlock((Camera *)&(camera->collisionTargetFocusRotation).z,
                  (int)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000) >> 0x10);
    CriticalDampAngle(1,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z,
                      &(camera->focusRotVel).z,&(camera->focusRotAccl).z,0x20);
    camera->forced_movement = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayer(struct Camera *camera /*$v1*/)
 // line 5301, offset 0x8001c9ac
	/* begin block 1 */
		// Start line: 5302
		// Start offset: 0x8001C9AC
		// Variables:
	// 		struct _Instance *focusInstance; // $v0
	/* end block 1 */
	// End offset: 0x8001C9AC
	// End Line: 5302

	/* begin block 2 */
		// Start line: 12179
	/* end block 2 */
	// End Line: 12180

void CAMERA_FollowGoBehindPlayer(Camera *camera)

{
  CAMERA_Unlock((Camera *)&(camera->targetFocusRotation).z,
                (int)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x800) * 0x10000) >> 0x10
               );
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalculateLead(struct Camera *camera /*$s1*/)
 // line 5313, offset 0x8001c9e8
	/* begin block 1 */
		// Start line: 5314
		// Start offset: 0x8001C9E8
		// Variables:
	// 		short lead_target; // $s0
	// 		short lead_smooth; // $v1

		/* begin block 1.1 */
			// Start line: 5320
			// Start offset: 0x8001CA34
			// Variables:
		// 		int speedxy; // $s0
		// 		short angle; // $a0

			/* begin block 1.1.1 */
				// Start line: 5332
				// Start offset: 0x8001CABC
				// Variables:
			// 		int calc; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8001CB2C
			// End Line: 5349
		/* end block 1.1 */
		// End offset: 0x8001CB34
		// End Line: 5354
	/* end block 1 */
	// End offset: 0x8001CB40
	// End Line: 5368

	/* begin block 2 */
		// Start line: 12203
	/* end block 2 */
	// End Line: 12204

void CAMERA_CalculateLead(Camera *camera)

{
  ushort uVar1;
  short angle0;
  int iVar2;
  
  if ((((camera->flags & 0x10000U) == 0) && (camera->mode != 6)) &&
     ((camera->instance_mode & 0x3002043) == 0)) {
    iVar2 = camera->instance_xyvel;
    uVar1 = CAMERA_SignedAngleDifference
                      ((short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x800) * 0x10000
                              >> 0x10),(camera->core).rotation.z);
    if (iVar2 < 0x17) {
      if (camera->instance_prev_xyvel == 0) {
        camera->lead_timer = 0;
      }
    }
    else {
      camera->lead_timer = camera->lead_timer + 1;
    }
    if (0x16 < iVar2) {
      iVar2 = (int)(short)uVar1;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 - 0x191U < 0x4af) {
        iVar2 = (int)camera->lead_timer;
        if (0x23 < iVar2) {
          iVar2 = (iVar2 + -0x23) * 3 + 0x23;
        }
        if ((int)((uint)uVar1 << 0x10) < 1) {
          angle0 = -(short)iVar2;
          if (iVar2 >= 0x50) {
            angle0 = -0x50;
          }
        }
        else {
          angle0 = 0x50;
          if (iVar2 < 0x50) {
            angle0 = (short)iVar2;
          }
        }
                    /* WARNING: Subroutine does not return */
        CAMERA_AngleDifference(angle0,camera->lead_angle);
      }
    }
  }
  else {
    camera->lead_timer = 0;
  }
  CriticalDampAngle(1,&camera->lead_angle,0,&camera->lead_vel,&camera->lead_accl,3);
  (camera->core).rotation.z = (camera->core).rotation.z + camera->lead_angle & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFollowPosition(struct Camera *camera /*$s1*/, struct _Rotation *rotation /*$s0*/)
 // line 5384, offset 0x8001cb90
	/* begin block 1 */
		// Start line: 5385
		// Start offset: 0x8001CB90
		// Variables:
	// 		struct _Instance *focusInstance; // $s2

		/* begin block 1.1 */
			// Start line: 5385
			// Start offset: 0x8001CB90
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CB90
		// End Line: 5385

		/* begin block 1.2 */
			// Start line: 5404
			// Start offset: 0x8001CC10
			// Variables:
		// 		short target_rotx; // $s0
		// 		int hypotXY; // $s3
		// 		int smooth; // $v1
		// 		int diff; // $a0
		// 		struct _Vector dpv; // stack offset -40
		// 		int zdiff; // $a0

			/* begin block 1.2.1 */
				// Start line: 5426
				// Start offset: 0x8001CCAC
				// Variables:
			// 		int velz; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 5437
					// Start offset: 0x8001CCC8
					// Variables:
				// 		int ground; // $a0
				// 		int pos; // $v1
				/* end block 1.2.1.1 */
				// End offset: 0x8001CD40
				// End Line: 5452
			/* end block 1.2.1 */
			// End offset: 0x8001CD40
			// End Line: 5452
		/* end block 1.2 */
		// End offset: 0x8001CE4C
		// End Line: 5500
	/* end block 1 */
	// End offset: 0x8001CE64
	// End Line: 5505

	/* begin block 2 */
		// Start line: 12347
	/* end block 2 */
	// End Line: 12348

void CAMERA_CalcFollowPosition(Camera *camera,_Rotation *rotation)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_t2;
  undefined4 in_t3;
  
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,rotation,camera->focusDistance);
  sVar1 = (camera->targetPos).z;
  *(undefined4 *)&(camera->core).position = *(undefined4 *)&camera->targetPos;
  (camera->core).position.z = sVar1;
  sVar2 = rotation->y;
  sVar3 = rotation->z;
  (camera->core).rotation.x = rotation->x;
  (camera->core).rotation.y = sVar2;
  (camera->core).rotation.z = sVar3;
  if ((camera->flags & 0x10000U) == 0) {
    sVar2 = (camera->real_focuspoint).x;
    sVar3 = (camera->targetPos).x;
    camera->actual_x_rot = camera->actual_x_rot - camera->x_rot_change;
    setCopReg(2,(int)sVar1,(int)sVar2 - (int)sVar3);
    setCopReg(2,in_t2,(int)(camera->real_focuspoint).y - (int)(camera->targetPos).y);
    setCopReg(2,in_t3,0);
    copFunction(2,0xa00428);
    iVar4 = getCopReg(2,0x19);
    iVar5 = getCopReg(2,0x1a);
    getCopReg(2,0x1b);
    uVar6 = MATH3D_FastSqrt0(iVar4 + iVar5);
                    /* WARNING: Subroutine does not return */
    ratan2((int)(camera->real_focuspoint).z - (int)(camera->targetPos).z,uVar6);
  }
  camera->actual_x_rot = (camera->core).rotation.x;
  camera->lagZ = (camera->core).rotation.z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetupColInfo(struct Camera *camera /*$a3*/, struct CameraCollisionInfo *colInfo /*$t0*/, struct _Position *targetCamPos /*$a2*/)
 // line 5509, offset 0x8001ce8c
	/* begin block 1 */
		// Start line: 5510
		// Start offset: 0x8001CE8C
		// Variables:
	// 		static short toggle; // offset 0x60

		/* begin block 1.1 */
			// Start line: 5515
			// Start offset: 0x8001CEA0
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CEA0
		// End Line: 5515

		/* begin block 1.2 */
			// Start line: 5519
			// Start offset: 0x8001CEAC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001CECC
		// End Line: 5519

		/* begin block 1.3 */
			// Start line: 5521
			// Start offset: 0x8001CECC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v1
		/* end block 1.3 */
		// End offset: 0x8001CECC
		// End Line: 5521
	/* end block 1 */
	// End offset: 0x8001CF44
	// End Line: 5542

	/* begin block 2 */
		// Start line: 12616
	/* end block 2 */
	// End Line: 12617

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
    bVar1 = DAT_800cdf98 == 0;
    colInfo->cldLines = 6;
    if (bVar1) {
      lVar5 = 0x16;
    }
    else {
      lVar5 = 0xe;
    }
  }
  colInfo->cldLines = lVar5;
  if (DAT_800cdf98 != 0) {
    DAT_800cdf98 = 0;
    return;
  }
  DAT_800cdf98 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_DoPanicCheck(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *tmpcolInfo /*$s1*/, struct _Rotation *rotation /*$s3*/, short *best_z /*$s4*/, short *max_dist /*stack 16*/)
 // line 5550, offset 0x8001cf4c
	/* begin block 1 */
		// Start line: 5551
		// Start offset: 0x8001CF4C
		// Variables:
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 5551
			// Start offset: 0x8001CF4C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CF4C
		// End Line: 5551
	/* end block 1 */
	// End offset: 0x8001CFFC
	// End Line: 5563

	/* begin block 2 */
		// Start line: 12701
	/* end block 2 */
	// End Line: 12702

void CAMERA_DoPanicCheck(Camera *camera,CameraCollisionInfo *tmpcolInfo,_Rotation *rotation,
                        short *best_z,short *max_dist)

{
  _Position local_20;
  
  CAMERA_CalcPosition(&local_20,&camera->focusPoint,rotation,camera->targetFocusDistance);
  (camera->posSphere).position.x = local_20.x;
  (camera->posSphere).position.y = local_20.y;
  (camera->posSphere).position.z = local_20.z;
  CAMERA_SphereToSphereWithLines(camera,tmpcolInfo,0);
  if ((tmpcolInfo->numCollided == 0) || ((int)*max_dist < tmpcolInfo->lenCenterToExtend)) {
    *best_z = rotation->z;
    *max_dist = *(short *)&tmpcolInfo->lenCenterToExtend;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Panic(struct Camera *camera /*$s2*/, short min_dist /*$fp*/)
 // line 5565, offset 0x8001d01c
	/* begin block 1 */
		// Start line: 5566
		// Start offset: 0x8001D01C
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
	// End offset: 0x8001D19C
	// End Line: 5615

	/* begin block 2 */
		// Start line: 12739
	/* end block 2 */
	// End Line: 12740

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
 // line 5619, offset 0x8001d1cc
	/* begin block 1 */
		// Start line: 5620
		// Start offset: 0x8001D1CC
		// Variables:
	// 		int secondcheck_flag; // $s0
	// 		long hit; // $s2
	// 		struct CameraCollisionInfo colInfo; // stack offset -120
	// 		static long collisiontimeDown; // offset 0x64

		/* begin block 1.1 */
			// Start line: 5710
			// Start offset: 0x8001D40C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001D40C
		// End Line: 5710

		/* begin block 1.2 */
			// Start line: 5766
			// Start offset: 0x8001D558
			// Variables:
		// 		int speed; // $s0
		/* end block 1.2 */
		// End offset: 0x8001D620
		// End Line: 5786

		/* begin block 1.3 */
			// Start line: 5816
			// Start offset: 0x8001D6A8
			// Variables:
		// 		int angle1; // $s0
		// 		int angle2; // $v0
		/* end block 1.3 */
		// End offset: 0x8001D754
		// End Line: 5832
	/* end block 1 */
	// End offset: 0x8001D7B4
	// End Line: 5871

	/* begin block 2 */
		// Start line: 12897
	/* end block 2 */
	// End Line: 12898

/* WARNING: Could not reconcile some variable overlaps */

long CAMERA_DoCameraCollision2(Camera *camera,_Position *targetCamPos,int simpleflag)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  _TFace *p_Var4;
  uint uVar5;
  int iVar6;
  int iVar7;
  Camera *camera_00;
  CameraCollisionInfo *colInfo;
  _Rotation *rotation;
  short *in_a3;
  _Rotation *secondcheck_flag;
  long lVar8;
  short *in_stack_ffffff88;
  ushort auStack68 [6];
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  lVar8 = 0;
  CAMERA_SetupColInfo(camera,(CameraCollisionInfo *)&stack0xffffff88,targetCamPos);
  secondcheck_flag = (_Rotation *)0x0;
  if ((camera->flags & 0x10000U) == 0) {
    iVar7 = (int)(camera->real_focuspoint).z;
    iVar6 = (int)(camera->targetFocusPoint).z;
    iVar3 = iVar7 - iVar6;
    if (iVar3 < 0) {
      iVar3 = iVar6 - iVar7;
    }
    secondcheck_flag = (_Rotation *)0x0;
    if (4 < iVar3) {
      secondcheck_flag = (_Rotation *)&UNK_00000001;
    }
  }
  colInfo = (CameraCollisionInfo *)&stack0xffffff88;
  camera_00 = camera;
  rotation = secondcheck_flag;
  p_Var4 = CAMERA_SphereToSphereWithLines(camera,colInfo,(int)secondcheck_flag);
  (camera->data).Follow.tface = p_Var4;
  if ((((((camera->instance_mode & 0x2000000) != 0) && (0 < local_30)) && (local_2c < 600)) &&
      ((CenterFlag = -1, local_30 != 1 || ((local_38 & 6) == 0)))) &&
     (sVar2 = (short)Spiral_Max + 0x90, (short)Spiral_Max < 0x1000)) {
    Spiral_Max._0_2_ = sVar2;
    if (0xfff < sVar2) {
      Spiral_Max._0_2_ = 0x1000;
    }
    if ((short)Spiral_Max < 0xf3c) {
      CenterFlag = -1;
      return 1;
    }
  }
  if (((((camera->flags & 0x12000U) == 0) && (camera->instance_xyvel == 0)) &&
      ((secondcheck_flag == (_Rotation *)0x0 &&
       (((camera->always_rotate_flag == 0 && (camera->forced_movement == 0)) && (0 < local_30))))))
     && (((local_30 == 4 || (camera_still != 0)) && (local_2c < 400)))) {
    panic_count = panic_count + 1;
    if ((theCamera.core.vvPlaneConsts[4] & 1U) == 0) {
      if (panic_count < 2) goto LAB_8001d3f4;
    }
    else {
      if (panic_count < 0xb) goto LAB_8001d3f4;
    }
    colInfo = (CameraCollisionInfo *)(int)(short)local_2c;
    camera_00 = camera;
    CAMERA_Panic(camera,(short)local_2c);
  }
  else {
    panic_count = 0;
  }
LAB_8001d3f4:
  if (((camera->data).Follow.tface != (_TFace *)0x0) &&
     (camera_00 = camera, secondcheck_flag != (_Rotation *)0x0)) {
    colInfo = (CameraCollisionInfo *)&stack0xffffff88;
    rotation = (_Rotation *)0x0;
    uVar1 = (camera->targetFocusPoint).y;
    in_a3 = (short *)(uint)uVar1;
    sVar2 = (camera->targetFocusPoint).z;
    (camera->focusSphere).position.x = (camera->targetFocusPoint).x;
    (camera->focusSphere).position.y = uVar1;
    (camera->focusSphere).position.z = sVar2;
    p_Var4 = CAMERA_SphereToSphereWithLines(camera,colInfo,0);
    (camera->data).Follow.tface = p_Var4;
  }
  if (simpleflag != 0) {
    if ((camera->data).Follow.tface == (_TFace *)0x0) {
      iVar3 = CAMERA_FocusInstanceMoved(camera_00);
      return iVar3;
    }
    sVar2 = camera->mode;
    if (((sVar2 != 4) && (sVar2 != 2)) && (sVar2 != 6)) {
      iVar3 = CAMERA_FocusInstanceMoved(camera_00);
      return iVar3;
    }
    uVar5 = (uint)auStack68[local_34];
    camera->collisionTargetFocusDistance = auStack68[local_34];
    CAMERA_DoPanicCheck(camera_00,colInfo,rotation,in_a3,in_stack_ffffff88);
    return uVar5;
  }
  if (0 < DAT_800cdf9c) {
    DAT_800cdf9c = DAT_800cdf9c + -1;
  }
  if (camera->always_rotate_flag != 0) {
    local_30 = 4;
  }
  if ((camera->flags & 0x10000U) == 0) {
    if ((((camera->instance_mode & 0x24000000) == 0) &&
        (((camera->flags & 0x2000U) == 0 || ((camera->instance_mode & 0x2000000) != 0)))) &&
       (camera->always_rotate_flag == 0)) {
      if ((camera->data).Follow.tface == (_TFace *)0x0) {
        CAMERA_dampgetline(0);
        if ((camera->mode == 0xd) && (0 < camera->instance_xyvel)) {
                    /* WARNING: Subroutine does not return */
          CAMERA_AngleDifference((camera->collisionTargetFocusRotation).z,(camera->focusRotation).z)
          ;
        }
        if (DAT_800cdf9c == 0) {
          CAMERA_Unlock((Camera *)&(camera->collisionTargetFocusRotation).z,
                        (int)(camera->targetFocusRotation).z);
          camera->collision_lastPush = 0;
        }
        if ((camera->instance_mode & 0x2000000) == 0) {
          camera->collisionTargetFocusDistance = camera->targetFocusDistance;
        }
        else {
          DAT_800cdf9c = 0;
          camera->collisionTargetFocusDistance = (short)Spiral_Current;
        }
      }
      else {
        lVar8 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)&stack0xffffff88);
        DAT_800cdf9c = 0x1e;
        (camera->targetFocusRotation).z = (camera->collisionTargetFocusRotation).z;
      }
      return lVar8;
    }
  }
  if ((camera->data).Follow.tface == (_TFace *)0x0) {
    camera->collisionTargetFocusDistance = camera->targetFocusDistance;
  }
  else {
    CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)&stack0xffffff88);
    DAT_800cdf9c = 0x1e;
  }
  camera_00 = (Camera *)&(camera->collisionTargetFocusRotation).z;
  if ((camera->flags & 0x10000U) != 0) {
                    /* WARNING: Subroutine does not return */
    AngleDiff((camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z);
  }
  CAMERA_Unlock(camera_00,(int)(camera->targetFocusRotation).z);
  iVar3 = CAMERA_FocusInstanceMoved(camera_00);
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_FocusInstanceMoved(struct Camera *camera /*$a0*/)
 // line 5876, offset 0x8001d7d0
	/* begin block 1 */
		// Start line: 13451
	/* end block 1 */
	// End Line: 13452

	/* begin block 2 */
		// Start line: 13452
	/* end block 2 */
	// End Line: 13453

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





