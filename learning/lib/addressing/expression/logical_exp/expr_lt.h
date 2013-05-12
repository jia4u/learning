//
//  expr_lt.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_lt__
#define __addressing__expr_lt__

#include "expression.h"

class expr_lt : public expression {
protected:
  expression *m_src;
  expression *m_dst;

public:
  virtual ~expr_lt();
  expr_lt( expression *src, expression *dst );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_lt__) */
