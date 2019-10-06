#include "THISDUST.H"
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = (char *)gameTrackerX.enemyPlanPool;
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(void)

{
  void *pvVar1;
  int iVar2;
  undefined *puVar3;
  
  pvVar1 = gameTrackerX.enemyPlanPool;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1) {
    puVar3 = (undefined *)(iVar2 * 0x5e + (int)pvVar1);
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

void ENMYPLAN_ReleasePlanningWorkspace(int slotID)

{
  void *pvVar1;
  
  pvVar1 = gameTrackerX.enemyPlanPool;
  if ((-1 < slotID) && (slotID < 10)) {
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
    *(undefined *)(slotID * 0x5e + (int)pvVar1) = 0;
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

int ENMYPLAN_MoveToTargetFinal
              (_Instance *instance,_Position *outputPos,int slotID,_Position *targetPos,
              int validNodeTypes)

{
  uchar uVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  EnemyPlanSlotData *planSlot;
  uchar *puVar12;
  byte bVar13;
  EnemyPlanData *planData;
  uint uVar14;
  _Position *nextTargetPos;
  _Position *targetPos_00;
  
  pvVar4 = gameTrackerX.enemyPlanPool;
  gameTrackerX.plan_collide_override = '\x01';
  sVar8 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar8;
  if ((slotID == -1) || (9 < slotID)) {
    gameTrackerX.plan_collide_override = '\x01';
    iVar5 = 2;
  }
  else {
    planSlot = (EnemyPlanSlotData *)((int)pvVar4 + slotID * 0x5e);
    bVar13 = planSlot->state;
    planData = &planSlot->planData;
    if (bVar13 == 1) {
      iVar5 = PLANAPI_FindPathInGraphToTarget(&planSlot->startPos,planData,validNodeTypes);
      sVar8 = planSlot->timer + 1;
      planSlot->timer = sVar8;
      if (iVar5 == 0) {
        if (0x3c < sVar8) {
          planSlot->state = '\x04';
        }
      }
      else {
        planSlot->state = '\x02';
        planSlot->wayPointBeingServoedTo = '\x01';
      }
    }
    else {
      if (bVar13 < 2) {
        if (bVar13 == 0) {
          sVar8 = (instance->position).z;
          *(undefined4 *)&planSlot->startPos = *(undefined4 *)&instance->position;
          (planSlot->startPos).z = sVar8;
          sVar8 = targetPos->z;
          *(undefined4 *)&planSlot->goalPos = *(undefined4 *)targetPos;
          (planSlot->goalPos).z = sVar8;
          planSlot->timer = 0;
          iVar5 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos,3);
          if (iVar5 != 0) {
            PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos,2);
            planSlot->state = '\x01';
          }
        }
      }
      else {
        if (bVar13 == 2) {
          bVar13 = planSlot->wayPointBeingServoedTo;
          uVar14 = (uint)bVar13;
          puVar12 = planData->nodeSkipArray + uVar14;
          uVar1 = *puVar12;
          targetPos_00 = planData->wayPointArray + uVar14;
          sVar8 = targetPos_00->z;
          *(undefined4 *)outputPos = *(undefined4 *)targetPos_00;
          outputPos->z = sVar8;
          if (uVar1 == '\x02') {
            iVar5 = ENMYPLAN_PathClear(&instance->position,targetPos_00);
            if (((iVar5 == 0) && (*(char *)(&planData[-1].field_0x43 + uVar14) == '\x01')) &&
               (bVar13 != 0)) {
              do {
                uVar9 = uVar14 - 1;
                if ((*(char *)(&planData[-1].field_0x43 + uVar14) != '\x01') || (uVar9 == 0)) {
                  planSlot->wayPointBeingServoedTo = (char)uVar9;
                  planData->nodeSkipArray[uVar14] = '\x02';
                  break;
                }
                uVar14 = uVar9;
              } while (0 < (int)uVar9);
            }
          }
          else {
            iVar5 = (uint)(byte)planSlot->wayPointBeingServoedTo + 1;
            iVar10 = iVar5 * 6 + 0x10;
            bVar13 = planData->nodeTypeArray[(uint)(byte)planSlot->wayPointBeingServoedTo + 1] >> 3
                     & 3;
            if (((puVar12[8] >> 3 & 3) == bVar13) &&
               (bVar3 = puVar12[8] >> 3 & 3, *puVar12 != '\x02')) {
              do {
                bVar2 = bVar13;
                if (bVar3 != 0) goto LAB_800967d8;
                nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar10);
                iVar6 = ENMYPLAN_WayPointSkipped(&instance->position,targetPos_00,nextTargetPos);
                puVar11 = planData->nodeSkipArray + uVar14;
                if (iVar6 == 0) break;
                if ((int)((uint)(planSlot->planData).numWayPoints - 2) <=
                    (int)(uint)(byte)planSlot->wayPointBeingServoedTo) goto LAB_800967d8;
                *puVar12 = '\x01';
                puVar12 = puVar12 + 1;
                uVar14 = uVar14 + 1;
                iVar10 = iVar10 + 6;
                planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01';
                bVar13 = planData->nodeTypeArray[iVar5 + 1] >> 3 & 3;
                targetPos_00 = nextTargetPos;
                if (bVar2 != bVar13) goto LAB_800967d8;
                puVar11 = planData->nodeSkipArray + uVar14;
                iVar5 = iVar5 + 1;
                bVar3 = bVar2;
              } while (*puVar12 != '\x02');
            }
            else {
LAB_800967d8:
              puVar11 = planData->nodeSkipArray + uVar14;
            }
            *puVar11 = '\x02';
          }
          iVar5 = ENMYPLAN_WayPointReached
                            (&instance->position,&planSlot->oldCurrentPos,targetPos_00);
          if ((iVar5 != 0) &&
             (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
             (int)((uint)(planSlot->planData).numWayPoints - 1) <=
             (int)(uint)(byte)planSlot->wayPointBeingServoedTo)) {
            planSlot->state = '\x03';
            PLANAPI_DeleteNodesFromPoolByType(2);
            PLANAPI_DeleteNodesFromPoolByType(3);
          }
        }
        else {
          if (bVar13 == 3) {
            lVar7 = MATH3D_LengthXYZ((int)targetPos->x - (int)(instance->position).x,
                                     (int)targetPos->y - (int)(instance->position).y,
                                     (int)targetPos->z - (int)(instance->position).z);
            if (0x400 < lVar7) {
              targetPos_00 = planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo;
              lVar7 = MATH3D_LengthXYZ((int)targetPos->x - (int)targetPos_00->x,
                                       (int)targetPos->y - (int)targetPos_00->y,
                                       (int)targetPos->z - (int)targetPos_00->z);
              if (0x400 < lVar7) {
                ENMYPLAN_Replan(planSlot);
              }
            }
            sVar8 = targetPos->z;
            *(undefined4 *)outputPos = *(undefined4 *)targetPos;
            outputPos->z = sVar8;
          }
        }
      }
    }
    sVar8 = (instance->position).z;
    *(undefined4 *)&planSlot->oldCurrentPos = *(undefined4 *)&instance->position;
    (planSlot->oldCurrentPos).z = sVar8;
    switch(planSlot->state) {
    case '\0':
    case '\x01':
      iVar5 = 0;
      break;
    case '\x02':
      iVar5 = 1;
      break;
    case '\x03':
      iVar5 = 2;
      break;
    default:
      iVar5 = 3;
    }
    gameTrackerX.plan_collide_override = '\0';
  }
  return iVar5;
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

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  
  pvVar3 = gameTrackerX.enemyPlanPool;
  iVar1 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool,slotID);
  if (iVar1 == 0) {
    uVar2 = 0x40;
  }
  else {
    pvVar3 = (void *)((int)pvVar3 + slotID * 0x5e);
    uVar2 = (uint)*(byte *)((int)pvVar3 + (uint)*(byte *)((int)pvVar3 + 2) + 0x1e);
  }
  return uVar2;
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

int ENMYPLAN_GetPosOfNextWaypoint(int slotID,_Position *pos)

{
  short sVar1;
  short sVar2;
  int iVar3;
  void *pvVar4;
  short *psVar5;
  
  pvVar4 = gameTrackerX.enemyPlanPool;
  iVar3 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool,slotID);
  if (iVar3 != 0) {
    pvVar4 = (void *)((int)pvVar4 + slotID * 0x5e);
    psVar5 = (short *)((int)pvVar4 + (uint)*(byte *)((int)pvVar4 + 2) * 6 + 0x26);
    sVar1 = psVar5[1];
    sVar2 = psVar5[2];
    pos->x = *psVar5;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (uint)(iVar3 != 0);
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

short ENMYPLAN_ReportCurrentGoalUnitID(int slotID)

{
  if (slotID != -1) {
    return *(short *)((int)gameTrackerX.enemyPlanPool + slotID * 0x5e + 0x56);
  }
  return 0;
}





