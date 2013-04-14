//
//  module.h
//  learning
//
//  Created by losor on 3/17/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_module_h
#define learning_module_h

#include "int.h"
#include "xml_conf.h"

/// every module should inherit from this class
class module {
public:

  virtual ~module(){}

  /// a module may contain many resources, such as functions,
  /// objects, datas .et. others can get these resources by
  /// calling this member function
  virtual void* get_resource( uint64 res_id ) = 0;

  /// a module may depend on one or more other modules, it is
  /// defined in module loading script. when the module loader
  /// loads the special module, it would call this member
  /// function to satisfy the dependence
  virtual void set_depend( module *depend, uint64 module_id ) = 0;

  /// when all are ready(modules are loaded, dependences are set)
  /// module loader will call this member function to start all
  /// works
  virtual long start() = 0;

  virtual long pause() = 0;

  /// when a stop command is recieved by the module loader, it
  /// would call this member function of the specified module
  /// when the system is going down, all modules would be called
  virtual long stop() = 0;
};

/// every module should implement this function
typedef module* (*init_module)( const xml_tree *root );

#endif
