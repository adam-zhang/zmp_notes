/*************************************************************************
    > File Name: User.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时32分33秒
 ************************************************************************/

#include "User.h"

User::User(QObject* parent)
	: BaseObject(parent)
{
}

const QString& User::userName()const
{
	return userName_;
}

void User::setUserName(const QString& userName)
{
	userName_ = userName;
}

const QString& User::password()const
{
	return password_;
}

void User::setPassword(const QString& password)
{
	password_ = password;
}
