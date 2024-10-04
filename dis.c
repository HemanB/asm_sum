#include "facile.h"

/* Return 1 for success, else -1. */

int
facile_asm_showline(opcode_t op, int src, int dest)
{
#ifdef STUDENT
  printf("%d %d %d\n", op, src, dest);
#else
  /*
   * Error-checking is not required if/when we make this a lab.
   * We could even give them the switch and the error checking.
   */
  if (op < 0 || op > FIN)
    return -1;
  printf("%s ", op_templates[op].mnemonic);
  
  switch(op_templates[op].source_mode) {
  case IMMEDIATE:
    printf("$%d", src);
    break;
  case REGISTER:
    if (src < 0 || src >= NUMREGS)
      return -1;
    printf("r%d", src);
    break;
  case INDIRECT:
    if (src < 0 || src >= NUMREGS)
      return -1;
    printf("(r%d)", src);
    break;
  case NO_OPERAND:
    if (src != 0)
      return -1;
    printf("0");
    break;
  }

  printf(",");

  switch(op_templates[op].dest_mode) {
  case IMMEDIATE:
    printf("$%d", dest);
    break;
  case REGISTER:
    if (src < 0 || src >= NUMREGS)
      return -1;
    printf("r%d", dest);
    break;
  case INDIRECT:
    if (src < 0 || src >= NUMREGS)
      return -1;
    printf("(r%d)", dest);
    break;
  case NO_OPERAND:
    if (dest != 0)
      return -1;
    printf("0");
    break;
  }

  printf("\n");
#endif

  return 1;
}

