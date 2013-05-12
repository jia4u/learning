//
//  expression.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef addressing_expression_h
#define addressing_expression_h

#include "items.h"

enum operation {
  OPT_CONST_NUMBER,
  OPT_CONST_STRING,
  OPT_CONST_OBJ_ALL,
  OPT_CONST_OBJ_CUR,
  OPT_CONST_OBJ_REST,

  OPT_CHOOSE_IF,
  OPT_N_OF,
  OPT_NTH_OF,
  OPT_INTERSECT,
  OPT_UNION,
  OPT_DIFF,

  OPT_COUNT,
  OPT_UUID,
  OPT_CREATOR,
  OPT_NREF,
  OPT_NVISIT,
  OPT_CHILD,

  OPT_ADD,
  OPT_SUB,
  OPT_MUL,
  OPT_DIV,
  OPT_MOD,
  OPT_NEGATIVE,

  OPT_AND_B,
  OPT_OR_B,
  OPT_NOT_B,
  OPT_XOR,

  OPT_EQ,
  OPT_NE,
  OPT_GT,
  OPT_GE,
  OPT_LT,
  OPT_LE,
  OPT_AND,
  OPT_OR,
  OPT_NOT,

  OPT_EXIST,
  OPT_LIKE,
};

enum expr_result_type {
  ERT_INTEGER,
  ERT_STRING,
  ERT_ALL,
  ERT_CURRENT,
  ERT_REST,
  ERT_OBJECT,
};

class expr_result {
protected:
  expr_result_type m_type;
  union {
    int64 integer;
    const char *string;
    object *object;
  } m_result;

public:
  virtual expr_result_type type() const;
  virtual int64 integer() const;
  virtual const char* string() const;
  virtual class object* object() const;

  virtual ~expr_result();
  expr_result( int64 result );
  expr_result( const char *result );
  expr_result( class object *result );
};

class expression {

public:
  virtual ~expression();

  virtual operation operation() const = 0;
  virtual expression* paramenter( int nth ) const = 0;
  virtual expr_result* calculate( ) const = 0;
};

#endif
