#include "ThreadPool.h"

void TaskQueue::push_Task(const Task task)
{
	boost::unique_lock<boost::mutex> lock(mutex_);
	TaskQueue_.push(task);
	cond_.notify_one();
}

Task TaskQueue::pop_Task()
{
	boost::unique_lock<boost::mutex> lock(mutex_);
	if (TaskQueue_.empty())
	{
		cond_.wait(lock);
	}
	Task task(TaskQueue_.front());
	TaskQueue_.pop();
	return task;
}

int TaskQueue::get_size()
{
	return TaskQueue_.size();
}

ThreadPool::ThreadPool(int num):
	threadNum(num),is_run(false)
{

}

void ThreadPool::init()
{
	if (threadNum <= 0) return;
	is_run = true;
	for (int i = 0; i < threadNum; i++)
	{
		thread_group_.add_thread(new boost::thread(boost::bind(&ThreadPool::run, this)));
	}
}

void ThreadPool::stop()
{
	is_run = false;
}

void ThreadPool::AddNewTask(const Task task)
{
	TaskQueue_.push_Task(task);
}

void ThreadPool::wait()
{
	thread_group_.join_all();
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::run()
{
	while (is_run)
	{
		Task task = TaskQueue_.pop_Task();
		task();
	}
}

