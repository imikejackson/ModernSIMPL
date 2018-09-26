#pragma once

#include <string>
#include <map>
#include <list>


#include "SIMPLib/SIMPLibGlobal.h"
#include "SIMPLib/DataContainers/AttributeMatrix.h"


class DataContainerModel;


class DataContainer
{
  public:
    explicit DataContainer(const std::string& name, DataContainerModel* model);
    ~DataContainer();

    DataContainer(const DataContainer&) = default; // Copy Constructor
    DataContainer(DataContainer&&) = default;      // Move Constructor
    DataContainer& operator=(const DataContainer&) = delete; // Copy Assignment Not Implemented
    DataContainer& operator=(DataContainer&&) = delete;      // Move Assignment Not Implemented
    
    
    bool isValid();

    // void setName(const std::string &name);
    std::string name() const;
    
     /**
     * @brief
     */
    virtual AttributeMatrix addAttributeMatrix(const std::string& name);

    /**
     * @brief getDataContainer
     * @param name
     * @return
     */
    virtual AttributeMatrix getAttributeMatrix(const std::string& name);

    /**
     * @brief
     */
    virtual bool deleteAttributeMatrix(const std::string& name);

    /**
     * @brief renameDataContainer
     * @param oldName
     * @param newName
     * @return
     */
    bool renameAttributeMatrix(const std::string& oldName, const std::string& newName);

    /**
     * @brief Removes all DataContainers from this DataContainerArray
     */
    virtual void clearAttributeMatrix();

    /**
     * @brief getDataContainerNames
     * @return
     */
    std::list<std::string> getAttributeMatrixNames();

    /**
     * @brief Returns the number of DataContainers
     * @return
     */
    virtual size_t getNumAttributeMatrix();

    
    /**
     * @brief printTree
     * @param out
     */
    void printTree(std::ostream& out) const;


  private:
    std::string m_Name;

    DataContainerModel* m_Model;
};
