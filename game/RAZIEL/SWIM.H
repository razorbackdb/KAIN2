#ifndef SWIM_H
#define SWIM_H


extern void StateHandlerInitSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009E290

extern void StateHandlerSwimCoil(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009E3A4

extern void StateHandlerSwimTread(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009EA74

extern void StateHandlerSwimDiveIn(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009F234

extern void StateHandlerSwim(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009F590


#endif
