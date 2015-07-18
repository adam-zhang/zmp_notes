/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/BaseObject.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 18时04分41秒
 ************************************************************************/

#include <QObject>
#include <QUuid>

class BaseObject : public QObject
{
public:
	BaseObject(QObject* parent = 0);
private:
	QUuid id_;

public:
	const QUuid& id();
	void setId(const QUuid& id);

};
