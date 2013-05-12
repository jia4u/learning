//
//  cluster.h
//  learning
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_cluster_h
#define learning_cluster_h

#include "object.h"

class muster : public object {
public:
  virtual uint32 count() = 0;
  virtual object* get( uint32 nth ) = 0;
};

#endif
