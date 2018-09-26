#pragma once

#include <list>
#include <iostream>

#include "SIMPLib/SIMPLibGlobal.h"

#include "SIMPLib/DataContainers/DataContainer.h"
#include "SIMPLib/DataContainers/DataContainerModel.h"


using DataContainerMapType = std::map<std::string, DataContainerModel>;

//Light weight, temporary object to provide a "view" into the *Model
class SIMPLib_EXPORT DataContainerArray
{
    
public:
    explicit DataContainerArray(const std::string& name);
    ~DataContainerArray() = default;

    DataContainerArray(const DataContainerArray&) = default;
    DataContainerArray(DataContainerArray&&) = delete;      // Move Constructor Not Implemented
    DataContainerArray& operator=(const DataContainerArray&) = delete; // Copy Assignment Not Implemented
    DataContainerArray& operator=(DataContainerArray&&) = delete;      // Move Assignment Not Implemented
    
    /**
     * @brief
     */
    virtual DataContainer addDataContainer(const std::string& name);

    /**
     * @brief getDataContainer
     * @param name
     * @return
     */
    virtual DataContainer getDataContainer(const std::string& name);

    /**
     * @brief
     */
    virtual bool deleteDataContainer(const std::string& name);

    /**
     * @brief renameDataContainer
     * @param oldName
     * @param newName
     * @return
     */
    bool renameDataContainer(const std::string& oldName, const std::string& newName);

    /**
     * @brief Removes all DataContainers from this DataContainerArray
     */
    virtual void clearDataContainers();

    /**
     * @brief getDataContainerNames
     * @return
     */
    std::list<std::string> getDataContainerNames() const;

    /**
     * @brief Returns the number of DataContainers
     * @return
     */
    virtual size_t getNumDataContainers() const;

    /**
     * @brief duplicateDataContainer
     * @param name
     * @param newName
     */
    //virtual void duplicateDataContainer(const std::string& name, const std::string& newName);
    
    /**
     * @brief printTree
     * @param out
     */
    void printTree(std::ostream& out) const;

    private:
      std::string m_Name;
      DataContainerMapType m_Model;
};
