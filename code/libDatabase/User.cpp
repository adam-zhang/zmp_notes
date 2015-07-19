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
#include <QVariant>

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
		user->setId(query.value(0).toByteArray());
		user->setUserName(query.value(1).toString());
		user->setPassword(query.value(2).toString());
		data.push_back(user);
	}
	db->close();
	return data;
}

bool User::verifyUser(const shared_ptr<User> user)
{
	QString sql("select count(id) from user where userName=:userName and password = :password");
	QSqlDatabase* db = Database::instance().db();
	db->open();
	QSqlQuery query(sql);
	query.bindValue(":userName", user->userName());
	query.bindValue(":password", user->password());
	query.exec();
	bool ret = false;
	if (query.first())
		ret = query.value(0).toInt();
	db->close();	
	return ret;
}

shared_ptr<User> User::getUser(const QString& userName, const QString& password)
{
	QString sql("select * from user where userName = :userName and password = :password");
	Database::instance().db()->open();
	shared_ptr<User> user(new User);
	QSqlQuery query(sql);
	query.bindValue(":userName", userName);
	query.bindValue(":password", password);
	query.exec();
	if (query.first())
	{
		user->setId(query.value(0).toByteArray());
		user->setUserName(query.value(0).toString());
		user->setPassword(query.value(0).toString());
	}
	Database::instance().db()->close();
	return 0;
}
