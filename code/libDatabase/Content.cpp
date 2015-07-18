/*************************************************************************
    > File Name: Content.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时48分28秒
 ************************************************************************/

#include "Content.h"

const QUuid& Content::userID()const
{
	return userID_;
}

void Content::setUserID(const QUuid& userID)
{
	userID_ = userID;
}

const QString& Content::title()const
{
	return title_;
}

void Content::setTitle(const QString& title)
{
	title_ = title;
}

const QString& Content::content()const
{
	return content_;
}

void Content::setContent(const QString& content)
{
	content_ = content;
}
