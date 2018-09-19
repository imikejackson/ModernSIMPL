#include "DataContainer.h"

#include "SIMPLib/DataContainers/AttributeMatrix.h"

class DataContainerPrivate
{
  public:
    DataContainerPrivate(DataContainer* parent)
      : q_ptr(parent)
    {
    }
    
    std::string name;
    std::shared_ptr<AttributeMatrix> atrMat = nullptr;
    
  private:
    DataContainer * const q_ptr;
    Q_DECLARE_PUBLIC(DataContainer)
};



DataContainer::DataContainer() :
  d_ptr(new DataContainerPrivate(this))
{

}

DataContainer::~DataContainer() 
{
  Q_D(DataContainer);
  delete d;
}


void DataContainer::setName(const std::string& name)
{
  Q_D(DataContainer);
  d->name = name;
}

std::string DataContainer::getName() const
{
  Q_D(const DataContainer);
  return d->name;
}


void DataContainer::setAttributeMatrix(std::shared_ptr<AttributeMatrix> atrMat)
{
  Q_D(DataContainer);
  d->atrMat = atrMat;
}

std::shared_ptr<AttributeMatrix> DataContainer::getAttributeMatrix() const
{
  Q_D(const DataContainer);
  return d->atrMat;
}


