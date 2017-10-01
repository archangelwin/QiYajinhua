#include "ThreadPool.h"
namespace Core
{

	void TaskQueue::push_Task(const Task task)
	{
		boost::unique_lock<boost::mutex> lock(mutex_);
		TaskQueue_.push(task);
		cond_.notify_one();
	}

	Core::Task TaskQueue::pop_Task()
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

	Threadpool::Threadpool(int num):
		threadNum(num),is_run(false)
	{

	}

	void Threadpool::init()
	{
		if (threadNum <= 0) return;
		is_run = true;
		for (int i = 0; i < threadNum; i++)
		{
			thread_group_.add_thread(new boost::thread(boost::bind(&Threadpool::run, this)));
		}
	}

	void Threadpool::stop()
	{
		is_run = false;
	}

	void Threadpool::AddNewTask(const Task task)
	{
		TaskQueue_.push_Task(task);
	}

	void Threadpool::wait()
	{
		thread_group_.join_all();
	}

	Threadpool::~Threadpool()
	{

	}

	void Threadpool::run()
	{
		while (is_run)
		{
			Task task = TaskQueue_.pop_Task();
			task();
		}
	}

}