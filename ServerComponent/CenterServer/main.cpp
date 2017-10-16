#include "DataBaseServer.h"
#include "GlobalDefine.h"
int main(int argc, char *argvp[])
{
	SQLTYPE type;
	type.user = CoreGlobalDefine::SQL_USER;
	type.password = CoreGlobalDefine::SQL_PASSWORD;
	type.host = "";
	type.user = CoreGlobalDefine::SQL_PORT;

	DataBaseServer  *db = new DataBaseServer(type);
	bool b = db->isRun();
	if (b)
	{
		std::cout << "connect ok";
	}
	return 0;
}