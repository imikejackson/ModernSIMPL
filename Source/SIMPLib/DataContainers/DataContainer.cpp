#include "DataContainer.h"

#include <iostream>

#include "SIMPLib/DataContainers/AttributeMatrix.h"
#include "SIMPLib/DataContainers/DataContainerModel.h"


/*
Version 1 of a PIMPL class has an empty d_ptr but still allocates
the pointer
*/

DataContainer::DataContainer(const std::string& name, DataContainerModel* model) :
  m_Name(name)
, m_Model(model)  
{
}

DataContainer::~DataContainer() = default;

bool DataContainer::isValid()
{
  return (m_Model != nullptr);
}


// void DataContainer::setName(const std::string& name)
// {
//   m_Name = name;
// }

std::string DataContainer::name() const
{
  return m_Name;
}



AttributeMatrix DataContainer::addAttributeMatrix(const std::string& name)
{
  AttributeMatrixModel amModel;
  AttributeMatrixMapType& amStorage = m_Model->storage();
  amStorage[name] = amModel;
  
  return AttributeMatrix(name, &amStorage[name]);
}

AttributeMatrix DataContainer::getAttributeMatrix(const std::string& name)
{
  
  AttributeMatrixMapType& amStorage = m_Model->storage();
  
  if(amStorage.find(name) != amStorage.end())
  {
    return AttributeMatrix(name, &amStorage[name]);
  }
  return AttributeMatrix(std::string(""), nullptr);
}

bool DataContainer::deleteAttributeMatrix(const std::string& name)
{
  AttributeMatrixMapType& amStorage = m_Model->storage();
  
  AttributeMatrixMapType::size_type numErased = amStorage.erase(name);
  return (numErased == 1);
}

bool DataContainer::renameAttributeMatrix(const std::string& oldName, const std::string& newName)
{
  AttributeMatrixMapType& amStorage = m_Model->storage();
  
  if(amStorage.find(oldName) != amStorage.end())
  {
    AttributeMatrixModel model = amStorage[oldName];
    deleteAttributeMatrix(oldName);
    amStorage[newName] = model;
    return true;
  }
  return false;
}

void DataContainer::clearAttributeMatrix()
{
  AttributeMatrixMapType& amStorage = m_Model->storage();
  
  amStorage.clear();
}

std::list<std::string> DataContainer::getAttributeMatrixNames()
{
  std::list<std::string> names;
  AttributeMatrixMapType& amStorage = m_Model->storage();
  for(auto elem : amStorage)
  {
    names.push_back(elem.first);
  }
  return names;
}

size_t DataContainer::getNumAttributeMatrix()
{
  AttributeMatrixMapType& amStorage = m_Model->storage();
  
  return amStorage.size();
}

void DataContainer::printTree(std::ostream& out) const
{
  out << "|-- DataContainer: " << m_Name << std::endl;
  AttributeMatrixMapType& amStorage = m_Model->storage();

  for(auto iter : amStorage)
  {
    AttributeMatrix am(iter.first, &iter.second);
    am.printTree(out);
  }
}
