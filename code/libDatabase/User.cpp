/*************************************************************************
    > File Name: User.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时32分33秒
 ************************************************************************/

#include "User.h"
#include "Database.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
using namespace std;

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

vector<shared_ptr<User>> User::getAllUsers()
{
	vector<shared_ptr<User>> data;
	QSqlDatabase* db = Database::instance().db();
	db->open();
	QSqlQuery query;
	QString sql = "select * from user;";
	query.prepare(sql);
	query.exec();
	while(query.next())
	{
		shared_ptr<User> user(new User);
		user->setId(query.value(0).toString());
		user->setUserName(query.value(1).toString());
		user->setPassword(query.value(2).toString());
		data.push_back(user);
	}
	db->close();
	return data;
}
