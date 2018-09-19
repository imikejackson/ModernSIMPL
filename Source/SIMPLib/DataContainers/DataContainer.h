#pragma once

#include <string>

#include "SIMPLib/SIMPLibGlobal.h"

class AttributeMatrix;
class DataContainerPrivate;

class DataContainer
{
  public:
    DataContainer();
    ~DataContainer();
    
    Q_DISABLE_COPY(DataContainer)
    Q_DISABLE_MOVE(DataContainer)

    void setName(const std::string &name);
    std::string getName() const;
    
    void setAttributeMatrix(std::shared_ptr<AttributeMatrix> atrMat);
    std::shared_ptr<AttributeMatrix> getAttributeMatrix() const;
    

  private:
    std::string m_Name;

    DataContainerPrivate* const d_ptr;
    Q_DECLARE_PRIVATE(DataContainer)
};

