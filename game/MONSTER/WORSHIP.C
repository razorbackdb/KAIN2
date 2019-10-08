#include "THISDUST.H"
#include "WORSHIP.H"

void WORSHIP_Init(_Instance *instance)

{
  byte bVar1;
  undefined2 uVar2;
  _Instance *p_Var3;
  int weaponid;
  void *pvVar4;
  void *pvVar5;

  pvVar5 = instance->extraData;
  pvVar4 = instance->data;
  weaponid = 0xc;
  if (*(char *)((int)pvVar5 + 0x15a) == '\0')
  {
    bVar1 = *(byte *)((int)pvVar4 + 0x24);
  }
  else
  {
    HUMAN_CreateWeapon(instance, 0xb, (u_int) * (byte *)((int)pvVar4 + 0x23));
    bVar1 = *(byte *)((int)pvVar4 + 0x24);
    weaponid = 0xb;
  }
  p_Var3 = HUMAN_CreateWeapon(instance, weaponid, (u_int)bVar1);
  if (p_Var3 != (_Instance *)0x0)
  {
    HUMAN_Init(instance);
  }
  uVar2 = 0x6000;
  if (*(char *)((int)pvVar5 + 0x15a) == '\0')
  {
    uVar2 = 0x5000;
  }
  *(undefined2 *)((int)pvVar5 + 0x144) = uVar2;
  return;
}

void WORSHIP_CombatEntry(_Instance *instance)

{
  _Instance *instance_00;
  u_int *puVar1;
  void *pvVar2;

  puVar1 = (u_int *)instance->extraData;
  if (((puVar1[0x31] != 0) &&
       (*(short *)(puVar1[0x31] + 0x14) < *(short *)(*(int *)(puVar1[0x59] + 8) + 10))) &&
      (*(char *)((int)puVar1 + 0x15a) == '\x01'))
  {
    instance_00 = instance->LinkChild;
    pvVar2 = instance->data;
    if (instance_00 == (_Instance *)0x0)
    {
      HUMAN_CreateWeapon(instance, 0xb, (u_int) * (byte *)((int)pvVar2 + 0x23));
    }
    else
    {
      if ((instance_00->LinkSibling != (_Instance *)0x0) ||
          (instance_00->ParentLinkNode != (u_int) * (byte *)((int)pvVar2 + 0x24)))
        goto LAB_8008ebd8;
      INSTANCE_UnlinkFromParent(instance_00);
      INSTANCE_LinkToParent(instance_00, instance, (u_int) * (byte *)((int)pvVar2 + 0x23));
    }
    *puVar1 = *puVar1 | 0x20;
  }
LAB_8008ebd8:
  MON_CombatEntry(instance);
  return;
}
