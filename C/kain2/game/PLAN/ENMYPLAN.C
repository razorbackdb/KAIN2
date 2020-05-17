#include "THISDUST.H"
#include "ENMYPLAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool /*$a0*/)
 // line 107, offset 0x800966e4
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x800966E4
		// Variables:
	// 		int i; // $v0
	/* end block 1 */
	// End offset: 0x800966FC
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
 // line 131, offset 0x80096704
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x80096704
		// Variables:
	// 		int slotID; // $a1
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8009673C
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
 // line 167, offset 0x80096744
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80096744
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s0
	// 		int slotID; // $a0
	/* end block 1 */
	// End offset: 0x8009678C
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
 // line 185, offset 0x800967a0
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x800967A0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	/* end block 1 */
	// End offset: 0x800967F4
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
 // line 208, offset 0x80096808
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x80096808
		// Variables:
	// 		long range[2]; // stack offset -40
	// 		struct _Position vector[2]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x80096808
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $v0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x80096808
		// End Line: 209

		/* begin block 1.2 */
			// Start line: 209
			// Start offset: 0x80096808
			// Variables:
		// 		short _x0; // $a0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $a1
		/* end block 1.2 */
		// End offset: 0x80096808
		// End Line: 209
	/* end block 1 */
	// End offset: 0x800968E0
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
 // line 235, offset 0x80096974
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x80096974
		// Variables:
	// 		long range[2]; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096A10
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
 // line 267, offset 0x80096a24
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
// int /*$ra*/ ENMYPLAN_PathClear(struct _Position *pos /*$s1*/, struct _Position *target /*$s0*/)
 // line 274, offset 0x80096a50
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x80096A50
		// Variables:
	// 		int len; // $a1
	// 		int oldPCO; // $s2
	// 		struct _Position *tpos; // $a1
	// 		struct _Position newTarget; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096BA8
	// End Line: 304

	/* begin block 2 */
		// Start line: 566
	/* end block 2 */
	// End Line: 567

int ENMYPLAN_PathClear(_Position *pos,_Position *target)

{
  uchar uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  _Position local_18;
  
  uVar1 = gameTrackerX.plan_collide_override;
  gameTrackerX.plan_collide_override = '\x01';
  iVar4 = (uint)(ushort)target->x - (uint)(ushort)pos->x;
  local_18.x = (short)iVar4;
  iVar5 = (uint)(ushort)target->y - (uint)(ushort)pos->y;
  local_18.y = (short)iVar5;
  iVar2 = (uint)(ushort)target->z - (uint)(ushort)pos->z;
  local_18.z = (short)iVar2;
  lVar3 = MATH3D_LengthXYZ(iVar4 * 0x10000 >> 0x10,iVar5 * 0x10000 >> 0x10,iVar2 * 0x10000 >> 0x10);
  if (0x500 < lVar3) {
    iVar2 = (((int)local_18.x << 0xc) / lVar3) * 0x500;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    iVar4 = (((int)local_18.y << 0xc) / lVar3) * 0x500;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    iVar5 = (((int)local_18.z << 0xc) / lVar3) * 0x500;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xfff;
    }
    local_18.x = (short)(iVar2 >> 0xc) + pos->x;
    local_18.y = (short)(iVar4 >> 0xc) + pos->y;
    target = &local_18;
    local_18.z = (short)(iVar5 >> 0xc) + pos->z;
  }
  iVar2 = PLANCOLL_DoesStraightLinePathExist(pos,target,0);
  gameTrackerX.plan_collide_override = uVar1;
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_MoveToTargetFinal(struct _Instance *instance /*stack 0*/, struct _Position *outputPos /*stack 4*/, int slotID /*$a2*/, struct _Position *targetPos /*$s1*/, int validNodeTypes /*stack 16*/)
 // line 313, offset 0x80096bd0
	/* begin block 1 */
		// Start line: 314
		// Start offset: 0x80096BD0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $a0
	// 		struct EnemyPlanSlotData *planSlot; // $s0
	// 		struct EnemyPlanData *planData; // $s5
	// 		int nextWayPointType; // $a0
	// 		int nextNextWayPointType; // $s2
	// 		int pathFound; // $v0
	// 		int nextWayPointIdx; // $s1
	// 		int nextNextWayPointIdx; // $s4
	// 		int nextWayPointSkip; // $a3
	// 		int i; // $v1
	// 		struct _Position *nextWayPointPos; // $s6
	// 		struct _Position *nextNextWayPointPos; // $fp
	/* end block 1 */
	// End offset: 0x800970AC
	// End Line: 540

	/* begin block 2 */
		// Start line: 664
	/* end block 2 */
	// End Line: 665

