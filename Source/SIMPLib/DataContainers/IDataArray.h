#pragma once

#include <string>
#include <iostream>


class IDataArray
{
 public:   
    explicit IDataArray(const std::string& name, void* data);
    ~IDataArray() = default;
    
    IDataArray(const IDataArray&) = default; // Copy Constructor
    IDataArray(IDataArray&&) = default;      // Move Constructor
    
    IDataArray& operator=(const IDataArray&) = default; // Copy Assignment Not Implemented
    IDataArray& operator=(IDataArray&&) = default;      // Move Assignment Not Implemented
    
    
    void printTree(std::ostream& out) const;

    
  private:
    std::string m_Name;
    void* m_Data = nullptr;
};
