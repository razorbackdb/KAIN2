#ifndef ALGOCTRL_H
#define ALGOCTRL_H

extern void InitAlgorithmicWings(struct _Instance *instance);

extern void DeInitAlgorithmicWings(struct _Instance *instance);

extern void AlgorithmicWings(struct _Instance *instance, struct evAnimationControllerDoneData *ControllerData);

extern void AlgorithmicNeck(struct _Instance *Player, struct _Instance *Target);

#endif