int ENMYPLAN_MoveToTargetFinal
              (_Instance *instance,_Position *outputPos,int slotID,_Position *targetPos,
              int validNodeTypes)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  uchar *puVar8;
  int iVar9;
  EnemyPlanSlotData *planSlot;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  uchar *puVar13;
  EnemyPlanData *planData;
  _Position *targetPos_00;
  _Position *nextTargetPos;
  
  pvVar2 = gameTrackerX.enemyPlanPool;
  gameTrackerX.plan_collide_override = '\x01';
  sVar6 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar6;
  if ((slotID == -1) || (9 < slotID)) {
    gameTrackerX.plan_collide_override = '\x01';
    return 2;
  }
  planSlot = (EnemyPlanSlotData *)((int)pvVar2 + slotID * 0x5e);
  bVar11 = planSlot->state;
  planData = &planSlot->planData;
  if (bVar11 == 1) {
    iVar5 = PLANAPI_FindPathInGraphToTarget(&planSlot->startPos,planData,validNodeTypes);
    sVar6 = planSlot->timer + 1;
    planSlot->timer = sVar6;
    if (iVar5 == 0) {
      if (100 < sVar6) {
        planSlot->state = '\x04';
      }
    }
    else {
      planSlot->state = '\x02';
      planSlot->wayPointBeingServoedTo = '\x01';
    }
    goto LAB_8009703c;
  }
  if (bVar11 < 2) {
    if (bVar11 == 0) {
      sVar6 = (instance->position).z;
      *(undefined4 *)&planSlot->startPos = *(undefined4 *)&instance->position;
      (planSlot->startPos).z = sVar6;
      sVar6 = targetPos->z;
      *(undefined4 *)&planSlot->goalPos = *(undefined4 *)targetPos;
      (planSlot->goalPos).z = sVar6;
      planSlot->timer = 0;
      iVar5 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos,3);
      if (iVar5 != 0) {
        PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos,2);
        planSlot->state = '\x01';
      }
    }
    goto LAB_8009703c;
  }
  if (bVar11 == 2) {
    bVar11 = planSlot->wayPointBeingServoedTo;
    uVar10 = (uint)bVar11;
    puVar13 = planData->nodeSkipArray + uVar10;
    targetPos_00 = planData->wayPointArray + uVar10;
    if (*puVar13 == '\x02') {
      iVar5 = ENMYPLAN_PathClear(&instance->position,targetPos_00);
      if (iVar5 == 0) {
        if (*(char *)(&planData[-1].field_0x43 + uVar10) == '\x01') {
          if (bVar11 != 0) {
            do {
              uVar7 = uVar10 - 1;
              if ((*(char *)(&planData[-1].field_0x43 + uVar10) != '\x01') || (uVar7 == 0)) {
                planSlot->wayPointBeingServoedTo = (char)uVar7;
                planData->nodeSkipArray[uVar10] = '\x02';
                break;
              }
              uVar10 = uVar7;
            } while (0 < (int)uVar7);
          }
        }
        else {
          ENMYPLAN_Replan(planSlot);
        }
      }
    }
    else {
      iVar5 = uVar10 + 1;
      iVar9 = iVar5 * 6 + 0x10;
      bVar11 = planData->nodeTypeArray[uVar10 + 1] >> 3 & 3;
      if ((puVar13[8] >> 3 & 3) == bVar11) {
        puVar8 = planData->nodeSkipArray + uVar10;
        if ((*puVar13 != '\x02') && ((puVar13[8] >> 3 & 3) == 0)) {
          do {
            nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar9);
            iVar3 = ENMYPLAN_WayPointSkipped(&instance->position,targetPos_00,nextTargetPos);
            puVar8 = planData->nodeSkipArray + uVar10;
            if (iVar3 == 0) goto LAB_80096ef0;
            if ((int)((uint)(planSlot->planData).numWayPoints - 2) <=
                (int)(uint)(byte)planSlot->wayPointBeingServoedTo) break;
            *puVar13 = '\x01';
            puVar13 = puVar13 + 1;
            uVar10 = uVar10 + 1;
            iVar9 = iVar9 + 6;
            planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01';
            bVar12 = planData->nodeTypeArray[iVar5 + 1] >> 3 & 3;
            targetPos_00 = nextTargetPos;
            if (bVar11 != bVar12) break;
            puVar8 = planData->nodeSkipArray + uVar10;
            if (*puVar13 == '\x02') goto LAB_80096ef0;
            bVar1 = bVar11 == 0;
            iVar5 = iVar5 + 1;
            bVar11 = bVar12;
          } while (bVar1);
          goto LAB_80096ee8;
        }
      }
      else {
LAB_80096ee8:
        puVar8 = planData->nodeSkipArray + uVar10;
      }
LAB_80096ef0:
      *puVar8 = '\x02';
    }
    iVar5 = ENMYPLAN_WayPointReached(&instance->position,&planSlot->oldCurrentPos,targetPos_00);
    if ((iVar5 != 0) &&
       (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
       (int)((uint)(planSlot->planData).numWayPoints - 1) <=
       (int)(uint)(byte)planSlot->wayPointBeingServoedTo)) {
      planSlot->state = '\x03';
      PLANAPI_DeleteNodesFromPoolByType(2);
      PLANAPI_DeleteNodesFromPoolByType(3);
    }
    sVar6 = planData->wayPointArray[(byte)planSlot->wayPointBeingServoedTo].z;
    *(undefined4 *)outputPos =
         *(undefined4 *)(planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo);
    outputPos->z = sVar6;
    goto LAB_8009703c;
  }
  if (bVar11 != 3) goto LAB_8009703c;
  iVar5 = ENMYPLAN_PathClear(&instance->position,targetPos);
  if (iVar5 == 0) {
LAB_80097018:
    ENMYPLAN_Replan(planSlot);
  }
  else {
    lVar4 = MATH3D_LengthXYZ((int)targetPos->x - (int)(instance->position).x,
                             (int)targetPos->y - (int)(instance->position).y,
                             (int)targetPos->z - (int)(instance->position).z);
    targetPos_00 = planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo;
    if ((0x400 < lVar4) &&
       (lVar4 = MATH3D_LengthXYZ((int)targetPos->x - (int)targetPos_00->x,
                                 (int)targetPos->y - (int)targetPos_00->y,
                                 (int)targetPos->z - (int)targetPos_00->z), 0x400 < lVar4))
    goto LAB_80097018;
  }
  sVar6 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar6;
