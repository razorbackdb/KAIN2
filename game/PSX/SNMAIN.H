#ifndef SNMAIN_H
#define SNMAIN_H


extern void __SN_ENTRY_POINT() ; // 0x800B566C

extern void __main() ; // 0x800B5714

extern void __initialised() ; // 0x800CB584

extern void __heapbase() ; // 0x800CB588

extern void __heapsize() ; // 0x800CB58C

extern void __text() ; // 0x800CB590

extern void __textlen() ; // 0x800CB594

extern void __data() ; // 0x800CB598

extern void __datalen() ; // 0x800CB59C

extern void __bss() ; // 0x800CB5A0

extern void __bsslen() ; // 0x800CB5A4

extern void the_cine_table() ; // 0x800CB5A8

extern void __ra_temp() ; // 0x800D6000

extern void voiceTracker() ; // 0x800D6004


#endif
