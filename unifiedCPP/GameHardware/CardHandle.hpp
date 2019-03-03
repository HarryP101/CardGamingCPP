//
//  CardHandle.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef CardHandle_hpp
#define CardHandle_hpp

#include <stdio.h>
class CardHandle {
public:
    virtual ~CardHandle() {
    }
    virtual int GetValue() = 0;
protected:
    int m_value;
};
#endif /* CardHandle_hpp */
