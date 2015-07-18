/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/User.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时32分56秒
 ************************************************************************/

#include "BaseObject.h"

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
};
