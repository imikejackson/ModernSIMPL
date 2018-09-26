#pragma once

#include <map>
#include <string>


#include "SIMPLib/DataContainers/AttributeMatrixModel.h"

using AttributeMatrixMapType = std::map<std::string, AttributeMatrixModel>;


class DataContainerModel
{
  public:
    DataContainerModel() = default;
    ~DataContainerModel() = default;
    
    DataContainerModel(const DataContainerModel&) = default; 
    DataContainerModel(DataContainerModel&&) = delete;      
    
    DataContainerModel& operator=(const DataContainerModel&) = default; // Copy Assignment Not Implemented
    DataContainerModel& operator=(DataContainerModel&&) = default;      // Move Assignment Not Implemented
    
    AttributeMatrixMapType& storage();
    
  private:
    AttributeMatrixMapType m_Storage;    
};
