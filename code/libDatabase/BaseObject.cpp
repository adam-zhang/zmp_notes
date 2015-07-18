/*************************************************************************
    > File Name: BaseObject.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 18时04分10秒
 ************************************************************************/

#include "BaseObject.h"

BaseObject::BaseObject(BaseObject* parent)
	: QObject(parent)
{
}

const QUuid& BaseObject::id()
{
	return id_;
}

void BaseObject::setId(const QUuid& id)
{
	id_ = id;
}

