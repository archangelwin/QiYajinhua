#pragma once
#ifndef ROOMTYPE_H
#define ROOMTYPE_H
namespace Applications
{
	enum NumOfPeople{THREE};
	enum Power
	{
		THREEHUNDRED
	};
	struct RoomType
	{
		Power power;
		NumOfPeople num;
		long index;
	};
}
#endif