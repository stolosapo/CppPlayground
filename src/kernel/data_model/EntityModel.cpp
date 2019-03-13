#include "EntityModel.h"

EntityModel::EntityModel(ModelFactory modelFactory) : Model(modelFactory)
{

}

EntityModel::~EntityModel()
{

}

string EntityModel::getTableName()
{
	return registerTableName();
}
