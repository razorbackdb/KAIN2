#include "THISDUST.H"
#include "MCASSERT.H"

void mcassert(char *exp, char *file, long line)

{
  if (exp == (char *)0x0)
  {
    printf("%s:%ld: assertion failure\n");
  }
  else
  {
    printf("%s:%ld: %s\n");
  }
  trap(0x407);
  return;
}
