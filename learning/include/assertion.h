//
//  assertion.h
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_assertion_h
#define learning_assertion_h

#define check_null( val, errno )                          \
  if ( val == NULL )                                      \
    return errno

#define check_code( code, errno )                         \
  if ( code != 0 )                                        \
    return errno

#endif