LAB_8009703c:
  sVar6 = (instance->position).z;
  *(undefined4 *)&planSlot->oldCurrentPos = *(undefined4 *)&instance->position;
  (planSlot->oldCurrentPos).z = sVar6;
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
  return iVar5;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ValidSlotAndState(struct EnemyPlanSlotData *pool /*$a0*/, int slotID /*$a1*/)
 // line 542, offset 0x800970dc
	/* begin block 1 */
		// Start line: 1206
	/* end block 1 */
	// End Line: 1207

	/* begin block 2 */
		// Start line: 1208
	/* end block 2 */
	// End Line: 1209

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
 // line 555, offset 0x80097120
	/* begin block 1 */
		// Start line: 556
		// Start offset: 0x80097120
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v0
	/* end block 1 */
	// End offset: 0x80097178
	// End Line: 568

	/* begin block 2 */
		// Start line: 1232
	/* end block 2 */
	// End Line: 1233

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
 // line 570, offset 0x8009718c
	/* begin block 1 */
		// Start line: 571
		// Start offset: 0x8009718C
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v1

		/* begin block 1.1 */
			// Start line: 575
			// Start offset: 0x800971C0
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x800971C0
		// End Line: 575
	/* end block 1 */
	// End offset: 0x80097214
	// End Line: 584

	/* begin block 2 */
		// Start line: 1270
	/* end block 2 */
	// End Line: 1271

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
// void /*$ra*/ ENMYPLAN_RelocatePlanPositions(int slotID /*$a0*/, struct _Position *offset /*$t2*/)
 // line 641, offset 0x8009722c
	/* begin block 1 */
		// Start line: 642
		// Start offset: 0x8009722C
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $v1
	// 		struct EnemyPlanSlotData *planSlot; // $t1
	// 		struct _Position *pos; // $a0
	// 		int i; // $a3
	// 		int numWayPoints; // $v1

		/* begin block 1.1 */
			// Start line: 659
			// Start offset: 0x80097280
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		/* end block 1.1 */
		// End offset: 0x80097280
		// End Line: 659
	/* end block 1 */
	// End offset: 0x800972C0
	// End Line: 663

	/* begin block 2 */
		// Start line: 1282
	/* end block 2 */
	// End Line: 1283

	/* begin block 3 */
		// Start line: 1370
	/* end block 3 */
	// End Line: 1371

void ENMYPLAN_RelocatePlanPositions(int slotID,_Position *offset)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  void *pvVar7;
  
  pvVar7 = (void *)((int)gameTrackerX.enemyPlanPool + slotID * 0x5e);
  bVar1 = *(byte *)((int)pvVar7 + 0x58);
  uVar4 = (uint)bVar1;
  if ((((slotID != -1) && (slotID < 10)) && (bVar1 < 8)) && (bVar1 != 0)) {
    iVar6 = uVar4 * 6 + 0x26;
    do {
      iVar6 = iVar6 + -6;
      uVar4 = uVar4 - 1;
      psVar5 = (short *)((int)pvVar7 + iVar6);
      sVar2 = offset->y;
      sVar3 = offset->z;
      *psVar5 = *psVar5 + offset->x;
      psVar5[1] = psVar5[1] + sVar2;
      psVar5[2] = psVar5[2] + sVar3;
    } while (0 < (int)uVar4);
  }
  return;
}





