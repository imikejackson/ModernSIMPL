
#include <iostream>
#include <string>


#include "SIMPLib/DataContainers/DataContainerArray.h"
#include "SIMPLib/DataContainers/DataContainer.h"
#include "SIMPLib/DataContainers/AttributeMatrix.h"

int main(int argc, char const *argv[])
{
  std::cout << std::string("SIMPLibUnitTest Starting....") << std::endl;
  DataContainerArray dca("DataContainerArray");

  DataContainer dc0 = dca.addDataContainer("Food");
  AttributeMatrix am0 = dc0.addAttributeMatrix("An Attribute Matrix");
  
  am0.addIDataArray("An IDataArray");



  DataContainer dc1 = dca.addDataContainer("Weeds");
  
  using DCANameListType = std::list<std::string>;

  DCANameListType names = dca.getDataContainerNames();
  for(auto name : names)
  {
    std::cout << "Name: " << name << std::endl;
  }

  DataContainerArray dcaCopy = dca;
  
  dca.printTree(std::cout);
  
  dca.clearDataContainers();
  size_t count = dca.getNumDataContainers();
  std::cout << "dca Count: " << count << std::endl;
  
  count = dcaCopy.getNumDataContainers();
  std::cout << "dcaCopy Count: " << count << std::endl;
  
  
 
  
  
  
  std::cout << std::string("SIMPLibUnitTest Ending....") << std::endl;
  return 0;
}
