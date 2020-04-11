#ifndef ALGOCTRL_H
#define ALGOCTRL_H


extern void InitAlgorithmicWings(struct _Instance *instance); // 0x800A0F00

extern void DeInitAlgorithmicWings(struct _Instance *instance); // 0x800A1098

extern void AlgorithmicWings(struct _Instance *instance, struct evAnimationControllerDoneData *ControllerData); // 0x800A1128

extern void AlgorithmicNeck(struct _Instance *Player, struct _Instance *Target); // 0x800A1198


#endif
