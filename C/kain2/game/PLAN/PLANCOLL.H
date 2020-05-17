#ifndef PLANCOLL_H
#define PLANCOLL_H


extern int PLANCOLL_DoesLOSExistFinal(struct _Position *startPos, struct _Position *endPos, int collideType, int passThroughHit, int zoffset); // 0x80098AE0

extern int PLANCOLL_CheckUnderwaterPoint(struct _Position *position); // 0x80098BE4

extern int PLANCOLL_FindTerrainHitFinal(struct _PlanCollideInfo *pci, int *placement, int distBefore, int distAfter, int start, int end); // 0x80098D50

extern int PLANCOLL_DoesStraightLinePathExist(struct _Position *startPos, struct _Position *endPos, int collideType); // 0x80099010

extern int PLANCOLL_DoesWaterPathUpExist(struct _Position *startPos, struct _Position *endPos, int collideType, struct _Position *peakPos, int passThroughHit); // 0x8009909C


#endif
