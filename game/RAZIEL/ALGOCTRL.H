#ifndef ALGOCTRL_H
#define ALGOCTRL_H


extern void InitAlgorithmicWings(struct _Instance *instance); // 0x8009E7D8

extern void DeInitAlgorithmicWings(struct _Instance *instance); // 0x8009E970

extern void AlgorithmicWings(struct _Instance *instance, struct evAnimationControllerDoneData *ControllerData); // 0x8009EA00

extern void AlgorithmicNeck(struct _Instance *Player, struct _Instance *Target); // 0x8009EA70


#endif
