
#include "ENMYPLAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool /*$a0*/)
 // line 107, offset 0x80095fe8
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x80095FE8
		// Variables:
	// 		int i; // $v0
	/* end block 1 */
	// End offset: 0x80096000
	// End Line: 117

	/* begin block 2 */
		// Start line: 214
	/* end block 2 */
	// End Line: 215

	/* begin block 3 */
		// Start line: 215
	/* end block 3 */
	// End Line: 216

	/* begin block 4 */
		// Start line: 220
	/* end block 4 */
	// End Line: 221

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = 9;
  puVar2 = (undefined *)((int)enemyPlanPool + 0x34e);
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -0x5e;
  } while (-1 < iVar1);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetNextAvailablePlanningSlot()
 // line 131, offset 0x80096008
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x80096008
		// Variables:
	// 		int slotID; // $a1
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80096040
	// End Line: 143

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

	/* begin block 3 */
		// Start line: 264
	/* end block 3 */
	// End Line: 265

	/* begin block 4 */
		// Start line: 265
	/* end block 4 */
	// End Line: 266

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = DAT_800d22e8;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x5e;
  } while (iVar1 < 10);
  return -1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetInitializedPlanningWorkspaceFinal()
 // line 167, offset 0x80096048
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80096048
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s0
	// 		int slotID; // $a0
	/* end block 1 */
	// End offset: 0x80096090
	// End Line: 181

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar1 = DAT_800d22e8;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1) {
    puVar3 = (undefined *)(iVar2 * 0x5e + iVar1);
    *puVar3 = 1;
    puVar3[1] = 0;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_ReleasePlanningWorkspace(int slotID /*$s0*/)
 // line 185, offset 0x800960a4
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x800960A4
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	/* end block 1 */
	// End offset: 0x800960F8
	// End Line: 203

	/* begin block 2 */
		// Start line: 376
	/* end block 2 */
	// End Line: 377

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

void ENMYPLAN_ReleasePlanningWorkspace(int slotID)

{
  int iVar1;
  
  iVar1 = DAT_800d22e8;
  if ((-1 < slotID) && (slotID < 10)) {
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
    *(undefined *)(slotID * 0x5e + iVar1) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_WayPointSkipped(struct _Position *currentPos /*$a0*/, struct _Position *targetPos /*$s0*/, struct _Position *nextTargetPos /*$s1*/)
 // line 208, offset 0x8009610c
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x8009610C
		// Variables:
	// 		long range[2]; // stack offset -40
	// 		struct _Position vector[2]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x8009610C
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $v0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8009610C
		// End Line: 209

		/* begin block 1.2 */
			// Start line: 209
			// Start offset: 0x8009610C
			// Variables:
		// 		short _x0; // $a0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $a1
		/* end block 1.2 */
		// End offset: 0x8009610C
		// End Line: 209
	/* end block 1 */
	// End offset: 0x800961E4
	// End Line: 225

	/* begin block 2 */
		// Start line: 423
	/* end block 2 */
	// End Line: 424

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_WayPointSkipped(_Position *currentPos,_Position *targetPos,_Position *nextTargetPos)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint local_28;
  uint local_24;
  
  iVar4 = (uint)(ushort)targetPos->x - (uint)(ushort)currentPos->x;
  sVar1 = targetPos->y - currentPos->y;
  sVar6 = targetPos->z - currentPos->z;
  local_28 = MATH3D_LengthXYZ(iVar4 * 0x10000 >> 0x10,(int)sVar1,(int)sVar6);
  iVar5 = (uint)(ushort)nextTargetPos->x - (uint)(ushort)targetPos->x;
  sVar2 = nextTargetPos->y - targetPos->y;
  sVar3 = nextTargetPos->z - targetPos->z;
  local_24 = MATH3D_LengthXYZ(iVar5 * 0x10000 >> 0x10,(int)sVar2,(int)sVar3);
  if ((int)local_28 < (int)local_24) {
    local_28 = local_28 ^ local_24;
    local_24 = local_24 ^ local_28;
    local_28 = local_28 ^ local_24;
  }
  return (uint)((int)(((int)(local_28 * 0x2d4) >> 10) * local_24) <
               (int)(short)iVar4 * (int)(short)iVar5 + (int)sVar1 * (int)sVar2 +
               (int)sVar6 * (int)sVar3) ^ 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_WayPointReached(struct _Position *currentPos /*$v1*/, struct _Position *oldCurrentPos /*$s1*/, struct _Position *targetPos /*$s0*/)
 // line 235, offset 0x80096278
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x80096278
		// Variables:
	// 		long range[2]; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096314
	// End Line: 249

	/* begin block 2 */
		// Start line: 487
	/* end block 2 */
	// End Line: 488

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_WayPointReached(_Position *currentPos,_Position *oldCurrentPos,_Position *targetPos)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = MATH3D_LengthXYZ((int)targetPos->x - (int)currentPos->x,
                           (int)targetPos->y - (int)currentPos->y,
                           (int)targetPos->z - (int)currentPos->z);
  lVar2 = MATH3D_LengthXYZ((int)targetPos->x - (int)oldCurrentPos->x,
                           (int)targetPos->y - (int)oldCurrentPos->y,
                           (int)targetPos->z - (int)oldCurrentPos->z);
  if (((lVar1 <= lVar2) || (iVar3 = 1, 399 < lVar1)) && (iVar3 = 1, 0x31 < lVar1)) {
    iVar3 = 0;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot /*$a0*/)
 // line 267, offset 0x80096328
	/* begin block 1 */
		// Start line: 552
	/* end block 1 */
	// End Line: 553

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

void ENMYPLAN_Replan(EnemyPlanSlotData *planSlot)

{
  planSlot->state = '\0';
  PLANAPI_DeleteNodesFromPoolByType(2);
  PLANAPI_DeleteNodesFromPoolByType(3);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_PathClear(struct _Position *pos /*$s0*/, struct _Position *target /*$a1*/)
 // line 274, offset 0x80096354
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x80096354
		// Variables:
	// 		int len; // $a1
	// 		struct _Position *tpos; // $a1
	// 		struct _Position newTarget; // stack offset -16
	/* end block 1 */
	// End offset: 0x80096494
	// End Line: 299

	/* begin block 2 */
		// Start line: 566
	/* end block 2 */
	// End Line: 567

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_PathClear(_Position *pos,_Position *target)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  _Position *endPos;
  _Position local_10;
  
  iVar4 = (uint)(ushort)target->x - (uint)(ushort)pos->x;
  local_10.x = (short)iVar4;
  iVar1 = (uint)(ushort)target->y - (uint)(ushort)pos->y;
  local_10.y = (short)iVar1;
  iVar3 = (uint)(ushort)target->z - (uint)(ushort)pos->z;
  local_10.z = (short)iVar3;
  lVar2 = MATH3D_LengthXYZ(iVar4 * 0x10000 >> 0x10,iVar1 * 0x10000 >> 0x10,iVar3 * 0x10000 >> 0x10);
  endPos = pos;
  if (0x500 < lVar2) {
    iVar1 = (((int)local_10.x << 0xc) / lVar2) * 0x500;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    iVar3 = (((int)local_10.y << 0xc) / lVar2) * 0x500;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    iVar4 = (((int)local_10.z << 0xc) / lVar2) * 0x500;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    local_10.x = (short)(iVar1 >> 0xc) + pos->x;
    local_10.y = (short)(iVar3 >> 0xc) + pos->y;
    local_10.z = (short)(iVar4 >> 0xc) + pos->z;
    endPos = &local_10;
  }
  iVar1 = PLANCOLL_DoesStraightLinePathExist(pos,endPos,0);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_MoveToTargetFinal(struct _Instance *instance /*stack 0*/, struct _Position *outputPos /*$s6*/, int slotID /*$a2*/, struct _Position *targetPos /*$s2*/, int validNodeTypes /*stack 16*/)
 // line 304, offset 0x800964b0
	/* begin block 1 */
		// Start line: 305
		// Start offset: 0x800964B0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $a0
	// 		struct EnemyPlanSlotData *planSlot; // $s0
	// 		struct EnemyPlanData *planData; // $s4
	// 		int nextWayPointType; // $a0
	// 		int nextNextWayPointType; // $s2
	// 		int pathFound; // $v0
	// 		int nextWayPointIdx; // $s5
	// 		int nextNextWayPointIdx; // $s3
	// 		int nextWayPointSkip; // $v1
	// 		int i; // $v1
	// 		struct _Position *nextWayPointPos; // $fp
	// 		struct _Position *nextNextWayPointPos; // $s6
	/* end block 1 */
	// End offset: 0x8009695C
	// End Line: 531

	/* begin block 2 */
		// Start line: 635
	/* end block 2 */
	// End Line: 636

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_MoveToTargetFinal
              (_Instance *instance,_Position *outputPos,int slotID,_Position *targetPos,
              int validNodeTypes)

{
  uchar uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  uchar *puVar10;
  EnemyPlanSlotData *planSlot;
  uchar *puVar11;
  byte bVar12;
  EnemyPlanData *planData;
  uint uVar13;
  _Position *nextTargetPos;
  _Position *targetPos_00;
  
  iVar4 = DAT_800d22e8;
  DAT_800d2296 = 1;
  sVar7 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar7;
  if ((slotID == -1) || (9 < slotID)) {
    DAT_800d2296 = 1;
    iVar4 = 2;
  }
  else {
    planSlot = (EnemyPlanSlotData *)(iVar4 + slotID * 0x5e);
    bVar12 = planSlot->state;
    planData = &planSlot->planData;
    if (bVar12 == 1) {
      iVar4 = PLANAPI_FindPathInGraphToTarget(&planSlot->startPos,planData,validNodeTypes);
      sVar7 = planSlot->timer + 1;
      planSlot->timer = sVar7;
      if (iVar4 == 0) {
        if (0x3c < sVar7) {
          planSlot->state = '\x04';
        }
      }
      else {
        planSlot->state = '\x02';
        planSlot->wayPointBeingServoedTo = '\x01';
      }
    }
    else {
      if (bVar12 < 2) {
        if (bVar12 == 0) {
          sVar7 = (instance->position).z;
          *(undefined4 *)&planSlot->startPos = *(undefined4 *)&instance->position;
          (planSlot->startPos).z = sVar7;
          sVar7 = targetPos->z;
          *(undefined4 *)&planSlot->goalPos = *(undefined4 *)targetPos;
          (planSlot->goalPos).z = sVar7;
          planSlot->timer = 0;
          iVar4 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos,3);
          if (iVar4 != 0) {
            PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos,2);
            planSlot->state = '\x01';
          }
        }
      }
      else {
        if (bVar12 == 2) {
          bVar12 = planSlot->wayPointBeingServoedTo;
          uVar13 = (uint)bVar12;
          puVar11 = planData->nodeSkipArray + uVar13;
          uVar1 = *puVar11;
          targetPos_00 = planData->wayPointArray + uVar13;
          sVar7 = targetPos_00->z;
          *(undefined4 *)outputPos = *(undefined4 *)targetPos_00;
          outputPos->z = sVar7;
          if (uVar1 == '\x02') {
            iVar4 = ENMYPLAN_PathClear(&instance->position,targetPos_00);
            if (((iVar4 == 0) && (*(char *)(&planData[-1].field_0x43 + uVar13) == '\x01')) &&
               (bVar12 != 0)) {
              do {
                uVar8 = uVar13 - 1;
                if ((*(char *)(&planData[-1].field_0x43 + uVar13) != '\x01') || (uVar8 == 0)) {
                  planSlot->wayPointBeingServoedTo = (char)uVar8;
                  planData->nodeSkipArray[uVar13] = '\x02';
                  break;
                }
                uVar13 = uVar8;
              } while (0 < (int)uVar8);
            }
          }
          else {
            iVar4 = (uint)(byte)planSlot->wayPointBeingServoedTo + 1;
            iVar9 = iVar4 * 6 + 0x10;
            bVar12 = planData->nodeTypeArray[(uint)(byte)planSlot->wayPointBeingServoedTo + 1] >> 3
                     & 3;
            if (((puVar11[8] >> 3 & 3) == bVar12) &&
               (bVar3 = puVar11[8] >> 3 & 3, *puVar11 != '\x02')) {
              do {
                bVar2 = bVar12;
                if (bVar3 != 0) goto LAB_800967d8;
                nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar9);
                iVar5 = ENMYPLAN_WayPointSkipped(&instance->position,targetPos_00,nextTargetPos);
                puVar10 = planData->nodeSkipArray + uVar13;
                if (iVar5 == 0) break;
                if ((int)((uint)(planSlot->planData).numWayPoints - 2) <=
                    (int)(uint)(byte)planSlot->wayPointBeingServoedTo) goto LAB_800967d8;
                *puVar11 = '\x01';
                puVar11 = puVar11 + 1;
                uVar13 = uVar13 + 1;
                iVar9 = iVar9 + 6;
                planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01';
                bVar12 = planData->nodeTypeArray[iVar4 + 1] >> 3 & 3;
                targetPos_00 = nextTargetPos;
                if (bVar2 != bVar12) goto LAB_800967d8;
                puVar10 = planData->nodeSkipArray + uVar13;
                iVar4 = iVar4 + 1;
                bVar3 = bVar2;
              } while (*puVar11 != '\x02');
            }
            else {
LAB_800967d8:
              puVar10 = planData->nodeSkipArray + uVar13;
            }
            *puVar10 = '\x02';
          }
          iVar4 = ENMYPLAN_WayPointReached
                            (&instance->position,&planSlot->oldCurrentPos,targetPos_00);
          if ((iVar4 != 0) &&
             (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
             (int)((uint)(planSlot->planData).numWayPoints - 1) <=
             (int)(uint)(byte)planSlot->wayPointBeingServoedTo)) {
            planSlot->state = '\x03';
            PLANAPI_DeleteNodesFromPoolByType(2);
            PLANAPI_DeleteNodesFromPoolByType(3);
          }
        }
        else {
          if (bVar12 == 3) {
            lVar6 = MATH3D_LengthXYZ((int)targetPos->x - (int)(instance->position).x,
                                     (int)targetPos->y - (int)(instance->position).y,
                                     (int)targetPos->z - (int)(instance->position).z);
            if (0x400 < lVar6) {
              targetPos_00 = planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo;
              lVar6 = MATH3D_LengthXYZ((int)targetPos->x - (int)targetPos_00->x,
                                       (int)targetPos->y - (int)targetPos_00->y,
                                       (int)targetPos->z - (int)targetPos_00->z);
              if (0x400 < lVar6) {
                ENMYPLAN_Replan(planSlot);
              }
            }
            sVar7 = targetPos->z;
            *(undefined4 *)outputPos = *(undefined4 *)targetPos;
            outputPos->z = sVar7;
          }
        }
      }
    }
    sVar7 = (instance->position).z;
    *(undefined4 *)&planSlot->oldCurrentPos = *(undefined4 *)&instance->position;
    (planSlot->oldCurrentPos).z = sVar7;
    switch(planSlot->state) {
    case '\0':
    case '\x01':
      iVar4 = 0;
      break;
    case '\x02':
      iVar4 = 1;
      break;
    case '\x03':
      iVar4 = 2;
      break;
    default:
      iVar4 = 3;
    }
    DAT_800d2296 = 0;
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ValidSlotAndState(struct EnemyPlanSlotData *pool /*$a0*/, int slotID /*$a1*/)
 // line 533, offset 0x8009698c
	/* begin block 1 */
		// Start line: 1166
	/* end block 1 */
	// End Line: 1167

	/* begin block 2 */
		// Start line: 1168
	/* end block 2 */
	// End Line: 1169

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ValidSlotAndState(EnemyPlanSlotData *pool,int slotID)

{
  if ((slotID != -1) && (slotID < 10)) {
    return (uint)((uint)(byte)pool[slotID].state - 2 < 2);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID /*$s0*/)
 // line 546, offset 0x800969d0
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x800969D0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v0
	/* end block 1 */
	// End offset: 0x80096A28
	// End Line: 559

	/* begin block 2 */
		// Start line: 1192
	/* end block 2 */
	// End Line: 1193

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  EnemyPlanSlotData *pEVar1;
  int iVar2;
  uint uVar3;
  
  pEVar1 = DAT_800d22e8;
  iVar2 = ValidSlotAndState(DAT_800d22e8,slotID);
  if (iVar2 == 0) {
    uVar3 = 0x40;
  }
  else {
    uVar3 = (uint)pEVar1[slotID].planData.nodeTypeArray[(byte)pEVar1[slotID].wayPointBeingServoedTo]
    ;
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetPosOfNextWaypoint(int slotID /*$s0*/, struct _Position *pos /*$s2*/)
 // line 561, offset 0x80096a3c
	/* begin block 1 */
		// Start line: 562
		// Start offset: 0x80096A3C
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v1

		/* begin block 1.1 */
			// Start line: 566
			// Start offset: 0x80096A70
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80096A70
		// End Line: 566
	/* end block 1 */
	// End offset: 0x80096AC4
	// End Line: 575

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

int ENMYPLAN_GetPosOfNextWaypoint(int slotID,_Position *pos)

{
  short sVar1;
  short sVar2;
  EnemyPlanSlotData *pEVar3;
  int iVar4;
  _Position *p_Var5;
  
  pEVar3 = DAT_800d22e8;
  iVar4 = ValidSlotAndState(DAT_800d22e8,slotID);
  if (iVar4 != 0) {
    p_Var5 = pEVar3[slotID].planData.wayPointArray + (byte)pEVar3[slotID].wayPointBeingServoedTo;
    sVar1 = p_Var5->y;
    sVar2 = p_Var5->z;
    pos->x = p_Var5->x;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (uint)(iVar4 != 0);
}



// decompiled code
// original method signature: 
// short /*$ra*/ ENMYPLAN_ReportCurrentGoalUnitID(int slotID /*$a0*/)
 // line 622, offset 0x80096adc
	/* begin block 1 */
		// Start line: 624
		// Start offset: 0x80096ADC
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $v1
	/* end block 1 */
	// End offset: 0x80096B0C
	// End Line: 630

	/* begin block 2 */
		// Start line: 1362
	/* end block 2 */
	// End Line: 1363

	/* begin block 3 */
		// Start line: 1363
	/* end block 3 */
	// End Line: 1364

/* File: C:\kain2\game\PLAN\ENMYPLAN.C */

short ENMYPLAN_ReportCurrentGoalUnitID(int slotID)

{
  if (slotID != -1) {
    return *(short *)(slotID * 0x5e + DAT_800d22e8 + 0x56);
  }
  return 0;
}





