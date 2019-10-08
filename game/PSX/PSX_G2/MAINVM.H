#ifndef MAINVM_H
#define MAINVM_H

struct _G2AppDataVM_Type 
{
	int argc; 
	int *argv; 
};

static struct _G2AppDataVM_Type _appDataVM;

extern int main(); 


#endif
