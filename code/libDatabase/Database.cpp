/*************************************************************************
    > File Name: Precondition.cpp
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 14时36分55秒
 ************************************************************************/

#include "Database.h"
#include "../errors/AppErrors.h"
#include <QtSql/QSqlQuery>
#include <QFileInfo>

using namespace std;

shared_ptr<Precondition> Precondition::instance_;

Precondition::Precondition()
{
	createDBFile();
}

bool Precondition::createDBFile()
{
	QString fileName("content.db");
	QFileInfo fileInfo(fileName);
	if (!fileInfo.exists())
	{
		db_ = QSqlDatabase::addDatabase("QSQLITE");
		db_.setDatabaseName("content.db");
		if (!createTables())
			return false;
	}
	return true;
}

Precondition& Precondition::instance()
{
	if (!instance_)
		if (!instance_)
			instance_ = shared_ptr<Precondition>(new Precondition);
	return *instance_;
}

vector<string> Precondition::getSqlScripts()
{
	vector<string> sql =
	{
		"create table user(id uuid primary keky,"
			"userName nvarchar(50),"
			"password nvarchar(50));",
		"create table content(id uuid primary key,"
			"userid uuid, foreign key(userid) reference user(id),"
			"parentid uuid, foreign key(id) reference content(id),"
			"title nvarchar(1000));",
		"create table images(id uuid primary key,"
			"contentid uuid, foreign key(contentid) reference content(id),"
			"data image);",
	};
	return sql;
}

QSqlDatabase* Precondition::db()
{
	return &db_;
}

int Precondition::createTables()
{
	vector<string> sql = getSqlScripts();
		QSqlQuery query;
	for(vector<string>::iterator i = sql.begin(); i != sql.end(); ++i)
	{
		query.prepare((*i).c_str());
		if (!query.exec())
			return CREATE_DATABASE_FAILED;
	}
	return 0;
}
