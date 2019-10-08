#ifndef PLANCOLL_H
#define PLANCOLL_H

extern int PLANCOLL_DoesLOSExistFinal(struct _Position *startPos, struct _Position *endPos, int collideType, int passThroughHit, int zoffset);

extern int PLANCOLL_CheckUnderwaterPoint(struct _Position *position);

extern int PLANCOLL_FindTerrainHitFinal(struct _PlanCollideInfo *pci, int *placement, int distBefore, int distAfter, int start, int end);

extern int PLANCOLL_DoesStraightLinePathExist(struct _Position *startPos, struct _Position *endPos, int collideType);

extern int PLANCOLL_DoesWaterPathUpExist(struct _Position *startPos, struct _Position *endPos, int collideType, struct _Position *peakPos, int passThroughHit);

#endif
