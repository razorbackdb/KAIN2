#ifndef SNMAIN_H
#define SNMAIN_H


extern void __SN_ENTRY_POINT() ; // 0x800B69F8

extern void __main() ; // 0x800B6AA0

extern void __initialised() ; // 0x800CC850

extern void __heapbase() ; // 0x800CC854

extern void __heapsize() ; // 0x800CC858

extern void __text() ; // 0x800CC85C

extern void __textlen() ; // 0x800CC860

extern void __data() ; // 0x800CC864

extern void __datalen() ; // 0x800CC868

extern void __bss() ; // 0x800CC86C

extern void __bsslen() ; // 0x800CC870

extern void the_cine_table() ; // 0x800CC874

extern void __ra_temp() ; // 0x800D7484

extern void voiceTracker() ; // 0x800D7488


#endif
