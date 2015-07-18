/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/Content.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 21时48分56秒
 ************************************************************************/
#include "BaseObject.h"

class Content : public BaseObject
{
public:
	Content(QObject* parent = 0);
private:
	QUuid	userID_;
	QString title_;
	QString content_;

public:
	const QUuid& userID()const;
	void setUserID(const QUuid& userID);

	const QString& title()const;
	void setTitle(const QString& title);

	const QString& content()const;
	void setContent(const QString& content);
};
