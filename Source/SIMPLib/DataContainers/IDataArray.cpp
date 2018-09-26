#include "IDataArray.h"



IDataArray::IDataArray(const std::string& name, void* data) :
  m_Name(name)
, m_Data(data)
{
}


void IDataArray::printTree(std::ostream& out) const
{
  out << "    |-- IDataArray: " << m_Name << std::endl;
}
