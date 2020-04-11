
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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 262, offset 0x80014a5c
	/* begin block 1 */
		// Start line: 551
	/* end block 1 */
	// End Line: 552

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CalcVVClipInfo(Camera *camera)

{
  long lVar1;
  undefined4 in_zero;
  undefined4 in_at;
  MATRIX *v1;
  MATRIX *v1_00;
  
  v1_00 = (camera->core).vvNormalWorVecMat;
  ApplyMatrixSV((camera->core).cwTransform2,(SVECTOR *)(camera->core).viewVolumeNormal,
                (SVECTOR *)v1_00);
  ApplyMatrixSV((camera->core).cwTransform2,(SVECTOR *)((camera->core).viewVolumeNormal + 1),
                (SVECTOR *)((camera->core).vvNormalWorVecMat[0].m + 3));
  ApplyMatrixSV((camera->core).cwTransform2,(SVECTOR *)((camera->core).viewVolumeNormal + 2),
                (SVECTOR *)((camera->core).vvNormalWorVecMat[0].m + 6));
  v1 = (camera->core).vvNormalWorVecMat + 1;
  ApplyMatrixSV((camera->core).cwTransform2,(SVECTOR *)((camera->core).viewVolumeNormal + 3),
                (SVECTOR *)v1);
  ApplyMatrixSV((camera->core).cwTransform2,(SVECTOR *)((camera->core).viewVolumeNormal + 4),
                (SVECTOR *)((camera->core).vvNormalWorVecMat[1].m + 3));
  setCopControlWord(2,0,*(undefined4 *)v1_00->m);
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
  setCopControlWord(2,0,*(undefined4 *)v1->m);
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
 // line 273, offset 0x80014b7c
	/* begin block 1 */
		// Start line: 575
	/* end block 1 */
	// End Line: 576

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_SetProjDistance(Camera *camera,long distance)

{
  Level *level;
  undefined4 *puVar1;
  int iVar2;
  
  SetGeomScreen(distance);
  (camera->core).projDistance = distance;
  CAMERA_CalculateViewVolumeNormals(camera);
  iVar2 = 0;
  puVar1 = &StreamTracker;
  do {
    if (*(short *)(puVar1 + 1) == 2) {
      level = (Level *)puVar1[2];
      SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,(camera->core).projDistance);
      LIGHT_CalcDQPTable(level);
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 0x10;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
    camera->savedCinematic[camera->stack].level = DAT_800d20f4;
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

/* File: C:\kain2\game\CAMERA.C */

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
      Inst = DAT_800d20f8;
      if (camera->mode == 5) {
        (camera->focusOffset).x = 0;
        (camera->focusOffset).y = 0;
        (camera->focusOffset).z = 0x160;
        camera->focusInstance = Inst;
        CAMERA_Restore(camera,7);
      }
      if (iVar7 == 0xc) {
        DAT_800d220c = DAT_800d220c & 0xffffffbf;
      }
      else {
        DAT_800d220c = DAT_800d220c | 0x40;
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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 523, offset 0x800155a8
	/* begin block 1 */
		// Start line: 1131
	/* end block 1 */
	// End Line: 1132

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

_SVector * SplineGetNextPointDC(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetNext(spline,def,DAT_800d2314);
  if ((uVar1 != 0) && (uVar1 = SplineGetData(spline,def,&point_42), uVar1 != 0)) {
    return (_SVector *)&point_42;
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

/* File: C:\kain2\game\CAMERA.C */

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
  if (((int)sVar1 == mode) && (mode - 0xcU < 2)) {
    return;
  }
  switch(camera->mode) {
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
    if (mode == 0xf) break;
  case 2:
  case 4:
    CAMERA_SaveMode(camera,(int)camera->mode);
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
        CAMERA_CalcPosition((_Position *)&_Stack40,&camera->targetFocusPoint,
                            (_Rotation *)&splinecam_helprot,camera->targetFocusDistance);
        local_20[0] = SplineGetNearestPoint
                                (((camera->data).Cinematic.posSpline)->positional,&_Stack40,
                                 &local_38);
        CAMERA_CalcRotation((_Rotation *)&splinecam_helprot,&camera->focusInstance->position,
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
    DAT_800d220c = DAT_800d220c & 0xffffffbf;
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
  *(undefined4 *)&camera->collisionTargetFocusRotation = *(undefined4 *)&camera->targetFocusRotation
  ;
  *(undefined4 *)&(camera->collisionTargetFocusRotation).z = uVar9;
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_Initialize(Camera *camera)

{
  _CameraCore_Type *p_Var1;
  long mode;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  memset();
  iVar4 = 0;
  do {
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    camera_shakeOffset[iVar4].x = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    camera_shakeOffset[iVar4].y = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
    iVar2 = rand();
    iVar2._1_2_ = (short)((uint)iVar2 >> 8);
    if (iVar2 < 0) {
      iVar2._1_2_ = (short)((uint)(iVar2 + 0xff) >> 8);
    }
    camera_shakeOffset[iVar4].z = (short)iVar2 + iVar2._1_2_ * -0x100 + -0x80;
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
  mode = playerCameraMode;
  iVar4 = 2;
  camera->presetIndex = 1;
  camera->mode = 0;
  CAMERA_SetMode(camera,mode);
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
  Camera_lookHeight = 0x200;
  Camera_lookDist = 0x28a;
  CameraCenterDelay = 10;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
    if (instance == DAT_800d20f8) {
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
    DAT_800d220c = DAT_800d220c & 0xffffff7f;
  }
  else {
    DAT_800d220c = DAT_800d220c | 0x80;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

short CAMERA_SignedAngleDifference(short angle0,short angle1)

{
  short sVar1;
  
  sVar1 = AngleDiff(angle1,angle0);
  return sVar1;
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

/* File: C:\kain2\game\CAMERA.C */

ulong CAMERA_QueryMode(Camera *camera)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = INSTANCE_Query(camera->focusInstance,10);
  if (camera->focusInstance == DAT_800d20f8) {
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
  MATH3D_SetUnityMatrix((char)(MATRIX *)&local_48);
  RotMatrixX((int)rotation->x,(MATRIX *)&local_48);
  RotMatrixY((int)rotation->y,(MATRIX *)&local_48);
  RotMatrixZ((int)rotation->z,(MATRIX *)&local_48);
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_SetFocus(Camera *camera,_Position *targetfocusPoint)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _Segment *p_Var4;
  ulong uVar5;
  _Instance *Inst;
  SVECTOR local_40;
  _SVector local_38;
  VECTOR VStack48;
  SVECTOR local_20;
  
  Inst = camera->focusInstance;
  if (((camera->flags & 0x10000U) != 0) || ((camera->instance_mode & 0x4000000) != 0)) {
    p_Var4 = Inst->object->modelList[Inst->currentModel]->segmentList;
    local_40.vx = p_Var4[1].px;
    local_40.vy = p_Var4[1].py;
    local_40.vz = p_Var4[1].pz;
    ApplyMatrix(Inst->matrix + 1,&local_40,&VStack48);
    sVar1 = (Inst->position).x;
    sVar2 = (Inst->position).y;
    sVar3 = (Inst->position).z;
    targetfocusPoint->x = sVar1;
    targetfocusPoint->y = sVar2;
    targetfocusPoint->z = sVar3;
    if ((camera->flags & 0x10000U) != 0) {
      targetfocusPoint->x = sVar1 + local_40.vx;
      targetfocusPoint->y = targetfocusPoint->y + local_40.vy;
      targetfocusPoint->z = sVar3 + local_40.vz;
      uVar5 = INSTANCE_Query(Inst,9);
      if ((uVar5 & 0x40) != 0) {
        targetfocusPoint->z = targetfocusPoint->z + 0xc0;
      }
    }
    sVar1 = targetfocusPoint->z;
    *(undefined4 *)&camera->real_focuspoint = *(undefined4 *)targetfocusPoint;
    (camera->real_focuspoint).z = sVar1;
    goto LAB_80016998;
  }
  if (((camera->instance_mode & 0x2000000) == 0) || (1 < (uint)(ushort)camera->mode - 0xc)) {
LAB_800168f8:
    sVar1 = (Inst->position).y;
    sVar2 = (Inst->position).z;
    targetfocusPoint->x = (Inst->position).x;
    targetfocusPoint->y = sVar1;
    targetfocusPoint->z = sVar2;
  }
  else {
    uVar5 = INSTANCE_Query(Inst,0x22);
    if (uVar5 == 0) goto LAB_800168f8;
    LoadAverageShort12((SVECTOR *)(uVar5 + 0x5c),(SVECTOR *)&Inst->position,
                       0x1000 - (int)combat_cam_weight,(int)combat_cam_weight,&local_20);
    targetfocusPoint->x = local_20.vx;
    targetfocusPoint->y = local_20.vy;
    targetfocusPoint->z = local_20.vz;
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
LAB_80016998:
  camera->focuspoint_fallz = targetfocusPoint->z;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 1485, offset 0x80016b14
	/* begin block 1 */
		// Start line: 3480
	/* end block 1 */
	// End Line: 3481

/* File: C:\kain2\game\CAMERA.C */

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
    uVar1 = DAT_800d21f8;
    camera->always_rotate_flag = 1;
    camera->lastModTime = uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CAMERA_Adjust_roll(long roll_degrees /*$s0*/, int frames /*$s1*/)
 // line 1504, offset 0x80016b98
	/* begin block 1 */
		// Start line: 3526
	/* end block 1 */
	// End Line: 3527

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 1583, offset 0x80016cdc
	/* begin block 1 */
		// Start line: 3686
	/* end block 1 */
	// End Line: 3687

	/* begin block 2 */
		// Start line: 3687
	/* end block 2 */
	// End Line: 3688

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 1611, offset 0x80016d94
	/* begin block 1 */
		// Start line: 3742
	/* end block 1 */
	// End Line: 3743

/* File: C:\kain2\game\CAMERA.C */

void Decouple_AngleMoveToward(short *current_ptr,short destination,short step)

{
  if (DAT_800d2314 != 0x1000) {
    step = (short)((uint)(step * DAT_800d2314) >> 0xc);
  }
  AngleMoveToward(current_ptr,destination,step);
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
      if (DAT_800d2314 != 0x1000) {
        sVar3 = (short)((uint)(iVar6 * DAT_800d2314) >> 0xc);
      }
    }
    else {
      if (iVar5 < -iVar6) {
        *vel = -(short)smooth;
        sVar3 = -(short)smooth;
        if (DAT_800d2314 != 0x1000) {
          sVar3 = (short)((uint)-(iVar6 * DAT_800d2314) >> 0xc);
        }
      }
    }
    sVar3 = *sourceVal + sVar3;
  }
  else {
    if (1 < dampMode) {
      if ((6 < dampMode) || (dampMode < 5)) goto LAB_80016f74;
      goto LAB_80016e8c;
    }
    if (dampMode != 0) goto LAB_80016f74;
    sVar3 = (short)((int)(((uint)(ushort)targetVal - (uint)(ushort)*sourceVal) * 0x10000) >> 0x12) -
            *vel;
    *accl = sVar3;
    sVar3 = *vel + sVar3;
    *vel = sVar3;
    sVar3 = *sourceVal + sVar3;
  }
  *sourceVal = sVar3;
LAB_80016f74:
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

/* File: C:\kain2\game\CAMERA.C */

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
LAB_80017624:
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
    if (DAT_800d2314 == 0x1000) break;
    position->x = position->x + (short)((uint)(vel->x * DAT_800d2314) >> 0xc);
    position->y = position->y + (short)((uint)(vel->y * DAT_800d2314) >> 0xc);
    sVar6 = position->z;
    sVar5 = (short)((uint)(vel->z * DAT_800d2314) >> 0xc);
    goto code_r0x80017618;
  default:
    goto switchD_8001700c_caseD_2;
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
    goto LAB_80017624;
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
    if (lVar4 < lVar3) goto LAB_80017624;
    iVar7 = (int)(short)smooth;
    if (iVar7 <= lVar3) {
      vel->x = (short)((vel->x * iVar7) / lVar3);
      vel->y = (short)((vel->y * iVar7) / lVar3);
      vel->z = (short)((vel->z * iVar7) / lVar3);
      if (DAT_800d2314 != 0x1000) {
        position->x = position->x + (short)((uint)(vel->x * DAT_800d2314) >> 0xc);
        position->y = position->y + (short)((uint)(vel->y * DAT_800d2314) >> 0xc);
        sVar6 = position->z;
        sVar5 = (short)((uint)(vel->z * DAT_800d2314) >> 0xc);
        goto code_r0x80017618;
      }
    }
  }
  position->x = position->x + vel->x;
  position->y = position->y + vel->y;
  sVar6 = position->z;
  sVar5 = vel->z;
code_r0x80017618:
  position->z = sVar6 + sVar5;
switchD_8001700c_caseD_2:
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

short CAMERA_CalcZRotation(_Position *target,_Position *position)

{
  short sVar1;
  long lVar2;
  short sVar3;
  _SVector local_10;
  
  sVar3 = position->x - target->x;
  sVar1 = position->y - target->y;
  local_10.z = 0;
  local_10.x = sVar3;
  local_10.y = sVar1;
  CAMERA_LengthSVector(&local_10);
  lVar2 = ratan2((int)sVar1,(int)sVar3);
  return (short)((short)lVar2 + 0x400U & 0xfff);
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CalcRotation(_Rotation *rotation,_Position *target,_Position *position)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long x;
  short sVar4;
  _SVector local_10;
  
  sVar1 = position->z;
  sVar2 = target->z;
  sVar4 = position->x - target->x;
  sVar3 = position->y - target->y;
  local_10.z = 0;
  local_10.x = sVar4;
  local_10.y = sVar3;
  x = CAMERA_LengthSVector(&local_10);
  x = ratan2((int)(short)(sVar1 - sVar2),x);
  rotation->x = -(short)x;
  rotation->y = 0;
  x = ratan2((int)sVar3,(int)sVar4);
  rotation->z = (short)x + 0x400;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CalcFSRotation(Camera *camera,_Rotation *rotation,_Position *target,_Position *position)

{
  long x;
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
  x = CAMERA_LengthSVector(&local_18);
  x = ratan2((int)local_c,x);
  rotation->x = -(short)x;
  rotation->y = 0;
  x = ratan2((int)local_e,(int)local_10);
  rotation->z = (short)x + 0x400;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
  SVECTOR local_100;
  short local_f8 [2];
  short local_f4;
  short local_f0;
  SVECTOR local_e8;
  short local_e0 [2];
  short local_dc;
  short local_d8;
  VECTOR local_d0;
  _Rotation local_c0;
  MATRIX MStack184;
  VECTOR local_98;
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
  local_100.vx = 0;
  local_100.vz = 0;
  local_e8.vx = 0;
  local_e8.vz = 0;
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
  MATH3D_SetUnityMatrix((char)&MStack184);
  RotMatrixZ((int)local_c0.z + 0x400,&MStack184);
  if ((((camera->flags & 0x10000U) == 0) && ((camera->instance_mode & 0x4000000) == 0)) &&
     (camera->mode != 6)) {
    local_100.vy = 0x1000;
    ApplyMatrix(&MStack184,&local_100,&local_98);
    ACE_amount = local_98.vx * (camera->focusInstanceVelVec).x +
                 local_98.vy * (camera->focusInstanceVelVec).y +
                 local_98.vz * (camera->focusInstanceVelVec).z >> 0xc;
    if ((camera->always_rotate_flag != 0) || (camera->forced_movement != 0)) {
      if (camera->forced_movement == 0) {
        iVar9 = -0x48;
        uVar2 = CAMERA_SignedAngleDifference
                          ((camera->focusRotation).z,(camera->targetFocusRotation).z);
        if ((int)((uint)uVar2 << 0x10) < 0) goto LAB_80017c58;
      }
      else {
        if (camera->rotDirection < 1) {
          if (camera->rotDirection < 0) {
            iVar9 = -0x48;
          }
        }
        else {
LAB_80017c58:
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
  local_e8.vy = 0x122;
  local_100.vy = (short)ACE_amount;
  if (ACE_amount < 1) {
    local_100.vy = local_100.vy * -2;
  }
  else {
    local_e8.vy = local_100.vy * 5 + (short)(ACE_amount / 2) + 0x122;
  }
  local_100.vy = local_100.vy + 0x20;
  if (0 < iVar9) {
    local_e8.vy = local_e8.vy + (short)iVar9 * 5;
  }
  ApplyMatrix(&MStack184,&local_100,(VECTOR *)local_f8);
  ApplyMatrix(&MStack184,&local_e8,(VECTOR *)local_e0);
  p_Var7 = colInfo->start;
  local_148.x = (p_Var7->position).x + local_f8[0];
  local_148.y = (p_Var7->position).y + local_f4;
  local_148.z = (p_Var7->position).z + local_f0;
  p_Var7 = colInfo->end;
  local_120.x = (p_Var7->position).x + local_e0[0];
  local_120.y = (p_Var7->position).y + local_dc;
  local_120.z = (p_Var7->position).z + local_d8;
  local_e8.vy = 0x122;
  local_100.vy = (short)ACE_amount;
  if (ACE_amount < 0) {
    local_e8.vy = 0x122 - (local_100.vy * 5 + (short)(ACE_amount / 2));
    local_100.vy = -local_100.vy;
  }
  else {
    local_100.vy = local_100.vy * 2;
  }
  local_100.vy = local_100.vy + 0x20;
  if (iVar9 < 0) {
    local_e8.vy = local_e8.vy + (short)iVar9 * -5;
  }
  ApplyMatrix(&MStack184,&local_100,(VECTOR *)local_f8);
  ApplyMatrix(&MStack184,&local_e8,(VECTOR *)local_e0);
  p_Var7 = colInfo->start;
  local_140.x = (p_Var7->position).x - local_f8[0];
  local_140.y = (p_Var7->position).y - local_f4;
  local_140.z = (p_Var7->position).z - local_f0;
  p_Var7 = colInfo->end;
  local_118.x = (p_Var7->position).x - local_e0[0];
  local_118.y = (p_Var7->position).y - local_dc;
  local_118.z = (p_Var7->position).z - local_d8;
  local_e8.vy = 0xb4;
  local_100.vy = 0x20;
  MATH3D_SetUnityMatrix((char)&MStack184);
  RotMatrixX((int)local_c0.x + 0x400,&MStack184);
  RotMatrixZ((int)local_c0.z,&MStack184);
  ApplyMatrix(&MStack184,&local_100,(VECTOR *)local_f8);
  ApplyMatrix(&MStack184,&local_e8,(VECTOR *)local_e0);
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
  local_100.vy = 0x1000;
  left_point.x = local_140.x + (camera->focusInstanceVelVec).x;
  left_point.y = local_140.y + (camera->focusInstanceVelVec).y;
  left_point.z = local_140.z + (camera->focusInstanceVelVec).z;
  ApplyMatrix(&MStack184,&local_100,(VECTOR *)local_f8);
  local_100.vy = 0;
  local_100.vz = 0x1000;
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
                         (local_34->terrain,&_Stack120,Flags,local_48,(long)&DAT_000010d0,0x20,
                          (_LCollideInfo *)auStack136);
      *(_TFace **)pCVar13->tfaceList = p_Var5;
      *(_Terrain **)pCVar13->tfaceTerrain = local_34->terrain;
      if (pCVar13->tfaceList[0] == (_func_18 *)0x0) {
        iVar9 = 0;
        puVar8 = &DAT_800d2a12;
        do {
          address = *(Level **)(puVar8 + 1);
          if ((((puVar8[-1] == 2) && (address != local_34)) &&
              (lVar3 = MEMPACK_MemoryValidFunc((char *)address), lVar3 != 0)) &&
             ((local_30 == 0 || ((*puVar8 & 1) == 0)))) {
            p_Var5 = COLLIDE_PointAndTerrainFunc
                               (address->terrain,&_Stack120,Flags,local_48,(long)&DAT_000010d0,0x20,
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
             (short)((iVar9 * 0x10000 >> 0x10) * local_d0.vx + local_156 * local_d0.vy +
                     local_154 * local_d0.vz >> 0xc);
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
        iVar9 = (iVar9 * 0x10000 >> 0x10) * local_d0.vx + local_156 * local_d0.vy +
                local_154 * local_d0.vz >> 0xc;
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
        goto LAB_80018510;
      }
      if ((colInfo->flags & 2U) == 0) {
        return local_40;
      }
    }
    target = &local_148;
    position = &local_120;
  }
LAB_80018510:
  hitline_rot = CAMERA_CalcZRotation(target,position);
  return local_40;
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

/* File: C:\kain2\game\CAMERA.C */

long CAMERA_CalcTilt(_Normal *normal,short zRot)

{
  long lVar1;
  MATRIX MStack64;
  VECTOR VStack32;
  
  MATH3D_SetUnityMatrix(0xc0);
  RotMatrixZ(-(int)zRot,&MStack64);
  ApplyMatrix(&MStack64,(SVECTOR *)normal,&VStack32);
  lVar1 = ratan2(VStack32.vy,VStack32.vz);
  return -(int)(short)lVar1;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_SetLookFocusAndDistance(Camera *camera,undefined focuspoint,int distance)

{
  undefined3 in_register_00000015;
  short *psVar1;
  
  psVar1 = (short *)CONCAT31(in_register_00000015,focuspoint);
  (camera->targetFocusPoint).x = *psVar1;
  (camera->targetFocusPoint).y = psVar1[2];
  Camera_lookDist = (short)distance;
  (camera->targetFocusPoint).z = psVar1[4];
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

/* File: C:\kain2\game\CAMERA.C */

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
  if (((camera->instance_mode & 0x20000) != 0) && (distance < 400)) {
    distance = 400;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CalcFocusOffsetForSwim(_SVector *offset,Camera *camera)

{
  short local_20 [2];
  short local_1c;
  short local_18;
  SVECTOR local_10;
  
  local_10.vx = (camera->focusOffset).x;
  local_10.vy = (camera->focusOffset).y;
  local_10.vz = (camera->focusOffset).z;
  ApplyMatrix(camera->focusInstance->matrix + 1,&local_10,(VECTOR *)local_20);
  offset->x = local_20[0];
  offset->y = local_1c;
  offset->z = local_18;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 2828, offset 0x80018f60
	/* begin block 1 */
		// Start line: 6945
	/* end block 1 */
	// End Line: 6946

	/* begin block 2 */
		// Start line: 6946
	/* end block 2 */
	// End Line: 6947

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

short CAMERA_dampgetline(short angle)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)angle;
  CriticalDampAngle(1,&DAT_800cf160,angle,(short *)&DAT_800cf162,(short *)&DAT_800cf164,0x400);
  if (0x800 < DAT_800cf160) {
    DAT_800cf160 = DAT_800cf160 + -0x1000;
  }
  iVar1 = (int)DAT_800cf160;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x20) {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = -iVar2;
    }
    if ((0x1f < iVar1) && (DAT_800cf160 = 0x20, iVar2 < 0)) {
      DAT_800cf160 = -0x20;
    }
  }
  return DAT_800cf160;
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

/* File: C:\kain2\game\CAMERA.C */

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
      dist = CAMERA_GetLineAngle(camera,colInfo,(_SVector *)&left_point,2);
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
      dist = CAMERA_GetLineAngle(camera,colInfo,(_SVector *)&right_point,1);
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

/* File: C:\kain2\game\CAMERA.C */

long CAMERA_AbsoluteCollision(Camera *camera,CameraCollisionInfo *colInfo)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  
  if ((DAT_800d218c & 0x10000) != 0) {
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

/* File: C:\kain2\game\CAMERA.C */

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
  iVar1 = iVar3 - iVar4;
  if (iVar1 < 0) {
    iVar1 = iVar4 - iVar3;
  }
  if (iVar1 < 5) {
    DAT_800cf166 = 0;
    DAT_800cf168 = 0;
    DAT_800cf16a = 0;
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
  local_10[0] = current;
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CombatCamDist(Camera *camera)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
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
  SetRotMatrix((camera->core).wcTransform);
  SetTransMatrix((camera->core).wcTransform);
  local_20 = CONCAT22((camera->focusInstance->position).y,(camera->focusInstance->position).x);
  uVar2 = local_1c & 0xffff0000;
  local_1c = uVar2 | (ushort)(camera->focusInstance->position).z;
  setCopReg(2,in_zero,local_20);
  setCopReg(2,in_at,local_1c);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  iVar7 = getCopReg(2,0x13);
  local_30 = (short)uVar1;
  iVar5 = (int)local_30 + -0x100;
  if ((int)local_30 < 0x100) {
    iVar5 = iVar5 * iVar7;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0x7f;
    }
    combat_cam_distance = -(short)(iVar5 >> 7);
  }
  else {
    iVar5 = iVar5 * iVar7;
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
    if (0xd1 < sStack46) goto LAB_80019af4;
    combat_cam_weight = combat_cam_weight + -0x30;
    sVar3 = 0x800;
    if (0x7ff < combat_cam_weight) goto LAB_80019af4;
  }
  else {
    combat_cam_weight = combat_cam_weight + 0x30;
    sVar3 = 0x1000;
    if (combat_cam_weight < 0x1001) goto LAB_80019af4;
  }
  combat_cam_weight = sVar3;
LAB_80019af4:
  local_1c = uVar2 | *(ushort *)(uVar4 + 0x60);
  setCopReg(2,in_zero,*(undefined4 *)(uVar4 + 0x5c));
  setCopReg(2,in_at,local_1c);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  sStack38 = (short)((uint)uVar1 >> 0x10);
  local_28 = (short)uVar1;
  lVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
  if (lVar6 < 0) {
    lVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
    combat_cam_angle = -(short)lVar6;
  }
  else {
    lVar6 = ratan2((int)sStack38 - (int)sStack46,(int)local_28 - (int)local_30);
    combat_cam_angle = (short)lVar6;
  }
  if (0x400 < combat_cam_angle) {
    combat_cam_angle = 0x800 - combat_cam_angle;
  }
  iVar7 = (int)combat_cam_angle;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 7;
  }
  combat_cam_angle = -0xaa - (short)(iVar7 >> 3);
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
       (((camera->instance_mode & 0x2000) == 0 && (DAT_800d2297 != '\x01')))) {
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
        goto LAB_80019ed4;
      }
    }
    else {
      if ((uVar5 & 0x2000000) != 0) goto LAB_80019ed4;
      (camera->rotationVel).z = 0x40;
    }
    CAMERA_FollowGoBehindPlayer(camera);
  }
LAB_80019ed4:
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_NearestPointOnLineVec
               (_SVector *linePoint,_SVector *start,_SVector *line,_Position *point)

{
  int iVar1;
  MATRIX local_40;
  VECTOR local_20;
  
  local_40.m[0][0] = line->x;
  local_40.m[0][1] = line->y;
  local_40.m[0][2] = line->z;
  local_40.m[1][0] = start->x;
  local_40.m[1][1] = start->y;
  local_40.m[1][2] = start->z;
  local_40.m[2][0] = point->x;
  local_40.m[2][1] = point->y;
  local_40.m[2][2] = point->z;
  ApplyMatrix(&local_40,(SVECTOR *)line,&local_20);
  iVar1 = (local_20.vy - local_20.vz) * 0x1000;
  if (local_20.vx != 0) {
    iVar1 = ((local_20.vy - local_20.vz) * -0x1000) / local_20.vx;
  }
  linePoint->x = start->x + (short)(line->x * iVar1 >> 0xc);
  linePoint->y = start->y + (short)(line->y * iVar1 >> 0xc);
  linePoint->z = start->z + (short)(line->z * iVar1 >> 0xc);
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\CAMERA.C */

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
LAB_8001ae04:
    if (iVar9 == -1) {
      iVar3 = -1;
LAB_8001ae54:
      if ((iVar2 - 1U < 0xfff) &&
         (iVar4 = CAMERA_GetDistSq((_SVector *)&local_58,point), iVar4 < iVar5)) {
        *currkey = iVar7;
        goto LAB_8001ae7c;
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
      if (0 < iVar4) goto LAB_8001ae54;
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
    if (iVar4 < 0x1000) goto LAB_8001ae04;
    *currkey = iVar7;
LAB_8001ae7c:
    *(uint *)ret_dpoint = local_58;
    *(undefined4 *)&ret_dpoint->z = local_54;
  }
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
  CAMERA_CalcPosition((_Position *)&_Stack40,&camera->targetFocusPoint,
                      (_Rotation *)&splinecam_helprot,camera->targetFocusDistance);
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

/* File: C:\kain2\game\CAMERA.C */

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
      DAT_800cf16c = 1;
    }
    else {
      smooth = CAMERA_FocusInstanceMoved(camera);
      if (smooth != 0) {
        if (DAT_800cf16c != 0) {
          camera->always_rotate_flag = 1;
        }
        DAT_800cf16c = 0;
      }
    }
    if (((camera->forced_movement != 1) && (DAT_800cf16c == 0)) && (camera->rotState != 3)) {
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
    if (((camera->forced_movement == 1) || (camera->always_rotate_flag != 0)) || (DAT_800cf16c != 0)
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
 // line 4193, offset 0x8001b418
	/* begin block 1 */
		// Start line: 9936
	/* end block 1 */
	// End Line: 9937

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_ShakeCamera(Camera *camera)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if (0 < camera->shake) {
    uVar1 = camera->shakeFrame;
    (camera->core).position.x =
         (camera->core).position.x +
         (short)((int)camera_shakeOffset[(uint)(ushort)camera->shakeFrame & 0xf].x *
                 (int)camera->shakeScale >> 0xc);
    uVar2 = camera->shakeFrame;
    (camera->core).position.y =
         (camera->core).position.y +
         (short)((int)camera_shakeOffset[(uint)uVar1 & 0xf].y * (int)camera->shakeScale >> 0xc);
    (camera->core).position.z =
         (camera->core).position.z +
         (short)((int)camera_shakeOffset[(uint)uVar2 & 0xf].z * (int)camera->shakeScale >> 0xc);
    iVar3 = camera->shake - DAT_800d2314;
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

/* File: C:\kain2\game\CAMERA.C */

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
                    /* WARNING: Could not recover jumptable at 0x8001b6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_800100d8)[uVar9])();
    return;
  }
  camera->flags = camera->flags & 0xffffe7ff;
  CAMERA_ShakeCamera(camera);
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 4429, offset 0x8001b838
	/* begin block 1 */
		// Start line: 8853
	/* end block 1 */
	// End Line: 8854

	/* begin block 2 */
		// Start line: 10412
	/* end block 2 */
	// End Line: 10413

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 4453, offset 0x8001b8d4
	/* begin block 1 */
		// Start line: 10469
	/* end block 1 */
	// End Line: 10470

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
  if ((DAT_800d2210 & 0x100000) == 0) {
    bVar1 = true;
    if (CameraLookStickyFlag == 0) {
      bVar1 = (DAT_800d2114 & 0xc00) == 0xc00;
    }
    camera->last_forced_movement = camera->forced_movement;
    if (((camera->instance_xyvel != 0) || (camera->forced_movement != 1)) ||
       ((camera->instance_mode & 0x2000000) != 0)) {
      camera->forced_movement = 0;
    }
    sVar3 = camera->mode;
    if ((sVar3 != 8) && (-1 < (int)camera->instance_mode)) {
      if (CenterFlag == -1) {
        if ((DAT_800d2297 != '\x01') || ((DAT_800d2114 & 0xf) == 0)) {
          if ((((camera->lock & 4U) == 0) && ((camera->flags & 0x10000U) == 0)) &&
             (((((sVar3 == 0 || (sVar3 == 0xc)) || (sVar3 == 4)) || (sVar3 == 0xd)) &&
              ((playerInstance->flags & 0x100U) == 0)))) {
            if (((DAT_800d2114 & 0x400) == 0) || (bVar1)) {
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
                uVar5 = (camera->focusRotation).z - (short)((uint)(DAT_800d2314 << 5) >> 0xc) &
                        0xfff;
                (camera->focusRotation).z = uVar5;
                uVar2 = DAT_800d21f8;
                camera->forced_movement = 1;
                (camera->data).Follow.stopTimer = -0x1a5e0000;
                (camera->focusRotation).z = uVar5;
                (camera->collisionTargetFocusRotation).z = uVar5;
                (camera->targetFocusRotation).z = uVar5;
                camera->lastModTime = uVar2;
              }
            }
            if (((DAT_800d2114 & 0x800) == 0) || (bVar1)) {
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
                uVar5 = (camera->focusRotation).z + (short)((uint)(DAT_800d2314 << 5) >> 0xc) &
                        0xfff;
                (camera->focusRotation).z = uVar5;
                uVar2 = DAT_800d21f8;
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
          if ((DAT_800d2190 & 0x2000000) != 0) {
            if ((camera->lock & 1U) == 0) {
              if (((DAT_800d2114 & 0x40000008) == 0x40000008) &&
                 (sVar3 = camera->targetFocusDistance + -0x14, camera->targetFocusDistance = sVar3,
                 sVar3 < 200)) {
                camera->targetFocusDistance = 200;
              }
              if (((DAT_800d2114 & 0x40000004) == 0x40000004) &&
                 (sVar3 = camera->targetFocusDistance + 0x14, camera->targetFocusDistance = sVar3,
                 0x1000 < sVar3)) {
                camera->targetFocusDistance = 0x1000;
              }
            }
            if ((camera->lock & 2U) == 0) {
              if ((DAT_800d2114 & 0x40000002) == 0x40000002) {
                camera->extraXRot = camera->extraXRot + 0x10;
              }
              if ((DAT_800d2114 & 0x40000001) == 0x40000001) {
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
                                  (GameTracker *)&gameTrackerX);
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
 // line 4801, offset 0x8001c030
	/* begin block 1 */
		// Start line: 11236
	/* end block 1 */
	// End Line: 11237

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
    if (DAT_800d2314 != 0x1000) {
      if (roll_inc < 0) {
        iVar2 = roll_inc + 0x1f;
      }
      iVar6 = (iVar2 >> 5) * DAT_800d2314;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_UpdateFocusRotationX(Camera *camera,_Instance *focusInstance)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  _TFace *p_Var4;
  ushort uVar5;
  int local_1c;
  short target;
  _Normal _Stack24;
  
  p_Var4 = focusInstance->tface;
  target = camera->targetFocusDistance;
  if ((((p_Var4 == (_TFace *)0x0) || (local_1c = *(int *)focusInstance->tfaceLevel, local_1c == 0))
      || (p_Var4->textoff == 0xffff)) ||
     (((*(ushort *)(*(int *)(local_1c + 0x34) + (uint)p_Var4->textoff + 10) & 0x8000) == 0 ||
      (0xb5f < target)))) {
    local_1c = 0x18;
    if ((camera->instance_mode & 0x38) == 0) {
      camera->targetTilt = 0;
    }
    if (((camera->instance_mode & 0x2000) != 0) &&
       ((camera->real_focuspoint).z < camera->focuspoint_fallz)) {
      camera->targetTilt = -0x180;
      local_1c = 0xc;
    }
    target = camera->targetTilt;
  }
  else {
    COLLIDE_GetNormal(p_Var4->normal,*(short **)(local_1c + 0x24),(_SVector *)&_Stack24);
    if (_Stack24.z < 0xffa) {
      lVar2 = CAMERA_CalcTilt(&_Stack24,(camera->focusRotation).z);
      local_1c = lVar2 * 9;
      if (local_1c < 0) {
        local_1c = local_1c + 0xf;
      }
      sVar1 = (short)(local_1c >> 4);
      camera->targetTilt = sVar1;
      if (sVar1 < -0x100) {
        camera->targetTilt = -0x100;
      }
      else {
        if (0x100 < sVar1) {
          camera->targetTilt = 0x100;
        }
      }
    }
    else {
      camera->targetTilt = 0;
    }
    local_1c = 0xb60 - (int)target;
    if (local_1c < 0x200) {
      local_1c = camera->targetTilt * local_1c;
      if (local_1c < 0) {
        local_1c = local_1c + 0x1ff;
      }
      camera->targetTilt = (short)(local_1c >> 9);
    }
    target = camera->targetTilt;
    local_1c = 8;
  }
  CriticalDampAngle(1,&camera->tilt,target,&camera->tiltVel,&camera->tiltAccl,local_1c);
  uVar3 = (uint)(ushort)camera->extraXRot +
          (uint)(ushort)(camera->targetFocusRotation).x + (uint)(ushort)camera->tilt & 0xfff;
  if (uVar3 - 0x301 < 0x4ff) {
    uVar3 = 0x300;
  }
  else {
    if (0x4ff < uVar3 - 0x800) goto LAB_8001c664;
    uVar3 = 0xfffffd00;
  }
  uVar3 = uVar3 & 0xfff;
LAB_8001c664:
  uVar5 = (ushort)uVar3;
  camera->tfaceTilt = uVar5;
  if ((camera->instance_mode & 0x2000000) != 0) {
    if (0x800 < uVar3) {
      uVar5 = uVar5 | 0xf000;
    }
    if (combat_cam_angle < (short)uVar5) {
      camera->tfaceTilt = combat_cam_angle + 0x1000;
    }
  }
  return;
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_FollowPlayerTilt(Camera *camera,_Instance *focusInstance)

{
  short sVar1;
  ushort uVar2;
  short current;
  ulong uVar3;
  long x;
  int iVar4;
  Level *pLVar5;
  int iVar6;
  int y;
  _SVector local_20;
  _Normal local_18;
  
  uVar3 = INSTANCE_Query(focusInstance,9);
  current = 0x20;
  if ((camera->instance_mode & 0x4000000) == 0) {
    if ((uVar3 & 0x40) != 0) {
      camera->targetTilt = -0xab;
      current = 0x20;
      goto LAB_8001c864;
    }
    CAMERA_CalcFocusOffsetForSwim(&local_20,camera);
    local_18.z = local_20.z;
    local_18.x = local_20.x;
    local_18.y = local_20.y;
    x = CAMERA_CalcTilt(&local_18,(camera->targetFocusRotation).z);
    camera->targetTilt = (short)x + 0x400;
    current = camera->targetTilt + -0x80;
    camera->targetTilt = current;
    uVar2 = AngleDiff(current,camera->tilt);
    if ((int)((uint)uVar2 << 0x10) < 0) {
      current = AngleDiff(camera->targetTilt,camera->tilt);
      iVar4 = -(int)current;
    }
    else {
      current = AngleDiff(camera->targetTilt,camera->tilt);
      iVar4 = (int)current;
    }
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xf;
    }
    current = (short)(iVar4 >> 4);
    if (0x20 < iVar4 >> 4) {
      current = 0x20;
    }
    pLVar5 = STREAM_GetLevelWithID(camera->focusInstance->currentStreamUnitID);
    iVar6 = (int)camera->focusDistance;
    y = (int)(camera->focusPoint).z - (pLVar5->waterZLevel + -0xa0);
    iVar4 = y;
    if (y < 0) {
      iVar4 = -y;
    }
    if (iVar6 <= iVar4) goto LAB_8001c864;
    x = MATH3D_FastSqrt0(iVar6 * iVar6 - y * y);
    x = ratan2(y,x);
    sVar1 = (short)x;
    if (x <= camera->targetTilt) goto LAB_8001c864;
  }
  else {
    sVar1 = -(camera->focusInstance->rotation).x;
  }
  camera->targetTilt = sVar1;
LAB_8001c864:
  CriticalDampAngle(1,&camera->tilt,camera->targetTilt,&camera->tiltVel,&camera->tiltAccl,
                    (int)current);
  camera->tfaceTilt = camera->tilt & 0xfff;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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
    if ((DAT_800d2210 & 0x100000) != 0) goto LAB_8001c928;
    iVar1 = (camera->data).Follow.stopTimer + DAT_800d2314;
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
    CriticalDampAngle(1,&(camera->focusRotation).z,(camera->collisionTargetFocusRotation).z,
                      &(camera->focusRotVel).z,&(camera->focusRotAccl).z,0x20);
    camera->forced_movement = 1;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
      goto LAB_8001cb40;
    }
  }
  else {
    camera->lead_timer = 0;
  }
  angle0 = 0;
  smooth = 3;
LAB_8001cb40:
  CriticalDampAngle(1,&camera->lead_angle,angle0,&camera->lead_vel,&camera->lead_accl,smooth);
  (camera->core).rotation.z = (camera->core).rotation.z + camera->lead_angle & 0xfff;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

void CAMERA_CalcFollowPosition(Camera *camera,_Rotation *rotation)

{
  short sVar1;
  short angle0;
  ushort uVar2;
  short sVar3;
  long x;
  long y;
  int iVar4;
  int iVar5;
  undefined4 in_t2;
  undefined4 in_t3;
  
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
    goto LAB_8001ce60;
  }
  sVar3 = (camera->real_focuspoint).x;
  sVar1 = (camera->targetPos).x;
  camera->actual_x_rot = camera->actual_x_rot - camera->x_rot_change;
  setCopReg(2,(int)angle0,(int)sVar3 - (int)sVar1);
  setCopReg(2,in_t2,(int)(camera->real_focuspoint).y - (int)(camera->targetPos).y);
  setCopReg(2,in_t3,0);
  copFunction(2,0xa00428);
  iVar5 = getCopReg(2,0x19);
  iVar4 = getCopReg(2,0x1a);
  getCopReg(2,0x1b);
  x = MATH3D_FastSqrt0(iVar5 + iVar4);
  y = ratan2((int)(camera->real_focuspoint).z - (int)(camera->targetPos).z,x);
  angle0 = (short)y;
  if ((camera->instance_mode & 0x1038) == 0) {
    sVar3 = CAMERA_AngleDifference(angle0,(camera->core).rotation.x);
    if (sVar3 < 4) goto LAB_8001cd6c;
  }
  else {
    iVar5 = (int)(camera->focusInstanceVelVec).z;
    if (iVar5 < 1) {
      if (iVar5 < 0) {
        if ((iVar5 < -0x104) && (iVar5 = -0x208 - iVar5, 0 < iVar5)) {
          iVar5 = 0;
        }
        iVar4 = (int)(camera->focusInstance->shadowPosition).z + 0x160;
        iVar5 = (int)(camera->real_focuspoint).z + iVar5 * 2;
        if (iVar5 < iVar4) {
          y = iVar4 - (camera->targetPos).z;
        }
        else {
          y = iVar5 - (camera->targetPos).z;
        }
        x = ratan2(y,x);
        angle0 = (short)x;
        uVar2 = CAMERA_SignedAngleDifference(angle0,camera->actual_x_rot);
        if (0 < (int)((uint)uVar2 << 0x10)) {
          angle0 = camera->actual_x_rot;
        }
      }
    }
    else {
LAB_8001cd6c:
      angle0 = (camera->core).rotation.x;
    }
  }
  if ((camera->flags & 0x1800U) != 0) {
    camera->actual_x_rot = angle0;
    camera->x_rot_change = 0;
  }
  sVar3 = CAMERA_SignedAngleDifference(angle0,camera->actual_x_rot);
  iVar5 = (int)sVar3;
  if ((camera->instance_mode & 0x2000) == 0) {
    iVar4 = 0x18;
  }
  else {
    if (iVar5 < 0x51) {
      iVar4 = 0x18;
      if (0 < iVar5) goto LAB_8001cdfc;
    }
    else {
      iVar4 = (iVar5 + -0x50) / 3;
      if (iVar4 < 4) {
LAB_8001cdfc:
        iVar4 = 4;
      }
      else {
        if (0x18 < iVar4) {
          iVar4 = 0x18;
        }
      }
    }
  }
  if (iVar4 == 0) {
    camera->actual_acc_x = 0;
    camera->actual_vel_x = 0;
  }
  else {
    CriticalDampAngle(1,&camera->actual_x_rot,angle0,&camera->actual_vel_x,&camera->actual_acc_x,
                      (int)(short)iVar4);
  }
  (camera->core).rotation.x = camera->actual_x_rot;
LAB_8001ce60:
  camera->lagZ = (camera->core).rotation.z;
  return;
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

/* File: C:\kain2\game\CAMERA.C */

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

/* File: C:\kain2\game\CAMERA.C */

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
/* File: C:\kain2\game\CAMERA.C */

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
/* File: C:\kain2\game\CAMERA.C */

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
     (((CenterFlag = -1, local_30 != 1 || ((local_38 & 6) == 0)) && (combat_cam_weight < 0x1000))))
  {
    if ((short)(combat_cam_weight + 0x90) < 0x1000) {
      CenterFlag = -1;
      combat_cam_weight = combat_cam_weight + 0x90;
      return 1;
    }
    combat_cam_weight = 0x1000;
  }
  if ((((camera->flags & 0x12000U) == 0) && (camera->instance_xyvel == 0)) &&
     ((((secondcheck_flag == 0 &&
        (((camera->always_rotate_flag == 0 && (camera->forced_movement == 0)) && (0 < local_30))))
       && ((local_30 == 4 || (camera_still != 0)))) && (local_2c < 400)))) {
    panic_count = panic_count + 1;
    if ((DAT_800d2114 & 1) == 0) {
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
    step = (camera->targetFocusPoint).y;
    sVar2 = (camera->targetFocusPoint).z;
    (camera->focusSphere).position.x = (camera->targetFocusPoint).x;
    (camera->focusSphere).position.y = step;
    (camera->focusSphere).position.z = sVar2;
    p_Var5 = CAMERA_SphereToSphereWithLines(camera,(CameraCollisionInfo *)auStack120,0);
    (camera->data).Follow.tface = p_Var5;
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
          lVar7 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
          DAT_800cf178 = 0x1e;
          (camera->targetFocusRotation).z = (camera->collisionTargetFocusRotation).z;
          return lVar7;
        }
        CAMERA_dampgetline(0);
        if ((camera->mode == 0xd) && (0 < camera->instance_xyvel)) {
          step = CAMERA_AngleDifference
                           ((camera->collisionTargetFocusRotation).z,(camera->focusRotation).z);
          if (step < 5) {
            bVar1 = DAT_800cf178 == 0;
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
          if (DAT_800cf178 == 0) {
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
        DAT_800cf178 = 0;
        camera->collisionTargetFocusDistance = combat_cam_distance;
        return 0;
      }
    }
    if ((camera->data).Follow.tface == (_TFace *)0x0) {
      camera->collisionTargetFocusDistance = camera->targetFocusDistance;
    }
    else {
      lVar7 = CAMERA_AbsoluteCollision(camera,(CameraCollisionInfo *)auStack120);
      DAT_800cf178 = 0x1e;
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
 // line 5851, offset 0x8001d7b4
	/* begin block 1 */
		// Start line: 13382
	/* end block 1 */
	// End Line: 13383

	/* begin block 2 */
		// Start line: 13383
	/* end block 2 */
	// End Line: 13384

/* File: C:\kain2\game\CAMERA.C */

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





