#include "TcpServer.h"
#include "RoomController.h"
#include "RoomServer.h"
#include "GlobalDefine.h"
#include "ServerMgr.h"
#include "AsyncServer.h"
#include <iostream>
#include "HttpReply.hpp"
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
	//	items->SendData("GET \/ HTTP/1.1\nHost: 192.168.1.18 : 8080\nAccept : */*\n Accept-Encoding: identity\n<html><body><h1>我的第一个标题</h1><p>我的第一个段落</p></body></html>");
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
		auto target = reply::stock_reply(reply::status_type::not_found).to_buffers();
		if(Data.method=="GET")
		{
			
		}
		else if(Data.method=="POST")
		{
			
		}
		else if(Data.method=="CONNECT")
		{
			
		}
		else
		{
			
		}
		Json::Reader reader;
		Json::Value root;
		
		if (reader.parse(json.c_str(), root,false))
		{
			std::string MSG = root["MSG"].asString();
			std::string SUBCMD = root["SUBCMD"].asString();
			std::string DATA = root["DATA"].asString();
		}
		items->SendData("HTTP/1.0 200 OK\r\n\r\n{\"index\":\"test\"}");
		boost::system::error_code ignored_ec;
		items->GetPoint()->Sokcet().shutdown(boost::asio::ip::tcp::socket::shutdown_both,
			ignored_ec);
	}

	RoomServer::~RoomServer()
	{

	}

}