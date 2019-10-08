#ifndef SWIM_H
#define SWIM_H

extern void StateHandlerInitSwim(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSwimCoil(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSwimTread(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSwimDiveIn(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSwim(struct __CharacterState *In, int CurrentSection, int Data);

#endif
