
#include <string>
#include <iostream>


#include "SIMPLib/DataContainers/DataContainer.h"
#include "SIMPLib/DataContainers/AttributeMatrix.h"

int main(int argc, char const *argv[])
{
  std::cout << std::string("SIMPLibUnitTest Starting....") << std::endl;
  DataContainer dc;
  dc.setName(std::string("Foo"));
  
  {
    std::shared_ptr<AttributeMatrix> am = std::make_shared<AttributeMatrix>();
    am->setName("The AttributeMatrix");
    dc.setAttributeMatrix(am);
  }
  
  {
    std::shared_ptr<AttributeMatrix> am = dc.getAttributeMatrix();
    std::cout << am->getName() << std::endl;
  }
  
  std::cout << std::string("SIMPLibUnitTest Ending....") << std::endl;
  return 0;
}
