//
//  expr_choose_if.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_choose_if__
#define __addressing__expr_choose_if__

#include "expression.h"

class expr_choose_if : public expression {
protected:
  expression *m_muster;
  expression *m_condition;

public:
  virtual ~expr_choose_if();
  expr_choose_if( expression *muster, expression *condition );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_choose_if__) */
