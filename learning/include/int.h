//
//  int.h
//  brain
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_int_h
#define brain_int_h

#define __OSX64__
#ifdef __OSX64__

typedef long            int64;
typedef int             int32;
typedef short           int16;
typedef char            int8;
typedef unsigned long   uint64;
typedef unsigned int    uint32;
typedef unsigned short  uint16;
typedef unsigned char   uint8;

typedef long double     float128;
typedef double          float64;
typedef float           float32;

#endif

#endif
