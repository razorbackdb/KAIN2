#ifndef PLANCOLL_H
#define PLANCOLL_H


extern int PLANCOLL_DoesLOSExistFinal(struct _Position *startPos, struct _Position *endPos, int collideType, int passThroughHit, int zoffset); // 0x800964E0

extern int PLANCOLL_CheckUnderwaterPoint(struct _Position *position); // 0x800965EC

extern int PLANCOLL_FindTerrainHitFinal(struct _PlanCollideInfo *pci, int *placement, int distBefore, int distAfter, int start, int end); // 0x80096760

extern int PLANCOLL_DoesStraightLinePathExist(struct _Position *startPos, struct _Position *endPos, int collideType); // 0x80096A30

extern int PLANCOLL_DoesWaterPathUpExist(struct _Position *startPos, struct _Position *endPos, int collideType, struct _Position *peakPos, int passThroughHit); // 0x80096AAC


#endif
