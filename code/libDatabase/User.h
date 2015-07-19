/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/User.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时32分56秒
 ************************************************************************/

#include "BaseObject.h"
#include <memory>
#include <vector>

class User : public BaseObject
{
public:
	User(QObject* parent = 0);
private:
	QString userName_;
	QString password_;

public:
	const QString& userName()const;
	void setUserName(const QString& userName);

	const QString& password()const;
	void setPassword(const QString& password);
public:
	static std::vector<std::shared_ptr<User>> getAllUsers();
	static bool verifyUser(const std::shared_ptr<User> user);
	static std::shared_ptr<User> getUser(const QString& userName, const QString& password);
};
