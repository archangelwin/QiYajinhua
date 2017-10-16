#pragma once
#ifndef ROOM_H
#define ROOM_H
class RoomType;
enum NumOfPeople;
enum Power;
namespace Applications
{
	class Room
	{
	public:
		Room(RoomType type);
		long GetIndex();
		NumOfPeople GetNumOfPeople();
		Power GetPower();

		~Room();
	private:

	};
}
#endif