#pragma once

#include <string>
#include <memory>

#include "SIMPLib/SIMPLibGlobal.h"



class AttributeMatrixPrivate;


class AttributeMatrix
{
  public:
    AttributeMatrix();
    ~AttributeMatrix();
    Q_DISABLE_COPY(AttributeMatrix)
    Q_DISABLE_MOVE(AttributeMatrix)
    
    void setName(const std::string &name);
    std::string getName() const;
    
  private:
    AttributeMatrixPrivate* const d_ptr;
    Q_DECLARE_PRIVATE(AttributeMatrix)
    
};

