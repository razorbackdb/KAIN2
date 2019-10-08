






#include "THISDUST.H"
#include "SNMAIN.H"





 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	



void start(void)

{
  DebugMenuLine *pDVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char uVar2;
  
  pDVar1 = &debugSoundMenu;
  do {
    pDVar1->type = DEBUG_LINE_TYPE_BIT;
    pDVar1 = (DebugMenuLine *)&pDVar1->lower;
  } while (pDVar1 < (DebugMenuLine *)&DAT_800de9fc);
  __heapsize = &DAT_0011d5fc;
  __heapbase = &DAT_800de9fc;
  __ra_temp = unaff_retaddr;
  InitHeap();
  uVar2 = 0x800b5710;
  main();
  trap(1);
  if (__initialised == 0) {
    __initialised = 1;
  }
  DAT_801fffec = unaff_s0;
  DAT_801ffff0 = unaff_s1;
  DAT_801ffff4 = uVar2;
  return;
}






 

		

	


		

	


		

	


		

	

void __main(void)

{
  if (__initialised == 0) {
    __initialised = 1;
  }
  return;
}





void __initialised() 
{ 

		

	

	return null;
}




void __heapbase() 
{ 
	return null;
}




void __heapsize() 
{ 
	return null;
}




void __text() 
{ 
	return null;
}




void __textlen() 
{ 
	return null;
}




void __data() 
{ 
	return null;
}




void __datalen() 
{ 
	return null;
}




void __bss() 
{ 
	return null;
}




void __bsslen() 
{ 
	return null;
}




void the_cine_table() 
{ 

		

	

	return null;
}




void __ra_temp() 
{ 

		

	

	return null;
}




void voiceTracker() 
{ 

		

	

	return null;
}




