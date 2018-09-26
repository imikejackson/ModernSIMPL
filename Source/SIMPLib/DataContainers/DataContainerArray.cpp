#include "DataContainerArray.h"

#include <iostream>

#include "SIMPLib/DataContainers/DataContainer.h"
#include "SIMPLib/DataContainers/DataContainerModel.h"


DataContainerArray::DataContainerArray(const std::string& name) :
m_Name(name)
{
}

DataContainer DataContainerArray::addDataContainer(const std::string& name)
{
    m_Model[name] = DataContainerModel();
    return DataContainer(name, &m_Model[name]);
}

DataContainer DataContainerArray::getDataContainer(const std::string& name)
{
    if(m_Model.find(name) != m_Model.end())
    {
        return DataContainer(name, &m_Model[name]);
    }
    return DataContainer(std::string(""), nullptr);
}

bool DataContainerArray::deleteDataContainer(const std::string& name)
{
    DataContainerMapType::size_type numErased = m_Model.erase(name);
    return (numErased == 1);
}

bool DataContainerArray::renameDataContainer(const std::string& oldName, const std::string& newName)
{
    if(m_Model.find(oldName) != m_Model.end())
    {
      DataContainerModel model = m_Model[oldName];
      deleteDataContainer(oldName);
      m_Model[newName] = model;
      return true;
    }
    return false;
}

void DataContainerArray::clearDataContainers()
{
    m_Model.clear();
}

std::list<std::string> DataContainerArray::getDataContainerNames() const
{
  std::list<std::string> names;
  for(auto elem : m_Model)
  {
    names.push_back(elem.first);
  }
  return names;
}

size_t DataContainerArray::getNumDataContainers() const
{
    return m_Model.size();
}


void DataContainerArray::printTree(std::ostream& out) const
{
  out << "DataContainerArray: " << m_Name << std::endl;
  
  for(auto iter : m_Model)
  {
    DataContainer dc(iter.first, &iter.second);
    dc.printTree(out);
  }
}
