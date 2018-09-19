

#include "AttributeMatrix.h"

#include <iostream>

class AttributeMatrixPrivate
{
  public:
    AttributeMatrixPrivate(AttributeMatrix *parent)
      : q_ptr(parent)
    {
    }
    
    std::string name;
    
  private:
    AttributeMatrix* const q_ptr;
    Q_DECLARE_PUBLIC(AttributeMatrix)
};


AttributeMatrix::AttributeMatrix() :
  d_ptr(new AttributeMatrixPrivate(this))
{

}

AttributeMatrix::~AttributeMatrix() 
{
  Q_D(AttributeMatrix);
  delete d;
  std::cout << "~AttributeMatrix" << std::endl;
}

void AttributeMatrix::setName(const std::string& name)
{
  Q_D(AttributeMatrix);
  d->name = name;
}

std::string AttributeMatrix::getName() const
{
  Q_D(const AttributeMatrix);
  return d->name;
}
