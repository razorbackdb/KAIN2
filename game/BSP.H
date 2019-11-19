#ifndef BSP_H
#define BSP_H


extern void BSP_TraverseIntrosWithVV(struct _BSPNode *root, struct _CameraCore_Type *cameraCore); // 0x8003EBAC

extern void SBSP_IntroduceInstancesAndLightsInLeaf(struct _SBSPLeaf *sbspLeaf); // 0x8003EDDC

extern void SBSP_IntroduceInstances(struct _Terrain *terrain, int unitID); // 0x8003EE84

extern void SBSP_IntroduceInstancesAndLights(struct _Terrain *terrain, struct _CameraCore_Type *cameraCore, struct LightInfo *lightInfo, int unitID); // 0x8003EF3C


#endif
