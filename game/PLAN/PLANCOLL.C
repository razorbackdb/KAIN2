#include "THISDUST.H"
#include "PLANCOLL.H"

int PLANCOLL_DoesLOSExistFinal(_Position *startPos, _Position *endPos, int collideType, int passThroughHit, int zoffset)

{
	u_int uVar1;
	_PCollideInfo local_48;
	SVECTOR local_18;
	SVECTOR local_10;

	local_18.vx = startPos->x;
	local_18.vy = startPos->y;
	local_48.oldPoint = &local_18;
	local_10.vx = endPos->x;
	local_10.vy = endPos->y;
	local_48.newPoint = &local_10;
	local_48.collideType = 0x127;
	local_48.inst = (_Instance *)0x0;
	local_48.instance = (_Instance *)0x0;
	local_18.vz = startPos->z + (short)zoffset;
	local_10.vz = endPos->z + (short)zoffset;
	COLLIDE_PointAndTerrain(&local_48, (Level *)0x0);
	if ((((passThroughHit == 0) || (local_48.type != 3)) ||
		 (*(u_short *)((int)local_48.prim + 10) == 0xffff)) ||
		(uVar1 = 1,
		 (*(u_short *)((int)&((local_48.inst)->node).prev[6].next[1].prev +
					   (u_int) * (u_short *)((int)local_48.prim + 10) + 2) &
		  0x1000) == 0))
	{
		uVar1 = (u_int)(local_48.type == 0);
	}
	return uVar1;
}

int PLANCOLL_CheckUnderwaterPoint(_Position *position)

{
	long lVar1;
	BSPTree *pBVar2;
	_BSPNode *p_Var3;
	Level **ppLVar4;
	Level *pLVar5;
	int iVar6;
	STracker *pSVar7;

	pSVar7 = &StreamTracker;
	iVar6 = 0x10;
	ppLVar4 = &StreamTracker.StreamList[0].level;
	do
	{
		if ((*(short *)(ppLVar4 + -1) == 2) &&
			(lVar1 = MEMPACK_ReportMemory((char *)*ppLVar4), lVar1 != 0))
		{
			pLVar5 = *ppLVar4;
			pBVar2 = pLVar5->terrain->BSPTreeArray;
			p_Var3 = pBVar2->bspRoot;
			lVar1 = MATH3D_LengthXY((int)position->x -
										(int)(short)((p_Var3->sphere).position.x + (pBVar2->globalOffset).x),
									(int)position->y -
										(int)(short)((p_Var3->sphere).position.y + (pBVar2->globalOffset).y),
									(int)position->z -
										(int)(short)((p_Var3->sphere).position.z + (pBVar2->globalOffset).z));
			if ((lVar1 < (int)(u_int)(p_Var3->sphere).radius) && ((int)position->z < pLVar5->waterZLevel))
			{
				return pSVar7->StreamList[0].StreamUnitID;
			}
		}
		iVar6 = iVar6 + -1;
		ppLVar4 = ppLVar4 + 0x10;
		pSVar7 = (STracker *)(pSVar7->StreamList + 1);
		if (iVar6 == 0)
		{
			return -1;
		}
	} while (true);
}

int PLANCOLL_FindTerrainHitFinal(struct _PlanCollideInfo *pci, int *placement, int distBefore, int distAfter, int start, int end)
{

	struct _PCollideInfo pcollideinfo;
	struct _fth *current;
	struct _fth *last;
	struct SVECTOR startPt;
	struct SVECTOR endPt;
	struct _SVector normal;

	short _x1;
	short _y1;
	short _z1;
	struct _Position *_v0;
	struct _Position *_v1;

	short _x1;
	short _y1;
	short _z1;
	struct _Position *_v0;

	short _y1;
	short _z1;

	return 0;
}

int PLANCOLL_DoesWaterPathUpExist(_Position *startPos, _Position *endPos, int collideType)

{
	bool bVar1;
	int iVar2;
	u_int uVar3;

	uVar3 = 0;
	bVar1 = gameTrackerX.gameFlags < 0;
	iVar2 = PLANCOLL_DoesLOSExistFinal(startPos, endPos, collideType, (u_int)bVar1, 0x100);
	if (iVar2 != 0)
	{
		iVar2 = PLANCOLL_DoesLOSExistFinal(startPos, endPos, collideType, (u_int)bVar1, 0x3c0);
		uVar3 = (u_int)(iVar2 != 0);
	}
	return uVar3;
}

int PLANCOLL_DoesStraightLinePathExist(_Position *startPos, _Position *endPos, int collideType, _Position *peakPos,
									   int passThroughHit)

{
	short sVar1;
	short sVar2;
	long lVar3;
	long lVar4;
	int iVar5;

	lVar3 = MATH3D_FastSqrt(0x50000);
	iVar5 = ((u_int)(u_short)startPos->z - (u_int)(u_short)endPos->z) + 0x280;
	peakPos->z = (short)iVar5;
 3);
 if (lVar4 < 0)
 {
	 lVar4 = lVar4 + 0xf;
 }
 iVar5 = lVar4 >> 4;
 sVar1 = endPos->y;
 sVar2 = startPos->y;
  peakPos->x = endPos->x +
               (short)((((int)(((u_int)(u_short)startPos->x - (u_int)(u_short)endPos->x) * 0x10000) >>
 (lVar3 + iVar5));
 (lVar3 + iVar5));
  iVar5 = PLANCOLL_DoesLOSExistFinal(startPos,peakPos,collideType,passThroughHit,0);
  return iVar5;
}
