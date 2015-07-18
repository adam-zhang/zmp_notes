/*************************************************************************
    > File Name: Precondition.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 14时36分55秒
 ************************************************************************/

#include "Precondition.h"

using namespace std;

shared_ptr<Precondition> Precondition::instance_;

Precondition& Precondition::instance()
{
	if (!instance_)
		if (!instance_)
			instance_ = shared_ptr<Precondition>(new Precondition);
	return *instance_;
}
