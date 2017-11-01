#include "TcpServer.h"
#include "RoomController.h"
#include "RoomServer.h"
#include "GlobalDefine.h"
#include "ServerMgr.h"
#include "AsyncServer.h"
#include <iostream>
#include "HttpReply.hpp"
#include "MsgFunction.h"
#include <json/json.h>

namespace Applications
{

	RoomServer::RoomServer():
		RoomController(nullptr)
	{
		TcpServer_ = new TcpServer(CoreGlobalDefine::ROOM_SERVER_PORT);

	}

	void RoomServer::Run()
	{
		TcpServer_->SetTcpObserver(this);
		TcpServer_->Run();
		auto instance = ServerMgr::GetInstance();
		instance->GetAsyncServer()->GetIOService().run();
	}

	void RoomServer::Stop()
	{

	}

	bool RoomServer::isRun()
	{
		return isRun_;
	}

	void RoomServer::OnSocketAccept(int SockIndex)
	{
		auto items = TcpServer_->GetSocketItem(SockIndex);
		std::cout << items->GetClientAddress().to_string()<<std::endl;
	//	items->SendData("GET \/ HTTP/1.1\nHost: 192.168.1.18 : 8080\nAccept : */*\n Accept-Encoding: identity\n<html><body><h1>�ҵĵ�һ������</h1><p>�ҵĵ�һ������</p></body></html>");
	}

	void RoomServer::OnSocketRead(int SockIndex, char *pData)
	{
		std::cout << "sock " << SockIndex << ":" << pData << std::endl;
	}

	void RoomServer::OnSocketClose(int SockIndex)
	{

	}

	void RoomServer::OnHttpAccept(int SockIndex, request Data,std::string json)
	{
		auto items= TcpServer_->GetSocketItem(SockIndex);
		if(Data.method=="GET")
		{
				std::string url=Data.url;
				auto ok=reply::stock_reply(reply::status_type::ok).to_buffers();
				items->SendData(ok);
				items->GetPoint()->Sokcet().shutdown(boost::asio::ip::tcp::socket::shutdown_both,ignored_ec);
		}
		else if(Data.method=="POST")
		{
			Json::Reader reader;
			Json::Value root;

			if (reader.parse(json.c_str(), root,false))
			{
				std::string MSG = root["MSG"].asString();
				std::string SUBCMD = root["SUBCMD"].asString();
				std::string DATA = root["DATA"].asString();
				int n = MSGCALLFUNC(MSG,DATA,SockIndex);
				if(n!=0)
				{
					auto not_found = reply::stock_reply(reply::status_type::not_found).to_buffers();
					items->SendData(not_found);
				}
			}

		}
		else
		{

		}



	}

	RoomServer::~RoomServer()
	{

	}

}
