#ifndef ALGOCTRL_H
#define ALGOCTRL_H


extern void InitAlgorithmicWings(struct _Instance *instance); // 0x800A1B54

extern void DeInitAlgorithmicWings(struct _Instance *instance); // 0x800A1CEC

extern void AlgorithmicWings(struct _Instance *instance, struct evAnimationControllerDoneData *ControllerData); // 0x800A1D7C

extern void AlgorithmicNeck(struct _Instance *Player, struct _Instance *Target); // 0x800A1DEC


#endif
