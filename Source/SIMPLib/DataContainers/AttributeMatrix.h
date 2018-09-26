#pragma once

#include <string>
#include <memory>
#include <map>
#include <list>
#include <iostream>

#include "SIMPLib/SIMPLibGlobal.h"

#include "SIMPLib/DataContainers/IDataArray.h"


class AttributeMatrixModel;


class AttributeMatrix
{
  public:
    explicit AttributeMatrix(const std::string& name, AttributeMatrixModel* model);
    ~AttributeMatrix();

    AttributeMatrix(const AttributeMatrix&) = default; // Copy Constructor
    AttributeMatrix(AttributeMatrix&&) = default;      // Move Constructor
    
    AttributeMatrix& operator=(const AttributeMatrix&) = delete; // Copy Assignment Not Implemented
    AttributeMatrix& operator=(AttributeMatrix&&) = delete;      // Move Assignment Not Implemented

    bool isValid() const;

    // void setName(const std::string &name);
    std::string name() const;
    
     /**
     * @brief
     */
    virtual IDataArray addIDataArray(const std::string& name);

    /**
     * @brief getAttributeMatrix
     * @param name
     * @return
     */
    virtual IDataArray getIDataArray(const std::string& name);

    /**
     * @brief
     */
    virtual bool deleteIDataArray(const std::string& name);

    /**
     * @brief renameAttributeMatrix
     * @param oldName
     * @param newName
     * @return
     */
    bool renameIDataArray(const std::string& oldName, const std::string& newName);

    /**
     * @brief Removes all AttributeMatrixs from this AttributeMatrixArray
     */
    virtual void clearIDataArrays();

    /**
     * @brief getAttributeMatrixNames
     * @return
     */
    std::list<std::string> getIDataArrayNames();

    /**
     * @brief Returns the number of AttributeMatrixs
     * @return
     */
    virtual size_t getNumIDataArrays();


    /**
     * @brief printTree
     * @param out
     */
    void printTree(std::ostream& out) const;


  private:
    std::string m_Name;
    AttributeMatrixModel* m_Model;

};
