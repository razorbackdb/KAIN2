#include "THISDUST.H"
#include "SCRIPT2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LitShaftInit(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 127, offset 0x80060afc
	/* begin block 1 */
		// Start line: 128
		// Start offset: 0x80060AFC
		// Variables:
	// 		struct LitShaftProperties *Prop; // $s0

		/* begin block 1.1 */
			// Start line: 133
			// Start offset: 0x80060B20
			// Variables:
		// 		int curTimeOfDay; // $v1
		/* end block 1.1 */
		// End offset: 0x80060B78
		// End Line: 146
	/* end block 1 */
	// End offset: 0x80060B78
	// End Line: 147

	/* begin block 2 */
		// Start line: 188
	/* end block 2 */
	// End Line: 189

	/* begin block 3 */
		// Start line: 254
	/* end block 3 */
	// End Line: 255

void LitShaftInit(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  psVar3 = (short *)instance->data;
  if (psVar3 == (short *)0x0) {
    return;
  }
  iVar2 = GAMELOOP_GetTimeOfDay();
  if (iVar2 != 700) {
    if (iVar2 < 0x2bd) {
      sVar1 = 0x1000;
      if (iVar2 != 600) {
        return;
      }
      goto code_r0x80060b74;
    }
    if (iVar2 != 0x708) {
      if (iVar2 != 0x76c) {
        return;
      }
      instance->fadeValue = 0x1000;
      return;
    }
  }
  sVar1 = *psVar3;
code_r0x80060b74:
  instance->fadeValue = sVar1;
  return;
}





