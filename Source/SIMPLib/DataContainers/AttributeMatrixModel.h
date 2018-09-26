#pragma once

#include <map>
#include <string>

#include "SIMPLib/DataContainers/IDataArrayModel.h"

using IDataArrayMapType = std::map<std::string, IDataArrayModel>;


class AttributeMatrixModel
{
  public:
    AttributeMatrixModel() = default;
    ~AttributeMatrixModel() = default;
    
    AttributeMatrixModel(const AttributeMatrixModel&) = default; 
    AttributeMatrixModel(AttributeMatrixModel&&) = delete;      
    
    AttributeMatrixModel& operator=(const AttributeMatrixModel&) = default; // Copy Assignment Not Implemented
    AttributeMatrixModel& operator=(AttributeMatrixModel&&) = default;      // Move Assignment Not Implemented
    
    IDataArrayMapType& storage();
    
    private:
    
    IDataArrayMapType m_Storage;
};
