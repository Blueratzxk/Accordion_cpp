//
// Created by zxk on 5/15/23.
//

#ifndef OLVP_SCHEMAMANAGER_HPP
#define OLVP_SCHEMAMANAGER_HPP

#include "DataFileDicts.hpp"



class CatalogsMetaManager
{
    map<string,Schema> catalogs;
    DataFileDicts DDicts;

public:
    CatalogsMetaManager()
    {
        this->catalogs = DDicts.parseCatalogs();
    }

    Schema getSchema(string catalogName,string SchemaName)
    {
        if(catalogs.count(catalogName) != 0)
        {
            if(catalogs[catalogName].getSchemaName().compare(SchemaName) == 0)
                return catalogs[catalogName];
            else
                return Schema::getEmptySchema();
        }
        else
        {
            return Schema::getEmptySchema();
        }
    }

    TableInfo getTable(string catalogName,string schemaName,string TableName)
    {
        if(Schema::isEmpty(getSchema(catalogName,schemaName)))
        {
            return TableInfo::getEmptyTableInfo();
        }
        Schema schema = this->catalogs[catalogName];
        if(schema.getTables().count(TableName) == 0)
        {
            return TableInfo::getEmptyTableInfo();
        }
        else
        {
            return schema.getTables()[TableName];
        }

    }

    void viewSchemas()
    {
        for(auto schema : catalogs)
        {
            cout << schema.first << endl;
            cout << schema.second.to_string() << endl;
        }
    }

};


#endif //OLVP_SCHEMAMANAGER_HPP
