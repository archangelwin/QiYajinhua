#pragma once

#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <queue>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

typedef boost::function<void(void)> Task;
class TaskQueue :public boost::noncopyable
{
public:
	void push_Task(const Task task);
	Task pop_Task();
	int get_size();
private:
	std::queue<Task> TaskQueue_;
	boost::mutex mutex_;
	boost::condition_variable_any cond_;
};

class ThreadPool :public boost::noncopyable
{
public:
	ThreadPool(int num);
	void init();
	void stop();
	void AddNewTask(const Task task);
	void wait();
	~ThreadPool();
private:
	void run();
	TaskQueue TaskQueue_;
	boost::thread_group thread_group_;
	int threadNum;
	volatile bool is_run;
};

#endif