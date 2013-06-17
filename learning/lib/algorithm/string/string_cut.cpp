//
//  string_cut.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 6/1/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "string_cut.h"
#include <stdarg.h>
#include <string.h>

namespace alg {

#ifdef __cplusplus
  extern "C"
  {
#endif

    int strspl( const char *src, char delim, int npart, ... )
    {
      if ( npart < 1 )
        return 0;

      va_list para;
      char *buf;
      int buf_len;

      va_start( para, npart );
      buf = va_arg( para, char* );
      buf_len = va_arg( para, int );

      int parsed_part = 0;
      int parsed_len = 0;
      while ( *src )
      {
        if ( *src == delim )
        {
          buf[ parsed_len ] = 0;
          ++parsed_part;
          parsed_len = 0;

          if ( parsed_part < npart )
          {
            buf = va_arg( para, char* );
            buf_len = va_arg( para, int );
          }
          else
          {
            break;
          }
        }
        else if ( parsed_len < buf_len-1 )
        {
          buf[ parsed_len++ ] = *src;
        }
        ++src;
      }
      buf[ parsed_len ] = 0;

      return parsed_part + 1;
    }

    int strspl_npart( const char *src, char delim )
    {
      int n = 1;
      while ( *src )
      {
        if ( *src == delim )
          ++n;
        ++src;
      }
      return n;
    }

    void strspl_right( const char *src, char delim, char *buf, int buflen,
                      char *buf_for_remain, int remainlen )
    {
      size_t srclen;
      int delimpos;
      srclen = strlen( src );

      delimpos = (int)srclen;
      while ( delimpos > 0 && src[ delimpos ] != delim )
        --delimpos;

      if ( srclen - delimpos > buflen )
        strncpy( buf, src + delimpos + 1, buflen );
      else
        strncpy( buf, src + delimpos + 1, srclen - delimpos );

      if ( delimpos > 0 )
      {
        if ( delimpos-1 > remainlen )
          strncpy( buf_for_remain, src, remainlen );
        else
          strncpy( buf_for_remain, src, delimpos - 1 );
      }
    }

#ifdef __cplusplus
  }
#endif
}