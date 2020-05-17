#ifndef SWIM_H
#define SWIM_H


extern void StateHandlerInitSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009EE2C

extern void StateHandlerSwimCoil(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009EF38

extern void StateHandlerSwimTread(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009F6B8

extern void StateHandlerSwimDiveIn(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009FE80

extern void StateHandlerSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A020C


#endif
