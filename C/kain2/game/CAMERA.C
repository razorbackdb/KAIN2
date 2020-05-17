#include "THISDUST.H"
#include "CAMERA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalculateViewVolumeNormals(struct Camera *camera /*$s0*/)
 // line 230, offset 0x80014aa4
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x80014AA4
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
	// End offset: 0x80014AA4
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
  short sVar5;
  
  sVar3 = ((short)(camera->core).leftX + -0xa0) * 0x10;
  sVar2 = ((short)(camera->core).topY + -0x78) * 0x10;
  sVar5 = ((short)(camera->core).rightX + -0xa0) * 0x10;
  sVar4 = ((short)(camera->core).bottomY + -0x78) * 0x10;
  sVar1 = (short)((int)((uint)*(ushort *)&(camera->core).projDistance << 0x10) >> 0xc);
  (camera->core).viewVolumeNormal[0].x = 0;
  (camera->core).viewVolumeNormal[0].y = 0;
  (camera->core).viewVolumeNormal[0].z = 0x1000;
  (camera->core).viewVolumeNormal[1].x =
       (short)((int)sVar2 * (int)sVar1 - (int)sVar1 * (int)sVar2 >> 0xc);
  (camera->core).viewVolumeNormal[1].y =
       -(short)((int)sVar3 * (int)sVar1 - (int)sVar1 * (int)sVar5 >> 0xc);
  (camera->core).viewVolumeNormal[1].z =
       (short)((int)sVar3 * (int)sVar2 - (int)sVar2 * (int)sVar5 >> 0xc);
  CAMERA_Normalize((_SVector *)((camera->core).viewVolumeNormal + 1));
  (camera->core).viewVolumeNormal[2].x =
       (short)((int)sVar4 * (int)sVar1 - (int)sVar1 * (int)sVar2 >> 0xc);
  (camera->core).viewVolumeNormal[2].y =
       -(short)((int)sVar3 * (int)sVar1 - (int)sVar1 * (int)sVar3 >> 0xc);
  (camera->core).viewVolumeNormal[2].z =
       (short)((int)sVar3 * (int)sVar2 - (int)sVar4 * (int)sVar3 >> 0xc);
  CAMERA_Normalize((_SVector *)((camera->core).viewVolumeNormal + 2));
  (camera->core).viewVolumeNormal[3].x =
       (short)((int)sVar2 * (int)sVar1 - (int)sVar1 * (int)sVar4 >> 0xc);
  (camera->core).viewVolumeNormal[3].y =
       -(short)((int)sVar5 * (int)sVar1 - (int)sVar1 * (int)sVar5 >> 0xc);
  (camera->core).viewVolumeNormal[3].z =
       (short)((int)sVar5 * (int)sVar4 - (int)sVar2 * (int)sVar5 >> 0xc);
  CAMERA_Normalize((_SVector *)((camera->core).viewVolumeNormal + 3));
  (camera->core).viewVolumeNormal[4].x =
       (short)((int)sVar4 * (int)sVar1 - (int)sVar1 * (int)sVar4 >> 0xc);
  (camera->core).viewVolumeNormal[4].y =
       -(short)((int)sVar5 * (int)sVar1 - (int)sVar1 * (int)sVar3 >> 0xc);
  (camera->core).viewVolumeNormal[4].z =
       (short)((int)sVar5 * (int)sVar4 - (int)sVar4 * (int)sVar3 >> 0xc);
  CAMERA_Normalize((_SVector *)((camera->core).viewVolumeNormal + 4));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcVVClipInfo(struct Camera *camera /*$s0*/)
 // line 263, offset 0x80014de0
	/* begin block 1 */
		// Start line: 553
	/* end block 1 */
	// End Line: 554

void CAMERA_CalcVVClipInfo(Camera *camera)

{
  long lVar1;
  undefined4 in_zero;
  undefined4 in_at;
  MATRIX *pMVar2;
  MATRIX *pMVar3;
  
  pMVar3 = (camera->core).vvNormalWorVecMat;
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal,pMVar3);
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal + 1,
                (camera->core).vvNormalWorVecMat[0].m + 3);
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal + 2,
                (camera->core).vvNormalWorVecMat[0].m + 6);
  pMVar2 = (camera->core).vvNormalWorVecMat + 1;
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal + 3,pMVar2);
  ApplyMatrixSV((camera->core).cwTransform2,(camera->core).viewVolumeNormal + 4,
                (camera->core).vvNormalWorVecMat[1].m + 3);
  setCopControlWord(2,0,*(undefined4 *)pMVar3->m);
  setCopControlWord(2,0x800,*(undefined4 *)((camera->core).vvNormalWorVecMat[0].m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)((camera->core).vvNormalWorVecMat[0].m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)((camera->core).vvNormalWorVecMat[0].m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)((camera->core).vvNormalWorVecMat[0].m + 8));
  setCopReg(2,in_zero,*(undefined4 *)&(camera->core).position);
  setCopReg(2,in_at,*(undefined4 *)&(camera->core).position.z);
  copFunction(2,0x486012);
  lVar1 = getCopReg(2,0x19);
  (camera->core).vvPlaneConsts[0] = lVar1;
  lVar1 = getCopReg(2,0x1a);
  (camera->core).vvPlaneConsts[1] = lVar1;
  lVar1 = getCopReg(2,0x1b);
  (camera->core).vvPlaneConsts[2] = lVar1;
  setCopControlWord(2,0,*(undefined4 *)pMVar2->m);
  setCopControlWord(2,0x800,*(undefined4 *)((camera->core).vvNormalWorVecMat[1].m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)((camera->core).vvNormalWorVecMat[1].m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)((camera->core).vvNormalWorVecMat[1].m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)((camera->core).vvNormalWorVecMat[1].m + 8));
  setCopReg(2,in_zero,*(undefined4 *)&(camera->core).position);
  setCopReg(2,in_at,*(undefined4 *)&(camera->core).position.z);
  copFunction(2,0x486012);
  lVar1 = getCopReg(2,0x19);
  (camera->core).vvPlaneConsts[3] = lVar1;
  lVar1 = getCopReg(2,0x1a);
  (camera->core).vvPlaneConsts[4] = lVar1;
  lVar1 = getCopReg(2,0x1b);
  (camera->core).vvPlaneConsts[5] = lVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetViewVolume(struct Camera *camera /*$s0*/)
 // line 274, offset 0x80014f00
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
 // line 280, offset 0x80014f2c
	/* begin block 1 */
		// Start line: 281
		// Start offset: 0x80014F2C
		// Variables:
	// 		struct Level *level; // $s0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x80014FB0
	// End Line: 300

	/* begin block 2 */
		// Start line: 589
	/* end block 2 */
	// End Line: 590

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
 // line 302, offset 0x80014fd0
	/* begin block 1 */
		// Start line: 303
		// Start offset: 0x80014FD0
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 303
			// Start offset: 0x80014FD0
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v0
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x80014FD0
		// End Line: 303

		/* begin block 1.2 */
			// Start line: 303
			// Start offset: 0x80014FD0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		struct _Position *_v; // $a2
		/* end block 1.2 */
		// End offset: 0x80014FD0
		// End Line: 303
	/* end block 1 */
	// End offset: 0x80014FD0
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
 // line 315, offset 0x80015074
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x80015074
		// Variables:
	// 		long i; // $t4
	/* end block 1 */
	// End offset: 0x800153A4
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
 // line 359, offset 0x800153ac
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x800153AC

		/* begin block 1.1 */
			// Start line: 372
			// Start offset: 0x800153D0
			// Variables:
		// 		long mode; // $s1
		/* end block 1.1 */
		// End offset: 0x80015840
		// End Line: 485
	/* end block 1 */
	// End offset: 0x80015840
	// End Line: 486

	/* begin block 2 */
		// Start line: 770
	/* end block 2 */
	// End Line: 771

void CAMERA_RestoreMode(Camera *camera)

{
  short sVar1;
  _Position *p_Var2;
  MultiSpline *pMVar3;
  ulong uVar4;
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
      Inst = gameTrackerX.playerInstance;
      if (camera->mode == 5) {
        (camera->focusOffset).x = 0;
        (camera->focusOffset).y = 0;
        (camera->focusOffset).z = 0x160;
        camera->focusInstance = Inst;
        CAMERA_Restore(camera,7);
      }
      if (iVar7 == 0xc) {
        gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffffbf;
      }
      else {
        gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x40;
      }
      cameraMode = iVar7;
      camera->mode = sVar6;
      sVar6 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)&camera_modeToIndex + ((iVar7 << 0x10) >> 0xe)) * 3 +
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
      uVar5 = *(undefined4 *)&p_Var2[0x79].y;
      *(undefined4 *)&camera->targetFocusRotation = *(undefined4 *)&p_Var2[0x78].z;
      *(undefined4 *)&(camera->targetFocusRotation).z = uVar5;
      if ((camera->smooth == 0) && (camera->mode != 6)) {
        camera->focusDistance = camera->savedCinematic[(int)camera->stack].focusDistance;
        p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
        uVar5 = *(undefined4 *)(p_Var2 + 0x78);
        *(undefined4 *)&camera->focusRotation = *(undefined4 *)&p_Var2[0x77].y;
        *(undefined4 *)&(camera->focusRotation).z = uVar5;
      }
      else {
        camera->always_rotate_flag = 1;
      }
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&p_Var2[0x7b].y;
      *(undefined4 *)&camera->focusPointVel = *(undefined4 *)&p_Var2[0x7a].z;
      *(undefined4 *)&(camera->focusPointVel).z = uVar5;
      p_Var2 = (_Position *)((int)&(camera->core).position + (int)camera->stack * 0x70);
      uVar5 = *(undefined4 *)&p_Var2[0x7c].z;
      *(undefined4 *)&camera->focusPointAccl = *(undefined4 *)(p_Var2 + 0x7c);
      *(undefined4 *)&(camera->focusPointAccl).z = uVar5;
      iVar7 = (int)camera->stack;
      Inst = camera->focusInstance;
      camera->maxVel = *(short *)&camera->savedCinematic[iVar7].maxVel;
      (camera->data).Cinematic.posSpline = camera->savedCinematic[iVar7].posSpline;
      pMVar3 = camera->savedCinematic[iVar7].targetSpline;
      camera->mode = sVar6;
      (camera->data).Cinematic.targetSpline = pMVar3;
      uVar4 = INSTANCE_Query(Inst,9);
      if ((uVar4 & 0x50) != 0) {
        CAMERA_ChangeToUnderWater(camera,camera->focusInstance);
      }
      break;
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
 // line 489, offset 0x80015854
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x80015854

		/* begin block 1.1 */
			// Start line: 493
			// Start offset: 0x80015864
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x800158CC
		// End Line: 505
	/* end block 1 */
	// End offset: 0x80015914
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
 // line 524, offset 0x80015924
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
 // line 564, offset 0x800159e0
	/* begin block 1 */
		// Start line: 565
		// Start offset: 0x800159E0
		// Variables:
	// 		static struct _SVector point; // offset 0x0
	/* end block 1 */
	// End offset: 0x80015A28
	// End Line: 576

	/* begin block 2 */
		// Start line: 1219
	/* end block 2 */
	// End Line: 1220

