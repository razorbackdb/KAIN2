#include "THISDUST.H"
#include "PLANSRCH.H"

PlanningNode *
PLANSRCH_ExpandNode(PlanningNode *planningPool, PlanningNode *goalNode, int validNodeTypes)

{
  long lVar1;
  u_int uVar2;
  PlanningNode *pPVar3;
  int iVar4;
  PlanningNode *pPVar5;
  u_int uVar6;

  uVar6 = 0xffffffff;
  iVar4 = 0;
  pPVar5 = (PlanningNode *)0x0;
  pPVar3 = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      if ((((validNodeTypes >> ((u_int)planningPool->nodeType & 0x1f) & 1U) != 0) &&
           ((planningPool->flags & 1) != 0)) &&
          ((planningPool->flags & 2) == 0))
      {
        lVar1 = MATH3D_LengthXY((int)(pPVar3->pos).x - (int)(goalNode->pos).x,
                                (int)(planningPool->pos).y - (int)(goalNode->pos).y,
                                (int)(planningPool->pos).z - (int)(goalNode->pos).z);
        uVar2 = (u_int)planningPool->cost + lVar1;
        if (uVar2 <= uVar6)
        {
          pPVar5 = planningPool;
          uVar6 = uVar2;
        }
      }
      planningPool = planningPool + 1;
      iVar4 = iVar4 + 1;
      pPVar3 = pPVar3 + 1;
    } while (iVar4 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return pPVar5;
}

void PLANSRCH_FindNodeToExpand(PlanningNode *planningPool, PlanningNode *nodeToExpand)

{
  u_short uVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;

  iVar2 = poolManagementData;
  iVar3 = 0;
  nodeToExpand->flags = nodeToExpand->flags | 2;
  uVar5 = (int)((int)nodeToExpand - (int)planningPool) * -0x49249249 >> 2;
  uVar4 = 1 << (uVar5 & 0x1f);
  if (*(char *)(iVar2 + 1) != '\0')
  {
    do
    {
      if (((((planningPool->connectionStatus & uVar4) != 0) &&
            ((planningPool->connections & uVar4) != 0)) &&
           (planningPool != nodeToExpand)) &&
          ((iVar2 = (u_int)nodeToExpand->cost +
                    (int)*(short *)(iVar3 * 2 + uVar5 * 0x40 + *(int *)(iVar2 + 0x10)),
            (planningPool->flags & 1) == 0 || (iVar2 < (int)(u_int)planningPool->cost))))
      {
        planningPool->parent = (u_short)uVar5;
        if (iVar2 < -0x7fff)
        {
          iVar2 = -0x7fff;
        }
        uVar1 = (u_short)iVar2;
        if (0x7fff < iVar2)
        {
          uVar1 = 0x7fff;
        }
        planningPool->cost = uVar1;
        planningPool->flags = planningPool->flags | 1;
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
      iVar2 = poolManagementData;
    } while (iVar3 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return;
}

void PLANSRCH_InitNodesForSearch(PlanningNode *planningPool)

{
  int iVar1;
  int iVar2;

  iVar1 = poolManagementData;
  iVar2 = 0;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      iVar2 = iVar2 + 1;
      planningPool->cost = 0;
      planningPool->parent = 0;
      planningPool->flags = planningPool->flags & 0xfffc;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(u_int) * (byte *)(iVar1 + 1));
  }
  return;
}

PlanningNode *
PLANAPI_FindPathInGraphToTarget(PlanningNode *planningPool, PlanningNode *startNode, PlanningNode *goalNode,
                                int validNodeTypes)

{
  int iVar1;
  PlanningNode *nodeToExpand;
  u_short uVar2;

  if ((goalNode->connections &
       ~(1 << ((int)((int)goalNode - (int)planningPool) * -0x49249249 >> 2 & 0x1fU))) != 0)
  {
    PLANSRCH_InitNodesForSearch(planningPool);
    uVar2 = (u_short)((int)((int)startNode - (int)planningPool) * -0x49249249 >> 2);
    startNode->parent = uVar2;
    startNode->cost = 0;
    startNode->flags = startNode->flags | 1;
    iVar1 = PLANPOOL_AreTwoNodesConnected(startNode, goalNode, planningPool);
    if (iVar1 != 0)
    {
      goalNode->parent = uVar2;
      return goalNode;
    }
    while (nodeToExpand = PLANSRCH_ExpandNode(planningPool, goalNode, validNodeTypes),
           nodeToExpand != (PlanningNode *)0x0)
    {
      if (nodeToExpand == goalNode)
      {
        return nodeToExpand;
      }
      PLANSRCH_FindNodeToExpand(planningPool, nodeToExpand);
    }
  }
  return (PlanningNode *)0x0;
}
