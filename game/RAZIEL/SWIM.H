#ifndef SWIM_H
#define SWIM_H


extern void StateHandlerInitSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009BFBC

extern void StateHandlerSwimCoil(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009C0D0

extern void StateHandlerSwimTread(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009C674

extern void StateHandlerSwimDiveIn(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009CDA0

extern void StateHandlerSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009D0A8


#endif
