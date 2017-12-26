#include "EntityModel.h"

EntityModel::EntityModel(staticFactoryMethod staticFactory) : Model(staticFactory)
{

}

EntityModel::~EntityModel()
{

}

string EntityModel::getTableName()
{
	return registerTableName();
}