_SVector * SplineGetNextPointDC(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetNext(spline,def,gameTrackerX.timeMult);
  if ((uVar1 != 0) && (uVar1 = SplineGetData(spline,def,&point_42), uVar1 != 0)) {
    return (_SVector *)&point_42;
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMode(struct Camera *camera /*$s2*/, long mode /*$s3*/)
 // line 578, offset 0x80015a3c
	/* begin block 1 */
		// Start line: 579
		// Start offset: 0x80015A3C
		// Variables:
	// 		int oldMode; // $s0
	// 		struct SplineDef curPositional; // stack offset -56
	// 		struct _SVector sv; // stack offset -48

		/* begin block 1.1 */
			// Start line: 625
			// Start offset: 0x80015B10
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		// 		struct _Rotation *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80015B10
		// End Line: 625

		/* begin block 1.2 */
			// Start line: 625
			// Start offset: 0x80015B10
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80015B10
		// End Line: 625

		/* begin block 1.3 */
			// Start line: 625
			// Start offset: 0x80015B10
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
		// End offset: 0x80015B10
		// End Line: 625

		/* begin block 1.4 */
			// Start line: 685
			// Start offset: 0x80015C6C
			// Variables:
		// 		struct _SVector *camPos; // stack offset -32
		// 		struct _SVector *targetPos; // $a0

			/* begin block 1.4.1 */
				// Start line: 690
				// Start offset: 0x80015C80
				// Variables:
			// 		struct _Position pos; // stack offset -40
			/* end block 1.4.1 */
			// End offset: 0x80015C80
			// End Line: 692

			/* begin block 1.4.2 */
				// Start line: 706
				// Start offset: 0x80015D2C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.2 */
			// End offset: 0x80015D2C
			// End Line: 706

			/* begin block 1.4.3 */
				// Start line: 716
				// Start offset: 0x80015D80
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.3 */
			// End offset: 0x80015D9C
			// End Line: 716
		/* end block 1.4 */
		// End offset: 0x80015D9C
		// End Line: 720
	/* end block 1 */
	// End offset: 0x80015ED0
	// End Line: 772

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
      if (pMVar5 != (MultiSpline *)0x0) {
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
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffffbf;
      cameraMode = mode;
      camera->mode = (short)mode;
      sVar3 = *(short *)(camera->focusDistanceList +
                        *(int *)((int)&camera_modeToIndex + ((mode << 0x10) >> 0xe)) * 3 +
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
 // line 774, offset 0x80015eec
	/* begin block 1 */
		// Start line: 775
		// Start offset: 0x80015EEC
		// Variables:
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x80016174
	// End Line: 993

	/* begin block 2 */
		// Start line: 1694
	/* end block 2 */
	// End Line: 1695

void CAMERA_Initialize(Camera *camera)

{
  _CameraCore_Type *p_Var1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  memset(camera,0,0x4c4);
  iVar4 = 0;
  do {
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    (&camera_shakeOffset)[iVar4].x = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    (&camera_shakeOffset)[iVar4].y = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    (&camera_shakeOffset)[iVar4].z = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  (camera->core).rotation.x = 0xfc7;
  (camera->targetRotation).x = 0xfc7;
  (camera->focusRotation).x = 0xfc7;
  (camera->targetFocusRotation).x = 0xfc7;
  camera->focusDistanceList[0] = 0x5dc;
  camera->focusDistanceList[3] = 0x5dc;
  camera->focusDistanceList[1] = 0x8ca;
  camera->focusDistanceList[4] = 2000;
  camera->focusDistanceList[8] = 2000;
  iVar2._1_2_ = *(short *)(camera->focusDistanceList + 1);
  camera->focusDistanceList[2] = 0xc80;
  camera->focusDistanceList[5] = 0xa28;
  camera->focusDistanceList[6] = 0x4b0;
  camera->focusDistanceList[7] = 0x640;
  camera->tiltList[0] = 0xfc7;
  camera->tiltList[1] = 0xfc7;
  camera->tiltList[2] = 0xfc7;
  camera->tiltList[3] = 0xfc7;
  camera->tiltList[4] = 0xfc7;
  camera->tiltList[5] = 0xfc7;
  camera->tiltList[6] = 0xfc7;
  camera->tiltList[7] = 0xfc7;
  camera->tiltList[8] = 0xfc7;
  (camera->smallBaseSphere).radiusSquared = 0x13240;
  (camera->focusSphere).radiusSquared = 0x13240;
  (camera->posSphere).radiusSquared = 0x13240;
  (camera->smallBaseSphere).radius = 0x118;
  (camera->focusSphere).radius = 0x118;
  (camera->posSphere).radius = 0x118;
  (camera->core).nearPlane = 0x32;
  (camera->core).projDistance = 0x140;
  camera->targetFocusDistance = iVar2._1_2_;
  camera->focusDistance = iVar2._1_2_;
  (camera->core).farPlane = 12000;
  (camera->core).bottomY = 0xf0;
  (camera->core).wcTransform = &wcTransformX;
  (camera->core).wcTransform2 = &wcTransform2X;
  (camera->core).cwTransform2 = &cwTransform2X;
  camera->smooth = 0x10;
  (camera->core).leftX = 0;
  (camera->core).rightX = 0x140;
  (camera->core).topY = 0;
  camera->maxVel = 200;
  camera->always_rotate_flag = 0;
  camera->follow_flag = 0;
  iVar2._1_2_ = (camera->focusPoint).z;
  *(undefined4 *)&camera->real_focuspoint = *(undefined4 *)&camera->focusPoint;
  (camera->real_focuspoint).z = iVar2._1_2_;
  iVar2._1_2_ = (camera->focusPoint).z;
  camera->minFocusDistance = 0x200;
  camera->Spline01 = (MultiSpline *)0x0;
  camera->Spline00 = (MultiSpline *)0x0;
  shorten_count = 0;
  shorten_flag = 0;
  camera->maxFocusDistance = 0x1000;
  camera->focuspoint_fallz = iVar2._1_2_;
  camera->flags = camera->flags | 0x800;
  if (camera->focusInstance != (_Instance *)0x0) {
    CAMERA_EndLook(camera);
  }
  iVar4 = 2;
  camera->presetIndex = 1;
  camera->mode = 0;
  CAMERA_SetMode(camera,0xd);
  p_Var1 = &camera->core;
  camera->maxXYDist = 3000;
  uVar3 = camera->flags;
  camera->minXYDist = 0;
  camera->rotDirection = 1;
  (camera->core).screenScale.z = 0x1000;
  (camera->core).screenScale.y = 0x1000;
  (camera->core).screenScale.x = 0x1000;
  camera->stack = -1;
  camera->targetStack = -1;
  camera->flags = uVar3 | 0x8000;
  do {
    p_Var1->vvNormalWorVecMat[0x13].t[2] = 0;
    iVar4 = iVar4 + -1;
    p_Var1 = (_CameraCore_Type *)p_Var1->vvNormalWorVecMat[-1].t;
  } while (-1 < iVar4);
  (camera->core).projDistance = 0x140;
  CAMERA_SetProjDistance(camera,0x140);
  (camera->data).Cinematic.cinema_done = 0;
  roll_target = 0;
  current_roll_amount = 0;
  roll_inc = 0;
  combat_cam_distance = 3000;
  combat_cam_angle = 0;
  combat_cam_weight = 0x1000;
  combat_cam_debounce = 0;
  CenterFlag = -1;
  Camera_lookHeight = 0x200;
  Camera_lookDist = 0x28a;
  CameraCenterDelay = 10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetInstanceFocus(struct Camera *camera /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1018, offset 0x800161ec
	/* begin block 1 */
		// Start line: 2485
	/* end block 1 */
	// End Line: 2486

	/* begin block 2 */
		// Start line: 2489
	/* end block 2 */
	// End Line: 2490

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
 // line 1052, offset 0x8001624c
	/* begin block 1 */
		// Start line: 2554
	/* end block 1 */
	// End Line: 2555

	/* begin block 2 */
		// Start line: 2555
	/* end block 2 */
	// End Line: 2556

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
 // line 1107, offset 0x80016270
	/* begin block 1 */
		// Start line: 2664
	/* end block 1 */
	// End Line: 2665

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
 // line 1116, offset 0x800162c4
	/* begin block 1 */
		// Start line: 1118
		// Start offset: 0x800162C4
		// Variables:
	// 		long min; // $t1
	// 		long max; // $t0
	// 		long minTilt; // $a3
	// 		long maxTilt; // $a1
	/* end block 1 */
	// End offset: 0x800166E8
	// End Line: 1170

	/* begin block 2 */
		// Start line: 2682
	/* end block 2 */
	// End Line: 2683

	/* begin block 3 */
		// Start line: 2683
	/* end block 3 */
	// End Line: 2684

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
LAB_8001668c:
      if (bVar2) {
        iVar5 = iVar4;
      }
      goto LAB_80016698;
    }
    iVar5 = camera->tiltList[5];
    bVar2 = iVar5 < iVar7;
  }
  else {
    if (sVar1 < 0xd) {
      if (sVar1 != 0) goto LAB_80016698;
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
        goto LAB_8001668c;
      }
      iVar5 = camera->tiltList[2];
      bVar2 = iVar5 < iVar7;
    }
    else {
      if (sVar1 != 0xd) goto LAB_80016698;
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
        goto LAB_8001668c;
      }
      iVar5 = camera->tiltList[8];
      bVar2 = iVar5 < iVar7;
    }
  }
  if (bVar2) {
    iVar5 = iVar7;
  }
LAB_80016698:
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
 // line 1173, offset 0x800166f0
	/* begin block 1 */
		// Start line: 2800
	/* end block 1 */
	// End Line: 2801

	/* begin block 2 */
		// Start line: 2801
	/* end block 2 */
	// End Line: 2802

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
 // line 1190, offset 0x80016768
	/* begin block 1 */
		// Start line: 2834
	/* end block 1 */
	// End Line: 2835

short CAMERA_SignedAngleDifference(short angle0,short angle1)

{
  short sVar1;
  
  sVar1 = AngleDiff(angle1,angle0);
  return sVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ CAMERA_QueryMode(struct Camera *camera /*$s0*/)
 // line 1209, offset 0x80016798
	/* begin block 1 */
		// Start line: 1210
		// Start offset: 0x80016798
		// Variables:
	// 		unsigned long mode; // $s0
	/* end block 1 */
	// End offset: 0x80016820
	// End Line: 1228

	/* begin block 2 */
		// Start line: 2873
	/* end block 2 */
	// End Line: 2874

ulong CAMERA_QueryMode(Camera *camera)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = INSTANCE_Query(camera->focusInstance,10);
  if (camera->focusInstance == gameTrackerX.playerInstance) {
    if ((uVar1 & 0x2000000) == 0) {
      if (0 < combat_cam_debounce) {
        uVar1 = uVar1 | 0x2000000;
        combat_cam_debounce = combat_cam_debounce + -1;
      }
    }
    else {
      combat_cam_debounce = 1;
    }
  }
  else {
    uVar1 = uVar1 & 0xfdffffff;
  }
  iVar2 = WARPGATE_IsWarpgateActive();
  if (iVar2 != 0) {
    uVar1 = uVar1 | 0x80000000;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetMaxVel(struct Camera *camera /*$s1*/)
 // line 1233, offset 0x80016834
	/* begin block 1 */
		// Start line: 1234
		// Start offset: 0x80016834
		// Variables:
	// 		long extraVel; // $s0
	// 		long targetMaxVel; // $v0
	// 		struct _SVector cam_dist; // stack offset -24
	// 		static long maxVelAccl; // offset 0x8
	// 		static long maxVelVel; // offset 0xc

		/* begin block 1.1 */
			// Start line: 1234
			// Start offset: 0x80016834
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
		// End offset: 0x80016834
		// End Line: 1234
	/* end block 1 */
	// End offset: 0x8001692C
	// End Line: 1266

	/* begin block 2 */
		// Start line: 2921
	/* end block 2 */
	// End Line: 2922

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
 // line 1268, offset 0x80016940
	/* begin block 1 */
		// Start line: 1269
		// Start offset: 0x80016940
		// Variables:
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1269
			// Start offset: 0x80016940
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80016940
		// End Line: 1269
	/* end block 1 */
	// End offset: 0x80016940
	// End Line: 1269

	/* begin block 2 */
		// Start line: 3009
	/* end block 2 */
	// End Line: 3010

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
 // line 1279, offset 0x800169bc
	/* begin block 1 */
		// Start line: 1280
		// Start offset: 0x800169BC
		// Variables:
	// 		struct SVECTOR sv; // stack offset -96
	// 		struct VECTOR v; // stack offset -88
	// 		struct MATRIX matrix; // stack offset -72
	// 		struct _Vector vectorPos; // stack offset -40

		/* begin block 1.1 */
			// Start line: 1280
			// Start offset: 0x800169BC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x800169BC
		// End Line: 1280
	/* end block 1 */
	// End offset: 0x800169BC
	// End Line: 1280

	/* begin block 2 */
		// Start line: 3034
	/* end block 2 */
	// End Line: 3035

void CAMERA_CalcPosition(_Position *position,_Position *base,_Rotation *rotation,short distance)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  int local_60;
  uint local_5c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  short local_28;
  short local_24;
  short local_20;
  
  local_60 = (uint)(ushort)-distance << 0x10;
  local_5c = local_5c & 0xffff0000;
  MATH3D_SetUnityMatrix((MATRIX *)&local_48);
  RotMatrixX((int)rotation->x,(int)(MATRIX *)&local_48);
  RotMatrixY((int)rotation->y,(uint *)(MATRIX *)&local_48);
  RotMatrixZ((int)rotation->z,(uint *)(MATRIX *)&local_48);
  setCopControlWord(2,0,local_48);
  setCopControlWord(2,0x800,local_44);
  setCopControlWord(2,0x1000,local_40);
  setCopControlWord(2,0x1800,local_3c);
  setCopControlWord(2,0x2000,local_38);
  setCopReg(2,in_zero,local_60);
  setCopReg(2,in_at,local_5c);
  copFunction(2,0x486012);
  uVar1 = getCopReg(2,0x19);
  uVar2 = getCopReg(2,0x1a);
  uVar3 = getCopReg(2,0x1b);
  local_28 = (short)uVar1 + base->x;
  local_24 = (short)uVar2 + base->y;
  local_20 = (short)uVar3 + base->z;
  position->x = local_28;
  position->y = local_24;
  position->z = local_20;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetFocus(struct Camera *camera /*$s3*/, struct _Position *targetfocusPoint /*$s1*/)
 // line 1320, offset 0x80016ae4
	/* begin block 1 */
		// Start line: 1321
		// Start offset: 0x80016AE4
		// Variables:
	// 		struct _Instance *focusInstance; // $s0
	// 		struct _Model *model; // $v0
	// 		struct _SVector temp1; // stack offset -64
	// 		struct _SVector offset; // stack offset -56
	// 		struct _SVector *segPosVector; // $v1
	// 		struct _Vector temp2; // stack offset -48

		/* begin block 1.1 */
			// Start line: 1336
			// Start offset: 0x80016B30
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $s2
		/* end block 1.1 */
		// End offset: 0x80016B30
		// End Line: 1336

		/* begin block 1.2 */
			// Start line: 1336
			// Start offset: 0x80016B30
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $t1
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x80016B30
		// End Line: 1336

		/* begin block 1.3 */
			// Start line: 1346
			// Start offset: 0x80016BB4

			/* begin block 1.3.1 */
				// Start line: 1348
				// Start offset: 0x80016BB4
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a2
			// 		short _x1; // $a3
			// 		short _y1; // $t0
			// 		short _z1; // $v1
			/* end block 1.3.1 */
			// End offset: 0x80016BB4
			// End Line: 1348
		/* end block 1.3 */
		// End offset: 0x80016C04
		// End Line: 1356

		/* begin block 1.4 */
			// Start line: 1368
			// Start offset: 0x80016C48
			// Variables:
		// 		struct _Instance *instance; // $v0
		// 		struct _SVector output; // stack offset -32

			/* begin block 1.4.1 */
				// Start line: 1374
				// Start offset: 0x80016C58
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.4.1 */
			// End offset: 0x80016C58
			// End Line: 1374

			/* begin block 1.4.2 */
				// Start line: 1381
				// Start offset: 0x80016C90
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v1; // $v0
			/* end block 1.4.2 */
			// End offset: 0x80016C90
			// End Line: 1381
		/* end block 1.4 */
		// End offset: 0x80016C90
		// End Line: 1381

		/* begin block 1.5 */
			// Start line: 1386
			// Start offset: 0x80016C90
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x80016CAC
		// End Line: 1386

		/* begin block 1.6 */
			// Start line: 1389
			// Start offset: 0x80016CAC
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x80016CAC
		// End Line: 1389
	/* end block 1 */
	// End offset: 0x80016D40
	// End Line: 1426

	/* begin block 2 */
		// Start line: 3129
	/* end block 2 */
	// End Line: 3130

void CAMERA_SetFocus(Camera *camera,_Position *targetfocusPoint)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _Segment *p_Var4;
  ulong uVar5;
  _Instance *Inst;
  short local_40;
  short local_3e;
  short local_3c;
  _SVector local_38;
  undefined auStack48 [16];
  short local_20;
  short local_1e;
  short local_1c;
  
  Inst = camera->focusInstance;
  if (((camera->flags & 0x10000U) != 0) || ((camera->instance_mode & 0x4000000) != 0)) {
    p_Var4 = Inst->object->modelList[Inst->currentModel]->segmentList;
    local_40 = p_Var4[1].px;
    local_3e = p_Var4[1].py;
    local_3c = p_Var4[1].pz;
    ApplyMatrix(Inst->matrix + 1,&local_40,auStack48);
    sVar1 = (Inst->position).x;
    sVar2 = (Inst->position).y;
    sVar3 = (Inst->position).z;
    targetfocusPoint->x = sVar1;
    targetfocusPoint->y = sVar2;
    targetfocusPoint->z = sVar3;
    if ((camera->flags & 0x10000U) != 0) {
      targetfocusPoint->x = sVar1 + local_40;
      targetfocusPoint->y = targetfocusPoint->y + local_3e;
      targetfocusPoint->z = sVar3 + local_3c;
      uVar5 = INSTANCE_Query(Inst,9);
      if ((uVar5 & 0x40) != 0) {
        targetfocusPoint->z = targetfocusPoint->z + 0xc0;
      }
    }
    sVar1 = targetfocusPoint->z;
    *(undefined4 *)&camera->real_focuspoint = *(undefined4 *)targetfocusPoint;
    (camera->real_focuspoint).z = sVar1;
    goto LAB_80016d34;
  }
  if (((camera->instance_mode & 0x2000000) == 0) || (1 < (uint)(ushort)camera->mode - 0xc)) {
LAB_80016c94:
    sVar1 = (Inst->position).y;
    sVar2 = (Inst->position).z;
    targetfocusPoint->x = (Inst->position).x;
    targetfocusPoint->y = sVar1;
    targetfocusPoint->z = sVar2;
  }
  else {
    uVar5 = INSTANCE_Query(Inst,0x22);
    if (uVar5 == 0) goto LAB_80016c94;
    LoadAverageShort12((uint *)(uVar5 + 0x5c),(uint *)&Inst->position,
                       0x1000 - (int)combat_cam_weight,(int)combat_cam_weight,(uint *)&local_20);
    targetfocusPoint->x = local_20;
    targetfocusPoint->y = local_1e;
    targetfocusPoint->z = local_1c;
  }
  CAMERA_CalcFocusOffset(&local_38,camera);
  targetfocusPoint->x = targetfocusPoint->x + local_38.x;
  targetfocusPoint->y = targetfocusPoint->y + local_38.y;
  targetfocusPoint->z = targetfocusPoint->z + local_38.z;
  sVar1 = targetfocusPoint->z;
  *(undefined4 *)&camera->real_focuspoint = *(undefined4 *)targetfocusPoint;
  (camera->real_focuspoint).z = sVar1;
  if ((camera->instance_mode & 0x2038) != 0) {
    if ((camera->instance_mode & 0x2000) == 0) {
      return;
    }
    if ((camera->focusInstanceVelVec).z < 0x47) {
      return;
    }
  }
LAB_80016d34:
  camera->focuspoint_fallz = targetfocusPoint->z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Lock(struct Camera *camera /*$a0*/, long lock /*$a1*/)
 // line 1428, offset 0x80016d60
	/* begin block 1 */
		// Start line: 3376
	/* end block 1 */
	// End Line: 3377

	/* begin block 2 */
		// Start line: 3377
	/* end block 2 */
	// End Line: 3378

void CAMERA_Lock(Camera *camera,long lock)

{
  camera->lock = camera->lock | lock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Unlock(struct Camera *camera /*$a0*/, long unlock /*$a1*/)
 // line 1433, offset 0x80016d74
	/* begin block 1 */
		// Start line: 3386
	/* end block 1 */
	// End Line: 3387

	/* begin block 2 */
		// Start line: 3387
	/* end block 2 */
	// End Line: 3388

void CAMERA_Unlock(Camera *camera,long unlock)

{
  camera->lock = camera->lock & ~unlock;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetSmoothValue(struct Camera *camera /*$a0*/, long smooth /*$a1*/)
 // line 1438, offset 0x80016d88
	/* begin block 1 */
		// Start line: 3396
	/* end block 1 */
	// End Line: 3397

	/* begin block 2 */
		// Start line: 3398
	/* end block 2 */
	// End Line: 3399

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
 // line 1451, offset 0x80016dd8
	/* begin block 1 */
		// Start line: 3422
	/* end block 1 */
	// End Line: 3423

void CAMERA_SetTimer(Camera *camera,long time)

{
  CAMERA_Save(camera,-1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_tilt(struct Camera *camera /*$a0*/, long tilt /*$a1*/)
 // line 1457, offset 0x80016df8
	/* begin block 1 */
		// Start line: 3434
	/* end block 1 */
	// End Line: 3435

	/* begin block 2 */
		// Start line: 3435
	/* end block 2 */
	// End Line: 3436

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
 // line 1475, offset 0x80016e34
	/* begin block 1 */
		// Start line: 3473
	/* end block 1 */
	// End Line: 3474

	/* begin block 2 */
		// Start line: 3474
	/* end block 2 */
	// End Line: 3475

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
 // line 1493, offset 0x80016eb0
	/* begin block 1 */
		// Start line: 3511
	/* end block 1 */
	// End Line: 3512

void CAMERA_Adjust_rotation(Camera *camera,long rotation)

{
  ulong uVar1;
  short sVar2;
  ushort uVar3;
  
  sVar2 = CAMERA_AngleDifference((ushort)rotation,(camera->targetFocusRotation).z);
  if (sVar2 != 0) {
    camera->rotState = 3;
    sVar2 = camera->smooth;
    uVar3 = (ushort)rotation & 0xfff;
    camera->forced_movement = 0;
    (camera->signalRot).z = uVar3;
    if (sVar2 == 0) {
      (camera->targetFocusRotation).z = uVar3;
      (camera->focusRotation).z = uVar3;
      camera->teleportZRot = uVar3;
      (camera->collisionTargetFocusRotation).z = uVar3;
    }
    uVar1 = gameTrackerX.frameCount;
    camera->always_rotate_flag = 1;
    camera->lastModTime = uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_roll(long roll_degrees /*$s0*/, int frames /*$s1*/)
 // line 1512, offset 0x80016f34
	/* begin block 1 */
		// Start line: 3557
	/* end block 1 */
	// End Line: 3558

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
 // line 1528, offset 0x80016fb8
	/* begin block 1 */
		// Start line: 1529
		// Start offset: 0x80016FB8

		/* begin block 1.1 */
			// Start line: 1533
			// Start offset: 0x80016FE0

			/* begin block 1.1.1 */
				// Start line: 1536
				// Start offset: 0x80016FEC
				// Variables:
			// 		struct _SVector dv; // stack offset -24

				/* begin block 1.1.1.1 */
					// Start line: 1537
					// Start offset: 0x80016FEC
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
				// End offset: 0x80016FEC
				// End Line: 1537
			/* end block 1.1.1 */
			// End offset: 0x80017030
			// End Line: 1552
		/* end block 1.1 */
		// End offset: 0x80017060
		// End Line: 1583
	/* end block 1 */
	// End offset: 0x80017060
	// End Line: 1588

	/* begin block 2 */
		// Start line: 3591
	/* end block 2 */
	// End Line: 3592

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
 // line 1591, offset 0x80017078
	/* begin block 1 */
		// Start line: 3717
	/* end block 1 */
	// End Line: 3718

	/* begin block 2 */
		// Start line: 3718
	/* end block 2 */
	// End Line: 3719

void CAMERA_ChangeTo(Camera *camera,_CameraKey *cameraKey)

{
  camera->cameraKey = cameraKey;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetShake(struct Camera *camera /*$t0*/, long shake /*$a1*/, long scale /*$a2*/)
 // line 1596, offset 0x80017080
	/* begin block 1 */
		// Start line: 1597
		// Start offset: 0x80017080
		// Variables:
	// 		int shock; // $a0
	// 		int duration; // $a1
	/* end block 1 */
	// End offset: 0x80017118
	// End Line: 1616

	/* begin block 2 */
		// Start line: 3727
	/* end block 2 */
	// End Line: 3728

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
 // line 1619, offset 0x80017130
	/* begin block 1 */
		// Start line: 3773
	/* end block 1 */
	// End Line: 3774

void Decouple_AngleMoveToward(short *current_ptr,short destination,short step)

{
  if (gameTrackerX.timeMult != 0x1000) {
    step = (short)((int)step * gameTrackerX.timeMult >> 0xc);
  }
  AngleMoveToward(current_ptr,destination,step);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampValue(long dampMode /*$a0*/, short *sourceVal /*$a1*/, short targetVal /*$t2*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1627, offset 0x80017180
	/* begin block 1 */
		// Start line: 1628
		// Start offset: 0x80017180
		// Variables:
	// 		short maxVel; // $t0
	// 		short useVel; // $a0
	/* end block 1 */
	// End offset: 0x8001732C
	// End Line: 1686

	/* begin block 2 */
		// Start line: 3789
	/* end block 2 */
	// End Line: 3790

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
LAB_80017228:
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
      if ((6 < dampMode) || (dampMode < 5)) goto LAB_80017310;
      goto LAB_80017228;
    }
    if (dampMode != 0) goto LAB_80017310;
    sVar3 = (short)((int)(((uint)(ushort)targetVal - (uint)(ushort)*sourceVal) * 0x10000) >> 0x12) -
            *vel;
    *accl = sVar3;
    sVar3 = *vel + sVar3;
    *vel = sVar3;
    sVar3 = *sourceVal + sVar3;
  }
  *sourceVal = sVar3;
LAB_80017310:
  if (*vel != 0) {
    return;
  }
  *sourceVal = targetVal;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampPosition(long dampMode /*$a0*/, struct _Position *position /*$s1*/, struct _Position *targetPos /*$s3*/, struct _SVector *vel /*$s2*/, struct _SVector *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1739, offset 0x80017334
	/* begin block 1 */
		// Start line: 1740
		// Start offset: 0x80017334
		// Variables:
	// 		long length; // $s0
	// 		struct _Vector vector; // stack offset -48
	// 		struct _SVector svector; // stack offset -32
	// 		short maxVel; // $s4
	// 		int shift; // $a3

		/* begin block 1.1 */
			// Start line: 1761
			// Start offset: 0x800173B0
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.1 */
		// End offset: 0x800173B0
		// End Line: 1761

		/* begin block 1.2 */
			// Start line: 1776
			// Start offset: 0x8001746C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $a2
		// 		long _z0; // $a1
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		/* end block 1.2 */
		// End offset: 0x8001746C
		// End Line: 1776

		/* begin block 1.3 */
			// Start line: 1810
			// Start offset: 0x80017610
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $s2
		/* end block 1.3 */
		// End offset: 0x80017610
		// End Line: 1810

		/* begin block 1.4 */
			// Start line: 1814
			// Start offset: 0x80017664
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.4 */
		// End offset: 0x80017664
		// End Line: 1814

		/* begin block 1.5 */
			// Start line: 1818
			// Start offset: 0x80017664
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.5 */
		// End offset: 0x80017664
		// End Line: 1818

		/* begin block 1.6 */
			// Start line: 1825
			// Start offset: 0x80017700
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $a1
		/* end block 1.6 */
		// End offset: 0x80017700
		// End Line: 1825

		/* begin block 1.7 */
			// Start line: 1839
			// Start offset: 0x80017890
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.7 */
		// End offset: 0x80017890
		// End Line: 1839

		/* begin block 1.8 */
			// Start line: 1870
			// Start offset: 0x800179C0
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.8 */
		// End offset: 0x800179D8
		// End Line: 1870
	/* end block 1 */
	// End offset: 0x800179D8
	// End Line: 1872

	/* begin block 2 */
		// Start line: 4015
	/* end block 2 */
	// End Line: 4016

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
LAB_800179c0:
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
    if (gameTrackerX.timeMult == 0x1000) break;
    position->x = position->x + (short)((int)vel->x * gameTrackerX.timeMult >> 0xc);
    position->y = position->y + (short)((int)vel->y * gameTrackerX.timeMult >> 0xc);
    sVar6 = position->z;
    sVar5 = (short)((int)vel->z * gameTrackerX.timeMult >> 0xc);
    goto code_r0x800179b4;
  default:
    goto switchD_800173a8_caseD_2;
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
    goto LAB_800179c0;
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
    if (lVar4 < lVar3) goto LAB_800179c0;
    iVar7 = (int)(short)smooth;
    if (iVar7 <= lVar3) {
      vel->x = (short)((vel->x * iVar7) / lVar3);
      vel->y = (short)((vel->y * iVar7) / lVar3);
      vel->z = (short)((vel->z * iVar7) / lVar3);
      if (gameTrackerX.timeMult != 0x1000) {
        position->x = position->x + (short)((int)vel->x * gameTrackerX.timeMult >> 0xc);
        position->y = position->y + (short)((int)vel->y * gameTrackerX.timeMult >> 0xc);
        sVar6 = position->z;
        sVar5 = (short)((int)vel->z * gameTrackerX.timeMult >> 0xc);
        goto code_r0x800179b4;
      }
    }
  }
  position->x = position->x + vel->x;
  position->y = position->y + vel->y;
  sVar6 = position->z;
  sVar5 = vel->z;
code_r0x800179b4:
  position->z = sVar6 + sVar5;
switchD_800173a8_caseD_2:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CriticalDampAngle(long dampMode /*$a0*/, short *currentVal /*$s0*/, short target /*$t1*/, short *vel /*$a3*/, short *accl /*stack 16*/, int smooth /*stack 20*/)
 // line 1874, offset 0x800179f8
	/* begin block 1 */
		// Start line: 1875
		// Start offset: 0x800179F8
		// Variables:
	// 		short current; // stack offset -16
	/* end block 1 */
	// End offset: 0x80017A54
	// End Line: 1890

	/* begin block 2 */
		// Start line: 4303
	/* end block 2 */
	// End Line: 4304

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
 // line 1895, offset 0x80017a98
	/* begin block 1 */
		// Start line: 1896
		// Start offset: 0x80017A98
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1896
			// Start offset: 0x80017A98
			// Variables:
		// 		short _x0; // $a2
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80017A98
		// End Line: 1896
	/* end block 1 */
	// End offset: 0x80017A98
	// End Line: 1896

	/* begin block 2 */
		// Start line: 4355
	/* end block 2 */
	// End Line: 4356

short CAMERA_CalcZRotation(_Position *target,_Position *position)

{
  short sVar1;
  int iVar2;
  short sVar3;
  _SVector local_10;
  
  sVar3 = position->x - target->x;
  sVar1 = position->y - target->y;
  local_10.z = 0;
  local_10.x = sVar3;
  local_10.y = sVar1;
  CAMERA_LengthSVector(&local_10);
  iVar2 = ratan2((int)sVar1,(int)sVar3);
  return (short)((short)iVar2 + 0x400U & 0xfff);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcRotation(struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a1*/, struct _Position *position /*$a2*/)
 // line 1912, offset 0x80017b10
	/* begin block 1 */
		// Start line: 1913
		// Start offset: 0x80017B10
		// Variables:
	// 		struct _SVector sv; // stack offset -24
	// 		struct _SVector onPlane; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1913
			// Start offset: 0x80017B10
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a0
		// 		short _y1; // $a2
		// 		short _z1; // $a1
		// 		struct _SVector *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80017B10
		// End Line: 1913
	/* end block 1 */
	// End offset: 0x80017B10
	// End Line: 1913

	/* begin block 2 */
		// Start line: 4394
	/* end block 2 */
	// End Line: 4395

void CAMERA_CalcRotation(_Rotation *rotation,_Position *target,_Position *position)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  _SVector local_10;
  
  sVar1 = position->z;
  sVar2 = target->z;
  sVar6 = position->x - target->x;
  sVar3 = position->y - target->y;
  local_10.z = 0;
  local_10.x = sVar6;
  local_10.y = sVar3;
  uVar4 = CAMERA_LengthSVector(&local_10);
  iVar5 = ratan2((int)(short)(sVar1 - sVar2),uVar4);
  rotation->x = -(short)iVar5;
  rotation->y = 0;
  iVar5 = ratan2((int)sVar3,(int)sVar6);
  rotation->z = (short)iVar5 + 0x400;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFSRotation(struct Camera *camera /*$a0*/, struct _Rotation *rotation /*$s0*/, struct _Position *target /*$a2*/, struct _Position *position /*$a3*/)
 // line 1929, offset 0x80017bac
	/* begin block 1 */
		// Start line: 1930
		// Start offset: 0x80017BAC
		// Variables:
	// 		struct _SVector sv; // stack offset -32
	// 		struct _SVector onPlane; // stack offset -24
	// 		struct _SVector sv2; // stack offset -16

		/* begin block 1.1 */
			// Start line: 1930
			// Start offset: 0x80017BAC
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $v0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // $v0
		/* end block 1.1 */
		// End offset: 0x80017BAC
		// End Line: 1930

		/* begin block 1.2 */
			// Start line: 1930
			// Start offset: 0x80017BAC
			// Variables:
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80017BAC
		// End Line: 1930
	/* end block 1 */
	// End offset: 0x80017BAC
	// End Line: 1930

	/* begin block 2 */
		// Start line: 4432
	/* end block 2 */
	// End Line: 4433

void CAMERA_CalcFSRotation(Camera *camera,_Rotation *rotation,_Position *target,_Position *position)

{
  uint uVar1;
  int iVar2;
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
  uVar1 = CAMERA_LengthSVector(&local_18);
  iVar2 = ratan2((int)local_c,uVar1);
  rotation->x = -(short)iVar2;
  rotation->y = 0;
  iVar2 = ratan2((int)local_e,(int)local_10);
  rotation->z = (short)iVar2 + 0x400;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Relocate(struct Camera *camera /*$a0*/, struct _SVector *offset /*$a1*/, int streamSignalFlag /*$a2*/)
 // line 1949, offset 0x80017c58
	/* begin block 1 */
		// Start line: 4476
	/* end block 1 */
	// End Line: 4477

	/* begin block 2 */
		// Start line: 4481
	/* end block 2 */
	// End Line: 4482

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
 // line 2018, offset 0x80017da4
	/* begin block 1 */
		// Start line: 2019
		// Start offset: 0x80017DA4
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
			// Start line: 2134
			// Start offset: 0x800180B0
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
		// End offset: 0x800180B0
		// End Line: 2134

		/* begin block 1.2 */
			// Start line: 2134
			// Start offset: 0x800180B0
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
		// End offset: 0x800180B0
		// End Line: 2134

		/* begin block 1.3 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.4 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.5 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.6 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.7 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.8 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.9 */
			// Start line: 2147
			// Start offset: 0x800181BC
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
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.10 */
			// Start line: 2147
			// Start offset: 0x800181BC
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t2
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $v0
		/* end block 1.10 */
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.11 */
			// Start line: 2147
			// Start offset: 0x800181BC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.11 */
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.12 */
			// Start line: 2147
			// Start offset: 0x800181BC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a2
		// 		struct _Position *_v1; // $v0
		/* end block 1.12 */
		// End offset: 0x800181BC
		// End Line: 2147

		/* begin block 1.13 */
			// Start line: 2233
			// Start offset: 0x80018504
			// Variables:
		// 		int flag; // $fp
		// 		short backface_flag; // stack offset -72
		// 		struct _PCollideInfo pCollideInfo; // stack offset -120

			/* begin block 1.13.1 */
				// Start line: 2258
				// Start offset: 0x80018564
				// Variables:
			// 		int n; // $s2

				/* begin block 1.13.1.1 */
					// Start line: 2263
					// Start offset: 0x80018570
					// Variables:
				// 		struct Level *thislevel; // $s1
				/* end block 1.13.1.1 */
				// End offset: 0x800185F8
				// End Line: 2280
			/* end block 1.13.1 */
			// End offset: 0x80018608
			// End Line: 2281

			/* begin block 1.13.2 */
				// Start line: 2306
				// Start offset: 0x80018648
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // stack offset -44
			/* end block 1.13.2 */
			// End offset: 0x80018648
			// End Line: 2306

			/* begin block 1.13.3 */
				// Start line: 2337
				// Start offset: 0x8001879C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.13.3 */
			// End offset: 0x8001879C
			// End Line: 2337
		/* end block 1.13 */
		// End offset: 0x8001881C
		// End Line: 2362
	/* end block 1 */
	// End offset: 0x800188B0
	// End Line: 2381

	/* begin block 2 */
		// Start line: 4614
	/* end block 2 */
	// End Line: 4615

_TFace * CAMERA_SphereToSphereWithLines
                   (Camera *camera,CameraCollisionInfo *colInfo,int secondcheck_flag)

{
  short sVar1;
  ushort uVar2;
  long lVar3;
  _StreamUnit *p_Var4;
  _TFace *p_Var5;
  short sVar6;
  _Sphere *p_Var7;
  _Position *target;
  _Position *position;
  ushort *puVar8;
  Level *address;
  int iVar9;
  CameraCollisionInfo *pCVar10;
  SVECTOR *pSVar11;
  SVECTOR *pSVar12;
  CameraCollisionInfo *pCVar13;
  uint Flags;
  undefined2 local_158;
  short local_156;
  short local_154;
  SVECTOR local_150;
  _Position local_148;
  _Position local_140;
  short local_138;
  short local_136;
  short local_134;
  short local_130;
  short local_12e;
  short local_12c;
  SVECTOR local_128;
  _Position local_120;
  _Position local_118;
  short local_110;
  short local_10e;
  short local_10c;
  short local_108;
  short local_106;
  short local_104;
  undefined2 local_100;
  short local_fe;
  undefined2 local_fc;
  short local_f8 [2];
  short local_f4;
  short local_f0;
  undefined2 local_e8;
  short local_e6;
  undefined2 local_e4;
  short local_e0 [2];
  short local_dc;
  short local_d8;
  int local_d0;
  int local_cc;
  int local_c8;
  _Rotation local_c0;
  MATRIX MStack184;
  int local_98;
  int local_94;
  int local_90;
  undefined auStack136 [8];
  short local_80;
  _PCollideInfo _Stack120;
  short local_48 [2];
  int local_44;
  _TFace *local_40;
  uint local_3c;
  int local_38;
  Level *local_34;
  uint local_30;
  undefined2 *local_2c;
  
  local_44 = 0;
  local_40 = (_TFace *)0x0;
  local_38 = 1;
  iVar9 = 0;
  local_34 = STREAM_GetLevelWithID(camera->focusInstance->currentStreamUnitID);
  if (local_34 == (Level *)0x0) {
    return local_40;
  }
  lVar3 = MEMPACK_MemoryValidFunc((char *)local_34);
  if (lVar3 == 0) {
    return local_40;
  }
  colInfo->line = -1;
  colInfo->flags = 0;
  colInfo->numCollided = 0;
  local_100 = 0;
  local_fc = 0;
  local_e8 = 0;
  local_e4 = 0;
  CAMERA_CalcFSRotation(camera,&local_c0,(_Position *)colInfo->end,(_Position *)colInfo->start);
  if ((camera->flags & 0x10000U) != 0) {
    p_Var7 = colInfo->start;
    (p_Var7->position).x =
         (p_Var7->position).x +
         (short)((int)(colInfo->end->position).x - (int)(p_Var7->position).x >> 5);
    p_Var7 = colInfo->start;
    (p_Var7->position).y =
         (p_Var7->position).y +
         (short)((int)(colInfo->end->position).y - (int)(p_Var7->position).y >> 5);
    p_Var7 = colInfo->start;
    (p_Var7->position).z =
         (p_Var7->position).z +
         (short)((int)(colInfo->end->position).z - (int)(p_Var7->position).z >> 5);
  }
  MATH3D_SetUnityMatrix(&MStack184);
  RotMatrixZ((int)local_c0.z + 0x400,(uint *)&MStack184);
  if ((((camera->flags & 0x10000U) == 0) && ((camera->instance_mode & 0x4000000) == 0)) &&
     (camera->mode != 6)) {
    local_fe = 0x1000;
    ApplyMatrix(&MStack184,&local_100,&local_98);
    ACE_amount = local_98 * (camera->focusInstanceVelVec).x +
                 local_94 * (camera->focusInstanceVelVec).y +
                 local_90 * (camera->focusInstanceVelVec).z >> 0xc;
    if ((camera->always_rotate_flag != 0) || (camera->forced_movement != 0)) {
      if (camera->forced_movement == 0) {
        iVar9 = -0x48;
        uVar2 = CAMERA_SignedAngleDifference
                          ((camera->focusRotation).z,(camera->targetFocusRotation).z);
        if ((int)((uint)uVar2 << 0x10) < 0) goto LAB_80017ff4;
      }
      else {
        if (camera->rotDirection < 1) {
          if (camera->rotDirection < 0) {
            iVar9 = -0x48;
          }
        }
        else {
LAB_80017ff4:
          iVar9 = 0x48;
        }
      }
      if (ACE_amount < 1) {
        if ((iVar9 < 0) && (iVar9 = iVar9 - ACE_amount, 0 < iVar9)) {
          iVar9 = 0;
        }
      }
      else {
        if ((0 < iVar9) && (iVar9 = iVar9 - ACE_amount, iVar9 < 0)) {
          iVar9 = 0;
        }
      }
    }
  }
  else {
    ACE_amount = 0;
  }
  local_e6 = 0x122;
  local_fe = (short)ACE_amount;
  if (ACE_amount < 1) {
    local_fe = local_fe * -2;
  }
  else {
    local_e6 = local_fe * 5 + (short)(ACE_amount / 2) + 0x122;
  }
  local_fe = local_fe + 0x20;
  if (0 < iVar9) {
    local_e6 = local_e6 + (short)iVar9 * 5;
  }
  ApplyMatrix(&MStack184,&local_100,local_f8);
  ApplyMatrix(&MStack184,&local_e8,local_e0);
  p_Var7 = colInfo->start;
  local_148.x = (p_Var7->position).x + local_f8[0];
  local_148.y = (p_Var7->position).y + local_f4;
  local_148.z = (p_Var7->position).z + local_f0;
  p_Var7 = colInfo->end;
  local_120.x = (p_Var7->position).x + local_e0[0];
  local_120.y = (p_Var7->position).y + local_dc;
  local_120.z = (p_Var7->position).z + local_d8;
  local_e6 = 0x122;
  local_fe = (short)ACE_amount;
  if (ACE_amount < 0) {
    local_e6 = 0x122 - (local_fe * 5 + (short)(ACE_amount / 2));
    local_fe = -local_fe;
  }
  else {
    local_fe = local_fe * 2;
  }
  local_fe = local_fe + 0x20;
  if (iVar9 < 0) {
    local_e6 = local_e6 + (short)iVar9 * -5;
  }
  ApplyMatrix(&MStack184,&local_100,local_f8);
  ApplyMatrix(&MStack184,&local_e8,local_e0);
  p_Var7 = colInfo->start;
  local_140.x = (p_Var7->position).x - local_f8[0];
  local_140.y = (p_Var7->position).y - local_f4;
  local_140.z = (p_Var7->position).z - local_f0;
  p_Var7 = colInfo->end;
  local_118.x = (p_Var7->position).x - local_e0[0];
  local_118.y = (p_Var7->position).y - local_dc;
  local_118.z = (p_Var7->position).z - local_d8;
  local_e6 = 0xb4;
  local_fe = 0x20;
  MATH3D_SetUnityMatrix(&MStack184);
  RotMatrixX((int)local_c0.x + 0x400,(int)&MStack184);
  RotMatrixZ((int)local_c0.z,(uint *)&MStack184);
  ApplyMatrix(&MStack184,&local_100,local_f8);
  ApplyMatrix(&MStack184,&local_e8,local_e0);
  p_Var7 = colInfo->start;
  local_138 = local_f8[0] + (p_Var7->position).x;
  local_136 = local_f4 + (p_Var7->position).y;
  local_134 = local_f0 + (p_Var7->position).z;
  p_Var7 = colInfo->end;
  local_110 = local_e0[0] + (p_Var7->position).x;
  local_10e = local_dc + (p_Var7->position).y;
  local_10c = local_d8 + (p_Var7->position).z;
  p_Var7 = colInfo->start;
  local_130 = (p_Var7->position).x - local_f8[0];
  local_12e = (p_Var7->position).y - local_f4;
  local_12c = (p_Var7->position).z - local_f0;
  p_Var7 = colInfo->end;
  local_108 = (p_Var7->position).x - local_e0[0];
  local_106 = (p_Var7->position).y - local_dc;
  local_104 = (p_Var7->position).z - local_d8;
  right_point.x = local_148.x + (camera->focusInstanceVelVec).x;
  right_point.y = local_148.y + (camera->focusInstanceVelVec).y;
  right_point.z = local_148.z + (camera->focusInstanceVelVec).z;
  local_fe = 0x1000;
  left_point.x = local_140.x + (camera->focusInstanceVelVec).x;
  left_point.y = local_140.y + (camera->focusInstanceVelVec).y;
  left_point.z = local_140.z + (camera->focusInstanceVelVec).z;
  ApplyMatrix(&MStack184,&local_100,local_f8);
  local_fe = 0;
  local_fc = 0x1000;
  camera_plane.x = local_f8[0];
  camera_plane.y = local_f4;
  camera_plane.z = local_f0;
  ApplyMatrix(&MStack184,&local_100,&local_d0);
  p_Var7 = colInfo->start;
  local_150.vx = (p_Var7->position).x;
  local_150.vy = (p_Var7->position).y;
  local_150.vz = (p_Var7->position).z;
  pSVar11 = &local_150;
  local_3c = 0;
  p_Var7 = colInfo->end;
  local_2c = &local_158;
  local_128.vx = (p_Var7->position).x;
  local_128.vy = (p_Var7->position).y;
  local_128.vz = (p_Var7->position).z;
  pSVar12 = &local_128;
  colInfo->lenCenterToExtend = (int)camera->targetFocusDistance;
  p_Var4 = STREAM_GetStreamUnitWithID(local_34->streamUnitID);
  local_30 = (uint)(ushort)p_Var4->flags & 1;
  pCVar10 = colInfo;
  pCVar13 = colInfo;
  do {
    if ((colInfo->cldLines & 1 << (local_3c & 0x1f)) != 0) {
      Flags = (uint)(local_3c - 1 < 2);
      local_48[0] = 0;
      _Stack120.instance = (_Instance *)0x0;
      _Stack120.collideType = 1;
      _Stack120.newPoint = pSVar12;
      _Stack120.oldPoint = pSVar11;
      p_Var5 = COLLIDE_PointAndTerrainFunc
                         (local_34->terrain,&_Stack120,Flags,local_48,0xd0,0x20,
                          (_LCollideInfo *)auStack136);
      *(_TFace **)pCVar13->tfaceList = p_Var5;
      *(_Terrain **)pCVar13->tfaceTerrain = local_34->terrain;
      if (pCVar13->tfaceList[0] == (_func_18 *)0x0) {
        iVar9 = 0;
        puVar8 = (ushort *)&StreamTracker.StreamList[0].flags;
        do {
          address = *(Level **)(puVar8 + 1);
          if ((((puVar8[-1] == 2) && (address != local_34)) &&
              (lVar3 = MEMPACK_MemoryValidFunc((char *)address), lVar3 != 0)) &&
             ((local_30 == 0 || ((*puVar8 & 1) == 0)))) {
            p_Var5 = COLLIDE_PointAndTerrainFunc
                               (address->terrain,&_Stack120,Flags,local_48,0xd0,0x20,
                                (_LCollideInfo *)auStack136);
            *(_TFace **)pCVar13->tfaceList = p_Var5;
            if (p_Var5 != (_TFace *)0x0) {
              *(_Terrain **)pCVar13->tfaceTerrain = address->terrain;
              break;
            }
          }
          iVar9 = iVar9 + 1;
          puVar8 = puVar8 + 0x20;
        } while (iVar9 < 0x10);
      }
      pCVar10->bspTree[0] = local_80;
      if ((_TFace *)pCVar13->tfaceList[0] == (_TFace *)0x0) {
        sVar6 = pSVar11->vz;
        sVar1 = pSVar12->vz;
        iVar9 = (uint)(ushort)pSVar11->vx - (uint)(ushort)pSVar12->vx;
        local_158 = (undefined2)iVar9;
        local_2c[1] = pSVar11->vy - pSVar12->vy;
        local_2c[2] = sVar6 - sVar1;
        pCVar10->lengthList[0] =
             (short)((iVar9 * 0x10000 >> 0x10) * local_d0 + local_156 * local_cc +
                     local_154 * local_c8 >> 0xc);
      }
      else {
        if (secondcheck_flag != 0) {
          return (_TFace *)pCVar13->tfaceList[0];
        }
        colInfo->numCollided = colInfo->numCollided + 1;
        sVar6 = pSVar11->vz;
        sVar1 = pSVar12->vz;
        iVar9 = (uint)(ushort)pSVar11->vx - (uint)(ushort)pSVar12->vx;
        local_158 = (undefined2)iVar9;
        local_2c[1] = pSVar11->vy - pSVar12->vy;
        local_2c[2] = sVar6 - sVar1;
        iVar9 = (iVar9 * 0x10000 >> 0x10) * local_d0 + local_156 * local_cc + local_154 * local_c8
                >> 0xc;
        sVar6 = (short)iVar9;
        pCVar10->lengthList[0] = sVar6;
        if ((local_48[0] == 0) || (99 < sVar6)) {
          iVar9 = iVar9 + -100;
          pCVar10->lengthList[0] = (short)iVar9;
          if (iVar9 * 0x10000 >> 0x10 < 0xdc) {
            pCVar10->lengthList[0] = 0xdc;
          }
          if ((local_38 != 0) || (pCVar10->lengthList[0] < local_44)) {
            colInfo->line = local_3c;
            local_44 = (int)pCVar10->lengthList[0];
            local_38 = 0;
            colInfo->lenCenterToExtend = local_44;
            local_40 = (_TFace *)pCVar13->tfaceList[0];
          }
          colInfo->flags = colInfo->flags | 1 << (local_3c & 0x1f);
        }
      }
    }
    pSVar12 = pSVar12 + 1;
    pSVar11 = pSVar11 + 1;
    pCVar13 = (CameraCollisionInfo *)(pCVar13->tfaceList + 1);
    pCVar10 = (CameraCollisionInfo *)((int)pCVar10->tfaceList + 2);
    local_3c = local_3c + 1;
  } while ((int)local_3c < 5);
  if (colInfo->line == 2) {
    target = &local_140;
    position = &local_118;
  }
  else {
    if (colInfo->line != 1) {
      target = &local_140;
      if ((colInfo->flags & 4U) != 0) {
        position = &local_118;
        goto LAB_800188a0;
      }
      if ((colInfo->flags & 2U) == 0) {
        return local_40;
      }
    }
    target = &local_148;
    position = &local_120;
  }
LAB_800188a0:
  hitline_rot = CAMERA_CalcZRotation(target,position);
  return local_40;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_CalcTilt(struct _Normal *normal /*$s1*/, short zRot /*$a1*/)
 // line 2383, offset 0x800188e0
	/* begin block 1 */
		// Start line: 2384
		// Start offset: 0x800188E0
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct VECTOR newNormal; // stack offset -32
	/* end block 1 */
	// End offset: 0x800188E0
	// End Line: 2384

	/* begin block 2 */
		// Start line: 5840
	/* end block 2 */
	// End Line: 5841

long CAMERA_CalcTilt(_Normal *normal,short zRot)

{
  int iVar1;
  MATRIX MStack64;
  undefined auStack32 [4];
  uint local_1c;
  uint local_18;
  
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixZ(-(int)zRot,(uint *)&MStack64);
  ApplyMatrix(&MStack64,normal,auStack32);
  iVar1 = ratan2(local_1c,local_18);
  return -(int)(short)iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance /*$a0*/, struct _Position *focusPoint /*$a1*/)
 // line 2400, offset 0x80018954
	/* begin block 1 */
		// Start line: 2401
		// Start offset: 0x80018954
		// Variables:
	// 		struct _Position lookFocus; // stack offset -8
	/* end block 1 */
	// End offset: 0x80018954
	// End Line: 2401

	/* begin block 2 */
		// Start line: 5875
	/* end block 2 */
	// End Line: 5876

	/* begin block 3 */
		// Start line: 5880
	/* end block 3 */
	// End Line: 5881

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
 // line 2413, offset 0x8001899c
	/* begin block 1 */
		// Start line: 5906
	/* end block 1 */
	// End Line: 5907

	/* begin block 2 */
		// Start line: 5907
	/* end block 2 */
	// End Line: 5908

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
 // line 2421, offset 0x800189c4
	/* begin block 1 */
		// Start line: 2422
		// Start offset: 0x800189C4
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		int smooth; // $t0
	// 		int distance; // $a3
	// 		long dampMode; // $a0

		/* begin block 1.1 */
			// Start line: 2467
			// Start offset: 0x80018AB4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80018AB4
		// End Line: 2467

		/* begin block 1.2 */
			// Start line: 2488
			// Start offset: 0x80018B1C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.2 */
		// End offset: 0x80018B1C
		// End Line: 2488

		/* begin block 1.3 */
			// Start line: 2488
			// Start offset: 0x80018B1C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80018B1C
		// End Line: 2488

		/* begin block 1.4 */
			// Start line: 2488
			// Start offset: 0x80018B1C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80018B1C
		// End Line: 2488
	/* end block 1 */
	// End offset: 0x80018B1C
	// End Line: 2494

	/* begin block 2 */
		// Start line: 5919
	/* end block 2 */
	// End Line: 5920

	/* begin block 3 */
		// Start line: 5923
	/* end block 3 */
	// End Line: 5924

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
 // line 2547, offset 0x80018c18
	/* begin block 1 */
		// Start line: 2548
		// Start offset: 0x80018C18
		// Variables:
	// 		long len; // $a1
	/* end block 1 */
	// End offset: 0x80018C80
	// End Line: 2556

	/* begin block 2 */
		// Start line: 6218
	/* end block 2 */
	// End Line: 6219

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
 // line 2558, offset 0x80018c90
	/* begin block 1 */
		// Start line: 2559
		// Start offset: 0x80018C90
	/* end block 1 */
	// End offset: 0x80018E34
	// End Line: 2670

	/* begin block 2 */
		// Start line: 6242
	/* end block 2 */
	// End Line: 6243

void CAMERA_HandleTransitions(Camera *camera)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  if (camera->rotState == 3) {
    sVar1 = (camera->signalRot).z;
    sVar2 = camera->forced_movement;
    (camera->targetFocusRotation).z = sVar1;
    (camera->collisionTargetFocusRotation).z = sVar1;
    if (((sVar2 == 1) && ((camera->lock & 4U) == 0)) ||
       (sVar2 = CAMERA_AngleDifference((camera->targetFocusRotation).z,(camera->focusRotation).z),
       sVar2 < 4)) {
      camera->rotState = 0;
      (camera->focusRotVel).z = 0;
      (camera->focusRotAccl).z = 0;
    }
  }
  if ((camera->tiltState == 3) &&
     (((sVar2 = camera->forced_movement, (camera->targetFocusRotation).x = (camera->signalRot).x,
       sVar2 == 3 && ((camera->lock & 2U) == 0)) ||
      (sVar2 = CAMERA_AngleDifference((camera->focusRotation).x,(camera->signalRot).x), sVar2 < 4)))
     ) {
    camera->tiltState = 0;
    (camera->focusRotVel).x = 0;
    (camera->focusRotAccl).x = 0;
  }
  if (camera->distanceState != 3) goto LAB_80018dfc;
  if ((camera->forced_movement == 2) && ((camera->lock & 1U) == 0)) {
LAB_80018de4:
    camera->distanceState = 0;
LAB_80018de8:
    camera->focusDistanceVel = 0;
    camera->focusDistanceAccl = 0;
  }
  else {
    iVar3 = (int)camera->targetFocusDistance - (int)camera->signalFocusDistance;
    if (iVar3 < 0) {
      if ((int)camera->signalFocusDistance - (int)camera->targetFocusDistance < 4)
      goto LAB_80018de4;
    }
    else {
      if (iVar3 < 4) {
        camera->distanceState = 0;
        goto LAB_80018de8;
      }
    }
  }
  camera->targetFocusDistance = camera->signalFocusDistance;
LAB_80018dfc:
  if ((camera->posState == 3) && ((camera->mode != 5 || ((camera->flags & 0x1000U) != 0)))) {
    camera->posState = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFocusOffset(struct _SVector *offset /*$a2*/, struct Camera *camera /*$a1*/)
 // line 2674, offset 0x80018e44
	/* begin block 1 */
		// Start line: 2675
		// Start offset: 0x80018E44
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -24
	// 		struct _SVector temp; // stack offset -8
	// 		struct _Instance *focusInstance; // $a0

		/* begin block 1.1 */
			// Start line: 2699
			// Start offset: 0x80018E84
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x80018E84
		// End Line: 2699
	/* end block 1 */
	// End offset: 0x80018E84
	// End Line: 2699

	/* begin block 2 */
		// Start line: 6476
	/* end block 2 */
	// End Line: 6477

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
 // line 2704, offset 0x80018ef8
	/* begin block 1 */
		// Start line: 2705
		// Start offset: 0x80018EF8
		// Variables:
	// 		struct _Vector adjustedOffset; // stack offset -32
	// 		struct _SVector temp; // stack offset -16
	// 		struct _Instance *focusInstance; // $v1

		/* begin block 1.1 */
			// Start line: 2705
			// Start offset: 0x80018EF8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _Vector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80018EF8
		// End Line: 2705
	/* end block 1 */
	// End offset: 0x80018EF8
	// End Line: 2705

	/* begin block 2 */
		// Start line: 6544
	/* end block 2 */
	// End Line: 6545

void CAMERA_CalcFocusOffsetForSwim(_SVector *offset,Camera *camera)

{
  short local_20 [2];
  short local_1c;
  short local_18;
  short local_10;
  short local_e;
  short local_c;
  
  local_10 = (camera->focusOffset).x;
  local_e = (camera->focusOffset).y;
  local_c = (camera->focusOffset).z;
  ApplyMatrix(camera->focusInstance->matrix + 1,&local_10,local_20);
  offset->x = local_20[0];
  offset->y = local_1c;
  offset->z = local_18;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ CAMERA_CalcIntersectAngle(struct _SVector *linept /*$s0*/, struct _SVector *vertex0 /*$a1*/, struct _SVector *vertex1 /*$a2*/, short *high /*$s2*/, short *low /*stack 16*/)
 // line 2728, offset 0x80018f64
	/* begin block 1 */
		// Start line: 2729
		// Start offset: 0x80018F64
		// Variables:
	// 		struct _SVector point; // stack offset -24
	// 		short zrot; // $a0
	// 		long camera_plane_d; // $v0
	/* end block 1 */
	// End offset: 0x8001903C
	// End Line: 2748

	/* begin block 2 */
		// Start line: 6610
	/* end block 2 */
	// End Line: 6611

	/* begin block 3 */
		// Start line: 6615
	/* end block 3 */
	// End Line: 6616

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
 // line 2750, offset 0x80019054
	/* begin block 1 */
		// Start line: 2751
		// Start offset: 0x80019054
		// Variables:
	// 		struct _Terrain *terrain; // $t1
	// 		struct _SVector *vertex0; // $s1
	// 		struct _SVector *vertex1; // $s0
	// 		struct _SVector *vertex2; // $s3
	// 		struct _SVector new_linept; // stack offset -48
	// 		short high; // stack offset -40
	// 		short low; // stack offset -38
	/* end block 1 */
	// End offset: 0x800191F8
	// End Line: 2780

	/* begin block 2 */
		// Start line: 6677
	/* end block 2 */
	// End Line: 6678

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
 // line 2794, offset 0x8001921c
	/* begin block 1 */
		// Start line: 2795
		// Start offset: 0x8001921C
		// Variables:
	// 		long dp; // $v0
	// 		struct _Normal normal; // stack offset -32
	// 		struct _SVector sv; // stack offset -24

		/* begin block 1.1 */
			// Start line: 2795
			// Start offset: 0x8001921C
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
		// End offset: 0x8001921C
		// End Line: 2795
	/* end block 1 */
	// End offset: 0x800192D4
	// End Line: 2833

	/* begin block 2 */
		// Start line: 6885
	/* end block 2 */
	// End Line: 6886

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
  CAMERA_Normalize(&local_18);
  camera->collisionTargetFocusDistance = *(short *)&colInfo->lenCenterToExtend;
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_update_dist_debounced(struct Camera *camera /*$a0*/, short dist /*$a2*/)
 // line 2836, offset 0x800192ec
	/* begin block 1 */
		// Start line: 6976
	/* end block 1 */
	// End Line: 6977

	/* begin block 2 */
		// Start line: 6977
	/* end block 2 */
	// End Line: 6978

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
 // line 2848, offset 0x8001935c
	/* begin block 1 */
		// Start line: 2849
		// Start offset: 0x8001935C
		// Variables:
	// 		static short target_angle; // offset 0x50
	// 		static short angle_vel; // offset 0x52
	// 		static short angle_accl; // offset 0x54
	/* end block 1 */
	// End offset: 0x800193F4
	// End Line: 2866

	/* begin block 2 */
		// Start line: 7001
	/* end block 2 */
	// End Line: 7002

short CAMERA_dampgetline(short angle)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)angle;
  CriticalDampAngle(1,&DAT_800d03f0,angle,(short *)&DAT_800d03f2,(short *)&DAT_800d03f4,0x400);
  if (0x800 < DAT_800d03f0) {
    DAT_800d03f0 = DAT_800d03f0 + -0x1000;
  }
  iVar1 = (int)DAT_800d03f0;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x20) {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = -iVar2;
    }
    if ((0x1f < iVar1) && (DAT_800d03f0 = 0x20, iVar2 < 0)) {
      DAT_800d03f0 = -0x20;
    }
  }
  return DAT_800d03f0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_ACNoForcedMovement(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *colInfo /*$s1*/)
 // line 2874, offset 0x80019408
	/* begin block 1 */
		// Start line: 2875
		// Start offset: 0x80019408
		// Variables:
	// 		long hit; // $s2
	// 		short playerSamePos; // $s3
	// 		short angle; // $a0

		/* begin block 1.1 */
			// Start line: 2901
			// Start offset: 0x80019480
			// Variables:
		// 		int n; // $a0
		// 		int flag; // $t1
		// 		short dist; // $a1
		/* end block 1.1 */
		// End offset: 0x80019634
		// End Line: 2957
	/* end block 1 */
	// End offset: 0x800198F0
	// End Line: 3125

	/* begin block 2 */
		// Start line: 7061
	/* end block 2 */
	// End Line: 7062

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
      goto LAB_80019634;
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
      goto LAB_80019634;
    }
  }
  else {
LAB_80019634:
    if ((colInfo->numCollided == 4) && ((camera->lock & 1U) == 0)) {
      dist = (camera->targetFocusRotation).z;
      lVar9 = 1;
      camera->collisionTargetFocusDistance = *(short *)&colInfo->lenCenterToExtend;
      (camera->collisionTargetFocusRotation).z = dist;
      goto LAB_800198e4;
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
LAB_800198e4:
      CAMERA_dampgetline(0);
      return lVar9;
    }
    if ((uVar8 & 2) != 0) goto LAB_800197f8;
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
          goto LAB_80019888;
        }
      }
      else {
        if ((int)((uint)uVar3 << 0x10) < 0) {
          return 1;
        }
      }
      dist = (camera->focusRotation).z + 4;
      goto LAB_80019884;
    }
  }
  else {
    if ((uVar8 & 4) != 0) goto LAB_800197f8;
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
        goto LAB_80019888;
      }
      dist = (camera->focusRotation).z + -4;
LAB_80019884:
      dist = uVar3 + dist;
LAB_80019888:
      (camera->collisionTargetFocusRotation).z = dist;
      return 1;
    }
  }
  (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
LAB_800197f8:
  CAMERA_update_dist_debounced(camera,*(short *)&colInfo->lenCenterToExtend);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CAMERA_AbsoluteCollision(struct Camera *camera /*$a0*/, struct CameraCollisionInfo *colInfo /*$a1*/)
 // line 3131, offset 0x8001990c
	/* begin block 1 */
		// Start line: 3132
		// Start offset: 0x8001990C
		// Variables:
	// 		long hit; // $a3
	/* end block 1 */
	// End offset: 0x80019A24
	// End Line: 3201

	/* begin block 2 */
		// Start line: 7594
	/* end block 2 */
	// End Line: 7595

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
 // line 3206, offset 0x80019a34
	/* begin block 1 */
		// Start line: 3207
		// Start offset: 0x80019A34
		// Variables:
	// 		static short upvel; // offset 0x56
	// 		static short upaccl; // offset 0x58
	// 		static short upmaxVel; // offset 0x5a
	// 		short current_tmp; // stack offset -16
	/* end block 1 */
	// End offset: 0x80019C94
	// End Line: 3251

	/* begin block 2 */
		// Start line: 7754
	/* end block 2 */
	// End Line: 7755

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
      DAT_800d03fa = (short)(iVar3 << 1);
    }
    else {
      if (iVar3 - iVar4 < 0) {
        DAT_800d03fa = (short)((iVar4 - iVar3) / 6);
      }
      else {
        DAT_800d03fa = (short)((iVar3 - iVar4) / 6);
      }
    }
    goto LAB_80019c50;
  }
  iVar1 = iVar3 - iVar4;
  if (iVar1 < 0) {
    iVar1 = iVar4 - iVar3;
  }
  if (iVar1 < 5) {
    DAT_800d03f6 = 0;
    DAT_800d03f8 = 0;
    DAT_800d03fa = 0;
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
LAB_80019be8:
    DAT_800d03fa = sVar5;
  }
  else {
    iVar4 = iVar3 - target;
    sVar2 = (short)((uint)iVar4 >> 0x10);
    if (iVar4 < 0) {
      iVar3 = target - iVar3;
      sVar2 = (short)((uint)iVar3 >> 0x10);
      DAT_800d03fa = (short)(iVar3 / 6) + (sVar2 >> 0xf);
    }
    else {
      DAT_800d03fa = (short)(iVar4 / 6) + (sVar2 >> 0xf);
    }
    DAT_800d03fa = DAT_800d03fa - (sVar2 >> 0xf);
    sVar5 = 0x32;
    if (DAT_800d03fa < 0x32) goto LAB_80019be8;
  }
  iVar3 = (int)current - (int)target;
  if (iVar3 < 0) {
    iVar3 = (int)target - (int)current;
  }
  if ((iVar3 < DAT_800d03fa) && (DAT_800d03fa = current - target, (int)current - (int)target < 0)) {
    DAT_800d03fa = target - current;
  }
LAB_80019c50:
  local_10[0] = current;
  CriticalDampValue(1,local_10,target,&DAT_800d03f6,&DAT_800d03f8,(int)DAT_800d03fa);
  return local_10[0];
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CombatCamDist(struct Camera *camera /*$s0*/)
 // line 3311, offset 0x80019ca4
	/* begin block 1 */
		// Start line: 3312
		// Start offset: 0x80019CA4
		// Variables:
	// 		struct DVECTOR xy; // stack offset -48
	// 		struct DVECTOR xy2; // stack offset -40
	// 		struct _SVector position; // stack offset -32
	// 		long z; // stack offset -24
	// 		struct _Instance *instance; // $s1
	/* end block 1 */
	// End offset: 0x80019F54
	// End Line: 3393

	/* begin block 2 */
		// Start line: 7968
	/* end block 2 */
	// End Line: 7969

void CAMERA_CombatCamDist(Camera *camera)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  short local_30;
  short sStack46;
  short local_28;
  short sStack38;
  undefined4 local_20;
  uint local_1c;
  
  uVar4 = INSTANCE_Query(camera->focusInstance,0x22);
  if (uVar4 == 0) {
    combat_cam_distance = camera->targetFocusDistance;
    combat_cam_weight = 0x1000;
    return;
  }
  SetRotMatrix((undefined4 *)(camera->core).wcTransform);
  SetTransMatrix((int)(camera->core).wcTransform);
  local_20 = CONCAT22((camera->focusInstance->position).y,(camera->focusInstance->position).x);
  uVar2 = local_1c & 0xffff0000;
  local_1c = uVar2 | (ushort)(camera->focusInstance->position).z;
  setCopReg(2,in_zero,local_20);
  setCopReg(2,in_at,local_1c);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  iVar6 = getCopReg(2,0x13);
  local_30 = (short)uVar1;
  iVar5 = (int)local_30 + -0x100;
  if ((int)local_30 < 0x100) {
    iVar5 = iVar5 * iVar6;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0x7f;
    }
    combat_cam_distance = -(short)(iVar5 >> 7);
  }
  else {
    iVar5 = iVar5 * iVar6;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0x7f;
    }
    combat_cam_distance = (short)(iVar5 >> 7);
  }
  if (3000 < combat_cam_distance) {
    combat_cam_distance = 3000;
  }
  if (combat_cam_distance < camera->targetFocusDistance) {
    combat_cam_distance = camera->targetFocusDistance;
  }
  sStack46 = (short)((uint)uVar1 >> 0x10);
  if (sStack46 < 0xf1) {
    if (0xd1 < sStack46) goto LAB_80019e64;
    combat_cam_weight = combat_cam_weight + -0x30;
    sVar3 = 0x800;
    if (0x7ff < combat_cam_weight) goto LAB_80019e64;
  }
  else {
    combat_cam_weight = combat_cam_weight + 0x30;
    sVar3 = 0x1000;
    if (combat_cam_weight < 0x1001) goto LAB_80019e64;
  }
  combat_cam_weight = sVar3;
LAB_80019e64:
  local_1c = uVar2 | *(ushort *)(uVar4 + 0x60);
  setCopReg(2,in_zero,*(undefined4 *)(uVar4 + 0x5c));
  setCopReg(2,in_at,local_1c);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  sStack38 = (short)((uint)uVar1 >> 0x10);
  local_28 = (short)uVar1;
  iVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
  if (iVar6 < 0) {
    iVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
    combat_cam_angle = -(short)iVar6;
  }
  else {
    iVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
    combat_cam_angle = (short)iVar6;
  }
  if (0x400 < combat_cam_angle) {
    combat_cam_angle = 0x800 - combat_cam_angle;
  }
  iVar6 = (int)combat_cam_angle;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 7;
  }
  combat_cam_angle = -0xaa - (short)(iVar6 >> 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_GenericCameraProcess(struct Camera *camera /*$s0*/)
 // line 3396, offset 0x80019f68
	/* begin block 1 */
		// Start line: 3397
		// Start offset: 0x80019F68
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3449
			// Start offset: 0x8001A08C
			// Variables:
		// 		short angle; // $a0
		// 		struct _Rotation test_rot; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8001A0EC
		// End Line: 3467

		/* begin block 1.2 */
			// Start line: 3475
			// Start offset: 0x8001A0FC
			// Variables:
		// 		struct _Instance *warpInstance; // $v0
		// 		int tmp; // $v0
		/* end block 1.2 */
		// End offset: 0x8001A10C
		// End Line: 3481

		/* begin block 1.3 */
			// Start line: 3513
			// Start offset: 0x8001A1BC
			// Variables:
		// 		int mod; // $v1
		/* end block 1.3 */
		// End offset: 0x8001A23C
		// End Line: 3528

		/* begin block 1.4 */
			// Start line: 3536
			// Start offset: 0x8001A258
			// Variables:
		// 		int dist; // $a3
		/* end block 1.4 */
		// End offset: 0x8001A2AC
		// End Line: 3554

		/* begin block 1.5 */
			// Start line: 3568
			// Start offset: 0x8001A2EC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x8001A2EC
		// End Line: 3568

		/* begin block 1.6 */
			// Start line: 3577
			// Start offset: 0x8001A330
			// Variables:
		// 		struct _Position target; // stack offset -24
		/* end block 1.6 */
		// End offset: 0x8001A3B0
		// End Line: 3597
	/* end block 1 */
	// End offset: 0x8001A3B0
	// End Line: 3600

	/* begin block 2 */
		// Start line: 8139
	/* end block 2 */
	// End Line: 8140

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
        goto LAB_8001a244;
      }
    }
    else {
      if ((uVar5 & 0x2000000) != 0) goto LAB_8001a244;
      (camera->rotationVel).z = 0x40;
    }
    CAMERA_FollowGoBehindPlayer(camera);
  }
LAB_8001a244:
  if ((camera->flags & 0x1800U) == 0) {
    if ((camera->instance_mode & 0x2000000) == 0) {
      combat_cam_distance = camera->targetFocusDistance;
    }
    else {
      CAMERA_CombatCamDist(camera);
    }
    CAMERA_CalcPosition(&_Stack32,&camera->focusPoint,&camera->focusRotation,combat_cam_distance);
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
 // line 3608, offset 0x8001a3e4
	/* begin block 1 */
		// Start line: 3609
		// Start offset: 0x8001A3E4
		// Variables:
	// 		struct _SVector *camPos; // $s0
	// 		struct _SVector *camTarget; // $s3
	// 		struct MultiSpline *posSpline; // $s4
	// 		struct MultiSpline *targetSpline; // $s1

		/* begin block 1.1 */
			// Start line: 3632
			// Start offset: 0x8001A45C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001A45C
		// End Line: 3632

		/* begin block 1.2 */
			// Start line: 3636
			// Start offset: 0x8001A478
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _SVector *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001A490
		// End Line: 3636

		/* begin block 1.3 */
			// Start line: 3641
			// Start offset: 0x8001A4A0
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x8001A4A0
		// End Line: 3641

		/* begin block 1.4 */
			// Start line: 3649
			// Start offset: 0x8001A4E8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a2
		// 		struct _Position *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x8001A4E8
		// End Line: 3649

		/* begin block 1.5 */
			// Start line: 3662
			// Start offset: 0x8001A548
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x8001A548
		// End Line: 3662

		/* begin block 1.6 */
			// Start line: 3710
			// Start offset: 0x8001A79C
		/* end block 1.6 */
		// End offset: 0x8001A898
		// End Line: 3727

		/* begin block 1.7 */
			// Start line: 3730
			// Start offset: 0x8001A898
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.7 */
		// End offset: 0x8001A898
		// End Line: 3730
	/* end block 1 */
	// End offset: 0x8001A898
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
    goto LAB_8001a8a0;
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
    if (8 < iVar3) goto LAB_8001a8a0;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a8a0;
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
    if (8 < iVar3) goto LAB_8001a8a0;
    iVar5 = (int)(camera->core).position.y;
    iVar4 = (int)(camera->targetPos).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a8a0;
    iVar5 = (int)(camera->core).position.z;
    iVar4 = (int)(camera->targetPos).z;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a8a0;
    iVar5 = (int)(camera->focusPoint).x;
    iVar4 = (int)(camera->targetFocusPoint).x;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a8a0;
    iVar5 = (int)(camera->focusPoint).y;
    iVar4 = (int)(camera->targetFocusPoint).y;
    iVar3 = iVar5 - iVar4;
    if (iVar3 < 0) {
      iVar3 = iVar4 - iVar5;
    }
    if (8 < iVar3) goto LAB_8001a8a0;
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
LAB_8001a8a0:
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
 // line 3744, offset 0x8001a900
	/* begin block 1 */
		// Start line: 3745
		// Start offset: 0x8001A900
		// Variables:
	// 		struct _Vector d; // stack offset -16
	/* end block 1 */
	// End offset: 0x8001A900
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
 // line 3759, offset 0x8001a97c
	/* begin block 1 */
		// Start line: 3760
		// Start offset: 0x8001A97C
		// Variables:
	// 		struct MATRIX nmat; // stack offset -64
	// 		struct _Vector dpv; // stack offset -32
	// 		long t; // $a0
	/* end block 1 */
	// End offset: 0x8001AA30
	// End Line: 3778

	/* begin block 2 */
		// Start line: 8903
	/* end block 2 */
	// End Line: 8904

void CAMERA_NearestPointOnLineVec
               (_SVector *linePoint,_SVector *start,_SVector *line,_Position *point)

{
  int iVar1;
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  int local_20;
  int local_1c;
  int local_18;
  
  local_40 = line->x;
  local_3e = line->y;
  local_3c = line->z;
  local_3a = start->x;
  local_38 = start->y;
  local_36 = start->z;
  local_34 = point->x;
  local_32 = point->y;
  local_30 = point->z;
  ApplyMatrix(&local_40,line,&local_20);
  iVar1 = (local_1c - local_18) * 0x1000;
  if (local_20 != 0) {
    iVar1 = ((local_1c - local_18) * -0x1000) / local_20;
  }
  linePoint->x = start->x + (short)(line->x * iVar1 >> 0xc);
  linePoint->y = start->y + (short)(line->y * iVar1 >> 0xc);
  linePoint->z = start->z + (short)(line->z * iVar1 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_CheckPoint(int linePoint /*$a0*/, int linept1 /*$a1*/, int linept2 /*$a2*/)
 // line 3784, offset 0x8001aaa8
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
 // line 3790, offset 0x8001aaec
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
 // line 3798, offset 0x8001ab7c
	/* begin block 1 */
		// Start line: 3799
		// Start offset: 0x8001AB7C
		// Variables:
	// 		struct _SVector outPoint; // stack offset -56
	// 		struct _SVector line; // stack offset -48
	// 		int calc; // $s1
	// 		int hits; // $s4

		/* begin block 1.1 */
			// Start line: 3799
			// Start offset: 0x8001AB7C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a3
		// 		short _x1; // $t0
		// 		short _y1; // $t1
		// 		short _z1; // $t2
		// 		struct _SVector *_v; // $s2
		/* end block 1.1 */
		// End offset: 0x8001AB7C
		// End Line: 3799

		/* begin block 1.2 */
			// Start line: 3813
			// Start offset: 0x8001AC10
			// Variables:
		// 		struct _SVector linePoint; // stack offset -40
		// 		int n; // $s3

			/* begin block 1.2.1 */
				// Start line: 3827
				// Start offset: 0x8001ACC4
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8001ACC4
			// End Line: 3827
		/* end block 1.2 */
		// End offset: 0x8001AD18
		// End Line: 3833
	/* end block 1 */
	// End offset: 0x8001AD18
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
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;
  
  local_30.x = linept2->x - linept1->x;
  local_30.y = linept2->y - linept1->y;
  local_30.z = linept2->z - linept1->z;
  CAMERA_NearestPointOnLineVec(&local_38,linept1,&local_30,point);
  iVar1 = CAMERA_GetDistSq(&local_38,(_SVector *)point);
  iVar2 = 0;
  if (0 < target_dist_sq - iVar1) {
    lVar3 = MATH3D_FastSqrt0(target_dist_sq - iVar1);
    CAMERA_Normalize(&local_30);
    iVar1 = 0;
    iVar2 = 0;
    do {
      iVar4 = local_30.x * lVar3;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0xfff;
      }
      iVar5 = local_30.y * lVar3;
      local_28.x = local_38.x + (short)(iVar4 >> 0xc);
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0xfff;
      }
      iVar4 = local_30.z * lVar3;
      local_28.y = local_38.y + (short)(iVar5 >> 0xc);
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0xfff;
      }
      local_28.z = local_38.z + (short)(iVar4 >> 0xc);
      iVar4 = CAMERA_CheckIfPointOnLine(&local_28,linept1,linept2);
      if (iVar4 != 0) {
        iVar2 = iVar2 + 1;
        results->x = local_28.x;
        results->y = local_28.y;
        results->z = local_28.z;
        results = results + 1;
      }
      iVar1 = iVar1 + 1;
      local_30.x = -local_30.x;
      local_30.z = -local_30.z;
      local_30.y = -local_30.y;
    } while (iVar1 < 2);
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineGetNearestPoint2(struct Camera *camera /*stack 0*/, struct Spline *spline /*stack 4*/, struct _SVector *point /*stack 8*/, int *currkey /*stack 12*/, struct _SVector *ret_dpoint /*stack 16*/)
 // line 3838, offset 0x8001ad40
	/* begin block 1 */
		// Start line: 3839
		// Start offset: 0x8001AD40
		// Variables:
	// 		struct SplineKey *key; // stack offset -56
	// 		int n; // $s2
	// 		int target_dist_sq; // stack offset -52
	// 		long dist; // $fp

		/* begin block 1.1 */
			// Start line: 3839
			// Start offset: 0x8001AD40
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001AD40
		// End Line: 3839

		/* begin block 1.2 */
			// Start line: 3858
			// Start offset: 0x8001ADF4
			// Variables:
		// 		struct _SVector point1; // stack offset -88
		// 		struct _SVector point2; // stack offset -80
		// 		struct _SVector results[2]; // stack offset -72
		// 		int i; // $s1
		// 		int hits; // $s3

			/* begin block 1.2.1 */
				// Start line: 3862
				// Start offset: 0x8001AE10
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a2
			// 		short _z1; // $v0
			// 		struct _SVector *_v0; // $s7
			// 		struct vecS *_v1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8001AE10
			// End Line: 3862

			/* begin block 1.2.2 */
				// Start line: 3862
				// Start offset: 0x8001AE10
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $a2
			// 		short _z1; // $v1
			// 		struct _SVector *_v0; // $s6
			// 		struct vecS *_v1; // $v1
			/* end block 1.2.2 */
			// End offset: 0x8001AE10
			// End Line: 3862

			/* begin block 1.2.3 */
				// Start line: 3869
				// Start offset: 0x8001AE88
				// Variables:
			// 		int tmpdist; // $a1

				/* begin block 1.2.3.1 */
					// Start line: 3880
					// Start offset: 0x8001AEA4
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.2.3.1 */
				// End offset: 0x8001AEA4
				// End Line: 3880
			/* end block 1.2.3 */
			// End offset: 0x8001AEC8
			// End Line: 3884
		/* end block 1.2 */
		// End offset: 0x8001AED8
		// End Line: 3892
	/* end block 1 */
	// End offset: 0x8001AEF8
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
 // line 3895, offset 0x8001af28
	/* begin block 1 */
		// Start line: 3896
		// Start offset: 0x8001AF28
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
			// Start offset: 0x8001B054
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $a3
		/* end block 1.1 */
		// End offset: 0x8001B054
		// End Line: 3921

		/* begin block 1.2 */
			// Start line: 3921
			// Start offset: 0x8001B054
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.2 */
		// End offset: 0x8001B054
		// End Line: 3921

		/* begin block 1.3 */
			// Start line: 3936
			// Start offset: 0x8001B11C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a2
		// 		struct vecS *_v1; // $v1
		/* end block 1.3 */
		// End offset: 0x8001B11C
		// End Line: 3936

		/* begin block 1.4 */
			// Start line: 3949
			// Start offset: 0x8001B17C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $t0
		// 		short _z1; // $v1
		// 		struct _SVector *_v0; // $a1
		// 		struct vecS *_v1; // $v1
		/* end block 1.4 */
		// End offset: 0x8001B17C
		// End Line: 3949
	/* end block 1 */
	// End offset: 0x8001B290
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
  SplineKey *pSVar8;
  int iVar9;
  uint local_60;
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
  short local_38;
  short local_36;
  short local_34;
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
  local_40 = (pSVar6->point).x;
  local_3e = (pSVar6->point).y;
  local_3c = (pSVar6->point).z;
  pSVar6 = pSVar8 + iVar9 + 1;
  local_38 = (pSVar6->point).x;
  local_36 = (pSVar6->point).y;
  local_34 = (pSVar6->point).z;
  iVar4 = COLLIDE_NearestPointOnLine_S
                    ((uint *)&local_60,(uint *)&local_40,(uint *)&local_38,(uint *)point);
  iVar5 = CAMERA_GetDistSq((_SVector *)&local_60,point);
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
    iVar9 = -1;
    if (bVar1) {
      iVar9 = (int)spline->numkeys + -2;
    }
  }
  else {
    iVar9 = iVar9 + -1;
  }
  if (iVar7 == -1) {
    iVar2 = -1;
LAB_8001b174:
    if (iVar9 == -1) {
      iVar3 = -1;
LAB_8001b1c4:
      if ((iVar2 - 1U < 0xfff) &&
         (iVar4 = CAMERA_GetDistSq((_SVector *)&local_58,point), iVar4 < iVar5)) {
        *currkey = iVar7;
        goto LAB_8001b1ec;
      }
      if ((0xffe < iVar3 - 1U) ||
         (iVar4 = CAMERA_GetDistSq((_SVector *)&local_50,point), iVar5 <= iVar4)) {
        *(uint *)ret_dpoint = local_60;
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
      if (0 < iVar4) goto LAB_8001b1c4;
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
    if (iVar4 < 0x1000) goto LAB_8001b174;
    *currkey = iVar7;
LAB_8001b1ec:
    *(uint *)ret_dpoint = local_58;
    *(undefined4 *)&ret_dpoint->z = local_54;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineHelpMove(struct Camera *camera /*$s1*/)
 // line 3981, offset 0x8001b2c0
	/* begin block 1 */
		// Start line: 3982
		// Start offset: 0x8001B2C0
		// Variables:
	// 		struct _SVector camPos; // stack offset -48
	// 		struct _Position pos; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Instance *focusInstance; // $s3
	// 		struct MultiSpline *posSpline; // $s2
	/* end block 1 */
	// End offset: 0x8001B414
	// End Line: 4026

	/* begin block 2 */
		// Start line: 9489
	/* end block 2 */
	// End Line: 9490

void CAMERA_SplineHelpMove(Camera *camera)

{
  short sVar1;
  int iVar2;
  int iVar3;
  MultiSpline *pMVar4;
  _Instance *p_Var5;
  _SVector _Stack48;
  _SVector _Stack40;
  _Rotation local_20;
  
  pMVar4 = (camera->data).Cinematic.posSpline;
  p_Var5 = camera->focusInstance;
  sVar1 = CAMERA_AngleDifference(splinecam_helprot.z,(camera->targetFocusRotation).z);
  if (sVar1 < 400) {
    splinecam_helprot.z = (camera->targetFocusRotation).z + 0x800;
    (camera->targetFocusRotation).z = (camera->targetFocusRotation).z & 0xfff;
  }
  CAMERA_CalcPosition((_Position *)&_Stack40,&camera->targetFocusPoint,&splinecam_helprot,
                      camera->targetFocusDistance);
  CAMERA_SplineGetNearestPoint2
            (camera,pMVar4->positional,&_Stack40,&(camera->data).Cinematic.splinecam_helpkey,
             &_Stack48);
  CAMERA_CalcRotation(&local_20,&camera->focusPoint,(_Position *)&_Stack48);
  splinecam_helprot.x = local_20.x;
  splinecam_helprot.z = local_20.z;
  sVar1 = CAMERA_AngleDifference
                    ((p_Var5->rotation).z,
                     (short)(((uint)(ushort)camera->lagZ + 0x800) * 0x10000 >> 0x10));
  if (sVar1 < 900) {
    local_20.z = local_20.z + 0x800 & 0xfff;
    sVar1 = CAMERA_SignedAngleDifference(local_20.z,camera->lagZ);
    iVar3 = (int)sVar1;
    iVar2 = iVar3;
    if (iVar3 < 0) {
      iVar2 = -iVar3;
    }
    if (iVar2 < 900) {
      camera->lagZ = camera->lagZ + (short)(iVar3 * 0x533 >> 0xb);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SplineProcess(struct Camera *camera /*$s1*/)
 // line 4028, offset 0x8001b430
	/* begin block 1 */
		// Start line: 4029
		// Start offset: 0x8001B430
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
			// Start offset: 0x8001B57C
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
		// End offset: 0x8001B57C
		// End Line: 4114
	/* end block 1 */
	// End offset: 0x8001B764
	// End Line: 4177

	/* begin block 2 */
		// Start line: 9602
	/* end block 2 */
	// End Line: 9603

void CAMERA_SplineProcess(Camera *camera)

{
  short sVar1;
  short distance;
  long lVar2;
  _SVector *point;
  int smooth;
  int smooth_00;
  MultiSpline *pMVar3;
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
  if (pMVar3 != (MultiSpline *)0x0) {
    CAMERA_CalcPosition((_Position *)point,&camera->targetFocusPoint,&local_20,distance);
    if (camera->mode == 4) {
      CAMERA_SplineGetNearestPoint2
                (camera,pMVar3->positional,point,&(camera->data).Cinematic.splinecam_currkey,
                 &local_30);
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
      DAT_800d03fc = 1;
    }
    else {
      smooth = CAMERA_FocusInstanceMoved(camera);
      if (smooth != 0) {
        if (DAT_800d03fc != 0) {
          camera->always_rotate_flag = 1;
        }
        DAT_800d03fc = 0;
      }
    }
    if (((camera->forced_movement != 1) && (DAT_800d03fc == 0)) && (camera->rotState != 3)) {
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
    if (((camera->forced_movement == 1) || (camera->always_rotate_flag != 0)) || (DAT_800d03fc != 0)
       ) {
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
    distance = CAMERA_AngleDifference((camera->focusRotation).z,local_20.z);
    if (distance < 0x20) {
      camera->always_rotate_flag = 0;
      camera->rotState = 0;
    }
    CAMERA_CalcFollowPosition(camera,&camera->focusRotation);
    if ((camera->mode == 4) && ((camera->flags & 0x10000U) == 0)) {
      CAMERA_SplineHelpMove(camera);
    }
    CAMERA_CalculateLead(camera);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_ShakeCamera(struct Camera *camera /*$a2*/)
 // line 4201, offset 0x8001b784
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
 // line 4220, offset 0x8001b86c
	/* begin block 1 */
		// Start line: 4221
		// Start offset: 0x8001B86C
		// Variables:
	// 		struct _Instance *focusInstance; // $a1

		/* begin block 1.1 */
			// Start line: 4280
			// Start offset: 0x8001B940
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
		// End offset: 0x8001B940
		// End Line: 4280
	/* end block 1 */
	// End offset: 0x8001BAA8
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
                    /* WARNING: Could not recover jumptable at 0x8001ba48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_80010134)[uVar9])();
    return;
  }
  camera->flags = camera->flags & 0xffffe7ff;
  CAMERA_ShakeCamera(camera);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CenterCamera(struct Camera *camera /*$s1*/)
 // line 4404, offset 0x8001bab8
	/* begin block 1 */
		// Start line: 4405
		// Start offset: 0x8001BAB8

		/* begin block 1.1 */
			// Start line: 4409
			// Start offset: 0x8001BAE0
			// Variables:
		// 		int tmp1; // $s0
		// 		int tmp2; // $v0
		/* end block 1.1 */
		// End offset: 0x8001BB4C
		// End Line: 4413
	/* end block 1 */
	// End offset: 0x8001BB78
	// End Line: 4420

	/* begin block 2 */
		// Start line: 10388
	/* end block 2 */
	// End Line: 10389

void CAMERA_CenterCamera(Camera *camera)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  if ((camera->instance_mode & 0x2000000) == 0) {
    uVar3 = (camera->focusInstance->rotation).z + 0x800;
  }
  else {
    sVar1 = CAMERA_AngleDifference
                      ((camera->focusRotation).z,
                       (short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x400) * 0x10000
                              >> 0x10));
    sVar2 = CAMERA_AngleDifference
                      ((camera->focusRotation).z,
                       (short)(((uint)(ushort)(camera->focusInstance->rotation).z - 0x400) * 0x10000
                              >> 0x10));
    if (sVar1 < sVar2) {
      uVar3 = (camera->focusInstance->rotation).z + 0x400;
    }
    else {
      uVar3 = (camera->focusInstance->rotation).z - 0x400;
    }
  }
  (camera->focusRotAccl).z = 0;
  (camera->focusRotVel).z = 0;
  CenterFlag = uVar3 & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetLookRot(struct Camera *camera /*$a0*/, int x_rotation /*$a1*/, int z_rotation /*$a2*/)
 // line 4436, offset 0x8001bba0
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
 // line 4442, offset 0x8001bbac
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
 // line 4460, offset 0x8001bc3c
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
 // line 4468, offset 0x8001bc7c
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
 // line 4474, offset 0x8001bca0
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
 // line 4483, offset 0x8001bcdc
	/* begin block 1 */
		// Start line: 4484
		// Start offset: 0x8001BCDC
		// Variables:
	// 		long *controlCommand; // $s2
	// 		int lookmode; // $s1
	// 		struct _Instance *focusInstance; // $s4
	/* end block 1 */
	// End offset: 0x8001C200
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
      if (CenterFlag == -1) {
        if ((gameTrackerX.cheatMode != '\x01') || ((gameTrackerX.controlCommand[0][0] & 0xfU) == 0))
        {
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
      else {
        if ((camera->instance_mode & 0x2000000) == 0) {
          camera->forced_movement = 1;
        }
        CriticalDampAngle(1,&(camera->focusRotation).z,CenterFlag,&(camera->focusRotVel).z,
                          &(camera->focusRotAccl).z,0x90);
        angle1 = CenterFlag;
        sVar3 = (camera->focusRotation).z;
        (camera->collisionTargetFocusRotation).z = sVar3;
        (camera->targetFocusRotation).z = sVar3;
        sVar3 = CAMERA_AngleDifference((camera->focusRotation).z,angle1);
        if (sVar3 < 8) {
          CenterFlag = -1;
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_EndLook(struct Camera *camera /*$s0*/)
 // line 4721, offset 0x8001c224
	/* begin block 1 */
		// Start line: 4722
		// Start offset: 0x8001C224
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001C300
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
 // line 4786, offset 0x8001c318
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
 // line 4813, offset 0x8001c3c4
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
 // line 4929, offset 0x8001c438
	/* begin block 1 */
		// Start line: 4930
		// Start offset: 0x8001C438
		// Variables:
	// 		int smooth; // $v1
	// 		long dampMode; // $a0
	/* end block 1 */
	// End offset: 0x8001C4F8
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
 // line 4979, offset 0x8001c508
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
 // line 5013, offset 0x8001c5d4
	/* begin block 1 */
		// Start line: 5014
		// Start offset: 0x8001C5D4
		// Variables:
	// 		long tmp_inc; // $s0
	/* end block 1 */
	// End offset: 0x8001C6D4
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
  short sVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  
  if (roll_inc != 0) {
    iVar2 = roll_inc;
    if (gameTrackerX.timeMult != 0x1000) {
      if (roll_inc < 0) {
        iVar2 = roll_inc + 0x1f;
      }
      iVar6 = (iVar2 >> 5) * gameTrackerX.timeMult;
      iVar2 = iVar6 >> 7;
      if (iVar6 < 0) {
        iVar2 = iVar6 + 0x7f >> 7;
      }
    }
    lVar3 = current_roll_amount;
    if (current_roll_amount < 0) {
      lVar3 = current_roll_amount + 0xfff;
    }
    lVar5 = roll_target;
    if (roll_target < 0) {
      lVar5 = roll_target + 0xfff;
    }
    sVar1 = CAMERA_AngleDifference
                      ((short)((uint)(lVar3 << 4) >> 0x10),(short)((uint)(lVar5 << 4) >> 0x10));
    iVar6 = iVar2;
    if (iVar2 < 0) {
      iVar6 = iVar2 + 0xfff;
    }
    iVar6 = iVar6 >> 0xc;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 < sVar1) {
      uVar4 = current_roll_amount + iVar2;
    }
    else {
      roll_inc = 0;
      uVar4 = roll_target;
    }
    current_roll_amount = uVar4 & 0xffffff;
  }
  lVar3 = current_roll_amount;
  if (current_roll_amount < 0) {
    lVar3 = current_roll_amount + 0xfff;
  }
  (camera->core).rotation.y = (short)(lVar3 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotate(struct Camera *camera /*$s0*/)
 // line 5037, offset 0x8001c6f0
	/* begin block 1 */
		// Start line: 5038
		// Start offset: 0x8001C6F0

		/* begin block 1.1 */
			// Start line: 5041
			// Start offset: 0x8001C724
			// Variables:
		// 		int dampspeed; // $v1
		// 		long dampmode; // $a0
		/* end block 1.1 */
		// End offset: 0x8001C7A4
		// End Line: 5066
	/* end block 1 */
	// End offset: 0x8001C7CC
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
      sVar1 = CAMERA_AngleDifference((camera->targetFocusRotation).z,(camera->focusRotation).z);
      if (3 < sVar1) {
        return;
      }
      camera->always_rotate_flag = 0;
      return;
    }
  }
  (camera->focusRotation).z = (camera->targetFocusRotation).z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_UpdateFocusRotationX(struct Camera *camera /*$s0*/, struct _Instance *focusInstance /*$a1*/)
 // line 5079, offset 0x8001c7dc
	/* begin block 1 */
		// Start line: 5080
		// Start offset: 0x8001C7DC
		// Variables:
	// 		short cameraPlayerRotX; // $a1
	// 		short dist; // $s1
	// 		short tfaceFlag; // $s2

		/* begin block 1.1 */
			// Start line: 5102
			// Start offset: 0x8001C85C
			// Variables:
		// 		struct _Normal normal; // stack offset -24
		// 		int mult; // $v1
		/* end block 1.1 */
		// End offset: 0x8001C938
		// End Line: 5128

		/* begin block 1.2 */
			// Start line: 5132
			// Start offset: 0x8001C944
			// Variables:
		// 		int tmpsmooth; // $t0
		/* end block 1.2 */
		// End offset: 0x8001C9B0
		// End Line: 5147
	/* end block 1 */
	// End offset: 0x8001CA40
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
  _Normal _Stack24;
  
  p_Var7 = focusInstance->tface;
  sVar1 = camera->targetFocusDistance;
  bVar2 = false;
  if ((((p_Var7 != (_TFace *)0x0) && (smooth = *(int *)focusInstance->tfaceLevel, smooth != 0)) &&
      (p_Var7->textoff != 0xffff)) &&
     (((*(ushort *)(*(int *)(smooth + 0x34) + (uint)p_Var7->textoff + 10) & 0x8000) != 0 &&
      (bVar2 = false, sVar1 < 0xb60)))) {
    COLLIDE_GetNormal(p_Var7->normal,*(short **)(smooth + 0x24),(_SVector *)&_Stack24);
    bVar2 = false;
    if (_Stack24.z < 0xf6e) {
      bVar2 = true;
      lVar5 = CAMERA_CalcTilt(&_Stack24,(camera->focusRotation).z);
      smooth = lVar5 * 9;
      if (smooth < 0) {
        smooth = smooth + 0xf;
      }
      sVar3 = (short)(smooth >> 4);
      camera->targetTilt = sVar3;
      sVar4 = -0x100;
      if (sVar3 < -0x100) {
LAB_8001c8d0:
        camera->targetTilt = sVar4;
      }
      else {
        if (0x100 < sVar3) {
          sVar4 = 0x100;
          goto LAB_8001c8d0;
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
    if (0x4ff < uVar6 - 0x800) goto LAB_8001c9f8;
    uVar6 = 0xfffffd00;
  }
  uVar6 = uVar6 & 0xfff;
LAB_8001c9f8:
  uVar8 = (ushort)uVar6;
  camera->tfaceTilt = uVar8;
  if ((camera->instance_mode & 0x2000000) != 0) {
    if (0x800 < uVar6) {
      uVar8 = uVar8 | 0xf000;
    }
    if (combat_cam_angle < (short)uVar8) {
      camera->tfaceTilt = combat_cam_angle + 0x1000;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowPlayerTilt(struct Camera *camera /*$s1*/, struct _Instance *focusInstance /*$a1*/)
 // line 5178, offset 0x8001ca58
	/* begin block 1 */
		// Start line: 5179
		// Start offset: 0x8001CA58
		// Variables:
	// 		int speed; // $s2
	// 		int mode; // $s3
	// 		long focusInstanceStatus; // $a0

		/* begin block 1.1 */
			// Start line: 5203
			// Start offset: 0x8001CADC
			// Variables:
		// 		struct _SVector offset; // stack offset -40
		// 		struct _Normal normal; // stack offset -32

			/* begin block 1.1.1 */
				// Start line: 5227
				// Start offset: 0x8001CB94
				// Variables:
			// 		int waterZ; // $v0
			// 		int target; // $v0
			// 		int height; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 5235
					// Start offset: 0x8001CBD4
					// Variables:
				// 		int fdsq; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8001CC14
				// End Line: 5243
			/* end block 1.1.1 */
			// End offset: 0x8001CC14
			// End Line: 5244
		/* end block 1.1 */
		// End offset: 0x8001CC14
		// End Line: 5245
	/* end block 1 */
	// End offset: 0x8001CC14
	// End Line: 5250

	/* begin block 2 */
		// Start line: 11914
	/* end block 2 */
	// End Line: 11915

void CAMERA_FollowPlayerTilt(Camera *camera,_Instance *focusInstance)

{
  short sVar1;
  ushort uVar2;
  short current;
  ulong uVar3;
  long lVar4;
  int iVar5;
  Level *pLVar6;
  uint uVar7;
  uint uVar8;
  long dampMode;
  _SVector local_28;
  _Normal local_20;
  
  uVar3 = INSTANCE_Query(focusInstance,9);
  dampMode = 1;
  if ((camera->flags & 0x10000U) != 0) {
    dampMode = 5;
  }
  current = 0x20;
  if ((camera->instance_mode & 0x4000000) == 0) {
    if ((uVar3 & 0x40) != 0) {
      camera->targetTilt = -0xab;
      current = 0x20;
      goto LAB_8001cc18;
    }
    CAMERA_CalcFocusOffsetForSwim(&local_28,camera);
    local_20.z = local_28.z;
    local_20.x = local_28.x;
    local_20.y = local_28.y;
    lVar4 = CAMERA_CalcTilt(&local_20,(camera->targetFocusRotation).z);
    camera->targetTilt = (short)lVar4 + 0x400;
    current = camera->targetTilt + -0x80;
    camera->targetTilt = current;
    uVar2 = AngleDiff(current,camera->tilt);
    if ((int)((uint)uVar2 << 0x10) < 0) {
      current = AngleDiff(camera->targetTilt,camera->tilt);
      iVar5 = -(int)current;
    }
    else {
      current = AngleDiff(camera->targetTilt,camera->tilt);
      iVar5 = (int)current;
    }
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xf;
    }
    current = (short)(iVar5 >> 4);
    if (0x20 < iVar5 >> 4) {
      current = 0x20;
    }
    pLVar6 = STREAM_GetLevelWithID(camera->focusInstance->currentStreamUnitID);
    iVar5 = (int)camera->focusDistance;
    uVar8 = (int)(camera->focusPoint).z - (pLVar6->waterZLevel + -0xa0);
    uVar7 = uVar8;
    if ((int)uVar8 < 0) {
      uVar7 = -uVar8;
    }
    if (iVar5 <= (int)uVar7) goto LAB_8001cc18;
    uVar7 = MATH3D_FastSqrt0(iVar5 * iVar5 - uVar8 * uVar8);
    iVar5 = ratan2(uVar8,uVar7);
    sVar1 = (short)iVar5;
    if (iVar5 <= camera->targetTilt) goto LAB_8001cc18;
  }
  else {
    sVar1 = -(camera->focusInstance->rotation).x;
  }
  camera->targetTilt = sVar1;
LAB_8001cc18:
  CriticalDampAngle(dampMode,&camera->tilt,camera->targetTilt,&camera->tiltVel,&camera->tiltAccl,
                    (int)current);
  camera->tfaceTilt = camera->tilt & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera /*$s0*/)
 // line 5259, offset 0x8001cc68
	/* begin block 1 */
		// Start line: 5260
		// Start offset: 0x8001CC68
		// Variables:
	// 		struct _Instance *focusInstance; // $s1
	/* end block 1 */
	// End offset: 0x8001CD50
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
    if ((gameTrackerX.streamFlags & 0x100000U) != 0) goto LAB_8001cce0;
    iVar1 = (camera->data).Follow.stopTimer + gameTrackerX.timeMult;
  }
  else {
    iVar1 = CameraCenterDelay * -0x1e000;
  }
  (camera->data).Follow.stopTimer = iVar1;
LAB_8001cce0:
  if (0 < (camera->data).Follow.stopTimer) {
    Decouple_AngleMoveToward
              (&(camera->targetFocusRotation).z,
               (short)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000 >> 0x10),0x20);
    Decouple_AngleMoveToward
              (&(camera->collisionTargetFocusRotation).z,
               (short)(((uint)(ushort)(p_Var2->rotation).z + 0x800) * 0x10000 >> 0x10),0x20);
    CriticalDampAngle(1,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z,
                      &(camera->focusRotVel).z,&(camera->focusRotAccl).z,0x20);
    camera->forced_movement = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_FollowGoBehindPlayer(struct Camera *camera /*$v1*/)
 // line 5301, offset 0x8001cd64
	/* begin block 1 */
		// Start line: 5302
		// Start offset: 0x8001CD64
		// Variables:
	// 		struct _Instance *focusInstance; // $v0
	/* end block 1 */
	// End offset: 0x8001CD64
	// End Line: 5302

	/* begin block 2 */
		// Start line: 12179
	/* end block 2 */
	// End Line: 12180

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
 // line 5313, offset 0x8001cda0
	/* begin block 1 */
		// Start line: 5314
		// Start offset: 0x8001CDA0
		// Variables:
	// 		short lead_target; // $s0
	// 		short lead_smooth; // $v1

		/* begin block 1.1 */
			// Start line: 5320
			// Start offset: 0x8001CDEC
			// Variables:
		// 		int speedxy; // $s0
		// 		short angle; // $a0

			/* begin block 1.1.1 */
				// Start line: 5332
				// Start offset: 0x8001CE74
				// Variables:
			// 		int calc; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8001CEE4
			// End Line: 5349
		/* end block 1.1 */
		// End offset: 0x8001CEEC
		// End Line: 5354
	/* end block 1 */
	// End offset: 0x8001CEF8
	// End Line: 5368

	/* begin block 2 */
		// Start line: 12203
	/* end block 2 */
	// End Line: 12204

void CAMERA_CalculateLead(Camera *camera)

{
  ushort uVar1;
  short sVar2;
  int smooth;
  short angle0;
  int iVar3;
  
  if ((((camera->flags & 0x10000U) == 0) && (camera->mode != 6)) &&
     ((camera->instance_mode & 0x3002043) == 0)) {
    iVar3 = camera->instance_xyvel;
    uVar1 = CAMERA_SignedAngleDifference
                      ((short)(((uint)(ushort)(camera->focusInstance->rotation).z + 0x800) * 0x10000
                              >> 0x10),(camera->core).rotation.z);
    if (iVar3 < 0x17) {
      if (camera->instance_prev_xyvel == 0) {
        camera->lead_timer = 0;
      }
    }
    else {
      camera->lead_timer = camera->lead_timer + 1;
    }
    angle0 = 0;
    if (0x16 < iVar3) {
      iVar3 = (int)(short)uVar1;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      smooth = 3;
      if (iVar3 - 0x191U < 0x4af) {
        iVar3 = (int)camera->lead_timer;
        if (0x23 < iVar3) {
          iVar3 = (iVar3 + -0x23) * 3 + 0x23;
        }
        if ((int)((uint)uVar1 << 0x10) < 1) {
          angle0 = -(short)iVar3;
          if (iVar3 >= 0x50) {
            angle0 = -0x50;
          }
        }
        else {
          angle0 = 0x50;
          if (iVar3 < 0x50) {
            angle0 = (short)iVar3;
          }
        }
        sVar2 = CAMERA_AngleDifference(angle0,camera->lead_angle);
        smooth = 8;
        if (0x50 < sVar2) {
          smooth = 0xc;
        }
      }
      goto LAB_8001cef8;
    }
  }
  else {
    camera->lead_timer = 0;
  }
  angle0 = 0;
  smooth = 3;
LAB_8001cef8:
  CriticalDampAngle(1,&camera->lead_angle,angle0,&camera->lead_vel,&camera->lead_accl,smooth);
  (camera->core).rotation.z = (camera->core).rotation.z + camera->lead_angle & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_CalcFollowPosition(struct Camera *camera /*$s1*/, struct _Rotation *rotation /*$s0*/)
 // line 5384, offset 0x8001cf48
	/* begin block 1 */
		// Start line: 5385
		// Start offset: 0x8001CF48
		// Variables:
	// 		struct _Instance *focusInstance; // $s2

		/* begin block 1.1 */
			// Start line: 5385
			// Start offset: 0x8001CF48
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Rotation *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CF48
		// End Line: 5385

		/* begin block 1.2 */
			// Start line: 5404
			// Start offset: 0x8001CFC8
			// Variables:
		// 		short target_rotx; // $s0
		// 		int hypotXY; // $s3
		// 		int smooth; // $v1
		// 		int diff; // $a0
		// 		struct _Vector dpv; // stack offset -40
		// 		int zdiff; // $a0

			/* begin block 1.2.1 */
				// Start line: 5426
				// Start offset: 0x8001D064
				// Variables:
			// 		int velz; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 5437
					// Start offset: 0x8001D080
					// Variables:
				// 		int ground; // $a0
				// 		int pos; // $v1
				/* end block 1.2.1.1 */
				// End offset: 0x8001D0F8
				// End Line: 5452
			/* end block 1.2.1 */
			// End offset: 0x8001D0F8
			// End Line: 5452
		/* end block 1.2 */
		// End offset: 0x8001D204
		// End Line: 5500
	/* end block 1 */
	// End offset: 0x8001D21C
	// End Line: 5505

	/* begin block 2 */
		// Start line: 12347
	/* end block 2 */
	// End Line: 12348

void CAMERA_CalcFollowPosition(Camera *camera,_Rotation *rotation)

{
  short sVar1;
  short angle0;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 in_t2;
  undefined4 in_t3;
  _Instance *p_Var8;
  
  p_Var8 = camera->focusInstance;
  CAMERA_CalcPosition(&camera->targetPos,&camera->focusPoint,rotation,camera->focusDistance);
  angle0 = (camera->targetPos).z;
  *(undefined4 *)&(camera->core).position = *(undefined4 *)&camera->targetPos;
  (camera->core).position.z = angle0;
  sVar3 = rotation->y;
  sVar1 = rotation->z;
  (camera->core).rotation.x = rotation->x;
  (camera->core).rotation.y = sVar3;
  (camera->core).rotation.z = sVar1;
  if ((camera->flags & 0x10000U) != 0) {
    camera->actual_x_rot = (camera->core).rotation.x;
    goto LAB_8001d21c;
  }
  sVar3 = (camera->real_focuspoint).x;
  sVar1 = (camera->targetPos).x;
  camera->actual_x_rot = camera->actual_x_rot - camera->x_rot_change;
  setCopReg(2,(int)angle0,(int)sVar3 - (int)sVar1);
  setCopReg(2,in_t2,(int)(camera->real_focuspoint).y - (int)(camera->targetPos).y);
  setCopReg(2,in_t3,0);
  copFunction(2,0xa00428);
  iVar5 = getCopReg(2,0x19);
  iVar6 = getCopReg(2,0x1a);
  getCopReg(2,0x1b);
  uVar4 = MATH3D_FastSqrt0(iVar5 + iVar6);
  iVar5 = ratan2((int)(camera->real_focuspoint).z - (int)(camera->targetPos).z,uVar4);
  angle0 = (short)iVar5;
  if ((camera->instance_mode & 0x1038) == 0) {
    sVar3 = CAMERA_AngleDifference(angle0,(camera->core).rotation.x);
    if (sVar3 < 4) {
LAB_8001d128:
      angle0 = (camera->core).rotation.x;
    }
  }
  else {
    iVar5 = (int)(camera->focusInstanceVelVec).z;
    if ((p_Var8->shadowPosition).z != (p_Var8->position).z) {
      if (-1 < iVar5) goto LAB_8001d128;
      if ((iVar5 < -0x104) && (iVar5 = -0x208 - iVar5, 0 < iVar5)) {
        iVar5 = 0;
      }
      iVar6 = (int)(p_Var8->shadowPosition).z + 0x160;
      iVar5 = (int)(camera->real_focuspoint).z + iVar5 * 2;
      if (iVar5 < iVar6) {
        uVar7 = iVar6 - (camera->targetPos).z;
      }
      else {
        uVar7 = iVar5 - (camera->targetPos).z;
      }
      iVar5 = ratan2(uVar7,uVar4);
      angle0 = (short)iVar5;
      uVar2 = CAMERA_SignedAngleDifference(angle0,camera->actual_x_rot);
      if (0 < (int)((uint)uVar2 << 0x10)) {
        angle0 = camera->actual_x_rot;
      }
    }
  }
  if ((camera->flags & 0x1800U) != 0) {
    camera->actual_x_rot = angle0;
    camera->x_rot_change = 0;
  }
  sVar3 = CAMERA_SignedAngleDifference(angle0,camera->actual_x_rot);
  iVar5 = (int)sVar3;
  if ((camera->instance_mode & 0x2000) == 0) {
    iVar6 = 0x18;
  }
  else {
    if (iVar5 < 0x51) {
      iVar6 = 0x18;
      if (0 < iVar5) goto LAB_8001d1b8;
    }
    else {
      iVar6 = (iVar5 + -0x50) / 3;
      if (iVar6 < 4) {
LAB_8001d1b8:
        iVar6 = 4;
      }
      else {
        if (0x18 < iVar6) {
          iVar6 = 0x18;
        }
      }
    }
  }
  if (iVar6 == 0) {
    camera->actual_acc_x = 0;
    camera->actual_vel_x = 0;
  }
  else {
    CriticalDampAngle(1,&camera->actual_x_rot,angle0,&camera->actual_vel_x,&camera->actual_acc_x,
                      (int)(short)iVar6);
  }
  (camera->core).rotation.x = camera->actual_x_rot;
LAB_8001d21c:
  camera->lagZ = (camera->core).rotation.z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_SetupColInfo(struct Camera *camera /*$a3*/, struct CameraCollisionInfo *colInfo /*$t0*/, struct _Position *targetCamPos /*$a2*/)
 // line 5509, offset 0x8001d244
	/* begin block 1 */
		// Start line: 5510
		// Start offset: 0x8001D244
		// Variables:
	// 		static short toggle; // offset 0x60

		/* begin block 1.1 */
			// Start line: 5515
			// Start offset: 0x8001D258
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001D258
		// End Line: 5515

		/* begin block 1.2 */
			// Start line: 5519
			// Start offset: 0x8001D264
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001D284
		// End Line: 5519

		/* begin block 1.3 */
			// Start line: 5521
			// Start offset: 0x8001D284
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v1
		/* end block 1.3 */
		// End offset: 0x8001D284
		// End Line: 5521
	/* end block 1 */
	// End offset: 0x8001D2FC
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
    bVar1 = DAT_800d0400 == 0;
    colInfo->cldLines = 6;
    if (bVar1) {
      lVar5 = 0x16;
    }
    else {
      lVar5 = 0xe;
    }
  }
  colInfo->cldLines = lVar5;
  if (DAT_800d0400 != 0) {
    DAT_800d0400 = 0;
    return;
  }
  DAT_800d0400 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_DoPanicCheck(struct Camera *camera /*$s0*/, struct CameraCollisionInfo *tmpcolInfo /*$s1*/, struct _Rotation *rotation /*$s3*/, short *best_z /*$s4*/, short *max_dist /*stack 16*/)
 // line 5550, offset 0x8001d304
	/* begin block 1 */
		// Start line: 5551
		// Start offset: 0x8001D304
		// Variables:
	// 		struct _Position targetCamPos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 5551
			// Start offset: 0x8001D304
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001D304
		// End Line: 5551
	/* end block 1 */
	// End offset: 0x8001D3B4
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
 // line 5565, offset 0x8001d3d4
	/* begin block 1 */
		// Start line: 5566
		// Start offset: 0x8001D3D4
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
	// End offset: 0x8001D554
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
 // line 5619, offset 0x8001d584
	/* begin block 1 */
		// Start line: 5620
		// Start offset: 0x8001D584
		// Variables:
	// 		int secondcheck_flag; // $s0
	// 		long hit; // $s2
	// 		struct CameraCollisionInfo colInfo; // stack offset -120
	// 		static long collisiontimeDown; // offset 0x64

		/* begin block 1.1 */
			// Start line: 5710
			// Start offset: 0x8001D7C4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8001D7C4
		// End Line: 5710

		/* begin block 1.2 */
			// Start line: 5766
			// Start offset: 0x8001D910
			// Variables:
		// 		int speed; // $s0
		/* end block 1.2 */
		// End offset: 0x8001D9D8
		// End Line: 5786

		/* begin block 1.3 */
			// Start line: 5816
			// Start offset: 0x8001DA60
			// Variables:
		// 		int angle1; // $s0
		// 		int angle2; // $v0
		/* end block 1.3 */
		// End offset: 0x8001DB0C
		// End Line: 5832
	/* end block 1 */
	// End offset: 0x8001DB6C
	// End Line: 5871

	/* begin block 2 */
		// Start line: 12897
	/* end block 2 */
	// End Line: 12898

/* WARNING: Could not reconcile some variable overlaps */

long CAMERA_DoCameraCollision2(Camera *camera,_Position *targetCamPos,int simpleflag)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  short step;
  int iVar4;
  _TFace *p_Var5;
  int iVar6;
  int secondcheck_flag;
  long lVar7;
  undefined auStack120 [52];
  undefined auStack68 [12];
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  lVar7 = 0;
  CAMERA_SetupColInfo(camera,(CameraCollisionInfo *)auStack120,targetCamPos);
  secondcheck_flag = 0;
  if ((camera->flags & 0x10000U) == 0) {
    iVar6 = (int)(camera->real_focuspoint).z;
    secondcheck_flag = (int)(camera->targetFocusPoint).z;
    iVar4 = iVar6 - secondcheck_flag;
    if (iVar4 < 0) {
      iVar4 = secondcheck_flag - iVar6;
    }
    secondcheck_flag = 0;
    if (4 < iVar4) {
      secondcheck_flag = 1;
    }
  }
  p_Var5 = CAMERA_SphereToSphereWithLines(camera,(CameraCollisionInfo *)auStack120,secondcheck_flag)
  ;
  (camera->data).Follow.tface = p_Var5;
  if (((((camera->instance_mode & 0x2000000) != 0) && (0 < local_30)) && (local_2c < 600)) &&
     (((CenterFlag = -1, local_30 != 1 || ((local_38 & 6) == 0)) &&
      (step = combat_cam_weight + 0x90, combat_cam_weight < 0x1000)))) {
    combat_cam_weight = step;
    if (0xfff < step) {
      combat_cam_weight = 0x1000;
    }
    if (combat_cam_weight < 0xf3c) {
      CenterFlag = -1;
      return 1;
    }
  }
  if ((((camera->flags & 0x12000U) == 0) && (camera->instance_xyvel == 0)) &&
     ((((secondcheck_flag == 0 &&
        (((camera->always_rotate_flag == 0 && (camera->forced_movement == 0)) && (0 < local_30))))
       && ((local_30 == 4 || (camera_still != 0)))) && (local_2c < 400)))) {
    panic_count = panic_count + 1;
    if ((gameTrackerX.controlCommand[0][0] & 1U) == 0) {
      if (panic_count < 2) goto LAB_8001d7ac;
    }
    else {
      if (panic_count < 0xb) goto LAB_8001d7ac;
    }
    CAMERA_Panic(camera,(short)local_2c);
  }
  else {
    panic_count = 0;
  }
LAB_8001d7ac:
  if (((camera->data).Follow.tface != (_TFace *)0x0) && (secondcheck_flag != 0)) {
    step = (camera->targetFocusPoint).y;
    sVar2 = (camera->targetFocusPoint).z;
    (camera->focusSphere).position.x = (camera->targetFocusPoint).x;
    (camera->focusSphere).position.y = step;
    (camera->focusSphere).position.z = sVar2;
    p_Var5 = CAMERA_SphereToSphereWithLines(camera,(CameraCollisionInfo *)auStack120,0);
    (camera->data).Follow.tface = p_Var5;
  }
  if (simpleflag == 0) {
    if (0 < DAT_800d0404) {
      DAT_800d0404 = DAT_800d0404 + -1;
    }
    if (camera->always_rotate_flag != 0) {
      local_30 = 4;
    }
    if ((camera->flags & 0x10000U) == 0) {
      if (((camera->instance_mode & 0x24000000) == 0) &&
         ((((camera->flags & 0x2000U) == 0 || ((camera->instance_mode & 0x2000000) != 0)) &&
          (camera->always_rotate_flag == 0)))) {
        if ((camera->data).Follow.tface != (_TFace *)0x0) {
          lVar7 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
          DAT_800d0404 = 0x1e;
          (camera->targetFocusRotation).z = (camera->collisionTargetFocusRotation).z;
          return lVar7;
        }
        CAMERA_dampgetline(0);
        if ((camera->mode == 0xd) && (0 < camera->instance_xyvel)) {
          step = CAMERA_AngleDifference
                           ((camera->collisionTargetFocusRotation).z,(camera->focusRotation).z);
          if (step < 5) {
            bVar1 = DAT_800d0404 == 0;
            (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
            if (bVar1) {
              camera->collision_lastPush = 0;
            }
          }
          else {
            step = CAMERA_SignedAngleDifference
                             ((camera->collisionTargetFocusRotation).z,(camera->focusRotation).z);
            iVar4 = (int)step;
            step = CAMERA_SignedAngleDifference
                             ((camera->targetFocusRotation).z,(camera->focusRotation).z);
            secondcheck_flag = (int)step;
            if (((iVar4 < 0) && (secondcheck_flag < 0)) || ((0 < iVar4 && (0 < secondcheck_flag))))
            {
              if (secondcheck_flag < 0) {
                secondcheck_flag = -secondcheck_flag;
              }
              if (iVar4 < 0) {
                iVar4 = -iVar4;
              }
              if (iVar4 < secondcheck_flag) {
                (camera->collisionTargetFocusRotation).z = (camera->targetFocusRotation).z;
              }
            }
          }
        }
        else {
          if (DAT_800d0404 == 0) {
            Decouple_AngleMoveToward
                      (&(camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z,
                       0x40);
            camera->collision_lastPush = 0;
          }
        }
        if ((camera->instance_mode & 0x2000000) == 0) {
          camera->collisionTargetFocusDistance = camera->targetFocusDistance;
          return 0;
        }
        DAT_800d0404 = 0;
        camera->collisionTargetFocusDistance = combat_cam_distance;
        return 0;
      }
    }
    if ((camera->data).Follow.tface == (_TFace *)0x0) {
      camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    }
    else {
      lVar7 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
      DAT_800d0404 = 0x1e;
    }
    if ((camera->flags & 0x10000U) == 0) {
      Decouple_AngleMoveToward
                (&(camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z,0x40);
      return lVar7;
    }
    uVar3 = AngleDiff((camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z);
    if ((int)((uint)uVar3 << 0x10) < 0) {
      step = AngleDiff((camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z);
      secondcheck_flag = -(int)step;
    }
    else {
      step = AngleDiff((camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z);
      secondcheck_flag = (int)step;
    }
    if ((local_38 & 6) == 0) {
      CAMERA_dampgetline(0);
    }
    if ((secondcheck_flag < 0x400) || ((local_38 & 6) != 0)) {
      if (secondcheck_flag < 0) {
        secondcheck_flag = secondcheck_flag + 0xf;
      }
      secondcheck_flag = secondcheck_flag >> 4;
      step = (short)secondcheck_flag;
      if (secondcheck_flag < 8) {
        step = 8;
      }
      if (0x20 < secondcheck_flag) {
        step = 0x20;
      }
    }
    else {
      step = 0x40;
    }
    Decouple_AngleMoveToward
              (&(camera->collisionTargetFocusRotation).z,(camera->targetFocusRotation).z,step);
    return lVar7;
  }
  if ((camera->data).Follow.tface == (_TFace *)0x0) {
    return 0;
  }
  step = camera->mode;
  if (((step != 4) && (step != 2)) && (step != 6)) {
    return 1;
  }
  camera->collisionTargetFocusDistance = *(short *)(auStack120 + local_34 * 2 + 0x34);
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CAMERA_FocusInstanceMoved(struct Camera *camera /*$a0*/)
 // line 5876, offset 0x8001db88
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





