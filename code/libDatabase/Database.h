/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/Database.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 14时37分57秒
 ************************************************************************/

#include <memory>
#include <vector>
#include <QtSql/QSqlDatabase>

class Database
{
	Database();
	static std::shared_ptr<Database> instance_;
public:
	~Database();
	static Database& instance();

private:
	int createTables();
private:
	QSqlDatabase db_;
private:
	bool createDBFile();
	std::vector<std::string> getSqlScripts();
public:
	QSqlDatabase* db();
};
