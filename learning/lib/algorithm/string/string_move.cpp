//
//  string_copy.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "string_move.h"
#include <cstdarg>

namespace alg {

#ifdef __cplusplus
  extern "C"
  {
#endif

    int strcpy( char *dst, const char *src )
    {
      int len = 0;
      while ( src[len] != 0 )
      {
        dst[len] = src[len];
        ++len;
      }

      dst[len] = 0;
      return len;
    }

#ifdef __cplusplus
  }
#endif
}
