#include "vector.h"
#include "../main.h"

struct MATRIX4X4
{
  VECTOR right;
  DWORD flags;
  VECTOR up;
  float pad_u;
  VECTOR at;
  float pad_a;
  VECTOR pos;
  float pad_p;
};