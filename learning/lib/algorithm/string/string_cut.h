//
//  string_cut.h
//  algorithm
//
//  Created by xiangyun.kongxy on 6/1/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__string_cut__
#define __algorithm__string_cut__

namespace alg {
#ifdef __cplusplus
  extern "C"
  {
#endif

    int strspl( const char *src, char delim, int npart, ... );
    int strspl_npart( const char *src, char delim );
    void strspl_right( const char *src, char delim, char *buf, int buflen,
                      char *buf_for_remain, int remainlen );

#ifdef __cplusplus
  }
#endif
}

#endif /* defined(__algorithm__string_cut__) */
