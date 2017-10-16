#pragma once
#include <string>

namespace Applications
{
	class UserInfo
	{

	};
	class UserRule
	{

	};
	class UserScore
	{

	};
	class UserStatus
	{

	};
	class UserItem
	{
	public:
		UserItem();
		std::string GetCilenIP();
		float GetDrawRate();	//ƽ����
		float GetFleeRate();	//����
		float GetLostRate();	//����
		float GetWinRate();		//ʤ��
		std::string GetOnLineTime();
		std::string GetPassword();
		long GetPlayingTime();
		int GetIndex();
		UserInfo GetUserInfo();
		UserRule GetUserRule();
		UserScore GetUserScore();
		UserStatus GetUserStatus();
		bool IsOnLine();
		void SetUserScore();
		void SetUserStatus(UserStatus);
		~UserItem();
	private:

	};
}