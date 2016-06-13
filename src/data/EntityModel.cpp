#include "EntityModel.h"

EntityModel::EntityModel() : Model()
{

}

EntityModel::~EntityModel()
{

}

string EntityModel::getTableName()
{
	return registerTableName();
}