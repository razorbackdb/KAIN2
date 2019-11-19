#include "THISDUST.H"
#include "ENMYPLAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool /*$a0*/)
 // line 107, offset 0x800943e8
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x800943E8
		// Variables:
	// 		int i; // $v0
	/* end block 1 */
	// End offset: 0x80094400
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
 // line 131, offset 0x80094408
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x80094408
		// Variables:
	// 		int slotID; // $a1
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80094440
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = (char *)gameTrackerX.currentTime;
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
 // line 167, offset 0x80094448
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80094448
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s0
	// 		int slotID; // $a0
	/* end block 1 */
	// End offset: 0x80094490
	// End Line: 181

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(void)

{
  ulong uVar1;
  int iVar2;
  undefined *puVar3;
  
  uVar1 = gameTrackerX.currentTime;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1) {
    puVar3 = (undefined *)(iVar2 * 0x5e + uVar1);
    *puVar3 = 1;
    puVar3[1] = 0;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_ReleasePlanningWorkspace(int slotID /*$s0*/)
 // line 185, offset 0x800944a4
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x800944A4
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	/* end block 1 */
	// End offset: 0x800944F8
	// End Line: 203

	/* begin block 2 */
		// Start line: 376
	/* end block 2 */
	// End Line: 377

void ENMYPLAN_ReleasePlanningWorkspace(int slotID)

{
  ulong uVar1;
  
  uVar1 = gameTrackerX.currentTime;
  if ((-1 < slotID) && (slotID < 10)) {
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
    *(undefined *)(slotID * 0x5e + uVar1) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_WayPointSkipped(struct _Position *currentPos /*$a0*/, struct _Position *targetPos /*$s0*/, struct _Position *nextTargetPos /*$s1*/)
 // line 208, offset 0x8009450c
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x8009450C
		// Variables:
	// 		long range[2]; // stack offset -40
	// 		struct _Position vector[2]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x8009450C
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $v0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8009450C
		// End Line: 209

		/* begin block 1.2 */
			// Start line: 209
			// Start offset: 0x8009450C
			// Variables:
		// 		short _x0; // $a0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $a1
		/* end block 1.2 */
		// End offset: 0x8009450C
		// End Line: 209
	/* end block 1 */
	// End offset: 0x800945E4
	// End Line: 225

	/* begin block 2 */
		// Start line: 423
	/* end block 2 */
	// End Line: 424

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
 // line 235, offset 0x80094678
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x80094678
		// Variables:
	// 		long range[2]; // stack offset -24
	/* end block 1 */
	// End offset: 0x80094714
	// End Line: 249

	/* begin block 2 */
		// Start line: 487
	/* end block 2 */
	// End Line: 488

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
 // line 267, offset 0x80094728
	/* begin block 1 */
		// Start line: 552
	/* end block 1 */
	// End Line: 553

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
 // line 274, offset 0x80094754
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x80094754
		// Variables:
	// 		struct _Position newTarget; // stack offset -16
	/* end block 1 */
	// End offset: 0x8009480C
	// End Line: 284

	/* begin block 2 */
		// Start line: 566
	/* end block 2 */
	// End Line: 567

int ENMYPLAN_PathClear(_Position *pos,_Position *target)

{
  int iVar1;
  _Normal local_10;
  
  local_10.x = target->x - pos->x;
  local_10.y = target->y - pos->y;
  local_10.z = target->z - pos->z;
  MATH3D_Normalize(&local_10);
  iVar1 = (int)local_10.x * 0x500;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  local_10.x = (short)(iVar1 >> 0xc);
  iVar1 = (int)local_10.y * 0x500;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  local_10.y = (short)(iVar1 >> 0xc);
  iVar1 = (int)local_10.z * 0x500;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  local_10.z = (short)(iVar1 >> 0xc);
  iVar1 = PLANCOLL_DoesStraightLinePathExist(pos,(_Position *)&local_10,0);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_MoveToTargetFinal(struct _Instance *instance /*$fp*/, struct _Position *outputPos /*$s4*/, int slotID /*$a2*/, struct _Position *targetPos /*$s0*/, int validNodeTypes /*stack 16*/)
 // line 291, offset 0x80094834
	/* begin block 1 */
		// Start line: 292
		// Start offset: 0x80094834
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $a0
	// 		struct EnemyPlanSlotData *planSlot; // $s1
	// 		struct EnemyPlanData *planData; // $s3
	// 		int nextWayPointType; // $a0
	// 		int nextNextWayPointType; // $s0
	// 		int pathFound; // $v0
	// 		int nextWayPointIdx; // $s6
	// 		int nextNextWayPointIdx; // $s2
	// 		int nextWayPointSkip; // $v1
	// 		int i; // $v1
	// 		struct _Position *nextWayPointPos; // $s7
	// 		struct _Position *nextNextWayPointPos; // $s4
	/* end block 1 */
	// End offset: 0x80094C6C
	// End Line: 507

	/* begin block 2 */
		// Start line: 603
	/* end block 2 */
	// End Line: 604

int ENMYPLAN_MoveToTargetFinal
              (_Instance *instance,_Position *outputPos,int slotID,_Position *targetPos,
              int validNodeTypes)

{
  bool bVar1;
  uchar uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  EnemyPlanSlotData *planSlot;
  EnemyPlanData *planData;
  _Position *nextTargetPos;
  uint uVar11;
  _Position *targetPos_00;
  
  uVar3 = gameTrackerX.currentTime;
  sVar7 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar7;
  if ((slotID == -1) || (9 < slotID)) {
switchD_80094c48_caseD_3:
    iVar6 = 2;
  }
  else {
    planSlot = (EnemyPlanSlotData *)(uVar3 + slotID * 0x5e);
    bVar10 = planSlot->state;
    planData = &planSlot->planData;
    if (bVar10 == 1) {
      iVar6 = PLANAPI_FindPathInGraphToTarget(&planSlot->startPos,planData,validNodeTypes);
      sVar7 = planSlot->timer + 1;
      planSlot->timer = sVar7;
      if (iVar6 == 0) {
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
      if (bVar10 < 2) {
        if (bVar10 == 0) {
          sVar7 = (instance->position).z;
          *(undefined4 *)&planSlot->startPos = *(undefined4 *)&instance->position;
          (planSlot->startPos).z = sVar7;
          sVar7 = targetPos->z;
          *(undefined4 *)&planSlot->goalPos = *(undefined4 *)targetPos;
          (planSlot->goalPos).z = sVar7;
          planSlot->timer = 0;
          iVar6 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos,3);
          if (iVar6 != 0) {
            PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos,2);
            planSlot->state = '\x01';
          }
        }
      }
      else {
        if (bVar10 == 2) {
          uVar11 = (uint)(byte)planSlot->wayPointBeingServoedTo;
          uVar2 = planData->nodeSkipArray[uVar11];
          targetPos_00 = planData->wayPointArray + uVar11;
          sVar7 = targetPos_00->z;
          *(undefined4 *)outputPos = *(undefined4 *)targetPos_00;
          outputPos->z = sVar7;
          if (uVar2 == '\x02') {
            iVar6 = ENMYPLAN_PathClear(&instance->position,targetPos_00);
            if ((iVar6 == 0) &&
               (iVar6 = uVar11 - 2, *(char *)(&planData[-1].field_0x43 + uVar11) == '\x01')) {
              while (iVar6 != 0) {
                if (planData->nodeSkipArray[iVar6] != '\x01') {
                  planSlot->wayPointBeingServoedTo = (char)iVar6;
                  planData->nodeSkipArray[iVar6 + 1] = '\x02';
                  break;
                }
                iVar6 = iVar6 + -1;
              }
            }
          }
          else {
            bVar10 = (planData->nodeSkipArray + uVar11)[8] >> 3;
            iVar6 = (uint)(byte)planSlot->wayPointBeingServoedTo + 1;
            iVar8 = iVar6 * 6 + 0x10;
            bVar9 = planData->nodeTypeArray[(uint)(byte)planSlot->wayPointBeingServoedTo + 1] >> 3 &
                    3;
            if (((bVar10 & 3) == bVar9) && ((bVar10 & 3) == 0)) {
              while( true ) {
                nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar8);
                iVar4 = ENMYPLAN_WayPointSkipped(&instance->position,targetPos_00,nextTargetPos);
                if ((iVar4 == 0) ||
                   ((int)((uint)(planSlot->planData).numWayPoints - 2) <=
                    (int)(uint)(byte)planSlot->wayPointBeingServoedTo)) break;
                uVar11 = uVar11 + 1;
                iVar8 = iVar8 + 6;
                planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + 1;
                bVar10 = planData->nodeTypeArray[iVar6 + 1] >> 3 & 3;
                targetPos_00 = nextTargetPos;
                if ((bVar9 != bVar10) ||
                   (bVar1 = bVar9 != 0, iVar6 = iVar6 + 1, bVar9 = bVar10, bVar1)) break;
              }
            }
            planData->nodeSkipArray[uVar11] = '\x02';
          }
          iVar6 = ENMYPLAN_WayPointReached
                            (&instance->position,&planSlot->oldCurrentPos,targetPos_00);
          if ((iVar6 != 0) &&
             (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
             (int)((uint)(planSlot->planData).numWayPoints - 1) <=
             (int)(uint)(byte)planSlot->wayPointBeingServoedTo)) {
            planSlot->state = '\x03';
            PLANAPI_DeleteNodesFromPoolByType(2);
            PLANAPI_DeleteNodesFromPoolByType(3);
          }
        }
        else {
          if (bVar10 == 3) {
            lVar5 = MATH3D_LengthXYZ((int)targetPos->x - (int)(instance->position).x,
                                     (int)targetPos->y - (int)(instance->position).y,
                                     (int)targetPos->z - (int)(instance->position).z);
            if (0x400 < lVar5) {
              targetPos_00 = planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo;
              lVar5 = MATH3D_LengthXYZ((int)targetPos->x - (int)targetPos_00->x,
                                       (int)targetPos->y - (int)targetPos_00->y,
                                       (int)targetPos->z - (int)targetPos_00->z);
              if (0x400 < lVar5) {
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
      iVar6 = 0;
      break;
    case '\x02':
      iVar6 = 1;
      break;
    case '\x03':
      goto switchD_80094c48_caseD_3;
    default:
      iVar6 = 3;
    }
  }
  return iVar6;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ValidSlotAndState(struct EnemyPlanSlotData *pool /*$a0*/, int slotID /*$a1*/)
 // line 509, offset 0x80094c9c
	/* begin block 1 */
		// Start line: 1091
	/* end block 1 */
	// End Line: 1092

	/* begin block 2 */
		// Start line: 1093
	/* end block 2 */
	// End Line: 1094

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
 // line 522, offset 0x80094ce0
	/* begin block 1 */
		// Start line: 523
		// Start offset: 0x80094CE0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v0
	/* end block 1 */
	// End offset: 0x80094D38
	// End Line: 535

	/* begin block 2 */
		// Start line: 1117
	/* end block 2 */
	// End Line: 1118

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = gameTrackerX.currentTime;
  iVar2 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.currentTime,slotID);
  if (iVar2 == 0) {
    uVar3 = 0x40;
  }
  else {
    iVar2 = uVar1 + slotID * 0x5e;
    uVar3 = (uint)*(byte *)(iVar2 + (uint)*(byte *)(iVar2 + 2) + 0x1e);
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetPosOfNextWaypoint(int slotID /*$s0*/, struct _Position *pos /*$s2*/)
 // line 537, offset 0x80094d4c
	/* begin block 1 */
		// Start line: 538
		// Start offset: 0x80094D4C
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v1

		/* begin block 1.1 */
			// Start line: 542
			// Start offset: 0x80094D80
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80094D80
		// End Line: 542
	/* end block 1 */
	// End offset: 0x80094DD4
	// End Line: 551

	/* begin block 2 */
		// Start line: 1155
	/* end block 2 */
	// End Line: 1156

int ENMYPLAN_GetPosOfNextWaypoint(int slotID,_Position *pos)

{
  short sVar1;
  short sVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  uVar3 = gameTrackerX.currentTime;
  iVar4 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.currentTime,slotID);
  if (iVar4 != 0) {
    iVar5 = uVar3 + slotID * 0x5e;
    psVar6 = (short *)(iVar5 + (uint)*(byte *)(iVar5 + 2) * 6 + 0x26);
    sVar1 = psVar6[1];
    sVar2 = psVar6[2];
    pos->x = *psVar6;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (uint)(iVar4 != 0);
}



// decompiled code
// original method signature: 
// short /*$ra*/ ENMYPLAN_ReportCurrentGoalUnitID(int slotID /*$a0*/)
 // line 598, offset 0x80094dec
	/* begin block 1 */
		// Start line: 600
		// Start offset: 0x80094DEC
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $v1
	/* end block 1 */
	// End offset: 0x80094E1C
	// End Line: 606

	/* begin block 2 */
		// Start line: 1287
	/* end block 2 */
	// End Line: 1288

	/* begin block 3 */
		// Start line: 1288
	/* end block 3 */
	// End Line: 1289

short ENMYPLAN_ReportCurrentGoalUnitID(int slotID)

{
  if (slotID != -1) {
    return *(short *)(slotID * 0x5e + gameTrackerX.currentTime + 0x56);
  }
  return 0;
}





