//
//  expr_and.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_and__
#define __addressing__expr_and__

#include "expression.h"

class expr_and : public expression {
protected:
  expression *m_src;
  expression *m_dst;

public:
  virtual ~expr_and();
  expr_and( expression *src, expression *dst );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_and__) */
