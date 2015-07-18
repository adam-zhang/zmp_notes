/*************************************************************************
    > File Name: /home/zmp/Projects/GitProjects/zmp_notes/code/libDatabase/Precondition.h
    > Author: Mingping (Adam) Zhang
    > Mail: mingpingzhang@163.com 
    > Created Time: 2015- 7月-18 14时37分57秒
 ************************************************************************/

#include <memory>

class Precondition
{
	static std::shared_ptr<Precondition> instance_;
public:
	static Precondition& instance();
};
