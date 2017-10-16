#pragma once
#include "UserItem.h"
namespace Applications
{
	class UserManager
	{
	public:
		UserManager();
		void AddUserItme(UserItem);
		void DeleteUserItem(UserItem);
		long GetOffLineCount();
		UserItem GetOffLineUserItem(int);
		long GetOnLoneCount();
		UserItem GetOnLoneUserItem(int);
		void RegOffLineUserItem(UserItem);
		void Reset();
		UserItem SearchOffLineUserItem(int);
		UserItem SearchOnLineUserItem(int);
		void SwitchUserItem(UserItem);
		void UnRegOffLineUserItem(UserItem);
		~UserManager();
	private:
	};
}