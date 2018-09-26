#pragma once

#include <map>
#include <string>

#include "SIMPLib/DataContainers/IDataArray.h"

//using IDataArrayMapType = std::map<std::string, IDataArray>;


class IDataArrayModel
{
  public:
    IDataArrayModel() = default;
    ~IDataArrayModel() = default;
    
    IDataArrayModel(const IDataArrayModel&) = default; 
    IDataArrayModel(IDataArrayModel&&) = delete;      
    
    IDataArrayModel& operator=(const IDataArrayModel&) = default; // Copy Assignment Not Implemented
    IDataArrayModel& operator=(IDataArrayModel&&) = default;      // Move Assignment Not Implemented
    
    //IDataArrayMapType& storage();
    
    private:
    
    //IDataArrayMapType m_Storage;
};
