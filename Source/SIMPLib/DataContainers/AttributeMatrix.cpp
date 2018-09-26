

#include "AttributeMatrix.h"

#include <iostream>


#include "SIMPLib/DataContainers/AttributeMatrixModel.h"
#include "SIMPLib/DataContainers/IDataArrayModel.h"


AttributeMatrix::AttributeMatrix(const std::string& name, AttributeMatrixModel* model) :
  m_Name(name)
, m_Model(model)
{
  
}

AttributeMatrix::~AttributeMatrix() = default;


bool AttributeMatrix::isValid() const
{
  return (m_Model != nullptr);
}

std::string AttributeMatrix::name() const
{
  return m_Name;
}


IDataArray AttributeMatrix::addIDataArray(const std::string& name)
{  
  IDataArrayMapType& storage = m_Model->storage();
  IDataArrayModel daModel;
  
  storage[name] = daModel;
  
  return IDataArray(name, &storage[name]);
}

IDataArray AttributeMatrix::getIDataArray(const std::string& name)
{
  IDataArrayMapType& daStorage = m_Model->storage();
  
  if(daStorage.find(name) != daStorage.end())
  {
    return IDataArray(name, &daStorage[name]);
  }
  return IDataArray(std::string(""), nullptr);
}

bool AttributeMatrix::deleteIDataArray(const std::string& name)
{
  IDataArrayMapType& daStorage = m_Model->storage();
  
  IDataArrayMapType::size_type numErased = daStorage.erase(name);
  return (numErased == 1);
}

bool AttributeMatrix::renameIDataArray(const std::string& oldName, const std::string& newName)
{
  IDataArrayMapType& daStorage = m_Model->storage();
  
  if(daStorage.find(oldName) != daStorage.end())
  {
    IDataArrayModel model = daStorage[oldName];
    deleteIDataArray(oldName);
    daStorage[newName] = model;
    return true;
  }
  return false;
}

void AttributeMatrix::clearIDataArrays()
{
  IDataArrayMapType& daStorage = m_Model->storage();
  
  daStorage.clear();
}

std::list<std::string> AttributeMatrix::getIDataArrayNames()
{
  std::list<std::string> names;
  IDataArrayMapType& daStorage = m_Model->storage();
  for(auto elem : daStorage)
  {
    names.push_back(elem.first);
  }
  return names;
}

size_t AttributeMatrix::getNumIDataArrays()
{
  IDataArrayMapType& daStorage = m_Model->storage();
  
  return daStorage.size();
}

void AttributeMatrix::printTree(std::ostream& out) const
{
  out << "  |-- AttributeMatrix: " << m_Name << std::endl;
  IDataArrayMapType& amStorage = m_Model->storage();
  
  for(auto iter : amStorage)
  {
    IDataArray da(iter.first, &iter.second);
    da.printTree(out);
  }
}
